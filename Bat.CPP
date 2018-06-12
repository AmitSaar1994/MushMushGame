#include "Bat.h"
#include "string"
#include "string.h"


using namespace std;


Bat::Bat()
{
}


Bat::~Bat()
{
}


bool Bat::attackInRoom(std::string & message) const
{
	if (message == this->roomHazard())
	{
		message = "Bat is laughing";
		return true;
	}

	return false;
}

bool Bat::clashInRoom(std::string & msg) const
{
	if (msg == this->roomHazard())
	{
		msg = "A Bat will move you";
		return true;
	}

	return false;
}

