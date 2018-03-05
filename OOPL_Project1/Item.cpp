#include "Item.hpp"

Item::Item(std::string name, std::string description) {
	this->name = name;
	this->description_ = description;
}

std::string Item::GetName() {
	return this->name;
}

std::string Item::GetDescription() {
	return this->description_;
}


void Item::SetDescription(std::string description) {
	this->description_ = description;
}


void Item::PrintData() {
	std::cout << GetName()<< "\t" << GetDescription() << std::endl;
}