#ifndef _gameobject_h_
#define _gameobject_h_

#include <vector>

#define GOOD 0
#define EVIL 1

#define MAX_INTERVALS 8
class GameObject
{
private:
	int intervals[MAX_INTERVALS];
public:
	DWORD starttime[MAX_INTERVALS];
	DWORD time[MAX_INTERVALS];
	int typeOfImpact;
//	vector<int> intervals;
//	vector<int>	::iterator pInter;


//	int intervalMilliSec;

	bool correct;
	GameObject()
	{
			typeOfImpact = GOOD;
			restart();

			for(int i=0;i<MAX_INTERVALS;i++)
				intervals[i] = 0;
			
			correct = false;

	}

	virtual void 	actionOnTime(int numAction) = 0;

	bool corrected()
	{
		return correct;
	}

	void setCorrect()
	{
		correct = true;
	}
	void setInterval(int index, int intervalsMilliSec)
	{
		if(index >= 0 && index < MAX_INTERVALS)
			intervals[index] = intervalsMilliSec;

		starttime[index] = timeGetTime() - rand()% timeGetTime() ;
		restart();
	}


	bool timer()
	{	
		for(int i=0;i<MAX_INTERVALS;i++)
			time[i] = timeGetTime()-starttime[i]; 

		bool flag = false;
		for( i=0;i<MAX_INTERVALS;i++)
		{
		  if ( intervals[i]!=0 && (time[i] >= intervals[i] || starttime[i] == timeGetTime()) )
		  {	starttime[i] += time[i];
			actionOnTime(i);
			flag = true;
		  }
		}
		return flag;

	}


	void restart()
	{	for(int i=0;i<MAX_INTERVALS;i++)
			starttime[i] = timeGetTime();
	}


};

#endif
