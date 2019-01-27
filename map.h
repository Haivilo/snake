#pragma once
#include"mai.h"
class map
{
	vector<int> x;
	vector<int> y;
	//vector of border
	HANDLE hd;
	int size;
	int numOfObstacles;
	int midx;
	int midy;
	int maxx;
	int minx;
	int maxy;
	int miny;
	

public:
	vector<int>sy;
	vector<int>sx;
	//vector of obstacle
	map(HANDLE htd);

	~map();
	void create(int startx, int starty, int sizex, int sizey);
	//if input is too small, return defualt map
	void printmap();

	void obstacles(int len, int num, vector<int> snx, vector<int> sny);
	//produce obs
	void printObs();

	void createObs(int len, vector<int> snx, vector<int> sny);
	//create single obs
	vector<int>reVectorx();
	vector<int>reVectory();
	//return border
	vector<int>reOsx();
	vector<int>reOsy();
	//return obs 
	int midX();
	int midY();
	int maxY();
	int minY();
	int maxX();
	int minX();

};

