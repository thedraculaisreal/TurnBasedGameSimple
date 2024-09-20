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
	//constructor for entity
	entity(std::string name, int current_health, int max_health, int defense)
		: name(name), current_health(current_health), max_health(max_health), defense(defense) {}

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

namespace game
{
	void runGame();
	void knightVampire();
	void knight();
	void dragon();
}