#include "map.h"


map::map(HANDLE htd) :hd(htd)
{
	srand((unsigned)time(NULL));
}

void map::create(int startx, int starty, int sizex, int sizey){
	//get proper ptr and print
	size = sizex * 2 + sizey * 2 - 4;
	x.resize(size);
	x[0] = startx;
	y.resize(size);
	y[0] = starty;
	midx = sizex / 2 + startx;
	midy = sizey / 2 + starty; 
	minx = startx + 1;
	maxx = startx + sizex - 2;
	miny = starty + 1;
	maxy = starty + sizey - 2;
	for (int i = 1; i < sizex; i++)
	{
		x[i] = x[i - 1] + 1;
		y[i] = y[i - 1];
	}
	for (int i = sizex; i < size/2+1; i++)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1] + 1;
	}
	for (int i = size/2+1; i < size-sizey+2; i++)
	{
		x[i] = x[i - 1]  -1;
		y[i] = y[i - 1];
	}
	for (int i = size-sizey+2; i < size; i++)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1] - 1;
	}
}
void map::printmap(){
	for (int i = 0; i <size/2; i++)
	{
		writechar(x[i], y[i], hd, "■", 0xd);
		writechar(x[x.size()-i-1], y[x.size()-i-1], hd, "■", 0xd);
		Sleep(20);
	}//print map
	for (int i = 0; i < x.size(); i++)
	{
		writechar(x[i], y[i], hd, "  ", 0xd);
	}
	Sleep(500);
	//print again, get graphic enhancement
	for (int i = 0; i < x.size(); i++)
	{
		writechar(x[i], y[i], hd, "■", 0xd);

	}
}

void map::createObs(int len,vector<int> snx,vector<int> sny){
	int frameX = maxx - len;
	int framex = minx + 1;

	int frameY = maxy - len;

	int framey = miny + 1;

	if (rand() % 2){//50 50 possibility to do vertical or horizontal obstacle
		sx.push_back(rand() % (maxx-framex)+framex);
		sy.push_back(rand() % (frameY - framey + 1) + framey);
		
		for (int i = 1; i < len; i++)
		{
			sx.push_back( *(sx.end()-1));
			sy.push_back( *(sy.end()-1)+1);
		}

	}
	else
	{
		sx.push_back( rand() % (frameX - framex + 1) + framex);
		sy.push_back(rand() % (maxy - framey) + framey);
		for (int i = 1; i < len; i++)
		{
			sy.push_back(*(sy.end()-1));
			sx.push_back(*(sx.end()-1)+1);
		}
	}
	for (int i = 1; i < len + 1; i++)
	{
		if (checkObs(*(sx.end() - i), *(sy.end() - i), snx, sny) || checkPos(*(sx.end() - i), *(sy.end() - i), snx[0], sny[0]-1)){
			//prevent collapse with snake, if so, dont create obs
			for (int i = 1; i < len + 1; i++)
			{
				sx.pop_back();
				sy.pop_back();
			}
			return;
			//createObs(len, snx, sny);
		}
	}
}

void map::obstacles(int len, int num, vector<int> snx, vector<int> sny){
	for (int i = 0; i < num; i++)//打印次数
	{
		createObs(len,snx,sny);
	}
}
void map::printObs(){
	for (int i = 0; i < sx.size(); i++)
	{
		writechar(sx[i], sy[i], hd, "■", 0xc);


		Sleep(3000/sx.size());//睡眠，总时间控制3s
	}
}
vector<int> map::reVectorx(){
	return x;
} 
vector<int> map::reVectory(){
	return y;
}
vector<int> map::reOsx(){
	return sx;
}
vector<int> map::reOsy(){
	return sy;
}
int map::midX(){
	return midx;
}
int map::midY(){
	return midy;
}
int map::maxX(){
	return maxx;
}
int map::maxY(){
	return maxy;
}
int map::minX(){
	return minx;
}
int map::minY(){
	return miny;
}

map::~map()
{
}
