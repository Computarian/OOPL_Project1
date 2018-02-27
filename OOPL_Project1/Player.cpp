#include "Player.hpp"

Player::Player(int health, int damage, std::string name) : CombatUnit(health, damage, name) {

}

void Player::AddItemToInventory(Item* item) {
	this->inventory.push_back(item);
}
