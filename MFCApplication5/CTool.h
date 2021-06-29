#pragma once
#include "GameObject.h"
#include "resource.h"

class CTool :
	public CGameObject
{
public:
	CTool();
	~CTool();
	CTool(int x, int y);
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		// »­Í¼º¯Êý

		m_ptPos.y += 2;
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	}

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMB_WIDTH, m_ptPos.y + BOMB_HEIGHT));
	}

	
private:
	static const int BOMB_HEIGHT = 40;
	static const int BOMB_WIDTH = 40;
	static CImageList m_Images;
	
};

