#pragma once
#include "snake.h"
#include"map.h"
#include"food.h"
class game
{
	HANDLE hStdOut;
	map m;
	snake s;
	food f;
	int point=-1;
	//score init is -1
public:
	game(int x, HANDLE hd);

	int refreshFood(int sizeX,int sizeY);
	void run(int hardOrEasy);
	void writeIn(int size, vector<int> &source, FILE* &p);//write into vector
	void readIn(int size, vector<int> &source, FILE* &p);//read from vector
	~game();
};

