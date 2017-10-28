#include <iostream>
#include <string>
#include <conio.h>

void AnalyseLetter ();
void AnalyseAlphabet ();
char GetUserInput ();
bool IsValidInput (const char& character);
bool IsVowel (const char& letter);
void PressKeyToContinue ();

const char ALPHABET[] {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
	'm', 'n', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

int main ()
{
	AnalyseLetter ();
	AnalyseAlphabet ();

	return 0;
}

void AnalyseLetter ()
{
	char userInput = GetUserInput ();

	if (IsVowel (userInput))
		std::cout << "That letter is a vowel!" << std::endl << std::endl;
	else
		std::cout << "That letter is a consonant!" << std::endl << std::endl;

	PressKeyToContinue ();
}

void AnalyseAlphabet ()
{
	std::cout << "Analysing Alphabet..." << std::endl << std::endl;

	for (int i = 0; i < strlen (ALPHABET); i++)
	{
		std::cout << ALPHABET[i];

		if (IsVowel (ALPHABET[i]))
			std::cout << " is a vowel" << std::endl;
		else
			std::cout << " is a consonant" << std::endl;
	}

	PressKeyToContinue ();
}

char GetUserInput ()
{
	std::cout << "Enter an alphabetical character: " << std::endl << std::endl;

	char userInput = ' ';

	std::cin >> userInput;

	if (IsValidInput (userInput))
		return userInput;

	return GetUserInput ();
}

bool IsValidInput (const char& character)
{
	if (std::cin.fail ())
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << "Please enter a valid alphabetical character!" << std::endl << std::endl;

		return false;
	}

	for (int i = 0; i < strlen (ALPHABET); i++)
		if (character == ALPHABET[i])
			return true;

	return false;
}

bool IsVowel (const char& letter)
{
	const char vowels[] {
		'a', 'e', 'i', 'o', 'u'
	};

	for (int i = 0; i < strlen (vowels); i++)
		if (letter == vowels[i])
			return true;

	return false;
}

void PressKeyToContinue ()
{
	std::cout << std::endl << "Please press any key to continue..." << std::endl << std::endl;

	_getch ();
}