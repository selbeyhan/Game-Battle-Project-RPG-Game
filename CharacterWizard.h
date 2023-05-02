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
    int Staff();
    int fireball();
    string AttackInfo(int AttackName);

private:
    // Kick
    int KickStamina = 5;
    int KickDamage = 10;
    int KickCrit = 1;
    // Staff Wack
    int StaffStamina = 10;
    int StaffDamage = 20;
    int StaffCrit = 2;
    // Fireball
    int FireballStamina = 15;
    int FireballDamage = 35;
    int FireballCrit = 4;
};

Wizard::Wizard(string _name) : Character(_name)
{
    type = "Wizard";
}

int Wizard::attack()
{
    int damage;
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) " + AttackInfo(1) + "\n2) " + AttackInfo(2) + "\n3) " + AttackInfo(3) + "\n4) Rest (Gives 10 Stamina)", 4);
    if (attackOption == 1)
    {
        damage = kick();
    }
    if (attackOption == 2)
    {
        damage = Staff();
    }
    if (attackOption == 3)
    {
        damage = fireball();
    }
    if (attackOption == 4)
    {
        Resting(10);
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

int Wizard::Staff()
{
    if (stamina >= StaffStamina && crit >= StaffCrit)
    {
        removeCrit(StaffCrit);
        stamina -= StaffStamina;
        return StaffDamage;
    }
    return -1; // error
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

string Wizard::AttackInfo(int AttackName)
{
    string temp;
    if (AttackName == 1)
    {
        temp = "Kick (" + to_string(KickDamage) + " Damage, " + to_string(KickStamina) + " Stamina)";
    }
    if (AttackName == 2)
    {
        temp = "Staff Wack (" + to_string(StaffDamage) + " Damage, " + to_string(StaffStamina) + " Stamina, Requires " + to_string(StaffCrit) + " Crit)";
    }
    if (AttackName == 3)
    {
        temp = "Fireball (" + to_string(FireballDamage) + " Damage, " + to_string(FireballStamina) + " Stamina, Requires " + to_string(FireballCrit) + " Crit)";
    }

    return temp;
}

#endif