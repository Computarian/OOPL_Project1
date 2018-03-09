#include "Bulbasaur.hpp"



Bulbasaur::Bulbasaur(std::string name): Cute(Bulbasaur::defaultHealth, Bulbasaur::defaultDamage, name){

}


Bulbasaur::~Bulbasaur(){

}


void Bulbasaur::makeMove(int move, CombatUnit* target) {
	if (move < 25) {
		tackle(target);
		DealDamage(target);
	}
	else if (move >= 25 && move < 45) {
		growl(target);
	}
	else if (move >= 45 && move < 65) {
		leechSeed(target);
	}
	else if (move >= 65 && move < 75){
		vineWhip(target);
	}
	else if (move >= 75 && move < 85) {
		play(target);
	}
	else {
		pet(target);
	}
}


void Bulbasaur::tackle(CombatUnit* target) {
	std::cout << GetName() << " uses Tackle!" << std::endl;
	std::cout << defaultDamage << " damage to " << target->GetName() << "!" << std::endl;
}


void Bulbasaur::growl(CombatUnit* target) {
	std::cout << GetName() << " growls!" << std::endl;
	std::cout << "It has no effect on " << target->GetName() << "!" << std::endl;
}


void Bulbasaur::leechSeed(CombatUnit* target) {
	std::cout << GetName() << " uses Leech Seed!" << std::endl;
	std::cout << GetName() << " absorbs " << leech_seed_damage_ << " hp from " << target->GetName() << "!" << std::endl;
	ModifyHealth(-(leech_seed_damage_));
	target->ModifyHealth(leech_seed_damage_);
}


void Bulbasaur::vineWhip(CombatUnit* target) {
	std::cout << GetName() << " uses Vine Whip!" << std::endl;
	std::cout << "It's super effective!" << std::endl;
	std::cout << vine_whip_damage_ << " damage to " << target->GetName() << "!" << std::endl;
}
