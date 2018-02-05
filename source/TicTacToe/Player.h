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
		// Delete the default constructor for Player.
		Player() = delete;

		// Use the Default copy and move constructors.
		Player(const Player&) = default;
		Player(Player&&) = default;
		Player& operator=(const Player&) = default;
		Player& operator=(Player&&) = default;

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
		/**
		* The struct used to hold each move step for calculating the best move.
		*/
		struct AIMove 
		{
			/**
			* Default constructor for AIMove.
			*/
			AIMove() = default;

			/**
			* Constructor for AIMove taht accepts a score parameter.
			* @param score Score parameter for this move.
			*/
			AIMove(std::int32_t score);

			std::int32_t mScore;		/**< Stores the score associated to the move. */
			std::uint32_t mMove;		/**< The position to move to in this move. */
		};

		/**
		* Calculates the optimum next move for the non-human player, using the minimax algorithm.
		* @param board A reference to the board being used by the game.
		* @param piece The piece to calculate the best move for.
		* @param isThisPlayer boolean value that denotes whether the current move is for this Player.
		* @return A copy of the optimum AIMove.
		*/
		AIMove calculateBestMove(Board& board, char piece, bool isThisPlayer);

		char mPiece;		/**< The piece used to play by this player. */
		char mOtherPiece;	/**< The piece used to play by the other player. */
		bool mIsHuman;		/**< Whether this player is a human player. */
	};
}