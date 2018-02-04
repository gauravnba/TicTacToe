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
		Player() = delete;

		/**
		* Player constructor. Needs which piece to use.
		* @param piece Is a char value, a nought or a cross.
		*/
		Player(char piece);

		/**
		* Default destructor for Player class.
		*/
		~Player() = default;

		/**
		* Mutator for the member variable mIsWeapon, which holds whether the player is a human or AI.
		* @param isHuman new value to be assigned to isHuman.
		*/
		void SetHumanity(bool isHuman);

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
		void recurseIntoMinimax();

		std::int32_t minimax(Board& board, int depth, bool isMaximizingPlayer);

		char mPiece;		/**< The piece used to play by this player. */
		bool mIsHuman;		/**< Whether this player is a human player. */
	};
}