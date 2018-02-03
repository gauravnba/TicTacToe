#pragma once

namespace TicTacToe
{
	// forward declarations
	enum class GameState : char;
	class Board;

	/**
	* Player class handles the input by the players.
	*/
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
		* @param board non const reference to the board of the game.
		* @gameState a non const reference to the game state of the MainGame.
		*/
		void Update(Board& board, GameState& gameState);

		/**
		* Accessor method for the piece of this player.
		*/
		char Piece();
	private:
		char mPiece;		/**<  */
	};
}