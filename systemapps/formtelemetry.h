#pragma once

class FormTelemetry
{
void FormTelemetry::FormTelemetry(CarAvatar *car_avatar);
void FormTelemetry::~FormTelemetry();
void FormTelemetry::render(float dt);
// void __userpurge FormTelemetry::addChannel(@<ecx>, float a2@<xmm3>, const std::wstring *name, float *input_value, float max_value, float scale, bool isReadOnPhysicsThread, int jumpFrames);
// void __userpurge FormTelemetry::addChannelLambda(@<ecx>, float a2@<xmm2>, float a3@<xmm3>, const std::wstring *name, float scale, bool isReadOnPhysicsThread, std::function<float __cdecl(void)> lambda);
void FormTelemetry::initChannels();
void FormTelemetry::applyPreset(const std::wstring *preset_name);
void FormTelemetry::getValuesFromPhysics();
void FormTelemetry::getValuesFromGraphics();

};