#include "brakediscgraphics.h"
void BrakeDiscGraphics::BrakeDiscGraphics(BrakeDiscGraphics *this, CarAvatar *car)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  bool v5; // bl
  double v6; // st7
  bool v7; // cf
  double v8; // st7
  std::wstring *v9; // esi
  float *v10; // ecx
  MaterialVar ***v11; // ebx
  Node **v12; // esi
  Node **i; // edi
  int v14; // eax
  void (*v15)(void *); // ecx
  std::wstring *v16; // eax
  Material *v17; // ecx
  Material *v18; // eax
  int v19; // eax
  int v20; // edx
  int v21; // ecx
  MaterialVar *v22; // eax
  MaterialVar **v23; // edx
  std::vector<ICollisionObject *> *v24; // ecx
  int v25; // eax
  ICollisionObject **v26; // edx
  _DWORD *v27; // ecx
  MaterialVar **v28; // eax
  MaterialVar *v29; // eax
  MaterialVar **v30; // edx
  std::vector<ICollisionObject *> *v31; // ecx
  int v32; // eax
  std::_Ref_count_base *v33; // edx
  std::_Ref_count_base *v34; // ecx
  int v35; // eax
  void (*v36)(void *); // ecx
  std::wstring *v37; // eax
  int v38; // edi
  double v39; // st7
  std::wstring v40; // [esp-1Ch] [ebp-1B8h] BYREF
  unsigned int v41; // [esp-4h] [ebp-1A0h]
  int v42; // [esp+10h] [ebp-18Ch]
  float v43; // [esp+14h] [ebp-188h]
  float *v44; // [esp+18h] [ebp-184h]
  std::shared_ptr<Material> mat; // [esp+1Ch] [ebp-180h] BYREF
  MaterialVar *v46; // [esp+24h] [ebp-178h] BYREF
  MaterialVar *v47; // [esp+28h] [ebp-174h] BYREF
  std::wstring *v48; // [esp+2Ch] [ebp-170h]
  std::vector<Node *> result; // [esp+30h] [ebp-16Ch] BYREF
  BrakeDiscGraphics *v50; // [esp+3Ch] [ebp-160h]
  CarAvatar *v51; // [esp+40h] [ebp-15Ch]
  Material *v52; // [esp+44h] [ebp-158h]
  BrakeDiscGraphics *v53; // [esp+48h] [ebp-154h]
  std::wstring vname; // [esp+4Ch] [ebp-150h] BYREF
  std::wstring disc_name; // [esp+64h] [ebp-138h] BYREF
  std::wstring key; // [esp+7Ch] [ebp-120h] BYREF
  std::wstring section; // [esp+94h] [ebp-108h] BYREF
  std::wstring v58; // [esp+ACh] [ebp-F0h] BYREF
  std::wstring v59; // [esp+C4h] [ebp-D8h] BYREF
  INIReader ini; // [esp+DCh] [ebp-C0h] BYREF
  std::wstring keys[4]; // [esp+124h] [ebp-78h] BYREF
  int v62; // [esp+198h] [ebp-4h]

  v50 = this;
  v53 = this;
  v51 = car;
  v41 = (unsigned int)car->game;
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  std::wstring::assign(&v40, L"BRAKE_DISC_GRAPHICS", 0x13u);
  GameObject::GameObject(this, v40, (Game *)v41);
  v41 = (unsigned int)std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>;
  v40._Myres = (unsigned int)std::vector<MaterialVar *>::vector<MaterialVar *>;
  v40._Mysize = 4;
  *(_DWORD *)&v40._Bx._Alias[12] = 12;
  v62 = 0;
  *(_DWORD *)&v40._Bx._Alias[8] = this->glowVars;
  this->__vftable = (BrakeDiscGraphics_vtbl *)&BrakeDiscGraphics::`vftable';
  this->car = car;
  `eh vector constructor iterator'(
    *(void **)&v40._Bx._Alias[8],
    *(unsigned int *)&v40._Bx._Alias[12],
    v40._Mysize,
    (void (*)(void *))v40._Myres,
    (void (*)(void *))v41);
  LOBYTE(v62) = 1;
  `eh vector constructor iterator'(
    this->blurVars,
    0xCu,
    4,
    (void (*)(void *))std::vector<MaterialVar *>::vector<MaterialVar *>,
    (void (*)(void *))std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>);
  LOBYTE(v62) = 2;
  v41 = (unsigned int)&car->unixName;
  this->lag_hot = 0.89999998;
  v40._Myres = (unsigned int)L"content/cars/";
  v40._Mysize = (unsigned int)&v58;
  this->lag_cool = 0.99000001;
  v3 = std::operator+<wchar_t>((std::wstring *)v40._Mysize, (const wchar_t *)v40._Myres, (const std::wstring *)v41);
  LOBYTE(v62) = 3;
  v4 = std::operator+<wchar_t>(&v59, v3, L"/data/brakes.ini");
  LOBYTE(v62) = 4;
  CarAvatar::openINI(car, &ini, v4);
  if ( v59._Myres >= 8 )
    operator delete(v59._Bx._Ptr);
  v59._Myres = 7;
  v59._Mysize = 0;
  v59._Bx._Buf[0] = 0;
  LOBYTE(v62) = 7;
  if ( v58._Myres >= 8 )
    operator delete(v58._Bx._Ptr);
  v58._Myres = 7;
  v58._Mysize = 0;
  v58._Bx._Buf[0] = 0;
  keys[0]._Myres = 7;
  keys[0]._Mysize = 0;
  keys[0]._Bx._Buf[0] = 0;
  std::wstring::assign(keys, L"DISC_LF", 7u);
  LOBYTE(v62) = 8;
  keys[1]._Myres = 7;
  keys[1]._Mysize = 0;
  keys[1]._Bx._Buf[0] = 0;
  std::wstring::assign(&keys[1], L"DISC_RF", 7u);
  LOBYTE(v62) = 9;
  keys[2]._Myres = 7;
  keys[2]._Mysize = 0;
  keys[2]._Bx._Buf[0] = 0;
  std::wstring::assign(&keys[2], L"DISC_LR", 7u);
  LOBYTE(v62) = 10;
  keys[3]._Myres = 7;
  keys[3]._Mysize = 0;
  keys[3]._Bx._Buf[0] = 0;
  std::wstring::assign(&keys[3], L"DISC_RR", 7u);
  LOBYTE(v62) = 11;
  if ( ini.ready )
  {
    disc_name._Myres = 7;
    disc_name._Mysize = 0;
    disc_name._Bx._Buf[0] = 0;
    std::wstring::assign(&disc_name, L"DISCS_GRAPHICS", 0xEu);
    LOBYTE(v62) = 12;
    v5 = INIReader::hasSection(&ini, &disc_name);
    LOBYTE(v62) = 11;
    if ( disc_name._Myres >= 8 )
      operator delete(disc_name._Bx._Ptr);
    if ( v5 )
    {
      std::wstring::wstring(&key, L"LAG_HOT");
      LOBYTE(v62) = 13;
      std::wstring::wstring(&disc_name, L"DISCS_GRAPHICS");
      LOBYTE(v62) = 14;
      v6 = INIReader::getFloat(&ini, &disc_name, &key);
      v7 = disc_name._Myres < 8;
      v43 = v6;
      this->lag_hot = (float)(1.0 - v43) * 59.999996;
      if ( !v7 )
        operator delete(disc_name._Bx._Ptr);
      disc_name._Myres = 7;
      disc_name._Mysize = 0;
      disc_name._Bx._Buf[0] = 0;
      LOBYTE(v62) = 11;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"LAG_COOL");
      LOBYTE(v62) = 15;
      std::wstring::wstring(&disc_name, L"DISCS_GRAPHICS");
      LOBYTE(v62) = 16;
      v8 = INIReader::getFloat(&ini, &disc_name, &key);
      v7 = disc_name._Myres < 8;
      v43 = v8;
      this->lag_cool = (float)(1.0 - v43) * 59.999996;
      if ( !v7 )
        operator delete(disc_name._Bx._Ptr);
      disc_name._Myres = 7;
      disc_name._Mysize = 0;
      disc_name._Bx._Buf[0] = 0;
      LOBYTE(v62) = 11;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v9 = keys;
      v43 = 0.0;
      v10 = this->maxGlow;
      v48 = keys;
      v44 = this->maxGlow;
      v11 = &this->blurVars[0]._Mylast;
      do
      {
        v41 = 14;
        *(v10 - 4) = 0.0;
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        std::wstring::assign(&section, L"DISCS_GRAPHICS", v41);
        LOBYTE(v62) = 17;
        INIReader::getString(&ini, &disc_name, &section, v9);
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        result._Myfirst = 0;
        result._Mylast = 0;
        result._Myend = 0;
        LOBYTE(v62) = 20;
        v51->carNode->findChildrenByName(v51->carNode, &disc_name, &result);
        v12 = result._Myfirst;
        for ( i = result._Mylast; v12 != i; ++v12 )
        {
          v14 = __RTDynamicCast(*v12, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
          v42 = v14;
          if ( v14 )
          {
            if ( std::wstring::compare(
                   (std::wstring *)(*(_DWORD *)(*(_DWORD *)(v14 + 248) + 24) + 4),
                   0,
                   *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v14 + 248) + 24) + 20),
                   L"ksBrakeDisc",
                   0xBu) )
            {
              v35 = *(_DWORD *)(v42 + 248);
              v36 = (void (*)(void *))(*(_DWORD *)(v35 + 24) + 4);
              if ( *(_DWORD *)(*(_DWORD *)(v35 + 24) + 24) >= 8u )
                v36 = *(void (**)(void *))v36;
              v37 = &disc_name;
              v41 = (unsigned int)v36;
              if ( disc_name._Myres >= 8 )
                v37 = (std::wstring *)disc_name._Bx._Ptr;
              _printf(
                "WARNING: BRAKE DISC MESH : %S DOES NOT HAVE CORRECT ksBrakeDisc SHADER, HAS :%S\n",
                v37->_Bx._Buf,
                (const wchar_t *)v41);
            }
            else
            {
              if ( v48->_Myres < 8 )
                v15 = (void (*)(void *))v48;
              else
                v15 = (void (*)(void *))v48->_Bx._Ptr;
              v16 = &disc_name;
              v41 = (unsigned int)v15;
              if ( disc_name._Myres >= 8 )
                v16 = (std::wstring *)disc_name._Bx._Ptr;
              _printf("BRAKE DISC: %S FOUND FOR: %S\n", v16->_Bx._Buf, (const wchar_t *)v41);
              v17 = (Material *)operator new(104);
              v52 = v17;
              LOBYTE(v62) = 21;
              if ( v17 )
                Material::Material(v17, *(const Material **)(v42 + 248));
              else
                v18 = 0;
              LOBYTE(v62) = 20;
              mat._Ptr = 0;
              mat._Rep = 0;
              std::shared_ptr<Material>::_Resetp<Material>(&mat, v18);
              LOBYTE(v62) = 22;
              if ( mat._Rep )
                _InterlockedExchangeAdd((volatile signed __int32 *)&mat._Rep->_Uses, 1u);
              v19 = v42;
              v20 = *(_DWORD *)(v42 + 252);
              *(_DWORD *)(v42 + 252) = mat._Rep;
              v42 = v20;
              *(_DWORD *)(v19 + 248) = mat._Ptr;
              if ( v20 )
              {
                if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v20 + 4), 0xFFFFFFFF) )
                {
                  (**(void (***)(int))v20)(v20);
                  v21 = v42;
                  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v42 + 8), 0xFFFFFFFF) )
                    (*(void (**)(int))(*(_DWORD *)v21 + 4))(v21);
                }
              }
              vname._Myres = 7;
              vname._Mysize = 0;
              vname._Bx._Buf[0] = 0;
              std::wstring::assign(&vname, L"glowLevel", 9u);
              LOBYTE(v62) = 23;
              v22 = Material::getVar(mat._Ptr, &vname);
              v23 = *(v11 - 12);
              v47 = v22;
              if ( &v47 >= v23 || (v24 = (std::vector<ICollisionObject *> *)(v11 - 13), *(v11 - 13) > &v47) )
              {
                if ( v23 == *(v11 - 11) )
                  std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)(v11 - 13), 1u);
                v28 = *(v11 - 12);
                if ( v28 )
                  *v28 = v47;
              }
              else
              {
                v25 = ((char *)&v47 - (char *)v24->_Myfirst) >> 2;
                v42 = v25;
                if ( v23 == *(v11 - 11) )
                {
                  std::vector<SVar *>::_Reserve(v24, 1u);
                  v25 = v42;
                  v24 = (std::vector<ICollisionObject *> *)(v11 - 13);
                }
                v26 = v24->_Myfirst;
                v27 = *(v11 - 12);
                if ( v27 )
                  *v27 = v26[v25];
              }
              ++*(v11 - 12);
              LOBYTE(v62) = 22;
              if ( vname._Myres >= 8 )
                operator delete(vname._Bx._Ptr);
              vname._Myres = 7;
              vname._Mysize = 0;
              vname._Bx._Buf[0] = 0;
              std::wstring::assign(&vname, L"blurLevel", 9u);
              LOBYTE(v62) = 24;
              v29 = Material::getVar(mat._Ptr, &vname);
              v30 = *v11;
              v46 = v29;
              if ( &v46 >= v30 || (v31 = (std::vector<ICollisionObject *> *)(v11 - 1), *(v11 - 1) > &v46) )
              {
                if ( v30 == v11[1] )
                  std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)(v11 - 1), 1u);
                if ( *v11 )
                  **v11 = v46;
              }
              else
              {
                v32 = ((char *)&v46 - (char *)v31->_Myfirst) >> 2;
                v42 = v32;
                if ( v30 == v11[1] )
                {
                  std::vector<SVar *>::_Reserve(v31, 1u);
                  v32 = v42;
                  v31 = (std::vector<ICollisionObject *> *)(v11 - 1);
                }
                if ( *v11 )
                  **v11 = (MaterialVar *)v31->_Myfirst[v32];
              }
              ++*v11;
              if ( vname._Myres >= 8 )
                operator delete(vname._Bx._Ptr);
              v33 = mat._Rep;
              LOBYTE(v62) = 20;
              if ( mat._Rep )
              {
                if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&mat._Rep->_Uses, 0xFFFFFFFF) )
                {
                  v33->_Destroy(v33);
                  v34 = mat._Rep;
                  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&mat._Rep->_Weaks, 0xFFFFFFFF) )
                    v34->_Delete_this(v34);
                }
              }
            }
          }
        }
        v38 = LODWORD(v43);
        _printf(
          "FOUND %llu BRAKE DISCS MESHES FOR TYRE:%d\n",
          (unsigned __int64)(unsigned int)(*(v11 - 12) - *(v11 - 13)),
          v43);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( v38 >= 2 )
        {
          std::wstring::assign(&key, L"REAR_MAX_GLOW", 0xDu);
          LOBYTE(v62) = 27;
          vname._Myres = 7;
          vname._Mysize = 0;
          vname._Bx._Buf[0] = 0;
          std::wstring::assign(&vname, L"DISCS_GRAPHICS", 0xEu);
          LOBYTE(v62) = 28;
        }
        else
        {
          std::wstring::assign(&key, L"FRONT_MAX_GLOW", 0xEu);
          LOBYTE(v62) = 25;
          vname._Myres = 7;
          vname._Mysize = 0;
          vname._Bx._Buf[0] = 0;
          std::wstring::assign(&vname, L"DISCS_GRAPHICS", 0xEu);
          LOBYTE(v62) = 26;
        }
        v39 = INIReader::getFloat(&ini, &vname, &key);
        v7 = vname._Myres < 8;
        *v44 = v39;
        if ( !v7 )
          operator delete(vname._Bx._Ptr);
        vname._Myres = 7;
        vname._Bx._Buf[0] = 0;
        vname._Mysize = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        LOBYTE(v62) = 19;
        if ( result._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&result);
          operator delete(result._Myfirst);
          result._Myfirst = 0;
          result._Mylast = 0;
          result._Myend = 0;
        }
        LOBYTE(v62) = 11;
        if ( disc_name._Myres >= 8 )
          operator delete(disc_name._Bx._Ptr);
        v10 = v44 + 1;
        v9 = v48 + 1;
        LODWORD(v43) = v38 + 1;
        v11 += 3;
        ++v44;
        ++v48;
      }
      while ( v38 + 1 < 4 );
    }
  }
  LOBYTE(v62) = 7;
  `eh vector destructor iterator'(keys, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
  LOBYTE(v62) = 2;
  INIReader::~INIReader(&ini);
}
BrakeDiscGraphics *BrakeDiscGraphics::`scalar deleting destructor'(BrakeDiscGraphics *this, unsigned int a2)
{
  this->__vftable = (BrakeDiscGraphics_vtbl *)&BrakeDiscGraphics::`vftable';
  `eh vector destructor iterator'(
    this->blurVars,
    0xCu,
    4,
    (void (*)(void *))std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>);
  `eh vector destructor iterator'(
    this->glowVars,
    0xCu,
    4,
    (void (*)(void *))std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void BrakeDiscGraphics::update(BrakeDiscGraphics *this, float dt)
{
  BrakeDiscGraphics *v2; // esi
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float *v7; // edx
  MaterialVar ***v8; // edi
  int v9; // eax
  CarAvatar *v10; // ecx
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  _DWORD *v17; // esi
  _DWORD *v18; // edi
  int v19; // edx
  float *v20; // ecx
  int v21; // ecx
  float *v22; // eax
  MaterialVar **v23; // esi
  MaterialVar **v24; // edi
  float v25; // xmm0_4
  MaterialVar *v26; // eax
  ShaderVariable *v27; // ecx
  float *v28; // eax
  bool v29; // zf
  int v30; // [esp+0h] [ebp-24h]
  float *v32; // [esp+8h] [ebp-1Ch]
  int v33; // [esp+Ch] [ebp-18h]
  float v34; // [esp+10h] [ebp-14h]
  MaterialVar ***v35; // [esp+14h] [ebp-10h]
  float v36; // [esp+18h] [ebp-Ch]
  float *v37; // [esp+1Ch] [ebp-8h]
  float v38; // [esp+20h] [ebp-4h]

  v2 = this;
  v36 = FLOAT_1_0;
  v34 = FLOAT_1_0;
  v3 = FLOAT_1_0;
  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
  {
    v4 = v2->car->sim->replayManager->timeMult;
    v34 = v4;
    v5 = v4;
    v36 = v4;
    if ( v4 == 0.0 )
    {
      v5 = FLOAT_1_0;
      v36 = FLOAT_1_0;
    }
  }
  else
  {
    v4 = FLOAT_1_0;
    v5 = 1.0;
  }
  v6 = dt;
  v7 = v2->currentGlowValue;
  v37 = v2->currentGlowValue;
  v8 = &v2->blurVars[0]._Mylast;
  v33 = 4;
  v9 = 868 - (_DWORD)v2;
  v35 = &v2->blurVars[0]._Mylast;
  v30 = 868 - (_DWORD)v2;
  do
  {
    v10 = v2->car;
    LODWORD(v11) = (__int128)*(CarAvatar_vtbl **)((_BYTE *)&v10->__vftable + (_DWORD)v7 + v9) & _xmm;
    v12 = (float)(v11 - 10.0) * 0.0066666668;
    if ( v12 <= v3 )
    {
      if ( v12 < 0.0 )
        v12 = 0.0;
    }
    else
    {
      v12 = v3;
    }
    v13 = (float)(v7[4] * v10->physicsState.brake) * v12;
    v14 = (float)(v11 * v5) * 0.1;
    v38 = v14;
    if ( v14 <= v3 )
    {
      if ( v14 < 0.0 )
        v38 = 0.0;
    }
    else
    {
      v38 = v3;
    }
    if ( v4 != 0.0 )
    {
      if ( v13 <= *v7 )
        v15 = v2->lag_cool;
      else
        v15 = v2->lag_hot;
      v16 = v15 * v6;
      if ( v16 <= v3 )
      {
        if ( v16 < 0.0 )
          v16 = 0.0;
      }
      else
      {
        v16 = v3;
      }
      *v7 = (float)((float)(v13 - *v7) * v16) + *v7;
    }
    v17 = *(v8 - 13);
    v18 = *(v8 - 12);
    if ( v17 != v18 )
    {
      do
      {
        v19 = *v17;
        v20 = (float *)(*v17 + 24);
        *v20 = *v37;
        v32 = v20;
        v21 = *(_DWORD *)(v19 + 128);
        switch ( *(_DWORD *)(v21 + 28) )
        {
          case 0:
            ShaderVariable::set((ShaderVariable *)v21, v32);
            break;
          case 1:
            v22 = (float *)(v19 + 28);
            goto LABEL_30;
          case 2:
            v22 = (float *)(v19 + 36);
            goto LABEL_30;
          case 3:
            v22 = (float *)(v19 + 48);
            goto LABEL_30;
          case 4:
            v22 = (float *)(v19 + 64);
LABEL_30:
            ShaderVariable::set((ShaderVariable *)v21, v22);
            break;
          default:
            break;
        }
        ++v17;
      }
      while ( v17 != v18 );
      v7 = v37;
    }
    v23 = *(v35 - 1);
    v24 = *v35;
    if ( v23 != *v35 )
    {
      v25 = v38;
      do
      {
        v26 = *v23;
        v26->fValue = v25;
        v27 = v26->var;
        switch ( v27->type )
        {
          case 0:
            ShaderVariable::set(v27, &v26->fValue);
            goto LABEL_42;
          case 1:
            v28 = &v26->fValue2.x;
            goto LABEL_41;
          case 2:
            v28 = &v26->fValue3.x;
            goto LABEL_41;
          case 3:
            v28 = &v26->fValue4.x;
            goto LABEL_41;
          case 4:
            v28 = &v26->mValue.M11;
LABEL_41:
            ShaderVariable::set(v27, v28);
LABEL_42:
            v25 = v38;
            break;
          default:
            break;
        }
        ++v23;
      }
      while ( v23 != v24 );
      v7 = v37;
    }
    ++v7;
    v3 = FLOAT_1_0;
    v8 = v35 + 3;
    v29 = v33-- == 1;
    v4 = v34;
    v5 = v36;
    v6 = dt;
    v2 = this;
    v9 = v30;
    v37 = v7;
    v35 += 3;
  }
  while ( !v29 );
}
