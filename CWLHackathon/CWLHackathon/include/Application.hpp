#ifndef _Application_Hpp
#define _Application_Hpp

#include <array>
#include <iostream>

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

		bool gameCompleted() const;
		bool isWin() const;
		bool isDraw() const;

		void printBoard() const;
		void placeMove();

		bool isInvalidMove(unsigned int idx) const;
		char togglePlayer() const;

		void resetBoard();

	private:
		std::array<char, 9> m_TTTBoard{ '0', '1', '2', '3', '4', '5', '6', '7', '8' };
		char m_Player = 'X';
		mutable unsigned char m_GameEndState = PLAYING;

	private:
		static const unsigned char PLAYING = 0;
		static const unsigned char WIN = 1;
		static const unsigned char LOSE = 2;
		static const unsigned char DRAW = 3;

		static const std::array<std::array<char, 3>, 8> WIN_POSITIONS;
	};
}

#endif