#ifndef UNIT_H
#define UNIT_H

#include "Point2d.h"
#include "gameobject.h"
#include "fvector.h"

 

class Unit : public GameObject, public PointF
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
		int massCategory;

		bool moveble;

		float cred,
			  cgreen,
			  cblue;


		Unit();

		Unit(float x, float y, float radius);

		
		void setPos(float x, float y);

		void setRadius(float r);
		void setDxDy(float dx, float dy);
		void setMassive(short value);
		void setFriction(bool fri);
		void setSpirit(bool spi);
		void setInertion(float ine);
		void CalcVector();

		void CalcDxDy();

		void Trenie(float trenie);
		void Move();


		//virtual void Show() = 0;

		void actionOnTime(int);
	};

#endif