// SearchDlg.cpp: 구현 파일
//

#include "pch.h"
#include "fm2024.h"
#include "afxdialogex.h"
#include "SearchDlg.h"


// SearchDlg 대화 상자

IMPLEMENT_DYNAMIC(SearchDlg, CDialogEx)

SearchDlg::SearchDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SEARCH, pParent)

	, m_nStat1Min(0)
	, m_nStat1Max(20)
	, m_nStat2Min(0)
	, m_nStat2Max(20)
	, m_nStat3Max(20)
	, m_nStat3Min(0)
	, m_nWeightMin(0)
	, m_nWeightMax(0)
	, m_nHeightMin(0)
	, m_nHeightMax(0)
	, m_nAgeMin(0)
	, m_nAgeMax(0)
	, m_nLeftFootMin(0)
	, m_nLeftFootMax(20)
	, m_nRightFootMin(0)
	, m_nRightFootMax(20)
{
	
}

SearchDlg::~SearchDlg()
{
}

void SearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_STAT1_MIN, m_nStat1Min);
	DDX_Text(pDX, IDC_EDIT_STAT1_MAX, m_nStat1Max);
	DDX_Text(pDX, IDC_EDIT_STAT2_MIN, m_nStat2Min);
	DDX_Text(pDX, IDC_EDIT_STAT2_MAX, m_nStat2Max);
	DDX_Text(pDX, IDC_EDIT_STAT3_MAX, m_nStat3Max);
	DDX_Text(pDX, IDC_EDIT_STAT3_MIN, m_nStat3Min);
	DDX_Text(pDX, IDC_EDIT_WEIGHT_MIN, m_nWeightMin);
	DDX_Text(pDX, IDC_EDIT_WEIGHT_MAX, m_nWeightMax);
	DDX_Text(pDX, IDC_EDIT_HEIGHT_MIN, m_nHeightMin);
	DDX_Text(pDX, IDC_EDIT_HEIGHT_MAX, m_nHeightMax);
	DDX_Text(pDX, IDC_EDIT_AGE_MIN, m_nAgeMin);
	DDX_Text(pDX, IDC_EDIT_AGE_MAX, m_nAgeMax);
	DDX_Text(pDX, IDC_EDIT_LEFTFOOT_MIN, m_nLeftFootMin);
	DDX_Text(pDX, IDC_EDIT_LEFTFOOT_MAX, m_nLeftFootMax);
	DDX_Text(pDX, IDC_EDIT_RIGHTFOOT_MIN, m_nRightFootMin);
	DDX_Text(pDX, IDC_EDIT_RIGHTFOOT_MAX, m_nRightFootMax);
	DDX_Control(pDX, IDC_COMBO_STAT1, m_cbStat1);
	DDX_Control(pDX, IDC_COMBO_STAT2, m_cbStat2);
	DDX_Control(pDX, IDC_COMBO_STAT3, m_cbStat3);
}


BEGIN_MESSAGE_MAP(SearchDlg, CDialogEx)
	


	ON_BN_CLICKED(IDC_CHECK_STAT1, &SearchDlg::OnClickedCheckStat1)
	ON_BN_CLICKED(IDC_CHECK_STAT2, &SearchDlg::OnClickedCheckStat2)
	ON_BN_CLICKED(IDC_CHECK_STAT3, &SearchDlg::OnClickedCheckStat3)
	ON_BN_CLICKED(IDC_CHECK_HEIGHT, &SearchDlg::OnClickedCheckHeight)
	ON_BN_CLICKED(IDC_CHECK_WEIGHT, &SearchDlg::OnClickedCheckWeight)
	ON_BN_CLICKED(IDC_CHECK_AGE, &SearchDlg::OnClickedCheckAge)
	ON_BN_CLICKED(IDC_CHECK_LEFTFOOT, &SearchDlg::OnClickedCheckLeftfoot)
	ON_BN_CLICKED(IDC_CHECK_RIGHTFOOT, &SearchDlg::OnClickedCheckRightfoot)


	ON_BN_CLICKED(IDOK, &SearchDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SearchDlg 메시지 처리기

void SearchDlg::OnClickedCheckStat1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (m_bChecked[0] == FALSE) {
		m_bChecked[0] = TRUE;
		
	}
	else m_bChecked[0] = FALSE;
}


void SearchDlg::OnClickedCheckStat2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[1] == FALSE) m_bChecked[1] = TRUE;
	else m_bChecked[1] = FALSE;
}


void SearchDlg::OnClickedCheckStat3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[2] == FALSE) m_bChecked[2] = TRUE;
	else m_bChecked[2] = FALSE;
}


void SearchDlg::OnClickedCheckHeight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[3] == FALSE) m_bChecked[3] = TRUE;
	else m_bChecked[3] = FALSE;
}


void SearchDlg::OnClickedCheckWeight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[4] == FALSE) m_bChecked[4] = TRUE;
	else m_bChecked[4] = FALSE;
}


