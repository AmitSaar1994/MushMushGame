#include "Pit.h"
#include "string"
#include "string.h"


using namespace std;


Pit::Pit()
{
}


Pit::~Pit()
{
}

bool Pit::attackInRoom(std::string & message) const
{
	if (message == this->roomHazard())
	{
		message = "Pit is whistling";
		return true;
	}

	return false;
}

bool Pit::clashInRoom(std::string & msg) const
{
	if (msg == this->roomHazard())
	{
		msg = "You fell into a Pit";
		return true;
	}

	return false;
}


