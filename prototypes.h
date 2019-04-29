#ifndef PROTOTYPES
#define PROTOTYPES

void init(void);
void display(void);
void reshape (int , int );
void omegaTime(void);//int val);
void step(double *t, double *theta, double *omega );
void stepCall(void);
void showFPS(void);
void drawString(GLuint x, GLuint y, void *font, const char* string);
void keyboard(unsigned char key, int x, int y);
void glutLockFrameRate(float desiredFrameRate);
void PeriodTime(void);
void processSpecialKeys(int key, int x, int y);
void loadTextures(void);
void showPhysics(void);
void calculatePhysics(double x, double y);
void drawPhysics(void);
#endif

