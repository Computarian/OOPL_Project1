#ifndef ENEMY_HPP
#define ENEMY_HPP

//#include "Spawnable.hpp"
#include "CombatUnit.hpp"
#include "Item.hpp"

class Enemy : /*public Spawnable,*/ public CombatUnit {
public:
	Enemy(int health, int damage, std::string name);
};

#endif