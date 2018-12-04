#include "Object.h"
class CVEHICLE :public CObject {
public:
	CVEHICLE(int up, int down, int left, int right, int tmpfloor) :CObject(up, down, left, right, tmpfloor) {

	}
	CVEHICLE() = default;
	~CVEHICLE()
	{

	};
	virtual bool GoRight()
	{
		return CObject::GoRight();
	}
	virtual bool GoLeft()
	{
		return CObject::GoLeft();
	}
	int getSize() {
		return Num;
	}
	void BlockCor(int &x, int &y)
	{
		CObject::BlockCor(x, y);
	}
private:
	int Num;//numberofvehicle
};
class CTRUCK :public CVEHICLE {
public:
	CTRUCK(int up, int down, int left, int right, int tmpfloor) :CVEHICLE(up, down, left, right, tmpfloor) {

	}
	CTRUCK() = default;
	~CTRUCK();
	bool GoRight()
	{
		return CVEHICLE::GoRight();
	}
	bool GoLeft()
	{
		return CVEHICLE::GoLeft();
	}
private:
	void DTRUCK();//drawing truck
};
class CCAR :public CVEHICLE {
public:
	CCAR(int up, int down, int left, int right, int tmpfloor) :CVEHICLE(up, down, left, right, tmpfloor) {

	}
	CCAR() = default;
	~CCAR()
	{

	}
	bool GoRight()
	{
		return CObject::GoRight();
	}
	bool GoLeft()
	{
		return CObject::GoLeft();
	}
	void BlockCor(int &x, int &y)
	{
		CVEHICLE::BlockCor(x, y);
	}
private:
	void DCAR();//drawing car
};