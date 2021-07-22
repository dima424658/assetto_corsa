#include "pitcrew.h
void PitCrew::PitCrew(PitCrew *this, CarAvatar *aCar, std::wstring skin)
{
  int v4; // ebx
  Sim *v5; // eax
  Game *v6; // eax
  char v7; // al
  std::wstring *v8; // edx
  unsigned int v9; // ecx
  PitCrew::{ctor}::__l30::<lambda_a281ae7dde51db8b02ffd1ae29fb0902> *v10; // esi
  Node *v11; // eax
  const __m128i *v12; // eax
  float v13; // xmm0_4
  const std::wstring *v14; // edi
  double v15; // st7
  double v16; // st7
  double v17; // st7
  Node *v18; // eax
  AnimationPlayer *v19; // eax
  AnimationPlayer *v20; // eax
  CarAudioFMOD *v21; // esi
  AudioEvent *v22; // eax
  Game *v23; // eax
  CarAudioFMOD *v24; // esi
  AudioEvent *v25; // eax
  Game *v26; // eax
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  Node **v33; // esi
  int v34; // edi
  unsigned int v35; // ebx
  CarAvatar *v36; // eax
  std::wstring *v37; // edi
  NodeBoundingSphere *v38; // ecx
  Node *v39; // eax
  const __m128i *v40; // eax
  Node *v41; // ecx
  bool v42; // zf
  PitCrew::{ctor}::__l40::<lambda_40085dc40819131e0092da0abfab2a9e> *v43; // eax
  _BYTE aTimeToPosDefault[48]; // [esp-16h] [ebp-318h] BYREF
  int v45; // [esp+2Eh] [ebp-2D4h] BYREF
  float v46; // [esp+32h] [ebp-2D0h]
  char _Arg[5]; // [esp+39h] [ebp-2C9h] BYREF
  PitCrew::{ctor}::__l30::<lambda_a281ae7dde51db8b02ffd1ae29fb0902> *_Val; // [esp+3Eh] [ebp-2C4h]
  std::wstring *v49; // [esp+42h] [ebp-2C0h]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v50; // [esp+46h] [ebp-2BCh] BYREF
  float tyreMult; // [esp+4Ah] [ebp-2B8h]
  int v52; // [esp+4Eh] [ebp-2B4h]
  SceneGraphCloner cloner; // [esp+52h] [ebp-2B0h] BYREF
  PitCrew::CrewMember member; // [esp+56h] [ebp-2ACh] BYREF
  PitCrew *v55; // [esp+DAh] [ebp-228h]
  std::wstring folder; // [esp+DEh] [ebp-224h] BYREF
  std::wstring section; // [esp+F6h] [ebp-20Ch] BYREF
  std::wstring v58; // [esp+10Eh] [ebp-1F4h] BYREF
  std::wstring v59; // [esp+126h] [ebp-1DCh] BYREF
  std::wstring v60; // [esp+13Eh] [ebp-1C4h] BYREF
  std::wstring v61; // [esp+156h] [ebp-1ACh] BYREF
  std::wstring v62; // [esp+16Eh] [ebp-194h] BYREF
  std::wstring v63; // [esp+186h] [ebp-17Ch] BYREF
  std::wstring v64; // [esp+19Eh] [ebp-164h] BYREF
  std::wstring ifilename; // [esp+1B6h] [ebp-14Ch] BYREF
  std::wstring key; // [esp+1CEh] [ebp-134h] BYREF
  INIReader ini; // [esp+1E6h] [ebp-11Ch] BYREF
  std::wstring crewskin; // [esp+22Ah] [ebp-D8h] BYREF
  INIReader iniS; // [esp+242h] [ebp-C0h] BYREF
  KN5IO kn; // [esp+286h] [ebp-7Ch] BYREF
  int v71; // [esp+2FEh] [ebp-4h]

  v4 = 0;
  v55 = this;
  *(_DWORD *)&_Arg[1] = 0;
  v46 = 0.0;
  v5 = aCar->sim;
  v71 = 0;
  *(_DWORD *)&aTimeToPosDefault[44] = v5->game;
  *(_DWORD *)&aTimeToPosDefault[40] = 7;
  *(_DWORD *)&aTimeToPosDefault[36] = 0;
  *(_WORD *)&aTimeToPosDefault[20] = 0;
  std::wstring::assign((std::wstring *)&aTimeToPosDefault[20], L"LOLLIPOP_CREW", 0xDu);
  GameObject::GameObject(this, *(std::wstring *)&aTimeToPosDefault[20], *(Game **)&aTimeToPosDefault[44]);
  this->__vftable = (PitCrew_vtbl *)&PitCrew::`vftable';
  this->pitcrews = 0;
  this->targetLolliPosition = 1.0;
  this->members._Myfirst = 0;
  this->members._Mylast = 0;
  this->members._Myend = 0;
  this->pitStop = 0;
  this->sim = aCar->sim;
  v6 = this->game;
  this->car = aCar;
  this->pitStopOn = 0;
  strcpy((char *)&this->animationSpeed, "���=");
  this->oldCameraMode = eCockpit;
  *(_DWORD *)&aTimeToPosDefault[44] = v6->graphics;
  LOBYTE(v71) = 2;
  KN5IO::KN5IO(&kn, *(GraphicsManager **)&aTimeToPosDefault[44]);
  LOBYTE(v71) = 3;
  std::operator+<wchar_t>(&crewskin, &skin, L"/skin.ini");
  LOBYTE(v71) = 4;
  HIBYTE(v45) = 1;
  if ( !Path::fileExists(0, &crewskin, 0) )
    goto LABEL_20;
  CarAvatar::openINI(this->car, &iniS, &crewskin);
  LOBYTE(v71) = 5;
  if ( iniS.ready )
  {
    std::wstring::wstring(&section, L"CREW");
    LOBYTE(v71) = 6;
    v7 = INIReader::hasSection(&iniS, &section);
    _Arg[0] = v7;
    LOBYTE(v71) = 5;
    if ( section._Myres >= 8 )
    {
      operator delete(section._Bx._Ptr);
      v7 = _Arg[0];
    }
    if ( v7 )
    {
      std::wstring::wstring(&section, L"SUIT");
      LOBYTE(v71) = 7;
      std::wstring::wstring(&folder, L"CREW");
      LOBYTE(v71) = 8;
      PitCrew::loadCrewSkin(this, &kn, &iniS, &folder, &section);
      if ( folder._Myres >= 8 )
        operator delete(folder._Bx._Ptr);
      folder._Myres = 7;
      folder._Mysize = 0;
      folder._Bx._Buf[0] = 0;
      LOBYTE(v71) = 5;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      std::wstring::wstring(&section, L"HELMET");
      LOBYTE(v71) = 9;
      std::wstring::wstring(&folder, L"CREW");
      LOBYTE(v71) = 10;
      PitCrew::loadCrewSkin(this, &kn, &iniS, &folder, &section);
      if ( folder._Myres >= 8 )
        operator delete(folder._Bx._Ptr);
      folder._Myres = 7;
      folder._Mysize = 0;
      folder._Bx._Buf[0] = 0;
      LOBYTE(v71) = 5;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      std::wstring::wstring(&section, L"BRAND");
      LOBYTE(v71) = 11;
      std::wstring::wstring(&folder, L"CREW");
      LOBYTE(v71) = 12;
      PitCrew::loadCrewSkin(this, &kn, &iniS, &folder, &section);
      if ( folder._Myres >= 8 )
        operator delete(folder._Bx._Ptr);
      folder._Myres = 7;
      folder._Mysize = 0;
      folder._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      HIBYTE(v45) = 0;
    }
  }
  LOBYTE(v71) = 4;
  INIReader::~INIReader(&iniS);
  if ( HIBYTE(v45) )
  {
LABEL_20:
    v8 = &skin;
    folder._Myres = 7;
    if ( skin._Myres >= 8 )
      v8 = (std::wstring *)skin._Bx._Ptr;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    if ( v8->_Bx._Buf[0] )
      v9 = wcslen(v8->_Bx._Buf);
    else
      v9 = 0;
    std::wstring::assign(&folder, v8->_Bx._Buf, v9);
    LOBYTE(v71) = 13;
    KN5IO::addTextureFolder(&kn, &folder);
    LOBYTE(v71) = 4;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
  }
  v10 = (PitCrew::{ctor}::__l30::<lambda_a281ae7dde51db8b02ffd1ae29fb0902> *)operator new(188);
  _Val = v10;
  v11 = 0;
  LOBYTE(v71) = 14;
  if ( v10 )
  {
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"PIT_CREWS", 9u);
    LOBYTE(v71) = 15;
    v4 = 1;
    *(_DWORD *)&_Arg[1] = 1;
    LODWORD(v46) = 1;
    Node::Node((Node *)v10, &folder);
  }
  this->pitcrews = v11;
  v71 = 4;
  if ( (v4 & 1) != 0 )
  {
    v4 &= 0xFFFFFFFE;
    *(_DWORD *)&_Arg[1] = v4;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
  }
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"content/objects3D/pitcrewtyre.ini", 0x21u);
  LOBYTE(v71) = 17;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v71) = 19;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( !ini.ready )
  {
    _printf("ERROR! Problems reading ini pitcrewtyre file\n");
    ksGenerateCrash();
  }
  this->isUsingAnimatedSuspension = __RTDynamicCast(
                                      this->car->suspensionAvatar,
                                      0,
                                      &ISuspensionAvatar `RTTI Type Descriptor',
                                      &SuspensionAnimator `RTTI Type Descriptor',
                                      0) != 0;
  v12 = (const __m128i *)this->car->physics;
  v13 = *(float *)_mm_loadu_si128(v12 + 739).m128i_i32;
  v60._Mysize = v12[740].m128i_u32[0];
  tyreMult = v13 * 0.1;
  v14 = wheels;
  _Val = (PitCrew::{ctor}::__l30::<lambda_a281ae7dde51db8b02ffd1ae29fb0902> *)std::forward<_lambda_b1b5a2018750bb2261f39e860a2780a3_>((AIDriver::{ctor}::__l57::<lambda_b1b5a2018750bb2261f39e860a2780a3> *)_Arg);
  v49 = wheels;
  v52 = 4;
  do
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"TIME_TO_FINISH", 0xEu);
    LOBYTE(v71) = 20;
    v63._Myres = 7;
    v63._Mysize = 0;
    v63._Bx._Buf[0] = 0;
    std::wstring::assign(&v63, L"ANIMATION", 9u);
    LOBYTE(v71) = 21;
    v62._Myres = 7;
    v62._Mysize = 0;
    v62._Bx._Buf[0] = 0;
    std::wstring::assign(&v62, L"TIME_TO_CHANGE_TYRE", 0x13u);
    LOBYTE(v71) = 22;
    v64._Myres = 7;
    v64._Mysize = 0;
    v64._Bx._Buf[0] = 0;
    std::wstring::assign(&v64, L"ANIMATION", 9u);
    LOBYTE(v71) = 23;
    v61._Myres = 7;
    v61._Mysize = 0;
    v61._Bx._Buf[0] = 0;
    std::wstring::assign(&v61, L"TIME_TO_POSITION", 0x10u);
    LOBYTE(v71) = 24;
    v60._Myres = 7;
    v60._Mysize = 0;
    v60._Bx._Buf[0] = 0;
    std::wstring::assign(&v60, L"ANIMATION", 9u);
    LOBYTE(v71) = 25;
    v15 = INIReader::getFloat(&ini, &v63, &key);
    *(float *)&aTimeToPosDefault[44] = v15 * tyreMult;
    v16 = INIReader::getFloat(&ini, &v64, &v62);
    *(float *)&aTimeToPosDefault[40] = v16 * tyreMult;
    v17 = INIReader::getFloat(&ini, &v60, &v61);
    *(float *)&aTimeToPosDefault[36] = v17 * tyreMult;
    PitCrew::CrewMember::CrewMember(
      &member,
      *(float *)&aTimeToPosDefault[36],
      *(float *)&aTimeToPosDefault[40],
      *(float *)&aTimeToPosDefault[44]);
    if ( v60._Myres >= 8 )
      operator delete(v60._Bx._Ptr);
    v60._Myres = 7;
    v60._Mysize = 0;
    v60._Bx._Buf[0] = 0;
    if ( v61._Myres >= 8 )
      operator delete(v61._Bx._Ptr);
    v61._Myres = 7;
    v61._Mysize = 0;
    v61._Bx._Buf[0] = 0;
    if ( v64._Myres >= 8 )
      operator delete(v64._Bx._Ptr);
    v64._Myres = 7;
    v64._Mysize = 0;
    v64._Bx._Buf[0] = 0;
    if ( v62._Myres >= 8 )
      operator delete(v62._Bx._Ptr);
    v62._Myres = 7;
    v62._Mysize = 0;
    v62._Bx._Buf[0] = 0;
    if ( v63._Myres >= 8 )
      operator delete(v63._Bx._Ptr);
    v63._Myres = 7;
    v63._Mysize = 0;
    v63._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"content/objects3D/pitcrewtyre.kn5", 0x21u);
    LOBYTE(v71) = 33;
    v18 = KN5IO::load(&kn, &folder);
    member.model = v18;
    LOBYTE(v71) = 32;
    if ( folder._Myres >= 8 )
    {
      operator delete(folder._Bx._Ptr);
      v18 = member.model;
    }
    v18->isActive = 0;
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"content/objects3D/pitcrewtyre.ksanim", 0x24u);
    LOBYTE(v71) = 34;
    Animation::load(&member.animation, &folder);
    LOBYTE(v71) = 32;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    v19 = (AnimationPlayer *)operator new(28);
    v46 = *(float *)&v19;
    LOBYTE(v71) = 35;
    if ( v19 )
      AnimationPlayer::AnimationPlayer(v19, &member.animation, member.model, eOnlyAnimated);
    else
      v20 = 0;
    member.player = v20;
    LOBYTE(v71) = 32;
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"CREW:TIRE_OLD_Center", 0x14u);
    LOBYTE(v71) = 36;
    member.oldTyreNull = member.model->findChildByName(member.model, &folder, 1);
    LOBYTE(v71) = 32;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"CREW:TIRE_NEW_Center", 0x14u);
    LOBYTE(v71) = 37;
    member.newTyreNull = member.model->findChildByName(member.model, &folder, 1);
    LOBYTE(v71) = 32;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"Position", 8u);
    LOBYTE(v71) = 38;
    member.defaultPosition = member.model->findChildByName(member.model, &folder, 1);
    LOBYTE(v71) = 32;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    v21 = (CarAudioFMOD *)operator new(48);
    v50.__this = v21;
    v22 = 0;
    LOBYTE(v71) = 39;
    if ( v21 )
    {
      folder._Myres = 7;
      folder._Mysize = 0;
      folder._Bx._Buf[0] = 0;
      std::wstring::assign(&folder, L"event:/common/screw", 0x13u);
      *(_DWORD *)&aTimeToPosDefault[44] = 0;
      LOBYTE(v71) = 40;
      *(_DWORD *)&aTimeToPosDefault[40] = &folder;
      v23 = this->game;
      v4 |= 2u;
      *(_DWORD *)&_Arg[1] = v4;
      v46 = *(float *)&v4;
      AudioEvent::AudioEvent((AudioEvent *)v21, v23->audioEngine, &folder, Off);
    }
    member.screwEvent = v22;
    v71 = 32;
    if ( (v4 & 2) != 0 )
    {
      v4 &= 0xFFFFFFFD;
      *(_DWORD *)&_Arg[1] = v4;
      if ( folder._Myres >= 8 )
        operator delete(folder._Bx._Ptr);
    }
    v24 = (CarAudioFMOD *)operator new(48);
    v50.__this = v24;
    v25 = 0;
    LOBYTE(v71) = 42;
    if ( v24 )
    {
      folder._Myres = 7;
      folder._Mysize = 0;
      folder._Bx._Buf[0] = 0;
      std::wstring::assign(&folder, L"event:/common/unscrew", 0x15u);
      *(_DWORD *)&aTimeToPosDefault[44] = 0;
      LOBYTE(v71) = 43;
      *(_DWORD *)&aTimeToPosDefault[40] = &folder;
      v26 = this->game;
      v4 |= 4u;
      *(_DWORD *)&_Arg[1] = v4;
      v46 = *(float *)&v4;
      AudioEvent::AudioEvent((AudioEvent *)v24, v26->audioEngine, &folder, Off);
    }
    member.unscrewEvent = v25;
    v71 = 32;
    if ( (v4 & 4) != 0 )
    {
      *(_DWORD *)&_Arg[1] = v4 & 0xFFFFFFFB;
      if ( folder._Myres >= 8 )
        operator delete(folder._Bx._Ptr);
    }
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"BEGIN_UNSCREW_FRAME", 0x13u);
    LOBYTE(v71) = 45;
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"ANIMATION", 9u);
    LOBYTE(v71) = 46;
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    std::wstring::assign(&v58, L"TOTAL_FRAMES", 0xCu);
    LOBYTE(v71) = 47;
    v59._Myres = 7;
    v59._Mysize = 0;
    v59._Bx._Buf[0] = 0;
    std::wstring::assign(&v59, L"ANIMATION", 9u);
    LOBYTE(v71) = 48;
    v46 = INIReader::getFloat(&ini, &folder, &section);
    v27 = INIReader::getFloat(&ini, &v59, &v58);
    member.percentageBeginUnScrew = v46 / v27;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    v59._Myres = 7;
    v59._Mysize = 0;
    v59._Bx._Buf[0] = 0;
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    v59._Myres = 7;
    v59._Mysize = 0;
    v59._Bx._Buf[0] = 0;
    std::wstring::assign(&v59, L"UNSCREW_FRAME", 0xDu);
    LOBYTE(v71) = 49;
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    std::wstring::assign(&v58, L"ANIMATION", 9u);
    LOBYTE(v71) = 50;
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    std::wstring::assign(&folder, L"TOTAL_FRAMES", 0xCu);
    LOBYTE(v71) = 51;
    std::wstring::wstring(&section, L"ANIMATION");
    LOBYTE(v71) = 52;
    v46 = INIReader::getFloat(&ini, &v58, &v59);
    v28 = INIReader::getFloat(&ini, &section, &folder);
    member.percentageUnScrew = v46 / v28;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    std::wstring::wstring(&v59, L"END_UNSCREW_FRAME");
    LOBYTE(v71) = 53;
    std::wstring::wstring(&v58, L"ANIMATION");
    LOBYTE(v71) = 54;
    std::wstring::wstring(&folder, L"TOTAL_FRAMES");
    LOBYTE(v71) = 55;
    std::wstring::wstring(&section, L"ANIMATION");
    LOBYTE(v71) = 56;
    v46 = INIReader::getFloat(&ini, &v58, &v59);
    v29 = INIReader::getFloat(&ini, &section, &folder);
    member.percentageEndUnScrew = v46 / v29;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    std::wstring::wstring(&v59, L"BEGIN_SCREW_FRAME");
    LOBYTE(v71) = 57;
    std::wstring::wstring(&v58, L"ANIMATION");
    LOBYTE(v71) = 58;
    std::wstring::wstring(&folder, L"TOTAL_FRAMES");
    LOBYTE(v71) = 59;
    std::wstring::wstring(&section, L"ANIMATION");
    LOBYTE(v71) = 60;
    v46 = INIReader::getFloat(&ini, &v58, &v59);
    v30 = INIReader::getFloat(&ini, &section, &folder);
    member.percentageBeginScrew = v46 / v30;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    std::wstring::wstring(&v59, L"SCREW_FRAME");
    LOBYTE(v71) = 61;
    std::wstring::wstring(&v58, L"ANIMATION");
    LOBYTE(v71) = 62;
    std::wstring::wstring(&folder, L"TOTAL_FRAMES");
    LOBYTE(v71) = 63;
    std::wstring::wstring(&section, L"ANIMATION");
    LOBYTE(v71) = 64;
    v46 = INIReader::getFloat(&ini, &v58, &v59);
    v31 = INIReader::getFloat(&ini, &section, &folder);
    member.percentageScrew = v46 / v31;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    std::wstring::wstring(&v59, L"END_SCREW_FRAME");
    LOBYTE(v71) = 65;
    std::wstring::wstring(&v58, L"ANIMATION");
    LOBYTE(v71) = 66;
    std::wstring::wstring(&folder, L"TOTAL_FRAMES");
    LOBYTE(v71) = 67;
    std::wstring::wstring(&section, L"ANIMATION");
    LOBYTE(v71) = 68;
    v46 = INIReader::getFloat(&ini, &v58, &v59);
    v32 = INIReader::getFloat(&ini, &section, &folder);
    member.percentageEndScrew = v46 / v32;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    folder._Myres = 7;
    folder._Mysize = 0;
    folder._Bx._Buf[0] = 0;
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    std::wstring::wstring(&folder, L"LOOP_SPEED_MULT");
    LOBYTE(v71) = 69;
    std::wstring::wstring(&section, L"ANIMATION");
    LOBYTE(v71) = 70;
    member.loopSpeedMult = INIReader::getFloat(&ini, &section, &folder);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v71) = 32;
    if ( folder._Myres >= 8 )
      operator delete(folder._Bx._Ptr);
    this->car->carNode->findChildrenByName(this->car->carNode, v14, &member.carWheels);
    v33 = member.carWheels._Myfirst;
    v34 = 0;
    v35 = (unsigned int)((char *)member.carWheels._Mylast - (char *)member.carWheels._Myfirst + 3) >> 2;
    if ( member.carWheels._Myfirst > member.carWheels._Mylast )
      v35 = 0;
    if ( v35 )
    {
      do
      {
        std::vector<mat44f>::push_back(&member.tyreOldTransforms, &(*v33)->matrix);
        ++v34;
        ++v33;
      }
      while ( v34 != v35 );
    }
    GraphicsManager::compile(this->game->graphics, member.model);
    this->pitcrews->addChild(this->pitcrews, member.model);
    SceneGraphCloner::SceneGraphCloner(&cloner);
    v36 = this->car;
    v37 = v49;
    *(_DWORD *)&aTimeToPosDefault[44] = 1;
    *(_DWORD *)&aTimeToPosDefault[40] = v49;
    v38 = v36->carNode;
    LOBYTE(v71) = 71;
    v39 = v38->findChildByName(v38, v49, 1);
    member.newTyreModel = SceneGraphCloner::cloneGraph(&cloner, v39);
    v40 = (const __m128i *)member.newTyreNull->getWorldMatrix(member.newTyreNull, &iniS);
    v41 = member.newTyreModel;
    v50.__this = (CarAudioFMOD *)&aTimeToPosDefault[24];
    v49 = (std::wstring *)&aTimeToPosDefault[24];
    *(__m128i *)&member.newTyreModel->matrix.M11 = _mm_loadu_si128(v40);
    *(__m128i *)&v41->matrix.M21 = _mm_loadu_si128(v40 + 1);
    *(__m128i *)&v41->matrix.M31 = _mm_loadu_si128(v40 + 2);
    *(__m128i *)&v41->matrix.M41 = _mm_loadu_si128(v40 + 3);
    *(_DWORD *)&aTimeToPosDefault[40] = 0;
    *(_DWORD *)&aTimeToPosDefault[20] = v41;
    LOBYTE(v71) = 72;
    std::allocator<std::_Func_class<void,SessionInfo const &>>::allocator<std::_Func_class<void,SessionInfo const &>>(
      (std::allocator<std::_Func_class<void,SessionInfo const &> > *)&aTimeToPosDefault[20],
      (const std::allocator<std::_Func_class<void,SessionInfo const &> > *)&v45 + 3);
    std::_Func_class<void,Node *>::_Do_alloc<std::_Func_impl<std::_Callable_obj<_lambda_a281ae7dde51db8b02ffd1ae29fb0902_,0>,std::allocator<std::_Func_class<void,Node *>>,void,Node *>,_lambda_a281ae7dde51db8b02ffd1ae29fb0902_,std::allocator<std::_Func_class<void,Node *>>>(
      (std::_Func_class<void,Node *> *)&aTimeToPosDefault[24],
      _Val,
      (std::allocator<std::_Func_class<void,Node *> >)aTimeToPosDefault[20]);
    LOBYTE(v71) = 73;
    std::function<bool __cdecl (Node *)>::function<bool __cdecl (Node *)>(
      (std::function<bool __cdecl(Node *)> *)aTimeToPosDefault,
      (PitCrew::{ctor}::__l29::<lambda_f6071ca18ff07b3dfb3ad84b4c9c54aa> *)&v45 + 3);
    LOBYTE(v71) = 71;
    Node::visit(
      member.newTyreModel,
      *(std::function<bool __cdecl(Node *)> *)aTimeToPosDefault,
      *(std::function<void __cdecl(Node *)> *)&aTimeToPosDefault[24]);
    Node::setActive(member.newTyreModel, 0);
    GraphicsManager::compile(this->game->graphics, member.newTyreModel);
    this->sim->blurredNode->addChild(this->sim->blurredNode, member.newTyreModel);
    std::vector<PitCrew::CrewMember>::push_back(&this->members, &member);
    LOBYTE(v71) = 32;
    SceneGraphCloner::~SceneGraphCloner(&cloner);
    LOBYTE(v71) = 19;
    PitCrew::CrewMember::~CrewMember(&member);
    v4 = *(_DWORD *)&_Arg[1];
    v14 = v37 + 1;
    v42 = v52-- == 1;
    v49 = (std::wstring *)v14;
  }
  while ( !v42 );
  *(_DWORD *)&aTimeToPosDefault[44] = this;
  CommandItem::CommandItem(&v50, (CarAudioFMOD *)this);
  std::function<void __cdecl (OnReplayStatusChanged const &)>::function<void __cdecl (OnReplayStatusChanged const &)>(
    (std::function<void __cdecl(OnReplayStatusChanged const &)> *)&aTimeToPosDefault[20],
    v43);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->sim->evOnReplayStatusChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&aTimeToPosDefault[20],
    *(void **)&aTimeToPosDefault[44]);
  LOBYTE(v71) = 4;
  INIReader::~INIReader(&ini);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&crewskin);
  LOBYTE(v71) = 2;
  KN5IO::~KN5IO(&kn);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&skin);
}
void PitCrew::~PitCrew(PitCrew *this)
{
  PitCrew *v1; // ebx
  PitCrew::CrewMember *v2; // edi
  std::vector<PitCrew::CrewMember> *v3; // ebp
  PitCrew::CrewMember *v4; // esi
  AnimationPlayer *v5; // ebx
  AudioEvent *v6; // ebx
  AudioEvent *v7; // ebx

  v1 = this;
  this->__vftable = (PitCrew_vtbl *)&PitCrew::`vftable';
  v2 = this->members._Mylast;
  v3 = &this->members;
  v4 = this->members._Myfirst;
  if ( v4 != v2 )
  {
    do
    {
      v5 = v4->player;
      if ( v5 )
      {
        std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v4->player);
        operator delete(v5);
      }
      v6 = v4->screwEvent;
      if ( v6 )
      {
        AudioEvent::~AudioEvent(v4->screwEvent);
        operator delete(v6);
      }
      v7 = v4->unscrewEvent;
      if ( v7 )
      {
        AudioEvent::~AudioEvent(v4->unscrewEvent);
        operator delete(v7);
      }
      ++v4;
    }
    while ( v4 != v2 );
    v1 = this;
  }
  if ( v3->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v3);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<PitCrew::CrewMember>>>(v3->_Myfirst, v3->_Mylast);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  GameObject::~GameObject(v1);
}
PitCrew *PitCrew::`vector deleting destructor'(PitCrew *this, unsigned int a2)
{
  PitCrew::~PitCrew(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PitCrew::loadCrewSkin(PitCrew *this, KN5IO *kn, INIReader *iniS, const std::wstring *section, const std::wstring *key)
{
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // esi
  std::wstring *v8; // eax
  KN5IO_vtbl *v9; // eax
  int v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  KN5IO_vtbl *v13; // eax
  std::wstring iniSkin; // [esp+14h] [ebp-70h] BYREF
  std::wstring v15; // [esp+2Ch] [ebp-58h] BYREF
  std::wstring nm; // [esp+44h] [ebp-40h] BYREF
  std::wstring result; // [esp+5Ch] [ebp-28h] BYREF
  int v18; // [esp+80h] [ebp-4h]

  iniSkin._Myres = 7;
  iniSkin._Mysize = 0;
  iniSkin._Bx._Buf[0] = 0;
  v18 = 0;
  if ( INIReader::hasKey(iniS, section, key) )
  {
    v5 = INIReader::getString(iniS, &result, section, key);
    LOBYTE(v18) = 1;
    v6 = std::operator+<wchar_t>(&v15, L"content/texture/crew_", key);
    LOBYTE(v18) = 2;
    v7 = std::operator+<wchar_t>(&nm, v6, v5);
    if ( &iniSkin != v7 )
    {
      iniSkin._Myres = 7;
      iniSkin._Mysize = 0;
      iniSkin._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&iniSkin, v7);
    }
    if ( nm._Myres >= 8 )
      operator delete(nm._Bx._Ptr);
    nm._Myres = 7;
    nm._Mysize = 0;
    nm._Bx._Buf[0] = 0;
    if ( v15._Myres >= 8 )
      operator delete(v15._Bx._Ptr);
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( Path::folderExists(&iniSkin) )
    {
      v8 = &iniSkin;
      if ( iniSkin._Myres >= 8 )
        v8 = (std::wstring *)iniSkin._Bx._Ptr;
      std::wstring::wstring(&v15, v8->_Bx._Buf);
      v9 = kn->__vftable;
      LOBYTE(v18) = 3;
      v9->addTextureFolder(kn, &v15);
      LOBYTE(v18) = 0;
      if ( v15._Myres >= 8 )
        operator delete(v15._Bx._Ptr);
    }
    v10 = std::wstring::find_last_of(&iniSkin, L"\\", 0xFFFFFFFF, 1u);
    if ( v10 >= 0 )
    {
      v11 = std::wstring::substr(&iniSkin, &v15, 0, v10 + 1);
      LOBYTE(v18) = 4;
      std::operator+<wchar_t>(&nm, v11, L"_nm");
      LOBYTE(v18) = 6;
      if ( v15._Myres >= 8 )
        operator delete(v15._Bx._Ptr);
      v15._Myres = 7;
      v15._Bx._Buf[0] = 0;
      v15._Mysize = 0;
      if ( Path::folderExists(&nm) )
      {
        v12 = &nm;
        if ( nm._Myres >= 8 )
          v12 = (std::wstring *)nm._Bx._Ptr;
        std::wstring::wstring(&result, v12->_Bx._Buf);
        v13 = kn->__vftable;
        LOBYTE(v18) = 7;
        v13->addTextureFolder(kn, &result);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
      if ( nm._Myres >= 8 )
        operator delete(nm._Bx._Ptr);
    }
  }
  if ( iniSkin._Myres >= 8 )
    operator delete(iniSkin._Bx._Ptr);
}
void PitCrew::onPitStopBegin(PitCrew *this, const PitStopStart *message)
{
  Sim *v3; // ecx
  PitCrew::CrewMember *v4; // edi
  PitCrew::CrewMember *i; // esi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  PitCrew *v9; // esi
  int v10; // edi
  PitCrew::CrewMember *v11; // ecx
  unsigned int v12; // edx
  PitCrew::CrewMember *v13; // ecx
  Node *v14; // edx
  __m128i *v15; // eax
  __m128i v16; // xmm0
  __m128i v17; // xmm0
  PitCrew::CrewMember *v18; // ecx
  Node *v19; // eax
  PitCrew::CrewMember *v20; // eax
  Node *v21; // esi
  int *v22; // eax
  float v23; // xmm0_4
  Node_vtbl *v24; // eax
  float *v25; // eax
  float v26; // xmm3_4
  float v27; // xmm5_4
  int v28; // ecx
  CarAvatar *v29; // edx
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm1_4
  PitCrew::CrewMember *v33; // eax
  Node *v34; // ecx
  float v35; // xmm4_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm5_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float *v45; // eax
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float *v50; // eax
  Node *v51; // ecx
  float v52; // xmm4_4
  float v53; // xmm3_4
  float v54; // xmm5_4
  float v55; // xmm1_4
  PitCrew::CrewMember *v56; // eax
  Node *v57; // eax
  float v58; // xmm7_4
  float v59; // xmm3_4
  Node *v60; // edx
  float v61; // xmm5_4
  float v62; // xmm4_4
  float v63; // xmm3_4
  float v64; // xmm1_4
  float v65; // xmm1_4
  float v66; // xmm1_4
  float v67; // xmm1_4
  CarAvatar *v68; // eax
  float v69; // xmm4_4
  float v70; // xmm2_4
  float v71; // xmm1_4
  float v72; // xmm0_4
  float *v73; // eax
  PitCrew::CrewMember *v74; // esi
  const __m128i *v75; // eax
  __m128i *v76; // ecx
  PitCrew::CrewMember *v77; // eax
  Node *v78; // eax
  char v79[52]; // [esp+1Ch] [ebp-98h] BYREF
  __m128i v80; // [esp+50h] [ebp-64h] BYREF
  __int128 v81; // [esp+60h] [ebp-54h] BYREF
  __int128 v82; // [esp+70h] [ebp-44h] BYREF
  __int128 v83; // [esp+80h] [ebp-34h] BYREF
  int v84; // [esp+9Ch] [ebp-18h]
  PitCrew *v85; // [esp+A0h] [ebp-14h]
  float v86; // [esp+A4h] [ebp-10h]
  unsigned int v87; // [esp+A8h] [ebp-Ch]
  float v88; // [esp+ACh] [ebp-8h]
  float v89; // [esp+B0h] [ebp-4h]
  unsigned int messagea; // [esp+B8h] [ebp+4h]

  v85 = this;
  _printf("Starting Pit animation\n");
  v3 = this->sim;
  this->pitStopOn = 1;
  this->oldCameraMode = v3->cameraManager->mode;
  if ( !v3->isVrConnected && message->forceChangeCamera )
  {
    ACCameraManager::setMode(v3->cameraManager, eOnBoardFree, 0, 0);
    CameraOnBoardFree::forceThetaPhi(this->sim->cameraManager->cameraOnBoardFree, 0.1, 0.1, 5.0);
    this->sim->cameraManager->cameraOnBoardFree->lockCamera = 1;
  }
  v4 = this->members._Mylast;
  for ( i = this->members._Myfirst; i != v4; ++i )
  {
    i->timer = 0.0;
    i->timeToPosition = (float)((float)((float)_rand() * 0.000030518509) * 0.5) + (float)i->timeToPositionDefault;
    i->timeToChangeTyre = (float)i->timeToChangeTyreDefault + (float)((float)_rand() * 0.000030518509);
    v6 = (float)((float)((float)_rand() * 0.000030518509) * 0.5) + (float)i->timeToFinishDefault;
    i->timeToFinish = v6;
    v7 = (float)((float)(message->tyreChangeTime - i->timeToPosition) - i->timeToChangeTyre) - v6;
    v8 = FLOAT_9999_0;
    if ( v7 > 9999.0 || (v8 = 0.0, v7 < 0.0) )
      v7 = v8;
    i->state = GoingToPosition;
    i->timeScrew = v7 * 0.5;
  }
  v9 = v85;
  v10 = 0;
  v84 = 0;
  v87 = 0;
  messagea = 1020;
  do
  {
    v11 = v9->members._Myfirst;
    *(float *)&v12 = 0.0;
    v88 = 0.0;
    if ( v11[v10].carWheels._Mylast - v11[v10].carWheels._Myfirst )
    {
      v89 = 0.0;
      do
      {
        v13 = v9->members._Myfirst;
        v14 = v13[v10].carWheels._Myfirst[v12];
        v15 = (__m128i *)((char *)v13[v10].tyreOldTransforms._Myfirst + LODWORD(v89));
        v16 = _mm_loadu_si128((const __m128i *)&v14->matrix);
        LODWORD(v89) += 64;
        *v15 = v16;
        v15[1] = _mm_loadu_si128((const __m128i *)&v14->matrix.M21);
        v15[2] = _mm_loadu_si128((const __m128i *)&v14->matrix.M31);
        v17 = _mm_loadu_si128((const __m128i *)&v14->matrix.M41);
        v12 = LODWORD(v88) + 1;
        v15[3] = v17;
        v18 = v9->members._Myfirst;
        v88 = *(float *)&v12;
      }
      while ( v12 < v18[v10].carWheels._Mylast - v18[v10].carWheels._Myfirst );
    }
    v19 = v9->members._Myfirst[v10].model;
    v19->matrix.M11 = 1.0;
    v19->matrix.M12 = 0.0;
    v19->matrix.M13 = 0.0;
    v19->matrix.M14 = 0.0;
    v19->matrix.M21 = 0.0;
    v19->matrix.M22 = 1.0;
    v19->matrix.M23 = 0.0;
    v19->matrix.M24 = 0.0;
    v19->matrix.M31 = 0.0;
    v19->matrix.M32 = 0.0;
    v19->matrix.M33 = 1.0;
    v19->matrix.M34 = 0.0;
    v19->matrix.M41 = 0.0;
    v19->matrix.M42 = 0.0;
    v19->matrix.M43 = 0.0;
    v19->matrix.M44 = 1.0;
    v20 = v9->members._Myfirst;
    v21 = v20[v10].model;
    v22 = (int *)v20[v10].defaultPosition->getWorldMatrix(
                   v20[v10].defaultPosition,
                   (mat44f *)((char *)&v80.m128i_u64[1] + 4));
    v89 = *((float *)v22 + 12);
    v88 = *((float *)v22 + 13);
    v23 = *((float *)v22 + 14);
    v24 = v21->__vftable;
    v86 = v23;
    v25 = (float *)v24->getWorldMatrix(v21, (mat44f *)v79);
    v26 = (float)((float)((float)(v25[13] - v88) * (float)(v25[13] - v88))
                + (float)((float)(v25[12] - v89) * (float)(v25[12] - v89)))
        + (float)((float)(v25[14] - v86) * (float)(v25[14] - v86));
    if ( v26 == 0.0 )
      v88 = 0.0;
    else
      v88 = fsqrt(v26);
    v9 = v85;
    v27 = 0.0;
    v28 = v87;
    v29 = v85->car;
    v30 = v29->physicsState.tyreMatrix[v87 / 0x40].M11;
    v31 = v29->physicsState.tyreMatrix[v87 / 0x40].M13;
    v32 = fsqrt((float)(v31 * v31) + (float)(v30 * v30));
    if ( v32 != 0.0 )
    {
      v30 = v30 * (float)(1.0 / v32);
      v27 = (float)(1.0 / v32) * 0.0;
      v31 = v31 * (float)(1.0 / v32);
    }
    v33 = v85->members._Myfirst;
    if ( (v84 & 1) != 0 )
    {
      v34 = v33[v10].model;
      LODWORD(v35) = LODWORD(v31) ^ _xmm;
      LODWORD(v89) = LODWORD(v27) ^ _xmm;
      LODWORD(v36) = LODWORD(v30) ^ _xmm;
      v37 = COERCE_FLOAT(LODWORD(v27) ^ _xmm) * 0.0;
      v38 = v36 - v37;
      v39 = v37 - v35;
      v40 = (float)(v35 * 0.0) - (float)(v36 * 0.0);
      v41 = fsqrt((float)((float)(v40 * v40) + (float)(v39 * v39)) + (float)(v38 * v38));
      if ( v41 != 0.0 )
      {
        v39 = v39 * (float)(1.0 / v41);
        v40 = v40 * (float)(1.0 / v41);
        v38 = v38 * (float)(1.0 / v41);
      }
      v34->matrix.M21 = 0.0;
      v34->matrix.M22 = 1.0;
      LODWORD(v34->matrix.M31) = LODWORD(v36) ^ _xmm;
      LODWORD(v42) = LODWORD(v89) ^ _xmm;
      v34->matrix.M23 = 0.0;
      v34->matrix.M32 = v42;
      v34->matrix.M11 = v39;
      v43 = v88;
      LODWORD(v34->matrix.M33) = LODWORD(v35) ^ _xmm;
      v44 = v89;
      v34->matrix.M12 = v40;
      v34->matrix.M13 = v38;
      v45 = (float *)((char *)v9->car + messagea * 2);
      v46 = v35 * v43;
      v47 = *v45 + (float)(v36 * v43);
      v48 = v45[1] + (float)(v44 * v43);
      v49 = v45[2] + v46;
      v50 = (float *)v9->members._Myfirst[v10].model;
      v50[13] = v47;
      v50[14] = v48;
      v50[15] = v49;
      v51 = v9->members._Myfirst[v10].newTyreNull;
      v51->getWorldMatrix(v51, (mat44f *)((char *)&v80.m128i_u64[1] + 4));
      v89 = *((float *)&v83 + 1);
      v52 = (float)(*((float *)&v82 + 1) * *(float *)&v83) - (float)(*(float *)&v82 * *((float *)&v83 + 1));
      v53 = (float)(*(float *)&v82 * *((float *)&v82 + 3)) - (float)(*((float *)&v81 + 3) * *(float *)&v83);
      v54 = (float)(*((float *)&v81 + 3) * *((float *)&v83 + 1)) - (float)(*((float *)&v82 + 1) * *((float *)&v82 + 3));
      v55 = fsqrt((float)((float)(v54 * v54) + (float)(v52 * v52)) + (float)(v53 * v53));
      if ( v55 != 0.0 )
      {
        v52 = v52 * (float)(1.0 / v55);
        v54 = v54 * (float)(1.0 / v55);
        v53 = v53 * (float)(1.0 / v55);
      }
      v56 = v9->members._Myfirst;
      HIDWORD(v82) ^= _xmm;
      DWORD1(v83) = LODWORD(v89) ^ _xmm;
      LODWORD(v83) = v83 ^ _xmm;
      *(float *)&v80.m128i_i32[3] = v52;
      *(_QWORD *)&v81 = __PAIR64__(LODWORD(v53), LODWORD(v54));
      v57 = v56[v10].newTyreModel;
      *(__m128i *)&v57->matrix.M11 = _mm_loadu_si128((const __m128i *)&v80.m128i_i8[12]);
      *(__m128i *)&v57->matrix.M21 = _mm_loadu_si128((const __m128i *)((char *)&v81 + 12));
      *(__m128i *)&v57->matrix.M31 = _mm_loadu_si128((const __m128i *)((char *)&v82 + 12));
      *(__m128i *)&v57->matrix.M41 = _mm_loadu_si128((const __m128i *)((char *)&v83 + 12));
    }
    else
    {
      v58 = v29->physicsState.tyreMatrix[v87 / 0x40].M11;
      v59 = v29->physicsState.tyreMatrix[v87 / 0x40].M13;
      v86 = v29->physicsState.tyreMatrix[v87 / 0x40].M12;
      v60 = v33[v10].model;
      v89 = v59;
      v61 = v58 - (float)(v86 * 0.0);
      v62 = (float)(v86 * 0.0) - v59;
      v63 = (float)(v59 * 0.0) - (float)(v58 * 0.0);
      v64 = fsqrt((float)((float)(v63 * v63) + (float)(v62 * v62)) + (float)(v61 * v61));
      if ( v64 != 0.0 )
      {
        v62 = v62 * (float)(1.0 / v64);
        v63 = v63 * (float)(1.0 / v64);
        v61 = v61 * (float)(1.0 / v64);
      }
      LODWORD(v65) = LODWORD(v86) ^ _xmm;
      v60->matrix.M11 = v62;
      v60->matrix.M32 = v65;
      v66 = v89;
      v60->matrix.M12 = v63;
      LODWORD(v60->matrix.M33) = LODWORD(v66) ^ _xmm;
      v67 = v88;
      LODWORD(v60->matrix.M31) = LODWORD(v58) ^ _xmm;
      v60->matrix.M21 = 0.0;
      v60->matrix.M22 = 1.0;
      v60->matrix.M23 = 0.0;
      v60->matrix.M13 = v61;
      v68 = v9->car;
      v69 = *(float *)((char *)&v68->physicsState.tyreMatrix[0].M13 + v28) * v67;
      v70 = *(float *)((char *)&v68->__vftable + messagea * 2)
          + (float)(*(float *)((char *)&v68->physicsState.tyreMatrix[0].M11 + v28) * v67);
      v71 = *(float *)((char *)&v68->game + messagea * 2)
          + (float)(*(float *)((char *)&v68->physicsState.tyreMatrix[0].M12 + v28) * v67);
      v72 = *(float *)&v68->name._Bx._Buf[messagea] + v69;
      v73 = (float *)v9->members._Myfirst[v10].model;
      v73[13] = v70;
      v73[14] = v71;
      v73[15] = v72;
      v74 = v9->members._Myfirst;
      v75 = (const __m128i *)v74[v10].newTyreNull->getWorldMatrix(v74[v10].newTyreNull, (mat44f *)v79);
      v76 = (__m128i *)v74[v10].newTyreModel;
      v9 = v85;
      v76 = (__m128i *)((char *)v76 + 4);
      *v76 = _mm_loadu_si128(v75);
      v76[1] = _mm_loadu_si128(v75 + 1);
      v76[2] = _mm_loadu_si128(v75 + 2);
      v76[3] = _mm_loadu_si128(v75 + 3);
    }
    AnimationPlayer::setCurrentPos(v9->members._Myfirst[v10].player, 0.0, COERCE_FLOAT(1));
    v77 = v9->members._Myfirst;
    ++v84;
    v87 += 64;
    messagea += 6;
    v77[v10].model->isActive = 1;
    v78 = v9->members._Myfirst[v10++].newTyreModel;
    v78->isActive = 1;
  }
  while ( messagea < 1044 );
}
void PitCrew::onPitStopFinished(PitCrew *this)
{
  Sim *v2; // eax
  int v3; // edi
  char v4; // cl
  Node *v5; // ecx
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  PitCrew::CrewMember *v11; // eax
  Node *v12; // eax
  PitCrew::CrewMember *v13; // esi
  const __m128i *v14; // eax
  Node *v15; // ecx
  unsigned int v16; // edx
  int v17; // esi
  PitCrew::CrewMember *v18; // eax
  const __m128i *v19; // ecx
  Node *v20; // eax
  unsigned int v21; // [esp+18h] [ebp-48h]
  __m128i v22; // [esp+1Ch] [ebp-44h] BYREF
  __m128i v23; // [esp+2Ch] [ebp-34h] BYREF
  __m128i v24; // [esp+3Ch] [ebp-24h] BYREF
  __m128i v25; // [esp+4Ch] [ebp-14h] BYREF

  v21 = 0;
  v2 = this->sim;
  this->pitStopOn = 0;
  v2->cameraManager->cameraOnBoardFree->lockCamera = 0;
  if ( this->members._Mylast - this->members._Myfirst )
  {
    v3 = 0;
    v4 = 0;
    do
    {
      if ( (v4 & 1) != 0 )
      {
        v5 = this->members._Myfirst[v3].oldTyreNull;
        v5->getWorldMatrix(v5, (mat44f *)((char *)v22.m128i_i64 + 4));
        v6 = (float)(*(float *)&v24.m128i_i32[2] * *(float *)&v23.m128i_i32[3])
           - (float)(*(float *)&v24.m128i_i32[3] * *(float *)&v23.m128i_i32[2]);
        v7 = (float)(*(float *)&v24.m128i_i32[3] * *(float *)&v23.m128i_i32[1])
           - (float)(*(float *)&v24.m128i_i32[1] * *(float *)&v23.m128i_i32[3]);
        v8 = (float)(*(float *)&v24.m128i_i32[1] * *(float *)&v23.m128i_i32[2])
           - (float)(*(float *)&v24.m128i_i32[2] * *(float *)&v23.m128i_i32[1]);
        v9 = fsqrt((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8));
        if ( v9 != 0.0 )
        {
          v10 = 1.0 / v9;
          v6 = v6 * v10;
          v7 = v7 * v10;
          v8 = v10 * v8;
        }
        v11 = this->members._Myfirst;
        v24.m128i_i32[1] ^= _xmm;
        v24.m128i_i32[3] ^= _xmm;
        v24.m128i_i32[2] ^= _xmm;
        *(__int64 *)((char *)v22.m128i_i64 + 4) = __PAIR64__(LODWORD(v7), LODWORD(v6));
        *(float *)&v22.m128i_i32[3] = v8;
        v12 = v11[v3].newTyreModel;
        *(__m128i *)&v12->matrix.M11 = _mm_loadu_si128((const __m128i *)&v22.m128i_i8[4]);
        *(__m128i *)&v12->matrix.M21 = _mm_loadu_si128((const __m128i *)&v23.m128i_i8[4]);
        *(__m128i *)&v12->matrix.M31 = _mm_loadu_si128((const __m128i *)&v24.m128i_i8[4]);
        *(__m128i *)&v12->matrix.M41 = _mm_loadu_si128((const __m128i *)&v25.m128i_i8[4]);
      }
      else
      {
        v13 = this->members._Myfirst;
        v14 = (const __m128i *)v13[v3].oldTyreNull->getWorldMatrix(
                                 v13[v3].oldTyreNull,
                                 (mat44f *)((char *)v22.m128i_i64 + 4));
        v15 = v13[v3].newTyreModel;
        *(__m128i *)&v15->matrix.M11 = _mm_loadu_si128(v14);
        *(__m128i *)&v15->matrix.M21 = _mm_loadu_si128(v14 + 1);
        *(__m128i *)&v15->matrix.M31 = _mm_loadu_si128(v14 + 2);
        *(__m128i *)&v15->matrix.M41 = _mm_loadu_si128(v14 + 3);
      }
      v16 = 0;
      if ( this->members._Myfirst[v3].carWheels._Mylast - this->members._Myfirst[v3].carWheels._Myfirst )
      {
        v17 = 0;
        do
        {
          v18 = this->members._Myfirst;
          v19 = (const __m128i *)&v18[v3].tyreOldTransforms._Myfirst[v17++];
          v20 = v18[v3].carWheels._Myfirst[v16++];
          *(__m128i *)&v20->matrix.M11 = _mm_loadu_si128(v19);
          *(__m128i *)&v20->matrix.M21 = _mm_loadu_si128(v19 + 1);
          *(__m128i *)&v20->matrix.M31 = _mm_loadu_si128(v19 + 2);
          *(__m128i *)&v20->matrix.M41 = _mm_loadu_si128(v19 + 3);
        }
        while ( v16 < this->members._Myfirst[v3].carWheels._Mylast - this->members._Myfirst[v3].carWheels._Myfirst );
      }
      AnimationPlayer::setCurrentPos(this->members._Myfirst[v3++].player, 1.0, COERCE_FLOAT(1));
      v4 = ++v21;
    }
    while ( v21 < this->members._Mylast - this->members._Myfirst );
  }
}
void PitCrew::onPitStopIdle(PitCrew *this)
{
  unsigned int v1; // ebx
  int v2; // edi

  v1 = 0;
  if ( this->members._Mylast - this->members._Myfirst )
  {
    v2 = 0;
    do
    {
      ++v2;
      ++v1;
      this->members._Myfirst[v2 - 1].newTyreModel->isActive = 0;
      this->members._Myfirst[v2 - 1].model->isActive = 0;
    }
    while ( v1 < this->members._Mylast - this->members._Myfirst );
  }
}
void PitCrew::pitCrewUpdate(PitCrew *this, float dt)
{
  PitStop *v3; // eax
  Event<SessionInfo> *v4; // ecx
  Event<bool> *v5; // ecx
  Sim *v6; // ecx
  std::function<void __cdecl(SessionInfo const &)> v7; // [esp-18h] [ebp-3Ch] BYREF
  float v8; // [esp+0h] [ebp-24h]
  int v9; // [esp+20h] [ebp-4h]

  if ( !ReplayManager::isInReplaymode(this->sim->replayManager) )
  {
    if ( !this->pitStop )
    {
      v3 = GameObject::getGameObject<PitStop>(this->sim);
      LODWORD(v8) = this;
      this->pitStop = v3;
      v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_02055456cd06d39816b125e75a09a4d9_,0>,std::allocator<std::_Func_class<void,PitStopStart const &>>,void,PitStopStart const &>::`vftable';
      v7._Space._Pfn[1] = (void (__cdecl *)())this;
      v7._Impl = (std::_Func_base<void,SessionInfo const &> *)&v7;
      v4 = (Event<SessionInfo> *)&this->pitStop->evPitStopCommit;
      v9 = -1;
      Event<float>::addHandler(v4, v7, (void *)LODWORD(v8));
      LODWORD(v8) = this;
      v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_5128a3a68e2cfaadecd5aaef50b8a656_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
      v7._Space._Pfn[1] = (void (__cdecl *)())this;
      v7._Impl = (std::_Func_base<void,SessionInfo const &> *)&v7;
      v5 = &this->pitStop->evPitStopOver;
      v9 = -1;
      Event<std::wstring>::addHandler(
        (Event<OnPhysicsStepCompleted> *)v5,
        (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v7,
        this);
    }
    v6 = this->sim;
    if ( !v6->pauseMenu->visible
      && (RaceManager::getCurrentSessionType(v6->raceManager) == Race
       || RaceManager::getCurrentSessionType(this->sim->raceManager) == Qualify
       || RaceManager::getCurrentSessionType(this->sim->raceManager) == Pratice)
      && !this->sim->pauseMenu->visible )
    {
      switch ( this->pitStop->state )
      {
        case Idle:
          if ( !this->car->physicsState.tyreSurfaceDef[0].isPitlane )
            PitCrew::onPitStopIdle(this);
          goto $LN4_14;
        case ChangingTyre:
          if ( this->pitStopOn )
            PitCrew::updateCurrentPosition(this, dt);
          break;
        case ScrewingTyre:
          if ( this->pitStopOn )
            PitCrew::onPitStopFinished(this);
          break;
        case Finishing:
$LN4_14:
          if ( this->pitStopOn )
          {
            PitCrew::reset(this);
            ACCameraManager::setMode(this->sim->cameraManager, this->oldCameraMode, 1, 0);
          }
          break;
        default:
          return;
      }
    }
  }
}
void PitCrew::reset(PitCrew *this)
{
  PitCrew::CrewMember *v2; // edx
  PitCrew::CrewMember *i; // eax
  Node *v4; // ecx
  Sim *v5; // edi
  GameObject **v6; // esi
  int v7; // eax

  PitCrew::onPitStopFinished(this);
  v2 = this->members._Mylast;
  for ( i = this->members._Myfirst; i != v2; v4->isActive = 0 )
  {
    i->model->isActive = 0;
    v4 = i->newTyreModel;
    ++i;
  }
  if ( !this->pitStop )
  {
    v5 = this->sim;
    v6 = v5->gameObjects._Myfirst;
    if ( v6 == v5->gameObjects._Mylast )
    {
LABEL_7:
      v7 = 0;
    }
    else
    {
      while ( 1 )
      {
        v7 = __RTDynamicCast(*v6, 0, &GameObject `RTTI Type Descriptor', &PitStop `RTTI Type Descriptor', 0);
        if ( v7 )
          break;
        if ( ++v6 == v5->gameObjects._Mylast )
          goto LABEL_7;
      }
    }
    this->pitStop = (PitStop *)v7;
    *(_DWORD *)(v7 + 180) = 5;
  }
}
void PitCrew::updateCurrentPosition(PitCrew *this, float dt)
{
  PitCrew *v2; // esi
  float v3; // xmm3_4
  int v4; // edi
  float v5; // xmm2_4
  PitCrew::CrewMember *v6; // eax
  PitCrew::CrewMember *v7; // ecx
  float p; // xmm4_4
  float v9; // xmm0_4
  PitCrew::CrewMember *v10; // eax
  unsigned int v11; // esi
  const mat44f *v12; // eax
  PitCrew::CrewMember *v13; // ecx
  unsigned int v14; // esi
  bool v15; // zf
  AudioEvent *v16; // ecx
  int v17; // ecx
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm1_4
  PitCrew::CrewMember *v22; // esi
  int v23; // edi
  int i; // esi
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 *v29; // eax
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128i v32; // xmm3
  int v33; // edi
  int v34; // ecx
  const __m128i *v35; // eax
  float v36; // xmm1_4
  float v37; // xmm5_4
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm6_4
  float v41; // xmm7_4
  float v42; // xmm1_4
  PitCrew::CrewMember *v43; // eax
  int v44; // eax
  float v45; // xmm0_4
  PitCrew::CrewMember *v46; // eax
  unsigned int v47; // esi
  const mat44f *v48; // eax
  PitCrew::CrewMember *v49; // ecx
  unsigned int v50; // esi
  PitCrew::CrewMember *v51; // esi
  int v52; // ecx
  int *v53; // edi
  int *j; // esi
  int v55; // ecx
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm3
  __m128 v59; // xmm0
  int v60; // eax
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  __m128i v63; // xmm3
  __m128 v64; // xmm0
  PitCrew::CrewMember *v65; // esi
  const __m128i *v66; // eax
  int v67; // ecx
  __m128 *v69; // [esp+14h] [ebp-1A4h]
  int v70; // [esp+14h] [ebp-1A4h]
  float v71; // [esp+18h] [ebp-1A0h]
  __int64 v72; // [esp+1Ch] [ebp-19Ch]
  unsigned int v73; // [esp+24h] [ebp-194h]
  __m128 v74; // [esp+28h] [ebp-190h] BYREF
  __m128 v75; // [esp+38h] [ebp-180h] BYREF
  __m128 v76; // [esp+48h] [ebp-170h] BYREF
  __m128i v77; // [esp+58h] [ebp-160h] BYREF
  vec3f velocity; // [esp+70h] [ebp-148h] BYREF
  char v79[28]; // [esp+7Ch] [ebp-13Ch] BYREF
  __m128 v80; // [esp+98h] [ebp-120h] BYREF
  __m128 v81; // [esp+A8h] [ebp-110h]
  __m128 v82; // [esp+B8h] [ebp-100h]
  __m128 v83; // [esp+C8h] [ebp-F0h]
  __int128 v84; // [esp+D8h] [ebp-E0h] BYREF
  __int128 v85; // [esp+E8h] [ebp-D0h]
  __int128 v86; // [esp+F8h] [ebp-C0h]
  __int128 v87; // [esp+108h] [ebp-B0h]
  __m128 M2_8[3]; // [esp+118h] [ebp-A0h] BYREF
  __m128 M2_56; // [esp+148h] [ebp-70h]
  DirectX::XMMATRIX v90; // [esp+158h] [ebp-60h] BYREF
  __m128 v91; // [esp+198h] [ebp-20h] BYREF
  __m128 pDeterminant; // [esp+1A8h] [ebp-10h] BYREF

  v2 = this;
  v73 = 0;
  if ( this->members._Mylast - this->members._Myfirst )
  {
    v3 = FLOAT_1_0;
    v4 = 0;
    v72 = 0i64;
    while ( 2 )
    {
      v5 = (float)(v2->pitStop->pitTimer - (float)(v2->pitStop->maxPitTimer - v2->pitStop->tyreTime))
         / v2->pitStop->tyreTime;
      if ( v5 <= v3 )
      {
        if ( v5 < 0.0 )
          v5 = 0.0;
      }
      else
      {
        v5 = v3;
      }
      v6 = v2->members._Myfirst;
      v71 = v3 - v5;
      *(float *)((char *)&v6->timer + v4) = *(float *)((char *)&v6->timer + v4) + dt;
      (*(Node **)((char *)&v6->model + v4))->isActive = 1;
      (*(Node **)((char *)&v2->members._Myfirst->newTyreModel + v4))->isActive = 1;
      v7 = v2->members._Myfirst;
      switch ( *(PitCrew::CrewMemberState *)((char *)&v7->state + v4) )
      {
        case GoingToPosition:
          p = (float)(*(float *)((char *)&v7->timer + v4) / *(float *)((char *)&v7->timeToPosition + v4))
            * *(float *)((char *)&v7->percentageUnScrew + v4);
          if ( *(float *)((char *)&v7->timer + v4) >= *(float *)((char *)&v7->timeToPosition + v4) )
          {
            *(float *)((char *)&v7->timer + v4) = 0.0;
            *(PitCrew::CrewMemberState *)((char *)&v7->state + v4) = UnScrewingTyre;
          }
          goto LABEL_20;
        case UnScrewingTyre:
          v9 = __libm_sse2_sinf().m128_f32[0];
          v10 = v2->members._Myfirst;
          v71 = (float)(v9
                      * (float)(*(float *)((char *)&v10->percentageEndUnScrew + v4)
                              - *(float *)((char *)&v10->percentageBeginUnScrew + v4)))
              + *(float *)((char *)&v10->percentageUnScrew + v4);
          if ( *(float *)((char *)&v10->timer + v4) >= *(float *)((char *)&v10->timeScrew + v4) )
          {
            *(float *)((char *)&v10->timer + v4) = 0.0;
            *(PitCrew::CrewMemberState *)((char *)&v10->state + v4) = ChangingTyre;
          }
          v11 = Sim::getFocusedCarIndex(v2->sim);
          if ( CarAvatar::getGuid(this->car) == v11
            && !AudioEvent::isPlaying(*(AudioEvent **)((char *)&this->members._Myfirst->unscrewEvent + v4)) )
          {
            v12 = (mat44f *)((char *)this->car->physicsState.tyreMatrix + HIDWORD(v72));
            *(_QWORD *)v79 = 0i64;
            v13 = this->members._Myfirst;
            *(_DWORD *)&v79[8] = 0;
            AudioEvent::set3DAttributes(*(AudioEvent **)((char *)&v13->unscrewEvent + v4), v12, (const vec3f *)v79);
            AudioEvent::start(*(AudioEvent **)((char *)&this->members._Myfirst->unscrewEvent + v4));
          }
          v14 = Sim::getFocusedCarIndex(this->sim);
          v15 = CarAvatar::getGuid(this->car) == v14;
          v2 = this;
          if ( v15 && *(PitCrew::CrewMemberState *)((char *)&this->members._Myfirst->state + v4) == UnScrewingTyre )
            goto LABEL_19;
          v16 = *(AudioEvent **)((char *)&this->members._Myfirst->unscrewEvent + v4);
          goto LABEL_18;
        case ChangingTyre:
          p = (float)((float)(*(float *)((char *)&v7->percentageScrew + v4)
                            - *(float *)((char *)&v7->percentageUnScrew + v4))
                    * (float)(*(float *)((char *)&v7->timer + v4) / *(float *)((char *)&v7->timeToChangeTyre + v4)))
            + *(float *)((char *)&v7->percentageUnScrew + v4);
          if ( *(float *)((char *)&v7->timer + v4) >= *(float *)((char *)&v7->timeToChangeTyre + v4) )
          {
            *(float *)((char *)&v7->timer + v4) = 0.0;
            *(PitCrew::CrewMemberState *)((char *)&v7->state + v4) = ScrewingTyre;
          }
          goto LABEL_20;
        case ScrewingTyre:
          v45 = __libm_sse2_sinf().m128_f32[0];
          v46 = v2->members._Myfirst;
          v71 = (float)(v45
                      * (float)(*(float *)((char *)&v46->percentageEndScrew + v4)
                              - *(float *)((char *)&v46->percentageBeginScrew + v4)))
              + *(float *)((char *)&v46->percentageScrew + v4);
          if ( *(float *)((char *)&v46->timer + v4) >= *(float *)((char *)&v46->timeScrew + v4) )
          {
            *(float *)((char *)&v46->timer + v4) = 0.0;
            *(PitCrew::CrewMemberState *)((char *)&v46->state + v4) = Finishing;
          }
          v47 = Sim::getFocusedCarIndex(v2->sim);
          if ( CarAvatar::getGuid(this->car) == v47
            && !AudioEvent::isPlaying(*(AudioEvent **)((char *)&this->members._Myfirst->screwEvent + v4)) )
          {
            v48 = (mat44f *)((char *)this->car->physicsState.tyreMatrix + HIDWORD(v72));
            velocity.x = 0.0;
            v49 = this->members._Myfirst;
            velocity.y = 0.0;
            velocity.z = 0.0;
            AudioEvent::set3DAttributes(*(AudioEvent **)((char *)&v49->screwEvent + v4), v48, &velocity);
            AudioEvent::start(*(AudioEvent **)((char *)&this->members._Myfirst->screwEvent + v4));
          }
          v50 = Sim::getFocusedCarIndex(this->sim);
          v15 = CarAvatar::getGuid(this->car) == v50;
          v2 = this;
          if ( !v15 || *(PitCrew::CrewMemberState *)((char *)&this->members._Myfirst->state + v4) != ScrewingTyre )
          {
            v16 = *(AudioEvent **)((char *)&this->members._Myfirst->screwEvent + v4);
LABEL_18:
            AudioEvent::stop(v16);
          }
          goto LABEL_19;
        case Finishing:
          p = (float)((float)(*(float *)((char *)&v7->timer + v4) / *(float *)((char *)&v7->timeToFinish + v4))
                    * (float)(v3 - *(float *)((char *)&v7->percentageScrew + v4)))
            + *(float *)((char *)&v7->percentageScrew + v4);
          goto LABEL_20;
        default:
LABEL_19:
          p = v71;
LABEL_20:
          AnimationPlayer::setCurrentPos(*(AnimationPlayer **)((char *)&v2->members._Myfirst->player + v4), p, 0.0);
          if ( (v73 & 1) != 0 )
          {
            v17 = *(int *)((char *)&v2->members._Myfirst->oldTyreNull + v4);
            (*(void (**)(int, __m128 *))(*(_DWORD *)v17 + 32))(v17, &v74);
            v18 = (float)(v75.m128_f32[2] * v76.m128_f32[1]) - (float)(v75.m128_f32[1] * v76.m128_f32[2]);
            v19 = (float)(v75.m128_f32[1] * v76.m128_f32[0]) - (float)(v75.m128_f32[0] * v76.m128_f32[1]);
            v20 = (float)(v75.m128_f32[0] * v76.m128_f32[2]) - (float)(v75.m128_f32[2] * v76.m128_f32[0]);
            v21 = fsqrt((float)((float)(v20 * v20) + (float)(v18 * v18)) + (float)(v19 * v19));
            if ( v21 != 0.0 )
            {
              v18 = v18 * (float)(1.0 / v21);
              v20 = v20 * (float)(1.0 / v21);
              v19 = v19 * (float)(1.0 / v21);
            }
            v22 = v2->members._Myfirst;
            v76.m128_i32[0] ^= _xmm;
            v76.m128_i32[1] ^= _xmm;
            v76.m128_i32[2] ^= _xmm;
            v74.m128_u64[0] = __PAIR64__(LODWORD(v20), LODWORD(v18));
            v74.m128_f32[2] = v19;
            v23 = *(int *)((char *)&v22->carWheels._Mylast + v4);
            for ( i = *(int *)((char *)&v22->carWheels._Myfirst + v72); i != v23; v69[3] = (__m128)v32 )
            {
              (*(void (**)(_DWORD, __m128 *))(**(_DWORD **)(*(_DWORD *)i + 148) + 32))(
                *(_DWORD *)(*(_DWORD *)i + 148),
                &v80);
              v25 = v81;
              v26 = v82;
              v27 = v83;
              v84 = 0i64;
              v85 = 0i64;
              v86 = 0i64;
              v87 = 0i64;
              v28 = DirectX::XMMatrixInverse(&pDeterminant, v80, v81, v82, v83);
              v29 = (__m128 *)(*(_DWORD *)i + 4);
              M2_8[0] = v28;
              M2_8[1] = v25;
              v30 = v75;
              M2_8[2] = v26;
              v31 = v76;
              M2_56 = v27;
              v32 = v77;
              v69 = v29;
              i += 4;
              *v29 = DirectX::XMMatrixMultiply(M2_8, v74);
              v69[1] = v30;
              v69[2] = v31;
            }
            v2 = this;
            v33 = v72;
            v34 = *(int *)((char *)&this->members._Myfirst->newTyreNull + v72);
            v35 = (const __m128i *)(*(int (**)(int, __int128 *))(*(_DWORD *)v34 + 32))(v34, &v84);
            v74 = (__m128)_mm_loadu_si128(v35);
            v75 = (__m128)_mm_loadu_si128(v35 + 1);
            v76 = (__m128)_mm_loadu_si128(v35 + 2);
            v77 = _mm_loadu_si128(v35 + 3);
            *(__m128 *)&v79[12] = _mm_xor_ps(
                                    _mm_xor_ps(_mm_shuffle_ps(v76, v76, 85), (__m128)(unsigned int)_xmm),
                                    (__m128)(unsigned int)_xmm);
            v36 = _mm_shuffle_ps(v75, v75, 170).m128_f32[0];
            v37 = _mm_shuffle_ps(v76, v76, 170).m128_f32[0];
            v38 = _mm_shuffle_ps(v75, v75, 85).m128_f32[0];
            v39 = (float)(v38 * v76.m128_f32[0]) - (float)(v75.m128_f32[0] * *(float *)&v79[12]);
            v40 = (float)(v36 * *(float *)&v79[12]) - (float)(v38 * v37);
            v41 = (float)(v75.m128_f32[0] * v37) - (float)(v36 * v76.m128_f32[0]);
            v42 = fsqrt((float)((float)(v41 * v41) + (float)(v40 * v40)) + (float)(v39 * v39));
            if ( v42 != 0.0 )
            {
              v40 = v40 * (float)(1.0 / v42);
              v41 = v41 * (float)(1.0 / v42);
              v39 = v39 * (float)(1.0 / v42);
            }
            v43 = this->members._Myfirst;
            v76.m128_i32[0] ^= _xmm;
            v76.m128_i32[2] = LODWORD(v37) ^ _xmm;
            v76.m128_i32[1] = *(_DWORD *)&v79[12] ^ _xmm;
            v74.m128_u64[0] = __PAIR64__(LODWORD(v41), LODWORD(v40));
            v74.m128_f32[2] = v39;
            v44 = *(int *)((char *)&v43->newTyreModel + v72);
            *(__m128i *)(v44 + 4) = _mm_loadu_si128((const __m128i *)&v74);
            *(__m128i *)(v44 + 20) = _mm_loadu_si128((const __m128i *)&v75);
            *(__m128i *)(v44 + 36) = _mm_loadu_si128((const __m128i *)&v76);
            *(__m128i *)(v44 + 52) = _mm_loadu_si128(&v77);
          }
          else
          {
            v51 = v2->members._Myfirst;
            v52 = v72;
            v53 = *(int **)((char *)&v51->carWheels._Mylast + v4);
            for ( j = *(int **)((char *)&v51->carWheels._Myfirst + v72); j != v53; *(__m128i *)(v70 + 48) = v63 )
            {
              v55 = *(int *)((char *)&this->members._Myfirst->oldTyreNull + v52);
              (*(void (**)(int, __m128 *))(*(_DWORD *)v55 + 32))(v55, &v74);
              (*(void (**)(_DWORD, __m128 *))(**(_DWORD **)(*j + 148) + 32))(*(_DWORD *)(*j + 148), &v80);
              v56 = v81;
              v57 = v82;
              v58 = v83;
              v84 = 0i64;
              v85 = 0i64;
              v86 = 0i64;
              v87 = 0i64;
              v59 = DirectX::XMMatrixInverse(&v91, v80, v81, v82, v83);
              v60 = *j;
              v90.r[0] = v59;
              v70 = v60 + 4;
              v90.r[1] = v56;
              v61 = v75;
              v90.r[2] = v57;
              v62 = v76;
              v90.r[3] = v58;
              v63 = v77;
              v64 = DirectX::XMMatrixMultiply(v90.r, v74);
              ++j;
              v52 = v72;
              *(__m128 *)v70 = v64;
              *(__m128 *)(v70 + 16) = v61;
              *(__m128 *)(v70 + 32) = v62;
            }
            v33 = v72;
            v65 = this->members._Myfirst;
            v66 = (const __m128i *)(*(int (**)(_DWORD, __int128 *))(**(_DWORD **)((char *)&v65->newTyreNull
                                                                                           + v72)
                                                                             + 32))(
                                     *(Node **)((char *)&v65->newTyreNull + v72),
                                     &v84);
            v67 = *(int *)((char *)&v65->newTyreModel + v72);
            v2 = this;
            *(__m128i *)(v67 + 4) = _mm_loadu_si128(v66);
            *(__m128i *)(v67 + 20) = _mm_loadu_si128(v66 + 1);
            *(__m128i *)(v67 + 36) = _mm_loadu_si128(v66 + 2);
            *(__m128i *)(v67 + 52) = _mm_loadu_si128(v66 + 3);
          }
          v4 = v33 + 132;
          ++v73;
          HIDWORD(v72) += 64;
          v3 = FLOAT_1_0;
          LODWORD(v72) = v4;
          if ( v73 >= v2->members._Mylast - v2->members._Myfirst )
            return;
          continue;
      }
    }
  }
}
