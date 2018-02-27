#include "Enemy.hpp"

Enemy::Enemy(int health, int damage, std::string name) : CombatUnit(health, damage, name) {
	std::cout << "Enemy health: " << this->health<< " Enemy damage: " << this->damage << std::endl;
}
