
// fm2024Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "fm2024.h"
#include "fm2024Dlg.h"
#include "afxdialogex.h"
#include "SearchDlg.h"

#include "afxwin.h"
#include "fstream"
#include "sstream"
#include "iostream"
#include "vector"
#include "string"
#include "map"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//이중 순환 연결리스트
class Node {
public:
	Player data;
	Node* next;
	Node* prev;
	int index;
	Node(const Player& data, int index = 0) : data(data), next(nullptr), prev(nullptr), index(index) {}
};

class LinkedList {

public:
	Node* head;
	Node* current;
	LinkedList() : head(nullptr), current(nullptr) {}

	int GetCurrentIndex() const {
		if (current) {
			return current->index;
		}
		return -1; // 노드가 없을 경우
	}

	void Insert(const Player& data) {
		int newIndex = head ? head->prev->index + 1 : 1; //새 노드의 인덱스 계산
		Node* newNode = new Node(data, newIndex);

		if (!head) {
			head = newNode;
			head->next = head;
			head->prev = head;
		}
		else {
			Node* tail = head->prev;
			tail->next = newNode;
			newNode->prev = tail;
			newNode->next = head;
			head->prev = newNode;
		}
		current = head;
	}
	void Delete(int UID) {
		if (!head) return;

		Node* current_del = head;
		do {
			if (current_del->data.UID == UID) {
				if (current_del->next == current_del) {
					delete current;
					head = nullptr;
				}
				else {
					Node* prevNode = current_del->prev;
					Node* nextNode = current_del->next;
					prevNode->next = nextNode;
					nextNode->prev = prevNode;

					if (current_del == head) head = nextNode;
					delete current_del;

					Node* temp = nextNode;
					int newIndex = temp->prev->index + 1;
					do {
						temp->index = newIndex++;
						temp = temp->next;
					} while (temp != head);
				}
				return;
			}
			current_del = current_del->next;
		} while (current_del != head);
	}
	Player* GetCurrentPlayer() {
		if (current) {
			return &current->data;
		}
		return nullptr;
	}
	void MoveNext() {
		if (current) {
			current = current->next;
		}
	}
	void MovePrev() {
		if (current) {
			current = current->prev;
		}
	}

	int GetSize() const {
		if (!head) return 0;
		return head->prev->index;
	}
	~LinkedList() {
		if (!head) return;
		Node* current = head;
		do {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		} while (current != head);
	}
};

class ListCSVrecommond : public LinkedList {
public:

	// 리스트 데이터 삭제 함수
	void Clear() {
		if (!head) return;

		Node* current = head;
		do {
			Node* nextNode = current->next;
			delete current; // 메모리 해제
			current = nextNode;
		} while (current != head);

		head = nullptr;
		current = nullptr;
		
	}

	void ReadCSVFile(const std::string& filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			AfxMessageBox(_T("파일 열수 없음"));
			//std::cerr << "Could not open the file " << filename << std::endl;
			//return;
		}

