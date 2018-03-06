#include "HealthPotion.hpp"



HealthPotion::HealthPotion() : Item("Cookie", "Restores 5hp to the target.") {

}


void HealthPotion::Effect(CombatUnit* target) {
	target->ModifyHealth(-5);
}

