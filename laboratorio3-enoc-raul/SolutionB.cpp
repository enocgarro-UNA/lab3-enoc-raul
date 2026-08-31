#include "SolutionB.h"
#include <iostream>
#include <string>

int Character::totalCharactersCreated = 0; //Miembro Estatico

// Character //

Character::Character()
	: name("Unknown"), experienceLevel(1), healthPoints(100) {
	totalCharactersCreated++;
}
Character::Character(std::string _name, int _level, int _hp) {
	setName(_name);
	setExperienceLevel(_level);
	setHealthPoints(_hp);
	totalCharactersCreated++;
}

Character::Character(const Character& other)
	: name(other.name), experienceLevel(other.experienceLevel), healthPoints(other.healthPoints) {
	totalCharactersCreated++;
}

Character::~Character() {

}

std::string Character::getName() const {
	return name;
}

void Character::setName(const std::string& _name) {
	if (!_name.empty()) {
		this->name = _name;
	}
	else {
		this->name = "Unknown";
	}
}

int Character::getExperienceLevel() const {
	return experienceLevel;
}

void Character::setExperienceLevel(int _level) {
	if (_level < 0) {
		this->experienceLevel = 0;
	}
	else {
		this->experienceLevel = _level;
	}
}

int Character::getHealthPoints() const {
	return healthPoints;
}

void Character::setHealthPoints(int _hp) {
	if (_hp < 0) {
		this->healthPoints = 0;
	}
	else {
		this->healthPoints = _hp;
	}
}

void Character::displayInfo() const {
	std::cout << "Name: " << name
		<< " | Level: " << experienceLevel
		<< " | HP: " << healthPoints << std::endl;
}

int Character::getTotalCharactersCreated() {
	return totalCharactersCreated;
}

bool Character::operator==(const Character& other) const {
	return this->experienceLevel == other.experienceLevel;
}