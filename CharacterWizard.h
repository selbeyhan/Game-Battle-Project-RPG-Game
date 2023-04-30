#ifndef CHARACTERWIZARD_H
#define CHARACTERWIZARD_H
#include <iostream>
#include <string>
#include "InputValidation.h"
#include "Character.h"

class Wizard : public Character
{
private:
    // Kick
    int KickStamina = 5;
    int KickDamage = 10;
    int KickCrit = 1;
    // Fireball
    int FireballStamina = 20;
    int FireballDamage = 30;
    int FireballCrit = 2;

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
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) Kick (" + to_string(KickDamage) + " Damage)\n2) Fireball (" + to_string(FireballDamage) + " Damage, Requires " + to_string(FireballCrit) + " Crit)", 2);
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
    if (stamina >= KickStamina)
    {
        addCrit(KickCrit);
        stamina -= KickStamina;
        return KickDamage;
    }
    return -1;
}

int Wizard::fireball()
{
    if (stamina >= FireballStamina && crit >= FireballCrit)
    {
        removeCrit(FireballCrit);
        stamina -= FireballStamina;
        return FireballDamage;
    }
    return -1; // error
}

void Wizard::setAll(int info[])
{
    Character::setAll(info);
}

#endif