		std::string line;
		bool header = true;
		while (std::getline(file, line)) {
			if (header) { // 헤더 행은 건너뜀
				header = false;
				continue;
			}

			std::istringstream ss(line);
			std::string token;

			Player player;
			int fieldCount = 0;
			
			// CSV 파일의 각 필드를 ','로 분리하여 Player 멤버에 할당
			while (std::getline(ss, token, ',')) {
				switch (fieldCount) {
				case 0: player.name = CString(token.c_str()); break;
				case 1: player.position_str = CString(token.c_str()); break;
				case 2: player.age = std::stoi(token); break;
				case 3: player.average.CA = std::stoi(token); break;
				case 4: player.average.PA = std::stoi(token); break;
				case 5: player.nationality = CString(token.c_str()); break;
				case 6: player.club = CString(token.c_str()); break;
				case 7: player.stat.corners = std::stoi(token); break;
				case 8: player.stat.crossing = std::stoi(token); break;
				case 9: player.stat.dribbling = std::stoi(token); break;
				case 10: player.stat.finishing = std::stoi(token); break;
				case 11: player.stat.first_touch = std::stoi(token); break;
				case 12: player.stat.free_kick_taking = std::stoi(token); break;
				case 13: player.stat.heading = std::stoi(token); break;
				case 14: player.stat.long_shots = std::stoi(token); break;
				case 15: player.stat.long_throws = std::stoi(token); break;
				case 16: player.stat.marking = std::stoi(token); break;
				case 17: player.stat.passing = std::stoi(token); break;
				case 18: player.stat.penalty_taking = std::stoi(token); break;
				case 19: player.stat.tackling = std::stoi(token); break;
				case 20: player.stat.technique = std::stoi(token); break;
				case 21: player.stat.aggression = std::stoi(token); break;
				case 22: player.stat.anticipation = std::stoi(token); break;
				case 23: player.stat.bravery = std::stoi(token); break;
				case 24: player.stat.composure = std::stoi(token); break;
				case 25: player.stat.concentration = std::stoi(token); break;
				case 26: player.stat.vision = std::stoi(token); break;
				case 27: player.stat.decision = std::stoi(token); break;
				case 28: player.stat.determination = std::stoi(token); break;
				case 29: player.stat.flair = std::stoi(token); break;
				case 30: player.stat.leadership = std::stoi(token); break;
				case 31: player.stat.off_the_ball = std::stoi(token); break;
				case 32: player.stat.position = std::stoi(token); break;
				case 33: player.stat.teamwork = std::stoi(token); break;
				case 34: player.stat.work_rate = std::stoi(token); break;
				case 35: player.stat.acceleration = std::stoi(token); break;
				case 36: player.stat.agility = std::stoi(token); break;
				case 37: player.stat.balance = std::stoi(token); break;
				case 38: player.stat.jumping_reach = std::stoi(token); break;
				case 39: player.stat.natural_fitness = std::stoi(token); break;
				case 40: player.stat.pace = std::stoi(token); break;
				case 41: player.stat.stamina = std::stoi(token); break;
				case 42: player.stat.strength = std::stoi(token); break;
				case 43: player.stat.stability = std::stoi(token); break;
				case 44: player.stat.foul = std::stoi(token); break;
				case 45: player.stat.contest_performance = std::stoi(token); break;
				case 46: player.stat.injury = std::stoi(token); break;
				case 47: player.stat.diversity = std::stoi(token); break;
				case 48: player.stat.aerial_reach = std::stoi(token); break;
				case 49: player.stat.command_of_area = std::stoi(token); break;
				case 50: player.stat.communication = std::stoi(token); break;
				case 51: player.stat.eccentricity = std::stoi(token); break;
				case 52: player.stat.handling = std::stoi(token); break;
				case 53: player.stat.kicking = std::stoi(token); break;
				case 54: player.stat.one_on_ones = std::stoi(token); break;
				case 55: player.stat.reflexes = std::stoi(token); break;
				case 56: player.stat.rushing_out = std::stoi(token); break;
				case 57: player.stat.punching = std::stoi(token); break;
				case 58: player.stat.throwing = std::stoi(token); break;
				case 59: player.stat.adaptation = std::stoi(token); break;
				case 60: player.stat.ambition = std::stoi(token); break;
				case 61: player.stat.argue = std::stoi(token); break;
				case 62: player.stat.loyal = std::stoi(token); break;
				case 63: player.stat.resistant_to_stress = std::stoi(token); break;
				case 64: player.stat.professional = std::stoi(token); break;
				case 65: player.stat.sportsmanship = std::stoi(token); break;
				case 66: player.stat.emotional_control = std::stoi(token); break;
				case 67: player.positionStat.GK = std::stoi(token); break;
				case 68: player.positionStat.DL = std::stoi(token); break;
				case 69: player.positionStat.DC = std::stoi(token); break;
				case 70: player.positionStat.DR = std::stoi(token); break;
				case 71: player.positionStat.WBL = std::stoi(token); break;
				case 72: player.positionStat.WBR = std::stoi(token); break;
				case 73: player.positionStat.DM = std::stoi(token); break;
				case 74: player.positionStat.ML = std::stoi(token); break;
				case 75: player.positionStat.MC = std::stoi(token); break;
				case 76: player.positionStat.MR = std::stoi(token); break;
				case 77: player.positionStat.AML = std::stoi(token); break;
				case 78: player.positionStat.AMC = std::stoi(token); break;
				case 79: player.positionStat.AMR = std::stoi(token); break;
				case 80: player.positionStat.ST = std::stoi(token); break;
				case 81: player.bodyStat.height = std::stoi(token); break;
				case 82: player.bodyStat.weight = std::stoi(token); break;
				case 83: player.footStat.left = std::stoi(token); break;
				case 84: player.footStat.right = std::stoi(token); break;
				case 92: player.date_of_birth = CString(token.c_str()); break;
				case 95: player.salary = std::stoi(token); break;
				case 97: player.UID = CString(token.c_str()); break;
				default: break;
				}
				fieldCount++;
			}

			// Player 객체를 리스트에 추가
			Insert(player);
		}

