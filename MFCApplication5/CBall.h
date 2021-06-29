#pragma once
#include "GameObject.h"
#include "resource.h"

class CBall :
	public CGameObject
{
public:
	CBall(int x, int y, int nMontion);
	~CBall();
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		m_ptPos.y += 10;
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BALL_HEIGHT, m_ptPos.y + BALL_HEIGHT));
	}
private:
	static const int BALL_HEIGHT = 8;
	static CImageList m_Images;
	int    m_nMotion;

};

