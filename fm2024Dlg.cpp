
// fm2024Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "fm2024.h"
#include "fm2024Dlg.h"
#include "afxdialogex.h"

#include "afxwin.h"
#include "fstream"
#include "sstream"
#include "vector"
#include "string"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//이중 순환 연결리스트
struct Node {
	player data;
	Node* next;
	Node* prev;

	Node(player val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() : head(nullptr) {}

	void Insert(player data) {
		Node* newNode = new Node(data);

		if (!head) {
			head = newNode;
			head->next = head;
			head->prev = head;
		}
		else {
			Node* tail = head->prev;
			tail->next = newNode;
		}
	}
	void Delete(player data) {

	}
};
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cfm2024Dlg 대화 상자



Cfm2024Dlg::Cfm2024Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FM2024_DIALOG, pParent)
	, m_strName(_T(""))

	, m_intAcceleration(0)
	, m_intAdaptation(0)
	, m_intAerialReach(0)
	, m_intAge(0)
	, m_intAggression(0)
	, m_intAgility(0)
	, m_intAmbition(0)
	, m_intAnticipation(0)
	, m_intArgue(0)
	, m_intBalance(0)
	, m_strBirth(_T(""))
	, m_intBravery(0)
	, m_intCOA(0)
	, m_intCommunication(0)
	, m_intComposure(0)
	, m_intConcentration(0)
	, m_intCorners(0)
	, m_intHeight(0)
	, m_intWeight(0)
	, m_intCP(0)
	, m_intCrossing(0)
	, m_intDecision(0)
	, m_intDetermination(0)
	, m_intDiversity(0)
	, m_intDribbling(0)
	, m_intEccentricity(0)
	, m_intEmotional_control(0)
	, m_intFinishing(0)
	, m_intFirst_touch(0)
	, m_intFlair(0)
	, m_intFoul(0)
	, m_intFree_kick(0)
	, m_intHandling(0)
	, m_intHeading(0)
	, m_intInjury(0)
	, m_intJumping_reach(0)
	, m_intKicking(0)
	, m_intLeadership(0)
	, m_intLong_shot(0)
	, m_intLong_throw(0)
	, m_intLoyal(0)
	, m_intMarking(0)
	, m_intNatural_fitness(0)
	, m_intOff_the_ball(0)
	, m_intOne_on_ones(0)
	, m_intPace(0)
	, m_intPassing(0)
	, m_intPenalty_taking(0)
	, m_intProfessional(0)
	, m_intPunching(0)
	, m_intReflexes(0)
	, m_intResistant_of_stress(0)
	, m_intRushing_out(0)
	, m_intSportsmanship(0)
	, m_intStability(0)
	, m_intStamina(0)
	, m_intStrength(0)
	, m_intTackling(0)
	, m_intTeamwork(0)
	, m_intTechnique(0)
	, m_intThrowing(0)
	, m_intVision(0)
	, m_intWork_rate(0)
	, m_strPosition(_T(""))
	, m_intPosition_stat(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cfm2024Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);


	DDX_Text(pDX, IDC_EDIT_ACCELERATION, m_intAcceleration);
	DDX_Text(pDX, IDC_EDIT_ADAPTATION, m_intAdaptation);
	DDX_Text(pDX, IDC_EDIT_AERIAL_REACH, m_intAerialReach);
	DDX_Text(pDX, IDC_EDIT_AGE, m_intAge);
	DDX_Text(pDX, IDC_EDIT_AGGRESSION, m_intAggression);
	DDX_Text(pDX, IDC_EDIT_AGILITY, m_intAgility);
	DDX_Text(pDX, IDC_EDIT_AMBITION, m_intAmbition);
	DDX_Text(pDX, IDC_EDIT_ANTICIPATION, m_intAnticipation);
	DDX_Text(pDX, IDC_EDIT_ARGUE, m_intArgue);
	DDX_Text(pDX, IDC_EDIT_BALANCE, m_intBalance);
	DDX_Text(pDX, IDC_EDIT_BIRTH, m_strBirth);
	DDX_Text(pDX, IDC_EDIT_BRAVERY, m_intBravery);
	DDX_Text(pDX, IDC_EDIT_COA, m_intCOA);
	DDX_Text(pDX, IDC_EDIT_COMMUNICATION, m_intCommunication);
	DDX_Text(pDX, IDC_EDIT_COMPOSURE, m_intComposure);
	DDX_Text(pDX, IDC_EDIT_CONCENTRATION, m_intConcentration);
	DDX_Text(pDX, IDC_EDIT_CORNERS, m_intCorners);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_intHeight);
	DDX_Text(pDX, IDC_EDIT_WEIGHT, m_intWeight);
	DDX_Text(pDX, IDC_EDIT_CP, m_intCP);
	DDX_Text(pDX, IDC_EDIT_CROSSING, m_intCrossing);
	DDX_Text(pDX, IDC_EDIT_DECISION, m_intDecision);
	DDX_Text(pDX, IDC_EDIT_DETERMINATION, m_intDetermination);
	DDX_Text(pDX, IDC_EDIT_DIVERSITY, m_intDiversity);
	DDX_Text(pDX, IDC_EDIT_DRIBBLING, m_intDribbling);
	DDX_Text(pDX, IDC_EDIT_ECCENTRICITY, m_intEccentricity);
	DDX_Text(pDX, IDC_EDIT_EMOTIONAL_CONTROL, m_intEmotional_control);
	DDX_Text(pDX, IDC_EDIT_FINISHING, m_intFinishing);
	DDX_Text(pDX, IDC_EDIT_FIRST_TOUCH, m_intFirst_touch);
	DDX_Text(pDX, IDC_EDIT_FLAIR, m_intFlair);
	DDX_Text(pDX, IDC_EDIT_FOUL, m_intFoul);
	DDX_Text(pDX, IDC_EDIT_FREE_KICK, m_intFree_kick);
	DDX_Text(pDX, IDC_EDIT_HANDLING, m_intHandling);
	DDX_Text(pDX, IDC_EDIT_HEADING, m_intHeading);
	DDX_Text(pDX, IDC_EDIT_INJURY, m_intInjury);
	DDX_Text(pDX, IDC_EDIT_JUMPING_REACH, m_intJumping_reach);
	DDX_Text(pDX, IDC_EDIT_KICKING, m_intKicking);
	DDX_Text(pDX, IDC_EDIT_LEADERSHIP, m_intLeadership);
	DDX_Text(pDX, IDC_EDIT_LONG_SHOT, m_intLong_shot);
	DDX_Text(pDX, IDC_EDIT_LONG_THROW, m_intLong_throw);
	DDX_Text(pDX, IDC_EDIT_LOYAL, m_intLoyal);
	DDX_Text(pDX, IDC_EDIT_MARKING, m_intMarking);
	DDX_Text(pDX, IDC_EDIT_NATURAL_FITNESS, m_intNatural_fitness);
	DDX_Text(pDX, IDC_EDIT_OFF_THE_BALL, m_intOff_the_ball);
	DDX_Text(pDX, IDC_EDIT_ONE_ON_ONES, m_intOne_on_ones);
	DDX_Text(pDX, IDC_EDIT_PACE, m_intPace);
	DDX_Text(pDX, IDC_EDIT_PASSING, m_intPassing);
	DDX_Text(pDX, IDC_EDIT_PENALTY_TAKING, m_intPenalty_taking);
	DDX_Text(pDX, IDC_EDIT_PROFESSIONAL, m_intProfessional);
	DDX_Text(pDX, IDC_EDIT_PUNCHING, m_intPunching);
	DDX_Text(pDX, IDC_EDIT_REFLEXES, m_intReflexes);
	DDX_Text(pDX, IDC_EDIT_RESISTANT_OF_STRESS, m_intResistant_of_stress);
	DDX_Text(pDX, IDC_EDIT_RUSHING_OUT, m_intRushing_out);
	DDX_Text(pDX, IDC_EDIT_SPORTSMANSHIP, m_intSportsmanship);
	DDX_Text(pDX, IDC_EDIT_STABILITY, m_intStability);
	DDX_Text(pDX, IDC_EDIT_STAMINA, m_intStamina);
	DDX_Text(pDX, IDC_EDIT_STRENGTH, m_intStrength);
	DDX_Text(pDX, IDC_EDIT_TACKLING, m_intTackling);
	DDX_Text(pDX, IDC_EDIT_TEAMWORK, m_intTeamwork);
	DDX_Text(pDX, IDC_EDIT_TECHNIQUE, m_intTechnique);
	DDX_Text(pDX, IDC_EDIT_THROWING, m_intThrowing);
	DDX_Text(pDX, IDC_EDIT_VISION, m_intVision);
	DDX_Text(pDX, IDC_EDIT_WORK_RATE, m_intWork_rate);
	DDX_Text(pDX, IDC_EDIT_POSITION, m_strPosition);
	DDX_Text(pDX, IDC_EDIT_POSITION_STAT, m_intPosition_stat);
}

BEGIN_MESSAGE_MAP(Cfm2024Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Cfm2024Dlg 메시지 처리기

BOOL Cfm2024Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cfm2024Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cfm2024Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cfm2024Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cfm2024Dlg::ReadCSVFile(const CString& filePath)
{
	// TODO: 여기에 구현 코드 추가.
	//파일 스트림 생성
	std::ifstream file((CT2CA)filePath);

	//파일 열기 성공 확인
	if (!file.is_open()) {
		AfxMessageBox(_T("파일을 열 숭 없습니다."));
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream lineStream(line);
		std::string cell;
		std::vector<std::string> rowData;

		while (std::getline(lineStream, cell, ',')) {
			rowData.push_back(cell);
		}

		for (const auto& data : rowData) {
			AfxMessageBox(CString(data.c_str()));
		}
	}

	file.close();
}

