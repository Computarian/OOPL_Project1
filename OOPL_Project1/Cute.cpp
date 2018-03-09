#include "Cute.hpp"



Cute::Cute(int health, int damage, std::string name) : Enemy(health, damage, name){

}


Cute::~Cute() {

}


void Cute::play(CombatUnit* target) {
	std::cout << GetName() << " plays with " << target->GetName() << "!" << std::endl;
}


void Cute::pet(CombatUnit* target) {
	std::cout << target->GetName() << " pets " << GetName() << "!" << std::endl;
}
