#include "Application.hpp"

namespace DK
{
	const std::array<std::array<char, 3>, 8> TicTacToeAiMalware::WIN_POSITIONS = {
		std::array<char, 3>({ 0, 1, 2 }), { 3, 4, 5 }, { 6, 7, 8 },
		{ 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 },
		{ 0, 4, 8 }, { 2, 4, 6 }
	};

	TicTacToeAiMalware::TicTacToeAiMalware()
	{
	}

	TicTacToeAiMalware::~TicTacToeAiMalware()
	{
	}

	void TicTacToeAiMalware::run()
	{
		std::cout << "Welcome to an entry to the Coding with Lewis Hackathon!\n";

		do
		{
			std::cout << "\n\nWhat you want to do now? ( Exit - 0, Play Tic Tac Toe - 1, About - 2 ): ";

			int result;
			std::cin >> result;

			if (!result)
			{
				std::cout << "Thanks for seeing my entry!";
				return;
			}

			switch (result)
			{
				case 1:
				{
					playingTicTacToe();
					break;
				}
				case 2:
				{
					about();
					break;
				}
				default:
				{
					std::cout << "Please give a desired input!\n";
				}
			}
		} while (true);
	}

	void TicTacToeAiMalware::playingTicTacToe()
	{
		std::cout << "\n\nAlright! Since you want to play tic tac toe! Let me tell you rules!\n";
		std::cout << "You need to get 3 of your symbols in a row, column and diagonal.\n";
		std::cout << "If you get the condition first, you win!\n";
		std::cout << "If the computer gets it first, then you lose!\n";
		std::cout << "If neither happens, then it'll be a draw!\n";

		resetBoard();
		do
		{
			m_Player = togglePlayer();
			printBoard();
			placeMove();
		} while (!gameCompleted());

		printBoard();
		switch (m_GameEndState)
		{
			case WIN:
			{
				std::cout << "Well done! You won!\n";
				break;
			}
			case LOSE:
			{
				std::cout << "Nice try but You lose!\n";
				break;
			}
			case DRAW:
			{
				std::cout << "Well both of you were good and you both end to a draw!\n";
				break;
			}
			default:
			{
				std::cout << "Invalid state occured! Need a check!\n";
			}
		}
	}

	void TicTacToeAiMalware::about()
	{
		std::cout << "Not written about till now :)\n";
	}

	bool TicTacToeAiMalware::gameCompleted() const
	{
		return isWin() || isDraw();
	}

	bool TicTacToeAiMalware::isWin() const
	{
		if (m_GameEndState != PLAYING) return m_GameEndState != DRAW;
		for (unsigned int i = 0; i < 8; i++)
		{
			if (m_TTTBoard[WIN_POSITIONS[i][0]] == m_Player && m_TTTBoard[WIN_POSITIONS[i][1]] == m_Player && m_TTTBoard[WIN_POSITIONS[i][2]] == m_Player)
			{
				m_GameEndState = (m_Player == 'O') ? WIN : LOSE;
				return true;
			}
		}
		return false;
	}

	bool TicTacToeAiMalware::isDraw() const
	{
		if (m_GameEndState != PLAYING) return m_GameEndState == DRAW;
		for (unsigned int i = 0; i < 9; i++)
		{
			if (m_TTTBoard[i] != 'O' && m_TTTBoard[i] != 'X') return false;
		}
		if (isWin()) return false;

		m_GameEndState = DRAW;
		return true;
	}

	void TicTacToeAiMalware::printBoard() const
	{
		std::cout << "\n\nCurrent Board Status:\n " << m_TTTBoard[0] << " | " << m_TTTBoard[1] << " | " << m_TTTBoard[2] << "\n-----------\n " << m_TTTBoard[3]
			<< " | " << m_TTTBoard[4] << " | " << m_TTTBoard[5] << "\n-----------\n " << m_TTTBoard[6] << " | " << m_TTTBoard[7] << " | " << m_TTTBoard[8] << "\n";
	}

	void TicTacToeAiMalware::placeMove()
	{
		// 1'000'000'100 is a magic value that i suppose no one would type.
		static const unsigned int MAGIC_VALUE = 1'000'000'100;
		unsigned int idx{MAGIC_VALUE};
		std::cout << "Place a move by giving the idx of the board: ";
		do 
		{
			if (idx != MAGIC_VALUE)
			{
				std::cout << idx << " is an invalid input. Please give an index of an empty square on the board: ";
			}
			std::cin >> idx;
		} while (idx > 8 || isInvalidMove(idx));
		m_TTTBoard[idx] = m_Player;
	}

	bool TicTacToeAiMalware::isInvalidMove(unsigned int idx) const
	{
		return m_TTTBoard[idx] == 'O' || m_TTTBoard[idx] == 'X';
	}

	char TicTacToeAiMalware::togglePlayer() const
	{
		return m_Player == 'O' ? 'X' : 'O';
	}

	void TicTacToeAiMalware::resetBoard()
	{
		m_TTTBoard = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
		m_GameEndState = PLAYING;
	}
}

int main()
{
	DK::TicTacToeAiMalware game;
	game.run();
}