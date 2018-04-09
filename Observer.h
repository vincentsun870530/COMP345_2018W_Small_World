#pragma once
#include <string>

class Players;
class Region;

class Observer
{
public:
	Observer();
	virtual ~Observer();

	virtual void update(Players * inputPlayer) = 0;
	virtual void update(Region * inputRegion) = 0;
	virtual void showStatus() = 0;

	std::string get_observer_name() const
	{
		return observerName;
	}

	void set_observer_name(const std::string& observer_name)
	{
		observerName = observer_name;
	}

private:
	std::string observerName = "Observer";
};

