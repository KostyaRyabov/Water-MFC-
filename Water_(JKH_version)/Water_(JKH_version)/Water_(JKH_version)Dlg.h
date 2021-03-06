
// Water_(JKH_version)Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CWaterJKHversionDlg
class CWaterJKHversionDlg : public CDialogEx
{
// Создание
public:
	CWaterJKHversionDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WATER_JKH_VERSION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl pr_H;
	CProgressCtrl pr_C;
	CProgressCtrl pr_D;
	CProgressCtrl pr_R;
	float el_H;
	float el_C;
	float el_D;
	float el_R;
	CScrollBar sb_H;
	CScrollBar sb_C;
	CScrollBar sb_D;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
