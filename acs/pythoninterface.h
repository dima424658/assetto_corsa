#pragma once

class PythonInterface
{
void PythonInterface::PythonInterface(Sim *sim);
void PythonInterface::~PythonInterface();
int PythonInterface::addFormToTaskBar(ksgui::Control *c);
int PythonInterface::addPythonListBoxDeselectionElementListener(int index, _object *ob);
int PythonInterface::addPythonListBoxElementListener(int index, _object *ob);
int PythonInterface::addPythonOnAppActivatedListener(int index, _object *ob);
int PythonInterface::addPythonOnAppDismissedListener(int index, _object *ob);
int PythonInterface::addPythonOnCheckBoxChanged(int index, _object *ob);
int PythonInterface::addPythonOnClickedListener(int index, _object *ob);
int PythonInterface::addPythonOnValidatedListener(int index, _object *ob);
int PythonInterface::addPythonOnValueChangedListener(int index, _object *ob);
ksgui::Control *PythonInterface::getControl(unsigned int index);
// int __userpurge PythonInterface::getTexture@<eax>(@<ecx>, unsigned int a2@<ebx>, std::wstring t);
Texture *PythonInterface::getTextureByIndex(Texture *result, unsigned int index);

};