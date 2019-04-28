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
	extern bool physics;

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
    	camerar = 9.0;
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
	}
	if(key == 'd')
	{
		cameraphi = cameraphi + 1.0;
        if(cameraphi > 360.0)
        {
            cameraphi = cameraphi - 360.0;
        }
		eyey = eyey + 0.25;
	}
	if(key == 'g' && physics == false)	
    {
        physics = true;
    } else if(key == 'g' && physics == true)
	{
		physics = false;
	}
	if(key == 'w')	//move forward
    {
        if(camerar > 1.0)
		{
			camerar = camerar - 1.0;
		}
    }
    if(key == 's')	//move backward
    {
        if(camerar < 9.0)
		{
			camerar = camerar + 1.0;
		}
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
        if(centerz < 0.9)
		{
			centerz = centerz + 0.2;
		}
    } else if(key == GLUT_KEY_DOWN)	//pan down
    {
       if(centerz > 0.0)
		{
			centerz = centerz - 0.2;
		}
    } else if(key == GLUT_KEY_LEFT)	//pan left
    {
        if((centerx > -2.6) && (centery > -2.6))
		{
			centerx = centerx - 0.2;
			centery = centery - 0.2;
		} 
    } else if(key == GLUT_KEY_RIGHT)	//pan right
    {
        if((centerx < 2.6) && (centery < 2.6))
		{
			centerx = centerx + 0.2;
			centery = centery + 0.2;
		}
    } else if(key == GLUT_KEY_PAGE_UP)	//move up
    {
        if(cameratheta > 90.0)
		{
			cameratheta = cameratheta - 1.0;
        	if(cameratheta < 0.0)
        	{
            	cameratheta = cameratheta + 360.0;
        	}
			centerz = centerz + 0.1;
		}
    } else if(key == GLUT_KEY_PAGE_DOWN)	//move down
    {
        if(cameratheta < 101.0)
		{
			cameratheta = cameratheta + 1.0;
        	if(cameratheta > 360.0)
        	{
            	cameratheta = cameratheta - 360.0;
        	}
			centerz = centerz - 0.1;
		}
    }

}
#endif
