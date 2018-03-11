#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

#include "Dungeon.hpp"
#include "Player.hpp"

class GameWorld {
public:
	GameWorld();
	void displayMenu();
	void openInventory();
	
	//Combat encounter menus
	void combatMenu();
	CombatUnit* selectTarget();
	void combatTurn( int move, CombatUnit* target);
	int magicMenu();
	Item* combatInventory();

	void gameEndings(std::string ending);

private:
	Player * player_;
	Dungeon* new_dungeon_;
	Room* currentRoom;
	Room* prev_room_;

	// player move selection
	int use_attack_ = 1;
	int use_bolt_magic_ = 2;
	int use_cure_magic_ = 3;
	int use_scan_ = 8;
	int use_item_ = 9;
	bool game_over_;
};

#endif //GAMEWORLD_HPP

