#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#define DUNGEON_SIZE 4

#include <vector>
#include "Room.hpp"

#include "Enemy.hpp"
#include "Mimic.hpp"
#include "Chinchilla.hpp"

#include "Item.hpp"
#include "HealthPotion.hpp"
#include "MasterBall.hpp"

class Dungeon
{
public:
	Dungeon();
	Room* getStartRoom();
	std::vector<Room*> getDungeon();

	void generateRooms();
	void generateDoors();
	void generateDescriptions();
	void generateItems();
	void generateEnemies();

	void doorTable();
	void descriptionTable();
	void itemTable();
	void enemyTable();

private:
	std::vector<Room*> dungeon_;
	std::vector < std::vector<Room*>> doors_;
	std::vector<std::string> descriptions_;
	std::vector<std::vector<Item*>> items_;
	std::vector < std::vector<Enemy*>> enemies_;
};

#endif //DUNGEON_HPP