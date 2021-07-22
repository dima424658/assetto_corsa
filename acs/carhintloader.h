#pragma once

class CarHintLoader
{
void CarHintLoader(const std::wstring *unixName, const std::wstring *config);
void ~CarHintLoader();
std::wstring *getCarName(std::wstring *result);
std::vector<std::wstring> *getHints(std::vector<std::wstring> *result);

};