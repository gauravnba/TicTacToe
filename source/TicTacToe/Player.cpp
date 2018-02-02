#include "pch.h"
#include "Player.h"
#include "Board.h"

using namespace std;

namespace TicTacToe
{
	void Player::SetPlayerWeapon(char character)
	{
		mWeapon = character;
	}

	void Player::Update(Board & board)
	{
		uint32_t input = 9;
		while (input >= 8)
		{
			cin >> input;
			bool isPlacementSuccessful = true;
			board.Update(input, mWeapon, isPlacementSuccessful);
			if (!isPlacementSuccessful)
			{
				input = 9;
				cout << "Please enter a valid position. This space is already taken.";
			}
		}
	}
}
