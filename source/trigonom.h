#pragma once

#include "Point2d.h"

#define MAX(a,b) ((a < b) ? (b) : (a))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define		_torad	0.017453293  //3.1415926/180;
#define		_toa	57.29577952  //180/3.1415926;

#define SIGN(x)  ((x) < (0) ? (-1) : (1))
#define SQR(x)   ((x) * (x))


class trigonom
{
public:
	static bool CircleIntersects(float* x, float* y, float R, float L,
		PointF A, PointF  B);

	  
	static bool  simple_rasst(PointF p1, PointF p2, double R);;


	static float getC2(float A, float B); 
	static float DistS(float x1, float y1, float x2, float y2); 
	static float Dist(float* x1, float* y1, float* x2, float* y2); 
	static float Dist(PointF* p1, PointF* p2); 
	static float Dist(PointF p1, PointF  p2); 
	static float Dist(PointF* u, float x, float y);
	 

	static float distance(PointF a, PointF  b, PointF c); 
	static float distance(PointF a, PointF  b, PointF* c); 
	 
	static float minirand();


	static int interrRand(int a, int b);

	static double FSIN(float x); 

	static double FCOS(float x);
	 
	static void ch(int* a, int* b);
	static void ch(float* a, float* b);

	static int numMax3(float a, float b, float c, int* num2, int* num3); 
	static double ugol(double X1, double Y1, double X2, double Y2);



};

