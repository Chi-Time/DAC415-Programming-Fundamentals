#include <iostream>
#include <conio.h>

const int HIGH_SCORE = 500;

void DisplayMenu ();
void StartCalculator ();
int GetUserScore ();
bool IsValidScore ();
void CompareScore (const int& firstScore, const int& secondScore);
void CompareHighScore (const int& score);

int main ()
{
	DisplayMenu ();
	StartCalculator ();

	_getch ();

	return 0;
}

void DisplayMenu ()
{
	std::cout << "Welcome to the high score calculator!" << std::endl << std::endl;
}

void StartCalculator ()
{
	std::cout << "Please enter the first user's score: " << std::endl;
	int firstUserScore = GetUserScore ();

	std::cout << "Please enter the second user's score: " << std::endl;
	int secondUserScore = GetUserScore ();

	CompareScore (firstUserScore, secondUserScore);
}

int GetUserScore ()
{
	int score = 0;

	std::cin >> score;

	if (IsValidScore ())
		return score;
	
	return GetUserScore ();
}

bool IsValidScore ()
{
	if (std::cin.fail ())
	{
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');

		std::cout << std::endl << "Please enter a valid numerical score!" << std::endl;

		return false;
	}

	return true;
}

void CompareScore (const int& firstScore, const int& secondScore)
{
	if (firstScore > secondScore)
	{
		std::cout << std::endl << "First player has a higher score!" << std::endl;
		std::cout << "By almost " << abs (firstScore - secondScore) << " points!" << std::endl;

		CompareHighScore (firstScore);
	}
	else if (secondScore > firstScore)
	{
		std::cout << std::endl << "Second player has a higher score!" << std::endl;
		std::cout << "By almost " << abs (secondScore - firstScore) << " points!" << std::endl;

		CompareHighScore (secondScore);
	}
}

void CompareHighScore (const int& score)
{
	if (score > HIGH_SCORE)
	{
		std::cout << std::endl << "WOW, they also beat the high score!" << std::endl;
		std::cout << "By a whopping " << abs (score - HIGH_SCORE) << " points" << std::endl;
	}
	else if (HIGH_SCORE > score)
	{
		std::cout << std::endl << "Oof... They didn't beat the high score though." << std::endl;
		std::cout << "They're just shy of it by " << abs (HIGH_SCORE - score) << " points" << std::endl;
	}
}
