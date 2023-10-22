#ifndef MYGISH_H
#define MYGISH_H

#include "building.h"
#include "primitive.h"
#include "phys.h"
#include "impact.h"
#include "weapon.h"
#include "door.h"
#include "key.h"
#include "item.h"

class MyGish: public GameObject 
{
public:
	bool LIP   ;
	bool SKOL  ;
	bool TVER ;	
	bool FIRE ;
	Building *bui[100];
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
	vector<Primitive>::iterator p;
///	Impact impact[1];
	bool SLOMO;

	int currentWeapon;

	Weapon weapon;

	MyGish()
	{	DelOx = false;
		Red = false;
		Score= 0;
		N = 24;
		LIP  = false;
		SKOL = false;
		TVER = false;
		FIRE = false;
		SLOMO=false;
		H = 100;
		Ox = 10;
		tmpcolor[0] = color[0] = 1;
		tmpcolor[1] = color[1] = 1;
		tmpcolor[2] = color[2] = 1;
		tmpcolor[3] = color[3] = 1;
		SetPos(limitX/2,limitY/2);
		currentWeapon = WeaponTypes::GRENADE;
	//	impact
	}

	void SetPos(float x ,float y)
	{
		for(int i=0;i<N;i++)
			bui[i] = new Building(x+70*sin((float)i*_torad*15),y+70*cos((float)i*_torad*15),6.2,i);
	
//		starttime = timeGetTime();
	}
	

	void actionOnTime(int numInterval){};

	


	void calcMedium()
	{
	
		float XMed=0;
		float YMed=0;	
		
		int kkk=0;

		for(int i=0;i<N;i++)
		{
			if(bui[i]->visible)
			{
			XMed+=bui[i]->x;
			YMed+=bui[i]->y;
			kkk++;
			}
		}

		
		XMed/=kkk;
		YMed/=kkk;

		med.x = XMed;
		med.y = YMed;

		boxMIN.x = XMed - 200;
		boxMIN.y = YMed - 200;
		boxMAX.x = XMed + 200;
		boxMAX.y = YMed + 200;
	
	}

	PointF medium()
	{
		calcMedium();
		return med;
	}

/*	PointF boxMedium ()
	{
	
	//	st_medium.x = (boxMIN.x + boxMAX.x) /2;
	//	st_medium.y = (boxMIN.y + boxMAX.y) /2;	
		return medium();
	}*/
	
	int soot(int a)
	{
		if(a<N/2) 
			return a+N/2;
		else 
			return a-N/2;
	}


	int numMedX()
	{
		int res=0;
		for(int i=1;i<N;i++)
		{
			if(fabs(bui[i]->x -medium().x ) > fabs(bui[i-1]->x -medium().x )) res = i-1;
			else res = i;
		}
		return res;
	}


	void Kaplya()
	{	
		float elementsDist = 10; // 12.4

		int K=25;
		int L = 70; // 90;

		if(H>0) 
		{	
			TROS ((Unit**)bui,0,N-1, elementsDist,1000);
			SVIAZKA (bui[0],bui[N-1], elementsDist,1000);
		}

			for(int i=0;i<N;i++)
			{
				if(TVER)
					{K=2000;
					 L = 80; //100;

					 bui[i]->y-=0.1;
					}

				K=180000/SQR(diameter=Dist(bui[i],bui[soot(i)])) ;

				PROCH(bui[i],bui[soot(i)],L+ elementsDist,K);
			
			}	
		
	
	}



