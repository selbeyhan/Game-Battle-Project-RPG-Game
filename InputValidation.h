#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <iostream>
#include <string>
using namespace std;

int intReturnPrompt(string InputText, int numOptions)
{
    int input;
    while (true)
    {
        cout << InputText << "\n\t> ";
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Re-enter a valid value!\n\t";
        }
        else
        {
            if (!(input >= 1 && input <= numOptions))
            {
                cout << "Re-enter a valid value!\n\t";
            }
            else
                break;
        }
    }
    return input;
}

string stringReturnPrompt(string InputText)
{
    string input;
    while (true)
    {
        cout << InputText << "\n\t> ";
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Re-enter a valid value!\n";
        }
        else
            break;
    }
    return input;
}

#endif