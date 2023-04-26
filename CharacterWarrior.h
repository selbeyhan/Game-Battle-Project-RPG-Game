#ifndef CHARCTERWARRIOR_H
#define CHARCTERWARRIOR_H
#include "InputValidation.h"
#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(string _name);
    void attack() override;
    int swordSwing();
    int M4A1S();
};

Warrior::Warrior(string _name) : Character(_name)
{
    type = "Warrior";
}

void Warrior::attack()
{
    
}

int Warrior::swordSwing()
{
    if (stamina > 5)
    {
        return 10;
    }
}

#endif