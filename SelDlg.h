#pragma once
#include "afxdialogex.h"


// SelDlg 대화 상자

class SelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelDlg)

public:
	SelDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SelDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonYoo();
	afx_msg void OnClickedButtonAi();
};
