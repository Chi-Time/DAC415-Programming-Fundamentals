#include <iostream>
#include <conio.h>
#include <string>

void StartProgram ();
void DisplayMenu ();
int GetNumberFromUser ();
bool IsValidInput (int& countdown);
void StartCountdown (const int& countdown);
void StartCountdownNoEvenNumbers (const int& countdown);
void StartCountdownLiteral (const int& countdown);
std::string GetNameFromNumber (const int& number);

int main ()
{
	StartProgram ();

	_getch ();
	
	return 0;
}

void StartProgram ()
{
	DisplayMenu ();

	int countdown = GetNumberFromUser ();
	
	StartCountdown (countdown);

	_getch ();

	StartCountdownNoEvenNumbers (countdown);

	_getch ();

	StartCountdownLiteral (countdown);
}

void DisplayMenu ()
{
	std::cout << "Countdown Machine" << std::endl << std::endl;
}

int GetNumberFromUser ()
{
	std::cout << "Please enter a postive number to countdown from: " << std::endl;

	int countdown = 0;

	std::cin >> countdown;

	if (IsValidInput (countdown))
		return countdown;

	return GetNumberFromUser ();
}

bool IsValidInput (int& countdown)
{
	if (std::cin.fail () || countdown < 0)
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << std::endl << "Please enter a valid positive number" << std::endl;

		return false;
	}

	return true;
}

void StartCountdown (const int& countdown)
{
	system ("cls");

	for (int i = countdown; i > 0; i--)
	{
		if (i == 1)
		{
			std::cout << "FIRE!" << std::endl;
			break;
		}

		std::cout << i << std::endl;
	}
}

void StartCountdownNoEvenNumbers (const int& countdown)
{
	system ("cls");

	for (int i = countdown; i > 0; i--)
	{
		if (i % 2 == 0)
			continue;

		if (i == 1)
		{
			std::cout << "FIRE!" << std::endl;
			break;
		}

		std::cout << i << std::endl;
	}
}

void StartCountdownLiteral (const int& countdown)
{
	system ("cls");

	for (int i = countdown; i >= 1; i--)
		std::cout << GetNameFromNumber (i) << std::endl;
}

std::string GetNameFromNumber (const int& number)
{
	switch (number)
	{
	case 5:
		return "Five";
	case 4:
		return "Four";
	case 3:
		return "Three";
	case 2:
		return "Two";
	case 1:
		return "FIRE!";
	default:
		return std::to_string (number);
	}
}
