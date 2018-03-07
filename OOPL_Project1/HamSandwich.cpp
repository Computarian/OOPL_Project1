#include "HamSandwich.hpp"



HamSandwich::HamSandwich(): Item("Ham Sandwich", "Fully restores HP. Delicious!") {

}


void HamSandwich::Effect(CombatUnit* target) {
	target->ModifyHealth(-(target->GetDefaultHealth() - target->GetHealth()));
}

