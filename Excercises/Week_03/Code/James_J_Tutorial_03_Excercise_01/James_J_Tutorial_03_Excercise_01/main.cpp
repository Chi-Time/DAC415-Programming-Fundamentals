#include <iostream>
#include <conio.h>

// Container for the users input numbers.
struct UserNumbers
{
public:
	float firstNumber;
	float secondNumber;
	float thirdNumber;
};

void GetUserInput ();
bool IsValidInput ();
void PerformCalculations (const UserNumbers& userNumbers);
void PrintNumbers (const UserNumbers& userNumbers);
void PrintNumbersSum (const UserNumbers& userNumbers);
float AddNumbers (const UserNumbers& userNumbers);
void PrintNumbersAverage (const UserNumbers& usernumbers);
float GetAverage (const UserNumbers& userNumbers);

int main ()
{
	std::cout << "Please enter 3 numbers below (seperate each one with a space, or enter them one after the other): " << std::endl << std::endl;
	
	GetUserInput ();

	_getch ();

	return 0;
}

void GetUserInput ()
{
	// Struct holiding users values.
	UserNumbers userNumbers = { 0, 0, 0 };

	// Read the users values from the console.
	std::cin >> userNumbers.firstNumber >> userNumbers.secondNumber >> userNumbers.thirdNumber;

	if (IsValidInput ())
		PerformCalculations (userNumbers);	// Valid input? Continue with progam.
	else
		GetUserInput ();					// Invalid input? Re-prompt user for values.
}

bool IsValidInput ()
{
	// Parse the input.
	if (std::cin.fail ())
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << std::endl << "Please enter 3 NUMBERS only!" << std::endl;

		return false;
	}

	return true;
}

void PerformCalculations (const UserNumbers& userNumbers)
{
	PrintNumbers (userNumbers);
	PrintNumbersSum (userNumbers);
	PrintNumbersAverage (userNumbers);
}

void PrintNumbers (const UserNumbers& userNumbers)
{
	std::cout << std::endl << "Numbers in reverse order: " << std::endl;
	std::cout << userNumbers.thirdNumber << std::endl;
	std::cout << userNumbers.secondNumber << std::endl;
	std::cout << userNumbers.firstNumber << std::endl << std::endl;
}

void PrintNumbersSum (const UserNumbers& userNumbers)
{
	std::cout << "The sum of all numbers: " << std::endl;
	std::cout << userNumbers.firstNumber << " + ";
	std::cout << userNumbers.secondNumber << " + ";
	std::cout << userNumbers.thirdNumber << " = ";
	std::cout << AddNumbers (userNumbers) << std::endl << std::endl;
}

float AddNumbers (const UserNumbers& userNumbers)
{
	return userNumbers.firstNumber + userNumbers.secondNumber + userNumbers.thirdNumber;
}

void PrintNumbersAverage (const UserNumbers& userNumbers)
{
	std::cout << "Average of all numbers: " << std::endl;
	std::cout << GetAverage (userNumbers) << std::endl << std::endl;
}

float GetAverage (const UserNumbers& userNumbers)
{
	return (userNumbers.firstNumber + userNumbers.secondNumber + userNumbers.thirdNumber) / 3;
}
