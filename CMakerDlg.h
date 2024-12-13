#pragma once
#include "afxdialogex.h"


// CMakerDlg 대화 상자

class CMakerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMakerDlg)

public:
	CMakerDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMakerDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAKER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
