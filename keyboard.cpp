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
        eyex = eyex + 0.25;
    }
    if(key == 'v')
    {
        eyex = eyex - 0.25;
    }

	if(key == 'w')
    {
        eyez = eyez + 0.25;
    }
    if(key == 's')
    {
        eyez = eyez - 0.25;
    }


}
#endif
