#pragma once
#include "afxdialogex.h"


// SearchDlg 대화 상자

class SearchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SearchDlg)

public:
	SearchDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SearchDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	
	
	afx_msg void OnClickedCheckStat1();
	afx_msg void OnClickedCheckStat2();
	afx_msg void OnClickedCheckStat3();
	afx_msg void OnClickedCheckHeight();
	afx_msg void OnClickedCheckWeight();
	afx_msg void OnClickedCheckAge();
	afx_msg void OnClickedCheckLeftfoot();
	afx_msg void OnClickedCheckRightfoot();
	bool m_bChecked[8];

	int m_nStat1Min;
	int m_nStat1Max;
	int m_nStat2Min;
	int m_nStat2Max;
	int m_nStat3Min;
	int m_nStat3Max;
	int m_nWeightMin;
	int m_nWeightMax;
	int m_nHeightMin;
	int m_nHeightMax;
	int m_nAgeMin;
	int m_nAgeMax;
	int m_nLeftFootMin;
	int m_nLeftFootMax;
	int m_nRightFootMin;
	int m_nRightFootMax;
	CComboBox m_cbStat1;
	CComboBox m_cbStat2;
	CComboBox m_cbStat3;
	virtual BOOL OnInitDialog();
	void AddComboBox(CComboBox& m_cbStat);

	CString m_strStat1;
	CString m_strStat2;
	CString m_strStat3;
	afx_msg void OnBnClickedOk();
};
