#pragma once
#include "resource.h"
#include "Aes.h"
#include "afxwin.h"
// CAesGroupEncryptDlg �Ի���

class CAesGroupEncryptDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAesGroupEncryptDlg)

public:
	CAesGroupEncryptDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAesGroupEncryptDlg();

// �Ի�������
	enum { IDD = IDD_AES_GROUP_EN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_plainEdit;
	CEdit m_keyEdit;
	CStatic m_cipherText;
	CListBox m_listBox1;
	CListBox m_listBox2;
	CString plainToCString(Byte plain[]);
	afx_msg void OnBnClickedEncryptTest();
	afx_msg void OnBnClickedButton2();
	CString m_plain;
	CString m_key;
};
