#include "visualdamagemanager.h"
void VisualDamageManager::VisualDamageManager(VisualDamageManager *this, CarAvatar *car)
{
  CarAvatar *v3; // esi
  std::vector<VisualDamageManager::GlassBreakablePart> *v4; // ebp
  Event<OnReplayStatusChanged> *v5; // ecx
  Event<bool> *v6; // ecx
  double v7; // st7
  bool v8; // cf
  std::wstring *v9; // eax
  bool v10; // bl
  int v11; // eax
  float v12; // ebx
  int v13; // edi
  std::wostream *v14; // eax
  const std::wstring *v15; // eax
  bool v16; // bl
  const std::wstring *v17; // eax
  Node *v18; // ecx
  Node_vtbl *v19; // eax
  const std::wstring *v20; // eax
  const std::wstring *v21; // eax
  const std::wstring *v22; // eax
  const std::wstring *v23; // eax
  float v24; // xmm1_4
  const std::wstring *v25; // eax
  const std::wstring *v26; // eax
  float v27; // xmm1_4
  const std::wstring *v28; // esi
  const std::wstring *v29; // edi
  double v30; // st7
  const std::wstring *v31; // eax
  const std::wstring *v32; // eax
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Mesh *> > > v33; // eax
  Node **v34; // esi
  int v35; // ebp
  unsigned int v36; // ebx
  Node *v37; // edi
  __m128i v38; // xmm0
  __m128i v39; // xmm0
  __m128i v40; // xmm0
  int v41; // edi
  VisualDamageManager::GlassBreakablePart *v42; // esi
  VisualDamageManager::GlassBreakablePart *v43; // esi
  int v44; // ecx
  int v45; // ecx
  int v46; // ebx
  int v47; // edi
  std::wostream *v48; // eax
  std::wostream *v49; // eax
  std::wstring *v50; // eax
  Node *v51; // ecx
  Node *v52; // esi
  std::wstring *v53; // eax
  std::wostream *v54; // eax
  std::wostream *v55; // eax
  std::wstring *v56; // eax
  unsigned int v57; // edi
  std::vector<VisualDamageManager::GlassBreakablePart> *v58; // ecx
  Material *v59; // eax
  std::allocator<wchar_t> *v60; // eax
  Material *v61; // esi
  MaterialVar *v62; // eax
  MaterialVar *v63; // esi
  VisualDamageManager::GlassBreakablePart *v64; // eax
  VisualDamageManager::GlassBreakablePart *v65; // eax
  std::vector<TyreCompoundDef> *v66; // esi
  std::shared_ptr<Material> **v67; // eax
  int v68; // ecx
  VisualDamageManager::{ctor}::__l60::<lambda_e3ff8306fac25f806bae74fad5e2fa7b> *v69; // eax
  Console *v70; // eax
  std::wstring v71; // [esp-8h] [ebp-464h] BYREF
  char v72[28]; // [esp+10h] [ebp-44Ch] BYREF
  float lvl; // [esp+2Ch] [ebp-430h]
  unsigned int _Pos; // [esp+54h] [ebp-408h]
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Mesh *> > > _S21; // [esp+58h] [ebp-404h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Mesh *> > > _S20; // [esp+5Ch] [ebp-400h] BYREF
  int v77; // [esp+60h] [ebp-3FCh]
  CarAvatar *v78; // [esp+64h] [ebp-3F8h]
  std::shared_ptr<Material> sharedMaterial; // [esp+68h] [ebp-3F4h] BYREF
  std::vector<VisualDamageManager::GlassBreakablePart> *v80; // [esp+70h] [ebp-3ECh]
  std::vector<Node *> nodes; // [esp+74h] [ebp-3E8h] BYREF
  CarAudioFMOD *_This; // [esp+80h] [ebp-3DCh]
  int v83; // [esp+84h] [ebp-3D8h] BYREF
  float static_damage_angle; // [esp+88h] [ebp-3D4h]
  vec3f static_damage_axis; // [esp+8Ch] [ebp-3D0h] BYREF
  Mesh **v86; // [esp+98h] [ebp-3C4h]
  float v87; // [esp+9Ch] [ebp-3C0h]
  VisualDamageManager::OscillationAngle oscillationAngle; // [esp+A0h] [ebp-3BCh]
  float fullspeed; // [esp+A8h] [ebp-3B4h]
  VisualDamageManager *v90; // [esp+ACh] [ebp-3B0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v91; // [esp+B0h] [ebp-3ACh] BYREF
  VisualDamageManager::BreakablePart _Val; // [esp+160h] [ebp-2FCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v93; // [esp+1F0h] [ebp-26Ch] BYREF
  std::wstring key; // [esp+2A0h] [ebp-1BCh] BYREF
  std::wstring v95; // [esp+2B8h] [ebp-1A4h] BYREF
  std::wstring v96; // [esp+2D0h] [ebp-18Ch] BYREF
  std::wstring name; // [esp+2E8h] [ebp-174h] BYREF
  std::wstring vname; // [esp+300h] [ebp-15Ch] BYREF
  vec3f allowedG; // [esp+318h] [ebp-144h] BYREF
  int v100; // [esp+328h] [ebp-134h]
  unsigned int v101; // [esp+32Ch] [ebp-130h]
  vec3f oscillationAxis; // [esp+330h] [ebp-12Ch] BYREF
  int v103; // [esp+340h] [ebp-11Ch]
  unsigned int v104; // [esp+344h] [ebp-118h]
  Texture tex; // [esp+348h] [ebp-114h] BYREF
  std::wstring v106; // [esp+364h] [ebp-F8h] BYREF
  INIReader ini; // [esp+37Ch] [ebp-E0h] BYREF
  std::wstring zonestring; // [esp+3C0h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+3D8h] [ebp-84h] BYREF
  std::wstring filename; // [esp+3F0h] [ebp-6Ch] BYREF
  INIReader acINI; // [esp+408h] [ebp-54h] BYREF
  int v112; // [esp+458h] [ebp-4h]

  _This = (CarAudioFMOD *)this;
  v3 = car;
  v77 = 0;
  v90 = this;
  v78 = car;
  lvl = *(float *)&car->game;
  *(_DWORD *)&v72[24] = 7;
  *(_DWORD *)&v72[20] = 0;
  *(_WORD *)&v72[4] = 0;
  std::wstring::assign((std::wstring *)&v72[4], L"VISUAL_DAMAGE", 0xDu);
  GameObject::GameObject(this, *(std::wstring *)&v72[4], (Game *)LODWORD(lvl));
  this->__vftable = (VisualDamageManager_vtbl *)&VisualDamageManager::`vftable';
  v112 = 0;
  this->breakableParts._Myfirst = 0;
  this->breakableParts._Mylast = 0;
  this->breakableParts._Myend = 0;
  this->scrathableParts._Myfirst = 0;
  this->scrathableParts._Mylast = 0;
  this->scrathableParts._Myend = 0;
  v4 = &this->glassBreakableParts;
  this->glassBreakableParts._Myfirst = 0;
  v80 = &this->glassBreakableParts;
  this->glassBreakableParts._Mylast = 0;
  this->glassBreakableParts._Myend = 0;
  LODWORD(lvl) = this;
  this->car = car;
  this->isDebugMode = 0;
  this->oscillationEnabled = 1;
  this->lastDamageMagnitude = 0.0;
  this->glassDamageThreshold = 0.64999998;
  *(_DWORD *)&v72[4] = &std::_Func_impl<std::_Callable_obj<_lambda_bbbceb35afd77094959811095fb67b0c_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v72[8] = this;
  *(_DWORD *)&v72[20] = &v72[4];
  v5 = &car->sim->evOnReplayStatusChanged;
  LOBYTE(v112) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v5,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v72[4],
    (void *)LODWORD(lvl));
  LODWORD(lvl) = this;
  *(_DWORD *)&v72[4] = &std::_Func_impl<std::_Callable_obj<_lambda_ee97dcae96e2f38d91e7cfb8a2fef3a7_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v72[8] = this;
  *(_DWORD *)&v72[20] = &v72[4];
  v6 = &car->sim->evOnPauseModeChanged;
  LOBYTE(v112) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v6,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v72[4],
    this);
  LODWORD(lvl) = 5;
  this->localDebugZones[0] = 0.0;
  this->localDebugZones[1] = 0.0;
  this->localDebugZones[2] = 0.0;
  this->localDebugZones[3] = 0.0;
  this->localDebugZones[4] = 0.0;
  std::vector<VisualDamageManager::GlassBreakablePart>::resize(&this->glassBreakableParts, LODWORD(lvl));
  v101 = 7;
  v100 = 0;
  LOWORD(allowedG.x) = 0;
  std::wstring::assign((std::wstring *)&allowedG, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v112) = 6;
  INIReader::INIReader(&acINI, (const std::wstring *)&allowedG);
  LOBYTE(v112) = 8;
  if ( v101 >= 8 )
    operator delete(LODWORD(allowedG.x));
  v101 = 7;
  v100 = 0;
  LOWORD(allowedG.x) = 0;
  if ( acINI.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GLASS_THRESHOLD", 0xFu);
    LOBYTE(v112) = 9;
    v104 = 7;
    v103 = 0;
    LOWORD(oscillationAxis.x) = 0;
    std::wstring::assign((std::wstring *)&oscillationAxis, L"DAMAGE", 6u);
    LOBYTE(v112) = 10;
    v7 = INIReader::getFloat(&acINI, (const std::wstring *)&oscillationAxis, &key);
    v8 = v104 < 8;
    this->glassDamageThreshold = v7;
    if ( !v8 )
      operator delete(LODWORD(oscillationAxis.x));
    v104 = 7;
    v103 = 0;
    LOWORD(oscillationAxis.x) = 0;
    LOBYTE(v112) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v9 = std::operator+<wchar_t>(&result, L"content/cars/", &car->unixName);
  LOBYTE(v112) = 11;
  std::operator+<wchar_t>(&filename, v9, L"/data/damage.ini");
  LOBYTE(v112) = 13;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  CarAvatar::openINI(car, &ini, &filename);
  LOBYTE(v112) = 14;
  if ( !ini.ready )
    goto LABEL_96;
  damageEnabled = 1;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"OSCILLATIONS", 0xCu);
  LOBYTE(v112) = 15;
  v10 = INIReader::hasSection(&ini, &key);
  LOBYTE(v112) = 14;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v10 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ENABLED", 7u);
    LOBYTE(v112) = 16;
    v101 = 7;
    v100 = 0;
    LOWORD(allowedG.x) = 0;
    std::wstring::assign((std::wstring *)&allowedG, L"OSCILLATIONS", 0xCu);
    LOBYTE(v112) = 17;
    v11 = INIReader::getInt(&ini, (const std::wstring *)&allowedG, &key);
    v8 = v101 < 8;
    this->oscillationEnabled = v11 > 0;
    if ( !v8 )
      operator delete(LODWORD(allowedG.x));
    v101 = 7;
    v100 = 0;
    LOWORD(allowedG.x) = 0;
    LOBYTE(v112) = 14;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  VisualDamageManager::initScratchableParts(this, &ini);
  v12 = 0.0;
  key._Myres = 7;
  _Pos = 0;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"INITIAL_LEVEL", 0xDu);
  LOBYTE(v112) = 18;
  v101 = 7;
  v100 = 0;
  LOWORD(allowedG.x) = 0;
  std::wstring::assign((std::wstring *)&allowedG, L"DAMAGE", 6u);
  LOBYTE(v112) = 19;
  *(float *)&_S21._Ptr = INIReader::getFloat(&ini, (const std::wstring *)&allowedG, &key);
  if ( v101 >= 8 )
    operator delete(LODWORD(allowedG.x));
  v101 = 7;
  v100 = 0;
  LOWORD(allowedG.x) = 0;
  LOBYTE(v112) = 14;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  CarAvatar::setDamageLevel(car, *(float *)&_S21._Ptr);
  while ( 1 )
  {
    *(_DWORD *)v91.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v91.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v91.gap68);
    v13 = v77 | 1;
    LOBYTE(v112) = 20;
    v77 |= 1u;
    std::wiostream::basic_iostream<wchar_t>(&v91, &v91.gap10[8], 0);
    v112 = 21;
    *(_DWORD *)&v91.gap0[*(_DWORD *)(*(_DWORD *)v91.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(VisualDamageManager **)((char *)&v90 + *(_DWORD *)(*(_DWORD *)v91.gap0 + 4)) = (VisualDamageManager *)(*(_DWORD *)(*(_DWORD *)v91.gap0 + 4) - 104);
    std::wstreambuf::wstreambuf(&v91.gap10[8]);
    *(_DWORD *)&v91.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v91.gap10[64] = 0;
    *(_DWORD *)&v91.gap10[68] = 0;
    lvl = v12;
    LOBYTE(v112) = 23;
    v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v91.gap10, "VISUAL_OBJECT_");
    std::wostream::operator<<(v14, LODWORD(lvl));
    v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &vname);
    LOBYTE(v112) = 24;
    v16 = INIReader::hasSection(&ini, v15);
    if ( vname._Myres >= 8 )
      operator delete(vname._Bx._Ptr);
    if ( !v16 )
      break;
    nodes._Myfirst = 0;
    nodes._Mylast = 0;
    nodes._Myend = 0;
    LOBYTE(v112) = 25;
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    std::wstring::assign(&v95, L"NAME", 4u);
    LOBYTE(v112) = 26;
    v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &v96);
    LOBYTE(v112) = 27;
    INIReader::getString(&ini, &name, v17, &v95);
    if ( v96._Myres >= 8 )
      operator delete(v96._Bx._Ptr);
    v96._Myres = 7;
    v96._Mysize = 0;
    v96._Bx._Buf[0] = 0;
    LOBYTE(v112) = 30;
    if ( v95._Myres >= 8 )
      operator delete(v95._Bx._Ptr);
    v18 = v3->bodyTransform;
    v95._Myres = 7;
    v95._Bx._Buf[0] = 0;
    LODWORD(lvl) = &nodes;
    v19 = v18->__vftable;
    v95._Mysize = 0;
    v19->findChildrenByName(v18, &name, &nodes);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_SPEED", 9u);
    LOBYTE(v112) = 31;
    v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            &v91,
            (std::wstring *)&tex);
    LOBYTE(v112) = 32;
    *(float *)&_S20._Ptr = INIReader::getFloat(&ini, v20, &key);
    if ( tex.fileName._Mysize >= 8 )
      operator delete(tex.kid);
    tex.fileName._Mysize = 7;
    *(_DWORD *)&tex.fileName._Bx._Alias[12] = 0;
    LOWORD(tex.kid) = 0;
    LOBYTE(v112) = 30;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FULL_SPEED", 0xAu);
    LOBYTE(v112) = 33;
    v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            &v91,
            (std::wstring *)&tex);
    LOBYTE(v112) = 34;
    fullspeed = INIReader::getFloat(&ini, v21, &key);
    if ( tex.fileName._Mysize >= 8 )
      operator delete(tex.kid);
    tex.fileName._Mysize = 7;
    *(_DWORD *)&tex.fileName._Bx._Alias[12] = 0;
    LOWORD(tex.kid) = 0;
    LOBYTE(v112) = 30;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DAMAGE_ZONE", 0xBu);
    LOBYTE(v112) = 35;
    v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            &v91,
            (std::wstring *)&tex);
    LOBYTE(v112) = 36;
    INIReader::getString(&ini, &zonestring, v22, &key);
    if ( tex.fileName._Mysize >= 8 )
      operator delete(tex.kid);
    tex.fileName._Mysize = 7;
    *(_DWORD *)&tex.fileName._Bx._Alias[12] = 0;
    LOWORD(tex.kid) = 0;
    LOBYTE(v112) = 39;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    std::wstring::assign(&v95, L"STATIC_ROTATION_AXIS", 0x14u);
    LOBYTE(v112) = 40;
    v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &v96);
    LOBYTE(v112) = 41;
    INIReader::getFloat3(&ini, &static_damage_axis, v23, &v95);
    if ( v96._Myres >= 8 )
      operator delete(v96._Bx._Ptr);
    v96._Myres = 7;
    v96._Mysize = 0;
    v96._Bx._Buf[0] = 0;
    LOBYTE(v112) = 39;
    if ( v95._Myres >= 8 )
      operator delete(v95._Bx._Ptr);
    v24 = fsqrt(
            (float)((float)(static_damage_axis.x * static_damage_axis.x)
                  + (float)(static_damage_axis.y * static_damage_axis.y))
          + (float)(static_damage_axis.z * static_damage_axis.z));
    if ( v24 != 0.0 )
    {
      static_damage_axis.x = static_damage_axis.x * (float)(1.0 / v24);
      static_damage_axis.y = static_damage_axis.y * (float)(1.0 / v24);
      static_damage_axis.z = static_damage_axis.z * (float)(1.0 / v24);
    }
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    std::wstring::assign(&v95, L"STATIC_ROTATION_ANGLE", 0x15u);
    LOBYTE(v112) = 42;
    v25 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &v96);
    LOBYTE(v112) = 43;
    static_damage_angle = INIReader::getFloat(&ini, v25, &v95) * 0.017453;
    if ( v96._Myres >= 8 )
      operator delete(v96._Bx._Ptr);
    v96._Myres = 7;
    v96._Mysize = 0;
    v96._Bx._Buf[0] = 0;
    LOBYTE(v112) = 39;
    if ( v95._Myres >= 8 )
      operator delete(v95._Bx._Ptr);
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    std::wstring::assign(&v95, L"OSCILLATION_AXIS", 0x10u);
    LOBYTE(v112) = 44;
    v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &v96);
    LOBYTE(v112) = 45;
    INIReader::getFloat3(&ini, &oscillationAxis, v26, &v95);
    if ( v96._Myres >= 8 )
      operator delete(v96._Bx._Ptr);
    v96._Myres = 7;
    v96._Mysize = 0;
    v96._Bx._Buf[0] = 0;
    LOBYTE(v112) = 39;
    if ( v95._Myres >= 8 )
      operator delete(v95._Bx._Ptr);
    v27 = fsqrt(
            (float)((float)(oscillationAxis.x * oscillationAxis.x) + (float)(oscillationAxis.y * oscillationAxis.y))
          + (float)(oscillationAxis.z * oscillationAxis.z));
    if ( v27 != 0.0 )
    {
      oscillationAxis.x = oscillationAxis.x * (float)(1.0 / v27);
      oscillationAxis.y = oscillationAxis.y * (float)(1.0 / v27);
      oscillationAxis.z = oscillationAxis.z * (float)(1.0 / v27);
    }
    v96._Myres = 7;
    v96._Mysize = 0;
    v96._Bx._Buf[0] = 0;
    std::wstring::assign(&v96, L"OSCILLATION_MAX_ANGLE", 0x15u);
    LOBYTE(v112) = 46;
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    std::wstring::assign(&v95, L"OSCILLATION_MIN_ANGLE", 0x15u);
    LOBYTE(v112) = 47;
    v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &vname);
    LOBYTE(v112) = 48;
    v29 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &v106);
    LOBYTE(v112) = 49;
    *(float *)&_S21._Ptr = INIReader::getFloat(&ini, v28, &v96) * 0.017453;
    v30 = INIReader::getFloat(&ini, v29, &v95);
    LODWORD(oscillationAngle.max) = (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Mesh *> > >)_S21._Ptr;
    oscillationAngle.min = v30 * 0.017453;
    if ( v106._Myres >= 8 )
      operator delete(v106._Bx._Ptr);
    v106._Myres = 7;
    v106._Mysize = 0;
    v106._Bx._Buf[0] = 0;
    if ( vname._Myres >= 8 )
      operator delete(vname._Bx._Ptr);
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    if ( v95._Myres >= 8 )
      operator delete(v95._Bx._Ptr);
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    LOBYTE(v112) = 39;
    if ( v96._Myres >= 8 )
      operator delete(v96._Bx._Ptr);
    v96._Myres = 7;
    v96._Mysize = 0;
    v96._Bx._Buf[0] = 0;
    std::wstring::assign(&v96, L"MULT_G", 6u);
    LOBYTE(v112) = 50;
    v31 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &vname);
    LOBYTE(v112) = 51;
    *(float *)&sharedMaterial._Ptr = 1.0 - INIReader::getFloat(&ini, v31, &v96);
    if ( vname._Myres >= 8 )
      operator delete(vname._Bx._Ptr);
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    LOBYTE(v112) = 39;
    if ( v96._Myres >= 8 )
      operator delete(v96._Bx._Ptr);
    std::wstring::wstring(&v106, L"ALLOWED_G");
    LOBYTE(v112) = 52;
    v32 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v91, &vname);
    LOBYTE(v112) = 53;
    INIReader::getFloat3(&ini, &allowedG, v32, &v106);
    if ( vname._Myres >= 8 )
      operator delete(vname._Bx._Ptr);
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    LOBYTE(v112) = 39;
    if ( v106._Myres >= 8 )
      operator delete(v106._Bx._Ptr);
    *(float *)&v33._Ptr = COERCE_FLOAT(damageZoneFromString(&zonestring));
    v34 = nodes._Myfirst;
    v35 = 0;
    _S21._Ptr = v33._Ptr;
    v36 = (unsigned int)((char *)nodes._Mylast - (char *)nodes._Myfirst + 3) >> 2;
    if ( nodes._Myfirst > nodes._Mylast )
      v36 = 0;
    if ( v36 )
    {
      v86 = _S20._Ptr;
      v87 = fullspeed;
      do
      {
        v37 = *v34;
        VisualDamageManager::BreakablePart::BreakablePart(&_Val);
        *(__m128i *)&_Val.orgMatrix.M11 = _mm_loadu_si128((const __m128i *)&v37->matrix);
        LODWORD(_Val.range.minSpeed) = v86;
        v38 = _mm_loadu_si128((const __m128i *)&v37->matrix.M21);
        _Val.range.maxSpeed = v87;
        *(__m128i *)&_Val.orgMatrix.M21 = v38;
        _Val.damageZone = (int)_S21._Ptr;
        v39 = _mm_loadu_si128((const __m128i *)&v37->matrix.M31);
        _Val.staticDamageAxis.z = static_damage_axis.z;
        *(__m128i *)&_Val.orgMatrix.M31 = v39;
        _Val.oscillationAngle.min = oscillationAngle.min;
        v40 = _mm_loadu_si128((const __m128i *)&v37->matrix.M41);
        _Val.oscillationAngle.max = oscillationAngle.max;
        *(__m128i *)&_Val.orgMatrix.M41 = v40;
        _Val.oscillationAxis = oscillationAxis;
        *(_QWORD *)&_Val.staticDamageAxis.x = *(_QWORD *)&static_damage_axis.x;
        _Val.staticDamageAngle = static_damage_angle;
        _Val.allowedG = allowedG;
        LODWORD(_Val.oscillationGMult) = sharedMaterial._Ptr;
        _Val.damageLevel = 1.0;
        _Val.node = v37;
        _Val.phase = 0.0;
        std::vector<VisualDamageManager::BreakablePart>::push_back(
          (std::vector<VisualDamageManager::BreakablePart> *)&_This->car,
          &_Val);
        ++v35;
        ++v34;
      }
      while ( v35 != v36 );
      v34 = nodes._Myfirst;
    }
    if ( zonestring._Myres >= 8 )
    {
      operator delete(zonestring._Bx._Ptr);
      v34 = nodes._Myfirst;
    }
    zonestring._Myres = 7;
    zonestring._Mysize = 0;
    zonestring._Bx._Buf[0] = 0;
    if ( name._Myres >= 8 )
    {
      operator delete(name._Bx._Ptr);
      v34 = nodes._Myfirst;
    }
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    LOBYTE(v112) = 23;
    if ( v34 )
    {
      std::_Container_base0::_Orphan_all(&nodes);
      operator delete(nodes._Myfirst);
      nodes._Myfirst = 0;
      nodes._Mylast = 0;
      nodes._Myend = 0;
    }
    LODWORD(v12) = _Pos + 1;
    LOBYTE(v112) = 14;
    ++_Pos;
    *(_DWORD *)&v91.gap0[*(_DWORD *)(*(_DWORD *)v91.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(VisualDamageManager **)((char *)&v90 + *(_DWORD *)(*(_DWORD *)v91.gap0 + 4)) = (VisualDamageManager *)(*(_DWORD *)(*(_DWORD *)v91.gap0 + 4) - 104);
    *(_DWORD *)&v91.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v91.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v91.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v91.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v91.gap68);
    v3 = v78;
  }
  LOBYTE(v112) = 14;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v91);
  v4 = v80;
  _Pos = 0;
  if ( v80->_Mylast - v80->_Myfirst )
  {
    v41 = 0;
    do
    {
      if ( INIReader::hasSection(&ini, &glassDamageNames[v41]) )
      {
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        std::wstring::assign(&name, L"MIN_SPEED", 9u);
        v42 = v4->_Myfirst;
        LOBYTE(v112) = 54;
        v42[v41].range.minSpeed = INIReader::getFloat(&ini, &glassDamageNames[v41], &name);
        LOBYTE(v112) = 14;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        std::wstring::wstring(&vname, L"FULL_SPEED");
        v43 = v4->_Myfirst;
        LOBYTE(v112) = 55;
        v43[v41].range.maxSpeed = INIReader::getFloat(&ini, &glassDamageNames[v41], &vname);
        LOBYTE(v112) = 14;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
      }
      v44 = (char *)v4->_Mylast - (char *)v4->_Myfirst;
      ++v41;
      ++_Pos;
    }
    while ( _Pos < v44 / 24 );
    v3 = v78;
LABEL_96:
    v13 = v77;
  }
  v45 = (char *)v4->_Mylast - (char *)v4->_Myfirst;
  _Pos = 0;
  if ( v45 / 24 )
  {
    v46 = 0;
    while ( 1 )
    {
      *(_DWORD *)v93.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v93.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v93.gap68);
      LOBYTE(v112) = 56;
      v77 = v13 | 2;
      std::wiostream::basic_iostream<wchar_t>(&v93, &v93.gap10[8], 0);
      v112 = 57;
      *(_DWORD *)&v93.gap0[*(_DWORD *)(*(_DWORD *)v93.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&_Val.allowedG.z + *(_DWORD *)(*(_DWORD *)v93.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v93.gap0 + 4)
                                                                                   - 104;
      std::wstreambuf::wstreambuf(&v93.gap10[8]);
      *(_DWORD *)&v93.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v93.gap10[64] = 0;
      *(_DWORD *)&v93.gap10[68] = 0;
      v47 = 1;
      LOBYTE(v112) = 59;
      LODWORD(lvl) = 1;
      *(_DWORD *)&v72[24] = "_";
      v48 = std::operator<<<wchar_t>((std::wostream *)v93.gap10, &glassDamageNames[v46]);
      v49 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v48, *(const char **)&v72[24]);
      std::wostream::operator<<(v49, LODWORD(lvl));
      v50 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v93, &vname);
      v51 = v3->bodyTransform;
      LOBYTE(v112) = 60;
      v52 = v51->findChildByName(v51, v50, 1);
      LOBYTE(v112) = 59;
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      vname._Myres = 7;
      vname._Mysize = 0;
      for ( vname._Bx._Buf[0] = 0; v52; v106._Bx._Buf[0] = 0 )
      {
        collectAllMeshes(v52, &v4->_Myfirst[v46].meshes);
        std::wstring::wstring(&name, word_17BE9D8);
        LOBYTE(v112) = 61;
        std::wstringbuf::_Tidy((std::wstringbuf *)&v93.gap10[8]);
        lvl = *(float *)&v93.gap10[68];
        v53 = &name;
        *(_DWORD *)&v72[24] = name._Mysize;
        if ( name._Myres >= 8 )
          v53 = (std::wstring *)name._Bx._Ptr;
        std::wstringbuf::_Init(
          (std::wstringbuf *)&v93.gap10[8],
          v53->_Bx._Buf,
          *(unsigned int *)&v72[24],
          SLODWORD(lvl));
        LOBYTE(v112) = 59;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        LODWORD(lvl) = ++v47;
        *(_DWORD *)&v72[24] = "_";
        v54 = std::operator<<<wchar_t>((std::wostream *)v93.gap10, &glassDamageNames[v46]);
        v55 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v54, *(const char **)&v72[24]);
        std::wostream::operator<<(v55, LODWORD(lvl));
        v56 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v93, &v106);
        LOBYTE(v112) = 62;
        v52 = v78->bodyTransform->findChildByName(v78->bodyTransform, v56, 1);
        LOBYTE(v112) = 59;
        if ( v106._Myres >= 8 )
          operator delete(v106._Bx._Ptr);
        v106._Myres = 7;
        v106._Mysize = 0;
      }
      if ( v4->_Myfirst[v46].meshes._Myfirst == v4->_Myfirst[v46].meshes._Mylast )
      {
        LOBYTE(v112) = 14;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v93);
        v57 = _Pos;
      }
      else
      {
        std::wstring::wstring(&name, L"content/texture/DAMAGE_GLASS.dds");
        LOBYTE(v112) = 63;
        ResourceStore::getTexture(_This->game->graphics->resourceStore._Myptr, &tex, &name, 0);
        LOBYTE(v112) = 65;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        v58 = (std::vector<VisualDamageManager::GlassBreakablePart> *)operator new(104);
        v80 = v58;
        LOBYTE(v112) = 66;
        if ( v58 )
          Material::Material((Material *)v58, (*v4->_Myfirst[v46].meshes._Myfirst)->material._Ptr);
        else
          v59 = 0;
        LOBYTE(v112) = 65;
        sharedMaterial._Ptr = 0;
        sharedMaterial._Rep = 0;
        std::shared_ptr<Material>::_Resetp<Material>(&sharedMaterial, v59);
        LOBYTE(v112) = 67;
        std::wstring::wstring(&name, L"txNormal");
        LOBYTE(v112) = 68;
        Material::setTexture(sharedMaterial._Ptr, &name, &tex);
        LOBYTE(v112) = 67;
        if ( name._Myres >= 8 )
        {
          LODWORD(lvl) = name._Myres + 1;
          *(_DWORD *)&v72[24] = name._Bx._Ptr;
          v60 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                             (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&name,
                                             (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&v83
                                           + 3);
          std::allocator<wchar_t>::deallocate(v60, *(wchar_t **)&v72[24], LODWORD(lvl));
        }
        name._Myres = 7;
        std::wstring::_Eos(&name, 0);
        v61 = (Material *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&sharedMaterial);
        LODWORD(lvl) = L"glassDamage";
        v61->doubleFace = 1;
        std::wstring::wstring(&vname, (const wchar_t *)LODWORD(lvl));
        LOBYTE(v112) = 69;
        v62 = Material::getVar(v61, &vname);
        v57 = _Pos;
        v63 = v62;
        v64 = std::vector<VisualDamageManager::GlassBreakablePart>::operator[](v4, _Pos);
        LOBYTE(v112) = 67;
        v64->varDamage = v63;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        lvl = 0.0;
        v65 = std::vector<VisualDamageManager::GlassBreakablePart>::operator[](v4, v57);
        MaterialVar::setFloat(v65->varDamage, lvl);
        v66 = (std::vector<TyreCompoundDef> *)std::vector<VisualDamageManager::GlassBreakablePart>::operator[](v4, v57);
        std::vector<SetupTab *>::begin(
          v66,
          (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
        std::vector<Mesh *>::end(
          v66,
          (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
        while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
                  (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
                  (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
        {
          v67 = (std::shared_ptr<Material> **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
          std::shared_ptr<Material>::operator=(*v67 + 31, &sharedMaterial);
          std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator++((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > *)&_S20);
        }
        std::shared_ptr<Material>::~shared_ptr<Material>(&sharedMaterial);
        LOBYTE(v112) = 59;
        OnSetupAppCreated::~OnSetupAppCreated(&tex);
        LOBYTE(v112) = 14;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v93);
      }
      v68 = (char *)v4->_Mylast - (char *)v4->_Myfirst;
      ++v46;
      _Pos = v57 + 1;
      v8 = v57 + 1 < v68 / 24;
      v13 = v77;
      if ( !v8 )
        break;
      v3 = v78;
    }
  }
  lvl = 1.0;
  *(_DWORD *)&v72[24] = 0;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&sharedMaterial,
    _This);
  v80 = (std::vector<VisualDamageManager::GlassBreakablePart> *)v72;
  std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
    (std::function<void __cdecl(SVar *,float)> *)v72,
    v69);
  LOBYTE(v112) = 70;
  static_damage_angle = COERCE_FLOAT(&v71);
  std::wstring::wstring(&v71, L"debugDamage");
  LOBYTE(v112) = 71;
  v70 = Sim::getConsole(v78->sim);
  LOBYTE(v112) = 14;
  Console::addVarLambda(v70, v71, *(std::function<void __cdecl(SVar *,float)> *)v72, v72[24], lvl);
  LOBYTE(v112) = 13;
  INIReader::~INIReader(&ini);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  LOBYTE(v112) = 3;
  INIReader::~INIReader(&acINI);
}
void VisualDamageManager::~VisualDamageManager(VisualDamageManager *this)
{
  this->__vftable = (VisualDamageManager_vtbl *)&VisualDamageManager::`vftable';
  if ( this->glassBreakableParts._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->glassBreakableParts);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<VisualDamageManager::GlassBreakablePart>>>(
      this->glassBreakableParts._Myfirst,
      this->glassBreakableParts._Mylast);
    operator delete(this->glassBreakableParts._Myfirst);
    this->glassBreakableParts._Myfirst = 0;
    this->glassBreakableParts._Mylast = 0;
    this->glassBreakableParts._Myend = 0;
  }
  if ( this->scrathableParts._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->scrathableParts);
    operator delete(this->scrathableParts._Myfirst);
    this->scrathableParts._Myfirst = 0;
    this->scrathableParts._Mylast = 0;
    this->scrathableParts._Myend = 0;
  }
  if ( this->breakableParts._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->breakableParts);
    operator delete(this->breakableParts._Myfirst);
    this->breakableParts._Myfirst = 0;
    this->breakableParts._Mylast = 0;
    this->breakableParts._Myend = 0;
  }
  GameObject::~GameObject(this);
}
VisualDamageManager *VisualDamageManager::`scalar deleting destructor'(VisualDamageManager *this, unsigned int a2)
{
  VisualDamageManager::~VisualDamageManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void VisualDamageManager::initScratchableParts(VisualDamageManager *this, INIReader *ini)
{
  std::_Func_base<void,Node *> *v3; // ecx
  CarAvatar *v4; // ecx
  std::function<bool __cdecl(Node *)> v5; // [esp-2Ch] [ebp-84h] BYREF
  std::function<void __cdecl(Node *)> v6; // [esp-14h] [ebp-6Ch] BYREF
  float initial_damage; // [esp+14h] [ebp-44h]
  std::wstring section; // [esp+18h] [ebp-40h] BYREF
  std::wstring key; // [esp+30h] [ebp-28h] BYREF
  int v10; // [esp+54h] [ebp-4h]

  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"INITIAL_LEVEL", 0xDu);
  v10 = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DAMAGE", 6u);
  LOBYTE(v10) = 1;
  initial_damage = INIReader::getFloat(ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  v10 = -1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  (&v6._Impl)[1] = v3;
  CarAvatar::setDamageLevel(this->car, initial_damage);
  initial_damage = COERCE_FLOAT(&v6);
  v6._Impl = 0;
  v10 = 2;
  v5._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_f8ff827a2ba47f6b6eb6c1a263ec6e6d_,0>,std::allocator<std::_Func_class<bool,Node *>>,bool,Node *>::`vftable';
  *(_QWORD *)&v5._Space._Alias[4] = __PAIR64__((unsigned int)this, (unsigned int)ini);
  v5._Impl = (std::_Func_base<bool,Node *> *)&v5;
  v4 = this->car;
  v10 = -1;
  Node::visit(v4->bodyTransform, v5, v6);
}
void VisualDamageManager::update(VisualDamageManager *this, float deltaT)
{
  VisualDamageManager *v2; // esi
  float v3; // xmm0_4
  float v4; // xmm2_4
  VisualDamageManager *v5; // eax
  VisualDamageManager::ScratchablePart *v6; // esi
  VisualDamageManager::ScratchablePart *i; // edi
  Mesh *v8; // eax
  MaterialVar *v9; // eax
  bool v10; // cf
  MaterialVar *v11; // edx
  float v12; // xmm6_4
  bool v13; // cl
  float v14; // xmm0_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm1_4
  float v22; // xmm1_4
  VisualDamageManager *v23; // esi
  int v24; // eax
  int v25; // edi
  VisualDamageManager::GlassBreakablePart *v26; // ecx
  MaterialVar *v27; // edx
  float v28; // xmm0_4
  float v29; // xmm3_4
  ShaderVariable *v30; // ecx
  float *v31; // eax
  VisualDamageManager::BreakablePart *v32; // edi
  VisualDamageManager::BreakablePart *v33; // esi
  VisualDamageManager *v34; // eax
  float *v35; // ecx
  int v36; // edx
  float v37; // xmm2_4
  float v38; // xmm2_4
  int v39; // ecx
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm4_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm6_4
  float v48; // xmm4_4
  __m128 v49; // xmm1
  int v50; // ecx
  float v51; // xmm1_4
  int v52; // ecx
  float v53; // xmm7_4
  float v54; // xmm6_4
  float v55; // xmm4_4
  float v56; // xmm3_4
  float v57; // xmm2_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm4_4
  float v61; // xmm2_4
  __m128 v62; // xmm3
  float v63; // xmm2_4
  float v64; // xmm6_4
  float v65; // xmm4_4
  unsigned int v66; // xmm0_4
  float v67; // xmm1_4
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm0
  Node *v71; // eax
  CarAvatar *v72; // eax
  float v73; // xmm0_4
  float v74; // xmm5_4
  float v75; // xmm0_4
  float v76; // xmm4_4
  float v77; // xmm3_4
  float v78; // xmm3_4
  float v79; // xmm0_4
  float v80; // xmm3_4
  float v81; // xmm2_4
  int v82; // ecx
  float v83; // xmm7_4
  float v84; // xmm6_4
  float v85; // xmm4_4
  float v86; // xmm3_4
  Node *v87; // eax
  float v88; // xmm2_4
  float v89; // xmm0_4
  float v90; // xmm1_4
  float v91; // xmm2_4
  float v92; // xmm6_4
  float v93; // xmm4_4
  __m128 v94; // xmm1
  __m128 v95; // xmm0
  Node *v96; // eax
  Node *v97; // eax
  int v98; // [esp+0h] [ebp-164h]
  int v99; // [esp+0h] [ebp-164h]
  int v100; // [esp+4h] [ebp-160h]
  int v101; // [esp+4h] [ebp-160h]
  unsigned int v103; // [esp+14h] [ebp-150h]
  float v104; // [esp+14h] [ebp-150h]
  float v105; // [esp+14h] [ebp-150h]
  int v106; // [esp+18h] [ebp-14Ch]
  float v107; // [esp+18h] [ebp-14Ch]
  int v108; // [esp+1Ch] [ebp-148h]
  float *v109; // [esp+1Ch] [ebp-148h]
  __m128 v110; // [esp+20h] [ebp-144h]
  __m128 v111; // [esp+20h] [ebp-144h]
  __m128 v112; // [esp+20h] [ebp-144h]
  __int128 v113; // [esp+30h] [ebp-134h]
  __int128 v114; // [esp+30h] [ebp-134h]
  __int128 v115; // [esp+30h] [ebp-134h]
  _BYTE v116[32]; // [esp+40h] [ebp-124h]
  _BYTE v117[32]; // [esp+40h] [ebp-124h]
  _BYTE v118[32]; // [esp+40h] [ebp-124h]
  float v119; // [esp+60h] [ebp-104h]
  __m128i v120; // [esp+64h] [ebp-100h] BYREF
  DirectX::XMMATRIX M2; // [esp+74h] [ebp-F0h] BYREF
  DirectX::XMMATRIX v122; // [esp+B4h] [ebp-B0h] BYREF
  DirectX::XMMATRIX v123; // [esp+F4h] [ebp-70h] BYREF
  std::wstring vname; // [esp+138h] [ebp-2Ch] BYREF
  int v125; // [esp+160h] [ebp-4h]

  v2 = this;
  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
    v3 = v2->car->sim->replayManager->timeMult * deltaT;
  else
    v3 = deltaT;
  v119 = v3;
  if ( !v2->car->sim->pauseMenu->visible && damageEnabled )
  {
    GraphicsManager::clearTextureSlot(v2->game->graphics, 21);
    v4 = FLOAT_1_0;
    v5 = v2;
    v6 = v2->scrathableParts._Myfirst;
    for ( i = v5->scrathableParts._Mylast; v6 != i; v5 = this )
    {
      if ( !v6->varDamage )
      {
        vname._Myres = 7;
        vname._Mysize = 0;
        vname._Bx._Buf[0] = 0;
        std::wstring::assign(&vname, L"damageZones", 0xBu);
        v8 = v6->mesh;
        v125 = 0;
        v9 = Material::getVar(v8->material._Ptr, &vname);
        v10 = vname._Myres < 8;
        v6->varDamage = v9;
        v125 = -1;
        if ( !v10 )
          operator delete(vname._Bx._Ptr);
        v5 = this;
        v4 = FLOAT_1_0;
      }
      v11 = v6->varDamage;
      if ( v11 )
      {
        v12 = v6->range.maxSpeed;
        v13 = v5->isDebugMode;
        v14 = v12 - v6->range.minSpeed;
        if ( v13 )
        {
          v15 = (float)(v5->localDebugZones[0] - v6->range.minSpeed) / v14;
          if ( v15 <= v4 )
          {
            if ( v15 < 0.0 )
              v15 = 0.0;
          }
          else
          {
            v15 = v4;
          }
        }
        else
        {
          v15 = (float)(v5->car->physicsState.damageZoneLevel[0] - v6->range.minSpeed) / v14;
          if ( v15 <= v4 )
          {
            if ( v15 < 0.0 )
              v15 = 0.0;
          }
          else
          {
            v15 = v4;
          }
          v5 = this;
        }
        v16 = v12 - v6->range.minSpeed;
        if ( v13 )
        {
          v17 = (float)(v5->localDebugZones[3] - v6->range.minSpeed) / v16;
          if ( v17 <= v4 )
          {
            if ( v17 < 0.0 )
              v17 = 0.0;
          }
          else
          {
            v17 = v4;
          }
        }
        else
        {
          v17 = (float)(v5->car->physicsState.damageZoneLevel[3] - v6->range.minSpeed) / v16;
          if ( v17 <= v4 )
          {
            if ( v17 < 0.0 )
              v17 = 0.0;
          }
          else
          {
            v17 = v4;
          }
          v5 = this;
        }
        v18 = v12 - v6->range.minSpeed;
        if ( v13 )
        {
          v19 = (float)(v5->localDebugZones[1] - v6->range.minSpeed) / v18;
          if ( v19 <= v4 )
          {
            if ( v19 < 0.0 )
              v19 = 0.0;
          }
          else
          {
            v19 = v4;
          }
        }
        else
        {
          v19 = (float)(v5->car->physicsState.damageZoneLevel[1] - v6->range.minSpeed) / v18;
          if ( v19 <= v4 )
          {
            if ( v19 < 0.0 )
              v19 = 0.0;
          }
          else
          {
            v19 = v4;
          }
          v5 = this;
        }
        v20 = v12 - v6->range.minSpeed;
        if ( v13 )
          v21 = v5->localDebugZones[2];
        else
          v21 = v5->car->physicsState.damageZoneLevel[2];
        v22 = (float)(v21 - v6->range.minSpeed) / v20;
        if ( v22 <= v4 )
        {
          if ( v22 < 0.0 )
            v22 = 0.0;
        }
        else
        {
          v22 = v4;
        }
        v120.m128i_i64[0] = __PAIR64__(LODWORD(v19), LODWORD(v22));
        v120.m128i_i64[1] = __PAIR64__(LODWORD(v15), LODWORD(v17));
        v11->fValue4 = (vec4f)_mm_loadu_si128(&v120);
        MaterialVar::set(v11);
      }
      v4 = FLOAT_1_0;
      ++v6;
    }
    v23 = this;
    v103 = 0;
    if ( v5->glassBreakableParts._Mylast - v5->glassBreakableParts._Myfirst )
    {
      v24 = 2264;
      v25 = 0;
      v108 = 2264;
      do
      {
        v26 = v23->glassBreakableParts._Myfirst;
        v27 = v26[v25].varDamage;
        if ( v27 )
        {
          v28 = v26[v25].range.maxSpeed - v26[v25].range.minSpeed;
          if ( v23->isDebugMode )
          {
            v29 = (float)(*(float *)((char *)&v23[-16] + v24 - 120) - v26[v25].range.minSpeed) / v28;
            if ( v29 <= v4 )
            {
              if ( v29 < 0.0 )
                v29 = 0.0;
            }
            else
            {
              v29 = v4;
            }
          }
          else
          {
            v29 = (float)(*(float *)((char *)&v23->car->__vftable + v108) - v26[v25].range.minSpeed) / v28;
            if ( v29 <= v4 )
            {
              if ( v29 < 0.0 )
                v29 = 0.0;
            }
            else
            {
              v29 = v4;
            }
            v23 = this;
          }
          if ( v29 <= v23->glassDamageThreshold )
            v4 = 0.0;
          v30 = v27->var;
          v27->fValue = v4;
          switch ( v30->type )
          {
            case 0:
              ShaderVariable::set(v30, &v27->fValue);
              break;
            case 1:
              v31 = &v27->fValue2.x;
              goto LABEL_72;
            case 2:
              v31 = &v27->fValue3.x;
              goto LABEL_72;
            case 3:
              v31 = &v27->fValue4.x;
              goto LABEL_72;
            case 4:
              v31 = &v27->mValue.M11;
LABEL_72:
              ShaderVariable::set(v30, v31);
              break;
            default:
              break;
          }
        }
        ++v25;
        ++v103;
        v108 += 4;
        v4 = FLOAT_1_0;
        v24 = v108;
      }
      while ( v103 < v23->glassBreakableParts._Mylast - v23->glassBreakableParts._Myfirst );
    }
    v32 = v23->breakableParts._Mylast;
    v33 = v23->breakableParts._Myfirst;
    if ( v33 != v32 )
    {
      v34 = this;
      v35 = &v33->staticDamageAxis.z;
      v109 = &v33->staticDamageAxis.z;
      do
      {
        v36 = *((_DWORD *)v35 - 5);
        if ( v34->isDebugMode )
          v37 = v34->localDebugZones[v36];
        else
          v37 = v34->car->physicsState.damageZoneLevel[v36];
        v38 = (float)(v37 - *(v35 - 4)) / (float)(*(v35 - 3) - *(v35 - 4));
        if ( v38 <= 1.0 )
        {
          if ( v38 < 0.0 )
            v38 = 0.0;
        }
        else
        {
          v38 = FLOAT_1_0;
        }
        *(v35 - 23) = v38;
        if ( v38 == 0.0 )
        {
          v97 = v33->node;
          *(__m128i *)&v97->matrix.M11 = _mm_loadu_si128((const __m128i *)(v35 - 22));
          *(__m128i *)&v97->matrix.M21 = _mm_loadu_si128((const __m128i *)(v35 - 18));
          *(__m128i *)&v97->matrix.M31 = _mm_loadu_si128((const __m128i *)(v35 - 14));
          *(__m128i *)&v97->matrix.M41 = _mm_loadu_si128((const __m128i *)(v35 - 10));
          v34 = this;
        }
        else
        {
          v104 = __libm_sse2_cosf(v98, v100).m128_f32[0];
          v40 = __libm_sse2_sinf(v39).m128_f32[0];
          v41 = *(v109 - 2);
          v42 = *(v109 - 1);
          *(_OWORD *)&v116[12] = 0i64;
          *(_DWORD *)&v116[28] = 1065353216;
          v106 = (int)&v33->node->matrix;
          v110.m128_f32[0] = (float)((float)(v41 * v41) * (float)(1.0 - v104)) + v104;
          *((float *)&v113 + 1) = (float)((float)(v42 * v42) * (float)(1.0 - v104)) + v104;
          *(float *)&v116[8] = (float)((float)(*v109 * *v109) * (float)(1.0 - v104)) + v104;
          v43 = (float)(v41 * v42) * (float)(1.0 - v104);
          v44 = (float)(*v109 * v40) + v43;
          v45 = v42 * v40;
          *(float *)&v113 = v43 - (float)(*v109 * v40);
          v46 = (float)(v41 * *v109) * (float)(1.0 - v104);
          v110.m128_f32[1] = v44;
          v47 = v41 * v40;
          v48 = (float)(v42 * *v109) * (float)(1.0 - v104);
          M2.r[3] = *(__m128 *)(v109 - 10);
          v110.m128_u64[1] = COERCE_UNSIGNED_INT(v46 - v45);
          M2.r[2] = *(__m128 *)(v109 - 14);
          *(float *)v116 = v45 + v46;
          v49 = *(__m128 *)(v109 - 18);
          *((_QWORD *)&v113 + 1) = COERCE_UNSIGNED_INT(v47 + v48);
          *(float *)&v116[4] = v48 - v47;
          M2.r[0] = *(__m128 *)(v109 - 22);
          M2.r[1] = v49;
          *(__m128 *)v106 = DirectX::XMMatrixMultiply(M2.r, v110);
          *(_OWORD *)(v106 + 16) = v113;
          *(_OWORD *)(v106 + 32) = *(_OWORD *)v116;
          *(_OWORD *)(v106 + 48) = *(_OWORD *)&v116[16];
          v34 = this;
          if ( this->oscillationEnabled )
          {
            v51 = this->car->physicsState.engineRPM / (float)this->car->physicsState.limiterRPM;
            if ( v51 <= 1.0 )
            {
              if ( v51 < 0.30000001 )
                v51 = FLOAT_0_30000001;
            }
            else
            {
              v51 = FLOAT_1_0;
            }
            *(v109 - 6) = (float)((float)(*(v109 - 23) * v51) * 1000.0) + *(v109 - 6);
            __libm_sse2_sinf(v50);
            v105 = __libm_sse2_cosf(v98, v100).m128_f32[0];
            v53 = __libm_sse2_sinf(v52).m128_f32[0];
            v54 = v109[2];
            v55 = v109[3];
            v56 = v109[4];
            *(_OWORD *)&v117[12] = 0i64;
            *(_DWORD *)&v117[28] = 1065353216;
            v111.m128_f32[0] = (float)((float)(v54 * v54) * (float)(1.0 - v105)) + v105;
            *((float *)&v114 + 1) = (float)((float)(v55 * v55) * (float)(1.0 - v105)) + v105;
            v57 = (float)(v54 * v55) * (float)(1.0 - v105);
            *(float *)&v117[8] = (float)((float)(v56 * v56) * (float)(1.0 - v105)) + v105;
            v58 = (float)(v56 * v53) + v57;
            v59 = v55 * v53;
            v60 = v55 * v56;
            *(float *)&v114 = v57 - (float)(v56 * v53);
            v61 = v54 * v56;
            v62 = *(__m128 *)&v33->node->matrix.M41;
            v63 = v61 * (float)(1.0 - v105);
            v111.m128_f32[1] = v58;
            v64 = v54 * v53;
            v65 = v60 * (float)(1.0 - v105);
            *(float *)&v66 = v63 - v59;
            v67 = v59 + v63;
            v68 = *(__m128 *)&v33->node->matrix.M31;
            v111.m128_u64[1] = v66;
            *(float *)v117 = v67;
            v69 = *(__m128 *)&v33->node->matrix.M21;
            *((_QWORD *)&v114 + 1) = COERCE_UNSIGNED_INT(v64 + v65);
            *(float *)&v117[4] = v65 - v64;
            v122.r[0] = *(__m128 *)&v33->node->matrix.M11;
            v122.r[1] = v69;
            v122.r[2] = v68;
            v122.r[3] = v62;
            v70 = DirectX::XMMatrixMultiply(v122.r, v111);
            v71 = v33->node;
            *(__m128 *)&v71->matrix.M11 = v70;
            *(_OWORD *)&v71->matrix.M21 = v114;
            *(_OWORD *)&v71->matrix.M31 = *(_OWORD *)v117;
            *(_OWORD *)&v71->matrix.M41 = *(_OWORD *)&v117[16];
            v72 = this->car;
            v73 = COERCE_FLOAT(LODWORD(v72->physicsState.accG.x) & _xmm) * 0.5;
            if ( v73 <= 1.0 )
            {
              if ( v73 < 0.0 )
                v73 = 0.0;
            }
            else
            {
              v73 = FLOAT_1_0;
            }
            v74 = v109[9] * v73;
            v75 = COERCE_FLOAT(LODWORD(v72->physicsState.accG.y) & _xmm) * 0.40000001;
            if ( v75 <= 1.0 )
            {
              if ( v75 < 0.0 )
                v75 = 0.0;
            }
            else
            {
              v75 = FLOAT_1_0;
            }
            v76 = COERCE_FLOAT(LODWORD(v72->physicsState.accG.z) & _xmm) * 0.2;
            if ( v76 <= 1.0 )
            {
              if ( v76 < 0.0 )
                v76 = 0.0;
            }
            else
            {
              v76 = FLOAT_1_0;
            }
            v77 = (float)((float)((float)(v109[10] * v75) * (float)(v109[10] * v75)) + (float)(v74 * v74))
                + (float)((float)(v109[11] * v76) * (float)(v109[11] * v76));
            if ( v77 == 0.0 )
              v78 = 0.0;
            else
              v78 = fsqrt(v77);
            v79 = *(v109 - 23) * v78;
            if ( v79 <= 1.0 )
            {
              if ( v79 < 0.0 )
                v79 = 0.0;
            }
            else
            {
              v79 = FLOAT_1_0;
            }
            v80 = v109[5];
            v81 = (float)((float)((float)((float)((float)(v109[6] - v80) * v79) + v80) - v109[8])
                        * (float)(v109[7] * v119))
                + v109[8];
            if ( v81 <= v109[6] )
            {
              if ( v80 > v81 )
                v81 = v109[5];
            }
            else
            {
              v81 = v109[6];
            }
            v109[8] = v81;
            v107 = __libm_sse2_cosf(v99, v101).m128_f32[0];
            v83 = __libm_sse2_sinf(v82).m128_f32[0];
            v84 = v109[2];
            v85 = v109[3];
            v86 = v109[4];
            *(_OWORD *)&v118[12] = 0i64;
            v87 = v33->node;
            *(_DWORD *)&v118[28] = 1065353216;
            v112.m128_f32[0] = (float)((float)(v84 * v84) * (float)(1.0 - v107)) + v107;
            *((float *)&v115 + 1) = (float)((float)(v85 * v85) * (float)(1.0 - v107)) + v107;
            *(float *)&v118[8] = (float)((float)(v86 * v86) * (float)(1.0 - v107)) + v107;
            v88 = (float)(v84 * v85) * (float)(1.0 - v107);
            v89 = (float)(v86 * v83) + v88;
            v90 = v85 * v83;
            *(float *)&v115 = v88 - (float)(v86 * v83);
            v91 = (float)(v84 * v86) * (float)(1.0 - v107);
            v112.m128_f32[1] = v89;
            v92 = v84 * v83;
            v93 = (float)(v85 * v86) * (float)(1.0 - v107);
            v123.r[3] = *(__m128 *)&v33->node->matrix.M41;
            v112.m128_u64[1] = COERCE_UNSIGNED_INT(v91 - v90);
            v123.r[2] = *(__m128 *)&v87->matrix.M31;
            *(float *)v118 = v90 + v91;
            v94 = *(__m128 *)&v87->matrix.M21;
            *((_QWORD *)&v115 + 1) = COERCE_UNSIGNED_INT(v92 + v93);
            *(float *)&v118[4] = v93 - v92;
            v123.r[0] = *(__m128 *)&v87->matrix.M11;
            v123.r[1] = v94;
            v95 = DirectX::XMMatrixMultiply(v123.r, v112);
            v96 = v33->node;
            *(__m128 *)&v96->matrix.M11 = v95;
            *(_OWORD *)&v96->matrix.M21 = v115;
            *(_OWORD *)&v96->matrix.M31 = *(_OWORD *)v118;
            *(_OWORD *)&v96->matrix.M41 = *(_OWORD *)&v118[16];
            v34 = this;
          }
          v35 = v109;
        }
        ++v33;
        v35 += 36;
        v109 = v35;
      }
      while ( v33 != v32 );
    }
  }
}
