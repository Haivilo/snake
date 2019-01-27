#include <iostream>
using namespace std;
#include <Windows.h>
#include <vector>
#include<stdio.h>
#include<conio.h>
#include <time.h> 
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define NORMAL 1
#define HARD 2
#define GETFILE 3
#define GETMAP 4
#define DRAW 5
#define up -1
#define down 1
#define left -4
#define right 4
void printAll(int xFrame, int yFrame, int mark, HANDLE hd,int i);//ifi=1£¬dead info
void writechar(short x, short y, HANDLE hStdOut, const char* pstr, WORD color);

int waitkey();

int checkObs(int x, int y, vector<int> ox, vector<int>oy);
//check if collided
int checkHead(vector<int> ox, vector<int>oy);
//check if head collided with body
int checkPos(int x1, int y1, int x2, int y2);//check if 2 ptr are same 
void printFrame(int x, int y);
