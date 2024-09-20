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
	//constructor for entity
	entity(std::string name, int current_health, int max_health)
		: name(name), current_health(current_health), max_health(max_health) {}

	//display function to display the name and health of the entity
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
	
	void heal(int health)
	{
		current_health += health;
	}
};

void knightVampire()
{

	entity knight("Himothy", 100, 100);
	entity dragon("dragon", 200, 200);
	entity vampire("vampire", 100, 100);
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

void Knight()
{

	entity knight("Himothy", 100, 100);
	entity dragon("dragon", 200, 200);
	entity vampire("vampire", 100, 100);


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

void Dragon()
{
	entity dragon("dragon", 200, 200);
	entity knight("Himothy", 100, 100);
	entity vampire("vampire", 100, 100);

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