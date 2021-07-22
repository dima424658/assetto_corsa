#pragma once

class DigitalItem
{
void DigitalItem(CarAvatar *a_car, INIReader *ini, const std::wstring *section, std::vector<DigitalItem *> *items);
void ~DigitalItem();
void cleanup();
void update(float dt);

};