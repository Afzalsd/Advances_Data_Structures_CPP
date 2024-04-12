#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void searchPattern(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    cout << "1. From File" << endl;
    cout << "2. From User" << endl;
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        ifstream file("input.txt");
        string text, pattern;
        getline(file, text);
        cout << "Enter Pattern: ";
        cin >> pattern;
        searchPattern(text, pattern);
        file.close();
    } else {
        string text, pattern;
        cout << "Enter Text: ";
        cin >> text;
        cout << "Enter Pattern: ";
        cin >> pattern;
        searchPattern(text, pattern);
    }
    return 0;
}
