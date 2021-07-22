#pragma once

class PhysicsCarStateProvider
{
void PhysicsCarStateProvider(Car *car);
void getPhysicsState(CarPhysicsState *physicsState);
void getWingState(std::vector<WingState> *wingStatus);

};