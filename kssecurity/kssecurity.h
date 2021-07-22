#pragma once

class ksSecurity
{
void ksSecurity::ksSecurity();
void ksSecurity::~ksSecurity();
ksSecurity *ksSecurity::`vector deleting destructor'(unsigned int a2);
std::wstring *ksSecurity::getMacAddress(std::wstring *result, bool printDebugInfos);
std::wstring *ksSecurity::getRequestCode(std::wstring *result, bool printDebugInfos);
std::wstring *ksSecurity::keyFromString(std::wstring *result, std::wstring is);
char ksSecurity::validate(std::wstring sfx, int version);

};