#include "Mimic.hpp"



Mimic::Mimic(std::string name): Enemy(Mimic::defaultHealth, Mimic::defaultDamage, name) {
	
}


Mimic::~Mimic() {

}


void Mimic::makeMove(int move, CombatUnit* target) {
	//CombatUnit::makeMove(move, target);
	if (move < 50) {
		DealDamage(target);
	}
	if (move >= 51 && move < 90) {
		shootCan(target);
	}
	else {
		chomp(target);
	}
}


void Mimic::shootCan(CombatUnit* target) {
	ManaPotion* shootCan = new ManaPotion();
	std::cout << GetName() << " fires a " << shootCan->GetName() << " at " << target->GetName() << " for " << shoot_can_damage_ << " damage!" << std::endl;
	target->ModifyHealth(shoot_can_damage_);
	target->AddItemToInventory(shootCan);
	std::cout << target->GetName() << " retrieved a " << shootCan->GetName() << "!" << std::endl;
}


void Mimic::chomp(CombatUnit* target) {
	std::cout << GetName() << " shrieks and then chomps on " << target->GetName() << " for " << chomp_damage_ << " damage!" << std::endl;
	target->ModifyHealth(chomp_damage_);
}
