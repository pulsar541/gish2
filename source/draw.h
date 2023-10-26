#pragma once


#include "MyGish.h"
#include "Enemy.h"
#include "Door.h"
#include "Key.h"
#include "Item.h"


	 
class draw
{


	public:

	float  commonColor[4]; // = { .5, .6, .5 };
  

	void SetDif(float r,float g ,float b); 

	void ShowGish(MyGish *mygish); 

	void ShowEnemy(Enemy *enemy); 

	void ShowEnemyImpacts(Enemy *enemy);

	void ShowField();

	void ShowField2(); 

	void ShowLimit(); 

	void ShowDoor(Door *door);

	void ShowKey(Key *key);

	void ShowPrimitive(Primitive *primitive);

	void ShowCheckPoint(PointF *checkPoint); 

	void ShowExit(PointF *exitPoint);

	void ShowImpactLine(MyGish *mygish, float crossX, float crossY);

	void ShowWeaponWithImpacts(Weapon *weapon);

	void ShowItem(Item *item);  

	void spisok();  

	void displayFunc();  
};



