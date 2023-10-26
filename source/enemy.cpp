#include "enemy.h"
#include <cstdlib>
#include "trigonom.h"
 
 Enemy::Enemy()
{
}

 void Enemy::set(int type, float x, float y)
{
	this->type = type;
	typeOfImpact = EVIL;
	setPos(x, y);

	startPosition = PointF(x, y);
	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;
	move = false;
	rotate = 0;
	angle = rand() % 360;
	dangle = 0.1;
	dspeed = 2;
	ACTUAL = false;
	restart();
	impactCounter = 0;
	goalx = x + 1;
	goaly = y;
	oldDistToGoal = 0;

	impactMassive = 0;
	tmpFireType = 0;

	tmpInterval = 100 + rand() % 700;


	respawnInterval = 60000;

	setType(type);

	sleeping = true;

	//minirand()>0.5;

	maxHealth = health = radius;
	impactSpeed = 10;
	dx = dy = 0;

	//setInterval(3, respawnInterval);


	// minirand()>0.5;

	//	if(!impactMassive)
	//		impactSpeed = 3+minirand()*3;

}

 void Enemy::setType(int type)
{
	switch (type)
	{
	case ANTI_JUMPER:
		setMassive(-1);
		//	setFriction(false);
		impactMassive = 1;
		tmpFireType = 1;
		setInterval(1, 2000 + rand() % 1000);
	case JUMPER:

		dspeed = 4;
		//	dangle = 0.8;
		radius = 20 + rand() % 20;
		tmpInterval = 200 + rand() % 1500;
		setInterval(0, tmpInterval);
		//	setFriction(false);	

		break;
	case TURRET:

		dspeed = 0;
		dangle = trigonom::minirand() * 5;
		radius = 20 + rand() % 20;
		setInterval(0, 500 + rand() % 1500);
		setInterval(2, 100);
		setMassive(false);
		setFriction(false);
		//	tmpFireType=true;
		impactMassive = 0;
		break;

	case FLY:
		dspeed = 4;
		dangle = trigonom::minirand() * 5;
		rotate = 1;
		radius = 15 + rand() % 35;
		setInterval(0, 100 + rand() % 500);
		setInterval(1, 2000 + rand() % 1000);
		setMassive(false);
		setFriction(false);

		impactMassive = 0;
		tmpFireType = 0;

		break;

	}
}

 void Enemy::setLive()
{
	set(type, x, y);

}

 void Enemy::setDeath()
{
	health = 0;
	//setInertion(0.97);
	if (!spirit)setMassive(1);
	typeOfImpact = GOOD;
}

 void Enemy::actionOnTime(int numInterval)
{




	//	if(numInterval == 3)
	//	{



	//	}


	if (health <= 0)
		return;

	if (sleeping)
		return;

	switch (type)
	{
	case ANTI_JUMPER:
	case JUMPER:
		switch (numInterval)
		{
		case 0:
			//	setInterval(0, rand()%700);
			//		move = !move;
			//		dspeed = 2+minirand() * 3;


			if (onHard)
			{

				FMove.addImpulse((2 * (goalx > x) - 1) * 2, 0);

				if (fabs(x - goalx) > radius * 3)
					FMove.addImpulse(0, (2 * (goaly > y) - 1) * (tmpInterval / 100));

				CalcDxDy();
				Move();
			}

			if (inWater)
			{

				if (goaly > y)
					FMove.addImpulse((2 * (goalx > x) - 1) * 2, 2);
				else
					FMove.addImpulse((2 * (goalx > x) - 1) * 2, -5);
				CalcDxDy();
				Move();
			}



			/*	float xx=1,gxx=1;
			float currentDistToGoal = Dist(&x,&xx,&goalx,&gxx);
			if(oldDistToGoal < currentDistToGoal)
			setInertion(0.97);
			else setInertion(1);

			oldDistToGoal = currentDistToGoal;*/
			break;

		}
		break;

	case TURRET:

		switch (numInterval)
		{
			//	case 2:
			////		angle = ugol(x,y,goalx,goaly);
			//	break;

		case 0:
			rotate = 1 - rotate;
			if (rotate == 0)
			{
				impact[impactCounter].setPos(x, y);
				/*

				impact[impactCounter].setDxDy(cos(angle*_torad)*impactSpeed,sin(angle*_torad)*impactSpeed);

				impact[impactCounter].setFriction(!impactMassive);
				impact[impactCounter].setMassive(impactMassive);
				impact[impactCounter].Move();
				impact[impactCounter].H=100;
				impactCounter++; if(impactCounter>=10) impactCounter=0;

				*/


				if (impactMassive)
					angle = trigonom::ugol(x, y, goalx, goaly + fabs(goaly - y));
				else
					angle = trigonom::ugol(x, y, goalx, goaly);

				impact[impactCounter].setPos(x, y);
				impact[impactCounter].setDxDy(cos(angle * _torad) * impactSpeed, sin(angle * _torad) * impactSpeed);

				impact[impactCounter].setFriction(!impactMassive);
				impact[impactCounter].setMassive(impactMassive);
				impact[impactCounter].Move();
				impact[impactCounter].H = 100;
				impactCounter++; if (impactCounter >= 10) impactCounter = 0;
			}
			break;

		}

		break;

	case FLY:
		switch (numInterval)
		{
		case 0:

			float currentDistToGoal = trigonom::Dist(&x, &y, &goalx, &goaly);

			if (oldDistToGoal < currentDistToGoal)
				setInertion(0.97);
			else setInertion(1);


			oldDistToGoal = currentDistToGoal;


			angle = trigonom::ugol(x, y, goalx, goaly + radius * 0.5);

			//	CalcVector();

			float vimpx = cos(angle * _torad);
			float vimpy = sin(angle * _torad);
			if ((vimpx + vimpy) <= 2)
			{
				FMove.addImpulse(vimpx * 0.5, vimpy * 0.5);
				CalcDxDy();
				Move();
			}


			moveRight = moveUp = moveDown = moveLeft = false;

			if (goalx > x) moveRight = true;
			else		moveLeft = true;

			if (goaly > y) moveUp = true;
			else		moveDown = true;


			break;

		}
		break;
	}


	if (numInterval == 1)
	{
		if (tmpFireType)
		{
			if (impactMassive)
			{
				angle = trigonom::ugol(x, y, goalx, goaly + fabs(goaly - y));

				if (goaly < y && fabs(goalx - x) < radius * 3)
					for (impactCounter = 0; impactCounter <5; impactCounter++)
					{
						impactSpeed = trigonom::minirand() * 4 - 2;
						impact[impactCounter].setPos(x, y);
						impact[impactCounter].setDxDy(cos(angle * _torad) * impactSpeed, sin(angle * _torad) * impactSpeed);

						impact[impactCounter].setFriction(!impactMassive);
						impact[impactCounter].setMassive(impactMassive);
						impact[impactCounter].Move();
						impact[impactCounter].H = 100;
					}
			}
			else
			{
				angle = trigonom::ugol(x, y, goalx, goaly);

				impact[impactCounter].setPos(x, y);
				impact[impactCounter].setDxDy(cos(angle * _torad) * impactSpeed, sin(angle * _torad) * impactSpeed);

				impact[impactCounter].setFriction(!impactMassive);
				impact[impactCounter].setMassive(impactMassive);
				impact[impactCounter].Move();
				impact[impactCounter].H = 100;
				impactCounter++; if (impactCounter >= 10) impactCounter = 0;
			}
		}

	}






}

 void Enemy::setGoal(float gx, float gy)
{

	goalx = gx;
	goaly = gy;

}

 void Enemy::Controller()
{


	/*	if(move)
	{
	if(x < goalx)
	moveRight = true;
	else
	moveLeft = true;

	if(y < goaly)
	moveUp = true;
	else
	moveDown = true;

	}
	else moveRight = moveLeft =moveDown = moveUp = false;

	if(moveUp) y+=dspeed;
	if(moveDown) y-=dspeed;
	if(moveRight) x+=dspeed;
	if(moveLeft) x-=dspeed;
	*/
	//	if(rotate == 1) angle+=dangle;


	if (health >0)
		angle = trigonom::ugol(x, y, goalx, goaly);

	if (health <= 0)
	{
		setDeath();
	}


}

 void Enemy::InvalidateView()
{
	enemyView.x = x;
	enemyView.y = y;
}
