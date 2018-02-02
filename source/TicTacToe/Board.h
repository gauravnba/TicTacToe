#pragma once

namespace TicTacToe
{
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

		void Update(std::uint32_t position, char character, bool& isPlacementSuccessful);

	private:
		std::vector<std::uint8_t> mBoard;
	};
}