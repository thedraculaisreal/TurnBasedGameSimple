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