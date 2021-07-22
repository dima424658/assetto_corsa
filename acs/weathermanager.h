#pragma once

class WeatherManager
{
std::wstring *getLastWeatherName(std::wstring *result);
void WeatherManager(Sim *a_sim);
void applyCustomWeather(const std::wstring *name);

};