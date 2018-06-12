#pragma once
#include "Hazard.h"
#include "string"
#include "string.h"


using namespace std;

class Bat :
	public Hazard
{
public:
	Bat();
	virtual ~Bat();
	virtual std::string roomHazard() const { return "Bat is near"; }
	virtual bool attackInRoom(std::string& message) const;
	virtual bool clashInRoom(std::string& msg) const;
};

