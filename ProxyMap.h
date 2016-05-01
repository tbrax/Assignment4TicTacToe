
// ProxyMap.h
// Trace Braxling
// 1 May 2016
//
// For CS 372 Spring 2016
// Header file for Assignment 4, tic-tac-toe game
// Uses proxy design pattern

#ifndef PROXYMAP_H_INCLUDED
#define PROXYMAP_H_INCLUDED
#include <iostream>
using namespace std;

class ProxyMap
{
    public :
        void takeInput(string);
        void reset();
        void displayMap();

    private :
        TrueMap tictacMap;


};

#endif
