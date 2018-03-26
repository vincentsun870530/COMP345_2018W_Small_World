#include "Subject.h"
#include <iostream>


Subject::Subject()
{
	observerList = new vector<Observer*>;
}


Subject::~Subject()
{
}


void Subject::attach(Observer * pObeserver) {
	observerList->push_back(pObeserver);
}

void Subject::detach(Observer * pObeserver) {
	for (vector<Observer*>::iterator itr = observerList->begin(); itr != observerList->end(); ++itr)
	{
		if (*itr == pObeserver)
		{
			observerList->erase(itr);
			return;
		}
	}
}

void Subject::notify() {
	for (vector<Observer*>::iterator itr = observerList->begin();
		itr != observerList->end();
		++itr)
	{
		cout << "in notify function " << endl;
		(*itr)->update();
	}
}