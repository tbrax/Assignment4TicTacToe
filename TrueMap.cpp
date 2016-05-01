
// TrueMap.cpp
// Trace Braxling
// 1 May 2016
//
// For CS 372 Spring 2016
// Source file for Assignment 4, tic-tac-toe game
// Uses proxy design pattern

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "TrueMap.h"
using namespace std;


//Constructor
TrueMap::TrueMap()
{
    srand(time(NULL));
    theGameMap = {0,0,0,0,0,0,0,0,0};
    compCanPlay = false;
}

//Display X,O, or a number
char turnNumToText(int i,int x)
{
    if (i == 1)
    {
        return 'X';
    }

    else if (i == 2)
    {
        return 'O';
    }
    else
    {
        return x+49;
    }
}

//Reset the board
void TrueMap::reset()
{
    vector<int> compare {0,0,0,0,0,0,0,0,0};
    if (theGameMap != compare)
        {
            theGameMap = {0,0,0,0,0,0,0,0,0};
            compCanPlay = false;
            cout << "Starting new game.." << endl;
        }

}



//Display the board
void TrueMap::displayMap()
{
    cout << endl << turnNumToText(getMap(0),0) << "|" << turnNumToText(getMap(1),1) << "|" << turnNumToText(getMap(2),2) << endl;
    cout << "-----" << endl;
    cout << turnNumToText(getMap(3),3) << "|" << turnNumToText(getMap(4),4) << "|" << turnNumToText(getMap(5),5) << endl;
    cout << "-----" << endl;
    cout << turnNumToText(getMap(6),6) << "|" << turnNumToText(getMap(7),7) << "|" << turnNumToText(getMap(8),8) << endl << endl;
}

//Access function
int TrueMap::getMap(int i)
{
    return theGameMap[i];
}

//Check game end conditions
void TrueMap::checkWin()
{

    bool wasWon = false;

    if (theGameMap[0] == 1 && theGameMap[1] == 1 && theGameMap[2] == 1)
    {
        cout << "You won across the top row!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[3] == 1 && theGameMap[4] == 1 && theGameMap[5] == 1)
    {
        cout << "You won across the middle top row!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[6] == 1 && theGameMap[7] == 1 && theGameMap[8] == 1)
    {
        cout << "You won across the middle top row!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[0] == 1 && theGameMap[4] == 1 && theGameMap[8] == 1)
    {
        cout << "You won diagonally!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[2] == 1 && theGameMap[4] == 1 && theGameMap[6] == 1)
    {
        cout << "You won diagonally!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[0] == 1 && theGameMap[3] == 1 && theGameMap[6] == 1)
    {
        cout << "You won down the left column!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[1] == 1 && theGameMap[4] == 1 && theGameMap[7] == 1)
    {
        cout << "You won down the middle column!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[2] == 1 && theGameMap[5] == 1 && theGameMap[8] == 1)
    {
        cout << "You won down the right column!" << endl;
        wasWon = true;
        reset();
    }

    //////

    if (theGameMap[0] == 2 && theGameMap[1] == 2 && theGameMap[2] == 2)
    {
        cout << "The computer won across the top row!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[3] == 2 && theGameMap[4] == 2 && theGameMap[5] == 2)
    {
        cout << "The computer won across the middle top row!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[6] == 2 && theGameMap[7] == 2 && theGameMap[8] == 2)
    {
        cout << "The computer won across the middle top row!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[0] == 2 && theGameMap[4] == 2 && theGameMap[8] == 2)
    {
        cout << "The computer won diagonally!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[2] == 2 && theGameMap[4] == 2 && theGameMap[6] == 2)
    {
        cout << "The computer won diagonally!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[0] == 2 && theGameMap[3] == 2 && theGameMap[6] == 2)
    {
        cout << "The computer won down the left column!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[1] == 2 && theGameMap[4] == 2 && theGameMap[7] == 2)
    {
        cout << "The computer won down the middle column!" << endl;
        wasWon = true;
        reset();
    }

    if (theGameMap[2] == 2 && theGameMap[5] == 2 && theGameMap[8] == 2)
    {
        cout << "The computer won down the right column!" << endl;
        wasWon = true;
        reset();
    }

        if (theGameMap[0] != 0 && theGameMap[1] != 0 && theGameMap[2] != 0
        && theGameMap[3] != 0&& theGameMap[4] != 0&& theGameMap[5] != 0
        && theGameMap[6] != 0&& theGameMap[7] != 0&& theGameMap[8] != 0 && wasWon == false)
    {
        cout << "The game was a tie!" << endl;
        reset();
    }


}

//See if move has already been made
bool TrueMap::checkMove(int i)
{
    if (theGameMap[i] == 0)
    {
        return true;
    }
    else
    {
        cout << "You cannot make that move!" << endl;
        return false;
    }

}

//The computer makes a random move
void TrueMap::compPlay()
{
    if (compCanPlay)
    {
        bool moved = false;
        while(moved == false)
        {
            int doMove = rand() % 8;

            if(theGameMap[doMove] == 0)
            {
                theGameMap[doMove] = 2;
                moved = true;
            }
        }
    }
    checkWin();
}

//Can't display error messages, relies on proxymap
//Process the player move
void TrueMap::takeInput(string s)
{

    //My compiler currently can't do string to int conversion, so I do this for now...
    if (s == "1")
    {
        if (checkMove(0))
        {
            theGameMap[0] = 1;
        }
    }

    else if (s == "2")
    {
        if (checkMove(1))
        {
            theGameMap[1] = 1;
        }
    }
        else if (s == "3")
    {
        if (checkMove(2))
        {
            theGameMap[2] = 1;
        }
    }
        else if (s == "4")
    {
        if (checkMove(3))
        {
            theGameMap[3] = 1;
        }
    }
        else if (s == "5")
    {
        if (checkMove(4))
        {
            theGameMap[4] = 1;
        }
    }
        else if (s == "6")
    {
        if (checkMove(5))
        {
            theGameMap[5] = 1;
        }
    }
        else if (s == "7")
    {
        if (checkMove(6))
        {
            theGameMap[6] = 1;
        }
    }
        else if (s == "8")
    {
        if (checkMove(7))
        {
            theGameMap[7] = 1;
        }
    }
        else if (s == "9")
    {
        if (checkMove(8))
        {
            theGameMap[8] = 1;
        }
    }
    compCanPlay = true;
    checkWin();
    compPlay();
}





