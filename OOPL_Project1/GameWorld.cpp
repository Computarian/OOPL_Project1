#include "GameWorld.hpp"


GameWorld::GameWorld() {
	std::string ending;
	std::string playerName;

	do {
		playerName = "";
		std::cout << "Please name the player character: ";
		getline(std::cin, playerName);
	} while (playerName.length() < 1);

	//Create new Player: Player(int health, int damage, std::string name);
	this->player_ = new Player(1000, 100, playerName);
	game_over_ = false;

	// Initial Inventory
	player_->AddItemToInventory(new HealthPotion());
	player_->AddItemToInventory(new BitCoin());

	// Creating dungeon
	new_dungeon_ = new Dungeon();
	currentRoom = new_dungeon_->getStartRoom();
	displayMenu();

	// Deciding on an ending
	if (player_->GetHealth() < 1) {
		ending = "death";
	} else {
		ending = "vault";
	}
	gameEndings(ending);
}


void GameWorld::displayMenu() {
	std::string input;

	// Shows the intro story for the room if there is one
	if (currentRoom->hasStory()) {
		std::cout << currentRoom->getStory();
		currentRoom->setStory("");
	}
	// Initiates enemy encounter in room if there are any
	if (currentRoom->hasEnemies()) {
		combatMenu();
	}
	// Bool that checks if the current room is the endgame room, ends the game if so
	if (new_dungeon_->endRoom(currentRoom)) {
		game_over_ = true;
	}
	// Gets the room description if the player hasn't hit a game over state from combat
	if (!game_over_) {
		currentRoom->getDescription();
	}
	// Displays them main exploration menu to the player upon entering a room
	while (!game_over_){
		input = "";

		std::cout << "1. NORTH" << "  " << "2. SOUTH" << "     " << "3. EAST" << "   " << "4. WEST" << std::endl;
		std::cout << "5. SEARCH" << " " << "6. TAKE" << "      " << "7. OPEN" << std::endl;
		std::cout << "8. LOOK" << "   " << "9. INVENTORY" << " " << "10. STATS" << std::endl;
		std::getline(std::cin, input);

		// Navigation Block 1,2,3,4:  N,S,E,W
		if (input == "1" || input == "NORTH") {
			if (currentRoom->getNorth()) {
				prev_room_ = currentRoom;
				currentRoom = currentRoom->getNorth();
				displayMenu();
			}
			else {
				std::cout << "There's northing there!" << std::endl;
			}
		}
		if (input == "2" || input == "SOUTH") {
			if (currentRoom->getSouth()) {
				prev_room_ = currentRoom;
				currentRoom = currentRoom->getSouth();
				displayMenu();
			}
			else {
				std::cout << "I wish there was soumthing there!" << std::endl;
			}
		}
		if (input == "3" || input == "EAST") {
			if (currentRoom->getEast()) {
				prev_room_ = currentRoom;
				currentRoom = currentRoom->getEast();
				displayMenu();
			}
			else {
				std::cout << "No easty way out" << std::endl;
			}

		}
		if (input == "4" || input == "WEST") {
			if (currentRoom->getWest()) {
				prev_room_ = currentRoom;
				currentRoom = currentRoom->getWest();
				displayMenu();
			}
			else {
				std::cout << "A large wall blocks your way westward" << std::endl;
			}
		}

		//SEARCH: searches room and identifies items and chests within
		if (input == "5") {

			if (currentRoom->getItems().empty()) {
				std::cout << "There are no items left in here" << std::endl;
			}
			else {
				std::cout << "The room contains the following item(s)" << std::endl;
				currentRoom->printItems();
			}
			if (currentRoom->getChests().empty()) {
				std::cout << "There are no chests in here" << std::endl;
			}
			else {
				std::cout << "The room contains the following chest(s)" << std::endl;
				currentRoom->printChests();
			}
		}
		//TAKE: Take items from room, not in chests
		if (input == "6") {
			if (currentRoom->getItems().empty()) {
				std::cout << "There's nothing to take!" << std::endl;
			}
			else {
				do {
					input = "";
					currentRoom->printItems();
					std::cout << "Select which an item to take. Press q to go back" << std::endl;
					getline(std::cin, input);
					for (int i = 0; i < currentRoom->getItems().size(); i++) {
						if (input == currentRoom->getItems()[i]->GetName() || input == std::to_string(i + 1)) {
							player_->AddItemToInventory(currentRoom->getItems()[i]);
							std::cout << player_->GetName() << " added " << currentRoom->getItems()[i]->GetName();
							std::cout << " to inventory!" << std::endl;
							currentRoom->removeItem(currentRoom->getItems()[i]);
						}
					}
					if (currentRoom->getItems().empty()) {
						std::cout << "No more items remain in the room." << std::endl;
					}
				} while (input != "q" && !currentRoom->getItems().empty());
			}
		}
		//OPEN: player can open chests within room and loot their contents, some chests have monsters!
		if (input == "7") {
			if (currentRoom->getChests().empty()) {
				std::cout << "There are no chests in here" << std::endl;
			}
			else {
				do {
					input = "";
					currentRoom->printChests();
					std::cout << "Select which a chest to open. Press q to go back" << std::endl;
					getline(std::cin, input);
					for (int i = 0; i < currentRoom->getChests().size(); i++) {
						if (input == currentRoom->getChests()[i]->getName() || input == std::to_string(i + 1)) {
							std::cout << player_->GetName() << " opens the " << currentRoom->getChests()[i]->getName() << " and it contains: " << std::endl;

							//Logic for monster chests
							if (currentRoom->getChests()[i]->getEnemy()) {
								std::cout << currentRoom->getChests()[i]->getEnemy()->GetName() << " startles you!" << std::endl;
								// slightly messy way to work around targeting system being based off room enemies
								std::vector<Enemy*> mimic = currentRoom->getEnemies();
								mimic.push_back(currentRoom->getChests()[i]->getEnemy());
								currentRoom->addEnemies(mimic);
								currentRoom->getChests()[i]->setChestEnemy(nullptr);
								combatMenu();
							}
							//Player adds all chest contents to inventory
							for (int j = 0; j < currentRoom->getChests()[i]->getLoot().size(); j++) {
								player_->AddItemToInventory(currentRoom->getChests()[i]->getLoot()[j]);
								std::cout << player_->GetName() << " added " << currentRoom->getChests()[i]->getLoot()[j]->GetName();
								std::cout << " to inventory!" << std::endl;
								currentRoom->removeItem(currentRoom->getChests()[i]->getLoot()[j]);
							}
							currentRoom->removeChest(currentRoom->getChests()[i]);
						}
					}
					if (currentRoom->getChests().empty()) {
						std::cout << "No more chests remain in the room." << std::endl;
						break;
					}
				} while (input != "q" && !currentRoom->getItems().empty());
			}
		}
		//LOOK: Repeats the room description, generally has directions to nearby rooms
		if (input == "8") {
			currentRoom->getDescription();
		}
		//INVENTORY: Opens the non-combat inventory, player can use as many items in a row as they'd like outside of combat
		if (input == "9") {
			if (player_->getInventory().empty()) {
				std::cout << "Inventory is empty!" << std::endl;
			} else {
				openInventory();
			}
		}
		//STATS: Prints the player's stats(Health, Damage, Mana)
		if (input == "10") {
			this->player_->PrintStats();
		}
	}
}


