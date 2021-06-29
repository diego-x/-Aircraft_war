#include "stdafx.h"
#include "CE_Bomb.h"


CE_Bomb::CE_Bomb()
{
}

CE_Bomb::CE_Bomb(int x, int y) :CGameObject(x, y)
{
}


CE_Bomb::~CE_Bomb()
{
}

CImageList CE_Bomb::m_Images;

BOOL CE_Bomb::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_EBomb, RGB(0, 0, 0), BOMB_WIDTH, BOMB_HEIGHT, 1);
}