#include "warningreporter.h"
void __userpurge WarningReporter::WarningReporter(WarningReporter *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  double v4; // st7
  bool v5; // cf
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  std::wstring v11; // [esp-1Ch] [ebp-B8h] BYREF
  Game *v12; // [esp-4h] [ebp-A0h]
  WarningReporter *v13; // [esp+14h] [ebp-88h]
  std::wstring section; // [esp+18h] [ebp-84h] BYREF
  std::wstring key; // [esp+30h] [ebp-6Ch] BYREF
  INIReaderDocuments warningsini; // [esp+48h] [ebp-54h] BYREF
  int v17; // [esp+98h] [ebp-4h]

  v13 = this;
  v12 = aSim->game;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"WARNING_REPORTER", 0x10u);
  GameObject::GameObject(this, v11, v12);
  this->__vftable = (WarningReporter_vtbl *)&WarningReporter::`vftable';
  this->sim = aSim;
  this->loadingTime = 0.0;
  this->cpuWS.type = eCPU;
  this->cpuWS.bound = 0.0;
  this->cpuWS.duration = 0.0;
  this->cpuWS.encountered = 0;
  this->cpuWS.timestamp = 0.0;
  this->cpuWS.reportTimer = 5000.0;
  this->cpuWS.maxTimeOverbound = 0.0;
  this->cpuWS.meanValue = -1.0;
  this->gpuWS.type = eFPS;
  this->gpuWS.bound = 0.0;
  this->gpuWS.duration = 0.0;
  this->gpuWS.encountered = 0;
  this->gpuWS.timestamp = 0.0;
  this->gpuWS.reportTimer = 5000.0;
  this->gpuWS.maxTimeOverbound = 0.0;
  this->gpuWS.meanValue = -1.0;
  this->cpuWA.type = eCPU;
  this->cpuWA.bound = 0.0;
  this->cpuWA.duration = 0.0;
  this->cpuWA.encountered = 0;
  this->cpuWA.timestamp = 0.0;
  this->cpuWA.reportTimer = 5000.0;
  this->cpuWA.maxTimeOverbound = 0.0;
  this->cpuWA.meanValue = -1.0;
  this->gpuWA.type = eFPS;
  this->gpuWA.bound = 0.0;
  this->gpuWA.duration = 0.0;
  this->gpuWA.encountered = 0;
  this->gpuWA.timestamp = 0.0;
  this->gpuWA.reportTimer = 5000.0;
  this->gpuWA.maxTimeOverbound = 0.0;
  this->gpuWA.meanValue = -1.0;
  v17 = 0;
  this->overboundArray._Myfirst = 0;
  this->overboundArray._Mylast = 0;
  this->overboundArray._Myend = 0;
  this->overboundAverageArray._Myfirst = 0;
  this->overboundAverageArray._Mylast = 0;
  this->overboundAverageArray._Myend = 0;
  v12 = 0;
  this->currentIndexAverage = 0;
  this->currentIndex = 0;
  LOBYTE(v17) = 2;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"cfg/warning_reporter.ini", 0x18u);
  INIReaderDocuments::INIReaderDocuments(&warningsini, a2, v11, (bool)v12);
  LOBYTE(v17) = 3;
  if ( warningsini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_TIME_TO_REPORT_FPS_MS", 0x19u);
    LOBYTE(v17) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v17) = 5;
    v4 = INIReader::getFloat(&warningsini, &section, &key);
    v5 = section._Myres < 8;
    this->gpuWS.reportTimer = v4;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_TIME_TO_REPORT_CPU_MS", 0x19u);
    LOBYTE(v17) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v17) = 7;
    v6 = INIReader::getFloat(&warningsini, &section, &key);
    v5 = section._Myres < 8;
    this->cpuWS.reportTimer = v6;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_CPU_OCCUPANCY_PERCENT", 0x19u);
    LOBYTE(v17) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v17) = 9;
    v7 = INIReader::getFloat(&warningsini, &section, &key);
    v5 = section._Myres < 8;
    this->cpuWS.bound = v7;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_FPS", 7u);
    LOBYTE(v17) = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v17) = 11;
    v8 = INIReader::getFloat(&warningsini, &section, &key);
    v5 = section._Myres < 8;
    this->gpuWS.bound = v8;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CPU_AVERAGE_PERCENT_FLUCTUATION", 0x1Fu);
    LOBYTE(v17) = 12;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v17) = 13;
    v9 = INIReader::getFloat(&warningsini, &section, &key);
    v5 = section._Myres < 8;
    this->cpuWA.bound = v9;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FPS_AVERAGE_PERCENT_FLUCTUATION", 0x1Fu);
    LOBYTE(v17) = 14;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v17) = 15;
    v10 = INIReader::getFloat(&warningsini, &section, &key);
    v5 = section._Myres < 8;
    this->gpuWA.bound = v10;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v17) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  else
  {
    this->cpuWS.bound = 95.0;
    this->gpuWS.bound = 15.0;
  }
  std::vector<WarningReporter::WarningEvent>::resize(&this->overboundArray, 0x12Cu);
  std::vector<WarningReporter::WarningEvent>::resize(&this->overboundAverageArray, 0x12Cu);
  LOBYTE(v17) = 2;
  INIReaderDocuments::~INIReaderDocuments(&warningsini);
}
void WarningReporter::~WarningReporter(WarningReporter *this)
{
  std::vector<WarningReporter::WarningEvent> *v2; // esi
  std::vector<WarningReporter::WarningEvent> *v3; // esi

  v2 = &this->overboundAverageArray;
  this->__vftable = (WarningReporter_vtbl *)&WarningReporter::`vftable';
  if ( this->overboundAverageArray._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->overboundAverageArray);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = &this->overboundArray;
  if ( this->overboundArray._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->overboundArray);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->overboundArray._Mylast = 0;
    this->overboundArray._Myend = 0;
  }
  GameObject::~GameObject(this);
}
WarningReporter *WarningReporter::`scalar deleting destructor'(WarningReporter *this, unsigned int a2)
{
  WarningReporter::~WarningReporter(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void WarningReporter::checkAverage(WarningReporter *this, WarningReporter::WarningStatistic *wa, float valueNow, float deltaT)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  __m128i v7; // [esp+8h] [ebp-20h]

  v4 = wa->meanValue;
  if ( v4 == -1.0 )
  {
    wa->meanValue = valueNow;
    return;
  }
  v7 = _mm_loadu_si128((const __m128i *)wa);
  v5 = (float)((float)(valueNow - v4) * 0.2) + v4;
  if ( _mm_cvtsi128_si32(v7) )
  {
    if ( (float)(v5 - (float)((float)(*(float *)&v7.m128i_i32[1] * 0.0099999998) * v5)) <= valueNow )
      goto LABEL_4;
  }
  else if ( valueNow <= (float)((float)((float)(*(float *)&v7.m128i_i32[1] * 0.0099999998) * v5) + v5) )
  {
LABEL_4:
    if ( wa->encountered )
    {
      this->overboundAverageArray._Myfirst[this->currentIndexAverage].timestamp = wa->timestamp;
      this->overboundAverageArray._Myfirst[this->currentIndexAverage].duration = wa->duration;
      this->overboundAverageArray._Myfirst[this->currentIndexAverage].type = wa->type;
      this->currentIndexAverage = (this->currentIndexAverage + 1)
                                % (unsigned int)(this->overboundAverageArray._Mylast
                                               - this->overboundAverageArray._Myfirst);
      wa->timestamp = 0.0;
      wa->duration = 0.0;
      wa->encountered = 0;
    }
    wa->meanValue = v5;
    return;
  }
  if ( wa->timestamp == 0.0 )
    wa->timestamp = this->sim->game->gameTime.now;
  v6 = wa->duration + deltaT;
  wa->encountered = 1;
  wa->duration = v6;
}
void WarningReporter::checkProblems(WarningReporter *this, WarningReporter::WarningStatistic *ws, float valueNow, float deltaT)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool v7; // cc
  __m128i v8; // [esp+8h] [ebp-20h]

  v8 = _mm_loadu_si128((const __m128i *)ws);
  if ( _mm_cvtsi128_si32(v8) )
  {
    if ( *(float *)&v8.m128i_i32[1] <= valueNow )
      goto LABEL_3;
  }
  else if ( valueNow <= *(float *)&v8.m128i_i32[1] )
  {
LABEL_3:
    v4 = ws->timestamp;
    if ( v4 != 0.0 )
    {
      this->overboundArray._Myfirst[this->currentIndex].timestamp = v4;
      this->overboundArray._Myfirst[this->currentIndex].duration = ws->duration;
      this->overboundArray._Myfirst[this->currentIndex].type = ws->type;
      this->currentIndex = (this->currentIndex + 1)
                         % (unsigned int)(this->overboundArray._Mylast - this->overboundArray._Myfirst);
      ws->timestamp = 0.0;
    }
    ws->duration = 0.0;
    return;
  }
  if ( ws->timestamp == 0.0 )
    ws->timestamp = this->sim->game->gameTime.now;
  v5 = ws->duration;
  if ( v5 >= ws->reportTimer )
    ws->encountered = 1;
  v6 = (float)(deltaT * 1000.0) + v5;
  v7 = v6 <= ws->maxTimeOverbound;
  ws->duration = v6;
  if ( !v7 )
    ws->maxTimeOverbound = v6;
}
void WarningReporter::shutdown(WarningReporter *this)
{
  int v2; // eax
  WarningReporter::WarningEvent *v3; // ecx
  int v4; // eax
  WarningReporter::WarningEvent *v5; // ecx
  int v6; // edx
  WarningReporter::WarningEvent *v7; // ecx
  float v8; // eax
  float value; // xmm0_4
  unsigned int v10; // ebx
  int v11; // edi
  WarningReporter::WarningEvent *v12; // ecx
  WarningReporter::WarningEvent *v13; // eax
  WarningReporter::WarningEvent *v14; // eax
  float v15; // xmm0_4
  unsigned int v16; // ebx
  int v17; // edi
  WarningReporter::WarningEvent *v18; // ecx
  WarningReporter::WarningEvent *v19; // eax
  WarningReporter::WarningEvent *v20; // eax
  unsigned int v21; // ebx
  int v22; // edi
  WarningReporter::WarningEvent *v23; // ecx
  WarningReporter::WarningEvent *v24; // eax
  WarningReporter::WarningEvent *v25; // eax
  unsigned int v26; // ebx
  int v27; // edi
  WarningReporter::WarningEvent *v28; // ecx
  WarningReporter::WarningEvent *v29; // eax
  WarningReporter::WarningEvent *v30; // eax
  jsonwriter::Value v31; // [esp+4h] [ebp-FCh] BYREF
  jsonwriter::Object root; // [esp+38h] [ebp-C8h] BYREF
  jsonwriter::Object cpuObj; // [esp+48h] [ebp-B8h] BYREF
  jsonwriter::Object fpsObj; // [esp+58h] [ebp-A8h] BYREF
  jsonwriter::Array cpuSession; // [esp+68h] [ebp-98h] BYREF
  jsonwriter::Array fpsSession; // [esp+78h] [ebp-88h] BYREF
  jsonwriter::Array averageLowFPS; // [esp+88h] [ebp-78h] BYREF
  jsonwriter::Array averageHighCPU; // [esp+98h] [ebp-68h] BYREF
  std::wstring name; // [esp+A8h] [ebp-58h] BYREF
  jsonwriter::Object ev; // [esp+C0h] [ebp-40h] BYREF
  int v41; // [esp+D0h] [ebp-30h]
  unsigned int v42; // [esp+D4h] [ebp-2Ch]
  std::wstring documentPath; // [esp+D8h] [ebp-28h] BYREF
  int v44; // [esp+FCh] [ebp-4h]

  jsonwriter::Object::Object(&root);
  v44 = 0;
  jsonwriter::Array::Array(&fpsSession);
  LOBYTE(v44) = 1;
  jsonwriter::Array::Array(&cpuSession);
  LOBYTE(v44) = 2;
  jsonwriter::Array::Array(&averageHighCPU);
  LOBYTE(v44) = 3;
  jsonwriter::Array::Array(&averageLowFPS);
  LOBYTE(v44) = 4;
  jsonwriter::Object::Object(&fpsObj);
  LOBYTE(v44) = 5;
  jsonwriter::Object::Object(&cpuObj);
  v2 = this->currentIndex;
  v3 = this->overboundArray._Myfirst;
  v31.type = VT_BOOL;
  LOBYTE(v44) = 6;
  v3[v2].timestamp = this->gpuWS.timestamp;
  v4 = this->currentIndex;
  v5 = this->overboundArray._Myfirst;
  v31.valueStr._Myres = (unsigned int)L"encountered";
  v5[v4].duration = this->gpuWS.duration;
  this->overboundArray._Myfirst[this->currentIndex].type = eFPS;
  v6 = (this->currentIndex + 1) % (unsigned int)(this->overboundArray._Mylast - this->overboundArray._Myfirst);
  v7 = this->overboundArray._Myfirst;
  v8 = this->cpuWS.timestamp;
  this->currentIndex = v6;
  v7[v6].timestamp = v8;
  this->overboundArray._Myfirst[this->currentIndex].duration = this->cpuWS.duration;
  this->overboundArray._Myfirst[this->currentIndex].type = eCPU;
  if ( this->gpuWS.encountered )
  {
    v42 = 7;
    v41 = 0;
    LOWORD(ev.__vftable) = 0;
    std::wstring::assign((std::wstring *)&ev, (const wchar_t *)v31.valueStr._Myres, v31.type);
    LOBYTE(v44) = 7;
    jsonwriter::Value::Value(&v31, 1);
    jsonwriter::Object::Add(&fpsObj, (const std::wstring *)&ev, v31);
    LOBYTE(v44) = 6;
    if ( v42 >= 8 )
      operator delete(ev.__vftable);
    v42 = 7;
    v41 = 0;
    LOWORD(ev.__vftable) = 0;
    std::wstring::assign((std::wstring *)&ev, L"max_time_sec", 0xCu);
    value = this->gpuWS.maxTimeOverbound * 0.001;
    LOBYTE(v44) = 8;
    jsonwriter::Value::Value(&v31, value);
    jsonwriter::Object::Add(&fpsObj, (const std::wstring *)&ev, v31);
    LOBYTE(v44) = 6;
    if ( v42 >= 8 )
      operator delete(ev.__vftable);
    v10 = 0;
    if ( this->overboundArray._Mylast - this->overboundArray._Myfirst )
    {
      v11 = 0;
      do
      {
        v12 = this->overboundArray._Myfirst;
        if ( v12[v11].duration != 0.0 && v12[v11].type == eFPS )
        {
          jsonwriter::Object::Object(&ev);
          LOBYTE(v44) = 9;
          name._Myres = 7;
          name._Mysize = 0;
          name._Bx._Buf[0] = 0;
          std::wstring::assign(&name, L"timestamp_sec", 0xDu);
          v13 = this->overboundArray._Myfirst;
          LOBYTE(v44) = 10;
          jsonwriter::Value::Value(&v31, v13[v11].timestamp * 0.001);
          jsonwriter::Object::Add(&ev, &name, v31);
          LOBYTE(v44) = 9;
          if ( name._Myres >= 8 )
            operator delete(name._Bx._Ptr);
          name._Myres = 7;
          name._Mysize = 0;
          name._Bx._Buf[0] = 0;
          std::wstring::assign(&name, L"event_length_sec", 0x10u);
          v14 = this->overboundArray._Myfirst;
          LOBYTE(v44) = 11;
          jsonwriter::Value::Value(&v31, v14[v11].duration * 0.001);
          jsonwriter::Object::Add(&ev, &name, v31);
          LOBYTE(v44) = 9;
          if ( name._Myres >= 8 )
            operator delete(name._Bx._Ptr);
          jsonwriter::Array::Add(&fpsSession, &ev);
          LOBYTE(v44) = 6;
          jsonwriter::Object::~Object(&ev);
        }
        ++v10;
        ++v11;
      }
      while ( v10 < this->overboundArray._Mylast - this->overboundArray._Myfirst );
    }
  }
  else
  {
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, (const wchar_t *)v31.valueStr._Myres, v31.type);
    LOBYTE(v44) = 12;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&fpsObj, &name, v31);
    LOBYTE(v44) = 6;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"max_time_sec", 0xCu);
    LOBYTE(v44) = 13;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&fpsObj, &name, v31);
    LOBYTE(v44) = 6;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    jsonwriter::Object::Object(&ev);
    LOBYTE(v44) = 14;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"timestamp_sec", 0xDu);
    LOBYTE(v44) = 15;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&ev, &name, v31);
    LOBYTE(v44) = 14;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"event_length_sec", 0x10u);
    LOBYTE(v44) = 16;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&ev, &name, v31);
    LOBYTE(v44) = 14;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    jsonwriter::Array::Add(&fpsSession, &ev);
    LOBYTE(v44) = 6;
    jsonwriter::Object::~Object(&ev);
  }
  name._Myres = 7;
  name._Mysize = 0;
  v31.type = VT_BOOL;
  name._Bx._Buf[0] = 0;
  v31.valueStr._Myres = (unsigned int)L"encountered";
  if ( this->cpuWS.encountered )
  {
    std::wstring::assign(&name, (const wchar_t *)v31.valueStr._Myres, v31.type);
    LOBYTE(v44) = 17;
    jsonwriter::Value::Value(&v31, 1);
    jsonwriter::Object::Add(&cpuObj, &name, v31);
    LOBYTE(v44) = 6;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"max_time_sec", 0xCu);
    v15 = this->cpuWS.maxTimeOverbound * 0.001;
    LOBYTE(v44) = 18;
    jsonwriter::Value::Value(&v31, v15);
    jsonwriter::Object::Add(&cpuObj, &name, v31);
    LOBYTE(v44) = 6;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    v16 = 0;
    if ( this->overboundArray._Mylast - this->overboundArray._Myfirst )
    {
      v17 = 0;
      do
      {
        v18 = this->overboundArray._Myfirst;
        if ( v18[v17].duration != 0.0 && v18[v17].type == eCPU )
        {
          jsonwriter::Object::Object(&ev);
          LOBYTE(v44) = 19;
          name._Myres = 7;
          name._Mysize = 0;
          name._Bx._Buf[0] = 0;
          std::wstring::assign(&name, L"timestamp_sec", 0xDu);
          v19 = this->overboundArray._Myfirst;
          LOBYTE(v44) = 20;
          jsonwriter::Value::Value(&v31, v19[v17].timestamp * 0.001);
          jsonwriter::Object::Add(&ev, &name, v31);
          LOBYTE(v44) = 19;
          if ( name._Myres >= 8 )
            operator delete(name._Bx._Ptr);
          name._Myres = 7;
          name._Mysize = 0;
          name._Bx._Buf[0] = 0;
          std::wstring::assign(&name, L"event_length_sec", 0x10u);
          v20 = this->overboundArray._Myfirst;
          LOBYTE(v44) = 21;
          jsonwriter::Value::Value(&v31, v20[v17].duration * 0.001);
          jsonwriter::Object::Add(&ev, &name, v31);
          LOBYTE(v44) = 19;
          if ( name._Myres >= 8 )
            operator delete(name._Bx._Ptr);
          jsonwriter::Array::Add(&cpuSession, &ev);
          LOBYTE(v44) = 6;
          jsonwriter::Object::~Object(&ev);
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->overboundArray._Mylast - this->overboundArray._Myfirst );
    }
  }
  else
  {
    std::wstring::assign(&name, (const wchar_t *)v31.valueStr._Myres, v31.type);
    LOBYTE(v44) = 22;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&cpuObj, &name, v31);
    LOBYTE(v44) = 6;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"max_time_sec", 0xCu);
    LOBYTE(v44) = 23;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&cpuObj, &name, v31);
    LOBYTE(v44) = 6;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    jsonwriter::Object::Object(&ev);
    LOBYTE(v44) = 24;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"timestamp_sec", 0xDu);
    LOBYTE(v44) = 25;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&ev, &name, v31);
    LOBYTE(v44) = 24;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"event_length_sec", 0x10u);
    LOBYTE(v44) = 26;
    jsonwriter::Value::Value(&v31, 0);
    jsonwriter::Object::Add(&ev, &name, v31);
    LOBYTE(v44) = 24;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    jsonwriter::Array::Add(&cpuSession, &ev);
    LOBYTE(v44) = 6;
    jsonwriter::Object::~Object(&ev);
  }
  v21 = 0;
  if ( this->overboundAverageArray._Mylast - this->overboundAverageArray._Myfirst )
  {
    v22 = 0;
    do
    {
      v23 = this->overboundAverageArray._Myfirst;
      if ( v23[v22].duration != 0.0 && v23[v22].type == eCPU )
      {
        jsonwriter::Object::Object(&ev);
        LOBYTE(v44) = 27;
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        std::wstring::assign(&name, L"timestamp", 9u);
        v24 = this->overboundAverageArray._Myfirst;
        LOBYTE(v44) = 28;
        jsonwriter::Value::Value(&v31, v24[v22].timestamp);
        jsonwriter::Object::Add(&ev, &name, v31);
        LOBYTE(v44) = 27;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        std::wstring::assign(&name, L"event_length_sec", 0x10u);
        v25 = this->overboundAverageArray._Myfirst;
        LOBYTE(v44) = 29;
        jsonwriter::Value::Value(&v31, v25[v22].duration * 0.001);
        jsonwriter::Object::Add(&ev, &name, v31);
        LOBYTE(v44) = 27;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        jsonwriter::Array::Add(&averageHighCPU, &ev);
        LOBYTE(v44) = 6;
        jsonwriter::Object::~Object(&ev);
      }
      ++v21;
      ++v22;
    }
    while ( v21 < this->overboundAverageArray._Mylast - this->overboundAverageArray._Myfirst );
  }
  v26 = 0;
  if ( this->overboundAverageArray._Mylast - this->overboundAverageArray._Myfirst )
  {
    v27 = 0;
    do
    {
      v28 = this->overboundAverageArray._Myfirst;
      if ( v28[v27].duration != 0.0 && v28[v27].type == eFPS )
      {
        jsonwriter::Object::Object(&ev);
        LOBYTE(v44) = 30;
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        std::wstring::assign(&name, L"timestamp", 9u);
        v29 = this->overboundAverageArray._Myfirst;
        LOBYTE(v44) = 31;
        jsonwriter::Value::Value(&v31, v29[v27].timestamp);
        jsonwriter::Object::Add(&ev, &name, v31);
        LOBYTE(v44) = 30;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        std::wstring::assign(&name, L"event_length_sec", 0x10u);
        v30 = this->overboundAverageArray._Myfirst;
        LOBYTE(v44) = 32;
        jsonwriter::Value::Value(&v31, v30[v27].duration * 0.001);
        jsonwriter::Object::Add(&ev, &name, v31);
        LOBYTE(v44) = 30;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        jsonwriter::Array::Add(&averageLowFPS, &ev);
        LOBYTE(v44) = 6;
        jsonwriter::Object::~Object(&ev);
      }
      ++v26;
      ++v27;
    }
    while ( v26 < this->overboundAverageArray._Mylast - this->overboundAverageArray._Myfirst );
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"cpu_occupancy", 0xDu);
  LOBYTE(v44) = 33;
  jsonwriter::Object::Add(&root, &name, &cpuObj);
  LOBYTE(v44) = 6;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"low_fps", 7u);
  LOBYTE(v44) = 34;
  jsonwriter::Object::Add(&root, &name, &fpsObj);
  LOBYTE(v44) = 6;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"high_cpu_occupancy_events", 0x19u);
  LOBYTE(v44) = 35;
  jsonwriter::Object::Add(&root, &name, &cpuSession);
  LOBYTE(v44) = 6;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"low_fps_events", 0xEu);
  LOBYTE(v44) = 36;
  jsonwriter::Object::Add(&root, &name, &fpsSession);
  LOBYTE(v44) = 6;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"average_low_fps_events", 0x16u);
  LOBYTE(v44) = 37;
  jsonwriter::Object::Add(&root, &name, &averageLowFPS);
  LOBYTE(v44) = 6;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"average_high_cpu_events", 0x17u);
  LOBYTE(v44) = 38;
  jsonwriter::Object::Add(&root, &name, &averageHighCPU);
  LOBYTE(v44) = 6;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  Path::getDocumentPath(&documentPath);
  LOBYTE(v44) = 39;
  std::wstring::append(&documentPath, L"\\Assetto Corsa\\out\\warnings.json", 0x20u);
  jsonwriter::FileWriter::WriteFile(&documentPath, &root);
  if ( documentPath._Myres >= 8 )
    operator delete(documentPath._Bx._Ptr);
  documentPath._Myres = 7;
  documentPath._Mysize = 0;
  documentPath._Bx._Buf[0] = 0;
  LOBYTE(v44) = 5;
  jsonwriter::Object::~Object(&cpuObj);
  LOBYTE(v44) = 4;
  jsonwriter::Object::~Object(&fpsObj);
  LOBYTE(v44) = 3;
  jsonwriter::Array::~Array(&averageLowFPS);
  LOBYTE(v44) = 2;
  jsonwriter::Array::~Array(&averageHighCPU);
  LOBYTE(v44) = 1;
  jsonwriter::Array::~Array(&cpuSession);
  LOBYTE(v44) = 0;
  jsonwriter::Array::~Array(&fpsSession);
  v44 = -1;
  jsonwriter::Object::~Object(&root);
}
void WarningReporter::update(WarningReporter *this, float deltaT)
{
  if ( this->loadingTime > 60.0 )
  {
    WarningReporter::checkProblems(this, &this->gpuWS, this->sim->game->gameTime.fps, deltaT);
    WarningReporter::checkProblems(this, &this->cpuWS, (float)this->sim->physicsAvatar->occupancy, deltaT);
    WarningReporter::checkAverage(this, &this->gpuWA, this->sim->game->gameTime.fps, deltaT);
    WarningReporter::checkAverage(this, &this->cpuWA, (float)this->sim->physicsAvatar->occupancy, deltaT);
  }
  this->loadingTime = deltaT + this->loadingTime;
}
