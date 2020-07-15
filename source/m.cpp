// lab4.cpp : Defines the entry point for the console application.
//

#include "glut.h"
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <vector>
//#include<gl/glaux.h>
//#include "tgalib.h"

using namespace std;

	float crossX ;
	float crossY ;

float SLOMO_K = 1;
#include "mystuctures.h"
#include "constants.h"
#include "mygish.h"
#include "enemy.h"
#include "draw.h"
#include "spisok.h"
#include "scene.h"
#include "levelManager.h"


bool onlgt[2];


bool moveUP=false;
bool moveDOWN=false;
bool moveLEFT=false;
bool moveRIGHT=false;


bool moveUP_2=false;
bool moveDOWN_2=false;
bool moveLEFT_2=false;
bool moveRIGHT_2=false;


bool jump=false;
float YROT= 0;
float XROT= 0;
float ZROT= 0;
bool cameraHeroOrientation = true;
char command[100];
bool  playing=true;
//PointF light[2];
PointF MEDGISH;
GLsizei width,height;
GLenum format;
GLenum type;
POINT mousePos;

PointF  camera;
GLfloat d=0;

int NUMLINES;
int NUM_TR;
int RMX = limitX;
int LMX = 0;
int BMY = limitY;
int TMY = 0;

MyGish gish;

Primitive		prim[MAXPRIMCOUNT];
Enemy			enemy[MAXENEMYCOUNT];
Weapon			weapon[11];
Door			door[MAXDOORCOUNT];
Key				key[MAXDOORCOUNT];
Item			item[MAXITEMS];

int enemyCount = 0;
int doorCount = 0;
int keyCount = 0;
int itemCount = 0;

vector<Building>		ball;


vector<int> n_prim_graph_actual;
vector<int> n_prim_actual;
//vector<Primitive>		::iterator iter_prim;
vector<Building>		::iterator pBall;
vector<Enemy>			::iterator iter_enemy;	
vector<int> n_enemy_actual;

PointF Hero;
PointF exitLevel;
PointF startLevel;
PointF respawnPoint;
PointF checkPoint[CHECKPOINT_COUNT];


Scene scene;
LevelManager levelManager;

float	FVector::gravity = 0.16;

bool isMap = false;

bool noclipMode = false;


float colorGeo[3];
float colorWalk[3];

float lightColor[100][100][3];

bool researched[100][100];
char dat[101][101];



GLfloat	real_lightmodel[4]={0.1,0.1,0.1,1};

PointF forbombPoint;


void GetQuadCoord(int *I,int *J, PointF heroPos)
{
	*I = heroPos.x / SIZE1;
	*J = 101-heroPos.y / SIZE2;

	if (*I<0 || *I>99) *I=0;
	if (*J<0 || *J>99) *J=0;


}


bool underCameraUnit (PointF unit, PointF camera, int area)
{
	int iii,jjj;
	GetQuadCoord(&iii,&jjj, unit);

	int iii2,jjj2;
	GetQuadCoord(&iii2,&jjj2, camera);

	if(fabs(iii-iii2) < area && fabs(jjj-jjj2) < area)
		return true;

	return false;
}


bool researchedUnit (PointF unit)
{
	int iii,jjj;
	GetQuadCoord(&iii,&jjj, unit);

	if(iii >=0 && iii<100 && jjj>=0 && jjj<100)
		if(researched[iii][jjj])
			return true;


	return false;
}


void DescCollision(Unit *unit,  int *primIndex)
{
	
	int iii,jjj;
	GetQuadCoord(&iii,&jjj,	*unit);
	int primi =  -1;

	for (int n = iii-2; n<=iii+1; n++)
	 for(int m = jjj-1; m<=jjj+1; m++)
	 {
		if(n >=0 && m>=0 && n<100 && m<100)
		{
			
			if((primi = Collision( unit,	&prim[desc[n][m].num1])) != -1)  {*primIndex = primi; }
			if((primi = Collision( unit,	&prim[desc[n][m].num2])) != -1)  {*primIndex = primi; }
		}
	 }

	for(int d=0;d<doorCount;d++)	
	{
		if(door[d].inBox(unit))
			Collision( unit,	&door[d]);
	}

}


void SimpleCollision(Unit *unit)
{
	int iii,jjj;
	GetQuadCoord(&iii,&jjj,	*unit);
	Collision( unit,	&prim[desc[iii][jjj].num1]);
	Collision( unit,	&prim[desc[iii][jjj].num2]);
}

