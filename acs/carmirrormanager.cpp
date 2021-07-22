#include "carmirrormanager.h"
void CarMirrorManager::CarMirrorManager(CarMirrorManager *this, CarAvatar *icar, const Texture *mirrorTexture)
{
  CarMirrorManager *v3; // edi
  unsigned int v4; // ebx
  CarAvatar *v5; // eax
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  CarAvatar *v8; // ecx
  float v9; // esi
  std::wostream *v10; // eax
  const std::wstring *v11; // eax
  char v12; // al
  const std::wstring *v13; // eax
  Mesh *v14; // eax
  Material *v15; // esi
  Material *v16; // eax
  Game *v17; // eax
  std::_Ref_count_base *v18; // eax
  Material *v19; // edi
  Material *v20; // esi
  Material *v21; // eax
  std::_Ref_count_base *v22; // eax
  Material *v23; // esi
  std::wstring v24; // [esp-Ch] [ebp-200h] BYREF
  float value; // [esp+Ch] [ebp-1E8h]
  int v26; // [esp+24h] [ebp-1D0h]
  unsigned int v27; // [esp+28h] [ebp-1CCh]
  std::shared_ptr<Material> v28; // [esp+2Ch] [ebp-1C8h] BYREF
  std::shared_ptr<Material> v29; // [esp+34h] [ebp-1C0h] BYREF
  float v30; // [esp+3Ch] [ebp-1B8h]
  Material *v31; // [esp+40h] [ebp-1B4h]
  Texture *tex; // [esp+44h] [ebp-1B0h]
  CarMirrorManager *v33; // [esp+48h] [ebp-1ACh]
  std::vector<MirrorObject> *v34; // [esp+4Ch] [ebp-1A8h]
  vec3f v35; // [esp+50h] [ebp-1A4h] BYREF
  vec3f v36; // [esp+5Ch] [ebp-198h] BYREF
  CarMirrorManager *v37; // [esp+68h] [ebp-18Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v38; // [esp+6Ch] [ebp-188h] BYREF
  std::wstring iname; // [esp+11Ch] [ebp-D8h] BYREF
  MirrorObject mo; // [esp+134h] [ebp-C0h] BYREF
  unsigned int v41; // [esp+148h] [ebp-ACh]
  std::wstring oname; // [esp+14Ch] [ebp-A8h] BYREF
  std::wstring v43; // [esp+164h] [ebp-90h] BYREF
  std::wstring result; // [esp+17Ch] [ebp-78h] BYREF
  INIReader ini; // [esp+194h] [ebp-60h] BYREF
  int v46; // [esp+1F0h] [ebp-4h]

  v3 = this;
  v33 = this;
  v4 = 0;
  v27 = 0;
  tex = (Texture *)mirrorTexture;
  value = *(float *)&icar->game;
  v37 = this;
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  std::wstring::assign(&v24, L"MIRROR_MANAGER", 0xEu);
  GameObject::GameObject(v3, v24, (Game *)LODWORD(value));
  v3->__vftable = (CarMirrorManager_vtbl *)&CarMirrorManager::`vftable';
  v3->car = icar;
  v46 = 0;
  v34 = &v3->objects;
  v3->objects._Myfirst = 0;
  v3->objects._Mylast = 0;
  v3->objects._Myend = 0;
  v5 = v3->car;
  LOBYTE(v46) = 1;
  v6 = std::operator+<wchar_t>(&result, L"content/cars/", &v5->unixName);
  LOBYTE(v46) = 2;
  v7 = std::operator+<wchar_t>(&v43, v6, L"/data/mirrors.ini");
  v8 = v3->car;
  LOBYTE(v46) = 3;
  CarAvatar::openINI(v8, &ini, v7);
  if ( v43._Myres >= 8 )
    operator delete(v43._Bx._Ptr);
  v43._Myres = 7;
  v43._Mysize = 0;
  v43._Bx._Buf[0] = 0;
  LOBYTE(v46) = 6;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    v9 = 0.0;
    while ( 1 )
    {
      *(_DWORD *)v38.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v38.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v38.gap68);
      LOBYTE(v46) = 7;
      v4 |= 4u;
      v27 = v4;
      std::wiostream::basic_iostream<wchar_t>(&v38, &v38.gap10[8], 0);
      v46 = 8;
      *(_DWORD *)&v38.gap0[*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(CarMirrorManager **)((char *)&v37 + *(_DWORD *)(*(_DWORD *)v38.gap0 + 4)) = (CarMirrorManager *)(*(_DWORD *)(*(_DWORD *)v38.gap0 + 4) - 104);
      std::wstreambuf::wstreambuf(&v38.gap10[8]);
      *(_DWORD *)&v38.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v38.gap10[64] = 0;
      *(_DWORD *)&v38.gap10[68] = 0;
      value = v9;
      LOBYTE(v46) = 10;
      v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v38.gap10, "MIRROR_");
      std::wostream::operator<<(v10, LODWORD(value));
      ++LODWORD(v9);
      v30 = v9;
      v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &oname);
      LOBYTE(v46) = 11;
      v12 = INIReader::hasSection(&ini, v11);
      HIBYTE(v26) = v12;
      LOBYTE(v46) = 10;
      if ( oname._Myres >= 8 )
      {
        operator delete(oname._Bx._Ptr);
        v12 = HIBYTE(v26);
      }
      if ( !v12 )
        break;
      v41 = 7;
      mo.outMaterial._Rep = 0;
      LOWORD(mo.mesh) = 0;
      std::wstring::assign((std::wstring *)&mo, L"NAME", 4u);
      LOBYTE(v46) = 12;
      v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &iname);
      LOBYTE(v46) = 13;
      INIReader::getString(&ini, &oname, v13, (const std::wstring *)&mo);
      if ( iname._Myres >= 8 )
        operator delete(iname._Bx._Ptr);
      iname._Myres = 7;
      iname._Mysize = 0;
      iname._Bx._Buf[0] = 0;
      LOBYTE(v46) = 16;
      if ( v41 >= 8 )
        operator delete(mo.mesh);
      LODWORD(value) = 1;
      v41 = 7;
      mo.outMaterial._Rep = 0;
      LOWORD(mo.mesh) = 0;
      v24._Mysize = 0;
      v24._Myres = 7;
      v24._Bx._Buf[0] = 0;
      std::wstring::assign(&v24, &oname, 0, 0xFFFFFFFF);
      v14 = Node::getNodeChild<Mesh>(v3->car->bodyTransform, v24, SLOBYTE(value));
      if ( v14 && v14->material._Ptr )
      {
        *(_OWORD *)&mo.inMaterial._Ptr = 0i64;
        LOBYTE(v46) = 17;
        mo.mesh = v14;
        v15 = (Material *)operator new(104);
        v31 = v15;
        v16 = 0;
        LOBYTE(v46) = 18;
        if ( v15 )
        {
          iname._Myres = 7;
          iname._Mysize = 0;
          iname._Bx._Buf[0] = 0;
          std::wstring::assign(&iname, L"MIRROR_IN", 9u);
          v17 = v3->game;
          v4 |= 1u;
          LOBYTE(v46) = 19;
          v27 = v4;
          Material::Material(v15, &iname, v17->graphics);
        }
        v46 = 20;
        v29._Ptr = 0;
        v29._Rep = 0;
        std::shared_ptr<Material>::_Resetp<Material>(&v29, v16);
        v18 = v29._Rep;
        v19 = v29._Ptr;
        v29._Rep = 0;
        v29._Ptr = 0;
        mo.inMaterial._Rep = v18;
        mo.inMaterial._Ptr = v19;
        v46 = 17;
        if ( (v4 & 1) != 0 )
        {
          v4 &= 0xFFFFFFFE;
          v27 = v4;
          if ( iname._Myres >= 8 )
            operator delete(iname._Bx._Ptr);
        }
        v20 = (Material *)operator new(104);
        v31 = v20;
        v21 = 0;
        LOBYTE(v46) = 21;
        if ( v20 )
        {
          iname._Myres = 7;
          iname._Mysize = 0;
          iname._Bx._Buf[0] = 0;
          std::wstring::assign(&iname, L"MIRROR_IN", 9u);
          v4 |= 2u;
          LOBYTE(v46) = 22;
          v27 = v4;
          Material::Material(v20, &iname, v33->game->graphics);
        }
        v46 = 23;
        v28._Ptr = 0;
        v28._Rep = 0;
        std::shared_ptr<Material>::_Resetp<Material>(&v28, v21);
        v22 = v28._Rep;
        v23 = v28._Ptr;
        v28._Rep = 0;
        v28._Ptr = 0;
        mo.outMaterial._Rep = v22;
        mo.outMaterial._Ptr = v23;
        v46 = 17;
        if ( (v4 & 2) != 0 )
        {
          v4 &= 0xFFFFFFFD;
          if ( iname._Myres >= 8 )
            operator delete(iname._Bx._Ptr);
        }
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksPerPixel", 0xAu);
        LOBYTE(v46) = 24;
        Material::setShader(v19, v4, &iname);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"txDiffuse", 9u);
        LOBYTE(v46) = 25;
        Material::setTexture(v19, &iname, tex);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksDiffuse", 9u);
        LOBYTE(v46) = 26;
        Material::setVar(v19, &iname, 0.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksAmbient", 9u);
        LOBYTE(v46) = 27;
        Material::setVar(v19, &iname, 0.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksEmissive", 0xAu);
        LOBYTE(v46) = 28;
        v35.x = 1.0;
        v35.y = 1.0;
        v35.z = 1.0;
        Material::setVar(v19, &iname, &v35);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksSpecular", 0xAu);
        LOBYTE(v46) = 29;
        Material::setVar(v19, &iname, 0.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksSpecularEXP", 0xDu);
        LOBYTE(v46) = 30;
        Material::setVar(v19, &iname, 1.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksPerPixelReflection", 0x14u);
        LOBYTE(v46) = 31;
        Material::setShader(v23, v4, &iname);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"txDiffuse", 9u);
        LOBYTE(v46) = 32;
        Material::setTexture(v23, &iname, tex);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        std::wstring::assign(&iname, L"ksDiffuse", 9u);
        LOBYTE(v46) = 33;
        Material::setVar(v23, &iname, 0.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        std::wstring::wstring(&iname, L"ksAmbient");
        LOBYTE(v46) = 34;
        Material::setVar(v23, &iname, 0.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        std::wstring::wstring(&iname, L"ksEmissive");
        LOBYTE(v46) = 35;
        v36.x = 1.0;
        v36.y = 1.0;
        v36.z = 1.0;
        Material::setVar(v23, &iname, &v36);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        std::wstring::wstring(&iname, L"ksSpecular");
        LOBYTE(v46) = 36;
        Material::setVar(v23, &iname, 0.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        std::wstring::wstring(&iname, L"ksSpecularEXP");
        LOBYTE(v46) = 37;
        Material::setVar(v23, &iname, 255.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        std::wstring::wstring(&iname, L"fresnelMaxLevel");
        LOBYTE(v46) = 38;
        Material::setVar(v23, &iname, 1.0);
        LOBYTE(v46) = 17;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        std::vector<MirrorObject>::push_back(v34, &mo);
        MirrorObject::~MirrorObject(&mo);
        v3 = v33;
        v9 = v30;
      }
      if ( oname._Myres >= 8 )
        operator delete(oname._Bx._Ptr);
      LOBYTE(v46) = 6;
      *(_DWORD *)&v38.gap0[*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(CarMirrorManager **)((char *)&v37 + *(_DWORD *)(*(_DWORD *)v38.gap0 + 4)) = (CarMirrorManager *)(*(_DWORD *)(*(_DWORD *)v38.gap0 + 4) - 104);
      *(_DWORD *)&v38.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v38.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v38.gap68);
    }
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v38);
  }
  LOBYTE(v46) = 1;
  INIReader::~INIReader(&ini);
}
void CarMirrorManager::~CarMirrorManager(CarMirrorManager *this)
{
  this->__vftable = (CarMirrorManager_vtbl *)&CarMirrorManager::`vftable';
  if ( this->objects._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->objects);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<MirrorObject>>>(this->objects._Myfirst, this->objects._Mylast);
    operator delete(this->objects._Myfirst);
    this->objects._Myfirst = 0;
    this->objects._Mylast = 0;
    this->objects._Myend = 0;
  }
  GameObject::~GameObject(this);
}
CarMirrorManager *CarMirrorManager::`scalar deleting destructor'(CarMirrorManager *this, unsigned int a2)
{
  CarMirrorManager::~CarMirrorManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CarMirrorManager::update(CarMirrorManager *this, float dt)
{
  bool v3; // al
  MirrorObject *v4; // edi
  MirrorObject *v5; // esi
  std::_Ref_count_base **v6; // ebp
  Mesh *v7; // edx
  std::_Ref_count_base *v8; // eax
  Material *v9; // ecx
  volatile signed __int32 *v10; // ebx
  bool v11; // [esp+Bh] [ebp-9h]
  std::_Ref_count_base *v12; // [esp+10h] [ebp-4h]

  v3 = ACCameraManager::isCameraOnBoard(this->car->sim->cameraManager, this->car);
  v4 = this->objects._Mylast;
  v5 = this->objects._Myfirst;
  v11 = v3;
  if ( v5 != v4 )
  {
    v6 = &v5->outMaterial._Rep;
    do
    {
      v7 = v5->mesh;
      if ( v3 )
      {
        v8 = *(v6 - 2);
        v9 = (Material *)*(v6 - 3);
        if ( v8 )
          _InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 1u);
      }
      else
      {
        v8 = *v6;
        v9 = (Material *)*(v6 - 1);
        v12 = *v6;
        if ( *v6 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 1u);
          v8 = v12;
        }
      }
      v10 = (volatile signed __int32 *)v7->material._Rep;
      v7->material._Rep = v8;
      v7->material._Ptr = v9;
      if ( v10 && !_InterlockedExchangeAdd(v10 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v10)(v10);
        if ( !_InterlockedExchangeAdd(v10 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v10 + 4))(v10);
      }
      v3 = v11;
      ++v5;
      v6 += 5;
    }
    while ( v5 != v4 );
  }
}
