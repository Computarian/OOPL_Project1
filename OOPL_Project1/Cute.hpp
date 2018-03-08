#ifndef CUTE_HPP
#define CUTE_HPP

#include "Enemy.hpp"
class Cute : public Enemy {
public:
	Cute(int health, int damage, std::string name);
	void play(CombatUnit* target);
	void pet(CombatUnit* target);
};

#endif // CUTE_HPP