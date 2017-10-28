#include <iostream>
#include <conio.h>
#include <string>

struct Vector2D 
{
public:
	float X;
	float Y;

	Vector2D (float x, float y)
	{
		X = x;
		Y = y;
	}

	void ClearProperties ()
	{
		X = 0.0f;
		Y = 0.0f;
	}
};

void GetUserData ();
void PressKeyToContinue ();

int main ()
{
	GetUserData ();

	return 0;
}

void GetUserData ()
{
	Vector2D vector = Vector2D (0.0f, 0.0f);

	while (true)
	{
		std::cout << "Please enter a value for the x component: " << std::endl;
		std::cin >> vector.X;
		std::cout << std::endl;
		std::cout << "Please enter a value for the x component: " << std::endl;
		std::cin >> vector.Y;
		std::cout << std::endl;

		std::cout << "Your vector's components are: " << std::endl << "X: " << vector.X << " Y: " << vector.Y << std::endl;

		PressKeyToContinue ();

		vector.ClearProperties ();
	}
}

void PressKeyToContinue ()
{
	std::cout << std::endl << "Press any key to continue..." << std::endl << std::endl;

	_getch ();
}