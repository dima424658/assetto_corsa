#pragma once

class DynamicWingController
{
void DynamicWingController::~DynamicWingController();
void DynamicWingController::DynamicWingController(Car *car, INIReader *ini, const std::wstring *section);
void DynamicWingController::DynamicWingController(const CarPhysicsState *state, const std::wstring *carUnixName, INIReader *ini, const std::wstring *section);
double DynamicWingController::getInput();
void DynamicWingController::initCommon(const std::wstring *carUnixName, INIReader *ini, const std::wstring *section);
void DynamicWingController::step();

};