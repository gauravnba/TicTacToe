#include "pch.h"

#include "Player.h"
#include "Board.h"
#include "MainGame.h"

using namespace std;

namespace TicTacToe
{
	Player::Player(char piece) :
		mIsHuman(true)
	{
		mPiece = piece;
	}

	void Player::SetHumanity(bool isHuman)
	{
		mIsHuman = isHuman;
	}

	void Player::Update(Board& board, GameState& gameState)
	{
		if (mIsHuman)
		{
			cout << "Enter a position from 0 to 8\n" <<
				"Position Chart:\n" <<
				"0   1   2\n" <<
				"3   4   5\n" <<
				"6   7   8" << endl;
			char input = 9;
			while (input > 8)
			{
				cout << "\nPlayer " << mPiece << ": ";
				cin >> input;

				if (input == 'q')
				{
					gameState = GameState::Quit;
					return;
				}

				// Convert the char type input to integer value.
				input = input - '0';

				bool isPlacementSuccessful = true;
				board.PlacePiece(static_cast<uint32_t>(input), mPiece, isPlacementSuccessful);

				if (!isPlacementSuccessful)
				{
					input = 9;
					cout << "Please enter a valid position.";
				}
			}
		}

		else
		{
			uint32_t moveTo = 0;
			int32_t bestValue = -100;

			for (uint32_t i = 0; i < board.MAX_POSITIONS_ON_BOARD; ++i)
			{
				bool isPlacementSuccessful = true;
				board.PlacePiece(i, mPiece, isPlacementSuccessful);
				if (isPlacementSuccessful)
				{
					int32_t moveValue = max(bestValue, minimax(board, 0, false));
					board.RemovePiece(i);

					if (moveValue > bestValue)
					{
						moveTo = i;
					}
				}
			}

			bool dummy = true;
			board.PlacePiece(moveTo, mPiece, dummy);
		}
	}

	char Player::Piece()
	{
		return mPiece;
	}

	int32_t Player::minimax(Board& board, int depth, bool isMaximizer)
	{
		char otherPiece;
		if (mPiece == 'x')
		{
			otherPiece = 'o';
		}
		else
		{
			otherPiece = 'x';
		}

		int32_t result = board.CalculateWinningState(mPiece);
		if ((result == -2) || (result == 1) || (result == 2)) return result;

		if (isMaximizer)
		{
			int32_t best = -100;

			for (uint32_t i = 0; i < board.MAX_POSITIONS_ON_BOARD; ++i)
			{
				bool isPlacementSuccessful = true;
				board.PlacePiece(i, mPiece, isPlacementSuccessful);
				if (isPlacementSuccessful)
				{
					best = max(best, minimax(board, depth + 1, !isMaximizer));
					board.RemovePiece(i);
				}
			}
			return best;
		}

		else 
		{
			int32_t best = 100;
			for (uint32_t i = 0; i < board.MAX_POSITIONS_ON_BOARD; ++i)
			{
				bool isPlacementSuccessful = true;
				board.PlacePiece(i, otherPiece, isPlacementSuccessful);
				if (isPlacementSuccessful)
				{
					best = max(best, minimax(board, depth + 1, !isMaximizer));
					board.RemovePiece(i);
				}
			}
			return best;
		}
	}
}
