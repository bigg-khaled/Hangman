#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
	char word[50];
	char dashes[50];
	int length;
	bool win = false;

	cout << "Choose a word: ";
	cin >> word;

	for (int i = 0; i < 50; i++) {
		cout << " " << endl;
	}
	
	for (int i = 0; i < 50; i++) {
		if (int(word[i]) == -52) {
			length = i-1;
			i = 50;
		}
	}

	cout << "Guess the word!" << endl;
	for (int i = 0; i < length; i++) {
		dashes[i] = '_';
	}
	for (int i = 0; i < length; i++) {
		cout << "_ ";
	}
	cout << endl;

	char guess;
	int letters_found = 0;
	int score = 6;
	while (win == false) {
		cout << endl << endl;
		for (int i = 0; i < length; i++) {
			cout << dashes[i] << " ";
		}
		cout << endl;
		cout << "Please enter a letter: ";
		cin >> guess;
		bool found = false;
		for (int i = 0; i < length; i++) {
			if (guess == word[i]) {
				cout << "you got the letter right!" << endl;
				dashes[i] = guess;
				letters_found++;
				for (int i = 0; i < length; i++) {
					cout << dashes[i] << " ";
				}
				found = true;
				cout << endl;
			}
			
		}
		if (found == false) {
			cout << "Try Again!" << endl << endl;
			score--;
			if (score <= 5)
				cout << " O ";
			if (score <= 4)
				cout << endl << "/";
			if (score <= 3)
				cout << "|";
			if (score <= 2)
				cout << '\\';
			if (score <= 1)
				cout << endl << '/' << " ";
			if (score <= 0)
				cout << "\\";
			cout << endl << endl << endl;

		}
		if (score == 0) {
			cout << "Wrong! the word was: " << word << endl << endl;
			win = true;
		}
		if (letters_found == length) {
			cout << endl << endl << "Congrats! you got the word right!!" << endl << endl;
			win = true;
		}
	}


}
