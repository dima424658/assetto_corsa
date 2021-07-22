#pragma once

class PvsProcessor
{
void PvsProcessor::PvsProcessor();
void PvsProcessor::begin(RenderContext *rc, const PvsRenderMode renderMode, std::vector<RenderTarget *> *shadowMaps, CubeMap *cubeMap);
void PvsProcessor::doDistanceAndLod();
void PvsProcessor::doExclusion();
void PvsProcessor::doFrustumCulling();
void PvsProcessor::doRenderCalls();
void PvsProcessor::doRenderClassic();
void PvsProcessor::end();
void PvsProcessor::prepareDrawCallsDefault();

};