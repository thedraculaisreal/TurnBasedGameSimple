#include "entity.h"

void game::runGame()
{
	std::cout << "Would you rather be a dragon or a knight?: ";
	std::string input;
	std::string input2;
	std::cin >> input;

	while (input != "dragon" && input != "knight")
	{
		std::cout << "Invalid input" << std::endl;
		std::cin >> input;
	}

	if (input == "dragon")
	{
		dragon();
	}
	else if (input == "knight")
	{
		knight();
	}
}

void game::knightVampire()
{

	entity knight("Himothy", 100, 100, 10);
	entity dragon("dragon", 200, 200, 10);
	entity vampire("vampire", 100, 100, 10);
	std::string input;

	while (knight.isAlive() && vampire.isAlive())
	{

		knight.display();

		std::cout << "**********************************" << std::endl;

		vampire.display();

		std::cout << "**********************************" << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		int critical = std::rand() % 2;

		if (input == "A" || input == "a" && critical == 0)
		{
			std::cout << "You attacked the enemy critcaly" << std::endl;
			vampire.takeDamge(40);
		}
		else if (input == "A" || input == "a" && critical == 1)
		{
			std::cout << "You attacked the enemy!" << std::endl;
			vampire.takeDamge(20);
		}
		else if (input == "D" || input == "d")
		{
			std::cout << "You defended" << std::endl;
			continue;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (!vampire.isAlive())
		{
			std::cout << "You have defeated the vampire!" << std::endl;
			break;
		}

		int random = std::rand() % 3;

		if (random == 0)
		{
			std::cout << "The vampire attacked you!" << std::endl;
			knight.takeDamge(10);
		}
		else if (random == 1)
		{
			std::cout << "The vampire attacked you critcally!" << std::endl;
			knight.takeDamge(20);
		}
		else
		{
			std::cout << "The vampire missed" << std::endl;
		}

		vampire.heal(10);
	}
}

void game::knight()
{

	entity knight("Himothy", 100, 100, 10);
	entity dragon("dragon", 200, 200, 10);
	entity vampire("vampire", 100, 100, 10);


	std::string input;

	knight.display();

	std::cout << "**********************************" << std::endl;

	std::cout << "Do you want to left or right? : ";
	std::cin >> input;

	if (input == "left")
	{
		std::cout << "You went left, and encounter a vampire." << std::endl;
		std::cout << "Watch out vampires heal every turn!" << std::endl;

		knightVampire();
	}
}

void game::dragon()
{
	entity knight("Himothy", 100, 100, 10);
	entity dragon("dragon", 200, 200, 10);
	entity vampire("vampire", 100, 100, 10);

	std::string input;

	while (knight.isAlive() && dragon.isAlive()) {

		dragon.display();

		std::cout << "**********************************" << std::endl;

		knight.display();

		std::cout << "**********************************" << std::endl;

		vampire.display();

		std::cout << "**********************************" << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		int critical = std::rand() % 2;

		if (input == "A" || input == "a" && critical == 0)
		{
			std::cout << "You attacked the knight critcaly" << std::endl;
			knight.takeDamge(40);
		}
		else if (input == "A" || input == "a" && critical == 1)
		{
			std::cout << "You attacked the knight!" << std::endl;
			knight.takeDamge(20);
		}
		else if (input == "D" || input == "d")
		{
			std::cout << "You defended" << std::endl;
			continue;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (!knight.isAlive())
		{
			std::cout << "You have defeated the knight!" << std::endl;
			break;
		}

		int random = std::rand() % 3;

		if (random == 0)
		{
			std::cout << "The knight attacked you!" << std::endl;
			dragon.takeDamge(20);
		}
		else if (random == 1)
		{
			std::cout << "The knight attacked you critcally!" << std::endl;
			dragon.takeDamge(40);
		}
		else
		{
			std::cout << "The knight missed" << std::endl;
		}

		std::cout << "Boreds turn who do you want to attack? (d),(h)" << std::endl;

		std::cin >> input;

		if (input == "D" || input == "d")
		{
			std::cout << "You attacked the dragon!" << std::endl;
			dragon.takeDamge(20);
		}
		else if (input == "H" || input == "h")
		{
			std::cout << "You attacked the knight!" << std::endl;
			knight.takeDamge(20);
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}
	}
}