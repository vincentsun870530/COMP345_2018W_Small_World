#include "PlayerObserver.h"

int PlayerObserver::get_score() const
{
	return score;
}

int PlayerObserver::get_token() const
{
	return token;
}

const string& PlayerObserver::get_phase() const
{
	return phase;
}

PlayerObserver::PlayerObserver()
{

}

PlayerObserver::PlayerObserver(Players *playerdata)
{
	_playerdata = playerdata;
	_playerdata->attach(this);
}

PlayerObserver::~PlayerObserver()
{
	_playerdata->detach(this);
}

void PlayerObserver::display()
{
	//if ((phase == " starts to play the game. ")|| (phase == " continue to play the game. ")) {
	//	cout << "Player " << player_id << phase << endl;
	//	std::cout << "Player " << player_id << " has " << token << " tokens in hand. " << std::endl;
	//}
	//else if(phase ==" conquers some regions. ")
	//{
	//	cout << "Player " << player_id << phase << endl;
	//}
	//else if (phase == " scores some victory coins. ")
	//{
	//	cout << "Player " << player_id << phase << endl;
	//	cout << "The amount of victory coins are " << score << endl;
	//}
	//else if (phase == " starts deploy. ")
	//{
	//	cout << "Player " << player_id << phase << endl;
	//}
	cout << "Player " << player_id << phase << endl;
}

bool PlayerObserver::is_phase_change() const
{
	return phaseChange;
}

void PlayerObserver::set_phase_change(bool phase_change)
{
	phaseChange = phase_change;
}

void PlayerObserver::update()
{
	int tempTotalAmount = _playerdata->get_coin_1() + _playerdata->get_coin_3() * 3 + _playerdata->get_coin_5() * 5 + _playerdata->get_coin_10() * 10;
	this->score = tempTotalAmount;
	this->phase = _playerdata->get_phaser();
	this->token = _playerdata->get_in_hand_solider_current_race();
	this->player_id = _playerdata->get_id_player();
	this->phaseChange = _playerdata->is_phase_change();
	if (this->phaseChange == true) {
		display();
		_playerdata->set_phase_change(false);
	}
}
