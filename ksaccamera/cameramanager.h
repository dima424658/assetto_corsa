#pragma once

class CameraManager
{
void CameraManager(const std::wstring *filename);
void ~CameraManager();
void load(std::wstring filename, bool merge);
ACCamera *getActiveCamera(float normalizedSplinePosition);
void initCamerasDistanceRanges(const Spline *spline);

};