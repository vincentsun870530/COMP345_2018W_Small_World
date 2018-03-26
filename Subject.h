#pragma once
#include "Observer.h"
#include <vector>
using namespace std;

class Subject
{
public:
	Subject();
	virtual ~Subject();
	Observer *m_observer;

	void attach(Observer *p_observer);
	void detach(Observer *p_observer);
	void notify();
private:
	vector <Observer*> *observerList;
};

