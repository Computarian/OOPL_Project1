#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Enemy.hpp"
#include "Item.hpp"

class Room
{
public:
	Room();
	~Room();
	// Room constructors, construct room based off type, all rooms have pointers to N,S,E,W, descriptions
	// some rooms have treasures, monsters, or both
	Room(Room* north, Room* south, Room* east, Room* west, std::string description);
	void getDescription();
	void addEnemy(Enemy* enemy);
	void addItem(Item* item);
	bool hasEnemies();
	Enemy* targetEnemy();
	void removeEnemy(Enemy* enemy);
	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();

	void setNorth(Room* north);
	void setSouth(Room* south);
	void setEast(Room* east);
	void setWest(Room* west);
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
