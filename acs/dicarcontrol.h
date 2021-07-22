#pragma once

class DICarControl
{
void DICarControl::~DICarControl();
// void __userpurge DICarControl::acquireControls(@<ecx>, int a2@<edi>, CarControls *controls, float dt, CarControlsInput *input);
bool DICarControl::getAction(DriverActions anAction);
double DICarControl::getFFGlobalGain();
const char *DICarControl::getName();
void DICarControl::initShifter(INIReader *ini);
void DICarControl::onAutoShifterChanged(bool newmode);
void DICarControl::sendFF(float ff, float damper, float userGain);
void DICarControl::setEngineRPM(float rpm, float minRpm, float maxRpm);
void DICarControl::setVibrations(const VibrationDef *vibrations);
void DICarControl::validate();

};