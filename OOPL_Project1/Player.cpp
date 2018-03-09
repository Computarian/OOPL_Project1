#include "Player.hpp"



Player::Player(int health, int damage, std::string name): CombatUnit(health, damage, mana_, name) {
	setMana(true);
}


Player::~Player() {

}


void Player::makeMove(int move, CombatUnit* target){
	//CombatUnit::makeMove(move, target);
	if (move == 1) {
		DealDamage(target);
	}
	if (move == 2) {
		boltMagic(target);
	}
	if (move == 3) {
		cureMagic(target);
	}
	if (move == 8) {
		std::cout << GetName() << " scanned the enemies stats!" << std::endl;
	}
	if (move == 9) {
		std::cout << GetName()<<" used an item, and must wait their turn again!" << std::endl;
	}
}


void Player::boltMagic(CombatUnit* target) {

	// bolt logic
	// maybe add if enemy is a robot do more damage?
	if (mana_ >= bolt_cost_) {
		std::cout << GetName() << " shoots a lightning bolt at " << target->GetName() << " for " << bolt_damage_ << " damage!" << std::endl;
		target->ModifyHealth(bolt_damage_);
		ModifyMana(bolt_cost_);
	}
	else {
		std::cout << GetName() << " doesnt have enough mana and the spell fizzles,\n";
		std::cout<<"doing no damage to "<<target->GetName() <<"!"<< std::endl;
	}
}


void Player::cureMagic(CombatUnit* target) {
	// cure logic
	if (mana_ >= cure_cost_) {
		std::cout << GetName() << " casts cure on " << target->GetName() << " and restores " << cure_heal_ << " health!" << std::endl;
		target->ModifyHealth(-(cure_heal_));
		ModifyMana(cure_cost_);
	}
	else {
		std::cout << GetName() << " doesnt have enough mana and the spell fizzles,\n";
		std::cout << "doing no healing to " << target->GetName() << "!" << std::endl;
	}
}