#ifndef MY_STRUCTURES
#define MY_STRUCTURES


class PointF
{public:
		float x;
		float y;
			
		void setPos(float x, float y)
		{
			this->x = x; 
			this->y = y;
		}
};

class DESC
{
public:
	int num1;
	int num2;
	DESC()
	{
		num1=0; num2=0;
	}
};

DESC desc[100][100];

int curDescI, curDescJ;

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