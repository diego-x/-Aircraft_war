#include "stdafx.h"
#include "Ckill.h"


Ckill::Ckill()
{
}

Ckill::Ckill(int x, int y) :CGameObject(x, y)
{
}


Ckill::~Ckill()
{
}

CImageList Ckill::m_Images;

BOOL Ckill::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_SKILL, RGB(0, 0, 0), 67, 700, 1);
}
