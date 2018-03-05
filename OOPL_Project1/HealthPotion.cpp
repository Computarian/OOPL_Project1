#include "HealthPotion.hpp"



HealthPotion::HealthPotion() : Item("Health Potion", "Restores 5hp to the target.") {

}


void HealthPotion::Effect(CombatUnit* target) {
	target->ModifyHealth(-5);
}

