#pragma once
#include <iostream>
#include <string>

class Character {
// FEEDBACK: Estos tres atributos deben ser private. El enunciado permite protected solo donde una clase
//           derivada necesite acceder directamente, y ninguna lo necesita: Warrior::displayInfo llama a
//           Character::displayInfo, que es un METODO, no toca name ni healthPoints. Paladin hace lo mismo
//           con Warrior::displayInfo. Todo el acceso ya pasa por la interfaz.
//           Fijense que en Paladin si usaron private para shieldPoints, y funciona igual. Ese es el
//           criterio correcto para las otras tres clases.
//           Regla practica: empiecen siempre en private y suban a protected solo cuando el compilador se
//           lo exija. protected abre el atributo a todas las clases que hereden en el futuro.
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
    // FEEDBACK: Mismo caso: este atributo deberia ser private. Paladin nunca lo toca directamente.
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
    // FEEDBACK: Mismo caso: private. Ninguna clase hereda de Mage en su entrega.
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