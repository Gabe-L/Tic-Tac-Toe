#include "grid.h"
#include <iostream>

using namespace std;

grid::grid()
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			tictactoe_game[row][column] = '?';
		}
	}
}


grid::~grid()
{
}

int grid::horCheck(int row, char chr)
{
	int gap = 0;
	bool match = false;
	for (int column = 0; column < 3; column++)
	{
		if (tictactoe_game[row][column] == chr)
		{
			gap++;
			match = true;
		}
	}
	if (match = false)
	{
		gap = -1;
	}
	return gap;
}

int grid::verCheck(int col, char chr)
{
	int gap = 0;
	bool match = false;
	for (int row = 0; row < 3; row++)
	{
		if (tictactoe_game[row][col] == chr)
		{
			gap++;
			match = true;
		}
	}
	if (match = false)
	{
		gap = -1;
	}
	return gap;
}

int grid::diaCheck(int direction, char chr)
{
	int gap = 0;
	bool match = false;
	if (direction == 0)
	{
		for (int counter = 0; counter < 3; counter++)
		{
			if (tictactoe_game[counter][counter] == chr)
			{
				gap++;
				match = true;
			}
		}
	}
	else
	{
		for (int counter = 0; counter < 3; counter++)
		{
			if (tictactoe_game[counter][2 - counter] == playerCharacter)
			{
				gap++;
				match = true;
			}
		}
	}
	if (match = false)
	{
		gap = -1;
	}
	return gap;
}

void grid::printGrid()
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			cout << tictactoe_game[row][column] << " ";
			if (column == 2)
			{
				cout << endl;
			}
		}
	}
}

void grid::userTurn(int turnCount, bool AI)
{
	int u_row, u_column, hor, ver, dia;
	bool turnTaken = false;
	double turn = 0;
	if (playerCharacter == 'X')
	{
		playerCharacter = 'O';
	}
	else
	{
		playerCharacter = 'X';
	}
	cout << (turnCount % 2) << endl;
	if (((turnCount % 2) > 0) && AI == true)
	{
		//AI Player
		int x = 0, y = 0;
		//check for horizontal win possibility
		for (int row = 0; row < 3; row++)
		{
			hor = horCheck(row, playerCharacter);
			if (hor > -1 && hor < 3)
			{
				if (tictactoe_game[row][hor] == '?' && turnTaken == false)
				{
					tictactoe_game[row][hor] = playerCharacter;
					turnTaken = true;
				}
			}
		}
		if (turnTaken == false)
		{
			//check for vertical win possibility
			for (int col = 0; col < 3; col++)
			{
				ver = verCheck(col, playerCharacter);
				if (hor > -1 && hor < 3)
				{
					if (tictactoe_game[ver][col] == '?' && turnTaken == false)
					{
						tictactoe_game[ver][col] = playerCharacter;
						turnTaken = true;
					}
				}
			}
			if (turnTaken == false)
			{
				//check for diagonal win possibility
				dia = diaCheck(0, playerCharacter);
				if (dia > -1 && dia < 3)
				{
					if (tictactoe_game[dia][dia] == '?' && turnTaken == false)
					{
						tictactoe_game[dia][dia] = playerCharacter;
						turnTaken = true;
					}
				}
				if (turnTaken == false)
				{
					dia = diaCheck(1, playerCharacter);
					if (dia > -1 && dia < 3)
					{
						if (tictactoe_game[dia][2-dia] == '?' && turnTaken == false)
						{
							tictactoe_game[dia][2-dia] = playerCharacter;
							turnTaken = true;
						}
					}
				}
			}
		}
	}
	else if (AI == false || ((((turnCount / 2) * 10) % 10) == 0))
	{
		//Non AI Player
		//gets location user wants to place character in.
		cout << "Enter the row for " << playerCharacter << ". (0 to 2)" << endl;
		cin >> u_row;
		cout << endl << "Enter the column. (0 to 2)" << endl;
		cin >> u_column;
		cout << endl;
		system("cls");
		//sets chosen location to player character.
		tictactoe_game[u_row][u_column] = playerCharacter;
	}
}
