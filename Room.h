#pragma once
#include "string"
#include "string.h"


using namespace std;


class Hazard;

#pragma pack(push, 1)
class Room
{
public:
	Room(int tunnel1, int tunnel2, int tunnel3);
	virtual ~Room();
	virtual bool attackInRoom(std::string& message) const;
	int getTunnel1() const;
	int getTunnel2() const;
	int getTunnel3() const;
	virtual std::string roomHazard() const;
	const Hazard * getHazard() const;
	const void setHazard(const std::string& str);
	void deleteHazard();
	int getTunnel(int idx);

	bool roomIsEmpty() const;
	virtual bool isMushMushHere() const;
	virtual bool clashInRoom(std::string& msg) const;
protected:
	const Hazard* _hazard;
private:
	int _tunnels[3];
};
#pragma pack(pop) 
