#include "Dungeon.hpp"



Dungeon::Dungeon(){
	//creating the dungeon rooms first, then generates the tables and dungeon contents
	generateRooms();
	doorTable();
	descriptionTable();
	itemTable();
	chestTable();
	enemyTable();
	storyTable();

	generateDoors();
	generateDescriptions();
	generateItems();
	generateChests();
	generateEnemies();
	generateStory();
}


Room* Dungeon::getStartRoom() {
	return this->dungeon_[0];
}


bool Dungeon::endRoom(Room* currentRoom) {
	if (currentRoom == dungeon_[19]) {
		return true;
	}
	return false;
}


std::vector<Room*> Dungeon::getDungeon() {
	return this->dungeon_;
}


// generate rooms in the dungeon
void Dungeon::generateRooms() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		Room* newRoom = new Room();
		dungeon_.push_back(newRoom);
	}
}


// generate doors for the rooms
void Dungeon::generateDoors() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->setRoomDoors(doors_[i]);
	}
}


// generate room descriptions
void Dungeon::generateDescriptions() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->setDescription(descriptions_[i]);
	}
}


// generate room items
void Dungeon::generateItems() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->addItems(items_[i]);
	}
}


// generate room chests
void Dungeon::generateChests() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->addChests(chests_[i]);
	}
}


// generate room enemies
void Dungeon::generateEnemies() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->addEnemies(enemies_[i]);
	}
}


// generates one time intro story to rooms
void Dungeon::generateStory() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->setStory(story_[i]);
	}
}


// room doors to other rooms: {NORTH, SOUTH, EAST, WEST}
void Dungeon::doorTable() {
	doors_ = { { nullptr, nullptr, dungeon_[1], dungeon_[2] }, //Room 0: Start Room
		{ nullptr, nullptr, nullptr, dungeon_[0] }, //Room 1: City
		{ dungeon_[3], nullptr, dungeon_[0], nullptr }, //Room 2: Snow Field
		{ dungeon_[5], dungeon_[2], nullptr, dungeon_[4]}, //Room 3: Mine Entrance
		{ nullptr, nullptr, dungeon_[3], nullptr}, //Room 4: Mines Lv1
		{ nullptr, dungeon_[3], dungeon_[6], nullptr }, //Room 5: Break Room
		{ dungeon_[8], nullptr, dungeon_[7], dungeon_[5] }, //Room 6: Mines Lvl2
		{ nullptr, nullptr, nullptr, dungeon_[6] }, //Room 7: Bulbasaur Room
		{ dungeon_[9], dungeon_[6], nullptr, nullptr }, //Room 8: Courtyard
		{ nullptr, dungeon_[8], dungeon_[17], dungeon_[10] }, //Room 9: Castle Entrance
		{ dungeon_[11], nullptr, dungeon_[9], nullptr }, //Room 10: Kitchen
		{ dungeon_[12], dungeon_[10], nullptr, nullptr }, //Room 11: Museum
		{ nullptr, dungeon_[11], dungeon_[13], nullptr }, //Room 12: Conservatory
		{ dungeon_[18], nullptr, dungeon_[14], dungeon_[12] }, //Room 13: Grand Hall
		{ nullptr, dungeon_[15], nullptr, dungeon_[13]}, //Room 14: Royal Chambers
		{ dungeon_[14], dungeon_[17], dungeon_[16], nullptr }, //Room 15: Block Chainber
		{ nullptr, nullptr, nullptr, dungeon_[15] }, //Room 16: Chinchilla Chamber
		{ dungeon_[15], nullptr, nullptr, dungeon_[9] }, //Room 17: Lab
		{ dungeon_[19], dungeon_[13], nullptr, nullptr }, //Room 18: Final Boss Room
		{ nullptr, dungeon_[18], nullptr, nullptr } }; //Room 19: Goal Room
}


