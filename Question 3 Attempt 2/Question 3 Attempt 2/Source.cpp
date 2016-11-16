#include<iostream>

using namespace std;

int main()
{
	const int NUM_ROWS = 3;
	const int NUM_COLUMNS = 3;
	int u_row, u_column;

	char tictactoe_game[NUM_ROWS][NUM_COLUMNS];
	char playerCharacter = 'O';

	int winCount = 0;
	bool winCheck = false;

	//end of declarations

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			tictactoe_game[row][column] = '?';
		}
	}

	cout << "Welcome to Tic Tac Toe, Player X starts the game..." << endl;

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			cout << tictactoe_game[row][column];
			if (column == 2)
			{
				cout << endl;
			}
		}
	}

	/*tictactoe_game[0][0] = 'X';
	tictactoe_game[1][1] = 'X';
	tictactoe_game[2][2] = 'X';*/

	//Start of gameloop

	for (int turnCount = 0; turnCount < 9;turnCount++)
	{
		if (playerCharacter == 'X')
		{
			playerCharacter = 'O';
		}
		else
		{
			playerCharacter = 'X';
		}
		//gets location user wants to place character in.
		cout << "Enter the row for " << playerCharacter << ". (0 to 2)" << endl;
		cin >> u_row;
		cout << endl << "Enter the column. (0 to 2)" << endl;
		cin >> u_column;
		cout << endl;
		system("cls");
		//sets chosen location to player character.

		tictactoe_game[u_row][u_column] = playerCharacter;

		//prints game grid
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


		//detects for horizontal win.

		for (int row = 0; row < NUM_ROWS; row++)
		{
			winCount = 0;
			for (int column = 0; column < NUM_COLUMNS; column++)
			{
				if (tictactoe_game[row][column] == playerCharacter)
				{
					// the character at this location
					// in the grid matches our players
					// character
					// add one to our win counter

					winCount++;
				}
			}

			if (winCount == NUM_COLUMNS)
			{
				winCheck = true;
				break;
			}
			else
			{
				winCheck = false;

			}
		}

		//detects for vertical win
		if (winCheck == false)
		{
			for (int column = 0; column < NUM_COLUMNS; column++)
			{
				winCount = 0;
				for (int row = 0; row < NUM_ROWS; row++)
				{
					if (tictactoe_game[row][column] == playerCharacter)
					{
						// the character at this location
						// in the grid matches our players
						// character
						// add one to our win counter

						winCount++;
					}
				}

				if (winCount == NUM_COLUMNS)
				{
					winCheck = true;
					break;
				}
				else
				{
					winCheck = false;

				}


			}

			//detects for diagonal win
			if (winCheck == false)
			{
				winCount = 0;

				if ((tictactoe_game[0][0] == playerCharacter) && (tictactoe_game[1][1] == playerCharacter) && (tictactoe_game[2][2] == playerCharacter))
				{
					winCheck = true;
				}
				else
				{
					winCheck = false;

				}

				if (winCheck == false)
				{
					winCount = 0;

					if ((tictactoe_game[0][2] == playerCharacter) && (tictactoe_game[1][1] == playerCharacter) && (tictactoe_game[2][0] == playerCharacter))
					{
						winCheck = true;
					}
					else
					{
						winCheck = false;

					}
				}
			}
		}
		if (winCheck == true)
		{
			break;
		}
	}
	//loop ends here when a win is detected or until a tie game.

	if (winCheck == true)
	{
		cout << playerCharacter << " win the game!" << endl;
	}
	else
	{
		cout << "No winner, tie game!" << endl;
	}

	return 0;
}