#ifndef GLOBALS
#define GLOBALS

#include "includes.h"

unsigned frames = 0;
int oldtime = 0;
int WINDOW_HEIGHT = 600;
int WINDOW_WIDTH = 600;
double t = 0.0;
double theta = M_PI/4.0;
double omega = -0.0;
double eyex = 10.0;
double eyey = 0.0;
double eyez = 0.0;
bool sc1 = false;
bool sc2 = false;
char osign = 'n';
int oldptime = 0;
int totaltime = 0;

#endif