void Collisions()
{
	GetQuadCoord(&curDescI,&curDescJ,gish.medium());

	//curDescI = gish.medium().x / SIZE1;
	//curDescJ = 101-gish.medium().y / SIZE2;
		   	int i;
	
		if(!noclipMode)
		{

			if(gish.LIP && !gish.SKOL)	
			{
		
				  
					for (int n = curDescI-1; n<=curDescI+1; n++)
					  for(int m = curDescJ-1; m<=curDescJ+1; m++)
					  {	
						  if(n >=0 && m>=0 && n<100 && m<100)
						  {	
							for(int k =0; k<2 ; k++)
							  {	gish.Slipanie(&prim[desc[n][m].num1],NUM_TR,6,
								 moveUP || moveUP_2 ,
								 moveDOWN || moveDOWN_2,
								 moveLEFT || moveLEFT_2,
								 moveRIGHT || moveRIGHT_2
										);

								gish.Slipanie(&prim[desc[n][m].num2],NUM_TR,6,
								 moveUP || moveUP_2 ,
								 moveDOWN || moveDOWN_2,
								 moveLEFT || moveLEFT_2,
								 moveRIGHT || moveRIGHT_2
										);
							  }
						  }
					  }

					  for(int k=0;door[k].corrected();k++)
								gish.Slipanie(&door[k],NUM_TR,6.51,
								 moveUP || moveUP_2 ,
								 moveDOWN || moveDOWN_2,
								 moveLEFT || moveLEFT_2,
								 moveRIGHT || moveRIGHT_2
										);

			}




			for(  i=0;i<gish.N;i++)	
			{
				gish.bui[i]->inWater = false;
				gish.bui[i]->onHard = false;
				int primi=-1;
				DescCollision(gish.bui[i],&primi);

				if(primi >=0 && primi<MAXPRIMCOUNT)
				  {


						gish.AdditionColliz(
							&prim[primi],
							NUM_TR,
							 moveUP || moveUP_2 ,
							 moveDOWN || moveDOWN_2,
							 moveLEFT || moveLEFT_2,
							 moveRIGHT || moveRIGHT_2,
							 jump,
							 i);

				  }
				
			}
			FVector::gravity =DEFAULT_GRAVITY;


		}
		else FVector::gravity = 0;

		
		//float dx  = -(float)sin((-90+ZROT)*_torad) * 0.05f;
		//	float dy  = (float)cos((-90+ZROT)*_torad) * 0.05f;
		gish.oldMed = gish.medium();

			for( i=0;i<gish.N;i++)
			{
	
				if(!gish.bui[i]->moveble) 
					gish.bui[i]->CalcVector();
				


		
				if(moveDOWN || moveDOWN_2 ) gish.bui[i]->FMove.addImpulse(0, -0.04);
				if(moveUP|| moveUP_2 ) 	 gish.bui[i]->FMove.addImpulse(0, 0.04);
				

				if(YROT >= 90 &&  YROT < 270)
				{ if(moveRIGHT || moveRIGHT_2 ) gish.bui[i]->FMove.addImpulse(-0.04, 0);	
				  if(moveLEFT || moveLEFT_2) gish.bui[i]->FMove.addImpulse(0.04, 0);
				}
				else
				{ if(moveLEFT || moveLEFT_2) gish.bui[i]->FMove.addImpulse(-0.04, 0);	
				  if(moveRIGHT || moveRIGHT_2) gish.bui[i]->FMove.addImpulse(0.04, 0);
				}
		

			//	if(moveDOWN) gish.bui[i]->FMove.addImpulse(-dx, -dy);
			//	if(moveUP) 	 gish.bui[i]->FMove.addImpulse(dx, dy);



				if(!gish.bui[i]->moveble) 
				{	gish.bui[i]->CalcDxDy();	
					gish.bui[i]->Move();
				}

			}	

			gish.Kaplya();
			////////////
			/////////////
			////////////
		


	int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
	
	 	    for(int d=0;key[d].corrected();d++) 
			{
				int primi;
				DescCollision(&key[d],&primi);
				MyGishCollision(&gish,&key[d]);
				key[d].CalcVector();
				key[d].CalcDxDy();
				key[d].Move();

			}


			for(int k=0;k<11;k++)
			{	weapon[k].inWater = false;
				weapon[k].onHard = false;
					
				
				if(gish.currentWeapon != k) 
				{	MyGishCollision(&gish,&weapon[k]);
					int primi;
					DescCollision(&weapon[k],&primi);	
				
					for ( int d  = 0; d < 10; d++)
					if(d!=k) 
						Proch(&weapon[k],&weapon[d], weapon[d].radius + weapon[k].radius);
				

	
					for(d=0; door[d].corrected();d++)	
					{
						Proch(&weapon[k],&key[d], key[d].radius + weapon[k].radius);
					}
				
				
				//	int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
					for ( int j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
					{
							Proch(&weapon[k],&enemy[n_enemy_actual[j]], enemy[n_enemy_actual[j]].radius + weapon[k].radius);
					}
				}

				weapon[k].CalcVector();
				weapon[k].CalcDxDy();
				weapon[k].Move();
			

			
				for(i=0; i<10;i++)
					weapon[k].impact[i].inWater = false;

				for(i=0; i<10; i++)
				{
					int iii,jjj;
					GetQuadCoord(&iii,&jjj,	weapon[k].impact[i]);	
					Collision( &weapon[k].impact[i],	&prim[desc[iii][jjj].num1]);
					Collision( &weapon[k].impact[i],	&prim[desc[iii][jjj].num2]);

					for(int d=0; door[d].corrected();d++)	
					{
						Collision( &weapon[k].impact[i],	&door[d]);
					}


					if(weapon[k].impact[i].H)
					{	weapon[k].impact[i].CalcVector();
						weapon[k].impact[i].CalcDxDy();
						weapon[k].impact[i].Move();
					}
				}
			}

 int j;
						
			
				for (  j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
				{	
					Enemy *tmpEnemy;  
					tmpEnemy = &enemy[n_enemy_actual[j]];
					tmpEnemy->inWater = false;
					tmpEnemy->onHard  = false;
					
					for ( int k  = 0; k < ENEMY_ACTUAL_COUNT; k++)
					{	if(n_enemy_actual[j]==n_enemy_actual[k]) continue;
						Enemy *tmpEnemy2; 
						tmpEnemy2 = &enemy[n_enemy_actual[k]];
						Proch(	tmpEnemy2, tmpEnemy, tmpEnemy->radius + tmpEnemy2->radius);
					}
					  
				    MyGishCollision(&gish,tmpEnemy); /////!
					int primi;
				    DescCollision(&enemy[n_enemy_actual[j]],&primi);
					enemy[n_enemy_actual[j]].CalcVector();
					enemy[n_enemy_actual[j]].CalcDxDy();
					enemy[n_enemy_actual[j]].Move();
				}



				for (  j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
				{	

					Enemy *tmpEnemy;  
					tmpEnemy = &enemy[n_enemy_actual[j]];
	
					
					for( k=0; k<10;k++)
					{
						tmpEnemy->impact[k].inWater = false;
						tmpEnemy->impact[k].onHard = false;

						SimpleCollision(&tmpEnemy->impact[k]); 
					
						MyGishCollision(&gish,&tmpEnemy->impact[k]); 


						if(tmpEnemy->impact[k].onHard)tmpEnemy->impact[k].H = 0;

						for (  d  = 0; d < ENEMY_ACTUAL_COUNT; d++)
						{
							if(d!=j) 
							{
								if(enemy[n_enemy_actual[d]].health > 0)
									PROCH(&tmpEnemy->impact[k],&enemy[n_enemy_actual[d]], enemy[n_enemy_actual[d]].radius,5000);
							}
						}
						
	
						if(tmpEnemy->impact[k].H)
						{	tmpEnemy->impact[k].CalcVector();
							tmpEnemy->impact[k].CalcDxDy();
							tmpEnemy->impact[k].Move();

							if(tmpEnemy->impact[k].onHard )
							{	tmpEnemy->impact[k].H=0;
								tmpEnemy->impact[k].setPos(10000,1000000);
							}

						}

					}		
		
				}

			
		

	//		TROS ((Unit**)ball,0,ball.size()-1,12.4,2000);

			TROS(&ball,20,5000);
		//	SVIAZKA (&ball[0],&ball[ball.size()-1],12.4,2000);
			
		



	//		if(moveUP) weapon[GUN].y+=5;
	//		if(moveDOWN) weapon[GUN].y-=5;
	//		if(moveLEFT) weapon[GUN].x-=5;
	//		if(moveRIGHT) weapon[GUN].x+=5;

	//		if(moveUP_2) weapon[SUPER_WEAPON].y+=5;
	//		if(moveDOWN_2) weapon[SUPER_WEAPON].y-=5;
	//		if(moveLEFT_2) weapon[SUPER_WEAPON].x-=5;
	//		if(moveRIGHT_2) weapon[SUPER_WEAPON].x+=5;

			
			ball[0].x = weapon[SUPER_WEAPON].x;
			ball[0].y =	weapon[SUPER_WEAPON].y;

	//		ball[ball.size()-1].x = weapon[GUN].x;
	//		ball[ball.size()-1].y =	weapon[GUN].y;




		
			for(pBall=ball.begin(); pBall!=ball.end(); pBall++)
			{

		
				for (  j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
				{	

					
					Enemy *tmpEnemy;  
					tmpEnemy = &enemy[n_enemy_actual[j]];
					if(tmpEnemy->health > 0)
						Proch(tmpEnemy,pBall, pBall->radius + tmpEnemy->radius);

				}


				int primi;
				DescCollision(pBall,&primi);


				pBall->CalcVector();
				pBall->CalcDxDy();
				pBall->Move();
			/*	for( int i=0;i<gish.N;i++)	
				{

					if(gish.LIP && Dist(gish.bui[i],pBall)<gish.bui[i]->radius+pBall->radius+5)
					{
						SVIAZKA(gish.bui[i],pBall,14,5000);
					}
					else 	Proch(pBall,	gish.bui[i],	6+pBall->radius);

				}*/
			}
	
}



void setDeath()
{

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.9);
	glEnable (GL_LIGHT1);
	glDisable (GL_LIGHT0);
	real_lightmodel[0]=0;
	real_lightmodel[1]=0;
	real_lightmodel[2]=0;
	real_lightmodel[3]=1;
//	glClearColor(0.1,0,0,1);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,real_lightmodel);
	GLfloat	diffuse[4]={1,0.5,0.5,1};
	glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse);

}


void setDay()
{	glDisable (GL_LIGHT0);


	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.9);
	glEnable (GL_LIGHT1);
	glDisable (GL_LIGHT2);
	real_lightmodel[0]=0.1;
	real_lightmodel[1]=0.1;
	real_lightmodel[2]=0.1;
	real_lightmodel[3]=1;
	glClearColor(0.95,1,1,1);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,real_lightmodel);
	GLfloat	diffuse[4]={1,1,1,1};
	glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse);



	GLfloat myLightPosition[] = {
									0, 
									10000, 
									0, 
									1
								};
	glLightfv(GL_LIGHT1, GL_POSITION, myLightPosition);	

	
}

void setLocalLight(int number,
				   int x,int y,float z,
				   float difR, float difG, float difB,
				   GLfloat k)
{	
	
	glDisable (GL_LIGHT0);
	glLightf(GL_LIGHT0+number, GL_QUADRATIC_ATTENUATION, k);
	glEnable (GL_LIGHT0+number);

	real_lightmodel[0]=0.02;
	real_lightmodel[1]=0.02;
	real_lightmodel[2]=0.02;
	real_lightmodel[3]=1;
	glClearColor(0,0,0,1);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,real_lightmodel);

//	int n,m;
//	GetQuadCoord(&n,&m, ToPointF(x,y));

	int n = x/SIZE1;
	int m = 101 - y/SIZE2;
	
//	if(number > 1)
/*	{
		glLightfv(GL_LIGHT0+number,GL_DIFFUSE,diffuse);
	}
	else{*/
		GLfloat	diffuse[4]={difR,difG,difB,1};
		glLightfv(GL_LIGHT0+number,GL_DIFFUSE,diffuse);
//	}

	

	GLfloat myLightPosition[] = {
									x,
									y,	
									z, 
									1
								};

	glLightfv(GL_LIGHT0+number, GL_POSITION, myLightPosition);	


	

}

DWORD starttime1=timeGetTime(),time_1;
DWORD starttime2=timeGetTime(),time_2;
DWORD starttime3=timeGetTime(),time_3;
DWORD tGT=timeGetTime ();


void CreateLines(char *path);
void MyMouseFunc();

	   int deathPause = 0;
