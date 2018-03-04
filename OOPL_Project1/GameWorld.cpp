#include "GameWorld.hpp"


GameWorld::GameWorld(){
	//Create new Player: Player(int health, int damage, std::string name);
	this->player_ = new Player(100, 100, "Chappie");

	Dungeon* newDungeon = new Dungeon();
	displayMenu(newDungeon->getStartRoom());
}


void GameWorld::displayMenu(Room* currentRoom) {
	std::string input;
	/*
	Dungeon navigation
	North/South/East/West
	Dungeon interaction
	{SEARCH, TAKE, OPEN, LOOK, INVENTORY}
	*/
	currentRoom->getDescription();
	if (currentRoom->hasEnemies()) {
		combatMenu(currentRoom);
	}
	do {
		input = "";
		std::cout << "1. NORTH" << "  " << "2. SOUTH" << "     " << "3. EAST" <<"   "<< "4. WEST" << std::endl;
		std::cout << "5. SEARCH" << " " << "6. TAKE" << "      " << "7. OPEN" << std::endl;
		std::cout<<"8. LOOK"<<"   "<< "9. INVENTORY" <<" " <<"10. STATS"<< std::endl;
		std::getline(std::cin, input);

		// Navigation Block 1,2,3,4:  N,S,E,W
		if (input == "1" || input == "NORTH") {
			if (currentRoom->getNorth()) {
				//access which room is north of this room
				//std::cout << "I'd be going north but I'm a stub" << std::endl;
				displayMenu(currentRoom->getNorth());	
			}else {
				std::cout << "There's northing there!" << std::endl;
			}
		}
		if (input == "2" || input == "SOUTH") {
			if (currentRoom->getSouth()) {
				displayMenu(currentRoom->getSouth());
			}else {
				std::cout << "I wish there was soumthing there!" << std::endl;
			}
		}
		if (input == "3" || input == "EAST") {
			if (currentRoom->getEast()) {
				displayMenu(currentRoom->getEast());
			}else {
				std::cout << "No easty way out" << std::endl;
			}

		}
		if (input == "4" || input == "WEST") {
			if (currentRoom->getWest()) {
				displayMenu(currentRoom->getWest());
			}else {
				std::cout << "A large wall blocks your way westward" << std::endl;
			}
		}
		if (input == "8") {
			currentRoom->getDescription();
			//perform some kind of item, chest looking thing here too
		}
		if (input == "10") {
			this->player_->PrintStats();
		}
	} while (1);
}

void GameWorld::combatMenu(Room* currentRoom) {
	std::string input;

	//combat menu
	/*
	do {
		input = "";
	} while (1);
	*/
	currentRoom->targetEnemy()->PrintStats();
	while (currentRoom->hasEnemies()) {
		if (player_->GetHealth() > 0) {
			player_->DealDamage(currentRoom->targetEnemy());
		}
		if (currentRoom->targetEnemy()->GetHealth() < 1) {
			std::cout << "The " << currentRoom->targetEnemy()->GetName() << " was defeated!" << std::endl;
			delete currentRoom->targetEnemy();
			currentRoom->removeEnemy(currentRoom->targetEnemy());

		} else {
			currentRoom->targetEnemy()->DealDamage(player_);
		}
		currentRoom->targetEnemy()->PrintStats();
		break;
	}
}
