#pragma once

class SetupItem
{
void SetupItem(const SetupItem *__that);
void SetupItem(std::wstring aname, float *aconnectedFloat, std::wstring units, bool isAttached, float multiplier, float labelMult);
void ~SetupItem();

};