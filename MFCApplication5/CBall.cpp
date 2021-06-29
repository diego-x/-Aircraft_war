#include "stdafx.h"
#include "CBall.h"


CBall::CBall(int x, int y, int nMontion):CGameObject(x,y)
{
}


CBall::~CBall()
{
}

CImageList CBall::m_Images;

BOOL CBall::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_BALL, RGB(0, 0, 0), BALL_HEIGHT, BALL_HEIGHT, 1);
}