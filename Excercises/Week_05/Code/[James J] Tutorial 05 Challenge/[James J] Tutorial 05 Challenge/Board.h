#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

class Board
{
public:
	Board ();
	void DrawBoard ();
	void SetBoardPosition (int position, char tile);
	~Board ();

private:
	std::vector<char> m_Grid;
};

#endif // !BOARD_H_INCLUDED