		file.close();
	}
	//recommond함수

};

ListCSVrecommond list;
ListCSVrecommond origin;
// -----------------------------------------------------------------------------//
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum statMap[IDD = IDD_ABOUTBOX };
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
	, m_nIndex(0)
	, m_nSizeALL(0)
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
	DDX_Control(pDX, IDC_FACE, m_picture_control);
	DDX_Text(pDX, IDC_EDIT_COUNT, m_nIndex);
	DDX_Text(pDX, IDC_EDIT_ALL, m_nSizeALL);
}

BEGIN_MESSAGE_MAP(Cfm2024Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_NEXT, &Cfm2024Dlg::OnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREV, &Cfm2024Dlg::OnClickedButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_STRIKER, &Cfm2024Dlg::OnClickedButtonStriker)
//	ON_BN_CLICKED(IDC_BUTTON2, &Cfm2024Dlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON_WINGER, &Cfm2024Dlg::OnClickedButtonWinger)
ON_BN_CLICKED(IDC_BUTTON_ATKMID, &Cfm2024Dlg::OnClickedButtonAtkmid)
ON_BN_CLICKED(IDC_BUTTON_CENTMID, &Cfm2024Dlg::OnClickedButtonCentmid)
ON_BN_CLICKED(IDC_BUTTON_DEFMID, &Cfm2024Dlg::OnClickedButtonDefmid)
ON_BN_CLICKED(IDC_BUTTON_LEFTFULL, &Cfm2024Dlg::OnClickedButtonLeftfull)
ON_BN_CLICKED(IDC_BUTTON_RIGHTFULL, &Cfm2024Dlg::OnClickedButtonRightfull)
ON_BN_CLICKED(IDC_BUTTON_DEF, &Cfm2024Dlg::OnClickedButtonDef)
ON_BN_CLICKED(IDC_BUTTON_GOALKEEP, &Cfm2024Dlg::OnClickedButtonGoalkeep)
ON_BN_CLICKED(IDC_BUTTON_FIND, &Cfm2024Dlg::OnClickedButtonFind)
ON_BN_CLICKED(IDC_BUTTON_ALL, &Cfm2024Dlg::OnClickedButtonAll)
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
	m_filepath = _T("C:\\Users\\th\\Desktop\\24-2opensw\\fm2024\\image\\");
	list.Clear();
	origin.Clear();
	list.ReadCSVFile("FM2023.csv");
	origin.ReadCSVFile("FM2023.csv");
	//m_strUIDPath = m_filepath + list.head->data.UID;
	UpdateDisplay(list);
	

	// 이미지 로드
	if (FAILED(m_image.Load(m_strUIDPath))) {
		AfxMessageBox(_T("이미지를 로드할 수 없습니다."));
	}

	return TRUE;  // 다이얼로그 초기화가 완료되었음을 나타냄
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
	if (m_image)  // 이미지가 로드되었는지 확인
	{
		CRect rect;
		m_picture_control.GetClientRect(&rect);  // Picture Control의 크기 얻기

		CDC* pDC = m_picture_control.GetDC();
		m_image.StretchBlt(pDC->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);  // 이미지 출력
		m_picture_control.ReleaseDC(pDC);  // DC 해제
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cfm2024Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cfm2024Dlg::UpdateDisplay(ListCSVrecommond& List)
{
	// TODO: 여기에 구현 코드 추가.
	Player* player = List.GetCurrentPlayer();
	if (player) {
		m_strUIDPath = m_filepath + player->UID + _T(".png");
		m_strName = player->name;;
		m_intAge = player->age;
		m_intAge = player->age;
		m_strBirth = player->date_of_birth;
		m_intHeight = player->bodyStat.height;
		m_intWeight = player->bodyStat.weight;
		m_strPosition = player->position_str;
		m_intCorners = player->stat.corners;
		m_intCrossing = player->stat.crossing;
		m_intDribbling = player->stat.dribbling;
		m_intFinishing = player->stat.finishing;
		m_intFirst_touch = player->stat.first_touch;
		m_intFree_kick = player->stat.free_kick_taking;
		m_intHeading = player->stat.heading;
		m_intLong_shot = player->stat.long_shots;
		m_intLong_throw = player->stat.long_throws;
		m_intMarking = player->stat.marking;
		m_intPassing = player->stat.passing;
		m_intPenalty_taking = player->stat.penalty_taking;
		m_intTackling = player->stat.tackling;
		m_intTechnique = player->stat.technique;
		m_intAggression = player->stat.aggression;
		m_intAnticipation = player->stat.anticipation;
		m_intBravery = player->stat.bravery;
		m_intComposure = player->stat.composure;
		m_intConcentration = player->stat.concentration;
		m_intVision = player->stat.vision;
		m_intDecision = player->stat.decision;
		m_intDetermination = player->stat.determination;
		m_intFlair = player->stat.flair;
		m_intLeadership = player->stat.leadership;
		m_intOff_the_ball = player->stat.off_the_ball;
		m_intPosition_stat = player->stat.position;
		m_intTeamwork = player->stat.teamwork;
		m_intWork_rate = player->stat.work_rate;
		m_intAcceleration = player->stat.acceleration;
		m_intAgility = player->stat.agility;
		m_intBalance = player->stat.balance;
		m_intJumping_reach = player->stat.jumping_reach;
		m_intNatural_fitness = player->stat.natural_fitness;
		m_intPace = player->stat.pace;
		m_intStamina = player->stat.stamina;
		m_intStrength = player->stat.strength;
		m_intStability = player->stat.stability;
		m_intFoul = player->stat.foul;
		m_intCP = player->stat.contest_performance;
		m_intInjury = player->stat.injury;
		m_intDiversity = player->stat.diversity;
		m_intAerialReach = player->stat.aerial_reach;
		m_intCOA = player->stat.command_of_area;
		m_intCommunication = player->stat.communication;
		m_intEccentricity = player->stat.eccentricity;
		m_intHandling = player->stat.handling;
		m_intKicking = player->stat.kicking;
		m_intOne_on_ones = player->stat.one_on_ones;
		m_intReflexes = player->stat.reflexes;
		m_intRushing_out = player->stat.rushing_out;
		m_intPunching = player->stat.punching;
		m_intThrowing = player->stat.throwing;
		m_intAdaptation = player->stat.adaptation;
		m_intAmbition = player->stat.ambition;
		m_intArgue = player->stat.argue;
		m_intLoyal = player->stat.loyal;
		m_intResistant_of_stress = player->stat.resistant_to_stress;
		m_intProfessional = player->stat.professional;
		m_intSportsmanship = player->stat.sportsmanship;
		m_intEmotional_control = player->stat.emotional_control;
		m_nIndex = list.GetCurrentIndex();
		m_nSizeALL = list.GetSize();
		
		UpdateData(FALSE);
		//Invalidate();
		//UpdateWindow();
	}
		
}


void Cfm2024Dlg::OnClickedButtonNext()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	list.MoveNext();
	UpdateDisplay(list);

	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonPrev()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	list.MovePrev();
	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::isPromisingStriker(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();
	
	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.finishing >= 13 && player.stat.finishing <= 16) && (player.stat.heading >= 12 && player.stat.heading <= 15) &&
			(player.stat.first_touch >= 11 && player.stat.first_touch <= 14) &&
			(player.stat.technique >= 12 && player.stat.technique <= 15) &&
			(player.stat.long_shots >= 10 && player.stat.long_shots <= 13) &&
			(player.stat.anticipation >= 11 && player.stat.anticipation <= 15) &&
			(player.stat.composure >= 10 && player.stat.composure <= 14) &&
			(player.stat.off_the_ball >= 12 && player.stat.off_the_ball <= 16) &&
			(player.stat.determination >= 11 && player.stat.determination <= 15) &&
			(player.stat.pace >= 12 && player.stat.pace <= 15) &&
			(player.stat.strength >= 11 && player.stat.strength <= 14) &&
			(player.stat.jumping_reach >= 11 && player.stat.jumping_reach <= 14) &&
			(player.age <= 20) && (player.positionStat.ST >= 18))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}
