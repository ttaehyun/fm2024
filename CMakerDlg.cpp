// CMakerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "fm2024.h"
#include "afxdialogex.h"
#include "CMakerDlg.h"


// CMakerDlg 대화 상자

IMPLEMENT_DYNAMIC(CMakerDlg, CDialogEx)

CMakerDlg::CMakerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MAKER, pParent)
{

}

CMakerDlg::~CMakerDlg()
{
}

void CMakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMakerDlg, CDialogEx)
END_MESSAGE_MAP()


// CMakerDlg 메시지 처리기
