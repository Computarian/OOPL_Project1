#include "ManaPotion.hpp"



ManaPotion::ManaPotion() : Item("Mountain Dew Voltage", "Restores 50 mana points to the target. Do the Dew!") {

}


void ManaPotion::Effect(CombatUnit* target) {
	target->ModifyMana(-50);
}
