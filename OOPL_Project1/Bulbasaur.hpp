#ifndef BULBASAUR_HPP
#define BULBASAUR_HPP

#include "Cute.hpp"

class Bulbasaur: public Cute {
public:
	Bulbasaur(std::string name);
	~Bulbasaur();
	void makeMove(int move, CombatUnit* target);
	void tackle(CombatUnit* target);
	void growl(CombatUnit* target);
	void leechSeed(CombatUnit* target);
	void vineWhip(CombatUnit* target);

private:
	const static int defaultHealth = 500;
	const static int defaultDamage = 20;
	int leech_seed_damage_ = 10;
	int vine_whip_damage_ = 50;
};

#endif //BULBASAUR_HPP