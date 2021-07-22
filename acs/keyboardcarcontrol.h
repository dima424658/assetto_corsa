#pragma once

class KeyboardCarControl
{
// void __userpurge KeyboardCarControl::KeyboardCarControl(@<ecx>, unsigned int a2@<ebx>, Car *carPointer);
void KeyboardCarControl::acquireControls(CarControls *controls, float dt, CarControlsInput *input);
double KeyboardCarControl::computeGasCoefficient(CarControlsInput *input, float dt);
bool KeyboardCarControl::getAction(DriverActions anAction);
vec3f *KeyboardCarControl::getCarPositionOnSpline(vec3f *result);
double KeyboardCarControl::getKeyboardSteering(float dt, CarControlsInput *input);
double KeyboardCarControl::getMouseSteering(float dt, CarControlsInput *input);
const char *KeyboardCarControl::getName();
vec3f *KeyboardCarControl::getPointAtDistance(vec3f *result, float distance, int *pointIndex);
void KeyboardCarControl::setMouseSteering(bool value);
double KeyboardCarControl::steeringMovement(const float targetSteer, float dt, CarControlsInput *input);
double KeyboardCarControl::stepSteer(float dt);
double KeyboardCarControl::getFFGlobalGain(TyreTester *this);

};