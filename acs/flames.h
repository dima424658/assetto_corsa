#pragma once

class Flames
{
void Flames::Flames(CarAvatar *a_car);
void Flames::~Flames();
Flames *Flames::`vector deleting destructor'(unsigned int a2);
void Flames::checkTextures(const std::wstring name, const std::vector<FlameTexture> *orig);
void Flames::copyFlameVector(const std::vector<FlameTexture> *orig, std::vector<FlameTexture> *dest, FlameInstanceV2 *f);
void Flames::cycleTexture(FlameTexture *ft, unsigned __int16 cycle);
// void __userpurge Flames::drawBackfireState(@<ecx>, float a2@<xmm0>, GLRenderer *gl, RenderContext *rc, FlameGroup *f);
void Flames::drawFlame(GLRenderer *gl, FlameInstance *flame, RenderContext *rc);
// void __userpurge Flames::drawFlame(@<ecx>, float a2@<xmm0>, GLRenderer *gl, RenderContext *rc, BackfireState st, FlameGroup *g);
void Flames::loadFlames();
void Flames::loadTextures(std::wstring folder);
// void __userpurge Flames::onNodeRenderEvent(@<ecx>, float a2@<xmm0>, const OnNodeRenderEvent *e);
void Flames::readFlamePresets(const std::wstring *str, FlameInstanceV2 *f);
void Flames::reset();
void Flames::update(float dt);

};