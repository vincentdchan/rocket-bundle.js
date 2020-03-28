/* Generated by Ruby Script! */


#pragma once

#include "BaseNodes.h"
#include <memory>
#include <optional>
#include <vector>
#include <variant>
#include "../scope/Scope.h"

namespace rocket_bundle {

    class ArrayExpression: public Expression {
    public:
        ArrayExpression();

        std::vector<std::optional<Sp<SyntaxNode>>> elements;

    };

    class ArrayPattern: public Pattern {
    public:
        ArrayPattern();

        std::vector<std::optional<Sp<SyntaxNode>>> elements;

    };

    class ArrowFunctionExpression: public Expression {
    public:
        ArrowFunctionExpression();

        std::optional<Sp<Identifier>> id;
        std::vector<Sp<SyntaxNode>> params;
        Sp<SyntaxNode> body;
        bool generator = false;
        bool expression = false;
        bool async = false;

        std::unique_ptr<Scope> scope;

        bool IsGenerator() const override { return generator; }
        bool IsAsync() const override { return async; }

    };

    class AssignmentExpression: public Expression {
    public:
        AssignmentExpression();

        UString operator_;
        Sp<Pattern> left;
        Sp<Expression> right;

    };

    class AssignmentPattern: public Pattern {
    public:
        AssignmentPattern();

        Sp<SyntaxNode> left;
        Sp<Expression> right;

    };

    class AwaitExpression: public Expression {
    public:
        AwaitExpression();

        Sp<Expression> argument;

    };

    class BinaryExpression: public Expression {
    public:
        BinaryExpression();

        UString operator_;
        Sp<Expression> left;
        Sp<Expression> right;

    };

    class BlockStatement: public Statement {
    public:
        BlockStatement();

        std::vector<Sp<SyntaxNode>> body;

        std::optional<std::unique_ptr<Scope>> scope;

    };

    class BreakStatement: public Statement {
    public:
        BreakStatement();

        std::optional<Sp<Identifier>> label;

    };

    class CallExpression: public Expression {
    public:
        CallExpression();

        Sp<Expression> callee;
        std::vector<Sp<SyntaxNode>> arguments;

    };

    class CatchClause: public SyntaxNode {
    public:
        CatchClause();

        Sp<SyntaxNode> param;
        Sp<BlockStatement> body;

        std::unique_ptr<Scope> scope;

    };

    class ClassBody: public SyntaxNode {
    public:
        ClassBody();

        std::vector<Sp<MethodDefinition>> body;

    };

    class ClassDeclaration: public Declaration {
    public:
        ClassDeclaration();

        std::optional<Sp<Identifier>> id;
        std::optional<Sp<Identifier>> super_class;
        Sp<ClassBody> body;

        std::unique_ptr<Scope> scope;

    };

    class ClassExpression: public Expression {
    public:
        ClassExpression();

        std::optional<Sp<Identifier>> id;
        std::optional<Sp<Identifier>> super_class;
        std::optional<Sp<ClassBody>> body;

        std::unique_ptr<Scope> scope;

    };

    class ConditionalExpression: public Expression {
    public:
        ConditionalExpression();

        Sp<Expression> test;
        Sp<Expression> consequent;
        Sp<Expression> alternate;

    };

    class ContinueStatement: public Statement {
    public:
        ContinueStatement();

        std::optional<Sp<Identifier>> label;

    };

    class DebuggerStatement: public Statement {
    public:
        DebuggerStatement();


    };

    class Directive: public Statement {
    public:
        Directive();

        Sp<Expression> expression;
        UString directive;

    };

    class DoWhileStatement: public Statement {
    public:
        DoWhileStatement();

        Sp<Statement> body;
        Sp<Expression> test;

    };

    class EmptyStatement: public Statement {
    public:
        EmptyStatement();


    };

    class ExportAllDeclaration: public Declaration {
    public:
        ExportAllDeclaration();

        Sp<Literal> source;

    };

    class ExportDefaultDeclaration: public Declaration {
    public:
        ExportDefaultDeclaration();

        Sp<SyntaxNode> declaration;

    };

    class ExportNamedDeclaration: public Declaration {
    public:
        ExportNamedDeclaration();

