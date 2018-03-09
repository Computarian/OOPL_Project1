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
	
	void combatMenu(Room* currentRoom);
	CombatUnit* selectTarget(Room* currentRoom);
	void combatTurn(Room* currentRoom, int move, CombatUnit* target);
	int magicMenu(Room* currentRoom);
	Item* combatInventory(Room* currentRoom);
private:
	Player * player_;
	//Room* current_room_;
	Room* prev_room_;
	// moves
	int use_attack_ = 1;
	int use_bolt_magic_ = 2;
	int use_cure_magic_ = 3;
	int use_scan_ = 8;
	int use_item_ = 9;
};

#endif //GAMEWORLD_HPP

