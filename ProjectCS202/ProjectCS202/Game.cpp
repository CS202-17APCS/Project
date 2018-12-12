#include "Game.h"
#include "Drawing.h"
#include <thread>
#include <future>
#include <chrono>
#include <mutex>

mutex m;
condition_variable cv;
bool ready = false;

//CGAME mygame;

/*void drawAndUpdate(future<void> futureObj) {
	while (futureObj.wait_for(chrono::milliseconds(1)) == future_status::timeout) {
		unique_lock<mutex> lock(m);
		cv.wait(lock, [] {return ready; });
		mygame.drawAni();
		mygame.drawVe();
		mygame.updatePosAnimal();
		mygame.updatePosVehicle();
		Sleep(3);
		//this_thread::sleep_for(chrono::milliseconds(1));
		// Add function to clear animal and vehicles here
	}
}*/

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
	/*promise<void> endSignal;
	future<void> futureObj = endSignal.get_future();
	thread drawing(&drawAndUpdate, move(futureObj));
	while (true) {
		ready = false;
		cv.notify_one();
		lock_guard<mutex> lock(m);
		bool tmp = mygame.Handle();
		ready = true;
		if (tmp) {
			endSignal.set_value();
			drawing.join();
			mygame.turnOffNextLevel();
		}
		//Sleep(100);
	}*/
	CGAME mygame;
	//mygame.drawGame();
}