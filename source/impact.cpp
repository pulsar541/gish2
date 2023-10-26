#include "impact.h"

Impact::Impact()
{
}

void Impact::set(int type)
{
	H = 100;
	this->type = type;
	radius = 0;
	ammoDist = 2000;
	setCorrect();
	typeOfImpact = EVIL;
}

void Impact::actionOnTime(int numAction)
{

}
