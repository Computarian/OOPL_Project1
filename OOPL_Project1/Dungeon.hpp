#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#define DUNGEON_SIZE 3

#include <vector>
#include "Room.hpp"
#include "Enemy.hpp"
#include "Mimic.hpp"
#include "Item.hpp"
#include "HealthPotion.hpp"

class Dungeon
{
public:
	Dungeon();
	Room* getStartRoom();
	void generateRooms();
	void generateDoors();
	void generateDescriptions();
	void generateItems();
	void generateEnemies();
	void roomTables();
	void enemyTable();
	void itemTable();
private:
	Room * start_room_;
	std::vector<Room*> dungeon_;
	std::vector < std::vector<Room*>> doors_;
	std::vector<std::string> descriptions_;
	std::vector<std::vector<Item*>> items_;
	std::vector < std::vector<Enemy*>> enemies_;
};

#endif //DUNGEON_HPP