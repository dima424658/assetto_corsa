#pragma once

class NetCarStateProvider
{
void NetCarStateProvider::NetCarStateProvider(const NetCarStateProviderDef *def);
void NetCarStateProvider::~NetCarStateProvider();
NetCarStateProvider *NetCarStateProvider::`vector deleting destructor'(char *this, unsigned int a2);
NetCarStateProvider *NetCarStateProvider::`vector deleting destructor'(unsigned int a2);
void NetCarStateProvider::activateP2P();
void NetCarStateProvider::debugLag(bool isLagging, long double physics_time);
void NetCarStateProvider::getPhysicsState(CarPhysicsState *physicsState);
mat44f *NetCarStateProvider::getSmoothBodyMatrix(mat44f *result, long double physics_time, CarPhysicsState *state);
mat44f *NetCarStateProvider::getTyreMatrix(mat44f *result, int index);
void NetCarStateProvider::getWingState(std::vector<WingState> *ws);
void NetCarStateProvider::initDRS();
void NetCarStateProvider::initP2P();
void NetCarStateProvider::initPhysicsValues();
void NetCarStateProvider::initWings();
void NetCarStateProvider::onRemoteStateReceived(NetCarState *s);
vec3f *NetCarStateProvider::projectNetStatePos(vec3f *result, int ti, long double t);
void NetCarStateProvider::resetDamage();
void NetCarStateProvider::setCarAvatar(CarAvatar *av);
void NetCarStateProvider::setDamageZoneLevel(float *zones);
void NetCarStateProvider::step(long double physics_time);
void NetCarStateProvider::stepLagging(long double physics_time);
void NetCarStateProvider::stepWings();
void NetCarStateProvider::update(float dt);

};