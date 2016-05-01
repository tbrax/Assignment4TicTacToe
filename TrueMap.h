
// TrueMap.h
// Trace Braxling
// 1 May 2016
//
// For CS 372 Spring 2016
// Header file for Assignment 4, tic-tac-toe game
// Uses proxy design pattern

#ifndef TRUEMAP_H_INCLUDED
#define TRUEMAP_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrueMap
{

    public :
          TrueMap();
         int getMap(int);
         void displayMap();
         void takeInput(string);
         bool checkMove(int);
         void reset();
         void checkWin();
         void compPlay();
    private :

          bool compCanPlay;
          vector<int> theGameMap;

};

#endif
