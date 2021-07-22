#pragma once

class Autoclutch
{
void Autoclutch::Autoclutch();
double Autoclutch::getDownshiftSequenceDuration();
void Autoclutch::setDownshiftProfile(Curve *dp);
void Autoclutch::~Autoclutch();
void Autoclutch::init(Car *car);
void Autoclutch::loadINI(std::wstring carModel);
void Autoclutch::onGearRequest(const OnGearRequestEvent *ev);
void Autoclutch::step(float dt);
void Autoclutch::stepSequence(float dt);

};