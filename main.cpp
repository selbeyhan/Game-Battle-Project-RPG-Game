#include <iostream>
#include "InputValidation.h"
#include "Character.h"
#include "CharacterWizard.h"
using namespace std;

// system("cls");

int main()
{
    // Create character
    string player1Name = stringReturnPrompt("Enter Player 1 Name");
    string player2Name = stringReturnPrompt("Enter Player 2 Name");

    system("cls");

    int choice = intReturnPrompt("Select A Character For " + player1Name + " \n1) Wizard\n2) Warrior\n3) Archer\n4) Load From File", 4);
    int choice2 = intReturnPrompt("Select A Character For " + player2Name + " \n1) Wizard\n2) Warrior\n3) Archer\n4) Load From File", 4);

    Character *players[2];

    if (choice == 1)
    {
        Wizard *player1 = new Wizard(player1Name);
        players[0] = player1;
    }
    if (choice2 == 1)
    {
        Wizard *player2 = new Wizard(player2Name);
        players[1] = player2;
    }

    bool run = true;
    while (!run)
    {
        // player1
    }
}