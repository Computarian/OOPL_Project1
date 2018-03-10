#include "Dungeon.hpp"



Dungeon::Dungeon(){

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


void Dungeon::generateStory() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->setStory(story_[i]);
	}
}
// room doors to other rooms: {NORTH, SOUTH, EAST, WEST}
void Dungeon::doorTable() {
	doors_ = { { nullptr, nullptr, dungeon_[1], dungeon_[2] }, //Room 0: Start Room
				{ nullptr, nullptr, nullptr, dungeon_[0] }, //Room 1
				{ dungeon_[3], nullptr, dungeon_[0], nullptr }, //Room 2
				{ dungeon_[5], dungeon_[2], nullptr, dungeon_[4]}, //Room 3
				{ nullptr, nullptr, dungeon_[3], nullptr}, //Room 4
				{ nullptr, dungeon_[3], dungeon_[6], nullptr }, //Room 5
				{ dungeon_[8], nullptr, dungeon_[7], dungeon_[5] }, //Room 6
				{ nullptr, nullptr, nullptr, dungeon_[6] }, //Room 7: Bulbasaur Room
				{ dungeon_[9], dungeon_[6], nullptr, nullptr }, //Room 8
				{ nullptr, dungeon_[8], dungeon_[17], dungeon_[10] }, //Room 9
				{ dungeon_[11], nullptr, dungeon_[9], nullptr }, //Room 10
				{ dungeon_[12], dungeon_[10], nullptr, nullptr }, //Room 11: NAO Robot Boss
				{ nullptr, dungeon_[11], dungeon_[13], nullptr }, //Room 12
				{ dungeon_[18], nullptr, dungeon_[14], dungeon_[12] }, //Room 13
				{ nullptr, dungeon_[15], nullptr, dungeon_[13]}, //Room 14
				{ dungeon_[14], dungeon_[17], dungeon_[16], nullptr }, //Room 15: Clumsy Robot Boss
				{ nullptr, nullptr, nullptr, dungeon_[15] }, //Room 16: Chinchilla Chamber
				{ dungeon_[15], nullptr, nullptr, dungeon_[9] }, //Room 17
				{ dungeon_[19], dungeon_[13], nullptr, nullptr }, //Room 18: Final Boss Room
				{ nullptr, dungeon_[18], nullptr, nullptr } }; //Room 19: Goal Room
}


// room descriptions
void Dungeon::descriptionTable() {
	descriptions_ = {
		//Room 0
		"--Seaside--\n"
		"North of you up a mountain is the Castle,\n"
		" the cliffs are too steep to climb however, \n"
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
		"--Bitcoin Mines: Ground Level--\n"
		"To the north leads deeper into the mines.\n"
		"To the west is the Break Room.\n",
		//Room 4
		"--Mines: Break Room--\n"
		"The Break Room, several Vending Machines are in here.\n",
		//Room 5
		"--Bitcoin Mines: Upper Level--\n"
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
		"North in a secret passage is an elevator leading down to the Vault!\n",
		//Room 19
		"--The Vault--\n"
		"You did it!\n"
	};

}


void Dungeon::itemTable() {
	// items list
	HealthPotion* healPotion1 = new HealthPotion();

	// items table
	items_ = { {},
				{},
				{},
				{},
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{}, 
				{} };
}


void Dungeon::chestTable() {
	//items for chests
	std::vector<Item*> chest0 = { new HealthPotion(), new HealthPotion };
	std::vector<Item*> vendingMimic = { new ManaPotion(), new ManaPotion(), new ManaPotion() , new ManaPotion() };

	//mimic chest
	Mimic* mickeySr = new Mimic("Vending Machine Mimic");

	// chests list
	Chest* firstChest = new Chest(chest0, "Old Chest");

	Chest* mimicChest = new Chest(vendingMimic, "Strange Vending Machine");
	mimicChest->setChestEnemy(mickeySr);

	chests_ = { {},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{} };
}


void Dungeon::enemyTable() {
	// enemies list 

	// test rock battle room 0
	LargeRock* bigrock = new LargeRock("The Large Rock");

	// Mimic Test room 1
	Mimic* mickey = new Mimic("Mickey the Mimic");
	Mimic* mickeyJr = new Mimic("Mickey Jr the Mimic");
	Bulbasaur* bulby = new Bulbasaur("Bulbasaur");
	// Clumsy Robot room 2
	ClumsyRobot* clumsyRobot = new ClumsyRobot("Clumsy Robot");
	NAO* naoRobot = new NAO("Chappie, COMP 460 Project");

	// Chinchilla Chamber room 3
	Chinchilla* charlie = new Chinchilla("Charlie the Chinchilla");
	Chinchilla* chucky = new Chinchilla("Chucky the Chinchilla");
	Chinchilla* chunky = new Chinchilla("Chunky the Chinchilla");
	Chinchilla* chuckberry = new Chinchilla("Chuck Berry the Chinchilla");
	Chinchilla* steve = new Chinchilla("Steve the Chinchilla");

	// enemy table
	enemies_ = { {},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{} };
}


void Dungeon::storyTable() {
	story_ = { {"You have finally arrived at the mysterious estate,\n"
				"the tales of D. Ragon's Bitcoin Horde lead here,\nyou begin your search..\n\n"},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{},
				{} };
}
