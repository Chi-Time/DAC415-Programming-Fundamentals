#include <iostream>
#include "Vector3D.h"


Vector3D::Vector3D ()
{
	X = 0.0f;
	Y = 0.0f;
	Z = 0.0f;
}

Vector3D::Vector3D (float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

void Vector3D::SetProperties (float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

void Vector3D::DisplayProperties ()
{
	std::cout << "X: " << X << " Y: " << Y << " Z: " << Z << std::endl << std::endl;
}

Vector3D::~Vector3D ()
{
}
