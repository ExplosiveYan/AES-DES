#pragma once
#include "resource.h"
#include "afxcmn.h"

// CAesAboutDlg �Ի���

class CAesAboutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAesAboutDlg)

public:
	CAesAboutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAesAboutDlg();

// �Ի�������
	enum { IDD = IDD_AES_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnNMClickSyslink3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslink4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslink5(NMHDR *pNMHDR, LRESULT *pResult);
};
