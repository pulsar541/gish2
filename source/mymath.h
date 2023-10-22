#ifndef MYMATH_H
#define MYMATH_H


//#include <stdio.h>
#include <math.h>



static int nzmend=2;



float minirand()
{ return (float)(rand()%10000)/10000;
}


int interrRand(int a, int b)
{
	return   a + rand() % (b - a);
}

double FSIN(float x)
{float xx=x*x;//2
 float xxx=xx*x;//3
 float xxxxxx=xxx*xxx; //6

 return (double)(x-0.166666667*xxx
	     +0.008333333*xxx*xx
		 -0.000198413*xxxxxx*x
		 +0.000002756*xxxxxx*xxx
		 -0.000000025*xxxxxx*xxx*xx);

}



double FCOS(float x)
{ 
 float xx=x*x;
 float xxxx=xx*xx;
 float xxxxxxxx=xxxx*xxxx;
 
 return  (double)
	 (1.00000000
	     -0.500000000*xx
		 +0.041666667*xxxx
		 -0.001388889*xxxx*xx
		 +0.000024802*xxxxxxxx
		 -0.000000276*xxxxxxxx*xx
		 +0.000000002*xxxxxxxx*xxxx);
}




int GetPos(char mode ,double x,double y, double z) 
   { static double mv[16],pm[16]; 
      static int vp[4]; 
      static double winx,winy,winz; 
      glGetDoublev(GL_MODELVIEW_MATRIX, mv); 
      glGetDoublev(GL_PROJECTION_MATRIX,pm); 
      glGetIntegerv(GL_VIEWPORT,vp); 
      gluProject(x,y,z,mv,pm,vp,&winx,&winy,&winz); 
      switch(mode) 
      {  case 'x' : return winx; 
         case 'y' : return winW-winy; 
         case 'z' : return winz; 
         default : return 0; 
      } 
   } 


/*
bool isGraphActual(PointF a,Unit b)
{

}
*/

PointF ToPointF(float x,float y)
{
		return PointF(x, y);
}


		double ugol(double X1,double Y1,double X2,double Y2)
		{ double result_ugol;
		 double b;  b=fabs(Y1-Y2);
		 double c;  c=fabs(X1-X2);


		  if(Y2<=Y1 && X2>=X1) result_ugol=360-atan(b/c)*_toa;
		  if(Y2<=Y1 && X2<X1)  result_ugol=180+atan(b/c)*_toa;
		  if(Y2>Y1 && X2<=X1)  result_ugol=180-atan(b/c)*_toa;
		  if(Y2>Y1 && X2>X1)   result_ugol=atan(b/c)*_toa;  

		  return result_ugol;

		}



		int numMax3(float a,float b,float c , int *num2 , int *num3)
		{
			if(a>b && a>c) {*num2 = 1; *num3 = 2; return 0;}
			if(b>a && b>c) {*num2 = 0; *num3 = 2; return 1;}
			if(c>a && c>b) {*num2 = 0; *num3 = 1; return 2;}
			return 0;
		}



	//	PointF medium();


#define ITNUM 4

float Sqroot(float x) {
  int expo,i;
  float a,b;
  if(x<=0.F) return(0.F);
  /* decompose x into mantisse ranged [0.5,1) and exponent. Machine-
     dependent operation is presented here as a function call. */
  x=frexp(x,&expo);
  /* odd exponent: multiply mantisse by 2 and decrease exponent 
     making it even. Now the mantisse is ranged [0.5,2.) */
  if(expo&1) {x*=2.F;expo--;}
  /* initial approximation */
  a=1.F;
  /* process ITNUM Newtonian iterations with the mantisse as 
     an argument */
  for(i=ITNUM;i>0;i--) {
    b=x/a; a+=b; a*=0.5F;
  }
  /* divide the exponent by 2 and combine the result.
     Function ldexp() is opposite to frexp. */
  a=ldexp(a,expo/2);
  return(a);
}

