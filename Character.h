#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "InputValidation.h"
using namespace std;

class Character
{
protected:
    string type;
    bool alive = true;
    string name;
    int level;
    int maxHealth = 100;
    int maxStamina = 100;
    int health = maxHealth;
    int stamina = maxStamina;
    int XP = 0;
    int maxXP = 10;

public:
    Character(string _name);
    void setCharacterName(string setName);
    string getName();
    void Resting(int addHealth);
    void HealthItem(int addHealth);
    void AddXp(int addXp); // think about linear (same xp for each level )or progressive (more xp for every level)
    void takeDamage(int damage);
    virtual void attack() = 0;
};

Character::Character(string _name)
{
    name = _name;
}

void Character::setCharacterName(string setName)
{
    name = setName;
}

string Character::getName()
{
    return name;
}

void Character::Resting(int addHealth)
{
    if (health + addHealth > maxHealth)
    {
        health = maxHealth;
        return;
    }
    health += addHealth;
}

void Character::HealthItem(int addHealth)
{
    Resting(addHealth); // dont know if this'll work
}

// think about linear (same xp for each level )or progressive (more xp for every level)
void Character::AddXp(int addXp)
{
    if (XP + addXp > maxXP)
    {
        // Increase level, MaxXP, Health, MaxHealth, Stamina, MaxStamina
        level += 1;
        maxXP += 1;
        XP = (XP + addXp - maxXP);

        return;
    }
    XP += addXp;
}
void Character::takeDamage(int damage)
{
    if (health - damage < 0)
    {
        alive = false;
        health = 0;
        return;
    }

    health -= damage;
}

#endif