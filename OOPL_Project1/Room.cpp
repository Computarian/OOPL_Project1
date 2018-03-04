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


void Room::addItem(Item* item) {
	this->items_.push_back(item);
}


bool Room::hasEnemies() {
	if (enemies_.empty()) {
		return false;
	}
	return true;
}


Enemy* Room::targetEnemy() {
	return this->enemies_[0];
}


void Room::removeEnemy(Enemy* enemy) {
	//delete enemy;
	enemies_.erase(enemies_.begin());
	// delete enemy
	// remove pointer fromr vector/list
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


void Room::setNorth(Room* north) {
	this->north_ = north;
}


void Room::setSouth(Room* south) {
	this->south_ = south;
}


void Room::setEast(Room* east) {
	this->east_ = east;
}


void Room::setWest(Room* west) {
	this->west_ = west;
}

