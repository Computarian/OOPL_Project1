#ifndef MIMIC_HPP
#define MIMIC_HPP

#include "Enemy.hpp"

class Mimic: public Enemy {
public:
	Mimic(std::string name);
private:
	const static int defaultHealth = 100;
	const static int defaultDamage = 50;
};

#endif //MIMIC_HPP