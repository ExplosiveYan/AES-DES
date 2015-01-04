#pragma once
#include "resource.h"
#include "afxeditbrowsectrl.h"
#include "afxwin.h"
#include "Aes.h"

// CAesFileDecryptDlg �Ի���

class CAesFileDecryptDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAesFileDecryptDlg)

public:
	CAesFileDecryptDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAesFileDecryptDlg();

// �Ի�������
	enum { IDD = IDD_AES_FILE_DE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int count;  // ���ʱ
	CFont font;
	CString arr[3];
	HANDLE hThread;
	DWORD threadID;
	CMFCEditBrowseCtrl m_editBrowse1;
	CMFCEditBrowseCtrl m_editBrowse2;
	CEdit m_editCtrl;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedDecrypt();
	afx_msg void OnBnClickedClear();
};
