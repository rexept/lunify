#ifndef TODO_H
#define TODO_H

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

    void loadFromFile(std::string filename);

    void addTask(const std::string& description);
    void completeTask(size_t index);
    void revokeCompletion(size_t index);
    void deleteTask(size_t index);
    void listTasks() const;
    void saveToFile(const std::string& filename);

  private:
    std::vector<Task> tasks;
};

#endif // TODO_H
