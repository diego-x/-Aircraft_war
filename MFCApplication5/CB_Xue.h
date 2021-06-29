#pragma once
#include "GameObject.h"
#include "resource.h"
class CB_Xue :
	public CGameObject
{
public:
	CB_Xue();
   ~CB_Xue();
	CB_Xue(int x, int y);
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		//m_ptPos.y += 10; 
		GetWidth();
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BALL_HEIGHT, m_ptPos.y + BALL_HEIGHT));
	}
	void GetBossPoint(int x,int y)
	{
		m_ptPos.x = x; m_ptPos.y = y;
	}
	void GetBossLife_all(int life)
	{
		bosslife_all = life;
	}
	void GetBossLife_now(int life)
	{
		bosslife_now = life;
	}
    void GetWidth()
	{
		bei = (bosslife_now / bosslife_all);
	}
private:
	static const int BALL_HEIGHT = 22;
	static const int ENEMY_width = 343;
	static  int bei;
	static CImageList m_Images;
	int    m_nMotion;
	int bosslife_all = 1;
	int bosslife_now = 1;
};

