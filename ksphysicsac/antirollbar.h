#pragma once

class AntirollBar
{
void AntirollBar();
void ~AntirollBar(SteeringSystem *this);
void init(IRigidBody *cb, ISuspension **sus);
void step(float dt);

};