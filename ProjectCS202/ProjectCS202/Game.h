#include "Object.h"
#include "Animal.h"
#include "People.h"
#include "Vehicle.h"
class CGAME {
	CVEHICLE* VE;
	CANIMAL* ANI;
	CPEOPLE PEOPLE;
public:
	CGAME();
	void drawGame();
	~CGAME(); 
	CPEOPLE getPeople(); 
	CVEHICLE * getVehicle();
	CANIMAL* getAnimal();
	void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	void updatePosPeople(char);
	void updatePosVehicle();
	void updatePosAnimal();
};
