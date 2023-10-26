#include "Key.h"

Key::Key() {}

void Key::actionOnTime(int numInterval)
{
}

void Key::set(int num, float x, float y)
{
	NUM = num;
	radius = 20;
	setPos(x, y);
	setCorrect();

}
