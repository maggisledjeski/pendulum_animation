#ifndef PROTOTYPES
#define PROTOTYPES

void init(void);
void display(void);
void reshape (int , int );
void checkFPS(int val);
void step(double *t, double *theta, double *omega );
void stepCall(void);
void showFPS(void);
void drawString(GLuint x, GLuint y, void *font, const char* string);
//#include "structs.h"

/*void init(void);
void drawAxes(int );
void defineBox( struct box* );
void drawBox( struct box* );
void display(void);
void reshape (int , int );
void idleFunc();
*/
#endif

