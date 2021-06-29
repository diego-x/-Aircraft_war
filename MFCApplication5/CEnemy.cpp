#include "stdafx.h"
#include "CEnemy.h"


CEnemy::CEnemy():CGameObject(500, 0)
{
	m_V = 1;
	life = 6;
}


CEnemy::~CEnemy()
{
}

CEnemy::CEnemy(int x, int y, int m_nMotion) : CGameObject(x, y), m_V(rand()%3), m_nImgIndex(0), m_nMotion(m_nMotion)
{
	life = 6;
}

CImageList CEnemy::m_Images;


BOOL CEnemy::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_E2, RGB(0, 0, 0), ENEMY_WIDTH, ENEMY_HEIGHT, 1);
}
