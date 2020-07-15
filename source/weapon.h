#ifndef _weapon_h_
#define _weapon_h_


enum WeaponTypes{
 LAMP			,
 PISTOL			,
 GUN				,
 AUTOMAT			,
 GRENADE			,
 MACHINE_GUN		,
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
	void set(int type)
	{
		this->type = type;
	//	setPos(x, y);
		impactCounter = 0;
		angle = 0;
		fire = re = false;
		impactVectorX = 0;
		impactVectorY = 1;
		impactSpeed = 0;

		radius=20;
		health = 100;
		
		setInertion(0.99);


		active=true;
		switch (type)
		{

			case LAMP:	
				radius=15;
				setFriction(false);
				setMassive(true);
				setInterval(0, 50);
			break;

			case PISTOL:
				setInterval(0, 500);
				impactSpeed   = 2000;
			break;

			case GUN:
				setInterval(0, 900);
				setInterval(2, 900);
				impactSpeed   = 2000;
			break;

			case AUTOMAT:
				setInterval(0, 100);
				setInterval(1, 50);
				impactSpeed   = 2000;
			break;

			case MACHINE_GUN:
				setInterval(0, 50);
				setInterval(1, 25);
				impactSpeed   = 2000;
			break;


			case GRENADE:
				setInterval(0, 500);
				impactSpeed   = 12.5;
			break;

			case BLASTER:
				setInterval(0, 500);
				impactSpeed   = 10;
			break;

			case BOMB:
				setInterval(0, 1000);
				impactSpeed   = 6;
				setMassive(true);
			
				active=false;
				setInertion(0.98);
				radius=40;
				
			break;


		}
		
		for(int i=0;i<10; i++)
			impact[0].H = 0;
	setFriction(false);
	
		restart();
	}

	

	void startFire()
	{
	//	restart();
		fire = true;
		actionOnTime(0);
		
		for(int i=0;i<10; i++)
			impact[0].setPos(x,y);
	}
	void endFire()
	{
		fire = false;
	}

	void setImpactVector(float vx,float vy)
	{
		impactVectorX = vx;
		impactVectorY = vy;
	}


/*	float duloLength = 80;
	float ammorad = 2000;//mygish->impact[0].ammoDist;

	float dist = Dist(mygish->medium(),ToPointF(crossX,crossY));
	float k =	dist / ammorad ;
	float k2 =  dist / duloLength ;


	float ammox = mygish->medium().x + ( crossX - mygish->medium().x ) / k;
	float ammoy = mygish->medium().y + ( crossY - mygish->medium().y ) / k;

	float dulox = mygish->medium().x + ( crossX - mygish->medium().x ) / k2;
	float duloy = mygish->medium().y + ( crossY - mygish->medium().y ) / k2;
*/


	void actionOnTime(int numInterval)
	{

		if(health < 0)
			health = 0;

		if(type == LAMP  && numInterval == 0)
		{
			//if(!inWater) 
				y-=0.05;
	
		}

		if(re)
		{
			switch (type)
			{

				case GUN:
					switch(numInterval)
					{
						case 2:
							re = false; 
							break;

					}
					break;
			}

		}


		if(fire)
		{
			switch (type)
			{

				case PISTOL:
				case AUTOMAT:
				case MACHINE_GUN:				
					switch(numInterval)
					{
						case 0:
							impact[0].H = 100;
							impact[0].setPos(x,y);
							impact[1].setPos(x+impactVectorX*impactSpeed,y+impactVectorY*impactSpeed);
							break;

					}
				break;

				case GUN:

					switch(numInterval)
					{
						case 0:
							if(!re)
							{
								impact[0].H = 100;
								impact[0].setPos(x,y);
								impact[1].setPos(x+impactVectorX*impactSpeed,y+impactVectorY*impactSpeed);
								impact[2].setPos(x+impactVectorX*impactSpeed+(minirand()*500-250),y+impactVectorY*impactSpeed+(minirand()*500-250));					
								impact[3].setPos(x+impactVectorX*impactSpeed+(minirand()*500-250),y+impactVectorY*impactSpeed+(minirand()*500-250));
								impact[4].setPos(x+impactVectorX*impactSpeed+(minirand()*500-250),y+impactVectorY*impactSpeed+(minirand()*500-250));
								
								impact[5].setPos(x+impactVectorX*impactSpeed,y+impactVectorY*impactSpeed);
								impact[6].setPos(x+impactVectorX*impactSpeed+(minirand()*500-250),y+impactVectorY*impactSpeed+(minirand()*500-250));					
								impact[7].setPos(x+impactVectorX*impactSpeed+(minirand()*500-250),y+impactVectorY*impactSpeed+(minirand()*500-250));
								impact[8].setPos(x+impactVectorX*impactSpeed+(minirand()*500-250),y+impactVectorY*impactSpeed+(minirand()*500-250));
								
								for(int i=1; i<9; i++)impact[i].H = 100;


								re = true;
							}
							break;

					}
				break;
			
				case GRENADE:
				
					switch(numInterval)
					{
						case 0:
							impact[impactCounter].setPos(x,y);
						//	impact[impactCounter].setDxDy(cos(angle*_torad)*impactSpeed,sin(angle*_torad)*impactSpeed);
							impact[impactCounter].setDxDy(impactVectorX*impactSpeed,impactVectorY*impactSpeed);						
							impact[impactCounter].Move();
							impact[impactCounter].H=100;
							impactCounter++; if(impactCounter>=10) impactCounter=0;	
						break;
		
					}
				break;

			
				case BLASTER:
				
					switch(numInterval)
					{
						case 0:
							impact[impactCounter].setPos(x,y);
						//	impact[impactCounter].setDxDy(cos(angle*_torad)*impactSpeed,sin(angle*_torad)*impactSpeed);
							impact[impactCounter].setDxDy(impactVectorX*impactSpeed,impactVectorY*impactSpeed);						
							impact[impactCounter].Move();
							impact[impactCounter].H=100;
							impact[impactCounter].setMassive(false);
							impactCounter++; if(impactCounter>=10) impactCounter=0;	
						break;
		
					}
				break;


			}
		}
	}
};

#endif