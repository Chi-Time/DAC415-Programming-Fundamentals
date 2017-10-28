#include <iostream>
#include <conio.h>
#include <string>

struct WarriorInfo
{
	std::string Name;
	int Health;
	float WeightKilogramms;
	int DefendRating;
	int AttackRating;

	WarriorInfo (std::string name, int health, float weight, int defense, int attack)
	{

	}
};

void WaitForKeypress ();

int main ()
{
	WaitForKeypress ();

	return 0;
}

void WaitForKeypress ()
{
	std::cout << "Press any key to continue..." << std::endl;

	_getch ();
}