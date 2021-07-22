#pragma once

class ACDriverPerformance
{
// void __userpurge ACDriverPerformance::ACDriverPerformance(@<ecx>, unsigned int a2@<ebx>, CarAvatar *aCar);
void ACDriverPerformance::render(float dt);
void ACDriverPerformance::renderOnVideo();
// ACDriverPerformance *__userpurge ACDriverPerformance::fromFloatToString@<eax>(float a1@<xmm2>, );
char ACDriverPerformance::saveDriverRecords();
void ACDriverPerformance::~ACDriverPerformance();

};