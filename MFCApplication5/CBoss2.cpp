#include "stdafx.h"
#include "CBoss2.h"


CBoss2::CBoss2() :CGameObject(500, 0)
{
	//m_V = 1;
	life = 2000;
}


CBoss2::~CBoss2()
{
}

CBoss2::CBoss2(int x, int y, int m_nMotion) : CGameObject(x, y), m_V(rand() % 3), m_nImgIndex(0), m_nMotion(m_nMotion)
{
	life = 300;
}

CImageList CBoss2::m_Images;


BOOL CBoss2::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_BOSS11, RGB(0, 0, 0), ENEMY_width, ENEMY_HEIGHT, 1);
}
