#pragma once

class DynamicController
{
bool DynamicController::isReady();
DynamicController *DynamicController::operator=(const DynamicController *__that);
void DynamicController::DynamicController(Car *car, const std::wstring *filename);
void DynamicController::DynamicController();
void DynamicController::~DynamicController();
double DynamicController::eval();
double DynamicController::getInput(DynamicControllerInput input);

};