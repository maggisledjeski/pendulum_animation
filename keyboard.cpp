#ifndef KEYBOARD
#define KEYBOARD

#include "includes.h"
#include "prototypes.h"
//#include "globals.h"

void keyboard(unsigned char key, int x, int y)
{
	extern double eyex;
	extern double eyey;
	extern double eyez;

	/*exits the program if q or Q is clicked*/
	if(key == 'q' || key == 'Q') 
	{
		exit(0);
	}
	
	if(key == 'd')
	{
		eyey = eyey + 0.25;
		//cout << "d: " << eyey << endl;
	}
	if(key == 'a')
	{
		eyey = eyey - 0.25;
		//cout << "a: " << eyey << endl;
	}
	
	if(key == 'x')	
    {
        eyez = eyez + 0.25;
    }
    if(key == 'v')	
    {
        eyez = eyez - 0.25;
    }

	if(key == 'w')	//move forward
    {
        eyex = eyex - 0.25;
    }
    if(key == 's')	//move backward
    {
        eyex = eyex + 0.25;
    }

}

void processSpecialKeys(int key, int x, int y)
{
	extern double centerx;
	extern double centery;
	extern double centerz;

	if(key == GLUT_KEY_UP)	//pan up
    {
        centerz = centerz + 0.2;
    } else if(key == GLUT_KEY_DOWN)	//pan down
    {
        centerz = centerz - 0.2;
    } else if(key == GLUT_KEY_LEFT)	//pan left
    {
        centerx = centerx - 0.2;
		centery = centery - 0.2;
		//cout << "left -> x: " << centerx << " y: " << centery << endl; 
    } else if(key == GLUT_KEY_RIGHT)	//pan right
    {
        centerx = centerx + 0.2;
		centery = centery + 0.2;
		//cout << "right -> x: " << centerx << " y: " << centery << endl;
    } else if(key == GLUT_KEY_PAGE_UP)
    {
        //eyex = eyex + 0.25;
    } else if(key == GLUT_KEY_PAGE_DOWN)
    {
        //eyex = eyex + 0.25;
    }

}
#endif
