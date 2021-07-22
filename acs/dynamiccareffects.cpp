#include "dynamiccareffects.h"
void DynamicCarEffects::DynamicCarEffects(DynamicCarEffects *this, CarAvatar *aCar)
{
  CarAvatar *v3; // ecx
  CarAvatar *v4; // eax
  CarAvatar *v5; // ecx
  Console *v6; // eax
  CarAvatar *v7; // eax
  double v8; // st7
  bool v9; // cf
  _BYTE multiplier[56]; // [esp-34h] [ebp-FCh] BYREF
  _BYTE *v11; // [esp+20h] [ebp-A8h]
  _BYTE *v12; // [esp+24h] [ebp-A4h]
  DynamicCarEffects *v13; // [esp+28h] [ebp-A0h]
  std::wstring ifilename; // [esp+2Ch] [ebp-9Ch] BYREF
  std::wstring section; // [esp+44h] [ebp-84h] BYREF
  std::wstring key; // [esp+5Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+74h] [ebp-54h] BYREF
  int v18; // [esp+C4h] [ebp-4h]

  v13 = this;
  *(_DWORD *)&multiplier[52] = aCar->game;
  *(_DWORD *)&multiplier[48] = 7;
  *(_DWORD *)&multiplier[44] = 0;
  *(_WORD *)&multiplier[28] = 0;
  std::wstring::assign((std::wstring *)&multiplier[28], L"DYNAMIC_CAR_EFFECTS", 0x13u);
  GameObject::GameObject(this, *(std::wstring *)&multiplier[28], *(Game **)&multiplier[52]);
  this->__vftable = (DynamicCarEffects_vtbl *)&DynamicCarEffects::`vftable';
  v18 = 0;
  this->dirtVars._Myfirst = 0;
  this->dirtVars._Mylast = 0;
  this->dirtVars._Myend = 0;
  this->car = aCar;
  this->currentDirtLevel = 0.0;
  this->replayOldDirtLevel = 0.0;
  this->dirtMultiplier = 1.0;
  v11 = &multiplier[32];
  *(_DWORD *)&multiplier[48] = 0;
  *(_DWORD *)&multiplier[8] = &std::_Func_impl<std::_Callable_obj<_lambda_704f63be4f85e5217b2381f4831e0757_,0>,std::allocator<std::_Func_class<bool,Node *>>,bool,Node *>::`vftable';
  *(_DWORD *)&multiplier[12] = this;
  *(_DWORD *)&multiplier[24] = &multiplier[8];
  v3 = this->car;
  LOBYTE(v18) = 1;
  Node::visit(
    v3->bodyTransform,
    *(std::function<bool __cdecl(Node *)> *)&multiplier[8],
    *(std::function<void __cdecl(Node *)> *)&multiplier[32]);
  DynamicCarEffects::resetDirt(this);
  *(_DWORD *)&multiplier[52] = this;
  *(_DWORD *)&multiplier[28] = &std::_Func_impl<std::_Callable_obj<_lambda_c4460d128e2ab44f73fcde83f43a7b24_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&multiplier[32] = this;
  *(_DWORD *)&multiplier[44] = &multiplier[28];
  v4 = this->car;
  LOBYTE(v18) = 1;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v4->sim->evOnReplayStatusChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&multiplier[28],
    this);
  *(_DWORD *)&multiplier[52] = 1065353216;
  *(_DWORD *)&multiplier[48] = 0;
  v11 = &multiplier[24];
  *(_DWORD *)&multiplier[24] = &std::_Func_impl<std::_Callable_obj<_lambda_946fcd06e20ad4ff585c573ef4cf23ad_,0>,std::allocator<std::_Func_class<void,SVar *,float>>,void,SVar *,float>::`vftable';
  *(_DWORD *)&multiplier[28] = this;
  *(_DWORD *)&multiplier[40] = &multiplier[24];
  LOBYTE(v18) = 6;
  v12 = multiplier;
  *(_DWORD *)&multiplier[20] = 7;
  *(_DWORD *)&multiplier[16] = 0;
  *(_WORD *)multiplier = 0;
  std::wstring::assign((std::wstring *)multiplier, L"debugDirt", 9u);
  v5 = this->car;
  LOBYTE(v18) = 7;
  v6 = Sim::getConsole(v5->sim);
  LOBYTE(v18) = 1;
  Console::addVarLambda(
    v6,
    *(std::wstring *)multiplier,
    *(std::function<void __cdecl(SVar *,float)> *)&multiplier[24],
    multiplier[48],
    *(float *)&multiplier[52]);
  *(_DWORD *)&multiplier[52] = this;
  *(_DWORD *)&multiplier[28] = &std::_Func_impl<std::_Callable_obj<_lambda_2dd51a103a8160239d1fa2922da136d6_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&multiplier[32] = this;
  *(_DWORD *)&multiplier[44] = &multiplier[28];
  v7 = this->car;
  LOBYTE(v18) = 1;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v7->sim->evOnNewSession,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&multiplier[28],
    this);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v18) = 9;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v18) = 11;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MULT", 4u);
    LOBYTE(v18) = 12;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DIRT", 4u);
    LOBYTE(v18) = 13;
    v8 = INIReader::getFloat(&ini, &section, &key);
    v9 = section._Myres < 8;
    this->dirtMultiplier = v8;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  LOBYTE(v18) = 1;
  INIReader::~INIReader(&ini);
}
DynamicCarEffects *DynamicCarEffects::`vector deleting destructor'(DynamicCarEffects *this, unsigned int a2)
{
  this->__vftable = (DynamicCarEffects_vtbl *)&DynamicCarEffects::`vftable';
  if ( this->dirtVars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->dirtVars);
    operator delete(this->dirtVars._Myfirst);
    this->dirtVars._Myfirst = 0;
    this->dirtVars._Mylast = 0;
    this->dirtVars._Myend = 0;
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DynamicCarEffects::resetDirt(DynamicCarEffects *this)
{
  MaterialVar **v2; // esi
  MaterialVar **v3; // edi
  MaterialVar *v4; // edx
  ShaderVariable *v5; // ecx
  float *v6; // eax

  v2 = this->dirtVars._Myfirst;
  v3 = this->dirtVars._Mylast;
  for ( this->currentDirtLevel = 0.0; v2 != v3; ++v2 )
  {
    v4 = *v2;
    v4->fValue = this->currentDirtLevel;
    v5 = v4->var;
    switch ( v5->type )
    {
      case 0:
        ShaderVariable::set(v5, &v4->fValue);
        continue;
      case 1:
        v6 = &v4->fValue2.x;
        goto LABEL_8;
      case 2:
        v6 = &v4->fValue3.x;
        goto LABEL_8;
      case 3:
        v6 = &v4->fValue4.x;
        goto LABEL_8;
      case 4:
        v6 = &v4->mValue.M11;
LABEL_8:
        ShaderVariable::set(v5, v6);
        break;
      default:
        continue;
    }
  }
}
void DynamicCarEffects::setDirtLevel(DynamicCarEffects *this, float v)
{
  float v2; // xmm0_4
  MaterialVar **v4; // esi
  MaterialVar **v5; // edi
  MaterialVar *v6; // edx
  ShaderVariable *v7; // ecx
  float *v8; // eax

  v2 = FLOAT_1_0;
  if ( v <= 1.0 )
  {
    v2 = 0.0;
    if ( v >= 0.0 )
      v2 = v;
  }
  v4 = this->dirtVars._Myfirst;
  v5 = this->dirtVars._Mylast;
  for ( this->currentDirtLevel = v2; v4 != v5; ++v4 )
  {
    v6 = *v4;
    if ( *v4 )
    {
      v7 = v6->var;
      v6->fValue = this->currentDirtLevel;
      switch ( v7->type )
      {
        case 0:
          ShaderVariable::set(v7, &v6->fValue);
          continue;
        case 1:
          v8 = &v6->fValue2.x;
          goto LABEL_12;
        case 2:
          v8 = &v6->fValue3.x;
          goto LABEL_12;
        case 3:
          v8 = &v6->fValue4.x;
          goto LABEL_12;
        case 4:
          v8 = &v6->mValue.M11;
LABEL_12:
          ShaderVariable::set(v7, v8);
          break;
        default:
          continue;
      }
    }
  }
}
void DynamicCarEffects::update(DynamicCarEffects *this, float dt)
{
  DynamicCarEffects *v2; // esi
  DynamicCarEffects *v3; // ecx
  float v4; // xmm3_4
  unsigned int v5; // edx
  float v6; // xmm0_4
  float *v7; // esi
  int v8; // edi
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  MaterialVar **v12; // esi
  MaterialVar **i; // edi
  MaterialVar *v14; // edx
  ShaderVariable *v15; // eax
  float *v16; // eax
  float dta; // [esp+10h] [ebp+4h]
  float *dtb; // [esp+10h] [ebp+4h]

  v2 = this;
  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
  {
    DynamicCarEffects::updateReplayMode(v2, dt);
  }
  else
  {
    v3 = v2;
    v4 = FLOAT_1_0;
    v5 = 293;
    v6 = v2->currentDirtLevel;
    v7 = (float *)v2->car;
    dta = v6;
    v8 = 0;
    do
    {
      if ( (v7[264] > 1.0 || COERCE_FLOAT(LODWORD(v7[v5 - 38]) & _xmm) > 4.0)
        && COERCE_FLOAT(LODWORD(v7[v8 + 345]) & _xmm) > 0.1
        && v7[v5] > 10.0 )
      {
        v9 = (float)((float)(v7[265] * v7[265]) + (float)(v7[266] * v7[266])) + (float)(v7[267] * v7[267]);
        if ( v9 == 0.0 )
          v10 = 0.0;
        else
          v10 = fsqrt(v9);
        v3->currentDirtLevel = (float)((float)(v10 * v3->dirtMultiplier) * 0.0000099999997) + v3->currentDirtLevel;
      }
      ++v5;
      v8 += 47;
    }
    while ( v5 < 297 );
    v11 = v3->currentDirtLevel;
    if ( v11 <= 1.0 )
    {
      if ( v11 >= 0.0 )
        v4 = v3->currentDirtLevel;
      else
        v4 = 0.0;
    }
    v3->currentDirtLevel = v4;
    if ( dta != v4 )
    {
      v12 = v3->dirtVars._Myfirst;
      for ( i = v3->dirtVars._Mylast; v12 != i; ++v12 )
      {
        v14 = *v12;
        dtb = &(*v12)->fValue;
        v14->fValue = v3->currentDirtLevel;
        v15 = v14->var;
        switch ( v15->type )
        {
          case 0:
            ShaderVariable::set(v15, dtb);
            break;
          case 1:
            v16 = &v14->fValue2.x;
            goto LABEL_25;
          case 2:
            v16 = &v14->fValue3.x;
            goto LABEL_25;
          case 3:
            v16 = &v14->fValue4.x;
            goto LABEL_25;
          case 4:
            v16 = &v14->mValue.M11;
LABEL_25:
            ShaderVariable::set(v14->var, v16);
            break;
          default:
            break;
        }
        v3 = this;
      }
    }
  }
}
void DynamicCarEffects::updateReplayMode(DynamicCarEffects *this, float dt)
{
  MaterialVar **v3; // esi
  MaterialVar **i; // edi
  MaterialVar *v5; // edx
  ShaderVariable *v6; // ecx
  float *v7; // eax

  v3 = this->dirtVars._Myfirst;
  for ( i = this->dirtVars._Mylast; v3 != i; ++v3 )
  {
    v5 = *v3;
    v5->fValue = this->currentDirtLevel;
    v6 = v5->var;
    switch ( v6->type )
    {
      case 0:
        ShaderVariable::set(v6, &v5->fValue);
        continue;
      case 1:
        v7 = &v5->fValue2.x;
        goto LABEL_8;
      case 2:
        v7 = &v5->fValue3.x;
        goto LABEL_8;
      case 3:
        v7 = &v5->fValue4.x;
        goto LABEL_8;
      case 4:
        v7 = &v5->mValue.M11;
LABEL_8:
        ShaderVariable::set(v6, v7);
        break;
      default:
        continue;
    }
  }
}
