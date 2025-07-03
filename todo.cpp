#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Task {
    std::string description;
    std::string category;
    bool completed;
};

// Global task lists
std::vector<Task> tasks;

// File to save tasks
const std::string FILENAME = "todo_list.txt";

// Function declarations
void loadTasks();
void saveTasks();
void addTask();
void viewTasks();
void markTaskCompleted();
void removeTask();
void viewCompletedTasks();
void filterTasksByCategory();

int main() {
    loadTasks();
    int choice;
    do {
        std::cout << "\n--- Simple To-Do List ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. View Completed Tasks\n";
        std::cout << "4. Mark Task as Completed\n";
        std::cout << "5. Remove Task\n";
        std::cout << "6. Filter Tasks by Category\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // consume newline

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: viewCompletedTasks(); break;
            case 4: markTaskCompleted(); break;
            case 5: removeTask(); break;
            case 6: filterTasksByCategory(); break;
            case 0: saveTasks(); std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void loadTasks() {
    std::ifstream inFile(FILENAME);
    if (!inFile) return; // no file yet

    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        Task t;
        std::string completedFlag;
        if (getline(iss, t.description, '|') &&
            getline(iss, t.category, '|') &&
            getline(iss, completedFlag)) {
            t.completed = (completedFlag == "1");
            tasks.push_back(t);
        }
    }
}

void saveTasks() {
    std::ofstream outFile(FILENAME);
    for (const auto& t : tasks) {
        outFile << t.description << "|" << t.category << "|" << (t.completed ? "1" : "0") << "\n";
    }
}

void addTask() {
    Task t;
    std::cout << "Enter task description: ";
    std::getline(std::cin, t.description);
    std::cout << "Enter category (e.g., Work, Personal): ";
    std::getline(std::cin, t.category);
    t.completed = false;
    tasks.push_back(t);
    std::cout << "Task added.\n";
}

void viewTasks() {
    std::cout << "\n--- Current Tasks ---\n";
    int idx = 1;
    bool found = false;
    for (const auto& t : tasks) {
        if (!t.completed) {
            std::cout << idx << ". [" << t.category << "] " << t.description << "\n";
            found = true;
        }
        ++idx;
    }
    if (!found) std::cout << "No pending tasks.\n";
}

void viewCompletedTasks() {
    std::cout << "\n--- Completed Tasks ---\n";
    int idx = 1;
    bool found = false;
    for (const auto& t : tasks) {
        if (t.completed) {
            std::cout << idx << ". [" << t.category << "] " << t.description << "\n";
            found = true;
        }
        ++idx;
    }
    if (!found) std::cout << "No completed tasks.\n";
}

void markTaskCompleted() {
    viewTasks();
    std::cout << "Enter the task number to mark as completed: ";
    int num;
    std::cin >> num;
    std::cin.ignore();
    if (num < 1 || num > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    int idx = 1;
    for (auto& t : tasks) {
        if (!t.completed) {
            if (idx == num) {
                t.completed = true;
                std::cout << "Task marked as completed.\n";
                return;
            }
            ++idx;
        }
    }
    std::cout << "Task not found.\n";
}

void removeTask() {
    viewTasks();
    std::cout << "Enter the task number to remove: ";
    int num;
    std::cin >> num;
    std::cin.ignore();
    if (num < 1 || num > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    int idx = 1;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (!it->completed) {
            if (idx == num) {
                tasks.erase(it);
                std::cout << "Task removed.\n";
                return;
            }
            ++idx;
        }
    }
    std::cout << "Task not found.\n";
}

void filterTasksByCategory() {
    std::cout << "Enter category to filter: ";
    std::string filter;
    std::getline(std::cin, filter);
    std::cout << "\n--- Tasks in Category [" << filter << "] ---\n";
    int idx = 1;
    bool found = false;
    for (const auto& t : tasks) {
        if (!t.completed && t.category == filter) {
            std::cout << idx << ". " << t.description << "\n";
            found = true;
        }
        ++idx;
    }
    if (!found) std::cout << "No tasks found in this category.\n";
}
