#ifndef MIMIC_HPP
#define MIMIC_HPP

#include "Enemy.hpp"
//#include "GameWorld.hpp"

class Mimic: public Enemy {
public:
	Mimic();
	//~Mimic();
	//void Spawn(Dungeon* dungeon);
private:
	const int defaultHealth = 200;
	const int defaultDamage = 50;
};

#endif //MIMIC_HPP