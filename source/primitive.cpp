#include "primitive.h"


 Primitive::Primitive()
{
	//	set(GEO, PointF(0,0)	,PointF(0,0)	,PointF(0,0), 0,true,num);
}

 void Primitive::set(int type, PointF a, PointF b, PointF c, float Width, bool ishb, int NUM)
{

	this->type = type;
	this->NUM = NUM;
	isHalfBox = ishb;

	isLegal = false;

	static int cc = 0;
	Count = cc;
	cc++;

	fgh = 1100 + trigonom::minirand() * 50;


	dx = 0;
	dy = 0;



	//if(type!=HYDRO)
	//Width = 100 ;

	this->Width = Width;


	if (type == HYDRO) this->Width *= 0.95f;


	setPos(a, b, c);
	/*
	this->A = a;
	this->B = b;
	this->C = c;

	bmx = 	(A.x + C.x)*0.5;
	bmy = 	(A.y + C.y)*0.5;

	isDepth=false;

	uppest= false;

	boxMIN.x = MIN(a.x, MIN(b.x,c.x));
	boxMIN.y = MIN(a.y, MIN(b.y,c.y));
	boxMAX.x = MAX(a.x, MAX(b.x,c.x));
	boxMAX.y = MAX(a.y, MAX(b.y,c.y));
	medx= (A.x+B.x+C.x)/3;
	medy= (A.y+B.y+C.y)/3;
	medy= Width/2;

	line[0].set(a.x,a.y,b.x,b.y,Width,0);
	line[1].set(b.x,b.y,c.x,c.y,Width,1);
	line[2].set(c.x,c.y,a.x,a.y,Width,2);

	if(pointInPrimitive(PointF((A.x+B.x)/2+line[0].KKK().x,  (A.y+B.y)/2 + line[0].KKK().y), this))
	line[0].invertNormal = true;

	if(pointInPrimitive(PointF((C.x+B.x)/2+line[1].KKK().x,  (C.y+B.y)/2 + line[1].KKK().y), this))
	line[1].invertNormal = true;

	if(pointInPrimitive(PointF((A.x+C.x)/2+line[2].KKK().x,  (A.y+C.y)/2 + line[2].KKK().y), this))
	line[2].invertNormal = true;
	*/




	//		glNewList(NUM,GL_COMPILE);
	//			Show();
	//		glEndList();
}

 void Primitive::setPos(PointF a, PointF b, PointF c)
{
	this->A = a;
	this->B = b;
	this->C = c;

	bmx = (A.x + C.x) * 0.5;
	bmy = (A.y + C.y) * 0.5;

	isDepth = false;

	uppest = false;

	boxMIN.x = MIN(a.x, MIN(b.x, c.x));
	boxMIN.y = MIN(a.y, MIN(b.y, c.y));
	boxMAX.x = MAX(a.x, MAX(b.x, c.x));
	boxMAX.y = MAX(a.y, MAX(b.y, c.y));
	medx = (A.x + B.x + C.x) / 3;
	medy = (A.y + B.y + C.y) / 3;
	medy = Width / 2;

	line[0].set(a.x, a.y, b.x, b.y, Width, 0);
	line[1].set(b.x, b.y, c.x, c.y, Width, 1);
	line[2].set(c.x, c.y, a.x, a.y, Width, 2);

	if (pointInPrimitive(PointF((A.x + B.x) / 2 + line[0].KKK().x, (A.y + B.y) / 2 + line[0].KKK().y)))
		line[0].invertNormal = true;

	if (pointInPrimitive(PointF((C.x + B.x) / 2 + line[1].KKK().x, (C.y + B.y) / 2 + line[1].KKK().y)))
		line[1].invertNormal = true;

	if (pointInPrimitive(PointF((A.x + C.x) / 2 + line[2].KKK().x, (A.y + C.y) / 2 + line[2].KKK().y)))
		line[2].invertNormal = true;

	setCorrect();
}

 Primitive::~Primitive()
{
	//	delete 	&line[0] ;

	//	line[0] = NULL;
	//	line[1]	= NULL;
	//	line[2] = NULL;
}

 void Primitive::actionOnTime(int intervalMilliSec)
{
}

 void Primitive::setColor(float r, float g, float b, float a, bool show)
{
	view.color[0] = r;
	view.color[1] = g;
	view.color[2] = b;
	//	view.color[3]=a;
	view.color[3] = 0;

	view.colorDark[0] = r * 0.5;
	view.colorDark[1] = g * 0.5;
	view.colorDark[2] = b * 0.5;
	//	view.colorDark[3]=a*0.5;
	view.colorDark[3] = 0;

	this->show = show;

}

 void Primitive::setColor(float r, float g, float b, float a)
{
	view.color[0] = r;
	view.color[1] = g;
	view.color[2] = b;
	view.color[3] = a;
	view.color[3] = 0;

	view.colorDark[0] = r * 0.5;
	view.colorDark[1] = g * 0.5;
	view.colorDark[2] = b * 0.5;
	view.colorDark[3] = a * 0.5;

}

 int Primitive::numMin3(float a, float b, float c)
{

	if (a <= b && a <= c) return 0;
	if (b <= a && b <= c) return 1;
	if (c <= a && c <= b) return 2;

	return 0;
}

 PointF Primitive::GetLineNormal(int i)
{
	return line[i].KKK();
}

 MyLine Primitive::GetLine(int i)
{
	return line[i];
}

 PointF Primitive::GetLineA(int i)
{
	return line[i].a;
}

 PointF Primitive::GetLineB(int i)
{
	return line[i].b;
}

 float Primitive::GetLineLength(int i)
{
	return line[i].Length;
}

 int Primitive::numNearLine(PointF P)
{
	return 	numMin3(fabs(trigonom::distance(line[0].a, line[0].b, P)),
		fabs(trigonom::distance(line[1].a, line[1].b, P)),
		fabs(trigonom::distance(line[2].a, line[2].b, P))
	);

}

 PointF Primitive::medium()
{

	return st_medium;
}

 bool Primitive::HalfCheck(PointF P, bool pr)
{
	PointF a, b, c;
	if (pr)
	{
		a = this->C;
		b = this->B;
		c = this->A;
	}
	else
	{
		a = this->A;
		b = this->B;
		c = this->C;
	}

	if ((P.x - a.x) * (a.y - b.y) - (P.y - a.y) * (a.x - b.x) >= 0)
	{
		if ((P.x - b.x) * (b.y - c.y) - (P.y - b.y) * (b.x - c.x) >= 0)
		{
			if ((P.x - c.x) * (c.y - a.y) - (P.y - c.y) * (c.x - a.x) >= 0)
				return true;

		}
	}

	return false;
}

 void Primitive::Trenie(Unit* b)
{

	b->dx = 0;
	b->dy = 0;
	b->Move();
}

 bool Primitive::inBox(Unit* u)
{
	if (u->x >= boxMIN.x
		&& u->x <= boxMAX.x
		&& u->y >= boxMIN.y
		&& u->y <= boxMAX.y)
		return true;
	return false;
}

 void Primitive::Move()
{
	A.x += dx;
	B.x += dx;
	C.x += dx;

	A.y += dy;
	B.y += dy;
	C.y += dy;

	boxMIN.x = MIN(A.x, MIN(B.x, C.x));
	boxMIN.y = MIN(A.y, MIN(B.y, C.y));
	boxMAX.x = MAX(A.x, MAX(B.x, C.x));
	boxMAX.y = MAX(A.y, MAX(B.y, C.y));
	medx = (A.x + B.x + C.x) / 3;
	medy = (A.y + B.y + C.y) / 3;

	UpdateMediumPos();
}

 void Primitive::UpdateMediumPos()
{
	st_medium.x = (boxMIN.x + boxMAX.x) / 2;
	st_medium.y = (boxMIN.y + boxMAX.y) / 2;
}

 void Primitive::Show()
{}

 void Primitive::ShowAsSpheme()
{

}

 bool Primitive::pointInPrimitive(PointF point)
{
	PointF a, b, c;

	a = C;
	b = B;
	c = A;

	if ((point.x - a.x) * (a.y - b.y) - (point.y - a.y) * (a.x - b.x) >= 0)
	{
		if ((point.x - b.x) * (b.y - c.y) - (point.y - b.y) * (b.x - c.x) >= 0)
		{
			if ((point.x - c.x) * (c.y - a.y) - (point.y - c.y) * (c.x - a.x) >= 0)
				return true;

		}
	}


	a = A;
	b = B;
	c = C;


	if ((point.x - a.x) * (a.y - b.y) - (point.y - a.y) * (a.x - b.x) >= 0)
	{
		if ((point.x - b.x) * (b.y - c.y) - (point.y - b.y) * (b.x - c.x) >= 0)
		{
			if ((point.x - c.x) * (c.y - a.y) - (point.y - c.y) * (c.x - a.x) >= 0)
				return true;

		}
	}

	return false;
}
