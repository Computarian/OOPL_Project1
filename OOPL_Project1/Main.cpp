#include <iostream>
#include "GameWorld.hpp"
#include <time.h>

int main() {
	srand(time(NULL));
	std::string input;

	std::cout << "Hello Adventurer!" << std::endl;

	do {
		input = "";
		std::cout << "1. Adventure!" << std::endl;
		std::cout << "q. Quit" << std::endl;
		std::getline(std::cin, input);

		if (input == "1") {
			GameWorld* newGame = new GameWorld();
		}
	} while (input != "q");
	//game settings done in main?
	//then pass into game constructor to create game
	//std::cin.get();
	//system("pause"); //Needed with Visual Studio Windows to pause program
}