void Cfm2024Dlg::isPromisingWinger(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.dribbling >= 12 && player.stat.dribbling <= 16) &&
			(player.stat.crossing >= 10 && player.stat.crossing <= 15) &&
			(player.stat.first_touch >= 10 && player.stat.first_touch <= 14) &&
			(player.stat.technique >= 13 && player.stat.technique <= 15) &&
			(player.stat.long_shots >= 10 && player.stat.long_shots <= 14) &&
			(player.stat.flair >= 12 && player.stat.flair <= 15) &&
			(player.stat.off_the_ball >= 13 && player.stat.off_the_ball <= 15) &&
			(player.stat.vision >= 11 && player.stat.vision <= 14) &&
			(player.stat.decision >= 11 && player.stat.decision <= 13) &&
			(player.stat.acceleration >= 14 && player.stat.acceleration <= 16) &&
			(player.stat.pace >= 12 && player.stat.pace <= 15) &&
			(player.stat.agility >= 12 && player.stat.agility <= 15) &&
			(player.stat.balance >= 11 && player.stat.balance <= 13) &&
			(player.age <= 20) && ((player.positionStat.AMR >= 18) || (player.positionStat.AML >= 18)))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}

void Cfm2024Dlg::isPromisingAttackingMidfielder(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.dribbling >= 12 && player.stat.dribbling <= 15) &&
			(player.stat.passing >= 13 && player.stat.passing <= 16) &&
			(player.stat.first_touch >= 10 && player.stat.first_touch <= 15) &&
			(player.stat.technique >= 12 && player.stat.technique <= 16) &&
			(player.stat.finishing >= 10 && player.stat.finishing <= 13) &&
			(player.stat.vision >= 14 && player.stat.vision <= 16) &&
			(player.stat.decision >= 10 && player.stat.decision <= 15) &&
			(player.stat.flair >= 12 && player.stat.flair <= 16) &&
			(player.stat.anticipation >= 12 && player.stat.anticipation <= 14) &&
			(player.stat.agility >= 12 && player.stat.agility <= 15) &&
			(player.stat.acceleration >= 11 && player.stat.acceleration <= 14) &&
			(player.age <= 20) && ((player.positionStat.AMC >= 18) && (player.positionStat.AML >= 12) && (player.positionStat.AMR >= 12)))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}


