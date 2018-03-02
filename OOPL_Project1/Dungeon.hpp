#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#define DUNGEON_SIZE 20

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
private:
	Room * start_room_;
	std::vector<Room*> dungeon_;
};

#endif //DUNGEON_HPP