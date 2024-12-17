#include <CLI11.hpp>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <print>
#include <filesystem>
#include "todo.h"

namespace fs = std::filesystem;

#define XDG_CONFIG_HOME "XDG_CONFIG_HOME"

int main(int argc, char** argv) {
    int         EXIT_STATUS = EXIT_SUCCESS;

    CLI::App    app{"A CLI to-do list"};

    std::string c_XDG_CONFIG_HOME;

    if (!getenv(XDG_CONFIG_HOME)) {
        std::cerr << "Are you on Linux?\n ERROR: $XDG_CONFIG_HOME not found.";
        return EXIT_FAILURE;
    }

    c_XDG_CONFIG_HOME = getenv(XDG_CONFIG_HOME);

    std::string TODO_DB_DIR  = c_XDG_CONFIG_HOME + "/lunify";
    std::string TODO_DB_PATH = TODO_DB_DIR + "/lunify.json";

    if (!fs::exists(TODO_DB_DIR)) {
        if (!fs::create_directories(TODO_DB_DIR)) {
            std::cerr << "Failed to create database path" << std::endl;
            return EXIT_FAILURE;
        }
    }

    Todo todo;
    todo.loadFromFile(TODO_DB_PATH);

    auto addTask = [&todo](std::string task) { todo.addTask(task); };
    app.add_option("-a,--add", "Add a new task")->each(addTask);

    auto completeTask = [&todo, &EXIT_STATUS](std::string index) {
        std::stringstream sstream(index);
        size_t            result;
        if (!(sstream >> result)) {
            std::cerr << "Invalid type, please provide a numbered index" << std::endl;
            EXIT_STATUS = EXIT_FAILURE;
            return EXIT_STATUS;
        }
        todo.completeTask(result - 1);
        return EXIT_STATUS;
    };
    app.add_option("-c,--complete", "Mark task as completed")->each(completeTask);

    auto deleteTask = [&todo, &EXIT_STATUS](std::string index) {
        std::stringstream sstream(index);
        size_t            result;
        if (!(sstream >> result)) {
            std::cerr << "Invalid type, please provide a numbered index" << std::endl;
            EXIT_STATUS = EXIT_FAILURE;
            return EXIT_STATUS;
        }
        todo.deleteTask(result - 1);
        return EXIT_STATUS;
    };
    app.add_option("-d,--delete", "Delete a task")->each(deleteTask);

    auto listTasks = [&todo](int nothing) { todo.listTasks(); };
    app.add_flag("-l,--list", listTasks, "List all tasks");

    // Save tasks on exit
    app.callback([&todo, &TODO_DB_PATH]() { todo.saveToFile(TODO_DB_PATH); });

    CLI11_PARSE(app, argc, argv);
    return EXIT_STATUS;
}
