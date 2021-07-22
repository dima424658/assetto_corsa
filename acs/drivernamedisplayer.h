#pragma once

class DriverNameDisplayer
{
// void __userpurge DriverNameDisplayer::DriverNameDisplayer(@<ecx>, unsigned int a2@<ebx>, Sim *aSim);
void DriverNameDisplayer::~DriverNameDisplayer();
vec2f *DriverNameDisplayer::projectPoint(vec2f *result, vec3f worldSpacePoint, vec3f *outDirection);
void DriverNameDisplayer::renderHUD(float deltaT);
void DriverNameDisplayer::setActive(bool active);
void DriverNameDisplayer::shutdown();
void DriverNameDisplayer::update(float deltaT);

};