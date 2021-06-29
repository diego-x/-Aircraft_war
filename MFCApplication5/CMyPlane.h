#pragma once
#include "GameObject.h"
#include "resource.h"
class CMyPlane :
	public CGameObject
{
public:
	CMyPlane();
	~CMyPlane();

	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
		
	}

	static BOOL LoadImage();

	void SetHorMotion(int nMotion)
	{
		m_nHorMotion = nMotion;
		m_ptPos.x += m_nHorMotion * 10;

	}
	int GetHorMotion() const
	{
		return m_nHorMotion;
	}

	void SetVerMotion(int nMotion)
	{
		m_nVerMotion = nMotion;
	    m_ptPos.y += m_nVerMotion * 10;
	}
	int GetVerMotion() const
	{
		return m_nVerMotion;
	}

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + PLANE_WIDTH, m_ptPos.y + PLANE_HEIGHT));
	}

	// 生命树
	int GetLife()
	{
		return life;
	}
	void SetLife(int i)
	{
		life = life + i;
	}
	void re()
	{
		killnumber = 50;
		life = 50;
	}

	void gaixue(int i) { life = i; }
	// 技能数
 	int GetNumber()
	{
		return killnumber;
	}
	void SetNumber(int x)
	{
		killnumber += x;
	}

	//是否可以开火发射导弹
	//BOOL Fired();

public:
	static const int PLANE_WIDTH = 112;
	static const int PLANE_HEIGHT = 118;
	int   killnumber = 50;
private:

	static CImageList m_Images;
	int    m_nHorMotion;//飞机水平运行方向0->静止，1->右 -1->左
	int    m_nVerMotion;//飞机垂直运行方向0->静止，1->上 -1->下
	int    m_nWait;//发射延时
	int    life;
	
};

