#include "DropUnit.h"

#include "trigonom.h"

DropUnit::DropUnit(float x, float y, float rad)
{
	cc = false;
	iter = 0;
	massa = 1;
	blue = true;
	empty = true;
	visible = true;
	enable = true;
	moveble = false;

	Inert = true;
	fix = false;
	//this->NUM = NUM;
	inprocess = true;

	cred = 0.7;
	cgreen = 0.7;
	cblue = 0.7;

	oldx = this->x = x;
	oldy = this->y = y;

	oldrad = this->radius = rad;


	for (int k = 0; k<36; k++)
	{
		tochka[k].x = this->x + (float)cos(k * 10 * _torad) * this->radius;
		tochka[k].y = this->y + (float)sin(k * 10 * _torad) * this->radius;
	}


	dx = dy = 0;


}

void DropUnit::actionOnTime(int intervalMilliSec)
{

}

int DropUnit::soot(int a)
{
	if (a<18) return a + 18;
	else return a - 18;
}

void DropUnit::CalcVectorInWater()
{

	FMove.calc_kas(oldx, oldy, x, y);
	FMove.calc_in_water();

}

void DropUnit::CalcDxDyInWater()
{
	///	old_dx = dx;
	//	old_dy = dy;		
	dx = (FMove.x1 - FMove.x0);
	dy = (FMove.y1 - FMove.y0);
	dx *= 0.985;
	dy *= 0.985;
}
