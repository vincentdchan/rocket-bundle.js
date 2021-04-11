//
// Created by Duzhong Chen on 2021/3/25.
//

#pragma once

#include <cinttypes>
#include <string>
#include <future>
#include <parser/Parser.hpp>
#include "string/UString.h"
#include "codegen/CodeGen.h"
#include "sourcemap/MappingCollector.h"
#include "UniqueNameGenerator.h"
#include "ResolveResult.h"

namespace jetpack {
    class ModuleResolver;
    class ModuleProvider;

    struct RenamerCollection {
    public:
        std::vector<Sp<MinifyNameGenerator>> content;
        std::shared_ptr<UnresolvedNameCollector> idLogger;

        inline void PushGenerator(const Sp<MinifyNameGenerator>& generator) {
            std::lock_guard<std::mutex> lk(mutex_);
            content.push_back(generator);
        }

    private:
        std::mutex mutex_;

    };

    class ModuleFile {
    public:
        ModuleFile(const std::string& path, int32_t id_);
        /**
         * Unique id in module resolver
         */
        inline int32_t id() const {
            return id_;
        }

        /**
         * Absolute path
         */
        inline const std::string& Path() const {
            return path_;
        }

        UString default_export_name;

        // interface to provide content by contents;
        Sp<ModuleProvider> provider;

        Weak<ModuleResolver> module_resolver;

        Sp<Module> ast;

        /**
         * relative path -> absolute path
         */
        HashMap<std::string, std::string> resolved_map;

        /**
         * Temp for parallel codegen
         */
        CodeGenResult codegen_result;

        UString src_content;

        std::future<std::string> escaped_src_content;
        std::future<std::string> escaped_path;

        /**
         * For Postorder traversal
         */
        bool visited_mark = false;

        /**
         * For Postorder traversal
         */
        std::vector<std::weak_ptr<ModuleFile>> ref_mods;

        Sp<MappingCollector> mapping_collector_;

        void RenameInnerScopes(RenamerCollection& col);
        Sp<MinifyNameGenerator> RenameInnerScopes(Scope& scope, UnresolvedNameCollector* idLogger);

        void CodeGenFromAst(const CodeGen::Config &config);

        UString GetModuleVarName() const;

        ResolveResult<UString> GetSource();

        inline ExportManager& GetExportManager() {
            return ast->scope->export_manager;
        }

        inline void SetIsCommonJS(bool v) {
            is_common_js_ = v;
        }

        [[nodiscard]]
        inline bool IsCommonJS() const {
            return is_common_js_;
        }

    private:
        int32_t id_;
        std::string path_;
        bool is_common_js_ = false;

    };

}
