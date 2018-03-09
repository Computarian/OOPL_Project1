#include "Robot.hpp"



Robot::Robot(int health, int damage, std::string name) : Enemy(health, damage, name){

}


Robot::~Robot() {

}


void Robot::rocketPunch(CombatUnit* target) {
	std::cout << GetName() << " rocket punches " << target->GetName() << " in the face!!" << std::endl;
	std::cout << rocket_punch_damage_ << " damage to " << target->GetName() << "!" << std::endl;
	RobotArm* robotArm = new RobotArm();
	target->ModifyHealth(rocket_punch_damage_);
	target->AddItemToInventory(robotArm);
	std::cout << target->GetName() << " retrieved a " << robotArm->GetName() << "!" << std::endl;
}


