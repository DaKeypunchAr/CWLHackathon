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

	private:
		std::array<char, 9> m_TTTBoard;
	};
}

#endif