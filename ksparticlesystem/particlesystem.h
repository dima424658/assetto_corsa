#pragma once

class ParticleSystem
{
std::vector<unsigned short> *ParticleSystem::generateIndexBuffer(std::vector<unsigned short> *result, int pcount);
void ParticleSystem::ParticleSystem(const std::wstring *a_name, GraphicsManager *graphics, int a_maxParticleCount, const Texture *a_texture);
ParticleSystem *ParticleSystem::`vector deleting destructor'(unsigned int a2);
void ParticleSystem::~ParticleSystem();
void ParticleSystem::step(float dt);
void ParticleSystem::render(RenderContext *rc);
void ParticleSystem::clearParticles();
void ParticleSystem::disable();

};