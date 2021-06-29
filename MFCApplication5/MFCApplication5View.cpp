
// MFCApplication5View.cpp: CMFCApplication5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
//	ON_WM_ERASEBKGND()
//ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// CMFCApplication5View 构造/析构

CMFCApplication5View::CMFCApplication5View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication5View 绘图
int CMFCApplication5View::CurrentKey(int nVirtKey) const
{
	short vks = GetKeyState(nVirtKey);// & 0x8000;
	return ((vks & 0x80) != 0);
}


void CMFCApplication5View::OnDraw(CDC* pDC)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);

	
	/*GetClientRect(&rect);
	pDC->TextOutW(200, 300, str);


	// 画图
	CBrush brush,blush,*p;
	brush.CreateSolidBrush(RGB(0, 0, 255));
	p = (CBrush*)pDC->SelectObject(&brush);
	pDC->Rectangle(&rect);

	blush.CreateSolidBrush(RGB(0, 255, 0));
	p = (CBrush*)pDC->SelectObject(&blush);
	pDC->Rectangle(200, 200, 500, 500);
	
	/*CBrush br;
	br.CreateSolidBrush(RGB(255, 0, 0));
	p = (CBrush*)pDC->SelectObject(&br);
	pDC->Rectangle(200, 300,1000, 1000);
	
	全屏变色 pDC->Rectangle(&rect);

	CFont font;
	font.CreateFontW(48, 42, 90, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
	CFont *oldFont = pDC->SelectObject(&font);
	pDC->TextOutW(500, 500, _T("______________________"));
	pDC->TextOutW(500, 200, _T("abcdefg"));
	pDC->SelectObject(*oldFont);
	pDC->TextOutW(500, 100, _T("abcdefg"));

	CBitmap bmp;
	bmp.LoadBitmapW(IDB_ME);
	CImageList imglist;

	imglist.Create(528/3, 66,ILC_COLOR8| ILC_MASK,3,0 );
	imglist.Add(&bmp, RGB(0, 0, 0));
	int i = 1000;
	while (i != 0)
	{
		i--;
		imglist.Draw(pDC, 0, CPoint(1400-i, 1000 - i), ILD_TRANSPARENT);
		imglist.Draw(pDC, 1, CPoint(i, 500), ILD_TRANSPARENT);
		imglist.Draw(pDC, 2, CPoint(i, i), ILD_TRANSPARENT);
		//imglist.DeleteImageList();
	
		Sleep(10);
	}*/
}


// CMFCApplication5View 诊断

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5View 消息处理程序


