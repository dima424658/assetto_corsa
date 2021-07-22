#pragma once

class ACINIReader
{
void ACINIReader::ACINIReader();
void ACINIReader::~ACINIReader();
double ACINIReader::getFloat(const std::wstring *section, const std::wstring *key);
int ACINIReader::getInt(const std::wstring *section, const std::wstring *key);
unsigned int ACINIReader::getString(const std::wstring *section, const std::wstring *key, wchar_t *buffer, int bufferSize);
bool ACINIReader::open(std::wstring filename);

};