// room descriptions
void Dungeon::descriptionTable() {
	descriptions_ = {
		//Room 0
		"--Seaside--\n"
		"North of you up a mountain is the Castle,\n"
		"the cliffs are too steep to climb however, \n"
		"South lies \"The Sea\", your submarine is currently docked nearby.\n"
		"to the East lies the ruined City.\n"
		"to the West is a path leading to the abandoned Bitcoin Mine\n",
		//Room 1
		"--Ruined City--\n"
		"There is far too much rubble in the city, and you can't continue any further.\n"
		"The path west seems like a more promising way to the Castle\n",
		//Room 2
		"--Snowy Field--\n"
		"The entrance to the Bitcoin Mine lies to the north.\n"
		"A sign nearby says \"Don't feed the Trolls\"\n",
		//Room 3
		"--Bitcoin Mines: Level 1--\n"
		"To the north leads deeper into the mines.\n"
		"To the west is the Break Room.\n",
		//Room 4
		"--Mines: Break Room--\n"
		"The Break Room, several Vending Machines are in here.\n",
		//Room 5
		"--Bitcoin Mines: Level 2--\n"
		"The Funicular is to the East.\n",
		//Room 6
		"--Castle Gates--\n"
		"The gates to the castle lie open to the north.\n"
		"To the east is the Data Furnace.\n",
		//Room 7
		"--Data Furnace--\n"
		"The furnace lies dormant,\n"
		"the frozen Palm Trees nearby indicate this area used to be much warmer.\n",
		//Room 8
		"--Courtyard--\n"
		"To the north lies the entrance into the Castle.\n",
		//Room 9
		"--Grand Entrance--\n"
		"East Wing: Overly cutesy robot sounds can be heard coming from the halls to the east.\n"
		"West Wing: The west is quiet... almost too quiet...\n",
		//Room 10
		"--Kitchen--\n"
		"North lies the Museum.\n",
		//Room 11
		"--Museum--\n"
		"North lies the Conservatory.\n",
		//Room 12
		"--Conservatory--\n"
		"To the east is the Grand Hall. The treasure is near..\n",
		//Room 13
		"--Grand Hall--\n"
		"To the north is the Throne Room, prepare for the final battle!\n"
		"The East and West Wings meet here in the Grand Hall.\n",
		//Room 14
		"--Royal Chambers--\n"
		"To the west is the Grand Hall. The treasure is near..\n",
		//Room 15
		"--Block Chainber--\n"
		"To the north lie the Royal Chambers.\n"
		"To the east is an unknown room,\n"
		"a nearby sign has unreadable letters due to claw marks.\n",
		//Room 16
		"--Petting Zoo--\n"
		"On the ground lay five dead Chinchillas,\nyou monster\n",
		//Room 17
		"--Lab--\n"
		"North leads to the Block Chainber.\n",
		//Room 18
		"--Throne Room--\n"
		"North is a secret passage which contains an elevator leading down to the Vault!\n",
		//Room 19
		"--The Vault--\n"
		"You did it!\n" };
}


void Dungeon::itemTable() {
	items_ = { {new HealthPotion(), new HealthPotion()}, //Room 0
		{new HealthPotion(), new HealthPotion(), new ManaPotion(), new ManaPotion()}, //Room 1
		{}, //Room 2
		{new BitCoin()}, //Room 3
		{new BitCoin()}, //Room 4
		{new BitCoin(), new BitCoin()}, //Room 5
		{}, //Room 6
		{new MasterBall()}, //Room 7
		{}, //Room 8
		{new RobotArm()}, //Room 9
		{new HamSandwich(), new HealthPotion(), new ManaPotion()}, //Room 10
		{}, //Room 11
		{}, //Room 12
		{new HamSandwich(), new RobotArm(), new RobotArm()}, //Room 13
		{}, //Room 14
		{}, //Room 15
		{}, //Room 16
		{new RobotArm()}, //Room 17
		{}, //Room 18
		{} };  //Room 19
}


void Dungeon::chestTable() {
	//mimic chests
	Mimic* breakRoomMimic = new Mimic("Vending Machine Mimic");
	Chest* breakRoomMimicChest = new Chest({ new ManaPotion(), new ManaPotion(), new ManaPotion() , new ManaPotion() }, "Strange Vending Machine");
	breakRoomMimicChest->setChestEnemy(breakRoomMimic);

	Mimic* fridgeMimic = new Mimic("Fridge Mimic: Fridgic");
	Chest* fridgeMimicChest = new Chest({ new HamSandwich() }, "Ordinary Refrigerator");
	fridgeMimicChest->setChestEnemy(fridgeMimic);

	Mimic* freezerMimic = new Mimic("Fritz the Freezer Mimic");
	Chest* freezerMimicChest = new Chest({ new HealthPotion(), new ManaPotion(), new BitCoin() }, "CryptoCooler Freezer");
	freezerMimicChest->setChestEnemy(freezerMimic);

	chests_ = { {}, //Room 0
		{ new Chest({ new HealthPotion(), new HealthPotion }, "Old Chest") }, //Room 1
		{}, //Room 2
		{}, //Room 3
		{new Chest({new HealthPotion(), new HealthPotion(),new HealthPotion(),new HealthPotion()}, "CryptoCooler Vending Machine"),
			breakRoomMimicChest}, //Room 4
		{}, //Room 5
		{}, //Room 6
		{new Chest({new BitCoin(), new BitCoin()}, "Satoshi's Wallet")}, //Room 7
		{}, //Room 8
		{}, //Room 9
		{fridgeMimicChest, freezerMimicChest}, //Room 10
		{new Chest({new MasterBall()}, "Curator's Chest")}, //Room 11
		{}, //Room 12
		{new Chest({new HamSandwich(), new HamSandwich()}, "Discarded Lunch Box")}, //Room 13
		{new Chest({new BitCoin()}, "Royal Wallet")}, //Room 14
		{new Chest({new RobotArm(), new RobotArm()}, "Armoire")}, //Room 15
		{}, //Room 16
		{}, //Room 17
		{}, //Room 18
		{} }; //Room 19
}


