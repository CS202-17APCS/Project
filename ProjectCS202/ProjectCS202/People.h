#ifndef _People_
#define _People_
#include "LibraryPro.h"
#include "Animal.h"
#include "Vehicle.h"
#include "Object.h"
//Animal
class CPEOPLE :public CObject {
private:
	bool mState;//isDead
public:
	CPEOPLE() = default;
	CPEOPLE(int up, int down, int left, int right, int tmpfloor) :CObject(up, down, left, right, tmpfloor) {
		mState = false;
	}
	bool GoUp() {
		return CObject::GoUp();
	}
	bool GoLeft() {
		return CObject::GoLeft();
	}
	bool GoRight() {
		return CObject::GoRight();
	}
	bool  GoDown() {
		return CObject::GoDown();
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
		return CObject::checkFinish(tmpfloor);
	}
	bool isDead() { return mState; }
};
#endif

