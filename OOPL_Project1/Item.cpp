#include "Item.hpp"



Item::Item(std::string name, std::string description) {
	this->name_ = name;
	this->description_ = description;
}


std::string Item::GetName() {
	return this->name_;
}


std::string Item::GetDescription() {
	return this->description_;
}


void Item::SetDescription(std::string description) {
	this->description_ = description;
}


void Item::PrintData() {
	std::cout << GetName()<< ": " << GetDescription() << std::endl;
}