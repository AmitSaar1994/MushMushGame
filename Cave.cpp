#include "Cave.h"
#include "Room.h"
#include "RegularRoom.h"
#include "SealedRoom.h"
#include "Hazard.h"
#include "MushMush.h"
#include "Bat.h"
#include "Pit.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <typeinfo>

using namespace std;

Cave::Cave(const int * const sealedRooms, int size)
{
	_rooms = new Room*[20];
	_playerStatus=false;
	 _attack=false;

	_rooms[0] = new RegularRoom(19,18,2);
	_rooms[1] = new RegularRoom(18,17,5);
	_rooms[2] = new RegularRoom(0,17,4);
	_rooms[3] = new RegularRoom(19,16,7);
	_rooms[4] = new RegularRoom(15,2,6);
	_rooms[5] = new RegularRoom(1,14,9);
	_rooms[6] = new RegularRoom(4,13,8);
	_rooms[7] = new RegularRoom(3,12,11);
	_rooms[8] = new RegularRoom(6,11,10);
	_rooms[9] = new RegularRoom(5,10,13);
	_rooms[10] = new RegularRoom(12,9,8);
	_rooms[11] = new RegularRoom(15,8,7);
	_rooms[12] = new RegularRoom(14,7,10);
	_rooms[13] = new RegularRoom(17,6,9);
	_rooms[14] = new RegularRoom(16,5,12);
	_rooms[15] = new RegularRoom(19,4,11);
	_rooms[16] = new RegularRoom(18,3,14);
	_rooms[17] = new RegularRoom(1,2,13);
	_rooms[18] = new RegularRoom(0,1,16);
	_rooms[19] = new RegularRoom(15,0,3);

	int i;
	int roomidx;
	int tun1, tun2, tun3;
	for (i = 0; i < size; i++)
	{
		roomidx = sealedRooms[i];
		tun1 = _rooms[roomidx]->getTunnel(_rooms[roomidx]->getTunnel1());
		tun2 = _rooms[roomidx]->getTunnel(_rooms[roomidx]->getTunnel2());
		tun3 = _rooms[roomidx]->getTunnel(_rooms[roomidx]->getTunnel3());

		_rooms[sealedRooms[i]] = new SealedRoom(tun1,tun2,tun3);
	}

	_playerStatus = false;
	_playerIdx = 1;
}

Cave::~Cave()
{
	int i;

	for (i = 0; i < 20; i++)
		delete _rooms[i];
	delete[] _rooms;
}

void Cave::plotHazard(int idx, const std::string& eventName)
{
		if ((idx > 19) || (idx < 0))
			throw "Invalid Index Exception";
		else if (typeid(*this->_rooms[idx]->getHazard()) != typeid(Hazard))
			throw "Invalid Index Exception";
		if ((eventName != "MushMush") && (eventName != "Pit") && (eventName != "Bat"))
			throw "Invalid Hazard Exception";
		//if ((eventName.compare("MushMush")) && (eventName.compare("Pit")) && (eventName.compare("Bat")))
		this->_rooms[idx]->setHazard(eventName);


}

void Cave::plotPlayerIdx(int idx)
{
	if ((idx > 19) || (idx < 0))
		throw "Invalid Index Exception";
	else if (typeid(*this->_rooms[idx]->getHazard()) != typeid(Hazard))
		throw "Invalid Index Exception";
	_playerIdx = idx;
}

int Cave::findMushMush(void) const
{
	int i;
	int flag = 0;

	for (i = 0; i < Cave::NUM_OF_ROOMS; i++)
	{
		if (_rooms[i]->isMushMushHere())
		{
			flag = 1;
			return i;
		}
	}

	if (flag == 0)
		throw "MushMush Not Found Exception";
}

bool Cave::haveTunnel(int idx)
{
	if ((_rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel1()) != idx) && (_rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel2()) != idx) && (_rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel3()) != idx) || (idx<0) || (idx>19))
	{
		throw "Invalid Index Exception";
		return false;
	}
	return true;
}


