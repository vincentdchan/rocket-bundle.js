/* Generated by Ruby Script! */

#include "syntax_nodes.h"

ArrayExpression::ArrayExpression(): Expression() {
    type = SyntaxNodeType::ArrayExpression;
}

ArrayPattern::ArrayPattern(): Pattern() {
    type = SyntaxNodeType::ArrayPattern;
}

ArrowFunctionExpression::ArrowFunctionExpression(): Expression() {
    type = SyntaxNodeType::ArrowFunctionExpression;
}

AssignmentExpression::AssignmentExpression(): Expression() {
    type = SyntaxNodeType::AssignmentExpression;
}

AssignmentPattern::AssignmentPattern(): Pattern() {
    type = SyntaxNodeType::AssignmentPattern;
}

AsyncArrowFunctionExpression::AsyncArrowFunctionExpression(): Expression() {
    type = SyntaxNodeType::AsyncArrowFunctionExpression;
}

AsyncFunctionDeclaration::AsyncFunctionDeclaration(): Declaration() {
    type = SyntaxNodeType::AsyncFunctionDeclaration;
}

AsyncFunctionExpression::AsyncFunctionExpression(): Expression() {
    type = SyntaxNodeType::AsyncFunctionExpression;
}

AwaitExpression::AwaitExpression(): Expression() {
    type = SyntaxNodeType::AwaitExpression;
}

BinaryExpression::BinaryExpression(): Expression() {
    type = SyntaxNodeType::BinaryExpression;
}

BlockStatement::BlockStatement(): Statement() {
    type = SyntaxNodeType::BlockStatement;
}

BreakStatement::BreakStatement(): Statement() {
    type = SyntaxNodeType::BreakStatement;
}

CallExpression::CallExpression(): Expression() {
    type = SyntaxNodeType::CallExpression;
}

CatchClause::CatchClause(): SyntaxNode() {
    type = SyntaxNodeType::CatchClause;
}

ClassBody::ClassBody(): SyntaxNode() {
    type = SyntaxNodeType::ClassBody;
}

ClassDeclaration::ClassDeclaration(): Declaration() {
    type = SyntaxNodeType::ClassDeclaration;
}

ClassExpression::ClassExpression(): Expression() {
    type = SyntaxNodeType::ClassExpression;
}

ComputedMemberExpression::ComputedMemberExpression(): Expression() {
    type = SyntaxNodeType::ComputedMemberExpression;
}

ConditionalExpression::ConditionalExpression(): Expression() {
    type = SyntaxNodeType::ConditionalExpression;
}

ContinueStatement::ContinueStatement(): Statement() {
    type = SyntaxNodeType::ContinueStatement;
}

DebuggerStatement::DebuggerStatement(): Statement() {
    type = SyntaxNodeType::DebuggerStatement;
}

Directive::Directive(): Statement() {
    type = SyntaxNodeType::Directive;
}

DoWhileStatement::DoWhileStatement(): Statement() {
    type = SyntaxNodeType::DoWhileStatement;
}

EmptyStatement::EmptyStatement(): Statement() {
    type = SyntaxNodeType::EmptyStatement;
}

ExportAllDeclaration::ExportAllDeclaration(): Declaration() {
    type = SyntaxNodeType::ExportAllDeclaration;
}

ExportDefaultDeclaration::ExportDefaultDeclaration(): Declaration() {
    type = SyntaxNodeType::ExportDefaultDeclaration;
}

ExportNamedDeclaration::ExportNamedDeclaration(): Declaration() {
    type = SyntaxNodeType::ExportNamedDeclaration;
}

ExportSpecifier::ExportSpecifier(): SyntaxNode() {
    type = SyntaxNodeType::ExportSpecifier;
}

ExpressionStatement::ExpressionStatement(): Statement() {
    type = SyntaxNodeType::ExpressionStatement;
}

ForInStatement::ForInStatement(): Statement() {
    type = SyntaxNodeType::ForInStatement;
}

ForOfStatement::ForOfStatement(): Statement() {
    type = SyntaxNodeType::ForOfStatement;
}

ForStatement::ForStatement(): Statement() {
    type = SyntaxNodeType::ForStatement;
}

FunctionDeclaration::FunctionDeclaration(): Declaration() {
    type = SyntaxNodeType::FunctionDeclaration;
}

FunctionExpression::FunctionExpression(): Expression() {
    type = SyntaxNodeType::FunctionExpression;
}

