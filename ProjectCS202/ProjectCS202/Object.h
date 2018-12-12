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
	CObject(const CObject&tmp,int up, int down)
	{
		SetRight = tmp.SetRight;
		SetLeft = tmp.SetLeft;
		SetUp = up;
		SetDown = down;
	}
	CObject(int left, int right,int LR)//to specify which function of 2 parameters will run
	{
		SetLeft = left;
		SetRight = right;
	}
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
		if (SetUp-LengthBetweenOb>=1)
		{
			SetUp -= LengthBetweenOb;
			SetDown -= LengthBetweenOb;
			Curfloor++;
			return true;
		}
		return false;
	}
	virtual bool GoDown()
	{
		if (SetUp+LengthBetweenOb<=37)
		{
			SetUp += LengthBetweenOb;
			SetDown += LengthBetweenOb;
			Curfloor--;
			return true;
		}
		return false;
	}
	virtual bool GoRight()
	{
		if (SetRight+5 <= RightEdge)
		{
			SetRight+=5;
			SetLeft +=5;
			return true;
		}
		return false;
	}
	virtual bool GoLeft()
	{
		if (SetLeft-5 >= LeftEdge)
		{
			SetLeft -= 5;
			SetRight -=5;
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
	virtual void BlockCor(int &x, int &y)
	{
		x = SetLeft;
		y = SetUp;
	}
	virtual void ObStacleRight()//for ObStacles only
	{
		if (SetLeft + Step >= RightEdge+10)
		{
			SetLeft = 0;
			SetRight = SetLeft + LengthVe;
		}
		else
		{
			SetRight += Step;
			SetLeft += Step;
		}
	}
	virtual void ObStacleLeft()//for ObStacles only
	{
		if (SetRight - Step <= LeftEdge-8)
		{
			SetLeft = RightEdge - LengthAni;
			SetRight = RightEdge;
		}
		else
		{
			SetLeft -= Step;
			SetRight -= Step;
		}
	}
};
#endif
