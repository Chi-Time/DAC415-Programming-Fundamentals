#include <iostream>
#include <conio.h>

// Get's an integer input fromthe user.
int& GetUserInput ();
// Ensures the input given by the user is a valid integer.
bool IsValid (const int& number);
// Compares if the number is odd or even and increments the counters respectively.
void CheckNumber (const int& number, unsigned int& evenCount, unsigned int& oddCount);

int main ()
{
	bool shouldRun = true;

	unsigned int evenCount = 0;
	unsigned int oddCount = 0;

	while (shouldRun)
	{
		std::cout << "Please input a number:" << std::endl << std::endl;

		int userNumber = GetUserInput ();
		CheckNumber (userNumber, evenCount, oddCount);

		std::cout << "Even count is: " << evenCount << std::endl << "Odd count is: " << oddCount << std::endl;
		std::cout << "Press any key to continue..." << std::endl;

		_getch ();

		system ("cls");
	}

	_getch ();

	return 0;
}

int& GetUserInput ()
{
	int number = 0;

	std::cin >> number;

	if (IsValid (number))
		return number;

	return GetUserInput ();
}

bool IsValid (const int& number)
{
	if (std::cin.fail ())
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << std::endl << "Please input a valid number!" << std::endl << std::endl;

		return false;
	}

	return true;
}

void CheckNumber (const int& number, unsigned int& evenCount, unsigned int& oddCount)
{
	if (number % 2 == 0)
	{
		evenCount++;
		std::cout << std::endl << "It's an even number!" << std::endl << std::endl;
	}
	else
	{
		oddCount++;
		std::cout << std::endl << "It's an odd number!" << std::endl << std::endl;
	}
}
