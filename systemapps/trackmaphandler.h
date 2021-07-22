#pragma once

class TrackMapHandler
{
// void __userpurge TrackMapHandler::TrackMapHandler(@<ecx>, unsigned int a2@<ebx>, Sim *sim);
// void __userpurge TrackMapHandler::loadParameters(@<ecx>, float a2@<xmm1>, float a3@<xmm2>, std::wstring iniPath);
void TrackMapHandler::saveParameters(std::wstring iniPath);
void TrackMapHandler::makePositiveCoordAndCalculateWidthAndHeightRT();
void TrackMapHandler::createListOfPointsToDrawFromSpline();
void TrackMapHandler::drawMapOnRenderTarget(std::wstring filePath);
void TrackMapHandler::~TrackMapHandler();

};