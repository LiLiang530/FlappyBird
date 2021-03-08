
// ChildView.cpp: CChildView 类的实现
//

#include "pch.h"
#include "framework.h"
#include "FlappyBird.h"
#include "ChildView.h"
#include <ctime>
#include "mmsystem.h"
//#include <string.h>

#pragma comment(lib,"winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void TransparentPNG(CImage* png)
{
	for (int k = 0; k < png->GetWidth(); k++)
	{
		for (int j = 0; j < png->GetHeight(); j++)
		{
			unsigned char* pucColor = reinterpret_cast<unsigned char*>(png->GetPixelAddress(k, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
	}
}
// CChildView

CChildView::CChildView()
{
	i = 0;
	m_step = 0;
	m_bdpos.left = 0;
	m_bdpos.top = 245;
	m_bdpos.bottom = 245 + 33;
	m_bdpos.right = 40;
	m_game = 0;
	m_pipev = 0;
	m_high = 250;
	m_music = 0;
	m_score = 0;
	m_bg = 0;
	m_RbtnD.left = 24;
	m_RbtnD.top = 300;
	m_RbtnD.right = 140;
	m_RbtnD.bottom = 365;
	m_RbtnN.left = 144;
	m_RbtnN.top = 300;
	m_RbtnN.right = 260;
	m_RbtnN.bottom = 365;
	m_RbtnP.left = 86;
	m_RbtnP.top = 300;
	m_RbtnP.right = 202;
	m_RbtnP.bottom = 365;
	m_RbtnH.top = 400;
	m_RbtnH.left = 104;
	m_RbtnH.right = 184;
	m_RbtnH.bottom = 428;
	m_help = 0;
	m_luck = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CChildView 消息处理程序

bool CChildView::CanPass()
{
	if (m_bdpos.bottom >=m_client.Height())
	{
		KillTimer(2);
		if (m_music == 0)
		{
			mciSendString(_T("play crash.mp3"), NULL, 0, NULL);
			m_music = 1;
		}
		return false;
	}
	return true;
}

int CChildView::random()
{
	srand((int)time(NULL));
	int H;
	H = rand()%(10)*20+150;
	if (H == 250)
	{
		m_luck = 1;
	}
	else if (H == 170)
	{
		m_luck = 2;
	}
	else
	{
		m_luck = 0;
	}
	return H;
}

bool CChildView::Crash()
{
	if (m_bdpos.right >= 300 - m_pipev && (m_bdpos.top < m_high - 50 || m_bdpos.bottom > m_high + 50))
	{
		KillTimer(2);
		if (m_music == 0)
		{
			mciSendString(_T("play crash.mp3"), NULL, 0, NULL);
			m_music = 1;
		}
		return false;
	}
	else
		return true;
}

void CChildView::ShowScore(CDC* cDC)
{
	if (m_score == 0)
		m_f0.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 1)
		m_f1.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 2)
		m_f2.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 3)
		m_f3.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 4)
		m_f4.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 5)
		m_f5.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 6)
		m_f6.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 7)
		m_f7.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 8)
		m_f8.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 9)
		m_f9.Draw(*cDC, m_client.Width() / 2 - 12, 50, 24, 44);
	else if (m_score == 10)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f0.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 11)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f1.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 12)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f2.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 13)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f3.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 14)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f4.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 15)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f5.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 16)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f6.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 17)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f7.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 18)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f8.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 19)
	{
		m_f1.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f9.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
	else if (m_score == 20)
	{
		m_f2.Draw(*cDC, m_client.Width() / 2 - 24, 50, 24, 44);
		m_f0.Draw(*cDC, m_client.Width() / 2, 50, 24, 44);
	}
}


BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);
	mciSendString(_T("open bg.mp3 alias bgMusic"),NULL,0,NULL);
	mciSendString(_T("play bgMusic repeat"),NULL,0,NULL);

	m_bgBitmap.LoadBitmap(IDB_BITMAP1);
	m_bgDbmp.LoadBitmap(IDB_BITMAP1);
	m_bgHbmp.LoadBitmap(IDB_BITMAP2);
	m_bgNbmp.LoadBitmap(IDB_BITMAP2);

	m_pipeup.Load(_T("pipe_up.png"));
	m_pipedn.Load(_T("pipe_down.png"));
	m_bird1.Load(_T("move2.png"));

	m_f0.Load(_T("font_0.png"));
	m_f1.Load(_T("font_1.png"));
	m_f2.Load(_T("font_2.png"));
	m_f3.Load(_T("font_3.png"));
	m_f4.Load(_T("font_4.png"));
	m_f5.Load(_T("font_5.png"));
	m_f6.Load(_T("font_6.png"));
	m_f7.Load(_T("font_7.png"));
	m_f8.Load(_T("font_8.png"));
	m_f9.Load(_T("font_9.png"));

	m_txt0.Load(_T("title.png"));
	m_txt1.Load(_T("ready.png"));
	m_txt2.Load(_T("over.png"));
	m_gold.Load(_T("gold_m.png"));
	m_silver.Load(_T("silver_m.png"));

	m_btnd.Load(_T("btn_bgd.png"));
	m_btnn.Load(_T("btn_bgn.png"));
	m_btnp.Load(_T("btn_p.png"));
	m_btnh.Load(_T("btn_help.png"));
	m_btnok.Load(_T("btn_ok.png"));

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	CDC* cDC = this->GetDC();
	GetClientRect(m_client);
	CDC cacheDC;//双缓冲绘图
	cacheDC.CreateCompatibleDC(NULL);//
	CBitmap cachebmp;//
	cachebmp.CreateCompatibleBitmap(cDC,m_client.Width(),m_client.Height());//
	cacheDC.SelectObject(&cachebmp);//
	CDC m_bgcDC;
	m_bgcDC.CreateCompatibleDC(NULL);
	m_bgcDC.SetBkMode(TRANSPARENT);
	m_bgcDC.SetTextColor(RGB(0, 0, 0));
	if (m_help == 0)
	{
		if (m_game == 0)
		{
			m_bgcDC.SelectObject(&m_bgBitmap);
			m_bgcDC.TextOut(0, 0, _T("请选择白天/黑夜地图"));
		}
		else
		{
			if (m_bg == 0)
			{
				m_bgcDC.SelectObject(&m_bgDbmp);
			}
			else if (m_bg == 1)
			{
				m_bgcDC.SelectObject(&m_bgNbmp);
			}
		}
		cacheDC.BitBlt(0, 0, m_client.Width() - m_step, m_client.Height(), &m_bgcDC, m_step, 0, SRCCOPY);//
		cacheDC.BitBlt(m_client.Width() - m_step, 0, m_step, m_client.Height(), &m_bgcDC, 0, 0, SRCCOPY);//
		//cDC->TransparentBlt(0,m_client.Height()/2,37,37,&m_birdDC,0,0,37,37,RGB(0,0,0));
		m_bird1.Draw(cacheDC, 0, m_bdpos.top, 40, 33, 40 * i, 0, 40, 33);//
		//cDC->BitBlt(0, 0, m_client.Width(), m_client.Height(), &cacheDC, 0, 0, SRCCOPY);//***
		if (m_game != 0)
		{
			m_pipedn.Draw(cacheDC, 300 - m_pipev, 0, 50, m_high - 50);
			m_pipeup.Draw(cacheDC, 300 - m_pipev, m_high + 50, 50, 510 - m_high);
			if (m_luck == 2&& 300 - m_pipev>38)
				m_gold.Draw(cacheDC, 300 - m_pipev, m_high - 22, 44, 44);
			else if (m_luck==1 && 300 - m_pipev > 38)
				m_silver.Draw(cacheDC, 300 - m_pipev, m_high - 22, 44, 44);
			if (m_game == 2)
			{
				m_txt2.Draw(cacheDC, m_client.Width() / 2 - 102, 150, 204, 54);
				m_btnp.Draw(cacheDC, m_client.Width() / 2 - 58, 300, 116, 70);
			}
		}
		else if (m_game == 0)
		{
			m_txt0.Draw(cacheDC, m_client.Width() / 2 - 89, 50, 178, 48);
			m_txt1.Draw(cacheDC, m_client.Width() / 2 - 98, 150, 196, 62);
			m_btnd.Draw(cacheDC, m_client.Width() / 2 - 120, 300, 116, 70);
			m_btnn.Draw(cacheDC, m_client.Width() / 2, 300, 116, 70);
			m_btnh.Draw(cacheDC, 104, 400, 80, 28);
		}
		cDC->BitBlt(0, 0, m_client.Width(), m_client.Height(), &cacheDC, 0, 0, SRCCOPY);
		if (m_game != 0)
		{
			ShowScore(cDC);
		}
		cacheDC.DeleteDC();// ***8 / 29
		cachebmp.DeleteObject();
	}
	else if (m_help == 1)
	{
		m_bgcDC.SelectObject(&m_bgHbmp);
		m_bgcDC.TextOut(80, 100, _T("按下鼠标左键"));
		m_bgcDC.TextOutW(80, 120, _T("使小鸟向上飞"));
		m_bgcDC.TextOutW(70, 140, _T("避免与管道相撞"));
		m_bgcDC.TextOutW(70, 180, _T("捡到银币加一分"));
		m_bgcDC.TextOutW(70, 200, _T("捡到金币加两分"));
		m_bgcDC.TextOutW(60, 240, _T("选择你喜欢的地图"));
		m_bgcDC.TextOutW(70, 260, _T("然后开始游戏吧"));
		cDC->BitBlt(0, 0, m_client.Width(), m_client.Height(), &m_bgcDC, 0, 0, SRCCOPY);
		m_btnok.Draw(*cDC, 104, 400, 80, 28);
	}
	ValidateRect(&m_client);
	ReleaseDC(cDC);
	//DeleteDC(m_bgcDC);

	CWnd::OnPaint();
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_game==1)
	{
		if (m_bdpos.top-50 > 0)
		{
			m_bdpos.top -= 50;
			m_bdpos.bottom -= 50;
		}
		else
		{
			m_bdpos.top = 0;
			m_bdpos.bottom = 33;
		}
	}
	else if (m_game == 2)
	{
		if ((point.y > m_RbtnP.top && point.y < m_RbtnP.bottom) && (point.x > m_RbtnP.left && point.x < m_RbtnP.right))
		{
			m_game = 0;
			m_pipev = 0;
			m_step = 0;
			m_bdpos.left = 0;
			m_bdpos.top = 245;
			m_bdpos.bottom = 245 + 33;
			m_bdpos.right = 40;
			m_high = random();
			m_score = 0;
			m_music = 0;
			m_bg = 0;
		}
	}
	else if (m_game == 0) 
	{
		//m_game = 1;
		//SetTimer(2, 100, NULL);
		if (m_help==0&&(point.y > m_RbtnD.top && point.y < m_RbtnD.bottom) && (point.x > m_RbtnD.left && point.x < m_RbtnD.right))
		{
			m_game = 1;
			SetTimer(2, 100, NULL);
		}
		else if (m_help == 0 && (point.y > m_RbtnN.top && point.y < m_RbtnN.bottom) && (point.x > m_RbtnN.left && point.x < m_RbtnN.right))
		{
			m_bg = 1;
			m_game = 1;
			SetTimer(2, 100, NULL);
		}
		else if ((point.y > m_RbtnH.top && point.y < m_RbtnH.bottom) && (point.x > m_RbtnH.left && point.x < m_RbtnH.right))
		{
			if (m_help == 0)
			{
				m_help = 1;
			}
			else if (m_help == 1)
			{
				m_help = 0;
			}
		}
	}
		

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1: {
		if (CanPass())
		{
			if (m_game != 2) 
			{
				m_step += 10 / 2;
				if (m_step > m_client.Width())
					m_step = 0;
			}
			if (m_game == 1)
			{
				m_pipev += 10/2;
				if (m_pipev > 350)
				{
					m_pipev = 0;
					m_high = random();
					m_score += 1;
					
				}
				if (m_luck == 1&&300 - m_pipev < 38)
				{
					m_score += 1;
					m_luck = 0;
					mciSendString(_T("play coin.mp3"), NULL, 0, NULL);
				}
				else if (m_luck == 2&&300 - m_pipev < 38)
				{
					m_score += 2;
					m_luck = 0;
					mciSendString(_T("play coin.mp3"), NULL, 0, NULL);
				}
				m_bdpos.top += 4;
				m_bdpos.bottom += 4;
			}
			if (!Crash())
			{
				m_game = 2;
			}
		}
		else
		{
			m_game = 2;
		}
		OnPaint();
		break;
	}
	case 2: {
		i++;
		if (i == 3)
			i = 0;
	}
	//default:
		break;
	}

	CWnd::OnTimer(nIDEvent);

}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, 50, NULL);
	return 0;
}
