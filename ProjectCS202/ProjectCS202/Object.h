#pragma once
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
	int Curfloor;//Current floor of Object
public:
	CObject() = default;
	CObject(int up, int down, int left, int right,int tmpfloor)
	{
		SetLeft = left;
		SetRight = right;
		SetUp = up;
		SetDown = down;
		Curfloor = tmpfloor;
	}
	~CObject();
	virtual void GoUp()
	{
		SetUp++;
	}
	virtual void GoDown()
	{
		SetDown--;
	}
	virtual void GoRight()
	{
		SetRight++;
	}
	virtual void GoLeft()
	{
		SetLeft--;
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
	//must modify below functions
	int floor()
	{
		return Curfloor;
	}
	int left() {
		return SetLeft;
	}
	int right()
	{
		return SetRight;
	}
	int down(){
		return SetDown;
	}//
};
