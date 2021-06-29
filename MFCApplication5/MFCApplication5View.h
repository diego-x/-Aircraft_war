
// MFCApplication5View.h: CMFCApplication5View 类的接口
//

#pragma once
#include "CMyPlane.h"
#include "CEnemy.h"
#include "CBomb.h"
#include "CExplosion.h"
#include "CBall.h"
#include "CEnemy_1.h"
#include "Ckill.h"
#include "CBoss.h"
#include "CE_Bomb.h"
#include "CTool.h"
#include "CAddLife.h"
#include "CAddKill.h"
#include "CBoss2.h"
#include "CBoss3.h"
#include "CB_Xue.h"
#include "resource.h"
#include <Windows.h>
#include <iostream>
#include "string.h"
#include <process.h> 
#include<iomanip>
#include <MMSystem.h>
#pragma comment (lib,"Winmm.lib")

using namespace std;

class CMFCApplication5View : public CView
{
private:
	CPoint pt1,pt2;
	CMyPlane myplane;
	CExplosion Explosion;
	CEnemy enemy1;
	CBoss boss1;
	CBoss_2 boss_2;
	CBomb bomb;
	CObList listEnemy;
	
	CObList listBomb;
	//CObList listBomb2;
	CObList listKill;
	CObList listExplosion;
	
	CObList listBall;
	CObList listEnemy_1;
	
	CObList listBoss;
	CObList listE_Bomb;

	// 道具
	CObList listAddBomb;
	CObList listAddLife;
	CObList listAddKill;

	//xue liang
	CObList listBossXue;
	CB_Xue pb_xue;
	int guan=1;
	int easy=30;
	int easy2 = 40;

	int ll=0;
	int pp = 1;

	int GAME_WIDTH = 1920;
	int GAME_HEIGHT = 1080;

	int cnt = 1;
    protected: // 仅从序列化创建
	CMFCApplication5View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication5View)

// 特性
public:
	CMFCApplication5Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		int CurrentKey(int nVirtKey) const;
	void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

#ifndef _DEBUG  // MFCApplication5View.cpp 中的调试版本
inline CMFCApplication5Doc* CMFCApplication5View::GetDocument() const
   { return reinterpret_cast<CMFCApplication5Doc*>(m_pDocument); }
#endif
