#include "Player.hpp"



Player::Player(int health, int damage, std::string name): CombatUnit(health, damage, mana_, name) {
	setMana(true);
}


void Player::makeMove(int move, CombatUnit* target){
	//CombatUnit::makeMove(move, target);
	if (move == 1) {
		DealDamage(target);
	}
	if (move == 2) {
		boltMagic(target);
	}
	if (move == 8) {
		std::cout << GetName() << " scanned the enemies stats!" << std::endl;
	}
	if (move == 9) {
		std::cout << GetName()<<" used an item, and must wait their turn again!" << std::endl;
	}
}


void Player::boltMagic(CombatUnit* target) {
	// bolt spell stats
	int boltCost = 50;
	int boltDamage = 125;

	// bolt logic
	// maybe add if enemy is a robot do more damage?
	if (mana_ >= 50) {
		std::cout << GetName() << " shoots a lightning bolt at " << target->GetName() << " for " << boltDamage << " damage!" << std::endl;
		target->ModifyHealth(boltDamage);
		ModifyMana(boltCost);
	}
	else {
		std::cout << GetName() << " doesnt have enough mana and the spell fizzles,\n";
		std::cout<<"doing no damage to "<<target->GetName() <<"!"<< std::endl;
	}
}