#include "Application.hpp"

namespace DK
{
	TicTacToeAiMalware::TicTacToeAiMalware()
		: m_TTTBoard()
	{
	}

	TicTacToeAiMalware::~TicTacToeAiMalware()
	{
	}

	void TicTacToeAiMalware::run()
	{
		std::cout << "Welcome to an entry to the Coding with Lewis Hackathon!\n";
	}

}

int main()
{
	DK::TicTacToeAiMalware game;
	game.run();
}