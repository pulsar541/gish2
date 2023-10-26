#pragma once


#include "Unit.h"
#include "myline.h" 
#include "primitiveMath.h"
#include "GameObject.h"


#define GEO   0
#define HYDRO 1
#define ICE	  2
#define SAND  3
#define FORBOMB  4
 


#define  SIZE1  120 
#define  SIZE2   110

#define limitX   (SIZE1*100)
#define limitY   (SIZE2*100)

 

struct PrimitiveView
{
	 float color[4];
	 float colorDark[4];
};
 

class Primitive : public GameObject
{

public:

	int type; 


	PointF A;
	PointF B;
	PointF C;
	MyLine line[3];

	float Width;
	int Count;
	PointF boxMIN,boxMAX;
	int NUM;
	bool isHalfBox;
	float dx,dy;
	bool isLegal;
	float medx;
	float medy;	
	float medz;	
	bool show;
	bool isDepth;
	bool uppest;
	int fgh;
	float bmx,bmy;
	PrimitiveView view;

	PointF st_medium;

	Primitive();

	void set(int type, PointF a,PointF b,PointF c , float Width ,bool ishb, int NUM  );


	void setPos(PointF a,PointF b,PointF c);

	~Primitive();

//	bool isACTUAL()
//	{
//		return ACTUAL;
//	}

	void actionOnTime(int intervalMilliSec);

	void setColor(float r,float g,float b,float a, bool show);
	void setColor(float r,float g,float b,float a);


	int numMin3(float a,float b,float c );

	PointF GetLineNormal(int i);

	MyLine GetLine(int i);

	PointF GetLineA(int i);

	PointF GetLineB(int i);

	float GetLineLength(int i);


	int numNearLine (PointF P);

	PointF medium();

	bool HalfCheck(PointF P,bool pr);


/*	bool  PtInTriang( PointF P)
	{
		
		return (HalfCheck(P,true) );
	}

	*/

	//gish.bui[i]->x


	void Trenie(Unit *b);

	bool inBox(Unit *u);


	void Move();


	void UpdateMediumPos();



/*

	void Show2DLines()
	{


		if(color[3]>0)
		{
		line[0].Show2D();
		line[1].Show2D();
		line[2].Show2D();
		}
	}*/





	void Show();

/*	void ShowPalka()
	{
	
	pum
			if(isHalfBox && fgh>1140)
			{	blon

				pum
				glColor4f(color[0],color[1],color[2],1-color[3]*0.3);
				glTranslatef(boxMIN.x+SIZE1*0.5,boxMIN.y+SIZE2*0.5,-500);
				glScalef(5,5,color[3]*fgh);
				glutSolidCube(1);
				pom
	
				bloff
			}

	pom
	}*/



	void ShowAsSpheme();



	bool pointInPrimitive(PointF point);



};