void Dungeon::enemyTable() {
	enemies_ = { {}, //Room 0
		{new Chinchilla("Rad Chinchilla")}, //Room 1
		{}, //Room 2
		{new Troll("Larry the Troll")}, //Room 3
		{new Troll("Troll on their break")}, //Room 4
		{new Troll("Trololo the Troll"), new Troll( "|||||||| the Troll")}, //Room 5
		{}, //Room 6
		{new Bulbasaur("BULBASAUR")}, //Room 7
		{}, //Room 8
		{}, //Room 9
		{}, //Room 10
		{new LargeRock("The Large Rock")}, //Room 11
		{new Bulbasaur("Bulbasaur")}, //Room 12
		{new NAO("Chappie"), new NAO("Chappie's Good Friend")}, //Room 13
		{}, //Room 14
		{new NAO("NAO Grunt")}, //Room 15
		{ new Chinchilla("Charlie the Chinchilla"), new Chinchilla("Chucky the Chinchilla"), new Chinchilla("Chunky the Chinchilla"),
			new Chinchilla("Chuck Berry the Chinchilla"), new Chinchilla("Steve the Chinchilla") }, //Room 16
		{new NAO("COMP 460 Project: NAO Robot")}, //Room 17
		{new ClumsyRobot("Clumsy Robot")}, //Room 18
		{} }; //Room 19
}


void Dungeon::storyTable() {
	story_ = { 
		{"You have finally arrived at the Kingdom,\n"
		"the tales of the Lost Bitcoin Vault lead here,\nyou begin your search..\n\n"}, //Room 0
		{"The once prosperous City has fallen to ruin...\n"}, //Room 1
		{"You begin moving westward across the snow field,\n"
			"You continue your journey following the snow covered train tracks to the mine.\n"}, //Room 2
		{"You thought the mines were abandoned, but a wild troll appears!\n"
			"They have the ability to regen, but overall aren't too tough.\n"}, //Room 3
		{"You enter the break room and a lone troll seems upset you interrupted them.\n"}, //Room 4
		{"You see a pile of burnt out video cards and discarded fans in the corner.\n"
			"Two trolls are seen scavenging for good parts.\n"}, //Room 5
		{"After taking the Funicular and not having to fight anything on it oddly enough,\n"
			"you reach the castle gates. Although to the east lies the Data Furnace,\n"
			"which could contain some treasure...\n"}, //Room 6
		{"The Data Furnace was used to heat the Kingdom during the Bitcoin Boom,\n"
			"but eventually the mines began to run dry, draining the Kingdom's wealth and warmth.\n"}, //Room 7
		{"Despite the Kingdom's fall during the Crypto Wars,\n"
			"the Castle remains in fairly good condition.\n"}, //Room 8
		{"The interior of the Castle is quite grand and meticulously cleaned.\n"
			"To the west is a Kitchen, and to the east is the Lab.\n"}, //Room 9
		{"The Kitchen would probably be a good time to stock up the Inventory.\n"}, //Room 10
		{"You try to enter the Museum, but blocking the way is a very large rock!\n"}, //Room 11
		{"The Conservatory contains various flora native to the Kingdom,\n"
			"before it became frozen over.\n"}, //Room 12
		{"The Grand Hall leads to the Throne Room,\n"
			"but two NAO robots are guarding the way forward!\n"}, //Room 13
		{"No one knows what happened to the royal family after the Kingdom fell.\n"
			"*A notification appears* Pre-order the new DLC: Legacy of the Kingdom, today!\n"}, //Room 14
		{"The Block Chainber seems important, but you don't really know what it does.\n"}, //Room 15
		{"You're going to have a bad time.\n"}, //Room 16
		{"The Lab contains research on how to easily explain cryptocurrency.\n"}, //Room 17
		{"In the Throne Room, you find a robot cleaning the area,\n"
			"a robot that seems to be misplaced from the game Earthbound.\n"
			"You explore the room and find nothing.\n"
			"Desperate to find a way forward, you attack the robot!\n"
			"The robot does not take kindly to this and attacks!\n"}, //Room 18
		{"You descend the elevator and arrive in a room that is probably a Vault.\n"
			"The room contains nothing but a wallet on the floor.\n"
			"You open the wallet and a note is inside.\n"
			"On the note is written a hash.\n"
			"You decipher the hash and get a key.\n"
			"You use the key on the keyhole that was underneath the wallet you picked up.\n"
			"The key opens a door!\n"
			"Behind the door, a robot congratulates you!\n"
			"The Robot says: The new Coin Mining Algorithm is a success!\n"
			"By completing this adventure, you have earned one Adventure Coin!\n"
			"The robot then shuts down.\n"
			"Somewhat satisfied, you leave with your one Adventure Coin.\n"
			"...........\n"} }; //Room 19
}
