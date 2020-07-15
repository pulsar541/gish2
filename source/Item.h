#ifndef _item_h_
#define _item_h_

enum ItemTypes 
{
	HEALTH,
	AMMO,
	MAXITEMTYPES
};

class Item:public Unit
{
public:
	Item()
	{
		radius = 5+rand()%15;
	}
	int type;

	void actionOnTime(int intervalMilliSec)
	{
	
	}

	setType(int type)
	{
		this->type = type;
		
	}
};

#endif