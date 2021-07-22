#include "gpuprofiler.h
void GPUProfiler::GPUProfiler(GPUProfiler *this, GraphicsManager *gm)
{
  this->graphics = gm;
  this->queries._Myfirst = 0;
  this->queries._Mylast = 0;
  this->queries._Myend = 0;
  this->frameLatency = 30;
  this->waitCount = 0;
  kglInitGPUQuerySupport();
  this->isActive = 0;
}
void GPUProfiler::~GPUProfiler(GPUProfiler *this)
{
  QueryData *v1; // esi
  std::vector<QueryData> *v2; // ebx
  QueryData *i; // edi
  QueryData *v4; // ebp
  QueryData *v5; // edi
  unsigned int *v6; // esi

  v1 = this->queries._Myfirst;
  v2 = &this->queries;
  for ( i = this->queries._Mylast; v1 != i; ++v1 )
    kglReleaseTimestampQuery(v1->query);
  if ( v2->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v2);
    v4 = v2->_Mylast;
    v5 = v2->_Myfirst;
    if ( v2->_Myfirst != v4 )
    {
      v6 = &v5->name._Myres;
      do
      {
        if ( *v6 >= 8 )
          operator delete(*(v6 - 5));
        *v6 = 7;
        *(v6 - 1) = 0;
        ++v5;
        *((_WORD *)v6 - 10) = 0;
        v6 += 12;
      }
      while ( v5 != v4 );
    }
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
}
void GPUProfiler::beginFrame(GPUProfiler *this)
{
  std::wstring name; // [esp+8h] [ebp-28h] BYREF
  int v3; // [esp+2Ch] [ebp-4h]

  if ( this->isActive && this->waitCount > this->frameLatency )
  {
    GPUProfiler::fetchResults(this);
    kglQueryFrameBegin();
    std::wstring::wstring(&name, L"BEGIN_FRAME");
    v3 = 0;
    GPUProfiler::triggerQuery(this, &name);
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
  }
}
void GPUProfiler::endFrame(GPUProfiler *this)
{
  int v2; // eax
  std::wstring name; // [esp+8h] [ebp-28h] BYREF
  int v4; // [esp+2Ch] [ebp-4h]

  if ( this->isActive )
  {
    v2 = this->waitCount;
    if ( v2 <= this->frameLatency )
    {
      this->waitCount = v2 + 1;
    }
    else
    {
      std::wstring::wstring(&name, L"PRESENT");
      v4 = 0;
      GPUProfiler::triggerQuery(this, &name);
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      kglQueryFrameEnd();
      this->waitCount = 0;
    }
  }
}
void GPUProfiler::fetchResults(GPUProfiler *this)
{
  TyreTester *v2; // ecx
  QueryData *v3; // edi
  QueryData *v4; // esi
  long double v5; // xmm0_8
  double i; // [esp+8h] [ebp-10h]
  double v7; // [esp+10h] [ebp-8h]

  kglQueryFetchBegin();
  v3 = this->queries._Mylast;
  v4 = this->queries._Myfirst;
  for ( i = 0.0; v4 != v3; ++v4 )
  {
    v7 = kglQueryFetchTimestamp(v4->query);
    v4->lastTS = v7;
    v5 = v7 - i;
    i = v7;
    v4->lastResult = v5;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart(v2);
}
QueryData *GPUProfiler::getQuery(GPUProfiler *this, QueryData *result, const std::wstring *name)
{
  QueryData *v3; // esi
  QueryData *v4; // edi
  const std::wstring *v5; // eax
  QueryData *v6; // eax

  v3 = this->queries._Myfirst;
  v4 = this->queries._Mylast;
  if ( v3 == v4 )
  {
LABEL_7:
    v6 = result;
    result->name._Myres = 7;
    result->name._Mysize = 0;
    result->name._Bx._Buf[0] = 0;
    result->query = 0;
    *(_OWORD *)&result->lastResult = 0i64;
  }
  else
  {
    while ( 1 )
    {
      v5 = name->_Myres < 8 ? name : name->_Bx._Ptr;
      if ( !std::wstring::compare(&v3->name, 0, v3->name._Mysize, v5->_Bx._Buf, name->_Mysize) )
        break;
      if ( ++v3 == v4 )
        goto LABEL_7;
    }
    result->query = v3->query;
    result->lastResult = v3->lastResult;
    result->lastTS = v3->lastTS;
    result->name._Myres = 7;
    result->name._Mysize = 0;
    result->name._Bx._Buf[0] = 0;
    std::wstring::assign(&result->name, &v3->name, 0, 0xFFFFFFFF);
    v6 = result;
  }
  return v6;
}
std::vector<QueryData> *GPUProfiler::getResults(GPUProfiler *this, std::vector<QueryData> *result)
{
  std::vector<QueryData>::vector<QueryData>(result, &this->queries);
  return result;
}
char GPUProfiler::hasQuery(GPUProfiler *this, const std::wstring *name)
{
  QueryData *v2; // esi
  QueryData *v3; // edi
  const std::wstring *v4; // eax

  v2 = this->queries._Myfirst;
  v3 = this->queries._Mylast;
  if ( v2 == v3 )
    return 0;
  while ( 1 )
  {
    v4 = name->_Myres < 8 ? name : name->_Bx._Ptr;
    if ( !std::wstring::compare(&v2->name, 0, v2->name._Mysize, v4->_Bx._Buf, name->_Mysize) )
      break;
    if ( ++v2 == v3 )
      return 0;
  }
  return 1;
}
void GPUProfiler::setActive(GPUProfiler *this, bool mode)
{
  this->isActive = mode;
}
void GPUProfiler::triggerQuery(GPUProfiler *this, const std::wstring *name)
{
  QueryData d; // [esp+Ch] [ebp-70h] BYREF
  QueryData q; // [esp+3Ch] [ebp-40h] BYREF
  int v5; // [esp+78h] [ebp-4h]

  if ( this->isActive && this->waitCount > this->frameLatency )
  {
    if ( !GPUProfiler::hasQuery(this, name) )
    {
      d.name._Myres = 7;
      d.name._Mysize = 0;
      d.name._Bx._Buf[0] = 0;
      d.query = 0;
      *(_OWORD *)&d.lastResult = 0i64;
      v5 = 0;
      if ( &d.name != name )
        std::wstring::assign(&d.name, name, 0, 0xFFFFFFFF);
      d.query = kglNewTimestampQuery();
      std::vector<QueryData>::push_back(&this->queries, &d);
      v5 = -1;
      if ( d.name._Myres >= 8 )
        operator delete(d.name._Bx._Ptr);
    }
    GPUProfiler::getQuery(this, &q, name);
    kglTriggerTimestampQuery(q.query);
    if ( q.name._Myres >= 8 )
      operator delete(q.name._Bx._Ptr);
  }
}
