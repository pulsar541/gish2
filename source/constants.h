#ifndef CONSTANTS_H
#define CONSTANTS_H


int winW = 1;	
int winH = 1;

bool DEBUG_MODE = false;
double dT=1;
float shadow_volume = 0.9;
bool SH1 = false;
float ANGLE = 0.0;
float UDANG = 0.0;
int WIDTH = 75;
int ZFAR = 10000;
int viewAngle = 40;
int DISTANCETOSCENE = 1200;//1200;
bool pauseMode = false;



#define pum	 {glPushMatrix();
#define pom	 glPopMatrix();}

#define lon  glEnable(GL_LIGHTING);
#define loff  glDisable(GL_LIGHTING); 
#define don	 glEnable(GL_DEPTH_TEST);
#define doff glDisable(GL_DEPTH_TEST); 
#define aaon  glEnable(GL_POLYGON_SMOOTH);
#define aaoff glDisable(GL_POLYGON_SMOOTH); 
#define blon  glEnable(GL_BLEND);
#define bloff glDisable(GL_BLEND); 

#define		_torad	0.017453293  //3.1415926/180;
#define		_toa	57.29577952  //180/3.1415926;
#define MAX(a,b) ((a < b) ? (b) : (a))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define SIGN(x)  ((x) < (0) ? (-1) : (1))
#define SQR(x)   ((x) * (x))

int TOTALCOUNT =100;


#define MAXPRIMCOUNT 20000
#define MAXENEMYCOUNT 1000
#define MAXDOORCOUNT 100
#define CHECKPOINT_COUNT 10
#define MAXITEMS 300

#define DEFAULT_GRAVITY 0.16


//MyLine *line[3000]; 



#endif
