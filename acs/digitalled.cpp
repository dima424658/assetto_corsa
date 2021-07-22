#include "digitalled.h"
DigitalLed *DigitalLed::`scalar deleting destructor'(DigitalLed *this, unsigned int a2)
{
  DigitalLed::~DigitalLed(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
bool DigitalLed::hasTargetMesh(DigitalLed *this)
{
  return this->targetMesh != 0;
}
void DigitalLed::DigitalLed(DigitalLed *this, CarAvatar *car)
{
  this->type = RPM;
  this->fswitch = -1.0;
  this->emissive.x = 0.0;
  this->emissive.y = 0.0;
  this->emissive.z = 0.0;
  this->emissive2.x = 0.0;
  this->emissive2.y = 0.0;
  this->emissive2.z = 0.0;
  this->emissive3.x = 0.0;
  this->emissive3.y = 0.0;
  this->emissive3.z = 0.0;
  this->blinkFrequency = 0.0;
  this->blinkSwitch = -1.0;
  this->selectedWing = 0;
  *(_WORD *)&this->inverted = 0;
  this->showMin = 0.0;
  this->showMax = 0.0;
  this->showExcluded = 0;
  this->gForce = 0;
  this->gForceSign = 1;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  this->car = car;
  this->varEmissive = 0;
  this->targetMesh = 0;
}
void DigitalLed::DigitalLed(DigitalLed *this, CarAvatar *a_car, INIReader *ini, std::wstring section, DigitalLedType itype, Node *node)
{
  Node *v7; // esi
  DigitalLedType v8; // ecx
  Mesh *v9; // eax
  std::wstring *v10; // eax
  Material *v11; // ecx
  Material *v12; // eax
  volatile signed __int32 *v13; // esi
  std::_Ref_count_base *v14; // ecx
  std::shared_ptr<Material> *v15; // eax
  Material *v16; // esi
  volatile signed __int32 *v17; // esi
  vec3f *v18; // eax
  bool v19; // cf
  double v20; // st7
  double v21; // st7
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v22; // ecx
  int v23; // eax
  double v24; // st7
  double v25; // st7
  double v26; // st7
  int v27; // eax
  double v28; // st7
  int v29; // eax
  vec3f *v30; // eax
  Material *v31; // esi
  MaterialVar *v32; // eax
  Material *v33; // esi
  MaterialVar *v34; // eax
  Material *v35; // ecx
  MaterialVar *v36; // eax
  Material *v37; // ecx
  MaterialVar *v38; // eax
  std::wstring v39; // [esp-1Ch] [ebp-1D8h] BYREF
  BOOL v40; // [esp-4h] [ebp-1C0h]
  vec3f _Right; // [esp+14h] [ebp-1A8h] BYREF
  std::_Ref_count_base *v42; // [esp+20h] [ebp-19Ch]
  std::shared_ptr<Material> *v43; // [esp+24h] [ebp-198h]
  DigitalLed *v44; // [esp+28h] [ebp-194h]
  std::wstring v45; // [esp+2Ch] [ebp-190h] BYREF
  std::wstring vname; // [esp+44h] [ebp-178h] BYREF
  std::wstring key; // [esp+5Ch] [ebp-160h] BYREF
  std::wstring target_name; // [esp+74h] [ebp-148h] BYREF
  std::wstring v49; // [esp+8Ch] [ebp-130h] BYREF
  std::wstring v50; // [esp+A4h] [ebp-118h] BYREF
  std::wstring v51; // [esp+BCh] [ebp-100h] BYREF
  std::wstring v52; // [esp+D4h] [ebp-E8h] BYREF
  std::wstring v53; // [esp+ECh] [ebp-D0h] BYREF
  std::wstring v54; // [esp+104h] [ebp-B8h] BYREF
  std::wstring v55; // [esp+11Ch] [ebp-A0h] BYREF
  std::wstring v56; // [esp+134h] [ebp-88h] BYREF
  std::wstring v57; // [esp+14Ch] [ebp-70h] BYREF
  std::wstring v58; // [esp+164h] [ebp-58h] BYREF
  std::wstring v59; // [esp+17Ch] [ebp-40h] BYREF
  std::wstring v60; // [esp+194h] [ebp-28h] BYREF
  int v61; // [esp+1B8h] [ebp-4h]

  v44 = this;
  this->fswitch = -1.0;
  this->emissive.x = 0.0;
  this->emissive.y = 0.0;
  this->emissive.z = 0.0;
  this->emissive2.x = 0.0;
  this->emissive2.y = 0.0;
  this->emissive2.z = 0.0;
  this->emissive3.x = 0.0;
  this->emissive3.y = 0.0;
  this->emissive3.z = 0.0;
  this->blinkFrequency = 0.0;
  this->blinkSwitch = -1.0;
  this->selectedWing = 0;
  *(_WORD *)&this->inverted = 0;
  this->showMin = 0.0;
  this->showMax = 0.0;
  this->showExcluded = 0;
  this->gForce = 0;
  this->gForceSign = 1;
  v61 = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  v7 = node;
  v8 = itype;
  LOBYTE(v61) = 1;
  this->varEmissive = 0;
  this->targetMesh = 0;
  this->car = a_car;
  this->type = v8;
  if ( !v7 )
    v7 = a_car->bodyTransform;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"OBJECT_NAME", 0xBu);
  LOBYTE(v61) = 2;
  INIReader::getString(ini, &target_name, &section, &key);
  LOBYTE(v61) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v40 = 1;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  v39._Mysize = 0;
  v39._Myres = 7;
  v39._Bx._Buf[0] = 0;
  std::wstring::assign(&v39, &target_name, 0, 0xFFFFFFFF);
  v9 = Node::getNodeChild<Mesh>(v7, v39, v40);
  this->targetMesh = v9;
  if ( v9 )
  {
    v11 = (Material *)operator new(104);
    LODWORD(_Right.x) = v11;
    LOBYTE(v61) = 5;
    if ( v11 )
      Material::Material(v11, this->targetMesh->material._Ptr);
    else
      v12 = 0;
    LOBYTE(v61) = 4;
    _Right.x = 0.0;
    _Right.y = 0.0;
    std::shared_ptr<Material>::_Resetp<Material>((std::shared_ptr<Material> *)&_Right, v12);
    std::shared_ptr<Material>::operator=(&this->material, (std::shared_ptr<Material> *)&_Right);
    v13 = (volatile signed __int32 *)LODWORD(_Right.y);
    if ( LODWORD(_Right.y) )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(_Right.y) + 4), 0xFFFFFFFF) )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *, int))v13)(v13, -1);
        if ( !_InterlockedExchangeAdd(v13 + 2, 0xFFFFFFFF) )
          (*(void (**)(volatile signed __int32 *))(*v13 + 4))(v13);
      }
    }
    v14 = this->material._Rep;
    v15 = &this->targetMesh->material;
    v16 = this->material._Ptr;
    v43 = v15;
    v42 = v14;
    LODWORD(_Right.x) = v16;
    if ( v14 )
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)&v14->_Uses, 1u);
      v15 = v43;
      v14 = v42;
    }
    v17 = (volatile signed __int32 *)v15->_Rep;
    v15->_Rep = v14;
    v15->_Ptr = (Material *)LODWORD(_Right.x);
    if ( v17 )
    {
      if ( !_InterlockedExchangeAdd(v17 + 1, 0xFFFFFFFF) )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *, int))v17)(v17, -1);
        if ( !_InterlockedDecrement(v17 + 2) )
          (*(void (**)(volatile signed __int32 *))(*v17 + 4))(v17);
      }
    }
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    std::wstring::assign(&vname, L"EMISSIVE", 8u);
    LOBYTE(v61) = 6;
    v18 = INIReader::getFloat3(ini, &_Right, &section, &vname);
    v19 = vname._Myres < 8;
    LOBYTE(v61) = 4;
    this->emissive = *v18;
    if ( !v19 )
      operator delete(vname._Bx._Ptr);
    switch ( itype )
    {
      case RPM:
        std::wstring::wstring(&v45, L"RPM_SWITCH");
        LOBYTE(v61) = 7;
        v20 = INIReader::getFloat(ini, &section, &v45);
        LOBYTE(v61) = 4;
        this->fswitch = v20;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v45);
        std::wstring::wstring(&vname, L"BLINK_SWITCH");
        LOBYTE(v61) = 8;
        v21 = INIReader::getFloat(ini, &section, &vname);
        LOBYTE(v61) = 4;
        this->blinkSwitch = v21;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        std::wstring::wstring(&v51, L"BLINK_HZ");
        LOBYTE(v61) = 9;
        this->blinkFrequency = INIReader::getFloat(ini, &section, &v51);
        v22 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v51;
        goto LABEL_32;
      case FUEL_SHOW:
        std::wstring::wstring(&v55, L"FUEL_SWITCH");
        LOBYTE(v61) = 14;
        v26 = INIReader::getFloat(ini, &section, &v55);
        LOBYTE(v61) = 4;
        this->fswitch = v26;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v55);
        std::wstring::wstring(&v50, L"INVERTED");
        LOBYTE(v61) = 15;
        v27 = INIReader::getInt(ini, &section, &v50);
        v22 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v50;
        this->inverted = v27 != 0;
        goto LABEL_32;
      case DRS_ENABLED:
        std::wstring::wstring(&v57, L"BLINK_TIME");
        LOBYTE(v61) = 13;
        v25 = INIReader::getFloat(ini, &section, &v57);
        v22 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v57;
        goto LABEL_31;
      case TURBO_BOOST_LED:
        std::wstring::wstring(&v49, L"TURBO_SWITCH");
        LOBYTE(v61) = 10;
        this->fswitch = INIReader::getFloat(ini, &section, &v49);
        v22 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v49;
        goto LABEL_32;
      case TYRE_LOCK_SLIP:
        std::wstring::wstring(&v52, L"SLIP_SWITCH");
        LOBYTE(v61) = 16;
        v28 = INIReader::getFloat(ini, &section, &v52);
        LOBYTE(v61) = 4;
        this->blinkSwitch = v28;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v52);
        std::wstring::wstring(&v54, L"SHOW_LOCK");
        LOBYTE(v61) = 17;
        this->selectedWing = INIReader::getInt(ini, &section, &v54);
        LOBYTE(v61) = 4;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v54);
        std::wstring::wstring(&v56, L"TYRE_INDEX");
        LOBYTE(v61) = 18;
        v29 = INIReader::getInt(ini, &section, &v56);
        LOBYTE(v61) = 4;
        this->fswitch = (float)v29;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v56);
        std::wstring::wstring(&v58, L"EMISSIVE_LOCK");
        LOBYTE(v61) = 19;
        v30 = INIReader::getFloat3(ini, &_Right, &section, &v58);
        LOBYTE(v61) = 4;
        this->emissive2 = *v30;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v58);
        std::wstring::wstring(&v60, L"WHEEL_SPEED_MULT");
        LOBYTE(v61) = 20;
        v25 = INIReader::getFloat(ini, &section, &v60);
        v22 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v60;
LABEL_31:
        this->showMax = v25;
LABEL_32:
        LOBYTE(v61) = 4;
        std::wstring::~wstring(v22);
        break;
      case P2P_ENABLED_EXT:
        std::wstring::wstring(&v59, L"INVERTED");
        LOBYTE(v61) = 11;
        v23 = INIReader::getInt(ini, &section, &v59);
        LOBYTE(v61) = 4;
        this->inverted = v23 != 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
        std::wstring::wstring(&v53, L"BLINK_HZ");
        LOBYTE(v61) = 12;
        v24 = INIReader::getFloat(ini, &section, &v53);
        LOBYTE(v61) = 4;
        this->blinkFrequency = v24;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v53);
        this->showMax = 1.0;
        break;
      default:
        break;
    }
    v45._Myres = 7;
    v45._Mysize = 0;
    v45._Bx._Buf[0] = 0;
    std::wstring::assign(&v45, L"DIFFUSE", 7u);
    LOBYTE(v61) = 21;
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    std::wstring::assign(&vname, L"ksDiffuse", 9u);
    v31 = this->material._Ptr;
    LOBYTE(v61) = 22;
    _Right.x = INIReader::getFloat(ini, &section, &v45);
    v32 = Material::getVar(v31, &vname);
    v32->fValue = _Right.x;
    MaterialVar::set(v32);
    if ( vname._Myres >= 8 )
      operator delete(vname._Bx._Ptr);
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    LOBYTE(v61) = 4;
    if ( v45._Myres >= 8 )
      operator delete(v45._Bx._Ptr);
    v45._Myres = 7;
    v45._Mysize = 0;
    v45._Bx._Buf[0] = 0;
    std::wstring::assign(&v45, L"DIFFUSE", 7u);
    LOBYTE(v61) = 23;
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    std::wstring::assign(&vname, L"ksAmbient", 9u);
    v33 = this->material._Ptr;
    LOBYTE(v61) = 24;
    _Right.x = INIReader::getFloat(ini, &section, &v45);
    v34 = Material::getVar(v33, &vname);
    v34->fValue = _Right.x;
    MaterialVar::set(v34);
    if ( vname._Myres >= 8 )
      operator delete(vname._Bx._Ptr);
    vname._Myres = 7;
    vname._Mysize = 0;
    vname._Bx._Buf[0] = 0;
    LOBYTE(v61) = 4;
    if ( v45._Myres >= 8 )
      operator delete(v45._Bx._Ptr);
    v45._Myres = 7;
    v45._Mysize = 0;
    v45._Bx._Buf[0] = 0;
    std::wstring::assign(&v45, L"ksSpecular", 0xAu);
    v35 = this->material._Ptr;
    LOBYTE(v61) = 25;
    v36 = Material::getVar(v35, &v45);
    v36->fValue = 0.0;
    MaterialVar::set(v36);
    LOBYTE(v61) = 4;
    if ( v45._Myres >= 8 )
      operator delete(v45._Bx._Ptr);
    v45._Myres = 7;
    v45._Mysize = 0;
    v45._Bx._Buf[0] = 0;
    std::wstring::assign(&v45, L"ksEmissive", 0xAu);
    v37 = this->material._Ptr;
    LOBYTE(v61) = 26;
    v38 = Material::getVar(v37, &v45);
    v19 = v45._Myres < 8;
    this->varEmissive = v38;
    if ( !v19 )
      operator delete(v45._Bx._Ptr);
  }
  else
  {
    v10 = &target_name;
    if ( target_name._Myres >= 8 )
      v10 = (std::wstring *)target_name._Bx._Ptr;
    _printf("ERROR: Digital Led target %S\n", v10->_Bx._Buf);
  }
  if ( target_name._Myres >= 8 )
    operator delete(target_name._Bx._Ptr);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void DigitalLed::DigitalLed(DigitalLed *this, CarAvatar *a_car, std::wstring objectName, float valueSwitch, float bSwitch, float bFrequency)
{
  float v7; // xmm0_4
  Mesh *v8; // eax
  std::wstring *v9; // eax
  std::wstring v10; // [esp-1Ch] [ebp-38h] BYREF
  BOOL v11; // [esp-4h] [ebp-20h]
  DigitalLed *v12; // [esp+8h] [ebp-14h]
  int v13; // [esp+18h] [ebp-4h]

  v12 = this;
  this->emissive.x = 0.0;
  this->emissive.y = 0.0;
  this->emissive.z = 0.0;
  this->emissive2.x = 0.0;
  this->emissive2.y = 0.0;
  this->emissive2.z = 0.0;
  this->emissive3.x = 0.0;
  this->emissive3.y = 0.0;
  this->emissive3.z = 0.0;
  this->selectedWing = 0;
  *(_WORD *)&this->inverted = 0;
  this->showMin = 0.0;
  this->showMax = 0.0;
  this->showExcluded = 0;
  this->gForce = 0;
  this->gForceSign = 1;
  v13 = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  v11 = 1;
  this->fswitch = valueSwitch;
  this->blinkSwitch = bSwitch;
  v7 = bFrequency;
  this->car = a_car;
  this->targetMesh = 0;
  this->blinkFrequency = v7;
  this->type = RPM_HIDE;
  this->varEmissive = 0;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  LOBYTE(v13) = 1;
  std::wstring::assign(&v10, &objectName, 0, 0xFFFFFFFF);
  v8 = Node::getNodeChild<Mesh>(this->car->bodyTransform, v10, v11);
  this->targetMesh = v8;
  if ( !v8 )
  {
    v9 = &objectName;
    if ( objectName._Myres >= 8 )
      v9 = (std::wstring *)objectName._Bx._Ptr;
    _printf("ERROR: CANNOT FIND DigitalLed mesh:%S\n", v9->_Bx._Buf);
  }
  if ( objectName._Myres >= 8 )
    operator delete(objectName._Bx._Ptr);
}
void DigitalLed::~DigitalLed(DigitalLed *this)
{
  std::_Ref_count_base *v1; // esi

  v1 = this->material._Rep;
  if ( v1 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v1->_Uses, 0xFFFFFFFF) )
  {
    v1->_Destroy(v1);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v1->_Weaks) )
      v1->_Delete_this(v1);
  }
}
char DigitalLed::isWithinShowLimits(DigitalLed *this, float value)
{
  if ( !this->hasShowLimit )
    return 1;
  if ( this->showExcluded )
    return this->showMin >= value && value >= this->showMax;
  return value >= this->showMin && this->showMax >= value;
}
void DigitalLed::setShowLimits(DigitalLed *this, float mi, float mx, bool excluded)
{
  bool v4; // al

  v4 = mi != 0.0 || mx != 0.0;
  this->hasShowLimit = v4;
  this->showMin = mi;
  this->showMax = mx;
  this->showExcluded = excluded;
}
void DigitalLed::update(DigitalLed *this, float dt)
{
  CarAvatar *v3; // edi
  float v4; // xmm0_4
  MaterialVar *v5; // ecx
  float v6; // xmm0_4
  MaterialVar *v7; // ecx
  float v8; // xmm1_4
  MaterialVar *v9; // ecx
  unsigned __int8 v10; // al
  unsigned int v11; // edx
  WingState *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  float *v15; // eax
  float value; // xmm0_4
  Mesh *v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm2_4
  bool v20; // cf
  CarAvatar *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  Car *v25; // edi
  float v26; // xmm0_4
  double v27; // xmm1_8
  float v28; // xmm0_4
  float target; // xmm1_4
  Mesh *v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm0_4
  Mesh *v33; // ecx
  Mesh *v34; // ecx
  Mesh *v35; // ecx
  int v36; // eax
  float v37; // xmm2_4
  int v38; // eax
  float v39; // xmm2_4
  Mesh *v40; // ecx
  float v41; // xmm1_4
  float v42; // xmm2_4
  MaterialVar *v43; // ecx
  vec3f *v44; // eax
  float v45; // xmm1_4
  CarAvatar *v46; // eax
  MaterialVar *v47; // ecx
  MaterialVar *v48; // ecx
  vec3f *v49; // eax
  CarAvatar *v50; // ecx
  float v51; // xmm2_4
  vec3f v; // [esp+18h] [ebp-14h] BYREF
  float v53; // [esp+24h] [ebp-8h] BYREF
  float _X; // [esp+28h] [ebp-4h]

  v3 = this->car;
  if ( !v3->sim->pauseMenu->visible )
  {
    switch ( this->type )
    {
      case RPM:
        v43 = this->varEmissive;
        if ( v3->physicsState.engineRPM < this->fswitch )
        {
          v.x = 0.0;
          v44 = &v;
          v.y = 0.0;
          v.z = 0.0;
        }
        else
        {
          v44 = &this->emissive;
        }
        MaterialVar::setFloat3(v43, v44);
        v45 = this->blinkFrequency;
        if ( v45 != 0.0 )
        {
          v46 = this->car;
          if ( v46->physicsState.engineRPM >= this->blinkSwitch )
          {
            v7 = this->varEmissive;
            if ( !((int)(v46->game->gameTime.now / (float)(1000.0 / v45)) % 2) )
              goto LABEL_11;
            goto LABEL_129;
          }
        }
        return;
      case RPM_HIDE:
        v35 = this->targetMesh;
        if ( v35 )
        {
          v41 = this->blinkFrequency;
          if ( v41 == 0.0 || (v42 = v3->physicsState.engineRPM, v42 < this->blinkSwitch) )
          {
            v35->isActive = v3->physicsState.engineRPM >= this->fswitch;
          }
          else
          {
            if ( !((int)(v3->game->gameTime.now / (float)(1000.0 / v41)) % 2) )
              goto LABEL_100;
            v35->isActive = v42 >= this->fswitch;
          }
        }
        return;
      case FUEL_HIDE:
        v40 = this->targetMesh;
        if ( v40 )
          v40->isActive = v3->physicsState.fuel >= this->fswitch;
        return;
      case FUEL_SHOW:
        if ( this->targetMesh )
        {
          v.x = 0.0;
          v.y = 0.0;
          v.z = 0.0;
          if ( !operator==(&this->emissive, &v) )
          {
            v7 = this->varEmissive;
            if ( this->inverted )
            {
              v6 = v3->physicsState.fuel;
              goto LABEL_10;
            }
            if ( this->fswitch <= v3->physicsState.fuel )
              goto LABEL_11;
            goto LABEL_129;
          }
          v30 = this->targetMesh;
          if ( this->inverted )
          {
            v32 = v3->physicsState.fuel;
            goto LABEL_78;
          }
          v30->isActive = this->fswitch > v3->physicsState.fuel;
        }
        return;
      case KERS_CHARGE:
        if ( this->targetMesh )
        {
          value = v3->physicsState.kersCharge * 100.0;
          this->targetMesh->isActive = value >= this->fswitch && DigitalLed::isWithinShowLimits(this, value);
        }
        return;
      case KERS_INPUT:
        v30 = this->targetMesh;
        if ( v30 )
        {
          if ( !this->inverted )
          {
            v31 = v3->physicsState.kersInput;
            goto LABEL_77;
          }
          v30->isActive = this->fswitch >= (float)(v3->physicsState.kersInput * 100.0);
        }
        return;
      case WATER_TEMP:
        v33 = this->targetMesh;
        if ( v33 )
          v33->isActive = v3->physicsState.water >= this->fswitch;
        return;
      case TURBO_BOOST:
        v30 = this->targetMesh;
        if ( v30 )
        {
          v31 = v3->physicsState.turboBoost;
LABEL_77:
          v32 = v31 * 100.0;
          goto LABEL_78;
        }
        return;
      case DRS:
        if ( this->targetMesh )
        {
          v11 = this->selectedWing;
          if ( v11 < v3->wingsStatus._Mylast - v3->wingsStatus._Myfirst )
          {
            v12 = v3->wingsStatus._Myfirst;
            if ( this->inverted )
              this->targetMesh->isActive = this->fswitch >= v12[v11].angle;
            else
              this->targetMesh->isActive = v12[v11].angle >= this->fswitch;
          }
        }
        return;
      case GFORCES:
        v35 = this->targetMesh;
        if ( !v35 )
          return;
        v36 = this->gForce;
        v37 = 0.0;
        if ( v36 )
        {
          v38 = v36 - 1;
          if ( v38 )
          {
            if ( v38 != 1 )
              goto LABEL_99;
            v39 = v3->physicsState.accG.z;
          }
          else
          {
            v39 = v3->physicsState.accG.y;
          }
        }
        else
        {
          v39 = v3->physicsState.accG.x;
        }
        v37 = v39 * 1000.0;
LABEL_99:
        if ( (float)(v3->physicsState.speed.value * 3.5999999) >= 2.0 )
        {
          if ( v37 >= 0.0 && this->gForceSign > 0 || v37 < 0.0 && this->gForceSign < 0 )
            v35->isActive = COERCE_FLOAT(LODWORD(v37) & _xmm) > this->fswitch;
        }
        else
        {
LABEL_100:
          v35->isActive = 0;
        }
        return;
      case PERF:
        if ( this->targetMesh )
        {
          v4 = v3->physicsState.performanceMeter;
          if ( v4 > 0.0 )
            goto LABEL_44;
          v5 = this->varEmissive;
          if ( v4 >= 0.0 )
            MaterialVar::setFloat3(v5, &this->emissive3);
          else
            MaterialVar::setFloat3(v5, &this->emissive2);
        }
        return;
      case KERS_LOAD:
        v17 = this->targetMesh;
        if ( v17 )
        {
          v18 = v3->physicsInfo.kersMaxJ;
          if ( v18 > 0.0 )
          {
            v19 = v18 * 0.001;
            if ( this->inverted )
              v20 = this->fswitch < (float)((float)(v3->physicsState.kersCurrentKJ * 100.0) / v19);
            else
              v20 = (float)((float)(v3->physicsState.kersCurrentKJ * 100.0) / v19) < this->fswitch;
            v17->isActive = !v20;
          }
          v21 = this->car;
          v22 = v21->physicsInfo.ersMaxJ;
          if ( v22 > 0.0 )
          {
            v23 = v22 * 0.001;
            if ( !this->inverted )
            {
              v24 = (float)(v21->physicsState.kersCurrentKJ * 100.0) / v23;
              goto LABEL_74;
            }
            this->targetMesh->isActive = this->fswitch >= (float)((float)(v21->physicsState.kersCurrentKJ * 100.0) / v23);
          }
        }
        return;
      case DRS_AVAILABLE:
        v7 = this->varEmissive;
        if ( (v3->physicsState.statusBytes & 2) == 0 )
          goto LABEL_11;
        goto LABEL_46;
      case DRS_ENABLED:
        v13 = this->showMax;
        if ( v13 == 0.0 )
        {
          v7 = this->varEmissive;
          if ( (v3->physicsState.statusBytes & 4) != 0 )
          {
LABEL_46:
            MaterialVar::setFloat3(v7, &this->emissive);
          }
          else
          {
LABEL_11:
            v.x = 0.0;
            v.y = 0.0;
            v.z = 0.0;
            MaterialVar::setFloat3(v7, &v);
          }
          return;
        }
        if ( (v3->physicsState.statusBytes & 2) != 0 )
        {
          if ( (v3->physicsState.actionsState.state & 0x80000) != 0 && !this->hasShowLimit )
            this->showMin = v13;
          this->hasShowLimit = (v3->physicsState.actionsState.state & 0x80000) != 0;
        }
        v14 = this->showMin;
        if ( v14 > 0.0 )
        {
          v15 = &dt;
          v53 = 0.0;
          dt = v14 - dt;
          if ( dt <= 0.0 )
            v15 = &v53;
          this->showMin = *v15;
          goto LABEL_44;
        }
        goto LABEL_20;
      case KERS_ENABLED:
        v7 = this->varEmissive;
        if ( (v3->physicsState.actionsState.state & 0x100000) != 0 )
          goto LABEL_46;
        goto LABEL_11;
      case TURBO_BOOST_LED:
        if ( !this->targetMesh )
          return;
        v6 = v3->physicsState.turboBoost;
        v7 = this->varEmissive;
LABEL_10:
        if ( v6 < this->fswitch )
          goto LABEL_11;
LABEL_129:
        MaterialVar::setFloat3(v7, &this->emissive);
        return;
      case SPEED:
        v34 = this->targetMesh;
        if ( v34 )
          v34->isActive = (float)(v3->physicsState.speed.value * 3.5999999) >= this->fswitch;
        return;
      case POWER_918:
        if ( this->targetMesh )
        {
          v25 = v3->physics;
          if ( v25 )
          {
            v26 = v25->drivetrain.totalTorque;
            _X = FLOAT_1_0;
            v27 = v25->drivetrain.ratio;
            v53 = v26;
            if ( v27 != 0.0 )
              _X = v27;
            if ( isfinite<float>(v26) && isfinite<float>(_X) )
            {
              v28 = v53;
              if ( v25->drivetrain.ratio != 0.0 )
                v28 = v53 / _X;
              target = FLOAT_1000_0;
              if ( v28 <= 1000.0 )
              {
                target = 0.0;
                if ( v28 >= 0.0 )
                  target = v28;
              }
              dt = lerpDelta<float>(this->showMax, target, this->showMin, dt);
              v24 = dt;
              this->showMax = dt;
LABEL_74:
              this->targetMesh->isActive = v24 >= this->fswitch;
            }
          }
        }
        return;
      case KERS_RECHARGE:
        v30 = this->targetMesh;
        if ( v30 )
        {
          if ( this->inverted )
          {
            v30->isActive = this->fswitch >= v3->currentERSNormalizedRecharge;
          }
          else
          {
            v32 = v3->currentERSNormalizedRecharge;
LABEL_78:
            v30->isActive = v32 >= this->fswitch;
          }
        }
        return;
      case TYRE_LOCK_SLIP:
        v47 = this->varEmissive;
        v.x = 0.0;
        v.y = 0.0;
        v.z = 0.0;
        MaterialVar::setFloat3(v47, &v);
        v48 = this->varEmissive;
        if ( this->car->physicsState.ndSlip[this->fswitch] < this->blinkSwitch )
        {
          v.x = 0.0;
          v49 = &v;
          v.y = 0.0;
          v.z = 0.0;
        }
        else
        {
          v49 = &this->emissive;
        }
        MaterialVar::setFloat3(v48, v49);
        if ( this->selectedWing == 1 )
        {
          v50 = this->car;
          v51 = v50->physicsState.speed.value * 3.5999999;
          if ( (float)(this->showMax * v51) >= COERCE_FLOAT(LODWORD(v50->physicsState.wheelAngularSpeed[this->fswitch]) & _xmm)
            && v51 > 10.0 )
          {
            MaterialVar::setFloat3(this->varEmissive, &this->emissive2);
          }
        }
        return;
      case P2P_ENABLED_EXT:
        if ( !this->targetMesh )
          return;
        v8 = this->blinkFrequency;
        if ( v8 != 0.0 )
        {
          if ( (int)(v3->game->gameTime.now / (float)(1000.0 / v8)) % 2 )
            this->showMax = 0.0;
          else
            this->showMax = 1.0;
        }
        if ( this->inverted )
        {
          v10 = v3->physicsState.p2pStatus;
          if ( v10 == 3 || !v10 || this->showMax == 0.0 )
            goto LABEL_20;
          MaterialVar::setFloat3(this->varEmissive, &this->emissive);
        }
        else
        {
          if ( v3->physicsState.p2pStatus != 3 || this->showMax == 0.0 )
          {
LABEL_20:
            v9 = this->varEmissive;
            v.x = 0.0;
            v.y = 0.0;
            v.z = 0.0;
            MaterialVar::setFloat3(v9, &v);
            return;
          }
LABEL_44:
          MaterialVar::setFloat3(this->varEmissive, &this->emissive);
        }
        break;
      default:
        return;
    }
  }
}
