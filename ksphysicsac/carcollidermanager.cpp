#include "carcollidermanager.h
void CarColliderManager::CarColliderManager(CarColliderManager *this)
{
  std::wstring a_filename; // [esp+Ch] [ebp-28h] BYREF
  int v3; // [esp+30h] [ebp-4h]

  this->isLive = 0;
  this->boxes._Myfirst = 0;
  this->boxes._Mylast = 0;
  this->boxes._Myend = 0;
  v3 = 0;
  a_filename._Myres = 7;
  a_filename._Mysize = 0;
  a_filename._Bx._Buf[0] = 0;
  std::wstring::assign(&a_filename, word_17BE9D8, 0);
  LOBYTE(v3) = 1;
  FileChangeObserver::FileChangeObserver(&this->observer, &a_filename);
  if ( a_filename._Myres >= 8 )
    operator delete(a_filename._Bx._Ptr);
  this->carModel._Myres = 7;
  this->carModel._Mysize = 0;
  this->carModel._Bx._Buf[0] = 0;
  this->carBody = 0;
  this->car = 0;
}
void CarColliderManager::~CarColliderManager(CarColliderManager *this)
{
  if ( this->carModel._Myres >= 8 )
    operator delete(this->carModel._Bx._Ptr);
  this->carModel._Myres = 7;
  this->carModel._Mysize = 0;
  this->carModel._Bx._Buf[0] = 0;
  BonusInfo::~BonusInfo((SGearRatio *)&this->observer);
  if ( this->boxes._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->boxes);
    operator delete(this->boxes._Myfirst);
    this->boxes._Myfirst = 0;
    this->boxes._Mylast = 0;
    this->boxes._Myend = 0;
  }
}
CarCollisionBox *__userpurge CarColliderManager::getBox@<eax>(CarColliderManager *this@<ecx>, __m128 a2@<xmm0>, CarCollisionBox *result, int index)
{
  CarCollisionBox *v4; // ecx
  CarCollisionBox *v5; // eax

  if ( index < 0 || index >= this->boxes._Mylast - this->boxes._Myfirst )
  {
    v5 = result;
    a2.m128_f32[0] = 0.0;
    result->centre.x = 0.0;
    result->centre.y = 0.0;
    result->centre.z = 0.0;
    result->size.x = 0.0;
    result->size.y = 0.0;
    result->size.z = 0.0;
    *(_QWORD *)&result->centre.x = _mm_unpacklo_ps(a2, (__m128)0i64).m128_u64[0];
    result->centre.z = 0.0;
    *(_QWORD *)&result->size.x = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64).m128_u64[0];
    result->id = 0;
    result->size.z = 0.0;
  }
  else
  {
    v4 = this->boxes._Myfirst;
    v5 = result;
    *(__m128i *)&result->centre.x = _mm_loadu_si128((const __m128i *)&v4[index]);
    *(_QWORD *)&result->size.y = *(_QWORD *)&v4[index].size.y;
    result->id = v4[index].id;
  }
  return v5;
}
void CarColliderManager::init(CarColliderManager *this, Car *acar)
{
  std::wstring *v3; // ecx

  this->car = acar;
  v3 = &this->carModel;
  this->isLive = 0;
  this->carBody = acar->body;
  if ( v3 != &acar->unixName )
    std::wstring::assign(v3, &acar->unixName, 0, 0xFFFFFFFF);
  CarColliderManager::loadINI(this);
}
void CarColliderManager::loadINI(CarColliderManager *this)
{
  CarColliderManager *v1; // esi
  int v2; // edi
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Car *v5; // ecx
  int v6; // ebx
  std::wostream *v7; // eax
  const std::wstring *v8; // eax
  bool v9; // bl
  const std::wstring *v10; // esi
  const std::wstring *v11; // edi
  vec3f *v12; // esi
  vec3f *v13; // eax
  int v14; // eax
  int v15; // [esp+30h] [ebp-1F8h]
  int v16; // [esp+34h] [ebp-1F4h]
  CarCollisionBox box; // [esp+3Ch] [ebp-1ECh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v19; // [esp+58h] [ebp-1D0h] BYREF
  vec3f v20; // [esp+108h] [ebp-120h] BYREF
  vec3f v21; // [esp+114h] [ebp-114h] BYREF
  std::wstring v22; // [esp+120h] [ebp-108h] BYREF
  std::wstring v23; // [esp+138h] [ebp-F0h] BYREF
  std::wstring key; // [esp+150h] [ebp-D8h] BYREF
  std::wstring v25; // [esp+168h] [ebp-C0h] BYREF
  std::wstring v26; // [esp+180h] [ebp-A8h] BYREF
  std::wstring result; // [esp+198h] [ebp-90h] BYREF
  std::wstring filename; // [esp+1B0h] [ebp-78h] BYREF
  INIReader r; // [esp+1C8h] [ebp-60h] BYREF
  int v30; // [esp+224h] [ebp-4h]

  v1 = this;
  v2 = 0;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &this->carModel);
  v30 = 0;
  v4 = std::operator+<wchar_t>(&v25, v3, L"/data/colliders.ini");
  v5 = v1->car;
  LOBYTE(v30) = 1;
  Car::getConfigPath(v5, &filename, v4);
  if ( v25._Myres >= 8 )
    operator delete(v25._Bx._Ptr);
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  LOBYTE(v30) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&r, &filename);
  LOBYTE(v30) = 5;
  if ( r.ready )
  {
    std::_Container_base0::_Orphan_all(&v1->boxes);
    v6 = 0;
    v1->boxes._Mylast = v1->boxes._Myfirst;
    v15 = 0;
    while ( 1 )
    {
      *(_DWORD *)v19.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v19.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v19.gap68);
      LOBYTE(v30) = 6;
      v16 = v2 | 1;
      std::wiostream::basic_iostream<wchar_t>(&v19, &v19.gap10[8], 0);
      v30 = 7;
      *(_DWORD *)&v19.gap0[*(_DWORD *)(*(_DWORD *)v19.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(unsigned int *)((char *)&box.id + *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)
                                                                                - 104;
      std::wstreambuf::wstreambuf(&v19.gap10[8]);
      *(_DWORD *)&v19.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v19.gap10[64] = 0;
      *(_DWORD *)&v19.gap10[68] = 0;
      LOBYTE(v30) = 9;
      v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v19.gap10, "COLLIDER_");
      std::wostream::operator<<(v7, v6);
      v8 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v19, &v23);
      LOBYTE(v30) = 10;
      v9 = INIReader::hasSection(&r, v8);
      LOBYTE(v30) = 9;
      if ( v23._Myres >= 8 )
        operator delete(v23._Bx._Ptr);
      if ( !v9 )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"SIZE", 4u);
      LOBYTE(v30) = 11;
      v22._Myres = 7;
      v22._Mysize = 0;
      v22._Bx._Buf[0] = 0;
      std::wstring::assign(&v22, L"CENTRE", 6u);
      LOBYTE(v30) = 12;
      v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v19, &v23);
      LOBYTE(v30) = 13;
      v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v19, &v26);
      LOBYTE(v30) = 14;
      v12 = INIReader::getFloat3(&r, &v21, v10, &key);
      v13 = INIReader::getFloat3(&r, &v20, v11, &v22);
      *(_OWORD *)&box.centre.x = 0i64;
      box.size.y = 0.0;
      box.size.z = 0.0;
      box.id = 0;
      box.centre = *v13;
      box.size = *v12;
      if ( v26._Myres >= 8 )
        operator delete(v26._Bx._Ptr);
      v26._Myres = 7;
      v26._Mysize = 0;
      v26._Bx._Buf[0] = 0;
      if ( v23._Myres >= 8 )
        operator delete(v23._Bx._Ptr);
      v23._Myres = 7;
      v23._Mysize = 0;
      v23._Bx._Buf[0] = 0;
      if ( v22._Myres >= 8 )
        operator delete(v22._Bx._Ptr);
      v22._Myres = 7;
      v22._Mysize = 0;
      v22._Bx._Buf[0] = 0;
      LOBYTE(v30) = 9;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      box.id = this->carBody->addBoxCollider(
                 this->carBody,
                 (const vec3f *)&box,
                 &box.size,
                 4u,
                 1u,
                 this->car->physicsGUID + 1);
      std::vector<GrooveMesh>::push_back(&this->boxes, &box);
      v6 = v15 + 1;
      LOBYTE(v30) = 5;
      ++v15;
      *(_DWORD *)&v19.gap0[*(_DWORD *)(*(_DWORD *)v19.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(unsigned int *)((char *)&box.id + *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)
                                                                                - 104;
      *(_DWORD *)&v19.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v19.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v19.gap10[8]) )
          std::wstreambuf::epptr(&v19.gap10[8]);
        else
          std::wstreambuf::egptr(&v19.gap10[8]);
        std::wstreambuf::eback(&v19.gap10[8]);
        v14 = std::wstreambuf::eback(&v19.gap10[8]);
        operator delete(v14);
      }
      std::wstreambuf::setg(&v19.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v19.gap10[8], 0, 0);
      *(_DWORD *)&v19.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v19.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v19.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v19.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v19.gap68);
      v2 = v16;
    }
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v19);
  }
  LOBYTE(v30) = 4;
  INIReader::~INIReader(&r);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void CarColliderManager::step(CarColliderManager *this, float dt)
{
  if ( this->isLive )
  {
    if ( FileChangeObserver::hasChanged(&this->observer) )
    {
      this->carBody->removeCollisionObjects(this->carBody);
      INIReader::clearCache();
      CarColliderManager::loadINI(this);
    }
  }
}
