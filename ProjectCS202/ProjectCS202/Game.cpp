#include "Game.h"
#include "Drawing.h"
int main()
{
	FixConsoleWindow();
	HWND console = GetConsoleWindow();
	HDC mydc = GetDC(console);
	COLORREF color = RGB(255, 255, 255);
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1920, 1080, TRUE);
	CGAME mygame;
	mygame.drawGame();
}