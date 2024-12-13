// Mainmenu.cpp: 구현 파일
//

#include "pch.h"
#include "fm2024.h"
#include "afxdialogex.h"
#include "Mainmenu.h"
#include "SelDlg.h"
#include "CMakerDlg.h"
// Mainmenu 대화 상자

IMPLEMENT_DYNAMIC(Mainmenu, CDialogEx)

Mainmenu::Mainmenu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_START, pParent)
{
	m_bOK = false;
}

Mainmenu::~Mainmenu()
{
}

void Mainmenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Mainmenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_START, &Mainmenu::OnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_MAKER, &Mainmenu::OnClickedButtonMaker)
END_MESSAGE_MAP()


// Mainmenu 메시지 처리기


void Mainmenu::OnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SelDlg dlg;
	dlg.DoModal();
}


void Mainmenu::OnClickedButtonMaker()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMakerDlg dlg;
	dlg.DoModal();
}
