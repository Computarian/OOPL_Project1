#ifndef MIMIC_HPP
#define MIMIC_HPP

#include "Enemy.hpp"
//#include "GameWorld.hpp"

class Mimic: public Enemy {
public:
	Mimic(std::string name);
	Mimic(int health, int damage);
	//~Mimic();
	//void Spawn(Dungeon* dungeon);
private:
	const static int defaultHealth = 200;
	const static int defaultDamage = 50;
};

#endif //MIMIC_HPP