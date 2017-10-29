#include <iostream>
#include <string>
#include <conio.h>
#include "MenuManager.h"

void WaitForKeypress ();

int main ()
{
	MenuManager mm = MenuManager ();

	WaitForKeypress ();

	return 0;
}

void WaitForKeypress ()
{
	std::cout << "Press any key to continue..." << std::endl;

	_getch ();
}
