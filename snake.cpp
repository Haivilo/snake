#include "snake.h"
extern int saveOrNot;

snake::snake(HANDLE htd,int x1,int y1) :hd(htd)
{
	
	x = { x1, x1+1, x1+2 };
	y = { y1, y1, y1 };
}

void snake::setSize(int x1, int y1){
	//init
	x = { x1, x1 + 1, x1 + 2 };
	y = { y1, y1, y1 };
}
snake::~snake()
{
}

void snake::checkSize(){
	if (len >= x.size())
	{
		x.resize(x.size() + 10);
		y.resize(x.size());
	}
}

void snake::move(int i){
	endx = x[len - 1];
	endy = y[len - 1];
	switch (dir)//depending on dir to change shape
	{
	case up:
		movpt(0, -1); break;
	case down:
		movpt(0, 1); break;
	case left:
		movpt(-1, 0); break;
	case right:
		movpt(1,0); break;
	default:
		break;
	}
	len += 1;
	show(i);
}
void snake::movpt(int cx,int cy){
	//add an unit to head in order to move
	int nx = cx + x[0];
	int ny = cy + y[0];
	checkSize();
	x.insert(x.begin(), nx);
	y.insert(y.begin(), ny);
}
	
void snake::show(int i){
	if (!i){
		x.erase(x.begin() + len - 1);
		y.erase(y.begin() + len - 1);
		writechar(endx, endy, hd, "  ", 0xf);
		len -= 1; 
		//if got a ptr, do not erase tail
	}
	writechar(x[0], y[0], hd, "■", 0xf);
}

void snake::firstShow(){
	for (int i = 0; i < len; i++)
	{
		writechar(x[i], y[i], hd, "■", 0xf);
	}
}
void snake::checkdir(){
	char flag = waitkey();
	char a='\0';
	switch (flag)
	{
	case('w') : case('W') : if (dir!=down)
	{
		dir = up;
	}break;
	case('s') : case('S') : if (dir!=up)
	{
		dir = down;
	}break;
	case('d') : case('D') : if (dir!=left)
	{
		dir = right;
	}break;
	case('a') : case('A') : if (dir != right){
		dir = left;
	}	break;
	case('p') : case('P') ://pause or continue

		do{
			a = waitkey();
			if (a == 'x' || a == 'X'){
				saveOrNot = 1;
				return;//save or not
			}
		} while (a != ('p') && a != ('P'));
		break;

	
	default:
		break;
	}
}
void snake::moveSnake(int i){
	checkdir();
	move(i);
}
int snake::returnx(){
	return x[0];
}
int snake::returny(){
	return y[0];
}
vector<int>snake::returnAx(){
	return x;
}
vector<int>snake::returnAy(){
	return y;
}

void snake::addSnake(){
	int xDiff = x[len - 1] - x[len - 2];
	int yDiff = y[len - 1] - y[len - 2];
	x.push_back(xDiff + x[len - 1]);
	y.push_back(yDiff + y[len - 1]);
}
