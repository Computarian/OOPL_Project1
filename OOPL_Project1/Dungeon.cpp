#include "Dungeon.hpp"



Dungeon::Dungeon(){

	generateRooms();
	doorTable();
	descriptionTable();
	itemTable();
	chestTable();
	enemyTable();

	generateDoors();
	generateDescriptions();
	generateItems();
	generateChests();
	generateEnemies();
}


Room* Dungeon::getStartRoom() {
	return this->dungeon_[0];
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


void Dungeon::generateItems() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->addItems(items_[i]);
	}
}


void Dungeon::generateChests() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->addChests(chests_[i]);
	}
}


void Dungeon::generateEnemies() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->addEnemies(enemies_[i]);
	}
}


// room doors to other rooms: {NORTH, SOUTH, EAST, WEST}
void Dungeon::doorTable() {
	doors_ = { { dungeon_[1], nullptr, dungeon_[2], dungeon_[3] },
				{ nullptr, dungeon_[0], nullptr, nullptr },
				{nullptr, nullptr, nullptr, dungeon_[0]},
				{nullptr, nullptr, dungeon_[0], nullptr}};
}


// room descriptions
void Dungeon::descriptionTable() {
	descriptions_ = { "It's the start room!" ,
		"It's the Mimics' room!",
		"It's the test item room!",
		"\nOn the ground lay five dead Chinchillas,\nyou monster\n"};

}


void Dungeon::itemTable() {
	// items list
	HealthPotion* healPotion1 = new HealthPotion();

	// items table
	items_ = { {},
				{},
				{healPotion1},
				{} };
}


void Dungeon::chestTable() {
	//items for chests
	std::vector<Item*> chest0 = { new HealthPotion(), new HealthPotion };

	// chests list
	Chest* firstChest = new Chest(chest0, "Old Chest");

	chests_ = { {},
				{},
				{firstChest},
				{} };
}


void Dungeon::enemyTable() {
	// enemies list 
	// Mimic Test room 1
	Mimic* mickey = new Mimic("Mickey the Mimic");
	Mimic* mickeyJr = new Mimic("Mickey Jr the Mimic");

	// Chinchilla Chamber room 3
	Chinchilla* charlie = new Chinchilla("Charlie the Chinchilla");
	Chinchilla* chucky = new Chinchilla("Chucky the Chinchilla");
	Chinchilla* chunky = new Chinchilla("Chunky the Chinchilla");
	Chinchilla* chuckberry = new Chinchilla("Chuck Berry the Chinchilla");
	Chinchilla* steve = new Chinchilla("Steve the Chinchilla");

	// enemy table
	enemies_ = { {},
				{ mickey, mickeyJr },
				{},
				{charlie, chucky, chunky, chuckberry, steve} };
}
