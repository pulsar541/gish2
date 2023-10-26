#ifndef _enemy_h_
#define _enemy_h_

#include "enemyView.h"
#include "impact.h"

enum EnemyType 
{JUMPER,
 ANTI_JUMPER,
 TURRET,
 FLY,
 _MAX_ENEMY_TYPE_
};

class Enemy: public Unit
{

	
public:

	int type;
	float dspeed;

	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;
	bool move;
	short rotate;
	float angle;
	float dangle;
	bool ACTUAL;
	Impact impact[10];
	int impactCounter;
	EnemyView enemyView;
	float goalx,goaly;
	float health,maxHealth;
	float impactSpeed;
	bool impactMassive;
	int tmpInterval;
	int respawnInterval;

	bool tmpFireType;
	float oldDistToGoal;

	PointF startPosition;

	bool sleeping;
	Enemy();

	void set(int type,float x, float y);

	void setType(int type);
	void setLive();

	void setDeath();

	void actionOnTime(int numInterval);

	void setGoal(float gx,float gy);

	void Controller();

	void InvalidateView();


};


#endif