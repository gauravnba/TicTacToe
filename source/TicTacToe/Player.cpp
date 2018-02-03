#include "pch.h"

#include "Player.h"
#include "Board.h"
#include "MainGame.h"

using namespace std;

namespace TicTacToe
{
	void Player::SetPlayerWeapon(char character)
	{
		mPiece = character;
	}

	void Player::Update(Board& board, GameState& gameState)
	{
		char input = 9;
		while (input > 8)
		{
			cout << "Enter a position from 0 to 8\n" <<
				"Position Chart:\n" <<
				"0   1   2\n" <<
				"3   4   5\n" <<
				"6   7   8\n" << 
				"\nPlayer " << mPiece << ": ";
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

	char Player::Piece()
	{
		return mPiece;
	}
}
