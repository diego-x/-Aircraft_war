#include "stdafx.h"
#include "CAddLife.h"


CAddLife::CAddLife()
{
}


CAddLife::~CAddLife()
{
}
CAddLife::CAddLife(int x, int y) :CGameObject(x, y)
{
}


CImageList CAddLife::m_Images;

BOOL CAddLife::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_Life, RGB(0, 0, 0), BOMB_WIDTH, BOMB_HEIGHT, 1);
}