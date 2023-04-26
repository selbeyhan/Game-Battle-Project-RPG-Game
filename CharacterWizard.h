#ifndef CHARCTERWIZARD_H
#define CHARCTERWIZARD_H
#include "Character.h"

class Wizard : public Character
{
public:
    Wizard(string _name);
    void attack() override;
    int kick();
    int fireball();
};

Wizard::Wizard(string _name) : Character(_name)
{
    type = "Wizard";
}

int Wizard::kick()
{
    if (stamina > 5)
    {
        return 10;
    }
}

int Wizard::fireball()
{
    if (stamina > 10 && level >= 1)
    {
        return 30;
    }
}
#endif