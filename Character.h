#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

class Character
{
protected:
    string type;
    string name;
    int level;
    int health;
    int maxHealth = 100;
    int maxStamina = 100;
    int XP = 0;

public:
    void setCharacterName(string setName);
    string getName();
    void Resting(int addHealth);
    void HealthItem(int addHealth);
    void AddXp(int addXp); // think about linear (same xp for each level )or progressive (more xp for every level)
    void takeDamage(int damage);
};

class Wizard : Character
{

public:
    void kick();
    void fireball();
};

#endif