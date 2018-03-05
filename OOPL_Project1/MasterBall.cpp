#include "MasterBall.hpp"



MasterBall::MasterBall(): Item("Master Ball", "Use to capture any one enemy"){
	//Chinchilla* charlie = new Chinchilla("Charlie the Chincilla");
	//this->captured_enemy_ = charlie;
	//viewCapturedEnemy();
}


void MasterBall::Effect(CombatUnit* target) {
	target->ModifyHealth(-(target->GetHealth()));
	this->captured_enemy_ = target;
}


void MasterBall::viewCapturedEnemy(){
	SetDescription(captured_enemy_->GetName() + " gives you an angry glare");
}


