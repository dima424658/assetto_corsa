#include "pyenvironment.h
void PyEnvironment::PyEnvironment(PyEnvironment *this, const char *iname)
{
  this->methods._Myfirst = 0;
  this->methods._Mylast = 0;
  this->methods._Myend = 0;
  this->name = iname;
}
void PyEnvironment::addFunc(PyEnvironment *this, const char *name, _object *(__cdecl *func)(_object *, _object *))
{
  PyMethodDef *v4; // ecx
  PyMethodDef *v5; // eax
  int v6; // edi
  PyMethodDef *v7; // eax
  const __m128i *v8; // edi
  PyMethodDef *v9; // eax
  PyMethodDef nm; // [esp+4h] [ebp-10h] BYREF

  nm.ml_meth = func;
  v4 = &nm;
  nm.ml_name = name;
  nm.ml_doc = 0;
  v5 = this->methods._Mylast;
  nm.ml_flags = 1;
  if ( &nm >= v5 || (v4 = this->methods._Myfirst, this->methods._Myfirst > &nm) )
  {
    if ( v5 == this->methods._Myend )
      std::vector<FormChat::ChatIntensities>::_Reserve((std::vector<FormChat::ChatIntensities> *)this, (unsigned int)v4);
    v9 = this->methods._Mylast;
    if ( v9 )
      *(__m128i *)v9 = _mm_loadu_si128((const __m128i *)&nm);
    ++this->methods._Mylast;
  }
  else
  {
    v6 = (char *)&nm - (char *)v4;
    if ( v5 == this->methods._Myend )
      std::vector<FormChat::ChatIntensities>::_Reserve((std::vector<FormChat::ChatIntensities> *)this, (unsigned int)v4);
    v7 = this->methods._Mylast;
    v8 = (const __m128i *)((char *)this->methods._Myfirst + (v6 & 0xFFFFFFF0));
    if ( v7 )
      *(__m128i *)v7 = _mm_loadu_si128(v8);
    ++this->methods._Mylast;
  }
}
void PyEnvironment::addTerminator(PyEnvironment *this)
{
  PyMethodDef *v2; // ecx
  PyMethodDef *v3; // eax
  int v4; // edi
  PyMethodDef *v5; // eax
  const __m128i *v6; // edi
  PyMethodDef *v7; // eax
  PyMethodDef nm; // [esp+4h] [ebp-10h] BYREF

  nm.ml_doc = 0;
  v2 = &nm;
  nm.ml_flags = 0;
  nm.ml_meth = 0;
  nm.ml_name = 0;
  v3 = this->methods._Mylast;
  if ( &nm >= v3 || (v2 = this->methods._Myfirst, this->methods._Myfirst > &nm) )
  {
    if ( v3 == this->methods._Myend )
      std::vector<FormChat::ChatIntensities>::_Reserve((std::vector<FormChat::ChatIntensities> *)this, (unsigned int)v2);
    v7 = this->methods._Mylast;
    if ( v7 )
      *(__m128i *)v7 = _mm_loadu_si128((const __m128i *)&nm);
    ++this->methods._Mylast;
  }
  else
  {
    v4 = (char *)&nm - (char *)v2;
    if ( v3 == this->methods._Myend )
      std::vector<FormChat::ChatIntensities>::_Reserve((std::vector<FormChat::ChatIntensities> *)this, (unsigned int)v2);
    v5 = this->methods._Mylast;
    v6 = (const __m128i *)((char *)this->methods._Myfirst + (v4 & 0xFFFFFFF0));
    if ( v5 )
      *(__m128i *)v5 = _mm_loadu_si128(v6);
    ++this->methods._Mylast;
  }
}
