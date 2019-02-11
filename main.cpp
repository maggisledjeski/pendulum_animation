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
		cout << "spp(omega): " << totaltime << endl;
		sc1 = false;
        totaltime = 0;
		oldptime = currtime;
		//cout << " " << endl;
    } else if(omega > 0.0 && osign == 'n' && sc1 == true && sc2 == false)
    {
        osign = 'p';
        totaltime = totaltime + (currtime - oldptime);
		cout << "spp(omega): " << totaltime << endl;
		sc1 = false;
        totaltime = 0;
		oldptime = currtime;
		//cout << " " << endl;
    }
    
}

void PeriodTime()
{
    extern double omega;
    extern bool sc2;
    extern char osign2;
    extern int opt;
    extern int tpt;
    extern int pframes;
    extern double t;
    extern double oldppt;
    extern double pttotal;
    extern int totalFPP;
    extern double totalPTime;

	/*current period time based on physics function*/
    double currpt = t;
	
	/*current period time*/
    int ct = glutGet(GLUT_ELAPSED_TIME);

    if(omega <= -0.0 && osign2 == 'n')
    {
        osign2 = 'n';
        tpt = tpt + (ct - opt);
        pttotal = pttotal + (currpt - oldppt);
        opt = ct;
        oldppt = currpt;
    } else if(omega > 0.0 && osign2 == 'p')
    {
        osign2 = 'p';
        tpt = tpt + (ct - opt);
        opt = ct;
        pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega <= -0.0 && osign2 == 'p' && sc3 == false && sc4 == false)
    {
        osign2 = 'n';
        sc3 = true;
        tpt = tpt + (ct - opt);
        opt = ct;
        pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega > 0.0 && osign2 == 'n' && sc3 == false && sc4 == false)
    {
        osign2 = 'p';
        sc3 = true;
        tpt = tpt + (ct - opt);
        opt = ct;
        pttotal = pttotal + (currpt - oldppt);
        oldppt = currpt;
    } else if(omega <= -0.0 && osign2 == 'p' && sc3 == true && sc4 == false)
    {
		osign2 = 'n';
        tpt = tpt + (ct - opt);
        pttotal = pttotal + (currpt - oldppt);
        cout << "spp(tpt): " << tpt << endl;
        cout << "pframes: " << pframes << endl;
        cout << "actual pend period: " << pttotal << endl;
        totalFPP = pframes;
        totalPTime = pttotal;
        sc3 = false;
        tpt = 0;
        pttotal = 0;
        oldppt = currpt;
        opt = ct;
        pframes = 0;
		//cout << " " << endl;
    } else if(omega > 0.0 && osign2 == 'n' && sc3 == true && sc4 == false)
    {
        osign2 = 'p';
        tpt = tpt + (ct - opt);
        pttotal = pttotal + (currpt - oldppt);
        cout << "spp(tpt): " << tpt << endl;
        cout << "pframes: " << pframes << endl;
        cout << "actual pend period: " << pttotal << endl;
        totalFPP = pframes;
        totalPTime = pttotal;
        sc3 = false;
        tpt = 0;
        pttotal = 0;
        oldppt = currpt;
        opt = ct;
        pframes = 0;
		//cout << " " << endl;
    }

}


#endif

