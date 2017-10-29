#include <iostream>
#include <conio.h>
#include "Board.h"
#include "GameManager.h"




GameManager::GameManager ()
{
	m_Board = Board ();
	m_ShouldPlay = true;
	RunGame ();
}

void GameManager::RunGame ()
{
	while (m_ShouldPlay)
	{
		m_Board.DrawBoard ();
		TakeTurn ();
		WaitForKeypress ();
	}
}

void GameManager::TakeTurn ()
{

}

void GameManager::WaitForKeypress ()
{
	std::cout << "Press any key to continue..." << std::endl;

	_getch ();
}

GameManager::~GameManager ()
{
}
