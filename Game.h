#ifndef GAME_H
#define GAME_H
#include <fstream>
#include "InputValidation.h"
#include "Character.h"
#include "CharacterWarrior.h"
#include "CharacterWizard.h"

class Game
{
private:
    bool run = true;
    bool battle = false;
    Character *players[2];

public:
    Game();
    void NewGame();
    void LoadOldGame();
    void BattleRun();
};

Game::Game()
{
    cout << "Welcome To My RPG Game By Selman\n";
    int beginning = intReturnPrompt("1) Start New Game\n2) Load Old Game\n3) Quit Game", 3);
    if (beginning == 1)
    {
        NewGame();
    }
    if (beginning == 2)
    {
        LoadOldGame();
    }
    cout << "Thank you for playing!";
}

void Game::LoadOldGame()
{
    ifstream file;
    string fileName = stringReturnPrompt("Enter File Name, Example: gamedata.txt");
    file.open(fileName);
    // do the checking if it opens or fails or sum
    int const SIZE = 7;
    int attributes1[SIZE];
    int attributes2[SIZE];

    string Name1;
    string Name2;
    int temp;

    file >> Name1;

    for (unsigned int i = 0; i < SIZE; i++)
    {
        file.ignore();
        file >> temp;
        attributes1[i] = temp;
    }

    file >> Name2;

    for (unsigned int i = 0; i < SIZE; i++)
    {
        file.ignore();
        file >> temp;
        attributes2[i] = temp;
    }
    file.close();

    // Player 1
    if (attributes1[0] == 1)
    {
        players[0] = new Wizard(Name1);
        players[0]->health = attributes1[1];
        players[0]->maxHealth = attributes1[2];
        players[0]->stamina = attributes1[3];
        players[0]->maxStamina = attributes1[4];
        players[0]->level = attributes1[5];
        players[0]->XP = attributes1[6];
        players[0]->maxXP = attributes1[7];
    }

    if (attributes1[0] == 2)
    {
        players[0] = new Warrior(Name1);
        players[0]->health = attributes1[1];
        players[0]->maxHealth = attributes1[2];
        players[0]->stamina = attributes1[3];
        players[0]->maxStamina = attributes1[4];
        players[0]->level = attributes1[5];
        players[0]->XP = attributes1[6];
        players[0]->maxXP = attributes1[7];
    }

    /*
    if (attributes1[0] == 3) {
        players[0] = new Archer(Name1);
        players[0]->health = attributes1[1];
        players[0]->maxHealth = attributes1[2];
        players[0]->stamina = attributes1[3];
        players[0]->maxStamina = attributes1[4];
        players[0]->level = attributes1[5];
        players[0]->XP = attributes1[6];
        players[0]->maxXP = attributes1[7];
    }
    */

    // Player 2
    if (attributes2[0] == 1)
    {
        players[0] = new Wizard(Name1);
        players[0]->health = attributes2[1];
        players[0]->maxHealth = attributes2[2];
        players[0]->stamina = attributes2[3];
        players[0]->maxStamina = attributes2[4];
        players[0]->level = attributes2[5];
        players[0]->XP = attributes2[6];
        players[0]->maxXP = attributes2[7];
    }

    if (attributes2[0] == 2)
    {
        players[0] = new Warrior(Name1);
        players[0]->health = attributes2[1];
        players[0]->maxHealth = attributes2[2];
        players[0]->stamina = attributes2[3];
        players[0]->maxStamina = attributes2[4];
        players[0]->level = attributes2[5];
        players[0]->XP = attributes2[6];
        players[0]->maxXP = attributes2[7];
    }

    /*
    if (attributes2[0] == 3) {
        players[0] = new Archer(Name1);
        players[0]->health = attributes2[1];
        players[0]->maxHealth = attributes2[2];
        players[0]->stamina = attributes2[3];
        players[0]->maxStamina = attributes2[4];
        players[0]->level = attributes2[5];
        players[0]->XP = attributes2[6];
        players[0]->maxXP = attributes2[7];
    }
    */
}

void Game::NewGame()
{
    system("cls");
    string player1Name = stringReturnPrompt("Enter Player 1 Name");
    string player2Name = stringReturnPrompt("Enter Player 2 Name");
    int player1Choice = intReturnPrompt("Select A Character For " + player1Name + " \n1) Wizard\n2) Warrior\n3) Archer", 3);
    system("cls");
    int player2Choice = intReturnPrompt("Select A Character For " + player2Name + " \n1) Wizard\n2) Warrior\n3) Archer", 3);
    system("cls");

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
}

#endif
