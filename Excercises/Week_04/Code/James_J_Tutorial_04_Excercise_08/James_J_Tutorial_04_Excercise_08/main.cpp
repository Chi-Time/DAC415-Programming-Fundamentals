#include <iostream>
#include <conio.h>
#include <string>
#include <locale>
#include <vector>

void DisplayMenu ();
void Entry ();
std::string GetWord ();
std::vector<std::string> SplitString (std::string line, char delimiter);
bool IsPalindrome (std::string word);
std::string ToLower (std::string string);

int main ()
{
	DisplayMenu ();
	Entry ();

	std::cout << std::endl << "Press ENTER to exit..." << std::endl;

	_getch ();
	return 0;
}

void DisplayMenu ()
{
	std::cout << "Welcome to the palindrome checker! ";
	std::cout << "Type the words you wish to check. If you want to stop, simply type the word exit." << std::endl;
}

void Entry ()
{
	bool loop = true;

	while (loop)
	{
		std::string word = GetWord ();
		std::vector<std::string> words = SplitString (word, ' ');

		for (int i = 0; i < words.size (); i++)
		{
			if (word == "exit")
			{
				loop = false;
				break;
			}

			if (IsPalindrome (words[i]))
				std::cout << std::endl << words[i] << ": is a palindrome" << std::endl;
			else
				std::cout << std::endl << words[i] << ": is not a palindrome" << std::endl;
		}
	}
}

std::string GetWord ()
{
	std::cout << std::endl << std::endl << "Enter a word or sentence: " << std::endl;

	std::string word = "";

	std::getline (std::cin, word);

	return ToLower (word);
}

std::vector<std::string> SplitString (std::string line, char delimiter)
{
	// Find out how many words there are in the string by counting the delimters
	int size = 1;

	for (unsigned int i = 0; i < line.length (); i++)
		if (line[i] == delimiter)
			size++;

	// Declare the list of words and give it a size.
	std::vector<std::string> words;
	// Temporary variable to get each word out of the line.
	std::string word = "";

	// Loop through the line.
	for (unsigned int i = 0; i < line.length (); i++)
	{
		// If we're at a space
		if (line[i] == delimiter)
		{
			// Add a word to the list and reset our temporary word variable for the next one.
			words.push_back (word);
			word = "";
			continue;
		}

		// If there's not a space add the character to the current word.
		word += line[i];
	}

	// There's still a word left over?
	//if (word != "")
		// Add the final word to the list.
		words.push_back (word);

	// DEBUG: Checks the words contained inside the list.
	//for (unsigned int i = 0; i < words.size (); i++)
	//	std::cout << words[i] << std::endl;

	// Return the split string.
	return words;
}

bool IsPalindrome (std::string word)
{
	/*If the word is an even amount of characters or only 1 character
	it can't be a palindrome and we don't have to bother checking.*/
	if (word.length () % 2 == 0 || word.length () == 1)
		return false;

	std::string fwdCharacter = "";
	std::string revCharacter = "";

	for (unsigned int i = 1; i < word.length (); i++)
	{
		// Get each character of the word forwards
		fwdCharacter = word.at (i - 1);
		// Get each character of the word backwards
		revCharacter = word.at (word.length () - i);

		/* If both the forward and reverse characters are not the same
		then it isn't a palindrome and we can exit.*/
		if (fwdCharacter != revCharacter)
			return false;
	}

	// The loop finished with no breaks meaning the word is a palindrome.
	return true;
}

std::string ToLower (std::string string)
{
	std::locale locale;
	std::string lowercaseChoice = "";

	for (char elem : string)
		lowercaseChoice += std::tolower (elem, locale);

	return lowercaseChoice;
}
