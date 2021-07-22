#pragma once

class ParticleGenerator
{
// void __userpurge ParticleGenerator(@<ecx>, __m128 a2@<xmm0>, ParticleSystem *a_particleSystem, std::wstring a_filename, float aFrequency);
void ~ParticleGenerator();
void generateParticle(const vec3f *pos, const vec3f *velocity, long double now, long double timeRate);
void loadINI();

};