#include "grid.h"
#include<iostream>

using namespace std;

int main()
{
	grid grd;
	
	int winCount = 0, response;
	bool winCheck = false, AI = false;

	//end of declarations

	cout << "2 player (1) or AI (0)?" << endl;
	cin >> response;
	if (response == 0)
	{
		AI = true;
	}
	else
	{
		AI = false;
	}

	cout << "Welcome to Tic Tac Toe, Player X starts the game..." << endl;

	grd.printGrid();

	//Start of gameloop

	for (int turnCount = 0; turnCount < 9; turnCount++)
	{
		grd.userTurn(turnCount, AI);
		grd.printGrid();

		//detects for horizontal win.
		for (int row = 0; row < 3; row++)
		{
			if (grd.horCheck(row, grd.playerCharacter) == 3)
			{
				winCheck = true;
			}
		}

		//detects for vertical win
		if (winCheck == false)
		{
			for (int column = 0; column < 3; column++)
			{
				if (grd.verCheck(column, grd.playerCharacter) == 3)
				{
					winCheck = true;
				}
			}

			//detects for diagonal win
			if (winCheck == false)
			{
				if (grd.diaCheck(0, grd.playerCharacter) == 3)
				{
					winCheck = true;
				}
				else if (grd.diaCheck(1, grd.playerCharacter) == 3)
				{
					winCheck = true;
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
		cout << grd.playerCharacter << " win the game!" << endl;
	}
	else
	{
		cout << "No winner, tie game!" << endl;
	}

	return 0;
}