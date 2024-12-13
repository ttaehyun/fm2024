#pragma once
#include "afxdialogex.h"


// Mainmenu 대화 상자

class Mainmenu : public CDialogEx
{
	DECLARE_DYNAMIC(Mainmenu)

public:
	Mainmenu(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Mainmenu();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_START };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonStart();
	bool m_bOK;
	afx_msg void OnClickedButtonMaker();
};
