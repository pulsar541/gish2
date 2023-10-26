#ifndef _item_h_
#define _item_h_

#include "unit.h"

enum ItemTypes 
{
	HEALTH,
	AMMO,
	MAXITEMTYPES
};

class Item:public Unit
{
public:
	Item();
	int type;

	void actionOnTime(int intervalMilliSec);

	void setType(int type);
};

#endif