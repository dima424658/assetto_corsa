#pragma once

#include <vector>

class TimeTransponder
{
public:
	TimeTransponder();
	~TimeTransponder();
    
	void addCut();
	void armFirstLap();
	int getCuts();
	std::vector<unsigned int>* getLastLapSplits(std::vector<unsigned int>* result);
	TimeLineStatus* getStatus(int index);
	void init(Car* car);
	void invalidate();
	bool isInOpenTrackTransition();
	char isValid();
	void lap(bool valid);
	void onTimeLinePassed(int index, bool isFinishLine);
	void reset();

	void split(int sectorIndex);
	void step(float dt);
};