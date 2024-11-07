#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>

using namespace std;

void ST(int kolor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, kolor);
}

void patternset(char pattern[4], vector<char> all) {
	for (int i = 0; i < 4; i++) {
		pattern[i] = all[i];
	}
}

void showpattern(char pattern[4]) {
	for (int i = 0; i < 4; i++) {
		if (pattern[i] == 'g') {
			ST(10);
		}
		if (pattern[i] == 'b') {
			ST(11);
		}
		if (pattern[i] == 'r') {
			ST(12);
		}
		if (pattern[i] == 'p') {
			ST(13);
		}
		if (pattern[i] == 'y') {
			ST(14);
		}
		if (pattern[i] == 'w') {
			ST(15);
		}
		std::cout << pattern[i] << " ";
	}
}

void guessinput(char guess[]) {
	for (int i = 0; i < 4; i++) {
		std::cout << "wprowadz swoje typy: ";
		std::cin >> guess[i];
		std::cout << std::endl;
	}
}

int isinfor(char guessone, char pattern[4]) {
	for (int i = 0; i < 4; i++) {
		if (guessone == pattern[i]) {
			return i;
		}
		else {
			return 0;
		}
	}
}

void Search(char guess[4], char pattern[4]) {
	for (int i = 0; i < 4; i++) {
		char guessone = guess[i];
		if (isinfor(guessone, pattern) != 0) {
			if (guess[guessone] == pattern[guessone]) {
				ST(16 + 16);
				cout << "-" << " ";
			}
			else {
				ST(15 + 16);
				cout << "-" << " ";
			}
		}
	}
}

int main() {
	random_device rd;
	mt19937 gen(rd());

	vector <char> all = {
		'g',
		'b',
		'r',
		'p',
		'y',
		'w'
	};

	shuffle(begin(all), end(all), gen);
	char pattern[4];
	patternset(pattern, all);

	char guess[4];
	std::cout << std::endl;
	guessinput(guess);
	showpattern(pattern);

	for (int i = 0; i < 8; i++) {
		Search(guess, pattern);
		cout << endl;
		guessinput(guess);
	}

}
