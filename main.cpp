#include "entity.h"


int main() 
{

	std::cout << "Would you rather be a dragon or a knight?: ";
	std::string input;
	std::cin >> input;

	while (input != "dragon" && input != "knight")
	{
		std::cout << "Invalid input" << std::endl;
		std::cin >> input;
	}

	if (input == "dragon")
	{
		Dragon();
	}
	else if (input == "knight")
	{
		Knight();
	}
}
