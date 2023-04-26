#include <iostream>
#include "InputValidation.h"
#include "Character.h"
#include "CharacterWizard.h"
#include "CharacterWarrior.h"
using namespace std;

// system("cls");

int main()
{
    // Create character
    string player1Name = stringReturnPrompt("Enter Player 1 Name");
    string player2Name = stringReturnPrompt("Enter Player 2 Name");

    system("cls");

    int player1Choice = intReturnPrompt("Select A Character For " + player1Name + " \n1) Wizard\n2) Warrior\n3) Archer\n4) Load From File", 4);
    system("cls");
    int player2Choice = intReturnPrompt("Select A Character For " + player2Name + " \n1) Wizard\n2) Warrior\n3) Archer\n4) Load From File", 4);

    Character *players[2];

    if (player1Choice == 1)
    {
        Wizard *player1 = new Wizard(player1Name);
        players[0] = player1;
    }
    else if (player1Choice == 2)
    {
        Warrior *player1 = new Warrior(player1Name);
        players[0] = player1;
    }

    if (player2Choice == 1)
    {
        Wizard *player2 = new Wizard(player2Name);
        players[1] = player2;
    }
    else if (player2Choice == 2)
    {
        Warrior *player2 = new Warrior(player2Name);
        players[1] = player2;
    }

    bool run = true;
    while (run)
    {
        system("cls");
        cout << "Dueling " << player1Name << " and " << player2Name << "\n\n";
        players[0]->printStats();
        players[1]->printStats();
        int dmg = players[0]->attack();
        if (dmg > 0)
        {
            players[1]->takeDamage(dmg);
        }
        int shouldRun = intReturnPrompt("Should Continue 1 or 2", 2);
        if (shouldRun == 2)
        {
            run = false;
        }
    }
}