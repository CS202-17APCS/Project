#include <iostream>
#include <deque>
#include <vector>
#include <Windows.h>
#include <string>
using namespace std;

void cls()
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void gotoxy(int x, int y);
void drawdog(int x, int y,int color);
void FixConsoleWindow();
void drawcar(int x, int y);
void drawplayer(int x, int y);
void drawsnake(int x, int y);

void drawsnake(int x, int y)
{
	char a = 219, b = 220, c = 223;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x + 4, y);// x=50,y=20
	cout << a << a;
	gotoxy(x + 4, y + 1);
	cout << a << a;
	gotoxy(x + 5, y + 2);
	cout << a;
	for (int i = x + 4; i > x + 1; --i)
	{
		gotoxy(i, y + 2);
		cout << b;
	}
	gotoxy(x + 1, y + 2); cout << a;
	gotoxy(x, y + 2); cout << c;
	gotoxy(x, y + 1); cout << b;
	gotoxy(x + 6, y + 2); cout << c;
	gotoxy(x + 6, y + 1); cout << b;
	gotoxy(x + 6, y); cout << b;
	gotoxy(x + 5, y - 1); cout << b << b << b;
	gotoxy(x + 7, y); cout << a;
}

void drawcar(int x, int y)
{
	int color = rand() % 2 + 12;
	char a = 219, b = 220, c = 223;
	gotoxy(x, y + 1);
	// dai 20, cao 4
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << a;
	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << b;
	gotoxy(x + 1, y); cout << a;
	gotoxy(x + 1, y + 1); cout << a;
	gotoxy(x + 2, y); cout << a;
	gotoxy(x + 2, y + 1); cout << a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	for (int i = x + 3; i < x + 6; ++i)
	{
		gotoxy(i, y + 1); cout << a;
		gotoxy(i, y + 2); cout << c;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = x + 3; i < x + 8; ++i)
	{
		gotoxy(i, y); cout << a;
	}
	for (int i = x + 3; i < x + 6; ++i)
	{
		gotoxy(i, y - 1); cout << b;
	}
	gotoxy(x + 6, y - 1); cout << a;
	gotoxy(x + 7, y - 1); cout << a;
	gotoxy(x + 6, y + 1); cout << a;
	gotoxy(x + 7, y + 1); cout << a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = x + 8; i < x + 13; ++i)
	{
		gotoxy(i, y); cout << a;
		for (int j = x + 8; j < x + 11; ++j)
		{
			gotoxy(j, y - 1); cout << a;
		}
	}
	gotoxy(x + 11, y - 1); cout << b;
	gotoxy(x + 13, y); cout << b;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = x + 8; i < x + 14; ++i)
	{
		gotoxy(i, y + 1); cout << a;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	for (int i = x + 14; i < x + 17; ++i)
	{
		gotoxy(i, y + 1); cout << a;
		gotoxy(i, y + 2); cout << c;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = x + 14; i < x + 18; ++i)
	{
		gotoxy(i, y);
		cout << b;
	}
	gotoxy(x + 17, y + 1); cout << a;
	gotoxy(x + 18, y + 1); cout << a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(x + 19, y + 1); cout << b;
}

/*gotoxy(50, 20); cout << " ";
gotoxy(51, 21); cout << " ";
gotoxy(51, 22); cout << " ";
gotoxy(56, 19); cout << " ";
gotoxy(57, 22); cout << " ";*/

void drawdog(int x, int y,int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	gotoxy(x, y);// x=50, y=20
			   // do dai cua con cho la 9, do cao la 4
	char a = 219, b = 220, c = 223;
	cout << a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = y; i < y + 3; ++i)
	{
		gotoxy(x + 1, i);
		cout << a;
	}
	gotoxy(x + 2, y);
	cout << b;
	gotoxy(x + 2, y + 1);
	cout << a;
	gotoxy(x + 2, y + 2);
	cout << c;
	gotoxy(x + 3, y); cout << b;
	gotoxy(x + 3, y + 1); cout << a;
	gotoxy(x + 4, y); cout << b;
	gotoxy(x + 4, y + 1); cout << a;
	gotoxy(x + 5, y); cout << a;
	gotoxy(x + 5, y + 1); cout << a;
	gotoxy(x + 6, y); cout << a;
	gotoxy(x + 6, y + 1); cout << a;
	gotoxy(x + 6, y - 1); cout << b;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(x + 7, y - 1); cout << a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = y; i < y + 2; ++i)
	{
		gotoxy(x + 7, i); cout << a;
	}
	gotoxy(x + 7, y + 2); cout << c;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	gotoxy(x + 8, y - 1); cout << a;
	gotoxy(x + 8, y); cout << b;
	gotoxy(x + 8, y + 1); cout << a;
	gotoxy(x + 8, y + 2); cout << a;
	gotoxy(x + 9, y - 1); cout << a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(x + 9, y); cout << a;
}

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawplayer(int x, int y)
{
	char a = 219, b = 220, c = 223, d = 221, e = 222;
	gotoxy(x, y);//x=50,y=20
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << a << a;
	gotoxy(x - 1, y + 1);
	cout << d;
	gotoxy(x + 2, y + 1);
	cout << e;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoxy(x, y + 1);
	cout << a << a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(x, y + 2);
	cout << d;
	gotoxy(x + 1, y + 2); cout << e;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(x, y - 1); cout << b << b;
}

