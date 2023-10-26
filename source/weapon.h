#ifndef _weapon_h_
#define _weapon_h_

#include "impact.h"

enum WeaponTypes{
 //LAMP			,
 //PISTOL			,
 //GUN				,
 //AUTOMAT			,
 GRENADE			,
 //MACHINE_GUN		,
 BLASTER			,
 ROCKET_LAUNCHER ,
 SUPER_WEAPON	,
 BOMB,
 DETONATOR,
 MAXWEAPONTYPES	
};

class Weapon: public Unit
{
public:
	Impact impact[10];
	int impactCounter;
	int type;
	float angle;
	bool fire,re;
	float impactSpeed;
	float impactVectorX,impactVectorY;
	float health;
	bool active;

	Weapon();

	void set(int type);

	

	void startFire();
	void endFire();

	void setImpactVector(float vx,float vy);


/*	float duloLength = 80;
	float ammorad = 2000;//mygish->impact[0].ammoDist;

	float dist = Dist(mygish->medium(),PointF(crossX,crossY));
	float k =	dist / ammorad ;
	float k2 =  dist / duloLength ;


	float ammox = mygish->medium().x + ( crossX - mygish->medium().x ) / k;
	float ammoy = mygish->medium().y + ( crossY - mygish->medium().y ) / k;

	float dulox = mygish->medium().x + ( crossX - mygish->medium().x ) / k2;
	float duloy = mygish->medium().y + ( crossY - mygish->medium().y ) / k2;
*/


	void actionOnTime(int numInterval);
};

#endif