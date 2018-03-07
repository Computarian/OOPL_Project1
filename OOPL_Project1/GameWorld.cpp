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
		// break out navigation into it's own function? and other options
		if (input == "1" || input == "NORTH") {
			if (currentRoom->getNorth()) {
				prev_room_ = currentRoom;
				displayMenu(currentRoom->getNorth());
			}
			else {
				std::cout << "There's northing there!" << std::endl;
			}
		}
		if (input == "2" || input == "SOUTH") {
			if (currentRoom->getSouth()) {
				prev_room_ = currentRoom;
				displayMenu(currentRoom->getSouth());
			}
			else {
				std::cout << "I wish there was soumthing there!" << std::endl;
			}
		}
		if (input == "3" || input == "EAST") {
			if (currentRoom->getEast()) {
				prev_room_ = currentRoom;
				displayMenu(currentRoom->getEast());
			}
			else {
				std::cout << "No easty way out" << std::endl;
			}

		}
		if (input == "4" || input == "WEST") {
			if (currentRoom->getWest()) {
				prev_room_ = currentRoom;
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
			if (!currentRoom->getChests().empty()) {
				std::cout << "There's at least one treasure chest in this room!" << std::endl;
				for (int i = 0; i < currentRoom->getChests().size(); i++) {
					currentRoom->getChests()[i]->getName();
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
		if (input == "7") {
			if (currentRoom->getChests().empty()) {
				std::cout << "There are no chests in here" << std::endl;
			}
			else {
				
				for (int i = 0; i < currentRoom->getChests().size(); i++) {
					std::cout << player_->GetName() << " opens the "<<currentRoom->getChests()[i]->getName()<<" and it contains: " << std::endl;
					if(currentRoom->getChests()[i]->getEnemy()){
						std::cout<<currentRoom->getChests()[i]->getEnemy()->GetName() << " startles you!" << std::endl;
						// slightly messy way to work around targeting system being based off room enemies
						std::vector<Enemy*> mimic = currentRoom->getEnemies();
						mimic.push_back(currentRoom->getChests()[i]->getEnemy());
						currentRoom->addEnemies(mimic);
						currentRoom->getChests()[i]->setChestEnemy(nullptr);
						combatMenu(currentRoom);
					}
					for (int j = 0; j < currentRoom->getChests()[i]->getLoot().size(); j++) {
						player_->AddItemToInventory(currentRoom->getChests()[i]->getLoot()[j]);
						std::cout << player_->GetName() << " added " << currentRoom->getChests()[i]->getLoot()[j]->GetName();
						std::cout << " to inventory!" << std::endl;
						currentRoom->removeItem(currentRoom->getChests()[i]->getLoot()[j]);
					}
					currentRoom->removeChest(currentRoom->getChests()[i]);
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

	std::cout << player_->GetName() << "'s Inventory" << std::endl;
	this->player_->printInventory();

	do {
		input = "";
		std::cout << "1. View Inventory" << std::endl;
		std::cout << "2. Use Item" << std::endl;
		std::cout << "q. Exit Inventory" << std::endl;
		getline(std::cin, input);

		if (input == "1") {
			std::cout << player_->GetName() << "'s Inventory" << std::endl;
			this->player_->printInventory();
		}
		if (input == "2") {
			do {
				input = "";
				std::cout << "Select which item? Press q to exit" << std::endl;
				this->player_->printInventory();
				getline(std::cin, input);

				for (int i = 0; i < player_->getInventory().size(); i++) {
					if (input == player_->getInventory()[i]->GetName() || input == std::to_string(i + 1)) {
						player_->UseItem(player_->getInventory()[i], player_);
						player_->removeItemFromInventory(player_->getInventory()[i]);
						break;
					}
				}
			} while (input != "q" && !player_->getInventory().empty());
		}
	} while (input != "q");
}


// Displays combat menu when an enemy is encountered upon entering a room
void GameWorld::combatMenu(Room* currentRoom) {
	std::string input;
	std::string magicSpell;
	Enemy* target = nullptr;

	for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
		std::cout << currentRoom->getEnemies()[i]->GetName() << " has appeared!" << std::endl;
	}
	do {
		input = "";
		magicSpell = "";
		target = nullptr;

		this->player_->PrintStats();
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Magic" << std::endl;
		std::cout << "3. Inventory" << std::endl;
		std::cout << "4. Scan Enemies" << std::endl;
		std::cout << "5. Flee!" << std::endl;
		getline(std::cin, input);

		if (input == "1") {
			target = selectTarget(currentRoom);
			if (target) {
				combatTurn(currentRoom, "attack", target);
			}
		}
		if (input == "2") {
			magicSpell = magicMenu(currentRoom);
			if (magicSpell != "") {
				target = selectTarget(currentRoom);
				if (target) {
					combatTurn(currentRoom, magicSpell, target);
				}
			}
		}
		if (input == "3") {
			if (player_->getInventory().empty()) {
				std::cout << "Inventory is empty!" << std::endl;
			}
			else {
				openInventory(currentRoom);
			}
		}
		if (input == "4") {
			std::cout << "Enemy Stats" << std::endl;
			for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
				currentRoom->getEnemies()[i]->PrintStats();
			}
		}
		if (input == "5") {
			std::cout << "You run away like a coward while" << std::endl;
			for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
				std::cout<< currentRoom->getEnemies()[i]->GetName();
				std::cout << " laughs at you!" << std::endl;
			}
			displayMenu(prev_room_);
		}
		// Enemies take their turn
		for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
			currentRoom->getEnemies()[i]->makeMove("attack", player_);
			if (player_->GetHealth() < 1) {
				//end game from combat somehow
			}
		}
	} while (!currentRoom->getEnemies().empty());
}


// Used to select target during combat
Enemy* GameWorld::selectTarget(Room* currentRoom) {
	std::string input = "";

	do {
		std::cout << "Select which enemy? press q to go back" << std::endl;
		for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
			std::cout << i + 1 <<". " <<currentRoom->getEnemies()[i]->GetName() << std::endl;
		}
		getline(std::cin, input);

		// checks if player inputs monster's entire name or just presses the number key associated with it
		for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
			if (input == currentRoom->getEnemies()[i]->GetName() || input == std::to_string(i + 1)) {
				std::cout << currentRoom->getEnemies()[i]->GetName() << " is the target!" << std::endl;
				return currentRoom->getEnemies()[i];
			}
		}
	} while (input != "q");
	return nullptr;
}


void GameWorld::combatTurn(Room* currentRoom, std::string move, CombatUnit* target) {
	player_->makeMove(move, target);
	if (target->GetHealth() < 1) {
		std::cout << target->GetName() << " was defeated!" << std::endl;
		//delete currentRoom->targetEnemy();
		currentRoom->removeEnemy(target);
	}
}


std::string GameWorld::magicMenu(Room* currentRoom) {
	std::string input;

	do {
		input = "";
		std::cout << "1. Lightning Bolt!" << std::endl;
		std::cout << "q. Exit Magic Menu" << std::endl;
		getline(std::cin, input);

		if (input == "1") {
			return "bolt";
		}
	} while (input != "q");
	return "";
}