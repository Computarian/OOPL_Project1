#include "Mimic.hpp"


Mimic::Mimic(std::string name): Enemy(Mimic::defaultHealth, Mimic::defaultDamage, name) {
	std::cout << "Mimic health: " << this->defaultHealth << " Mimic damage: " << this->defaultDamage << std::endl;
}


Mimic::Mimic(int health, int damage): Enemy(health, damage, "Mimic"){

}


/*
Mimic::~Mimic(){

}
*/

/*
void Mimic::Spawn(Room* room) {
	room->addEnemy(new Mimic(this->defaultHealth, this->defaultDamage));
}
*/