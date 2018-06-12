#include "MushMush.h"

#include "string"
#include "string.h"


using namespace std;

MushMush::MushMush()
{
}


MushMush::~MushMush()
{
}


bool MushMush::attackInRoom(std::string & message) const
{
	if (message == this->roomHazard())
	{
		message = "You got MushMush";
		return true;
	}

	return false;
}

bool MushMush::clashInRoom(std::string & msg) const
{
	if (msg == this->roomHazard())
	{
		msg = "MushMush got you";
		return true;
	}

	return false;
}
