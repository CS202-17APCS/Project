#pragma once
#include "Object.h"
#include "Animal.h"
#include "Vehicle.h"
class CPEOPLE :public CObject {
private:
	bool mState;//isDead
	int Floor;//Where?
public:
	void Up(int) { CObject::GoUp(); }
	void Left(int) { CObject::GoLeft(); }
	void Right(int) { CObject::GoRight(); }
	void Down(int) { CObject::GoDown(); }
	bool imPact(const CVEHICLE*& C)
	{
		//NumOfVE=15
		for (int i = 0; i < 15; i++)
		{
			if (isCollide(C[i]))
				return true;
		}
		return false;
	}
	bool isImpact(const CANIMAL*& A)
	{
		//NumOfAni=15
		for (int i = 0; i < 15; i++)
		{
			if (isCollide(A[i]))
				return true;
		}
		return false;
	}
	bool isFinish();//Go to next level
	bool isDead() { return mState; }
};
