#pragma once
#include "Room.h"
#include "string"
#include "string.h"


using namespace std;

class SealedRoom :
	public Room
{
public:
	SealedRoom(int tunnel1, int tunnel2, int tunnel3);
	virtual ~SealedRoom();

	virtual bool attackInRoom(std::string& message) const;

	virtual bool isSealedRoom() const;
};

