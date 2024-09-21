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
	int attack;
	int defense;

public:

	entity(std::string name, int current_health, int max_health, int attack,  int defense)
		: name(name), current_health(current_health), max_health(max_health), attack(attack), defense(defense) {}

	void display()
	{
		std::cout << "Name: " << name << " " << "HP:" << current_health << '/' << max_health << ' ' << "ATK:" << attack << " DEF:" << defense << std::endl;
	}

	bool isAlive()
	{
		if (current_health > 0)
			return true;
		else
			return false;

	}

	void takeDamge(int attack)
	{
		current_health -= attack;
	}
	
	void heal(int health)
	{
		current_health += health;
	}

	void defend(int attack, int defense)
	{
		defense = std::rand() % defense;
		current_health -= attack - defense;
	}
};

namespace game
{
	void runGame();
	void knightVampire();
	void knightDragon();
	void knight();
	void dragon();
	void dragonVampire();
	void dragonKnight();
}