#include <iostream>
using namespace std;

char matrix[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char ch = 'X';

void draw() {
	cout << " " << matrix[0] << " | " << matrix[1] << " | " << matrix[2] << endl;
	cout << "------------\n";
	cout << " " << matrix[3] << " | " << matrix[4] << " | " << matrix[5] << endl;
	cout << "------------\n";
	cout << " " << matrix[6] << " | " << matrix[7] << " | " << matrix[8] << endl;
}

void input() {
	int a;
	cout << "Enter number of slot: ";
	cin >> a;
	if (a > 0 && a < 10) {
		if ((matrix[a - 1] != 'X') && (matrix[a - 1] != 'O')) {
			if (a == 1)
				matrix[0] = ch;
			else if (a == 2)
				matrix[1] = ch;
			else if (a == 3)
				matrix[2] = ch;
			else if (a == 4)
				matrix[3] = ch;
			else if (a == 5)
				matrix[4] = ch;
			else if (a == 6)
				matrix[5] = ch;
			else if (a == 7)
				matrix[6] = ch;
			else if (a == 8)
				matrix[7] = ch;
			else if (a == 9)
				matrix[8] = ch;

			if (ch == 'X')
				ch = 'O';
			else if (ch == 'O')
				ch = 'X';
			else
				system("exit");
		}
		else {
			input();
		}
	}
	else {
		input();
	}
}

char win() {
	// first player

	if ((matrix[0] == 'X') && (matrix[1] == 'X') && (matrix[2] == 'X'))
		return 'X';
	if ((matrix[3] == 'X') && (matrix[4] == 'X') && (matrix[5] == 'X'))
		return 'X';
	if ((matrix[6] == 'X') && (matrix[7] == 'X') && (matrix[8] == 'X'))
		return 'X';
	if ((matrix[0] == 'X') && (matrix[3] == 'X') && (matrix[6] == 'X'))
		return 'X';
	if ((matrix[1] == 'X') && (matrix[4] == 'X') && (matrix[7] == 'X'))
		return 'X';
	if ((matrix[2] == 'X') && (matrix[5] == 'X') && (matrix[8] == 'X'))
		return 'X';
	if ((matrix[0] == 'X') && (matrix[4] == 'X') && (matrix[8] == 'X'))
		return 'X';
	if ((matrix[2] == 'X') && (matrix[4] == 'X') && (matrix[6] == 'X'))
		return 'X';

	//second player

	if ((matrix[0] == 'O') && (matrix[1] == 'O') && (matrix[2] == 'O'))
		return 'O';
	if ((matrix[3] == 'O') && (matrix[4] == 'O') && (matrix[5] == 'O'))
		return 'O';
	if ((matrix[6] == 'O') && (matrix[7] == 'O') && (matrix[8] == 'O'))
		return 'O';
	if ((matrix[0] == 'O') && (matrix[3] == 'O') && (matrix[6] == 'O'))
		return 'O';
	if ((matrix[1] == 'O') && (matrix[4] == 'O') && (matrix[7] == 'O'))
		return 'O';
	if ((matrix[2] == 'O') && (matrix[5] == 'O') && (matrix[8] == 'O'))
		return 'O';
	if ((matrix[0] == 'O') && (matrix[4] == 'O') && (matrix[8] == 'O'))
		return 'O';
	if ((matrix[2] == 'O') && (matrix[4] == 'O') && (matrix[6] == 'O'))
		return 'O';
}

bool isdraw() {
	int counter = 0;
	for (char i : matrix) {
		if ((i == 'X') || (i == 'O')) {
			counter++;
		}
		else {
			return false;
		}
	}
	if (counter == 9) {
		return true;
	}
}


int main() {
	while (true) {
		system("cls");
		draw();
		input();
		if (win() == 'X') {
			system("cls");
			draw();
			cout << "X wins!\n";
			ch = 'X';
			break;
		}
		else if (win() == 'O') {
			system("cls");
			draw();
			cout << "O wins!\n";
			ch = 'O';
			break;
		}

		if (isdraw() == true) {
			system("cls");
			draw();
			cout << "Draw!\n";
			break;
		}
	}
	char p;
	cout << "Play again(y/n): ";
	cin >> p;
	if (p == 'y') {
		for (int i = 0; i < 9; i++) {
			char b = i + 49;
			matrix[i] = b;
		}
		main();
	}
	else if (p == 'n') {
		system("exit");
	}
	else {
		cout << "Ivalid character!";
	}
}