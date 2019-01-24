
#include "includes.h"
#include "prototypes.h"

void stepCall()
{
	extern unsigned frames;
    extern double t, theta, omega;

	step(&t, &theta, &omega);	
	
	glutPostRedisplay();
}

