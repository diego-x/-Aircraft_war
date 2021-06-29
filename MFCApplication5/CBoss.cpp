#include "stdafx.h"
#include "CBoss.h"


CBoss::CBoss() :CGameObject(500, 100)
{
	m_V = 1;
	life = 6000;
}


CBoss::~CBoss()
{
}

CBoss::CBoss(int x, int y, int m_nMotion) : CGameObject(x, y), m_V(rand() % 3), m_nImgIndex(0), m_nMotion(m_nMotion)
{
	life = 300;
}

CImageList CBoss::m_Images;


BOOL CBoss::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_BOSS_3, RGB(0, 0, 0), ENEMY_width, ENEMY_HEIGHT, 1);
}
