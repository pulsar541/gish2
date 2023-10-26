#pragma once
#include "unit.h"
class DropUnit :
    public Unit
{ 

public:
		
	 bool fix; 
	 bool blue ;
	 bool empty ;
	 bool visible;
	 bool enable ;
	 bool moveble;   
	 int massa; 
	 float oldrad ; 
	 bool inprocess ; 
	 bool Inert;
	  
	 int iter;
	 float cred,
		   cgreen,
		   cblue;
			
	 bool cc;
	 int coltype ;

	 int extype;
		
	
	 int NUM;
		
	 PointF tochka[36];
		
	 int nt1[44];
	 int nt2[44];
		 
	  
	
	DropUnit(float x, float y, float rad);
	void actionOnTime(int intervalMilliSec);

	int soot(int a);
	
 
	void CalcVectorInWater();

	void CalcDxDyInWater();
 

 
};