#ifndef CHINCHILLA_HPP
#define CHINCHILLA_HPP

#include "Cute.hpp"

class Chinchilla : public Cute {

public:
	Chinchilla(std::string name);
	~Chinchilla();
	void makeMove(int move, CombatUnit* target);
	void bite(CombatUnit* target);

private:
	const static int defaultHealth = 10;
	const static int defaultDamage = 5;
	const static int biteDamage = 50;
};

#endif //CHINCHILLA_HPPs
