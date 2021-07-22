#pragma once

class InputDevice
{
void InputDevice::InputDevice(_GUID guid, const std::wstring *name, DirectInput *di);
void InputDevice::~InputDevice();
void InputDevice::setG27Leds(float rpm, float minRpm, float maxRpm);
bool InputDevice::poll();
void InputDevice::sendFF(float v, float damper);
void InputDevice::initFF();
std::wstring *InputDevice::getName(std::wstring *result);

};