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
	extern double centerx;
    extern double centery;
    extern double centerz;
    extern GLfloat camerar;
    extern GLfloat cameratheta;
    extern GLfloat cameraphi;

	/*exits the program if q or Q is clicked*/
	if(key == 'q' || key == 'Q') 
	{
		exit(0);
	}
	if(key == 'r' || key == 'R')	//reset camera
	{
		eyex = 10.0;
    	eyey = 0.0;
    	eyez = 0.0;
    	centerx = 0.0;
    	centery = 0.0;
    	centerz = 0.0;
    	camerar = 10.0;
    	cameratheta = 100.0;
    	cameraphi = 45.0;		
	}
	if(key == 'a')
	{
		cameraphi = cameraphi - 1.0;
        if(cameraphi < 0.0)
        {
            cameraphi = cameraphi + 360.0;
        }
		eyey = eyey - 0.25;
		//cout << "d: " << eyey << endl;
	}
	if(key == 'd')
	{
		cameraphi = cameraphi + 1.0;
        if(cameraphi > 360.0)
        {
            cameraphi = cameraphi - 360.0;
        }
		eyey = eyey + 0.25;
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
        camerar = camerar - 1.0;
		//cout << camerar << endl;
		//eyex = eyex - 0.25;
    }
    if(key == 's')	//move backward
    {
        camerar = camerar + 1.0;
		//cout << camerar << endl;
		//eyex = eyex + 0.25;
    }

}

void processSpecialKeys(int key, int x, int y)
{
	extern double eyez;
	extern double centerx;
	extern double centery;
	extern double centerz;
	extern GLfloat camerar;
	extern GLfloat cameratheta;
	extern GLfloat cameraphi;
	
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
        if(centerz < 0.9)
		{
			cameratheta = cameratheta - 1.0;
        	if(cameratheta < 0.0)
        	{
            	cameratheta = cameratheta + 360.0;
        	}
			centerz = centerz + 0.1;
		}
		//cout << cameratheta << endl;
		//eyez = eyez + 0.2;
		//cameratheta = cameratheta + 1.0;
    } else if(key == GLUT_KEY_PAGE_DOWN)
    {
        if(centerz > 0.0)
		{
			cameratheta = cameratheta + 1.0;
        	if(cameratheta > 360.0)
        	{
            	cameratheta = cameratheta - 360.0;
        	}
			centerz = centerz - 0.1;
		}
		//cout << cameratheta << endl;
		//eyez = eyez - 0.2;
		//cameratheta = cameratheta - 1.0;
    }

}
#endif
