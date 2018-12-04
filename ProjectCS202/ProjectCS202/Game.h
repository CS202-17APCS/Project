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
		Curlevel=1;//Set Number Of Vehicle Here
		int CurFloor = 0;
		getPeopleByDefault();
		getVehicleByDefault();
		getAnimalByDefault();
		bool impact=false;
		while(true)
		{ 
			drawAni();
			drawVe();
			drawHuman();
			if (PEOPLE.GoUp() == false)
			{
				CPEOPLE tmp(YCorOfHuman - 1, YCorOfHuman + 2, XCorOfHuman - 1, XCorOfHuman + 2, 1);
				PEOPLE = tmp;
				CurFloor = 0;
			}
			else
				CurFloor++;
			updatePosVehicle();
			updatePosAnimal();
			//Check collide
			if (CurFloor % 2 == 0)
				impact = PEOPLE.imPact(VE[CurFloor]);
			else
			if(CurFloor%2!=0)
				impact = PEOPLE.isImpact(ANI[CurFloor]);
			if (impact)
			{
				break;
			}
			Sleep(100);
			system("cls");
		}
		system("pause>nil");
		/*drawHuman();
		while (true)
		{
			char c = _getch();
			if (c == 'W' || c == 'A' || c == 'D' || c == 'S'||c=='w'||c=='a'||c=='s'||c=='d')
			{
				system("cls");
				Sleep(100);
				updatePosPeople(c);
				drawHuman();
			}
		}*/
	}
	void drawAni()//OK
	{
		int xcor=0, ycor=0;
		for (int i = 1; i <=maxfloorsForAni; i+=2)
		{
			for (int j = 0; j < ANI[i].size(); j++)
			{
				ANI[i][j]->BlockCor(xcor, ycor);
				draw_reverse_dog(xcor, ycor);
			}
		}
	}
	void drawVe()//OK
	{
		int xcor = 0, ycor = 0;
		for (int i = 2; i <=maxfloorsForVe; i+=2)
		{
			for (int j = 0; j < VE[i].size(); j++)
			{
				VE[i][j]->BlockCor(xcor, ycor);
				drawcar(xcor%RightEdge, ycor);
			}
		}
	}
	void drawHuman()//OK
	{
		int xcor = 0, ycor = 0;
		PEOPLE.BlockCor(xcor, ycor);
		drawplayer(xcor, ycor);
	}
	void drawGame()//Just for testing
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
	void getPeopleByDefault()//New game(OK)
	{
		PEOPLE=CPEOPLE(YCorOfHuman-1, YCorOfHuman+2,XCorOfHuman-1 , XCorOfHuman+2,1);//please change the coordinate of people
	}
	void getVehicleByDefault()//New game(OK)
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
	void getAnimalByDefault()//New game(OK)
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
	void updatePosPeople(char c)//OK
	{
		if (c == 'W'||c=='w')
		{
			if (Curlevel == 6)
			{
				//Finish game
			}
			else
			{
				if (PEOPLE.GoUp() == false)//Standing on the maximum floor ,checking by using Coordinates
				{
					//Go to next level
					Curlevel++;
					CPEOPLE tmp(PEOPLE,YCorOfHuman - 1, YCorOfHuman + 2);
					PEOPLE = tmp;
				}
			}
		}
		else if (c == 'A'||c=='a')
		{
			bool checkLeft = PEOPLE.GoLeft();//creating bool variables just for checking for later problem . People will go to the left 
		}
		else if (c == 'S'||c=='s')
		{
			bool checkDown = PEOPLE.GoDown();
		}
		else if (c == 'D'||c=='d')
		{
			bool checkRight = PEOPLE.GoRight();
		}
	}
	void updatePosVehicle()//OK
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
	void updatePosAnimal()//OK
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

