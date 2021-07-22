#pragma once

class FormVolumes
{
void FormVolumes::FormVolumes(Sim *aSim);
void FormVolumes::refreshDrivers();
// void __userpurge FormVolumes::setSpinner(@<ecx>, float a2@<xmm3>, ksgui::Spinner *obj, float *lasttop);
// void __userpurge FormVolumes::saveVolume(float _Val@<xmm1>, const std::wstring key);
void FormVolumes::render(float dt);
void FormVolumes::setSound(__int16 camera, bool value, bool save);

};