#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// returns 0 if there's a win to stop animation-loop,
// returns 1 if there's no win to keep animation-loop
bool check_win();
void print_grid();
char check_move(int row, int col, char turn);

char grid[][3] = {
	{'0', '0', '0'},
	{'0', '0', '0'},
	{'0', '0', '0'},
};

int main() {
	int row, col, turnCounter = 0;
	char turn, win = '0';
	bool isOccupied = false, isInvalidMove = false;

	while (win == '0') {
		system("clear");
		// printf("%c\n", win);
		if (turnCounter > 8) break;
		print_grid();
		if (turnCounter % 2 == 0) turn = 'X';
		else turn = 'O';
		if (isOccupied) printf("(%d, %d) occupied\n", row, col);
		if (isInvalidMove) printf("(%d, %d) invalid move\n", row, col);
		printf("%c's turn%c\n\n", turn, isOccupied ? ' ' : '\n');
		printf("Row: ");
		scanf("%d", &row);
		printf("Col: ");
		scanf("%d", &col);
		if (row > 3 || row < 1 || col > 3 || col < 1) {
			isInvalidMove = true;
		} else if (grid[--row][--col] == '0') {
			win = check_move(row, col, turn);
			turnCounter++;
			isOccupied = false;
			isInvalidMove = false;
		} else {
			isOccupied = true;
		}
	}
	system("clear");
	print_grid();
	if (win != '0') {
		printf("%c Wins\n\n", win);
	} else {
		printf("Draw\n\n");
	}

	return 0;
}

char check_move(int row, int col, char turn) {
	bool win = true;
	grid[row][col] = turn;
	// Check col
	for (int i = 0; i < 3; i++) {
		if (grid[i][col] != turn) {
			win = false;
			break;
		}
	}
	if (win) return turn;
	
	// Check row
	win = true;
	for (int i = 0; i < 3; i++) {
		if (grid[row][i] != turn) {
			win = false;
			break;
		}
	}

	// Check diag
	if (row == col) {
		win = true;
		for (int i = 0; i < 3; i++) {
			if (grid[i][i] != turn) {
				win = false;
				break;
			}
		}
		if (win) return turn;
	}

	// Check anti-diag
	if ((row == 2 && col == 2) || (row == 1 && col == 3) || (row == 3 && col == 1)) {
		win = true;
		for (int i = 0, j = 2; i < 3; i++, j--) {
			if (grid[i][j] != turn) {
				win = false;
				break;
			}
		}
	}

	return win ? turn : '0';
}
bool check_win() {
	return 1;
}

void print_grid() {
	char player;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == 'X') {
				player = 'X';
			} else if (grid[i][j] == 'O'){
				player = 'O';
			} else {
				player = ' ';
			}
			printf(" %c ", player);
			if (j != 2) printf("|");
		}
		if (i != 2) printf("\n---+---+---\n");
	}
	printf("\n");
}