void Cfm2024Dlg::isPromisingDefensiveMidfielder(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.tackling >= 12 && player.stat.tackling <= 16) &&
			(player.stat.marking >= 11 && player.stat.marking <= 15) &&
			(player.stat.passing >= 10 && player.stat.passing <= 14) &&
			(player.stat.first_touch >= 10 && player.stat.first_touch <= 14) &&
			(player.stat.anticipation >= 12 && player.stat.anticipation <= 15) &&
			(player.stat.concentration >= 12 && player.stat.concentration <= 15) &&
			(player.stat.decision >= 11 && player.stat.decision <= 14) &&
			(player.stat.strength >= 12 && player.stat.strength <= 15) &&
			(player.stat.stamina >= 12 && player.stat.stamina <= 15) &&
			(player.stat.balance >= 12 && player.stat.balance <= 15) &&
			(player.age <= 20) && (player.positionStat.DM >= 18))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}


void Cfm2024Dlg::isPromisingCentralMidfielder(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.passing >= 14 && player.stat.passing <= 16) &&
			(player.stat.first_touch >= 12 && player.stat.first_touch <= 15) &&
			(player.stat.technique >= 13 && player.stat.technique <= 15) &&
			(player.stat.tackling >= 10 && player.stat.tackling <= 13) &&
			(player.stat.vision >= 12 && player.stat.vision <= 15) &&
			(player.stat.decision >= 11 && player.stat.decision <= 14) &&
			(player.stat.teamwork >= 13 && player.stat.teamwork <= 16) &&
			(player.stat.work_rate >= 12 && player.stat.work_rate <= 15) &&
			(player.stat.composure >= 11 && player.stat.composure <= 14) &&
			(player.stat.stamina >= 13 && player.stat.stamina <= 16) &&
			(player.stat.balance >= 13 && player.stat.balance <= 14) &&
			(player.age <= 20) && (player.positionStat.MC >= 18))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}


void Cfm2024Dlg::isPromisingLeftFullback(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.crossing >= 12 && player.stat.crossing <= 16) &&
			(player.stat.dribbling >= 10 && player.stat.dribbling <= 15) &&
			(player.stat.passing >= 10 && player.stat.passing <= 14) &&
			(player.stat.technique >= 12 && player.stat.technique <= 14) &&
			(player.stat.off_the_ball >= 12 && player.stat.off_the_ball <= 15) &&
			(player.stat.decision >= 12 && player.stat.decision <= 13) &&
			(player.stat.teamwork >= 12 && player.stat.teamwork <= 15) &&
			(player.stat.work_rate >= 12 && player.stat.work_rate <= 16) &&
			(player.stat.acceleration >= 13 && player.stat.acceleration <= 16) &&
			(player.stat.pace >= 13 && player.stat.pace <= 15) &&
			(player.stat.stamina >= 12 && player.stat.stamina <= 15) &&
			(player.footStat.left >= 15 && player.footStat.right <= 20) &&
			(player.age <= 20) && ((player.positionStat.WBL >= 16) || (player.positionStat.DR >= 18)))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}


