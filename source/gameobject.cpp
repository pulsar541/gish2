#include "gameobject.h"

GameObject::GameObject()
{
	typeOfImpact = GOOD;
	restart();

	for (int i = 0; i<MAX_INTERVALS; i++)
		intervals[i] = 0;

	correct = false;

}

bool GameObject::corrected()
{
	return correct;
}

void GameObject::setCorrect()
{
	correct = true;
}

void GameObject::setInterval(int index, int intervalsMilliSec)
{
	if (index >= 0 && index < MAX_INTERVALS)
		intervals[index] = intervalsMilliSec;

	starttime[index] = timeGetTime() - rand() % timeGetTime();
	restart();
}

bool GameObject::timer()
{
	for (int i = 0; i<MAX_INTERVALS; i++)
		time[i] = timeGetTime() - starttime[i];

	bool flag = false;
	for (int i = 0; i<MAX_INTERVALS; i++)
	{
		if (intervals[i] != 0 && (time[i] >= intervals[i] || starttime[i] == timeGetTime()))
		{
			starttime[i] += time[i];
			actionOnTime(i);
			flag = true;
		}
	}
	return flag;

}

void GameObject::restart()
{
	for (int i = 0; i<MAX_INTERVALS; i++)
		starttime[i] = timeGetTime();
}
