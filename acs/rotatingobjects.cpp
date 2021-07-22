#include "rotatingobjects.h"
void RotatingObjects::RotatingObjects(RotatingObjects *this, CarAvatar *a_car)
{
  int v3; // ebx
  CarAvatar *v4; // eax
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  CarAvatar *v7; // ecx
  Game *v8; // edi
  std::wostream *v9; // eax
  const std::wstring *v10; // eax
  bool v11; // bl
  const std::wstring *v12; // eax
  std::wstring *v13; // esi
  CarAvatar *v14; // eax
  const std::wstring *v15; // eax
  vec3f *v16; // eax
  __int64 v17; // xmm0_8
  float v18; // eax
  const std::wstring *v19; // eax
  int v20; // eax
  std::wstring v21; // [esp-Ch] [ebp-1F4h] BYREF
  unsigned int v22; // [esp+Ch] [ebp-1DCh]
  __int64 v23; // [esp+28h] [ebp-1C0h]
  RotatingObjects *v24; // [esp+30h] [ebp-1B8h]
  RotatingObject ro; // [esp+34h] [ebp-1B4h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v26; // [esp+48h] [ebp-1A0h] BYREF
  vec3f v27; // [esp+F8h] [ebp-F0h] BYREF
  std::wstring key; // [esp+104h] [ebp-E4h] BYREF
  std::wstring v29; // [esp+11Ch] [ebp-CCh] BYREF
  std::wstring _Left; // [esp+134h] [ebp-B4h] BYREF
  std::wstring v31; // [esp+14Ch] [ebp-9Ch] BYREF
  std::wstring v32; // [esp+164h] [ebp-84h] BYREF
  std::wstring result; // [esp+17Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+194h] [ebp-54h] BYREF
  int v35; // [esp+1E4h] [ebp-4h]

  v3 = 0;
  LODWORD(v23) = 0;
  v24 = this;
  v22 = (unsigned int)a_car->game;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, L"ROTATING_OBJECTS", 0x10u);
  GameObject::GameObject(this, v21, (Game *)v22);
  this->__vftable = (RotatingObjects_vtbl *)&RotatingObjects::`vftable';
  v35 = 0;
  this->objects._Myfirst = 0;
  this->objects._Mylast = 0;
  this->objects._Myend = 0;
  v22 = 13;
  LOBYTE(v35) = 1;
  v21._Myres = (unsigned int)L"content/cars/";
  this->car = a_car;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, (const wchar_t *)v21._Myres, v22);
  v4 = this->car;
  LOBYTE(v35) = 2;
  v5 = std::operator+<wchar_t>(&result, &_Left, &v4->unixName);
  LOBYTE(v35) = 3;
  v6 = std::operator+<wchar_t>(&v32, v5, L"/data/extra_animations.ini");
  v7 = this->car;
  LOBYTE(v35) = 4;
  CarAvatar::openINI(v7, &ini, v6);
  if ( v32._Myres >= 8 )
    operator delete(v32._Bx._Ptr);
  v32._Myres = 7;
  v32._Mysize = 0;
  v32._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v35) = 8;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&ini, 0);
  if ( ini.ready )
  {
    v8 = 0;
    while ( 1 )
    {
      *(_DWORD *)v26.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v26.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v26.gap68);
      LOBYTE(v35) = 9;
      LODWORD(v23) = v3 | 1;
      std::wiostream::basic_iostream<wchar_t>(&v26, &v26.gap10[8], 0);
      v35 = 10;
      *(_DWORD *)&v26.gap0[*(_DWORD *)(*(_DWORD *)v26.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&ro.axis.z + *(_DWORD *)(*(_DWORD *)v26.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v26.gap0 + 4)
                                                                             - 104;
      std::wstreambuf::wstreambuf(&v26.gap10[8]);
      *(_DWORD *)&v26.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v26.gap10[64] = 0;
      *(_DWORD *)&v26.gap10[68] = 0;
      v22 = (unsigned int)v8;
      LOBYTE(v35) = 12;
      v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v26.gap10, "ROTATING_OBJECT_");
      std::wostream::operator<<(v9, v22);
      v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v26, &v29);
      LOBYTE(v35) = 13;
      v11 = INIReader::hasSection(&ini, v10);
      LOBYTE(v35) = 12;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      if ( !v11 )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"NAME", 4u);
      LOBYTE(v35) = 14;
      v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v26, &v29);
      LOBYTE(v35) = 15;
      v13 = INIReader::getString(&ini, &v31, v12, &key);
      v14 = this->car;
      LOBYTE(v35) = 16;
      ro.target = v14->carNode->findChildByName(v14->carNode, v13, 1);
      if ( v31._Myres >= 8 )
        operator delete(v31._Bx._Ptr);
      v31._Myres = 7;
      v31._Mysize = 0;
      v31._Bx._Buf[0] = 0;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      LOBYTE(v35) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"AXIS", 4u);
      LOBYTE(v35) = 17;
      v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v26, &v29);
      LOBYTE(v35) = 18;
      v16 = INIReader::getFloat3(&ini, &v27, v15, &key);
      v17 = *(_QWORD *)&v16->x;
      v18 = v16->z;
      *(_QWORD *)&ro.axis.x = v17;
      ro.axis.z = v18;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      LOBYTE(v35) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"RPM", 3u);
      LOBYTE(v35) = 19;
      v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v26, &v29);
      LOBYTE(v35) = 20;
      *((float *)&v23 + 1) = (float)INIReader::getInt(&ini, v19, &key);
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      LOBYTE(v35) = 12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      ro.rotationStep = *((float *)&v23 + 1) * 6.0;
      std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element>>::push_back(
        (std::vector<TyreTestFrame> *)&this->objects,
        (const TyreTestFrame *)&ro);
      v8 = (Game *)((char *)v8 + 1);
      LOBYTE(v35) = 8;
      *(_DWORD *)&v26.gap0[*(_DWORD *)(*(_DWORD *)v26.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&ro.axis.z + *(_DWORD *)(*(_DWORD *)v26.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v26.gap0 + 4)
                                                                             - 104;
      *(_DWORD *)&v26.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v26.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v26.gap10[8]) )
          std::wstreambuf::epptr(&v26.gap10[8]);
        else
          std::wstreambuf::egptr(&v26.gap10[8]);
        std::wstreambuf::eback(&v26.gap10[8]);
        v20 = std::wstreambuf::eback(&v26.gap10[8]);
        operator delete(v20);
      }
      std::wstreambuf::setg(&v26.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v26.gap10[8], 0, 0);
      *(_DWORD *)&v26.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v26.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v26.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v26.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v26.gap68);
      v3 = v23;
    }
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v26);
  }
  LOBYTE(v35) = 1;
  INIReader::~INIReader(&ini);
}
RotatingObjects *RotatingObjects::`vector deleting destructor'(RotatingObjects *this, unsigned int a2)
{
  this->__vftable = (RotatingObjects_vtbl *)&RotatingObjects::`vftable';
  if ( this->objects._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->objects);
    operator delete(this->objects._Myfirst);
    this->objects._Myfirst = 0;
    this->objects._Mylast = 0;
    this->objects._Myend = 0;
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge RotatingObjects::update(RotatingObjects *this@<ecx>, int a2@<edi>, int a3@<esi>, float dt)
{
  CarAvatar *v5; // eax
  RotatingObject *v6; // edi
  RotatingObject *v7; // esi
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm4_4
  Node *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  __int128 v18; // xmm3
  float v19; // xmm1_4
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  __int128 v23; // xmm2
  __int128 v24; // xmm1
  __m128 v25; // xmm0
  Node *v26; // eax
  float v29; // [esp+Ch] [ebp-8Ch]
  float *v30; // [esp+10h] [ebp-88h]
  float v31; // [esp+14h] [ebp-84h]
  mat44f v32; // [esp+18h] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+58h] [ebp-40h] BYREF

  ReplayManager::isInReplaymode(this->car->sim->replayManager);
  v5 = this->car;
  if ( v5->physicsState.engineLifeLeft > 0.0 && v5->physicsState.fuel > 0.0 )
  {
    v6 = this->objects._Mylast;
    v7 = this->objects._Myfirst;
    if ( v7 != v6 )
    {
      v30 = &v7->axis.y;
      do
      {
        v31 = __libm_sse2_cosf(a2, a3).m128_f32[0];
        v29 = __libm_sse2_sinf().m128_f32[0];
        mat44f::mat44f(&v32);
        v8 = *v30;
        v9 = *(v30 - 1);
        v10 = v30[1];
        v11 = v7->target;
        v32.M44 = 1.0;
        v32.M22 = (float)((float)(v8 * v8) * (float)(1.0 - v31)) + v31;
        v32.M11 = (float)((float)(v9 * v9) * (float)(1.0 - v31)) + v31;
        v32.M33 = (float)((float)(v10 * v10) * (float)(1.0 - v31)) + v31;
        v12 = (float)(v9 * v8) * (float)(1.0 - v31);
        v13 = v8 * v29;
        v32.M12 = (float)(v10 * v29) + v12;
        v32.M21 = v12 - (float)(v10 * v29);
        v14 = (float)(v9 * v10) * (float)(1.0 - v31);
        v15 = v9 * v29;
        v16 = (float)(v10 * v8) * (float)(1.0 - v31);
        v17 = v14 - (float)(v8 * v29);
        M2.r[3] = *(__m128 *)&v11->matrix.M41;
        v18 = *(_OWORD *)&v32.M41;
        v19 = v13 + v14;
        v20 = *(__m128 *)&v11->matrix.M31;
        v32.M13 = v17;
        M2.r[2] = v20;
        v32.M31 = v19;
        v21 = *(__m128 *)&v11->matrix.M21;
        v32.M23 = v15 + v16;
        v22 = *(__m128 *)&v11->matrix.M11;
        v32.M32 = v16 - v15;
        v23 = *(_OWORD *)&v32.M31;
        M2.r[0] = v22;
        M2.r[1] = v21;
        v24 = *(_OWORD *)&v32.M21;
        v25 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v32.M11);
        v26 = v7->target;
        *(__m128 *)&v26->matrix.M11 = v25;
        ++v7;
        *(_OWORD *)&v26->matrix.M21 = v24;
        *(_OWORD *)&v26->matrix.M31 = v23;
        *(_OWORD *)&v26->matrix.M41 = v18;
        v30 += 5;
      }
      while ( v7 != v6 );
    }
  }
}
