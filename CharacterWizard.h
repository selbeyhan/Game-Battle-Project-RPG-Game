#ifndef CHARCTERWIZARD_H
#define CHARCTERWIZARD_H
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
    int attackOption = intReturnPrompt("Select An Attack (" + name + ")\n1) Sword Swing\n2) M4A1S (Gun)", 2);
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
    if (stamina > 5)
    {
        addCrit(1);
        stamina -= 5;
        return 10;
    }
    return -1;
}

int Wizard::fireball()
{
    if (stamina > 20 && crit > 2)
    {
        removeCrit(2);
        stamina -= 20;
        return 30;
    }
    return -1; // error
}

void Wizard::setAll(int info[])
{
    Character::setAll(info);
}

#endif