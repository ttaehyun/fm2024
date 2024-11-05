
// fm2024Dlg.h: 헤더 파일
//

#pragma once


// Cfm2024Dlg 대화 상자
class Cfm2024Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cfm2024Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FM2024_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;

	int m_intAcceleration;
	int m_intAdaptation;
	int m_intAerialReach;
	int m_intAge;
	int m_intAggression;
	int m_intAgility;
	int m_intAmbition;
	int m_intAnticipation;
	int m_intArgue;
	int m_intBalance;
	CString m_strBirth;
	int m_intBravery;
	int m_intCOA;
	int m_intCommunication;
	int m_intComposure;
	int m_intConcentration;
	int m_intCorners;
	int m_intHeight;
	int m_intWeight;
	int m_intCP;
	int m_intCrossing;
	int m_intDecision;
	int m_intDetermination;
	int m_intDiversity;
	int m_intDribbling;
	int m_intEccentricity;
	int m_intEmotional_control;
	int m_intFinishing;
	int m_intFirst_touch;
	int m_intFlair;
	int m_intFoul;
	int m_intFree_kick;
	int m_intHandling;
	int m_intHeading;
	int m_intInjury;
	int m_intJumping_reach;
	int m_intKicking;
	int m_intLeadership;
	int m_intLong_shot;
	int m_intLong_throw;
	int m_intLoyal;
	int m_intMarking;
	int m_intNatural_fitness;
	int m_intOff_the_ball;
	int m_intOne_on_ones;
	int m_intPace;
	int m_intPassing;
	int m_intPenalty_taking;
	int m_intProfessional;
	int m_intPunching;
	int m_intReflexes;
	int m_intResistant_of_stress;
	int m_intRushing_out;
	int m_intSportsmanship;
	int m_intStability;
	int m_intStamina;
	int m_intStrength;
	int m_intTackling;
	int m_intTeamwork;
	int m_intTechnique;
	int m_intThrowing;
	int m_intVision;
	int m_intWork_rate;
	CString m_strPosition;
	int m_intPosition_stat;
	void ReadCSVFile(const CString& filePath);
};

//Player class

class average {
public:
	int CA;
	int PA;
};

class foot_stat {
public:
	int left;
	int right;
};

class position_stat {
public:
	int GK;
	int DL;
	int DC;
	int DR;
	int WBL;
	int WBR;
	int DM;
	int ML;
	int MC;
	int MR;
	int AML;
	int AMC;
	int AMR;
	int ST;
};

class body_stat {
public:
	int height;
	int weight;
};

class Stat {
public:
	int corners;
	int crossing;
	int dribbling;
	int finishing;
	int first_touch;
	int free_kick_taking;
	int heading;
	int long_shots;
	int long_throws;
	int marking;
	int passing;
	int penalty_taking;
	int tackling;
	int technique;
	int aggression;
	int anticipation;
	int bravery;
	int composure;
	int concentration;
	int vision;
	int decision;
	int determination;
	int flair;
	int leadership;
	int off_the_ball;
	int position;
	int teamwork;
	int work_rate;
	int acceleration;
	int agility;
	int balance;
	int jumping_reach;
	int natural_fitness;
	int pace;
	int stamina;
	int strength;
	int stability;
	int foul;
	int contest_performance;
	int injury;
	int diversity;
	int aerial_reach;
	int command_of_area;
	int communication;
	int eccentricity;
	int handling;
	int kicking;
	int one_on_ones;
	int reflexes;
	int rushing_out;
	int punching;
	int throwing;
	int adaptation;
	int ambition;
	int argue;
	int loyal;
	int resistant_to_stress;
	int professional;
	int sportsmanship;
	int emotional_control;
};
class player : public average, public foot_stat, public position_stat, public body_stat, public Stat
{
public:
	int UID;
	CString name;
	int age;
	int salary;
	CString nationality;
	CString club;
	CString position_str;
	CString date_of_birth;
	
	void Recommond();
};