void SearchDlg::OnClickedCheckAge()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[5] == FALSE) m_bChecked[5] = TRUE;
	else m_bChecked[5] = FALSE;
}


void SearchDlg::OnClickedCheckLeftfoot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[6] == FALSE) m_bChecked[6] = TRUE;
	else m_bChecked[6] = FALSE;
}


void SearchDlg::OnClickedCheckRightfoot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[7] == FALSE) m_bChecked[7] = TRUE;
	else m_bChecked[7] = FALSE;
}

BOOL SearchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_bChecked[0] = m_bChecked[1] = m_bChecked[2] = m_bChecked[3] = m_bChecked[4] = m_bChecked[5] = m_bChecked[6] = m_bChecked[7] = FALSE;
	
	AddComboBox(m_cbStat1);
	AddComboBox(m_cbStat2);
	AddComboBox(m_cbStat3);
	m_cbStat1.SetCurSel(0);
	m_cbStat2.SetCurSel(0);
	m_cbStat3.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void SearchDlg::AddComboBox(CComboBox& m_cbStat)
{
	// TODO: 여기에 구현 코드 추가.
	m_cbStat.AddString(_T("Corners"));
	m_cbStat.AddString(_T("Crossing"));
	m_cbStat.AddString(_T("Dribbling"));
	m_cbStat.AddString(_T("Finishing"));
	m_cbStat.AddString(_T("First Touch"));
	m_cbStat.AddString(_T("Free Kick"));
	m_cbStat.AddString(_T("Heading"));
	m_cbStat.AddString(_T("Long Shots"));
	m_cbStat.AddString(_T("Long Throws"));
	m_cbStat.AddString(_T("Marking"));
	m_cbStat.AddString(_T("Passing"));
	m_cbStat.AddString(_T("Penalty Taking"));
	m_cbStat.AddString(_T("Tackling"));
	m_cbStat.AddString(_T("Technique"));
	m_cbStat.AddString(_T("Aggressiion"));
	m_cbStat.AddString(_T("Anticipation"));
	m_cbStat.AddString(_T("Bravery"));
	m_cbStat.AddString(_T("Composure"));
	m_cbStat.AddString(_T("Concentration"));
	m_cbStat.AddString(_T("Vision"));
	m_cbStat.AddString(_T("Decision"));
	m_cbStat.AddString(_T("Determination"));
	m_cbStat.AddString(_T("Flair"));
	m_cbStat.AddString(_T("Leadership"));
	m_cbStat.AddString(_T("Off The Ball"));
	m_cbStat.AddString(_T("Position"));
	m_cbStat.AddString(_T("Teamwork"));
	m_cbStat.AddString(_T("Work Rate"));
	m_cbStat.AddString(_T("Acceleration"));
	m_cbStat.AddString(_T("Agility"));
	m_cbStat.AddString(_T("Balance"));
	m_cbStat.AddString(_T("Jumping Reach"));
	m_cbStat.AddString(_T("Natural Fitness"));
	m_cbStat.AddString(_T("Pace"));
	m_cbStat.AddString(_T("Stamina"));
	m_cbStat.AddString(_T("Strength"));
	m_cbStat.AddString(_T("Stability"));
	m_cbStat.AddString(_T("Foul"));
	m_cbStat.AddString(_T("Contest performance"));
	m_cbStat.AddString(_T("Injury"));
	m_cbStat.AddString(_T("diversity"));
	m_cbStat.AddString(_T("Aerial Reach"));
	m_cbStat.AddString(_T("Command Of Area"));
	m_cbStat.AddString(_T("Communication"));
	m_cbStat.AddString(_T("Eccentricity"));
	m_cbStat.AddString(_T("Handling"));
	m_cbStat.AddString(_T("Kicking"));
	m_cbStat.AddString(_T("One On Ones"));
	m_cbStat.AddString(_T("Reflexes"));
	m_cbStat.AddString(_T("Rushing Out"));
	m_cbStat.AddString(_T("Punching"));
	m_cbStat.AddString(_T("Throwing"));
	m_cbStat.AddString(_T("Adaptation"));
	m_cbStat.AddString(_T("Ambition"));
	m_cbStat.AddString(_T("Argue"));
	m_cbStat.AddString(_T("Loyal"));
	m_cbStat.AddString(_T("Resistant to stress"));
	m_cbStat.AddString(_T("Professional"));
	m_cbStat.AddString(_T("Sportsmanship"));
	m_cbStat.AddString(_T("Emotional control"));
}


void SearchDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다
	int index = m_cbStat1.GetCurSel();
	m_cbStat1.GetLBText(index, m_strStat1);
	m_cbStat2.GetLBText(m_cbStat2.GetCurSel(), m_strStat2);
	m_cbStat3.GetLBText(m_cbStat3.GetCurSel(), m_strStat3);
	CDialogEx::OnOK();
}
