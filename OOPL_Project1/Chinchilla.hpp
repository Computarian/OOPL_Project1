#ifndef CHINCHILLA_HPP
#define CHINCHILLA_HPP

#include "Enemy.hpp"

class Chinchilla :
	public Enemy
{
public:
	Chinchilla(std::string name);
	void bite(CombatUnit* target);

private:
	const static int defaultHealth = 10;
	const static int defaultDamage = 5;
	const static int biteDamage = 15;
};

#endif //CHINCHILLA_HPPs
