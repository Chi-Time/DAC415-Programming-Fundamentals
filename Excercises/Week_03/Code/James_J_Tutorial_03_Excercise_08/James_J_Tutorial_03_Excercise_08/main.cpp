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

int GetUserGuess();
bool IsValidGuess(int& guess);
void CompareGuess(int& guess, int& randomNumber);
void WinGame();
void LoseGame(int& guess, int& randomNumber);

int main()
{
	RandomGenerator rng;

	int randomNumber = rng.GetIntInRange(1, 10);
	int guess = GetUserGuess();

	CompareGuess(guess, randomNumber);

	_getch();

	return 0;
}

int GetUserGuess()
{
	std::cout << "Guess a number between 1 - 10 (1 and 10 are inclusive): " << std::endl;

	int guess = 0;

	std::cin >> guess;

	if (IsValidGuess(guess))
		return guess;

	return GetUserGuess();
}

bool IsValidGuess(int& guess)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please enter a valid number guess!" << std::endl;

		return false;
	}
	else if (guess < 1 || guess > 10)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please enter a number between and including 1 - 10" << std::endl;

		return false;
	}

	return true;
}

void CompareGuess(int& guess, int& randomNumber)
{
	if (guess == randomNumber)
		WinGame();
	else
		LoseGame(guess, randomNumber);
}

void WinGame()
{
	std::cout << std::endl << "Congratulations, you won!" << std::endl;
}

void LoseGame(int& guess, int& randomNumber)
{
	std::cout << std::endl << "Ooof, you lost!" << std::endl << "You were only " << abs(guess - randomNumber) << " away from the right number." << std::endl;
}
