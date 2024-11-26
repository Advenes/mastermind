#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
#include <conio.h>

using namespace std;

int isInFor(char guessone, char pattern[4]) {
	for (int i = 0; i < 4; i++) {
		if (guessone == pattern[i]) {
			return i;
		}
	}
	return -1;
}

void ST(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void returnGuess(int guessC[4], int i) {
	for (int j = 0; j <= i; j++) {
		ST(guessC[j] + 15 + (guessC[j] * 15));
		cout << "   ";
	}
}

void rouletteTransform(string& guess, short roulette, int i, int guessC[4], int line) {
	COORD c;
	c.X = 0;
	c.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	switch (roulette) {
	case 10: guess += 'g'; guessC[i] = 10; break;
	case 11: guess += 'b'; guessC[i] = 11; break;
	case 12: guess += 'r'; guessC[i] = 12; break;
	case 13: guess += 'p'; guessC[i] = 13; break;
	case 14: guess += 'y'; guessC[i] = 14; break;
	case 15: guess += 'w'; guessC[i] = 15; break;
	}
}

void render(short roulette, string& guess) {
	COORD c;
	c.X = 2;
	c.Y = 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	if (roulette == 10) {
		ST(15 + (15 * 15));
		cout << "   ";
		ST(10 + (15 * 10));
		cout << "   ";
		ST(11 + (15 * 11));
		cout << "   ";
	}
	else if (roulette == 15) {
		ST(14 + (15 * 14));
		cout << "   ";
		ST(15 + (15 * 15));
		cout << "   ";
		ST(10 + (15 * 10));
		cout << "   ";
	}
	else {
		ST(roulette - 1 + (15 * (roulette - 1)));
		cout << "   ";
		ST(roulette + (15 * roulette));
		cout << "   ";
		ST(roulette + 1 + (15 * (roulette + 1)));
		cout << "   ";
	}
	ST(7);
	c.X = guess.length() + 2;
	c.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void patternSet(char pattern[4]) {
	 char all[6] = {
	'g',
	'b',
	'r',
	'p',
	'y',
	'w'
	};
	for (int i = 0; i < 4; i++) {
		pattern[i] = all[rand() % 6];
	}
}

bool search(string guess, char pattern[4], int& win) {
	for (int i = 0; i < 4; i++) {
		char guessone = guess[i];
		if (isInFor(guessone, pattern) != -1) {
			if (guess[i] == pattern[i]) {
				ST(15 + (15 * 15));
				cout << "   ";
				win = win + 1;
			}
			else {
				ST(9 + (9 * 15));
				cout << "   ";
			}
		}
		else {
			ST(8 + (8 * 15));
			cout << "   ";
		}
		ST(7);
	}
	if (win == 4) {
		return true;
	}
	else {
		return false;
	}
}

void clearG(int guessC[4]) {
	for (int i = 0; i < 4; i++) {
		guessC[i] = 0;
	}
}

int main() {
	// INSTRUKCJA OBSLUGI

	cout << "-MASTERMIND-" << endl;
	cout << "Posiadasz 8 prob. Potrzebujesz odgadnac dobrze 4 z 6 kolorow, ktore wybierasz z selektora ponizej:" << endl;
	cout << "Po karuzeli mozemy poruszac sie klawiszami A oraz D, wybrac kolor mozemy przy uzyciu W." << endl;
	cout << "Kolor niebieski oznacza dobry kolor, lecz w zlym miejscu, natomiast bialy oznacza dobry kolor we wlasciwym miejscu." << endl;
	cout << "=============" << endl;
	cout << "|" << "           " << "|" << endl;
	cout << "=============" << endl;

	srand(static_cast<unsigned int>(time(0)));

	char pattern[4];
	patternSet(pattern);

	int line = 7;
	short roulette = 13;
	string guess;
	int guessC[4];
	short i = 0;
	render(roulette, guess);

	int win = 0;
	int gameloop = 0;

	while (win != 4 && gameloop != 8) {
		while (i < 4) {
			char key = _getch();
			if (key == 'a') {
				if (roulette > 10) {
					roulette--;
				}
				else {
					roulette = 15;
				}
				render(roulette, guess);
			}
			if (key == 'd') {
				if (roulette < 15) {
					roulette++;
				}
				else {
					roulette = 10;
				}
				render(roulette, guess);
			}
			if (key == 'w') {
				rouletteTransform(guess, roulette, i, guessC, line);
				returnGuess(guessC, i);
				i++;
				ST(7);
			}
		}
		win = 0;
		cout << endl;
		if (search(guess, pattern, win)) {
			cout << endl;
			cout << "wygrales!!!";
			ST(7);
			return 0;
		}
		else {
			cout << endl;
			cout << "=============" << endl;
			line += 3;
			gameloop++;
			guess = "";
			clearG(guessC);
			i = 0;
		}

	}

}
