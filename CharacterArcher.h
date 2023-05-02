#ifndef CHARACTERARCHER_H
#define CHARACTERARCHER_H
#include <iostream>
#include <string>
#include "InputValidation.h"
#include "Character.h"

class Archer : public Character
{
public:
    Archer(string _name);
    int attack() override;
    void setAll(int info[]) override;
    int Punch();
    int Bow();
    int Firebow();
    string AttackInfo(int AttackName);

private:
    // Punch
    int PunchStamina = 5;
    int PunchDamage = 10;
    int PunchCrit = 1;
    // Bow Attack
    int BowStamina = 10;
    int BowDamage = 20;
    int BowCrit = 2;
    // Firebow
    int FirebowStamina = 15;
    int FirebowDamage = 35;
    int FirebowCrit = 4;
};

Archer::Archer(string _name) : Character(_name)
{
    type = "Archer";
}

int Archer::attack()
{
    int damage;
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) " + AttackInfo(1) + "\n2) " + AttackInfo(2) + "\n3) " + AttackInfo(3) + "\n4) Rest (Gives 10 Stamina)", 4);
    if (attackOption == 1)
    {
        damage = Punch();
    }
    if (attackOption == 2)
    {
        damage = Bow();
    }
    if (attackOption == 3)
    {
        damage = Firebow();
    }
    if (attackOption == 4)
    {
        Resting(10);
    }
    return damage;
}

int Archer::Punch()
{
    if (stamina >= PunchStamina)
    {
        addCrit(PunchCrit);
        stamina -= PunchStamina;
        return PunchDamage;
    }
    return -1;
}

int Archer::Bow()
{
    if (stamina >= BowStamina && crit >= BowCrit)
    {
        removeCrit(BowCrit);
        stamina -= BowStamina;
        return BowDamage;
    }
    return -1; // error
}

int Archer::Firebow()
{
    if (stamina >= FirebowStamina && crit >= FirebowCrit)
    {
        removeCrit(FirebowCrit);
        stamina -= FirebowStamina;
        return FirebowDamage;
    }
    return -1; // error
}

void Archer::setAll(int info[])
{
    Character::setAll(info);
}

string Archer::AttackInfo(int AttackName)
{
    string temp;
    if (AttackName == 1)
    {
        temp = "Punch (" + to_string(PunchDamage) + " Damage, " + to_string(PunchStamina) + " Stamina)";
    }
    if (AttackName == 2)
    {
        temp = "Bow Attack (" + to_string(BowDamage) + " Damage, " + to_string(BowStamina) + " Stamina, Requires " + to_string(BowCrit) + " Crit)";
    }
    if (AttackName == 3)
    {
        temp = "Firebow Attack (" + to_string(FirebowDamage) + " Damage, " + to_string(FirebowStamina) + " Stamina, Requires " + to_string(FirebowCrit) + " Crit)";
    }
    return temp;
}

#endif