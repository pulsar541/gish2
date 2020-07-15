#ifndef PRIMITIVE_H
#define PRIMITIVE_H


#include "myline.h"
#include "mymath.h"
#include "primitiveMath.h"


int SIZE1 = 120 ,SIZE2 = 110;

float limitX=SIZE1*100;
float limitY=SIZE2*100; 


#define GEO   0
#define HYDRO 1
#define ICE	  2
#define SAND  3
#define FORBOMB  4

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

	Primitive()
	{
	//	set(GEO, ToPointF(0,0)	,ToPointF(0,0)	,ToPointF(0,0), 0,true,num);
	}

	void set(int type, PointF a,PointF b,PointF c , float Width ,bool ishb, int NUM  )
	{

		this->type = type;
		this->NUM = NUM;
		isHalfBox = ishb;
		
		isLegal = false;

		static int cc=0;
		Count = cc;
		cc++;

		fgh = 1100+minirand()*50;


		dx = 0;
		dy=0;

	

		if(type!=HYDRO)
		Width = 100 ;

		this->Width=Width;

		setPos (a,b,c);
/*
		this->A = a;
		this->B = b;
		this->C = c;

		bmx = 	(A.x + C.x)*0.5;
		bmy = 	(A.y + C.y)*0.5;

		isDepth=false;

		uppest= false;

		boxMIN.x = MIN(a.x, MIN(b.x,c.x));
		boxMIN.y = MIN(a.y, MIN(b.y,c.y));
		boxMAX.x = MAX(a.x, MAX(b.x,c.x)); 
		boxMAX.y = MAX(a.y, MAX(b.y,c.y)); 
		medx= (A.x+B.x+C.x)/3;
		medy= (A.y+B.y+C.y)/3;
		medy= Width/2;		
		
		line[0].set(a.x,a.y,b.x,b.y,Width,0);
		line[1].set(b.x,b.y,c.x,c.y,Width,1);
		line[2].set(c.x,c.y,a.x,a.y,Width,2);

		if(pointInPrimitive(ToPointF((A.x+B.x)/2+line[0].KKK().x,  (A.y+B.y)/2 + line[0].KKK().y), this))
			line[0].invertNormal = true;

		if(pointInPrimitive(ToPointF((C.x+B.x)/2+line[1].KKK().x,  (C.y+B.y)/2 + line[1].KKK().y), this))
			line[1].invertNormal = true;
	
		if(pointInPrimitive(ToPointF((A.x+C.x)/2+line[2].KKK().x,  (A.y+C.y)/2 + line[2].KKK().y), this))
			line[2].invertNormal = true;	
*/


	

//		glNewList(NUM,GL_COMPILE);
//			Show();
//		glEndList();
	}


	void setPos(PointF a,PointF b,PointF c)
	{
		this->A = a;
		this->B = b;
		this->C = c;

		bmx = 	(A.x + C.x)*0.5;
		bmy = 	(A.y + C.y)*0.5;

		isDepth=false;

		uppest= false;

		boxMIN.x = MIN(a.x, MIN(b.x,c.x));
		boxMIN.y = MIN(a.y, MIN(b.y,c.y));
		boxMAX.x = MAX(a.x, MAX(b.x,c.x)); 
		boxMAX.y = MAX(a.y, MAX(b.y,c.y)); 
		medx= (A.x+B.x+C.x)/3;
		medy= (A.y+B.y+C.y)/3;
		medy= Width/2;		
		
		line[0].set(a.x,a.y,b.x,b.y,Width,0);
		line[1].set(b.x,b.y,c.x,c.y,Width,1);
		line[2].set(c.x,c.y,a.x,a.y,Width,2);

		if(pointInPrimitive(ToPointF((A.x+B.x)/2+line[0].KKK().x,  (A.y+B.y)/2 + line[0].KKK().y), this))
			line[0].invertNormal = true;

		if(pointInPrimitive(ToPointF((C.x+B.x)/2+line[1].KKK().x,  (C.y+B.y)/2 + line[1].KKK().y), this))
			line[1].invertNormal = true;
	
		if(pointInPrimitive(ToPointF((A.x+C.x)/2+line[2].KKK().x,  (A.y+C.y)/2 + line[2].KKK().y), this))
			line[2].invertNormal = true;
		
		setCorrect();	
	}

	~Primitive()
	{
	//	delete 	&line[0] ;

	//	line[0] = NULL;
	//	line[1]	= NULL;
	//	line[2] = NULL;
	}

