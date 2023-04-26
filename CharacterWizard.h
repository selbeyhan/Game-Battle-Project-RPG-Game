#ifndef CHARCTERWIZARD_H
#define CHARCTERWIZARD_H
#include "Character.h"

class Wizard : public Character
{
public:
    Wizard();
    int kick();
    int fireball();
};

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