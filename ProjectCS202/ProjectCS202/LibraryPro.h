#ifndef _LibraryPro_
#define _LibraryPro_
#include <vector>
#include <string>
#include <conio.h>
#include <iostream>
#include <Windows.h>
//#include "Utils.h"
//Any level will have 6 floors
const int maxfloors = 8;
const int maxfloorsForAni = 6;
const int maxfloorsForVe = 6;
//Set position for people 
const int UpPEOPLE = 0;//starting position
const int DownPEOPLE = 0;
const int LeftPEOPLE = 0;
const int RightPEOPLE = 0;
const int NumOfVe = 3;//set number of vehicle in a specific level
const int NumOfAni = 3;//set num of animal in a specific level
const int LeftEdge = 0;//Set left postion of game's screen
const int RightEdge = 165;//Set right postion ....
const int UpEdge = 0;//set up...
const int BelowEdge = 44;//set down...
const int LengthOb = 0;//set length of pix of an object(horizontal axis)
const int Height = 4;//set heigth of an object(vertical axis)
const int WidthEdge = 6;//set width between two rows
//adding
const int XCorOfVe = 0;
const int YCorOfVe = 31;
const int YCorOfAni = 37;
const int XCorOfAni = 165;
const int XCorOfHuman = 50;
const int YCorOfHuman = 37;
const int LengthVe = 20;
const int LengthAni = 9;
const int LengthHuman = 4;
const int LengthBetweenRows = 14;//Rows of same Objects(car-car ,dog-dog)
const int LengthBetweenOb = 7;//Rows of dif Objects
const int Step = 5;
#endif
