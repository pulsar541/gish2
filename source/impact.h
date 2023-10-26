#ifndef _impact_h_
#define _impact_h_


#include "unit.h"

enum ImpactType 
{BALL,
 LINE,
 _MAX_IMPACT_TYPE_
};
 
class Impact: public Unit
{
public:
	float H;
	int type;
	float ammoDist; 
	Impact();

	void set(int type); 
	 
    void actionOnTime(int numAction);

};

#endif