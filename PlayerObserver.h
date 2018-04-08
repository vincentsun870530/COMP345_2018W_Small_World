#pragma once
#include <iostream>
#include "Observer.h"
#include "Players.h"
using namespace std;

class PlayerObserver : public Observer
{
private:
	Players *_playerdata;
	int turn;
	int score;
	int token;
	string phase;
	int player_id;
	bool phaseChange = false;
public:
	int get_score() const;
	int get_token() const;
	const string& get_phase() const;
	PlayerObserver();
	PlayerObserver(Players *playerdata);
	~PlayerObserver();
	void update() override;
	void display() override;
	bool is_phase_change() const;
	void set_phase_change(bool phase_change);
};

