#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Enemy.hpp"
#include "Item.hpp"
#include "Chest.hpp"

class Room {

public:
	Room();
	// Room constructors, construct room based off type, all rooms have pointers to N,S,E,W, descriptions
	// some rooms have treasures, monsters, or both
	void setRoomDoors(std::vector<Room*> doors);
	void getDescription();
	void setDescription(std::string description);

	void addItems(std::vector<Item*> items);
	std::vector<Item*> getItems();
	void removeItem(Item* item);

	void addChests(std::vector < Chest*> chests);
	std::vector<Chest*> getChests();
	void removeChest(Chest* chest);

	void addEnemies(std::vector<Enemy*> enemies);
	std::vector<Enemy*> getEnemies();
	void removeEnemy(CombatUnit* enemy);

	void setStory(std::string story);
	bool hasStory();
	std::string getStory();

	bool hasEnemies();
	Enemy* targetEnemy(Enemy* enemy);

	void printItems();
	void printChests();

	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();

private:
	std::string description_;
	std::vector<Item*> items_;
	std::vector<Chest*> chests_;
	std::vector<Enemy*> enemies_;
	Room* north_;
	Room* south_;
	Room* east_;
	Room* west_;
	std::string story_;
	
};

#endif //ROOM_HPP
