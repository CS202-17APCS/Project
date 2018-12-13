#include "Game.h"
#include "Drawing.h"
#include <thread>
#include <future>
#include <chrono>
#include <mutex>

mutex m;
condition_variable cv;
bool finishDrawingHuman = true;
promise<void> endSignal;
future<void> futureObj;
thread drawingAnimalAndVehicles;

CGAME mygame;

void drawAndUpdate(future<void> futureObj) {
	while (futureObj.wait_for(chrono::milliseconds(1)) == future_status::timeout) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [] {return finishDrawingHuman; });
		mygame.drawVe();
		mygame.drawAni();
		mygame.updatePosAnimal();
		mygame.updatePosVehicle();
		this_thread::sleep_for(chrono::milliseconds(1));
		// Add function to clear animal and vehicles here
	}
}

int main()
{
	FixConsoleWindow();
	HWND console = GetConsoleWindow();
	HDC mydc = GetDC(console);
	COLORREF color = RGB(255, 255, 255);
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1920, 1080, TRUE);
	//new game only
	promise<void> endSignal;
	future<void> futureObj = endSignal.get_future();
	thread drawing(&drawAndUpdate, move(futureObj));



	while (true) {
		bool tmp = mygame.Handle(finishDrawingHuman, cv, m);
		//if (!finishDrawingHuman) cout << "DONE" << endl;

		if (tmp) {
			endSignal.set_value();
			drawing.join();
			system("CLS");
			Sleep(1000);
			mygame.clearScreenAndCreateNewLevel();
			mygame.turnOffNextLevel();
			endSignal = promise<void>();
			futureObj = endSignal.get_future();
			drawing = thread(&drawAndUpdate, move(futureObj));
		}

		//Sleep(100);
	}


	//mygame.drawGame();
}