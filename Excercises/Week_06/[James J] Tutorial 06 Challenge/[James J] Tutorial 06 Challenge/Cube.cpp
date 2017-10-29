#include <iostream>
#include "Vector3D.h"
#include "Cube.h"




Cube::Cube ()
{
	Size = 1.0f;
	Position.SetProperties ();
	SetPoints ();
}

Cube::Cube (float size)
{
	Size = size;
	Position.SetProperties ();
	SetPoints ();	
}

void Cube::MoveCube (Vector3D direction)
{
	Position.X += direction.X;
	Position.Y += direction.Y;
	Position.Z += direction.Z;

	SetPoints ();
}

Cube::~Cube ()
{
}

Vector3D Cube::GetCentre ()
{
	Centre = Vector3D (Size / 2 + Position.X, Size / 2 + Position.Y, Size / 2 + Position.Z);

	return Centre;
}

Vector3D Cube::GetPosition ()
{
	return Position;
}

void Cube::DisplayCentre ()
{
	std::cout << "----Cube's Centre----" << std::endl;
	GetCentre ().DisplayProperties ();
	std::cout << "---------------------" << std::endl;
}

void Cube::DisplayCube ()
{
	std::cout << "----Cube's Points----" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "Point: " << i + 1 << std::endl;
		Vertices[i].DisplayProperties ();
	}

	std::cout << "---------------------" << std::endl;
}

void Cube::DisplayPosition ()
{
	std::cout << "----Cube's Position----" << std::endl;
	GetPosition ().DisplayProperties ();
	std::cout << "-----------------------" << std::endl;
}

void Cube::SetPoints ()
{
	GetCentre ();

	// Top of cube. \\
	// BL
	Vertices[0] = Vector3D (Centre.X - Centre.X, Centre.Y + Centre.Y, Centre.Z - Centre.Z);
	// FL
	Vertices[1] = Vector3D (Centre.X - Centre.X, Centre.Y + Centre.Y, Centre.Z + Centre.Z);
	// FR
	Vertices[2] = Vector3D (Centre.X + Centre.X, Centre.Y + Centre.Y, Centre.Z + Centre.Z);
	// BR
	Vertices[3] = Vector3D (Centre.X + Centre.X, Centre.Y + Centre.Y, Centre.Z - Centre.Z);

	// Bottom of cube. \\
	// BL
	Vertices[4] = Vector3D (Centre.X - Centre.X, Centre.Y - Centre.Y, Centre.Z - Centre.Z);
	// FL
	Vertices[5] = Vector3D (Centre.X - Centre.X, Centre.Y - Centre.Y, Centre.Z + Centre.Z);
	// FR
	Vertices[6] = Vector3D (Centre.X + Centre.X, Centre.Y - Centre.Y, Centre.Z + Centre.Z);
	// BR
	Vertices[7] = Vector3D (Centre.X + Centre.X, Centre.Y - Centre.Y, Centre.Z - Centre.Z);
}