void menu()
{
	string menu[4] = { "Start game", "Load game", "Settings","Exit" };
	int pointer = 0;
	while (true)
	{
		cls();
		gotoxy(65, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "  ######  ########   #######   ######   ######  ##    ##    ########   #######     ###    ########" << endl;
		gotoxy(65, 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " ##    ## ##     ## ##     ## ##    ## ##    ##  ##  ##     ##     ## ##     ##   ## ##   ##     ##" << endl;
		gotoxy(65, 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << " ##       ##     ## ##     ## ##       ##         ####      ##     ## ##     ##  ##   ##  ##     ##" << endl;
		gotoxy(65, 5);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " ##       ########  ##     ##  ######   ######     ##       ########  ##     ## ##     ## ##     ##" << endl;
		gotoxy(65, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << " ##       ##   ##   ##     ##       ##       ##    ##       ##   ##   ##     ## ######### ##     ##" << endl;
		gotoxy(65, 7);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " ##    ## ##    ##  ##     ## ##    ## ##    ##    ##       ##    ##  ##     ## ##     ## ##     ##" << endl;
		gotoxy(65, 8);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  ######  ##     ##  #######   ######   ######     ##       ##     ##  #######  ##     ## ########" << endl;
		gotoxy(100, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 4; ++i)
		{
			gotoxy(100, 20 + i);
			if (i == pointer)
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << menu[i] << endl;
			}
			else
			{
				//gotoxy(100, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
					pointer = 3;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 4)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
				case 0:
				{
					cls();
					cout << "code for new game";
					Sleep(1000);
				}break;
				case 1:
				{
					cls();
					cout << "code for load game";
					Sleep(1000);
				}break;
				case 2:
				{
					cls();
					cout << "code for settings";
					Sleep(1000);
				}
				case 3:
				{
					return;
				}break;
				}
				break;
			}
			Sleep(500);
		}
	}
}

int main()
{
	FixConsoleWindow();
	HWND console = GetConsoleWindow();
	HDC mydc = GetDC(console);
	//COLORREF color = RGB(255, 255, 255);
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1920, 1080, TRUE); // 210 char width, 100 height

	string menu[4] = { "Start game", "Load game", "Settings","Exit" };
	int pointer = 0;
	while (true)
	{
		cls();
		gotoxy(65, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "  ######  ########   #######   ######   ######  ##    ##    ########   #######     ###    ########" << endl;
		gotoxy(65, 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " ##    ## ##     ## ##     ## ##    ## ##    ##  ##  ##     ##     ## ##     ##   ## ##   ##     ##" << endl;
		gotoxy(65, 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << " ##       ##     ## ##     ## ##       ##         ####      ##     ## ##     ##  ##   ##  ##     ##" << endl;
		gotoxy(65, 5);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " ##       ########  ##     ##  ######   ######     ##       ########  ##     ## ##     ## ##     ##" << endl;
		gotoxy(65, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << " ##       ##   ##   ##     ##       ##       ##    ##       ##   ##   ##     ## ######### ##     ##" << endl;
		gotoxy(65, 7);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " ##    ## ##    ##  ##     ## ##    ## ##    ##    ##       ##    ##  ##     ## ##     ## ##     ##" << endl;
		gotoxy(65, 8);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "  ######  ##     ##  #######   ######   ######     ##       ##     ##  #######  ##     ## ########" << endl;
		gotoxy(100, 20);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 4; ++i)
		{
			gotoxy(100, 20 + i);
			if (i == pointer)
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << menu[i] << endl;
			}
			else
			{
				//gotoxy(100, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
					pointer = 3;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 4)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
					case 0:
					{
						cls();
						cout << "code for new game";
						Sleep(1000);
					}break;
					case 1:
					{
						cls();
						cout << "code for load game";
						Sleep(1000);
					}break;
					case 2:
					{	
						cls();
						cout << "code for settings";
						Sleep(1000);
					}
					case 3:
					{	
						return 0;
					}break;
				}
				break;
			}
			Sleep(500);
		}
	}

	//drawsnake(50, 20);
	cout << endl;
	system("pause>nil");
	return 0;
}