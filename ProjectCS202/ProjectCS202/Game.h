#ifndef _Game_
#define _Game_
#include "LibraryPro.h"
#include "Object.h"
#include "People.h"
#include "Drawing.h"
class CGAME {
	vector<CVEHICLE*> VE[100];
	vector<CANIMAL*> ANI[100];
	CPEOPLE PEOPLE;
	int Curlevel;//6 levels for a game
public:
	CGAME()
	{
		Curlevel=1;
		getPeopleByDefault();
		getVehicleByDefault();
		getAnimalByDefault();
		while(true)
		{ 
			drawAni();
			drawVe();
			drawHuman();
			if (PEOPLE.GoUp() == false)
			{
				CPEOPLE tmp(YCorOfHuman - 1, YCorOfHuman + 2, XCorOfHuman - 1, XCorOfHuman + 2, 1);
				PEOPLE = tmp;
			}
			updatePosVehicle();
			Sleep(100);
			system("cls");
		}
		system("pause>nil");
	}
	void drawAni()
	{
		int xcor=0, ycor=0;
		for (int i = 1; i <=maxfloorsForAni; i+=2)
		{
			ANI[i][0]->BlockCor(xcor, ycor);
			draw_reverse_dog(xcor, ycor);
		}
	}
	void drawVe()
	{
		int xcor = 0, ycor = 0;
		for (int i = 2; i <=maxfloorsForVe; i+=2)
		{
			VE[i][0]->BlockCor(xcor, ycor);
			drawcar(xcor, ycor);
		}
	}
	void drawHuman()
	{
		int xcor = 0, ycor = 0;
		PEOPLE.BlockCor(xcor, ycor);
		drawplayer(xcor, ycor);
	}
	void drawGame()
	{
		int height = 35;
		drawplayer(50, 41);
		int count = 0;
		for (int start = height; start >= 5; start -= 6, count += 1)
		{
			if (count % 2 == 0)
				draw_reverse_dog(165, start);
			else
				drawcar(0, start);
		}
		system("pause>nil");
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
		PEOPLE=CPEOPLE(YCorOfHuman-1, YCorOfHuman+2,XCorOfHuman-1 , XCorOfHuman+2,1);//please change the coordinate of people
	}
	void getVehicleByDefault()//New game
	{
		int Distance = (RightEdge - LeftEdge - Curlevel * LengthVe) / Curlevel ;
		if (Curlevel != 1)
			Distance = (RightEdge - LeftEdge - Curlevel * LengthVe) / (Curlevel - 1);
		int startHeight = YCorOfVe;
		for (int i = 2; i <= maxfloorsForVe; i+=2)
		{
			int startPos = LeftEdge;
			for(int j=0;j<Curlevel;j++)
			{
				CVEHICLE *tmp = new CCAR(startHeight-1, startHeight+2, startPos, startPos + LengthVe,i+1);
				VE[i].push_back(tmp);
				//delete tmp;
				startPos =startPos+LengthVe+Distance;//startpos+=distance
				if (startPos >= RightEdge)
					break;
			}
			startHeight -= LengthBetweenRows;
		}
	}
	void getAnimalByDefault()//New game
	{
		int Distance = (RightEdge - LeftEdge - Curlevel * LengthAni) / Curlevel;
		if (Curlevel != 1)
			Distance = (RightEdge - LeftEdge - Curlevel * LengthAni) / (Curlevel - 1);
		int startHeight = YCorOfAni;
		for (int i = 1; i <= maxfloorsForAni; i += 2)
		{
			int startPos = RightEdge;
			for (int j = 0; j<Curlevel; j++)
			{
				CANIMAL *tmp = new CBIRD(startHeight-1, startHeight+2, startPos-9, startPos,i+1);
				ANI[i].push_back(tmp);
				//delete tmp;
				startPos = startPos - LengthAni - Distance;//startpos+=distance
				if (startPos <= LeftEdge)
					break;
			}
			startHeight -= LengthBetweenRows;
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
		int startHeight = YCorOfAni;
		for (int i = 2; i <= maxfloorsForVe; i += 2)
		{
			for (int j = 0; j < VE[i].size(); j++)
			{
				if (VE[i][j]->GoRight()==false)//Vehicle goes right
				{
					CCAR tmp(startHeight - 1, startHeight + 2, 0, 0 + LengthVe, i + 1);
				}
			}
			startHeight -= LengthBetweenRows;
		}
	}
	void updatePosAnimal()
	{
		for (int i = 1; i <= maxfloorsForAni; i += 2)
		{
			for (int j = 0; j < ANI[i].size(); j++)
			{
				ANI[i][j]->GoLeft();//Animal goes left
			}
		}
	}
};
#endif

