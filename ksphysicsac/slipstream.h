#pragma once

class SlipStream
{
void ~SlipStream();
double getSlipEffect(const vec3f *p);
void init(PhysicsEngine *pe);
void setPosition(const vec3f *pos, const vec3f *vel);

};