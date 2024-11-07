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
	}
	return -1;
}

void Search(char guess[4], char pattern[4], int &win) {
	for (int i = 0; i < 4; i++) {
		char guessone = guess[i];
		if (isinfor(guessone, pattern) != -1) {
			if (guess[i] == pattern[i]) {
				ST(15);
				cout << "-" << " ";
				win = win + 1;
			}
			else {
				ST(9);
				cout << "-" << " ";
			}
		}
		else {
			ST(8);
			cout << "-" << " ";
		}
		ST(7);
	}
}

int main() {

	cout << "Losujemy 4 kolory z puli 6: g = zielony, b = niebieski, r = czerwony, p = rozowy, y = zolty, w = bialy" << endl;
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
	//showpattern(pattern);
	std::cout << std::endl;
	int win = 0;
	for (int i = 0; i < 8 && win < 4; i++) {
		win = 0;
		guessinput(guess);
		Search(guess, pattern, win);
		cout << endl;
	}
	if (win == 4) {
		cout << "Wygrales!" << endl;
		showpattern(pattern);
	}
	else {
		cout << "Przegrales!" << endl;
		showpattern(pattern);
	}


}
