#include "Chinchilla.hpp"



Chinchilla::Chinchilla(std::string name): Enemy(Chinchilla::defaultHealth, Chinchilla::defaultDamage, name) {

}


void Chinchilla::makeMove(int move, CombatUnit* target) {
	//CombatUnit::makeMove(move, target);
	if (move < 50) {
		DealDamage(target);
	}
	else if (move >= 50 && move < 100) {
		cute(target);
	}
	else {
		bite(target);
	}
}


void Chinchilla::bite(CombatUnit* target) {
	std::cout << GetName() << " performs a vicious bite on " << target->GetName() << " for " << biteDamage << " damage!" << std::endl;
	target->ModifyHealth(biteDamage);
}


void Chinchilla::cute(CombatUnit* target) {
	std::cout << GetName() << " plays with " << target->GetName() << "!" << std::endl;
}


