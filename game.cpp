#include "game.h"

int saveOrNot = 0;//global var to check save
game::game(int x, HANDLE hd) :m(hd), s(hd), f(hd), hStdOut(hd)
{

}
int game::refreshFood(int sizeX,int sizeY){

	if (checkPos(f.returnX(),f.returnY(),s.returnx(), s.returny()) || !f.returnX()){
		do{//if collapsed refresh
			f.changeX(rand() % (m.maxX() - m.minX() + 1) + m.minX());
			f.changeY(rand() % (m.maxY() - m.minX() + 1) + m.minY());
		
		} while (checkObs(f.returnX(), f.returnY(), s.returnAx(), s.returnAy()) || checkObs(f.returnX(), f.returnY(), m.reOsx(), m.reOsy()));

		writechar(f.returnX(), f.returnY(), hStdOut, "¡ö", 0xe);
		point += 1;
		printAll(sizeX*2, sizeY, point, hStdOut, 0);
		return 1;
	}
	return 0;
}


void game::run(int hardOrEasy){
	int wallSizeX;
	int wallSizeY ;
	int numOfObs;
	//easy mode
	if (hardOrEasy == NORMAL){
		 wallSizeX = 51;
		 wallSizeY = 27;
		 numOfObs = 5;

		 m.create(0, 0, wallSizeX, wallSizeY);

		 s.setSize(m.midX(), m.midY());
		 m.obstacles(4, numOfObs, s.returnAx(), s.returnAy());
	}
	else if(hardOrEasy == HARD)
	{
		 wallSizeX = 55;
		 wallSizeY = 41;
		 numOfObs = 20;
		 m.create(0, 0, wallSizeX, wallSizeY);

		 s.setSize(m.midX(), m.midY());
		 m.obstacles(4, numOfObs, s.returnAx(), s.returnAy());

	}
	else if (hardOrEasy == DRAW){
		//diy mode
		system("cls");

		cout << "width£º";
		cin >> wallSizeX;
		cout << "\nheight£º";
		cin >> wallSizeY;
		cout << "\nnum of obstacles£º";
		cin >> numOfObs;
		if (wallSizeY<17)
		{
			wallSizeY = 17;
		}
		if (wallSizeX > 70){
			wallSizeX = 70;
		}
		m.create(0, 0, wallSizeX, wallSizeY);

		s.setSize(m.midX(), m.midY());
		m.obstacles(4, numOfObs, s.returnAx(), s.returnAy());

	}
	else if (hardOrEasy == GETFILE){
		//get archive
		int ssize;
		int scoreX;
		int scoreY;
		int obsSize;
		int Dir;
		FILE *p = nullptr;
		fopen_s(&p, "hahaha", "r");
		
		fread_s(&wallSizeX, 4, 4, 1, p);
		fread_s(&wallSizeY, 4, 4, 1, p);
		fread_s(&ssize, 4, 4, 1, p);
		fread_s(&scoreX, 4, 4, 1, p);
		fread_s(&scoreY, 4, 4, 1, p);
		fread_s(&point, 4, 4, 1, p);
		fread_s(&obsSize, 4, 4, 1, p);

		f.x = scoreX;

		f.y = scoreY;
		s.x.resize(ssize);
		s.y.resize(ssize);
		m.sx.resize(obsSize);

		m.sy.resize(obsSize);
		readIn(ssize, s.x, p);
		readIn(ssize, s.y, p);
		readIn(obsSize, m.sx, p);
		readIn(obsSize, m.sy, p);
		fread_s(&Dir, 4, 4, 1, p);
		s.dir = Dir;
		fclose(p);
		p = nullptr;
		m.create(0, 0, wallSizeX, wallSizeY);
		s.len = 3 + point;//change snake length
	}
	printFrame(wallSizeX, wallSizeY);
	m.printmap();

	m.printObs();
	if (f.returnX()!=0)
	{
		writechar(f.returnX(), f.returnY(), hStdOut, "¡ö", 0xe);

	}

	refreshFood(wallSizeX, wallSizeY);
	Sleep(60);
	s.firstShow();
	printAll(wallSizeX*2, wallSizeY, point, hStdOut,0);
	//init map
	Sleep(400);



	while (1)
	{
		s.moveSnake(refreshFood(wallSizeX,wallSizeY));
		//mov snake and refresh food
		if (saveOrNot){
			//if sav
			int ssize = s.returnAx().size();

			int scoreX = f.returnX();
			int scoreY = f.returnY();
			int obsSize = m.reOsx().size();
			int Dir = s.dir;
			FILE *p = nullptr;
			fopen_s(&p, "hahaha", "w");
			fwrite(&wallSizeX, 4, 1, p);
			fwrite(&wallSizeY, 4, 1, p);
			fwrite(&ssize, 4, 1, p);
			fwrite(&scoreX, 4, 1, p);
			fwrite(&scoreY, 4, 1, p);
			fwrite(&point, 4, 1, p);
			fwrite(&obsSize, 4, 1, p);


			writeIn(ssize, s.x, p);
			writeIn(ssize, s.y, p);
			writeIn(obsSize, m.sx, p);
			writeIn(obsSize, m.sy, p);
			fwrite(&Dir, 4, 1, p);
			fclose(p);
			p = nullptr;
			cout << "saved£¬input 0 to exit";
			while (_getch() != '0');
			saveOrNot--;
			return;
		}
		Sleep(point>20?40:100-3*point);
		if (checkObs(s.returnx(), s.returny(), m.reVectorx(), m.reVectory()) || checkObs(s.returnx(), s.returny(), m.reOsx(), m.reOsy()) || checkHead(s.returnAx(), s.returnAy())){
			printAll(wallSizeX * 2, wallSizeY, point, hStdOut, 1);//if dead, give a prompt , input 0 to exit
			while(_getch()!='0');
			return;

		}
	}


}
game::~game()
{
}
void game::writeIn(int size, vector<int> &source, FILE* &p){

	int a = 0;
	for (int i = 0; i < size; i++)
	{
		a = source[i];
		fwrite(&a, 4, 1, p);

	}
}
void game::readIn(int size, vector<int> &source, FILE* &p){
	
	int a = 0;
	for (int i = 0; i < size; i++){
		fread_s(&a, 4, 4, 1, p);
		source[i] = a;
	}
}