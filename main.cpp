#include "game.h"

int main() 
{

	while (true) 
	{

		game::runGame();

		char input;
		std::cout << "Would you like to play again? (Y/N): ";
		std::cin >> input;

		if (input == 'N' || input == 'n')
		{
			break;
		}
		else if (input == 'Y' || input == 'y')
		{
			continue;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			break;
		}
		
	}

	return 0;
}
