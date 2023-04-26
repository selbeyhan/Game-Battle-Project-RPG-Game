#ifndef CHARCTERWIZARD_H
#define CHARCTERWIZARD_H
#include "Character.h"

class Wizard : public Character
{
public:
    Wizard(string _name);
    int attack() override;
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
        AddXp(1);
        stamina -= 5;
        return 10;
    }
    return -1;
}

int Wizard::fireball()
{
    if (stamina > 20 && level >= 1)
    {
        stamina -= 20;
        return 30;
    }
    return -1;
}
#endif