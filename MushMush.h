#pragma once
#include "Hazard.h"
#include "string"
#include "string.h"


using namespace std;

class MushMush :
	public Hazard
{
public:
	MushMush();
	virtual ~MushMush();

	virtual std::string roomHazard() const { return "MushMush is near"; }

	virtual bool attackInRoom(std::string& message) const;
	virtual bool clashInRoom(std::string& msg) const;
	bool isMushMushHere() const  {return true;}

};

