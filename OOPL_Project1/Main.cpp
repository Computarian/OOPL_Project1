// Michael Sousa COMP340-001 Project 1

#include "GameWorld.hpp"
#include <time.h>

int main() {
	srand(time(NULL));
	std::string input;

	std::cout << "  //-------------------------------\\""\\" << std::endl;
	std::cout << " // Kingdom of the Lost CryptoVault \\""\\" << std::endl;
	std::cout << "//-----------------------------------\\""\\" << std::endl << std::endl;

	do {
		input = "";
		std::cout << "1. Begin the Adventure!" << std::endl;
		std::cout << "q. Quit" << std::endl;
		std::getline(std::cin, input);

		if (input == "1") {
			GameWorld* newGame = new GameWorld();
			delete newGame;
		}
	} while (input != "q");
}