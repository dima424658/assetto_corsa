#pragma once

class DIControlAxis
{
void DIControlAxis(std::wstring iname, DirectInput *di);
void ~DIControlAxis();
double getValue(bool useRange);
void load(INIReader *reader, bool loadRange);

};