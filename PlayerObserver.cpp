#include "PlayerObserver.h"

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
	cout <<"Player "<< _playerdata->get_id_player() << " starts to play the game. " << endl;
}

void PlayerObserver::update()
{
	display();
}
