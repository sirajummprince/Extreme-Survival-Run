/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

#include<math.h>
#include<stdio.h>

int ball_x[500], ball_y[500],ball_count;
int dx, dy;
float theta,gun_x,gun_y;
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();

	iSetColor(100,150,150);
	iLine(200,200,200+gun_x,200+gun_y);

	iSetColor(255, 100, 10);
	for(int i=0;i<ball_count;i++)
	{
		iCircle(ball_x[i],ball_y[i],3);
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
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{

	if(key == 'x')
	{
		ball_x[ball_count]=gun_x+200;
		ball_y[ball_count]=gun_y+200;
		ball_count++;
		
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

void ballChange(){

	for(int i=0;i<ball_count;i++)
	{
		ball_x[i] += dx;
		ball_y[i] += dy;

	}
	
}

void rotategun(){
	if(theta>360)theta=0;
	theta=theta+.1;

	gun_x=120*cos(theta);
	gun_y=120*sin(theta);

}

int main()
{
	//place your own initialization codes here. 
	iSetTimer(30, ballChange);
	iSetTimer(200, rotategun);
	dx = 0;
	dy = 7;
	iInitialize(400, 400, "BallDemo");
	return 0;
}	