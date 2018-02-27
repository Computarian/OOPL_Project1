#include "Dungeon.hpp"



Dungeon::Dungeon(){
	//Creating the first room
	Room* start = new Room(nullptr, nullptr, nullptr, nullptr, "It's the start room!");
	this->start_room_ = start;

	//Creating the second room
	Room* secondRoom = new Room(nullptr, start, nullptr, nullptr, "It's the second room!");
	start->setNorth(secondRoom);
	//Enemy* Mickey = new Enemy(100, 200, "Mimic");
	Mimic* mickey = new Mimic();
	mickey->PrintStats();
	secondRoom->addEnemy(mickey);

}


Dungeon::~Dungeon(){

}


Room* Dungeon::getStartRoom() {
	return this->start_room_;
}
