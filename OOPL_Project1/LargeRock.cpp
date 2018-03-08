#include "LargeRock.hpp"



LargeRock::LargeRock(std::string name): Enemy(LargeRock::defaulthealth, LargeRock::defaultDamage, name){

}

void LargeRock::makeMove(int move, CombatUnit* target) {
	if (GetHealth() < default_health_ / 4) {
		std::cout << GetName() << " suddently self destructs!" << std::endl;
		std::cout << "The rocks strike " << target->GetName() << " for " << self_destruct_damage_ << "!" << std::endl;
		ModifyHealth(GetHealth());
		target->ModifyHealth(self_destruct_damage_);
	}
	if (move < 10) {
		std::cout << target->GetName() << " punches the large rock and hurts their hand for " << punch_rock_damage_ << " damage!" << std::endl;
		target->ModifyHealth(punch_rock_damage_);
	}
	else if (move >= 10 && move < 50) {
		std::cout << "It's a big rock, what do you think is going to happen?" << std::endl;
	}
	else if (move >= 50 && move < 75) {
		std::cout << target->GetName() << " whistles a catchy tune!\n...unfortunately this is text adventure, so you can't hear it. :(" << std::endl;
	}
	else {
		std::cout<<"Some cracks appear in the rock..." << std::endl;
		std::cout << GetName() << " crumbles slightly for " << rock_crack_damage_ << " damage!" << std::endl;
		ModifyHealth(rock_crack_damage_);
	}
}
