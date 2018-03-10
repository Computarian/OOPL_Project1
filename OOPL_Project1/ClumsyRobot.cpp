#include "ClumsyRobot.hpp"



ClumsyRobot::ClumsyRobot(std::string name): Robot(ClumsyRobot::defaultHealth, ClumsyRobot::defaultDamage, name){
	AddItemToInventory(new HamSandwich());
	AddItemToInventory(new HamSandwich());
	AddItemToInventory(new HamSandwich());
}


ClumsyRobot::~ClumsyRobot() {
	std::cout << GetName() << " explodes!" << std::endl;
	std::cout << "BOOOOOOOOM!!" << std::endl;
	std::cout << "............" << std::endl;
	std::cout << "After the dust settles, a part of the wall was damaged by the explosion,\n"
		"revealing an elevator leading to the Vault!" << std::endl;
}


void ClumsyRobot::makeMove(int move, CombatUnit* target) {
	if (move < 10) {
		bandage();
	}
	else if (move >= 10 && move < 20) {
		clean();
	}
	else if (move >= 20 && move < 30) {
		reeling();
	}
	else if (move >= 30 && move < 40) {
		gear();
	}
	else if (move >= 40 && move < 50){
		wobbly();
	}
	else if (move >= 50 && move < 60) {
		battery();
	}
	else if (move >= 60 && move < 65) {
		missile(target);
	}
	else if (move >= 65 && move < 70) {
		beam(target);
	}
	else if (move >= 70 && move < 75) {
		sandwich();
	}
	else if(move >= 75 && move < 85){
		DealDamage(target);
	}
	else {
		rocketPunch(target);
	}
}


void ClumsyRobot::bandage() {
	std::cout << GetName() << " re-applied a bandage!" << std::endl;
}


void ClumsyRobot::clean(){
	std::cout << GetName() << " cleaned the area!" << std::endl;
}


void ClumsyRobot::reeling() {
	std::cout << GetName() << " is reeling."<<std::endl;
}


void ClumsyRobot::gear() {
	std::cout << GetName() << " lost a gear and some bolts." << std::endl;
}


void ClumsyRobot::wobbly() {
	std::cout << GetName() << " is wobbly!" << std::endl;
}


void ClumsyRobot::battery() {
	std::cout << GetName() << " wants to go and get a battery." << std::endl;
}


void ClumsyRobot::missile(CombatUnit* target) {
	std::cout << GetName() << " fired a missile, making itself dizzy!" << std::endl;
	std::cout << missile_damage_ << " damage to " << target->GetName() << "!" << std::endl;
	target->ModifyHealth(300);
}


void ClumsyRobot::beam(CombatUnit* target) {
	std::cout << GetName() << " stumbled, but fired a strange beam." << std::endl;
	std::cout << beam_damage_ << " damage to " << target->GetName() << "!" << std::endl;
}


void ClumsyRobot::sandwich() {
	if (inventory_.empty()) {
		std::cout << GetName() << " reaches into it's lunch bag for another sandwich, but it's empty!" << std::endl;
	}
	else {
		UseItem(inventory_.front(), this);
		removeItemFromInventory(inventory_.front());
		std::cout << GetName() << " hp is maxed out!" << std::endl;
	}
}
