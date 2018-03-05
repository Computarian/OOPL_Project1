#include "GameWorld.hpp"


GameWorld::GameWorld() {
	//Create new Player: Player(int health, int damage, std::string name);
	this->player_ = new Player(1000, 100, "Chappie");

	HealthPotion* healpotion0 = new HealthPotion();
	player_->AddItemToInventory(healpotion0);
	MasterBall* newBall = new MasterBall();
	player_->AddItemToInventory(newBall);
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
	if (currentRoom->hasEnemies()) {
		combatMenu(currentRoom);
	}
	currentRoom->getDescription();
	do {
		input = "";
		std::cout << "1. NORTH" << "  " << "2. SOUTH" << "     " << "3. EAST" << "   " << "4. WEST" << std::endl;
		std::cout << "5. SEARCH" << " " << "6. TAKE" << "      " << "7. OPEN" << std::endl;
		std::cout << "8. LOOK" << "   " << "9. INVENTORY" << " " << "10. STATS" << std::endl;
		std::getline(std::cin, input);

		// Navigation Block 1,2,3,4:  N,S,E,W
		if (input == "1" || input == "NORTH") {
			if (currentRoom->getNorth()) {
				//access which room is north of this room
				//std::cout << "I'd be going north but I'm a stub" << std::endl;
				displayMenu(currentRoom->getNorth());
			}
			else {
				std::cout << "There's northing there!" << std::endl;
			}
		}
		if (input == "2" || input == "SOUTH") {
			if (currentRoom->getSouth()) {
				displayMenu(currentRoom->getSouth());
			}
			else {
				std::cout << "I wish there was soumthing there!" << std::endl;
			}
		}
		if (input == "3" || input == "EAST") {
			if (currentRoom->getEast()) {
				displayMenu(currentRoom->getEast());
			}
			else {
				std::cout << "No easty way out" << std::endl;
			}

		}
		if (input == "4" || input == "WEST") {
			if (currentRoom->getWest()) {
				displayMenu(currentRoom->getWest());
			}
			else {
				std::cout << "A large wall blocks your way westward" << std::endl;
			}
		}
		if (input == "5") {
			//perform some kind of item, chest looking thing here too
			if (currentRoom->getItems().empty()) {
				std::cout << "There are no items left in here" << std::endl;
			}
			else {
				std::cout << "The room contains the following item(s)" << std::endl;
				for (int i = 0; i < currentRoom->getItems().size(); i++) {
					currentRoom->getItems()[i]->PrintData();
				}
			}
		}
		if (input == "6") {
			if (currentRoom->getItems().empty()) {
				std::cout << "There's nothing to take!" << std::endl;
			}
			else {
				for (int i = 0; i < currentRoom->getItems().size(); i++) {
					player_->AddItemToInventory(currentRoom->getItems()[i]);
					std::cout << player_->GetName() << " added " << currentRoom->getItems()[i]->GetName();
					std::cout << " to inventory!" << std::endl;
					currentRoom->removeItem(currentRoom->getItems()[i]);
				}
			}
		}
		if (input == "8") {
			currentRoom->getDescription();
		}
		if (input == "9") {
			if (player_->getInventory().empty()) {
				std::cout << "Inventory is empty!" << std::endl;
			} else {
				openInventory(currentRoom);
			}
		}
		if (input == "10") {
			this->player_->PrintStats();
		}
	} while (1);
}


// Inventory Menu, can be used during combat
void GameWorld::openInventory(Room* currentRoom) {
	std::string input;

	do {
		input = "";
		std::cout << "1. View Inventory" << std::endl;
		std::cout << "2. Use Item" << std::endl;
		std::cout << "q. quit" << std::endl;
		getline(std::cin, input);

		if (input == "1") {
			std::cout << player_->GetName() << "'s Inventory" << std::endl;
			this->player_->printInventory();
		}
		if (input == "2") {
			do {
				input = "";
				std::cout << "Select which item?" << std::endl;
				this->player_->printInventory();
				getline(std::cin, input);

				for (int i = 0; i < player_->getInventory().size(); i++) {
					if (input == player_->getInventory()[i]->GetName()) {
						player_->UseItem(player_->getInventory()[i], player_);
						player_->removeItemFromInventory(player_->getInventory()[i]);
					}
				}
			} while (input != "q" && !player_->getInventory().empty());
		}
	} while (input != "q");
}


// Used to select target during combat
/*
CombatUnit* selectTarget(Room* currentRoom) {

}
*/

// Displays combat menu when an enemy is encountered upon entering a room
void GameWorld::combatMenu(Room* currentRoom) {
	std::string input;

	for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
		std::cout << currentRoom->getEnemies()[i]->GetName() << " has appeared!" << std::endl;
	}
	//combat menu
	/*
	do {
		input = "";
		std::cout << "1. Attack" << std::endl;
		getline(std::cin, input);

		if (input == "1") {
			if (currentRoom->getEnemies().size() > 1) {
				do {
					input = "";
					std::cout << "Attack which enemy?" << std::endl;
					for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
						std::cout << currentRoom->getEnemies()[i]->GetName()<< std::endl;
					}
					getline(std::cin, input);
					for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
						if (input == currentRoom->getEnemies()[i]->GetName()) {
							std::cout << currentRoom->getEnemies()[i]->GetName() << " is the target!" << std::endl;
						}
					}
				} while (1);
			}
		}
	} while (1);
	*/
	
	//currentRoom->targetEnemy(currentRoom->getEnemies()[0])->PrintStats();
	while (currentRoom->hasEnemies()) {
		currentRoom->targetEnemy(currentRoom->getEnemies()[0]);
		if (player_->GetHealth() > 0) {
			player_->DealDamage(currentRoom->targetEnemy(currentRoom->getEnemies()[0]));
		}
		if (currentRoom->targetEnemy(currentRoom->getEnemies()[0])->GetHealth() < 1) {
			std::cout << currentRoom->targetEnemy(currentRoom->getEnemies()[0])->GetName() << " was defeated!" << std::endl;
			//delete currentRoom->targetEnemy();
			currentRoom->removeEnemy(currentRoom->targetEnemy(currentRoom->getEnemies()[0]));
		} else {
			currentRoom->targetEnemy(currentRoom->getEnemies()[0])->DealDamage(player_);
		}
	}
}
