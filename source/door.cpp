#include "door.h"

Door::Door()
{
	isOpen = false;
	setInterval(0, 10);
}

void Door::close()
{
	isOpen = false;
}

void Door::open()
{
	isOpen = true;
}

void Door::actionOnTime(int numInterval)
{
	switch (numInterval)
	{
	case 0:
		if (isOpen)
		{
			if (A.y < C.y - 10)
				A.y += 10;
			setPos(A, B, C);
			//	MessageBox(NULL,"rty","ty3",MB_OK);
		}

		//	

		break;
	}
}
