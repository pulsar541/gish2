#include "fvector.h"

FVector::FVector()
{
	//
	// TODO: Add constructor logic here
	//
}

void FVector::calc_kas(float oldx, float oldy, float x, float y)
{

	x0 = x;
	y0 = y;
	//	z0=z;

	x1 = x + (x - oldx);
	y1 = y + (y - oldy);
	//z1=z+(z-oldz);

}

void FVector::calc_gravity()
{
	y1 -= gravity / SLOMO_K;
}

void FVector::calc_antigravity()
{
	y1 += gravity / SLOMO_K;
}

void FVector::calc_in_water()
{
	y1 += (gravity / SLOMO_K + gravity / SLOMO_K * 0.4f);
}

void FVector::calc_veter(float massa, float xa, float ya)
{
	x1 += gravity / SLOMO_K;
}

void FVector::add(FVector* vector)
{

}

void FVector::addImpulse(float impx, float impy)
{
	this->x1 += impx;
	this->y1 += impy;
}
