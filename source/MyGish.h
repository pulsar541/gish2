#pragma once
 
#include <vector>
using namespace std;

//#include "primitive.h"
#include "weapon.h"
#include "Physics.h"
 

class MyGish: public GameObject 
{
public:
	bool LIP   ;
	bool SKOL  ;
	bool TVER ;	
	bool FIRE ;
	
	Unit *bui[100];
	int N ;
	float H ,oldH;	
	float Ox ;
	int Score ; 
	PointF oldMed;
	PointF med;
	PointF boxMIN, boxMAX;
	float color[4];
	float tmpcolor[4];
	bool Red;
	bool DelOx;
	float diameter;
//	vector<Primitive>::iterator p;
///	Impact impact[1];
	bool SLOMO;

	int currentWeapon;

	Weapon weapon;

	Physics *phys;

	MyGish(Physics *phys);

	void SetPos(float x ,float y);
	

	void actionOnTime(int numInterval);;

	


	void calcMedium();

	PointF medium();

/*	PointF boxMedium ()
	{
	
	//	st_medium.x = (boxMIN.x + boxMAX.x) /2;
	//	st_medium.y = (boxMIN.y + boxMAX.y) /2;	
		return medium();
	}*/
	
	int soot(int a);


	int numMedX();


	void Kaplya();



	void Slipanie(Primitive *prim, 
					 int NUM_TR , 
					 float limitDist,
					 bool moveUP,
					 bool moveDOWN,		 
					 bool moveLEFT,
					 bool moveRIGHT);

	

void AdditionColliz(Primitive *primitive,
					int NUM_TR, 
					bool moveDOWN,
					bool moveUP,
					bool moveLEFT,
					bool moveRIGHT,
					bool jump, 
					int i);


	//bool inBox(Unit *u);

/*	void damaging(float value)
	{
		this->H -= value;
		color[0] = 1;
		color[1] = 0;
		color[2] = 0;
	}

*/
/*	void ShowShadowsBalls()
	{

		pum;

		for(int i=0;i<N;i++)
			if(i!=1) bui[i]->ShowShadow1(0,light,0,0);
				
		pom;
	}*/


};


 