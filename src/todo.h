#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

class Todo {
  public:
    struct Task {
        std::string description;
        bool        completed = false;
    };

    void loadFromFile(const std::string& filename);

    void addTask(const std::string& description);
    void completeTask(const size_t index);
    void completeTasks(const std::vector<size_t> indices);
    void revokeCompletion(const size_t index);
    void deleteTask(const size_t index);
    void clearTasks();
    void listTasks() const;
    void saveToFile(const std::string& filename);

  private:
    std::vector<Task> m_tasks;
};
