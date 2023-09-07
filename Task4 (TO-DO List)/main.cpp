#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};


void addTask(vector<Task>& tasks, const string& description) {
    Task task(description);
    tasks.push_back(task);
   cout << "Task added: " << description << endl;
}


void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
       cout << "Task List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
          cout << i + 1 << ". ";
            if (tasks[i].completed) {
              cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << std::endl;
        }
    }
}


void markTaskCompleted(vector<Task>& tasks, int taskNumber) {
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
       cout << "Task marked as completed: " << tasks[taskNumber - 1].description << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}


void removeTask(vector<Task>& tasks, int taskNumber) {
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
       cout << "Task removed: " << tasks[taskNumber - 1].description << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    } else {
        cout << "Invalid task number." <<endl;
    }
}

int main() {
   vector<Task> tasks;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
       cout << "2. View Tasks\n";
      cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
       cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1: {
                cin.ignore();
            string description;
               cout << "Enter task description: ";
               getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2: {
                viewTasks(tasks);
                break;
            }
            case 3: {
                viewTasks(tasks);
                int taskNumber;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                markTaskCompleted(tasks, taskNumber);
                break;
            }
            case 4: {
                viewTasks(tasks);
                int taskNumber;
               cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                removeTask(tasks, taskNumber);
                break;
            }
            default:
               cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}




