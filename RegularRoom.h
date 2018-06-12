#pragma once
#include "Room.h"

#include "string"
#include "string.h"


using namespace std;

class RegularRoom :
	public Room
{
public:
	RegularRoom(int tunnel1, int tunnel2, int tunnel3);
	virtual ~RegularRoom();
};

