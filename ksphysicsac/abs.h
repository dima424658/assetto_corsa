#pragma once

#include <utility>

class Car;

class ABS
{
public:
	void cycleMode(int value); // idb
	std::pair<unsigned int, unsigned int> getCurrentMode();
	void init(Car* acar);
	bool isInAction();
	void step(float td);

	bool isPresent;
	std::pair<unsigned int, unsigned int> currentMode;
};