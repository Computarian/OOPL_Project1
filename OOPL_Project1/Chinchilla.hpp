#ifndef CHINCHILLA_HPP
#define CHINCHILLA_HPP

#include "Enemy.hpp"

class Chinchilla :
	public Enemy
{
public:
	Chinchilla(std::string name);
private:
	const static int defaultHealth = 10;
	const static int defaultDamage = 5;
};

#endif //CHINCHILLA_HPPs
