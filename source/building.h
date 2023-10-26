#ifndef BUILDING_H
#define BUILDING_H




class Building: public Unit
{
 

public: 
 
 
	Building(float x, float y, float rad,int NUM): Unit()
	{ 
		cred = 0.7;
		cgreen =0.7;
		cblue = 0.7; 
	}
	void actionOnTime(int intervalMilliSec)
	{
	
	}

	//int soot(int a)
	//{
	//	if(a<18) return a+18;
	//	else return a-18;
	//}
  
 

};



#endif


