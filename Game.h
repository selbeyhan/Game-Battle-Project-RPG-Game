#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "InputValidation.h"
#include "Character.h"
#include "CharacterWarrior.h"
#include "CharacterWizard.h"
using namespace std;
class Game
{
private:
    // bool run = true;
    // bool battle = false;
    string OS;
    Character *players[2];

public:
    Game();
    void SetOS();
    void ClearT();
    void SequelOptions();
    void MakeNewGame();
    void LoadOldGame();
    void BattleRun();
    void saveGame();
    void End();
};

Game::Game()
{
    SetOS();
    ClearT();
    cout << "Welcome To My RPG Game By Selman\n";
    int choice = intReturnPrompt(" 1) Start New Game\n 2) Load Old Game\n 3) Quit And Save Game \n 4) Quit Game", 4);
    if (choice == 1)
    {
        MakeNewGame();
    }
    if (choice == 2)
    {
        LoadOldGame();
    }
    if (choice == 3)
    {
        saveGame();
    }
    if (choice == 4)
    {
        End();
    }
}

void Game::SetOS()
{
#if __APPLE__
    OS = "APPLE";
#endif

#if _WIN32
    OS = "WIN";
#endif
}

void Game::ClearT()
{
    if (OS == "APPLE")
    {
        system("clear");
        return;
    }
    if (OS == "WIN")
    {
        system("cls");
        return;
    }
}

void Game::SequelOptions()
{
    int choice = intReturnPrompt(" 1) Battle\n 2) Quit And Save Game \n 3) Quit Game", 3);
    if (choice == 1)
    {
        BattleRun();
    }
    if (choice == 2)
    {
        saveGame();
        End();
    }
    if (choice == 3)
    {
        End();
    }
}

void Game::LoadOldGame()
{
    string fileName = stringReturnPrompt("Enter File Name (Inlucude .txt)");
    ifstream file(fileName);

    //  do the checking if it opens or fails or sum
    if (!file.is_open())
    {
        cout << "File Counldn't Be Opened\n";
        return;
    }

    int const SIZE = 7;
    int characterInfo1[SIZE];
    int characterInfo2[SIZE];

    string Name1;
    string Name2;
    string skip;
    int temp;

    file >> skip;
    file >> Name1;

    for (unsigned int i = 0; i < SIZE; i++)
    {
        file >> skip;
        file >> temp;
        characterInfo1[i] = temp;
    }

    file >> skip;
    file >> Name2;

    for (unsigned int i = 0; i < SIZE; i++)
    {
        file >> skip;
        file >> temp;
        characterInfo2[i] = temp;
    }
    file.close();

    // Player 1
    if (characterInfo1[0] == 1)
    {
        players[0] = new Wizard(Name1);
        players[0]->setAll(characterInfo1);
    }
    if (characterInfo1[0] == 2)
    {
        players[0] = new Warrior(Name1);
        players[0]->setAll(characterInfo1);
    }
    /*
    if (characterInfo1[0] == 3) {
        players[0] = new Archer(Name1);
        players[0]->setAll(characterInfo1);
    }
    */

    // Player 2
    if (characterInfo2[0] == 1)
    {
        players[1] = new Wizard(Name2);
        players[1]->setAll(characterInfo2);
    }
    if (characterInfo2[0] == 2)
    {
        players[1] = new Warrior(Name2);
        players[1]->setAll(characterInfo2);
    }
    /*
    if (characterInfo2[0] == 3) {
        players[1] = new Archer(Name1);
        players[1]->setAll(characterInfo2);
    }
    */

    cout << "Load Successful\n\n"
         << Name1 << " vs. " << Name2 << endl;
    SequelOptions();
}

void Game::MakeNewGame()
{
    ClearT();
    string player1Name = stringReturnPrompt("Enter Player 1 Name");
    ClearT();
    string player2Name = stringReturnPrompt("Enter Player 2 Name");
    ClearT();
    int player1Choice = intReturnPrompt("Select A Character For " + player1Name + " \n1) Wizard\n2) Warrior\n3) Archer", 3);
    ClearT();
    int player2Choice = intReturnPrompt("Select A Character For " + player2Name + " \n1) Wizard\n2) Warrior\n3) Archer", 3);
    ClearT();

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

    SequelOptions();
}

void Game::BattleRun()
{
    int damage;
    int quit;
    while (players[0]->isAlive() && players[1]->isAlive())
    {
        ClearT();
        players[0]->printStats();
        players[1]->printStats();

        damage = players[0]->attack();
        if (damage >= 0)
        {
            players[1]->takeDamage(damage);
        }

        damage = players[1]->attack();
        if (damage >= 0)
        {
            players[0]->takeDamage(damage);
        }

        quit = intReturnPrompt("Continue Or Quit Battle\n1) Continue\n2) Quit Battle", 2);
        if (quit == 2)
        {
            break;
        }
    }
    SequelOptions();
}

void Game::saveGame()
{
    string saveLocation = "GameData.txt";
    int autoSave = intReturnPrompt("1) Auto Save (Destination: \\" + saveLocation + "))\n2) Custom Save", 2);
    if (autoSave == 2)
    {
        string saveLocation = stringReturnPrompt("Custom Save File Name (include .txt)");
    }

    // start saving
    ofstream file(saveLocation);
    if (!file.is_open())
    {
        cout << "Failed To Open Save Location";
        return;
    }
    file << players[0]->getAllInfo() << players[1]->getAllInfo();
    file.close();
}

void Game::End()
{
    // for (int i = 0; i < 2; i++)
    // {
    //     delete players[i];
    // }
    // delete[] players;
    cout << "Thank you for playing!"; // add art
}

#endif
