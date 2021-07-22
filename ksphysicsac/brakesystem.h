#pragma once

class BrakeSystem
{
void BrakeSystem::BrakeSystem();
void BrakeSystem::~BrakeSystem();
void BrakeSystem::activateTempRunFile(bool mode);
double BrakeSystem::getBrakePower();
double BrakeSystem::getFrontBias();
// void __userpurge BrakeSystem::init(@<ecx>, unsigned int a2@<ebx>, Car *car);
void BrakeSystem::loadINI(std::wstring dataPath);
void BrakeSystem::reset();
void BrakeSystem::saveTempsRunFame();
void BrakeSystem::setManualFrontBias(int value);
void BrakeSystem::step(float dt);
void BrakeSystem::stepTemps(float dt);
BOOL BrakeSystem::isUsingEBB();

};