// Inventory Menu, non-combat version
void GameWorld::openInventory() {
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
void GameWorld::combatMenu() {
	std::string input;
	int magicSpell;
	CombatUnit* target = nullptr;
	Item* combatItem = nullptr;

	//Lists the enemies encountered
	for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
		std::cout << currentRoom->getEnemies()[i]->GetName() << " has appeared!" << std::endl;
	}
	do {
		input = "";
		magicSpell = 0;
		target = nullptr;
		combatItem = nullptr;

		this->player_->PrintStats();
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Magic" << std::endl;
		std::cout << "3. Inventory" << std::endl;
		std::cout << "4. Scan Enemies" << std::endl;
		std::cout << "5. Flee!" << std::endl;
		getline(std::cin, input);

		//attack an enemy
		if (input == "1") {
			target = selectTarget();
			if (target) {
				combatTurn(use_attack_, target);
			}
		}
		//magic spell selection
		if (input == "2") {
			magicSpell = magicMenu();
			if (magicSpell != 0) {
				target = selectTarget();
				if (target) {
					combatTurn(magicSpell, target);
				}
			}
		}
		//open combat inventory
		if (input == "3") {
			if (player_->getInventory().empty()) {
				std::cout << "Inventory is empty!" << std::endl;
			}
			else {
				combatItem = combatInventory();
				if (combatItem) {
					target = selectTarget();
					if (target) {
						player_->UseItem(combatItem, target);
						player_->removeItemFromInventory(combatItem);
						combatTurn(use_item_, target);
					}
				}
			}
		}
		//scans enemies and displays their stats
		if (input == "4") {
			target = player_;
			if (target) {
				for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
					currentRoom->getEnemies()[i]->PrintStats();
				}
				combatTurn(use_scan_, target);
			}
		}
		//escape the current room and return to the previously explored room
		if (input == "5") {
			std::cout << "You run away while" << std::endl;
			for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
				std::cout<< currentRoom->getEnemies()[i]->GetName();
				std::cout << " laughs at you!" << std::endl;
			}
			currentRoom = prev_room_;
			displayMenu();
		}
	} while (!currentRoom->getEnemies().empty() && player_->GetHealth() > 0);
}


