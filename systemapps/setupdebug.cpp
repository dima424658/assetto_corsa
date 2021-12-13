#include "setupdebug.h"
void __userpurge SetupDebug::SetupDebug(SetupDebug *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  std::wstring v7; // [esp-Ch] [ebp-64h] BYREF
  float w; // [esp+Ch] [ebp-4Ch]
  float h; // [esp+10h] [ebp-48h]
  std::shared_ptr<Font> v10; // [esp+24h] [ebp-34h] BYREF
  SetupDebug *v11; // [esp+2Ch] [ebp-2Ch]
  std::wstring v12; // [esp+30h] [ebp-28h] BYREF
  int v13; // [esp+54h] [ebp-4h]

  h = 0.0;
  v11 = this;
  w = *(float *)&aSim->game->gui;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, L"SETUP_DEBUG_APP", 0xFu);
  ksgui::Form::Form(this, a2, v7, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v13 = 0;
  LODWORD(h) = 11;
  this->__vftable = (SetupDebug_vtbl *)&SetupDebug::`vftable';
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  std::wstring::assign(&v12, L"Setup debug", LODWORD(h));
  LOBYTE(v13) = 1;
  this->formTitle->setText(this->formTitle, &v12);
  LOBYTE(v13) = 0;
  if ( v12._Myres >= 8 )
    operator delete(v12._Bx._Ptr);
  this->sim = aSim;
  this->y = 0.0;
  ksgui::Form::setSize(this, 400.0, 400.0);
  v4 = (Font *)operator new(0x18u);
  v10._Ptr = v4;
  LOBYTE(v13) = 2;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 20.0, 0, 0);
  else
    v5 = 0;
  LOBYTE(v13) = 0;
  v10 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v10, v5);
  v6 = this->font._Rep;
  this->font = v10;
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  ksgui::Form::setSize(this, 500.0, 1000.0);
}
void __userpurge SetupDebug::render(SetupDebug *this@<ecx>, int a2@<edi>, float dt)
{
  unsigned int v4; // eax
  CarAvatar *v5; // eax
  int v6; // edi
  void (__cdecl *v7)(void *); // ebx
  std::wstring *v8; // ecx
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  unsigned int v11; // eax
  CarAvatar *v12; // eax
  Car *v13; // eax
  int v14; // edi
  std::wstring *v15; // ecx
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  int i; // edi
  std::wstring *v19; // ecx
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  CarAvatar *v22; // edi
  std::wstring *v23; // eax
  SetupDebug_vtbl *v24; // eax
  float v25; // xmm1_4
  unsigned int v26; // ecx
  bool v27; // cf
  float v28; // xmm1_4
  float v29; // xmm2_4
  std::wstring *v30; // eax
  SetupDebug_vtbl *v31; // eax
  float v32; // xmm0_4
  unsigned int v33; // ecx
  std::wstring *v34; // eax
  SetupDebug_vtbl *v35; // eax
  float v36; // xmm0_4
  unsigned int v37; // ecx
  std::wstring *v38; // eax
  SetupDebug_vtbl *v39; // eax
  float v40; // xmm0_4
  unsigned int v41; // ecx
  Sim *v42; // ecx
  unsigned int v43; // eax
  CarAvatar *v44; // eax
  Car *v45; // eax
  Wing *v46; // edi
  Wing *v47; // esi
  SetupDebug *v48; // ebx
  SetupDebug *v49; // esi
  int j; // edi
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  unsigned int v54; // eax
  CarAvatar *v55; // eax
  ISuspension *v56; // eax
  int v57; // edi
  unsigned int v58; // eax
  int v59; // ebx
  std::wostream *v60; // eax
  std::wostream *v61; // eax
  unsigned int v62; // eax
  CarAvatar *v63; // eax
  int v64; // xmm1_4
  unsigned int v65; // eax
  unsigned int v66; // eax
  CarAvatar *v67; // eax
  Car *v68; // eax
  int v69; // edi
  std::wstring *v70; // eax
  std::wstring *v71; // eax
  std::wstring *v72; // eax
  int v73; // edi
  std::wstring *v74; // eax
  std::wstring *v75; // eax
  std::wstring *v76; // eax
  int v77; // edi
  std::wstring *v78; // eax
  std::wstring *v79; // eax
  std::wstring *v80; // eax
  int v81; // edi
  std::wstring *v82; // eax
  std::wstring *v83; // eax
  std::wstring *v84; // eax
  int v85; // edi
  std::wstring *v86; // eax
  std::wstring *v87; // eax
  std::wstring *v88; // eax
  int v89; // edi
  std::wstring *v90; // eax
  std::wstring *v91; // eax
  std::wstring *v92; // eax
  int v93; // edi
  int *v94; // ebx
  std::wstring *v95; // eax
  std::wstring *v96; // eax
  std::wstring v97; // [esp+6Ch] [ebp-20Ch] BYREF
  __int64 v98; // [esp+84h] [ebp-1F4h]
  float v99; // [esp+8Ch] [ebp-1ECh]
  int v100; // [esp+A0h] [ebp-1D8h]
  CarAvatar *v101; // [esp+A4h] [ebp-1D4h]
  __int64 x; // [esp+A8h] [ebp-1D0h] BYREF
  int *v103; // [esp+B0h] [ebp-1C8h]
  SetupDebug *v104; // [esp+B4h] [ebp-1C4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v105; // [esp+B8h] [ebp-1C0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v106; // [esp+168h] [ebp-110h] BYREF
  std::wstring s; // [esp+218h] [ebp-60h] BYREF
  std::wstring result; // [esp+234h] [ebp-44h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement _Newstr; // [esp+24Ch] [ebp-2Ch] BYREF
  int v110; // [esp+270h] [ebp-8h]
  int v111; // [esp+274h] [ebp-4h]
  char vars0; // [esp+278h] [ebp+0h]

  v104 = this;
  v100 = 0;
  ksgui::Control::render(this, a2, (int)this, dt, v98, v99);
  v4 = Sim::getFocusedCarIndex(this->sim);
  v5 = Sim::getCar(this->sim, v4);
  v97._Myres = 0;
  v97._Mysize = (unsigned int)&Car `RTTI Type Descriptor';
  *(_DWORD *)&v97._Bx._Alias[12] = &ICarPhysicsStateProvider `RTTI Type Descriptor';
  *(_DWORD *)&v97._Bx._Alias[4] = v5->physicsStateProvider;
  v101 = v5;
  __RTDynamicCast(
    *(_DWORD *)&v97._Bx._Alias[4],
    0,
    &ICarPhysicsStateProvider `RTTI Type Descriptor',
    &Car `RTTI Type Descriptor',
    0);
  this->y = 15.0;
  *(_DWORD *)v105.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v105.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v105.gap68);
  v111 = 0;
  v100 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v105, &v105.gap10[8], 0);
  v111 = 1;
  *(_DWORD *)&v105.gap0[*(_DWORD *)(*(_DWORD *)v105.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(SetupDebug **)((char *)&v104 + *(_DWORD *)(*(_DWORD *)v105.gap0 + 4)) = (SetupDebug *)(*(_DWORD *)(*(_DWORD *)v105.gap0 + 4)
                                                                                         - 104);
  std::wstreambuf::wstreambuf(&v105.gap10[8]);
  *(_DWORD *)&v105.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v105.gap10[64] = 0;
  *(_DWORD *)&v105.gap10[68] = 0;
  v111 = 3;
  v6 = 0;
  v7 = operator delete;
  v103 = 0;
  do
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v111) = 4;
    if ( (v105.gap10[68] & 1) != 0 )
      operator delete(**(void ***)&v105.gap10[20]);
    std::wstreambuf::setg(&v105.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v105.gap10[8], 0, 0);
    v8 = &result;
    *(_DWORD *)&v105.gap10[64] = 0;
    v97._Myres = *(_DWORD *)&v105.gap10[68] & 0xFFFFFFFE;
    if ( result._Myres >= 8 )
      v8 = (std::wstring *)result._Bx._Ptr;
    *(_DWORD *)&v105.gap10[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v8->_Bx._Buf, result._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v103);
    v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &result);
    LOBYTE(v111) = 5;
    v10 = std::operator+<wchar_t>(&s, L"AIR PRESSURE ", v9);
    LOBYTE(v111) = 6;
    LODWORD(x) = &v97;
    std::operator+<wchar_t>(&v97, v10, L" : ");
    LOBYTE(v111) = 7;
    v11 = Sim::getFocusedCarIndex(this->sim);
    v12 = Sim::getCar(this->sim, v11);
    v13 = RaceEngineer::getCar(v12->raceEngineer._Myptr);
    LOBYTE(v111) = 6;
    SetupDebug::printStringList(this, LODWORD(v13->tyres[v6].status.pressureStatic), SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v103 = (int *)((char *)v103 + 1);
    ++v6;
  }
  while ( v6 < 4 );
  v14 = 0;
  LODWORD(x) = v101->physicsState.camberRAD;
  v103 = (int *)v101->physicsState.camberRAD;
  do
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v111) = 8;
    if ( (v105.gap10[68] & 1) != 0 )
      operator delete(**(void ***)&v105.gap10[20]);
    std::wstreambuf::setg(&v105.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v105.gap10[8], 0, 0);
    v15 = &result;
    *(_DWORD *)&v105.gap10[64] = 0;
    v97._Myres = *(_DWORD *)&v105.gap10[68] & 0xFFFFFFFE;
    if ( result._Myres >= 8 )
      v15 = (std::wstring *)result._Bx._Ptr;
    *(_DWORD *)&v105.gap10[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v15->_Bx._Buf, result._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v14);
    v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 9;
    v17 = std::operator+<wchar_t>(&s, L"camberRAD ", v16);
    LOBYTE(v111) = 10;
    std::operator+<wchar_t>(&v97, v17, L" : ");
    SetupDebug::printStringList(this, *v103, SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      operator delete(_Newstr.name._Bx._Ptr);
    ++v103;
    ++v14;
  }
  while ( v14 < 4 );
  for ( i = 0; i < 4; ++i )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v111) = 11;
    if ( (v105.gap10[68] & 1) != 0 )
      operator delete(**(void ***)&v105.gap10[20]);
    std::wstreambuf::setg(&v105.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v105.gap10[8], 0, 0);
    v19 = &result;
    *(_DWORD *)&v105.gap10[64] = 0;
    v97._Myres = *(_DWORD *)&v105.gap10[68] & 0xFFFFFFFE;
    if ( result._Myres >= 8 )
      v19 = (std::wstring *)result._Bx._Ptr;
    *(_DWORD *)&v105.gap10[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v19->_Bx._Buf, result._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, i);
    v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 12;
    v21 = std::operator+<wchar_t>(&s, L"camberDEG ", v20);
    LOBYTE(v111) = 13;
    std::operator+<wchar_t>(&v97, v21, L" : ");
    SetupDebug::printStringList(this, COERCE_INT(*(float *)x * 57.29578), SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      operator delete(_Newstr.name._Bx._Ptr);
    LODWORD(x) = x + 4;
  }
  v22 = v101;
  v23 = vec3f::toString(&v101->physicsState.accG, &_Newstr.name);
  LOBYTE(v111) = 14;
  std::operator+<wchar_t>(&s, L"accG ", v23);
  LOBYTE(v111) = 15;
  v24 = this->__vftable;
  v25 = this->y;
  result._Bx._Ptr = 0;
  *(float *)&result._Bx._Alias[4] = v25;
  v24->localToWorld(this, (vec2f *)&x, (const vec2f *)&result);
  v97._Myres = 0;
  v97._Mysize = v26;
  Font::blitString(this->font._Ptr, *(float *)&x, *((float *)&x + 1), &s, 1.0, eAlignLeft);
  v27 = s._Myres < 8;
  this->y = this->y + 20.0;
  if ( !v27 )
    operator delete(s._Bx._Ptr);
  LOBYTE(v111) = 3;
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( _Newstr.name._Myres >= 8 )
    operator delete(_Newstr.name._Bx._Ptr);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"engineRPM ", 0xAu);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.engineRPM), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"limiterRPM ", 0xBu);
  SetupDebug::printStringList(this, COERCE_INT((float)v22->physicsState.limiterRPM), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"isEngineLimiterOn ", 0x12u);
  SetupDebug::printStringList(this, COERCE_INT((float)v22->physicsState.isEngineLimiterOn), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"steer ", 6u);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.steer), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"gas ", 4u);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.gas), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"brake ", 6u);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.brake), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"clutch ", 7u);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.clutch), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"gear ", 5u);
  SetupDebug::printStringList(this, COERCE_INT((float)v22->physicsState.gear), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"cgHeight ", 9u);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.cgHeight), SLODWORD(FLOAT_4_0), v97);
  v28 = v22->physicsState.worldMatrix.M42;
  v29 = v22->physicsState.worldMatrix.M43;
  result._Bx._Ptr = (wchar_t *)LODWORD(v22->physicsState.worldMatrix.M41);
  *(_QWORD *)&result._Bx._Alias[4] = __PAIR64__(LODWORD(v29), LODWORD(v28));
  v30 = vec3f::toString((vec3f *)&result, &_Newstr.name);
  LOBYTE(v111) = 16;
  std::operator+<wchar_t>(&s, L"worldPosition ", v30);
  LOBYTE(v111) = 17;
  v31 = this->__vftable;
  v32 = this->y;
  result._Bx._Ptr = 0;
  *(float *)&result._Bx._Alias[4] = v32;
  v31->localToWorld(this, (vec2f *)&x, (const vec2f *)&result);
  v97._Myres = 0;
  v97._Mysize = v33;
  Font::blitString(this->font._Ptr, *(float *)&x, *((float *)&x + 1), &s, 1.0, eAlignLeft);
  v27 = s._Myres < 8;
  this->y = this->y + 20.0;
  if ( !v27 )
    operator delete(s._Bx._Ptr);
  LOBYTE(v111) = 3;
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( _Newstr.name._Myres >= 8 )
    operator delete(_Newstr.name._Bx._Ptr);
  v34 = vec3f::toString(&v22->physicsState.velocity, &_Newstr.name);
  LOBYTE(v111) = 18;
  std::operator+<wchar_t>(&s, L"velocity ", v34);
  LOBYTE(v111) = 19;
  v35 = this->__vftable;
  v36 = this->y;
  result._Bx._Ptr = 0;
  *(float *)&result._Bx._Alias[4] = v36;
  v35->localToWorld(this, (vec2f *)&x, (const vec2f *)&result);
  v97._Myres = 0;
  v97._Mysize = v37;
  Font::blitString(this->font._Ptr, *(float *)&x, *((float *)&x + 1), &s, 1.0, eAlignLeft);
  v27 = s._Myres < 8;
  this->y = this->y + 20.0;
  if ( !v27 )
    operator delete(s._Bx._Ptr);
  LOBYTE(v111) = 3;
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( _Newstr.name._Myres >= 8 )
    operator delete(_Newstr.name._Bx._Ptr);
  v38 = CarAvatar::getTyreCompound(v22, &_Newstr.name, 0, 1);
  LOBYTE(v111) = 20;
  std::operator+<wchar_t>(&s, L"Tyre Comp.: ", v38);
  LOBYTE(v111) = 21;
  v39 = this->__vftable;
  v40 = this->y;
  result._Bx._Ptr = 0;
  *(float *)&result._Bx._Alias[4] = v40;
  v39->localToWorld(this, (vec2f *)&x, (const vec2f *)&result);
  v97._Myres = 0;
  v97._Mysize = v41;
  Font::blitString(this->font._Ptr, *(float *)&x, *((float *)&x + 1), &s, 1.0, eAlignLeft);
  v27 = s._Myres < 8;
  this->y = this->y + 20.0;
  if ( !v27 )
    operator delete(s._Bx._Ptr);
  LOBYTE(v111) = 3;
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( _Newstr.name._Myres >= 8 )
    operator delete(_Newstr.name._Bx._Ptr);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"lapTime ", 8u);
  SetupDebug::printStringList(this, COERCE_INT((float)v22->physicsState.lapTime), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"lastLap ", 8u);
  SetupDebug::printStringList(this, COERCE_INT((float)v22->physicsState.lastLap), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"bestLap ", 8u);
  SetupDebug::printStringList(this, COERCE_INT((float)v22->physicsState.bestLap), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"lapCount ", 9u);
  SetupDebug::printStringList(this, COERCE_INT((float)v22->physicsState.lapCount), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"performanceMeter ", 0x11u);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.performanceMeter), SLODWORD(FLOAT_4_0), v97);
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"FUEL  ", 6u);
  SetupDebug::printStringList(this, LODWORD(v22->physicsState.fuel), SLODWORD(FLOAT_4_0), v97);
  v42 = this->sim;
  this->y = this->y + 20.0;
  v43 = Sim::getFocusedCarIndex(v42);
  v44 = Sim::getCar(this->sim, v43);
  v45 = RaceEngineer::getCar(v44->raceEngineer._Myptr);
  v46 = v45->aeroMap.wings._Mylast;
  v47 = v45->aeroMap.wings._Myfirst;
  if ( v47 != v46 )
  {
    v48 = v104;
    do
    {
      v97._Myres = 7;
      v97._Mysize = 0;
      v97._Bx._Buf[0] = 0;
      std::wstring::assign(&v97, L"AEROMAP : ", 0xAu);
      SetupDebug::printStringList(v48, LODWORD(v47->status.angle), SLODWORD(FLOAT_4_0), v97);
      ++v47;
    }
    while ( v47 != v46 );
    v7 = operator delete;
  }
  v49 = v104;
  for ( j = 0; j < 4; ++j )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v111) = 22;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v105.gap10[8]);
    v97._Myres = *(_DWORD *)&v105.gap10[68];
    v51 = &result;
    v97._Mysize = result._Mysize;
    if ( result._Myres >= 8 )
      v51 = (std::wstring *)result._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v51->_Bx._Buf, v97._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( result._Myres >= 8 )
      v7(result._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, j);
    v52 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 23;
    v53 = std::operator+<wchar_t>(&s, L"ROD LENGTH ", v52);
    LOBYTE(v111) = 24;
    result._Bx._Ptr = (wchar_t *)&v97;
    std::operator+<wchar_t>(&v97, v53, L" : ");
    LOBYTE(v111) = 25;
    v54 = Sim::getFocusedCarIndex(v49->sim);
    v55 = Sim::getCar(v49->sim, v54);
    v56 = RaceEngineer::getCar(v55->raceEngineer._Myptr)->suspensions._Myfirst[j];
    LOBYTE(v111) = 24;
    SetupDebug::printStringList(v49, LODWORD(v56->rodLength), SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      v7(_Newstr.name._Bx._Ptr);
  }
  v57 = 0;
  v58 = Sim::getFocusedCarIndex(v49->sim);
  if ( Sim::getCar(v49->sim, v58)->physicsInfo.maxGear > 0 )
  {
    v59 = 2;
    do
    {
      *(_DWORD *)v106.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v106.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v106.gap68);
      vars0 = 26;
      v101 = (CarAvatar *)((unsigned int)v101 | 2);
      std::wiostream::basic_iostream<wchar_t>(&v106.gap0[4], &v106.gap10[12], 0);
      v110 = 27;
      *(_DWORD *)&v105.gap68[*(_DWORD *)(*(_DWORD *)&v105.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v105.gap68[*(_DWORD *)(*(_DWORD *)&v105.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v105.gap68[68]
                                                                                           + 4)
                                                                               - 104;
      std::wstreambuf::wstreambuf(&v106.gap10[4]);
      *(_DWORD *)&v106.gap10[4] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v106.gap10[60] = 0;
      *(_DWORD *)&v106.gap10[64] = 0;
      v97._Mysize = (unsigned int)"  : ";
      ++v57;
      LOBYTE(v110) = 29;
      *(_DWORD *)&v97._Bx._Alias[12] = v57;
      v60 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)((char *)&v106._Chcount + 4), "GEARS ");
      v61 = (std::wostream *)std::wostream::operator<<(v60, *(_DWORD *)&v97._Bx._Alias[12]);
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v61, (const char *)v97._Myres);
      result._Bx._Ptr = (wchar_t *)&v97;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v106, &v97);
      LOBYTE(v111) = 30;
      v62 = Sim::getFocusedCarIndex(v49->sim);
      v63 = Sim::getCar(v49->sim, v62);
      *(float *)&v64 = RaceEngineer::getCar(v63->raceEngineer._Myptr)->drivetrain.gears._Myfirst[v59].ratio;
      LOBYTE(v111) = 29;
      SetupDebug::printStringList(v49, v64, SLODWORD(FLOAT_4_0), v97);
      LOBYTE(v111) = 3;
      *(_DWORD *)&v106.gap0[*(_DWORD *)(*(_DWORD *)v106.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v105.gap68[*(_DWORD *)(*(_DWORD *)v106.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v106.gap0 + 4) - 104;
      *(_DWORD *)&v106.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v106.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v106.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v106.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v106.gap68);
      ++v59;
      v65 = Sim::getFocusedCarIndex(v49->sim);
    }
    while ( v57 < Sim::getCar(v49->sim, v65)->physicsInfo.maxGear );
    v7 = operator delete;
  }
  result._Bx._Ptr = (wchar_t *)&v97;
  v97._Myres = 7;
  v97._Mysize = 0;
  v97._Bx._Buf[0] = 0;
  std::wstring::assign(&v97, L"FINAL RATIO : ", 0xEu);
  LOBYTE(v111) = 31;
  v66 = Sim::getFocusedCarIndex(v49->sim);
  v67 = Sim::getCar(v49->sim, v66);
  v68 = RaceEngineer::getCar(v67->raceEngineer._Myptr);
  LOBYTE(v111) = 3;
  SetupDebug::printStringList(v49, LODWORD(v68->drivetrain.finalRatio), SLODWORD(FLOAT_4_0), v97);
  v69 = 0;
  v100 = (int)v101->physicsState.wheelAngularSpeed;
  do
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v111) = 32;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v105.gap10[8]);
    v97._Myres = *(_DWORD *)&v105.gap10[68];
    v70 = &result;
    v97._Mysize = result._Mysize;
    if ( result._Myres >= 8 )
      v70 = (std::wstring *)result._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v70->_Bx._Buf, v97._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( result._Myres >= 8 )
      v7(result._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v69);
    v71 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 33;
    v72 = std::operator+<wchar_t>(&s, L"wheelAngularSpeed ", v71);
    LOBYTE(v111) = 34;
    std::operator+<wchar_t>(&v97, v72, L" : ");
    SetupDebug::printStringList(v49, *(_DWORD *)v100, SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      v7(_Newstr.name._Bx._Ptr);
    v100 += 4;
    ++v69;
  }
  while ( v69 < 4 );
  v73 = 0;
  v100 = (int)v101->physicsState.slipAngle;
  do
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v111) = 35;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v105.gap10[8]);
    v97._Myres = *(_DWORD *)&v105.gap10[68];
    v74 = &result;
    v97._Mysize = result._Mysize;
    if ( result._Myres >= 8 )
      v74 = (std::wstring *)result._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v74->_Bx._Buf, v97._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( result._Myres >= 8 )
      v7(result._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v73);
    v75 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 36;
    v76 = std::operator+<wchar_t>(&s, L"slipAngle ", v75);
    LOBYTE(v111) = 37;
    std::operator+<wchar_t>(&v97, v76, L" : ");
    SetupDebug::printStringList(v49, *(_DWORD *)v100, SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      v7(_Newstr.name._Bx._Ptr);
    v100 += 4;
    ++v73;
  }
  while ( v73 < 4 );
  v77 = 0;
  v100 = (int)v101->physicsState.slipRatio;
  do
  {
    std::wstring::wstring(&s, word_17BE9D8);
    LOBYTE(v111) = 38;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v105.gap10[8]);
    v97._Myres = *(_DWORD *)&v105.gap10[68];
    v78 = &s;
    v97._Mysize = s._Mysize;
    if ( s._Myres >= 8 )
      v78 = (std::wstring *)s._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v78->_Bx._Buf, v97._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v77);
    v79 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 39;
    v80 = std::operator+<wchar_t>(&s, L"slipRatio ", v79);
    LOBYTE(v111) = 40;
    std::operator+<wchar_t>(&v97, v80, L" : ");
    SetupDebug::printStringList(v49, *(_DWORD *)v100, SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      v7(_Newstr.name._Bx._Ptr);
    v100 += 4;
    ++v77;
  }
  while ( v77 < 4 );
  v81 = 0;
  v100 = (int)v101->physicsState.load;
  do
  {
    std::wstring::wstring(&s, word_17BE9D8);
    LOBYTE(v111) = 41;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v105.gap10[8]);
    v97._Myres = *(_DWORD *)&v105.gap10[68];
    v82 = &s;
    v97._Mysize = s._Mysize;
    if ( s._Myres >= 8 )
      v82 = (std::wstring *)s._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v82->_Bx._Buf, v97._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v81);
    v83 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 42;
    v84 = std::operator+<wchar_t>(&s, L"load ", v83);
    LOBYTE(v111) = 43;
    std::operator+<wchar_t>(&v97, v84, L" : ");
    SetupDebug::printStringList(v49, *(_DWORD *)v100, SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      v7(_Newstr.name._Bx._Ptr);
    v100 += 4;
    ++v81;
  }
  while ( v81 < 4 );
  v85 = 0;
  v100 = (int)v101->physicsState.tyreDirtyLevel;
  do
  {
    std::wstring::wstring(&s, word_17BE9D8);
    LOBYTE(v111) = 44;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v105.gap10[8]);
    v97._Myres = *(_DWORD *)&v105.gap10[68];
    v86 = &s;
    v97._Mysize = s._Mysize;
    if ( s._Myres >= 8 )
      v86 = (std::wstring *)s._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v86->_Bx._Buf, v97._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v85);
    v87 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 45;
    v88 = std::operator+<wchar_t>(&s, L"tyreDirtyLevel ", v87);
    LOBYTE(v111) = 46;
    std::operator+<wchar_t>(&v97, v88, L" : ");
    SetupDebug::printStringList(v49, *(_DWORD *)v100, SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      v7(_Newstr.name._Bx._Ptr);
    v100 += 4;
    ++v85;
  }
  while ( v85 < 4 );
  v89 = 0;
  v100 = (int)v101->physicsState.suspensionTravel;
  do
  {
    std::wstring::wstring(&s, word_17BE9D8);
    LOBYTE(v111) = 47;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v105.gap10[8]);
    v97._Myres = *(_DWORD *)&v105.gap10[68];
    v90 = &s;
    v97._Mysize = s._Mysize;
    if ( s._Myres >= 8 )
      v90 = (std::wstring *)s._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v105.gap10[8], v90->_Bx._Buf, v97._Mysize, v97._Myres);
    LOBYTE(v111) = 3;
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    std::wostream::operator<<(v105.gap10, v89);
    v91 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 48;
    v92 = std::operator+<wchar_t>(&s, L"suspensionTravel ", v91);
    LOBYTE(v111) = 49;
    std::operator+<wchar_t>(&v97, v92, L" : ");
    SetupDebug::printStringList(v49, *(_DWORD *)v100, SLODWORD(FLOAT_4_0), v97);
    if ( s._Myres >= 8 )
      v7(s._Bx._Ptr);
    LOBYTE(v111) = 3;
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    if ( _Newstr.name._Myres >= 8 )
      v7(_Newstr.name._Bx._Ptr);
    v100 += 4;
    ++v89;
  }
  while ( v89 < 4 );
  v93 = 0;
  v94 = (int *)v101->physicsState.ndSlip;
  do
  {
    std::wstring::wstring(&_Newstr.name, word_17BE9D8);
    LOBYTE(v111) = 50;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &_Newstr.name);
    LOBYTE(v111) = 3;
    std::wstring::~wstring(&_Newstr);
    std::wostream::operator<<(v105.gap10, v93);
    v95 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v105, &s);
    LOBYTE(v111) = 51;
    v96 = std::operator+<wchar_t>(&_Newstr.name, L"ndSlip ", v95);
    LOBYTE(v111) = 52;
    std::operator+<wchar_t>(&v97, v96, L" : ");
    SetupDebug::printStringList(v49, *v94, SLODWORD(FLOAT_4_0), v97);
    std::wstring::~wstring(&_Newstr);
    LOBYTE(v111) = 3;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    ++v93;
    ++v94;
  }
  while ( v93 < 4 );
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v105);
}
void __userpurge SetupDebug::printStringList(SetupDebug *this@<ecx>, int a2@<xmm1>, int a3@<xmm2>, std::wstring name)
{
  int v7; // ecx
  SetupDebug_vtbl *v8; // eax
  float v9; // xmm0_4
  std::wstring *v10; // eax
  const std::wstring *v11; // eax
  int v12; // eax
  int v13[4]; // [esp+3Ch] [ebp-108h] BYREF
  vec2f pos; // [esp+4Ch] [ebp-F8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v15; // [esp+54h] [ebp-F0h] BYREF
  std::wstring v16; // [esp+104h] [ebp-40h] BYREF
  std::wstring result; // [esp+11Ch] [ebp-28h] BYREF
  int v18; // [esp+140h] [ebp-4h]

  v13[2] = a3;
  v13[0] = a2;
  v18 = 0;
  *(_DWORD *)v15.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v15.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v15.gap68);
  LOBYTE(v18) = 1;
  v13[3] = 1;
  std::wiostream::basic_iostream<wchar_t>(&v15, &v15.gap10[8], 0);
  v18 = 2;
  *(_DWORD *)&v15.gap0[*(_DWORD *)(*(_DWORD *)v15.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.y + *(_DWORD *)(*(_DWORD *)v15.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v15.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v15.gap10[8]);
  *(_DWORD *)&v15.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v15.gap10[64] = 0;
  *(_DWORD *)&v15.gap10[68] = 0;
  LOBYTE(v18) = 4;
  __libm_sse2_powf(v7);
  std::wostream::operator<<(v15.gap10);
  v8 = this->__vftable;
  v9 = this->y;
  v13[0] = 0;
  *(float *)&v13[1] = v9;
  v8->localToWorld(this, &pos, (const vec2f *)v13);
  v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v15, &result);
  LOBYTE(v18) = 5;
  v11 = std::operator+<wchar_t>(&v16, &name, v10);
  LOBYTE(v18) = 6;
  Font::blitString(this->font._Ptr, pos.x, pos.y, v11, 1.0, eAlignLeft);
  if ( v16._Myres >= 8 )
    operator delete(v16._Bx._Ptr);
  v16._Myres = 7;
  v16._Mysize = 0;
  v16._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v12 = *(_DWORD *)v15.gap0;
  this->y = this->y + 20.0;
  *(_DWORD *)&v15.gap0[*(_DWORD *)(v12 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.y + *(_DWORD *)(*(_DWORD *)v15.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v15.gap0 + 4) - 104;
  *(_DWORD *)&v15.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v15.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v15.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v15.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v15.gap68);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
