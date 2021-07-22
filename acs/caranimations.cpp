#include "caranimations.h"
void CarAnimations::CarAnimations(CarAnimations *this, CarAvatar *aCar)
{
  std::unique_ptr<CarAnimation> *v3; // ebp
  std::wstring *v4; // eax
  WingAnimation *v5; // eax
  CarAnimation *v6; // eax
  CarAnimation *v7; // esi
  WingAnimation *v8; // ecx
  AnimationPlayer *v9; // eax
  AnimationPlayer *v10; // edi
  std::wstring *v11; // eax
  std::wstring *v12; // esi
  WingAnimation *v13; // eax
  CarAnimation *v14; // eax
  CarAnimation *v15; // esi
  WingAnimation *v16; // ecx
  AnimationPlayer *v17; // eax
  AnimationPlayer *v18; // edi
  std::wstring *v19; // eax
  std::wstring *v20; // esi
  WingAnimation *v21; // eax
  CarAnimation *v22; // eax
  CarAnimation *v23; // esi
  WingAnimation *v24; // ecx
  AnimationPlayer *v25; // eax
  AnimationPlayer *v26; // edi
  std::wstring *v27; // eax
  std::wstring *v28; // esi
  WingAnimation *v29; // eax
  CarAnimation *v30; // eax
  CarAnimation *v31; // esi
  WingAnimation *v32; // ecx
  AnimationPlayer *v33; // eax
  AnimationPlayer *v34; // edi
  std::wstring *v35; // eax
  CarAvatar *v36; // ecx
  char v37; // al
  Game *v38; // ebp
  std::wostream *v39; // eax
  const std::wstring *v40; // eax
  char v41; // al
  WingAnimation *v42; // eax
  WingAnimation *v43; // eax
  WingAnimation *v44; // edi
  const std::wstring *v45; // eax
  std::wstring *v46; // esi
  CarAvatar *v47; // eax
  std::wstring *v48; // eax
  std::wstring *v49; // eax
  const std::wstring *v50; // eax
  AnimationPlayer *v51; // ecx
  AnimationPlayer *v52; // eax
  AnimationPlayer *v53; // esi
  const std::wstring *v54; // eax
  const std::wstring *v55; // eax
  const std::wstring *v56; // eax
  const std::wstring *v57; // eax
  const std::wstring *v58; // eax
  const std::wstring *v59; // eax
  std::wstring *v60; // eax
  std::wstring *v61; // esi
  CarAvatar *v62; // eax
  std::wstring *v63; // eax
  std::wstring *v64; // eax
  CarAnimation *v65; // eax
  CarAnimation *v66; // eax
  CarAnimation *v67; // esi
  AnimationPlayer *v68; // ecx
  AnimationPlayer *v69; // eax
  AnimationPlayer *v70; // edi
  std::wstring v71; // [esp-1Ch] [ebp-228h] BYREF
  Game *v72; // [esp-4h] [ebp-210h]
  char v73; // [esp+1Bh] [ebp-1F1h]
  WingAnimation *nn; // [esp+1Ch] [ebp-1F0h] BYREF
  int v75; // [esp+20h] [ebp-1ECh]
  int v76; // [esp+24h] [ebp-1E8h]
  void *v77; // [esp+28h] [ebp-1E4h]
  CarAnimations *v78; // [esp+2Ch] [ebp-1E0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v79; // [esp+30h] [ebp-1DCh] BYREF
  std::wstring v80; // [esp+E0h] [ebp-12Ch] BYREF
  std::wstring result; // [esp+F8h] [ebp-114h] BYREF
  std::wstring animation_name; // [esp+110h] [ebp-FCh] BYREF
  std::wstring section; // [esp+128h] [ebp-E4h] BYREF
  std::wstring key; // [esp+140h] [ebp-CCh] BYREF
  std::wstring iniw; // [esp+158h] [ebp-B4h] BYREF
  std::wstring v86; // [esp+170h] [ebp-9Ch] BYREF
  std::wstring v87; // [esp+188h] [ebp-84h] BYREF
  std::wstring v88; // [esp+1A0h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+1B8h] [ebp-54h] BYREF
  int v90; // [esp+208h] [ebp-4h]

  v76 = 0;
  v78 = this;
  v72 = aCar->sim->game;
  v71._Myres = 7;
  v71._Mysize = 0;
  v71._Bx._Buf[0] = 0;
  std::wstring::assign(&v71, L"CAR_ANIMATIONS", 0xEu);
  GameObject::GameObject(this, v71, v72);
  this->__vftable = (CarAnimations_vtbl *)&CarAnimations::`vftable';
  v90 = 0;
  this->wings._Myfirst = 0;
  this->wings._Mylast = 0;
  this->wings._Myend = 0;
  v3 = &this->door;
  this->door._Myptr = 0;
  LOBYTE(v90) = 2;
  v72 = (Game *)&aCar->unixName;
  this->doorAnimationTarget = 0.0;
  v71._Myres = (unsigned int)L"content/cars/";
  v71._Mysize = (unsigned int)&result;
  this->car = aCar;
  v4 = std::operator+<wchar_t>((std::wstring *)v71._Mysize, (const wchar_t *)v71._Myres, (const std::wstring *)v72);
  LOBYTE(v90) = 3;
  std::operator+<wchar_t>(&animation_name, v4, L"/animations/car_shift_dw.ksanim");
  LOBYTE(v90) = 5;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( Path::fileExists((unsigned int)this, &animation_name, 0) )
  {
    v5 = (WingAnimation *)operator new(28);
    nn = v5;
    LOBYTE(v90) = 6;
    if ( v5 )
    {
      CarAnimation::CarAnimation(v5);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    LOBYTE(v90) = 5;
    Animation::load(&v7->animation, &animation_name);
    v8 = (WingAnimation *)operator new(28);
    nn = v8;
    LOBYTE(v90) = 7;
    if ( v8 )
      AnimationPlayer::AnimationPlayer((AnimationPlayer *)v8, &v7->animation, this->car->bodyTransform, eOnlyAnimated);
    else
      v9 = 0;
    v10 = v7->player._Myptr;
    LOBYTE(v90) = 5;
    v7->player._Myptr = v9;
    if ( v10 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v10);
      operator delete(v10);
    }
    this->shiftDown = v7;
  }
  else
  {
    this->shiftDown = 0;
  }
  v11 = std::operator+<wchar_t>(&v80, L"content/cars/", &this->car->unixName);
  LOBYTE(v90) = 8;
  v12 = std::operator+<wchar_t>(&section, v11, L"/animations/car_shift_up.ksanim");
  if ( &animation_name != v12 )
  {
    if ( animation_name._Myres >= 8 )
      operator delete(animation_name._Bx._Ptr);
    animation_name._Myres = 7;
    animation_name._Mysize = 0;
    animation_name._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&animation_name, v12);
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v90) = 5;
  if ( v80._Myres >= 8 )
    operator delete(v80._Bx._Ptr);
  if ( Path::fileExists((unsigned int)this, &animation_name, 0) )
  {
    v13 = (WingAnimation *)operator new(28);
    nn = v13;
    LOBYTE(v90) = 9;
    if ( v13 )
    {
      CarAnimation::CarAnimation(v13);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    LOBYTE(v90) = 5;
    Animation::load(&v15->animation, &animation_name);
    v16 = (WingAnimation *)operator new(28);
    nn = v16;
    LOBYTE(v90) = 10;
    if ( v16 )
      AnimationPlayer::AnimationPlayer((AnimationPlayer *)v16, &v15->animation, this->car->bodyTransform, eOnlyAnimated);
    else
      v17 = 0;
    v18 = v15->player._Myptr;
    LOBYTE(v90) = 5;
    v15->player._Myptr = v17;
    if ( v18 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v18);
      operator delete(v18);
    }
    this->shiftUp = v15;
  }
  else
  {
    this->shiftUp = 0;
  }
  v19 = std::operator+<wchar_t>(&v80, L"content/cars/", &this->car->unixName);
  LOBYTE(v90) = 11;
  v20 = std::operator+<wchar_t>(&section, v19, L"/animations/car_shift.ksanim");
  if ( &animation_name != v20 )
  {
    if ( animation_name._Myres >= 8 )
      operator delete(animation_name._Bx._Ptr);
    animation_name._Myres = 7;
    animation_name._Mysize = 0;
    animation_name._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&animation_name, v20);
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v90) = 5;
  if ( v80._Myres >= 8 )
    operator delete(v80._Bx._Ptr);
  if ( Path::fileExists((unsigned int)this, &animation_name, 0) )
  {
    v21 = (WingAnimation *)operator new(28);
    nn = v21;
    LOBYTE(v90) = 12;
    if ( v21 )
    {
      CarAnimation::CarAnimation(v21);
      v23 = v22;
    }
    else
    {
      v23 = 0;
    }
    LOBYTE(v90) = 5;
    Animation::load(&v23->animation, &animation_name);
    v24 = (WingAnimation *)operator new(28);
    nn = v24;
    LOBYTE(v90) = 13;
    if ( v24 )
      AnimationPlayer::AnimationPlayer((AnimationPlayer *)v24, &v23->animation, this->car->bodyTransform, eOnlyAnimated);
    else
      v25 = 0;
    v26 = v23->player._Myptr;
    LOBYTE(v90) = 5;
    v23->player._Myptr = v25;
    if ( v26 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v26);
      operator delete(v26);
    }
    this->shift = v23;
  }
  else
  {
    this->shift = 0;
  }
  v27 = std::operator+<wchar_t>(&v80, L"content/cars/", &this->car->unixName);
  LOBYTE(v90) = 14;
  v28 = std::operator+<wchar_t>(&section, v27, L"/animations/car_steer_extra.ksanim");
  if ( &animation_name != v28 )
  {
    if ( animation_name._Myres >= 8 )
      operator delete(animation_name._Bx._Ptr);
    animation_name._Myres = 7;
    animation_name._Mysize = 0;
    animation_name._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&animation_name, v28);
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v90) = 5;
  if ( v80._Myres >= 8 )
    operator delete(v80._Bx._Ptr);
  if ( Path::fileExists((unsigned int)this, &animation_name, 0) )
  {
    v29 = (WingAnimation *)operator new(28);
    nn = v29;
    LOBYTE(v90) = 15;
    if ( v29 )
    {
      CarAnimation::CarAnimation(v29);
      v31 = v30;
    }
    else
    {
      v31 = 0;
    }
    LOBYTE(v90) = 5;
    Animation::load(&v31->animation, &animation_name);
    v32 = (WingAnimation *)operator new(28);
    nn = v32;
    LOBYTE(v90) = 16;
    if ( v32 )
      AnimationPlayer::AnimationPlayer((AnimationPlayer *)v32, &v31->animation, this->car->bodyTransform, eOnlyAnimated);
    else
      v33 = 0;
    v34 = v31->player._Myptr;
    LOBYTE(v90) = 5;
    v31->player._Myptr = v33;
    if ( v34 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v34);
      operator delete(v34);
    }
    this->carSteerExtra = v31;
  }
  else
  {
    this->carSteerExtra = 0;
  }
  v35 = std::operator+<wchar_t>(&v88, L"content/cars/", &this->car->unixName);
  LOBYTE(v90) = 17;
  std::operator+<wchar_t>(&iniw, v35, L"/data/wing_animations.ini");
  LOBYTE(v90) = 19;
  if ( v88._Myres >= 8 )
    operator delete(v88._Bx._Ptr);
  v36 = this->car;
  v88._Bx._Buf[0] = 0;
  v88._Myres = 7;
  v88._Mysize = 0;
  v75 = 1;
  CarAvatar::openINI(v36, &ini, &iniw);
  LOBYTE(v90) = 20;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v90) = 21;
  v37 = INIReader::hasSection(&ini, &section);
  v73 = v37;
  LOBYTE(v90) = 20;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v37 = v73;
  }
  if ( v37 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"VERSION", 7u);
    LOBYTE(v90) = 22;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v90) = 23;
    v75 = INIReader::getInt(&ini, &section, &result);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v90) = 20;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  if ( ini.ready )
  {
    v38 = 0;
    while ( 1 )
    {
      *(_DWORD *)v79.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v79.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v79.gap68);
      v76 |= 1u;
      LOBYTE(v90) = 24;
      std::wiostream::basic_iostream<wchar_t>(&v79, &v79.gap10[8], 0);
      v90 = 25;
      *(_DWORD *)&v79.gap0[*(_DWORD *)(*(_DWORD *)v79.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(CarAnimations **)((char *)&v78 + *(_DWORD *)(*(_DWORD *)v79.gap0 + 4)) = (CarAnimations *)(*(_DWORD *)(*(_DWORD *)v79.gap0 + 4)
                                                                                                 - 104);
      std::wstreambuf::wstreambuf(&v79.gap10[8]);
      *(_DWORD *)&v79.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v79.gap10[64] = 0;
      *(_DWORD *)&v79.gap10[68] = 0;
      v72 = v38;
      LOBYTE(v90) = 27;
      v39 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v79.gap10, "ANIMATION_");
      std::wostream::operator<<(v39, v72);
      v40 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
      LOBYTE(v90) = 28;
      v41 = INIReader::hasSection(&ini, v40);
      v73 = v41;
      LOBYTE(v90) = 27;
      if ( v80._Myres >= 8 )
      {
        operator delete(v80._Bx._Ptr);
        v41 = v73;
      }
      if ( !v41 )
        break;
      v42 = (WingAnimation *)operator new(48);
      nn = v42;
      LOBYTE(v90) = 29;
      if ( v42 )
      {
        WingAnimation::WingAnimation(v42);
        v44 = v43;
      }
      else
      {
        v44 = 0;
      }
      LOBYTE(v90) = 27;
      nn = v44;
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"FILE", 4u);
      LOBYTE(v90) = 30;
      v45 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
      LOBYTE(v90) = 31;
      v46 = INIReader::getString(&ini, &key, v45, &result);
      v47 = this->car;
      LOBYTE(v90) = 32;
      v48 = std::operator+<wchar_t>(&v86, L"content/cars/", &v47->unixName);
      LOBYTE(v90) = 33;
      v49 = std::operator+<wchar_t>(&v87, v48, L"/animations/");
      LOBYTE(v90) = 34;
      v50 = std::operator+<wchar_t>(&section, v49, v46);
      LOBYTE(v90) = 35;
      Animation::load(&v44->animation, v50);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( v87._Myres >= 8 )
        operator delete(v87._Bx._Ptr);
      v87._Myres = 7;
      v87._Mysize = 0;
      v87._Bx._Buf[0] = 0;
      if ( v86._Myres >= 8 )
        operator delete(v86._Bx._Ptr);
      v86._Myres = 7;
      v86._Mysize = 0;
      v86._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      v80._Myres = 7;
      v80._Mysize = 0;
      v80._Bx._Buf[0] = 0;
      LOBYTE(v90) = 27;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v51 = (AnimationPlayer *)operator new(28);
      v77 = v51;
      LOBYTE(v90) = 36;
      if ( v51 )
        AnimationPlayer::AnimationPlayer(v51, &v44->animation, this->car->bodyTransform, eOnlyAnimated);
      else
        v52 = 0;
      v53 = v44->player._Myptr;
      LOBYTE(v90) = 27;
      v44->player._Myptr = v52;
      if ( v53 )
      {
        std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v53);
        operator delete(v53);
      }
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"MIN", 3u);
      LOBYTE(v90) = 37;
      v54 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
      LOBYTE(v90) = 38;
      v44->zero = INIReader::getFloat(&ini, v54, &result);
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      v80._Myres = 7;
      v80._Mysize = 0;
      v80._Bx._Buf[0] = 0;
      LOBYTE(v90) = 27;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"MAX", 3u);
      LOBYTE(v90) = 39;
      v55 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
      LOBYTE(v90) = 40;
      v44->one = INIReader::getFloat(&ini, v55, &result);
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      v80._Myres = 7;
      v80._Mysize = 0;
      v80._Bx._Buf[0] = 0;
      LOBYTE(v90) = 27;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"WING", 4u);
      LOBYTE(v90) = 41;
      v56 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
      LOBYTE(v90) = 42;
      v44->wingIndex = INIReader::getInt(&ini, v56, &result);
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      v80._Myres = 7;
      v80._Mysize = 0;
      v80._Bx._Buf[0] = 0;
      LOBYTE(v90) = 27;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"INVERTED", 8u);
      LOBYTE(v90) = 43;
      v57 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
      LOBYTE(v90) = 44;
      v73 = INIReader::hasKey(&ini, v57, &result);
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      v80._Myres = 7;
      v80._Mysize = 0;
      v80._Bx._Buf[0] = 0;
      LOBYTE(v90) = 27;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( v73 )
      {
        std::wstring::wstring(&key, L"INVERTED");
        LOBYTE(v90) = 45;
        v58 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
        LOBYTE(v90) = 46;
        v44->inverted = INIReader::getInt(&ini, v58, &key) != 0;
        if ( v80._Myres >= 8 )
          operator delete(v80._Bx._Ptr);
        v80._Myres = 7;
        v80._Mysize = 0;
        v80._Bx._Buf[0] = 0;
        LOBYTE(v90) = 27;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
      if ( v75 >= 2 )
      {
        std::wstring::wstring(&key, L"SPEED");
        LOBYTE(v90) = 47;
        v59 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v79, &v80);
        LOBYTE(v90) = 48;
        v44->speed = INIReader::getFloat(&ini, v59, &key);
        if ( v80._Myres >= 8 )
          operator delete(v80._Bx._Ptr);
        v80._Myres = 7;
        v80._Mysize = 0;
        v80._Bx._Buf[0] = 0;
        LOBYTE(v90) = 27;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
      std::vector<SpinnerData *>::push_back(
        (std::vector<ICollisionObject *> *)&this->wings,
        (ICollisionObject *const *)&nn);
      v38 = (Game *)((char *)v38 + 1);
      LOBYTE(v90) = 20;
      *(_DWORD *)&v79.gap0[*(_DWORD *)(*(_DWORD *)v79.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(CarAnimations **)((char *)&v78 + *(_DWORD *)(*(_DWORD *)v79.gap0 + 4)) = (CarAnimations *)(*(_DWORD *)(*(_DWORD *)v79.gap0 + 4)
                                                                                                 - 104);
      *(_DWORD *)&v79.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v79.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v79.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v79.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v79.gap68);
    }
    LOBYTE(v90) = 20;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v79);
    v3 = &this->door;
  }
  v60 = std::operator+<wchar_t>(&key, L"content/cars/", &this->car->unixName);
  LOBYTE(v90) = 49;
  v61 = std::operator+<wchar_t>(&v80, v60, L"/animations/car_door_L.ksanim");
  if ( &animation_name != v61 )
  {
    if ( animation_name._Myres >= 8 )
      operator delete(animation_name._Bx._Ptr);
    animation_name._Myres = 7;
    animation_name._Mysize = 0;
    animation_name._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&animation_name, v61);
  }
  if ( v80._Myres >= 8 )
    operator delete(v80._Bx._Ptr);
  v80._Myres = 7;
  v80._Mysize = 0;
  v80._Bx._Buf[0] = 0;
  LOBYTE(v90) = 20;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v62 = this->car;
  if ( v62->driverEyesPosition.x < 0.0 )
  {
    v63 = std::operator+<wchar_t>(&key, L"content/cars/", &v62->unixName);
    LOBYTE(v90) = 50;
    v64 = std::operator+<wchar_t>(&v80, v63, L"/animations/car_door_R.ksanim");
    std::wstring::operator=(&animation_name, v64);
    if ( v80._Myres >= 8 )
      operator delete(v80._Bx._Ptr);
    v80._Myres = 7;
    v80._Mysize = 0;
    v80._Bx._Buf[0] = 0;
    LOBYTE(v90) = 20;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( Path::fileExists((unsigned int)this, &animation_name, 0) )
  {
    v65 = (CarAnimation *)operator new(28);
    v77 = v65;
    LOBYTE(v90) = 51;
    if ( v65 )
    {
      CarAnimation::CarAnimation(v65);
      v67 = v66;
    }
    else
    {
      v67 = 0;
    }
    LOBYTE(v90) = 20;
    Animation::load(&v67->animation, &animation_name);
    v68 = (AnimationPlayer *)operator new(28);
    v77 = v68;
    LOBYTE(v90) = 52;
    if ( v68 )
      AnimationPlayer::AnimationPlayer(v68, &v67->animation, this->car->bodyTransform, eOnlyAnimated);
    else
      v69 = 0;
    v70 = v67->player._Myptr;
    LOBYTE(v90) = 20;
    v67->player._Myptr = v69;
    if ( v70 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v70);
      operator delete(v70);
    }
    std::unique_ptr<CarAnimation>::reset(v3, v67);
  }
  LOBYTE(v90) = 19;
  INIReader::~INIReader(&ini);
  if ( iniw._Myres >= 8 )
    operator delete(iniw._Bx._Ptr);
  iniw._Myres = 7;
  iniw._Mysize = 0;
  iniw._Bx._Buf[0] = 0;
  if ( animation_name._Myres >= 8 )
    operator delete(animation_name._Bx._Ptr);
}
void CarAnimations::~CarAnimations(CarAnimations *this)
{
  CarAnimations *v1; // ebx
  CarAnimation *v2; // esi
  AnimationPlayer *v3; // edi
  CarAnimation *v4; // esi
  AnimationPlayer *v5; // edi
  CarAnimation *v6; // esi
  AnimationPlayer *v7; // edi
  CarAnimation *v8; // esi
  AnimationPlayer *v9; // edi
  WingAnimation **v10; // esi
  std::vector<WingAnimation *> *v11; // ebp
  WingAnimation **v12; // edi
  WingAnimation *v13; // ebx
  AnimationPlayer *v14; // ebp
  CarAnimation *v15; // esi
  AnimationPlayer *v16; // edi
  std::vector<WingAnimation *> *v18; // [esp+18h] [ebp-14h]

  v1 = this;
  this->__vftable = (CarAnimations_vtbl *)&CarAnimations::`vftable';
  v2 = this->shiftUp;
  if ( v2 )
  {
    v3 = v2->player._Myptr;
    if ( v3 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v3);
      operator delete(v3);
    }
    std::vector<AnimationSet>::_Tidy(&v2->animation);
    operator delete(v2);
  }
  v4 = v1->shiftDown;
  if ( v4 )
  {
    v5 = v4->player._Myptr;
    if ( v5 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v5);
      operator delete(v5);
    }
    std::vector<AnimationSet>::_Tidy(&v4->animation);
    operator delete(v4);
  }
  v6 = v1->shift;
  if ( v6 )
  {
    v7 = v6->player._Myptr;
    if ( v7 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v7);
      operator delete(v7);
    }
    std::vector<AnimationSet>::_Tidy(&v6->animation);
    operator delete(v6);
  }
  v8 = v1->carSteerExtra;
  if ( v8 )
  {
    v9 = v8->player._Myptr;
    if ( v9 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v9);
      operator delete(v9);
    }
    std::vector<AnimationSet>::_Tidy(&v8->animation);
    operator delete(v8);
  }
  v10 = v1->wings._Myfirst;
  v11 = &v1->wings;
  v12 = v1->wings._Mylast;
  v18 = &v1->wings;
  if ( v10 != v12 )
  {
    do
    {
      v13 = *v10;
      if ( *v10 )
      {
        v14 = v13->player._Myptr;
        if ( v14 )
        {
          std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v14);
          operator delete(v14);
        }
        std::vector<AnimationSet>::_Tidy(&v13->animation);
        operator delete(v13);
      }
      ++v10;
    }
    while ( v10 != v12 );
    v1 = this;
    v11 = v18;
  }
  v15 = v1->door._Myptr;
  if ( v15 )
  {
    v16 = v15->player._Myptr;
    if ( v16 )
    {
      std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v15->player._Myptr);
      operator delete(v16);
    }
    std::vector<AnimationSet>::_Tidy(&v15->animation);
    operator delete(v15);
  }
  if ( v11->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v11);
    operator delete(v11->_Myfirst);
    v11->_Myfirst = 0;
    v11->_Mylast = 0;
    v11->_Myend = 0;
  }
  GameObject::~GameObject(v1);
}
CarAnimations *CarAnimations::`scalar deleting destructor'(CarAnimations *this, unsigned int a2)
{
  CarAnimations::~CarAnimations(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CarAnimations::setDoorOpen(CarAnimations *this, bool mode)
{
  if ( mode )
    this->doorAnimationTarget = 1.0;
  else
    this->doorAnimationTarget = 0.0;
}
void CarAnimations::update(CarAnimations *this, float dt)
{
  CarAnimations *v2; // edi
  CarAnimation *v3; // ecx
  float v4; // xmm2_4
  WingAnimation **v5; // esi
  unsigned int v6; // ecx
  WingAnimation *v7; // edi
  WingState *v8; // eax
  float *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm3_4
  DriverModel *v15; // eax
  DriverModel *v16; // esi
  CarAnimation *v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm0_4
  unsigned int v20; // [esp+10h] [ebp-14h]
  float v21; // [esp+10h] [ebp-14h]
  float v22; // [esp+10h] [ebp-14h]
  float v23; // [esp+10h] [ebp-14h]
  float v24; // [esp+10h] [ebp-14h]
  float v25; // [esp+14h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-8h]
  CarAvatar *v28; // [esp+20h] [ebp-4h]
  float v29; // [esp+20h] [ebp-4h]

  v2 = this;
  v3 = this->carSteerExtra;
  if ( v3 )
    AnimationPlayer::setCurrentPos(
      v3->player._Myptr,
      0.5 - (float)((float)(v2->car->physicsState.steer / v2->car->physicsInfo.steerLock) * 0.5),
      0.0);
  v4 = FLOAT_1_0;
  v5 = v2->wings._Myfirst;
  v27 = 0;
  v6 = (unsigned int)((char *)v2->wings._Mylast - (char *)v5 + 3) >> 2;
  if ( v5 > v2->wings._Mylast )
    v6 = 0;
  v20 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = *v5;
      v28 = this->car;
      if ( (*v5)->wingIndex < v28->wingsStatus._Mylast - v28->wingsStatus._Myfirst )
        break;
LABEL_23:
      ++v5;
      if ( ++v27 == v20 )
      {
        v2 = this;
        goto LABEL_25;
      }
    }
    v8 = v28->wingsStatus._Myfirst;
    if ( v7->inverted )
    {
      v9 = &v8[v7->wingIndex].angle;
      if ( *v9 > v7->one )
        v9 = &v7->one;
      LODWORD(v10) = COERCE_UNSIGNED_INT((float)((float)(*v9 - v7->zero) / v7->one) - v4) & _xmm;
    }
    else
    {
      v10 = (float)(v8[v7->wingIndex].angle - v7->zero) / v7->one;
    }
    v29 = v10;
    if ( v10 <= v4 )
    {
      v11 = 0.0;
      if ( v10 >= 0.0 )
      {
LABEL_16:
        if ( v7->speed <= 0.0 )
        {
          v13 = v29;
        }
        else
        {
          v12 = AnimationPlayer::getCurrentPos(v7->player._Myptr);
          v13 = v29;
          v14 = v7->speed * dt;
          v25 = v12;
          if ( v14 < COERCE_FLOAT(COERCE_UNSIGNED_INT(v25 - v29) & _xmm) )
          {
            if ( v29 <= v25 )
              v13 = v25 - v14;
            else
              v13 = v25 + v14;
          }
        }
        AnimationPlayer::setCurrentPos(v7->player._Myptr, v13, 0.0);
        v4 = FLOAT_1_0;
        goto LABEL_23;
      }
    }
    else
    {
      v11 = v4;
    }
    v29 = v11;
    goto LABEL_16;
  }
LABEL_25:
  v15 = CarAvatar::getActiveDriverModel(v2->car);
  v16 = v15;
  if ( v2->shiftUp )
  {
    v21 = AnimationPlayer::getCurrentPos(v15->shiftPlayer);
    AnimationPlayer::setCurrentPos(v2->shiftUp->player._Myptr, v21, 0.0);
  }
  if ( v2->shiftDown )
  {
    v22 = DriverModel::getShiftDownPlayerCurrentPosition(v16);
    AnimationPlayer::setCurrentPos(v2->shiftDown->player._Myptr, v22, 0.0);
  }
  if ( v2->shift )
  {
    v23 = AnimationPlayer::getCurrentPos(v16->shiftPlayer);
    AnimationPlayer::setCurrentPos(v2->shift->player._Myptr, v23, 0.0);
  }
  v17 = v2->door._Myptr;
  if ( v17 )
  {
    v24 = AnimationPlayer::getCurrentPos(v17->player._Myptr);
    v18 = v2->doorAnimationTarget - v24;
    if ( dt <= COERCE_FLOAT(LODWORD(v18) & _xmm) )
    {
      v19 = 0.0;
      if ( v18 <= 0.0 )
      {
        if ( v18 < 0.0 )
          v19 = FLOAT_N1_0;
      }
      else
      {
        v19 = FLOAT_1_0;
      }
      AnimationPlayer::setCurrentPos(v2->door._Myptr->player._Myptr, (float)(v19 * dt) + v24, 0.0);
    }
    else
    {
      AnimationPlayer::setCurrentPos(v2->door._Myptr->player._Myptr, v2->doorAnimationTarget, 0.0);
    }
  }
}
