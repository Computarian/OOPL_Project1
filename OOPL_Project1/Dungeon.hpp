#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#define DUNGEON_SIZE 20

#include "Room.hpp"

#include "Item.hpp"
#include "HealthPotion.hpp"
#include "MasterBall.hpp"
#include "ManaPotion.hpp"
#include "BitCoin.hpp"
#include "Chest.hpp"

#include "Enemy.hpp"
#include "Mimic.hpp"
#include "Chinchilla.hpp"
#include "ClumsyRobot.hpp"
#include "LargeRock.hpp"
#include "NAO.hpp"
#include "Bulbasaur.hpp"
#include "Troll.hpp"

class Dungeon {
public:
	Dungeon();
	Room* getStartRoom();
	bool endRoom(Room *currentRoom);
	std::vector<Room*> getDungeon();

	//generates Dungeon contents
	void generateRooms();
	void generateDoors();
	void generateDescriptions();
	void generateItems();
	void generateChests();
	void generateEnemies();
	void generateStory();

	//tables to store Dungeon content
	void doorTable();
	void descriptionTable();
	void itemTable();
	void chestTable();
	void enemyTable();
	void storyTable();

private:
	std::vector<Room*> dungeon_;
	std::vector < std::vector<Room*>> doors_;
	std::vector<std::string> descriptions_;
	std::vector<std::vector<Item*>> items_;
	std::vector < std::vector<Chest*>> chests_;
	std::vector < std::vector<Enemy*>> enemies_;
	std::vector<std::string> story_;
};

#endif //DUNGEON_HPP