//	bool isACTUAL()
//	{
//		return ACTUAL;
//	}

	void actionOnTime(int intervalMilliSec)
	{
	}

	void setColor(float r,float g,float b,float a, bool show)
	{
		view.color[0]=r;
		view.color[1]=g;
		view.color[2]=b;
	//	view.color[3]=a;
		view.color[3]=0;

		view.colorDark[0]=r*0.5;
		view.colorDark[1]=g*0.5;
		view.colorDark[2]=b*0.5;
	//	view.colorDark[3]=a*0.5;
		view.colorDark[3]=0;

		this->show=show;

	}
	void setColor(float r,float g,float b,float a)
	{
		view.color[0]=r;
		view.color[1]=g;
		view.color[2]=b;
		view.color[3]=a;
		view.color[3]=0;

		view.colorDark[0]=r*0.5;
		view.colorDark[1]=g*0.5;
		view.colorDark[2]=b*0.5;
		view.colorDark[3]=a*0.5;

	}


	int numMin3(float a,float b,float c )
	{
	
		if(a<=b && a<=c) return 0;
		if(b<=a && b<=c) return 1;
		if(c<=a && c<=b) return 2;
		
		return 0;
	}

	PointF GetLineNormal(int i)
	{	return line[i].KKK();
	}

	MyLine GetLine(int i)
	{	return line[i];
	}

	PointF GetLineA(int i) 
	{	return line[i].a;
	}

	PointF GetLineB(int i) 
	{	return line[i].b;
	}

	float GetLineLength(int i)
	{	return line[i].Length;
	}


	int numNearLine (PointF P)
	{
		return 	numMin3(fabs(distance(line[0].a, line[0].b, P)),
						fabs(distance(line[1].a, line[1].b, P)),
						fabs(distance(line[2].a, line[2].b, P))
						);

	}

	PointF medium()
	{
		
		return st_medium;
	}

	bool HalfCheck(PointF P,bool pr)
	{
		PointF a,b,c ;
		if(pr)
		{
	 	 a = this->C;
		 b = this->B;
		 c = this->A;
		}
		else
		{
		 a = this->A;
		 b = this->B;
		 c = this->C;
		}
		
		if ((P.x-a.x)*(a.y-b.y) - (P.y-a.y)*(a.x-b.x) >= 0) 
		  {
			  if ((P.x-b.x)*(b.y-c.y) - (P.y-b.y)*(b.x-c.x) >= 0) 
			  {
				  if ((P.x-c.x)*(c.y-a.y) - (P.y-c.y)*(c.x-a.x) >= 0) 
				  return true;

			  }
		  }	  

		return false;
	}


/*	bool  PtInTriang( PointF P)
	{
		
		return (HalfCheck(P,true) );
	}

	*/

	//gish.bui[i]->x


	void Trenie(Building *b)
	{
	
		b->dx = 0;
		b->dy = 0;
		b->Move();	
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


	void Move()
	{
		A.x+=dx;
		B.x+=dx;
		C.x+=dx;

		A.y+=dy;
		B.y+=dy;
		C.y+=dy;

		boxMIN.x = MIN(A.x, MIN(B.x,C.x));
		boxMIN.y = MIN(A.y, MIN(B.y,C.y));
		boxMAX.x = MAX(A.x, MAX(B.x,C.x)); 
		boxMAX.y = MAX(A.y, MAX(B.y,C.y)); 
		medx= (A.x+B.x+C.x)/3;
		medy= (A.y+B.y+C.y)/3;
	
		st_medium.x = (boxMIN.x + boxMAX.x) /2;
		st_medium.y = (boxMIN.y + boxMAX.y) /2;	
	}



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





	void Show()
	{}

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



	void ShowAsSpheme()
	{
/*

	//	glColor3f(0.3,0.3,0.3);
		glNormal3f(0,0.5,0.5);
	//	loff

			glBegin(GL_TRIANGLES);
			glVertex3f(C.x,C.y,Width);
			glVertex3f(B.x,B.y,Width);
			glVertex3f(A.x,A.y,Width);		
			glEnd();

	//	lon
	*/	
	 

		if(isLegal)
		{
			if(view.color[3]<1) view.color[3]+=0.02;
		}

		glColor4fv(view.color);
	

	//	line[0].Show();
	//	line[1].Show();
	//	line[2].Show();
	
		
		float mx= medx ;
		float my= medy ;	
		

	
		pum
		loff 
		//aaon	
	

	    glBegin(GL_LINE_STRIP);

/*		glColor4f(color[0]*0.5,color[1]*0.5,color[2]*0.5,color[3]);		tr2( mx,my,Width*0.8,   B.x,B.y,Width, A.x,A.y,Width);
		glColor4f(color[0]*0.3,color[1]*0.3,color[2]*0.3,color[3]);		tr2(C.x,C.y,Width,   B.x,B.y,Width,	   mx,my,Width*0.8);
		glColor4f(color[0]*0.4,color[1]*0.4,color[2]*0.4,color[3]);		tr2(A.x,A.y,Width,   C.x,C.y,Width,		   mx,my,Width*0.8);
*/

	//	tr(A.x,A.y,Width,   C.x,C.y,Width,		   B.x,B.y,Width+2);

		glEnd();


	//	aaoff
		lon	 
		pom

	
	}

};




bool pointInPrimitive(PointF point, Primitive  *primitive)
{
		PointF a,b,c ;


	 	 a = (*primitive).C;
		 b = (*primitive).B;
		 c = (*primitive).A;

		if ((point.x-a.x)*(a.y-b.y) - (point.y-a.y)*(a.x-b.x) >= 0) 
		  {
			  if ((point.x-b.x)*(b.y-c.y) - (point.y-b.y)*(b.x-c.x) >= 0) 
			  {
				  if ((point.x-c.x)*(c.y-a.y) - (point.y-c.y)*(c.x-a.x) >= 0) 
				  return true;

			  }
		  }	  


		a = (*primitive).A;
		b = (*primitive).B;
		c = (*primitive).C;


		if ((point.x-a.x)*(a.y-b.y) - (point.y-a.y)*(a.x-b.x) >= 0) 
		  {
			  if ((point.x-b.x)*(b.y-c.y) - (point.y-b.y)*(b.x-c.x) >= 0) 
			  {
				  if ((point.x-c.x)*(c.y-a.y) - (point.y-c.y)*(c.x-a.x) >= 0) 
				  return true;

			  }
		  }	  




		return false;
}



#endif





