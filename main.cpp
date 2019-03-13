#ifndef MAIN
#define MAIN

#include "includes.h"
#include "prototypes.h"
#include "globals.h"

int main(int argc, char** argv)
{
    extern float dfr;
	extern bool cma;	//if there exists an argument from the command line

   	for(int i = 0; i < argc; i++)
    {
		dfr = (float) atoi(argv[i]);
		//cout << dfr << endl;
		cma = true;
	}
	if(dfr == 0.0)
	{
		cma = false;
	}
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glewInit();
	init();
	glutKeyboardFunc(keyboard);
    glutSpecialFunc(processSpecialKeys);
	glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(stepCall);
    glutMainLoop();
    return 0;
}

void omegaTime()
{
    extern double omega;
    extern bool sc1;
	extern bool sc2;
    extern char osign;
    extern int oldptime;
    extern int totaltime;
	extern unsigned frames;
	
	/*current time to calculate FPS*/
    int currtime = glutGet(GLUT_ELAPSED_TIME);
    
    if(omega <= -0.0 && osign == 'n')
    {
        osign = 'n';
        totaltime = totaltime + (currtime - oldptime);
		oldptime = currtime;
    } else if(omega > 0.0 && osign == 'p')
    {
        osign = 'p';
        totaltime = totaltime + (currtime - oldptime);
        oldptime = currtime;
    } else if(omega <= -0.0 && osign == 'p' && sc1 == false && sc2 == false)
    {
        osign = 'n';
        sc1 = true;
        totaltime = totaltime + (currtime - oldptime);
        oldptime = currtime;
    } else if(omega > 0.0 && osign == 'n' && sc1 == false && sc2 == false)
    {
        osign = 'p';
        sc1 = true;
        totaltime = totaltime + (currtime - oldptime);
        oldptime = currtime;
    } else if(omega <= -0.0 && osign == 'p' && sc1 == true && sc2 == false)
    {
        osign = 'n';
        totaltime = totaltime + (currtime - oldptime);
		/*set counting variables back to original to count*/
		sc1 = false;
        totaltime = 0;
		oldptime = currtime;
	} else if(omega > 0.0 && osign == 'n' && sc1 == true && sc2 == false)
    {
        osign = 'p';
        totaltime = totaltime + (currtime - oldptime);
		/*set counting variables back to original to count*/
		sc1 = false;
        totaltime = 0;
		oldptime = currtime;
	}
    
}

void PeriodTime()
{
    extern double omega;
    extern bool sc3;
	extern bool sc4;
    extern char osign2;
    extern int pframes;
    extern double t;
    extern double oldppt;
    extern double pttotal;
    extern int totalFPP;
    extern double totalPTime;
	extern float dfr;
	extern bool cma;

	/*current period time based on physics function*/
    double currpt = t;
	
	if(omega <= -0.0 && osign2 == 'n')
    {
        osign2 = 'n';
        pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega > 0.0 && osign2 == 'p')
    {
        osign2 = 'p';
        pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega <= -0.0 && osign2 == 'p' && sc3 == false && sc4 == false)
    {
        osign2 = 'n';
        sc3 = true;
        pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega > 0.0 && osign2 == 'n' && sc3 == false && sc4 == false)
    {
        osign2 = 'p';
        sc3 = true;
        pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega <= -0.0 && osign2 == 'p' && sc3 == true && sc4 == false)
    {
		osign2 = 'n';
        pttotal = pttotal + (currpt - oldppt);
		if(cma == false)	//if no cma, calculate the dfr
		{
			dfr = pframes/pttotal;
		}
        totalFPP = pframes;	//sets the total frames per period to be displayed on the screen
        totalPTime = pttotal;	//sets the total time per period to be displayed on the screen
        /*set counting variables back to original to count for next period*/
		sc3 = false;
        pttotal = 0;
        oldppt = currpt;
        pframes = 0;
	} else if(omega > 0.0 && osign2 == 'n' && sc3 == true && sc4 == false)
    {
        osign2 = 'p';
        pttotal = pttotal + (currpt - oldppt);
        if(cma == false)	//if no cma, calculate the dfr
		{
			dfr = pframes/pttotal;
        }
		totalFPP = pframes;	//sets the total frames per period to be displayed on the screen
        totalPTime = pttotal;	//sets the total time per period to be displayed on the screen
        /*set counting variables back to original to count for next period*/
		sc3 = false;
        pttotal = 0;
        oldppt = currpt;
        pframes = 0;
    }

}


#endif

