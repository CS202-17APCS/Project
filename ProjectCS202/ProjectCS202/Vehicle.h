#include "Object.h"
#include "People.h"
class CVEHICLE :public CObject {
public:
	CVEHICLE(int up,int down,int left,int right):CObject(up,down,left,right) {

	}
	CVEHICLE() = default;
	~CVEHICLE();
	virtual bool isCollide(const CObject &tmp)
	{
		return CObject::isCollide(tmp);
	}
	virtual void GoRight()
	{
		CObject::GoRight();
	}
	virtual void GoLeft()
	{
		CObject::GoLeft();
	}
	int getSize() {
		return Num;
	}
private:
	int Num;//numberofvehicle
};
class CTRUCK :public CVEHICLE {
public:
	CTRUCK(int up,int down,int left,int right):CVEHICLE(up,down,left,right) {

	}
	CTRUCK() = default;
	~CTRUCK();
	bool isCollide(const CObject &tmp)
	{
		return CVEHICLE::isCollide(tmp);
	}
	void GoRight()
	{
		CVEHICLE::GoRight();
	}
	void GoLeft()
	{
		CVEHICLE::GoLeft();
	}
private:
	void DTRUCK();//drawing truck
};
class CCAR :public CVEHICLE {
public:
	CCAR(int up, int down, int left, int right) :CVEHICLE(up, down, left, right) {

	}
	CCAR() = default;
	~CCAR();
	bool isCollide(const CObject &tmp)
	{
		return CVEHICLE::isCollide(tmp);
	}
	void GoRight()
	{
		CObject::GoRight();
	}
	void GoLeft()
	{
		CObject::GoLeft();
	}
private:
	void DCAR();//drawing car
};
