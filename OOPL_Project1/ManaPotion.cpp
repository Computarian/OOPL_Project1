#include "ManaPotion.hpp"



ManaPotion::ManaPotion() : Item("Energy Drink", "Restores 50 mana points to the target.") {

}


void ManaPotion::Effect(CombatUnit* target) {
	target->ModifyMana(-50);
}
