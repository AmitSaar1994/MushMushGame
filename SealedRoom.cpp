#include "SealedRoom.h"
#include "string"
#include "string.h"


using namespace std;


SealedRoom::SealedRoom(int tunnel1, int tunnel2, int tunnel3) : Room(tunnel1, tunnel2, tunnel3)
{
}


SealedRoom::~SealedRoom()
{
}

bool SealedRoom::attackInRoom(std::string & message) const
{
	message = "You just shot yourself";
	return true;
}

bool SealedRoom::isSealedRoom() const
{
	return true;
}
