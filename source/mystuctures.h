#ifndef MY_STRUCTURES
#define MY_STRUCTURES

 
class PointF
{public:
		float x;
		float y;

		PointF()
		{
			setPos(0, 0);
		}

		PointF(float x, float y)
		{
			setPos(x, y);
		}
		 
		void setPos(float x, float y)
		{
			this->x = x; 
			this->y = y;
		}
		PointF operator * (const PointF& pointf) const { return PointF(x * pointf.x, y * pointf.y); }
		PointF operator * (const float& value) const {	return PointF(x * value, y * value); }
		PointF operator + (const PointF& pointf) const { return PointF(x + pointf.x, y + pointf.y); }
		PointF operator + (const float& value) const {	return PointF(x + value, y + value); }



};

class CELL
{
public:
	int num1;
	int num2;
	CELL()
	{
		num1=0; num2=0;
	}
};
 
 
class Point3d
{public:
 float x,y,z;	
	Point3d(float x,float y,float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};


#endif