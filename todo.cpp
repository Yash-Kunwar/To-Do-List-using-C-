#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

// Class representing a to-do item
class todoItem
{
private:
    int id;             // Unique identifier for the to-do item
    string description; // Description of the task
    bool completed;     // Completion status of the task

public:
    todoItem() : id(0), description(""), completed(false) {} // Constructor initializing members
    ~todoItem() = default;                                   // Default destructor

    // Method to create a new to-do item with a description
    bool create(string new_description)
    {
        id = rand() % 100 + 1; // Generate a random ID between 1 and 100
        description = new_description;
        return true;
    }

    // Getter methods
    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }

    // Setter method to mark the task as completed
    void setCompleted(bool val)
    {
        completed = val;
    }
};

int main()
{
    char input_option;           // User's menu choice
    int input_id;                // ID input for marking tasks completed
    string input_description;    // Description input for new tasks
    list<todoItem> todoItems;    // List to store to-do items
    list<todoItem>::iterator it; // Iterator to traverse the list

    srand(time(NULL)); // Seed the random number generator

    todoItems.clear(); // Clear the list initially

    while (1)
    {
        // Display the menu and to-do list
        cout << "TO DO LIST Maker - " << endl;
        system("cls"); // Clear the console (platform-specific, Windows)
        cout << endl
             << endl;

        // Display each to-do item
        for (it = todoItems.begin(); it != todoItems.end(); it++)
        {
            string completed = it->isCompleted() ? "done" : "not done";
            cout << it->getId() << " | " << it->getDescription() << " | " << (it->isCompleted() ? "Completed" : "Not Completed") << endl;
        }

        // Prompt to add the first task if the list is empty
        if (todoItems.empty())
        {
            cout << "Add your first task: " << endl
                 << endl;
        };

        // Display menu options
        cout << "[a]dd a new task" << endl;
        cout << "[c]omplete a task" << endl;
        cout << "[q]uit" << endl;

        cout << "choice: ";
        cin >> input_option;

        if (input_option == 'q')
        {
            cout << "Have a great day!" << endl;
            break; // Exit the loop and end the program
        }
        else if (input_option == 'a')
        {
            // Add a new task
            cout << "Add a new task: ";
            cin.clear();  // Clear any error flags on cin
            cin.ignore(); // Ignore the rest of the current line

            getline(cin, input_description); // Get the entire line of input

            todoItem newItem;                  // Create a new todoItem
            newItem.create(input_description); // Initialize it with the description
            todoItems.push_back(newItem);      // Add it to the list
        }
        else if (input_option == 'c')
        {
            // Mark a task as completed
            cout << "Enter ID to mark completed: ";
            cin >> input_id;
            for (it = todoItems.begin(); it != todoItems.end(); it++)
            {
                if (input_id == it->getId())
                {
                    it->setCompleted(true); // Mark the item as completed
                    break;
                }
            }
        }
    }
    return 0;
}
