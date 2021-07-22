#pragma once

class DIControlButton
{
void DIControlButton(std::wstring iname, DirectInput *di);
void ~DIControlButton();
double getKeyboardValue(bool isKeyboardEnabled);
double getValue(bool useRange);
void load(INIReader *reader, bool loadRange);

};