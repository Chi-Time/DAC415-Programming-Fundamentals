#include <iostream>
#include <conio.h>
#include "GameManager.h"
#include "MenuManager.h"




MenuManager::MenuManager ()
{
	std::cout << "Welcome to the tic-tac-toe game!" << std::endl;
	std::cout << "In this game a computer AI will take a series of turns against itself" << std::endl;
	std::cout << std::endl;

	WaitForKeypress ();

	GameManager gm = GameManager ();
}

void MenuManager::WaitForKeypress ()
{
	std::cout << "Press any key to continue..." << std::endl;

	_getch ();
}

MenuManager::~MenuManager ()
{
}
