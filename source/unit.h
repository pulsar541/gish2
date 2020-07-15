#ifndef UNIT_H
#define UNIT_H

#include "gameobject.h"
#include "fvector.h"

class Unit : public GameObject,public PointF
	{
	public:

		float dx,dy;
		float oldx,oldy;
	    bool inWater;
		bool onHard;
		bool onAlienUnit;
		float radius;
		short isMassive;
		FVector FMove;
		bool friction;
		bool spirit;
		float inertion;
		Unit()
		{
			x=0;
			y=0;
			oldx=x;
			oldy=y;
			dx=0;
			dy=0;
			radius = 0;
			isMassive = 1;
			friction = true;
			spirit = false;
			inWater = false;
			inertion = 1;
			correct = false;

		}



		
		void setPos(float x, float y)
		{
			this->x = x; 
			this->y = y;
			oldx=x;
			oldy=y;
			setCorrect();
		}

		void setRadius(float r)
		{
			this->radius = r; 
		}
		void setDxDy(float dx, float dy)
		{
			this->dx = dx/SLOMO_K; 
			this->dy = dy/SLOMO_K;
		}
		void setMassive(short value)
		{
			isMassive = value;
		}
		void setFriction(bool fri)
		{
			friction = fri;
		}
		void setSpirit(bool spi)
		{
			spirit = spi;
		}
		void setInertion(float ine)
		{
			inertion= ine;
		}
		void CalcVector()
		{
			if(inertion)
				FMove.calc_kas(oldx,oldy,x,y);
			
			if(isMassive==1)
			{
				FMove.calc_gravity();
				
				if(inWater) 
					FMove.calc_in_water(); 
			}

			if(isMassive == -1)
			{
				FMove.calc_antigravity();
				
				if(inWater) 
					FMove.calc_in_water(); 
			}

		
		}

		void CalcDxDy()
		{	
			dx = inertion*(FMove.x1 - FMove.x0)/SLOMO_K;
			dy = inertion*(FMove.y1 - FMove.y0)/SLOMO_K ;
		
			if(isMassive)
				if(inWater) 
					Trenie(0.985);

		}

		void Trenie(float trenie)
		{	

			dx*=trenie;
			dy*=trenie;

		}
		void Move()
		{
			
	
			x+=dx;
			y+=dy ;
			
			oldx=x-dx*SLOMO_K;
			oldy=y-dy*SLOMO_K;				
		}
	};

#endif