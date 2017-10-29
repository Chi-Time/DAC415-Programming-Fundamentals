#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <conio.h>
#include "Vector3D.h"
#include "Cube.h"

struct RandomGenerator
{
	std::mt19937 Engine;

	RandomGenerator ()
	{
		Engine.seed ((unsigned int)time (0));
	}

	int Range (int min, int max)
	{
		std::uniform_int_distribution<int> unid (min, max);

		return unid (Engine);
	}
};

void WaitForKeypress ();

 int main ()
{
	RandomGenerator rng = RandomGenerator ();
	Vector3D vector = Vector3D (12, 20, 4);

	vector.DisplayProperties ();

	vector.SetProperties ();

	vector.DisplayProperties ();

	Cube cube = Cube (rng.Range (1.0f, 10.0f));

	cube.DisplayPosition ();
	cube.DisplayCentre ();
	cube.DisplayCube ();

	cube.MoveCube (Vector3D (rng.Range (1, 10), rng.Range (1, 10), rng.Range (1, 10)));

	cube.DisplayPosition ();
	cube.DisplayCentre ();
	cube.DisplayCube ();
	

	WaitForKeypress ();

	return 0;
}

void WaitForKeypress ()
{
	std::cout << "Press any key to continue..." << std::endl;

	_getch ();
}
