#include "stdafx.h"
#include "CMyPlane.h"


CMyPlane::CMyPlane():CGameObject(500,500)
{
	m_nVerMotion = 0;
	m_nHorMotion = 0;
	life = 20;
}


CMyPlane::~CMyPlane()
{

}
CImageList CMyPlane::m_Images;


BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImageW(m_Images, IDB_MY111, RGB(0, 0, 0), PLANE_WIDTH, PLANE_HEIGHT, 1);
}
