#include "comparativetelemetryrecorder.h
void ComparativeTelemetryRecorder::ComparativeTelemetryRecorder(ComparativeTelemetryRecorder *this, CarAvatar *aCar)
{
  std::wstring *v3; // esi
  std::wstring *v4; // eax
  std::wstring *v5; // ebp
  Sim *v6; // eax
  Event<OnStepCompleteEvent> *v7; // ecx
  Event<OnLapCompletedEvent> *v8; // ecx
  std::wstring v9; // [esp-1Ch] [ebp-68h] BYREF
  unsigned int v10; // [esp-4h] [ebp-50h]
  ComparativeTelemetryRecorder *v11; // [esp+20h] [ebp-2Ch]
  std::wstring result; // [esp+24h] [ebp-28h] BYREF
  int v13; // [esp+48h] [ebp-4h]

  v11 = this;
  v10 = (unsigned int)aCar->sim->game;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"COMPARATIVE_TELEMETRY_RECORDER", 0x1Eu);
  GameObject::GameObject(this, v9, (Game *)v10);
  v10 = 20;
  v13 = 0;
  this->__vftable = (ComparativeTelemetryRecorder_vtbl *)&ComparativeTelemetryRecorder::`vftable';
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&this->psQueue, v10);
  this->psQueue.__vftable = (Concurrency::concurrent_queue<CTData,std::allocator<CTData> >_vtbl *)&Concurrency::concurrent_queue<CTData,std::allocator<CTData>>::`vftable';
  this->currentCTData._Myfirst = 0;
  this->currentCTData._Mylast = 0;
  this->currentCTData._Myend = 0;
  this->lastCTData._Myfirst = 0;
  this->lastCTData._Mylast = 0;
  this->lastCTData._Myend = 0;
  this->bestCTData._Myfirst = 0;
  this->bestCTData._Mylast = 0;
  this->bestCTData._Myend = 0;
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  this->carName._Bx._Buf[0] = 0;
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  this->driverName._Myres = 7;
  this->driverName._Mysize = 0;
  this->driverName._Bx._Buf[0] = 0;
  v3 = &this->trackConfig;
  this->trackConfig._Myres = 7;
  this->trackConfig._Mysize = 0;
  this->trackConfig._Bx._Buf[0] = 0;
  LOBYTE(v13) = 8;
  if ( &this->carName != &aCar->unixName )
    std::wstring::assign(&this->carName, &aCar->unixName, 0, 0xFFFFFFFF);
  v4 = &aCar->sim->track->name;
  if ( &this->trackName != v4 )
    std::wstring::assign(&this->trackName, v4, 0, 0xFFFFFFFF);
  if ( &this->driverName != (std::wstring *)&aCar->driverInfo )
    std::wstring::assign(&this->driverName, &aCar->driverInfo.name, 0, 0xFFFFFFFF);
  v5 = TrackAvatar::getConfig(aCar->sim->track, &result);
  if ( v3 != v5 )
  {
    if ( this->trackConfig._Myres >= 8 )
      operator delete(v3->_Bx._Ptr);
    this->trackConfig._Myres = 7;
    this->trackConfig._Mysize = 0;
    v10 = (unsigned int)v5;
    v3->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->trackConfig, (std::wstring *)v10);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v10 = 3999;
  this->lastRecordingIndex = 0;
  this->lapCount = 0;
  this->recordingInterval = 0.00025000001;
  std::vector<CTData>::resize(&this->currentCTData, v10);
  std::vector<CTData>::resize(&this->bestCTData, 0xF9Fu);
  std::vector<CTData>::resize(&this->lastCTData, 0xF9Fu);
  this->needToSave = 0;
  this->car = aCar;
  this->bestTime = -1;
  this->lastTime = -1;
  v6 = aCar->sim;
  v10 = (unsigned int)this;
  this->physics = *v6->physicsAvatar->engine.cars._Myfirst;
  v9._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_0721caed60733fb79f38e221bf1be9eb_,0>,std::allocator<std::_Func_class<void,OnStepCompleteEvent const &>>,void,OnStepCompleteEvent const &>::`vftable';
  *(_DWORD *)&v9._Bx._Alias[4] = this;
  v9._Mysize = (unsigned int)&v9;
  v7 = &this->physics->evOnStepComplete;
  LOBYTE(v13) = 8;
  Event<float>::addHandler((Event<SessionInfo> *)v7, (std::function<void __cdecl(SessionInfo const &)>)v9, (void *)v10);
  v10 = (unsigned int)this;
  v9._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_4fec62f02147ab69502667dacac15b27_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  *(_DWORD *)&v9._Bx._Alias[4] = this;
  v9._Mysize = (unsigned int)&v9;
  v8 = &this->physics->evOnLapCompleted;
  LOBYTE(v13) = 8;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v8,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v9,
    this);
  ComparativeTelemetryRecorder::loadBest(this, (unsigned int)aCar);
}
void ComparativeTelemetryRecorder::~ComparativeTelemetryRecorder(ComparativeTelemetryRecorder *this)
{
  this->__vftable = (ComparativeTelemetryRecorder_vtbl *)&ComparativeTelemetryRecorder::`vftable';
  ComparativeTelemetryRecorder::saveBest(this);
  std::_Container_base0::_Orphan_all(&this->currentCTData);
  this->currentCTData._Mylast = this->currentCTData._Myfirst;
  std::_Container_base0::_Orphan_all(&this->bestCTData);
  this->bestCTData._Mylast = this->bestCTData._Myfirst;
  std::_Container_base0::_Orphan_all(&this->lastCTData);
  this->lastCTData._Mylast = this->lastCTData._Myfirst;
  if ( this->trackConfig._Myres >= 8 )
    operator delete(this->trackConfig._Bx._Ptr);
  this->trackConfig._Myres = 7;
  this->trackConfig._Mysize = 0;
  this->trackConfig._Bx._Buf[0] = 0;
  if ( this->driverName._Myres >= 8 )
    operator delete(this->driverName._Bx._Ptr);
  this->driverName._Myres = 7;
  this->driverName._Mysize = 0;
  this->driverName._Bx._Buf[0] = 0;
  if ( this->trackName._Myres >= 8 )
    operator delete(this->trackName._Bx._Ptr);
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  if ( this->carName._Myres >= 8 )
    operator delete(this->carName._Bx._Ptr);
  this->carName._Myres = 7;
  this->carName._Mysize = 0;
  this->carName._Bx._Buf[0] = 0;
  if ( this->bestCTData._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bestCTData);
    operator delete(this->bestCTData._Myfirst);
    this->bestCTData._Myfirst = 0;
    this->bestCTData._Mylast = 0;
    this->bestCTData._Myend = 0;
  }
  if ( this->lastCTData._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lastCTData);
    operator delete(this->lastCTData._Myfirst);
    this->lastCTData._Myfirst = 0;
    this->lastCTData._Mylast = 0;
    this->lastCTData._Myend = 0;
  }
  if ( this->currentCTData._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->currentCTData);
    operator delete(this->currentCTData._Myfirst);
    this->currentCTData._Myfirst = 0;
    this->currentCTData._Mylast = 0;
    this->currentCTData._Myend = 0;
  }
  Concurrency::concurrent_queue<CTData,std::allocator<CTData>>::~concurrent_queue<CTData,std::allocator<CTData>>(&this->psQueue);
  GameObject::~GameObject(this);
}
ComparativeTelemetryRecorder *ComparativeTelemetryRecorder::`vector deleting destructor'(ComparativeTelemetryRecorder *this, unsigned int a2)
{
  ComparativeTelemetryRecorder::~ComparativeTelemetryRecorder(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
unsigned int ComparativeTelemetryRecorder::getBestTime(ComparativeTelemetryRecorder *this)
{
  return this->bestTime;
}
std::vector<CTData> *ComparativeTelemetryRecorder::getBestTimeData(ComparativeTelemetryRecorder *this)
{
  return &this->bestCTData;
}
void ComparativeTelemetryRecorder::getCTOpponents(ComparativeTelemetryRecorder *this, std::vector<CTDriver> *opponents)
{
  int v3; // ebx
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  std::wstring *v6; // esi
  int *v7; // eax
  int v8; // ebp
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  const std::wstring *v11; // eax
  CarAvatar *v12; // eax
  int v13; // eax
  unsigned int v14; // ecx
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  unsigned int v17; // ecx
  bool v18; // cf
  char v19; // bl
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  CTDriver *v22; // esi
  _BYTE *v23; // esi
  void (__cdecl *v24)(FILE *); // ebx
  int v25; // ecx
  unsigned int v26; // ebx
  int *v27; // ecx
  std::wstring *v28; // edi
  std::wstring *v29; // esi
  unsigned int v30; // [esp+2Ch] [ebp-230h] BYREF
  int v31; // [esp+30h] [ebp-22Ch]
  int v32; // [esp+34h] [ebp-228h] BYREF
  std::vector<std::wstring> files; // [esp+3Ch] [ebp-220h] BYREF
  int v34; // [esp+48h] [ebp-214h]
  std::vector<CTDriver> *v35; // [esp+4Ch] [ebp-210h]
  unsigned int v36; // [esp+50h] [ebp-20Ch] BYREF
  int v37; // [esp+54h] [ebp-208h] BYREF
  std::ifstream in; // [esp+58h] [ebp-204h] BYREF
  std::wstring v39; // [esp+110h] [ebp-14Ch] BYREF
  std::wstring v40; // [esp+128h] [ebp-134h] BYREF
  std::wstring v41; // [esp+140h] [ebp-11Ch] BYREF
  std::wstring v42; // [esp+158h] [ebp-104h] BYREF
  CTDriver d; // [esp+170h] [ebp-ECh] BYREF
  std::wstring _Right; // [esp+1A4h] [ebp-B8h] BYREF
  std::wstring trackConfig; // [esp+1BCh] [ebp-A0h] BYREF
  std::wstring carName; // [esp+1D4h] [ebp-88h] BYREF
  std::wstring trackName; // [esp+1ECh] [ebp-70h] BYREF
  std::wstring driverName; // [esp+204h] [ebp-58h] BYREF
  std::wstring result; // [esp+21Ch] [ebp-40h] BYREF
  std::wstring v50; // [esp+234h] [ebp-28h] BYREF
  int v51; // [esp+258h] [ebp-4h]

  v3 = 0;
  v35 = opponents;
  v31 = 0;
  v30 = 0;
  std::_Container_base0::_Orphan_all(opponents);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<CTDriver>>>(opponents->_Myfirst, opponents->_Mylast);
  opponents->_Mylast = opponents->_Myfirst;
  _Right._Myres = 7;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  std::wstring::assign(&_Right, L"/Assetto Corsa/ctelemetry/opponents/*.*", 0x27u);
  v51 = 0;
  v4 = Path::getDocumentPath(&result);
  LOBYTE(v51) = 1;
  v5 = std::operator+<wchar_t>(&v50, v4, &_Right);
  LOBYTE(v51) = 2;
  Path::getFiles(&files, v5);
  if ( v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v51) = 6;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  v6 = files._Myfirst;
  _Right._Bx._Buf[0] = 0;
  v34 = 0;
  v7 = &v32;
  v32 = 20;
  _Right._Myres = 7;
  _Right._Mysize = 0;
  v30 = files._Mylast - files._Myfirst;
  if ( v30 <= 0x14 )
    v7 = (int *)&v30;
  if ( *v7 )
  {
    v32 = 20;
    v8 = 0;
    do
    {
      v39._Myres = 7;
      v39._Mysize = 0;
      v39._Bx._Buf[0] = 0;
      std::wstring::assign(&v39, L"/Assetto Corsa/ctelemetry/opponents/", 0x24u);
      LOBYTE(v51) = 7;
      v9 = Path::getDocumentPath(&v40);
      LOBYTE(v51) = 8;
      v10 = std::operator+<wchar_t>(&v42, v9, &v39);
      LOBYTE(v51) = 9;
      v11 = std::operator+<wchar_t>(&v41, v10, &files._Myfirst[v8]);
      LOBYTE(v51) = 10;
      std::ifstream::ifstream(&in, v11, 32, 64, 1);
      if ( v41._Myres >= 8 )
        operator delete(v41._Bx._Ptr);
      v41._Myres = 7;
      v41._Mysize = 0;
      v41._Bx._Buf[0] = 0;
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v42._Myres = 7;
      v42._Mysize = 0;
      v42._Bx._Buf[0] = 0;
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      v40._Myres = 7;
      v40._Mysize = 0;
      v40._Bx._Buf[0] = 0;
      LOBYTE(v51) = 15;
      if ( v39._Myres >= 8 )
        operator delete(v39._Bx._Ptr);
      v39._Myres = 7;
      v39._Bx._Buf[0] = 0;
      v39._Mysize = 0;
      std::istream::read(&in, &v37);
      ksLoadString(&driverName, &in);
      LOBYTE(v51) = 16;
      ksLoadString(&trackName, &in);
      LOBYTE(v51) = 17;
      ksLoadString(&carName, &in);
      LOBYTE(v51) = 18;
      ksLoadString(&trackConfig, &in);
      v12 = this->car;
      LOBYTE(v51) = 19;
      v13 = (int)&v12->sim->track->name;
      v14 = *(_DWORD *)(v13 + 16);
      if ( *(_DWORD *)(v13 + 20) >= 8u )
        v13 = *(_DWORD *)v13;
      if ( std::wstring::compare(&trackName, 0, trackName._Mysize, (const wchar_t *)v13, v14) )
        goto LABEL_29;
      v15 = &this->car->unixName;
      if ( this->car->unixName._Myres >= 8 )
        v15 = (std::wstring *)v15->_Bx._Ptr;
      if ( std::wstring::compare(&carName, 0, carName._Mysize, v15->_Bx._Buf, this->car->unixName._Mysize) )
        goto LABEL_29;
      v16 = TrackAvatar::getConfig(this->car->sim->track, &v40);
      v17 = v16->_Mysize;
      v18 = v16->_Myres < 8;
      LOBYTE(v51) = 20;
      v31 = v3 | 1;
      v30 = v3 | 1;
      if ( !v18 )
        v16 = (std::wstring *)v16->_Bx._Ptr;
      if ( std::wstring::compare(&trackConfig, 0, trackConfig._Mysize, v16->_Bx._Buf, v17) )
LABEL_29:
        v19 = 0;
      else
        v19 = 1;
      v51 = 19;
      if ( (v31 & 1) != 0 )
      {
        v31 &= 0xFFFFFFFE;
        if ( v40._Myres >= 8 )
          operator delete(v40._Bx._Ptr);
      }
      if ( v19 )
      {
        d.driverName._Myres = 7;
        d.driverName._Mysize = 0;
        d.driverName._Bx._Buf[0] = 0;
        d.filePath._Myres = 7;
        d.filePath._Mysize = 0;
        d.filePath._Bx._Buf[0] = 0;
        LOBYTE(v51) = 21;
        std::wstring::assign(&d.driverName, &driverName, 0, 0xFFFFFFFF);
        v39._Myres = 7;
        v39._Mysize = 0;
        v39._Bx._Buf[0] = 0;
        std::wstring::assign(&v39, L"/Assetto Corsa/ctelemetry/opponents/", 0x24u);
        LOBYTE(v51) = 22;
        v20 = Path::getDocumentPath(&v41);
        LOBYTE(v51) = 23;
        v21 = std::operator+<wchar_t>(&v42, v20, &v39);
        LOBYTE(v51) = 24;
        v22 = (CTDriver *)std::operator+<wchar_t>(&v40, v21, &files._Myfirst[v8]);
        if ( &d.filePath != (std::wstring *)v22 )
        {
          if ( d.filePath._Myres >= 8 )
            operator delete(d.filePath._Bx._Ptr);
          d.filePath._Myres = 7;
          d.filePath._Mysize = 0;
          d.filePath._Bx._Buf[0] = 0;
          if ( v22->driverName._Myres >= 8 )
          {
            d.filePath._Bx._Ptr = v22->driverName._Bx._Ptr;
            v22->driverName._Bx._Ptr = 0;
          }
          else if ( v22->driverName._Mysize != -1 )
          {
            _memmove(&d.filePath, v22, 2 * (v22->driverName._Mysize + 1));
          }
          d.filePath._Mysize = v22->driverName._Mysize;
          d.filePath._Myres = v22->driverName._Myres;
          v22->driverName._Myres = 7;
          v22->driverName._Mysize = 0;
          v22->driverName._Bx._Buf[0] = 0;
        }
        if ( v40._Myres >= 8 )
          operator delete(v40._Bx._Ptr);
        v40._Myres = 7;
        v40._Mysize = 0;
        v40._Bx._Buf[0] = 0;
        if ( v42._Myres >= 8 )
          operator delete(v42._Bx._Ptr);
        v42._Myres = 7;
        v42._Mysize = 0;
        v42._Bx._Buf[0] = 0;
        if ( v41._Myres >= 8 )
          operator delete(v41._Bx._Ptr);
        v41._Myres = 7;
        v41._Mysize = 0;
        v41._Bx._Buf[0] = 0;
        LOBYTE(v51) = 21;
        if ( v39._Myres >= 8 )
          operator delete(v39._Bx._Ptr);
        std::istream::read(&in, &v36);
        d.time = v36;
        std::vector<CTDriver>::push_back(v35, &d);
        LOBYTE(v51) = 19;
        if ( d.filePath._Myres >= 8 )
          operator delete(d.filePath._Bx._Ptr);
        d.filePath._Myres = 7;
        d.filePath._Mysize = 0;
        d.filePath._Bx._Buf[0] = 0;
        if ( d.driverName._Myres >= 8 )
          operator delete(d.driverName._Bx._Ptr);
      }
      v23 = in.gap10;
      if ( *(_DWORD *)in._Filebuffer )
      {
        v24 = (void (__cdecl *)(FILE *))_fclose;
        if ( !std::filebuf::_Endwrite((std::filebuf *)in.gap10) )
          v23 = 0;
        if ( _fclose(*(FILE **)in._Filebuffer) )
          v23 = 0;
      }
      else
      {
        v24 = (void (__cdecl *)(FILE *))_fclose;
        v23 = 0;
      }
      in.gap10[76] = 0;
      in.gap10[69] = 0;
      std::streambuf::_Init(in.gap10);
      *(_DWORD *)in._Filebuffer = 0;
      *(_DWORD *)&in.gap10[72] = `std::filebuf::_Init'::`2'::_Stinit;
      *(_DWORD *)&in.gap10[64] = 0;
      if ( !v23 )
        std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
      if ( trackConfig._Myres >= 8 )
        operator delete(trackConfig._Bx._Ptr);
      trackConfig._Myres = 7;
      trackConfig._Mysize = 0;
      trackConfig._Bx._Buf[0] = 0;
      if ( carName._Myres >= 8 )
        operator delete(carName._Bx._Ptr);
      carName._Myres = 7;
      carName._Mysize = 0;
      carName._Bx._Buf[0] = 0;
      if ( trackName._Myres >= 8 )
        operator delete(trackName._Bx._Ptr);
      trackName._Myres = 7;
      trackName._Mysize = 0;
      trackName._Bx._Buf[0] = 0;
      if ( driverName._Myres >= 8 )
        operator delete(driverName._Bx._Ptr);
      driverName._Myres = 7;
      driverName._Bx._Buf[0] = 0;
      driverName._Mysize = 0;
      LOBYTE(v51) = 6;
      *(_DWORD *)&in.gap0[*(_DWORD *)(*(_DWORD *)in.gap0 + 4)] = &std::ifstream::`vftable';
      *(int *)((char *)&v37 + *(_DWORD *)(*(_DWORD *)in.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)in.gap0 + 4) - 112;
      v25 = *(_DWORD *)in._Filebuffer;
      *(_DWORD *)in.gap10 = &std::filebuf::`vftable';
      if ( *(_DWORD *)in._Filebuffer && **(std::ifstream ***)&in.gap10[12] == (std::ifstream *)&in.gap10[68] )
      {
        std::streambuf::setg(in.gap10, *(_DWORD *)&in.gap10[56], *(_DWORD *)&in.gap10[56], *(_DWORD *)&in.gap10[60]);
        v25 = *(_DWORD *)in._Filebuffer;
      }
      if ( in.gap10[76] )
      {
        if ( v25 )
        {
          std::filebuf::_Endwrite((std::filebuf *)in.gap10);
          v24(*(FILE **)in._Filebuffer);
        }
        in.gap10[76] = 0;
        in.gap10[69] = 0;
        std::streambuf::_Init(in.gap10);
        *(_DWORD *)in._Filebuffer = 0;
        *(_DWORD *)&in.gap10[72] = `std::filebuf::_Init'::`2'::_Stinit;
        *(_DWORD *)&in.gap10[64] = 0;
      }
      std::streambuf::~streambuf<char,std::char_traits<char>>(in.gap10);
      std::istream::~istream<char,std::char_traits<char>>(&in.gap10[8]);
      std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
      v6 = files._Myfirst;
      ++v8;
      v26 = v34 + 1;
      v27 = &v32;
      ++v34;
      v30 = files._Mylast - files._Myfirst;
      if ( v30 <= 0x14 )
        v27 = (int *)&v30;
      v18 = v26 < *v27;
      v3 = v31;
    }
    while ( v18 );
  }
  v51 = -1;
  if ( v6 )
  {
    std::_Container_base0::_Orphan_all(&files);
    v28 = files._Mylast;
    v29 = files._Myfirst;
    if ( files._Myfirst != files._Mylast )
    {
      do
      {
        if ( v29->_Myres >= 8 )
          operator delete(v29->_Bx._Ptr);
        v29->_Myres = 7;
        v29->_Mysize = 0;
        v29->_Bx._Buf[0] = 0;
        ++v29;
      }
      while ( v29 != v28 );
      v29 = files._Myfirst;
    }
    operator delete(v29);
  }
}
unsigned int ComparativeTelemetryRecorder::getLastTime(ComparativeTelemetryRecorder *this)
{
  return this->lastTime;
}
std::vector<CTData> *ComparativeTelemetryRecorder::getLastTimeData(ComparativeTelemetryRecorder *this)
{
  return &this->lastCTData;
}
void __usercall ComparativeTelemetryRecorder::loadBest(ComparativeTelemetryRecorder *this@<ecx>, unsigned int a2@<ebx>)
{
  std::wstring *v3; // esi
  DriverInfo *v4; // ecx
  std::wstring *v5; // eax
  CarAvatar *v6; // ecx
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // ecx
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  DriverInfo *v15; // eax
  unsigned int v16; // ecx
  std::wstring *v17; // eax
  std::wstring *v18; // ecx
  std::wstring *v19; // eax
  const std::wstring *v20; // eax
  bool v21; // al
  int v22; // edi
  int v23; // esi
  CTData *v24; // ecx
  _BYTE *v25; // esi
  std::ifstream in; // [esp+30h] [ebp-1E0h] BYREF
  char v27[4]; // [esp+E8h] [ebp-128h] BYREF
  ComparativeTelemetryRecorder *v28; // [esp+ECh] [ebp-124h]
  int v29; // [esp+F0h] [ebp-120h] BYREF
  char v30; // [esp+F7h] [ebp-119h]
  std::wstring _Right; // [esp+F8h] [ebp-118h] BYREF
  std::wstring v32; // [esp+110h] [ebp-100h] BYREF
  std::wstring v33; // [esp+128h] [ebp-E8h] BYREF
  std::wstring result; // [esp+140h] [ebp-D0h] BYREF
  std::wstring path; // [esp+158h] [ebp-B8h] BYREF
  std::wstring v36; // [esp+170h] [ebp-A0h] BYREF
  std::wstring v37; // [esp+188h] [ebp-88h] BYREF
  std::wstring v38; // [esp+1A0h] [ebp-70h] BYREF
  std::wstring v39; // [esp+1B8h] [ebp-58h] BYREF
  std::wstring v40; // [esp+1D0h] [ebp-40h] BYREF
  std::wstring v41; // [esp+1E8h] [ebp-28h] BYREF
  int v42; // [esp+20Ch] [ebp-4h]

  v28 = this;
  v29 = 0;
  v3 = TrackAvatar::getConfig(this->car->sim->track, &result);
  v4 = &this->car->driverInfo;
  v42 = 0;
  v5 = std::operator+<wchar_t>(&v33, &v4->name, L"_");
  v6 = this->car;
  LOBYTE(v42) = 1;
  v7 = std::operator+<wchar_t>(&v37, v5, &v6->sim->track->name);
  LOBYTE(v42) = 2;
  v8 = std::operator+<wchar_t>(&v41, v7, L"_");
  LOBYTE(v42) = 3;
  v9 = std::operator+<wchar_t>(&v39, v8, v3);
  LOBYTE(v42) = 4;
  v10 = std::operator+<wchar_t>(&v40, v9, L"_");
  v11 = &this->car->unixName;
  LOBYTE(v42) = 5;
  v12 = std::operator+<wchar_t>(&v38, v10, v11);
  LOBYTE(v42) = 6;
  std::operator+<wchar_t>(&_Right, v12, L".tc");
  if ( v38._Myres >= 8 )
    operator delete(v38._Bx._Ptr);
  v38._Myres = 7;
  v38._Mysize = 0;
  v38._Bx._Buf[0] = 0;
  if ( v40._Myres >= 8 )
    operator delete(v40._Bx._Ptr);
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  if ( v39._Myres >= 8 )
    operator delete(v39._Bx._Ptr);
  v39._Myres = 7;
  v39._Mysize = 0;
  v39._Bx._Buf[0] = 0;
  if ( v41._Myres >= 8 )
    operator delete(v41._Bx._Ptr);
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  if ( v37._Myres >= 8 )
    operator delete(v37._Bx._Ptr);
  v37._Myres = 7;
  v37._Mysize = 0;
  v37._Bx._Buf[0] = 0;
  if ( v33._Myres >= 8 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v42) = 14;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v13 = Path::getDocumentPath(&v36);
  LOBYTE(v42) = 15;
  v14 = std::operator+<wchar_t>(&v32, v13, L"/Assetto Corsa/ctelemetry/player/");
  LOBYTE(v42) = 16;
  std::operator+<wchar_t>(&path, v14, &_Right);
  if ( v32._Myres >= 8 )
    operator delete(v32._Bx._Ptr);
  v32._Myres = 7;
  v32._Mysize = 0;
  v32._Bx._Buf[0] = 0;
  LOBYTE(v42) = 19;
  if ( v36._Myres >= 8 )
    operator delete(v36._Bx._Ptr);
  v36._Myres = 7;
  v36._Bx._Buf[0] = 0;
  v36._Mysize = 0;
  if ( Path::fileExists(a2, &path, 0) )
  {
    std::ifstream::ifstream(&in, &path, 32, 64, 1);
    LOBYTE(v42) = 20;
    std::istream::read(&in, v27);
    ksLoadString(&v40, &in);
    LOBYTE(v42) = 21;
    ksLoadString(&v41, &in);
    LOBYTE(v42) = 22;
    ksLoadString(&v39, &in);
    LOBYTE(v42) = 23;
    ksLoadString(&v38, &in);
    v15 = &this->car->driverInfo;
    LOBYTE(v42) = 24;
    v16 = v15->name._Mysize;
    if ( v15->name._Myres >= 8 )
      v15 = (DriverInfo *)v15->name._Bx._Ptr;
    if ( std::wstring::compare(&v40, 0, v40._Mysize, v15->name._Bx._Buf, v16) )
      goto LABEL_30;
    v17 = &v41;
    if ( v41._Myres >= 8 )
      v17 = (std::wstring *)v41._Bx._Ptr;
    v18 = &this->car->sim->track->name;
    if ( std::wstring::compare(v18, 0, v18->_Mysize, v17->_Bx._Buf, v41._Mysize) )
      goto LABEL_30;
    v19 = &this->car->unixName;
    if ( this->car->unixName._Myres >= 8 )
      v19 = (std::wstring *)v19->_Bx._Ptr;
    if ( std::wstring::compare(&v39, 0, v39._Mysize, v19->_Bx._Buf, this->car->unixName._Mysize)
      || (v20 = TrackAvatar::getConfig(this->car->sim->track, &v36),
          LOBYTE(v42) = 25,
          v29 = 1,
          v21 = std::operator!=<wchar_t>(v20, &v38),
          v30 = 0,
          v21) )
    {
LABEL_30:
      v30 = 1;
    }
    v42 = 24;
    if ( (v29 & 1) != 0 && v36._Myres >= 8 )
      operator delete(v36._Bx._Ptr);
    if ( !v30 )
    {
      std::istream::read(&in, &v29);
      this->bestTime = v29;
      std::istream::read(&in, &v29);
      v22 = v29;
      if ( v29 > 0 )
      {
        v23 = 0;
        do
        {
          *(_DWORD *)&v37._Bx._Alias[4] = 0;
          *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&v37._Bx + 8) = 0i64;
          std::istream::read(&in, &v37._Bx._Alias[4]);
          ++v23;
          v24 = v28->bestCTData._Myfirst;
          *(__m128i *)&v24[v23 - 1].gear = _mm_loadu_si128((const __m128i *)&v37._Bx._Buf[2]);
          LODWORD(v24[v23 - 1].brake) = v37._Myres;
          --v22;
        }
        while ( v22 );
      }
      v25 = in.gap10;
      if ( *(_DWORD *)in._Filebuffer )
      {
        if ( !std::filebuf::_Endwrite((std::filebuf *)in.gap10) )
          v25 = 0;
        if ( _fclose(*(FILE **)in._Filebuffer) )
          v25 = 0;
      }
      else
      {
        v25 = 0;
      }
      in.gap10[76] = 0;
      in.gap10[69] = 0;
      std::streambuf::_Init(in.gap10);
      *(_DWORD *)in._Filebuffer = 0;
      *(_DWORD *)&in.gap10[72] = `std::filebuf::_Init'::`2'::_Stinit;
      *(_DWORD *)&in.gap10[64] = 0;
      if ( !v25 )
        std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
    }
    if ( v38._Myres >= 8 )
      operator delete(v38._Bx._Ptr);
    v38._Myres = 7;
    v38._Bx._Buf[0] = 0;
    v38._Mysize = 0;
    if ( v39._Myres >= 8 )
      operator delete(v39._Bx._Ptr);
    v39._Myres = 7;
    v39._Bx._Buf[0] = 0;
    v39._Mysize = 0;
    if ( v41._Myres >= 8 )
      operator delete(v41._Bx._Ptr);
    v41._Myres = 7;
    v41._Bx._Buf[0] = 0;
    v41._Mysize = 0;
    if ( v40._Myres >= 8 )
      operator delete(v40._Bx._Ptr);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
    std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
  }
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
}
std::vector<CTData> *__userpurge ComparativeTelemetryRecorder::loadCTOpponent@<eax>(ComparativeTelemetryRecorder *this@<ecx>, unsigned int a2@<ebx>, std::vector<CTData> *result, std::wstring fileName)
{
  signed int v4; // edi
  int v5; // edi
  bool v6; // zf
  CTData *v7; // ecx
  _BYTE *v8; // edi
  std::ifstream in; // [esp+30h] [ebp-148h] BYREF
  std::vector<CTData> *v11; // [esp+E8h] [ebp-90h]
  int v12; // [esp+ECh] [ebp-8Ch] BYREF
  __int128 v13; // [esp+F0h] [ebp-88h]
  int v14; // [esp+100h] [ebp-78h]
  unsigned int _Newsize; // [esp+104h] [ebp-74h] BYREF
  std::wstring v16; // [esp+108h] [ebp-70h] BYREF
  std::wstring v17; // [esp+120h] [ebp-58h] BYREF
  std::wstring v18; // [esp+138h] [ebp-40h] BYREF
  std::wstring v19; // [esp+150h] [ebp-28h] BYREF
  int v20; // [esp+174h] [ebp-4h]

  v11 = result;
  v20 = 1;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v14 = 1;
  if ( Path::fileExists(a2, &fileName, 0) )
  {
    std::ifstream::ifstream(&in, &fileName, 32, 64, 1);
    LOBYTE(v20) = 2;
    std::istream::read(&in, &_Newsize);
    ksLoadString(&v17, &in);
    LOBYTE(v20) = 3;
    ksLoadString(&v16, &in);
    LOBYTE(v20) = 4;
    ksLoadString(&v18, &in);
    LOBYTE(v20) = 5;
    ksLoadString(&v19, &in);
    LOBYTE(v20) = 6;
    std::istream::read(&in, &_Newsize);
    std::istream::read(&in, &_Newsize);
    v4 = _Newsize;
    std::vector<CTData>::resize(result, _Newsize);
    if ( v4 > 0 )
    {
      v5 = 0;
      do
      {
        v12 = 0;
        v13 = 0i64;
        std::istream::read(&in, &v12);
        v6 = _Newsize-- == 1;
        ++v5;
        v7 = result->_Myfirst;
        *(__m128i *)&v7[v5 - 1].gear = _mm_loadu_si128((const __m128i *)&v12);
        v7[v5 - 1].brake = *((float *)&v13 + 3);
      }
      while ( !v6 );
    }
    v8 = in.gap10;
    if ( *(_DWORD *)in._Filebuffer )
    {
      if ( !std::filebuf::_Endwrite((std::filebuf *)in.gap10) )
        v8 = 0;
      if ( _fclose(*(FILE **)in._Filebuffer) )
        v8 = 0;
    }
    else
    {
      v8 = 0;
    }
    in.gap10[76] = 0;
    in.gap10[69] = 0;
    std::streambuf::_Init(in.gap10);
    *(_DWORD *)in._Filebuffer = 0;
    *(_DWORD *)&in.gap10[72] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&in.gap10[64] = 0;
    if ( !v8 )
      std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
    if ( v19._Myres >= 8 )
      operator delete(v19._Bx._Ptr);
    v19._Myres = 7;
    v19._Mysize = 0;
    v19._Bx._Buf[0] = 0;
    if ( v18._Myres >= 8 )
      operator delete(v18._Bx._Ptr);
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    if ( v16._Myres >= 8 )
      operator delete(v16._Bx._Ptr);
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    if ( v17._Myres >= 8 )
      operator delete(v17._Bx._Ptr);
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
    std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
  }
  if ( fileName._Myres >= 8 )
    operator delete(fileName._Bx._Ptr);
  return result;
}
void ComparativeTelemetryRecorder::saveBest(ComparativeTelemetryRecorder *this)
{
  int v2; // ecx
  unsigned int v3; // ebx
  int v4; // esi
  CTData *v5; // ecx
  float v6; // xmm0_4
  int v7; // ecx
  float v8; // xmm0_4
  unsigned int v9; // ebp
  int v10; // ebx
  CTData *v11; // esi
  double v12; // st7
  float v13; // xmm0_4
  CTData *v14; // esi
  double v15; // st7
  float v16; // xmm0_4
  CTData *v17; // esi
  double v18; // st7
  float v19; // xmm0_4
  CTData *v20; // esi
  double v21; // st7
  float v22; // xmm0_4
  int v23; // ecx
  std::wstring *v24; // eax
  const std::wstring *v25; // eax
  std::wstring *v26; // eax
  const std::wstring *v27; // eax
  std::wstring *v28; // esi
  DriverInfo *v29; // ecx
  std::wstring *v30; // ecx
  CarAvatar *v31; // eax
  std::wstring *v32; // eax
  std::wstring *v33; // eax
  std::wstring *v34; // eax
  std::wstring *v35; // ecx
  CarAvatar *v36; // eax
  std::wstring *v37; // eax
  std::wstring *v38; // eax
  std::wstring *v39; // eax
  _BYTE *v40; // esi
  int v41; // ecx
  __int64 ref; // [esp+74h] [ebp-31Ch]
  float v43; // [esp+90h] [ebp-300h] BYREF
  int ctDataSize; // [esp+98h] [ebp-2F8h] BYREF
  int version; // [esp+9Ch] [ebp-2F4h] BYREF
  std::ofstream out; // [esp+A0h] [ebp-2F0h] BYREF
  std::wstring v47; // [esp+148h] [ebp-248h] BYREF
  std::wstring result; // [esp+160h] [ebp-230h] BYREF
  std::wstring wFn; // [esp+178h] [ebp-218h] BYREF
  std::wstring filename; // [esp+190h] [ebp-200h] BYREF
  std::wstring v51; // [esp+1A8h] [ebp-1E8h] BYREF
  std::wstring v52; // [esp+1C0h] [ebp-1D0h] BYREF
  std::wstring v53; // [esp+1D8h] [ebp-1B8h] BYREF
  std::wstring v54; // [esp+1F0h] [ebp-1A0h] BYREF
  std::wstring v55; // [esp+208h] [ebp-188h] BYREF
  std::wstring v56; // [esp+220h] [ebp-170h] BYREF
  std::wstring v57; // [esp+238h] [ebp-158h] BYREF
  Curve gearCurve; // [esp+250h] [ebp-140h] BYREF
  Curve brakeCurve; // [esp+29Ch] [ebp-F4h] BYREF
  Curve gasCurve; // [esp+2E8h] [ebp-A8h] BYREF
  Curve speedCurve; // [esp+334h] [ebp-5Ch] BYREF
  int v62; // [esp+38Ch] [ebp-4h]

  if ( this->needToSave )
  {
    Curve::Curve(&brakeCurve);
    v62 = 0;
    Curve::Curve(&gasCurve);
    LOBYTE(v62) = 1;
    Curve::Curve(&speedCurve);
    LOBYTE(v62) = 2;
    Curve::Curve(&gearCurve);
    v2 = (char *)this->bestCTData._Mylast - (char *)this->bestCTData._Myfirst;
    v3 = 0;
    LOBYTE(v62) = 3;
    if ( v2 / 20 )
    {
      v4 = 0;
      do
      {
        Curve::addValue(
          &brakeCurve,
          this->bestCTData._Myfirst[v4].normalizedPosition,
          this->bestCTData._Myfirst[v4].brake);
        Curve::addValue(&gasCurve, this->bestCTData._Myfirst[v4].normalizedPosition, this->bestCTData._Myfirst[v4].gas);
        Curve::addValue(
          &speedCurve,
          this->bestCTData._Myfirst[v4].normalizedPosition,
          this->bestCTData._Myfirst[v4].speed);
        v5 = this->bestCTData._Myfirst;
        v6 = (float)v5[v4].gear;
        Curve::addValue(&gearCurve, v5[v4].normalizedPosition, v6);
        ++v3;
        ++v4;
      }
      while ( v3 < this->bestCTData._Mylast - this->bestCTData._Myfirst );
    }
    v7 = (char *)this->bestCTData._Mylast - (char *)this->bestCTData._Myfirst;
    v8 = 0.0;
    v43 = 0.0;
    v9 = 0;
    if ( v7 / 20 )
    {
      v10 = 0;
      do
      {
        v11 = this->bestCTData._Myfirst;
        v12 = Curve::getValue(&brakeCurve, v8);
        v13 = v43;
        v11[v10].brake = v12;
        v14 = this->bestCTData._Myfirst;
        v15 = Curve::getValue(&gasCurve, v13);
        v16 = v43;
        v14[v10].gas = v15;
        v17 = this->bestCTData._Myfirst;
        v18 = Curve::getValue(&speedCurve, v16);
        v19 = v43;
        v17[v10].speed = v18;
        v20 = this->bestCTData._Myfirst;
        v21 = Curve::getValue(&gearCurve, v19);
        v22 = v43;
        ++v9;
        *(_QWORD *)v47._Bx._Buf = (__int64)v21;
        v20[v10++].gear = (__int64)v21;
        v23 = (char *)this->bestCTData._Mylast - (char *)this->bestCTData._Myfirst;
        v8 = v22 + this->recordingInterval;
        v43 = v8;
      }
      while ( v9 < v23 / 20 );
    }
    v24 = Path::getDocumentPath(&result);
    LOBYTE(v62) = 4;
    v25 = std::operator+<wchar_t>(&v47, v24, L"/Assetto Corsa/ctelemetry/");
    LOBYTE(v62) = 5;
    Path::createFolder(v25);
    if ( v47._Myres >= 8 )
      operator delete(v47._Bx._Ptr);
    v47._Myres = 7;
    v47._Mysize = 0;
    v47._Bx._Buf[0] = 0;
    LOBYTE(v62) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v26 = Path::getDocumentPath(&result);
    LOBYTE(v62) = 6;
    v27 = std::operator+<wchar_t>(&v47, v26, L"/Assetto Corsa/ctelemetry/player/");
    LOBYTE(v62) = 7;
    Path::createFolder(v27);
    if ( v47._Myres >= 8 )
      operator delete(v47._Bx._Ptr);
    v47._Myres = 7;
    v47._Mysize = 0;
    v47._Bx._Buf[0] = 0;
    LOBYTE(v62) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v28 = TrackAvatar::getConfig(this->car->sim->track, &v56);
    v29 = &this->car->driverInfo;
    LOBYTE(v62) = 8;
    v30 = std::operator+<wchar_t>(&v57, &v29->name, L"_");
    v31 = this->car;
    LOBYTE(v62) = 9;
    v32 = std::operator+<wchar_t>(&v55, v30, &v31->sim->track->name);
    LOBYTE(v62) = 10;
    v33 = std::operator+<wchar_t>(&v51, v32, L"_");
    LOBYTE(v62) = 11;
    v34 = std::operator+<wchar_t>(&v52, v33, v28);
    LOBYTE(v62) = 12;
    v35 = std::operator+<wchar_t>(&v54, v34, L"_");
    v36 = this->car;
    LOBYTE(v62) = 13;
    v37 = std::operator+<wchar_t>(&v47, v35, &v36->unixName);
    LOBYTE(v62) = 14;
    std::operator+<wchar_t>(&filename, v37, L".tc");
    if ( v47._Myres >= 8 )
      operator delete(v47._Bx._Ptr);
    v47._Myres = 7;
    v47._Mysize = 0;
    v47._Bx._Buf[0] = 0;
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    v54._Myres = 7;
    v54._Mysize = 0;
    v54._Bx._Buf[0] = 0;
    if ( v52._Myres >= 8 )
      operator delete(v52._Bx._Ptr);
    v52._Myres = 7;
    v52._Mysize = 0;
    v52._Bx._Buf[0] = 0;
    if ( v51._Myres >= 8 )
      operator delete(v51._Bx._Ptr);
    v51._Myres = 7;
    v51._Mysize = 0;
    v51._Bx._Buf[0] = 0;
    if ( v55._Myres >= 8 )
      operator delete(v55._Bx._Ptr);
    v55._Myres = 7;
    v55._Mysize = 0;
    v55._Bx._Buf[0] = 0;
    if ( v57._Myres >= 8 )
      operator delete(v57._Bx._Ptr);
    v57._Myres = 7;
    v57._Mysize = 0;
    v57._Bx._Buf[0] = 0;
    LOBYTE(v62) = 22;
    if ( v56._Myres >= 8 )
      operator delete(v56._Bx._Ptr);
    v56._Myres = 7;
    v56._Bx._Buf[0] = 0;
    v56._Mysize = 0;
    v38 = Path::getDocumentPath(&result);
    LOBYTE(v62) = 23;
    v39 = std::operator+<wchar_t>(&v53, v38, L"/Assetto Corsa/ctelemetry/player/");
    LOBYTE(v62) = 24;
    std::operator+<wchar_t>(&wFn, v39, &filename);
    if ( v53._Myres >= 8 )
      operator delete(v53._Bx._Ptr);
    v53._Myres = 7;
    v53._Mysize = 0;
    v53._Bx._Buf[0] = 0;
    LOBYTE(v62) = 27;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    std::ofstream::ofstream(&out, &wFn, 34, 64, 1);
    LOBYTE(v62) = 28;
    version = 1;
    std::ostream::write(&out, &version, 4, 0);
    ksEncodeUtf8((std::vector<char> *)&v47, &this->driverName);
    LODWORD(v43) = *(_DWORD *)&v47._Bx._Alias[4] - (unsigned int)v47._Bx._Ptr;
    LOBYTE(v62) = 29;
    std::ostream::write(&out, &v43, 4, 0);
    std::ostream::write(&out, v47._Bx._Ptr, LODWORD(v43), SLODWORD(v43) >> 31);
    LOBYTE(v62) = 28;
    if ( v47._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&v47);
      operator delete(v47._Bx._Ptr);
    }
    ksEncodeUtf8((std::vector<char> *)&v47, &this->trackName);
    LODWORD(v43) = *(_DWORD *)&v47._Bx._Alias[4] - (unsigned int)v47._Bx._Ptr;
    LOBYTE(v62) = 30;
    std::ostream::write(&out, &v43, 4, 0);
    std::ostream::write(&out, v47._Bx._Ptr, LODWORD(v43), SLODWORD(v43) >> 31);
    LOBYTE(v62) = 28;
    if ( v47._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&v47);
      operator delete(v47._Bx._Ptr);
    }
    ksEncodeUtf8((std::vector<char> *)&v47, &this->carName);
    LODWORD(v43) = *(_DWORD *)&v47._Bx._Alias[4] - (unsigned int)v47._Bx._Ptr;
    LOBYTE(v62) = 31;
    std::ostream::write(&out, &v43, 4, 0);
    std::ostream::write(&out, v47._Bx._Ptr, LODWORD(v43), SLODWORD(v43) >> 31);
    LOBYTE(v62) = 28;
    if ( v47._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&v47);
      operator delete(v47._Bx._Ptr);
    }
    ksEncodeUtf8((std::vector<char> *)&v47, &this->trackConfig);
    LODWORD(v43) = *(_DWORD *)&v47._Bx._Alias[4] - (unsigned int)v47._Bx._Ptr;
    LOBYTE(v62) = 32;
    std::ostream::write(&out, &v43, 4, 0);
    std::ostream::write(&out, v47._Bx._Ptr, LODWORD(v43), SLODWORD(v43) >> 31);
    LOBYTE(v62) = 28;
    if ( v47._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&v47);
      operator delete(v47._Bx._Ptr);
    }
    std::ostream::write(&out, &this->bestTime, 4, 0);
    ctDataSize = this->bestCTData._Mylast - this->bestCTData._Myfirst;
    std::ostream::write(&out, &ctDataSize, 4, 0);
    ref = (unsigned int)(20 * (this->bestCTData._Mylast - this->bestCTData._Myfirst));
    std::ostream::write(&out, this->bestCTData._Myfirst, ref, HIDWORD(ref));
    v40 = &out.gap0[4];
    if ( *(_DWORD *)&out._Filebuffer[4] )
    {
      if ( !std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]) )
        v40 = 0;
      if ( _fclose(*(FILE **)&out._Filebuffer[4]) )
        v40 = 0;
    }
    else
    {
      v40 = 0;
    }
    out._Filebuffer[0] = 0;
    out.gap0[73] = 0;
    std::streambuf::_Init(&out.gap0[4]);
    *(_DWORD *)&out._Filebuffer[4] = 0;
    *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&out.gap0[68] = 0;
    if ( !v40 )
      std::ios::setstate((char *)&out + *(_DWORD *)(*(_DWORD *)out.gap0 + 4), 2, 0);
    LOBYTE(v62) = 27;
    *(_DWORD *)&out.gap0[*(_DWORD *)(*(_DWORD *)out.gap0 + 4)] = &std::ofstream::`vftable';
    *(int *)((char *)&version + *(_DWORD *)(*(_DWORD *)out.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)out.gap0 + 4) - 96;
    v41 = *(_DWORD *)&out._Filebuffer[4];
    *(_DWORD *)&out.gap0[4] = &std::filebuf::`vftable';
    if ( *(_DWORD *)&out._Filebuffer[4] && **(std::ofstream ***)&out.gap0[16] == (std::ofstream *)&out.gap0[72] )
    {
      std::streambuf::setg(&out.gap0[4], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[60], *(_DWORD *)&out.gap0[64]);
      v41 = *(_DWORD *)&out._Filebuffer[4];
    }
    if ( out._Filebuffer[0] )
    {
      if ( v41 )
      {
        std::filebuf::_Endwrite((std::filebuf *)&out.gap0[4]);
        _fclose(*(FILE **)&out._Filebuffer[4]);
      }
      out._Filebuffer[0] = 0;
      out.gap0[73] = 0;
      std::streambuf::_Init(&out.gap0[4]);
      *(_DWORD *)&out._Filebuffer[4] = 0;
      *(_DWORD *)&out.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
      *(_DWORD *)&out.gap0[68] = 0;
    }
    std::streambuf::~streambuf<char,std::char_traits<char>>(&out.gap0[4]);
    std::ostream::~ostream<char,std::char_traits<char>>(&out.gap0[8]);
    std::ios::~ios<char,std::char_traits<char>>(&out.gap58[8]);
    if ( wFn._Myres >= 8 )
      operator delete(wFn._Bx._Ptr);
    wFn._Myres = 7;
    wFn._Mysize = 0;
    wFn._Bx._Buf[0] = 0;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    LOBYTE(v62) = 2;
    Curve::~Curve(&gearCurve);
    LOBYTE(v62) = 1;
    Curve::~Curve(&speedCurve);
    LOBYTE(v62) = 0;
    Curve::~Curve(&gasCurve);
    v62 = -1;
    Curve::~Curve(&brakeCurve);
  }
}
void ComparativeTelemetryRecorder::shutdown(ComparativeTelemetryRecorder *this)
{
  Event<OnStepCompleteEvent>::removeHandler((Event<vec3f> *)&this->physics->evOnStepComplete, this);
  Event<OnStepCompleteEvent>::removeHandler((Event<vec3f> *)&this->physics->evOnLapCompleted, this);
}
void ComparativeTelemetryRecorder::update(ComparativeTelemetryRecorder *this, float dt)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  CTData *v5; // ecx
  unsigned int v6; // edx
  CTData data; // [esp+8h] [ebp-14h] BYREF

  data.gear = 0;
  *(_OWORD *)&data.normalizedPosition = 0i64;
  while ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(&this->psQueue, &data) )
  {
    if ( RaceManager::getLapCount(this->car->sim->raceManager, this->car) )
    {
      v3 = (unsigned int)(float)((float)(unsigned int)(this->currentCTData._Mylast - this->currentCTData._Myfirst)
                               * (float)((float)(this->recordingInterval * 0.5) + data.normalizedPosition));
      v4 = this->lastRecordingIndex;
      if ( v3 - v4 <= ((int)((unsigned __int64)(1717986919i64
                                              * ((char *)this->currentCTData._Mylast
                                               - (char *)this->currentCTData._Myfirst)) >> 32) >> 3)
                    + ((unsigned int)((unsigned __int64)(1717986919i64
                                                       * ((char *)this->currentCTData._Mylast
                                                        - (char *)this->currentCTData._Myfirst)) >> 32) >> 31)
                    - 3
        && v3 > v4 )
      {
        do
        {
          v5 = this->currentCTData._Myfirst;
          v6 = this->lastRecordingIndex;
          *(__m128i *)&v5[v6].gear = _mm_loadu_si128((const __m128i *)&data);
          v5[v6].brake = data.brake;
          ++this->lastRecordingIndex;
        }
        while ( v3 > this->lastRecordingIndex );
      }
    }
  }
}