	void Slipanie(Primitive *prim, 
					 int NUM_TR , 
					 float limitDist,
					 bool moveUP,
					 bool moveDOWN,		 
					 bool moveLEFT,
					 bool moveRIGHT)
	{

	
					if(prim->type ==  HYDRO || prim->type ==  ICE || prim->type ==  SAND )
						return;

				//	for(int k=0;k<3;k++)
					for(int i=0;i<N;i++)
					{
		
						

						int numNL = prim->numNearLine(ToPointF(bui[i]->x,bui[i]->y));

						if(CircleIntersects(
							&bui[i]->x,
							&bui[i]->y,
							bui[i]->radius+limitDist,
							prim->GetLineLength(numNL), 	
							prim->GetLineA(numNL),	
							prim->GetLineB(numNL)))
						{

						//	gravity = 0;	
							float dd = distance (prim->GetLineA(numNL),
												 prim->GetLineB(numNL),
											  	  ToPointF(bui[i]->x,bui[i]->y));

							bui[i]->x +=prim->GetLineNormal(numNL).x * SIGN(dd);
							bui[i]->y +=prim->GetLineNormal(numNL).y * SIGN(dd);	
							
							int N = soot(i);
	
	
							if(H>0)
							{
							if(moveUP)		bui[N]->y+=0.30;	
							if(moveDOWN)	bui[N]->y-=0.30;	
							}


						}
					//	else 	gravity = 0.1;	
					}
		//		}

	}

	

void AdditionColliz(Primitive *primitive,
					int NUM_TR, 
					bool moveDOWN,
					bool moveUP,
					bool moveLEFT,
					bool moveRIGHT,
					bool jump, 
					int i)
{	


			static float f = 1;

			if(primitive->type ==  HYDRO )
			{	
				for(int i=0;i<N;i++)
				if(pointInPrimitive(ToPointF(bui[i]->x,bui[i]->y) , primitive))
				{ 

					if(primitive->typeOfImpact == EVIL)
						this->H -=0.01;
				}
				return;
			}


			if(primitive->type ==  GEO 
				|| primitive->type ==  FORBOMB 
				|| primitive->type ==  ICE 
				||  primitive->type ==  SAND)
			{

				int M=i ,
				    N=soot(i);
				int numNL = primitive->numNearLine(ToPointF(bui[i]->x,bui[i]->y) );

		//		if(pointInPrimitive(ToPointF(bui[i]->x,bui[i]->y) , primitive))
		//		if(bui[i]->onHard)


		//		if(distance(primitive->line[numNL].a,primitive->line[numNL].b , bui[i])<=bui[i]->radius)
				{ 
				
					if(H>0 && primitive->type !=  ICE)
					{					
					if(moveLEFT)	bui[N]->x-=0.5;	
					if(moveRIGHT)	bui[N]->x+=0.5;		
					}

				//	if(moveUP)		bui[N]->y+=0.15;	
				//	if(moveDOWN)	bui[N]->y-=0.15;
				//	if(primitive->type == ICE)
				//	{
							
				//				if(moveLEFT)	bui[M]->x+=0.7;	
				//				if(moveRIGHT)	bui[M]->x-=0.7;	
				//	}



					if(primitive->type != SAND)
						if(H > 0 && jump)				
						{ f+=3;
						 bui[N]->x += f * primitive->GetLineNormal(numNL).x ;
						 bui[N]->y += f * primitive->GetLineNormal(numNL).y ;
						}

					f=1;

				//	if(!SKOL)
					if(primitive->type != ICE)
					{
				/*	bui[M]->dx = primitive->dx;
					bui[M]->dy = primitive->dy;
					bui[M]->Move();*/
					}
				}
			}
			
		
}


	bool inBox(Unit *u)
	{
		if(    u->x >= boxMIN.x 
			&& u->x <= boxMAX.x
			&& u->y >= boxMIN.y
			&& u->y <= boxMAX.y)
			return true;
		return false;
	}

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


void MyGishCollision(MyGish *mygish,Unit *unit)
{

	for(int i=0;i<mygish->N;i++)	
	{

		if(mygish->LIP && Dist(mygish->bui[i],unit)<=unit->radius+mygish->bui[i]->radius)
		{	if (unit->typeOfImpact == EVIL ) 
				SVIAZKA_UnitOne(mygish->bui[i],unit,unit->radius,5000);
			else
			{	
				if((i%2)==0)
					SVIAZKA(mygish->bui[i],unit,unit->radius,5000);
			}

		}
		else 
		{	
			if (unit->typeOfImpact == EVIL ) 
				ProchUnitOne(	mygish->bui[i], unit, unit->radius);
			else 
				Proch(	mygish->bui[i], unit, unit->radius);
		}
	}



/*	Building *unit2;
	unit2 = new Building(mygish->medium().x, mygish->medium().y,1,0);

	if(Dist(unit2,unit)<unit2->radius)	
	{//	Proch(	unit2, unit, 60 );
		unit->y+=45;
		unit->setDxDy(0,0);
		unit->Move();
	}
	
	delete unit2;*/
	
}


#endif
