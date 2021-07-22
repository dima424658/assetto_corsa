#pragma once

class AutoBlip
{
void init(Car *acar);
void loadINI(std::wstring carModel);
void step(float dt);

};