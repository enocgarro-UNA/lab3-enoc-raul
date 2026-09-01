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

// Warrior // 

Warrior::Warrior()
	:Character(), meleeAttackStrength(10) {
}

Warrior::Warrior(std::string _name, int _level, int _hp, int _attackStrength)
	: Character(_name, _level, _hp) {
	setMeleeAttackStrength(_attackStrength);
}

Warrior::Warrior(const Warrior& other)
	: Character(other), meleeAttackStrength(other.meleeAttackStrength) {
}

Warrior::~Warrior() {
}

int Warrior::getMeleeAttackStrength() const {
	return meleeAttackStrength;
}

void Warrior::setMeleeAttackStrength(int _strength) {
	if (_strength < 0) {
		this->meleeAttackStrength = 0;
	}
	else {
		this->meleeAttackStrength = _strength;
	}
}

void Warrior::displayInfo() const {
	Character::displayInfo();
	std::cout << " -> Melee Attack Strength: " << meleeAttackStrength << std::endl;
}

// Mage //

Mage::Mage()
	: Character(), manaPoints(50) {
}

Mage::Mage(std::string _name, int _level, int _hp, int _mana)
	: Character(_name, _level, _hp) {
	setManaPoints(_mana);
}

Mage::Mage(const Mage& other)
	: Character(other), manaPoints(other.manaPoints) {
}

Mage::~Mage() {
}

int Mage::getManaPoints() const {
	return manaPoints;
}

void Mage::setManaPoints(int _mana) {
	if (_mana < 0) {
		this->manaPoints = 0;
	}
	else {
		this->manaPoints = _mana;
	}
}

void Mage::displayInfo() const {
	Character::displayInfo();
	std::cout << " -> Mana Points: " << manaPoints << std::endl;
}

// Paladin
Paladin::Paladin()
	: Warrior(), shieldPoints(30) {}

Paladin::Paladin(std::string _name, int _level, int _hp, int _attackStrength, int _shield)
	: Warrior(_name, _level, _hp, _attackStrength) {
	setShieldPoints(_shield);
}

Paladin::Paladin(const Paladin& other)
	: Warrior(other), shieldPoints(other.shieldPoints) {}

Paladin::~Paladin() {}

int Paladin::getShieldPoints() const {
	return shieldPoints;
}

void Paladin::setShieldPoints(int _shield) {
	if (_shield < 0) {
		this->shieldPoints = 0;
	}
	else {
		this->shieldPoints = _shield;
	}
}

void Paladin::displayInfo() const {
	Warrior::displayInfo();
	std::cout << " -> Shield Points: " << shieldPoints << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Paladin& p) {
	os << "Paladin [" << p.getName()
		<< "] Level: " << p.getExperienceLevel()
		<< " | HP: " << p.getHealthPoints()
		<< " | Attack: " << p.getMeleeAttackStrength()
		<< " | Shield: " << p.getShieldPoints();
	return os;
}

// Adventuring Party
AdventuringParty::AdventuringParty(std::string _partyName, int _capacity)
	: partyName(_partyName), capacity(_capacity), currentMembersCount(0) {
	members = new Character * [capacity];
	for (int i = 0; i < capacity; i++) {
		members[i] = nullptr;
	}
}

AdventuringParty::~AdventuringParty() {
	delete[] members;
}

bool AdventuringParty::addMember(Character* character) {
	if (character == nullptr || currentMembersCount >= capacity) {
		return false;
	}
	members[currentMembersCount] = character;
	currentMembersCount++;
	return true;
}

int AdventuringParty::getMemberCount() const {
	return currentMembersCount;
}

void AdventuringParty::showPartyMembers() const {
	std::cout << "\n=== Party: " << partyName << " ===" << std::endl;
	std::cout << "Members: " << currentMembersCount << "/" << capacity << std::endl;
	for (int i = 0; i < currentMembersCount; i++) {
		if (members[i] != nullptr) {
			std::cout << (i + 1) << ". ";
			members[i]->displayInfo();
		}
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "===== LABORATORIO 3 - POO: HERENCIA =====\n" << std::endl;

	Character hero("Ares", 5, 120);
	Warrior warrior("Tyr", 8, 200, 45);
	Mage mage("Mimir", 6, 90, 150);
	Paladin paladin("Forseti", 12, 250, 60, 80);

	std::cout << "--- Personajes creados ---" << std::endl;
	hero.displayInfo();
	warrior.displayInfo();
	mage.displayInfo();
	paladin.displayInfo();

	std::cout << "\nContador despues de crear personajes principales: "
		<< Character::getTotalCharactersCreated() << std::endl;

	// Constructor copia
	std::cout << "\n--- Constructor de copia ---" << std::endl;
	Character copyHero(hero);
	Warrior copyWarrior(warrior);
	Paladin copyPaladin(paladin);

	std::cout << "Original: ";
	hero.displayInfo();
	std::cout << "Copia:    ";
	copyHero.displayInfo();

	copyHero.setName("Ares (Copia)");
	copyHero.setHealthPoints(50);

	std::cout << "\nDespues de modificar la copia:" << std::endl;
	std::cout << "Original: ";
	hero.displayInfo();
	std::cout << "Copia:    ";
	copyHero.displayInfo();

	std::cout << "\nContador despues de las copias: "
		<< Character::getTotalCharactersCreated() << std::endl;

	std::cout << "\n--- Contador static ---" << std::endl;
	std::cout << "Total de personajes creados: "
		<< Character::getTotalCharactersCreated() << std::endl;

	// Se compara personajes con operator==
	std::cout << "\n--- Comparacion con operator== ---" << std::endl;
	Character sameLevel("Test1", 5, 100);
	Character differentLevel("Test2", 7, 100);

	std::cout << "hero == sameLevel = "
		<< (hero == sameLevel ? "true" : "false") << std::endl;
	std::cout << "hero == differentLevel = "
		<< (hero == differentLevel ? "true" : "false") << std::endl;
	std::cout << "warrior == paladin = "
		<< (warrior == paladin ? "true" : "false") << std::endl;

	std::cout << "\nContador final (despues de crear los de comparacion): "
		<< Character::getTotalCharactersCreated() << std::endl;

	std::cout << "\n --- Adventuring Party --- " << std::endl;
	AdventuringParty party("The Brave Ones", 6);

	party.addMember(&hero);
	party.addMember(&warrior);
	party.addMember(&mage);
	party.addMember(&paladin);
	party.addMember(&copyHero);

	std::cout << "Cantidad de integrantes: " << party.getMemberCount() << std::endl;
	party.showPartyMembers();

	std::cout << "===== FIN =====" << std::endl;
	return 0;
}