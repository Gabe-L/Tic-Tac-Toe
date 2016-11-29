#pragma once

class grid
{
public:
	grid();
	~grid();

	char tictactoe_game[3][3];

	char playerCharacter = 'O';

	int horCheck(int row, char chr);
	int verCheck(int col, char chr);
	int diaCheck(int direction, char chr);
	void printGrid();
	void userTurn(int turnCount, bool AI);
};

