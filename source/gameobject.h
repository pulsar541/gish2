#ifndef _gameobject_h_
#define _gameobject_h_

#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
 
#define GOOD 0
#define EVIL 1

#define MAX_INTERVALS 8


class GameObject
{
private:
	unsigned long intervals[MAX_INTERVALS];
public:
	unsigned long starttime[MAX_INTERVALS];
	unsigned long time[MAX_INTERVALS];
	int typeOfImpact;
//	vector<int> intervals;
//	vector<int>	::iterator pInter;


//	int intervalMilliSec;

	bool correct;
	GameObject();

	virtual void 	actionOnTime(int numAction) = 0;

	bool corrected();

	void setCorrect();
	void setInterval(int index, int intervalsMilliSec);


	bool timer();


	void restart();


};

#endif
