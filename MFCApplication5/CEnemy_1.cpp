#include "stdafx.h"
#include "CEnemy_1.h"


CEnemy_1::CEnemy_1()
{
}


CEnemy_1::~CEnemy_1()
{
}
CEnemy_1::CEnemy_1(int x, int y, int m_nMotion) : CGameObject(x, y), m_V(rand() % 3), m_nImgIndex(0), m_nMotion(m_nMotion)
{

}

CImageList CEnemy_1::m_Images;


BOOL CEnemy_1::LoadImage()
{
	return CGameObject::LoadImageW(m_Images,IDB_E11 , RGB(0, 0, 0), 98, 144, 1);
}
