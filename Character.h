#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "InputValidation.h"
using namespace std;

class Character
{
public:
    string type;
    bool alive = true;
    string name;
    int level = 0;
    int maxHealth = 100;
    int maxStamina = 100;
    int health = maxHealth;
    int stamina = maxStamina;
    int XP = 0;
    int maxXP = 10;
    // -----
    Character(string _name);
    virtual void printStats();
    void setCharacterName(string setName);
    string getName();
    void Resting(int addHealth, int addStamina);
    void HealthItem(int addHealth, int addStamina);
    void AddXp(int addXp); // think about linear (same xp for each level )or progressive (more xp for every level)
    void takeDamage(int damage);
    virtual int attack() = 0;
};

Character::Character(string _name)
{
    name = _name;
}

void Character::printStats()
{
    cout << name << " " << type << endl;
    cout << "Health: " << health << "/" << maxHealth << endl;
    cout << "Stamina: " << stamina << "/" << maxStamina << endl;
    cout << "Level: " << level << endl;
    cout << "XP: " << XP << "/" << maxXP << "\n\n";
}

void Character::setCharacterName(string setName)
{
    name = setName;
}

string Character::getName()
{
    return name;
}

void Character::Resting(int addHealth, int addStamina)
{
    if (health + addHealth > maxHealth)
    {
        health = maxHealth;
        return;
    }
    health += addHealth;

    if (stamina + addStamina > maxStamina)
    {
        stamina = maxStamina;
    }
    stamina += addStamina;
}

void Character::HealthItem(int addHealth, int addStamina)
{
    Resting(addHealth, addStamina); // dont know if this'll work
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