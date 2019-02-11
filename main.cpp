#ifndef MAIN
#define MAIN

#include "includes.h"
//#include "structs.h"
#include "prototypes.h"
#include "globals.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
	//glutMouseFunc(mouse);
    //glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(stepCall);
    //used for fps option 3
	//glutTimerFunc(0,checkFPS,0);
	glutMainLoop();
    return 0;
}

void omegaTime()
{
    extern double omega;
    extern bool sc1;
    extern char osign;
    extern int oldptime;
    extern int totaltime;
	extern unsigned frames;
	extern int pframes;
	extern double t;
	extern double oldppt;
	extern double pttotal;
	extern int totalFPP;
	extern double totalPTime;
	
	double currpt = t;
	
    int currtime = glutGet(GLUT_ELAPSED_TIME);
    
    if(omega <= -0.0 && osign == 'n')
    {
        osign = 'n';
        totaltime = totaltime + (currtime - oldptime);
		pttotal = pttotal + (currpt - oldppt);
        oldptime = currtime;
		oldppt = currpt;
    } else if(omega > 0.0 && osign == 'p')
    {
        osign = 'p';
        totaltime = totaltime + (currtime - oldptime);
        oldptime = currtime;
		pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega <= -0.0 && osign == 'p' && sc1 == false && sc2 == false)
    {
        osign = 'n';
        sc1 = true;
        totaltime = totaltime + (currtime - oldptime);
        oldptime = currtime;
		pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega > 0.0 && osign == 'n' && sc1 == false && sc2 == false)
    {
        osign = 'p';
        sc1 = true;
        totaltime = totaltime + (currtime - oldptime);
        oldptime = currtime;
		pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega <= -0.0 && osign == 'p' && sc1 == true && sc2 == false)
    {
        osign = 'n';
        totaltime = totaltime + (currtime - oldptime);
		pttotal = pttotal + (currpt - oldppt);
        cout << "spp: " << totaltime << endl;
		cout << "pframes: " << pframes << endl;
		cout << "actual pend period: " << pttotal << endl;		
		totalFPP = pframes;
		totalPTime = pttotal;
		sc1 = false;
        totaltime = 0;
		pttotal = 0;
        oldppt = currpt;
        oldptime = currtime;
		pframes = 0;
    } else if(omega > 0.0 && osign == 'n' && sc1 == true && sc2 == false)
    {
        osign = 'p';
        totaltime = totaltime + (currtime - oldptime);
		pttotal = pttotal + (currpt - oldppt);
        cout << "spp: " << totaltime << endl;
		cout << "pframes: " << pframes << endl;
		cout << "actual pend period: " << pttotal << endl;		
		totalFPP = pframes;
		totalPTime = pttotal;
		sc1 = false;
        totaltime = 0;
		pttotal = 0;
        oldppt = currpt;
        oldptime = currtime;
		pframes = 0;
    }
    
}


void checkFPS(int val)
{
	extern unsigned frames;

	if(0 != val)
	{
//		printf("The framerate is %d fps.\n", frames);
		omegaTime();
	}
	
	//frames = 0;
	glutTimerFunc(1000,checkFPS,1);
}

#endif

