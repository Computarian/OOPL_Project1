#ifndef ROOM_HPP
#define ROOM_HPP

#define NUM_DOORS 4

#include <string>
#include <iostream>
#include <vector>
#include "Enemy.hpp"
#include "Item.hpp"

class Room
{
public:
	Room();
	// Room constructors, construct room based off type, all rooms have pointers to N,S,E,W, descriptions
	// some rooms have treasures, monsters, or both
	void setRoomDoors(std::vector<Room*> doors);
	void getDescription();
	void setDescription(std::string description);
	void addEnemies(std::vector<Enemy*> enemies);
	void addItems(std::vector<Item*> items);
	std::vector<Item*> getItems();
	void removeItem(Item* item);
	bool hasEnemies();
	std::vector<Enemy*> getEnemies();
	Enemy* targetEnemy(Enemy* enemy);
	void removeEnemy(Enemy* enemy);

	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();

private:
	Room* north_;
	Room* south_;
	Room* east_;
	Room* west_;
	std::string description_;
	std::vector<Enemy*> enemies_;
	std::vector<Item*> items_;
};

#endif //ROOM_HPP
