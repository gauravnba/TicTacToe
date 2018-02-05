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

		mOtherPiece = (mPiece == 'x') ? 'o' : 'x';
	}

	Player::AIMove::AIMove(int32_t score) :
		mScore(score)
	{
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

				if (!board.PlacePiece(static_cast<uint32_t>(input), mPiece))
				{
					input = 9;
					cout << "Please enter a valid position.";
				}
			}
		}

		else
		{
			AIMove bestMove = calculateBestMove(board, mPiece, true);
			board.PlacePiece(bestMove.mMove, mPiece);
		}
	}

	char Player::Piece()
	{
		return mPiece;
	}

	Player::AIMove Player::calculateBestMove(Board& board, char piece, bool isThisPlayer)
	{
		// Check if the piece is in winning state, losing state or a draw.
		int32_t boardState = board.WinningStateOfPiece(mPiece);
		if (boardState != -1)
		{
			AIMove move = boardState;
			return move;
		}

		vector<AIMove> possibleMoves;

		// Populate vector for possible moves, recursively.
		for (uint32_t i = 0; i < board.MAX_POSITIONS_ON_BOARD; ++i)
		{
			if (board.PlacePiece(i, piece))
			{
				AIMove move;
				move.mMove = i;
				if (isThisPlayer)
				{
					move.mScore = calculateBestMove(board, mOtherPiece, !isThisPlayer).mScore;
				}
				else
				{
					move.mScore = calculateBestMove(board, mPiece, !isThisPlayer).mScore;
				}
				possibleMoves.push_back(move);
				board.RemovePiece(i);
			}
		}

		uint32_t bestMove = 0;
		if (isThisPlayer)
		{
			int32_t bestScore = -1000;
			for (uint32_t i = 0; i < possibleMoves.size(); ++i)
			{
				if (possibleMoves[i].mScore > bestScore)
				{
					bestMove = i;
					bestScore = possibleMoves[i].mScore;
				}
			}
		}
		else
		{
			int32_t bestScore = 1000;
			for (uint32_t i = 0; i < possibleMoves.size(); ++i)
			{
				if (possibleMoves[i].mScore < bestScore)
				{
					bestMove = i;
					bestScore = possibleMoves[i].mScore;
				}
			}
		}

		return possibleMoves[bestMove];
	}
}