        std::optional<Sp<SyntaxNode>> declaration;
        std::vector<Sp<ExportSpecifier>> specifiers;
        std::optional<Sp<Literal>> source;

    };

    class ExportSpecifier: public SyntaxNode {
    public:
        ExportSpecifier();

        Sp<Identifier> exported;
        Sp<Identifier> local;

    };

    class ExpressionStatement: public Statement {
    public:
        ExpressionStatement();

        Sp<Expression> expression;

    };

    class ForInStatement: public Statement {
    public:
        ForInStatement();

        Sp<SyntaxNode> left;
        Sp<SyntaxNode> right;
        Sp<Statement> body;
        bool each = false;

        std::unique_ptr<Scope> scope;

    };

    class ForOfStatement: public Statement {
    public:
        ForOfStatement();

        Sp<SyntaxNode> left;
        Sp<SyntaxNode> right;
        Sp<Statement> body;

        std::unique_ptr<Scope> scope;

    };

    class ForStatement: public Statement {
    public:
        ForStatement();

        std::optional<Sp<SyntaxNode>> init;
        std::optional<Sp<SyntaxNode>> test;
        std::optional<Sp<SyntaxNode>> update;
        Sp<Statement> body;

        std::unique_ptr<Scope> scope;

    };

    class FunctionDeclaration: public Declaration {
    public:
        FunctionDeclaration();

        std::optional<Sp<Identifier>> id;
        std::vector<Sp<SyntaxNode>> params;
        Sp<BlockStatement> body;
        bool generator = false;
        bool expression = false;
        bool async = false;

        std::unique_ptr<Scope> scope;

    };

    class FunctionExpression: public Expression {
    public:
        FunctionExpression();

        std::optional<Sp<Identifier>> id;
        std::vector<Sp<SyntaxNode>> params;
        Sp<BlockStatement> body;
        bool generator = false;
        bool expression = false;
        bool async = false;

        std::unique_ptr<Scope> scope;

        bool IsGenerator() const override { return generator; }
        bool IsAsync() const override { return async; }

    };

    class Identifier: public Expression, public Pattern {
    public:
        Identifier();

        UString name;

    };

    class IfStatement: public Statement {
    public:
        IfStatement();

        Sp<Expression> test;
        Sp<Statement> consequent;
        std::optional<Sp<Statement>> alternate;

    };

    class Import: public Expression {
    public:
        Import();


    };

    class ImportDeclaration: public Declaration {
    public:
        ImportDeclaration();

        std::vector<Sp<SyntaxNode>> specifiers;
        Sp<Literal> source;

    };

    class ImportDefaultSpecifier: public SyntaxNode {
    public:
        ImportDefaultSpecifier();

        Sp<Identifier> local;

    };

    class ImportNamespaceSpecifier: public SyntaxNode {
    public:
        ImportNamespaceSpecifier();

        Sp<Identifier> local;

    };

    class ImportSpecifier: public SyntaxNode {
    public:
        ImportSpecifier();

        Sp<Identifier> local;
        Sp<Identifier> imported;

    };

    class LabeledStatement: public Statement {
    public:
        LabeledStatement();

        Sp<Identifier> label;
        Sp<Statement> body;

    };

    class Literal: public Expression {
    public:
        enum class Ty {
            Invalid = 0,
            Boolean,
            Double,
            String,
            Null,
            Regex,
        };

        Literal();

        Ty ty = Ty::Invalid;

        bool boolean_ = false;
        double double_ = 0;
        UString str_;

        UString raw;

    };

    class MetaProperty: public Expression {
    public:
        MetaProperty();

        Sp<Identifier> meta;
        Sp<Identifier> property;

    };

    class MethodDefinition: public SyntaxNode {
    public:
        MethodDefinition();

        std::optional<Sp<SyntaxNode>> key;
        bool computed = false;
        std::optional<Sp<Expression>> value;
        VarKind kind;
        bool static_ = false;

    };

    class Module: public SyntaxNode {
    public:
        Module();

        std::vector<Sp<SyntaxNode>> body;
        UString source_type;
        std::vector<Sp<Comment>> comments;

        std::unique_ptr<ModuleScope> scope;

    };

