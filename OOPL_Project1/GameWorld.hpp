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
	// combat bool so player can only use one item per turn in combat (maybe something else)
	// once player commits to turn, then combat turns go through?
	bool take_turn;
	// moves
	int use_attack_ = 1;
	int use_bolt_magic_ = 2;
	int use_scan_ = 8;
	int use_item_ = 9;
};

#endif //GAMEWORLD_HPP

