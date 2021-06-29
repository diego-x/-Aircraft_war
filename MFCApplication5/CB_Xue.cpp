#include "stdafx.h"
#include "CB_Xue.h"


CB_Xue::CB_Xue()
{
}


CB_Xue::~CB_Xue()
{

}

CB_Xue::CB_Xue(int x, int y) : CGameObject(x, y)
{
	
}

CImageList CB_Xue::m_Images;
int CB_Xue::bei = 1;

BOOL CB_Xue::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_BOSSXUE, RGB(0, 0, 0), ENEMY_width, BALL_HEIGHT, 1);
}


