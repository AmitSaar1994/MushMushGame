#include "Room.h"
#include "Hazard.h"
#include "MushMush.h"
#include "Bat.h"
#include "Pit.h"
#include "RegularRoom.h"
#include "SealedRoom.h"
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <typeinfo>

using namespace std;

Room::Room(int tunnel1, int tunnel2, int tunnel3)
{
	_tunnels[0] = tunnel1;
	_tunnels[1] = tunnel2;
	_tunnels[2] = tunnel3;

	_hazard = new Hazard;
}

void Room::deleteHazard()
{
	_hazard = new Hazard;
}

bool Room::attackInRoom(std::string & message) const
{

	return this->_hazard->attackInRoom(message);
}


int Room::getTunnel1() const
{
	int i, min = 20, MinI;

	for (i = 0; i < 3; i++)
	{
		if (_tunnels[i] < min)
		{
			min = _tunnels[i];
			MinI = i;
		}
	}

	return MinI;


}

int Room::getTunnel2() const
{

	int MaxI, MinI, i;
	MaxI = getTunnel3();
	MinI = getTunnel1();

	for (i = 0; i < 3; i++)
	{
		if ((i != MaxI) && (i != MinI))
			return i;
	}
}

const Hazard* Room::getHazard() const
{
	return _hazard;
}
int Room::getTunnel3() const
{

	int i, max = -1, MaxI;

	for (i = 0; i < 3; i++)
	{
		if (_tunnels[i] > max)
		{
			max = _tunnels[i];
			MaxI = i;
		}
	}

	return MaxI;
}


int Room::getTunnel(int idx)
{
	return _tunnels[idx];
}

std::string Room::roomHazard() const
{
	return _hazard->roomHazard();
		
}

bool Room::roomIsEmpty() const
{
	if (typeid(*this->_hazard) == typeid(Hazard))
		return true;
	return false;
}

bool Room::isMushMushHere() const
{
	return _hazard->isMushMushHere();
}

bool Room::clashInRoom(std::string & msg) const
{
	return this->_hazard->clashInRoom(msg);
}

const void Room::setHazard(const std::string& str)
{
	if (!str.compare("MushMush"))
		_hazard = new MushMush;
	else if (!str.compare("Pit"))
		_hazard = new Pit;
	else if (!str.compare("Bat"))
		_hazard = new Bat;
}



Room::~Room()
{
	delete this->_hazard;
}
