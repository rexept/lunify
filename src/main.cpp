#include <CLI11.hpp>
#include <iostream>
#include <cstdlib>
#include <print>
#include <filesystem>
#include "todo.h"

namespace fs = std::filesystem;

#define XDG_CONFIG_HOME "XDG_CONFIG_HOME"

int main(int argc, char** argv) {
    CLI::App    app{"A CLI to-do list"};

    std::string c_XDG_CONFIG_HOME;

    if (!getenv(XDG_CONFIG_HOME)) {
        std::cerr << "Are you on Linux?\n ERROR: $XDG_CONFIG_HOME not found.";
        return EXIT_FAILURE;
    }

    c_XDG_CONFIG_HOME = getenv(XDG_CONFIG_HOME);

    std::string TODO_DB_PATH = c_XDG_CONFIG_HOME + "/lunify/lunify.json";
    std::print("{}", TODO_DB_PATH);

    if (!fs::exists(TODO_DB_PATH)) {
        if (!fs::create_directories(TODO_DB_PATH)) {
            std::cerr << "Failed to create database path" << std::endl;
            return EXIT_FAILURE;
        }
    }

    Todo todo{TODO_DB_PATH};

    CLI11_PARSE(app, argc, argv);
    return EXIT_SUCCESS;
}
