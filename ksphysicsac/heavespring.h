#pragma once

class HeaveSpring
{
void HeaveSpring();
void ~HeaveSpring();
void init(Car *car, Suspension *s0, Suspension *s1, bool isFront);
void initData();
void step(float dt);

};