Identifier::Identifier(): Expression() {
    type = SyntaxNodeType::Identifier;
}

IfStatement::IfStatement(): Statement() {
    type = SyntaxNodeType::IfStatement;
}

Import::Import(): Expression() {
    type = SyntaxNodeType::Import;
}

ImportDeclaration::ImportDeclaration(): Declaration() {
    type = SyntaxNodeType::ImportDeclaration;
}

ImportDefaultSpecifier::ImportDefaultSpecifier(): SyntaxNode() {
    type = SyntaxNodeType::ImportDefaultSpecifier;
}

ImportNamespaceSpecifier::ImportNamespaceSpecifier(): SyntaxNode() {
    type = SyntaxNodeType::ImportNamespaceSpecifier;
}

ImportSpecifier::ImportSpecifier(): SyntaxNode() {
    type = SyntaxNodeType::ImportSpecifier;
}

LabeledStatement::LabeledStatement(): Statement() {
    type = SyntaxNodeType::LabeledStatement;
}

Literal::Literal(): Expression() {
    type = SyntaxNodeType::Literal;
}

MetaProperty::MetaProperty(): SyntaxNode() {
    type = SyntaxNodeType::MetaProperty;
}

MethodDefinition::MethodDefinition(): SyntaxNode() {
    type = SyntaxNodeType::MethodDefinition;
}

Module::Module(): SyntaxNode() {
    type = SyntaxNodeType::Module;
}

NewExpression::NewExpression(): Expression() {
    type = SyntaxNodeType::NewExpression;
}

ObjectExpression::ObjectExpression(): Expression() {
    type = SyntaxNodeType::ObjectExpression;
}

ObjectPattern::ObjectPattern(): Pattern() {
    type = SyntaxNodeType::ObjectPattern;
}

Property::Property(): SyntaxNode() {
    type = SyntaxNodeType::Property;
}

RegexLiteral::RegexLiteral(): SyntaxNode() {
    type = SyntaxNodeType::RegexLiteral;
}

RestElement::RestElement(): SyntaxNode() {
    type = SyntaxNodeType::RestElement;
}

ReturnStatement::ReturnStatement(): Statement() {
    type = SyntaxNodeType::ReturnStatement;
}

Script::Script(): SyntaxNode() {
    type = SyntaxNodeType::Script;
}

SequenceExpression::SequenceExpression(): Expression() {
    type = SyntaxNodeType::SequenceExpression;
}

SpreadElement::SpreadElement(): SyntaxNode() {
    type = SyntaxNodeType::SpreadElement;
}

StaticMemberExpression::StaticMemberExpression(): Expression() {
    type = SyntaxNodeType::StaticMemberExpression;
}

Super::Super(): SyntaxNode() {
    type = SyntaxNodeType::Super;
}

SwitchCase::SwitchCase(): SyntaxNode() {
    type = SyntaxNodeType::SwitchCase;
}

SwitchStatement::SwitchStatement(): Statement() {
    type = SyntaxNodeType::SwitchStatement;
}

TaggedTemplateExpression::TaggedTemplateExpression(): Expression() {
    type = SyntaxNodeType::TaggedTemplateExpression;
}

TemplateElement::TemplateElement(): SyntaxNode() {
    type = SyntaxNodeType::TemplateElement;
}

ThisExpression::ThisExpression(): Expression() {
    type = SyntaxNodeType::ThisExpression;
}

ThrowStatement::ThrowStatement(): Statement() {
    type = SyntaxNodeType::ThrowStatement;
}

TryStatement::TryStatement(): Statement() {
    type = SyntaxNodeType::TryStatement;
}

UnaryExpression::UnaryExpression(): Expression() {
    type = SyntaxNodeType::UnaryExpression;
}

UpdateExpression::UpdateExpression(): Expression() {
    type = SyntaxNodeType::UpdateExpression;
}

VariableDeclaration::VariableDeclaration(): Declaration() {
    type = SyntaxNodeType::VariableDeclaration;
}

VariableDeclarator::VariableDeclarator(): SyntaxNode() {
    type = SyntaxNodeType::VariableDeclarator;
}

WhileStatement::WhileStatement(): Statement() {
    type = SyntaxNodeType::WhileStatement;
}

WithStatement::WithStatement(): Statement() {
    type = SyntaxNodeType::WithStatement;
}

YieldExpression::YieldExpression(): Expression() {
    type = SyntaxNodeType::YieldExpression;
}
