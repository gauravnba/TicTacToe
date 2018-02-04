#pragma once

#include "Player.h"

namespace TicTacToe
{
	/**
	* Enum of states present in this game.
	*/
	enum class GameState : char
	{
		MainMenu			= '0',
		SinglePlayerGame	= '1',
		MultiPlayerGame		= '2',
		Quit				= 'q',
		PlayerXWins			= 'w',
		PlayerOWins			= 'l',
		Draw				= 'd'
	};

	/**
	* MainGame is the class that runs the game from start to quitting. It supports multiple modes and houses the game loop.
	*/
	class MainGame
	{
	public:
		/**
		* Constructor for MainGame, to initialize member variables.
		*/
		MainGame();

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

		/**
		* Main game loop where the actual game is played.
		*/
		void Update();

	private:
		void promptForGameMode();

		void promptForPlayerWeapons();

		void gameOver();

		GameState mGameState; /**< The current state of the game. */
		std::vector<Player> mPlayers;

		static const std::map<GameState, std::string> GAME_OVER_PROMPTS;
	};
}