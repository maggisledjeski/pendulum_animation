#ifndef INIT
#define INIT

#include "includes.h"
//#include "prototypes.h"
void loadTextures();
void init(void)
{
    extern GLUquadric *leg1;
    extern GLUquadric *leg2;
    extern GLUquadric *leg3;
    extern GLUquadric *leg4;
    extern GLUquadric *base1;
    extern GLUquadric *base2;
    extern GLUquadric *rod;
    extern GLUquadric *sphere;
	extern GLUquadric *spot;
	
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
	#ifdef TEXTURE
	loadTextures();
    leg1 = gluNewQuadric();
    gluQuadricTexture(leg1, GL_TRUE);
    leg2 = gluNewQuadric();
    gluQuadricTexture(leg2, GL_TRUE);
    leg3 = gluNewQuadric();
    gluQuadricTexture(leg3, GL_TRUE);
    leg4 = gluNewQuadric();
    gluQuadricTexture(leg4, GL_TRUE);
	base1 = gluNewQuadric();
    gluQuadricTexture(base1, GL_TRUE);
    base2 = gluNewQuadric();
    gluQuadricTexture(base2, GL_TRUE);
    rod = gluNewQuadric();
    gluQuadricTexture(rod, GL_TRUE);
    sphere = gluNewQuadric();
    gluQuadricTexture(sphere, GL_TRUE);
    spot = gluNewQuadric();
	gluQuadricTexture(spot, GL_TRUE);
	#endif
}

#endif

