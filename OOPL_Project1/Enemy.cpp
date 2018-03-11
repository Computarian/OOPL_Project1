#include "Enemy.hpp"

Enemy::Enemy(int health, int damage, std::string name) : CombatUnit(health, damage, name) {
	//No enemies use Mana
	this->has_mana_ = false;
}


Enemy::~Enemy() {

}