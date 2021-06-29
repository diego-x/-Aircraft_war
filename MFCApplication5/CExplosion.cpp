#include "stdafx.h"
#include "CExplosion.h"


CExplosion::CExplosion(int x,int y):CGameObject(x, y)
{
	m_nProcess = 0;
}


CExplosion::CExplosion()
{
}

CExplosion::~CExplosion()
{
}
CImageList CExplosion::m_Images;

BOOL CExplosion::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_Explosion, RGB(0, 0, 0), 528/8, EXPLOSION_WIDTH, 7);
}
