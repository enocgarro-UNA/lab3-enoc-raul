#pragma once
#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int experienceLevel;
    int healthPoints;
    static int totalCharactersCreated;

public:
    Character();
    Character(std::string _name, int _level, int _hp);
    Character(const Character& other);
    virtual ~Character();

    std::string getName() const;
    void setName(const std::string& _name);

    int getExperienceLevel() const;
    void setExperienceLevel(int _level);

    int getHealthPoints() const;
    void setHealthPoints(int _hp);

    virtual void displayInfo() const;
    static int getTotalCharactersCreated();

    bool operator==(const Character& other) const;
};

class Warrior : public Character {
protected:
    int meleeAttackStrength;

public:
    Warrior();
    Warrior(std::string _name, int _level, int _hp, int _attackStrength);
    Warrior(const Warrior& other);
    ~Warrior() override;

    int getMeleeAttackStrength() const;
    void setMeleeAttackStrength(int _strength);

    void displayInfo() const override;
};

class Mage : public Character {
protected:
    int manaPoints;

public:
    Mage();
    Mage(std::string _name, int _level, int _hp, int _mana);
    Mage(const Mage& other);
    ~Mage() override;

    int getManaPoints() const;
    void setManaPoints(int _mana);

    void displayInfo() const override;
};

class Paladin : public Warrior {
private:
    int shieldPoints;

public:
    Paladin();
    Paladin(std::string _name, int _level, int _hp, int _attackStrength, int _shield);
    Paladin(const Paladin& other);
    ~Paladin() override;

    int getShieldPoints() const;
    void setShieldPoints(int _shield);

    void displayInfo() const override;

    friend std::ostream& operator<<(std::ostream& os, const Paladin& p);
};

class AdventuringParty {
private:
    std::string partyName;
    Character** members;
    int capacity;
    int currentMembersCount;
     
public:
    AdventuringParty(std::string _partyName, int _capacity = 5);
    ~AdventuringParty();

    bool addMember(Character* character);
    int getMemberCount() const;
    void showPartyMembers() const;
};