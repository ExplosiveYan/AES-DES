
// AESDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Main.h"
#include "MainDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RED     RGB(255,0,0)
#define YELLOW  RGB(255,255,0)
#define MAGENTA RGB(255,0,255)
#define WHITE   RGB(255,255,255)
#define BLUE    RGB(0,0,255)


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMainDlg �Ի���



CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMainDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMainDlg ��Ϣ�������

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tab.InsertItem(0, _T("�������"));
	m_tab.InsertItem(1, _T("�������"));
	m_tab.InsertItem(2, _T("�ļ�����"));
	m_tab.InsertItem(3, _T("�ļ�����"));
	m_tab.InsertItem(4, _T("����"));
	// �����Ի������ǩҳ
	groupEnDlg.Create(IDD_AES_GROUP_EN, &m_tab);
	groupDeDlg.Create(IDD_AES_GROUP_DE, &m_tab);
	fileEnDlg.Create(IDD_AES_FILE_EN, &m_tab);
	fileDeDlg.Create(IDD_AES_FILE_DE, &m_tab);
	aboutDlg.Create(IDD_AES_ABOUT, &m_tab);
	// �趨��Tab����ʾ�ķ�Χ
	CRect rc;
	m_tab.GetClientRect(&rc);
	rc.top += 22;
	rc.bottom -= 3;
	rc.left += 1;
	rc.right -= 3;
	groupEnDlg.MoveWindow(&rc);
	groupDeDlg.MoveWindow(&rc);
	fileEnDlg.MoveWindow(&rc);
	fileDeDlg.MoveWindow(&rc);
	aboutDlg.MoveWindow(&rc);
	// ��ʾ��ʼҳ��
	groupEnDlg.ShowWindow(SW_SHOW);
	groupDeDlg.ShowWindow(SW_HIDE);
	fileEnDlg.ShowWindow(SW_HIDE);
	fileDeDlg.ShowWindow(SW_HIDE);
	aboutDlg.ShowWindow(SW_HIDE);
	// ����Ĭ��ѡ�
	m_tab.SetCurSel(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Tab��ǩҳ�����Ӧ����
void CMainDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int curSel = m_tab.GetCurSel();
	switch (curSel)
	{
	case 0:
		groupEnDlg.ShowWindow(SW_SHOW);
		groupDeDlg.ShowWindow(SW_HIDE);
		fileEnDlg.ShowWindow(SW_HIDE);
		fileDeDlg.ShowWindow(SW_HIDE);
		aboutDlg.ShowWindow(SW_HIDE);
		break;
	case 1:
		groupEnDlg.ShowWindow(SW_HIDE);
		groupDeDlg.ShowWindow(SW_SHOW);
		fileEnDlg.ShowWindow(SW_HIDE);
		fileDeDlg.ShowWindow(SW_HIDE);
		aboutDlg.ShowWindow(SW_HIDE);
		break;
	case 2:
		groupEnDlg.ShowWindow(SW_HIDE);
		groupDeDlg.ShowWindow(SW_HIDE);
		fileEnDlg.ShowWindow(SW_SHOW);
		fileDeDlg.ShowWindow(SW_HIDE);
		aboutDlg.ShowWindow(SW_HIDE);
		break;
	case 3:
		groupEnDlg.ShowWindow(SW_HIDE);
		groupDeDlg.ShowWindow(SW_HIDE);
		fileEnDlg.ShowWindow(SW_HIDE);
		fileDeDlg.ShowWindow(SW_SHOW);
		aboutDlg.ShowWindow(SW_HIDE);
		break;
	case 4:
		groupEnDlg.ShowWindow(SW_HIDE);
		groupDeDlg.ShowWindow(SW_HIDE);
		fileEnDlg.ShowWindow(SW_HIDE);
		fileDeDlg.ShowWindow(SW_HIDE);
		aboutDlg.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
	*pResult = 0;
}