#ifndef DISPLAY
#define DISPLAY

#include "includes.h"
#include "prototypes.h"

void display(void)
{
    extern unsigned frames;
	extern double theta;
	extern double eyex;
	extern double eyey;
	extern double eyez;
	extern unsigned pframes;	//frames per period
	extern float dfr;	//desired frame rate
	extern bool cma;
	extern double centerx;
	extern double centery;
	extern double centerz;
	
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 
   	gluLookAt(eyex,eyey,eyez,
			centerx,centery,centerz,
			0.0,0.0,1.0);
	glEnable(GL_DEPTH_TEST);
    glColor3f(0.0,1.0,0.0);

	/*pend sphere and rod*/
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

	/*pend horizontal pole*/
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
	
	/*pend vertical pole*/
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

	/*pend base*/
	/*glPushMatrix();
	glTranslated(0.0,0.0,-3.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 3.0, //radius of the cylinder at z=0
            (GLdouble) 3.0, //radius of the cylinder at z=height
            (GLdouble) 0.5, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    glPopMatrix();
*/
	/*pend base top*/
/*	glPushMatrix();
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
*/
	/*pend base bottom*/
/*	glPushMatrix();
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
*/
	/*tabletop top*/
	glPushMatrix();
	glTranslated(0.0,0.0,-3.0);
	glBegin(GL_POLYGON);
	//2ft = 0.6096m
	//1inch=0.0254m
	glVertex2f(-1.0,-1.0);//0.6096,-0.6096);//-4,-4);	//back left  
    glVertex2f(-1.0,1.0);//-4,4);   //back right
    glVertex2f(1.0,1.0);//4,4);    //front right
    glVertex2f(1.0,-1.0);//4,-4);   //front left
    glEnd();
	glPopMatrix();
	
	/*tabletop bottom*/
	glPushMatrix();
	glTranslated(0.0,0.0,-3.0254);
	glBegin(GL_POLYGON);
    glVertex2f(-1.0,-1.0);//-4,-4);  
    glVertex2f(-1.0,1.0);//-4,4);   
    glVertex2f(1.0,1.0);//4,4);    
    glVertex2f(1.0,-1.0);//4,-4);   
    glEnd();
	glPopMatrix();

	/*tabletop back*/
	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
    glTranslated(0.0,0.0,-3.0254);
    glBegin(GL_POLYGON);
    glVertex3f(-1,-1,0);  //bottom left
    glVertex3f(-1,-1,0.0254);   //top left
    glVertex3f(-1,1,0.0254);    //top right
    glVertex3f(-1,1,0);   //bottom right
    glEnd();
    glPopMatrix();

	/*tabletop front*/
	glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslated(0.0,0.0,-3.0254);
    glBegin(GL_POLYGON);
    glVertex3f(1,1,0);  //right bottom 
    glVertex3f(1,1,0.0254);   //right top
    glVertex3f(1,-1,0.0254);    //left top
    glVertex3f(1,-1,0);   //left bottom
    glEnd();
    glPopMatrix();

	/*tabletop left*/
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslated(0.0,0.0,-3.0254);
    glBegin(GL_POLYGON);
    glVertex3f(1,-1,0);  //front bottom
    glVertex3f(1,-1,0.0254);   //front top
    glVertex3f(-1,-1,0.0254);    //back top
    glVertex3f(-1,-1,0);   //back bottom
    glEnd();
    glPopMatrix();
	
	/*tabletop right*/
	glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslated(0.0,0.0,-3.0254);
    glBegin(GL_POLYGON);
    glVertex3f(1,1,0);  //front bottom
    glVertex3f(1,1,0.0254);   //front top
    glVertex3f(-1,1,0.0254);    //back top
    glVertex3f(-1,1,0);   //back bottom
    glEnd();
    glPopMatrix();
	
	/*table leg front right*/
	glPushMatrix();
	//-3.2-2.0=5.2
	//1.5ft = 0.4572m
	//-3.0254 - 0.4572 = -3.4826
    glTranslated(1.0,1.0,-3.4826);
    glRotated(45.0,0,0,1);
	glTranslated(-0.0254,0.0,0.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    glPopMatrix();
	
	/*table leg front left*/
	glPushMatrix();
	glTranslated(1.0,-1.0,-3.4826);
    glRotated(45.0,0,0,1);
    glTranslated(0.0,0.0254,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    glPopMatrix();

	/*table leg back left*/
    glPushMatrix();
    glTranslated(-1.0,-1.0,-3.4826);
    glRotated(45.0,0,0,1);
    glTranslated(0.0254,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    glPopMatrix();

	/*table leg back right*/
	glPushMatrix();
    glTranslated(-1.0,1.0,-3.4826);
    glRotated(45.0,0,0,1);
    glTranslated(0.0,-0.0254,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    glPopMatrix();


	glFlush();
	
	showFPS();	//shows the FPS, FPP, T
    omegaTime();	//calculates the FPS
	PeriodTime();	//calculates the FPP and T
	
	if(cma == true)	//if there is a cma, change the framerate to show it
	{
		glutLockFrameRate(dfr);
	}
	glutSwapBuffers();
}

void glutLockFrameRate(float desiredFrameRate)
{
    int milliWait = (int)(1.0/desiredFrameRate*1000);
    
    int startTime = glutGet(GLUT_ELAPSED_TIME);
    
	do{ }
	while((glutGet(GLUT_ELAPSED_TIME)-startTime<milliWait));
}

/*Draws onto the screen*/
void drawString(GLuint x, GLuint y, void *font, const char* string)
{
	const char *ch;
	glRasterPos2i(x,y);
	for(ch=string; *ch!='\0'; ch++)
	{
		glutBitmapCharacter(font, *ch);
	}
}

void showFPS()	//time for FPS
{
	extern double omega;
	extern unsigned frames;
	extern int pframes;
	extern int oldtime;
	extern int WINDOW_HEIGHT;
	extern int WINDOW_WIDTH;
	extern double pttotal;
	extern int totalFPP;
	extern double totalPTime;

	double width = WINDOW_WIDTH;
	double height = WINDOW_HEIGHT;

	static float fps;

	frames++;	//increments the number of frames

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
    sprintf(fppstring,"FPP: %6.1d",totalFPP);
	
	char *perstring = (char*) malloc(12*sizeof(char));
	sprintf(perstring,"Period: %6.2f",totalPTime);

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
