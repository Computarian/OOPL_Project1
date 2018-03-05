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
	void openInventory(Room* currentRoom);
	CombatUnit* selectTarget(Room* currentRoom);
	void combatMenu(Room* currentRoom);
	
private:
	Player * player_;

	// combat bool so player can only use one item per turn in combat (maybe something else)
	bool combat_;
};

#endif //GAMEWORLD_HPP

