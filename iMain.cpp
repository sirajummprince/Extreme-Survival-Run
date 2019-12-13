/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

/*
	function iDraw() is called again and again by the system.
*/

int x=0,y=185;
int mb_x=10,mb_y=190,mb_x1=244,mb_y1=190,mb_x2=478,mb_y2=190,mb_x3=712,mb_y3=190,mb_x4=946,mb_y4=190,mb_x5=1190,mb_y5=190;
int runner_x=200,runner_y=210;
int barriar_x=1300,barriar_y=210;
int obstacle_x=2100,obstacle_y=210;
int barriar_x1=2900,barriar_y1=210;
int obstacle_x1=3700,obstacle_y1=210;
bool gameon=false;
int menu=1;
int score=0;
int f =0,a=-10;     
//int menu1_x1=797;//,menu1_x2=797,menu1_x3=797,menu1_x4=797,
//int menu1_y1=530,menu1_y2=430,menu1_y3=330,menu1_y4=230;
int mx,my;
char str[11];
int highscore=0;
char str1[11];
int cloud_x=1340,cloud_y=580;
int cloud_x1=1280,cloud_y1=530;
int cloud_x2=680,cloud_y2=550;
int cloud_x3=230,cloud_y3=600;
int cloud_x4=480,cloud_y4=600;
int cloud_x5=820,cloud_y5=550;

void scoreShow()
{
	//char str[11];
	iSetColor(0,0,0);
	sprintf(str,"Score: %d",score);
	iText(1200,650,str,GLUT_BITMAP_TIMES_ROMAN_24);
}

void highscoreshow()
{
	iSetColor(250,250,250);
	sprintf(str1,"High Score: %d",highscore);
	iText(575,100,str1,GLUT_BITMAP_TIMES_ROMAN_24);

}

void backgroundmove()
{
	mb_x--;
	mb_x1--;
	mb_x2--;
	mb_x3--;
	mb_x4--;
	mb_x5--;

	if(mb_x+200<=0)
	{
		mb_x=1190;
	}mb_x--;

	if(mb_x1+200<=0)
	{
		mb_x1=1190;
	}mb_x1--;

	if(mb_x2+200<=0)
	{
		mb_x2=1190;
	}mb_x2--;

	if(mb_x3+200<=0)
	{
		mb_x3=1190;
	}mb_x3--;

	if(mb_x4+200<=0)
	{
		mb_x4=1190;
	}mb_x4--;

	if(mb_x5+200<=0)
	{
		mb_x5=1190;
	}mb_x5--;
}

void runnermove()
{
	if(f==0)
	{
	runner_y+=50;
	if(runner_y==410)
		f=1;

	}
	else if(f==1)
	{
		runner_y-=50;
		if(runner_y==210)
		{
			f=0;
			iPauseTimer(a);
			a=-10;
		}


	}//runner_y=210;
}

void barriarmove()
{
	barriar_x-=10;
	if(barriar_x<=0)
	{
		barriar_x=1300;
	}

	barriar_x1-=10;
	if(barriar_x<=0)
	{
		barriar_x=2100;
	}

	obstacle_x-=10;
	if(obstacle_x<=0)
	{
		obstacle_x=2900;
	}

	obstacle_x1-=10;
	if(obstacle_x1<=0)
	{
		obstacle_x1=3700;
	}

}

void cloudmove()
{
	cloud_x-=2;
	if(cloud_x+64<=0)
	{
		cloud_x=1340;
	}

	cloud_x1-=2;
	if(cloud_x1+64<=0)
	{
		cloud_x1=1380;

	}

	cloud_x2-=2;
	if(cloud_x2+64<=0)
	{
		cloud_x2=1300;
	}

	cloud_x3-=2;
	if(cloud_x3+64<=0)
	{
		cloud_x3=1420;

	}

	cloud_x4-=2;
	if(cloud_x4+64<=0)
	{
		cloud_x4=1480;
	}

	cloud_x5-=2;
	if(cloud_x5+64<=0)
	{
		cloud_x5=1340;

	}


}

