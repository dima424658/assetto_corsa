#pragma once

class Wing
{
void Wing::Wing(Car *a_car, INIReader *ini, int index, bool isVertical);
void Wing::~Wing();
void Wing::addDrag(vec3f *lv);
void Wing::addLift(vec3f *lv);
void Wing::clearOverrides();
double Wing::getCurrentModifiedAngle();
void Wing::setOverrideAngle(float iangle);
void Wing::step(float dt);
void Wing::stepDynamicControllers(float dt);
void Wing::Wing(const Wing *__that);

};