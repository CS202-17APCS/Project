#include "Object.h"
#include <string>
const string CDINOSAUR_SOUND_FILE = "sounds/dinosaur0.wav";
const string CBIRD_SOUND_FILE = "sounds/raven0.wav";
class CANIMAL;
class CVEHICLE;
class CANIMAL :public CObject {
public:
	CANIMAL(int up, int down, int left, int right, int tmpfloor) :CObject(up, down, left, right, tmpfloor) {
	}
	CANIMAL() = default;
	~CANIMAL()
	{

	}
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

private:
	int Num;//numberofanimals
};
class CDINOSAUR :public CANIMAL {
public:
	CDINOSAUR(int up, int down, int left, int right, int tmpfloor) :CANIMAL(up, down, left, right, tmpfloor) {

	}
	CDINOSAUR() = default;
	~CDINOSAUR();
	bool GoRight()
	{
		return CANIMAL::GoRight();
	}
	bool GoLeft()
	{
		return CANIMAL::GoLeft();
	}
	void playSound() {
		//loadSound(CDINOSAUR_SOUND_FILE);
	}

private:
	void DDINOSAUR();//drawing DINOSAUR
};

class CBIRD :public CANIMAL {
public:
	CBIRD(int up, int down, int left, int right, int tmpfloor) :CANIMAL(up, down, left, right, tmpfloor) {

	}
	CBIRD() = default;
	~CBIRD();
	bool GoRight()
	{
		return CANIMAL::GoRight();
	}
	bool GoLeft()
	{
		return CANIMAL::GoLeft();
	}

	/*void playSound() {
		loadSound(CBIRD_SOUND_FILE);
	}*/
private:
	void DBIRD();//drawing BIRD
};