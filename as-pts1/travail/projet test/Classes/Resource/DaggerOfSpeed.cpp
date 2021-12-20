
/* Generated from GenMyModel */

#include "../Header/DaggerOfSpeed.hpp"


DaggerOfSpeed::DaggerOfSpeed(int camp)
{
	estEnnemie = camp;
	/* speed of object 100 is slow- 300 is fast */
	_attackSpeed = 650.0f;
	/* duration in seconds 0.05 is very short */
	_attackDuration = 5.0f;
	/* speed to attack again */
	_projectileCooldown = 1.0f;
	

}