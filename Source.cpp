#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string scramble(string word) {
	if (word.length() <= 3) {
		return word;
	}

	int index1 = rand() % (word.length() - 2) + 1;
	int index2;
	do {
		index2 = rand() % (word.length() - 2) + 1;
	} while (index2 == index1);

	char temp = word[index1];
	word[index1] = word[index2];
	word[index2] = temp;

	return word;
}

int main() {

}