#include "Chinchilla.hpp"



Chinchilla::Chinchilla(std::string name): Cute(Chinchilla::defaultHealth, Chinchilla::defaultDamage, name) {

}


void Chinchilla::makeMove(int move, CombatUnit* target) {
	//CombatUnit::makeMove(move, target);
	if (move < 25) {
		DealDamage(target);
	}
	else if (move >= 25 && move < 50) {
		play(target);
	}
	else if (move >= 50 && move < 100) {
		pet(target);
	}
	else {
		bite(target);
	}
}


void Chinchilla::bite(CombatUnit* target) {
	std::cout << GetName() << " performs a vicious bite on " << target->GetName() << " for " << biteDamage << " damage!" << std::endl;
	target->ModifyHealth(biteDamage);
}

