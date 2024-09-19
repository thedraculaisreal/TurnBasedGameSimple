#include "main.h"
#include "random"

int main() {

	std::string input;

	
	while (dragon.current_health > 0 || knight.current_health > 0) {
		std::cout << "Knight's health: " << knight.current_health << "/" << knight.max_health << ' ' << "ATK" << knight.attack << std::endl;

		std::cout << "**********************************" << std::endl;

		std::cout << "Dragon's health: " << dragon.current_health << "/" << dragon.max_health << ' ' << "ATK" << dragon.attack << std::endl;
		
		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		if (input == "A")
		{
			std::cout << "You attacked the enemy!" << std::endl;
			dragon.current_health -= knight.attack;
		}
		else if (input == "D")
		{
			std::cout << "You defended" << std::endl;
			continue;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (dragon.current_health <= 0)
		{
			std::cout << "You have defeated the dragon!" << std::endl;
			break;
		}

		int random = std::rand() % 2;

		if (random == 0)
		{
			std::cout << "The dragon attacked you!" << std::endl;
			knight.current_health -= dragon.attack;
		}
		else
		{
			std::cout << "The dragon defended" << std::endl;
			continue;
		}

	}
}