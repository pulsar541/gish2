#pragma once

 
class PointF
{
public:
	float x;
	float y;

	PointF();

	PointF(float x, float y);

	void setPos(float x, float y);
	PointF operator * (const PointF& pointf) const;
	PointF operator * (const float& value) const;
	PointF operator + (const PointF& pointf) const;
	PointF operator + (const float& value) const;
};
 
/*
PointF PointF(float x, float y)
{
	return PointF(x, y);
}
*/
