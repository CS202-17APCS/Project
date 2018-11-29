#include "Object.h"
#include "Animal.h"
#include "People.h"
#include "Vehicle.h"
#include <vector>
#include <string>
#include <conio.h>
//Any level will have 6 floors
const int maxfloors = 6;
//Set position for people 
const int UpPEOPLE = 0;//starting position
const int DownPEOPLE = 0;
const int LeftPEOPLE = 0;
const int RightPEOPLE = 0;
const int NumOfVe = 0;//set number of vehicle in a specific level
const int NumOfAni = 0;//set num of animal in a specific level
const int LeftEdge = 0;//Set left postion of game's screen
const int RightEdge = 0;//Set right postion ....
const int UpEdge = 0;//set up...
const int BelowEdge = 0;//set down...
const int LengthOb = 0;//set length of pix of an object(horizontal axis)
const int Height = 0;//set heigth of an object(vertical axis)
const int WidthEdge = 0;//set width between two rows
class CGAME {
	vector<CVEHICLE*> VE[2];
	vector<CANIMAL*> ANI[2];
	CPEOPLE PEOPLE;
	int Curlevel;//6 levels for a game
public:
	CGAME();
	void drawGame();
	~CGAME();
	bool FinishGame()//Check whether game is finished or not
	{
		return Curlevel == 6;
	}
	void getPeopleFile();//load game
	void getAnimalFile();//load game
	void getVehicleFile();//load game
	void getPeopleByDefault()//New game
	{
		PEOPLE=CPEOPLE(UpPEOPLE, DownPEOPLE, LeftPEOPLE, RightPEOPLE);//please change the coordinate of people
	}
	void getVehicleByDefault()//New game
	{
		int Distance = (RightEdge - LeftEdge - Curlevel * LengthOb) / Curlevel ;
		if (Curlevel != 1)
			Distance = (RightEdge - LeftEdge - Curlevel * LengthOb) / (Curlevel - 1);
		for (int i = 1; i < maxfloors-1; i+=2)
		{
			int startPos = LeftEdge;
			for(int j=0;j<Curlevel;j++)
			{
				CVEHICLE *tmp = new CCAR(BelowEdge + i * Height + Height, BelowEdge + i * Height, startPos, startPos + LengthOb,i+1);
				VE[i].push_back(tmp);
				delete tmp;
				startPos =startPos+LengthOb+Distance;//startpos+=distance
				if (startPos >= RightEdge)
					break;
			}
		}
	}
	void getAnimalByDefault()//New game
	{
		int Distance = (RightEdge - LeftEdge - Curlevel * LengthOb) / Curlevel;
		if (Curlevel != 1)
			Distance = (RightEdge - LeftEdge - Curlevel * LengthOb) / (Curlevel - 1);
		for (int i = 1; i < maxfloors - 1; i += 2)
		{
			int startPos = RightEdge;
			for (int j = 0; j<Curlevel; j++)
			{
				CANIMAL *tmp = new CBIRD(BelowEdge + i * Height + Height, BelowEdge + i * Height, startPos-LengthOb, startPos,i+1);
				ANI[i].push_back(tmp);
				delete tmp;
				startPos = startPos - LengthOb - Distance;//startpos+=distance
				if (startPos <= LeftEdge)
					break;
			}
		}
	}
	void resetGame()
	{
		//delete all and set default again
	}
	void exitGame(HANDLE);
	void startGame()
	{
		//Check Button
		//Preparing database for game
		getPeopleByDefault();
		getAnimalByDefault();
		getVehicleByDefault();
	    //drawing game
	}
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE key)
	{
		if (key == "p" || key == "P")
			resumeGame();//waiting for user to enter P
		//After pressing p go on printing out the console
	}
	void resumeGame()
	{
		char c = _getch();
		while (c != 'P' &&c != 'p')
		{
			c = _getch();
		}
		//After pressing p go on printing out the console
	}
	void updatePosPeople(char c)
	{
		if (c == 'W')
		{
			if (PEOPLE.isFinish(maxfloors))
			{
				//go to next level
				if (FinishGame())
				{
					//finish game
				}
				else
				{
					Curlevel++;
				    //Drawing game again with new parameters
				}
			}
			else
			{
				PEOPLE.GoUp();
			}
		}
		else if (c == 'A')
		{
			PEOPLE.Left();
		}
		else if (c == 'S')
		{
			PEOPLE.Down();
		}
		else if (c == 'D')
		{
			PEOPLE.Right();
		}
	}
	void updatePosVehicle()
	{
		for (int i = 1; i < maxfloors; i += 2)
		{
			for (int j = 0; j < VE[i].size(); j++)
			{
				VE[i][j]->GoRight();//Vehicle goes right
			}
		}
	}
	void updatePosAnimal()
	{
		for (int i = 1; i < maxfloors; i += 2)
		{
			for (int j = 0; j < ANI[i].size(); j++)
			{
				ANI[i][j]->GoLeft();//Animal goes left
			}
		}
	}
};

