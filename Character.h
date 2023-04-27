#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include "InputValidation.h"
using namespace std;

class Character
{
protected:
    string type;
    bool alive;
    string name;
    int maxHealth;
    int maxStamina;
    int maxCrit;
    int health;
    int stamina;
    int crit;

public:
    Character(string _name);
    virtual void printStats();
    void setCharacterName(string setName);
    string getName();
    void Resting(int addHealth, int addStamina);
    void HealthItem(int addHealth, int addStamina);
    void addCrit(int _crit);
    void removeCrit(int _crit);
    void takeDamage(int damage);
    bool isAlive() { return alive; };
    virtual int attack() = 0;
    virtual void setAll(int info[]);
};

Character::Character(string _name)
{
    name = _name;
    alive = true;
    maxHealth = 100;
    maxStamina = 100;
    health = maxHealth;
    stamina = maxStamina;
    crit = 0;
    maxCrit = 10;
}

void Character::printStats()
{
    cout << name << " (" << type << ")" << endl;
    cout << "Health: " << health << "/" << maxHealth << endl;
    cout << "Stamina: " << stamina << "/" << maxStamina << endl;
    cout << "Crit: " << crit << "/" << maxCrit << "\n\n";
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
void Character::addCrit(int _crit)
{
    if (crit + _crit > maxCrit)
    {
        crit = maxCrit;
        return;
    }
    crit += _crit;
}

void Character::removeCrit(int _crit)
{
    if (crit - _crit >= 0)
    {
        crit -= _crit;
        return;
    }
    crit = 0; // if error occured then it'll be set to 0
}

void Character::takeDamage(int damage)
{
    if (health - damage <= 0)
    {
        alive = false;
        health = 0;
        return;
    }

    health -= damage;
}

void Character::setAll(int info[])
{
    health = info[1];
    maxHealth = info[2];
    stamina = info[3];
    maxStamina = info[4];
    crit = info[5];
    maxCrit = info[6];
}

#endif