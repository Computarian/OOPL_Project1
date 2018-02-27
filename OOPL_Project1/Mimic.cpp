#include "Mimic.hpp"


Mimic::Mimic(): Enemy(this->defaultHealth, this->defaultDamage, "Mimic") {
	std::cout << "Mimic health: " << this->defaultHealth << " Mimic damage: " << this->defaultDamage << std::endl;
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