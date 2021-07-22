#include "dynamictrackmanager.h"
void DynamicTrackManager::DynamicTrackManager(DynamicTrackManager *this, Sim *aSim, const std::wstring *trackDataFolder)
{
  unsigned int v4; // ebx
  Event<OnReplayStatusChanged> *v5; // ecx
  Sim *v6; // ecx
  Console *v7; // eax
  const std::wstring *v8; // eax
  float i; // edi
  bool v10; // bl
  std::wostream *v11; // eax
  const std::wstring *v12; // eax
  const std::wstring *v13; // eax
  const std::wstring *v14; // eax
  const std::wstring *v15; // eax
  Sim *v16; // eax
  Node *v17; // ecx
  Node_vtbl *v18; // eax
  int v19; // eax
  Mesh *v20; // esi
  Material *v21; // ecx
  MaterialVar *v22; // esi
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  bool v25; // cf
  int v26; // eax
  bool v27; // zf
  bool v28; // bl
  double v29; // st7
  double v30; // st7
  std::wstring v31; // [esp-34h] [ebp-25Ch] BYREF
  _BYTE v32[28]; // [esp-1Ch] [ebp-244h] BYREF
  float multiplier; // [esp+0h] [ebp-228h]
  unsigned int v34; // [esp+24h] [ebp-204h]
  _BYTE *v35; // [esp+28h] [ebp-200h]
  std::wstring *v36; // [esp+2Ch] [ebp-1FCh]
  GrooveMesh g; // [esp+30h] [ebp-1F8h] BYREF
  DynamicTrackManager *v38; // [esp+4Ch] [ebp-1DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v39; // [esp+50h] [ebp-1D8h] BYREF
  std::wstring vname; // [esp+100h] [ebp-128h] BYREF
  std::wstring section; // [esp+118h] [ebp-110h] BYREF
  std::wstring name; // [esp+130h] [ebp-F8h] BYREF
  std::wstring key; // [esp+148h] [ebp-E0h] BYREF
  std::wstring result; // [esp+160h] [ebp-C8h] BYREF
  std::wstring v45; // [esp+178h] [ebp-B0h] BYREF
  INIReader ini; // [esp+190h] [ebp-98h] BYREF
  INIReaderDocuments raceINI; // [esp+1D4h] [ebp-54h] BYREF
  int v48; // [esp+224h] [ebp-4h]

  v4 = 0;
  v34 = 0;
  v38 = this;
  multiplier = *(float *)&aSim->game;
  *(_DWORD *)&v32[24] = 7;
  *(_DWORD *)&v32[20] = 0;
  *(_WORD *)&v32[4] = 0;
  std::wstring::assign((std::wstring *)&v32[4], L"TRACK_DIRT_MANAGER", 0x12u);
  GameObject::GameObject(this, *(std::wstring *)&v32[4], (Game *)LODWORD(multiplier));
  this->__vftable = (DynamicTrackManager_vtbl *)&DynamicTrackManager::`vftable';
  this->sim = aSim;
  v48 = 0;
  this->grooves._Myfirst = 0;
  this->grooves._Mylast = 0;
  this->grooves._Myend = 0;
  LODWORD(multiplier) = this;
  this->startingLapsCount = 0.0;
  this->alwaysHide = 0;
  this->resetToTarget = 0;
  *(_DWORD *)&v32[4] = &std::_Func_impl<std::_Callable_obj<_lambda_80dca9b889e744383dc61558ea308d2b_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v32[8] = this;
  *(_DWORD *)&v32[20] = &v32[4];
  v5 = &this->sim->evOnReplayStatusChanged;
  LOBYTE(v48) = 1;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v5,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v32[4],
    (void *)LODWORD(multiplier));
  multiplier = 1.0;
  *(_DWORD *)&v32[24] = 0;
  v35 = v32;
  *(_DWORD *)v32 = &std::_Func_impl<std::_Callable_obj<_lambda_bf887b3ce1d0bc636711e9e5dd68400a_,0>,std::allocator<std::_Func_class<void,SVar *,float>>,void,SVar *,float>::`vftable';
  *(_DWORD *)&v32[4] = this;
  *(_DWORD *)&v32[16] = v32;
  LOBYTE(v48) = 4;
  v36 = &v31;
  v31._Myres = 7;
  v31._Mysize = 0;
  v31._Bx._Buf[0] = 0;
  std::wstring::assign(&v31, L"hideGroove", 0xAu);
  v6 = this->sim;
  LOBYTE(v48) = 5;
  v7 = Sim::getConsole(v6);
  LOBYTE(v48) = 1;
  Console::addVarLambda(v7, v31, *(std::function<void __cdecl(SVar *,float)> *)v32, v32[24], multiplier);
  v8 = std::operator+<wchar_t>(&result, trackDataFolder, L"/data/groove.ini");
  LOBYTE(v48) = 6;
  INIReader::INIReader(&ini, v8);
  LOBYTE(v48) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    for ( i = 0.0; ; ++LODWORD(i) )
    {
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"GROOVES_NUMBER", 0xEu);
      LOBYTE(v48) = 9;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"HEADER", 6u);
      LOBYTE(v48) = 10;
      v10 = SLODWORD(i) < INIReader::getInt(&ini, &section, &name);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v48) = 8;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      if ( !v10 )
        break;
      *(_DWORD *)v39.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v39.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v39.gap68);
      v34 |= 2u;
      LOBYTE(v48) = 11;
      std::wiostream::basic_iostream<wchar_t>(&v39, &v39.gap10[8], 0);
      v48 = 12;
      *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(DynamicTrackManager **)((char *)&v38 + *(_DWORD *)(*(_DWORD *)v39.gap0 + 4)) = (DynamicTrackManager *)(*(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104);
      std::wstreambuf::wstreambuf(&v39.gap10[8]);
      *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v39.gap10[64] = 0;
      *(_DWORD *)&v39.gap10[68] = 0;
      multiplier = i;
      LOBYTE(v48) = 14;
      v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v39.gap10, "GROOVE_");
      std::wostream::operator<<(v11, LODWORD(multiplier));
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"MIN", 3u);
      LOBYTE(v48) = 15;
      v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &vname);
      LOBYTE(v48) = 16;
      g.minAlpha = INIReader::getFloat(&ini, v12, &section);
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      vname._Myres = 7;
      vname._Mysize = 0;
      vname._Bx._Buf[0] = 0;
      LOBYTE(v48) = 14;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      g.currentAlpha = g.minAlpha;
      g.targetAlpha = g.minAlpha;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"MAX", 3u);
      LOBYTE(v48) = 17;
      v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &vname);
      LOBYTE(v48) = 18;
      g.maxAlpha = INIReader::getFloat(&ini, v13, &section);
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      vname._Myres = 7;
      vname._Mysize = 0;
      vname._Bx._Buf[0] = 0;
      LOBYTE(v48) = 14;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"MULT", 4u);
      LOBYTE(v48) = 19;
      v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &vname);
      LOBYTE(v48) = 20;
      g.mult = INIReader::getFloat(&ini, v14, &section);
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      vname._Myres = 7;
      vname._Mysize = 0;
      vname._Bx._Buf[0] = 0;
      LOBYTE(v48) = 14;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"NAME", 4u);
      LOBYTE(v48) = 21;
      v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &key);
      LOBYTE(v48) = 22;
      INIReader::getString(&ini, &name, v15, &section);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v48) = 25;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Bx._Buf[0] = 0;
      v16 = this->sim;
      multiplier = 0.0;
      *(_DWORD *)&v32[24] = &Mesh `RTTI Type Descriptor';
      *(_DWORD *)&v32[20] = &Node `RTTI Type Descriptor';
      v17 = v16->trackNode;
      *(_DWORD *)&v32[16] = 0;
      *(_DWORD *)&v32[12] = 1;
      *(_DWORD *)&v32[8] = &name;
      v18 = v17->__vftable;
      section._Mysize = 0;
      v19 = (int)v18->findChildByName(v17, &name, 1);
      v20 = (Mesh *)__RTDynamicCast(
                      v19,
                      *(_DWORD *)&v32[16],
                      *(_DWORD *)&v32[20],
                      *(_DWORD *)&v32[24],
                      LODWORD(multiplier));
      g.mesh = v20;
      if ( v20 )
      {
        vname._Myres = 7;
        vname._Mysize = 0;
        vname._Bx._Buf[0] = 0;
        std::wstring::assign(&vname, L"alpha", 5u);
        v21 = v20->material._Ptr;
        LOBYTE(v48) = 26;
        v22 = Material::getVar(v21, &vname);
        g.var = v22;
        LOBYTE(v48) = 25;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        if ( v22 )
        {
          v22->fValue = g.minAlpha;
          MaterialVar::set(v22);
        }
      }
      else
      {
        g.var = 0;
        if ( INIReader::crashAtError )
        {
          v23 = std::operator+<wchar_t>(&v45, L"ERROR: Groove object: ", &name);
          LOBYTE(v48) = 27;
          v24 = std::operator+<wchar_t>(&vname, v23, L" not found");
          v25 = v24->_Myres < 8;
          LOBYTE(v48) = 28;
          if ( !v25 )
            v24 = (std::wstring *)v24->_Bx._Ptr;
          _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v24->_Bx._Buf);
          ksGenerateCrash();
          if ( vname._Myres >= 8 )
            operator delete(vname._Bx._Ptr);
          vname._Myres = 7;
          vname._Mysize = 0;
          vname._Bx._Buf[0] = 0;
          LOBYTE(v48) = 25;
          if ( v45._Myres >= 8 )
            operator delete(v45._Bx._Ptr);
        }
      }
      std::vector<GrooveMesh>::push_back((std::vector<CarCollisionBox> *)&this->grooves, (const CarCollisionBox *)&g);
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Bx._Buf[0] = 0;
      name._Mysize = 0;
      LOBYTE(v48) = 8;
      *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(DynamicTrackManager **)((char *)&v38 + *(_DWORD *)(*(_DWORD *)v39.gap0 + 4)) = (DynamicTrackManager *)(*(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104);
      *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v39.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v39.gap10[8]) )
          std::wstreambuf::epptr(&v39.gap10[8]);
        else
          std::wstreambuf::egptr(&v39.gap10[8]);
        std::wstreambuf::eback(&v39.gap10[8]);
        v26 = std::wstreambuf::eback(&v39.gap10[8]);
        operator delete(v26);
      }
      std::wstreambuf::setg(&v39.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v39.gap10[8], 0, 0);
      *(_DWORD *)&v39.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v39.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v39.gap68);
    }
    v4 = v34;
  }
  else
  {
    this->isActive = 0;
  }
  multiplier = 0.0;
  *(_DWORD *)&v32[24] = 7;
  *(_DWORD *)&v32[20] = 0;
  *(_WORD *)&v32[4] = 0;
  std::wstring::assign((std::wstring *)&v32[4], L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&raceINI, v4, *(std::wstring *)&v32[4], SLOBYTE(multiplier));
  v27 = !raceINI.ready;
  LOBYTE(v48) = 29;
  this->maxNumberOfLaps = 0.0;
  v28 = 0;
  if ( !v27 )
  {
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    std::wstring::assign(&vname, L"GROOVE", 6u);
    LOBYTE(v48) = 30;
    v34 = v4 | 1;
    if ( INIReader::hasSection(&raceINI, &vname) )
      v28 = 1;
  }
  v48 = 29;
  if ( (v34 & 1) != 0 && vname._Myres >= 8 )
    operator delete(vname._Bx._Ptr);
  if ( v28 )
  {
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    std::wstring::assign(&vname, L"MAX_LAPS", 8u);
    LOBYTE(v48) = 31;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GROOVE", 6u);
    LOBYTE(v48) = 32;
    v29 = INIReader::getFloat(&raceINI, &section, &vname);
    v25 = section._Myres < 8;
    this->maxNumberOfLaps = v29;
    if ( !v25 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v48) = 29;
    if ( vname._Myres >= 8 )
      operator delete(vname._Bx._Ptr);
    std::wstring::wstring(&key, L"STARTING_LAPS");
    LOBYTE(v48) = 33;
    std::wstring::wstring(&vname, L"GROOVE");
    LOBYTE(v48) = 34;
    v30 = INIReader::getFloat(&raceINI, &vname, &key);
    v25 = vname._Myres < 8;
    this->startingLapsCount = v30;
    if ( !v25 )
      operator delete(vname._Bx._Ptr);
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( this->maxNumberOfLaps == 0.0 )
    this->maxNumberOfLaps = 100.0;
  LOBYTE(v48) = 8;
  INIReaderDocuments::~INIReaderDocuments(&raceINI);
  LOBYTE(v48) = 1;
  INIReader::~INIReader(&ini);
}
DynamicTrackManager *DynamicTrackManager::`scalar deleting destructor'(DynamicTrackManager *this, unsigned int a2)
{
  this->__vftable = (DynamicTrackManager_vtbl *)&DynamicTrackManager::`vftable';
  if ( this->grooves._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->grooves);
    operator delete(this->grooves._Myfirst);
    this->grooves._Myfirst = 0;
    this->grooves._Mylast = 0;
    this->grooves._Myend = 0;
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DynamicTrackManager::setGrooveMeshVisibility(DynamicTrackManager *this, bool visible)
{
  GrooveMesh *v3; // edx
  GrooveMesh *i; // eax
  Mesh *v5; // esi
  bool v6; // cl

  v3 = this->grooves._Mylast;
  for ( i = this->grooves._Myfirst; i != v3; ++i )
  {
    v5 = i->mesh;
    if ( v5 )
    {
      v6 = visible && !this->alwaysHide;
      v5->isActive = v6;
    }
  }
}
void DynamicTrackManager::update(DynamicTrackManager *this, float dt)
{
  Sim *v3; // ecx
  Track *v4; // eax
  unsigned int v5; // edi
  float v6; // xmm1_4
  CarAvatar *v7; // eax
  unsigned int v8; // ebp
  int v9; // edi
  GrooveMesh *v10; // eax
  GrooveMesh *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  GrooveMesh *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  GrooveMesh *v19; // eax
  MaterialVar *v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm0_4
  ShaderVariable *v23; // edx
  float *v24; // eax
  float v25; // xmm1_4
  unsigned int v26; // ebx
  int v27; // edi
  GrooveMesh *v28; // eax
  MaterialVar *v29; // ecx
  float v30; // [esp+10h] [ebp-4h]
  float dta; // [esp+18h] [ebp+4h]

  v3 = this->sim;
  v4 = v3->physicsAvatar->engine.track;
  if ( v4->dynamicTrack.enabled || v4->dynamicTrack.isExternal )
  {
    v25 = (float)(v4->dynamicGripLevel - 0.89999998) * 10.0;
    dta = v25;
    if ( v25 <= 1.0 )
    {
      if ( v25 < 0.0 )
      {
        v25 = 0.0;
        dta = 0.0;
      }
    }
    else
    {
      v25 = FLOAT_1_0;
      dta = FLOAT_1_0;
    }
    v26 = 0;
    if ( this->grooves._Mylast - this->grooves._Myfirst )
    {
      v27 = 0;
      do
      {
        v28 = this->grooves._Myfirst;
        v29 = v28[v27].var;
        if ( v29 )
        {
          v29->fValue = (float)((float)(v28[v27].maxAlpha - v28[v27].minAlpha) * v25) + v28[v27].minAlpha;
          MaterialVar::set(v29);
        }
        ++v26;
        v25 = dta;
        ++v27;
      }
      while ( v26 < this->grooves._Mylast - this->grooves._Myfirst );
    }
  }
  else
  {
    v5 = 0;
    v6 = this->startingLapsCount;
    v30 = v6;
    if ( v3->cars._Mylast - v3->cars._Myfirst )
    {
      do
      {
        v7 = Sim::getCar(this->sim, v5++);
        v6 = (float)v7->physicsState.lapCount + v30;
        v30 = v6;
      }
      while ( v5 < this->sim->cars._Mylast - this->sim->cars._Myfirst );
    }
    v8 = 0;
    if ( this->grooves._Mylast - this->grooves._Myfirst )
    {
      v9 = 0;
      do
      {
        v10 = this->grooves._Myfirst;
        v10[v9].targetAlpha = (float)((float)(v6 / (float)(v10[v9].mult * this->maxNumberOfLaps))
                                    * (float)(v10[v9].maxAlpha - v10[v9].minAlpha))
                            + v10[v9].minAlpha;
        v11 = this->grooves._Myfirst;
        v12 = v11[v9].targetAlpha;
        v13 = v11[v9].maxAlpha;
        if ( v12 <= v13 )
        {
          if ( v11[v9].minAlpha <= v12 )
            v13 = v11[v9].targetAlpha;
          else
            v13 = v11[v9].minAlpha;
        }
        v11[v9].targetAlpha = v13;
        v14 = this->grooves._Myfirst;
        v15 = v14[v9].targetAlpha;
        v16 = v14[v9].currentAlpha;
        v17 = (float)(v15 - v16) * dt;
        if ( v17 <= 0.0 || this->resetToTarget )
        {
          v14[v9].currentAlpha = v15;
          this->resetToTarget = 0;
        }
        else
        {
          v18 = v16 + v17;
          if ( v15 <= v18 )
            v14[v9].currentAlpha = v15;
          else
            v14[v9].currentAlpha = v18;
        }
        v19 = this->grooves._Myfirst;
        v20 = v19[v9].var;
        if ( v20 )
        {
          v21 = v19[v9].currentAlpha;
          v22 = v19[v9].maxAlpha;
          if ( v21 <= v22 )
          {
            if ( v19[v9].minAlpha <= v21 )
              v22 = v19[v9].currentAlpha;
            else
              v22 = v19[v9].minAlpha;
          }
          v23 = v20->var;
          v20->fValue = v22;
          switch ( v23->type )
          {
            case 0:
              ShaderVariable::set(v23, &v20->fValue);
              break;
            case 1:
              v24 = &v20->fValue2.x;
              goto LABEL_28;
            case 2:
              v24 = &v20->fValue3.x;
              goto LABEL_28;
            case 3:
              v24 = &v20->fValue4.x;
              goto LABEL_28;
            case 4:
              v24 = &v20->mValue.M11;
LABEL_28:
              ShaderVariable::set(v23, v24);
              break;
            default:
              break;
          }
        }
        ++v8;
        v6 = v30;
        ++v9;
      }
      while ( v8 < this->grooves._Mylast - this->grooves._Myfirst );
    }
  }
}
