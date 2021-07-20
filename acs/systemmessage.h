#pragma once

#include <string_view>

#include "Types.hpp"

enum class SystemMessageType
{
  eABS  
};

class SystemMessage
{
public:
    SystemMessage(Sim *aSim);
    ~SystemMessage();

   // const SystemMessageType *__thiscall std::map<enum SystemMessageType,bool>::operator[](std::map<enum SystemMessageType,bool> *this, const SystemMessageType *_Keyval);

    void addCarMessage(unsigned int carIndex, const SystemMessageType type);
    void addMessage(const std::wstring_view imessage, const std::wstring_view description, const SystemMessageType type);
    void clearMessage();
    void loadDriversInfo();
    void renderHUD(float dt);
    void setMask(INIReader *acIni, const std::wstring section, const std::wstring key, const SystemMessageType type);
    void update(float deltaT);
};