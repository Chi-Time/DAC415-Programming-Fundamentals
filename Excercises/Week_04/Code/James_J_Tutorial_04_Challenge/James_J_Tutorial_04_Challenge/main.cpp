#include <iostream>	// Used for basic input and output
#include <conio.h>	// Used for _getch ()
#include <random>	// Used for the mt19937 generator and uniform_int_distribution
#include <string>	// Used for manipulating and printing strings
#include <time.h>	// Used for time (0) to seed the mt19937 engine

/*------------------------OBJECTS------------------------*/

// Helper for generating pseudo random numbers.
struct RandomeGenerator
{
public:
	std::mt19937 Engine;

	RandomeGenerator ()
	{
		Engine.seed ((unsigned int)time (0));
	}

	// Returns an integer within the range of min (inclusive) and max (inclusive)
	int GetIntInRange (int min, int max)
	{
		std::uniform_int_distribution<int> unid (min, max);
		return unid (Engine);
	}
};

/*------------------------GLOBALS------------------------*/

// The choices available for the menu state.
enum MenuChoices
{
	PLAY = 1,
	RULES,
	EXIT
};

RandomeGenerator rng;

/*------------------FUNCTION-SIGNATURES------------------*/

void DisplayMenu ();
void CompareMenuChoice (const int& choice);
int GetUserChoice ();
bool IsValidChoice (const int& choice);
void ShowRules ();
void StartGame ();
int GetGuess ();
bool IsValidGuess (const int& guess);
bool GuessIsCorrect (const int& guess, const int& number);
void WinGame (const int& guesses);
void LoseGame ();

/*-----------------------FUNCTIONS-----------------------*/

// Entry point of the program.
int main ()
{
	DisplayMenu ();

	return 0;
}

void DisplayMenu ()
{
	system ("cls");

	std::cout << "Welcome to the guessing game!" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Play Game" << std::endl;
	std::cout << "2. Show Rules" << std::endl;
	std::cout << "3. Exit Game" << std::endl;
	std::cout << std::endl;

	CompareMenuChoice (GetUserChoice ());
}

void CompareMenuChoice (const int& choice)
{
	if (choice == MenuChoices::PLAY)
		StartGame ();
	else if (choice == MenuChoices::RULES)
		ShowRules ();
	else if (choice == MenuChoices::EXIT)
		return;
}

int GetUserChoice ()
{
	int choice;

	std::cin >> choice;

	if (IsValidChoice (choice))
		return choice;

	return GetUserChoice ();
}

bool IsValidChoice (const int& choice)
{
	if (std::cin.fail () || choice > 3 || choice < 1)
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << "Please choose a valid option from either 1, 2 or 3!" << std::endl;

		return false;
	}

	return true;
}

void ShowRules ()
{
	system ("cls");

	std::cout << "------------RULES OF PLAY------------" << std::endl;
	std::cout << std::endl;
	std::cout << "The aim of the game is to attempt to guess the random number the computer has chosen,";
	std::cout << std::endl << "this number will be between and including 1 - 10." << std::endl << std::endl;
	std::cout << "You will be given 10 attempts to guess the number chosen by the computer" << std::endl;
	std::cout << "each time you get a guess wrong, your attempts will be lowered." << std::endl;
	std::cout << "Lose all 10 attempts without a correct guess and you'll lose the game" << std::endl;
	std::cout << std::endl << "Each time you get a guess wrong the computer will give you a hint on how far away you were" << std::endl;
	std::cout << std::endl << "Guess the number correctly and you'll win the game!" << std::endl;
	std::cout << std::endl << "Press any key to return to menu..." << std::endl;

	_getch ();

	DisplayMenu ();
}

void StartGame ()
{
	system ("cls");
	std::cout << "------------GUESSING GAME------------" << std::endl;

	int number = rng.GetIntInRange (1, 10);
	int guesses = 10;

	bool gameOver = false;

	while (gameOver == false)
	{
		std::cout << std::endl << "You have " << guesses << " guesses left." << std::endl;

		int guess = GetGuess ();

		if (GuessIsCorrect (guess, number))
		{
			gameOver = true;
			WinGame (guesses);
		}

		guesses--;

		if (guesses <= 0)
		{
			gameOver = true;
			LoseGame ();
		}
	}
}

int GetGuess ()
{
	std::cout << "Enter your number: " << std::endl;

	int guess = 0;

	std::cin >> guess;

	if (IsValidGuess (guess))
		return guess;
	
	return GetGuess ();
}

bool IsValidGuess (const int& guess)
{
	if (std::cin.fail () || guess < 1 || guess > 10)
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << "Please enter a valid number between and including 1 - 10!" << std::endl;

		return false;
	}

	return true;
}

bool GuessIsCorrect (const int& guess, const int& number)
{
	if (guess == number)
	{
		std::cout << std::endl << "You're right!" << std::endl;
		return true;
	}
	
	std::cout << std::endl << "Nope, that's wromg." << std::endl;
	std::cout << "You're only " << abs (guess - number) << " away though!" << std::endl;
	return false;
}

void WinGame (const int& guesses)
{
	std::cout << std::endl << "Well done! You won the game and it only took you " << 10 - guesses << " guesses to do so!" << std::endl;
	std::cout << "Press enter to continue..." << std::endl;

	_getch ();

	DisplayMenu ();
}

void LoseGame ()
{
	std::cout << std::endl << "Oof... So sorry. You lost the game in all 10 guesses. Better luck next time!" << std::endl;
	std::cout << "Press any key to continue..." << std::endl;

	_getch ();

	DisplayMenu ();
}
