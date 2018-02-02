#include "pch.h"

#include "Board.h"

using namespace std;

namespace TicTacToe
{
	Board::Board()
	{
		mBoard.reserve(9);
		mBoard = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	}

	void Board::Draw()
	{
		system("cls");
		cout << ' ' << mBoard[0] << " | " << mBoard[1] << " | " << mBoard[2] << "\n" <<
			"-----------\n" <<
			' ' << mBoard[3] << " | " << mBoard[4] << " | " << mBoard[5] << "\n" <<
			"-----------\n" <<
			' ' << mBoard[6] << " | " << mBoard[7] << " | " << mBoard[8] << endl;

		cout << "\nEnter a position from 0 to 8\n" <<
			"Position Chart:\n" <<
			"0   1   2\n" <<
			"3   4   5\n" <<
			"6   7   8\n";
	}
	void Board::Update(uint32_t position, char character, bool& isPlacementSuccessful)
	{
		if (mBoard[position] == ' ')
		{
			mBoard[position] = character;
		}
		else
		{
			isPlacementSuccessful = false;
		}
	}
}