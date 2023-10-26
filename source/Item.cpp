#include "item.h"

Item::Item()
{
	radius = 5.0f + (float)(rand() % 15);
}

void Item::actionOnTime(int intervalMilliSec)
{

}

void Item::setType(int type)
{
	this->type = type;

}
