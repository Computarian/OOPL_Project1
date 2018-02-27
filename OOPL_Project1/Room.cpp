#include "Room.hpp"



Room::Room(){

}


Room::~Room() {

}


Room::Room(Room* north, Room* south, Room* east, Room* west, std::string description) {
	this->north_ = north;
	this->south_ = south;
	this->east_ = east;
	this->west_ = west;
	this->description_ = description;
}


void Room::getDescription() {
	std::cout << description_ << std::endl;
}


void Room::addEnemy(Enemy* enemy) {
	this->enemies_.push_back(enemy);
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

