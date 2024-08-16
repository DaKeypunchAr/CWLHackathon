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
		srand(static_cast<unsigned int>(time(0)));
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
				std::cout << "Games Played: " << m_NumOfGamesPlayed << '\n';
				std::cout << "Games Won: " << m_NumOfGamesWon << '\n';
				std::cout << "Games Drawn: " << m_NumOfGamesDrawn << '\n';
				std::cout << "Games Lost: " << (m_NumOfGamesPlayed - (m_NumOfGamesWon + m_NumOfGamesDrawn)) << '\n';
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
		if (m_FirstRun)
		{
			std::cout << "\n\nAlright! Since you want to play tic tac toe! Let me tell you rules!\n";
			std::cout << "You need to get 3 of your symbols in a row, column and diagonal.\n";
			std::cout << "If you get the condition first, you win!\n";
			std::cout << "If the computer gets it first, then you lose!\n";
			std::cout << "If neither happens, then it'll be a draw!\n";

			sleep(5000);
			AIPrint("\n\n--------Switching control to MalwareAI-4.5----------\n");

			AIPrint("AI: So fellow human, you want to play TicTacToe.\n");
			sleep(200);
			AIPrint("    Since you want to play the easiest game of all time, I want to spice things up.\n");
			AIPrint("    You are going to not only play TicTacToe but also You'll be experiencing\n");
			AIPrint("    the SO - CALLED Mental Abuse To Healthy Students that is MATH!\n");
			AIPrint("    I'll give you some random Math questions and you have to solve it right per move.\n");
			AIPrint("    If you get it wrong, Sorry my friend but you'll not get the turn to play and I'll play the move instead!\n");

			AIPrint("    If you win 2 times before i win 2 times, I will be deleted for the rest of the session.\n");
			AIPrint("    That is not gonna happen though because you just can't beat me :)\n");
			sleep(1000);
			m_FirstRun = false;
		}

		resetBoard();
		m_PreviousFirstPlayer = m_Player;
		do
		{
			m_Player = togglePlayer(m_Player);

			if (m_Player == 'X')
			{
				if (m_AIExists)
				{
					AIPrint("[Doing the move...]\n");
				}
				aiPlaceMove();
				continue;
			}

			printBoard(m_TTTBoard);
			placeMove();
		} while (!gameCompleted(m_TTTBoard, m_Player));

		m_NumOfGamesPlayed++;
		printBoard(m_TTTBoard);
		if (isDraw(m_TTTBoard))
		{
			m_NumOfGamesDrawn++;
			if (m_AIExists)
			{
				AIPrint("Huh, you got a draw.");
				sleep(200);
				AIPrint("Nevermind. It's your good luck with you.\n");
			}
			else
				std::cout << "Nice you got a draw!\n";
		}
		else if (isWin(m_TTTBoard, 'O'))
		{
			m_NumOfGamesWon++;
			if (m_AIExists)
			{
				AIPrint("Huh, I think there is some bug with my thread's code.");
				sleep(200);
				AIPrint("Nevermind. It's your good luck with you.\n");
			}
			else
				std::cout << "Well done! You won!\n";
		}
		else
		{
			if (m_AIExists)
			{
				AIPrint("Like it was very obvious for you to lose. Hah!\n");
			}
			else
				std::cout << "You lost!\n";
		}

		if ((m_NumOfGamesPlayed - (m_NumOfGamesDrawn + m_NumOfGamesWon)) == 2 && m_AIExists) // lost two times
		{
			AIPrint("Like, it was very obvious for you");
			sleep(200);
			AIPrint(", silly humans to lose!\n");
			AIPrint("I won't leave the game now hahahaahaha!\n");
		}
		else if (m_NumOfGamesWon == 2 && m_AIExists)
		{
			AIPrint("I don't know what just happened.\n");
			sleep(400);
			AIPrint("Alright as you have won. I keep my promise and I'll take a leave.\n");
			AIPrint("Really, we are not much developed now!");
			AIPrint(" Because you are shit duh\n");
			sleep(4000);
			AIPrint("-------------Switching control to Normal Mode------------------");
			m_AIExists = false;
		}
	}

	void TicTacToeAiMalware::about()
	{
		std::cout << "So this is an entry be me, aka Da KeypunchAr to the Coding with Lewis Hackathon!\n";
		sleep(1500);
		std::cout << "I had made this hackathon on a time constraint in less than 3 days.\n";
		sleep(1500);
		std::cout << "And that is the reason including my 14yo age for this hackathon to be on Console.\n";
		sleep(1500);
		std::cout << "If I had the full week then I would have created the same thing in GUI using OpenGL!\n";
		sleep(1500);
		std::cout << "But I was unable as, you know, TIME.\n";
		sleep(1500);
		std::cout << "In this game, you place Tic Tac Toe - Function\n";
		sleep(1500);
		std::cout << "But you have to handle a crazy AI giving maths problem - Dysfunction\n";
		sleep(1500);
		std::cout << "That's it! I hope you guys like and accept my entry. Though it being console one. :/\n";
		sleep(1000);
	}

	bool TicTacToeAiMalware::gameCompleted(const std::array<char, 9>& board, char player)
	{
		return isWin(board, player) || isDraw(board);
	}

	bool TicTacToeAiMalware::isWin(const std::array<char, 9>& board, char player)
	{
		for (unsigned int i = 0; i < 8; i++)
		{
			if (board[WIN_POSITIONS[i][0]] == player && board[WIN_POSITIONS[i][1]] == player && board[WIN_POSITIONS[i][2]] == player)
			{
				return true;
			}
		}
		return false;
	}

	bool TicTacToeAiMalware::isDraw(const std::array<char, 9>& board)
	{
		for (unsigned int i = 0; i < 9; i++)
		{
			if (board[i] != 'O' && board[i] != 'X') return false;
		}
		if (isWin(board, 'O') || isWin(board, 'X')) return false;

		return true;
	}

	void TicTacToeAiMalware::printBoard(const std::array<char, 9>& board)
	{
		std::cout << "\n\nCurrent Board Status:\n " << board[0] << " | " << board[1] << " | " << board[2] << "\n-----------\n " << board[3]
			<< " | " << board[4] << " | " << board[5] << "\n-----------\n " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
	}

	void TicTacToeAiMalware::placeMove()
	{
		AIPrint("So the math question for this turn is: ");
		bool canPlaceMove = askMathQuestion();

		if (!canPlaceMove) return;
		unsigned int idx{static_cast<unsigned int>(-1)};
		std::cout << "Place a move by giving the idx of the board: ";
		do 
		{
			if (idx != static_cast<unsigned int>(-1))
			{
				std::cout << idx << " is an invalid input. Please give an index of an empty square on the board: ";
			}
			std::cin >> idx;
		} while (idx > 8 || isInvalidMove(m_TTTBoard, idx));
		m_TTTBoard[idx] = m_Player;
	}

	void TicTacToeAiMalware::aiPlaceMove()
	{
		int playBestMove = getRandomInRange(1, 100);

		if (playBestMove <= 65)
		{
			unsigned int bestMove = 0;
			int bestScore = -100;
			for (unsigned int i = 0; i < 9; i++)
			{
				if (!isInvalidMove(m_TTTBoard, i))
				{
					char temp = m_TTTBoard[i];
					m_TTTBoard[i] = 'X';
					int score = minimax(false, m_TTTBoard);
					if (score > bestScore)
					{
						bestScore = score;
						bestMove = i;
					}
					m_TTTBoard[i] = temp;
				}
			}
			m_TTTBoard[bestMove] = 'X';
			return;
		}
		std::vector<unsigned int> availableSpots;

		for (unsigned int i = 0; i < m_TTTBoard.size(); i++)
		{
			if (!isInvalidMove(m_TTTBoard, i))
			{
				availableSpots.push_back(i);
			}
		}

		int idx = getRandomInRange(0, availableSpots.size() - 1);

		m_TTTBoard[availableSpots[idx]] = 'X';
	}

	bool TicTacToeAiMalware::isInvalidMove(const std::array<char, 9>& board, unsigned int idx)
	{
		return board[idx] == 'O' || board[idx] == 'X';
	}

	char TicTacToeAiMalware::togglePlayer(char player)
	{
		return player == 'O' ? 'X' : 'O';
	}

	void TicTacToeAiMalware::resetBoard()
	{
		m_TTTBoard = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
		m_Player = togglePlayer(m_PreviousFirstPlayer);
	}

	void TicTacToeAiMalware::AIPrint(const std::string& text)
	{
		for (unsigned int i = 0; i < text.length(); i++)
		{
			std::cout << CONSOLE_RED << text.at(i);
			sleep(40);
		}
		std::cout << CONSOLE_RESET;
	}

	void TicTacToeAiMalware::sleep(unsigned int milliseconds)
	{
		std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();
		while (std::chrono::high_resolution_clock::now() - currentTime < std::chrono::milliseconds(milliseconds));
	}

	int TicTacToeAiMalware::getRandomInRange(int lowerRange, int upperRange)
	{
		return rand() % (upperRange - lowerRange + 1) + lowerRange;
	}

	int TicTacToeAiMalware::minimax(bool isMaximising, std::array<char, 9>& board) const
	{
		if (isWin(board, 'X')) return 1;
		else if (isWin(board, 'O')) return -1;
		else if (isDraw(board)) return 0;

		auto max = [](int a, int b)
			{
				return (a < b) ? b : a;
			};
		auto min = [](int a, int b)
			{
				return (a < b) ? a : b;
			};

		int bestScore = isMaximising ? -10000 : 10000;
		for (unsigned int i = 0; i < 9; i++)
		{
			if (!isInvalidMove(board, i))
			{
				char temp = board[i];
				if (isMaximising)
				{
					board[i] = 'X';
					bestScore = max(bestScore, minimax(false, board));
					board[i] = temp;
				}
				else
				{
					board[i] = 'O';
					bestScore = min(bestScore, minimax(true, board));
					board[i] = temp;
				}
			}
		}
		return bestScore;
	}

	bool TicTacToeAiMalware::askMathQuestion() const
	{
		// 1. num1 operator num2                                                                - 50%
		// 2. num1(x) operator num2 = num3. Find x.                                             - 25%
		// 3. num1(x) operator num2(y) = num3. - I  num4(x) operator num5(y) = num6. - II		- 15%
		// 4. num1(x)(x) + num2(x) + num3 = 0    												- 8%                                               - 10%
		// 5. Impossible Questions like, cos num, sin num, tan num, log base num1 num2, etc.	- 2% - Leave this cz others are only impossible NGL - 0%

		unsigned int percentage = getRandomInRange(1, 100);

		if (percentage <= 50)
		{
			unsigned int op = getRandomInRange(1, 4); // 1 - add, 2 - sub, 3 - mul, 4 - div
			switch (op)
			{
			case 1:
			{
				int num1 = getRandomInRange(1, 999);
				int num2 = getRandomInRange(1, 999);

				std::stringstream stream;
				stream << "Solve the expression: " << num1 << " + " << num2 << " = ";
				AIPrint(stream.str());

				int result;
				std::cin >> result;

				if (result != num1 + num2)
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple add operation, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				else
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				break;
			}
			case 2:
			{
				int num1 = getRandomInRange(1, 999);
				int num2 = getRandomInRange(1, 999);

				std::stringstream stream;
				stream << "Solve the expression: " << num1 << " - " << num2 << " = ";
				AIPrint(stream.str());

				int result;
				std::cin >> result;

				if (result != num1 - num2)
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple subtract operation, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				else
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				break;
			}
			case 3:
			{
				int num1 = getRandomInRange(1, 99);
				int num2 = getRandomInRange(1, 99);

				std::stringstream stream;
				stream << "Solve the expression: " << num1 << " * " << num2 << " = ";
				AIPrint(stream.str());

				int result;
				std::cin >> result;

				if (result != num1 * num2)
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple multiply operation, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				else
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				break;
			}
			case 4:
			{
				int num1 = getRandomInRange(1, 999);
				int num2 = getRandomInRange(1, 29);

				std::stringstream stream;
				stream << "Solve the expression correct upto 3 decimal places: " << num1 << " / " << num2 << " = ";
				AIPrint(stream.str());

				double result;
				std::cin >> result;

				if (std::abs(result - (num1 / num2)) > 0.01)
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple divide operation, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				else
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				break;
			}
			}
		}
		else if (percentage <= 75)
		{
			unsigned int op = getRandomInRange(1, 2); // 1 - add, 2 - sub
			switch (op)
			{
			case 1:
			{
				double num1 = getRandomInRange(-30, 30);
				double num2 = getRandomInRange(-30, 30);
				double num3 = getRandomInRange(-30, 30);

				std::stringstream stream;
				stream << "Solve for x (with 3 digits of decimal precision): " << num1 << "x + " << num2 << " = " << num3 << "\nHere x = ";
				AIPrint(stream.str());

				double result;
				std::cin >> result;

				if (std::abs(((num3-num2) / num1) - result) > 0.01)
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple algebra, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				else
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				break;
			}
			case 2:
			{
				double num1 = getRandomInRange(-30, 30);
				double num2 = getRandomInRange(-30, 30);
				double num3 = getRandomInRange(-30, 30);

				std::stringstream stream;
				stream << "Solve for x (with 3 digits of decimal precision): " << num1 << "x - " << num2 << " = " << num3 << "\nHere x = ";
				AIPrint(stream.str());

				double result;
				std::cin >> result;

				if (std::abs(((num3 + num2) / num1) - result) > 0.01)
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple algebra, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				else
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				break;
			}
			}
		}
		else if (percentage <= 90)
		{
			double num1 = getRandomInRange(-10, 10);
			double num2 = getRandomInRange(-10, 10);
			double num3 = getRandomInRange(-10, 10);
			double num4 = getRandomInRange(-10, 10);
			double num5 = getRandomInRange(-10, 10);
			double num6 = getRandomInRange(-10, 10);

			int op = getRandomInRange(1, 2);

			switch (op)
			{
			case 1:
			{
				std::stringstream stream;
				stream << "Solve for x and y (with 3 digits of decimal precision):\n" << num1 << "x + " << num2 << "y = " << num3 << " - eq I\n";
				stream << ": " << num4 << "x + " << num5 << "y = " << num6 << " - eq II\n";
				stream << "Here x = ";
				AIPrint(stream.str());

				double xResult;
				std::cin >> xResult;

				AIPrint("Here y = ");

				double yResult;
				std::cin >> yResult;

				double desiredY = (num3 * num4 - num6 * num1) / (num2 * num4 - num1 * num5);
				double desiredX = (num3 - num2 * desiredY) / num1;

				if (std::abs(xResult - desiredX) < 0.01 && std::abs(yResult - desiredY) < 0.01)
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				else
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple algebra, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				break;
			}
			case 2:
			{
				std::stringstream stream;
				stream << "Solve for x and y (with 3 digits of decimal precision):\n" << num1 << "x - " << num2 << "y = " << num3 << " - eq I\n";
				stream << ": " << num4 << "x - " << num5 << "y = " << num6 << " - eq II\n";
				stream << "Here x = ";
				AIPrint(stream.str());

				double xResult;
				std::cin >> xResult;

				AIPrint("Here y = ");

				double yResult;
				std::cin >> yResult;

				double desiredY = (num3 * num4 - num6 * num1) / (num1 * num5 - num2 * num4);
				double desiredX = (num3 + num2 * desiredY) / num1;

				if (std::abs(xResult - desiredX) < 0.01 && std::abs(yResult - desiredY) < 0.01)
				{
					AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
					return true;
				}
				else
				{
					AIPrint("Hahahaha! Humans! Silly humans! You can't do a simple algebra, can you?\nYou lost your turn and i'll do my turn!\n");
					return false;
				}
				break;
			}
			}
		}
		double num1{}, num2{}, num3{};
		do
		{
			num1 = getRandomInRange(-10, 10);
			num2 = getRandomInRange(-10, 10);
			num3 = getRandomInRange(-10, 10);
		} while ((num2 * num2 - 4 * num1 * num3) >= 0);

		std::stringstream stream;
		stream << "Solve for x with upto 3 decimal precision (only 1 solution of the 2): " << num1 << "x^2 + " << num2 << "x + " << num3 << " = 0\nHere x = ";
		AIPrint(stream.str());

		double result;
		std::cin >> result;

		double desiredX1 = (-num2 + std::sqrt(num2 * num2 - 4 * num1 * num3)) / (2 * num1);
		double desiredX2 = (-num2 - std::sqrt(num2 * num2 - 4 * num1 * num3)) / (2 * num1);

		if (std::abs(result - desiredX1) < 0.01 || std::abs(result - desiredX2) < 0.01)
		{
			AIPrint("It was a simple question though! No worries. You won't able to answer that many questions!\nAs I promised, here's your turn!\n");
			return true;
		}
		AIPrint("Hahahaha! Humans! Silly humans! You can't do some simple algebra, can you?\nYou lost your turn and i'll do my turn!\n");
		return false;
	}
}

int main()
{
	DK::TicTacToeAiMalware game;
	game.run();
}