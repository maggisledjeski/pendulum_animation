
#include "includes.h"
#include "prototypes.h"

void stepCall()
{
	extern unsigned frames;
    extern double t, theta, omega;
	extern unsigned pframes;
	//cout <<  &t << " " << &theta << " " << &omega << endl;
	step(&t, &theta, &omega);	
	pframes++;
	//cout << "ptime: " << t << endl;
	glutPostRedisplay();
}

