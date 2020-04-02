//
// Created by Duzhong Chen on 2020/3/20.
//

//#ifndef _WIN32
//#include <jemalloc/jemalloc.h>
//#endif

#include <iostream>
#include <cxxopts.hpp>

#include "Path.h"
#include "ModuleResolver.h"
#include "codegen/CodeGen.h"
#include "parser/ParserContext.h"

#define OPT_HELP "help"
#define OPT_ENTRY "entry"
#define OPT_TOLERANT "tolerant"
#define OPT_JSX "jsx"
#define OPT_LIBRARY "library"
#define OPT_ANALYZE_MODULE "analyze-module"
#define OPT_NO_TRACE "no-trace"
#define OPT_MINIFY "minify"
#define OPT_OUT "out"

using namespace jetpack;

static int AnalyzeModule(const std::string& self_path,
                         const std::string& path,
                         bool jsx,
                         bool trace_file);

static int BundleModule(const std::string& self_path,
                        bool jsx,
                        bool minify,
                        bool library,
                        const std::string& path,
                        const std::string& out_path);

int main(int argc, char** argv) {
    try {
        cxxopts::Options options("rocket-bundle", "Rocket Bundle command line");
        options.add_options()
                (OPT_ENTRY, "entry file to parse", cxxopts::value<std::string>())
                (OPT_TOLERANT, "tolerant parsing error")
                (OPT_JSX, "support jsx syntax")
                (OPT_LIBRARY, "bundle as library, do not bundle node_modules")
                (OPT_HELP, "produce help message")
                (OPT_ANALYZE_MODULE, "analyze a module and print result", cxxopts::value<std::string>())
                (OPT_NO_TRACE, "do not trace ref file when analyze module")
                (OPT_MINIFY, "minify the code")
                (OPT_OUT, "output filename of bundle", cxxopts::value<std::string>())
                ;

        options.parse_positional(OPT_ENTRY);

        auto result = options.parse(argc, argv);
        bool trace_file = true;
        bool minify = false;
        bool jsx = false;
        bool library = false;

        // print help message
        if (result[OPT_HELP].count()) {
            std::cout << options.help() << std::endl;
            return !result[OPT_HELP].count();
        }

        if (result[OPT_NO_TRACE].count()) {
            trace_file = false;
        }

        if (result[OPT_MINIFY].count()) {
            minify = true;
        }

        if (result[OPT_JSX].count()) {
            jsx = true;
        }

        if (result[OPT_LIBRARY].count()) {
            library = true;
        }

        if (result[OPT_ANALYZE_MODULE].count()) {
            std::string path = result[OPT_ANALYZE_MODULE].as<std::string>();
            return AnalyzeModule(argv[0], path, jsx, trace_file);
        }

        if (result[OPT_OUT].count()) {
            std::string entry_path = result[OPT_ENTRY].as<std::string>();
            std::string out_path = result[OPT_OUT].as<std::string>();

            return BundleModule(argv[0], jsx, minify, library, entry_path, out_path);
        }

        std::cout << options.help() << std::endl;
        return 0;
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 3;
    }
}

static int AnalyzeModule(const std::string& self_path_str,
                         const std::string& path,
                         bool jsx,
                         bool trace_file) {
    Path self_path(self_path_str);
    self_path.Pop();

    parser::ParserContext::Config parser_config = parser::ParserContext::Config::Default();
    if (jsx) {
        parser_config.jsx = true;
    }

    // do not release memory
    // it will save your time
    auto resolver = std::shared_ptr<ModuleResolver>(new ModuleResolver, [](void*) {});

    try {
        resolver->SetTraceFile(trace_file);
        resolver->BeginFromEntry(parser_config, self_path.ToString(), path);
        resolver->PrintStatistic();
        return 0;
    } catch (ModuleResolveException& err) {
        err.PrintToStdErr();
        return 3;
    }
}

static int BundleModule(const std::string& self_path_str,
                        bool jsx,
                        bool minify,
                        bool library,
                        const std::string& path,
                        const std::string& out_path) {

    Path self_path(self_path_str);
    self_path.Pop();

    try {
        auto resolver = std::shared_ptr<ModuleResolver>(new ModuleResolver, [](void*) {});
        CodeGen::Config codegen_config;
        parser::ParserContext::Config parser_config = parser::ParserContext::Config::Default();

        if (jsx) {
            parser_config.jsx = true;
            parser_config.transpile_jsx = true;
        }

        if (minify) {
            codegen_config.minify = true;
            codegen_config.comments = false;
            resolver->SetNameGenerator(MinifyNameGenerator::Make());
        }

        resolver->SetTraceFile(true);
        resolver->BeginFromEntry(parser_config, self_path.ToString(), path);
        resolver->CodeGenAllModules(codegen_config, out_path);

        std::cout << "Finished." << std::endl;
        std::cout << "Totally " << resolver->ModCount() << " file(s)." << std::endl;
        return 0;
    } catch (ModuleResolveException& err) {
        err.PrintToStdErr();
        return 3;
    }
}