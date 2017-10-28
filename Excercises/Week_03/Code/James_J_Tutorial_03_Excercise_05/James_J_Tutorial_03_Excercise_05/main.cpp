#include <iostream>
#include <conio.h>
#include <string>

/*--------Objects--------*/
struct Birthday
{
	int day;
	int month;
	int year;
};

struct UserInfo
{
	std::string firstName;
	std::string lastName;
	Birthday birthDay;
};

/*--------Function Signatures--------*/
void GetUserInformation();
void GetUserName(UserInfo& user);
void GetUserBirthday(UserInfo& user);
bool IsValidInput(const UserInfo& user);
void PrintUsersName(const UserInfo& userName);
void PrintUserInformation(const UserInfo& user);

/*--------Functions--------*/
int main()
{
	GetUserInformation();

	_getch();

	return 0;
}

void GetUserInformation ()
{
	UserInfo user = { "", "", {0, 0, 0} };
	
	GetUserName(user);
	
	GetUserBirthday(user);
}

void GetUserName(UserInfo& user)
{
	std::cout << std::endl << "Please enter your first and last name below: " << std::endl;

	std::cin >> user.firstName >> user.lastName;

	PrintUsersName(user);
}

void GetUserBirthday(UserInfo& user)
{
	std::cout << std::endl << "Please enter your date of birth: (format: day month year) " << std::endl;

	std::cin >> user.birthDay.day >> user.birthDay.month >> user.birthDay.year;

	if (IsValidInput(user))
		PrintUserInformation(user);
	else
		GetUserBirthday(user);
}

bool IsValidInput(const UserInfo& user)
{
	// Parse the input.
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl << "Please enter 3 NUMBERS, with spaces between each or on each line only!" << std::endl;

		return false;
	}
	else if (user.birthDay.day > 31 || user.birthDay.day < 0)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Please enter a valid day!" << std::endl;

		return false;
	}
	else if (user.birthDay.month < 0 || user.birthDay.day > 12)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Please enter a valid month!" << std::endl;

		return false;
	}
	else if (user.birthDay.year < 1901 || user.birthDay.year > 2016)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Please enter a valid year!" << std::endl;

		return false;
	}

	return true;
}

void PrintUsersName(const UserInfo& user)
{
	std::cout << std::endl << "Printing Name: " << std::endl << std::endl;
	std::cout << user.firstName << " " << user.lastName << std::endl;
	std::cout << user.lastName << ", " << user.firstName << std::endl;
	std::cout << user.lastName << ", " << user.firstName[0] << std::endl;
}

void PrintUserInformation(const UserInfo& user)
{
	std::cout << std::endl << "User Information: " << std::endl << std::endl;
	std::cout << "User Name: " << user.lastName << ", " << user.firstName << std::endl;
	std::cout << "DOB: " << user.birthDay.day << "/" << user.birthDay.month << "/" << user.birthDay.year;
}
