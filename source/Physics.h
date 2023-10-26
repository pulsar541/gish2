#pragma once
 
#include <vector>
#include "unit.h" 
#include "primitive.h"

using namespace std;

class Physics
{ 

//	vector<Unit*> units;
//	vector<Unit*>		::iterator pUnit;
//	vector<Unit*>		::iterator pUnitSec;

public:

	Physics()
	{

	}

	~Physics()
	{

	}

	void Add(Unit* u);

	void Update();

	bool  Proch(Unit* u1, Unit* u2, float dist);


	bool  ProchUnitOne(Unit* u1, Unit* u2, float dist);
	void  ProchM(Unit* b1, Unit* b2, float dist, int k);


	bool  Proch(Unit* b1, PointF* p, float dist);




	void SVIAZKA(Unit* u1, Unit* u2, float dist, int K);


	void S_VIAZKA(Unit* u1, Unit* u2, float dist, int K);

	void SVIAZKA_UnitOne(Unit* u1, Unit* u2, float dist, int K);

	void TROS(Unit** u, int n1, int n2, float dist, int k);



	void TROS(vector<Unit>* ball, float dist, int k);



	void PROCH(Unit* u1, Unit* u2, float dist, int K);


	void  Proch(Unit* b, MyLine* line);

	int  Collision(Unit* u, Primitive* primitive);



};

 