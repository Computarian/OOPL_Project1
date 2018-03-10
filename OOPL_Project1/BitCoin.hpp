#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include "Item.hpp"

class BitCoin : public Item {
public:
	BitCoin();
	void Effect(CombatUnit* target);
};

#endif // BITCOIN_HPP