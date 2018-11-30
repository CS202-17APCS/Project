#ifndef _Game_
#define _Game_
#include "LibraryPro.h"
#include "Object.h"
#include "People.h"
#include "Drawing.h"
class CGAME {
	vector<CVEHICLE*> VE[2];
	vector<CANIMAL*> ANI[2];
	CPEOPLE PEOPLE;
	int Curlevel;//6 levels for a game
public:
	CGAME()
	{

	}
	void drawGame()
	{
		drawdog(0, 35);
		drawcar(0, 25);
		drawdog(0, 15);
		drawcar(0, 5);
		system("pause");
	}
	~CGAME() {};
	bool FinishGame()//Check whether game is finished or not
	{
		return Curlevel == 6;
	}
	void getPeopleFile();//load game
	void getAnimalFile();//load game
	void getVehicleFile();//load game
	void getPeopleByDefault()//New game
	{
		PEOPLE=CPEOPLE(UpPEOPLE, DownPEOPLE, LeftPEOPLE, RightPEOPLE,1);//please change the coordinate of people
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
			if (Curlevel == 6)
			{
				//Finish game
			}
			else
			{
				if (PEOPLE.GoUp() == false)//Standing on the maximum floor
				{
					//Go to next level
					Curlevel++;
				}
			}
		}
		else if (c == 'A')
		{
			bool checkLeft = PEOPLE.GoLeft();//creating bool variables just for checking for later problem . People will go to the left 
		}
		else if (c == 'S')
		{
			bool checkDown = PEOPLE.GoDown();
		}
		else if (c == 'D')
		{
			bool checkRight = PEOPLE.GoDown();
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
#endif

