
#include "includes.h"
#include "prototypes.h"

void stepCall()
{
	extern unsigned frames;
    extern double t, theta, omega;
	extern unsigned pframes;
	
	//double oldTheta = theta;
	//cout <<  &t << " " << &theta << " " << &omega << endl;
	//cout << "P:" << theta << endl;
	step(&t, &theta, &omega);	
	calculatePhysics(theta, omega);
	pframes++;
	//cout << "ptime: " << &omega << endl;
	glutPostRedisplay();
}

