#ifndef CHARCTERWARRIOR_H
#define CHARCTERWARRIOR_H
#include "InputValidation.h"
#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(string _name);
    int attack() override;
    int swordSwing();
    int M4A1S();
    void setAll(int info[]) override;
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
    if (stamina > 5)
    {
        AddXp(1);
        stamina -= 5;
        return 10;
    }
    return -1;
}

int Warrior::M4A1S()
{
    if (stamina > 20 && level > 1)
    {
        stamina -= 20;
        return 30;
    }
    return -1;
}

void Warrior::setAll(int info[])
{
    health = info[1];
    maxHealth = info[2];
    stamina = info[3];
    maxStamina = info[4];
    level = info[5];
    XP = info[6];
    maxXP = info[7];
}
#endif