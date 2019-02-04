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
    /*used for fps option 3
	glutTimerFunc(0,checkFPS,0);*/
	glutMainLoop();
    return 0;
}

void checkFPS(int val)
{
	extern unsigned frames;

	if(0 != val)
	{
		printf("The framerate is %d fps.\n", frames);
	}
	
	frames = 0;
	glutTimerFunc(1000,checkFPS,1);
}

#endif

