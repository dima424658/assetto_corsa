#pragma once

#include <cstdint>
#include <functional>

class PhysicsAvatar
{
public:
	PhysicsAvatar(Sim* isim);
	~PhysicsAvatar();

	void executeOnPhysicsThread(std::function<void()> f);
	DynamicTrackStatus* getDynamicTrackStatus(DynamicTrackStatus* result);
	TemperatureInfo* getTemperatureInfo(TemperatureInfo* result);
	// mat44f *__usercall getTimeCorrectedMatrix@<eax>(int a1@<edi>, int a2@<esi>, mat44f *result, const mat44f *src, const vec3f *vel, const vec3f *avel, float dt);
	void onPhysicsStepCompleted(long double pt);
	void pausePhysics(bool mode);
	void render(float dt);
	void setAllowedTyresOut(int v);
	void shutdown();
	void startPhysics();
	void stepCommandQueue();
	void update(float deltat);
	void updateCrossThreadValues();

	int16_t getBasePitPenaltyLaps();
	void setJumpStartPenaltyMode(JumpStartPenaltyMode mode);
};