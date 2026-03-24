#include "Library.h"
#include <iostream>
using namespace std;

// -------------------- Show Only Available Resources --------------------
void Library::showAvailableResources() const
{
    bool found = false;

    cout << "\nAvailable Resources:\n";

    for (auto res : resources)
    {
        if (res->getAvailableCopies() > 0)
        {
            res->displayInfo();  // polymorphic call
            found = true;
        }
    }

    if (!found)
        cout << "No resources currently available.\n";
}

// -------------------- Register New User --------------------
void Library::registerUser()
{
    string name, username, password, address;

    cout << "Enter full name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter address: ";
    cin >> ws;
    getline(cin, address);

    int newID = users.size() + 1;  // generate simple new ID

    User* newUser = new User(newID, "user", username, password, name, address, 0.0);
    users.push_back(newUser);

    cout << "User registered successfully!\n";
}

// -------------------- Search Resources (Full: title, author, category, type) --------------------
void Library::searchResources() const
{
    int choice;
    string keyword;
    bool found = false;

    cout << "Search by:\n";
    cout << "1. Title\n";
    cout << "2. Author/Creator\n";
    cout << "3. Category\n";
    cout << "4. Type (book, dvd, audiobook, magazine, newspaper)\n";
    cout << "Enter choice: ";
    cin >> choice;

    cin.ignore(); // flush newline

    cout << "Enter keyword: ";
    getline(cin, keyword);

    cout << "\nSearch Results:\n";

    for (auto res : resources)
    {
        switch (choice)
        {
            case 1: // Title
                if (res->getTitle().find(keyword) != string::npos)
                {
                    res->displayInfo();
                    found = true;
                }
                break;

            case 2: // Author/Creator
                if (res->getAuthorCreator().find(keyword) != string::npos)
                {
                    res->displayInfo();
                    found = true;
                }
                break;

            case 3: // Category
                if (res->getCategory().find(keyword) != string::npos)
                {
                    res->displayInfo();
                    found = true;
                }
                break;

            case 4: // Type
                if (res->getType().find(keyword) != string::npos)
                {
                    res->displayInfo();
                    found = true;
                }
                break;

            default:
                cout << "Invalid choice!\n";
                return;
        }
    }

    if (!found)
        cout << "NOT FOUND!!!.\n USE DIFFERENT KEYWORDS";
}