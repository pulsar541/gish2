#include "Point2d.h"

PointF::PointF()
{
	setPos(0, 0);
}

PointF::PointF(float x, float y)
{
	setPos(x, y);
}

void PointF::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

PointF PointF::operator*(const PointF& pointf) const { return PointF(x * pointf.x, y * pointf.y); }

PointF PointF::operator*(const float& value) const { return PointF(x * value, y * value); }

PointF PointF::operator+(const PointF& pointf) const { return PointF(x + pointf.x, y + pointf.y); }

PointF PointF::operator+(const float& value) const { return PointF(x + value, y + value); }