    class NewExpression: public Expression {
    public:
        NewExpression();

        Sp<Expression> callee;
        std::vector<Sp<SyntaxNode>> arguments;

    };

    class ObjectExpression: public Expression {
    public:
        ObjectExpression();

        std::vector<Sp<SyntaxNode>> properties;

    };

    class ObjectPattern: public Pattern {
    public:
        ObjectPattern();

        std::vector<Sp<SyntaxNode>> properties;

    };

    class Property: public SyntaxNode {
    public:
        Property();

        Sp<SyntaxNode> key;
        bool computed = false;
        std::optional<Sp<SyntaxNode>> value;
        VarKind kind;
        bool method = false;
        bool shorthand = false;

    };

    class RegexLiteral: public Expression {
    public:
        RegexLiteral();

        UString value;
        UString raw;

    };

    class RestElement: public Pattern, public Expression {
    public:
        RestElement();

        Sp<SyntaxNode> argument;

    };

    class ReturnStatement: public Statement {
    public:
        ReturnStatement();

        std::optional<Sp<Expression>> argument;

    };

    class Script: public SyntaxNode {
    public:
        Script();

        std::vector<Sp<SyntaxNode>> body;
        UString source_type;
        std::vector<Sp<Comment>> comments;

        std::unique_ptr<Scope> scope;

    };

    class SequenceExpression: public Expression {
    public:
        SequenceExpression();

        std::vector<Sp<Expression>> expressions;

    };

    class SpreadElement: public SyntaxNode {
    public:
        SpreadElement();

        Sp<Expression> argument;

    };

    class MemberExpression: public Expression, public Pattern {
    public:
        MemberExpression();

        bool computed = false;
        Sp<Expression> object;
        Sp<Expression> property;

        bool IsComputed() const override { return computed; }

    };

    class Super: public Expression {
    public:
        Super();


    };

    class SwitchCase: public SyntaxNode {
    public:
        SwitchCase();

        std::optional<Sp<Expression>> test;
        std::vector<Sp<Statement>> consequent;

    };

    class SwitchStatement: public Statement {
    public:
        SwitchStatement();

        Sp<Expression> discrimiant;
        std::vector<Sp<SwitchCase>> cases;

        std::unique_ptr<Scope> scope;

    };

    class TaggedTemplateExpression: public Expression {
    public:
        TaggedTemplateExpression();

        Sp<Expression> tag;
        Sp<TemplateLiteral> quasi;

    };

    class TemplateElement: public SyntaxNode {
    public:
        TemplateElement();

        UString cooked;
        UString raw;
        bool tail = false;

    };

    class TemplateLiteral: public Expression {
    public:
        TemplateLiteral();

        std::vector<Sp<TemplateElement>> quasis;
        std::vector<Sp<Expression>> expressions;

    };

    class ThisExpression: public Expression {
    public:
        ThisExpression();


    };

    class ThrowStatement: public Statement {
    public:
        ThrowStatement();

        Sp<Expression> argument;

    };

    class TryStatement: public Statement {
    public:
        TryStatement();

        Sp<BlockStatement> block;
        std::optional<Sp<CatchClause>> handler;
        std::optional<Sp<BlockStatement>> finalizer;

    };

    class UnaryExpression: public Expression {
    public:
        UnaryExpression();

        UString operator_;
        Sp<Expression> argument;
        bool prefix = false;

    };

    class UpdateExpression: public Expression {
    public:
        UpdateExpression();

        UString operator_;
        Sp<Expression> argument;
        bool prefix = false;

    };

    class VariableDeclaration: public Declaration {
    public:
        VariableDeclaration();

        std::vector<Sp<VariableDeclarator>> declarations;
        VarKind kind;

    };

    class VariableDeclarator: public SyntaxNode {
    public:
        VariableDeclarator();

        Sp<SyntaxNode> id;
        std::optional<Sp<Expression>> init;

        std::unique_ptr<Scope> scope;

    };

    class WhileStatement: public Statement {
    public:
        WhileStatement();

        Sp<Expression> test;
        Sp<Statement> body;

    };

    class WithStatement: public Statement {
    public:
        WithStatement();

        Sp<Expression> object;
        Sp<Statement> body;

    };

