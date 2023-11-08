#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype> // for std::tolower

// Function to convert a string to lowercase
using namespace std;
string toLowercase(const string& str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}

int main() {
    cout << "😃  Phonebook Search Program" << endl;
    cout << "❓  This program can read data from a file and display the results from the .txt file." << endl;
    ifstream phonebookFile("phonebook.txt");
    if (!phonebookFile) {
        cerr << "⚠️  Error: Could not open the phonebook file." << endl;
        return 1;
    }
    vector<string> phonebook;
    string line;
    while (getline(phonebookFile, line)) {
        phonebook.push_back(line);
    }
    phonebookFile.close();
    cout << "➡️  Enter a name or partial name to search for: ";
    string searchName;
    getline(cin, searchName);
    string searchNameLower = toLowercase(searchName);
    vector<string> matchingEntries;
    for (const string& entry : phonebook) {
        size_t colonPos = entry.find(": ");
        if (colonPos != string::npos) {
            string name = entry.substr(0, colonPos);
            string phoneNumber = entry.substr(colonPos + 2); // Skip ": "
            string nameLower = toLowercase(name);
            if (nameLower.find(searchNameLower) != string::npos) {
                matchingEntries.push_back(name + ": " + phoneNumber);
            }
        }
    }
    cout << endl;
    cout << "☑️  Here are the results of the search:" << endl;
    if (matchingEntries.empty()) {
        cout << "⚠️  No matching entries found for '" << searchName << "'." << endl;
    } else {
        for (const string& match : matchingEntries) {
            cout << match << endl;
        }
    }

    return 0;
}
