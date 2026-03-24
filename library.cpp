#include "Library.h"
#include <iostream>
#include <iomanip>
using namespace std;

// -------------------- Show (Available) Resources Only--------------------
void Library::showAvailableResources() const
{
    cout << "\nAvailable Resources in " << libraryName << endl;
    cout << left << setw(6)  << "ID"
                 << setw(35) << "Title"
                 << setw(15) << "Type"
                 << setw(15) << "Available" << endl;
    cout << string(71, '-') << endl;

    bool found = false;
    for (auto res : resources)
    {
        if (res->getAvailableCopies() > 0)
        {
            cout << left << setw(6)  << res->getResourceID()
                         << setw(35) << res->getTitle()
                         << setw(15) << res->getType()
                         << setw(15) << res->getAvailableCopies() << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No resources currently available.\n";
}

// -------------------- Add New User --------------------
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

    int newID = users.size() + 1;  // ID allotment

    User* newUser = new User(newID, "user", username, password, name, address, 0.0);
    users.push_back(newUser);

    cout << "User registered successfully!\n";
}

// -------------------- Search Resources --------------------
void Library::searchResources() const
{
    int choice;
    string keyword;
    bool found = false;

    cout << "\nSearch by:\n";
    cout << "1. Title\n";
    cout << "2. Author/Creator\n";
    cout << "3. Category\n";
    cout << "4. Type (book, dvd, audiobook, magazine, newspaper)\n";
    cout << "Enter choice: ";
    cin >> choice;

    cin.ignore();

    cout << "Enter keyword: ";
    getline(cin, keyword);

    cout << "\nSearch Results:\n";
    cout << left << setw(6)  << "ID"
                 << setw(35) << "Title"
                 << setw(15) << "Type"
                 << setw(15) << "Available" << endl;
    cout << string(71, '-') << endl;

    for (auto res : resources)
    {
        bool match = false;

        switch (choice)
        {
            case 1: //for Title
                if (res->getTitle().find(keyword) != string::npos)
                    match = true;
                break;

            case 2: // for Author/creator
                if (res->getAuthorCreator().find(keyword) != string::npos)
                    match = true;
                break;

            case 3: // for Category
                if (res->getCategory().find(keyword) != string::npos)
                    match = true;
                break;

            case 4: // for Type
                if (res->getType().find(keyword) != string::npos)
                    match = true;
                break;

            default:
                cout << "Invalid choice!\n";
                return;
        }

        if (match)
        {
            cout << left << setw(6)  << res->getResourceID()
                         << setw(35) << res->getTitle()
                         << setw(15) << res->getType()
                         << setw(15) << res->getAvailableCopies() << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No matching resources found.\n";
}
