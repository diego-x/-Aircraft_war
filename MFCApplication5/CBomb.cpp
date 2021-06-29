#include "stdafx.h"
#include "CBomb.h"


CBomb::CBomb()
{
}

CBomb::CBomb(int x, int y):CGameObject(x, y)
{
}


CBomb::~CBomb()
{
}

CImageList CBomb::m_Images;

BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_BITMAP3, RGB(0, 0, 0), BOMB_WIDTH, BOMB_HEIGHT, 1);
}
