#pragma once
#include "GameObject.h"
#include "resource.h"
class CBoss :
	public CGameObject
{
public:
	int number = 0;
	CBoss();
	~CBoss();
	CBoss(int x, int y, int m_nMotion);
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		
		if ((rect1.right >= m_ptPos.x + 360 )&& nnn)
		{
			m_ptPos.x += 5;
			if (rect1.right <= m_ptPos.x + 360)
				nnn = 0;
			if (rand() % 98 == 0)
			{
				m_ptPos.x += 10;
				//m_ptPos.y += 8;
			}
		}
		else
		{
			if (rect1.left >= m_ptPos.x)
				nnn = 1;
			if (rand() % 88 == 0)
			{
				m_ptPos.x -= 10;
				//m_ptPos.y -= 10;
			}
			m_ptPos.x -= 5;			
		}

		if (rect1.bottom / 2 - 150 > m_ptPos.y && nn)
		{
			m_ptPos.y += 1;
			if (rect1.bottom / 2 - 150 <= m_ptPos.y)
				nn = 0;
			if (rand() % 98 == 0)
			{
				//m_ptPos.x += 10;
				m_ptPos.y += 1;
			}
		}
		else
		{
			if (rect1.top+50 >= m_ptPos.y)
				nn = 1;
			if (rand() % 88 == 0)
			{
				//m_ptPos.x -= 10;
				m_ptPos.y -= 1;
			}
			m_ptPos.y -= 1;
		}


	
		if (m_V == 0)
			m_V = 1;
		
		return  m_Images.Draw(pDC, 0, CPoint(m_ptPos.x-100, m_ptPos.y-50), ILD_TRANSPARENT);

	}


	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 250, m_ptPos.y + 100));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}

	void set0(CRect &rect)
	{
		m_ptPos.y = 0;
		m_ptPos.x = rand() % rect.right;
	}
	void setxr(CRect &rect)
	{
		m_ptPos.x = rect.left;
	}
	void SetLife(int x)
	{
		life = life - x;
	}
	int GetLife()
	{
		return life;
	}
	void  SetRect1(CRect rect)
	{
		rect1 = rect;
	}
	void setxl(CRect &rect)
	{
		m_ptPos.x = rect.right;
	}
	//是否可以开火发射子弹
	//BOOL Fired();
private:
	static const int ENEMY_HEIGHT = 407;
	static const int ENEMY_width = 464;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时
	int life ;
	CRect rect1;
	int nnn = 1;
	int nn = 1;
};