    class YieldExpression: public Expression {
    public:
        YieldExpression();

        std::optional<Sp<Expression>> argument;
        bool delegate = false;

    };

    class ArrowParameterPlaceHolder: public Expression {
    public:
        ArrowParameterPlaceHolder();

        std::vector<Sp<SyntaxNode>> params;
        bool async = false;

        bool IsAsync() const override { return async; }

    };

    class JSXClosingElement: public SyntaxNode {
    public:
        JSXClosingElement();

        Sp<SyntaxNode> name;

    };

    class JSXElement: public Expression {
    public:
        JSXElement();

        Sp<JSXOpeningElement> opening_element;
        std::vector<Sp<SyntaxNode>> children;
        std::optional<Sp<JSXClosingElement>> closing_element;

    };

    class JSXEmptyExpression: public SyntaxNode {
    public:
        JSXEmptyExpression();


    };

    class JSXExpressionContainer: public SyntaxNode {
    public:
        JSXExpressionContainer();

        Sp<Expression> expression;

    };

    class JSXIdentifier: public SyntaxNode {
    public:
        JSXIdentifier();

        UString name;

    };

    class JSXMemberExpression: public SyntaxNode {
    public:
        JSXMemberExpression();

        Sp<SyntaxNode> object;
        Sp<JSXIdentifier> property;

    };

    class JSXAttribute: public SyntaxNode {
    public:
        JSXAttribute();

        Sp<SyntaxNode> name;
        std::optional<Sp<SyntaxNode>> value;

    };

    class JSXNamespacedName: public SyntaxNode {
    public:
        JSXNamespacedName();

        Sp<JSXIdentifier> namespace_;
        Sp<JSXIdentifier> name;

    };

    class JSXOpeningElement: public SyntaxNode {
    public:
        JSXOpeningElement();

        Sp<SyntaxNode> name;
        bool self_closing = false;
        std::vector<Sp<SyntaxNode>> attributes;

    };

    class JSXSpreadAttribute: public SyntaxNode {
    public:
        JSXSpreadAttribute();

        Sp<Expression> argument;

    };

    class JSXText: public SyntaxNode {
    public:
        JSXText();

        UString value;
        UString raw;

    };

    class TSParameterProperty: public SyntaxNode {
    public:
        TSParameterProperty();

        bool readonly_ = false;
        Sp<SyntaxNode> parameter;

    };

    class TSDeclareFunction: public Declaration {
    public:
        TSDeclareFunction();

        Sp<Identifier> id;
        bool decare = false;
        Sp<TSTypeAnnotation> return_type;

    };

    class TSDeclareMethod: public SyntaxNode {
    public:
        TSDeclareMethod();


    };

    class TSQualifiedName: public SyntaxNode {
    public:
        TSQualifiedName();


    };

    class TSCallSignatureDeclaration: public SyntaxNode {
    public:
        TSCallSignatureDeclaration();


    };

    class TSConstructSignatureDeclaration: public SyntaxNode {
    public:
        TSConstructSignatureDeclaration();


    };

    class TSPropertySignature: public SyntaxNode {
    public:
        TSPropertySignature();


    };

    class TSMethodSignature: public SyntaxNode {
    public:
        TSMethodSignature();


    };

    class TSIndexSignature: public SyntaxNode {
    public:
        TSIndexSignature();


    };

    class TSAnyKeyword: public TSType {
    public:
        TSAnyKeyword();


    };

    class TSBooleanKeyword: public TSType {
    public:
        TSBooleanKeyword();


    };

    class TSBigIntKeyword: public TSType {
    public:
        TSBigIntKeyword();


    };

    class TSNeverKeyword: public TSType {
    public:
        TSNeverKeyword();


    };

    class TSNullKeyword: public TSType {
    public:
        TSNullKeyword();


    };

    class TSNumberKeyword: public TSType {
    public:
        TSNumberKeyword();


    };

    class TSObjectKeyword: public TSType {
    public:
        TSObjectKeyword();


    };

    class TSStringKeyword: public TSType {
    public:
        TSStringKeyword();


    };

    class TSSymbolKeyword: public TSType {
    public:
        TSSymbolKeyword();


    };

