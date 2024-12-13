// SelDlg.cpp: 구현 파일
//

#include "pch.h"
#include "fm2024.h"
#include "afxdialogex.h"
#include "SelDlg.h"
#include "SearchDlg.h"
#include "fm2024Dlg.h"
// SelDlg 대화 상자

IMPLEMENT_DYNAMIC(SelDlg, CDialogEx)

SelDlg::SelDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SEL, pParent)
{

}

SelDlg::~SelDlg()
{
}

void SelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_YOO, &SelDlg::OnClickedButtonYoo)
	ON_BN_CLICKED(IDC_BUTTON_AI, &SelDlg::OnClickedButtonAi)

END_MESSAGE_MAP()


// SelDlg 메시지 처리기


void SelDlg::OnClickedButtonYoo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Cfm2024Dlg dlg;
	dlg.DoModal();
}


void SelDlg::OnClickedButtonAi()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

