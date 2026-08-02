// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string> &tasks) {
    cout << "Enter task: ";
    string task;
    getline(cin, task);
    if (!task.empty()) {
        tasks.push_back(task);
        cout << "Task added: \"" << task << "\"" << endl;
    } else {
        cout << "Error: Task description cannot be empty." << endl;
    }
}

bool viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
        return false;
    }
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
    return true;
}

void deleteTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Nothing to delete." << endl;
        return;
    }
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
    cout << "Enter task number to delete: ";
    int taskNum;
    if (cin >> taskNum) {
        cin.ignore();
        if (taskNum >= 1 && taskNum <= (int)tasks.size()) {
            string removed = tasks[taskNum - 1];
            tasks.erase(tasks.begin() + (taskNum - 1));
            cout << "Task \"" << removed << "\" has been removed." << endl;
        } else {
            cout << "Error: Invalid task number." << endl;
        }
    } else {
        cout << "Error: Please enter a valid integer task number." << endl;
        cin.clear();
        string junk;
        cin >> junk;
    }
}

int main() {
    vector<string> tasks;
    string choice;
    while (true) {
        cout << "\n============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        
        getline(cin, choice);
        if (choice == "4" || choice == "Quit" || choice == "quit") {
            cout << "Goodbye!" << endl;
            break;
        }
        if (choice == "1") {
            addTask(tasks);
        } else if (choice == "2") {
            viewTasks(tasks);
        } else if (choice == "3") {
            deleteTask(tasks);
        } else {
            cout << "Error: Invalid choice. Please select 1-4." << endl;
        }
    }
    return 0;
}

