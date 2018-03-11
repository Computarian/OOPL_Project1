#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "CombatUnit.hpp"

class Enemy : public CombatUnit {
public:
	Enemy(int health, int damage, std::string name);
	virtual ~Enemy();
};

#endif