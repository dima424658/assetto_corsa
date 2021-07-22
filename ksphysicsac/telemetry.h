#pragma once

class Telemetry
{
void Telemetry();
void ~Telemetry();
void init(Car *car);
void save(std::wstring filename);
void step(float td);

};