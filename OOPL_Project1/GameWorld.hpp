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
	Enemy* selectTarget(Room* currentRoom);
	void combatTurn(Room* currentRoom, std::string move, CombatUnit* target);
	std::string magicMenu(Room* currentRoom);
private:
	Player * player_;
	//Room* current_room_;
	Room* prev_room_;
	// combat bool so player can only use one item per turn in combat (maybe something else)
	// once player commits to turn, then combat turns go through?
	bool take_turn;
	bool gameover_; //when player health is < 1
};

#endif //GAMEWORLD_HPP

