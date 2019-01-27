#include"game.h"

int main(){


	PlaySoundA("sound\\yaya.wav", NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int sign;
	system("mode con cols=30 lines=15");
	while (1)
	{
		
		game a(0,hStdOut);
		//init
		cout << "snake\n 1.normal\n 2.hard\n 3.get archive\n 4.cancel\n 5.diy\n";
		scanf_s("%d", &sign);
		if (getchar() != '\n'){
			system("cls");
			printf("wrong input!\n\n");
			while (getchar() != '\n');
			continue;
		}//prevent wrong input
		switch (sign)
		{//if proper input, give differemt respond 
		case NORMAL: a.run(NORMAL); system("mode con cols=30 lines=10");
			break;
		case HARD:a.run(HARD); system("mode con cols=30 lines=10"); break;
		case GETFILE:a.run(GETFILE); system("mode con cols=30 lines=10"); break;
		case GETMAP:return 0; break;
		case DRAW:a.run(DRAW); system("mode con cols=30 lines=10"); break; break;

		default:
			system("cls");
			printf("ÈÏÕæÊäÈë!\n\n");
			break;
		}
	}



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	////COORD pos = { 20, 10 };
	////writechar(20, 10, hStdOut, "123", 0xf);
	//map b(hStdOut);
	//b.create(0, 0, 51, 27);
	//b.printmap();
	//snake a(hStdOut, b.midX(), b.midY());
	//a.firstShow();
	//b.obstacles(4, 10,a.returnAx(),a.returnAy());
	//b.printObs();


	//food f(hStdOut); 
	//f.refreshFood(b.maxX(), b.minX(), b.maxY(), b.minY(), a.returnAx(), a.returnAy(),b.reOsx(),b.reOsy());
	//Sleep(500);

	//while (1)
	//{

	//	a.moveSnake(f.refreshFood(b.maxX(), b.minX(), b.maxY(), b.minY(), a.returnAx(), a.returnAy(),b.reOsx(),b.reOsy()));
	//	//f.refreshFood(b.maxX(), b.minX(), b.maxY(), b.minY(), a.returnAx(), a.returnAy(), b.reOsx(), b.reOsy());
	//	if (checkObs(a.returnx(), a.returny(), b.reVectorx(), b.reVectory()) || checkObs(a.returnx(), a.returny(), b.reOsx(), b.reOsy())||checkHead(a.returnAx(),a.returnAy())){
	//		return 0;
	//	}
	//	

	//	Sleep(100);
	//}
}
 