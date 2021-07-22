#pragma once

class GPUProfiler
{
void GPUProfiler::GPUProfiler(GraphicsManager *gm);
void GPUProfiler::~GPUProfiler();
void GPUProfiler::beginFrame();
void GPUProfiler::endFrame();
void GPUProfiler::fetchResults();
QueryData *GPUProfiler::getQuery(QueryData *result, const std::wstring *name);
std::vector<QueryData> *GPUProfiler::getResults(std::vector<QueryData> *result);
char GPUProfiler::hasQuery(const std::wstring *name);
void GPUProfiler::setActive(bool mode);
void GPUProfiler::triggerQuery(const std::wstring *name);

};