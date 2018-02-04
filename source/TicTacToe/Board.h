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
		* @param playerPiece 
		*/
		void Update(GameState& gameState, char playerPiece);

		/**
		* Removes the piece at position, leaving the spot empty.
		* @param position the spot from where the piece is to be taken out from.
		*/
		void RemovePiece(std::uint32_t position);

		int32_t CalculateWinningState(char piece);

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