    class TSUndefinedKeyword: public TSType {
    public:
        TSUndefinedKeyword();


    };

    class TSUnknownKeyword: public TSType {
    public:
        TSUnknownKeyword();


    };

    class TSVoidKeyword: public TSType {
    public:
        TSVoidKeyword();


    };

    class TSThisType: public TSType {
    public:
        TSThisType();


    };

    class TSFunctionType: public TSType {
    public:
        TSFunctionType();


    };

    class TSConstructorType: public TSType {
    public:
        TSConstructorType();


    };

    class TSTypeReference: public TSType {
    public:
        TSTypeReference();


    };

    class TSTypePredicate: public TSType {
    public:
        TSTypePredicate();


    };

    class TSTypeQuery: public TSType {
    public:
        TSTypeQuery();


    };

    class TSTypeLiteral: public TSType {
    public:
        TSTypeLiteral();


    };

    class TSArrayType: public TSType {
    public:
        TSArrayType();


    };

    class TSTupleType: public TSType {
    public:
        TSTupleType();


    };

    class TSOptionalType: public TSType {
    public:
        TSOptionalType();


    };

    class TSRestType: public TSType {
    public:
        TSRestType();


    };

    class TSUnionType: public TSType {
    public:
        TSUnionType();


    };

    class TSIntersectionType: public TSType {
    public:
        TSIntersectionType();


    };

    class TSConditionalType: public TSType {
    public:
        TSConditionalType();


    };

    class TSInferType: public TSType {
    public:
        TSInferType();


    };

    class TSParenthesizedType: public TSType {
    public:
        TSParenthesizedType();


    };

    class TSTypeOperator: public TSType {
    public:
        TSTypeOperator();


    };

    class TSIndexedAccessType: public TSType {
    public:
        TSIndexedAccessType();


    };

    class TSMappedType: public TSType {
    public:
        TSMappedType();


    };

    class TSLiteralType: public TSType {
    public:
        TSLiteralType();


    };

    class TSExpressionWithTypeArguments: public TSType {
    public:
        TSExpressionWithTypeArguments();


    };

    class TSInterfaceDeclaration: public Declaration {
    public:
        TSInterfaceDeclaration();


    };

    class TSInterfaceBody: public SyntaxNode {
    public:
        TSInterfaceBody();


    };

    class TSTypeAliasDeclaration: public Declaration {
    public:
        TSTypeAliasDeclaration();

        Sp<Identifier> id;
        std::optional<Sp<TSTypeParameterDeclaration>> type_parameters;
        Sp<TSType> type_annotation;

    };

    class TSAsExpression: public Expression {
    public:
        TSAsExpression();


    };

    class TSTypeAssertion: public Expression {
    public:
        TSTypeAssertion();


    };

    class TSEnumDeclaration: public Declaration {
    public:
        TSEnumDeclaration();


    };

    class TSEnumMember: public SyntaxNode {
    public:
        TSEnumMember();


    };

    class TSModuleDeclaration: public Declaration {
    public:
        TSModuleDeclaration();


    };

    class TSModuleBlock: public SyntaxNode {
    public:
        TSModuleBlock();


    };

    class TSImportType: public TSType {
    public:
        TSImportType();


    };

    class TSImportEqualsDeclaration: public Declaration {
    public:
        TSImportEqualsDeclaration();


    };

    class TSExternalModuleReference: public SyntaxNode {
    public:
        TSExternalModuleReference();


    };

    class TSNonNullExpression: public Expression {
    public:
        TSNonNullExpression();


    };

    class TSExportAssignment: public Statement {
    public:
        TSExportAssignment();


    };

    class TSNamespaceExportDeclaration: public Statement {
    public:
        TSNamespaceExportDeclaration();


    };

    class TSTypeAnnotation: public SyntaxNode {
    public:
        TSTypeAnnotation();


    };

    class TSTypeParameterInstantiation: public SyntaxNode {
    public:
        TSTypeParameterInstantiation();


    };

    class TSTypeParameterDeclaration: public SyntaxNode {
    public:
        TSTypeParameterDeclaration();


    };

    class TSTypeParameter: public SyntaxNode {
    public:
        TSTypeParameter();


    };

}

