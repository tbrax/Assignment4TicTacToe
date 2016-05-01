
// main.cpp
// Trace Braxling
// 1 May 2016
//
// For CS 372 Spring 2016
// Main file for Assignment 4, tic-tac-toe game
// Uses proxy design pattern

#include <iostream>
#include "TrueMap.h"
#include "ProxyMap.h"

using namespace std;

int main()
{
    ProxyMap p;
    string text;
    cout << "Welcome to tic-tac-toe!" << endl;
    cout << "You can start playing, or press 'h' for help!" << endl << endl;
    while(true)
    {
        p.displayMap();
        getline (cin,text);
        p.takeInput(text);
    }

    return 0;
}
