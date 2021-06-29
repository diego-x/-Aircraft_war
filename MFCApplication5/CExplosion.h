#pragma once
#include "GameObject.h"
#include "resource.h"
class CExplosion :
	public CGameObject
{
public:
	CExplosion();
	CExplosion(int x, int y);
	~CExplosion();
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		return m_Images.Draw(pDC, m_nProcess++, m_ptPos, ILD_TRANSPARENT);
	}


	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + EXPLOSION_WIDTH, m_ptPos.y + EXPLOSION_WIDTH));
	}
	int GetProcess()
	{
		return m_nProcess;
	}
private:
	//ը����ͼƬ�б�
	static CImageList m_Images;
	//ͼ�������Ĳ�������
	int   m_nProcess;
public:
	static const int  EXPLOSION_WIDTH = 66;

};

