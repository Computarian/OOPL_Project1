#include "Troll.hpp"



Troll::Troll(std::string name): Enemy(Troll::defaultHealth, Troll::defaultDamage, name){

}


Troll::~Troll(){

}


void Troll::makeMove(int move, CombatUnit* target) {
	if (move < 50) {
		DealDamage(target);
	}
	else {
		insult(target);
	}
	regen();
}


void Troll::regen() {
	std::cout << GetName() << " regen restores " << regen_health_ << " hp!" << std::endl;
	ModifyHealth(regen_health_);
}


void Troll::insult(CombatUnit* target) {
	std::cout << GetName() << " insults " << target->GetName() << " for " << insult_damage_ << " damage!" << std::endl;
	target->ModifyHealth(insult_damage_);
}
