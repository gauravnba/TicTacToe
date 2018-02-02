#include "pch.h"

#include "MainGame.h"
#include "Board.h"

using namespace std;

namespace TicTacToe
{
	MainGame::MainGame() :
		mGameState(GameState::MainMenu)
	{
	}

	void MainGame::Run()
	{
		// Display the main menu.
		while (mGameState == GameState::MainMenu)
		{
			PromptForGameMode();
			PromptForPlayerWeapons();
			Update();
		}
	}

	void MainGame::Update()
	{
		Board board;
		while (mGameState == GameState::SinglePlayerGame || mGameState == GameState::MultiPlayerGame)
		{
			board.Draw();
			mPlayer1.Update(board);
			mPlayer2.Update(board);
		}
	}

	void MainGame::PromptForGameMode()
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

	void MainGame::PromptForPlayerWeapons()
	{
		char input = 0;

		// Wait for user input for selection of nought or cross.
		// Again, using XNOR.
		while (!(input == 'x' || input == 'o'))
		{
			cout << "Select weapon (either 'x' or 'o') for Player 1" << endl;
			cin >> input;
			mPlayer1.SetPlayerWeapon(input);

			if (input == 'x')
			{
				mPlayer2.SetPlayerWeapon('o');
			}
			else if (input == 'o')
			{
				mPlayer2.SetPlayerWeapon('x');
			}
		}
	}
}