#pragma once

namespace TicTacToe
{
	class Board;
	class Player
	{
	public:
		/**
		* Default constructor of Player class.
		*/
		Player() = default;

		/**
		* Default destructor for Player class.
		*/
		~Player() = default;

		/**
		* Mutator for the member variable mWeapon, which holds whether the player is using a nought or a cross.
		* @param character Is a char value, a nought or a cross.
		*/
		void SetPlayerWeapon(char character);

		/**
		* Update method updates the characters on the board every round.
		*/
		void Update(Board& board);

	private:
		char mWeapon;
		std::uint32_t mIdentity;
	};
}