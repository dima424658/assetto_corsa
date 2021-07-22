#pragma once

class TrackIR
{
void TrackIR(HWND__ *hwnd);
void ~TrackIR();
void getOffsets(vec3f *rot, vec3f *pos);

};