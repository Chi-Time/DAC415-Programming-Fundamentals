#include <iostream>
#include <conio.h>
#include <string>
#include <locale>

std::string ToLower (std::string input);

int main ()
{
	bool shouldLoop = true;

	while (shouldLoop)
	{
		std::cout << "If you wish to quit, simply type the word quit below: " << std::endl;

		std::string userInput = "";
		std::cin >> userInput;

		if (ToLower (userInput) == "quit")
		{
			shouldLoop = false;
			break;
		}

		system ("cls");
	}

	std::cout << std::endl << std::endl << "Please press any key to exit..." << std::endl;

	_getch ();

	return 0;
}

std::string ToLower (std::string input)
{
	std::locale locale;
	std::string lowercaseChoice = "";

	for (int i = 0; i < input.length (); i++)
		lowercaseChoice += std::tolower (input[i], locale);

	return lowercaseChoice;
}
