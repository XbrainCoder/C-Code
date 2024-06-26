// C++ program for text editor

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> textBuffer;

void loadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return;
    }

    string line;
    textBuffer.clear();
    while (getline(file, line)) {
        textBuffer.push_back(line);
    }

    file.close();
    cout << "File loaded successfully." << endl;
}

void saveFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return;
    }

    for (const auto& line : textBuffer) {
        file << line << endl;
    }

    file.close();
    cout << "File saved successfully." << endl;
}

void displayContent() {
    cout << "Text Content:" << endl;
    for (size_t i = 0; i < textBuffer.size(); ++i) {
        cout << i + 1 << ": " << textBuffer[i] << endl;
    }
}

void editContent() {
    cout << "Enter the line number to edit (0 to stop): ";
    int lineNumber;
    cin >> lineNumber;

    while (lineNumber > 0 && lineNumber <= textBuffer.size()) {
        cout << "Editing line " << lineNumber << ": " << textBuffer[lineNumber - 1] << endl;
        cout << "Enter new text: ";
        cin.ignore();
        string newText;
        getline(cin, newText);
        textBuffer[lineNumber - 1] = newText;

        cout << "Enter the line number to edit (0 to stop): ";
        cin >> lineNumber;
    }
}

int main() {
    string filename;
    int choice;

    while (true) {
        cout << "Simple Text Editor" << endl;
        cout << "1. Open File" << endl;
        cout << "2. Save File" << endl;
        cout << "3. Display Content" << endl;
        cout << "4. Edit Content" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter filename to open: ";
                cin >> filename;
                loadFile(filename);
                break;
            case 2:
                cout << "Enter filename to save: ";
                cin >> filename;
                saveFile(filename);
                break;
            case 3:
                displayContent();
                break;
            case 4:
                editContent();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
