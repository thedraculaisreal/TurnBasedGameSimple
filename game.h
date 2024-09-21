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

	entity knight("Himothy", 100, 100, 10, 10);
	entity dragon("dragon", 200, 200, 10, 20);
	entity vampire("vampire", 100, 100, 10, 5);
	std::string input;
	std::string enemy = "vampire";
	std::string player = "knight";

	while (knight.isAlive() && vampire.isAlive())
	{

		knight.display();

		std::cout << "**********************************" << std::endl;

		vampire.display();

		std::cout << "**********************************" << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		int critical = std::rand() % 2;

		switch (input[0])
		{
		case 'A':
		case 'a':
			if (critical == 0)
			{
				std::cout << "You attacked the " << enemy << " critcaly" << std::endl;
				dragon.defend(40, 5);
				break;
			}
			else
			{
				std::cout << "You attacked the " << enemy << std::endl;
				dragon.defend(20, 5);
				break;
			}

		case 'D':
		case 'd':
			std::cout << "You defended" << std::endl;
			continue;

		default:
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (!dragon.isAlive())
		{
			std::cout << "You have defeated the " << enemy << std::endl;
			break;
		}

		int random = std::rand() % 3;

		switch (random)
		{
		case 0:
			std::cout << "The " << enemy << " attacked you!" << std::endl;
			knight.defend(20, 10);
			break;

		case 1:
			std::cout << "The " << enemy << " attacked you critcally!" << std::endl;
			knight.defend(40, 10);
			break;

		default:
			std::cout << "The " << enemy << " missed" << std::endl;
		}
		vampire.heal(10);
	}
}

void game::knightDragon()
{

	std::cout << "You find a dragon slaying sword!" << std::endl;
	std::cout << "Plus 40 attack damage" << std::endl;

	entity knight("Himothy", 100, 100, 50, 10);
	entity dragon("dragon", 200, 200, 10, 20);
	entity vampire("vampire", 100, 100, 10, 5);
	std::string input;
	std::string enemy = "dragon";
	std::string player = "knight";



	while (knight.isAlive() && vampire.isAlive())
	{

		knight.display();

		std::cout << "**********************************" << std::endl;

		dragon.display();

		std::cout << "**********************************" << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		int critical = std::rand() % 2;

		switch (input[0])
		{
		case 'A':
		case 'a':
			if (critical == 0)
			{
				std::cout << "You attacked the " << enemy << " critcaly" << std::endl;
				dragon.defend(100, 20);
				break;
			}
			else
			{
				std::cout << "You attacked the " << enemy << std::endl;
				dragon.defend(50, 20);
				break;
			}

		case 'D':
		case 'd':
			std::cout << "You defended" << std::endl;
			continue;

		default:
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (!dragon.isAlive())
		{
			std::cout << "You have defeated the " << enemy << std::endl;
			break;
		}

		int random = std::rand() % 3;

		switch (random)
		{
		case 0:
			std::cout << "The " << enemy << " attacked you!" << std::endl;
			knight.defend(20, 20);
			break;

		case 1:
			std::cout << "The " << enemy << " attacked you critcally!" << std::endl;
			knight.defend(40, 20);
			break;

		default:
			std::cout << "The " << enemy << " missed" << std::endl;
		}
	}
}

void game::knight()
{
	entity knight("Himothy", 100, 100, 10, 10);
	entity dragon("dragon", 200, 200, 10, 20);
	entity vampire("vampire", 100, 100, 10, 5);


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
	else if (input == "right")
	{
		std::cout << "You went right, and encounter a dragon." << std::endl;
		std::cout << "Watch out dragons have high defense!" << std::endl;

		knightDragon();
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}
}

void game::dragon()
{
	entity knight("Himothy", 100, 100, 10, 10);
	entity dragon("dragon", 200, 200, 10, 20);
	entity vampire("vampire", 100, 100, 10, 5);


	std::string input;

	dragon.display();

	std::cout << "**********************************" << std::endl;

	std::cout << "Do you want to left or right? : ";
	std::cin >> input;

	if (input == "left")
	{
		std::cout << "You went left, and encounter a vampire." << std::endl;
		std::cout << "Watch out vampires heal every turn!" << std::endl;

		dragonVampire();
	}
	else if (input == "right")
	{
		std::cout << "You went right, and encounter a dragon." << std::endl;
		std::cout << "Watch out dragons have high defense!" << std::endl;

		dragonKnight();
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}
}

void game::dragonVampire()
{
	entity knight("Himothy", 100, 100, 10, 10);
	entity dragon("dragon", 200, 200, 10, 20);
	entity vampire("vampire", 100, 100, 10, 5);
	std::string input;
	std::string enemy = "vampire";
	std::string player = "dragon";

	while (knight.isAlive() && vampire.isAlive())
	{

		dragon.display();

		std::cout << "**********************************" << std::endl;

		vampire.display();

		std::cout << "**********************************" << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		int critical = std::rand() % 2;

		switch (input[0])
		{
		case 'A':
		case 'a':
			if (critical == 0)
			{
				std::cout << "You attacked the " << enemy << " critcaly" << std::endl;
				vampire.defend(40, 5);
				break;
			}
			else
			{
				std::cout << "You attacked the " << enemy << std::endl;
				vampire.defend(20, 5);
				break;
			}

		case 'D':
		case 'd':
			std::cout << "You defended" << std::endl;
			continue;

		default:
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (!vampire.isAlive())
		{
			std::cout << "You have defeated the " << enemy << std::endl;
			break;
		}

		int random = std::rand() % 3;

		switch (random)
		{
		case 0:
			std::cout << "The " << enemy << " attacked you!" << std::endl;
			dragon.defend(20, 20);
			break;

		case 1:
			std::cout << "The " << enemy << " attacked you critcally!" << std::endl;
			dragon.defend(40, 20);
			break;

		default:
			std::cout << "The " << enemy << " missed" << std::endl;
		}

		vampire.heal(10);
	}
}

void game::dragonKnight()
{
	entity knight("Himothy", 100, 100, 10, 10);
	entity dragon("dragon", 200, 200, 10, 20);
	entity vampire("vampire", 100, 100, 10, 5);
	std::string input;



	while (knight.isAlive() && vampire.isAlive())
	{

		dragon.display();

		std::cout << "**********************************" << std::endl;

		knight.display();

		std::cout << "**********************************" << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		int critical = std::rand() % 2;

		switch (input[0])
		{
		case 'A':
		case 'a':
			if (critical == 0)
			{
				std::cout << "You attacked the enemy critcaly" << std::endl;
				knight.defend(40, 10);
				break;
			}
			else
			{
				std::cout << "You attacked the enemy!" << std::endl;
				knight.defend(20, 10);
				break;
			}

		case 'D':
		case 'd':
			std::cout << "You defended" << std::endl;
			continue;
		
		default:
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (!knight.isAlive())
		{
			std::cout << "You have defeated the knight!" << std::endl;
			break;
		}

		int random = std::rand() % 3;

		switch (random)
		{
		case 0:
			std::cout << "The knight attacked you!" << std::endl;
			dragon.defend(20, 20);
			break;

		case 1:
			std::cout << "The knight attacked you critcally!" << std::endl;
			dragon.defend(40, 20);
			break;

		default:
			std::cout << "The knight missed" << std::endl;
		}
	}
}