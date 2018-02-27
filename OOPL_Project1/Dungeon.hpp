#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <vector>
#include "Room.hpp"
#include "Enemy.hpp"
#include "Mimic.hpp"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();
	Room* getStartRoom();
private:
	Room * start_room_;
};

#endif //DUNGEON_HPP