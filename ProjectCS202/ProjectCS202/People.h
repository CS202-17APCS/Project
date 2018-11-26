#pragma once
#include "Object.h"
#include "Animal.h"
#include "Vehicle.h"
#include "Game.h"
class CPEOPLE :public CObject {
private:
	bool mState;//isDead
public:
	CPEOPLE(int up, int down, int left, int right) :CObject(up, down, left, right) {
		mState = false;
	}
	void Up() { 
	
		CObject::GoUp(); 
	}
	void Left() { 
		if (CObject::left() > LeftEdge)
		 CObject::GoLeft(); 
	}
	void Right() { 
		if (CObject::right() < RightEdge)
			CObject::GoRight();
	}
	void Down() { 
		if(CObject::down()>BelowEdge)
		  CObject::GoDown(); 
	}
	bool imPact(vector<CVEHICLE*> tmp)
	{
		//NumOfVE=15
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i]->isCollide(*this))
				return true;
		}
		return false;
	}
	bool isImpact(vector<CANIMAL*> tmp)
	{
		//NumOfAni=15
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i]->isCollide(*this))
				return true;
		}
		return false;
	}
	bool isFinish(int tmpfloor)//Go to next level
	{
		if (CObject::floor() == tmpfloor)
			return true;
		return false;
	}
	bool isDead() { return mState; }
	int Peofloor()
	{
		return CObject::floor();
	}
};
