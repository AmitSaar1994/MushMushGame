#pragma once
#include "Hazard.h"
#include "string"
#include "string.h"


using namespace std;

class Pit :
	public Hazard
{
public:
	Pit();
	virtual ~Pit();


	virtual std::string roomHazard() const { return "Pit is near"; }

	virtual bool attackInRoom(std::string& message) const;
	virtual bool clashInRoom(std::string& msg) const;
 
};

