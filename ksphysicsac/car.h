#pragma once

#include "abs.h"

class Car
{
public:

	TimeTransponder* transponder;
	BrakeSystem* brakeSystem;
	ABS abs;
	ERS ers;
};