#pragma once
#include "GameObject.h"
#include "resource.h"

class CEnemy :
	public CGameObject
{
public:
	CEnemy();
	CEnemy(int x, int y, int m_nMotion);
	~CEnemy();
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		if (m_V == 0)
			m_V = 1;
		m_ptPos.y += 5* m_V;
		if (rand() % 59 == 0)
			m_ptPos.x += 10;
		if (rand() % 69 == 0)
			m_ptPos.x -= 10;
		
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	
	}
	

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMY_WIDTH, m_ptPos.y + ENEMY_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}

	void set0(CRect &rect)
	{
		m_ptPos.y =0;
		m_ptPos.x = rand()%rect.right;
	}
	void setxr(CRect &rect)
	{
		m_ptPos.x = rect.left;		
	}
	void setxl(CRect &rect)
	{
		m_ptPos.x = rect.right;
	}
	void SetLife()
	{
		life--;
	}
	void shan() 
	{ 
	
			m_ptPos.x += 100;
		
		
	}
	int GetLife()
	{
		return life;
	}
	//�Ƿ���Կ������ӵ�
	//BOOL Fired();
private:
	static const int ENEMY_HEIGHT = 179;
	static const int ENEMY_WIDTH = 199;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
	//ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
	int life=20;

};

