#include "unit.h"

 Unit::Unit()
{
	x = 0;
	y = 0;
	oldx = x;
	oldy = y;
	dx = 0;
	dy = 0;
	radius = 0;
	isMassive = 1;
	friction = true;
	spirit = false;
	inWater = false;
	inertion = 1;
	correct = false;
	massCategory = 0;
	moveble = false;
}

 Unit::Unit(float x, float y, float radius)
{
	Unit();
	setPos(x, y);
	setRadius(radius);
}

 void Unit::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
	oldx = x;
	oldy = y;
	setCorrect();
}

 void Unit::setRadius(float r)
{
	this->radius = r;
}

 void Unit::setDxDy(float dx, float dy)
{
	this->dx = dx / SLOMO_K;
	this->dy = dy / SLOMO_K;
}

 void Unit::setMassive(short value)
{
	isMassive = value;
}

 void Unit::setFriction(bool fri)
{
	friction = fri;
}

 void Unit::setSpirit(bool spi)
{
	spirit = spi;
}

 void Unit::setInertion(float ine)
{
	inertion = ine;
}

 void Unit::CalcVector()
{
	if (inertion)
		FMove.calc_kas(oldx, oldy, x, y);

	if (isMassive == 1)
	{
		FMove.calc_gravity();

		if (inWater)
			FMove.calc_in_water();
	}

	if (isMassive == -1)
	{
		FMove.calc_antigravity();

		if (inWater)
			FMove.calc_in_water();
	}


}

 void Unit::CalcDxDy()
{
	dx = inertion * (FMove.x1 - FMove.x0) / SLOMO_K;
	dy = inertion * (FMove.y1 - FMove.y0) / SLOMO_K;

	if (isMassive)
		if (inWater)
			Trenie(0.985);

}

 void Unit::Trenie(float trenie)
{

	dx *= trenie;
	dy *= trenie;

}

 void Unit::Move()
{


	x += dx;
	y += dy;

	oldx = x - dx * SLOMO_K;
	oldy = y - dy * SLOMO_K;
}

 void Unit::actionOnTime(int)
{

}
