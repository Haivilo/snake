#pragma once
#include "mai.h"


class snake
{
	HANDLE hd;
	int endx;
	int endy;
	//end pos
	void movpt(int cx,int cy);
	//func to move the tail
	void checkSize();

	void snake::movedir(int cx, int cy);

	void checkdir();

	void show(int i);

	void move(int i);

public:
	int len=3;				
	int dir = up;
	//init dir is up
	vector<int> x;
	vector<int> y;
	//all poses
	snake(HANDLE htd, int x1 = 0, int y1 = 0);
	
	void setSize(int x1, int y1);
	//init first pos
	~snake();
	void firstShow();

	int returnx();
	int returny();
	//return head ptr
	void moveSnake(int i);
	//add or move depending on i
	void addSnake();

	vector<int>returnAx();
	vector<int>returnAy();

};

