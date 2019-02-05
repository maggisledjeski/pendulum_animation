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
	extern double eyex;
	extern double eyey;
	extern double eyez;
	extern unsigned pframes;

	//used for fps option 3
	//pframes++;

  	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 
   	gluLookAt(eyex,eyey,eyez,
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
	glTranslated(2.0,0.0,0.2);
    glColor3f (0.0,0.0,1.0);
    glRotated((double)180*theta/M_PI,1,0,0);
	glRotated((double)180*theta/M_PI,0,0,1);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05,	//radius of the cylinder at z=0
            (GLdouble) 0.05,	//radius of the cylinder at z=height
            (GLdouble) 0.8,	//height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    
	glTranslated(0.0,0.0,0.8); //moves the sphere to the swinging end of the pendulum
    glColor3f (1.0,0.0,0.0);
    gluSphere(gluNewQuadric(),
             (GLdouble) 0.1,	//radius, diameter is .2 thus total length of pendulum is 1 meter
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();

	/*glPushMatrix();
	//glTranslated(0.0,0.0,0.5);
	//glRotated(90.0,1,0,0);
	//glRotated(90.0,0,1,0);
	//glTranslated(0.0,0.0,2.0);
	gluCylinder(gluNewQuadric(), 
			(GLdouble) 0.5, //radius of the cylinder at z=0
            (GLdouble) 0.5, //radius of the cylinder at z=height
            (GLdouble) 0.25, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();*/

	/*horizontal pole*/
    glPushMatrix();
	glTranslated(-0.2,0.0,0.0);
	glRotated(90.0,0,1,0);
	glColor3f (0.0,1.0,1.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2, //radius of the cylinder at z=0
            (GLdouble) 0.2, //radius of the cylinder at z=height
            (GLdouble) 2.2, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();
	
	/*vertical pole*/
	glPushMatrix();
	glTranslated(0.0,0.0,-3.0);
	glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2, //radius of the cylinder at z=0
            (GLdouble) 0.2, //radius of the cylinder at z=height
            (GLdouble) 3.0, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();

	/*base*/
	glPushMatrix();
	glTranslated(0.0,0.0,-3.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 3.0, //radius of the cylinder at z=0
            (GLdouble) 3.0, //radius of the cylinder at z=height
            (GLdouble) 0.5, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    glPopMatrix();

	/*glPushMatrix();
    glTranslated(0.0,0.0,-3.0);
    glRotated(90.0,1,1,0);//1,1,0
    glColor3f (1.0,0.0,1.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 3.0,//1.45, //radius of the cylinder at z=0
            (GLdouble) 3.0,//0.45, //radius of the cylinder at z=height
            (GLdouble) 3.0, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    glPopMatrix();*/

	/*top*/
	glPushMatrix();
	glTranslated(0.0,0.0,-2.5);
	glRotated(45.0,0,0,1);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-2.12,-2.12);	//left
	glVertex2f(-2.12,2.12);	//back
	glVertex2f(2.12,2.12);	//right
	glVertex2f(2.12,-2.12);	//front
	glEnd();
	glPopMatrix();

	/*bottom*/
	glPushMatrix();
    glTranslated(0.0,0.0,-3.0);
    glRotated(45.0,0,0,1);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.12,-2.12);  //left
    glVertex2f(-2.12,2.12);   //back
    glVertex2f(2.12,2.12);    //right
    glVertex2f(2.12,-2.12);   //front
    glEnd();
    glPopMatrix();

	/*person*/
	glPushMatrix(); 
	glTranslated(0.0,2.0,0.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.1, //radius of the cylinder at z=0
            (GLdouble) 0.1, //radius of the cylinder at z=height
            (GLdouble) 1.72, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();
	/*head*/
	glPushMatrix();
	glTranslated(0.0,1.0,1.52);
	gluSphere(gluNewQuadric(),
             (GLdouble) 0.2,   //radius
             (GLint)     10,
             (GLint)     10 );
    glPopMatrix();
	/*body*/
	glPushMatrix();
	glTranslated(0.0,1.0,0.52);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05, //radius of the cylinder at z=0
            (GLdouble) 0.05, //radius of the cylinder at z=height
            (GLdouble) 0.8, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();
	/*left leg*/
    glPushMatrix();
    glTranslated(0.0,1.0,0.52);
    glRotated(-45.0,1,0,0);
	glScaled(1.0,1.0,-1.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05, //radius of the cylinder at z=0
            (GLdouble) 0.05, //radius of the cylinder at z=height
            (GLdouble) 0.52, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();
	 /*right leg*/
    glPushMatrix();
    glTranslated(0.0,1.0,0.52);
    glRotated(45.0,1,0,0);
    glScaled(1.0,1.0,-1.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05, //radius of the cylinder at z=0
            (GLdouble) 0.05, //radius of the cylinder at z=height
            (GLdouble) 0.52, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();
	 /*arms*/
    glPushMatrix();
    glTranslated(0.0,1.35,0.9);
    glRotated(90.0,0,1,0);
    glRotated(90.0,1,0,0);
	//glTranslated(0.0,0.3,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05, //radius of the cylinder at z=0
            (GLdouble) 0.05, //radius of the cylinder at z=height
            (GLdouble) 0.7, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();

	
	glFlush();
	//fps option 2 call here
	//omegaTime();
	showFPS();
    omegaTime();
//    framesPeriod();
    glutSwapBuffers();
}

/*void framesPeriod()
{
    extern double omega;
    extern unsigned frames;
    extern int oldptime;
    
    int currtime = glutGet(GLUT_ELAPSED_TIME);
    if(currtime - oldptime > 4000)
    {
        //fps = frames*1000.0/(currtime-oldtime);
        oldptime = currtime;
        frames = 0;
    }

}*/

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
	extern int pframes;
	extern int oldtime;
	extern int WINDOW_HEIGHT;
	extern int WINDOW_WIDTH;
	extern double pttotal;

	double width = WINDOW_WIDTH;
	double height = WINDOW_HEIGHT;

	static float fps;

	frames++;
	pframes++;
	//cout << pframes << endl;
	int currtime = glutGet(GLUT_ELAPSED_TIME);
	
	if(currtime - oldtime > 1000)
	{
		fps = frames*1000.0/(currtime-oldtime);
		oldtime = currtime;
		frames = 0;
	} 

	char *fpsstring = (char*) malloc(12*sizeof(char));
	sprintf(fpsstring,"FPS: %6.1f",fps);
	
	char *fppstring = (char*) malloc(12*sizeof(char));
    sprintf(fppstring,"FPP: %6.1d",pframes);

	//char *omegastring = (char*) malloc(12*sizeof(char));
	//sprintf(omegastring,"Omega: %6.1f",omega);
	
	char *perstring = (char*) malloc(12*sizeof(char));
	sprintf(perstring,"Period: %6.1f",pttotal);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0,width,0.0,height);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(255,255,0);
	drawString(50,50,GLUT_BITMAP_HELVETICA_12,fpsstring);
	drawString(50,35,GLUT_BITMAP_HELVETICA_12,fppstring);	
	drawString(50,20,GLUT_BITMAP_HELVETICA_12,perstring);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	
	free(fpsstring);
	free(fppstring);
	free(perstring);
}

#endif