void Cave::movePlayer(int idx)
{
	int index1, index2, index3;

	index1 = _rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel1());
	index2 = _rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel2());
	index3 = _rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel3());

	if ((idx > 19) || (idx < 0))
		throw "Invalid Index Exception";

	if ((index1 == idx) || (index2 == idx) || (index3 == idx) || (_playerIdx == idx))
		this->_playerIdx = idx;
}

std::string Cave::playerAttack(int idx)
{
	int index;

	if ((idx > 19) || (idx < 0))
		throw "Invalid Index Exception";
	if ((this->_rooms[_playerIdx]->getTunnel(this->_rooms[_playerIdx]->getTunnel1()) != idx) && (this->_rooms[_playerIdx]->getTunnel(this->_rooms[_playerIdx]->getTunnel2()) != idx) && (this->_rooms[_playerIdx]->getTunnel(this->_rooms[_playerIdx]->getTunnel3()) != idx))
		throw "Invalid Index Exception";
	string msg = this->_rooms[idx]->roomHazard();
	this->_rooms[idx]->attackInRoom(msg);

	if (!(typeid(*this->_rooms[idx]->getHazard()) == (typeid(MushMush))))
	{
		index = this->findMushMush();
		if (this->_rooms[this->_rooms[index]->getTunnel(this->_rooms[index]->getTunnel1())]->roomIsEmpty())
		{
			this->_rooms[this->_rooms[index]->getTunnel(this->_rooms[index]->getTunnel1())]->setHazard("MushMush");
			this->_rooms[index]->deleteHazard();
		}
		else if (this->_rooms[this->_rooms[index]->getTunnel(this->_rooms[index]->getTunnel2())]->roomIsEmpty())
		{
			this->_rooms[this->_rooms[index]->getTunnel(this->_rooms[index]->getTunnel2())]->setHazard("MushMush");
			this->_rooms[index]->deleteHazard();
		}
		else if (this->_rooms[this->_rooms[index]->getTunnel(this->_rooms[index]->getTunnel3())]->roomIsEmpty())
		{
			this->_rooms[this->_rooms[index]->getTunnel(this->_rooms[index]->getTunnel3())]->setHazard("MushMush");
			this->_rooms[index]->deleteHazard();
		}
		
	}
	else
	{
		_playerStatus = true;
	}

	if (typeid(*this->_rooms[idx]) == typeid(SealedRoom))
		_playerStatus = true;

	return msg;


}

bool Cave:: gameOver() const
{
	return _playerStatus;
}

const Room* Cave::getRoomAtIndex(int index) const
{

	if ((index > 19) || (index < 0))
		throw "Invalid Index Exception";
	return this->_rooms[index];


}

void Cave::hazardNearPlayer(std::string* hazards) const
{
	int tun1, tun2, tun3;

	tun1 = _rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel1());
	tun2 = _rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel2());
	tun3 = _rooms[_playerIdx]->getTunnel(_rooms[_playerIdx]->getTunnel3());


	hazards[0] = _rooms[tun1]->roomHazard();
	hazards[1] = _rooms[tun2]->roomHazard();
	hazards[2] = _rooms[tun3]->roomHazard();

}

std::string Cave::playerClash(int idx)
{

	if ((idx > 19) || (idx < 0))
		throw "Invalid Index Exception";

	string msg = this->_rooms[_playerIdx]->roomHazard();
	this->_rooms[_playerIdx]->clashInRoom(msg);
	if (msg == "A Bat will move you")
	{
		this->_rooms[_playerIdx]->deleteHazard();
		this->_playerIdx = idx;
	}

	if ((typeid(*this->_rooms[_playerIdx]->getHazard()) == typeid(MushMush)) || (typeid(*this->_rooms[_playerIdx]->getHazard()) == typeid(Pit)))
	{
		msg = this->_rooms[_playerIdx]->roomHazard();
		this->_rooms[_playerIdx]->clashInRoom(msg);
		_playerStatus = true;
	}

	return msg;


}
