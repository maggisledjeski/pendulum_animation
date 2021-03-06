#ifndef DISPLAY
#define DISPLAY

#include "includes.h"
#include "prototypes.h"
#include "structs.h"

void display(void)
{
    extern unsigned frames;
	extern double theta;
	extern double eyex;
	extern double eyey;
	extern double eyez;
	extern int pframes;	//frames per period
	extern float dfr;	//desired frame rate
	extern bool cma;
	extern double centerx;
	extern double centery;
	extern double centerz;
	extern GLfloat camerar;
    extern GLfloat cameratheta;
    extern GLfloat cameraphi;
	extern GLuint textureID[4];
    extern GLUquadric *leg1;
    extern GLUquadric *leg2;
    extern GLUquadric *leg3;
    extern GLUquadric *leg4;
    extern GLUquadric *base1;
    extern GLUquadric *base2;
    extern GLUquadric *rod;
    extern GLUquadric *sphere;
	extern GLUquadric *spot;
	extern bool physics;

	glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
	glLoadIdentity();   // Call this before setting the viewing position 
   	gluLookAt(camerar*sin(cameratheta*M_PI/180.0)*cos(cameraphi*M_PI/180.0),camerar*sin(cameratheta*M_PI/180.0)*sin(cameraphi*M_PI/180.0),camerar*cos(cameratheta*M_PI/180.0),
			centerx,centery,centerz,
			0.0,0.0,1.0);

	/*LIGHTINGGGG*/
	#ifdef LIGHTING
	glClearColor(0.0,0.0,0.0,0.0);
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
	GLfloat emission_on[] = { 0.5, 0.5, 0.5, 1.0};
    GLfloat emission_off[] = { 0.0, 0.0, 0.0, 1.0};
	GLfloat a_on[] = { 0.01,0.01,0.01,1.0};//0.6,0.6,0.6,1.0};//0.2, 0.2, 0.2, 1.0};
    GLfloat a_off[] = { 0.0, 0.0, 0.0, 1.0};
	GLfloat d_on[] = { 0.3, 0.5, 0.8, 1.0};
    GLfloat d_off[] = { 0.0, 0.0, 0.0, 1.0};
	GLfloat s_on[] = { 0.2, 0.2, 0.2, 1.0};
    GLfloat s_off[] = { 0.0, 0.0, 0.0, 1.0};
	GLfloat on[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position0[] = { 0.0, 0.0, 1.0, 1.0 };

	/*Material Properties*/
	GLfloat a_mat[] = { 0.9, 0.7, 0.0, 1.0};
    GLfloat d_mat[] = { 0.0, 0.5, 0.0, 1.0};
    GLfloat s_mat[] = { 1.0, 1.0, 1.0, 1.0};  
	GLfloat a_mat1[] = { 0.9, 0.9, 0.9, 1.0};
    GLfloat d_mat1[] = { 0.7, 0.0, 0.0, 1.0};
    GLfloat s_mat1[] = { 0.0, 0.6, 0.0, 1.0};
	
	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, position0);
   	glLightfv(GL_LIGHT0, GL_EMISSION, emission_off);
    glLightfv(GL_LIGHT0, GL_SPECULAR, s_on);
   	glLightfv(GL_LIGHT0, GL_DIFFUSE, d_on);
	glLightfv(GL_LIGHT0, GL_AMBIENT, a_on);
	glTranslated(0.0,0.0,1.0);
	glDisable (GL_LIGHTING);
    glColor3f (0.0, 1.0, 1.0);
    glutWireCube (0.1);
    glEnable (GL_LIGHTING);
	glPopMatrix();

	/*Spotlight*/
	glDisable(GL_COLOR_MATERIAL);
	glPushMatrix();
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 7.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 30.0);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
	float *light1 = (float*) malloc(4*sizeof(float));
    light1[0]= 2.0; light1[1] = 0.0; light1[2]=2.0; light1[3] = 1.0;
    glLightfv(GL_LIGHT1, GL_POSITION, light1);
    light1[0]= 0.0; light1[1] = 0.5; light1[2]=0.0; light1[3] = 1.0;
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1);
	float *direction1 = (float*) malloc(3*sizeof(float));
   	direction1[0]= 0.0; direction1[1] =0.0; direction1[2]=-1.0;
   	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction1);
	glTranslated(2.0,0.0,1.0);
    glDisable(GL_LIGHTING);
    //glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
 	/*cone*/
    #ifdef TEXTURE
	gluCylinder(spot,
            (GLdouble) 0.2,    //radius of the cylinder at z=0
            (GLdouble) 0.05,    //radius of the cylinder at z=height
            (GLdouble) 0.8, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	#endif
	#ifndef TEXTURE
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2,    //radius of the cylinder at z=0
            (GLdouble) 0.05,    //radius of the cylinder at z=height
            (GLdouble) 0.8, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	#endif
	glEnable(GL_LIGHTING);
	glTranslated(0.0,-2.0,-5.0);
	glPushMatrix();
	glTranslated(1.5,0.5,0.0);
	#ifdef TEXTURE
    gluCylinder(base1,
            (GLdouble) 0.15, //radius of the cylinder at z=0
            (GLdouble) 0.15, //radius of the cylinder at z=height
            (GLdouble) 5.5, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    #endif
	#ifndef TEXTURE
	gluCylinder(gluNewQuadric(),//base1,
            (GLdouble) 0.15, //radius of the cylinder at z=0
            (GLdouble) 0.15, //radius of the cylinder at z=height
            (GLdouble) 5.5, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	#endif
	glPopMatrix();
	glPushMatrix();
	glTranslated(2.0,-0.3,0.0);
	glRotated(90.0,1,1,0);
    glTranslated(-3.7,4.0,-3.0);
	glColor3f (1.0,1.0,1.0);
	#ifdef TEXTURE
    gluCylinder(base1,
            (GLdouble) 0.05, //radius of the cylinder at z=0
            (GLdouble) 0.05, //radius of the cylinder at z=height
            (GLdouble) 2.2, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    #endif
	#ifndef TEXTURE
    gluCylinder(gluNewQuadric(),//base1,
            (GLdouble) 0.05, //radius of the cylinder at z=0
            (GLdouble) 0.05, //radius of the cylinder at z=height
            (GLdouble) 2.2, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	#endif
	glPopMatrix();
	glPopMatrix();
	#endif

	/*pend sphere and rod*/
	glPushMatrix();
    glScaled(1.0,1.0,-1.0);
	glTranslated(2.0,0.0,0.2);
    glRotated((double)180*theta/M_PI,1,0,0);
	glRotated((double)180*theta/M_PI,0,0,1);
	#ifdef LIGHTING
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	#endif
	#ifdef TEXTURE
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, textureID[4]);
    gluCylinder(rod,
            (GLdouble) 0.05,	//radius of the cylinder at z=0
            (GLdouble) 0.05,	//radius of the cylinder at z=height
            (GLdouble) 0.8,	//height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    
	glTranslated(0.0,0.0,0.8); //moves the sphere to the swinging end of the pendulum
    gluSphere(sphere,
             (GLdouble) 0.1,	//radius, diameter is .2 thus total length of pendulum is 1 meter
             (GLint)     10,
             (GLint)     10 );
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05,    //radius of the cylinder at z=0
            (GLdouble) 0.05,    //radius of the cylinder at z=height
            (GLdouble) 0.8, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );

    glTranslated(0.0,0.0,0.8); //moves the sphere to the swinging end of the pendulum
    glColor3f (0.0,0.0,1.0);
    gluSphere(gluNewQuadric(),
             (GLdouble) 0.1,    //radius, diameter is .2 thus total length of pendulum is 1 meter
             (GLint)     10,
             (GLint)     10 );
    #endif
	glPopMatrix();

	/*pend horizontal pole*/
    glPushMatrix();
	glTranslated(-0.2,0.0,0.0);
	#ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glRotated(90.0,0,1,0);
	#ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[3]);
    glColor3f (1.0,1.0,1.0);
	gluCylinder(base1,
            (GLdouble) 0.2, //radius of the cylinder at z=0
            (GLdouble) 0.2, //radius of the cylinder at z=height
            (GLdouble) 2.2, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
	#endif
    #ifndef TEXTURE
    glColor3f (0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2, //radius of the cylinder at z=0
            (GLdouble) 0.2, //radius of the cylinder at z=height
            (GLdouble) 2.2, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    #endif
    glPopMatrix();
	
	/*pend vertical pole*/
	glPushMatrix();
	#ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(0.0,0.0,-3.0);
	#ifdef TEXTURE
    glColor3f(1.0,1.0,1.0);
    gluCylinder(base2,//gluNewQuadric(),
            (GLdouble) 0.2, //radius of the cylinder at z=0
            (GLdouble) 0.2, //radius of the cylinder at z=height
            (GLdouble) 3.0, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    #endif
    #ifndef TEXTURE
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.2, //radius of the cylinder at z=0
            (GLdouble) 0.2, //radius of the cylinder at z=height
            (GLdouble) 3.0, //height of the cylinder
            (GLint)    20,
            (GLint)    20 );
    #endif
	glPopMatrix();

	/*tabletop top*/
	glPushMatrix();
    #ifdef LIGHTING
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	#endif
	glTranslated(0.0,0.0,-3.0);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	//2ft = 0.6096m
	//1inch=0.0254m
	glTexCoord2d(-1,-1);    glVertex2f(-1.0,-1.0);  
    glTexCoord2d(-1,1);    glVertex2f(-1.0,1.0);
    glTexCoord2d(1,1);    glVertex2f(1.0,1.0);
    glTexCoord2d(1,-1);    glVertex2f(1.0,-1.0);
    glEnd();
    #endif
	#ifndef TEXTURE
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,-1.0);
    glEnd();
    #endif
	glPopMatrix();
	
	/*tabletop bottom*/
	glPushMatrix();
	#ifdef LIGHTING
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(0.0,0.0,-3.0254);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);    glVertex2f(-1.0,-1.0);  
    glTexCoord2d(-1,1);    glVertex2f(-1.0,1.0);   
    glTexCoord2d(1,1);    glVertex2f(1.0,1.0);    
    glTexCoord2d(1,-1);    glVertex2f(1.0,-1.0);   
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,-1.0);
    glEnd();
    #endif
	glPopMatrix();

	/*tabletop back*/
	glPushMatrix();
    #ifdef LIGHTING
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	#endif
	glTranslated(0.0,0.0,-3.0254);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[2]);
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);    glVertex3f(-1,-1,0);  //bottom left
    glTexCoord2d(-1,1);    glVertex3f(-1,-1,0.0254);   //top left
    glTexCoord2d(1,1);    glVertex3f(-1,1,0.0254);    //top right
    glTexCoord2d(1,-1);    glVertex3f(-1,1,0);   //bottom right
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-1,-1,0);  //bottom left
    glVertex3f(-1,-1,0.0254);   //top left
    glVertex3f(-1,1,0.0254);    //top right
    glVertex3f(-1,1,0);   //bottom right
    glEnd();
    #endif
    glPopMatrix();

	/*tabletop front*/
	glPushMatrix();
    #ifdef LIGHTING
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	#endif
	glTranslated(0.0,0.0,-3.0254);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);    glVertex3f(1,1,0);  //right bottom 
    glTexCoord2d(-1,1);    glVertex3f(1,1,0.0254);   //right top
    glTexCoord2d(1,1);    glVertex3f(1,-1,0.0254);    //left top
    glTexCoord2d(1,-1);    glVertex3f(1,-1,0);   //left bottom
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(1,1,0);  //right bottom
    glVertex3f(1,1,0.0254);   //right top
    glVertex3f(1,-1,0.0254);    //left top
    glVertex3f(1,-1,0);   //left bottom
    glEnd();
    #endif
    glPopMatrix();

	/*tabletop left*/
    glPushMatrix();
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(0.0,0.0,-3.0254);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);    glVertex3f(1,-1,0);  //front bottom
    glTexCoord2d(-1,1);    glVertex3f(1,-1,0.0254);   //front top
    glTexCoord2d(1,1);    glVertex3f(-1,-1,0.0254);    //back top
    glTexCoord2d(1,-1);    glVertex3f(-1,-1,0);   //back bottom
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(1,-1,0);  //front bottom
    glVertex3f(1,-1,0.0254);   //front top
    glVertex3f(-1,-1,0.0254);    //back top
    glVertex3f(-1,-1,0);   //back bottom
    glEnd();
    #endif
    glPopMatrix();
	
	/*tabletop right*/
	glPushMatrix();
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(0.0,0.0,-3.0254);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[2]);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);    glVertex3f(1,1,0);  //front bottom
    glTexCoord2d(-1,1);    glVertex3f(1,1,0.0254);   //front top
    glTexCoord2d(1,1);    glVertex3f(-1,1,0.0254);    //back top
    glTexCoord2d(1,-1);    glVertex3f(-1,1,0);   //back bottom
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f(1,1,0);  //front bottom
    glVertex3f(1,1,0.0254);   //front top
    glVertex3f(-1,1,0.0254);    //back top
    glVertex3f(-1,1,0);   //back bottom
    glEnd();
    #endif
    glPopMatrix();
	
	/*table leg front right*/
	glPushMatrix();
    //-3.2-2.0=5.2
	//1.5ft = 0.4572m
	//-3.0254 - 0.4572 = -3.4826
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(1.0,1.0,-3.4826);
    glRotated(45.0,0,0,1);
	glTranslated(-0.0254,0.0,0.0);
	#ifdef TEXTURE
    glColor3f(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, textureID[3]);
    gluCylinder(leg1,
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #endif
    #ifndef TEXTURE
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #endif
    glPopMatrix();
	
	/*table leg front left*/
	glPushMatrix();
    #ifdef LIGHTING
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(1.0,-1.0,-3.4826);
    glRotated(45.0,0,0,1);
    glTranslated(0.0,0.0254,0.0);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[3]);
    glColor3f(1.0,1.0,1.0);
    gluCylinder(leg2,
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #endif
    #ifndef TEXTURE 
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #endif
    glPopMatrix();

	/*table leg back left*/
    glPushMatrix();
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(-1.0,-1.0,-3.4826);
    glRotated(45.0,0,0,1);
    glTranslated(0.0254,0.0,0.0);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[3]);
    glColor3f(1.0,1.0,1.0);
    gluCylinder(leg3,
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #else
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #endif
    glPopMatrix();

	/*table leg back right*/
	glPushMatrix();
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	glTranslated(-1.0,1.0,-3.4826);
    glRotated(45.0,0,0,1);
    glTranslated(0.0,-0.0254,0.0);
    #ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[3]);
    glColor3f(1.0,1.0,1.0);
    gluCylinder(leg4,
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #endif
    #ifndef TEXTURE
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.0254, //radius of the cylinder at z=0
            (GLdouble) 0.0254, //radius of the cylinder at z=height
            (GLdouble) 0.4572, //height of the cylinder
            (GLint)    4,
            (GLint)    20 );
    #endif
    glPopMatrix();

	/*floor*/
	glPushMatrix();
    glTranslated(0.0,0.0,-3.4826);
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	#ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);	glVertex2f(-9,-9);//-4.572,-4.572);  
    glTexCoord2d(-1,1);		glVertex2f(-9,9);//-4.572,4.572);   
    glTexCoord2d(1.0,1.0);	glVertex2f(9,9);//4.572,4.572);    
    glTexCoord2d(1.0,-1.0);	glVertex2f(9,-9);//4.572,-4.572);   
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-9,-9);//-4.572,-4.572);
    glVertex2f(-9,9);//-4.572,4.572);
    glVertex2f(9,9);//4.572,4.572);
    glVertex2f(9,-9);//4.572,-4.572);
    glEnd();
    #endif    
	glPopMatrix();

	/*ceiling*/
    glPushMatrix();
    glTranslated(0.0,0.0,1.5);
	#ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	#ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);	glVertex2f(-9,-9);//-4.572,-4.572);
    glTexCoord2d(-1,1);		glVertex2f(-9,9);//-4.572,4.572);
    glTexCoord2d(1,1);		glVertex2f(9,9);//4.572,4.572);
    glTexCoord2d(1,-1);		glVertex2f(9,-9);//4.572,-4.572);
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-9,-9);//-4.572,-4.572);
    glVertex2f(-9,9);//-4.572,4.572);
    glVertex2f(9,9);//4.572,4.572);
    glVertex2f(9,-9);//4.572,-4.572);
    glEnd();
    #endif
    glPopMatrix();
	
	/*back wall*/
    glPushMatrix();
	glTranslated(0.0,0.0,-3.4826);
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	#ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);	glVertex3f(-9,-9,0);
    glTexCoord2d(-1,1);		glVertex3f(-9,-9,5);
    glTexCoord2d(1,1);		glVertex3f(-9,9,5);
    glTexCoord2d(1,-1);		glVertex3f(-9,9,0);
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-9,-9,0);//-4.572,-4.572,0);
    glVertex3f(-9,-9,5);//-4.572,-4.572,4.4826);
    glVertex3f(-9,9,5);//-4.572,4.572,4.4826);
    glVertex3f(-9,9,0);//-4.572,4.572,0);
    glEnd();
    #endif
    glPopMatrix();

	/*left wall*/
    glPushMatrix();
    glTranslated(0.0,0.0,-3.4826);
	#ifdef LIGHTING
    glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	#ifdef TEXTURE
    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);	glVertex3f(-9,-9,0);
    glTexCoord2d(-1,1);		glVertex3f(-9,-9,5);
    glTexCoord2d(1,1);		glVertex3f(9,-9,5);
    glTexCoord2d(1,-1);		glVertex3f(9,-9,0);
    glEnd();
    #endif 
    #ifndef TEXTURE
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-9,-9,0);//-4.572,-4.572,0);
    glVertex3f(-9,-9,5);//-4.572,-4.572,4.4826);
    glVertex3f(9,-9,5);//-4.572,4.572,4.4826);
    glVertex3f(9,-9,0);//-4.572,4.572,0);
    glEnd();
    #endif
    glPopMatrix();

	/*right wall*/
    glPushMatrix();
    glTranslated(0.0,0.0,-3.4826);
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	#ifdef TEXTURE
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);	glVertex3f(9,9,0);
    glTexCoord2d(-1,1);		glVertex3f(9,9,5);
    glTexCoord2d(1,1);		glVertex3f(-9,9,5);
    glTexCoord2d(1,-1);		glVertex3f(-9,9,0);
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(9,9,0);//-4.572,-4.572,0);
    glVertex3f(9,9,5);//-4.572,-4.572,4.4826);
    glVertex3f(-9,9,5);//-4.572,4.572,4.4826);
    glVertex3f(-9,9,0);//-4.572,4.572,0);
    glEnd();
    #endif
    glPopMatrix();

    /*left wall*/
    glPushMatrix();
    glTranslated(0.0,0.0,-3.4826);
    #ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s_mat);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    #endif
	#ifdef TEXTURE
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(-1,-1);	glVertex3f(9,9,0);
    glTexCoord2d(-1,1);		glVertex3f(9,9,5);
    glTexCoord2d(1,1);		glVertex3f(9,-9,5);
    glTexCoord2d(1,-1);		glVertex3f(9,-9,0);
    glEnd();
    #endif
    #ifndef TEXTURE
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
	glVertex3f(9,9,0);//-4.572,-4.572,0);
    glVertex3f(9,9,5);//-4.572,-4.572,4.4826);
    glVertex3f(9,-9,5);//-4.572,4.572,4.4826);
    glVertex3f(9,-9,0);//-4.572,4.572,0);
    glEnd();
    #endif
    glPopMatrix();

	glFlush();
    #ifdef TEXTURE
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
	#endif
	showFPS();	//shows the FPS, FPP, T
    omegaTime();	//calculates the FPS
	PeriodTime();	//calculates the FPP and T
	if(physics == true)
	{
		showPhysics();	
	}
	if(cma == true)	//if there is a cma, change the framerate to show it
	{
		glutLockFrameRate(dfr);
	}
	#ifdef LIGHTING
	free(light1);
	free(direction1);
	#endif
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

