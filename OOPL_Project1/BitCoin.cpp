#include "BitCoin.hpp"



BitCoin::BitCoin(): Item("One Bitcoin", "Does a random amount of damage (1-500) when thrown. Volatile!"){

}


void BitCoin::Effect(CombatUnit* target) {
	int bitcoin_damage = rand() % 500 + 1;
	std::cout<<"You throw the "<<GetName()<<" at "<< target->GetName() << " and it hits for "<<bitcoin_damage<<" damage!" << std::endl;
	target->ModifyHealth(bitcoin_damage);
}