void Cfm2024Dlg::isPromisingRightFullback(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.crossing >= 14 && player.stat.crossing <= 16) &&
			(player.stat.dribbling >= 10 && player.stat.dribbling <= 15) &&
			(player.stat.passing >= 12 && player.stat.passing <= 14) &&
			(player.stat.technique >= 12 && player.stat.technique <= 14) &&
			(player.stat.off_the_ball >= 11 && player.stat.off_the_ball <= 15) &&
			(player.stat.decision >= 12 && player.stat.decision <= 13) &&
			(player.stat.teamwork >= 12 && player.stat.teamwork <= 15) &&
			(player.stat.work_rate >= 12 && player.stat.work_rate <= 16) &&
			(player.stat.acceleration >= 13 && player.stat.acceleration <= 16) &&
			(player.stat.pace >= 14 && player.stat.pace <= 15) &&
			(player.stat.stamina >= 12 && player.stat.stamina <= 15) &&
			(player.footStat.left >= 16 && player.footStat.right <= 20) &&
			(player.age <= 24) && ((player.positionStat.WBR >= 16) || (player.positionStat.DL >= 18)))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}


void Cfm2024Dlg::isPromisingCenterBack(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.tackling >= 12 && player.stat.tackling <= 17) &&
			(player.stat.marking >= 12 && player.stat.marking <= 16) &&
			(player.stat.heading >= 12 && player.stat.heading <= 16) &&
			(player.stat.anticipation >= 12 && player.stat.anticipation <= 17) &&
			(player.stat.concentration >= 12 && player.stat.concentration <= 16) &&
			(player.stat.decision >= 11 && player.stat.decision <= 16) &&
			(player.stat.bravery >= 12 && player.stat.bravery <= 15) &&
			(player.stat.strength >= 13 && player.stat.strength <= 16) &&
			(player.stat.jumping_reach >= 12 && player.stat.jumping_reach <= 15) &&
			(player.stat.stamina >= 12 && player.stat.stamina <= 20) &&
			(player.stat.pace >= 12 && player.stat.pace <= 16) &&
			(player.age <= 20) && (player.positionStat.DC >= 20))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}


void Cfm2024Dlg::isPromisingGoalkeepers(ListCSVrecommond& list)
{
	// TODO: 여기에 구현 코드 추가.
	list.Clear();

	if (!origin.head) {
		AfxMessageBox(_T("저장된 리스트가 없습니다."));
	}

	Node* currentNode = origin.head;
	do {
		Player player = currentNode->data;

		if ((player.stat.handling >= 11 && player.stat.handling <= 20) &&
			(player.stat.kicking >= 10 && player.stat.kicking <= 20) &&
			(player.stat.one_on_ones >= 12 && player.stat.one_on_ones <= 20) &&
			(player.stat.reflexes >= 11 && player.stat.reflexes <= 20) &&
			(player.stat.rushing_out >= 15 && player.stat.rushing_out <= 20) &&
			(player.stat.punching >= 7 && player.stat.punching <= 20) &&
			(player.stat.throwing >= 11 && player.stat.throwing <= 20) &&
			(player.age <= 20) && (player.positionStat.GK >= 20))
		{
			list.Insert(player);
		}
		currentNode = currentNode->next;
	} while (currentNode != origin.head);
}

void Cfm2024Dlg::OnClickedButtonStriker()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingStriker(list);
	
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonWinger()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingWinger(list);

	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonAtkmid()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingAttackingMidfielder(list);
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonCentmid()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingCentralMidfielder(list);
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonDefmid()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingDefensiveMidfielder(list);
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonLeftfull()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingLeftFullback(list);
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonRightfull()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingRightFullback(list);
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}

void Cfm2024Dlg::OnClickedButtonDef()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingCenterBack(list);
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}


void Cfm2024Dlg::OnClickedButtonGoalkeep()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	isPromisingGoalkeepers(list);
	if (!list.head) {
		AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
		return;
	}

	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}

void Cfm2024Dlg::OnClickedButtonAll()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	list.Clear();
	list.ReadCSVFile("FM2023.csv");
	if (!list.head) {
		AfxMessageBox(_T("리스트가 비었습니다."));
		return;
	}
	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
}

