#pragma once

class SunAnimator
{
void SunAnimator(Sim *aSim, float baseAngle, float velocityMult, float cloudSpeed);
void enableCustomSunDirection(bool value);
double getVelocityMultiplier();
// void __userpurge setSunDirection(@<ecx>, int a2@<esi>, __m128 a3@<xmm4>, float zenith, float azimuth, float nordOffset);
void update(float dt);

};