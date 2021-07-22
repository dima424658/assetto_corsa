#pragma once

class TyreTester
{
IRayCaster *TyreTester::createRayCaster(float length);
bool TyreTester::rayCastWithRayCaster(const vec3f *org, const vec3f *dir, RayCastResult *result, float length, IRayCaster *rayCaster);
double TyreTester::getK();
void TyreTester::TyreTester(const std::wstring *dataPath, int index);
TyreTester *TyreTester::`vector deleting destructor'(char *this, unsigned int a2);
TyreTester *TyreTester::`vector deleting destructor'(unsigned int a2);
vec3f *TyreTester::getBasePosition(vec3f *result);
std::vector<DebugLine> *TyreTester::getDebugLines(std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix);
mat44f *TyreTester::getHubWorldMatrix(mat44f *result);
double TyreTester::getLoad();
vec3f *TyreTester::getPointVelocity(vec3f *result, const vec3f *p);
SuspensionStatus *TyreTester::getStatus();
char TyreTester::rayCast(const vec3f *org, const vec3f *dir, RayCastResult *result, float length);
std::vector<TyreTestFrame> *TyreTester::slipAngleSweep(std::vector<TyreTestFrame> *result, float minSA, float maxSA, float aload, int steps);
std::vector<TyreTestFrame> *TyreTester::slipRatioSweep(std::vector<TyreTestFrame> *result, float minSR, float maxSR, float aload, int steps);
std::vector<TyreTestFrame> *TyreTester::srSASweep(std::vector<TyreTestFrame> *result, float sa, float minsr, float maxsr, float load, int steps);

};