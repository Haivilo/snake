#include "food.h"

food::food(HANDLE htd) :hd(htd)
{
	
	srand((unsigned)time(NULL));//random time seed
}


food::~food()
{
}

int food::refreshFood(int maxX, int minX, int maxY, int minY, vector<int>Sx, vector<int>Sy,vector<int>Ox,vector<int>Oy){
	if (checkPos(Sx[0], Sy[0])||!x){
		do{
			x = rand() % (maxX - minX + 1) + minX;
			y = rand() % (maxY - minY + 1) + minY;
		} while (checkObs(x, y, Sx, Sy) || checkObs(x, y, Ox, Oy));
		//if collapsed, refresh pos
		writechar(x, y, hd, "¡ö", 0xe);
		return 1;
	}
	return 0;
}
int food::checkPos(int Sx0, int Sy0){
	if (Sx0 == x&&Sy0 == y){
		return 1;
	}return 0;

}
int food::returnX(){
	return x;
}
int food::returnY(){
	return y;
}
void food::changeX(int a){
	x = a;
}
void food::changeY(int b){
	y = b;
}