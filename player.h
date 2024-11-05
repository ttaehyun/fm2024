#pragma once

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
	

};

