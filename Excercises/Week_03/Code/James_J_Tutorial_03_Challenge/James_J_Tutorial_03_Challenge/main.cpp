#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

struct RandomGenerator
{
public:
	std::mt19937 Engine;

	RandomGenerator()
	{
		Engine.seed((unsigned int)time(0));
	}

	int GetIntInRange(int min, int max)
	{
		std::uniform_int_distribution<int> unid(min, max);

		return unid(Engine);
	}
};

RandomGenerator rng;

void StartEngine();
void DisplayMenu();
int GetMenuChoice();
bool IsValidChoice(int& choice);
void SelectChoice(int& choice);
void PerformDieRoll();
void PerformDiceRoll();
int GetDieSize();
bool IsValidSize();
int GetDiceRollResult(int& dieSize);
int GetDiceRollResult(int& firstDieSize, int secondDieSize);

int main()
{
	StartEngine();

	std::cout << std::endl << "Press enter to exit..." << std::endl;

	_getch();

	return 0;
}

void StartEngine()
{
	DisplayMenu();

	int choice = GetMenuChoice();

	SelectChoice(choice);
}

void DisplayMenu()
{
	std::cout << "Welcome to the dice roll engine! Please a select an option from below" << std::endl;

	std::cout << "1. One die roll" << std::endl;
	std::cout << "2. Two dice roll" << std::endl;
	std::cout << "3. Exit progam" << std::endl;
}

int GetMenuChoice()
{
	int choice = 0;

	std::cin >> choice;

	if (IsValidChoice(choice))
		return choice;

	return GetMenuChoice ();
}

bool IsValidChoice(int& choice)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please enter a valid number choice!" << std::endl;

		return false;
	}
	else if (choice > 3 || choice < 0)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please select either 1, 2 or 3!" << std::endl;

		return false;
	}

	return true;
}

void SelectChoice(int& choice)
{
	switch (choice)
	{
	case 1:
		PerformDieRoll();
		break;
	case 2:
		PerformDiceRoll();
		break;
	case 3:
		return;
	}
}

void PerformDieRoll()
{
	std::cout << "Please enter the size of the die you wish to roll: " << std::endl;
	int dieSize = GetDieSize();

	std::cout << std::endl << "Rolling..." << std::endl;

	int rollResult = GetDiceRollResult(dieSize);

	std::cout << std::endl << "You rolled a " << rollResult << "!" << std::endl;
}

void PerformDiceRoll()
{
	std::cout << "Please enter the size of the first die you wish to roll: " << std::endl;
	int firstDieSize = GetDieSize();

	std::cout << "Please enter the size of the second die you wish to roll: " << std::endl;
	int secondDieSize = GetDieSize();

	std::cout << std::endl << "Rolling..." << std::endl;

	int rollResult = GetDiceRollResult(firstDieSize, secondDieSize);

	std::cout << std::endl << "You rolled a " << rollResult << "!" << std::endl;
}

int GetDieSize ()
{
	int size = 0;

	std::cin >> size;

	if (IsValidSize())
		return size;

	return GetDieSize();
}

bool IsValidSize()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please enter a valid number choice for the die size!" << std::endl;

		return false;
	}

	return true;
}

int GetDiceRollResult(int& dieSize)
{
	return rng.GetIntInRange(1, dieSize);
}

int GetDiceRollResult(int& firstDieSize, int secondDieSize)
{
	return rng.GetIntInRange(1, firstDieSize) + rng.GetIntInRange(1, secondDieSize);
}
