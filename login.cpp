#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Check if a username already exists in the file
bool isUsernameTaken(const string& username) {
    ifstream file("users.txt");
    if (!file.is_open()) {
        return false; // File doesn't exist yet, so user isn't taken
    }

    string fileUser, filePass;
    while (file >> fileUser >> filePass) {
        if (fileUser == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Register a new user
void registerUser() {
    string username, password;
    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Error: Username already exists! Please choose another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "Error: Username and Password cannot be empty!\n";
        return;
    }

    // Append user credentials to file
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
        cout << "Registration successful! You can now log in.\n";
    } else {
        cout << "Error: Unable to open file for saving credentials.\n";
    }
}

// Login verification
void loginUser() {
    string username, password;
    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "Error: No registered users found. Please register first.\n";
        return;
    }

    string fileUser, filePass;
    bool loginSuccess = false;

    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            loginSuccess = true;
            break;
        }
    }
    file.close();

    if (loginSuccess) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Error: Invalid username or password!\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n======================================\n";
        cout << "     LOGIN & REGISTRATION SYSTEM      \n";
        cout << "======================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please select 1, 2, or 3.\n";
        }
    }

    return 0;
}