#pragma once
#include "GameObject.h"
#include "resource.h"

class CBomb :
	public CGameObject
{
public:
	CBomb();
	CBomb(int x, int y);
	~CBomb();
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		// 画图函数

		m_ptPos.y -= 10;
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
		
	}

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMB_WIDTH, m_ptPos.y + BOMB_HEIGHT));
	}

	// 导弹数目
	int Get_Max_Size() { return max_size; }
	void Set_Max_Size(int x) { max_size += x; }
private:
	static const int BOMB_HEIGHT = 26;
	static const int BOMB_WIDTH = 22;
	static CImageList m_Images;
	int max_size = 10;

};

