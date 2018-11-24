#include <iostream>
#include <Windows.h>
#include "Utils.h"
using namespace std;

class CObject {
private:
	int SetLeft;//Left Position Of Object
	int SetRight;//Right Position Of Object
	int SetUp;
	int SetDown;
public:
	CObject() = default;
	CObject(int up, int down, int left, int right)
	{
		SetLeft = left;
		SetRight = right;
		SetUp = up;
		SetDown = down;
	}
	~CObject();
	virtual void GoUp()
	{
		SetUp++;
	}
	virtual void GoDown()
	{
		SetDown++;
	}
	virtual void GoRight()
	{
		SetRight++;
	}
	virtual void GoLeft()
	{
		SetLeft++;
	}
	virtual bool isCollide(const CObject &tmp)
	{
		if (tmp.SetRight < SetLeft)
			return false;
		if (tmp.SetLeft > SetRight)
			return false;
		return true;
	}
	virtual void playSound();
};
