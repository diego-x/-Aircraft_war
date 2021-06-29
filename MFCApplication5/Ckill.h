#pragma once
#include "GameObject.h"
#include "resource.h"

class Ckill :
	public CGameObject
{
public:
	Ckill();
	Ckill(int x, int y);
	~Ckill();
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		// »­Í¼º¯Êý

		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	}

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMB_WIDTH, m_ptPos.y + BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 700;
	static const int BOMB_WIDTH = 67;
	static CImageList m_Images;


};

