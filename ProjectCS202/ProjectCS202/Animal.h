#include "Object.h"

const string CDINOSAUR_SOUND_FILE = "sounds/dinosaur0.wav";
const string CBIRD_SOUND_FILE = "sounds/raven0.wav";

class CANIMAL :public CObject {
public:
	CANIMAL(int up, int down, int left, int right) :CObject(up, down, left, right) {

	}
	CANIMAL() = default;
	~CANIMAL();
	virtual bool isCollide(const CPEOPLE &tmp)
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
	int Num;//numberofanimals
};


class CDINOSAUR :public CANIMAL {
public:
	CDINOSAUR(int up, int down, int left, int right) :CANIMAL(up, down, left, right) {

	}
	CDINOSAUR() = default;
	~CDINOSAUR();
	bool isCollide(const CPEOPLE &tmp)
	{
		return CANIMAL::isCollide(tmp);
	}
	void GoRight()
	{
		CANIMAL::GoRight();
	}
	void GoLeft()
	{
		CANIMAL::GoLeft();
	}
	void playSound() {
		loadSound(CDINOSAUR_SOUND_FILE);
	}

private:
	void DDINOSAUR();//drawing DINOSAUR
};

class CBIRD :public CANIMAL {
public:
	CBIRD(int up, int down, int left, int right) :CANIMAL(up, down, left, right) {

	}
	CBIRD() = default;
	~CBIRD();
	bool isCollide(const CPEOPLE &tmp)
	{
		return CANIMAL::isCollide(tmp);
	}
	void GoRight()
	{
		CANIMAL::GoRight();
	}
	void GoLeft()
	{
		CANIMAL::GoLeft();
	}

	void playSound() {
		loadSound(CBIRD_SOUND_FILE);
	}
private:
	void DBIRD();//drawing BIRD
};