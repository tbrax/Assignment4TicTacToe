

// ProxyMap.cpp
// Trace Braxling
// 1 May 2016
//
// For CS 372 Spring 2016
// Source file for Assignment 4, tic-tac-toe game
// Uses proxy design pattern

#include <iostream>
#include "TrueMap.h"
#include "ProxyMap.h"
#include <string>
#include <vector>
using namespace std;


//Call display function
void ProxyMap::displayMap()
{
    tictacMap.displayMap();
}

//Call reset function
void ProxyMap::reset()
{
    tictacMap.reset();
}

//Process input, pass it if vaild
void ProxyMap::takeInput(string s)
{
    if (s == "r" or s == "R" or s == "Reset" or s == "reset")
    {
        reset();
    }
    else if (s == "h" or s == "H" or s == "help" or s == "Help")
    {
        cout << endl << "You are playing tic-tac-toe against a computer." << endl;
        cout << "You are playing as 'X'. The computer is playing as 'O'." << endl;
        cout << "To make a move, simply look at the board and type in a number you can see to make a move in that spot"  << endl;
    }
    else
    {
        if (s == "9" or s == "1" or s == "2" or s == "3"
             or s == "4" or s == "5" or s == "6" or s == "7"
              or s == "8")
        {
            tictacMap.takeInput(s);
        }
        else
        {
            cout << endl << "Invalid move. Type 'h' for help" << endl;
        }

    }

}


