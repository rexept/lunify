#include "todo.h"
#include <print>

void Todo::addTask(const std::string& description) {
    tasks.push_back({description, false});
}

void Todo::completeTask(size_t index) {
    if (index < tasks.size()) {
        tasks[index + 1].completed = true;
    }
}

void Todo::deleteTask(size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void Todo::listTasks() const {
    if (tasks.empty()) {
        std::print("No tasks available.\n");
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        std::print("{}: {}{}\n", i + 1, (tasks[i].completed ? "[x] " : "[ ] "), tasks[i].description);
    }
}

void Todo::saveToFile(const std::string& filename) {
    nlohmann::json json;
    for (const auto& task : tasks) {
        json.push_back({{"description", task.description}, {"completed", task.completed}});
    }
    std::ofstream file(filename);
    file << json.dump(4);
}

void Todo::loadFromFile(std::string filename) {
    std::ifstream file(filename);
    if (file) {
        nlohmann::json json;
        file >> json;
        tasks.clear();
        for (const auto& item : json) {
            tasks.push_back({item["description"], item["completed"]});
        }
    }
}
