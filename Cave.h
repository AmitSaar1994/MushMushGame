#pragma once

#include "string"
#include "string.h"


using namespace std;

class Room;
class Cave
{
	private:
		Room **_rooms;
		int _playerIdx;
		bool _playerStatus;
		bool _attack;
public:
	static const int NUM_OF_ROOMS = 20;

	Cave(const int* const sealedRooms, int size);
	~Cave();
	const Room* getRoomAtIndex(int index) const;
	void plotHazard(int idx, const std::string& eventName);
	void plotPlayerIdx(int idx);
	int findMushMush(void) const;
	void movePlayer(int idx);
	std::string playerAttack(int idx);
	std::string playerClash(int idx);
	bool gameOver() const;

	bool haveTunnel(int idx);

	void hazardNearPlayer(std::string* hazards) const;
};
