#include "stdafx.h"
#include "CTool.h"


CTool::CTool()
{
}


CTool::~CTool()
{
}
CTool::CTool(int x, int y) :CGameObject(x, y)
{
}


CImageList CTool::m_Images;

BOOL CTool::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_ADDbomb, RGB(0, 0, 0), BOMB_WIDTH, BOMB_HEIGHT, 1);
}
