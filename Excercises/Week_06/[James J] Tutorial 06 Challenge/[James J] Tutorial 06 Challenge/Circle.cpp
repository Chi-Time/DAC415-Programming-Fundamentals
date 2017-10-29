#include "Circle.h"
#include <_dbdao.h>
#include <AclAPI.h>
#include <accountssettingspaneinterop.h>

Circle::Circle ()
{
}


Circle::~Circle ()
{
}

float& Circle::GetCircumference ()
{
	float c = 3.14f * (radius * radius);;
	return c;
}
