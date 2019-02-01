#ifndef DISPLAY
#define DISPLAY

//#include <stdio.h>
#include "includes.h"
//#include "structs.h"
#include "prototypes.h"

void display(void)
{
    extern unsigned frames;
	extern double theta;
	//used for fps option 3
	//frames++;

  	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 
    gluLookAt(10.0,0.0,0.0,
			0.0,0.0,0.0,
			0.0,0.0,1.0);
	/*gluLookAt( 10.0,   0.0, 5.0,  // Eye
                0.0,   0.0, 0.0,  // Center
                0.0,   0.0, 1.0); // Up
    */
	glEnable(GL_DEPTH_TEST);
    glColor3f(0.0,1.0,0.0);

	glPushMatrix();
    glScaled(1.0,1.0,-1.0);
	//glTranslated(3.0,0.0,0.0);
    glColor3f (0.0,0.0,1.0);
    glRotated((double)180*theta/M_PI,1,0,0);
	glRotated((double)180*theta/M_PI,0,0,1);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.1,	//radius of the cylinder at z=0
            (GLdouble) 0.1,	//radius of the cylinder at z=height
            (GLdouble) 4.0,	//height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    
	glTranslated(0.0,0.0,4.0); //moves the sphere to the swinging end of the pendulum
    glColor3f (1.0,0.0,0.0);
    gluSphere(gluNewQuadric(),
             (GLdouble) 0.5,	//radius
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();

	glPushMatrix();
	//glTranslated(0.0,0.0,0.5);
	//glRotated(90.0,1,0,0);
	//glRotated(90.0,0,1,0);
	//glTranslated(0.0,0.0,2.0);
	gluCylinder(gluNewQuadric(), 
			(GLdouble) 0.05, //radius of the cylinder at z=0
            (GLdouble) 0.05, //radius of the cylinder at z=height
            (GLdouble) 0.25, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();

    glPushMatrix();
	glTranslated(0.0,0.0,1.0);
	//glColor3f (0.0,1.0,1.0);
	glRotated(90.0,0,1,0);
    //glRotated(90.0,0,0,1);
	//glTranslated(0.0,2.0,0.0);
	//glRotated(90.0,0,0,1);
	glColor3f (0.0,1.0,1.0);
	//glTranslated(0.0,0.0,2.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.5, //radius of the cylinder at z=0
            (GLdouble) 0.5, //radius of the cylinder at z=height
            (GLdouble) 2.0, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();
	
	glFlush();
	//fps option 2 call here
	showFPS();
    glutSwapBuffers();
}

void drawString(GLuint x, GLuint y, void *font, const char* string)
{
	const char *ch;
	glRasterPos2i(x,y);
	for(ch=string; *ch!='\0'; ch++)
	{
		glutBitmapCharacter(font, *ch);
	}
}

void showFPS()
{
	extern double omega;
	extern unsigned frames;
	extern int oldtime;
	extern int WINDOW_HEIGHT;
	extern int WINDOW_WIDTH;
	double width = WINDOW_WIDTH;
	double height = WINDOW_HEIGHT;
	static float fps;
	frames++;
	int currtime=glutGet(GLUT_ELAPSED_TIME);
	
	if(currtime - oldtime > 1000)
	{
		fps = frames*1000.0/(currtime-oldtime);
		oldtime = currtime;
		frames = 0;
	}
	
	char *charstring = (char*) malloc(12*sizeof(char));
	sprintf(charstring,"FPS: %6.1f",fps);
	
	char *omegastring = (char*) malloc(12*sizeof(char));
	sprintf(omegastring,"Omega: %6.1f",omega);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0,width,0.0,height);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(255,255,0);
	drawString(50,50,GLUT_BITMAP_HELVETICA_12,charstring);
	drawString(50,35,GLUT_BITMAP_HELVETICA_12,omegastring);	

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	
	free(charstring);
}

#endif
