#pragma once

class StaticParticleSystem
{
void StaticParticleSystem::StaticParticleSystem(const std::wstring *a_name, GraphicsManager *graphics, int a_maxParticleCount, const Texture *a_texture);
StaticParticleSystem *StaticParticleSystem::`vector deleting destructor'(unsigned int a2);
void StaticParticleSystem::~StaticParticleSystem();
void StaticParticleSystem::render(RenderContext *rc);
void StaticParticleSystem::addParticle(const StaticParticle *particle);
void StaticParticleSystem::initIndexBuffer(ParticleSystem *this);
void StaticParticleSystem::finalize();

};