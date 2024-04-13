#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//this is compute lps array function that computes lps array which is used in kmp search
void computeLPSArray(const string& pattern, int m, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    // lps[0] = 0; // lps[0] is always 0 for string with one character
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
//this is kunth moris pratt function that searches for pattern in text using lps array which is computed in computeLPSArray function
void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    computeLPSArray(pattern, m, lps);

    int j = 0;
    int i = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    cout << "1. From File" << endl;
    cout << "2. From User" << endl;
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        ifstream file("input.txt");
        if (!file.is_open()) {
            cout << "Error: Could not open file!" << endl;
            return 1;
        }
        string text, pattern;
        getline(file, text);
        cout << "Enter Pattern: ";
        getline(cin, pattern);
        KMPSearch(text, pattern);
        file.close();
    } else {
        string text, pattern;
        cout << "Enter Text: ";
        getline(cin, text);
        cout << "Enter Pattern: ";
        getline(cin, pattern);
        KMPSearch(text, pattern);
    }
    return 0;
}
