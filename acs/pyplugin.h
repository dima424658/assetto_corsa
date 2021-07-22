#pragma once

class PyPlugin
{
void PyPlugin(const std::shared_ptr<PyModule> *module, Sim *sim);
void ~PyPlugin();
void initFunc(_object **f, const std::wstring *name);
void shutdown();
void update(float dt);

};