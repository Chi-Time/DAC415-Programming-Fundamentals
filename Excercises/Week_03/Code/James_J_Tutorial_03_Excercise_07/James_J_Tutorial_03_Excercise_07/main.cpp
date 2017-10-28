#include <iostream>
#include <conio.h>

void GetCelsiusInput();
bool IsCelsius(float& celsius);
void ShowFahrenheit(float& celsius);
float ConvertToFahrenheit(float& celsius);

// The absolute minimum temperature defined.
const float ABSOLUTE_ZERO = -273.15f;
// The absolute maximum temperature defined.
const float MAXIMUM_TEMPERATURE = 437.12f;

int main()
{
	GetCelsiusInput();

	_getch();

	return 0;
}

void GetCelsiusInput()
{
	std::cout << std::endl << "Please enter your current temperature in celsius: " << std::endl;

	float celsius = 0;

	std::cin >> celsius;

	if (IsCelsius(celsius))
		ShowFahrenheit(celsius);
	else
		GetCelsiusInput();
}

bool IsCelsius(float& celsius)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << std::endl << "Please enter a number or decimal value for the current temperature!" << std::endl;

		return false;
	}
	else if (celsius < ABSOLUTE_ZERO)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please enter a valid temperature! That's too cold." << std::endl;

		return false;
	}
	else if (celsius > MAXIMUM_TEMPERATURE)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please enter a valid temperature! That's too hot." << std::endl;

		return false;
	}

	return true;
}

void ShowFahrenheit(float& celsius)
{
	std::cout << std::endl << "The current temperature in fahrenheit is: " << ConvertToFahrenheit(celsius) << std::endl;
}

float ConvertToFahrenheit(float& celsius)
{
	const float fractionalOffset = 1.8f;
	const float wholeOffest = 32;

	return (celsius * fractionalOffset) + wholeOffest;
}
