#include <bits/stdc++.h>
using namespace std;

string encode(string str, int shift) {
    string duplicate = str;
    for (int i = 0; i < str.length(); i++) {
        char lower, upper;
        // Checks the case of letter and whether it is valid letter
        if (str[i] >= 'A' && str[i] <= 'Z') {
            lower = 'A';
            upper = 'Z';
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            lower = 'a';
            upper = 'z';
        } else {
            return "Invalid Character";
        }

        // Encoding with positive and negative shifts
        if (str[i] + shift > upper) {
            duplicate[i] = str[i] - 26 + shift;
        } else if (str[i] + shift < lower) {
            duplicate[i] = str[i] + 26 + shift;
        } else {
            duplicate[i] = str[i] + shift;
        }
    }
    return duplicate;
}

int main() {
    string original, duplicate;
    int shift;
    cout << "Enter the string to be encoded: ";
    cin >> original;
    cout << "Enter the shift: ";
    cin >> shift;
    duplicate = encode(original, shift);
    cout << "The encoded string is: " << duplicate;
    return 0;
}