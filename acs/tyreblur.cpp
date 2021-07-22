#include "tyreblur.h"
void TyreBlur::TyreBlur(TyreBlur *this, CarAvatar *acar)
{
  std::wstring v3; // [esp-1Ch] [ebp-38h] BYREF
  Game *v4; // [esp-4h] [ebp-20h]
  TyreBlur *v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+18h] [ebp-4h]

  v5 = this;
  v4 = acar->game;
  v3._Myres = 7;
  v3._Mysize = 0;
  v3._Bx._Buf[0] = 0;
  std::wstring::assign(&v3, L"TYRE_BLUR", 9u);
  GameObject::GameObject(this, v3, v4);
  v4 = (Game *)TyreMaterials::~TyreMaterials;
  v3._Myres = (unsigned int)TyreMaterials::TyreMaterials;
  v3._Mysize = 4;
  *(_DWORD *)&v3._Bx._Alias[12] = 24;
  v6 = 0;
  *(_DWORD *)&v3._Bx._Alias[8] = this->tyreMaterials;
  this->__vftable = (TyreBlur_vtbl *)&TyreBlur::`vftable';
  `eh vector constructor iterator'(
    *(void **)&v3._Bx._Alias[8],
    *(unsigned int *)&v3._Bx._Alias[12],
    v3._Mysize,
    (void (*)(void *))v3._Myres,
    (void (*)(void *))v4);
  LOBYTE(v6) = 1;
  this->car = acar;
  TyreBlur::initTyreMaterials(this);
}
TyreBlur *TyreBlur::`scalar deleting destructor'(TyreBlur *this, unsigned int a2)
{
  this->__vftable = (TyreBlur_vtbl *)&TyreBlur::`vftable';
  `eh vector destructor iterator'(
    this->tyreMaterials,
    0x18u,
    4,
    (void (*)(void *))TyreMaterials::~TyreMaterials);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TyreBlur::initTyreMaterials(TyreBlur *this)
{
  TyreBlur *v1; // ebp
  int i; // ebx
  int v3; // edi
  int v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  Node **v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // ebp
  int v11; // eax
  int v12; // edi
  Node **v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // ecx
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]
  unsigned int v19; // [esp+18h] [ebp-4h]

  v1 = this;
  for ( i = 0; i < 4; ++i )
  {
    v3 = __RTDynamicCast(
           v1->car->suspensionAvatar,
           0,
           &ISuspensionAvatar `RTTI Type Descriptor',
           &SuspensionAnimator `RTTI Type Descriptor',
           0);
    v18 = v3;
    if ( v3 )
    {
      v4 = 0;
      v17 = 0;
      v5 = (char *)v1->car->lodManager->lods._Mylast - (char *)v1->car->lodManager->lods._Myfirst;
      if ( v5 >= 0 && (v5 & 0xFFFFFFC0) != 0 )
      {
        do
        {
          if ( (*(int (**)(int, int, int))(*(_DWORD *)v3 + 28))(v3, v4, i) )
          {
            v6 = (*(int (**)(int, int, int))(*(_DWORD *)v3 + 28))(v3, v4, i);
            v7 = 0;
            v8 = *(Node ***)(v6 + 136);
            v9 = *(_DWORD *)(v6 + 140);
            v10 = (v9 - (unsigned int)v8 + 3) >> 2;
            if ( (unsigned int)v8 > v9 )
              v10 = 0;
            if ( v10 )
            {
              do
              {
                TyreBlur::processNode(this, *v8, i);
                ++v7;
                ++v8;
              }
              while ( v7 != v10 );
            }
            v3 = v18;
            v4 = v17;
            v1 = this;
          }
          v17 = ++v4;
        }
        while ( v4 < v1->car->lodManager->lods._Mylast - v1->car->lodManager->lods._Myfirst );
      }
    }
    else if ( v1->car->suspensionAvatar->getWheelTransform(v1->car->suspensionAvatar, i) )
    {
      v11 = (int)v1->car->suspensionAvatar->getWheelTransform(v1->car->suspensionAvatar, i);
      v12 = 0;
      v13 = *(Node ***)(v11 + 136);
      v14 = *(_DWORD *)(v11 + 140);
      v15 = (v14 - (unsigned int)v13 + 3) >> 2;
      if ( (unsigned int)v13 > v14 )
        v15 = 0;
      v19 = v15;
      if ( v15 )
      {
        do
        {
          TyreBlur::processNode(v1, *v13, i);
          ++v12;
          ++v13;
        }
        while ( v12 != v19 );
      }
    }
  }
}
void TyreBlur::processNode(TyreBlur *this, Node *node, int tyreIndex)
{
  int v4; // eax
  int v5; // ecx
  std::shared_ptr<Material> *v6; // esi
  ICollisionObject *v7; // eax
  Material *v8; // eax
  Material *v9; // esi
  Node **v10; // esi
  int v11; // edi
  unsigned int v12; // ebx
  ICollisionObject *_Val; // [esp+14h] [ebp-38h] BYREF
  int v14; // [esp+18h] [ebp-34h]
  std::shared_ptr<Material> mc; // [esp+1Ch] [ebp-30h] BYREF
  std::wstring vname; // [esp+24h] [ebp-28h] BYREF
  int v17; // [esp+48h] [ebp-4h]

  v14 = tyreIndex;
  v4 = __RTDynamicCast(node, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 248);
    v6 = (std::shared_ptr<Material> *)(v4 + 248);
    if ( v5 )
    {
      if ( !std::wstring::compare(
              (std::wstring *)(*(_DWORD *)(v5 + 24) + 4),
              0,
              *(_DWORD *)(*(_DWORD *)(v5 + 24) + 20),
              L"ksTyres",
              7u) )
      {
        v7 = (ICollisionObject *)operator new(104);
        _Val = v7;
        v17 = 0;
        if ( v7 )
          Material::Material((Material *)v7, v6->_Ptr);
        else
          v8 = 0;
        v17 = -1;
        mc._Ptr = 0;
        mc._Rep = 0;
        std::shared_ptr<Material>::_Resetp<Material>(&mc, v8);
        v17 = 1;
        std::shared_ptr<Material>::operator=(v6, &mc);
        std::wstring::wstring(&vname, L"blurLevel");
        v9 = mc._Ptr;
        LOBYTE(v17) = 2;
        _Val = (ICollisionObject *)Material::getVar(mc._Ptr, &vname);
        std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->tyreMaterials[v14], &_Val);
        LOBYTE(v17) = 1;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        std::wstring::wstring(&vname, L"dirtyLevel");
        LOBYTE(v17) = 3;
        _Val = (ICollisionObject *)Material::getVar(v9, &vname);
        std::vector<SpinnerData *>::push_back(
          (std::vector<ICollisionObject *> *)&this->tyreMaterials[v14].varDirtyLevel,
          &_Val);
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        vname._Myres = 7;
        vname._Mysize = 0;
        vname._Bx._Buf[0] = 0;
        v17 = -1;
        std::shared_ptr<Material>::~shared_ptr<Material>(&mc);
      }
    }
  }
  v10 = node->nodes._Myfirst;
  v11 = 0;
  v12 = (unsigned int)((char *)node->nodes._Mylast - (char *)v10 + 3) >> 2;
  if ( v10 > node->nodes._Mylast )
    v12 = 0;
  if ( v12 )
  {
    do
    {
      TyreBlur::processNode(this, *v10, v14);
      ++v11;
      ++v10;
    }
    while ( v11 != v12 );
  }
}
void TyreBlur::update(TyreBlur *this, float deltaT)
{
  TyreBlur *v2; // ebx
  float v3; // xmm3_4
  float v4; // xmm5_4
  int v5; // xmm4_4
  MaterialVar ***v6; // ecx
  int v7; // edx
  CarAvatar *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  int *v12; // esi
  int *v13; // edi
  int v14; // eax
  int v15; // ecx
  float *v16; // eax
  MaterialVar **v17; // esi
  MaterialVar **v18; // edi
  MaterialVar *v19; // eax
  ShaderVariable *v20; // ecx
  float *v21; // eax
  float v22; // [esp+0h] [ebp-18h]
  float v23; // [esp+4h] [ebp-14h]
  int v24; // [esp+8h] [ebp-10h]
  MaterialVar ***v25; // [esp+Ch] [ebp-Ch]
  float v26; // [esp+10h] [ebp-8h]

  v2 = this;
  v26 = FLOAT_1_0;
  v3 = FLOAT_1_0;
  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
  {
    v4 = v2->car->sim->replayManager->timeMult;
    v26 = v4;
    if ( v4 == 0.0 )
    {
      v4 = FLOAT_1_0;
      v26 = FLOAT_1_0;
    }
  }
  else
  {
    v4 = FLOAT_1_0;
  }
  v5 = _xmm;
  v6 = &v2->tyreMaterials[0].varDirtyLevel._Mylast;
  v7 = 1020;
  v25 = &v2->tyreMaterials[0].varDirtyLevel._Mylast;
  v24 = 1020;
  do
  {
    v8 = v2->car;
    LODWORD(v9) = *(_DWORD *)((_BYTE *)v8->configName._Bx._Buf + v7) & v5;
    if ( v9 <= v3 )
    {
      if ( v9 < 0.0 )
        v9 = 0.0;
    }
    else
    {
      v9 = v3;
    }
    v10 = v9 * 1.1;
    v23 = v10;
    v11 = (float)(COERCE_FLOAT(*(int *)((_BYTE *)&v8->__vftable + v7) & v5) * v4) * 0.1;
    v22 = v11;
    if ( v11 <= v3 )
    {
      if ( v11 < 0.0 )
      {
        v11 = 0.0;
        v22 = 0.0;
      }
    }
    else
    {
      v11 = v3;
      v22 = v3;
    }
    v12 = (int *)*(v6 - 4);
    v13 = (int *)*(v6 - 3);
    if ( v12 != v13 )
    {
      do
      {
        v14 = *v12;
        *(float *)(v14 + 24) = v11;
        v15 = *(_DWORD *)(v14 + 128);
        switch ( *(_DWORD *)(v15 + 28) )
        {
          case 0:
            ShaderVariable::set((ShaderVariable *)v15, (float *)(v14 + 24));
            goto LABEL_22;
          case 1:
            v16 = (float *)(v14 + 28);
            goto LABEL_21;
          case 2:
            v16 = (float *)(v14 + 36);
            goto LABEL_21;
          case 3:
            v16 = (float *)(v14 + 48);
            goto LABEL_21;
          case 4:
            v16 = (float *)(v14 + 64);
LABEL_21:
            ShaderVariable::set((ShaderVariable *)v15, v16);
LABEL_22:
            v11 = v22;
            break;
          default:
            break;
        }
        ++v12;
      }
      while ( v12 != v13 );
      v6 = v25;
      v7 = v24;
    }
    v17 = *(v6 - 1);
    v18 = *v6;
    if ( v17 != *v6 )
    {
      do
      {
        v19 = *v17;
        v19->fValue = v10;
        v20 = v19->var;
        switch ( v20->type )
        {
          case 0:
            ShaderVariable::set(v20, &v19->fValue);
            goto LABEL_33;
          case 1:
            v21 = &v19->fValue2.x;
            goto LABEL_32;
          case 2:
            v21 = &v19->fValue3.x;
            goto LABEL_32;
          case 3:
            v21 = &v19->fValue4.x;
            goto LABEL_32;
          case 4:
            v21 = &v19->mValue.M11;
LABEL_32:
            ShaderVariable::set(v20, v21);
LABEL_33:
            v10 = v23;
            break;
          default:
            break;
        }
        ++v17;
      }
      while ( v17 != v18 );
      v6 = v25;
      v7 = v24;
    }
    v3 = FLOAT_1_0;
    v7 += 4;
    v5 = _xmm;
    v6 += 6;
    v4 = v26;
    v2 = this;
    v24 = v7;
    v25 = v6;
  }
  while ( v7 < 1036 );
}
