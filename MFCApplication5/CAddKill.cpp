#include "stdafx.h"
#include "CAddKill.h"


CAddKill::CAddKill()
{
}


CAddKill::~CAddKill()
{
}
CAddKill::CAddKill(int x, int y) :CGameObject(x, y)
{
}


CImageList CAddKill::m_Images;

BOOL CAddKill::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_ADDKILL, RGB(0, 0, 0), BOMB_WIDTH, BOMB_HEIGHT, 1);
}