#pragma once

class TimeLimitedTest
{
// void __userpurge TimeLimitedTest(@<ecx>, unsigned int a2@<ebx>, Sim *isim);
int getMaxRunningTime();
void renderHUD(float deltaT);
void shutdown();
void update(float dt);

};