void Cfm2024Dlg::OnClickedButtonFind()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	SearchDlg dlg;
	if (dlg.DoModal() == IDOK) {
		bool findPlayer = false;
		bool stat1 = true;
		bool stat2 = true;
		bool stat3 = true;
		bool checked[3];
		checked[0] = false; checked[1] = false; checked[2] = false;
		int stat1Min =0, stat2Min=0, stat3Min=0, LeftFootMin=0, RightFootMin = 0;
		int stat1Max=20, stat2Max=20, stat3Max=20, LeftFootMax=20, RightFootMax = 20;
		int heightMin=0, heightMax = 250;
		int weightMin=0, weightMax = 200;
		int AgeMin=0, AgeMax = 100;

		//bool형 stat자료 크기만큼 만들고, if문에 넣어놓고 bool형하고 and문으로 연결해서 작동하거나 안하거나 하게
		if (dlg.m_bChecked[0]) {
			checked[0] = true;
			stat1Min = dlg.m_nStat1Min;
			stat1Max = dlg.m_nStat1Max;
		}
		if (dlg.m_bChecked[1]) {
			checked[1] = true;
			stat2Min = dlg.m_nStat2Min;
			stat2Max = dlg.m_nStat2Max;
		}
		if (dlg.m_bChecked[2]) {
			checked[2] = true;
			stat3Min = dlg.m_nStat3Min;
			stat3Max = dlg.m_nStat3Max;
		}
		if (dlg.m_bChecked[3]) {
			heightMin = dlg.m_nHeightMin;
			heightMax = dlg.m_nHeightMax;
		}
		if (dlg.m_bChecked[4]) {
			weightMin = dlg.m_nWeightMin;
			weightMax = dlg.m_nWeightMax;
		}
		if (dlg.m_bChecked[5]) {
			AgeMin = dlg.m_nAgeMin;
			AgeMax = dlg.m_nAgeMax;
		}
		if (dlg.m_bChecked[6]) {
			LeftFootMin = dlg.m_nLeftFootMin;
			LeftFootMax = dlg.m_nLeftFootMax;
		}
		if (dlg.m_bChecked[7]) {
			RightFootMin = dlg.m_nRightFootMin;
			RightFootMax = dlg.m_nRightFootMax;
		}
		if (!origin.head) {
			AfxMessageBox(_T("저장된 리스트가 없습니다."));
		}

		bool first = false;
		Node* currentNode = origin.head;
		do {
			Player player = currentNode->data;
			std::map<CString, int> statMap;
			try {
				statMap[_T("Corners")] = player.stat.corners;
				statMap[_T("Crossing")] = player.stat.crossing;
				statMap[_T("Dribbling")] = player.stat.dribbling;
				statMap[_T("Finishing")] = player.stat.finishing;
				statMap[_T("First Touch")] = player.stat.first_touch;
				statMap[_T("Free Kick Taking")] = player.stat.free_kick_taking;
				statMap[_T("Heading")] = player.stat.heading;
				statMap[_T("Long Shots")] = player.stat.long_shots;
				statMap[_T("Long Throws")] = player.stat.long_throws;
				statMap[_T("Marking")] = player.stat.marking;
				statMap[_T("Passing")] = player.stat.passing;
				statMap[_T("Penalty Taking")] = player.stat.penalty_taking;
				statMap[_T("Tackling")] = player.stat.tackling;
				statMap[_T("Technique")] = player.stat.technique;
				statMap[_T("Aggression")] = player.stat.aggression;
				statMap[_T("Anticipation")] = player.stat.anticipation;
				statMap[_T("Bravery")] = player.stat.bravery;
				statMap[_T("Composure")] = player.stat.composure;
				statMap[_T("Concentration")] = player.stat.concentration;
				statMap[_T("Vision")] = player.stat.vision;
				statMap[_T("Decision")] = player.stat.decision;
				statMap[_T("Determination")] = player.stat.determination;
				statMap[_T("Flair")] = player.stat.flair;
				statMap[_T("Leadership")] = player.stat.leadership;
				statMap[_T("Off The Ball")] = player.stat.off_the_ball;
				statMap[_T("Position")] = player.stat.position;
				statMap[_T("Teamwork")] = player.stat.teamwork;
				statMap[_T("Work Rate")] = player.stat.work_rate;
				statMap[_T("Acceleration")] = player.stat.acceleration;
				statMap[_T("Agility")] = player.stat.agility;
				statMap[_T("Balance")] = player.stat.balance;
				statMap[_T("Jumping Reach")] = player.stat.jumping_reach;
				statMap[_T("Natural Fitness")] = player.stat.natural_fitness;
				statMap[_T("Pace")] = player.stat.pace;
				statMap[_T("Stamina")] = player.stat.stamina;
				statMap[_T("Strength")] = player.stat.strength;
				statMap[_T("Stability")] = player.stat.stability;
				statMap[_T("Foul")] = player.stat.foul;
				statMap[_T("Contest Performance")] = player.stat.contest_performance;
				statMap[_T("Injury")] = player.stat.injury;
				statMap[_T("Diversity")] = player.stat.diversity;
				statMap[_T("Aerial Reach")] = player.stat.aerial_reach;
				statMap[_T("Command Of Area")] = player.stat.command_of_area;
				statMap[_T("Communication")] = player.stat.communication;
				statMap[_T("Eccentricity")] = player.stat.eccentricity;
				statMap[_T("Handling")] = player.stat.handling;
				statMap[_T("Kicking")] = player.stat.kicking;
				statMap[_T("One On Ones")] = player.stat.one_on_ones;
				statMap[_T("Reflexes")] = player.stat.reflexes;
				statMap[_T("Rushing Out")] = player.stat.rushing_out;
				statMap[_T("Punching")] = player.stat.punching;
				statMap[_T("Throwing")] = player.stat.throwing;
				statMap[_T("Adaptation")] = player.stat.adaptation;
				statMap[_T("Ambition")] = player.stat.ambition;
				statMap[_T("Argue")] = player.stat.argue;
				statMap[_T("Loyal")] = player.stat.loyal;
				statMap[_T("Resistant To Stress")] = player.stat.resistant_to_stress;
				statMap[_T("Professional")] = player.stat.professional;
				statMap[_T("Sportsmanship")] = player.stat.sportsmanship;
				statMap[_T("Emotional Control")] = player.stat.emotional_control;
			}
			catch (const std::exception& e) {
				CString msg;
				msg.Format(_T("맵 삽입 중 오류 발생 : % s"), e.what());
				AfxMessageBox(msg);
			}
			if (checked[0]) {

				auto it = statMap.find(dlg.m_strStat1);
				if (it != statMap.end()) {
					int statValue = it->second;
					if (statValue >= stat1Min && statValue <= stat1Max) {
						stat1 = true;
					}
					else {
						stat1 = false;
					}
				}
				else {
					AfxMessageBox(_T("해당 항목이 Stat에 없습니다."));
					checked[0] = false;
					stat1 = true;
				}
			}
			if (checked[1]) {
				auto it = statMap.find(dlg.m_strStat2);
				if (it != statMap.end()) {
					int statValue = it->second;
					if (statValue >= stat2Min && statValue <= stat2Max) {
						stat2 = true;
					}
					else {
						stat2 = false;
					}
				}
				else {
					AfxMessageBox(_T("해당 항목이 Stat에 없습니다."));
					checked[1] = false;
					stat2 = true;
				}
			}
			if (checked[2]) {
				auto it = statMap.find(dlg.m_strStat3);
				if (it != statMap.end()) {
					int statValue = it->second;
					if (statValue >= stat3Min && statValue <= stat3Max) {
						stat3 = true;
					}
					else {
						stat3 = false;
					}
				}
				else {
					AfxMessageBox(_T("해당 항목이 Stat에 없습니다."));
					checked[2] = false;
					stat3 = true;
				}
			}
			if ((player.age >= AgeMin && player.age <= AgeMax) && 
				(player.bodyStat.height >= heightMin && player.bodyStat.height <= heightMax) &&
				(player.bodyStat.weight >= weightMin && player.bodyStat.weight <= weightMax) && 
				(player.footStat.left >= LeftFootMin && player.footStat.left <= LeftFootMax) &&
				(player.footStat.right >= RightFootMin && player.footStat.right <= RightFootMax) &&
				stat1 && stat2 && stat3) 
			{
				findPlayer = true;
				if (findPlayer && !first) {
					list.Clear();
					first = true;
				}
				list.Insert(player);
			}
			currentNode = currentNode->next;
			stat1 = true;
			stat2 = true;
			stat3 = true;
		} while (currentNode != origin.head);
		
		if (!findPlayer) {
			AfxMessageBox(_T("조건에 맞는 선수가 없습니다."));
			return;
		}
	}
	UpdateDisplay(list);
	m_image.Destroy();
	if (!m_strUIDPath.IsEmpty()) {
		m_image.Load(m_strUIDPath);
	}
	OnPaint();
	
}
