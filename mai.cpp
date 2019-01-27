#include"mai.h"
void writechar(short x, short y, HANDLE hStdOut, const char* pstr, WORD color)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(hStdOut, pos);
	SetConsoleTextAttribute(hStdOut, color);
	cout << pstr;
}
int waitkey(){
	if (_kbhit())
	{
		return _getch();
	}
	return 0;
}
int checkObs(int x, int y, vector<int> ox, vector<int>oy){
	for (int i = 0; i < ox.size(); i++)
	{
		if (x == ox[i] && y == oy[i]){
			return 1;
		}
	}
	return 0;
}
int checkHead(vector<int> ox, vector<int>oy){
	for (int i = 1; i < ox.size(); i++)
	{
		if (ox[0] == ox[i] && oy[0] == oy[i]){
			return 1;
		}
	}
	return 0;
}
int checkPos(int x1, int y1,int x2,int y2){
	if (x1 == x2&&y1 == y2){
		return 1;
	}return 0;

}
void printAll(int xFrame, int yFrame, int mark,HANDLE hd,int i){
	SetConsoleTextAttribute(hd, 0xf);
	SetConsoleCursorPosition(hd, { xFrame + 5, 1 });
	cout << "up£ºW";
	SetConsoleCursorPosition(hd, { xFrame + 5, 3 });
	cout << "down£ºS";
	SetConsoleCursorPosition(hd, { xFrame + 5, 5 });
	cout << "left£ºA";
	SetConsoleCursorPosition(hd, { xFrame + 5, 7 });
	cout << "right£ºD";
	SetConsoleCursorPosition(hd, { xFrame + 5, 9 });
	cout << "pause:P";
	SetConsoleCursorPosition(hd, { xFrame + 5, 11 });
	cout << "save£ºX";
	SetConsoleCursorPosition(hd, { xFrame + 5, 13 });
	cout << "mark£º"<<mark;
	if (i){
		SetConsoleCursorPosition(hd, { xFrame + 5, 15 });
		cout << "dead£¬press0";
	SetConsoleCursorPosition(hd, { xFrame + 5, 17 });
	cout << "return to main menu";

	}


	//SetConsoleCursorPosition(hd, { xFrame + 5, 9 });

}
void printFrame( int x, int y){
	char gameFrame[100] = { '\0' };
	sprintf_s(gameFrame, 100, "mode con cols=%d lines=%d", x * 2 + 25, y);
	system(gameFrame);
}