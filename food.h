#pragma once
#include"mai.h"
class food
{
	HANDLE hd;
public:
	int x=0;
	int y;
	//food pos
	food(HANDLE htd);
	//init
	int refreshFood(int maxX, int minX, int maxY, int minY, vector<int>Sx, vector<int>Sy,vector<int>Ox,vector<int>Oy);
	//return 1 or 0, ead or not, in order to refresh
	int checkPos(int Sx0, int Sy0);
	//check if head has collided with food 
	
	int returnX();
	
	int returnY();
	//return food pos
	void changeX(int a);
	void changeY(int b);

	~food();
};

