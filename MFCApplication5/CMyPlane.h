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

	// ������
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
	// ������
 	int GetNumber()
	{
		return killnumber;
	}
	void SetNumber(int x)
	{
		killnumber += x;
	}

	//�Ƿ���Կ����䵼��
	//BOOL Fired();

public:
	static const int PLANE_WIDTH = 112;
	static const int PLANE_HEIGHT = 118;
	int   killnumber = 50;
private:

	static CImageList m_Images;
	int    m_nHorMotion;//�ɻ�ˮƽ���з���0->��ֹ��1->�� -1->��
	int    m_nVerMotion;//�ɻ���ֱ���з���0->��ֹ��1->�� -1->��
	int    m_nWait;//������ʱ
	int    life;
	
};

