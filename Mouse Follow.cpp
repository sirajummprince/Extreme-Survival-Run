/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

int x[100];
int y[100];
int total;
int ball_x,ball_y;
int x2,y2,xt,yt;
int mode;

void drawFlowerAt(int p, int q)
{
	iSetColor(255, 0, 0);
	iFilledCircle(p+4, q+4, 4);

	iFilledCircle(p+4, q-4, 4);

	iFilledCircle(p-4, q+4, 4);

	iFilledCircle(p-4, q-4, 4);

	
	iSetColor(255, 255, 0);
	iFilledCircle(p, q, 4);
}

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();
	
	iSetColor(200,100,100);

	iFilledCircle(ball_x,ball_y,3);

	if (mode==0)drawFlowerAt(ball_x,ball_y);

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
		x2=mx;
		y2=my;
		mode=1;
		xt=ball_x-x2;
		yt=ball_y-y2;

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

void findY()
{
	if(mode==1)
	{
		if(xt>0)ball_x--;
		else ball_x++;

		if (ball_x==x2)mode=2;
	}
	if(mode==2)
	{
		if(yt>0)ball_y--;
		else ball_y++;

		if (ball_y==y2)mode=0;
	}

}
int main()
{
	//place your own initialization codes here. 
	ball_x=15;
	ball_y=15;
	iSetTimer(3,findY);
	iInitialize(400, 400, "MouseDemo");
	return 0;
}	