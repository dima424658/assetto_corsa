#pragma once

class ACControl
{
void ACControl::ACControl(ksgui::GUI *igui);
void *ACControl::getTag();
std::wstring *ACControl::getText(char *this);
void ACControl::setControlPosition(float x, float y);
void ACControl::setControlSize(float x, float y);
void ACControl::setTag(void *atag);
void ACControl::setText(char *this, const std::wstring *a2);

};