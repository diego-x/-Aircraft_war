#pragma once
#include "GameObject.h"
#include "resource.h"
class CE_Bomb :
	public CGameObject
{
public:
	CE_Bomb();
	~CE_Bomb();
	CE_Bomb(int x, int y);
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		// »­Í¼º¯Êý

		m_ptPos.y += 10;
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	}

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMB_WIDTH, m_ptPos.y + BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 52;
	static const int BOMB_WIDTH = 20;
	static CImageList m_Images;

};

