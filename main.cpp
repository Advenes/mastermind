
#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
#include <conio.h>

using namespace std;


void roulettetransform(string &guess, int roulette, int i) {
	switch (roulette) {
	case -3: guess[i] = 'g'; break;
		case -2: guess[i] = 'b'; break;
		case -1: guess[i] = 'r'; break;
		case 0: guess[i] = 'p'; break;
		case 1: guess[i] = 'y'; break;
		case 2: guess[i] = 'w'; break;

	}
}

int main() {
	int roulette = 0;
	string guess = "aaaa";
	int i = 0;
	while (i<4) {
		char key = _getch();
		if (key == 'a') {
			roulette --;
			cout << roulette;
		}
		if (key == 'd') {
			roulette++;
			cout << roulette;
		}
		if (key == 'w' && roulette >= -3 && roulette <= 2) {
			roulettetransform(guess, roulette, i);
			cout << guess[i];
			i++;
			

		}
	}

}

void ST(int kolor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, kolor);
}

void patternSet(char pattern[4], vector<char> all) {
	for (int i = 0; i < 4; i++) {
		pattern[i] = all[i];
	}
}

void showPattern(char pattern[4]) {
	for (int i = 0; i < 4; i++) {
		switch (i){
		case 'g': ST(10);
		case 'b': ST(11);
		case 'r': ST(12);
		case 'p': ST(13);
		case 'y': ST(14);
		case 'w': ST(15);
		}
		std::cout << pattern[i] << " ";
	}
}

string guessInput(string &guess) {
	cin >> guess;
	if (guess.length() != 4) {
		return "0";
	}
	else {
		return guess;
	}
}

int isInFor(char guessone, char pattern[4]) {
	for (int i = 0; i < 4; i++) {
		if (guessone == pattern[i]) {
			return i;
		}
	}
	return -1;
}

void Search(string guess, char pattern[4], int& win) {
	for (int i = 0; i < 4; i++) {
		char guessone = guess[i];
		if (isInFor(guessone, pattern) != -1) {
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
	cout << "Kolor bialy oznacza trafienie w dobrym miejscu np: wpisujemy r a kolorem jest czerwony" << endl;
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
	patternSet(pattern, all);

	string guess;
	//showpattern(pattern);
	std::cout << std::endl;
	int win = 0;
	for (int i = 0; i < 8 && win < 4; i++) {
		win = 0;
		for (int j = 0; j < 1; j++) {
			if (guessInput(guess) == "0") {
				j--;
			}
		}
		Search(guess, pattern, win);
		cout << endl;
	}
	if (win == 4) {
		cout << "Wygrales!" << endl;
		showPattern(pattern);
	}
	else {
		cout << "Przegrales!" << endl;
		showPattern(pattern);
	}
}
