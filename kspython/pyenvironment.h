#pragma once

class PyEnvironment
{
void PyEnvironment(const char *iname);
void addFunc(const char *name, _object *(__cdecl *func)(_object *, _object *));
void addTerminator();

};