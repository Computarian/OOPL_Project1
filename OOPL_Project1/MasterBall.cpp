#include "MasterBall.hpp"



MasterBall::MasterBall(): Item("Master Ball", "Use to capture any one enemy"){

}


void MasterBall::Effect(CombatUnit* target) {
	std::cout << target->GetName() << " was captured by the Master Ball!" << std::endl;
	MasterBallCapture* masterBallCapture = new MasterBallCapture(target);
	target->AddItemToInventory(masterBallCapture);
	target->ModifyHealth(target->GetHealth());
}