void CMFCApplication5View::OnTimer(UINT_PTR nIDEvent)
{
	
	CDC* pDC = GetDC();
	CRect rect;
	CDC demo;
	CBrush brush;
	GetClientRect(&rect);
	demo.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	demo.SelectObject(bmp);
	brush.CreateSolidBrush(RGB(255, 255, 255));
	demo.SelectObject(brush);
	demo.Rectangle(rect);
	
	if (CurrentKey(VK_ESCAPE) == 1)
	{
		exit(1);
	}
	if (CurrentKey(0x50) == 1 && pp%2==1)
	{
		KillTimer(1);
		KillTimer(2);
		KillTimer(3);
		KillTimer(4);
		pp++;
		if (AfxMessageBox(_T("游戏暂停,是继续,否退出"), MB_YESNO) == 6)//MB_OK表示在弹出的窗口中之前是一个OK按键
		{
			SetTimer(1, 30, 0);
			SetTimer(4, 500, 0);
			SetTimer(2, 3000, 0);
			SetTimer(3, 4000, 0);
		}

		else exit(1);
	}
	/*if (CurrentKey(0x50) == 1 && pp % 2 == 0)
	{
		pp++;
		SetTimer(1, 30, 0);
		SetTimer(4, 500, 0);
		SetTimer(2, 3000, 0);
		SetTimer(3, 4000, 0);
	}*/
	if (myplane.GetLife() <= 0)
	{
		KillTimer(1);
		KillTimer(2);
		KillTimer(3);
		KillTimer(4);
		
		if (AfxMessageBox(_T("GAME    OVER"), MB_OK) == 1)//MB_OK表示在弹出的窗口中之前是一个OK按键
			exit(1);
	}
	if (ll && listBoss.GetSize() == 0 && listEnemy.GetSize() == 0 && listEnemy_1.GetSize() == 0)
	{
		KillTimer(1);
		KillTimer(2);
		KillTimer(3);
		KillTimer(4);
		if (AfxMessageBox(_T("游戏胜利！！ 是重新开始，否退出游戏"), MB_YESNO) == 6)//MB_OK表示在弹出的窗口中之前是一个OK按键
		{

			myplane.re();
			listBoss.RemoveAll();
			listAddBomb.RemoveAll();
			listEnemy.RemoveAll();
			listEnemy_1.RemoveAll();
			listE_Bomb.RemoveAll();
			listBall.RemoveAll();
			guan = 1;
			boss1.number = 0;
			SetTimer(1, 30, 0);
			SetTimer(4, 500, 0);
			SetTimer(2, 3000, 0);
			SetTimer(3, 4000, 0);
		}
		else
		{
			
			SetTimer(1, 30, 0);
			SetTimer(4, 500, 0);
			SetTimer(2, 3000, 0);
			SetTimer(3, 4000, 0);
			exit(1);
		}
	}
	if (CurrentKey(0x52) == 1)
	{
		/*KillTimer(1);
		KillTimer(2);
		KillTimer(3);
		KillTimer(4);
		if (AfxMessageBox(_T("游戏重新开始"), MB_YESNO) == 6)//MB_OK表示在弹出的窗口中之前是一个OK按键
		{
			*/
			myplane.re();
			listBoss.RemoveAll();
			listAddBomb.RemoveAll();
			listEnemy.RemoveAll();
			listEnemy_1.RemoveAll();
			listE_Bomb.RemoveAll();
			listBall.RemoveAll();
			guan = 1;
			boss1.number = 0;
			/*SetTimer(1, 30, 0);
			SetTimer(4, 500, 0);
			SetTimer(2, 3000, 0);
			SetTimer(3, 4000, 0);
		}
		else
		{
			SetTimer(1, 30, 0);
			SetTimer(4, 500, 0);
			SetTimer(2, 3000, 0);
			SetTimer(3, 4000, 0);
		}*/

		
	}
	
	// ==========================================================  背景  =======================================================

	static int imagelocation = 0;//背景图片截取位置初始位置
	CDC memDC;
	memDC.CreateCompatibleDC(&demo);
	CBitmap bmpDraw;//创建位图
	if (guan == 1)
		bmpDraw.LoadBitmapW(IDB_BJ2);
	else if (guan == 2)
		bmpDraw.LoadBitmapW(IDB_BJ2);
	else if (guan == 3)
		bmpDraw.LoadBitmapW(IDB_BJ3);
	else if (guan == 4)
		bmpDraw.LoadBitmapW(IDB_BJ3);

	CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
	(&demo)->BitBlt(0, imagelocation, GAME_WIDTH, GAME_HEIGHT - imagelocation, &memDC, 0, 0, SRCCOPY);//设置动态背景
	(&demo)->BitBlt(0, 0, GAME_WIDTH, imagelocation, &memDC, 0, GAME_HEIGHT - imagelocation, SRCCOPY);
	memDC.SelectObject(pbmpold);
	imagelocation++;
	if (imagelocation == GAME_HEIGHT)
		imagelocation = 0;

	//======================
	

	//==========================================================  延时 =============================================================
	
	{short vks = GetKeyState(VK_LEFT);// & 0x8000;
	short vks2 = ((vks & 0x80) != 0);
	if (myplane.GetRect().left >= rect.left)
	{
		if (vks2 == 1)myplane.SetHorMotion(-1);
	}
	if (myplane.GetRect().right <= rect.right)
	{
		if (CurrentKey(VK_RIGHT) == 1)
			myplane.SetHorMotion(1);
	}
	short vks1 = GetKeyState(VK_UP);// & 0x8000;
	short vks12 = ((vks1 & 0x80) != 0);
	if (myplane.GetRect().top >= rect.top)
	{
		if (vks12 == 1)myplane.SetVerMotion(-1);
	}
	if (myplane.GetRect().bottom <= rect.bottom)
	{
		if (CurrentKey(VK_DOWN) == 1)
			myplane.SetVerMotion(1);
	}
	}
	//=============================================================================================================================

	//==========================================================  我的飞机  ==========================================================
	int life;
	myplane.Draw(&demo, false);
	life = myplane.GetLife();
	int kill = myplane.killnumber;
	
	
	
	//===================================================   BOSS  ===================================================================
	
	
	//pb_xue.Draw(&demo,false);

	POSITION posBomb;
	// 关卡 1
	if (listBoss.GetSize() == 0 && boss1.number==0 && guan == 1)
	{
		CBoss2 *pboss2 = new CBoss2();
		listBoss.AddTail(pboss2);
		// 血量
		CB_Xue *pb_xue = new CB_Xue();
		listBossXue.AddTail(pb_xue);
		boss1.number = 1;
		easy = 30;
		easy2 =35;
		ll = 0;
	}
	if (listBoss.GetSize() != 0 && guan == 1 && boss1.number ==1)
	{ 
		CBoss2 *pboss = (  CBoss2 *)listBoss.GetHead();
		pboss->SetRect1(rect);
		pboss->Draw(&demo, false);
		//  血量

		int xx = rand();
		if (xx % 20 == 0)
		{
			CBall *pBall = new CBall(pboss->GetPoint().x -50, pboss->GetPoint().y + 250, 0);
			listBall.AddTail(pBall);
			CBall *pBall1 = new CBall(pboss->GetPoint().x + 380, pboss->GetPoint().y + 250, 0);
			listBall.AddTail(pBall1);
			CBall *pBall2 = new CBall(pboss->GetPoint().x + 200, pboss->GetPoint().y + 250, 0);
			listBall.AddTail(pBall2);
		}
		/*if (xx % 59 == 0)
		{
			// 产生
			CE_Bomb *pE_Bomb = new CE_Bomb(pboss->GetPoint().x + 140, pboss->GetPoint().y);
			listE_Bomb.AddTail(pE_Bomb);

		}*/

		// BOSS导弹
		POSITION posE_Boss;
		for (posE_Boss = listE_Bomb.GetHeadPosition(); posE_Boss != NULL;)
		{
			POSITION pos1 = posE_Boss;
			CE_Bomb *pE_Boss = (CE_Bomb*)listExplosion.GetNext(posE_Boss);
			pE_Boss->Draw(&demo, false);
			if (pE_Boss->GetPoint().y > rect.bottom)
			{
				listE_Bomb.RemoveAt(pos1);
				break;
			}
			CRect  interRect;
			int intersection = interRect.IntersectRect(pE_Boss->GetRect(), myplane.GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pE_Boss->GetPoint().x, pE_Boss->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listE_Bomb.RemoveAt(pos1);
				myplane.SetLife(-3);
				break;
			}
		}
		// 判断 Boss 是否
		for (posBomb = listBomb.GetHeadPosition(); posBomb != NULL;)
		{
			int nn = 0;
			POSITION pos12;
			pos12 = posBomb;
			CBomb *pBomb = (CBomb*)listBomb.GetNext(posBomb);
			CRect  interRect;
			int intersection = interRect.IntersectRect(pBomb->GetRect(), pboss->GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pBomb->GetPoint().x, pBomb->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listBomb.RemoveAt(pos12);
				pboss->SetLife(3);
				if (pboss->GetLife() <= 0)
				{
					for (int k = 1; k < 50; k++)
					{
						CExplosion *explosion1 = new CExplosion(pboss->GetPoint().x + rand() % 300, pboss->GetPoint().y + rand() % (pboss->GetRect().bottom));
						listExplosion.AddTail(explosion1);
					}
				
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CTool *addbomb = new CTool(pboss->GetPoint().x + rand()%200, pboss->GetPoint().y + rand() % 200);
						listAddBomb.AddTail(addbomb);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddLife *addlife = new CAddLife(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddLife.AddTail(addlife);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddKill *addkill = new CAddKill(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddKill.AddTail(addkill);
					}

					listBoss.RemoveAll();
					listBossXue.RemoveAll();
				}
				break;
			}
		}
		
		
		double bei = (double)pboss->GetLife() / 2000;
		double width = 343;
		if ( bei >0.01)
		{
			CBitmap XueTiao;
			XueTiao.LoadBitmapW(IDB_BOSSXUE);
			CImageList Xue;
			Xue.Create(width * bei, 22, ILC_COLOR8 | ILC_MASK, 1, 0);
			Xue.Add(&XueTiao, RGB(0, 0, 0));
			Xue.Draw(&demo, 0, CPoint(pboss->GetPoint().x , pboss->GetPoint().y - 100), ILD_TRANSPARENT);
		}

		// 判断是否相撞
		CRect  interRect;
		int intersection = interRect.IntersectRect(myplane.GetRect(), pboss->GetRect());
		if (intersection > 0)
		{ //矩形相交，相撞，添加爆炸效果到爆炸列表
		//画出提示信息
			CExplosion *explosion1 = new CExplosion(myplane.GetPoint().x, myplane.GetPoint().y);
			listExplosion.AddTail(explosion1);

			int k = 0;
			if (k == 0) { myplane.SetLife(-1); k++; }

		}
	}
	//关卡 2
	if (listBoss.GetSize() == 0 && boss1.number == 1 && guan == 2 && rand() % 71 ==0)
	{		
		CBoss_2 *pboss = new CBoss_2();
		listBoss.AddTail(pboss);
		// xue
		CB_Xue *pb_xue = new CB_Xue();
		listBossXue.AddTail(pb_xue);
		boss1.number = 2;
		easy = 20;
		easy2 = 40;
	}	
	if (listBoss.GetSize() != 0 && guan == 2 && boss1.number == 2)
	{
		CBoss_2 *pboss = (CBoss_2 *)listBoss.GetHead();
		pboss->SetRect1(rect);
		pboss->Draw(&demo, false);

		// 血量
		double bei = (double)pboss->GetLife() / 4000;
		double width = 343;
		if (bei>0.01)
		{
			CBitmap XueTiao;
			XueTiao.LoadBitmapW(IDB_BOSSXUE);
			CImageList Xue;
			Xue.Create(width * bei, 22, ILC_COLOR8 | ILC_MASK, 1, 0);
			Xue.Add(&XueTiao, RGB(0, 0, 0));
			Xue.Draw(&demo, 0, CPoint(pboss->GetPoint().x - 50, pboss->GetPoint().y - 100), ILD_TRANSPARENT);
		}
		int xx = rand();
		if (xx % 15 == 0)
		{
			CBall *pBall = new CBall(pboss->GetPoint().x -40, pboss->GetPoint().y + 200, 0);
			listBall.AddTail(pBall);
			CBall *pBall1 = new CBall(pboss->GetPoint().x + 300, pboss->GetPoint().y + 200, 0);
			listBall.AddTail(pBall1);

		}
		if (xx % 159 == 0)
		{
			// 产生 
			CE_Bomb *pE_Bomb = new CE_Bomb(pboss->GetPoint().x + 140, pboss->GetPoint().y);
			listE_Bomb.AddTail(pE_Bomb);

		}
		// BOSS导弹
		POSITION posE_Boss;
		for (posE_Boss = listE_Bomb.GetHeadPosition(); posE_Boss != NULL;)
		{
			POSITION pos1 = posE_Boss;
			CE_Bomb *pE_Boss = (CE_Bomb*)listExplosion.GetNext(posE_Boss);
			pE_Boss->Draw(&demo, false);
			if (pE_Boss->GetPoint().y > rect.bottom)
			{
				listE_Bomb.RemoveAt(pos1);
				break;
			}
			CRect  interRect;
			int intersection = interRect.IntersectRect(pE_Boss->GetRect(), myplane.GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pE_Boss->GetPoint().x, pE_Boss->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listE_Bomb.RemoveAt(pos1);
				myplane.SetLife(-3);
				break;
			}
		}
		// 判断 Boss 是否
		for (posBomb = listBomb.GetHeadPosition(); posBomb != NULL;)
		{
			int nn = 0;
			POSITION pos12;
			pos12 = posBomb;
			CBomb *pBomb = (CBomb*)listBomb.GetNext(posBomb);
			CRect  interRect;
			int intersection = interRect.IntersectRect(pBomb->GetRect(), pboss->GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pBomb->GetPoint().x, pBomb->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listBomb.RemoveAt(pos12);
				pboss->SetLife(4);
				if (pboss->GetLife() <= 0)
				{
					for (int k = 1; k < 50; k++)
					{
						CExplosion *explosion1 = new CExplosion(pboss->GetPoint().x + rand() % 300, pboss->GetPoint().y + rand() % (pboss->GetRect().bottom));
						listExplosion.AddTail(explosion1);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CTool *addbomb = new CTool(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddBomb.AddTail(addbomb);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddLife *addlife = new CAddLife(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddLife.AddTail(addlife);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddKill *addkill = new CAddKill(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddKill.AddTail(addkill);
					}
					listBoss.RemoveAll();
					listBossXue.RemoveAll();
				}
				break;
			}
		}
		/*for (posBomb = listBomb2.GetHeadPosition(); posBomb != NULL;)
		{
			int nn = 0;
			POSITION pos12;
			pos12 = posBomb;
			CBomb *pBomb = (CBomb*)listBomb2.GetNext(posBomb);
			CRect  interRect;
			int intersection = interRect.IntersectRect(pBomb->GetRect(), pboss->GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pBomb->GetPoint().x, pBomb->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listBomb2.RemoveAt(pos12);
				pboss->SetLife(4);
				if (pboss->GetLife() <= 0)
				{
					for (int k = 1; k < 50; k++)
					{
						CExplosion *explosion1 = new CExplosion(pboss->GetPoint().x + rand() % 300, pboss->GetPoint().y + rand() % (pboss->GetRect().bottom));
						listExplosion.AddTail(explosion1);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CTool *addbomb = new CTool(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddBomb.AddTail(addbomb);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddLife *addlife = new CAddLife(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddLife.AddTail(addlife);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddKill *addkill = new CAddKill(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddKill.AddTail(addkill);
					}
					listBoss.RemoveAll();
					listBossXue.RemoveAll();
				}
				break;
			}
		}*/
		CRect  interRect;
		int intersection = interRect.IntersectRect(myplane.GetRect(), pboss->GetRect());
		if (intersection > 0)
		{ //矩形相交，相撞，添加爆炸效果到爆炸列表
		//画出提示信息
			CExplosion *explosion1 = new CExplosion(myplane.GetPoint().x, myplane.GetPoint().y);
			listExplosion.AddTail(explosion1);

			int k = 0;
			if (k == 0) { myplane.SetLife(-1); k++; }

		}
	}
    // 关卡 3
	if (listBoss.GetSize() == 0 && boss1.number == 2 && guan == 3 && rand() % 71 == 0)
	{
		CBoss *pboss = new CBoss();
		listBoss.AddTail(pboss);
		// xue
		CB_Xue *pb_xue = new CB_Xue();
		listBossXue.AddTail(pb_xue);
		boss1.number = 3;
		easy = 20;
		easy2 = 20;
		ll = 1;
	}
	if (listBoss.GetSize() != 0 && guan == 3 && boss1.number == 3)
	{
		CBoss *pboss = (CBoss *)listBoss.GetHead();
		pboss->SetRect1(rect);
		pboss->Draw(&demo, false);
		// xue

		
		double bei = (double)pboss->GetLife() / 6000;
		double width = 343;
		if (bei>0.01)
		{
			CBitmap XueTiao;
			XueTiao.LoadBitmapW(IDB_BOSSXUE);
			CImageList Xue;
			Xue.Create(width * bei, 22, ILC_COLOR8 | ILC_MASK, 1, 0);
			Xue.Add(&XueTiao, RGB(0, 0, 0));
			Xue.Draw(&demo, 0, CPoint(pboss->GetPoint().x - 30, pboss->GetPoint().y - 100), ILD_TRANSPARENT);
		}
		int xx = rand();
		if (xx % 10 == 0)
		{
			CBall *pBall = new CBall(pboss->GetPoint().x + 30, pboss->GetPoint().y + 200, 0);
			listBall.AddTail(pBall);
			CBall *pBall1 = new CBall(pboss->GetPoint().x + 230, pboss->GetPoint().y + 200, 0);
			listBall.AddTail(pBall1);

		}
		if (xx % 59 == 0)
		{
			// 产生 
			CE_Bomb *pE_Bomb = new CE_Bomb(pboss->GetPoint().x + 140, pboss->GetPoint().y);
			listE_Bomb.AddTail(pE_Bomb);

		}
		// BOSS导弹
		POSITION posE_Boss;
		for (posE_Boss = listE_Bomb.GetHeadPosition(); posE_Boss != NULL;)
		{
			POSITION pos1 = posE_Boss;
			CE_Bomb *pE_Boss = (CE_Bomb*)listExplosion.GetNext(posE_Boss);
			pE_Boss->Draw(&demo, false);
			if (pE_Boss->GetPoint().y > rect.bottom)
			{
				listE_Bomb.RemoveAt(pos1);
				break;
			}
			CRect  interRect;
			int intersection = interRect.IntersectRect(pE_Boss->GetRect(), myplane.GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pE_Boss->GetPoint().x, pE_Boss->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listE_Bomb.RemoveAt(pos1);
				myplane.SetLife(-3);
				break;
			}
		}
		// 判断 Boss 是否
		for (posBomb = listBomb.GetHeadPosition(); posBomb != NULL;)
		{
			int nn = 0;
			POSITION pos12;
			pos12 = posBomb;
			CBomb *pBomb = (CBomb*)listBomb.GetNext(posBomb);
			CRect  interRect;
			int intersection = interRect.IntersectRect(pBomb->GetRect(), pboss->GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pBomb->GetPoint().x, pBomb->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listBomb.RemoveAt(pos12);
				pboss->SetLife(5);
				if (pboss->GetLife() <= 0)
				{
					for (int k = 1; k < 50; k++)
					{
						CExplosion *explosion1 = new CExplosion(pboss->GetPoint().x + rand() % 300, pboss->GetPoint().y + rand() % (pboss->GetRect().bottom));
						listExplosion.AddTail(explosion1);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CTool *addbomb = new CTool(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddBomb.AddTail(addbomb);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddLife *addlife = new CAddLife(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddLife.AddTail(addlife);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddKill *addkill = new CAddKill(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddKill.AddTail(addkill);
					}
					guan = 4;
					listBoss.RemoveAll();
				}
				break;
			}
		}
		/*for (posBomb = listBomb2.GetHeadPosition(); posBomb != NULL;)
		{
			int nn = 0;
			POSITION pos12;
			pos12 = posBomb;
			CBomb *pBomb = (CBomb*)listBomb2.GetNext(posBomb);
			CRect  interRect;
			int intersection = interRect.IntersectRect(pBomb->GetRect(), pboss->GetRect());
			if (intersection > 0)
			{

				CExplosion *explosion1 = new CExplosion(pBomb->GetPoint().x, pBomb->GetPoint().y);
				listExplosion.AddTail(explosion1);
				listBomb2.RemoveAt(pos12);
				pboss->SetLife(5);
				if (pboss->GetLife() <= 0)
				{
					for (int k = 1; k < 50; k++)
					{
						CExplosion *explosion1 = new CExplosion(pboss->GetPoint().x + rand() % 300, pboss->GetPoint().y + rand() % (pboss->GetRect().bottom));
						listExplosion.AddTail(explosion1);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CTool *addbomb = new CTool(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddBomb.AddTail(addbomb);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddLife *addlife = new CAddLife(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddLife.AddTail(addlife);
					}
					for (int k = 1; k < rand() % 4 + 2; k++)
					{
						CAddKill *addkill = new CAddKill(pboss->GetPoint().x + rand() % 200, pboss->GetPoint().y + rand() % 200);
						listAddKill.AddTail(addkill);
					}
					listBoss.RemoveAll();
				}
				break;
			}
		}
		CRect  interRect;
		int intersection = interRect.IntersectRect(myplane.GetRect(), pboss->GetRect());
		if (intersection > 0)
		{ //矩形相交，相撞，添加爆炸效果到爆炸列表
		//画出提示信息
			CExplosion *explosion1 = new CExplosion(myplane.GetPoint().x, myplane.GetPoint().y);
			listExplosion.AddTail(explosion1);

			int k = 0;
			if (k == 0) { myplane.SetLife(-1); k++; }

		}*/
	}

	if (listBoss.GetSize()==0 && listEnemy.GetSize()==0 && listEnemy_1.GetSize()==0 && guan<3)
	{
		CFont font;
		font.CreateFontW(100, 35, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
		CFont *oldFont = demo.SelectObject(&font);
		CString str;
		demo.SetBkMode(TRANSPARENT);//设置字体背景透明
		demo.SetTextColor(RGB(0, 255, 0));//设置字体颜色
		str.Format(_T("战场正在清理中.......  准备进入下一关"));
		demo.TextOutW((rect.left+rect.right)/2-380, (rect.bottom + rect.top) / 2 -30, str);
	}
	
	//================================================================================================================================

	//==========================================================  显示（左） =============================================================
	
	CFont font;
	font.CreateFontW(25, 15, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
	CFont *oldFont = demo.SelectObject(&font);
	CString str;	
	demo.SetBkMode(TRANSPARENT);//设置字体背景透明
	demo.SetTextColor(RGB(0, 255, 0));//设置字体颜色
	//str.Format(_T("战机坐标(%d,%d)(%d,%d)"), cnt/*myplane.GetRect().left*/, listE_Bomb.GetSize(), myplane.GetRect().bottom, myplane.GetRect().top);
	//demo.TextOutW(rect.left, 0, str);
	if (bomb.Get_Max_Size() * 2 - listBomb.GetSize() >= 0)
	{
		str.Format(_T("子弹剩余数：%d "), bomb.Get_Max_Size() * 2 - listBomb.GetSize() );
		demo.TextOutW(rect.left, 40, str);
	}
	else
	{
		str.Format(_T("子弹剩余数：%d "), 0 );
		demo.TextOutW(rect.left, 40, str);
	}
	str.Format(_T("剩余生命：%d "), myplane.GetLife());
	demo.TextOutW(rect.left, 80, str);
	str.Format(_T("敌机数量：%d "), listEnemy.GetSize() + listEnemy_1.GetSize());
	demo.TextOutW(rect.left, 120, str);
	str.Format(_T("激光数：%d "), myplane.GetNumber());
	demo.TextOutW(rect.left, 160, str);	
	if (listBoss.GetSize() != 0)
	{
		CBoss *pboss = (CBoss *)listBoss.GetHead();
		str.Format(_T("BOSS血量：%d "), pboss->GetLife());
		demo.TextOutW(rect.left, 200, str);
	}
	str.Format(_T("按3键开启无敌 :"));
	demo.TextOutW(rect.left, 240, str);
	if (cnt % 2 == 0)
	{
		str.Format(_T("已开启 "));
		demo.TextOutW(rect.left+200, 240, str);
	}
	else
	{
		str.Format(_T("未开启 "));
		demo.TextOutW(rect.left + 200, 240, str);
	}

	str.Format(_T("按P键 => 暂停"));
	demo.TextOutW(rect.right - 200, 200, str);
	str.Format(_T("按0键 => 激光"));
	demo.TextOutW(rect.right - 200, 80, str);
	str.Format(_T("按空格键 => 导弹"));
	demo.TextOutW(rect.right - 200, 40, str);
	str.Format(_T("ESC => 退出"));
	demo.TextOutW(rect.right - 200, 120, str);
	str.Format(_T("按R键 => 重新开始"));
	demo.TextOutW(rect.right - 200, 160, str);
	

	CFont font1;
	font1.CreateFontW(40, 10, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
	CFont *oldFont1 = demo.SelectObject(&font1);
	CString str1;
	str1.Format(_T("关卡：%d "), guan);
	demo.TextOutW(rect.right, 0, str1);

	//===============================================================================================================================


	
	//==========================================================  敌机  ==============================================================
	  
	 if (nIDEvent == 2 && listEnemy.GetSize()<30-easy && listBoss.GetSize() != 0)
	 {
		 CEnemy *pEnemy = new CEnemy(rand() % rect.right, 0, 0);
		 listEnemy.AddTail(pEnemy);
	 }
	 if (nIDEvent == 3 && listEnemy_1.GetSize() < 40-easy2 && listBoss.GetSize()!=0)
	 {
		 CEnemy_1 *pEnemy_1 = new CEnemy_1(rand() % rect.right, 0, 0);
		 listEnemy_1.AddTail(pEnemy_1);
	 }
	 if (nIDEvent == 4)
	 {
		 myplane.SetNumber(1);
	 }

	 

	 POSITION posEnemy;
	  for (posEnemy = listEnemy.GetHeadPosition(); posEnemy != NULL;)
	 {
		 POSITION enemy_0= posEnemy;
		 CEnemy *pEnemy = (CEnemy*)listEnemy.GetNext(posEnemy);
		 pEnemy->Draw(&demo, false);
		 // 敌机出边界
		 if (pEnemy->GetPoint().y >= rect.bottom) pEnemy->set0(rect);
		 if (pEnemy->GetPoint().x >= rect.right) pEnemy->setxr(rect);
		 if (pEnemy->GetPoint().x <= rect.left) pEnemy->setxl(rect);
		 int x = rand();
		 if (x % 59 == 0)
		 {
			 CBall *pBall = new CBall(pEnemy->GetPoint().x+10, pEnemy->GetPoint().y+20, 0);
			 listBall.AddTail(pBall);
		 }
		 CRect  interRect;
		 int intersection = interRect.IntersectRect(myplane.GetRect(), pEnemy->GetRect());
		 if (intersection > 0)
		 { //矩形相交，相撞，添加爆炸效果到爆炸列表
		 //画出提示信息


			 listEnemy.RemoveAt(enemy_0);
			 int k = 0;
			 if (k == 0) { myplane.SetLife(-1); k++; }
			 CExplosion *explosion1 = new CExplosion(myplane.GetPoint().x, myplane.GetPoint().y);
			 listExplosion.AddTail(explosion1);
			 //CExplosion explosion1(myplane.GetPoint().x, myplane.GetPoint().y);
			 //explosion1.Draw(&demo, false);
		 }
	 }
	 //   飞机2号
	 for (posEnemy = listEnemy_1.GetHeadPosition(); posEnemy != NULL;)
	 {
		 POSITION enemy_0 = posEnemy;
		 CEnemy_1 *pEnemy = (CEnemy_1*)listEnemy_1.GetNext(posEnemy);
		 pEnemy->Draw(&demo, false);
		 if (pEnemy->GetPoint().y >= rect.bottom) pEnemy->set0(rect);
		 if (pEnemy->GetPoint().x >= rect.right) pEnemy->setxr(rect);
		 if (pEnemy->GetPoint().x <= rect.left) pEnemy->setxl(rect);
		 int x = rand();
		 if (x % 69 == 0)
		 {
			 CBall *pBall = new CBall(pEnemy->GetPoint().x + 10, pEnemy->GetPoint().y + 20, 0);
			 listBall.AddTail(pBall);
		 }
		 CRect  interRect;
		 int intersection = interRect.IntersectRect(myplane.GetRect(), pEnemy->GetRect());
		 if (intersection > 0)
		 { //矩形相交，相撞，添加爆炸效果到爆炸列表
		 //画出提示信息
			 CExplosion *explosion1 = new CExplosion(myplane.GetPoint().x, myplane.GetPoint().y);
			 listExplosion.AddTail(explosion1);
			 //CExplosion explosion1(myplane.GetPoint().x, myplane.GetPoint().y);
			 //explosion1.Draw(&demo, false);
			 listEnemy_1.RemoveAt(enemy_0);
			 int k = 0;
			 if (k == 0) { myplane.SetLife(-1); k++; }
		
		 }
	 }
	//=================================================================================================================================

	// ==========================================================  导弹  ==============================================================
	 if (CurrentKey(VK_SPACE)==1 && listBomb.GetSize()<=bomb.Get_Max_Size()*2)
	 {
 			 CBomb *pBomb = new CBomb(myplane.GetPoint().x+20, myplane.GetPoint().y);
			 listBomb.AddTail(pBomb);
			 CBomb *pBomb1 = new CBomb(myplane.GetPoint().x+65, myplane.GetPoint().y);
			 listBomb.AddTail(pBomb1);
			
	 }
	 if (CurrentKey(VK_NUMPAD0) == 1 && myplane.GetNumber()>=0)
	 {
		 myplane.SetNumber(-1);
		 Ckill *pkill = new Ckill(myplane.GetPoint().x+20, myplane.GetPoint().y-700);
		 listKill.AddTail(pkill);
		 pkill->Draw(&demo,false);
		 // 攻击 1 号 敌机 
		 for (posEnemy = listEnemy.GetHeadPosition(); posEnemy != NULL;)
		 {
			 POSITION pos1;
			 pos1 = posEnemy;

			 CEnemy *pEnemy = (CEnemy*)listEnemy.GetNext(posEnemy);
			 CRect  interRect;
			 int intersection = interRect.IntersectRect(pkill->GetRect(), pEnemy->GetRect());
			 if (intersection > 0)
			 { 
				 CExplosion *explosion1 = new CExplosion(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
				 listExplosion.AddTail(explosion1);
				 // 加子弹
				 int x = rand();
				 if (x % 6 == 0)
				 {
					 CTool *addbomb = new CTool(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
					 listAddBomb.AddTail(addbomb);
				 }
				 if (x % 5 == 0)
				 {
					 CAddLife *addlife = new CAddLife(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
					 listAddLife.AddTail(addlife);
				 }
				 if (x % 7 ==0 )
				 {
					 CAddKill *addkill = new CAddKill(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
					 listAddKill.AddTail(addkill);
				 }
				 listEnemy.RemoveAt(pos1);
				 break;
			 }
		 }
		 // 攻击 2 号 敌机
		 for (posEnemy = listEnemy_1.GetHeadPosition(); posEnemy != NULL;)
		 {
			 POSITION pos1;
			 pos1 = posEnemy;

			 CEnemy *pEnemy = (CEnemy*)listEnemy_1.GetNext(posEnemy);
			 CRect  interRect;
			 int intersection = interRect.IntersectRect(pkill->GetRect(), pEnemy->GetRect());
			 if (intersection > 0)
			 { 
				 CExplosion *explosion1 = new CExplosion(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
				 listExplosion.AddTail(explosion1);
				 // 加子弹
				 int x = rand();
				 if (x % 6 == 0)
				 {
					 CTool *addbomb = new CTool(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
					 listAddBomb.AddTail(addbomb);
				 }
				 if (x % 5 == 0)
				 {
					 CAddLife *addlife = new CAddLife(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
					 listAddLife.AddTail(addlife);
				 }
				 if (x % 7 ==0 )
				 {
					 CAddKill *addkill = new CAddKill(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
					 listAddKill.AddTail(addkill);
				 }
				 listEnemy_1.RemoveAt(pos1);
				 break;
			 }
		 }
		 //BOSS
		 if (listBoss.GetSize() != 0)
		 {
			 CBoss *pboss = (CBoss *)listBoss.GetHead();
			 CRect  interRect;
			 int intersection = interRect.IntersectRect(pkill->GetRect(), pboss->GetRect());
			 if (intersection > 0)
			 { //矩形相交，相撞，添加爆炸效果到爆炸列表
			 //画出提示信息
				 CExplosion *explosion1 = new CExplosion(pkill->GetPoint().x, pboss->GetPoint().y);
				 listExplosion.AddTail(explosion1);
				 CExplosion *explosion2 = new CExplosion(pkill->GetPoint().x, pboss->GetPoint().y + 40);
				 listExplosion.AddTail(explosion2);
				 CExplosion *explosion3 = new CExplosion(pkill->GetPoint().x, pboss->GetPoint().y + 80);
				 listExplosion.AddTail(explosion3);
				 CExplosion *explosion4 = new CExplosion(pkill->GetPoint().x, pboss->GetPoint().y + 120);
				 listExplosion.AddTail(explosion4);
				 CExplosion *explosion5 = new CExplosion(pkill->GetPoint().x, pboss->GetPoint().y + 160);
				 listExplosion.AddTail(explosion5);
				 pboss->SetLife(60);
				 if (pboss->GetLife() <= 0)
				 {
					 for (int k = 1; k < 50; k++)
					 {
						 CExplosion *explosion1 = new CExplosion(pboss->GetPoint().x + rand() % 300, pboss->GetPoint().y + rand() % (pboss->GetRect().bottom));
						 listExplosion.AddTail(explosion1);
					 }
					
					 listBoss.RemoveAll();
				 }
			 }
			 listKill.RemoveAll();
		 }
	 }

	 for (posBomb = listBomb.GetHeadPosition(); posBomb != NULL;)
	 {
		 int nn=0;
		 POSITION pos12;
		 pos12 = posBomb;
		 CBomb *pBomb = (CBomb*)listBomb.GetNext(posBomb);
		 pBomb->Draw(&demo, false);
		 if (pBomb->GetPoint().y < rect.top)
		 {
			 listBomb.RemoveAt(pos12);
			 nn = 1;
			 continue;
		 }
		 //1 号
		 for (posEnemy = listEnemy.GetHeadPosition(); posEnemy != NULL;)
		 {
			 POSITION pos1;
			 pos1 = posEnemy;
			 CEnemy *pEnemy = (CEnemy*)listEnemy.GetNext(posEnemy);
			 CRect  interRect;
			 int intersection = interRect.IntersectRect(pBomb->GetRect(), pEnemy->GetRect());
			 if (intersection)
			 {
				 CExplosion *explosion1 = new CExplosion(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
				 listExplosion.AddTail(explosion1);
				 nn = 1;
				 if (rand() % 3 == 0)
				 {
					 pEnemy->shan();
					 break;
				 }
				 listBomb.RemoveAt(pos12);
				 pEnemy->SetLife();
				 if (pEnemy->GetLife() == 0)
				 {
					 int x = rand();
					 if (x % 6 == 0)
					 {
						 CTool *addbomb = new CTool(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
						 listAddBomb.AddTail(addbomb);
					 }
					 if (x % 5 == 0)
					 {
						 CAddLife *addlife = new CAddLife(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
						 listAddLife.AddTail(addlife);
					 }
					 if (x % 7 == 0)
					 {
						 CAddKill *addkill = new CAddKill(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
						 listAddKill.AddTail(addkill);
					 }
					 listEnemy.RemoveAt(pos1);
				 }

				 // 产生道具

				 break;
			 }
		 }
		 if (nn)break;
		 for (posEnemy = listEnemy_1.GetHeadPosition(); posEnemy != NULL;)
		 {
			 POSITION pos1;
			 pos1 = posEnemy;
			 CEnemy *pEnemy = (CEnemy*)listEnemy_1.GetNext(posEnemy);
			 
			 CRect  interRect;
			 int intersection = interRect.IntersectRect(pBomb->GetRect(), pEnemy->GetRect());
			 if (intersection)
			 {
				 CExplosion *explosion1 = new CExplosion(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
				 listExplosion.AddTail(explosion1);
				 if (rand() % 3 == 0)
				 {
					 pEnemy->shan();
					 break;
				 }
				 listBomb.RemoveAt(pos12);
				 nn = 1;
				 listEnemy_1.RemoveAt(pos1);
				
				int x = rand();
			    if (x % 6 == 0)
					 {
						 CTool *addbomb = new CTool(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
						 listAddBomb.AddTail(addbomb);
					 }
			    if (x % 5 == 0)
					 {
						 CAddLife *addlife = new CAddLife(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
						 listAddLife.AddTail(addlife);
					 }
			    if (x % 7 == 0)
					 {
						 CAddKill *addkill = new CAddKill(pEnemy->GetPoint().x, pEnemy->GetPoint().y);
						 listAddKill.AddTail(addkill);
					 }
			

				 // 产生道具

				 break;
			 }
		 }
	 }

	 //=======================================================================================================================================

	 // ==========================================================  爆炸  ====================================================================
	 POSITION posExploson;
	 for (posExploson = listExplosion.GetHeadPosition(); posExploson != NULL;)
	 {
		 POSITION pos1 = posExploson;
		 CExplosion *pExplosion = (CExplosion*)listExplosion.GetNext(posExploson);
		 pExplosion->Draw(&demo, false);
		 if (pExplosion->GetProcess() > 8)
		 {
			 listExplosion.RemoveAt(pos1);
		 }
	 }

	 //======================================== ================================================================================================


	 //  ==========================================================  敌人子弹类  ==============================================================
	 POSITION posBall; 
	 for (posBall = listBall.GetHeadPosition(); ( posBall) != NULL;)
	 {
		 POSITION pos12 = posBall;
		 CBall *pBall = (CBall*)listBall.GetAt(pos12);
		 
		 
		 // 攻击到---
		 CRect  interRect;
		 int intersection = interRect.IntersectRect(pBall->GetRect(), myplane.GetRect());
		 if (intersection > 0)
		 { 
			 CExplosion *explosion1 = new CExplosion(myplane.GetPoint().x, myplane.GetPoint().y);
			 listExplosion.AddTail(explosion1);
			 listBall.GetNext(posBall);
			 listBall.RemoveAt(pos12);
			 
			 int k = 0;
			 if (k == 0) {
				 myplane.SetLife(-1); k++;
			 }
			 continue;
		 }
		 if (pBall->GetRect().bottom >= rect.bottom)
		 {
			 listBall.GetNext(posBall);
			 listBall.RemoveAt(pos12);

			 continue;
		 }
		 CBall *pBall1 = (CBall*)listBall.GetNext(posBall);
		 pBall1->Draw(&demo, false);
	 }
	 
	 //==========================================================================================================================================
	
	 
	 // ======================================================= ==== 道具类 ==================================================================
     // 加子弹
	 POSITION posaddbomb;
	 for (posaddbomb = listAddBomb.GetHeadPosition(); posaddbomb != NULL;)
	 {
		 POSITION pos12;
		 pos12 = posaddbomb;
		 CTool *addbomb = (CTool *)listAddBomb.GetNext(posaddbomb);
		 if (addbomb != NULL)
		 {
			 addbomb->Draw(&demo, false);
		 }
		 if (addbomb->GetRect().bottom >= rect.bottom)
		 {
			 listAddBomb.RemoveAt(pos12);
		 }
		 CRect  interRect;
		 int intersection = interRect.IntersectRect(addbomb->GetRect(), myplane.GetRect());
		 if (intersection > 0)
		 { 
			 listAddBomb.RemoveAt(pos12);
			 bomb.Set_Max_Size(1);
		 }

	 }
	 // 加生命
	 POSITION posaddlife;
	 for (posaddlife = listAddLife.GetHeadPosition(); posaddlife != NULL;)
	 {
		 POSITION pos12;
		 pos12 = posaddlife;
		 CTool *addlife = (CTool *)listAddLife.GetNext(posaddlife);
		 if (addlife != NULL)
		 {
			 addlife->Draw(&demo, false);
		 }
		 if (addlife->GetRect().bottom >= rect.bottom)
		 {
			 listAddLife.RemoveAt(pos12);
		 }
		 CRect  interRect;
		 int intersection = interRect.IntersectRect(addlife->GetRect(), myplane.GetRect());
		 if (intersection > 0)
		 {
			 listAddLife.RemoveAt(pos12);
			 myplane.SetLife(2);

		 }

	 }
	 // 加能量
	 POSITION posaddkill;
	 for (posaddkill = listAddKill.GetHeadPosition(); posaddkill != NULL;)
	 {
		 POSITION pos12;
		 pos12 = posaddkill;
		 CAddKill *addkill = (CAddKill *)listAddKill.GetNext(posaddkill);
		 if (addkill != NULL)
		 {
			 addkill->Draw(&demo, false);
		 }
		 if (addkill->GetRect().bottom >= rect.bottom)
		 {
			 listAddKill.RemoveAt(pos12);
		 }
		 CRect  interRect;
		 int intersection = interRect.IntersectRect(addkill->GetRect(), myplane.GetRect());
		 if (intersection > 0)
		 {
			 listAddKill.RemoveAt(pos12);
			 myplane.SetNumber(10);

		 }

	 }
	 //=======================================================================================================================================
    

	 // 关卡

	 if (boss1.number == 1 && listBoss.GetSize() == 0 && (listEnemy.GetSize() + listEnemy_1.GetSize()) == 0)
	 {
		 guan = 2;
		 
	 }
	 if (boss1.number == 2 && listBoss.GetSize() == 0 && (listEnemy.GetSize() + listEnemy_1.GetSize()) == 0)
	 {
		 guan = 3;

	 }

	 if (cnt % 2 == 0)
	 {
		 myplane.gaixue(life);
		 myplane.killnumber = kill;
	 }
	 pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &demo, 0, 0, SRCCOPY);
	 bmp.DeleteObject();
	 demo.DeleteDC();
	 ReleaseDC(pDC);
	 ReleaseDC(&demo);

	CView::OnTimer(nIDEvent);
}


int CMFCApplication5View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (AfxMessageBox(_T("游戏开始，消灭BOSS后小怪不再产出，最后消灭小怪即可通关"), MB_OK) == 1)//MB_OK表示在弹出的窗口中之前是一个OK按键
		SetTimer(1, 30, NULL);

	

	
	// TODO:  在此添加您专用的创建代码
	SetTimer(1, 30, 0);
	SetTimer(4, 500, 0);
	SetTimer(2, 3000, 0);
	SetTimer(3, 4000, 0);
	myplane.LoadImageW();
	CEnemy::LoadImageW();
	CEnemy_1::LoadImageW();
	CBomb::LoadImageW();
	CExplosion::LoadImageW();
	CBall::LoadImageW();
	Ckill::LoadImageW();
	CBoss::LoadImageW();
	CE_Bomb::LoadImageW();
	CTool::LoadImageW();
	CAddLife::LoadImageW();
	CAddKill::LoadImageW();
	CBoss2::LoadImageW();
	CBoss_2::LoadImageW();
	//boss.LoadImageW();
	CB_Xue::LoadImageW();
	srand(GetTickCount());
	return 0;
}


void CMFCApplication5View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CRect rect;
	GetClientRect(&rect);
	
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == VK_LEFT && myplane.GetRect().left >= rect.left)myplane.SetHorMotion(-1);
	if (nChar == VK_RIGHT && myplane.GetRect().right <= rect.right)myplane.SetHorMotion(1);
	if (nChar == VK_UP && myplane.GetRect().top >= rect.top)myplane.SetVerMotion(-1);
	if (nChar == VK_DOWN && myplane.GetRect().bottom <= rect.bottom)myplane.SetVerMotion(1);
	if (nChar == VK_NUMPAD3)
	{
		cnt++;

	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