//void resumegame()
//{
//	iSetColor(0,0,0);
//	iFilledRectangle(670,320,100,40);
//	iSetColor(250,250,250);
//	iText(680,330,"Resume",GLUT_BITMAP_TIMES_ROMAN_24);
//}

void scoremenu()
{
	if((barriar_x==200) || (barriar_x1==200) || (obstacle_x==200) || (obstacle_x1==200))
		score+=10;
	
//	if(barriar_x1==200)
//		score+=10;

//	if(obstacle_x==200)
//		score+=10;

//	if(obstacle_x1==200)
//		score+=10;
}
void iDraw()
{
	//place your drawing codes here
	iClear();
	//iSetColor(200,0,0);
	//iPoint(100, 200);
	
	if(menu==1)
	{
		iClear();
		//iSetColor(250,250,250);
		//iFilledRectangle(0,0,1340,680);
		iShowBMP(0,0,"menu.BMP");
		iSetColor(0,0,0);
		iFilledRectangle(177,430,100,40);
		iFilledRectangle(177,330,100,40);
		iFilledRectangle(177,230,100,40);
		iFilledRectangle(177,130,100,40);
		iFilledRectangle(177,30,100,40);
		iSetColor(250,250,250);
		iText(180, 440, "Play", GLUT_BITMAP_HELVETICA_18);
		iText(180, 340, "Instructions", GLUT_BITMAP_HELVETICA_18);
		iText(180, 240, "Exit", GLUT_BITMAP_HELVETICA_18);
		iText(180, 140, "Credits", GLUT_BITMAP_HELVETICA_18);
		iText(180, 40, "High Score", GLUT_BITMAP_HELVETICA_18);
		//iSetColor(0,0,0);

		gameon=false;

		if(gameon==false)
		{
			score=0;
		}
		
		//iText(200, 340, "EXTREME SURVIVAL RUN", GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	else if(menu==2)
	{
		gameon=true;
		iShowBMP(0,0,"Background1.BMP");
		iSetColor(200,0,0);
		iFilledRectangle(x,y,1340,20);
		iSetColor(255,255,255);
		iFilledRectangle(mb_x,mb_y,134,10);
		iFilledRectangle(mb_x1,mb_y1,134,10);
		iFilledRectangle(mb_x2,mb_y2,134,10);
		iFilledRectangle(mb_x3,mb_y3,134,10);
		iFilledRectangle(mb_x4,mb_y4,134,10);
		iFilledRectangle(mb_x5,mb_y5,134,10);
		iShowBMP(runner_x,runner_y,"runnerWarrior.BMP");
		iShowBMP(barriar_x,barriar_y,"barriar.BMP");
		iShowBMP(obstacle_x,obstacle_y,"obstacle.BMP");
		iShowBMP(barriar_x1,barriar_y1,"barriar.BMP");
		iShowBMP(obstacle_x1,obstacle_y1,"obstacle.BMP");
		iShowBMP(cloud_x,cloud_y,"cloud.BMP");
		//iShowBMP(cloud_x1,cloud_y1,"cloud1.BMP");
		iShowBMP(cloud_x2,cloud_y2,"cloud2.BMP");
		iShowBMP(cloud_x3,cloud_y3,"cloud3.BMP");
		iShowBMP(cloud_x4,cloud_y4,"cloud2.BMP");
		iShowBMP(cloud_x5,cloud_y5,"cloud3.BMP");
		
		if((runner_x+50==barriar_x) && (runner_y+64==barriar_y+64))
		{
			//exit(0);
			menu=5;
		}

		if((runner_x+50==barriar_x1) && (runner_y+64==barriar_y1+64))
		{
			//exit(0);
			menu=5;
		}

		if((runner_x+50==obstacle_x) && (runner_y+64==obstacle_y+64))
		{
			//exit(0);
			menu=5;
		}

		if((runner_x+50==obstacle_x1) && (runner_y+64==obstacle_y1+64))
		{
			//exit(0);
			menu=5;	
		}

		if(gameon==true)
		{
			scoreShow();	
		}

		scoremenu();

		if(score>=highscore)
		{
			highscore=score;
		}
		else
			highscore=highscore;

	}

	else if(menu==3)
	{
		iSetColor(0,0,0);
		iFilledRectangle(0,0,1340,680);
		iSetColor(250,250,250);
		iFilledRectangle(680,500,40,40);
		iFilledRectangle(680,440,40,40);
		iFilledRectangle(620,440,40,40);
		iFilledRectangle(740,440,40,40);
		iFilledRectangle(600,380,200,40);
		iFilledRectangle(600,320,200,40);
		iSetColor(0,0,0);
		iText(690, 510, "UP", GLUT_BITMAP_8_BY_13);
		iText(685, 450, "DOWN", GLUT_BITMAP_8_BY_13);
		iText(620, 450, "LEFT", GLUT_BITMAP_8_BY_13);
		iText(740, 450, "RIGHT", GLUT_BITMAP_8_BY_13);
		iText(630, 400, "Press END for Menu", GLUT_BITMAP_8_BY_13);
		iText(630, 340, "Press SPACE to JUMP", GLUT_BITMAP_8_BY_13);
	}

	else if(menu==4)
	{
		iSetColor(0,0,0);
		iFilledRectangle(0,0,1340,680);
		iSetColor(250,250,250);
		iText(550, 510, "Md. Sirajum Munir Prince", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 450, "Department of Computer Science & Engineering", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 390, "Ahsanullah University of Science & Technology", GLUT_BITMAP_TIMES_ROMAN_24);				
	}

	else if(menu==5)
	{
		iShowBMP(0,0,"gameover.BMP");
		iSetColor(250,250,250);
		iText(600,200,str,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(250,250,250);
		iFilledRectangle(800,100,140,40);
		iSetColor(0,0,0);
		iText(810,110,"Play Again",GLUT_BITMAP_TIMES_ROMAN_24);
		gameon=false;
		highscoreshow();
	}

	else if(menu==6)
	{
		highscoreshow();
		iSetColor(250,250,250);
		iText(600,200,str,GLUT_BITMAP_TIMES_ROMAN_24);
		//scoreShow();
	}
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if((mx>=177 && my>=430) && (mx<=277 && my<=470) && menu==1)
			menu=2;
			gameon=true;
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if((mx>=177 && my>=330) && (mx<=277 && my<=370) && menu==1)
			menu=3;
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if((mx>=177 && my>=230) && (mx<=277 && my<=270) && menu==1)
			exit(0);
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if((mx>=177 && my>=130) && (mx<=277 && my<=170) && menu==1)
			menu=4;
	}
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if((mx>=177 && my>=30) && (mx<=277 && my<=70) && menu==1)
			menu=6;
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if((mx>=800 && my>=100) && (mx<=940 && my<=140) && menu==5)
			menu=2;
			score=0;
	}

	//if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	//{
		//place your codes here
	//	if((mx>=670 && my>320) && (mx<=770 && my<=360) && menu==2)
	//		menu=2;
	//}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
	if(key == ' ')
	{
		if(a==-10)
		a = iSetTimer(100,runnermove);//do something with 'q'
		
	}
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
		iPauseTimer(2);
		iPauseTimer(3);
	}
	if(key == 'r')
	{
		//do something with 'q'
		iResumeTimer(0);
		iResumeTimer(2);
		iResumeTimer(3);
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		menu=1;
		
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	iSetTimer(2,backgroundmove);
	iSetTimer(50,barriarmove);
	iSetTimer(30,cloudmove);
	iInitialize(1340, 680, "Extreme Survival Run");
	return 0;
}
