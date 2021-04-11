//
// Created by Duzhong Chen on 2019/10/30.
//
#include "ParserContext.h"

namespace jetpack::parser {
    using namespace std;

    ParserContext::Config ParserContext::Config::Default() {
        return {
            nullopt,
            false,
            true,
            false,
            false,
            false,
            false,
            false,
            true,
        };
    }

    ParserContext::ParserContext(int32_t fileId, const UString& src, const Config& config):
        fileIndex(fileId), config_(config), source_(src) {
        error_handler_ = std::make_shared<ParseErrorHandler>();

        scanner_ = make_unique<Scanner>(source_, error_handler_);
        has_line_terminator_ = false;

        lookahead_.type = JsTokenType::EOF_;
        lookahead_.lineNumber = scanner_->LineNumber();
        lookahead_.lineStart = 0;
        lookahead_.range = make_pair(0, 0);

        is_module_ = false;
        await_ = false;
        allow_in_ = true;
        allow_strict_directive_ = true;
        allow_yield_ = true;
        is_assignment_target_ = false;
        is_binding_element_ = false;
        in_function_body_ = false;
        in_iteration_ = false;
        in_switch_ = false;
        strict_ = false;

        label_set_ = std::make_unique<std::unordered_set<UString>>();
    }

}
