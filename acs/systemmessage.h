#pragma once

class SystemMessage
{
void SystemMessage::SystemMessage(Sim *aSim);
void SystemMessage::~SystemMessage();
SystemMessage *SystemMessage::`vector deleting destructor'(unsigned int a2);
void SystemMessage::addCarMessage(unsigned int carIndex, const SystemMessageType type);
void SystemMessage::addMessage(const std::wstring *imessage, const std::wstring *description, const SystemMessageType type);
void SystemMessage::clearMessage();
void SystemMessage::loadDriversInfo();
void SystemMessage::renderHUD(float dt);
void SystemMessage::setMask(INIReader *acIni, const std::wstring section, const std::wstring key, const SystemMessageType type);
void SystemMessage::update(float deltaT);

};