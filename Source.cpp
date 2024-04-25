#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isAlphabetic(char c) {
    return isalpha(c) || c == '\'';
}
 
string scramble(string word) {
    if (word.length() <= 3) {
        return word;
    }

    // Generate random indices for character swapping
    int index1, index2;
    do {
        index1 = rand() % (word.length() - 2) + 1;
        index2 = rand() % (word.length() - 2) + 1;
    } while (index2 == index1 || !isAlphabetic(word[index1]) || !isAlphabetic(word[index2]));

    // Swap characters at index1 and index2
    char temp = word[index1];
    word[index1] = word[index2];
    word[index2] = temp;

    return word;
}

int main() {
    srand(time(nullptr));

    string line;
    cout << "Enter a line of text: ";
    getline(cin, line);

    string word;
    for (char c : line) {
        if (isAlphabetic(c)) {
            word += c;
        }
        else {
            if (!word.empty()) {
                cout << scramble(word);
                word.clear();
            }
            cout << c;
        }
    }
    if (!word.empty()) {
        cout << scramble(word);
    }

    return 0;
}
