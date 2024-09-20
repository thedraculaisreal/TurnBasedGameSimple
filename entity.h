#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class entity
{

private:

	std::string name;
	int current_health;
	int max_health;

public:

	entity(std::string name, int current_health, int max_health)
		: name(name), current_health(current_health), max_health(max_health) {}

	void display()
	{
		std::cout << "Name: " << name << " " << current_health << '/' << max_health << std::endl;
	}

	bool isAlive()
	{
		return current_health > 0;
	}

	void takeDamge(int attack)
	{
		current_health -= attack;
	}
};

void Knight()
{
	entity dragon("Dragon", 200, 100);
	entity knight("Himothy", 100, 100);

	std::string input;

	while (knight.isAlive() && dragon.isAlive()) {
		
		knight.display();

		std::cout << "**********************************" << std::endl;

		dragon.display();

		std::cout << "**********************************" << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		int critical = std::rand() % 2;

		if (input == "A" || input == "a" && critical == 0 )
		{
			std::cout << "You attacked the enemy critcaly" << std::endl;
			dragon.takeDamge(40);
		}
		else if (input == "A" || input == "a" && critical == 1)
		{
			std::cout << "You attacked the enemy!" << std::endl;
			dragon.takeDamge(20);
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

		if (!dragon.isAlive())
		{
			std::cout << "You have defeated the dragon!" << std::endl;
			break;
		}

		int random = std::rand() % 3;

		if (random == 0)
		{
			std::cout << "The dragon attacked you!" << std::endl;
			knight.takeDamge(20);
		}
		else if (random == 1)
		{
			std::cout << "The dragon attacked you critcally!" << std::endl;
			knight.takeDamge(40);
		}
		else
		{
			std::cout << "The dragon missed" << std::endl;
			continue;
		}
	}
}

void Dragon()
{
	entity dragon("Dragon", 200, 100);
	entity knight("Himothy", 100, 100);

	std::string input;

	while (knight.isAlive() && dragon.isAlive()) {

		dragon.display();

		std::cout << "**********************************" << std::endl;

		knight.display();

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
			continue;
		}
	}
}