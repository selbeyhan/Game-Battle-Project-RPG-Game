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
    string AttackInfo(int AttackName);

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
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) " + AttackInfo(1) + "\n2) " + AttackInfo(2), 2);
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

string Warrior::AttackInfo(int AttackName)
{
    string temp;
    if (AttackName == 1)
    {
        temp = "Sword Swing (" + to_string(SwordDamage) + " Damage, " + to_string(SwordStamina) + " Stamina)";
    }
    if (AttackName == 2)
    {
        temp = "M4 (" + to_string(M4A1SDamage) + " Damage, " + to_string(M4A1SStamina) + " Stamina, Requires " + to_string(M4A1SCrit) + " Crit)";
    }

    return temp;
}
#endif