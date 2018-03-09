#include "HealthPotion.hpp"



HealthPotion::HealthPotion() : Item("Energy Drink", "Restores 50 hp to the target.") {

}


void HealthPotion::Effect(CombatUnit* target) {
	target->ModifyHealth(-(health_potion_heal_));
}

