#ifndef _key_h_
#define _key_h_

#include "Unit.h"

#define YELLOW  0
#define BLUE	1
#define RED		2
#define GREEN	3

class Key: public Unit
{
public:
	int NUM;
	Key ();
	
	void actionOnTime(int numInterval);

	void set(int num, float x, float y );

};

#endif
