//
// Created by Duzhong Chen on 2020/3/21.
//

#pragma once

#include <vector>
#include <list>
#include <memory>
#include <robin_hood.h>
#include <unordered_set>

#include "Variable.h"
#include "ImportManager.h"
#include "ExportManager.h"

namespace rocket_bundle {

    enum class ScopeType {
        Invalid = 0,

        TDZ,
        Module,
        Block,
        Switch,
        Function,
        Catch,
        With,
        Class,
        Global,
        FunctionExpressionName,
        For,

        /**
         * Actually, variable declarator doesn't
         * create new scope.
         * It's regarded as a scope for graph computation.
         */
        VariableDeclarator,

    };

    class ModuleScope;

    class Scope {
    public:

        Scope() = default;
        Scope(const Scope&) = delete;
        Scope(Scope&&) = delete;

        Scope& operator=(const Scope&) = delete;
        Scope& operator=(Scope&&) = delete;

        explicit Scope(ScopeType t) : type(t) {
        }

        ScopeType type = ScopeType::Invalid;

        ModuleScope* CastToMoudle();

        inline bool IsMoudle() const {
            return type == ScopeType::Module;
        }

        virtual Variable* RecursivelyFindVariable(const UString& var_name);

        virtual Variable* CreateVariable(const std::shared_ptr<Identifier>& var_id, VarKind kind);

        virtual void AddUnresolvedId(const std::shared_ptr<Identifier>& id) {
            unresolved_id.push_back(id);
        }

        void SetParent(Scope* parent_);

        inline bool RemoveVariable(const UString& name) {
            auto iter = own_variables.find(name);
            if (iter == own_variables.end()) {
                return false;
            }
            own_variables.erase(iter);
            return true;
        }

        inline Scope* GetParent() {
            return parent;
        }

        void ResolveAllSymbols();

        virtual bool RenameSymbol(const UString& old_name, const UString& new_name);

        virtual ~Scope() = default;

        robin_hood::unordered_map<UString, Variable> own_variables;

    protected:
        Scope* parent = nullptr;

        /**
         * log identifier when parsing
         */
        std::list<std::shared_ptr<Identifier>> unresolved_id;

        std::vector<Scope*> children;

    };

    /**
     * Used in left value, do not record id
     */
    class LeftValueScope : public Scope {
    public:
        static LeftValueScope default_;

        Variable* CreateVariable(const std::shared_ptr<Identifier>& var_id, VarKind kind) override {
            return nullptr;
        }

        void AddUnresolvedId(const std::shared_ptr<Identifier>& id) override {}

    };

    /**
     * Moudle scope is special
     */
    class ModuleScope : public Scope {
    public:

        ModuleScope();

        bool RenameSymbol(const UString& old_name, const UString& new_name) override;

        ImportManager import_manager;
        ExportManager export_manager;

    };

}
