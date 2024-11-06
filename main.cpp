#include <iostream>
#include <Windows.h>
#include <random>

void ST(int kolor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, kolor);
}

void genpattern(int pattern[4]) {
	for (int i = 0; i < 4; i++) {
		pattern[i] = rand() % 5 +10;
	}
}

void changetochar(int pattern[4], int cpattern[4]) {
	for (int i = 0; i < 4; i++) {
		if (pattern[i]==10) {
			cpattern[i] = 'g';
		}
		if (pattern[i] == 11) {
			cpattern[i] = 'c';
		}
		if (pattern[i] == 12) {
			cpattern[i] = 'r';
		}
		if (pattern[i] == 13) {
			cpattern[i] = 'p';
		}
		if (pattern[i] == 14) {
			cpattern[i] = 'y';
		}
		if (pattern[i] == 15){
			cpattern[i] = 'w';
		}
	}
}

void showpattern(int pattern[4]) {
	for (int i = 0; i < 4; i++) {
		ST(pattern[i]);
		std::cout << pattern[i] << " ";
	}
}

void guessinput(char guess[]) {
	for (int i = 0; i < 4; i ++) {
		std::cout << "wprowadz swoje typy: ";
		std::cin >> guess[i];
		std::cout << std::endl;
	}
}
void showguess(char guess[4]) {
	for (int i = 0; i < 4; i++) {
		ST(guess[i]);
		std::cout << guess[i] << " ";
	}
}


int main() {
	// v2 = rand() % 100 + 1;  v2 in the range 1 to 100
	int pattern[4];
	char cpattern[4];
	char guess[4];
	genpattern(pattern);
	showpattern(pattern);
	std::cout << std::endl;

	guessinput(guess);
	showguess(guess);
}
