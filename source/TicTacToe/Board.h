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
		static const std::uint32_t MAX_POSITIONS_ON_BOARD;	/**< const value. Maximum number of moves available on the board. */

		// Delete the board move constructor and copy constructor.
		Board(const Board&) = delete;
		Board(Board&&) = delete;

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
		* @return boolean True if placement was successful.
		*/
		bool PlacePiece(std::uint32_t position, char character);

		/**
		* Update method of Board, checks for wins by a player.
		* @param gameState the current state of the game.
		*/
		void Update(GameState& gameState);

		/**
		* Removes the piece at position, leaving the spot empty.
		* @param position the spot from where the piece is to be taken out from.
		*/
		void RemovePiece(std::uint32_t position);

		/**
		* Checks if the piece is winning or losing or if it's a draw or no result.
		* @param piece The piece which needs to be checked for winning condition.
		* @return returns int value 10 if the piece is winning, -10 if losing, 0 if draw, -1 if it's no result.
		*/
		int32_t WinningStateOfPiece(char piece);

		/**
		* Accessor for the number of moves played so far.
		* @return Returns an unsigned int of the number of played played.
		*/
		uint32_t MovesPlayed();

	private:
		/**
		* Checks if the player piece is in a winning state.
		* @param playerPiece The piece of the player to check if winning.
		*/
		bool didPlayerWin(char playerPiece);

		/**
		* Check if the line made by positions 1, 2 and 3 is a winning line.
		* @param playerPiece the piece played by the Player under scrutiny.
		* @param position1 Position to check in the line.
		* @param position2 Position to check in the line.
		* @param position3 Position to check in the line.
		*/
		bool checkLineForWin(char playerPiece, std::uint32_t position1, std::uint32_t position2, std::uint32_t position3);

		static const std::map<std::int32_t, GameState> MATCHSTATE_TO_GAMESTATE_MAP; /**< A hashmap of the winning state or drawing state of the game to GameState. */

		std::vector<std::uint8_t> mBoard;					/**< List of positions on the board. */
		std::uint32_t mMovesPlayed;							/**< Number of moves played on the board, so far. */
	};
}