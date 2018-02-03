#pragma once

namespace TicTacToe
{
	// forward declarations
	enum class GameState : char;

	/**
	* The board that the game is uses to keep track of moves.
	*/
	class Board
	{
	public:
		/**
		* Constructor for the Board. To initialize the board.
		*/
		Board();

		/**
		* Default destructor for the Board.
		*/
		~Board() = default;

		/**
		* Draw the updated board to console.
		*/
		void Draw();

		/**
		* Used by the Player Update method to place the player's piece on the board.
		* @param position position at which to place the piece.
		* @param character the character that the piece is represented as.
		* @param isPlaceSuccessful bool output parameter, to noptify if the placement was succesful.
		*/
		void PlacePiece(std::uint32_t position, char character, bool& isPlacementSuccessful);

		/**
		* Update method of Board, checks for wins by a player.
		* @param gameState the current state of the game.
		*/
		void Update(GameState& gameState, char playerPiece);

	private:
		/**
		* 
		*/
		bool didPlayerWin(char playerPiece);

		/**
		* 
		*/
		bool checkLineForWin(char playerPiece, std::uint32_t position1, std::uint32_t position2, std::uint32_t position3);

		std::vector<std::uint8_t> mBoard;					/**< List of positions on the board. */
		std::uint32_t mMovesPlayed;							/**< Number of moves played on the board, so far. */

		static const std::uint32_t MAX_POSITIONS_ON_BOARD;	/**< const value. Maximum number of moves available on the board. */
	};
}