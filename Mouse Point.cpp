/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include <stdlib.h>
#include <stdio.h>
void position();
int r;
int ball_x,ball_y;
int mode;
int score=0;
char final_score[100]="Score :";
char sc[20]="";
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();
	
	iSetColor(250,100,255);

	iFilledCircle(ball_x,ball_y,r);

	itoa(score,sc,10);
	final_score[7]='\0';
	strcat(final_score,sc);

	iSetColor(250,200,100);
	iText(15,15,final_score);

	

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
		int in=((mx-ball_x)*(mx-ball_x))+((my-ball_y)*(my-ball_y))- (r*r);

		if(in<0)
		{
			score++;
			position();
		}

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}
	//place your codes for other keys here
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
		exit(0);	
	}
	//place your codes for other keys here
}



void position()
{
//	if(mode==1)
	{
		ball_x=rand()%400;
		ball_y=rand()%400;
		r=rand()%20;
		if(r<5)r+=5;
	//	mode=0;
	}
}
int main()
{
	//place your own initialization codes here. 
	ball_x=rand()%400;
	ball_y=rand()%400;
	r=rand()%20;
	if(r<5)r+=5;

	iSetTimer(5000,position);
	iInitialize(400, 400, "MouseDemo");
	return 0;
}	