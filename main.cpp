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
	//glutTimerFunc(0,omegaTime,0);
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
        cout << "twice: " << totaltime << endl;
        sc1 = false;
        totaltime = 0;
        oldptime = currtime;
    } else if(omega > 0.0 && osign == 'n' && sc1 == true && sc2 == false)
    {
        osign = 'p';
        totaltime = totaltime + (currtime - oldptime);
        cout << "twice: " << totaltime << endl;
        sc1 = false;
        totaltime = 0;
        oldptime = currtime;
    }
    
}


void checkFPS(int val)
{
	extern unsigned frames;

	if(0 != val)
	{
//		printf("The framerate is %d fps.\n", frames);
	}
	
	frames = 0;
	glutTimerFunc(1000,checkFPS,1);
}

#endif