// Used to select target during combat
CombatUnit* GameWorld::selectTarget() {
	std::string input = "";

	do {
		std::cout << "Select which target? press q to go back" << std::endl;
		std::cout << "0. " << player_->GetName() << std::endl;
		for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
			std::cout << i + 1 <<". " <<currentRoom->getEnemies()[i]->GetName() << std::endl;
		}
		getline(std::cin, input);

		// checks if player inputs monster's entire name or just presses the number key associated with it
		for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
			if (input == player_->GetName() || input == "0") {
				std::cout << player_->GetName() << " is the target!" << std::endl;
				return player_;
			}
			if (input == currentRoom->getEnemies()[i]->GetName() || input == std::to_string(i + 1)) {
				std::cout << currentRoom->getEnemies()[i]->GetName() << " is the target!" << std::endl;
				return currentRoom->getEnemies()[i];
			}
		}
	} while (input != "q");
	return nullptr;
}


//logic for once player commits to a move
void GameWorld::combatTurn(int move, CombatUnit* target) {
	int randomMove = 0;

	player_->makeMove(move, target);
	if (target->GetHealth() < 1) {
		std::cout << target->GetName() << " was defeated!" << std::endl;
		if (!target->getInventory().empty()) {
			for (int i = 0; i < target->getInventory().size(); i++) {
				player_->AddItemToInventory(target->getInventory()[i]);
				std::cout << player_->GetName() << " added " << target->getInventory()[i]->GetName();
				std::cout << " to inventory!" << std::endl;
			}
		}
		currentRoom->removeEnemy(target);
	}

	// Enemies take their turn
	for (int i = 0; i < currentRoom->getEnemies().size(); i++) {
		//random number generator used to select majority of enemy moves
		randomMove = rand() % 100 + 1;
		currentRoom->getEnemies()[i]->makeMove(randomMove, player_);
		if (player_->GetHealth() < 1) {
			//end game from combat somehow
			game_over_ = true;
			break;
		}
		if (currentRoom->getEnemies()[i]->GetHealth() < 1) {
			std::cout << currentRoom->getEnemies()[i]->GetName() << " was defeated!" << std::endl;
			currentRoom->removeEnemy(currentRoom->getEnemies()[i]);
		}
	}
}


//magic menu, use to select a magic spell
int GameWorld::magicMenu() {
	std::string input;

	do {
		input = "";
		std::cout << "1. Lightning Bolt!" << std::endl;
		std::cout << "2. Cure" << std::endl;
		std::cout << "q. Exit Magic Menu" << std::endl;
		getline(std::cin, input);

		if (input == "1") {
			return use_bolt_magic_;
		}
		if (input == "2") {
			return use_cure_magic_;
		}
	} while (input != "q");
	return 0;
}


//combat version of inventory, once player uses an item, their turn ends
Item* GameWorld::combatInventory() {
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
						return player_->getInventory()[i];
					}
				}
			} while (input != "q" && !player_->getInventory().empty());
		}
	} while (input != "q");

	return nullptr;
}


//Displays an ending depending on conditions reached
void GameWorld::gameEndings(std::string ending) {
	if (ending == "death") {
		std::cout << "\nGame Over! You died" << std::endl;
	}
	else if (ending == "vault") {
		std::cout << "You later sell that one Adventure Coin for a ridiculous sum of money,\n"
			"the one Adventure Coin is later sold for an even more ridiculous sum of money.\n"
			"Wars are fought, battles are won and lost over the one Coin.\n"
			"Eventually the coin falls into a volcano, crashing the world economy.\n" << std::endl;
		std::cout << "The End!" << std::endl << std::endl;
	}
}