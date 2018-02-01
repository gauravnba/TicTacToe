#pragma once

namespace TicTacToe
{
	/**
	* MainGame is the class that runs the game from start to quitting. It supports multiple modes and houses the game loop.
	*/
	class MainGame
	{
	public:
		/**
		* The default constructor for MainGame.
		*/
		MainGame() = default;

		/**
		* The default destructor for MainGame.
		*/
		~MainGame() = default;

		// Delete the MainGame copy constructor and move constructor.
		MainGame(MainGame&) = delete;
		MainGame(MainGame&&) = delete;

		/**
		* This will be called from main to start the main game loop.
		*/
		void Run();

	private:
		enum class GameMode
		{
			MainMenu,
			
		};
	};
}