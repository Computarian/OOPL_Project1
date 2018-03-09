#include "NAO.hpp"



NAO::NAO(std::string name) : Robot(NAO::defaultHealth, NAO::defaultDamage, name) {

}


NAO::~NAO(){

}


void NAO::makeMove(int move, CombatUnit* target) {
	if (move < 15) {
		fallOver(target);
	}
	else if (move >= 15 && move < 30) {
		dropCan(target);
	}
	else if (move >= 30 && move < 45){
		headHurts(target);
	}
	else if (move >= 50 && move < 65) {
		slipped(target);
	}
	else if (move >= 70 && move < 80) {
		dab(target);
	}
	else if (move >= 80 && move < 90) {
		rocketPunch(target);
	}
	else
	{
		DealDamage(target);
	}
}


void NAO::fallOver(CombatUnit* target) {
	std::cout << GetName() << " falls on " << target->GetName() << " for " << fall_over_damage_ << " damage!" << std::endl;
	target->ModifyHealth(fall_over_damage_);
}


void NAO::dropCan(CombatUnit* target) {
	HealthPotion* naoCan = new HealthPotion();
	std::cout << GetName() << " carefully drops a " << naoCan->GetName() << " and " << target->GetName() << " picks it up!" << std::endl;
	target->AddItemToInventory(naoCan);
}


void NAO::headHurts(CombatUnit* target) {
	std::cout << GetName() << " says: My head hurts" << std::endl;
}


void NAO::slipped(CombatUnit* target) {
	std::cout << GetName() << " says: Whoops! I slipped!" << std::endl;
	std::cout << GetName() << " slips and collides into " << target->GetName() << " for " << slipped_damage_ << " damage!" << std::endl;
	target->ModifyHealth(slipped_damage_);
}


void NAO::dab(CombatUnit* target) {
	std::cout<<GetName()<<" does a dab!"<<std::endl;
}