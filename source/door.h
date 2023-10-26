#ifndef _door_h_
#define _door_h_

#include "primitive.h"

#define YELLOW  0
#define BLUE	1
#define RED		2
#define GREEN	3

class Door: public Primitive
{
public :
	bool isOpen;
	Door();

	void close();

	void open();

	void actionOnTime(int numInterval);
};

#endif