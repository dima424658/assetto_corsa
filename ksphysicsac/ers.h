#pragma once

#include <utility>
#include <vector>
#include <string>

class ERSPowerController
{
public:
    std::wstring name;
};

class ERS
{
public:
    ERS();
    ~ERS();

    double getCoastTorque();
    double getOutputTorque();
    void init(Car *car);
    
    void reset();
    void setPowerController(int index);
    void step(float dt);

	bool isHeatCharginBattery;
    std::vector<ERSPowerController> ersPowerControllers;
};