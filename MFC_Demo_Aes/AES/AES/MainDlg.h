
// AESDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "AesGroupEncryptDlg.h"
#include "AesGroupDecryptDlg.h"
#include "AesFileEncryptDlg.h"
#include "AesFileDecryptDlg.h"
#include "AesAboutDlg.h"

// CMainDlg �Ի���
class CMainDlg : public CDialogEx
{
// ����
public:
	CMainDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_AES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CAesGroupEncryptDlg groupEnDlg;  // ������ܱ�ǩҳ
	CAesGroupDecryptDlg groupDeDlg;  // ������ܱ�ǩҳ
	CAesFileEncryptDlg fileEnDlg;    // �ļ����ܱ�ǩҳ
	CAesFileDecryptDlg fileDeDlg;    // �ļ����ܱ�ǩҳ
	CAesAboutDlg aboutDlg;           // ���ڱ�ǩҳ
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
