#ifndef CHARACTERWIZARD_H
#define CHARACTERWIZARD_H
#include <iostream>
#include <string>
#include "InputValidation.h"
#include "Character.h"

class Wizard : public Character
{
public:
    Wizard(string _name);
    int attack() override;
    void setAll(int info[]) override;
    int kick();
    int fireball();
};

Wizard::Wizard(string _name) : Character(_name)
{
    type = "Wizard";
}

int Wizard::attack()
{
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) Kick\n2) Fireball", 2);
    int damage;
    if (attackOption == 1)
    {
        damage = kick();
    }
    if (attackOption == 2)
    {
        damage = fireball();
    }
    return damage;
}

int Wizard::kick()
{
    int attackStaminaUse = 5;
    int attackDamage = 10;
    int attackCritGain = 1;
    cout << name << " Used A Kick!\nIt Did " << attackDamage << " Damage\n\n";
    if (stamina >= attackStaminaUse)
    {
        addCrit(attackCritGain);
        stamina -= attackStaminaUse;
        return attackDamage;
    }
    return -1;
}

int Wizard::fireball()
{
    int attackStaminaUse = 20;
    int attackDamage = 30;
    int attackCritUse = 2;
    cout << name << " Cast A Fireball!\nIt Did " << attackDamage << " Damage\n\n";
    if (stamina >= attackStaminaUse && crit >= attackCritUse)
    {
        removeCrit(attackCritUse);
        stamina -= attackStaminaUse;
        return attackDamage;
    }
    return -1; // error
}

void Wizard::setAll(int info[])
{
    Character::setAll(info);
}

#endif