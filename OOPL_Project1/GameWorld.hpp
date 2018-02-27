#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

#include "Dungeon.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Item.hpp"

class GameWorld
{
public:
	GameWorld();
	void displayMenu(Room* currentRoom);
	void combatMenu(Room* currentRoom);
private:
	Player* player_;
};

#endif //GAMEWORLD_HPP

