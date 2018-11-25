#include "Object.h"
#include "Animal.h"
#include "People.h"
#include "Vehicle.h"
#include <vector>
#include <string>
//Any level will have 12 floors
const int maxfloors = 12;
//Set position for people 
const int UpPEOPLE = 0;//starting position
const int DownPEOPLE = 0;
const int LeftPEOPLE = 0;
const int RightPEOPLE = 0;
const int NumOfVe = 15;//set number of vehicle in a specific level
const int NumOfAni = 15;//set num of animal in a specific level
const int LeftEdge = 0;//Set left postion of game's screen
const int RightEdge = 0;//Set right postion ....
const int UpEdge = 0;//set up...
const int BelowEdge = 0;//set down...
const int LengthOb = 0;//set length of pix of an object(horizontal axis)
const int Height = 0;//set heigth of an object(vertical axis)
const int WidthEdge = 0;//set width between two rows
class CGAME {
	vector<CVEHICLE*> VE[5];
	vector<CANIMAL*> ANI[5];
	CPEOPLE PEOPLE;
	int Curlevel;
public:
	CGAME();
	void drawGame();
	bool IncLevel()//increasing currentlevel and check if people have completed the game
	{
		if (Curlevel == 6)
		{
			//ENDGAME
			return true;
		}
		else
		{
			Curlevel++;
			//drawing a new screen for next level
			return false;
		}
	}
	~CGAME();
	void getPeopleFile();//load game
	void getAnimalFile();//load game
	void getVehicleFile();//load game
	void getPeopleByDefault()//New game
	{
		PEOPLE=CPEOPLE(UpPEOPLE, DownPEOPLE, LeftPEOPLE, RightPEOPLE);//please change the coordinate of people
	}
	void getVehicleByDefault()//New game
	{
		int Distance = 0;
		for (int i = 1; i < maxfloors-1; i+=2)
		{
			int startPos = LeftEdge;
			while (startPos + LengthOb <= RightEdge)
			{
				CVEHICLE *tmp = new CCAR(BelowEdge + i * Height + Height, BelowEdge + i * Height, startPos, startPos + LengthOb);
				VE[i].push_back(tmp);
				delete tmp;
				startPos += Distance;//startpos+=distance
			}
		}
	}
	void getAnimalByDefault()//New game
	{
		int Distance = 0;
		for (int i = 2; i < maxfloors-1; i += 2)
		{
			int startPos = RightEdge;
			while (startPos - LengthOb >= LeftEdge)
			{
				CANIMAL *tmp = new CBIRD(BelowEdge + i * Height + Height, BelowEdge + i * Height, startPos-LengthOb, startPos);
				ANI[i].push_back(tmp);
				delete tmp;
				startPos -= Distance;//startpos-=distance
			}
		}
	}
	void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	void updatePosPeople(char c)
	{
		if (c == 'W')
		{
			if (PEOPLE.isFinish(maxfloors))
			{
				//go to next level
			}
			else
			{
				PEOPLE.GoUp();
			}
		}
		else if (c == 'A')
		{
			PEOPLE.GoLeft();
		}
		else if (c == 'S')
		{
			PEOPLE.GoDown();
		}
		else if (c == 'D')
		{
			PEOPLE.GoRight();
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

