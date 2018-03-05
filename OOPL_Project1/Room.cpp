#include "Room.hpp"



Room::Room(){
	this->north_ = nullptr;
	this->south_ = nullptr;
	this->east_ = nullptr;
	this->west_ = nullptr;
}


void Room::setRoomDoors(std::vector<Room*> doors) {
	this->north_ = doors[0];
	this->south_ = doors[1];
	this->east_ = doors[2];
	this->west_ = doors[3];
}


void Room::getDescription() {
	std::cout << description_ << std::endl;
}


void Room::setDescription(std::string description) {
	this->description_ = description;
}


void Room::addEnemies(std::vector<Enemy*> enemies){
	this->enemies_ = enemies;
}


void Room::addItems(std::vector<Item*> items) {
	this->items_ = items;
}


std::vector<Item*> Room::getItems() {
	return this->items_;
}


void Room::removeItem(Item* item) {
	//delete enemy;
	for (int i = 0; i < items_.size(); i++) {
		if (item == items_[i]) {
			// delete item
			//delete item;
			// remove pointer from vector/list
			items_.erase(items_.begin() + i);
		}
	}
}


bool Room::hasEnemies() {
	if (enemies_.empty()) {
		return false;
	}
	return true;
}


std::vector<Enemy*> Room::getEnemies() {
	return this->enemies_;
}


Enemy* Room::targetEnemy(Enemy * enemy) {
	for (int i = 0; i < enemies_.size(); i++) {
		if (enemy == enemies_[i]) {
			return enemies_[i];
		}
	}
}


void Room::removeEnemy(Enemy* enemy) {
	//delete enemy;
	for (int i = 0; i < enemies_.size(); i++) {
		if (enemy == enemies_[i]) {
			// delete enemy
			delete enemy;
			// remove pointer fromr vector/list
			enemies_.erase(enemies_.begin() + i);
		}
	}
}


Room* Room::getNorth() {
	return this->north_;
}


Room* Room::getSouth() {
	return this->south_;
}


Room* Room::getEast() {
	return this->east_;
}


Room* Room::getWest() {
	return this->west_;
}