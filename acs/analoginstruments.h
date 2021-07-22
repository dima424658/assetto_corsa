#pragma once

class AnalogInstruments
{
void AnalogInstruments::AnalogInstruments(CarAvatar *car);
void AnalogInstruments::~AnalogInstruments();
void AnalogInstruments::initFuel(INIReader *r);
void AnalogInstruments::initPlaceHolders(INIReader *ini);
void AnalogInstruments::initRPM(INIReader *r);
void AnalogInstruments::initSpeed(INIReader *r);
void AnalogInstruments::initTurbo(INIReader *r);
void AnalogInstruments::initWater(INIReader *ini);
void AnalogInstruments::readTurboSection(INIReader *r, const std::wstring *section);
// void __userpurge AnalogInstruments::update(@<ecx>, int a2@<ebx>, float dt);
// void __userpurge AnalogInstruments::updateFuel(@<ecx>, int a2@<ebx>, int a3@<edi>, float dt);
void AnalogInstruments::updatePlaceHolders(float dt);
// void __userpurge AnalogInstruments::updateRPM(@<ecx>, int a2@<edi>, int a3@<esi>, float dt);
// void __userpurge AnalogInstruments::updateSpeed(@<ecx>, int a2@<edi>, float dt);
void AnalogInstruments::updateTurbo(float dt);
// void __userpurge AnalogInstruments::updateWater(@<ecx>, int a2@<ebx>, int a3@<edi>, float dt);

};