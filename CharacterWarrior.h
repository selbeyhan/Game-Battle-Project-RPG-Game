#ifndef CHARACTERWARRIOR_H
#define CHARACTERWARRIOR_H
#include <iostream>
#include <string>
#include "InputValidation.h"
#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(string _name);
    int attack() override;
    void setAll(int info[]) override;
    int swordSwing();
    int M4A1S();
};

Warrior::Warrior(string _name) : Character(_name)
{
    type = "Warrior";
}

int Warrior::attack()
{
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) Sword Swing\n2) M4A1S (Gun)", 2);
    int damage;
    if (attackOption == 1)
    {
        damage = swordSwing();
    }
    if (attackOption == 2)
    {
        damage = M4A1S();
    }
    return damage;
}

int Warrior::swordSwing()
{
    int attackStaminaUse = 5;
    int attackDamage = 10;
    int attackCritGain = 1;
    cout << name << " Used A Sword!\nIt Did " << attackDamage << " Damage\n\n";
    if (stamina >= attackStaminaUse)
    {
        addCrit(attackCritGain);
        stamina -= attackStaminaUse;
        return attackDamage;
    }
    return -1;
}

int Warrior::M4A1S()
{
    int attackStaminaUse = 20;
    int attackDamage = 30;
    int attackCritUse = 2;
    cout << name << " Used A Gun!\nIt Did " << attackDamage << " Damage\n\n";
    if (stamina >= attackStaminaUse && crit >= attackCritUse)
    {
        removeCrit(attackCritUse);
        stamina -= attackStaminaUse;
        return attackDamage;
    }
    return -1; // error
}

void Warrior::setAll(int info[])
{
    Character::setAll(info);
}

#endif