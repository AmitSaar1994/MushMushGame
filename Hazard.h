#pragma once
#include "Room.h"

#include "string"
#include "string.h"


using namespace std;

class Hazard
{
public:

	virtual std::string roomHazard() const { return ""; }
	virtual bool attackInRoom(std::string& message) const;
	virtual bool clashInRoom(std::string& msg) const;
	virtual bool isMushMushHere() const { return false; }
};

