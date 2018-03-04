#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#define DUNGEON_SIZE 2
#define NUM_DOORS 4

#include <vector>
#include "Room.hpp"
#include "Enemy.hpp"
#include "Mimic.hpp"

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
private:
	Room * start_room_;
	std::vector<Room*> dungeon_;
	std::vector < std::vector<Room*>> doors_;
	std::vector<std::string> descriptions_;
	std::vector<std::vector<Item*>> items_;
	std::vector < std::vector<Enemy*>> enemies_;
};

#endif //DUNGEON_HPP