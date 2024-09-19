#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

struct entity
{
	std::string name;
	int current_health;
	int max_health;
	int attack;
};

entity knight
{
	entity {"Knight", 100, 100, 10}
};

entity dragon
{
	entity {"dragon", 200, 200, 20}
};

void Knight()
{
	std::string input;


	while (dragon.current_health > 0 && knight.current_health > 0) {
		std::cout << "Knight's health: " << knight.current_health << "/" << knight.max_health << ' ' << "ATK" << knight.attack << std::endl;

		std::cout << "**********************************" << std::endl;

		std::cout << "Dragon's health: " << dragon.current_health << "/" << dragon.max_health << ' ' << "ATK" << dragon.attack << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		if (input == "A" || input == "a")
		{
			std::cout << "You attacked the enemy!" << std::endl;
			dragon.current_health -= knight.attack;
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
			std::cout << "The dragon missed" << std::endl;
			continue;
		}
	}
	std::cout << "You have defeated the Dragon!" << std::endl;
}

void Dragon()
{
	std::string input;


	while (dragon.current_health > 0 && knight.current_health > 0) {
		std::cout << "Dragon's health: " << dragon.current_health << "/" << dragon.max_health << ' ' << "ATK" << dragon.attack << std::endl;

		std::cout << "**********************************" << std::endl;

		std::cout << "Knight's health: " << knight.current_health << "/" << knight.max_health << ' ' << "ATK" << knight.attack << std::endl;

		std::cout << "Type A to attack D to defend: ";

		std::cin >> input;

		if (input == "A" || input == "a")
		{
			std::cout << "You attacked the enemy!" << std::endl;
			knight.current_health -= dragon.attack;
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

		if (dragon.current_health <= 0)
		{
			std::cout << "You have defeated the Knight!" << std::endl;
			break;
		}

		int random = std::rand() % 2;

		if (random == 0)
		{
			std::cout << "The Knight attacked you!" << std::endl;
			dragon.current_health -= knight.attack;
		}
		else
		{
			std::cout << "The knight missed" << std::endl;
			continue;
		}
	}
	std::cout << "You have defeated the Knight!" << std::endl;
}
