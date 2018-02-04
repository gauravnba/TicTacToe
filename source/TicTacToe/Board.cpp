#include "pch.h"

#include "Board.h"
#include "MainGame.h"

using namespace std;

namespace TicTacToe
{
	const uint32_t Board::MAX_POSITIONS_ON_BOARD = 9;
	const map<int32_t, GameState> Board::MATCHSTATE_TO_GAMESTATE_MAP = {{-10, GameState::PlayerXWins},
																		{1, GameState::Draw},
																		{10, GameState::PlayerOWins} };

	Board::Board() :
		mMovesPlayed(0)
	{
		mBoard.reserve(MAX_POSITIONS_ON_BOARD);
		mBoard = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	}

	void Board::Draw()
	{
		system("cls");
		cout << ' ' << mBoard[0] << " | " << mBoard[1] << " | " << mBoard[2] << "\n" <<
			"-----------\n" <<
			' ' << mBoard[3] << " | " << mBoard[4] << " | " << mBoard[5] << "\n" <<
			"-----------\n" <<
			' ' << mBoard[6] << " | " << mBoard[7] << " | " << mBoard[8] << "\n\n" <<endl;
	}

	void Board::PlacePiece(uint32_t position, char character, bool& isPlacementSuccessful)
	{
		if (position <= 8 && mBoard[position] == ' ')
		{
			mBoard[position] = character;
			++mMovesPlayed;
		}
		else
		{
			isPlacementSuccessful = false;
		}
	}

	void Board::Update(GameState& gameState, char playerPiece)
	{
		int32_t result = CalculateWinningState(playerPiece);
		if (result != 0)
		{
			gameState = MATCHSTATE_TO_GAMESTATE_MAP.at(result);
		}
	}

	int32_t Board::CalculateWinningState(char piece)
	{
		if (didPlayerWin(piece))
		{
			if (piece == 'x')
			{
				return -10;
			}
			else if (piece == 'o')
			{
				return 10;
			}
		}
		else if (mMovesPlayed >= MAX_POSITIONS_ON_BOARD)
		{
			return 1;
		}

		return 0;
	}

	void Board::RemovePiece(std::uint32_t position)
	{
		mBoard[position] = ' ';
		--mMovesPlayed;
	}

	bool Board::checkLineForWin(char playerPiece, uint32_t position1, uint32_t position2, uint32_t position3)
	{
		return ((mBoard[position1] == playerPiece) &&
				(mBoard[position2] == playerPiece) &&
				(mBoard[position3] == playerPiece)
				);
	}

	bool Board::didPlayerWin(char playerPiece)
	{
		return (
			// check for horizontal lines.
			(checkLineForWin(playerPiece, 0, 1, 2)) ||
			(checkLineForWin(playerPiece, 3, 4, 5)) ||
			(checkLineForWin(playerPiece, 6, 7, 8)) ||
			
			// check for vertical lines.
			(checkLineForWin(playerPiece, 0, 3, 6)) || 
			(checkLineForWin(playerPiece, 1, 4, 7)) ||
			(checkLineForWin(playerPiece, 2, 5, 8)) ||
			
			// check the diagonals
			(checkLineForWin(playerPiece, 0, 4, 8)) ||
			(checkLineForWin(playerPiece, 2, 4, 6)));
	}
}