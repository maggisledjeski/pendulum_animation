#ifndef GLOBALS
#define GLOBALS

#include "includes.h"

bool cma = false;
unsigned frames = 0;
int pframes = 0;
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
bool sc3 = false;
bool sc4 = false;
char osign = 'n';
char osign2 = 'n';
int opt = 0;
int tpt = 0;
int oldptime = 0;
int totaltime = 0;	//my pendulum period time
double oldppt = 0.0;	//old physics period time
double pttotal = 0.0;	//physics period time
float dfr;// = 60.0;	//desired frame rate
double centerx = 0.0;
double centery = 0.0;
double centerz = 0.0;


int totalFPP = 0;
double totalPTime = 0.0;


#endif
