#include "pymodule.h"
void PyModule::PyModule(PyModule *this, const std::wstring *name)
{
  const std::wstring *v3; // esi
  std::wstring *v4; // ecx
  const std::wstring *v5; // eax
  const std::wstring *v6; // eax
  _DWORD *v7; // ebp

  v3 = name;
  v4 = &this->name;
  v4->_Myres = 7;
  v4->_Mysize = 0;
  v4->_Bx._Buf[0] = 0;
  std::wstring::assign(v4, name, 0, 0xFFFFFFFF);
  this->hasErrors = 1;
  if ( name->_Myres < 8 )
    v5 = name;
  else
    v5 = (const std::wstring *)name->_Bx._Ptr;
  _printf("Opening PyModule %S\n", v5->_Bx._Buf);
  if ( name->_Myres < 8 )
    v6 = name;
  else
    v6 = (const std::wstring *)name->_Bx._Ptr;
  v7 = (_DWORD *)_PyUnicode_FromWideChar(v6, name->_Mysize);
  this->module = (_object *)_PyImport_Import(v7);
  if ( (*v7)-- == 1 )
    (*(void (__cdecl **)(_DWORD *))(v7[1] + 24))(v7);
  if ( this->module )
  {
    this->hasErrors = 0;
  }
  else
  {
    _printf("ERROR\n");
    this->hasErrors = 1;
  }
  if ( _PyErr_Occurred() )
  {
    if ( name->_Myres >= 8 )
      v3 = (const std::wstring *)name->_Bx._Ptr;
    _printf("PyModule :: Errors occurred loading %S\n", v3->_Bx._Buf);
    pyError();
    _PyErr_Clear();
  }
}
void PyModule::~PyModule(PyModule *this)
{
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
