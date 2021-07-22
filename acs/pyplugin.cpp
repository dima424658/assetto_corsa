#include "pyplugin.h"
void PyPlugin::PyPlugin(PyPlugin *this, const std::shared_ptr<PyModule> *module, Sim *sim)
{
  INIReader *v4; // ecx
  std::wstring *v5; // eax
  int v6; // eax
  _DWORD *v7; // esi
  _object *v8; // edi
  bool v9; // zf
  _BYTE v10[28]; // [esp-14h] [ebp-78h] BYREF
  PyPlugin *v11; // [esp+20h] [ebp-44h]
  std::wstring result; // [esp+24h] [ebp-40h] BYREF
  std::wstring res; // [esp+3Ch] [ebp-28h] BYREF
  int v14; // [esp+60h] [ebp-4h]

  v11 = this;
  *(_DWORD *)&v10[24] = sim->game;
  INIReader::getFileName((INIReader *)module->_Ptr, (std::wstring *)v10);
  GameObject::GameObject(this, *(std::wstring *)v10, *(Game **)&v10[24]);
  this->__vftable = (PyPlugin_vtbl *)&PyPlugin::`vftable';
  this->sim = sim;
  this->module._Ptr = 0;
  this->module._Rep = 0;
  *(_DWORD *)&v10[24] = module->_Rep;
  v14 = 0;
  std::_Ptr_base<Font>::_Reset(
    (std::_Ptr_base<Material> *)&this->module,
    (Material *)module->_Ptr,
    *(std::_Ref_count_base **)&v10[24]);
  v4 = (INIReader *)module->_Ptr;
  LOBYTE(v14) = 1;
  v5 = INIReader::getFileName(v4, &result);
  if ( v5->_Myres >= 8 )
    v5 = (std::wstring *)v5->_Bx._Ptr;
  _printf("Init PyPlugin:%S\n", v5->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v6 = _PyObject_GetAttrString(module->_Ptr->module, "acMain");
  v7 = (_DWORD *)v6;
  this->acUpdateFunc = 0;
  this->acShutdownFunc = 0;
  if ( v6 )
  {
    *(double *)&v10[20] = DOUBLE_1_0;
    v8 = (_object *)_PyObject_CallFunction(v6, "d");
    if ( v8 )
    {
      pyString(&res, v8);
      LOBYTE(v14) = 2;
      std::wstring::wstring(&result, L"acUpdate");
      LOBYTE(v14) = 3;
      PyPlugin::initFunc(this, &this->acUpdateFunc, &result);
      LOBYTE(v14) = 2;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::wstring::wstring(&result, L"acShutdown");
      LOBYTE(v14) = 4;
      PyPlugin::initFunc(this, &this->acShutdownFunc, &result);
      LOBYTE(v14) = 2;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v9 = v8->ob_refcnt-- == 1;
      if ( v9 )
        v8->ob_type->tp_dealloc(v8);
      LOBYTE(v14) = 1;
      if ( res._Myres >= 8 )
        operator delete(res._Bx._Ptr);
    }
    else
    {
      _printf("PyPlugin :: Error in Main function\n");
      PythonInterface::printErr();
    }
    v9 = (*v7)-- == 1;
    if ( v9 )
      (*(void (__cdecl **)(_DWORD *))(v7[1] + 24))(v7);
  }
  else
  {
    _printf("ERROR: acMain not found\n");
    _PyErr_Print();
  }
}
void PyPlugin::~PyPlugin(PyPlugin *this)
{
  std::wstring *v2; // eax
  std::_Ref_count_base *v3; // esi

  v2 = &this->name;
  this->__vftable = (PyPlugin_vtbl *)&PyPlugin::`vftable';
  if ( this->name._Myres >= 8 )
    v2 = (std::wstring *)v2->_Bx._Ptr;
  _printf("DELETING PY PLUGIN %S\n", v2->_Bx._Buf);
  v3 = this->module._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v3->_Weaks) )
        v3->_Delete_this(v3);
    }
  }
  GameObject::~GameObject(this);
}
PyPlugin *PyPlugin::`scalar deleting destructor'(PyPlugin *this, unsigned int a2)
{
  PyPlugin::~PyPlugin(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PyPlugin::initFunc(PyPlugin *this, _object **f, const std::wstring *name)
{
  const std::wstring *v3; // esi
  const std::wstring *v5; // eax
  int v6; // eax
  _object *v7; // eax

  v3 = name;
  if ( name->_Myres < 8 )
    v5 = name;
  else
    v5 = (const std::wstring *)name->_Bx._Ptr;
  v6 = _PyUnicode_FromWideChar(v5, name->_Mysize);
  v7 = (_object *)_PyObject_GetAttr(this->module._Ptr->module, v6);
  *f = v7;
  if ( v7 )
  {
    if ( name->_Myres >= 8 )
      v3 = (const std::wstring *)name->_Bx._Ptr;
    _printf("Function %S bind to module\n", v3->_Bx._Buf);
  }
  pyError();
}
void PyPlugin::shutdown(PyPlugin *this)
{
  _object *v2; // eax

  v2 = this->acShutdownFunc;
  if ( v2 )
  {
    _PyObject_CallFunction(v2, &byte_17C29BB);
    PythonInterface::printErr();
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)this);
}
void PyPlugin::update(PyPlugin *this, float dt)
{
  _object *v2; // eax

  v2 = this->acUpdateFunc;
  if ( v2 )
  {
    _PyObject_CallFunction(v2, "d");
    PythonInterface::printErr();
  }
}
