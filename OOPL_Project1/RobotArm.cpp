#include "RobotArm.hpp"



RobotArm::RobotArm(): Item("Robot Arm", "Still smells of burnt rocket fuel..."){

}


void RobotArm::Effect(CombatUnit* target){
	target->ModifyHealth(25);
	std::cout << "The Robot Arm hits " << target->GetName() << " right in the face!" << std::endl;
}

