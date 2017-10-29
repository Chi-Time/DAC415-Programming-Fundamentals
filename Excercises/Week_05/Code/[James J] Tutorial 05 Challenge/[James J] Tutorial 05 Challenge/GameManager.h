#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "Board.h"

class GameManager
{
public:
	GameManager ();
	void RunGame ();
	void TakeTurn ();
	void WaitForKeypress ();
	~GameManager ();
private:
	bool m_ShouldPlay;
	Board m_Board;
};

#endif // !GAMEMANAGER_H_INCLUDED
