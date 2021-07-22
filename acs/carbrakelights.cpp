#include "carbrakelights.h"
void CarBrakeLights::CarBrakeLights(CarBrakeLights *this, CarAvatar *acar)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  std::wstring v5; // [esp-1Ch] [ebp-70h] BYREF
  Game *v6; // [esp-4h] [ebp-58h]
  CarBrakeLights *v7; // [esp+10h] [ebp-44h]
  std::wstring v8; // [esp+14h] [ebp-40h] BYREF
  std::wstring result; // [esp+2Ch] [ebp-28h] BYREF
  int v10; // [esp+50h] [ebp-4h]

  v7 = this;
  v6 = acar->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"CAR_BRAKE_LIGHTS", 0x10u);
  GameObject::GameObject(this, v5, v6);
  this->__vftable = (CarBrakeLights_vtbl *)&CarBrakeLights::`vftable';
  v10 = 0;
  this->vars._Myfirst = 0;
  this->vars._Mylast = 0;
  this->vars._Myend = 0;
  LOBYTE(v10) = 1;
  *(_WORD *)&this->frontLightsOn = 0;
  this->lightTriggerCount = 0;
  Trigger::Trigger(&this->frontLightsTrigger);
  LOBYTE(v10) = 2;
  v6 = (Game *)&acar->unixName;
  this->lockedLights = 0;
  v5._Myres = (unsigned int)L"content/cars/";
  v5._Mysize = (unsigned int)&result;
  this->flashingTime = 0.0;
  this->flashingBlink = 0.0;
  this->flashingCount = 0.0;
  this->flashingRepeat = 0;
  *(_WORD *)&this->hasPitLights = 0;
  this->pitLightTime = 0.0;
  this->pitLightBlink = 0.0;
  *(_WORD *)&this->hasKersLights = 0;
  this->kersLightTime = 0.0;
  this->kersLightBlink = 0.0;
  v3 = std::operator+<wchar_t>((std::wstring *)v5._Mysize, (const wchar_t *)v5._Myres, (const std::wstring *)v6);
  LOBYTE(v10) = 3;
  v4 = std::operator+<wchar_t>(&v8, v3, L"/data/lights.ini");
  LOBYTE(v10) = 4;
  FileChangeObserver::FileChangeObserver(&this->observer, v4);
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  LOBYTE(v10) = 7;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  this->car = acar;
  this->observeINI = 0.0;
  this->flashingRepeat = 0;
  this->flashingBlink = 0.0;
  CarBrakeLights::loadLights(this);
}
void CarBrakeLights::~CarBrakeLights(CarBrakeLights *this)
{
  this->__vftable = (CarBrakeLights_vtbl *)&CarBrakeLights::`vftable';
  BonusInfo::~BonusInfo((SGearRatio *)&this->observer);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->frontLightsTrigger);
  if ( this->vars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->vars);
    operator delete(this->vars._Myfirst);
    this->vars._Myfirst = 0;
    this->vars._Mylast = 0;
    this->vars._Myend = 0;
  }
  GameObject::~GameObject(this);
}
CarBrakeLights *CarBrakeLights::`vector deleting destructor'(CarBrakeLights *this, unsigned int a2)
{
  CarBrakeLights::~CarBrakeLights(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
bool CarBrakeLights::getFrontLightOn(CarBrakeLights *this)
{
  return this->frontLightsOn;
}
int CarBrakeLights::getVars(CarBrakeLights *this, const Mesh *m)
{
  int v2; // edi
  CarLightsVars *i; // esi

  v2 = 0;
  if ( !(this->vars._Mylast - this->vars._Myfirst) )
    return -1;
  for ( i = this->vars._Myfirst; i->mesh != m; ++i )
  {
    if ( ++v2 >= (unsigned int)(this->vars._Mylast - this->vars._Myfirst) )
      return -1;
  }
  return v2;
}
void CarBrakeLights::loadLights(CarBrakeLights *this)
{
  CarBrakeLights *v1; // ebx
  CarAvatar *v2; // eax
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  CarAvatar *v5; // ecx
  char v6; // al
  double v7; // st7
  bool v8; // cf
  int v9; // eax
  float v10; // xmm0_4
  double v11; // st7
  double v12; // st7
  int v13; // eax
  int v14; // ecx
  std::wstring *v15; // eax
  char v16; // al
  CarAvatar *v17; // eax
  Node **v18; // esi
  Node **v19; // edi
  Mesh *v20; // eax
  std::wstring *v21; // eax
  Material *v22; // eax
  Material *v23; // eax
  std::_Ref_count_base *v24; // edx
  Mesh *v25; // ecx
  Material *v26; // eax
  int v27; // edx
  int v28; // ecx
  MaterialVar *v29; // eax
  unsigned int v30; // eax
  int v31; // ecx
  int v32; // edx
  CarLightsVars *v33; // eax
  char *v34; // ebx
  const __m128i *v35; // eax
  __m128 v36; // xmm0
  char *v37; // ebx
  vec3f *v38; // eax
  CarBrakeLights *v39; // ebx
  Mesh *v40; // ecx
  double v41; // st7
  Game *v42; // ecx
  const vec3f *v43; // eax
  float *v44; // ebx
  float v45; // xmm1_4
  Mesh *v46; // ecx
  CarLightsVars *v47; // eax
  CarLightsVars *v48; // eax
  Mesh *v49; // edx
  CarLightsVars *v50; // ecx
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  Console *v53; // eax
  Console *v54; // eax
  std::_Ref_count_base *v55; // edx
  std::_Ref_count_base *v56; // ecx
  int v57; // esi
  std::wstring *v58; // eax
  char v59; // al
  CarAvatar *v60; // eax
  Node **v61; // esi
  Node **i; // edi
  std::wstring *v63; // ecx
  Material *v64; // eax
  Material *v65; // eax
  Mesh *v66; // edx
  std::_Ref_count_base *v67; // ecx
  Material *v68; // eax
  float v69; // edx
  int v70; // ecx
  MaterialVar *v71; // eax
  char v72; // al
  float v73; // eax
  unsigned int v74; // eax
  int v75; // ecx
  int v76; // edx
  CarLightsVars *v77; // eax
  char *v78; // ebx
  vec3f *v79; // eax
  int v80; // ebx
  char *v81; // ebx
  vec3f *v82; // eax
  CarBrakeLights *v83; // ebx
  Mesh *v84; // ecx
  double v85; // st7
  Game *v86; // ecx
  const vec3f *v87; // eax
  float *v88; // ebx
  float v89; // xmm1_4
  Mesh *v90; // ecx
  CarLightsVars *v91; // eax
  CarLightsVars *v92; // eax
  float v93; // xmm0_4
  float v94; // xmm1_4
  float v95; // eax
  Mesh *v96; // edx
  CarLightsVars *v97; // ecx
  char v98; // al
  float v99; // eax
  unsigned int v100; // eax
  int v101; // ecx
  int v102; // edx
  CarLightsVars *v103; // eax
  char *v104; // ebx
  vec3f *v105; // eax
  int v106; // ebx
  char *v107; // ebx
  vec3f *v108; // eax
  CarBrakeLights *v109; // ebx
  Mesh *v110; // ecx
  double v111; // st7
  Game *v112; // ecx
  const vec3f *v113; // eax
  float *v114; // ebx
  float v115; // xmm1_4
  Mesh *v116; // ecx
  CarBrakeLights *v117; // ebx
  CarLightsVars *v118; // eax
  CarLightsVars *v119; // eax
  float v120; // eax
  Mesh *v121; // edx
  CarLightsVars *v122; // ecx
  char v123; // al
  float v124; // eax
  unsigned int v125; // eax
  int v126; // ecx
  int v127; // edx
  CarLightsVars *v128; // eax
  char *v129; // ebx
  vec3f *v130; // eax
  int v131; // ebx
  char *v132; // ebx
  vec3f *v133; // eax
  CarBrakeLights *v134; // ebx
  Mesh *v135; // ecx
  double v136; // st7
  Game *v137; // ecx
  const vec3f *v138; // eax
  float *v139; // ebx
  float v140; // xmm1_4
  Mesh *v141; // ecx
  CarLightsVars *v142; // eax
  CarLightsVars *v143; // eax
  float v144; // xmm0_4
  float v145; // xmm1_4
  float v146; // eax
  Mesh *v147; // edx
  CarLightsVars *v148; // ecx
  char v149; // al
  char v150; // al
  unsigned int v151; // eax
  int v152; // ecx
  int v153; // edx
  CarLightsVars *v154; // eax
  char *v155; // ebx
  vec3f *v156; // eax
  int v157; // ebx
  char *v158; // ebx
  vec3f *v159; // eax
  CarBrakeLights *v160; // ebx
  Mesh *v161; // ecx
  double v162; // st7
  Game *v163; // ecx
  const vec3f *v164; // eax
  float *v165; // ebx
  float v166; // xmm1_4
  Mesh *v167; // ecx
  CarLightsVars *v168; // eax
  CarLightsVars *v169; // eax
  float v170; // eax
  Mesh *v171; // edx
  CarLightsVars *v172; // ecx
  AIDriver::{ctor}::__l57::<lambda_b1b5a2018750bb2261f39e860a2780a3> **v173; // eax
  std::wstring *v174; // eax
  Console *v175; // eax
  Console *v176; // eax
  double v177; // st7
  std::wstring v178; // [esp-10h] [ebp-274h] BYREF
  std::wstring v179[2]; // [esp+8h] [ebp-25Ch] BYREF
  char v180; // [esp+3Fh] [ebp-225h]
  CarBrakeLights *v181; // [esp+40h] [ebp-224h]
  int v182; // [esp+44h] [ebp-220h]
  Mesh *m; // [esp+48h] [ebp-21Ch] BYREF
  float v184; // [esp+4Ch] [ebp-218h] BYREF
  Mesh *v185; // [esp+50h] [ebp-214h]
  float v186; // [esp+54h] [ebp-210h] BYREF
  unsigned int v187; // [esp+58h] [ebp-20Ch]
  float v188; // [esp+5Ch] [ebp-208h] BYREF
  int v189; // [esp+60h] [ebp-204h]
  std::wstring *v190; // [esp+64h] [ebp-200h]
  std::shared_ptr<Material> mat; // [esp+68h] [ebp-1FCh] BYREF
  std::vector<Node *> objectsv; // [esp+70h] [ebp-1F4h] BYREF
  std::vector<Node *> objects; // [esp+7Ch] [ebp-1E8h] BYREF
  vec3f v194; // [esp+88h] [ebp-1DCh] BYREF
  vec3f v195; // [esp+94h] [ebp-1D0h] BYREF
  vec3f v196; // [esp+A0h] [ebp-1C4h] BYREF
  vec3f v197; // [esp+ACh] [ebp-1B8h] BYREF
  vec3f v198; // [esp+B8h] [ebp-1ACh] BYREF
  vec3f v199; // [esp+C4h] [ebp-1A0h] BYREF
  vec3f v200; // [esp+D0h] [ebp-194h] BYREF
  std::wstring section; // [esp+DCh] [ebp-188h] BYREF
  std::wstring key; // [esp+F4h] [ebp-170h] BYREF
  std::wstring objname; // [esp+10Ch] [ebp-158h] BYREF
  std::wstring v204; // [esp+134h] [ebp-130h] BYREF
  INIReader r; // [esp+14Ch] [ebp-118h] BYREF
  std::wstring _Left; // [esp+198h] [ebp-CCh] BYREF
  std::wstring v207; // [esp+1B0h] [ebp-B4h] BYREF
  std::wstring s; // [esp+1C8h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+1E0h] [ebp-84h] BYREF
  CarLightsVars clv; // [esp+1F8h] [ebp-6Ch] BYREF
  int v211; // [esp+260h] [ebp-4h]

  v1 = this;
  v181 = this;
  v184 = 0.0;
  v187 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v2 = v1->car;
  v211 = 0;
  v3 = std::operator+<wchar_t>(&result, &_Left, &v2->unixName);
  LOBYTE(v211) = 1;
  v4 = std::operator+<wchar_t>(&s, v3, L"/data/lights.ini");
  v5 = v1->car;
  LOBYTE(v211) = 2;
  CarAvatar::openINI(v5, &r, v4);
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v211) = 6;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&r, 1);
  if ( r.ready )
  {
    v189 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v211) = 7;
    v6 = INIReader::hasSection(&r, &section);
    v180 = v6;
    LOBYTE(v211) = 6;
    if ( section._Myres >= 8 )
    {
      operator delete(section._Bx._Ptr);
      v6 = v180;
    }
    if ( v6 )
    {
      std::wstring::wstring(&key, L"VERSION");
      LOBYTE(v211) = 8;
      std::wstring::wstring(&section, L"HEADER");
      LOBYTE(v211) = 9;
      v189 = INIReader::getInt(&r, &section, &key);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v211) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"FLASHING_BLINK_TIME");
      LOBYTE(v211) = 10;
      std::wstring::wstring(&section, L"HEADER");
      LOBYTE(v211) = 11;
      v180 = INIReader::hasKey(&r, &section, &key);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v211) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v180 )
      {
        std::wstring::wstring(&key, L"FLASHING_BLINK_TIME");
        LOBYTE(v211) = 12;
        std::wstring::wstring(&section, L"HEADER");
        LOBYTE(v211) = 13;
        v7 = INIReader::getFloat(&r, &section, &key);
        v8 = section._Myres < 8;
        v1->flashingBlink = v7;
        if ( !v8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v211) = 6;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        std::wstring::wstring(&key, L"FLASHING_REPEAT");
        LOBYTE(v211) = 14;
        std::wstring::wstring(&section, L"HEADER");
        LOBYTE(v211) = 15;
        v9 = (int)INIReader::getFloat(&r, &section, &key);
        v8 = section._Myres < 8;
        v1->flashingRepeat = v9;
        if ( !v8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v211) = 6;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        v10 = v1->flashingBlink;
        v1->pitLightBlink = v10;
        v1->kersLightBlink = v10;
      }
      std::wstring::wstring(&key, L"PITLINE_BLINK_TIME");
      LOBYTE(v211) = 16;
      std::wstring::wstring(&section, L"HEADER");
      LOBYTE(v211) = 17;
      v180 = INIReader::hasKey(&r, &section, &key);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v211) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v180 )
      {
        std::wstring::wstring(&key, L"PITLINE_BLINK_TIME");
        LOBYTE(v211) = 18;
        std::wstring::wstring(&section, L"HEADER");
        LOBYTE(v211) = 19;
        v11 = INIReader::getFloat(&r, &section, &key);
        v8 = section._Myres < 8;
        v1->pitLightBlink = v11;
        if ( !v8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v211) = 6;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
      std::wstring::wstring(&key, L"KERS_BLINK_TIME");
      LOBYTE(v211) = 20;
      std::wstring::wstring(&section, L"HEADER");
      LOBYTE(v211) = 21;
      v180 = INIReader::hasKey(&r, &section, &key);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v211) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v180 )
      {
        std::wstring::wstring(&key, L"KERS_BLINK_TIME");
        LOBYTE(v211) = 22;
        std::wstring::wstring(&section, L"HEADER");
        LOBYTE(v211) = 23;
        v12 = INIReader::getFloat(&r, &section, &key);
        v8 = section._Myres < 8;
        v1->kersLightBlink = v12;
        if ( !v8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v211) = 6;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
      std::wstring::wstring(&key, L"NO_LIGHT_SWITCH");
      LOBYTE(v211) = 24;
      std::wstring::wstring(&section, L"HEADER");
      LOBYTE(v211) = 25;
      v180 = INIReader::hasKey(&r, &section, &key);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v211) = 6;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v180 )
      {
        std::wstring::wstring(&key, L"NO_LIGHT_SWITCH");
        LOBYTE(v211) = 26;
        std::wstring::wstring(&section, L"HEADER");
        LOBYTE(v211) = 27;
        v13 = INIReader::getInt(&r, &section, &key);
        v8 = section._Myres < 8;
        v1->lockedLights = v13 != 0;
        if ( !v8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v211) = 6;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
    }
    v14 = 0;
    v180 = 1;
    v184 = 0.0;
    do
    {
      v15 = std::to_wstring(&key, v14);
      LOBYTE(v211) = 28;
      std::operator+<wchar_t>(&v207, L"BRAKE_", v15);
      LOBYTE(v211) = 30;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"NAME", 4u);
      LOBYTE(v211) = 31;
      v16 = INIReader::hasKey(&r, &v207, &section);
      HIBYTE(v182) = v16;
      LOBYTE(v211) = 30;
      if ( section._Myres >= 8 )
      {
        operator delete(section._Bx._Ptr);
        v16 = HIBYTE(v182);
      }
      if ( v16 )
      {
        v204._Myres = 7;
        v204._Mysize = 0;
        v204._Bx._Buf[0] = 0;
        std::wstring::assign(&v204, L"NAME", 4u);
        LOBYTE(v211) = 32;
        INIReader::getString(&r, &objname, &v207, &v204);
        if ( v204._Myres >= 8 )
          operator delete(v204._Bx._Ptr);
        v204._Myres = 7;
        v204._Mysize = 0;
        v204._Bx._Buf[0] = 0;
        objectsv._Myfirst = 0;
        objectsv._Mylast = 0;
        objectsv._Myend = 0;
        v17 = v1->car;
        LOBYTE(v211) = 35;
        v17->bodyTransform->findChildrenByName(v17->bodyTransform, &objname, &objectsv);
        v18 = objectsv._Myfirst;
        v19 = objectsv._Mylast;
        if ( objectsv._Myfirst != objectsv._Mylast )
        {
          do
          {
            *(float *)&v20 = COERCE_FLOAT(__RTDynamicCast(*v18, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0));
            m = v20;
            if ( *(float *)&v20 != 0.0 )
            {
              v21 = &v20->name;
              if ( v21->_Myres >= 8 )
                v21 = (std::wstring *)v21->_Bx._Ptr;
              _printf("ADDING BRAKE LIGHT: %S\n", v21->_Bx._Buf);
              v22 = (Material *)operator new(104);
              v190 = &v22->name;
              LOBYTE(v211) = 36;
              if ( v22 )
                Material::Material(v22, m->material._Ptr);
              else
                v23 = 0;
              LOBYTE(v211) = 35;
              mat._Ptr = 0;
              mat._Rep = 0;
              std::shared_ptr<Material>::_Resetp<Material>(&mat, v23);
              v24 = mat._Rep;
              LOBYTE(v211) = 37;
              if ( mat._Rep )
                _InterlockedExchangeAdd((volatile signed __int32 *)&mat._Rep->_Uses, 1u);
              v25 = m;
              v188 = *(float *)&m->material._Rep;
              v26 = mat._Ptr;
              m->material._Rep = v24;
              v27 = LODWORD(v188);
              v25->material._Ptr = v26;
              if ( v27 )
              {
                if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v27 + 4), 0xFFFFFFFF) )
                {
                  (**(void (***)(int))v27)(v27);
                  v28 = LODWORD(v188);
                  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v188) + 8), 0xFFFFFFFF) )
                    (*(void (**)(int))(*(_DWORD *)v28 + 4))(v28);
                }
              }
              section._Myres = 7;
              section._Mysize = 0;
              section._Bx._Buf[0] = 0;
              std::wstring::assign(&section, L"ksEmissive", 0xAu);
              LOBYTE(v211) = 38;
              v29 = Material::getVar(m->material._Ptr, &section);
              v190 = &v29->name;
              LOBYTE(v211) = 37;
              if ( section._Myres >= 8 )
              {
                operator delete(section._Bx._Ptr);
                v29 = (MaterialVar *)v190;
              }
              if ( v29 )
              {
                v30 = CarBrakeLights::getVars(v1, m);
                if ( v30 == -1 )
                {
                  CarLightsVars::CarLightsVars(&clv);
                  std::vector<CarLightsVars>::push_back(&v1->vars, &clv);
                  v31 = (char *)v1->vars._Mylast - (char *)v1->vars._Myfirst;
                  v1 = v181;
                  v30 = ((int)((unsigned __int64)(1717986919i64 * v31) >> 32) >> 4)
                      + ((unsigned int)((unsigned __int64)(1717986919i64 * v31) >> 32) >> 31)
                      - 1;
                }
                v32 = 5 * v30;
                v33 = v1->vars._Myfirst;
                v179[0]._Myres = (unsigned int)L"COLOR";
                v185 = (Mesh *)(8 * v32);
                *(Mesh **)((char *)&v33->mesh + (_DWORD)v185) = m;
                std::wstring::wstring(&key, (const wchar_t *)v179[0]._Myres);
                v34 = (char *)v185 + (unsigned int)v1->vars._Myfirst;
                LOBYTE(v211) = 39;
                v35 = (const __m128i *)INIReader::getFloat3(&r, &v195, &v207, &key);
                LOBYTE(v211) = 37;
                v36 = (__m128)_mm_loadl_epi64(v35);
                *((_QWORD *)v34 + 1) = v36.m128_u64[0];
                *((_DWORD *)v34 + 4) = v35->m128i_i32[2];
                if ( key._Myres >= 8 )
                  operator delete(key._Bx._Ptr);
                if ( v189 < 2 )
                {
                  v39 = v181;
                  v49 = v185;
                  v36.m128_f32[0] = 0.0;
                  objects._Myend = 0;
                  v50 = v181->vars._Myfirst;
                  *(_QWORD *)((char *)&v185->matrix.M21 + (_DWORD)v50) = _mm_unpacklo_ps(v36, (__m128)0i64).m128_u64[0];
                  *(float *)((char *)&v49->matrix.M23 + (_DWORD)v50) = 0.0;
                }
                else
                {
                  std::wstring::wstring(&key, L"OFF_COLOR");
                  LOBYTE(v211) = 40;
                  v37 = (char *)v185 + (unsigned int)v181->vars._Myfirst;
                  v38 = INIReader::getFloat3(&r, &v194, &v207, &key);
                  LOBYTE(v211) = 37;
                  *(vec3f *)(v37 + 20) = *v38;
                  if ( key._Myres >= 8 )
                    operator delete(key._Bx._Ptr);
                  v39 = v181;
                }
                v40 = v185;
                *(&v39->vars._Myfirst->brake + (unsigned int)v185) = 1;
                v41 = GraphicsManager::getLDRScale(
                        v39->game->graphics,
                        (const vec3f *)((char *)&v40->matrix.M21 + (unsigned int)v39->vars._Myfirst));
                v42 = v39->game;
                v43 = (const vec3f *)((char *)v185 + (unsigned int)&v39->vars._Myfirst->colors);
                v188 = v41;
                v44 = &v188;
                *(float *)&m = GraphicsManager::getLDRScale(v42->graphics, v43);
                if ( v188 <= *(float *)&m )
                  v44 = (float *)&m;
                if ( *v44 <= 1.0 )
                {
                  v1 = v181;
                }
                else
                {
                  _printf("Scaling down brake colors for PP off, factor: %f\n", *v44);
                  _printf(
                    "%s: (%f , %f , %f)\n",
                    "COLOR",
                    *(float *)((char *)&v181->vars._Myfirst->colors.x + (unsigned int)v185),
                    *(float *)((char *)&v181->vars._Myfirst->colors.y + (unsigned int)v185),
                    *(float *)((char *)&v181->vars._Myfirst->colors.z + (unsigned int)v185));
                  v45 = 1.0 / *v44;
                  v46 = v185;
                  v1 = v181;
                  v47 = v181->vars._Myfirst;
                  *(float *)((char *)&v185->matrix.M12 + (_DWORD)v47) = *(float *)((char *)&v185->matrix.M12
                                                                                 + (_DWORD)v47)
                                                                      * v45;
                  *(float *)((char *)&v46->matrix.M13 + (_DWORD)v47) = *(float *)((char *)&v46->matrix.M13 + (_DWORD)v47)
                                                                     * v45;
                  *(float *)((char *)&v46->matrix.M14 + (_DWORD)v47) = *(float *)((char *)&v46->matrix.M14 + (_DWORD)v47)
                                                                     * v45;
                  v48 = v1->vars._Myfirst;
                  *(float *)((char *)&v46->matrix.M21 + (_DWORD)v48) = *(float *)((char *)&v46->matrix.M21 + (_DWORD)v48)
                                                                     * v45;
                  *(float *)((char *)&v46->matrix.M22 + (_DWORD)v48) = *(float *)((char *)&v46->matrix.M22 + (_DWORD)v48)
                                                                     * v45;
                  *(float *)((char *)&v46->matrix.M23 + (_DWORD)v48) = *(float *)((char *)&v46->matrix.M23 + (_DWORD)v48)
                                                                     * v45;
                  _printf(
                    "%s: (%f , %f , %f)\n",
                    "COLOR scaled",
                    *(float *)((char *)&v1->vars._Myfirst->colors.x + (unsigned int)v46),
                    *(float *)((char *)&v1->vars._Myfirst->colors.y + (unsigned int)v46),
                    *(float *)((char *)&v1->vars._Myfirst->colors.z + (unsigned int)v46));
                }
              }
              else
              {
                v51 = &m->material._Ptr->shader->name;
                if ( m->material._Ptr->shader->name._Myres >= 8 )
                  v51 = (std::wstring *)v51->_Bx._Ptr;
                _printf("ERROR MATERIAL BRAKE SHADER: %S\n", v51->_Bx._Buf);
                v190 = v179;
                std::wstring::wstring(v179, L"\n");
                LOBYTE(v211) = 41;
                v52 = std::operator+<wchar_t>(&key, L"ERROR: BRAKE LIGHT ", &objname);
                LOBYTE(v211) = 42;
                v186 = COERCE_FLOAT(&v178);
                std::operator+<wchar_t>(&v178, v52, L" CAN'T FIND ksEmissive var");
                LOBYTE(v211) = 43;
                v53 = Console::singleton();
                LOBYTE(v211) = 42;
                v54 = Console::operator<<(v53, v178);
                LOBYTE(v211) = 44;
                Console::operator<<(v54, v179[0]);
                if ( key._Myres >= 8 )
                  operator delete(key._Bx._Ptr);
              }
              v55 = mat._Rep;
              LOBYTE(v211) = 35;
              if ( mat._Rep )
              {
                if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&mat._Rep->_Uses, 0xFFFFFFFF) )
                {
                  v55->_Destroy(v55);
                  v56 = mat._Rep;
                  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&mat._Rep->_Weaks, 0xFFFFFFFF) )
                    v56->_Delete_this(v56);
                }
              }
            }
            ++v18;
          }
          while ( v18 != v19 );
          v18 = objectsv._Myfirst;
        }
        LOBYTE(v211) = 34;
        if ( v18 )
        {
          std::_Container_base0::_Orphan_all(&objectsv);
          operator delete(objectsv._Myfirst);
          objectsv._Myfirst = 0;
          objectsv._Mylast = 0;
          objectsv._Myend = 0;
        }
        if ( objname._Myres >= 8 )
          operator delete(objname._Bx._Ptr);
      }
      else
      {
        v180 = 0;
      }
      v14 = LODWORD(v184) + 1;
      LOBYTE(v211) = 6;
      ++LODWORD(v184);
      if ( v207._Myres >= 8 )
      {
        operator delete(v207._Bx._Ptr);
        v14 = LODWORD(v184);
      }
    }
    while ( v180 );
    v57 = 0;
    v190 = 0;
    while ( 1 )
    {
      v58 = std::to_wstring(&objname, v57);
      LOBYTE(v211) = 45;
      std::operator+<wchar_t>(&v204, L"LIGHT_", v58);
      LOBYTE(v211) = 47;
      if ( objname._Myres >= 8 )
        operator delete(objname._Bx._Ptr);
      objname._Myres = 7;
      objname._Mysize = 0;
      objname._Bx._Buf[0] = 0;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"NAME", 4u);
      LOBYTE(v211) = 48;
      v59 = INIReader::hasKey(&r, &v204, &section);
      HIBYTE(v182) = v59;
      LOBYTE(v211) = 47;
      if ( section._Myres >= 8 )
      {
        operator delete(section._Bx._Ptr);
        v59 = HIBYTE(v182);
      }
      if ( !v59 )
        break;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"NAME", 4u);
      LOBYTE(v211) = 49;
      INIReader::getString(&r, &key, &v204, &section);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      objects._Myfirst = 0;
      objects._Mylast = 0;
      objects._Myend = 0;
      v60 = v1->car;
      LOBYTE(v211) = 52;
      v60->bodyTransform->findChildrenByName(v60->bodyTransform, &key, &objects);
      v61 = objects._Myfirst;
      for ( i = objects._Mylast; v61 != i; ++v61 )
      {
        v185 = (Mesh *)__RTDynamicCast(*v61, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
        if ( v185 )
        {
          v63 = &key;
          if ( key._Myres >= 8 )
            v63 = (std::wstring *)key._Bx._Ptr;
          _printf("ADDING LIGHT OBJECT %S\n", v63->_Bx._Buf);
          *(float *)&v64 = COERCE_FLOAT(operator new(104));
          v186 = *(float *)&v64;
          LOBYTE(v211) = 53;
          if ( *(float *)&v64 == 0.0 )
            v65 = 0;
          else
            Material::Material(v64, v185->material._Ptr);
          LOBYTE(v211) = 52;
          objectsv._Myfirst = 0;
          objectsv._Mylast = 0;
          std::shared_ptr<Material>::_Resetp<Material>((std::shared_ptr<Material> *)&objectsv, v65);
          LOBYTE(v211) = 54;
          mat._Ptr = 0;
          mat._Rep = 0;
          std::_Ptr_base<Font>::_Reset(&mat, (Material *)objectsv._Myfirst, (std::_Ref_count_base *)objectsv._Mylast);
          v66 = v185;
          v67 = v185->material._Rep;
          v185->material._Rep = mat._Rep;
          v68 = v66->material._Ptr;
          v184 = *(float *)&v67;
          v66->material._Ptr = mat._Ptr;
          v69 = v184;
          mat._Ptr = v68;
          if ( v184 != 0.0 && !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v184) + 4), 0xFFFFFFFF) )
          {
            (**(void (***)(_DWORD))LODWORD(v69))(LODWORD(v69));
            v70 = LODWORD(v184);
            if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v184) + 8), 0xFFFFFFFF) )
              (*(void (**)(int))(*(_DWORD *)v70 + 4))(v70);
          }
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          std::wstring::assign(&section, L"ksEmissive", 0xAu);
          LOBYTE(v211) = 55;
          *(float *)&v71 = COERCE_FLOAT(Material::getVar(v185->material._Ptr, &section));
          v188 = *(float *)&v71;
          LOBYTE(v211) = 54;
          if ( section._Myres >= 8 )
          {
            operator delete(section._Bx._Ptr);
            *(float *)&v71 = v188;
          }
          section._Myres = 7;
          section._Mysize = 0;
          section._Bx._Buf[0] = 0;
          if ( *(float *)&v71 == 0.0 )
          {
            v173 = (AIDriver::{ctor}::__l57::<lambda_b1b5a2018750bb2261f39e860a2780a3> **)&v185->material._Ptr->shader->name;
            if ( v185->material._Ptr->shader->name._Myres >= 8 )
              v173 = (AIDriver::{ctor}::__l57::<lambda_b1b5a2018750bb2261f39e860a2780a3> **)std::forward<_lambda_b1b5a2018750bb2261f39e860a2780a3_>(*v173);
            _printf("ERROR MATERIAL LIGHT SHADER: %S\n", (const wchar_t *)v173);
            v186 = COERCE_FLOAT(v179);
            std::wstring::wstring(v179, L"\n");
            LOBYTE(v211) = 75;
            v174 = std::operator+<wchar_t>((std::wstring *)&clv, L"ERROR: LIGHT LIGHT ", &key);
            LOBYTE(v211) = 76;
            v184 = COERCE_FLOAT(&v178);
            std::operator+<wchar_t>(&v178, v174, L" CAN'T FIND ksEmissive var");
            LOBYTE(v211) = 77;
            v175 = Console::singleton();
            LOBYTE(v211) = 76;
            v176 = Console::operator<<(v175, v178);
            LOBYTE(v211) = 78;
            Console::operator<<(v176, v179[0]);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&clv);
          }
          else
          {
            objname._Mysize = 0;
            objname._Myres = 7;
            objname._Bx._Buf[0] = 0;
            std::wstring::assign(&objname, L"FLASH", 5u);
            LOBYTE(v211) = 56;
            v72 = INIReader::hasKey(&r, &v204, &objname);
            HIBYTE(v182) = v72;
            LOBYTE(v211) = 54;
            if ( objname._Myres >= 8 )
            {
              operator delete(objname._Bx._Ptr);
              v72 = HIBYTE(v182);
            }
            if ( v72 )
            {
              std::wstring::wstring(&objname, L"FLASH");
              LOBYTE(v211) = 57;
              v73 = COERCE_FLOAT(INIReader::getInt(&r, &v204, &objname));
              v186 = v73;
              LOBYTE(v211) = 54;
              if ( objname._Myres >= 8 )
              {
                operator delete(objname._Bx._Ptr);
                v73 = v186;
              }
              if ( v73 != 0.0 )
              {
                v74 = CarBrakeLights::getVars(v1, v185);
                if ( v74 == -1 )
                {
                  CarLightsVars::CarLightsVars((CarLightsVars *)&objname);
                  std::vector<CarLightsVars>::push_back(&v1->vars, (const CarLightsVars *)&objname);
                  v75 = (char *)v1->vars._Mylast - (char *)v1->vars._Myfirst;
                  v1 = v181;
                  v74 = ((int)((unsigned __int64)(1717986919i64 * v75) >> 32) >> 4)
                      + ((unsigned int)((unsigned __int64)(1717986919i64 * v75) >> 32) >> 31)
                      - 1;
                }
                v76 = 5 * v74;
                v77 = v1->vars._Myfirst;
                v179[0]._Myres = (unsigned int)L"COLOR";
                m = (Mesh *)(8 * v76);
                *(Mesh **)((char *)&v77->mesh + (_DWORD)m) = v185;
                std::wstring::wstring(&objname, (const wchar_t *)v179[0]._Myres);
                v78 = (char *)m + (unsigned int)v1->vars._Myfirst;
                LOBYTE(v211) = 58;
                v79 = INIReader::getFloat3(&r, &v194, &v204, &objname);
                LOBYTE(v211) = 54;
                *(vec3f *)(v78 + 8) = *v79;
                if ( objname._Myres >= 8 )
                  operator delete(objname._Bx._Ptr);
                std::wstring::wstring(&objname, L"OFF_COLOR");
                LOBYTE(v211) = 59;
                v80 = v187 | 1;
                v187 = v80;
                v184 = *(float *)&v80;
                if ( !INIReader::hasKey(&r, &v204, &objname) || (v180 = 1, v189 < 3) )
                  v180 = 0;
                v211 = 54;
                if ( (v80 & 1) != 0 )
                {
                  v187 = v80 & 0xFFFFFFFE;
                  if ( objname._Myres >= 8 )
                    operator delete(objname._Bx._Ptr);
                }
                if ( v180 )
                {
                  std::wstring::wstring(&objname, L"OFF_COLOR");
                  LOBYTE(v211) = 60;
                  v81 = (char *)m + (unsigned int)v181->vars._Myfirst;
                  v82 = INIReader::getFloat3(&r, &v195, &v204, &objname);
                  LOBYTE(v211) = 54;
                  *(vec3f *)(v81 + 20) = *v82;
                  if ( objname._Myres >= 8 )
                    operator delete(objname._Bx._Ptr);
                  v83 = v181;
                }
                else
                {
                  v83 = v181;
                  v95 = v188;
                  v96 = m;
                  v97 = v181->vars._Myfirst;
                  *(_QWORD *)((char *)&v97->colorsOff.x + (_DWORD)m) = *(_QWORD *)(LODWORD(v188) + 36);
                  *(float *)((char *)&v97->colorsOff.z + (_DWORD)v96) = *(float *)(LODWORD(v95) + 44);
                }
                v84 = m;
                *((_BYTE *)&m->matrix.M31 + (unsigned int)v83->vars._Myfirst) = 1;
                v85 = GraphicsManager::getLDRScale(
                        v83->game->graphics,
                        (const vec3f *)((char *)&v84->matrix.M21 + (unsigned int)v83->vars._Myfirst));
                v86 = v83->game;
                v87 = (const vec3f *)((char *)m + (unsigned int)&v83->vars._Myfirst->colors);
                v184 = v85;
                v88 = &v184;
                v186 = GraphicsManager::getLDRScale(v86->graphics, v87);
                if ( v184 <= v186 )
                  v88 = &v186;
                if ( *v88 <= 1.0 )
                {
                  v1 = v181;
                }
                else
                {
                  _printf("Scaling down light colors for PP off, factor: %f\n", *v88);
                  _printf(
                    "%s: (%f , %f , %f)\n",
                    "COLOR",
                    *(float *)((char *)&m->matrix.M12 + (unsigned int)v181->vars._Myfirst),
                    *(float *)((char *)&m->matrix.M13 + (unsigned int)v181->vars._Myfirst),
                    *(float *)((char *)&m->matrix.M14 + (unsigned int)v181->vars._Myfirst));
                  v89 = 1.0 / *v88;
                  v90 = m;
                  v1 = v181;
                  v91 = v181->vars._Myfirst;
                  *(float *)((char *)&v91->colors.x + (_DWORD)m) = v89 * *(float *)((char *)&v91->colors.x + (_DWORD)m);
                  *(float *)((char *)&v91->colors.y + (_DWORD)v90) = *(float *)((char *)&v91->colors.y + (_DWORD)v90)
                                                                   * v89;
                  *(float *)((char *)&v91->colors.z + (_DWORD)v90) = *(float *)((char *)&v91->colors.z + (_DWORD)v90)
                                                                   * v89;
                  v92 = v1->vars._Myfirst;
                  *(float *)((char *)&v92->colorsOff.x + (_DWORD)v90) = *(float *)((char *)&v92->colorsOff.x
                                                                                 + (_DWORD)v90)
                                                                      * v89;
                  v93 = v89 * *(float *)((char *)&v92->colorsOff.y + (_DWORD)v90);
                  v94 = v89 * *(float *)((char *)&v92->colorsOff.z + (_DWORD)v90);
                  *(float *)((char *)&v92->colorsOff.y + (_DWORD)v90) = v93;
                  *(float *)((char *)&v92->colorsOff.z + (_DWORD)v90) = v94;
                  _printf(
                    "%s: (%f , %f , %f)\n",
                    "COLOR scaled",
                    *(float *)((char *)&v90->matrix.M12 + (unsigned int)v1->vars._Myfirst),
                    *(float *)((char *)&v90->matrix.M13 + (unsigned int)v1->vars._Myfirst),
                    *(float *)((char *)&v90->matrix.M14 + (unsigned int)v1->vars._Myfirst));
                }
              }
            }
            std::wstring::wstring(&objname, L"PITLINE");
            LOBYTE(v211) = 61;
            v98 = INIReader::hasKey(&r, &v204, &objname);
            HIBYTE(v182) = v98;
            LOBYTE(v211) = 54;
            if ( objname._Myres >= 8 )
            {
              operator delete(objname._Bx._Ptr);
              v98 = HIBYTE(v182);
            }
            if ( !v98 )
              goto LABEL_185;
            std::wstring::wstring(&objname, L"PITLINE");
            LOBYTE(v211) = 62;
            v99 = COERCE_FLOAT(INIReader::getInt(&r, &v204, &objname));
            v186 = v99;
            LOBYTE(v211) = 54;
            if ( objname._Myres >= 8 )
            {
              operator delete(objname._Bx._Ptr);
              v99 = v186;
            }
            if ( v99 == 0.0 )
              goto LABEL_185;
            v179[0]._Myres = (unsigned int)v185;
            v1->hasPitLights = 1;
            v100 = CarBrakeLights::getVars(v1, (const Mesh *)v179[0]._Myres);
            if ( v100 == -1 )
            {
              CarLightsVars::CarLightsVars((CarLightsVars *)&objname);
              std::vector<CarLightsVars>::push_back(&v1->vars, (const CarLightsVars *)&objname);
              v101 = (char *)v1->vars._Mylast - (char *)v1->vars._Myfirst;
              v1 = v181;
              v100 = ((int)((unsigned __int64)(1717986919i64 * v101) >> 32) >> 4)
                   + ((unsigned int)((unsigned __int64)(1717986919i64 * v101) >> 32) >> 31)
                   - 1;
            }
            v102 = 5 * v100;
            v103 = v1->vars._Myfirst;
            v179[0]._Myres = (unsigned int)L"COLOR";
            m = (Mesh *)(8 * v102);
            *(Mesh **)((char *)&v103->mesh + (_DWORD)m) = v185;
            std::wstring::wstring(&objname, (const wchar_t *)v179[0]._Myres);
            v104 = (char *)m + (unsigned int)v1->vars._Myfirst;
            LOBYTE(v211) = 63;
            v105 = INIReader::getFloat3(&r, &v199, &v204, &objname);
            LOBYTE(v211) = 54;
            *(vec3f *)(v104 + 8) = *v105;
            if ( objname._Myres >= 8 )
              operator delete(objname._Bx._Ptr);
            std::wstring::wstring(&objname, L"OFF_COLOR");
            LOBYTE(v211) = 64;
            v106 = v187 | 2;
            v187 = v106;
            v184 = *(float *)&v106;
            if ( !INIReader::hasKey(&r, &v204, &objname) || (v180 = 1, v189 < 3) )
              v180 = 0;
            v211 = 54;
            if ( (v106 & 2) != 0 )
            {
              v187 = v106 & 0xFFFFFFFD;
              if ( objname._Myres >= 8 )
                operator delete(objname._Bx._Ptr);
            }
            if ( v180 )
            {
              std::wstring::wstring(&objname, L"OFF_COLOR");
              LOBYTE(v211) = 65;
              v107 = (char *)m + (unsigned int)v181->vars._Myfirst;
              v108 = INIReader::getFloat3(&r, &v198, &v204, &objname);
              LOBYTE(v211) = 54;
              *(vec3f *)(v107 + 20) = *v108;
              if ( objname._Myres >= 8 )
                operator delete(objname._Bx._Ptr);
              v109 = v181;
            }
            else
            {
              v109 = v181;
              v120 = v188;
              v121 = m;
              v122 = v181->vars._Myfirst;
              *(_QWORD *)((char *)&v122->colorsOff.x + (_DWORD)m) = *(_QWORD *)(LODWORD(v188) + 36);
              *(float *)((char *)&v122->colorsOff.z + (_DWORD)v121) = *(float *)(LODWORD(v120) + 44);
            }
            v110 = m;
            *((_BYTE *)&m->matrix.M24 + (unsigned int)v109->vars._Myfirst + 2) = 1;
            v111 = GraphicsManager::getLDRScale(
                     v109->game->graphics,
                     (const vec3f *)((char *)&v110->matrix.M21 + (unsigned int)v109->vars._Myfirst));
            v112 = v109->game;
            v113 = (const vec3f *)((char *)m + (unsigned int)&v109->vars._Myfirst->colors);
            v186 = v111;
            v114 = &v186;
            v184 = GraphicsManager::getLDRScale(v112->graphics, v113);
            if ( v186 <= v184 )
              v114 = &v184;
            if ( *v114 <= 1.0 )
            {
LABEL_185:
              v117 = v181;
            }
            else
            {
              _printf("Scaling down light colors for PP off, factor: %f\n", *v114);
              _printf(
                "%s: (%f , %f , %f)\n",
                "COLOR",
                *(float *)((char *)&m->matrix.M12 + (unsigned int)v181->vars._Myfirst),
                *(float *)((char *)&m->matrix.M13 + (unsigned int)v181->vars._Myfirst),
                *(float *)((char *)&m->matrix.M14 + (unsigned int)v181->vars._Myfirst));
              v115 = 1.0 / *v114;
              v116 = m;
              v117 = v181;
              v118 = v181->vars._Myfirst;
              *(float *)((char *)&v118->colors.x + (_DWORD)m) = *(float *)((char *)&v118->colors.x + (_DWORD)m) * v115;
              *(float *)((char *)&v118->colors.y + (_DWORD)v116) = v115
                                                                 * *(float *)((char *)&v118->colors.y + (_DWORD)v116);
              *(float *)((char *)&v118->colors.z + (_DWORD)v116) = v115
                                                                 * *(float *)((char *)&v118->colors.z + (_DWORD)v116);
              v119 = v117->vars._Myfirst;
              *(float *)((char *)&v119->colorsOff.x + (_DWORD)v116) = v115
                                                                    * *(float *)((char *)&v119->colorsOff.x
                                                                               + (_DWORD)v116);
              *(float *)((char *)&v119->colorsOff.y + (_DWORD)v116) = *(float *)((char *)&v119->colorsOff.y
                                                                               + (_DWORD)v116)
                                                                    * v115;
              *(float *)((char *)&v119->colorsOff.z + (_DWORD)v116) = *(float *)((char *)&v119->colorsOff.z
                                                                               + (_DWORD)v116)
                                                                    * v115;
              _printf(
                "%s: (%f , %f , %f)\n",
                "COLOR scaled",
                *(float *)((char *)&v116->matrix.M12 + (unsigned int)v117->vars._Myfirst),
                *(float *)((char *)&v116->matrix.M13 + (unsigned int)v117->vars._Myfirst),
                *(float *)((char *)&v116->matrix.M14 + (unsigned int)v117->vars._Myfirst));
            }
            std::wstring::wstring(&objname, L"KERS");
            LOBYTE(v211) = 66;
            v123 = INIReader::hasKey(&r, &v204, &objname);
            HIBYTE(v182) = v123;
            LOBYTE(v211) = 54;
            if ( objname._Myres >= 8 )
            {
              operator delete(objname._Bx._Ptr);
              v123 = HIBYTE(v182);
            }
            if ( !v123 )
              goto LABEL_211;
            std::wstring::wstring(&objname, L"KERS");
            LOBYTE(v211) = 67;
            v124 = COERCE_FLOAT(INIReader::getInt(&r, &v204, &objname));
            v186 = v124;
            LOBYTE(v211) = 54;
            if ( objname._Myres >= 8 )
            {
              operator delete(objname._Bx._Ptr);
              v124 = v186;
            }
            if ( v124 == 0.0 )
              goto LABEL_211;
            v179[0]._Myres = (unsigned int)v185;
            v117->hasKersLights = 1;
            v125 = CarBrakeLights::getVars(v117, (const Mesh *)v179[0]._Myres);
            if ( v125 == -1 )
            {
              CarLightsVars::CarLightsVars((CarLightsVars *)&objname);
              std::vector<CarLightsVars>::push_back(&v117->vars, (const CarLightsVars *)&objname);
              v126 = (char *)v117->vars._Mylast - (char *)v117->vars._Myfirst;
              v117 = v181;
              v125 = ((int)((unsigned __int64)(1717986919i64 * v126) >> 32) >> 4)
                   + ((unsigned int)((unsigned __int64)(1717986919i64 * v126) >> 32) >> 31)
                   - 1;
            }
            v127 = 5 * v125;
            v128 = v117->vars._Myfirst;
            v179[0]._Myres = (unsigned int)L"COLOR";
            m = (Mesh *)(8 * v127);
            *(Mesh **)((char *)&v128->mesh + (_DWORD)m) = v185;
            std::wstring::wstring(&objname, (const wchar_t *)v179[0]._Myres);
            v129 = (char *)m + (unsigned int)v117->vars._Myfirst;
            LOBYTE(v211) = 68;
            v130 = INIReader::getFloat3(&r, &v200, &v204, &objname);
            LOBYTE(v211) = 54;
            *(vec3f *)(v129 + 8) = *v130;
            if ( objname._Myres >= 8 )
              operator delete(objname._Bx._Ptr);
            std::wstring::wstring(&objname, L"OFF_COLOR");
            LOBYTE(v211) = 69;
            v131 = v187 | 4;
            v187 = v131;
            v184 = *(float *)&v131;
            if ( !INIReader::hasKey(&r, &v204, &objname) || (v180 = 1, v189 < 3) )
              v180 = 0;
            v211 = 54;
            if ( (v131 & 4) != 0 )
            {
              v187 = v131 & 0xFFFFFFFB;
              if ( objname._Myres >= 8 )
                operator delete(objname._Bx._Ptr);
            }
            if ( v180 )
            {
              std::wstring::wstring(&objname, L"OFF_COLOR");
              LOBYTE(v211) = 70;
              v132 = (char *)m + (unsigned int)v181->vars._Myfirst;
              v133 = INIReader::getFloat3(&r, &v196, &v204, &objname);
              LOBYTE(v211) = 54;
              *(vec3f *)(v132 + 20) = *v133;
              if ( objname._Myres >= 8 )
                operator delete(objname._Bx._Ptr);
              v134 = v181;
            }
            else
            {
              v134 = v181;
              v146 = v188;
              v147 = m;
              v148 = v181->vars._Myfirst;
              *(_QWORD *)((char *)&v148->colorsOff.x + (_DWORD)m) = *(_QWORD *)(LODWORD(v188) + 36);
              *(float *)((char *)&v148->colorsOff.z + (_DWORD)v147) = *(float *)(LODWORD(v146) + 44);
            }
            v135 = m;
            *((_BYTE *)&m->matrix.M24 + (unsigned int)v134->vars._Myfirst + 3) = 1;
            v136 = GraphicsManager::getLDRScale(
                     v134->game->graphics,
                     (const vec3f *)((char *)&v135->matrix.M21 + (unsigned int)v134->vars._Myfirst));
            v137 = v134->game;
            v138 = (const vec3f *)((char *)m + (unsigned int)&v134->vars._Myfirst->colors);
            v186 = v136;
            v139 = &v186;
            v184 = GraphicsManager::getLDRScale(v137->graphics, v138);
            if ( v186 <= v184 )
              v139 = &v184;
            if ( *v139 <= 1.0 )
            {
LABEL_211:
              v1 = v181;
            }
            else
            {
              _printf("Scaling down light colors for PP off, factor: %f\n", *v139);
              _printf(
                "%s: (%f , %f , %f)\n",
                "COLOR",
                *(float *)((char *)&m->matrix.M12 + (unsigned int)v181->vars._Myfirst),
                *(float *)((char *)&m->matrix.M13 + (unsigned int)v181->vars._Myfirst),
                *(float *)((char *)&m->matrix.M14 + (unsigned int)v181->vars._Myfirst));
              v140 = 1.0 / *v139;
              v141 = m;
              v1 = v181;
              v142 = v181->vars._Myfirst;
              *(float *)((char *)&v142->colors.x + (_DWORD)m) = v140 * *(float *)((char *)&v142->colors.x + (_DWORD)m);
              *(float *)((char *)&v142->colors.y + (_DWORD)v141) = v140
                                                                 * *(float *)((char *)&v142->colors.y + (_DWORD)v141);
              *(float *)((char *)&v142->colors.z + (_DWORD)v141) = v140
                                                                 * *(float *)((char *)&v142->colors.z + (_DWORD)v141);
              v143 = v1->vars._Myfirst;
              *(float *)((char *)&v143->colorsOff.x + (_DWORD)v141) = *(float *)((char *)&v143->colorsOff.x
                                                                               + (_DWORD)v141)
                                                                    * v140;
              v144 = v140 * *(float *)((char *)&v143->colorsOff.y + (_DWORD)v141);
              v145 = v140 * *(float *)((char *)&v143->colorsOff.z + (_DWORD)v141);
              *(float *)((char *)&v143->colorsOff.y + (_DWORD)v141) = v144;
              *(float *)((char *)&v143->colorsOff.z + (_DWORD)v141) = v145;
              _printf(
                "%s: (%f , %f , %f)\n",
                "COLOR scaled",
                *(float *)((char *)&v141->matrix.M12 + (unsigned int)v1->vars._Myfirst),
                *(float *)((char *)&v141->matrix.M13 + (unsigned int)v1->vars._Myfirst),
                *(float *)((char *)&v141->matrix.M14 + (unsigned int)v1->vars._Myfirst));
            }
            std::wstring::wstring(&objname, L"SPECIAL");
            LOBYTE(v211) = 71;
            v149 = INIReader::hasKey(&r, &v204, &objname);
            LOBYTE(v211) = 54;
            v150 = v149 == 0;
            HIBYTE(v182) = v150;
            if ( objname._Myres >= 8 )
            {
              operator delete(objname._Bx._Ptr);
              v150 = HIBYTE(v182);
            }
            if ( v150 )
            {
              v151 = CarBrakeLights::getVars(v1, v185);
              if ( v151 == -1 )
              {
                CarLightsVars::CarLightsVars((CarLightsVars *)&objname);
                std::vector<CarLightsVars>::push_back(&v1->vars, (const CarLightsVars *)&objname);
                v152 = (char *)v1->vars._Mylast - (char *)v1->vars._Myfirst;
                v1 = v181;
                v151 = ((int)((unsigned __int64)(1717986919i64 * v152) >> 32) >> 4)
                     + ((unsigned int)((unsigned __int64)(1717986919i64 * v152) >> 32) >> 31)
                     - 1;
              }
              v153 = 5 * v151;
              v154 = v1->vars._Myfirst;
              v179[0]._Myres = (unsigned int)L"COLOR";
              m = (Mesh *)(8 * v153);
              *(Mesh **)((char *)&v154->mesh + (_DWORD)m) = v185;
              std::wstring::wstring(&objname, (const wchar_t *)v179[0]._Myres);
              v155 = (char *)m + (unsigned int)v1->vars._Myfirst;
              LOBYTE(v211) = 72;
              v156 = INIReader::getFloat3(&r, &v197, &v204, &objname);
              LOBYTE(v211) = 54;
              *(vec3f *)(v155 + 8) = *v156;
              if ( objname._Myres >= 8 )
                operator delete(objname._Bx._Ptr);
              std::wstring::wstring(&objname, L"OFF_COLOR");
              LOBYTE(v211) = 73;
              v157 = v187 | 8;
              v187 = v157;
              v184 = *(float *)&v157;
              if ( !INIReader::hasKey(&r, &v204, &objname) || (v180 = 1, v189 < 3) )
                v180 = 0;
              v211 = 54;
              if ( (v157 & 8) != 0 )
              {
                v187 = v157 & 0xFFFFFFF7;
                if ( objname._Myres >= 8 )
                  operator delete(objname._Bx._Ptr);
              }
              if ( v180 )
              {
                std::wstring::wstring(&objname, L"OFF_COLOR");
                LOBYTE(v211) = 74;
                v158 = (char *)m + (unsigned int)v181->vars._Myfirst;
                v159 = INIReader::getFloat3(&r, (vec3f *)&v207, &v204, &objname);
                LOBYTE(v211) = 54;
                *(vec3f *)(v158 + 20) = *v159;
                if ( objname._Myres >= 8 )
                  operator delete(objname._Bx._Ptr);
                v160 = v181;
              }
              else
              {
                v160 = v181;
                v170 = v188;
                v171 = m;
                v172 = v181->vars._Myfirst;
                *(_QWORD *)((char *)&v172->colorsOff.x + (_DWORD)m) = *(_QWORD *)(LODWORD(v188) + 36);
                *(float *)((char *)&v172->colorsOff.z + (_DWORD)v171) = *(float *)(LODWORD(v170) + 44);
              }
              v161 = m;
              *((_BYTE *)&m->matrix.M24 + (unsigned int)v160->vars._Myfirst + 1) = 1;
              v162 = GraphicsManager::getLDRScale(
                       v160->game->graphics,
                       (const vec3f *)((char *)&v161->matrix.M21 + (unsigned int)v160->vars._Myfirst));
              v163 = v160->game;
              v164 = (const vec3f *)((char *)m + (unsigned int)&v160->vars._Myfirst->colors);
              v186 = v162;
              v165 = &v186;
              v184 = GraphicsManager::getLDRScale(v163->graphics, v164);
              if ( v186 <= v184 )
                v165 = &v184;
              if ( *v165 <= 1.0 )
              {
                v1 = v181;
              }
              else
              {
                _printf("Scaling down light colors for PP off, factor: %f\n", *v165);
                _printf(
                  "%s: (%f , %f , %f)\n",
                  "COLOR",
                  *(float *)((char *)&m->matrix.M12 + (unsigned int)v181->vars._Myfirst),
                  *(float *)((char *)&m->matrix.M13 + (unsigned int)v181->vars._Myfirst),
                  *(float *)((char *)&m->matrix.M14 + (unsigned int)v181->vars._Myfirst));
                v166 = 1.0 / *v165;
                v167 = m;
                v1 = v181;
                v168 = v181->vars._Myfirst;
                *(float *)((char *)&v168->colors.x + (_DWORD)m) = v166 * *(float *)((char *)&v168->colors.x + (_DWORD)m);
                *(float *)((char *)&v168->colors.y + (_DWORD)v167) = v166
                                                                   * *(float *)((char *)&v168->colors.y + (_DWORD)v167);
                *(float *)((char *)&v168->colors.z + (_DWORD)v167) = v166
                                                                   * *(float *)((char *)&v168->colors.z + (_DWORD)v167);
                v169 = v1->vars._Myfirst;
                *(float *)((char *)&v169->colorsOff.x + (_DWORD)v167) = v166
                                                                      * *(float *)((char *)&v169->colorsOff.x
                                                                                 + (_DWORD)v167);
                *(float *)((char *)&v169->colorsOff.y + (_DWORD)v167) = *(float *)((char *)&v169->colorsOff.y
                                                                                 + (_DWORD)v167)
                                                                      * v166;
                *(float *)((char *)&v169->colorsOff.z + (_DWORD)v167) = *(float *)((char *)&v169->colorsOff.z
                                                                                 + (_DWORD)v167)
                                                                      * v166;
                _printf(
                  "%s: (%f , %f , %f)\n",
                  "COLOR scaled",
                  *(float *)((char *)&v167->matrix.M12 + (unsigned int)v1->vars._Myfirst),
                  *(float *)((char *)&v167->matrix.M13 + (unsigned int)v1->vars._Myfirst),
                  *(float *)((char *)&v167->matrix.M14 + (unsigned int)v1->vars._Myfirst));
              }
            }
          }
          LOBYTE(v211) = 52;
          std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&objectsv);
        }
      }
      std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>((std::vector<SplineIndexBound> *)&objects);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      v57 = (int)v190->_Bx._Buf + 1;
      LOBYTE(v211) = 6;
      v190 = (std::wstring *)((char *)v190 + 1);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
    }
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
  }
  v177 = ksRand(2.0, 3.0);
  v211 = -1;
  v1->pitLightTime = v177;
  INIReader::~INIReader(&r);
}
void CarBrakeLights::update(CarBrakeLights *this, float deltaT)
{
  CarLightsVars *v3; // eax
  CarLightsVars *v4; // edi
  CarLightsVars *v5; // esi
  Mesh *v6; // eax
  MaterialVar *v7; // eax
  bool v8; // cf
  CarAvatar *v9; // edx
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float *v13; // eax
  float v14; // xmm0_4
  bool v15; // al
  float v16; // xmm0_4
  bool v17; // al
  bool v18; // ah
  __m128 v19; // xmm1
  float v20; // eax
  float v21; // xmm0_4
  float v22; // xmm2_4
  float *v23; // eax
  float v24; // xmm0_4
  float v25; // eax
  float v26; // eax
  float v27; // xmm0_4
  float *v28; // eax
  float v29; // xmm0_4
  float v30; // eax
  CarLightsVars *v31; // edi
  CarLightsVars *i; // esi
  MaterialVar *v33; // ecx
  float v34; // eax
  MaterialVar *v35; // ecx
  bool v36; // zf
  MaterialVar *v37; // ecx
  float v38; // eax
  MaterialVar *v39; // ecx
  bool v40; // [esp+13h] [ebp-35h]
  float v41; // [esp+14h] [ebp-34h] BYREF
  float v42; // [esp+18h] [ebp-30h] BYREF
  float v43; // [esp+1Ch] [ebp-2Ch]
  std::wstring vname; // [esp+20h] [ebp-28h] BYREF
  int v45; // [esp+44h] [ebp-4h]

  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
    v43 = this->car->sim->replayManager->timeMult * deltaT;
  else
    v43 = deltaT;
  if ( this->observeINI != 0.0 && FileChangeObserver::hasChanged(&this->observer) )
  {
    INIReader::clearCache();
    CarBrakeLights::loadLights(this);
    std::_Container_base0::_Orphan_all(&this->vars);
    this->vars._Mylast = this->vars._Myfirst;
  }
  if ( this->vars._Mylast - this->vars._Myfirst )
  {
    v3 = this->vars._Myfirst;
    if ( !v3->matvar )
    {
      v4 = this->vars._Mylast;
      v5 = this->vars._Myfirst;
      if ( v3 != v4 )
      {
        do
        {
          vname._Myres = 7;
          vname._Mysize = 0;
          vname._Bx._Buf[0] = 0;
          std::wstring::assign(&vname, L"ksEmissive", 0xAu);
          v6 = v5->mesh;
          v45 = 0;
          v7 = Material::getVar(v6->material._Ptr, &vname);
          v8 = vname._Myres < 8;
          v5->matvar = v7;
          v45 = -1;
          if ( !v8 )
            operator delete(vname._Bx._Ptr);
          ++v5;
        }
        while ( v5 != v4 );
      }
    }
    if ( this->lockedLights )
      this->frontLightsOn = 0;
    else
      this->frontLightsOn = (this->car->physicsState.statusBytes & 1) != 0;
    v9 = this->car;
    if ( (v9->physicsState.actionsState.state & 0x400) != 0 && this->flashingTime == 0.0 && this->flashingCount == 0.0 )
    {
      v10 = this->flashingRepeat;
      if ( v10 )
      {
        v11 = this->flashingBlink;
        if ( v11 != 0.0 )
        {
          v36 = !this->frontLightsOn;
          this->flashingTime = v11;
          this->frontFlashLightsOn = v36;
          this->flashingCount = (float)v10;
        }
      }
    }
    v12 = this->flashingTime;
    if ( v12 != 0.0 )
    {
      v13 = &v41;
      v42 = 0.0;
      v41 = v12 - v43;
      if ( (float)(v12 - v43) <= 0.0 )
        v13 = &v42;
      v14 = *v13;
      this->flashingTime = *v13;
      if ( v14 == 0.0 )
      {
        v15 = this->frontFlashLightsOn;
        if ( v15 != this->frontLightsOn || (v16 = this->flashingCount - 1.0, this->flashingCount = v16, v16 != 0.0) )
        {
          this->frontFlashLightsOn = !v15;
          this->flashingTime = this->flashingBlink;
        }
      }
    }
    v17 = CarAvatar::isInPitlane(v9);
    v18 = v17;
    v40 = v17;
    v19 = 0i64;
    if ( this->hasPitLights )
    {
      if ( v17 && this->pitLightTime == 0.0 )
      {
        v20 = this->pitLightBlink;
        this->pitLightsOn = 1;
        this->pitLightTime = v20;
      }
      v21 = this->pitLightTime;
      v22 = v43;
      if ( v21 != 0.0 )
      {
        v41 = 0.0;
        v23 = &v42;
        v42 = v21 - v43;
        if ( (float)(v21 - v43) <= 0.0 )
          v23 = &v41;
        v24 = *v23;
        this->pitLightTime = *v23;
        if ( v24 == 0.0 && this->pitLightsOn )
        {
          v25 = this->pitLightBlink;
          this->pitLightsOn = 0;
          this->pitLightTime = v25;
        }
      }
      v18 = v40;
    }
    else
    {
      v22 = v43;
    }
    if ( this->hasKersLights )
    {
      if ( !v18 && this->car->physicsState.kersIsCharging && this->kersLightTime == 0.0 )
      {
        v26 = this->kersLightBlink;
        this->kersLightsOn = 1;
        this->kersLightTime = v26;
      }
      v27 = this->kersLightTime;
      if ( v27 != 0.0 )
      {
        v41 = 0.0;
        v28 = &v42;
        v42 = v27 - v22;
        if ( (float)(v27 - v22) <= 0.0 )
          v28 = &v41;
        v29 = *v28;
        this->kersLightTime = *v28;
        if ( v29 == 0.0 && this->kersLightsOn )
        {
          v30 = this->kersLightBlink;
          this->kersLightsOn = 0;
          this->kersLightTime = v30;
        }
      }
    }
    v31 = this->vars._Mylast;
    for ( i = this->vars._Myfirst; i != v31; v19 = 0i64 )
    {
      if ( i->brake )
      {
        v33 = i->matvar;
        if ( this->car->physicsState.brake <= 0.0099999998 )
        {
          if ( this->frontLightsOn )
          {
            *(_QWORD *)&v33->fValue3.x = *(_QWORD *)&i->colorsOff.x;
            v34 = i->colorsOff.z;
          }
          else
          {
            *(_DWORD *)&vname._Bx._Alias[8] = 0;
            v34 = 0.0;
            *(_QWORD *)&v33->fValue3.x = _mm_unpacklo_ps(v19, v19).m128_u64[0];
          }
        }
        else
        {
          *(_QWORD *)&v33->fValue3.x = *(_QWORD *)&i->colors.x;
          v34 = i->colors.z;
        }
        v33->fValue3.z = v34;
        MaterialVar::set(v33);
      }
      if ( v40 )
      {
        if ( i->kers )
        {
          v35 = i->matvar;
          *(_QWORD *)&v35->fValue3.x = *(_QWORD *)&i->colorsOff.x;
          v35->fValue3.z = i->colorsOff.z;
          MaterialVar::set(v35);
        }
        if ( i->pitline )
        {
          v36 = !this->pitLightsOn;
LABEL_65:
          v37 = i->matvar;
          if ( v36 )
          {
            *(_QWORD *)&v37->fValue3.x = *(_QWORD *)&i->colorsOff.x;
            v38 = i->colorsOff.z;
          }
          else
          {
            *(_QWORD *)&v37->fValue3.x = *(_QWORD *)&i->colors.x;
            v38 = i->colors.z;
          }
          v37->fValue3.z = v38;
          MaterialVar::set(v37);
          goto LABEL_78;
        }
      }
      else
      {
        if ( i->pitline )
        {
          v39 = i->matvar;
          *(_QWORD *)&v39->fValue3.x = *(_QWORD *)&i->colorsOff.x;
          v39->fValue3.z = i->colorsOff.z;
          MaterialVar::set(v39);
        }
        if ( i->kers )
        {
          v36 = !this->kersLightsOn;
          goto LABEL_65;
        }
      }
      if ( i->flash && this->flashingCount != 0.0 )
      {
        v36 = !this->frontFlashLightsOn;
        goto LABEL_65;
      }
      if ( i->normal )
      {
        v36 = !this->frontLightsOn;
        goto LABEL_65;
      }
LABEL_78:
      ++i;
    }
  }
}
