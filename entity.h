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
	int defense;

public:

	entity(std::string name, int current_health, int max_health, int defense)
		: name(name), current_health(current_health), max_health(max_health), defense(defense) {}

	void display()
	{
		std::cout << "Name: " << name << " " << current_health << '/' << max_health << ' ' << "DEF: " << defense << std::endl;
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

namespace game
{
	void runGame();
	void knightVampire();
	void knight();
	void dragon();
}