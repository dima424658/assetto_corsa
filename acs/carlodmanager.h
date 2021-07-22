#pragma once

class CarLodManager
{
void CarLodManager::CarLodManager(CarAvatar *car);
void CarLodManager::~CarLodManager();
CarLodManager *CarLodManager::`vector deleting destructor'(unsigned int a2);
void CarLodManager::initNoBodyNodes();
void CarLodManager::loadLod(CarLodDef *lod);
void CarLodManager::renderHUD(float deltaT);
void CarLodManager::update(float dt);
void CarLodManager::updateLodVisibility();

};