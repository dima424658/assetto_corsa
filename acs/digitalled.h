#pragma once

class DigitalLed
{
bool DigitalLed::hasTargetMesh();
void DigitalLed::DigitalLed(CarAvatar *car);
void DigitalLed::DigitalLed(CarAvatar *a_car, INIReader *ini, std::wstring section, DigitalLedType itype, Node *node);
void DigitalLed::DigitalLed(CarAvatar *a_car, std::wstring objectName, float valueSwitch, float bSwitch, float bFrequency);
void DigitalLed::~DigitalLed();
char DigitalLed::isWithinShowLimits(float value);
void DigitalLed::setShowLimits(float mi, float mx, bool excluded);
void DigitalLed::update(float dt);

};