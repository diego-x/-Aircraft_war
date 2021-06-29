#pragma once
#include "GameObject.h"
#include "resource.h"
class CEnemy_1 :
	public CGameObject
{
public:
	CEnemy_1();
	~CEnemy_1();
	CEnemy_1(int x, int y, int m_nMotion);
	BOOL Draw(CDC* pDC, BOOL bPause)
	{
		if (m_V == 0)
			m_V = 1;
		m_ptPos.y += 5 * m_V;
		/*if (rand() % 17 == 0)
			m_ptPos.x += 10;
		if (rand() % 27 == 0)
			m_ptPos.x -= 10;*/
		return  m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	}


	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 98, m_ptPos.y + 144));
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
	void setxl(CRect &rect)
	{
		m_ptPos.x = rect.right;
	}
	//�Ƿ���Կ������ӵ�
	//BOOL Fired();
	void shan() 
	{
		
			m_ptPos.x -= 100;

		
	}
private:
	static const int ENEMY_HEIGHT = 35;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
	//ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ

};

