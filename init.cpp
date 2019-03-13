#ifndef INIT
#define INIT

#include "includes.h"
//#include "prototypes.h"
void loadTextures();
void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
	#ifdef TEXTURE
	loadTextures();
	#endif
}

#endif

