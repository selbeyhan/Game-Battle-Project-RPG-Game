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

private:
    // Sword
    int SwordStamina = 5;
    int SwordDamage = 10;
    int SwordCrit = 1;
    // M4A1S
    int M4A1SStamina = 20;
    int M4A1SDamage = 30;
    int M4A1SCrit = 2;
};

Warrior::Warrior(string _name) : Character(_name)
{
    type = "Warrior";
}

int Warrior::attack()
{
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) Sword Swing (" + SwordDamage + "Damage)\n2) M4A1S (Gun)", 2);
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
    if (stamina >= SwordStamina)
    {
        addCrit(SwordCrit);
        stamina -= SwordStamina;
        return SwordDamage;
    }
    return -1;
}

int Warrior::M4A1S()
{
    if (stamina >= M4A1SStamina && crit >= M4A1SCrit)
    {
        removeCrit(M4A1SCrit);
        stamina -= M4A1SStamina;
        return M4A1SDamage;
    }
    return -1; // error
}

void Warrior::setAll(int info[])
{
    Character::setAll(info);
}

#endif