#include "pch.h"

#include "Board.h"
#include "MainGame.h"

using namespace std;

namespace TicTacToe
{
	const map<GameState, string> MainGame::GAME_OVER_PROMPTS = {	{GameState::Draw, "The game was a draw. "},
																			{GameState::PlayerXWins, "Player x won the game. "},
																			{GameState::PlayerOWins, "Player o won the game. "} };

	MainGame::MainGame() :
		mGameState(GameState::MainMenu)
	{ 
		// Populate the mPlayers vector with our two players.
		mPlayers.reserve(2);
		Player player1('x'), player2('o');
		mPlayers = { player1, player2 };
	}

	void MainGame::Run()
	{
		// Display the main menu.
		while (mGameState == GameState::MainMenu)
		{
			promptForGameMode();
			promptForPlayerWeapons();
			Update();
		}
	}

	void MainGame::Update()
	{
		system("cls");

		Board board;
		while (mGameState == GameState::SinglePlayerGame || mGameState == GameState::MultiPlayerGame)
		{
			for (uint32_t i = 0; i < mPlayers.size(); ++i)
			{
				mPlayers[i].Update(board, mGameState);
				board.Update(mGameState, mPlayers[i].Piece());
				board.Draw();
				
				if (!(mGameState == GameState::SinglePlayerGame || mGameState == GameState::MultiPlayerGame)) break;
			}
		}

		if (mGameState != GameState::Quit)
		{
			cout << GAME_OVER_PROMPTS.at(mGameState);
			gameOver();
		}
	}

	void MainGame::promptForGameMode()
	{
		char input;

		system("cls");
		cout << "\tTic Tac Toe" << endl;
		cout << "To play a game with the AI, press 1 and enter\n"
			"To play a game with another player, press 2 and enter\n"
			"Enter q at any time to quit." << endl;

		cin >> input;

		// Wait for user input for game mode. Repeat until valid input is encountered.
		// Check if only one of the conditions is true (XNOR).
		while (!(input == '1' || input == '2' || input == 'q'))
		{
			cout << "Please enter either 1 or 2. Or q to quit." << endl;
			cin >> input;
		}

		mGameState = static_cast<GameState>(input);
	}

	void MainGame::promptForPlayerWeapons()
	{
		// Check in case the player decided to quit earlier.
		if (mGameState == GameState::SinglePlayerGame)
		{
			char input = 0;

			// Wait for user input for selection of nought or cross.
			// Again, check while using XNOR.
			while (!(input == 'x' || input == 'o'))
			{
				cout << "Select weapon (either 'x' or 'o') for Player 1" << endl;
				cin >> input;

				// Quit if input was q. This condition returns to Run().
				if (input == 'q')
				{
					mGameState = GameState::Quit;
					return;
				}

				if (mGameState == GameState::SinglePlayerGame)
				{
					if (input == 'x')
					{
						mPlayers[1].SetHumanity(false);
					}
					else if (input == 'o')
					{
						mPlayers[0].SetHumanity(false);
					}
				}
			}
		}
	}

	void MainGame::gameOver()
	{
		char input;
		cout << "Enter 'y' to go back to the Main Menu or 'q' to quit." << endl;
		cin >> input;
		if (input == 'q') return;
		else if (input == 'y') mGameState = GameState::MainMenu;
	}
}