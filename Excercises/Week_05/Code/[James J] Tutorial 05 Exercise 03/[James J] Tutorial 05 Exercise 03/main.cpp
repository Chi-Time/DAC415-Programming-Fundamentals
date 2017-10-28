#include <iostream>
#include <string>
#include <conio.h>
#include <ctype.h>

int main ()
{
	bool shouldRun = true;

	while (shouldRun)
	{
		char character = GetUserInput ();

		if (IsNumber (character))
			PrintNumber (character);
		else if (IsLetter (character))
			PrintLetter (character);
		else
			PrintSymbol (character);
	}

	_getch ();

	return 0;
}

char GetUserInput ()
{
	std::cout << "Please enter a character to process: " << std::endl << std::endl;

	char userInput = ' ';

	std::cin >> userInput;

	if (IsValid ())
		return userInput;
}

bool IsValid ()
{
	if (std::cin.fail ())
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << "Please input a valid character: " << std::endl;

		return false;
	}

	return true;
}

bool IsNumber (const char& character)
{
	if (isdigit (character))
		return true;

	return false;
}

bool IsLetter (const char& character)
{
	char symbols[] {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'lL', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	for (int i = 0; i < strlen (symbols); i++)
		if (character == symbols[i])
			return true;

	return false;
}

void PrintNumber (const char& character)
{

}

void PrintLetter (const char& character)
{

}

void PrintSymbol (const char& character)
{

}
