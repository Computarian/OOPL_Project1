#include "Mimic.hpp"


Mimic::Mimic(std::string name): Enemy(Mimic::defaultHealth, Mimic::defaultDamage, name) {
	//std::cout << "Mimic health: " << this->defaultHealth << " Mimic damage: " << this->defaultDamage << std::endl;
	this->has_mana_ = false;
}