void ch(int *a,int *b)
{ 
	int t = *a;
	*a= *b;
	*b = t;
}
void ch(float *a,float *b)
{ 
	float t = *a;
	*a= *b;
	*b = t;
}

	
		bool CircleIntersects(float *x, float *y, float R, float L, 
		                      PointF A,PointF  B)
		{
		// единичный вектор отрезка AB
		  float overL = 1/ L;
		  float Xv = (B.x - A.x) * overL ;
		  float Yv = (B.y - A.y) * overL;
		  float Xd = (A.x - *x);
		  float Yd = (A.y - *y);
		  float b = 2 * (Xd * Xv + Yd * Yv);
		  float c = Xd * Xd + Yd * Yd - (R) * (R);
		  float c4 = c + c; c4 += c4;
		  float D = b * b - c4;
		  if (D < 0) return false; // нет корней, нет пересечений
		
		  D = Sqroot(D);
		  float l1 = ( - b + D) * 0.5f;
		  float l2 = ( - b - D) * 0.5f;
		  bool intersects1 = ((l1 >= 0.0) && (l1 <= L));
		  bool intersects2 = ((l2 >= 0.0) && (l2 <= L));
		  bool intersects = intersects1 || intersects2;
		
		  return intersects;
		}

	
		
		bool  simple_rasst (Unit *u1,Unit *u2, double R)
		{

			return (u1->x< u2->x+R && u1->x > u2->x - R &&
					u1->y< u2->y+R && u1->y > u2->y - R );
						
		//	return (fabs(X1-X2)<R && fabs(Y1-Y2)<R && fabs(Z1-Z2)<R);

		} ;

		
		bool  simple_rasst (PointF p1,PointF p2, double R)
		{

			return (p1.x< p2.x+R && p1.x > p2.x - R &&
					p1.y< p2.y+R && p1.y > p2.y - R );
						
		//	return (fabs(X1-X2)<R && fabs(Y1-Y2)<R && fabs(Z1-Z2)<R);

		} ;

		
		bool  simple_rasst (float x1,float y1, float x2,float y2, double R)
		{

			return (x1< x2+R && x1 > x2 - R &&
					y1< y2+R && y1 > y2 - R );
						
		//	return (fabs(X1-X2)<R && fabs(Y1-Y2)<R && fabs(Z1-Z2)<R);

		} ;



		float getC2 (float A,float B)
        {
			static float tmax,b;		
			tmax = MAX(A,B);
			b =  MIN(A,B)/tmax; 
        	return  tmax+ 0.425*b*b*tmax;
        } 
		
		float MousePosX (int winw)
		{
			POINT p;
			GetCursorPos(&p);
		//	glutGet
			return (p.x-(winw>>1)); 
		}

		
		float MousePosY (int winh)
		{
			POINT p;
			GetCursorPos(&p);
			return -(p.y-(winh>>1)); 
		}


		float DistS(float x1, float y1, float x2, float y2)
		{
	     //   return  getC2(fabs(x1 - x2),fabs(y1 - y2)); 
			return (float)sqrtf((x1 - x2) * (x1 - x2)+ (y1 - y2) * (y1 - y2)); 
		}
		

		float Dist(float *x1, float *y1, float *x2, float *y2)
		{
	     //   return  getC2(fabs(x1 - x2),fabs(y1 - y2)); 
			return (float)sqrtf((*x1 - *x2) * (*x1 - *x2)+ (*y1 - *y2) * (*y1 - *y2)); 
		}



		float Dist(PointF *p1,PointF  *p2)
		{
           	return Dist(&p1->x, &p1->y, &p2->x ,&p2->y);
		}
		
		float Dist(PointF p1,PointF  p2)
		{
           	return DistS(p1.x, p1.y, p2.x ,p2.y);
		}

		float Dist(Unit *bui1, PointF *p)
		{
	       
			return Dist(&bui1->x,&bui1->y, &p->x ,&p->y );
				
		}

		
		float Dist(Unit *u1,Unit  *u2)
		{
           	return Dist(&u1->x,&u1->y,  &u2->x,&u2->y);		
		}
		

		

		float Dist(Unit *u, float x, float y)
		{
	       	return Dist(&u->x,&u->y, &x, &y);	    
		}





		
		float distance(PointF a,PointF  b,PointF c)
		{																																																																												
			float dx = a.x - b.x;
			float dy = a.y - b.y;
			float D = dx * (c.y - a.y) - dy * (c.x - a.x);
			return (float)(D / sqrt(dx * dx + dy * dy));
		}

		float distance(PointF a,PointF  b,Unit *c)
		{																																																																												
			float dx = a.x - b.x;
			float dy = a.y - b.y;
			float D = dx * (c->y - a.y) - dy * (c->x - a.x);
			return (float)(D / sqrt(dx * dx + dy * dy));
		}
	


#endif
