#include <iostream>
#include <string>
#include "Board.h"




Board::Board ()
{
	m_Grid.resize (9);
}

void Board::DrawBoard ()
{
	system ("cls");

	std::cout << m_Grid[0] << "|" << m_Grid[1] << "|" << m_Grid[2] << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << m_Grid[3] << "|" << m_Grid[4] << "|" << m_Grid[5] << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << m_Grid[6] << "|" << m_Grid[7] << "|" << m_Grid[8] << std::endl;
	std::cout << std::endl;
}

void Board::SetBoardPosition (int position, char tile)
{
	if (position > 7)
		return;

	m_Grid[position] = tile;
}

Board::~Board ()
{
}
