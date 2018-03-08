#include "MasterBallCapture.hpp"



MasterBallCapture::MasterBallCapture(CombatUnit* target ): Item("Master Ball (Captured Enemy)", target->GetName() + " gives you an angry glare") {
	this->captured_enemy_ = target->GetName();
}


void MasterBallCapture::Effect(CombatUnit* target) {
	std::cout << target->GetName() << " views " << captured_enemy_ << " inside the Master Ball!" << std::endl;
}

