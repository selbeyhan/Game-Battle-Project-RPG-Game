#include <iostream>
#include "InputValidation.h"
#include "Character.h"
#include "CharacterWizard.h"
using namespace std;

// system("clear");

int main()
{
    // Create character

    int choice = intReturnPrompt("Select A Character For Player 1\n1) Wizard\n2) Warrior\n3) Archer\n4) Load From File", 4);
    int choice2 = intReturnPrompt("Select A Character For Player 2\n1) Wizard\n2) Warrior\n3) Archer\n4) Load From File", 4);

    int myArr[2];
    Character *players[2];

    if (choice == 1)
    {
        Wizard *player1 = new Wizard();
        players[0] = player1;
    }
    if (choice2 == 1)
    {
        Wizard player2;
    }

    bool run = true;
    while (run)
    {
        // player1
    }
}