/*builds the physics display window*/
void showPhysics()
{
	extern int WINDOW_HEIGHT;
    extern int WINDOW_WIDTH;
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0,(double) WINDOW_WIDTH,0.0,(double) WINDOW_HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
	
	glDisable(GL_CULL_FACE);
	glClear(GL_DEPTH_BUFFER_BIT);	

	#ifdef TEXTURE
	glColor3f(1.0,1.0,1.0);
    glRecti(455.0,0.0,600.0,130.0);
	#endif
	drawPhysics();
	char *fpsstring = (char*) malloc(5*sizeof(char));
    sprintf(fpsstring,"Theta");
	char *string = (char*) malloc(5*sizeof(char));
    sprintf(string,"Omega");
	/*text*/
    glColor3f(0.0,0.0,0.0);
    drawString(560,10,GLUT_BITMAP_HELVETICA_12,fpsstring);
    drawString(460,115,GLUT_BITMAP_HELVETICA_12,string);
	/*y-axis*/	
	glBegin(GL_LINES);
    glVertex3f(480.0,110.0,0.0);
    glVertex3f(480.0,10.0,0.0);
    glEnd();
	/*x-axis*/
	glBegin(GL_LINES);
    glVertex3f(555.0,10.0,0.0);
    glVertex3f(480.0,10.0,0.0);
    glEnd();
	/*white background*/	
	#ifndef TEXTURE
	glColor3f(1.0,1.0,1.0);
    glRecti(455.0,0.0,600.0,130.0);
	#endif
	glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
	
	free(fpsstring);
	free(string);
}
/*Calulates and draws the physics in the pop-up display*/
void calculatePhysics(double x, double y)
{
	extern double theta;
	extern list <vertex> vList;

	double gxmin = 0.0;
	double gymin = 0.0;
	double vxmin = 480.0;
	double vymin = 10.0;
	double vxmax = 555.0;
	double vymax = 110.0;
	double fxmin = -3.0;
	double fymin = -3.0;
	double fxmax = 3.0;
	double fymax = 3.0;
		
	/*Calculate the screen points*/
	vertex v;
	double screenx = gxmin + vxmin + ((x - fxmin)/(fxmax - fxmin)) * (vxmax - vxmin);
	double screeny = gymin + vymin + ((y - fymin)/(fymax - fymin)) * (vymax - vymin);
	//cout << screenx << " " << screeny << endl;
	v.x = screenx;
	v.y = screeny;
	vList.push_back(v);
}

void drawPhysics(void)
{	
	extern list <vertex> vList;
	/*Draw the screen points*/
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
	for(list<vertex>::iterator it=vList.begin(); it!=vList.end(); it++)
    {
        glVertex2f((*it).x,(*it).y);
    }
	glEnd();
}
#endif
