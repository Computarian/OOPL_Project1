#include "Chinchilla.hpp"



Chinchilla::Chinchilla(std::string name): Enemy(Chinchilla::defaultHealth, Chinchilla::defaultDamage, name) {

}


void Chinchilla::bite(CombatUnit* target) {
	std::cout << GetName() << " performs a vicious bite on " << target << " for " << biteDamage << " damage!" << std::endl;
	target->ModifyHealth(biteDamage);
}


