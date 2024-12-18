#include "todo.h"
#include <print>
#include <vector>
#include <iostream>

void Todo::addTask(const std::string& description) {
    m_tasks.push_back({description, false});
}

void Todo::completeTask(const size_t index) {
    if (index < m_tasks.size()) {
        m_tasks[index].completed = true;
    }
}

void Todo::revokeCompletion(const size_t index) {
    if (index < m_tasks.size()) {
        m_tasks[index].completed = false;
    }
}

void Todo::deleteTask(const size_t index) {
    if (index < m_tasks.size()) {
        m_tasks.erase(m_tasks.begin() + index);
    }
}

void Todo::clearTasks() {
    if (m_tasks.empty()) {
        std::print("No tasks available to clear");
        return;
    }
    std::string response;
    std::print("Are you sure you want to clear all tasks? (Type IWANTTODELETEMYSTUFF in all caps) ");
    std::cin >> response;

    if (response == "IWANTTODELETEMYSTUFF") {
        m_tasks.clear();
        std::println("Your tasks have been cleared");
    }
}

void Todo::listTasks() const {
    if (m_tasks.empty()) {
        std::print("No tasks available.\n");
        return;
    }
    for (size_t i = 0; i < m_tasks.size(); i++) {
        std::print("{}: {}{}\n", i + 1, (m_tasks[i].completed ? "[x] " : "[ ] "), m_tasks[i].description);
    }
}

void Todo::saveToFile(const std::string& filename) {
    nlohmann::json json;
    for (const auto& task : m_tasks) {
        json.push_back({{"description", task.description}, {"completed", task.completed}});
    }
    std::ofstream file(filename);
    file << json.dump(4);
}

void Todo::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        nlohmann::json json;
        file >> json;
        m_tasks.clear();
        for (const auto& item : json) {
            m_tasks.push_back({item["description"], item["completed"]});
        }
    }
}
