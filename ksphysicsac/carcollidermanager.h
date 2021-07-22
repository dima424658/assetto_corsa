#pragma once

class CarColliderManager
{
void CarColliderManager::CarColliderManager();
void CarColliderManager::~CarColliderManager();
// CarCollisionBox *__userpurge CarColliderManager::getBox@<eax>(@<ecx>, __m128 a2@<xmm0>, CarCollisionBox *result, int index);
void CarColliderManager::init(Car *acar);
void CarColliderManager::loadINI();
void CarColliderManager::step(float dt);

};