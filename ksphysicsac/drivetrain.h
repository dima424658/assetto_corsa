#pragma once

class Drivetrain
{
TractionType Drivetrain::getTractionType();
void Drivetrain::~Drivetrain();
void Drivetrain::addGear(std::wstring name, long double ratio);
char Drivetrain::gearDown();
char Drivetrain::gearUp();
SGearRatio *Drivetrain::getCurrentGear(SGearRatio *result);
long double Drivetrain::getDrivetrainSpeed();
double Drivetrain::getEngineRPM();
long double Drivetrain::getInertiaFromEngine();
long double Drivetrain::getInertiaFromWheels();
long double Drivetrain::getRpmWindowStatus();
bool Drivetrain::hasDynamicControllers();
void Drivetrain::init(Car *car);
BOOL Drivetrain::isChangingGear();
bool Drivetrain::isGearboxLocked();
void Drivetrain::loadINI(const std::wstring *dataPath);
double Drivetrain::projectRPMAtDownshift();
void Drivetrain::reallignSpeeds(float dt);
void Drivetrain::reset();
void Drivetrain::setCurrentGear(int index, bool force);
void Drivetrain::setGearRatio(int index, float value);
void Drivetrain::step2WD(float dt);
void Drivetrain::step4WD(float dt);
void Drivetrain::step4WD_new(float dt);
void Drivetrain::step(float dt);
void Drivetrain::stepControllers(float dt);
void Drivetrain::Drivetrain();
long double Drivetrain::getGearDnTime();

};