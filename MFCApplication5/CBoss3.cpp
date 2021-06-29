#include "stdafx.h"
#include "CBoss3.h"


CBoss_2::CBoss_2() :CGameObject(500, 100)
{
	m_V = 1;
	life = 4000;
}


CBoss_2::~CBoss_2()
{
}

CBoss_2::CBoss_2(int x, int y, int m_nMotion) : CGameObject(x, y), m_V(rand() % 3), m_nImgIndex(0), m_nMotion(m_nMotion)
{
	life = 300;
}

CImageList CBoss_2::m_Images;


BOOL CBoss_2::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_BOSS222, RGB(0, 0, 0), ENEMY_width, ENEMY_HEIGHT, 1);
}
