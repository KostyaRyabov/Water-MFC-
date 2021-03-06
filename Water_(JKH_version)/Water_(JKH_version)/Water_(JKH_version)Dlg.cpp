
// Water_(JKH_version)Dlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Water_(JKH_version).h"
#include "Water_(JKH_version)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CWaterJKHversionDlg



CWaterJKHversionDlg::CWaterJKHversionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WATER_JKH_VERSION_DIALOG, pParent)
	, el_H(0)
	, el_C(0)
	, el_R(0)
	, el_D(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWaterJKHversionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, pr_H);
	DDX_Control(pDX, IDC_PROGRESS2, pr_C);
	DDX_Control(pDX, IDC_PROGRESS4, pr_D);
	DDX_Control(pDX, IDC_PROGRESS3, pr_R);

	pr_H.SetRange(0, 100);
	pr_C.SetRange(0, 100);
	pr_D.SetRange(0, 100);
	pr_R.SetRange(0, 10000);

	DDX_Text(pDX, IDC_EDIT1, el_H);
	DDX_Text(pDX, IDC_EDIT2, el_C);
	DDX_Text(pDX, IDC_EDIT3, el_R);
	DDX_Text(pDX, IDC_EDIT4, el_D);

	DDX_Control(pDX, IDC_SCROLLBAR1, sb_H);
	DDX_Control(pDX, IDC_SCROLLBAR2, sb_C);
	DDX_Control(pDX, IDC_SCROLLBAR3, sb_D);

	sb_H.SetScrollRange(0, 100);
	sb_C.SetScrollRange(0, 100);
	sb_D.SetScrollRange(0, 100);

	SetTimer(1, 10, NULL);
}

BEGIN_MESSAGE_MAP(CWaterJKHversionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// Обработчики сообщений CWaterJKHversionDlg

BOOL CWaterJKHversionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CWaterJKHversionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CWaterJKHversionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CWaterJKHversionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWaterJKHversionDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CDialogEx::OnTimer(nIDEvent);

	if (nIDEvent == 1) {
		UpdateData();

		el_R += (el_H + el_C - el_D) / 100;

		if (el_R > 10000) el_R = 10000;
		else if (el_R < 0) el_R = 0;

		pr_R.SetPos(el_R);

		UpdateData(FALSE);
	}
}


void CWaterJKHversionDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного


	switch (nSBCode)
	{
	case SB_TOP:
		if (pScrollBar == &sb_H)
		{
			el_H = 0;
			sb_H.SetScrollPos(0);
			pr_H.SetPos(0);
		}
		else if (pScrollBar == &sb_C)
		{
			el_C = 0;
			sb_C.SetScrollPos(0);
			pr_C.SetPos(0);
		}
		else if (pScrollBar == &sb_D)
		{
			el_D = 0;
			sb_D.SetScrollPos(0);
			pr_D.SetPos(0);
		}
		break;
	case SB_BOTTOM:
		if (pScrollBar == &sb_H)
		{
			el_H = 100;
			sb_H.SetScrollPos(100);
			pr_D.SetPos(0);
		}
		else if (pScrollBar == &sb_C)
		{
			el_C = 100;
			sb_C.SetScrollPos(100);
			pr_C.SetPos(0);
		}
		else if (pScrollBar == &sb_D)
		{
			el_D = 100;
			sb_D.SetScrollPos(100);
			pr_D.SetPos(0);
		}
		break; 
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		if (pScrollBar == &sb_H) {
			el_H = nPos;
			sb_H.SetScrollPos(nPos);
			pr_H.SetPos(nPos);
		}
		else if (pScrollBar == &sb_C)
		{
			el_C = nPos;
			sb_C.SetScrollPos(nPos);
			pr_C.SetPos(nPos);
		}
		else if (pScrollBar == &sb_D)
		{
			el_D = nPos;
			sb_D.SetScrollPos(nPos);
			pr_D.SetPos(nPos);
		}
		break;
	case SB_LINELEFT:
	case SB_PAGELEFT:
		if (pScrollBar == &sb_H)
		{
			if (el_H > 0) {
				el_H -= 1;
				sb_H.SetScrollPos(el_H);
				pr_H.SetPos(el_H);
			}
			else {
				el_H = 0;
				sb_H.SetScrollPos(0);
				pr_H.SetPos(0);
			}
		}
		else if (pScrollBar == &sb_C)
		{
			if (el_C > 0) {
				el_C -= 1;
				sb_C.SetScrollPos(el_C);
				pr_C.SetPos(el_C);
			}
			else {
				el_C = 0;
				sb_C.SetScrollPos(0);
				pr_C.SetPos(0);
			}
		}
		else if (pScrollBar == &sb_D)
		{
			if (el_D > 0) {
				el_D -= 1;
				sb_D.SetScrollPos(el_D);
				pr_D.SetPos(el_D);
			}
			else {
				el_D = 0;
				sb_D.SetScrollPos(0);
				pr_D.SetPos(0);
			}
		}
		break;
	case SB_LINERIGHT:
	case SB_PAGERIGHT:
		if (pScrollBar == &sb_H)
		{
			if (el_H < 100) {
				el_H += 1;
				sb_H.SetScrollPos(el_H);
				pr_H.SetPos(el_H);
			}
			else {
				el_H = 100;
				sb_H.SetScrollPos(100);
				pr_H.SetPos(100);
			}
		}
		else if (pScrollBar == &sb_C)
		{
			if (el_C < 100) {
				el_C += 1;
				sb_C.SetScrollPos(el_C);
				pr_C.SetPos(el_C);
			}
			else {
				el_C = 100;
				sb_C.SetScrollPos(100);
				pr_C.SetPos(100);
			}
		}
		else if (pScrollBar == &sb_D)
		{
			if (el_D < 100) {
				el_D += 1;
				sb_D.SetScrollPos(el_D);
				pr_D.SetPos(el_D);
			}
			else {
				el_D = 100;
				sb_D.SetScrollPos(100);
				pr_D.SetPos(100);
			}
		}
		break;
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

	UpdateData(FALSE);
}
