#include "Dungeon.hpp"



Dungeon::Dungeon(){

	generateRooms();
	roomTables();
	enemyTable();

	generateDoors();
	generateDescriptions();
	generateItems();
	generateEnemies();
	/*
	//Creating the first room
	Room* start = new Room(nullptr, nullptr, nullptr, nullptr);
	this->start_room_ = start;
	start->setDescription("It's the start room!");
	//Creating the second room
	Room* secondRoom = new Room(nullptr, start, nullptr, nullptr);
	secondRoom->setDescription("It's the second room!");
	start->setNorth(secondRoom);

	//Mimic* mickey = new Mimic(100, 200);
	Mimic* mickey = new Mimic();
	mickey->PrintStats();
	secondRoom->addEnemy(mickey);
	*/
}


Room* Dungeon::getStartRoom() {
	return this->dungeon_[0];
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

}


void Dungeon::generateEnemies() {
	for (int i = 0; i < DUNGEON_SIZE; i++) {
		dungeon_[i]->addEnemies(enemies_[i]);
	}
}


void Dungeon::roomTables() {
	// room doors to other rooms
	doors_ = { { dungeon_[1], nullptr, nullptr, nullptr }, 
				{ nullptr, dungeon_[0], nullptr, nullptr }};

	// room descriptions
	descriptions_ = {  "It's the start room!" ,
						"It's the second room!" };

	// items

}

void Dungeon::enemyTable() {
	// enemies
	Mimic* mickey = new Mimic();
	Mimic* mickeyJr = new Mimic();
	enemies_ = { {},
				{ mickey} };
}
