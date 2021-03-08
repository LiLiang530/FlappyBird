
// ChildView.h: CChildView 类的接口
//


#pragma once


// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 特性
public:
	CRect m_client;
	CRect m_bdpos;//bird's position
	CRect m_RbtnD;
	CRect m_RbtnN;
	CRect m_RbtnP;
	CRect m_RbtnH;
	CBitmap m_bgBitmap;
	CBitmap m_bgDbmp;
	CBitmap m_bgNbmp;
	CBitmap m_bgHbmp;
	CImage m_bird1;
	CImage m_pipeup;
	CImage m_pipedn;
	CImage m_f0;
	CImage m_f1;
	CImage m_f2;
	CImage m_f3;
	CImage m_f4;
	CImage m_f5;
	CImage m_f6;
	CImage m_f7;
	CImage m_f8;
	CImage m_f9;
	CImage m_txt0;
	CImage m_txt1;
	CImage m_txt2;
	CImage m_btnd;
	CImage m_btnn;
	CImage m_btnp;
	CImage m_btnh;
	CImage m_btnok;
	CImage m_gold;
	CImage m_silver;
	int i;//bird's flash
	int m_step;
	int m_game;
	int m_pipev;
	int m_high;//pipe height
	int m_music;
	int m_bg;
	int m_score;
	int m_help;
	int m_luck;
// 操作
public:
	bool CanPass();
	int random();
	bool Crash();
	void ShowScore(CDC* cDC);
// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

