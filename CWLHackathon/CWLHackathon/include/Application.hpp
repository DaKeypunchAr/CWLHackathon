#ifndef _Application_Hpp
#define _Application_Hpp

#include <chrono>

#include <array>
#include <vector>
#include <iostream>
#include <sstream>

#include <thread>

#define CONSOLE_RESET "\033[0m"
#define CONSOLE_RED "\033[31m"

#define DEBUG 1

namespace DK
{
	class TicTacToeAiMalware
	{
	public:
		TicTacToeAiMalware();
		~TicTacToeAiMalware();

		void run(); // the magic place where everything happens

	private:
		void playingTicTacToe();
		void about();

		bool askMathQuestion() const;

		static bool gameCompleted(const std::array<char, 9>& board, char player);
		static bool isWin(const std::array<char, 9>& board, char player);
		static bool isDraw(const std::array<char, 9>& board);

		static void printBoard(const std::array<char, 9>& board);
		void placeMove();

		static bool isInvalidMove(const std::array<char, 9>& board, unsigned int idx);
		static char togglePlayer(char player);

		void resetBoard();

		static void AIPrint(const std::string& text);
		static void sleep(unsigned int milliseconds);

		static int getRandomInRange(int lowerBound, int upperBound);

		int minimax(bool isMaximising, std::array<char, 9>& board) const;

	private:
		std::array<char, 9> m_TTTBoard{ '0', '1', '2', '3', '4', '5', '6', '7', '8' };
		char m_Player = 'X';

		bool m_FirstRun = true;
	private:

		static const std::array<std::array<char, 3>, 8> WIN_POSITIONS;
	};
}

#endif