void myIdle()
{ 



	try{
	
	int n;

   tGT = timeGetTime ();         
   time_1 = tGT-starttime1; 
   time_2 = tGT-starttime2; 
   time_3 = tGT-starttime3;
 

    if(time_3>1000/100)
	   {
	
	//	 MyMouseFunc();

  		glutPostRedisplay();			
		starttime3+=time_3;

	   }

	if(pauseMode)
		return;

	gish.timer();
	
	for(int i=0; i<10; i++)
		weapon[i].timer();

	for(int d=0;d<MAXDOORCOUNT;d++)
		door[d].timer();

//	if ( gish.time[0] >= 45000 )  
//	{
//		respawnPoint = gish.medium();
 //  		gish.starttime[0] += gish.time[0];	
//	}
	
  // int numEnemyActual = n_enemy_actual.size();
    for( n=0; n < enemyCount; n++)
	{ //  if(	enemy[n_enemy_actual[n]].health>0)
			enemy[n].timer();
			
	}				





   if ( time_2 > 1000/5)  
   { starttime2 += time_2; 
	
   /*   int numEnemyActual = n_enemy_actual.size();
	  for( n=0; n < numEnemyActual; n++)
	  {
	   enemy[n_enemy_actual[n]].setGoal(gish.medium().x, gish.medium().y);

	  }*/





	  if( gish.H<= 0 || weapon[BOMB].health <=0)
	  {
		  gish.H = 0 ;
		  deathPause++;
		  setDeath();
		  if(deathPause > 25) 
		  {	 //glClearColor(0,0,0,1);
//		     setNight();
			weapon[BOMB].health = gish.H = 100;	
			PointF tmpP = respawnPoint;
			CreateLines((char*)levelManager.getCurrentLevel().c_str());
			gish.SetPos(tmpP.x, tmpP.y);

			deathPause=0;
		  }
		  
	  }


	  if(Dist(gish.medium(), exitLevel) < 50)
		  CreateLines((char*)levelManager.nextLevel("mapscript.dat").c_str());

	  for(int d=0; door[d].corrected(); d++)
		  for(int k=0; key[k].corrected(); k++)
			  if(key[k].NUM == door[d].NUM)
				  if(key[k].x + key[k].radius > door[d].boxMIN.x 					  
					  && key[k].x - key[k].radius < door[d].boxMAX.x 
					 &&key[k].y + key[k].radius > door[d].boxMIN.y 					  
					  && key[k].y - key[k].radius < door[d].boxMAX.y  )
				  {door[d].open();
				   key[k].radius = 0;
				  }
	  


	  for(n = 0;  n<MAXPRIMCOUNT; 	n++)
		prim[n].Move();
		   

	  n_enemy_actual.clear();

	  for (n = 0; n < enemyCount; n++)
	  {	
		  enemy[n].ACTUAL = 
			  simple_rasst((PointF)enemy[n],gish.medium(),1500) 
		   || simple_rasst((PointF)enemy[n],weapon[BOMB],1500);


		  if( enemy[n].ACTUAL)
		  {	  n_enemy_actual.push_back(n);
			/*
				if(weapon[BOMB].active && Dist(&weapon[BOMB],&enemy[n]) < Dist(&gish.medium(), &enemy[n]))
					enemy[n].setGoal(weapon[BOMB].x, weapon[BOMB].y);
				else  
					enemy[n].setGoal(gish.medium().x, gish.medium().y);*/

				enemy[n].setGoal(gish.medium().x, gish.medium().y);			 
				if(weapon[BOMB].active)
					enemy[n].setGoal(weapon[BOMB].x, weapon[BOMB].y);

		  }
	  }

	
	
         /////////////////////////////////////////////////////////////////
	  gish.oldH = gish.H;


	  for(n=0; n< CHECKPOINT_COUNT; n++) 
		if(Dist(gish.medium(), checkPoint[n]) < 70)
		  respawnPoint =  checkPoint[n] ; 
  

	  if(Dist(gish.medium(), weapon[BOMB]) <  105) 
	  {	 
		 if(!weapon[BOMB].active )
		 { for(int i=0;i<enemyCount; i++)
			  enemy[i].setLive(); 
		  
		  weapon[BOMB].active = true;
		 }
	  }

	  if(weapon[DETONATOR].fire)
	  {
		 

		  int iii,jjj;
		  GetQuadCoord(&iii,&jjj, weapon[BOMB]);

		  for(int n = iii-1; n<=iii+1; n++)
			for(int m=jjj-1; m<=jjj+1; m++)
			{
				if(prim[desc[n][m].num1].type == FORBOMB || prim[desc[n][m].num2].type == FORBOMB) {
				   prim[desc[n][m].num1].setPos(ToPointF(0,0), ToPointF(0,1), ToPointF(1,1));
				   prim[desc[n][m].num2].setPos(ToPointF(0,0), ToPointF(0,1), ToPointF(1,1));
					weapon[DETONATOR].setPos(100000,10000);
					weapon[DETONATOR].setMassive(false);
					weapon[DETONATOR].active=false;

					weapon[BOMB].setPos(100000,10000);
					weapon[BOMB].setMassive(false); 
					
					if(weapon[BOMB].active)
					  {	weapon[BOMB].active=false;
						for(int i=0;i<enemyCount; i++)
						  enemy[i].setLive(); 
						//  enemy[i].setSpirit(true);
					  }

				}
			}

	  }

	  for(n=0; n< itemCount; n++)
	  {
		  if(Dist(gish.medium(), item[n]) < 70 )
		  {
		
			
			  if(gish.H < 100) 
			  {	  gish.H += item[n].radius*2 ;
				  item[n].setPos(100000,100000);

			  }
			 if(gish.H > 100) 
				 gish.H = 100;
			

		  }
	  }
		
	/*	if(gish.FIRE)
		{
			PointF A = gish.medium();
			PointF B = ToPointF(gish.impact[0].x,gish.impact[0].y);


			int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
			float dist = 10000000000;
			int numnearEnemy = -1;
			for ( int j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
			{
				if(enemy[n_enemy_actual[j]].health>0)
				{

					float curdist = Dist( (PointF)enemy[n_enemy_actual[j]], gish.medium()) ;
				
					if(	 curdist < dist 
						&& CircleIntersects(&enemy[n_enemy_actual[j]].x, &enemy[n_enemy_actual[j]].y, enemy[n_enemy_actual[j]].radius, Dist(A, B), A, B))					
					{	dist = curdist;
						numnearEnemy = n_enemy_actual[j];
					}
				}
			}

			if(numnearEnemy > -1)
			{
				enemy[numnearEnemy].health -= 3;
			}
		}
	*/		




		
		int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
		for (int  j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
		{

			


			if(researchedUnit(	enemy[n_enemy_actual[j]]) )
				enemy[n_enemy_actual[j]].sleeping = false;


			if(	enemy[n_enemy_actual[j]].health>0)	
			{
				Enemy *tmpEnemy;  
				tmpEnemy = &enemy[n_enemy_actual[j]];

				if(weapon[BOMB].active && Dist(&weapon[BOMB],tmpEnemy)<=tmpEnemy->radius+weapon[BOMB].radius+1)
				{
					weapon[BOMB].health-= minirand()*3;
				}

				for( int i=0;i<gish.N;i++)	
				{

					if(Dist(gish.bui[i],tmpEnemy)<tmpEnemy->radius)
					{
					
						gish.H -= minirand()*3;

					}
					
					if(gish.TVER && Dist(gish.bui[i],tmpEnemy)<tmpEnemy->radius+10)
					{
						tmpEnemy->health -=2;
					}



				/*	for(int i=0;i<10;i++)
						if(Dist(&gish.medium(), &tmpEnemy->impact[i])<tmpEnemy->radius + 20)
						{
						gish.H -= minirand()*10;
						tmpEnemy->impact[i].H=0;
						tmpEnemy->impact[i].setPos(tmpEnemy->x,tmpEnemy->y );
				//		tmpEnemy->impact[i].setDxDy(0, 0);
						}*/
				}
				
				
				for(int k=0;k<10;k++)
				{		for( int i=0;i<gish.N;i++)
						if(Dist(&gish.medium(), &tmpEnemy->impact[k])<tmpEnemy->radius + 20)
						{
						gish.H -= minirand()*10;
						tmpEnemy->impact[k].H=0;
						tmpEnemy->impact[k].setPos(tmpEnemy->x,tmpEnemy->y );
				//		tmpEnemy->impact[i].setDxDy(0, 0);
						}

					if(weapon[BOMB].active && Dist(&weapon[BOMB],&tmpEnemy->impact[k])<weapon[BOMB].radius)
					{
						weapon[BOMB].health-= minirand()*3;
						tmpEnemy->impact[k].H=0;
						tmpEnemy->impact[k].setPos(tmpEnemy->x,tmpEnemy->y );
					}
				}
			}
		}



	  gish.Red = false;

	  if(gish.H < gish.oldH)
	  {

		  gish.color[0] = 1;		  
		  gish.color[1] = 0;		  
		  gish.color[2] = 0;		  
	  }
	  else
	  {
		  gish.color[0] = 1;		  
		  gish.color[1] = 1;		  
		  gish.color[2] = 1;
	  }

	  static float night_color = 0;
	  static bool rassvet = true;
	  if(night_color <= 0) rassvet = true;
	  if(night_color >= 1) rassvet = false;

	  if(rassvet) night_color+=0.0005;
	  else night_color-=0.0005;

	 // glClearColor(night_color*0.95,night_color,night_color,1);


   }//if


   
   
   /* if(glutGetModifiers() && GLUT_ACTIVE_SHIFT )
	{
			gish.SLOMO=true;
	}
	else 	gish.SLOMO=false;

*/
  /* 	int dtimer = 1000/100;

	if(gish.SLOMO)
		dtimer = 1000/10;
*/
	if (time_1 > 1000/100)  
	{
		starttime1 += time_1; 
		static float deltaOpen[4];
		static int napr=1;
		static int  TT = 0;
	   
		if(TT++>300) {TT=0; napr=-napr;}

		MEDGISH = gish.medium();
int k;

//		for(int k=0; k<10; k++)
	//			weapon[k].setPos(0, 0);

	  


	  if(curDescI >=0 && curDescI <100 && curDescJ >=0 && curDescJ <100) 
	  {
		  int k=0;

		  for(int i=curDescI; k<4; i++, k++ )
		  {
			  if(i>=0 && i<100)
				researched[i][curDescJ] = true;

			  if( dat[i][curDescJ] == '0' || dat[i][curDescJ] == 'W') {}
			   else 	  break;
		  }
		  k=0;

		  for( i=curDescI, k=0; k<4; i--, k++ )
		  {
			  if(i>=0 && i<100)
				researched[i][curDescJ] = true;

			  if( dat[i][curDescJ] == '0' || dat[i][curDescJ] == 'W') {}
			  else 	 	  break;
		  }

		
		  k=0;

		  for(int j=curDescJ; k<4; j++, k++ )
		  {
			  if(j>=0 && j<100)
				researched[curDescI][j] = true;

			  if( dat[curDescI][j] == '0' || dat[curDescI][j] == 'W') {}
			  else 	 	  break;
		  } 
		  k=0;


		  for( j=curDescJ; k<4; j--, k++ )
		  {
			  if(j>=0 && j<100)
				researched[curDescI][j] = true;

			  if( dat[curDescI][j] == '0' ||  dat[curDescI][j] == 'W') {}
			  else 	 	  break;
		  }
	
		  for( i=curDescI-1; i<curDescI+2; i++)
		  for(int j=curDescJ-1; j<curDescJ+2; j++)
		  {	 
			  
			  if( dat[i][j] != '0' )
				  break;
			  if(i>=0 && i<100 && j>=0 && j<100)
				researched[i][j] = true;

		
		  }




	  }
	
//	if(gish.LIP)
		for(int i=0;i<gish.N;i++)
			for( k=0;k<MAXWEAPONTYPES;k++)
 			if(k!=gish.currentWeapon && k!=BOMB
				&& weapon[gish.currentWeapon].y > weapon[k].y 
				&& Dist(&weapon[gish.currentWeapon],&weapon[k]) < weapon[k].radius*2.2 )
			{	
				weapon[gish.currentWeapon].setPos(gish.medium().x, gish.medium().y+70);
				gish.currentWeapon = k;
				i=gish.N;
				k=MAXWEAPONTYPES;
			}

			if(gish.currentWeapon!=BOMB )
				weapon[gish.currentWeapon].setPos(gish.medium().x, gish.medium().y);
	




	  for(  i=0;i<gish.N;i++)	
	  {
		  if(Dist(gish.bui[i], gish.bui[gish.soot(i)]) < 20  )
			  gish.H -= 1;

		 for(int k=0; key[k].corrected(); k++)
			 if(Dist(gish.bui[i], &key[k]) < key[k].radius*1.1 )
			 { key[k].setSpirit(true);
			//	key[k].setMassive(false);
			
			 }
		//	 else 
		//	 {	key[k].setSpirit(false);
		//		key[k].setMassive(true);
		//	 }



	  }

	 for( k=0; key[k].corrected(); k++)
	 {
		 if(key[k].spirit)
			 key[k].setPos(gish.bui[key[k].NUM]->x , gish.bui[key[k].NUM]->y);

	 }


		Collisions();

		int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
		for ( n = 0; n < ENEMY_ACTUAL_COUNT; n++)
		{
		  
		   	enemy[n_enemy_actual[n]].Controller();
			enemy[n_enemy_actual[n]].InvalidateView();
		   
		//	iter_enemy->Move();
		}
	   
		float dist = Dist(gish.medium(),ToPointF(crossX,crossY));
		float impactVectorX = ( crossX - gish.medium().x ) / dist;
		float impactVectorY = ( crossY - gish.medium().y ) / dist;

		weapon[gish.currentWeapon].setImpactVector(impactVectorX,impactVectorY);
	
	/*	if(weapon[gish.currentWeapon].fire)
		{	
			for(int i=0;i<gish.N ;i++)
			{//	gish.bui[i]->CalcVector();
				gish.bui[i]->setDxDy(0,0);
			//	gish.bui[i]->CalcDxDy();
				gish.bui[i]->Move();
			}

			for( i=0;i<gish.N ;i++)
			{

				gish.bui[i]->CalcVector();
				gish.bui[i]->FMove.addImpulse
					(-weapon[gish.currentWeapon].impactVectorX,
					-weapon[gish.currentWeapon].impactVectorY );
				gish.bui[i]->CalcDxDy();
				gish.bui[i]->Move();
			}
		}*/



				
			for(pBall=ball.begin(); pBall!=ball.end(); pBall++)
			{

		
				for (  int j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
				{	

					Enemy *tmpEnemy;  
					tmpEnemy = &enemy[n_enemy_actual[j]];
					if(Dist(pBall,tmpEnemy)<tmpEnemy->radius+pBall->radius)
					{
						tmpEnemy->health = 0;
					}
				}
			}

		
		  for( k=0; k<10; k++)
		  {		if(k==SUPER_WEAPON) 
				{
				 if(weapon[k].fire)	
					 for(int i=0;i<20;i++)
						 ball[i].setMassive(-1);
				 else 	 
					 for(int i=0;i<20;i++)
						 ball[i].setMassive(1);
				 }

		  if(weapon[k].fire)
		  {
			  

				if(k == GRENADE || k==BLASTER || k==ROCKET_LAUNCHER)
				{			
					int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
					for ( int j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
					{
						if(	enemy[n_enemy_actual[j]].health>0)	
						{
							Enemy *tmpEnemy;  
							tmpEnemy = &enemy[n_enemy_actual[j]];
						
							for( int i=0;i<10;i++)	
							{					
		
								if(weapon[k].impact[i].H > 0 )
								{
									if(Dist(&weapon[k].impact[i],tmpEnemy)<tmpEnemy->radius)
									{
										tmpEnemy->health -= 25;
										weapon[k].impact[i].H=0;
									}
								}

							//	for(int i=0;i<10;i++)
							//	if(Dist(ToPointF(gish.bui[i]->x,gish.bui[i]->y) ,
							//			ToPointF(tmpEnemy->impact[i].x,tmpEnemy->impact[i].y)
							//			)<gish.bui[i]->radius+35)
							//	{
							//		gish.H -= 0.1;
							//		tmpEnemy->impact[i].H=0;
							//		tmpEnemy->impact[i].setPos(100000000, 100000000);
							//		tmpEnemy->impact[i].setDxDy(0, 0);
							//	}

							}


						}
					}
				}
				else if(weapon[k].impact[0].H > 0)
				{


					for(int i=0; i<10; i++)
					{
						if(weapon[k].impact[i].x == 0)
							continue;

						PointF A = ToPointF(
							weapon[k].impact[0].x, 
							weapon[k].impact[0].y);

						PointF B = ToPointF(
							weapon[k].impact[i].x, 
							weapon[k].impact[i].y);


							int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
							float dist = 10000000000;
							int numnearEnemy = -1;
							for ( int j  = 0; j < ENEMY_ACTUAL_COUNT; j++)
							{
							//	if(enemy[n_enemy_actual[j]].health>0)
								{

									float curdist = Dist( (PointF)enemy[n_enemy_actual[j]], A) ;
								
									if(	 curdist < dist 
										&& CircleIntersects(
										&enemy[n_enemy_actual[j]].x, 
										&enemy[n_enemy_actual[j]].y, 
										enemy[n_enemy_actual[j]].radius, 
										Dist(A, B), A, B))					
										{	dist = curdist;
											numnearEnemy = n_enemy_actual[j];
										}
								}
							}

							if(numnearEnemy > -1)
							{
							
								enemy[numnearEnemy].health -= 3;

							//	enemy[numnearEnemy].CalcVector();
							//	enemy[numnearEnemy].setDxDy(0,0);
							//	enemy[numnearEnemy].CalcDxDy();
							//	enemy[numnearEnemy].Move();


								enemy[numnearEnemy].CalcVector();
							//	enemy[numnearEnemy].setDxDy(weapon[k].impactVectorX*0.3 ,weapon[k].impactVectorY*0.3);
								enemy[numnearEnemy].FMove.addImpulse(weapon[k].impactVectorX*0.7 ,weapon[k].impactVectorY*0.7  );
								enemy[numnearEnemy].CalcDxDy();
								enemy[numnearEnemy].Move();

									;
							//	weapon[k].impact[0].H = 0;
							}
					}


				}
			}
			 
		}





  }
  
 
  }catch(int){}
}



bool levelFreeSpace(char c)
{
	return (c=='0' || c=='W');
}


void CreateLines(char *path)
{





			ball.clear();

			NUM_TR = 0;
			FILE *fp;
						
		/*	prim[num].set(ToPointF(-limitX/2,0),		 ToPointF(limitX+limitX/2,0),ToPointF(limitX/2,-4000), 120,num++);
			prim[num].set(ToPointF(0,limitY),		 ToPointF(0,-limitY/2),		 ToPointF(-4000,limitY/2), 120,num++);
			prim[num].set(ToPointF(limitX,-limitY/2), ToPointF(limitX,limitY),	 ToPointF(limitX+4000,limitY/2), 120,num++);
		*/


			colorGeo[0] = minirand();
			colorGeo[1] = minirand();
			colorGeo[2] = minirand();

			colorWalk[0] = 1-minirand()*0.5;
			colorWalk[1] = 1-minirand()*0.5;
			colorWalk[2] = 1-minirand()*0.5;	

			for(int n=0;n<100;n++)
				for(int m=0;m<100; m++)
				{
					lightColor[n][m][0] = 1-minirand()*0.5;
					lightColor[n][m][1] = 1-minirand()*0.5;
					lightColor[n][m][2] = 1-minirand()*0.5;

					researched[n][m] = false;

				}


			for(int i=0;i<10;i++)
				weapon[i].set(i);


			for( i=0; i< enemyCount; i++)
			{
				enemy[i].correct=false;
				enemy[i].setPos(4000000,4000000);

			}
		//	int NUMPRIMS = prim.size();
				for( n = 0;  n<MAXPRIMCOUNT; 	n++)
				{   
					prim[n].type = 0;
	     			prim[n].A.x = 3000000;
					prim[n].B.x = 1000000;
					prim[n].C.x = 2000000;
	     			prim[n].A.y = 3000000;
	     			prim[n].B.y = 4000000;
	     			prim[n].C.y = 5000000;

	     			prim[n].line[0].a.x = 10000000;
	     			prim[n].line[0].a.y = 20000000;
	     			prim[n].line[0].b.x = 10000000;
	     			prim[n].line[0].b.y = 20000000;

	     			prim[n].line[1].a.x = 10000000;
	     			prim[n].line[1].a.y = 20000000;
	     			prim[n].line[1].b.x = 10000000;
	     			prim[n].line[1].b.y = 20000000;


	     			prim[n].line[2].a.x = 10000000;
	     			prim[n].line[2].a.y = 20000000;
	     			prim[n].line[2].b.x = 10000000;
	     			prim[n].line[2].b.y = 20000000;			
					
					prim[n].typeOfImpact = GOOD;
				 }

 

				int minLevelI = 100;
				int minLevelJ = 100;
				int maxLevelI = 0;
				int maxLevelJ = 0;

			if(path[0]!=0)
			{
				cout << path[0];

				fp=fopen(path,"r");
			

		//	return;


			int j;	
			for( j=0; j<100; j++)
					for(int i=0; i<100; i++)
						dat[i][j] = '1';

			for( j=0; j<100; j++)
					for(int i=0; i<100; i++)
						dat[i][j] = '0';


				for( j=0; j<100; j++)
				{	for(int i=0; i<100; i++)
					{
						dat[i][j] =  getc(fp);
					}
					getc(fp);
				}

					

				int counter = 0;
				int num = 0;
				float redcol=0.75,greencol=0.75,bluecol=0.75;

				int ienem=0;
				int icheck = 0;

				 enemyCount = 0;
				 doorCount = 0;
				 keyCount = 0;
				 itemCount = 0;
				
				for( j=0; j<100; j++)
				{


					for(int i=0; i<100; i++)
					{
					//	if((counter++)>1000)
					//	{counter = 0;
					//	redcol=1-minirand()*0.7;
					//	greencol=1-minirand()*0.7;
					//	bluecol=1-minirand()*0.7;
					//	}

						int I = i;
						int J = j;
					
						char c = '0';
						c= dat[i][j];

						PointF A = ToPointF(I*SIZE1,		 limitY - J*SIZE2);
						PointF B = ToPointF(I*SIZE1,		  limitY - J*SIZE2+SIZE2); 	
						PointF C = ToPointF(I*SIZE1 + SIZE1, limitY - J*SIZE2+SIZE2);
						PointF D = ToPointF(I*SIZE1 + SIZE1, limitY - J*SIZE2);
						
						PointF E;
						E.x = (A.x + D.x) / 2; 
						E.y = A.y-SIZE2/2;
			 
						PointF A0 = ToPointF(I*SIZE1,		 limitY - J*SIZE2);
						PointF B0 = ToPointF(I*SIZE1,		  limitY - J*SIZE2+SIZE2); 	
						PointF C0 = ToPointF(I*SIZE1 + SIZE1, limitY - J*SIZE2+SIZE2);
						PointF D0 = ToPointF(I*SIZE1 + SIZE1, limitY - J*SIZE2); 


						if(c!='0')
						{
							if(I > maxLevelI) maxLevelI = I;
							if(J > maxLevelJ) maxLevelJ = J;

							if(I < minLevelI) minLevelI = I;
							if(J < minLevelJ) minLevelJ = J;

						}

						if(c == '1' || c == 'I'  || c == 's' || c== 'F')
						{
							
							desc[i][j].num1 = num;
							desc[i][j].num2 = num+1;

 							if(c=='1')
							{
								prim[num].set(GEO, A	,B	,C,WIDTH,true,num);
								num++;
								prim[num].set(GEO,C	,D	,A,WIDTH,true,num);	
								num++;
							}
							else  	if(c=='I')
							{
								prim[num].set(ICE, A	,B	,C,WIDTH,true,num); 
								num++;
								prim[num].set(ICE,C	,D	,A,WIDTH,true,num);
								num++;
							}
							else  	if(c=='s')
							{
								prim[num].set(SAND, A	,B	,C,WIDTH,true,num);
								num++;
								prim[num].set(SAND, C	,D	,A,WIDTH,true,num);
								num++;
							}
							else  	if(c=='F')
							{
							//	forbombPoint = A;

								prim[num].set(FORBOMB, A	,B	,C,WIDTH,true,num);

								forbombPoint.x =	(prim[num].B.x + prim[num].C.x)/2;
								forbombPoint.y =	(prim[num].B.y + prim[num].C.y)/2;
								num++;
								prim[num].set(FORBOMB, C	,D	,A,WIDTH,true,num);
								num++;
							}


							prim[num-2].setColor(redcol,greencol,bluecol,1,1); 
							prim[num-1].setColor(redcol,greencol,bluecol,1,1);


							if(dat[i-1][j]==c && dat[i][j-1]==c &&
							   dat[i+1][j]==c && dat[i][j+1]==c &&
							   i>=0 && i<100 && j>=0 && j<100	)
							{
								prim[num-1].isDepth = true;
								prim[num-2].isDepth = true;
							}

						}

						if(c == 'W')
						{
							desc[i][j].num1 = num;
							desc[i][j].num2 = num+1;

							prim[num].set(HYDRO, A0	,B0	,C0,WIDTH,true, num);
							prim[num].setColor(0,0.7,0.6,.4); 
							num++;
							prim[num].set(HYDRO, C0	,D0	,A0,WIDTH,true, num);
							prim[num].setColor(0,0.7,0.6,.4);
							num++;

						//	prim[num-2].uppest = (dat[i][j-1]==' ' || dat[i][j-1]=='0');
							prim[num-2].uppest = dat[i][j-1]!='W';

						}

						if(c == 'L')
						{	desc[i][j].num1 = num;

							desc[i][j].num2 = num+1;
							prim[num].set(HYDRO,A0	,B0	,C0,WIDTH,true,num);
							prim[num].typeOfImpact = EVIL;
							prim[num].setColor(1,0,0,.5); 
							num++;
							prim[num].set(HYDRO,C0	,D0	,A0,WIDTH,true,num);
							prim[num].typeOfImpact = EVIL;
							prim[num].setColor(1,0,0,.5);
							num++;
							
							
							prim[num-2].uppest = (dat[i][j-1]!='L');
						//	prim[num].uppest = dat[i][j-1]!='W';
						}

					/*	if(c == 'X')
						{
							thpick.push_back(ThornPrickle(A	,B	,C,WIDTH,true,num++);		
							thpick.push_back(ThornPrickle(C	,D	,A,WIDTH,true,num++);		
							(thpick.end()-2)->setColor(0,0,0,.5,1); 
							(thpick.end()-1)->setColor(0,0,0,.5,1);
						}*/


						if(c == '2')
						{	desc[i][j].num1 = num;
							
							prim[num].set(GEO,A	,B	,C,WIDTH,false,num);
							prim[num].setColor(redcol,greencol,bluecol,1,true); 
							num++;

							if(i<100 && dat[i+1][j]=='W') 
							{		
								prim[num].set(HYDRO, C0	,D0	,A0,WIDTH,false, num);
								prim[num].setColor(0,0.7,0.7,.4);
								desc[i][j].num2 = num;	
								num++;
							}

						}


						if(c == '3')
						{	desc[i][j].num1 = num;
							prim[num].set(GEO, A	,B	,D,WIDTH,false,num);
							prim[num].setColor(redcol,greencol,bluecol,1,true); 
							num++;
							if(i<100 && dat[i+1][j]=='W') 
							{		
								prim[num].set(HYDRO,D0	,B0	,C0,WIDTH,false,num);		
								prim[num].setColor(0,0.7,0.7,.4);
								desc[i][j].num2 = num;
								num++;
							}
						}



						if(c == '4')
						{		
							if(i>0 && dat[i-1][j]=='W') 
							{
								desc[i][j].num1 = num;
								prim[num].set(HYDRO,A	,B	,D,WIDTH,false,num);		 
								prim[num].setColor(0,0.7,0.7,.4);
								num++;
							} 
						
							prim[num].set(GEO, D,  B , C,WIDTH,false,num++);
							prim[num].setColor(redcol,greencol,bluecol,1,true);
							desc[i][j].num2 = num;
							num++;


						
						}

						if(c == '5')
						{
						
						
							prim[num].set(GEO,C	,D	,A,WIDTH,false,num);
							prim[num].setColor(redcol,greencol,bluecol,1,true);	
							desc[i][j].num1 = num;
							num++;

							if(i>0 && dat[i-1][j]=='W') 
							{
								prim[num].set(HYDRO,A0	,B0	,C0,WIDTH,false,num);		 
								prim[num].setColor(0,0.7,0.7,.4);
								desc[i][j].num2 = num;
								num++;
							}

						}

				
						if(c == '6')
						{	desc[i][j].num1 = num;
							
							prim[num].set(ICE,A	,B	,C,WIDTH,false,num);
							prim[num].setColor(redcol,greencol,bluecol,1,true); 
							num++;

							if(i<100 && dat[i+1][j]=='W') 
							{		
								prim[num].set(HYDRO, C0	,D0	,A0,WIDTH,false, num);
								prim[num].setColor(0,0.7,0.7,.4);
								desc[i][j].num2 = num;	
								num++;
							}

						}


						if(c == '7')
						{	desc[i][j].num1 = num;
							prim[num].set(ICE, A	,B	,D,WIDTH,false,num);
							prim[num].setColor(redcol,greencol,bluecol,1,true); 
							num++;
							if(i<100 && dat[i+1][j]=='W') 
							{		
								prim[num].set(HYDRO,D0	,B0	,C0,WIDTH,false,num);		
								prim[num].setColor(0,0.7,0.7,.4);
								desc[i][j].num2 = num;
								num++;
							}
						}



						if(c == '8')
						{		
							if(i>0 && dat[i-1][j]=='W') 
							{
								desc[i][j].num1 = num;
								prim[num].set(HYDRO,A	,B	,D,WIDTH,false,num);		 
								prim[num].setColor(0,0.7,0.7,.4);
								num++;
							} 
						
							prim[num].set(ICE, D,  B , C,WIDTH,false,num++);
							prim[num].setColor(redcol,greencol,bluecol,1,true);
							desc[i][j].num2 = num;
							num++;


						
						}

						if(c == '9')
						{
						
						
							prim[num].set(ICE,C	,D	,A,WIDTH,false,num);
							prim[num].setColor(redcol,greencol,bluecol,1,true);	
							desc[i][j].num1 = num;
							num++;

							if(i>0 && dat[i-1][j]=='W') 
							{
								prim[num].set(HYDRO,A0	,B0	,C0,WIDTH,false,num);		 
								prim[num].setColor(0,0.7,0.7,.4);
								desc[i][j].num2 = num;
								num++;
							}

						}

						if(c == 'R')	{	door[doorCount].set(GEO,E, B, C,WIDTH,false,RED); doorCount++;}
						if(c == 'G')	{	door[doorCount] .set(GEO,E, B, C,WIDTH,false,GREEN);doorCount++;}
						if(c == 'B')	{	door[doorCount].set(GEO,E, B, C,WIDTH,false,BLUE); doorCount++;}
						if(c == 'Y')	{	door[doorCount].set(GEO,E, B, C,WIDTH,false,YELLOW);doorCount++;}

						if(c == 'r')	{	key[keyCount].set(RED,I*SIZE1+75,limitY - J*SIZE2+75);keyCount++;}
						if(c == 'g')	{	key[keyCount]. set(GREEN,I*SIZE1+75,limitY - J*SIZE2+75);keyCount++;}
						if(c == 'b')	{	key[keyCount].set(BLUE,I*SIZE1+75,limitY - J*SIZE2+75);keyCount++;}
						if(c == 'y')	{	key[keyCount].set(YELLOW,I*SIZE1+75,limitY - J*SIZE2+75);keyCount++;}
		
						if(c == 'S')
						{
							startLevel.x = I*SIZE1+75;
							startLevel.y = limitY - J*SIZE2+75;
								respawnPoint = startLevel;
							gish.SetPos(I*SIZE1+75,limitY - J*SIZE2+75);

							item[itemCount].setPos(I*SIZE1+60, limitY - J*SIZE2+60);
							item[itemCount].setType(HEALTH);
							itemCount++;
						}
				
	

						if(c == 't' )
						{
							int enT = TURRET;
							enemy[ienem++].set(enT,I*SIZE1+SIZE1/2, limitY - J*SIZE2+SIZE2/2);enemyCount++;

						//	int count = rand()%5;
						//	if(enT != TURRET)
						//		for(int cn=0; cn<count; cn++)	
						//			enemy[ienem++].set(enT,I*SIZE1+SIZE1/2, limitY - J*SIZE2+SIZE2/2);

						}

						if (c == '@') 
						{
							weapon[BOMB].set(BOMB);
							weapon[BOMB].setPos(I*SIZE1+SIZE1/2, limitY - J*SIZE2+SIZE2/2);
						}


						if (c == '!') 
						{
							weapon[DETONATOR].set(DETONATOR);
							weapon[DETONATOR].setPos(I*SIZE1+SIZE1/2, limitY - J*SIZE2+SIZE2/2);
						}

						if(c == 'e' )
						{
							int enT = rand()%_MAX_ENEMY_TYPE_;
							enemy[ienem++].set(enT,I*SIZE1+SIZE1/2, limitY - J*SIZE2+SIZE2/2);enemyCount++;
		
						}

					
						
						if(c == 'E')
						{	exitLevel.x = I*SIZE1+60;
							exitLevel.y = limitY - J*SIZE2+60;
						}


					}
				
				//	getc(fp);
				}
				fclose(fp);
				fp = NULL;
			}

			else
			{
				int	num=0;

				for(int i=0;i<50;i++)
				{		int x1= rand () %(int)limitX;
						int x2= x1+100+rand()%1000;
						int y1 = rand () %(int)limitY;
						int y2 = y1+100+rand ()%1000;

						prim[num].set(GEO, ToPointF(MIN(x1,x2),limitY-y1),
														 ToPointF(MAX(x1,x2),limitY-y1+rand()%150-75),
														 ToPointF((x1+x2)/2+rand()%700-350,limitY-y2),
														 120,false,num++);
						prim[num].setColor(minirand(),
												 minirand(),
												 minirand(),1,true); 

						
				}
			}




		//	MMM:

		//			CreateLevel();

/*
	PISTOL			1
	GUN				2
	AUTOMAT			3
	GRENADE			4
	MACHINE_GUN		5
	BLASTER			6
	ROCKET_LAUNCHER 7
	SUPER_WEAPON	8
*/


//	weapon[LAMP].setPos(gish.medium().x-150, gish.medium().y+100);



///	for( i=0; door[i].corrected(); i++)
//		cout<<i<<endl;


			

	
	for( i=0;i<MAXWEAPONTYPES-1;i++)
	{
		if(i!=BOMB)
			if(i!=DETONATOR)
				weapon[i].setPos(
					interrRand(minLevelI,maxLevelI)*SIZE1+60, 
					(100-interrRand(minLevelJ,maxLevelJ))*SIZE2+60);
	}



/*
	if(levelFreeSpace(c) 
							&&  dat[i][j+1] !='0'
							&&  ( dat[i][j-1] !='0' || dat[i][j-2] !='0')

				a		//	&& ( !levelFreeSpace(dat[i][j-1]) || !levelFreeSpace(dat[i][j-2]) )
							)*/

					
					{
							
						
							for(int  icheck=0;icheck<CHECKPOINT_COUNT;icheck++)
							{
								checkPoint[icheck].setPos(
									interrRand(minLevelI,maxLevelI+10)*SIZE1+60, 
										(100-interrRand(minLevelJ,maxLevelJ+10))*SIZE2+60);
							}
					
						
							for( itemCount=0;itemCount<MAXITEMS;itemCount++)
							{

								item[itemCount].setPos(
									interrRand(minLevelI,maxLevelI+10)*SIZE1+60, 
										(100-interrRand(minLevelJ,maxLevelJ+10))*SIZE2+60);

								item[itemCount].setType(HEALTH);
						
							}

						}




 for(int g=0;g<20;g++)
 {
	 ball.push_back(Building(weapon[SUPER_WEAPON].x+g,weapon[SUPER_WEAPON].y+10,10,g));

	 ball[g].setInertion(0.99);
 	  
	//  if(g<12)ball[g].setMassive(-1);
	//  else 
		  ball[g].setMassive(0);

		ball[g].setFriction(false);

	  ball[g].cred = 0.1;
	  ball[g].cgreen = 0;
	  ball[g].cblue = 0;

	
 }
 ball[19].setMassive(1);



playing = true;
}



void myInit()
{
	srand ((unsigned)time(NULL));

	CreateLines((char*)levelManager.nextLevel("mapscript.dat").c_str());

	scene.font.CreateOpenGLFont("Verdana",12);
	scene.fontBig.CreateOpenGLFont("Verdana",30);


	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluPerspective(viewAngle,    (float)winW / (float)(winH),   5,  ZFAR);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	glBlendFunc	(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);   
	glEnable(GL_BLEND);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);	
	glEnable(GL_SCISSOR_TEST);
	ShowCursor(false);
	
}


void myReshape(int width, int height)
{
//	 glViewport(0, 0, width, height);
}




bool console_mode=false;




void myKeyboardDown(unsigned char key, int x, int y)
{	
	static int n=0;
	if(key == 27)	
	{
		glDeleteLists(888,1);
		exit(0);

	}
	
	if(!console_mode)
	{


		if(key == 'a' || key == 'ф')	moveLEFT_2 = true;
		if(key == 'd' || key == 'в')	moveRIGHT_2 = true;
		if(key == 'w' || key == 'ц')	moveUP_2 = true;
		if(key == 's' || key == 'ы')	moveDOWN_2= true;


		if(key ==  'r' || key ==  'к' ) 
		{
			cameraHeroOrientation = false;
		/*	for(int i=0;i <enemyCount;i++)
			{	enemy[i].setSpirit(true);
				enemy[i].setType(FLY);
			}*/

		}

		if(key ==  'p' || key ==  'з' ) 
		{
			pauseMode = !pauseMode;
		}


		if(weapon[BOMB].active) {
			if(key ==  'q' || key ==  'й' ) {

				if((gish.H - 10)>0) 
				{ gish.H -= 10;
				  weapon[BOMB].health +=10;				
				}

			}

			if(key ==  'e' || key ==  'у' )	{

				if((weapon[BOMB].health - 10)>0) 
				{ weapon[BOMB].health -= 10;
				  gish.H +=10;				
				}

			}
			
		}	
			
			//SLOMO_K = 5;


/*		if(key == 'l')
		{

			static bool day = true;
			day = !day;
				
			if(day)
			{	setDay();
			}
			else
			{
//				setNight();
			}


		}*/


	//	if(key >= 48 && key <=57) 
	//		gish.currentWeapon = key - 48;


		if(key ==  32)	jump = true;


	/*	if(key ==  'l' || key ==  'z')	gish.LIP = true;
		if(key ==  'k')	gish.SKOL = true;
		if(key ==  'x')	gish.TVER = true;
		if(key ==  'h')	gish.FIRE = true;
*/


		if( key == 'm' )
		{	/*glMatrixMode(GL_PROJECTION);	
			glLoadIdentity();
			glOrtho(-winW*7, winW*7, -winH*7, winH*7,1,ZFAR);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			
			DEBUG_MODE=true;*/
		//	ORTHO = true;

			isMap = !isMap;

		
		}
	/*	else if(key ==  'p' || key == 'm')
		{	glMatrixMode(GL_PROJECTION);	
			glLoadIdentity();
			gluPerspective(viewAngle,    (float)winW / (float)winH,   5,  ZFAR);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			 DISTANCETOSCENE = 1400;
		//	DEBUG_MODE=false;
		
		}
*/
		if(key == 'y') SH1 = !SH1;



	}
	else
	{
		if(key==13)
				{command[n] = '\0';n=0; 
				 
				 if(strstr(command,"maps"))
				 {
					CreateLines(command);
					levelManager.numCurrentLevel--;
				 }

				 if(strstr(command,"noclip"))
				 {
						noclipMode = !noclipMode;
				 }

				 console_mode = false;
				}
		else if (key==8)
		{
			
			if(n>0) n--;
			for(int i=n;i<100;i++ )
				command[i] = '\0';
		}
		else	
		{
			command[n] = key;
			n++;
		}

	}

	if(key == '`')
	{console_mode = !console_mode;
	 n=0;
	 for(int i=0;i<strlen(command);i++)
		 command[i]=0;

	}

}


void MyMouseFunc()
{

	POINT p;
	GetCursorPos( &p );						
	SetCursorPos( winW >> 1, winH >> 1 );
	ZROT -= (((winH >> 1)  - p.y )*0.3);

	YROT += (((winW >> 1)  - p.x )*0.3);

	if(ZROT > 360) ZROT = 0;
	if(ZROT < 0)   ZROT = 360;

	if(YROT > 360) YROT = 0;
	if(YROT < 0)   YROT = 360;


}

void MouseButton(int key,int state,int x,int y)
{ 
	
	if(key==GLUT_LEFT_BUTTON)
	{
	 if(state==GLUT_DOWN)	 
	 {
		weapon[gish.currentWeapon].startFire();
	 }
	 if(state==GLUT_UP)		
	 {	
		weapon[gish.currentWeapon].endFire();
	 }

	}	

	if(key==GLUT_RIGHT_BUTTON)
	{
	 if(state==GLUT_UP)		
	 {gish.LIP = false;
	 }
	 if(state==GLUT_DOWN)	 
	 {gish.LIP = true;
	 }
	}
	
	if(key==GLUT_MIDDLE_BUTTON)
	{
	 if(state==GLUT_UP)		
	 {gish.TVER = false;
	 }
	 if(state==GLUT_DOWN)	 
	 {gish.TVER = true;
	 }
	}

}

void myKeyboardUp(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
	if(!console_mode)
	{
		if(key == 'a' || key == 'ф')	moveLEFT_2 = false;
		if(key == 'd' || key == 'в')	moveRIGHT_2 = false;
		if(key == 'w' || key == 'ц')	moveUP_2 = false;
		if(key == 's' || key == 'ы')	moveDOWN_2= false;

		if(key ==  'l' || key ==  'z')	gish.LIP = false;
		if(key ==  'k')	gish.SKOL = false;
		if(key ==  'x')	gish.TVER = false;
		if(key ==  'h')	gish.FIRE = false;

	//	if(key ==  'e' || key ==  'у' )	SLOMO_K = 1;

		if(key ==  'r' || key ==  'к' ) cameraHeroOrientation = true; 



	if(key ==  32)	jump = false;
	}
}

void mySpecUp( int key,int x, int y)
{
	if(key == GLUT_KEY_LEFT)	moveLEFT = false;
	if(key == GLUT_KEY_RIGHT)	moveRIGHT = false;
	if(key == GLUT_KEY_UP)		moveUP = false;
	if(key == GLUT_KEY_DOWN)	moveDOWN= false;

	
}


void mySpecDown(int key,  int x, int y)
{
	if(key == GLUT_KEY_LEFT)	moveLEFT = true;
	if(key == GLUT_KEY_RIGHT)	moveRIGHT = true;
	if(key == GLUT_KEY_UP)		moveUP = true;
	if(key == GLUT_KEY_DOWN)	moveDOWN= true;


}


void myDisplay();

void timer(int value)
{
   if (value == 1)
   { 
		MessageBox(NULL,"sdfsd","sesdef",0);
		//glutTimerFunc(3000, timer, 1);
   }
   
   
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

//	glutGameModeString("1024x768:32"); 


	int screenW = winW = glutGet(GLUT_SCREEN_WIDTH);//GetSystemMetrics(SM_CXSCREEN);
	int screenH = winH = glutGet(GLUT_SCREEN_HEIGHT);//GetSystemMetrics(SM_CYSCREEN);

 //   winW -= 8;
  //  winH -= 100;	
	
	if(argc == 1)
		glutEnterGameMode();
	else {

		glutInitWindowSize(winW, winH);	
		glutInitWindowPosition(screenW/2-winW/2, 0);
		glutCreateWindow("Game.  Demo from Useinov Evgeni");
	}


//	glutEnterGameMode();//////////////////////////

//	glutFullScreen();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(myKeyboardDown);
	glutKeyboardUpFunc(myKeyboardUp);

	glutSpecialFunc(mySpecDown);
	glutSpecialUpFunc(mySpecUp);
	glutMouseFunc			(MouseButton);	myInit();
//	glutTimerFunc(3000, timer, 1);
	glutIdleFunc(myIdle);




	//if(minirand()>0.5)setDay();
	//else 
//		setNight();

	spisok();
	


	HKL   hKbLayout = NULL;
     
	char szName[9];
    DWORD dwLangID = MAKELANGID( LANG_ENGLISH,
                                 SUBLANG_ENGLISH_US );
                                wsprintf( szName, "%8.8X", dwLangID );
    hKbLayout = LoadKeyboardLayout( szName, KLF_REPLACELANG );
	
	
	glutMainLoop();	

	if ( hKbLayout )
    {
     ActivateKeyboardLayout( (HKL)HKL_NEXT, 0 );
     UnloadKeyboardLayout( hKbLayout );
    }

	getch();

	return 0;
}



float t=0;


static float a = 0;


void ShowUnits()
{

		ShowGish(&gish);
	
		for(int i=0;i<MAXWEAPONTYPES;i++)
		{
			if(underCameraUnit (weapon[i],  camera,12) && researchedUnit(weapon[i]))
				ShowWeaponWithImpacts(&weapon[i]);
		}

		if(researchedUnit(exitLevel))
			ShowExit(&exitLevel);

		for(int n=0;n<CHECKPOINT_COUNT; n++)
		{
			if(underCameraUnit (checkPoint[n],  camera,12) && researchedUnit(checkPoint[n]))
				ShowCheckPoint(&checkPoint[n]);
		}

		for( n=0;n<itemCount; n++)
		{
			if(underCameraUnit (item[n],  camera,12) && researchedUnit(item[n]))
				ShowItem(&item[n]);
		}

		
			
			int ENEMY_ACTUAL_COUNT = n_enemy_actual.size();
			for ( n = 0; n < ENEMY_ACTUAL_COUNT; n++)
			{ //  if(	enemy[n_enemy_actual[n]].health>0)
				
				pum
				if(underCameraUnit (enemy[n_enemy_actual[n]],  camera,12) && researchedUnit(enemy[n_enemy_actual[n]]))
						ShowEnemy(&enemy[n_enemy_actual[n]]);
				pom

				ShowEnemyImpacts(&enemy[n_enemy_actual[n]]);
			}
		
			pum
			for ( i = 0; i<keyCount; i++)
			{  
				ShowKey(&key[i]);
			}
			pom	
}



void displayByCamera(PointF cameraPos, int interval, int area)
{

	glLoadIdentity (); 

	pum;

	YROT = -MousePosX(winW)*0.08;
	XROT = MousePosY(winH)*0.1;



	glTranslatef(0,0 ,-(DISTANCETOSCENE - (DISTANCETOSCENE/3)));
		if(interval==0){
			glRotatef(-XROT+5,1,0,0);	
			glRotatef(-YROT,0,1,0);	
		}
	glTranslatef(0,0 ,-(DISTANCETOSCENE/3));
	

	if(isMap)
			glScalef(0.3,0.3,0.3);




	camera = cameraPos;

	glTranslatef(-cameraPos.x ,-cameraPos.y ,0);




	for(int nl=0; nl<8;nl ++)
		glDisable(GL_LIGHT0+nl);

//	loff 

	int lightNumber = 1;
 
/*	setLocalLight(lightNumber, 	gish.medium().x, gish.medium().y ,0*150,
		1,weapon[BOMB].health/100,weapon[BOMB].health/100,
		0.000001 );
	
	lightNumber++;*/


	 if(prim[desc[curDescI][curDescJ].num2].type == HYDRO  )
	 {//	ShowWeaponWithImpacts(&weapon[LAMP]);
		setLocalLight(lightNumber, gish.medium().x,gish.medium().y,180,		1,1,1, 0.0001);
		lightNumber++;  
	 }



	if(weapon[BOMB].active)
	{	setLocalLight(lightNumber, 	weapon[BOMB].x, weapon[BOMB].y ,0,
		1,weapon[BOMB].health/100,weapon[BOMB].health/100,
		0.00000000001 );
		lightNumber++;
	}
	
	if(weapon[DETONATOR].active)
	{	setLocalLight(lightNumber, 	weapon[DETONATOR].x, weapon[DETONATOR].y ,0,
		1,0,1,
		0.00001 );
		lightNumber++;
	}
	
	int inerv = 25;
	
//	if(prim[desc[curDescI][curDescJ].num2].type == HYDRO  )inerv=10;

	if(!weapon[BOMB].active)
	  for(int n = curDescI-inerv; n<=curDescI+inerv; n++)
	  for(int m = curDescJ-inerv; m<=curDescJ+inerv; m++)
	  {
			  
		//	if(n > 0 && m > 0 && n < 100 && m < 100 ) {}
		//	else continue;
			
			  
			    if(lightNumber<7)
				{
					 

					
						if(((n%inerv) == 0 && (m%inerv) == 0 ) )
						{	
						
			
							setLocalLight(lightNumber, n*SIZE1,(100-m)*SIZE2,200,
												lightColor[n][m][0],lightColor[n][m][1],lightColor[n][m][2], 0.000001);
						

							 pum
								glTranslatef(n*SIZE1,(100-m)*SIZE2,10);loff	
							 glColor3f(1,1,1
								// (lightColor[n][m][0]*0.5 + 0.5),
								// (lightColor[n][m][1]*0.5 + 0.5), 
								// (lightColor[n][m][2]*0.5 + 0.5)
									);
								glutSolidSphere(10,8,8);lon
							 pom
								 
							lightNumber++;
						
					
						}

					
		

				}	else break;

			  
		  }
	lon

	if(playing)
	{
		
		int n;


			crossX = gish.medium().x + MousePosX(winW)/2;
			crossY = gish.medium().y + MousePosY(winH)/2;
			pum
				loff
				doff
				glColor3f(0,0,0);
			
			//	glLineWidth(5);
				glTranslatef(crossX,crossY,10);

				glLineWidth(1);
				glutWireCube(20);
				don
				lon
			pom

		
			::ShowImpactLine(&gish);

			
				
			
			int iii,jjj;
			GetQuadCoord(&iii,&jjj,cameraPos);



			pum	
				glBegin(GL_TRIANGLES);
				for (int i = 0; i<doorCount; i++)
				{  
					if(researchedUnit(door[i].A))
					ShowDoor(&door[i]);	
				
				}
				glEnd();
			pom

			

	
			ShowUnits();
			if(interval == 0)
			{
			pum
				glTranslatef(0,0,-prim[0].Width*2);
			//	glScalef(1,1,-1);
				ShowUnits();
			pom
			}



			pum


				glBegin(GL_TRIANGLES);
		

				 for ( n = iii-area; n<=iii+area; n++)
				  for(int m = jjj-area; m<=jjj+area; m++)
				  {  
					  
					  if(n >=0 && m>=0 && n<100 && m<100)
					  {
						 if(prim[desc[n][m].num1].type == GEO)
							ShowPrimitive(&prim[desc[n][m].num1]);
						 if(prim[desc[n][m].num2].type == GEO)
							ShowPrimitive(&prim[desc[n][m].num2]);	
					  }

				  }



				 for ( n = iii-area; n<=iii+area; n++)
				  for(int m = jjj-area; m<=jjj+area; m++)
				  {  
					  if(n >=0 && m>=0 && n<100 && m<100)
					  {
						  if(prim[desc[n][m].num1].type != GEO && prim[desc[n][m].num1].typeOfImpact == EVIL)
							ShowPrimitive(&prim[desc[n][m].num1]);
						 if(prim[desc[n][m].num2].type != GEO && prim[desc[n][m].num2].typeOfImpact == EVIL)
							ShowPrimitive(&prim[desc[n][m].num2]);	
					  }

				  }


				 for ( n = iii-area; n<=iii+area; n++)
				  for(int m = jjj-area; m<=jjj+area; m++)
				  {  
					  if(n >=0 && m>=0 && n<100 && m<100)
					  {  if( prim[desc[n][m].num1].type == FORBOMB) continue;
						  if(prim[desc[n][m].num1].type != GEO && prim[desc[n][m].num1].typeOfImpact == GOOD)
							ShowPrimitive(&prim[desc[n][m].num1]);
						 if(prim[desc[n][m].num2].type != GEO && prim[desc[n][m].num2].typeOfImpact == GOOD)
							ShowPrimitive(&prim[desc[n][m].num2]);	
					  }

				  }			

				glEnd();
				
				blon
			 glBegin(GL_TRIANGLES);
			
		 		glColor4f(.2,.2,.2,0.7);
			//	glColor3f(.5, 1,.5);
				int z = - prim[0].Width;
				 for ( n = iii-area; n<=iii+area; n++)
				  for(int m = jjj-area; m<=jjj+area; m++)
				  {  
				//	  if(n >=0 && m>=0 && n<100 && m<100)
					  {
					//	  if(prim[desc[n][m].num1].type != HYDRO)
						
					//	  if(!researched[n][m]) 

						  {
					
								
							  PointF a = ToPointF(n*SIZE1,(100-m)*SIZE2);
							  PointF b = ToPointF(n*SIZE1+SIZE1,(100-m)*SIZE2);
							  PointF c = ToPointF(n*SIZE1,(100-m)*SIZE2+SIZE2); 
							  PointF d = ToPointF(n*SIZE1+SIZE1,(100-m)*SIZE2+SIZE2);  
						
						
							tr2(a.x,a.y, z,   
								b.x,b.y, z,		 
								c.x,c.y, z);

							tr2(b.x,b.y, z,
								d.x,d.y, z,   	 
								c.x,c.y, z);

							float bmx = 	(a.x + d.x)*0.5;
							float bmy = 	(a.y + d.y)*0.5;

				
							tr2(b.x,b.y,z,  
								bmx,bmy,z+10,  
								a.x,a.y,z);

							tr2(
								c.x,c.y,z,
								bmx,bmy,z+10,  
								d.x,d.y,z);


						  }

					  }

				  }
				  
				  bloff
				glEnd();



				  loff
					 blon
				glBegin(GL_TRIANGLES);
			
				
		 		 glColor4f(1,1,1,0.1);

				 z =  prim[0].Width+1;
				 for ( n = iii-area; n<=iii+area; n++)
				  for(int m = jjj-area; m<=jjj+area; m++)
				  {  
				//	  if(n >=0 && m>=0 && n<100 && m<100)
					  {
					//	  if(prim[desc[n][m].num1].type != HYDRO)
						
						  if(!researched[n][m]) 

						  {
					
								
							  PointF a = ToPointF(n*SIZE1,(100-m)*SIZE2);
							  PointF b = ToPointF(n*SIZE1+SIZE1,(100-m)*SIZE2);
							  PointF c = ToPointF(n*SIZE1,(100-m)*SIZE2+SIZE2); 
							  PointF d = ToPointF(n*SIZE1+SIZE1,(100-m)*SIZE2+SIZE2);  
						
						
							tr2(a.x,a.y, z,   
								b.x,b.y, z,		 
								c.x,c.y, z);

							tr2(b.x,b.y, z,
								d.x,d.y, z,   	 
								c.x,c.y, z);

						/*	float bmx = 	(a.x + d.x)*0.5;
							float bmy = 	(a.y + d.y)*0.5;

				
							tr2(b.x,b.y,z,  
								bmx,bmy,z+10,  
								a.x,a.y,z);

							tr2(
								c.x,c.y,z,
								bmx,bmy,z+10,  
								d.x,d.y,z);*/


						  }

					  }

				  }
				  
				 
				glEnd();
				bloff
					  lon



				loff
				glBegin(GL_TRIANGLES);
			
				for ( n = iii-area; n<=iii+area; n++)
				  for(int m = jjj-area; m<=jjj+area; m++)
				  {  
					  if(n >=0 && m>=0 && n<100 && m<100)
					  {
						  if( prim[desc[n][m].num1].type == FORBOMB)
							ShowPrimitive(&prim[desc[n][m].num1]);
						 if(prim[desc[n][m].num2].type == FORBOMB)
							ShowPrimitive(&prim[desc[n][m].num2]);	
					  }

				  }	

				glEnd();
				lon
			pom


				

		//doff
	
		for(pBall=ball.begin(); pBall!=ball.end(); pBall++)
		{
				pBall->Show(0,0);
		}
	//	don



		

	}


	
	if(console_mode)
		{
		loff;
		
	//	blon;
		

		 glColor3f(1,0,0);
		 	scene.font.glDrawText(winH,10,500,"file> %s",command);
		 lon;//	bloff;
		}

	pom


}


void MyPerspective ( double FOV,double nearz,int farz) 
{ 	
	glMatrixMode ( GL_PROJECTION); // выбор матрицы проекций (камеры)  
    glLoadIdentity (); 
    gluPerspective(FOV, 
     (double)(winW) / (double)winH, 
    nearz, 
    farz); 
    glMatrixMode ( GL_MODELVIEW); // выбор матрицы модели  

}

int tttt=0;
void myDisplay()
{
	tttt++;
	if(tttt==8) tttt=0;

//	MyPerspective ( 60,10,10000) ;
//	glScissor ( 0, winH/4, winW, winH-(winH/4));

	int granY = winH/4;
	PointF camHero = gish.medium();
	camHero.y += 50;
	if(!cameraHeroOrientation)
		camHero = forbombPoint;


//	glScissor ( 0, granY, winW, winH-granY);
//	glViewport( 0, 0, winW, winH);  

//	if(tttt!=0)
//	{
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	displayByCamera(camHero,0,12); 


//	}


/*

*/

//	glViewport( 0, granY, winW, winH-granY); 



//	displayByCamera(camHero,0,12); 


		
	//	 
//	if(tttt!=0)
		
//	glScissor ( 0, 0, winW, granY-1);
//	glViewport(0, 0, winW, granY-1);  
	
//	if(tttt==0)
	{	
	
	/*	glScissor (0, 0, winW/4, granY-1);
		glViewport(0, 0, winW/4, granY-1);  

		glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
*/	
	    
	
	//	glViewport(0, 0, winW, granY-1);  
//		glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
		
	//	displayByCamera(camHero,0,12);

	//	displayByCamera(ToPointF(weapon[BOMB].x,weapon[BOMB].y+50),10,5);
	//	glutSwapBuffers();


	/*	glScissor ((winW>>2)+100, 0,winW-(winW>>2) , winH>>2);
		glViewport((winW>>2)+100, 0,winW-(winW>>2) , winH>>2); 
		glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();*/
	
		pum
					
			glTranslatef(0,0,10);
			loff;
			
			glColor3f(1,0,1);
			
			/*	scene.font.glDrawText(winH,200,20,"YROT %d",(int)YROT);
				scene.font.glDrawText(winH,200,30,"XROT %d",(int)XROT);
				scene.font.glDrawText(winH,200,40,"curDescI %d",(int)curDescI);
				scene.font.glDrawText(winH,200,50,"curDescJ %d",(int)curDescJ);
		*/
			

			glColor3f(0,1,0);
				
			//			glColor3f(0,0,0);
			//				scene.font.glDrawText(winH,11,151," ислород   %d", (int)gish.Ox);
			//			glColor3f(1,1,1);
			//				scene.font.glDrawText(winH,10,150," ислород   %d", (int)gish.Ox);

						
						lon
			
			glColor3f(0,0,0);
						
						lon	
		pom	
/**/

	loff
		pum	

		if(gish.H>0)
		{
			glColor3f(0,0.75,0);
			glTranslatef(0,3.4,-10);
			pum
			glScalef(gish.H*0.01,0.05,0.1);
			glutSolidCube(1);
			pom	
		}
		else	
		{
			glColor3f(1,1,1); scene.fontBig.glDrawText(winH,150,300,"DEMO from Useinov Evgeni");
		}
			pum
			glScalef(1,0.01,0.01);
			glutSolidCube(1);
			pom
	
		

				if(pauseMode) {
					glColor3f(1,1,1);
					scene.fontBig.glDrawText(winH,winW/2,winH/2,"PAUSE");
				}
		//	scene.font.glDrawText(winH,10,22,"Hero health %d\%%", (int)gish.H);			
		
		pom	


		pum	


		
		if(weapon[BOMB].active)
		{
				glColor3f(1,1,0);
				glTranslatef(0, 3.2,-10);
				pum
				glScalef(weapon[BOMB].health*0.01,0.05,0.1);
				glutSolidCube(1);
				pom
				pum
				glScalef(1,0.01,0.01);
				glutSolidCube(1);
				pom	
		

			//	scene.font.glDrawText(winH,10,72,"Bomb health %d\%%",(int)weapon[BOMB].health);	
			/*	scene.font.glDrawText(winH,50,150,"”правление:");
				scene.font.glDrawText(winH,50,170,"Q - отдать 10\%% здоровь€ бомбе");
				scene.font.glDrawText(winH,50,190,"E - вз€ть 10\%% здоровь€ у бомбы");*/
			
		}
	
		pom
		
	

	lon	


	//	glutSwapBuffers();
	
	}
//	else 
	{
	//	glScissor (0, 0, 320, 240);
	//	glViewport(0, 0, 320, 240);   
	//	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//	glScissor ( 0, 0, winW, granY-1);	
		
		
	//	displayByCamera(camHero,0,12);

	}

	//if(tttt==0)
		glutSwapBuffers();


//	glFlush();
//	glutSwapBuffers();	
}


