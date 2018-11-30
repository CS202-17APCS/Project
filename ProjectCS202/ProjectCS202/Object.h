#ifndef _Object_
#define _Object_
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
	~CObject()
	{

	}
	virtual bool GoUp()//Return true when people can go up and false...
	{
		if (Curfloor != 6)
		{
			SetUp += Height;
			SetDown += Height;
			Curfloor++;
			return true;
		}
		return false;
	}
	virtual bool GoDown()
	{
		if (Curfloor != 1)
		{
			SetUp -= Height;
			SetDown -= Height;
			Curfloor--;
			return true;
		}
		return false;
	}
	virtual bool GoRight()
	{
		if (SetRight != RightEdge)
		{
			SetRight++;
			return true;
		}
		return false;
	}
	virtual bool GoLeft()
	{
		if (SetLeft != LeftEdge)
		{
			SetLeft--;
			return true;
		}
		return false;
	}
	virtual bool isCollide(const CObject &tmp)
	{
		if (tmp.SetRight < SetLeft)
			return false;
		if (tmp.SetLeft > SetRight)
			return false;
		return true;
	}
	//virtual void playSound();
	bool checkFinish(int maxfloor)
	{
		return Curfloor == maxfloor;
	}
	//must modify below functions
};
#endif
