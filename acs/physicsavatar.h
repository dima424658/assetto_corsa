#pragma once

class PhysicsAvatar
{
void PhysicsAvatar::PhysicsAvatar(Sim *isim);
void PhysicsAvatar::~PhysicsAvatar();
PhysicsAvatar *PhysicsAvatar::`vector deleting destructor'(unsigned int a2);
void PhysicsAvatar::executeOnPhysicsThread(std::function<void __cdecl(void)> f);
DynamicTrackStatus *PhysicsAvatar::getDynamicTrackStatus(DynamicTrackStatus *result);
TemperatureInfo *PhysicsAvatar::getTemperatureInfo(TemperatureInfo *result);
void PhysicsAvatar::onPhysicsStepCompleted(long double pt);
void PhysicsAvatar::pausePhysics(bool mode);
void PhysicsAvatar::render(float dt);
void PhysicsAvatar::setAllowedTyresOut(int v);
void PhysicsAvatar::shutdown();
void PhysicsAvatar::startPhysics();
void PhysicsAvatar::stepCommandQueue();
void PhysicsAvatar::update(float deltat);
void PhysicsAvatar::updateCrossThreadValues();
__int16 PhysicsAvatar::getBasePitPenaltyLaps();
void PhysicsAvatar::setJumpStartPenaltyMode(JumpStartPenaltyMode mode);

};