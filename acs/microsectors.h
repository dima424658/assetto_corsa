#pragma once

class MicroSectors
{
// void __userpurge MicroSectors::MicroSectors(@<ecx>, unsigned int a2@<ebx>, Sim *aSim);
void MicroSectors::~MicroSectors();
MicroSectors *MicroSectors::`vector deleting destructor'(unsigned int a2);
void MicroSectors::drawSectors(GLRenderer *gl, int guid, float x, float y, float cellWidth, float cellHeight, vec4f backColor);
std::vector<SectorData> *MicroSectors::getSectorsPerformance(std::vector<SectorData> *result, int carId);
void MicroSectors::initialize();
void MicroSectors::update(float deltaT);

};