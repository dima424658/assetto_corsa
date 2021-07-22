#include "cameratrack.h"
std::wstring *CameraTrack::getCameraSetName(CameraTrack *this, std::wstring *result, unsigned int i)
{
  std::wstring *v4; // [esp-10h] [ebp-14h]

  v4 = &this->sets._Myfirst[i]->name;
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, v4, 0, 0xFFFFFFFF);
  return result;
}
void CameraTrack::CameraTrack(CameraTrack *this, Sim *isim, CameraForward *icamera)
{
  CameraTrack *v3; // ebx
  std::vector<TyreThermalPatch *> *v4; // esi
  int v5; // ebp
  CameraManager *v6; // edi
  TyreThermalPatch **v7; // ecx
  TyreThermalPatch **v8; // ebx
  TyreThermalPatch **v9; // edx
  int v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // edx
  TyreThermalPatch **v13; // ecx
  TyreThermalPatch **v14; // edx
  int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // edx
  _DWORD *v18; // eax
  Event<OnPhysicsStepCompleted> *v19; // ecx
  double v20; // st7
  bool v21; // cf
  double v22; // st7
  double v23; // st7
  std::wstring v24; // [esp-1Ch] [ebp-E8h] BYREF
  int v25; // [esp-4h] [ebp-D0h]
  int v26; // [esp+1Ch] [ebp-B0h]
  float userDistanceScale; // [esp+20h] [ebp-ACh]
  CameraManager *set; // [esp+24h] [ebp-A8h] BYREF
  CameraTrack *v29; // [esp+28h] [ebp-A4h]
  CameraTrack *v30; // [esp+2Ch] [ebp-A0h]
  std::wstring section; // [esp+30h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+48h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+60h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+78h] [ebp-54h] BYREF
  int v35; // [esp+C8h] [ebp-4h]

  v3 = this;
  v29 = this;
  v30 = this;
  userDistanceScale = *(float *)&isim;
  v25 = (int)isim->game;
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  std::wstring::assign(&v24, L"CAMERA_TRACK", 0xCu);
  GameObject::GameObject(v3, v24, (Game *)v25);
  v3->__vftable = (CameraTrack_vtbl *)&CameraTrack::`vftable';
  v35 = 0;
  v3->evOnCameraChanged.handlers._Myfirst = 0;
  v3->evOnCameraChanged.handlers._Mylast = 0;
  v3->evOnCameraChanged.handlers._Myend = 0;
  v4 = (std::vector<TyreThermalPatch *> *)&v3->sets;
  v3->sets._Myfirst = 0;
  v3->sets._Mylast = 0;
  v3->sets._Myend = 0;
  v3->sim = isim;
  v5 = 0;
  v25 = 0;
  LOBYTE(v35) = 2;
  v3->camera = icamera;
  v3->oldAc = 0;
  v3->stillCamera = 0;
  v3->time = 0.0;
  v3->rotx = 0.0;
  v3->roty = 0.0;
  v3->rotz = 0.0;
  v3->dd = 0.0;
  v26 = 0;
  v3->currentSet = 0;
  v6 = CameraTrack::loadSet(v3, v25);
  for ( set = v6; v6; set = v6 )
  {
    v7 = v4->_Mylast;
    if ( &set >= (CameraManager **)v7 || (v8 = v4->_Myfirst, v4->_Myfirst > (TyreThermalPatch **)&set) )
    {
      v14 = v4->_Myend;
      if ( v7 == v14 && !(v14 - v7) )
      {
        v15 = v7 - v4->_Myfirst;
        if ( v15 == 0x3FFFFFFF )
LABEL_46:
          std::_Xlength_error("vector<T> too long");
        v16 = v14 - v4->_Myfirst;
        if ( 0x3FFFFFFF - (v16 >> 1) >= v16 )
          v17 = (v16 >> 1) + v16;
        else
          v17 = 0;
        if ( v17 < v15 + 1 )
          v17 = v15 + 1;
        std::vector<ID3D11ShaderResourceView *>::_Reallocate(v4, v17);
        v5 = v26;
      }
      v18 = v4->_Mylast;
      if ( v18 )
        *v18 = v6;
    }
    else
    {
      v9 = v4->_Myend;
      if ( v7 == v9 && !(v9 - v7) )
      {
        v10 = v7 - v8;
        if ( v10 == 0x3FFFFFFF )
          goto LABEL_46;
        v11 = v9 - v8;
        if ( 0x3FFFFFFF - (v11 >> 1) >= v11 )
          v12 = (v11 >> 1) + v11;
        else
          v12 = 0;
        if ( v12 < v10 + 1 )
          v12 = v10 + 1;
        std::vector<ID3D11ShaderResourceView *>::_Reallocate(v4, v12);
        v5 = v26;
      }
      v13 = v4->_Mylast;
      if ( v13 )
        *v13 = v4->_Myfirst[((char *)&set - (char *)v8) >> 2];
    }
    v3 = v29;
    ++v5;
    ++v4->_Mylast;
    v26 = v5;
    v6 = CameraTrack::loadSet(v3, v5);
  }
  v24._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_bd42f1a77e06a403de8b711a437b815b_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v24._Bx._Alias[4] = v3;
  v24._Mysize = (unsigned int)&v24;
  LOBYTE(v35) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)(LODWORD(userDistanceScale) + 68),
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v24,
    v3);
  v25 = (int)v3;
  v24._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_a4ac36ffb1d76d1c41fc8543199f53d8_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v24._Bx._Alias[4] = v3;
  v24._Mysize = (unsigned int)&v24;
  v19 = (Event<OnPhysicsStepCompleted> *)&v3->sim->evOnPauseModeChanged;
  LOBYTE(v35) = 2;
  Event<std::wstring>::addHandler(v19, (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v24, v3);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/camera_track.ini", 0x1Bu);
  LOBYTE(v35) = 5;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v35) = 7;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"DISTANCE_SCALE", 0xEu);
  LOBYTE(v35) = 8;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
  LOBYTE(v35) = 9;
  userDistanceScale = INIReader::getFloat(&ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v35) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v25 = 13;
  key._Myres = 7;
  v24._Myres = (unsigned int)L"UPWARD_OFFSET";
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  v3->distanceScale = 1.0 / userDistanceScale;
  std::wstring::assign(&key, (const wchar_t *)v24._Myres, v25);
  LOBYTE(v35) = 10;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
  LOBYTE(v35) = 11;
  v20 = INIReader::getFloat(&ini, &section, &key);
  v21 = section._Myres < 8;
  v3->upwardOffset = v20;
  if ( !v21 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v35) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CAMERA_WOBBLING_SPEED", 0x15u);
  LOBYTE(v35) = 12;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
  LOBYTE(v35) = 13;
  v22 = INIReader::getFloat(&ini, &section, &key);
  v21 = section._Myres < 8;
  v3->cameraWobblingSpeed = v22;
  if ( !v21 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v35) = 7;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CAMERA_WOBBLING_STRENGTH", 0x18u);
  LOBYTE(v35) = 14;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
  LOBYTE(v35) = 15;
  v23 = INIReader::getFloat(&ini, &section, &key);
  v21 = section._Myres < 8;
  v3->cameraWobblingStrenght = v23;
  if ( !v21 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LOBYTE(v35) = 2;
  INIReader::~INIReader(&ini);
}
void CameraTrack::~CameraTrack(CameraTrack *this)
{
  CameraManager **v1; // esi
  std::vector<CameraManager *> *v2; // ebp
  int v3; // edi
  unsigned int v4; // ebx
  CameraTrack *v5; // esi
  Event<ACCamera> *v6; // ebx
  std::pair<void *,std::function<void __cdecl(ACCamera const &)> > *v7; // ebp
  std::pair<void *,std::function<void __cdecl(ACCamera const &)> > *v8; // edi
  std::_Func_base<void,ACCamera const &> **v9; // esi

  this->__vftable = (CameraTrack_vtbl *)&CameraTrack::`vftable';
  v1 = this->sets._Myfirst;
  v2 = &this->sets;
  v3 = 0;
  v4 = (unsigned int)((char *)this->sets._Mylast - (char *)v1 + 3) >> 2;
  if ( v1 > this->sets._Mylast )
    v4 = 0;
  if ( v4 )
  {
    do
    {
      if ( *v1 )
        ((void (*)(CameraManager *, int))(*v1)->~CameraManager)(*v1, 1);
      ++v3;
      ++v1;
    }
    while ( v3 != v4 );
  }
  if ( v2->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v2);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v5 = this;
  v6 = &this->evOnCameraChanged;
  if ( this->evOnCameraChanged.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnCameraChanged);
    v7 = this->evOnCameraChanged.handlers._Mylast;
    v8 = v6->handlers._Myfirst;
    if ( v6->handlers._Myfirst != v7 )
    {
      v9 = &v8->second._Impl;
      do
      {
        if ( *v9 )
        {
          ((void (__stdcall *)(bool))(*v9)->_Delete_this)(*v9 != (std::_Func_base<void,ACCamera const &> *)(v9 - 4));
          *v9 = 0;
        }
        ++v8;
        v9 += 8;
      }
      while ( v8 != v7 );
      v5 = this;
    }
    operator delete(v6->handlers._Myfirst);
    v6->handlers._Myfirst = 0;
    this->evOnCameraChanged.handlers._Mylast = 0;
    this->evOnCameraChanged.handlers._Myend = 0;
  }
  GameObject::~GameObject(v5);
}
CameraTrack *CameraTrack::`vector deleting destructor'(CameraTrack *this, unsigned int a2)
{
  CameraTrack::~CameraTrack(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
int CameraTrack::getCameraTrackCount(CameraTrack *this)
{
  return this->sets._Mylast - this->sets._Myfirst;
}
CameraManager *CameraTrack::loadSet(CameraTrack *this, int index)
{
  Sim *v3; // ebx
  GameObject **v4; // esi
  TrackAvatar *v5; // edi
  char v6; // bl
  std::wostream *v7; // eax
  std::wostream *v8; // eax
  std::wostream *v9; // eax
  const std::wstring *v10; // eax
  char v11; // al
  CameraManager *v12; // esi
  const std::wstring *v13; // eax
  CameraManager *v14; // eax
  CameraManager *v15; // ebp
  AISpline *v16; // eax
  ACCamera *v17; // esi
  ACCamera *i; // edi
  std::wstring *v19; // eax
  Spline *v20; // eax
  Spline *v21; // eax
  float v22; // xmm0_4
  int v23; // ecx
  Spline *v24; // ecx
  Console *v25; // eax
  Console *v26; // eax
  Console *v27; // eax
  Console *v28; // eax
  int v29; // eax
  std::wstring v31; // [esp-60h] [ebp-1ECh] BYREF
  std::wstring v32; // [esp-48h] [ebp-1D4h] BYREF
  std::wstring v33; // [esp-30h] [ebp-1BCh] BYREF
  std::wstring v34; // [esp-18h] [ebp-1A4h] BYREF
  int v35; // [esp+0h] [ebp-18Ch]
  int v36; // [esp+4h] [ebp-188h]
  int v37; // [esp+18h] [ebp-174h]
  unsigned int v38; // [esp+1Ch] [ebp-170h]
  float v39; // [esp+20h] [ebp-16Ch]
  float v40; // [esp+24h] [ebp-168h]
  std::wstring *v41; // [esp+28h] [ebp-164h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v42; // [esp+2Ch] [ebp-160h] BYREF
  mat44f m; // [esp+DCh] [ebp-B0h] BYREF
  std::wstring result; // [esp+11Ch] [ebp-70h] BYREF
  std::wstring csv; // [esp+134h] [ebp-58h] BYREF
  std::wstring data_folder; // [esp+14Ch] [ebp-40h] BYREF
  std::wstring fn; // [esp+164h] [ebp-28h] BYREF
  int v48; // [esp+188h] [ebp-4h]

  *(float *)&v38 = 0.0;
  v3 = this->sim;
  v39 = *(float *)&index;
  v4 = v3->gameObjects._Myfirst;
  if ( v4 == v3->gameObjects._Mylast )
  {
LABEL_4:
    v5 = 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = (TrackAvatar *)__RTDynamicCast(
                            *v4,
                            0,
                            &GameObject `RTTI Type Descriptor',
                            &TrackAvatar `RTTI Type Descriptor',
                            0);
      if ( v5 )
        break;
      if ( ++v4 == v3->gameObjects._Mylast )
        goto LABEL_4;
    }
  }
  TrackAvatar::getDataFolder(v5, &data_folder);
  v48 = 0;
  std::operator+<wchar_t>(&fn, &data_folder, L"/data/cameras.ini");
  LOBYTE(v48) = 1;
  this->animationTime = 0.0;
  *(_DWORD *)v42.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v42.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v42.gap68);
  LOBYTE(v48) = 2;
  v6 = 2;
  v38 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v42, &v42.gap10[8], 0);
  v48 = 3;
  *(_DWORD *)&v42.gap0[*(_DWORD *)(*(_DWORD *)v42.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::wstring **)((char *)&v41 + *(_DWORD *)(*(_DWORD *)v42.gap0 + 4)) = (std::wstring *)(*(_DWORD *)(*(_DWORD *)v42.gap0 + 4)
                                                                                           - 104);
  std::wstreambuf::wstreambuf(&v42.gap10[8]);
  *(_DWORD *)&v42.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v42.gap10[64] = 0;
  *(_DWORD *)&v42.gap10[68] = 0;
  LOBYTE(v48) = 5;
  if ( v39 == 0.0 )
  {
    v34._Myres = (unsigned int)"/data/cameras.ini";
    v9 = std::operator<<<wchar_t>((std::wostream *)v42.gap10, &data_folder);
  }
  else
  {
    v34._Myres = (unsigned int)".ini";
    v7 = std::operator<<<wchar_t>((std::wostream *)v42.gap10, &data_folder);
    v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v7, "/data/cameras_");
    v9 = (std::wostream *)std::wostream::operator<<(v8, LODWORD(v39));
  }
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v9, (const char *)v34._Myres);
  v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &csv);
  LOBYTE(v48) = 6;
  v11 = Path::fileExists(2u, v10, 0);
  HIBYTE(v37) = v11;
  LOBYTE(v48) = 5;
  if ( csv._Myres >= 8 )
  {
    operator delete(csv._Bx._Ptr);
    v11 = HIBYTE(v37);
  }
  if ( v11 )
  {
    v12 = (CameraManager *)operator new(44);
    v40 = *(float *)&v12;
    LOBYTE(v48) = 7;
    if ( v12 )
    {
      v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v42, &result);
      v6 = 3;
      LOBYTE(v48) = 8;
      v38 = 3;
      CameraManager::CameraManager(v12, v13);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    v48 = 5;
    if ( (v6 & 1) != 0 )
    {
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    v16 = TrackAvatar::getAISpline(v5);
    CameraManager::initCamerasDistanceRanges(v15, &v16->spline);
    v17 = v15->cameras._Myfirst;
    for ( i = v15->cameras._Mylast; v17 != i; ++v17 )
    {
      if ( v17->splineFileName._Mysize )
      {
        v19 = std::operator+<wchar_t>(&result, &data_folder, L"/data/");
        LOBYTE(v48) = 10;
        std::operator+<wchar_t>(&csv, v19, &v17->splineFileName);
        LOBYTE(v48) = 12;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Bx._Buf[0] = 0;
        result._Mysize = 0;
        if ( Path::fileExists((unsigned int)&v17->splineFileName, &csv, 0) )
        {
          v20 = (Spline *)operator new(24);
          v40 = *(float *)&v20;
          LOBYTE(v48) = 13;
          if ( v20 )
            Spline::Spline(v20);
          else
            v21 = 0;
          v17->spline = v21;
          LOBYTE(v48) = 12;
          v34._Myres = 7;
          v34._Mysize = 0;
          v34._Bx._Buf[0] = 0;
          std::wstring::assign(&v34, &csv, 0, 0xFFFFFFFF);
          Spline::loadFromCSV(v17->spline, v34);
          v22 = v17->splineRotationY;
          if ( v22 != 0.0 )
          {
            v39 = v22 * 0.017453;
            v38 = __libm_sse2_cosf(v35, v36).m128_u32[0];
            LODWORD(v40) = __libm_sse2_sinf(v23).m128_u32[0];
            v39 = 1.0 - *(float *)&v38;
            mat44f::mat44f(&m);
            v24 = v17->spline;
            m.M44 = 1.0;
            m.M22 = v39 + *(float *)&v38;
            m.M11 = (float)(v39 * 0.0) + *(float *)&v38;
            m.M33 = m.M11;
            m.M12 = (float)(v40 * 0.0) + (float)(v39 * 0.0);
            m.M21 = (float)(v39 * 0.0) - (float)(v40 * 0.0);
            m.M13 = (float)(v39 * 0.0) - v40;
            m.M31 = v40 + (float)(v39 * 0.0);
            m.M23 = m.M12;
            m.M32 = m.M21;
            Spline::applyMatrix(v24, &m);
          }
        }
        else
        {
          v40 = COERCE_FLOAT(&v34);
          v34._Myres = 7;
          v34._Mysize = 0;
          v34._Bx._Buf[0] = 0;
          std::wstring::assign(&v34, L"\n", 1u);
          LOBYTE(v48) = 14;
          v39 = COERCE_FLOAT(&v33);
          v33._Myres = 7;
          v33._Mysize = 0;
          v33._Bx._Buf[0] = 0;
          std::wstring::assign(&v33, L" not found", 0xAu);
          LOBYTE(v48) = 15;
          *(float *)&v38 = COERCE_FLOAT(&v32);
          v32._Myres = 7;
          v32._Mysize = 0;
          v32._Bx._Buf[0] = 0;
          std::wstring::assign(&v32, &csv, 0, 0xFFFFFFFF);
          LOBYTE(v48) = 16;
          v41 = &v31;
          v31._Myres = 7;
          v31._Mysize = 0;
          v31._Bx._Buf[0] = 0;
          std::wstring::assign(&v31, L"[ERROR] Spline CSV file ", 0x18u);
          LOBYTE(v48) = 17;
          v25 = Console::singleton();
          LOBYTE(v48) = 16;
          v26 = Console::operator<<(v25, v31);
          LOBYTE(v48) = 15;
          v27 = Console::operator<<(v26, v32);
          LOBYTE(v48) = 14;
          v28 = Console::operator<<(v27, v33);
          LOBYTE(v48) = 12;
          Console::operator<<(v28, v34);
        }
        LOBYTE(v48) = 5;
        if ( csv._Myres >= 8 )
          operator delete(csv._Bx._Ptr);
      }
    }
  }
  else
  {
    v15 = 0;
  }
  LOBYTE(v48) = 1;
  *(_DWORD *)&v42.gap0[*(_DWORD *)(*(_DWORD *)v42.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::wstring **)((char *)&v41 + *(_DWORD *)(*(_DWORD *)v42.gap0 + 4)) = (std::wstring *)(*(_DWORD *)(*(_DWORD *)v42.gap0 + 4)
                                                                                           - 104);
  *(_DWORD *)&v42.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v42.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v42.gap10[8]) )
      std::wstreambuf::epptr(&v42.gap10[8]);
    else
      std::wstreambuf::egptr(&v42.gap10[8]);
    std::wstreambuf::eback(&v42.gap10[8]);
    v29 = std::wstreambuf::eback(&v42.gap10[8]);
    operator delete(v29);
  }
  std::wstreambuf::setg(&v42.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v42.gap10[8], 0, 0);
  *(_DWORD *)&v42.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v42.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v42.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v42.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v42.gap68);
  if ( fn._Myres >= 8 )
    operator delete(fn._Bx._Ptr);
  fn._Myres = 7;
  fn._Mysize = 0;
  fn._Bx._Buf[0] = 0;
  if ( data_folder._Myres >= 8 )
    operator delete(data_folder._Bx._Ptr);
  return v15;
}
std::wstring *CameraTrack::nextSet(CameraTrack *this, std::wstring *result)
{
  std::wstring *v3; // [esp-10h] [ebp-14h]

  if ( ++this->currentSet >= this->sets._Mylast - this->sets._Myfirst )
    this->currentSet = 0;
  v3 = &this->sets._Myfirst[this->currentSet]->name;
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, v3, 0, 0xFFFFFFFF);
  return result;
}
void CameraTrack::setAudioDistanceScale(CameraTrack *this)
{
  AudioEngine::setDistanceScale(this->game->audioEngine, this->distanceScale);
}
void CameraTrack::setCurrentCameraSet(CameraTrack *this, unsigned int cameraIndex)
{
  if ( cameraIndex < this->sets._Mylast - this->sets._Myfirst )
    this->currentSet = cameraIndex;
}
void __userpurge CameraTrack::update(CameraTrack *this@<ecx>, int a2@<esi>, float dt)
{
  unsigned int v4; // eax
  int *v5; // ecx
  int v6; // eax
  float *v7; // eax
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  CameraForward *v14; // eax
  CameraForward *v15; // eax
  float v16; // xmm0_4
  CameraManager *v17; // esi
  unsigned int v18; // eax
  CarAvatar *v19; // eax
  const OnGearRequestEvent *v20; // eax
  CameraForward *v21; // ecx
  int v22; // esi
  bool v23; // zf
  CameraForward *v24; // eax
  const __m128i *v25; // eax
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm2_4
  float v31; // xmm2_4
  float v32; // xmm2_4
  std::wstring *v33; // ecx
  float v34; // xmm0_4
  mat44f *v35; // esi
  mat44f *v36; // eax
  unsigned int v37; // xmm4_4
  mat44f *v38; // eax
  float v39; // xmm0_4
  mat44f *v40; // eax
  Spline *v41; // ecx
  float v42; // xmm2_4
  float v43; // xmm1_4
  vec3f *v44; // eax
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  CameraForward *v48; // eax
  float v49; // xmm1_4
  CameraForward *v50; // esi
  const __m128i *v51; // eax
  CameraForward *v52; // eax
  float v53; // xmm1_4
  float v54; // xmm2_4
  CameraForward *v55; // ecx
  float v56; // xmm2_4
  float v57; // xmm0_4
  CameraForward *v58; // ecx
  float v59; // eax
  CameraForward *v60; // ecx
  float v61; // eax
  const mat44f *v62; // eax
  int v64; // [esp+14h] [ebp-94h]
  int v65; // [esp+18h] [ebp-90h]
  int v66; // [esp+18h] [ebp-90h]
  mat44f result; // [esp+1Ch] [ebp-8Ch] BYREF
  vec3f v68; // [esp+5Ch] [ebp-4Ch] BYREF
  float v69; // [esp+68h] [ebp-40h]
  float v70; // [esp+6Ch] [ebp-3Ch]
  vec3f cameraTarget; // [esp+70h] [ebp-38h] BYREF
  float v72; // [esp+7Ch] [ebp-2Ch]
  const OnGearRequestEvent *v73; // [esp+80h] [ebp-28h]
  float v74; // [esp+84h] [ebp-24h]
  float v75; // [esp+88h] [ebp-20h]
  float v76; // [esp+8Ch] [ebp-1Ch]
  float v77; // [esp+90h] [ebp-18h]
  float v78; // [esp+94h] [ebp-14h]
  vec3f cameraPosition; // [esp+98h] [ebp-10h] BYREF
  float v80; // [esp+A4h] [ebp-4h]
  float dta; // [esp+ACh] [ebp+4h]
  mat44f *dtb; // [esp+ACh] [ebp+4h]
  float dtc; // [esp+ACh] [ebp+4h]

  v4 = Sim::getFocusedCarIndex(this->sim);
  v74 = COERCE_FLOAT(Sim::getCar(this->sim, v4));
  v5 = *(int **)(LODWORD(v74) + 272);
  v78 = *(float *)(LODWORD(v74) + 332);
  cameraPosition.x = *(float *)(LODWORD(v74) + 336);
  v6 = *v5;
  v77 = *(float *)(LODWORD(v74) + 340);
  v7 = (float *)(*(int (**)(int *, mat44f *))(v6 + 32))(v5, &result);
  v8 = v77;
  v9 = v7[6];
  v10 = (float)(v7[5] * cameraPosition.x) + (float)(v7[1] * v78);
  v11 = v7[9] * v77;
  v77 = (float)((float)((float)(v7[4] * cameraPosition.x) + (float)(*v7 * v78)) + (float)(v7[8] * v77)) + v7[12];
  cameraTarget.x = v77;
  v12 = this->upwardOffset + (float)((float)(v10 + v11) + v7[13]);
  v13 = (float)((float)((float)(v9 * cameraPosition.x) + (float)(v7[2] * v78)) + (float)(v7[10] * v8)) + v7[14];
  v14 = this->camera;
  v78 = v12;
  cameraTarget.y = v12;
  v14->chromaticAberrationEnabled = 1;
  v15 = this->camera;
  cameraPosition.x = v13;
  cameraTarget.z = v13;
  v15->lensFlare = 1;
  this->camera->tripleScreenAvailable = 0;
  if ( this->sets._Myfirst != this->sets._Mylast )
  {
    if ( ReplayManager::isInReplaymode(this->sim->replayManager) )
      v16 = this->sim->replayManager->timeMult * dt;
    else
      v16 = dt;
    dta = v16;
    v17 = this->sets._Myfirst[this->currentSet];
    v18 = Sim::getFocusedCarIndex(this->sim);
    v19 = Sim::getCar(this->sim, v18);
    v20 = (const OnGearRequestEvent *)CameraManager::getActiveCamera(v17, v19->physicsState.normalizedSplinePosition);
    v22 = (int)v20;
    v73 = v20;
    if ( v20 != (const OnGearRequestEvent *)this->oldAc )
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnCameraChanged, v20);
    if ( !this->stillCamera )
      this->animationTime = v16 + this->animationTime;
    if ( *(_BYTE *)(v22 + 204) )
      this->animationTime = 0.0;
    v23 = *(_BYTE *)(v22 + 212) == 0;
    v24 = this->camera;
    LODWORD(v72) = LODWORD(v24->matrix.M31) ^ _xmm;
    LODWORD(v70) = LODWORD(v24->matrix.M32) ^ _xmm;
    LODWORD(v69) = LODWORD(v24->matrix.M33) ^ _xmm;
    if ( v23 )
    {
      cameraPosition.y = *(float *)(v22 + 76);
      cameraPosition.z = *(float *)(v22 + 80);
      v80 = *(float *)(v22 + 84);
      v25 = (const __m128i *)mat44f::createTarget(&result, (vec3f *)&cameraPosition.y, &cameraTarget);
      v21 = this->camera;
      *(__m128i *)&v21->matrix.M11 = _mm_loadu_si128(v25);
      *(__m128i *)&v21->matrix.M21 = _mm_loadu_si128(v25 + 1);
      *(__m128i *)&v21->matrix.M31 = _mm_loadu_si128(v25 + 2);
      *(__m128i *)&v21->matrix.M41 = _mm_loadu_si128(v25 + 3);
    }
    else
    {
      *(__m128i *)&v24->matrix.M11 = _mm_loadu_si128((const __m128i *)(v22 + 28));
      *(__m128i *)&v24->matrix.M21 = _mm_loadu_si128((const __m128i *)(v22 + 44));
      *(__m128i *)&v24->matrix.M31 = _mm_loadu_si128((const __m128i *)(v22 + 60));
      *(__m128i *)&v24->matrix.M41 = _mm_loadu_si128((const __m128i *)(v22 + 76));
      v26 = (__m128)*(unsigned int *)(v22 + 64);
      v27 = _mm_xor_ps((__m128)*(unsigned int *)(v22 + 60), (__m128)(unsigned int)_xmm);
      LODWORD(v68.z) = *(_DWORD *)(v22 + 68) ^ _xmm;
      v80 = v68.z;
      *(_QWORD *)&cameraPosition.y = _mm_unpacklo_ps(v27, _mm_xor_ps(v26, (__m128)(unsigned int)_xmm)).m128_u64[0];
      v69 = v68.z;
      v70 = cameraPosition.z;
      v72 = cameraPosition.y;
    }
    v28 = *(float *)(v22 + 160);
    v29 = *(float *)(v22 + 164);
    if ( v28 <= v29 || *(_DWORD *)(v22 + 196) )
    {
      this->camera->fov = *(float *)(v22 + 96);
    }
    else
    {
      v30 = (float)((float)((float)(v78 - *(float *)(v22 + 80)) * (float)(v78 - *(float *)(v22 + 80)))
                  + (float)((float)(v77 - *(float *)(v22 + 76)) * (float)(v77 - *(float *)(v22 + 76))))
          + (float)((float)(cameraPosition.x - *(float *)(v22 + 84)) * (float)(cameraPosition.x - *(float *)(v22 + 84)));
      if ( v30 == 0.0 )
        v31 = 0.0;
      else
        v31 = fsqrt(v30);
      v32 = (float)(v31 - v29) / (float)(v28 - v29);
      if ( v32 <= 1.0 )
      {
        if ( v32 < 0.0 )
          v32 = 0.0;
      }
      else
      {
        v32 = FLOAT_1_0;
      }
      if ( *(float *)(v22 + 200) != 1.0 )
        LODWORD(v32) = __libm_sse2_powf(v21).m128_u32[0];
      this->camera->fov = (float)((float)(*(float *)(v22 + 96) - *(float *)(v22 + 92)) * v32) + *(float *)(v22 + 92);
    }
    this->camera->maxExposure = *(float *)(v22 + 140);
    this->camera->minExposure = *(float *)(v22 + 136);
    this->camera->dofFactor = *(float *)(v22 + 144);
    this->camera->nearPlane = *(float *)(v22 + 128);
    this->camera->farPlane = *(float *)(v22 + 132);
    this->camera->exposure = 30.0;
    v33 = &this->camera->name;
    if ( v33 != (std::wstring *)(v22 + 4) )
      std::wstring::assign(v33, (const std::wstring *)(v22 + 4), 0, 0xFFFFFFFF);
    CameraShadowMapped::setShadowMapsSplits(
      this->camera,
      *(float *)(v22 + 112),
      *(float *)(v22 + 116),
      *(float *)(v22 + 120),
      500.0);
    if ( !*(_BYTE *)(v22 + 212) )
    {
      if ( this->stillCamera )
      {
        v34 = this->roty;
        v35 = (mat44f *)this->camera;
        cameraPosition.y = this->rotx;
        v35 = (mat44f *)((char *)v35 + 8);
        cameraPosition.z = v34;
        v80 = this->rotz;
        v36 = mat44f::createFromAxisAngle((int)v35, &result, (vec3f *)&cameraPosition.y);
        mul(v35, v35, v36);
        v22 = (int)v73;
      }
      else
      {
        this->time = (float)(dta * 1000.0) + this->time;
        LODWORD(v76) = __libm_sse2_sinf().m128_u32[0];
        this->rotx = v76;
        LODWORD(v75) = __libm_sse2_cosf(a2, v65).m128_u32[0];
        this->roty = v75;
        v37 = __libm_sse2_cosf(v64, v66).m128_u32[0];
        v38 = &this->camera->matrix;
        this->rotz = *(float *)&v37;
        dtb = v38;
        v39 = (float)(1.0
                    - (float)((float)((float)(COERCE_FLOAT(LODWORD(v38->M32) ^ _xmm) * v70)
                                    + (float)(COERCE_FLOAT(LODWORD(v38->M31) ^ _xmm) * v72))
                            + (float)(COERCE_FLOAT(LODWORD(v38->M33) ^ _xmm) * v69)))
            + 0.050000001;
        this->dd = v39;
        if ( (ACCamera *)v22 != this->oldAc && v39 > 0.05 )
          this->dd = 0.050000001;
        cameraPosition.z = v75;
        cameraPosition.y = v76;
        v80 = *(float *)&v37;
        v40 = mat44f::createFromAxisAngle(v22, &result, (vec3f *)&cameraPosition.y);
        mul(dtb, dtb, v40);
      }
    }
    v41 = *(Spline **)(v22 + 196);
    if ( v41 )
    {
      v42 = this->animationTime / *(float *)(v22 + 208);
      v43 = FLOAT_1_0;
      if ( v42 <= 1.0 )
      {
        if ( v42 >= 0.0 )
          v43 = this->animationTime / *(float *)(v22 + 208);
        else
          v43 = 0.0;
      }
      dtc = *(float *)(v22 + 76);
      v75 = *(float *)(v22 + 80);
      v74 = *(float *)(v22 + 84);
      v44 = Spline::getPointSmooth(v41, &v68, v43);
      v45 = v44->y;
      v46 = dtc + v44->x;
      v47 = v44->z + v74;
      v48 = this->camera;
      v49 = v45 + v75;
      v48->matrix.M41 = v46;
      v48->matrix.M43 = v47;
      v48->matrix.M42 = v49;
      v50 = this->camera;
      cameraPosition.y = v50->matrix.M41;
      cameraPosition.z = v50->matrix.M42;
      v80 = v50->matrix.M43;
      v51 = (const __m128i *)mat44f::createTarget(&result, (vec3f *)&cameraPosition.y, &cameraTarget);
      *(__m128i *)&v50->matrix.M11 = _mm_loadu_si128(v51);
      *(__m128i *)&v50->matrix.M21 = _mm_loadu_si128(v51 + 1);
      *(__m128i *)&v50->matrix.M31 = _mm_loadu_si128(v51 + 2);
      *(__m128i *)&v50->matrix.M41 = _mm_loadu_si128(v51 + 3);
      v22 = (int)v73;
    }
    else
    {
      v52 = this->camera;
      v53 = *(float *)(v22 + 80);
      v54 = *(float *)(v22 + 84);
      v52->matrix.M41 = *(float *)(v22 + 76);
      v52->matrix.M42 = v53;
      v52->matrix.M43 = v54;
    }
    v55 = this->camera;
    if ( *(_BYTE *)(v22 + 156) )
    {
      v55->dofFocus = *(float *)(v22 + 148);
    }
    else
    {
      v56 = (float)((float)((float)(v55->matrix.M42 - v78) * (float)(v55->matrix.M42 - v78))
                  + (float)((float)(v55->matrix.M41 - v77) * (float)(v55->matrix.M41 - v77)))
          + (float)((float)(v55->matrix.M43 - cameraPosition.x) * (float)(v55->matrix.M43 - cameraPosition.x));
      v57 = 0.0;
      if ( v56 != 0.0 )
        v57 = fsqrt(v56);
      v55->dofFocus = v57;
    }
    v58 = this->camera;
    v59 = *(float *)(v22 + 152);
    cameraTarget.x = 0.0;
    cameraTarget.y = 0.0;
    v58->dofRange = v59;
    v60 = this->camera;
    v61 = *(float *)(v22 + 144);
    cameraTarget.z = 0.0;
    v60->dofFactor = v61;
    v62 = this->camera->getFinalWorldMatrix(this->camera, &result);
    AudioEngine::setListener(this->game->audioEngine, v62, &cameraTarget);
    this->oldAc = (ACCamera *)v22;
  }
}
