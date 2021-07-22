#include "digitalpanels.h"
void DigitalPanels::DigitalPanels(DigitalPanels *this, CarAvatar *a_car)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  std::wstring v5; // [esp-1Ch] [ebp-70h] BYREF
  Game *v6; // [esp-4h] [ebp-58h]
  DigitalPanels *v7; // [esp+10h] [ebp-44h]
  std::wstring v8; // [esp+14h] [ebp-40h] BYREF
  std::wstring result; // [esp+2Ch] [ebp-28h] BYREF
  int v10; // [esp+50h] [ebp-4h]

  v7 = this;
  v6 = a_car->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"DIGITAL_PANELS", 0xEu);
  GameObject::GameObject(this, v5, v6);
  v10 = 0;
  v6 = (Game *)&a_car->unixName;
  this->__vftable = (DigitalPanels_vtbl *)&DigitalPanels::`vftable';
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", (const std::wstring *)v6);
  LOBYTE(v10) = 1;
  v4 = std::operator+<wchar_t>(&v8, v3, L"/data/digital_panels.ini");
  LOBYTE(v10) = 2;
  FileChangeObserver::FileChangeObserver(&this->observer, v4);
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->items._Myfirst = 0;
  this->items._Mylast = 0;
  this->items._Myend = 0;
  this->leds._Myfirst = 0;
  this->leds._Mylast = 0;
  this->leds._Myend = 0;
  LOBYTE(v10) = 7;
  this->car = a_car;
  this->observeINI = 0.0;
  this->lastPosition = -1;
  this->boostCount = -1;
  this->P2PblinkFrequency = -1.0;
  DigitalPanels::initPanels(this);
}
void DigitalPanels::~DigitalPanels(DigitalPanels *this)
{
  DigitalLed **v2; // eax

  this->__vftable = (DigitalPanels_vtbl *)&DigitalPanels::`vftable';
  std::_For_each<DigitalPanelItem *,_lambda_0c55fedeafba8993e34832c3aa51cef7_>(
    this->items._Myfirst,
    this->items._Mylast);
  std::_Container_base0::_Orphan_all(&this->items);
  this->items._Mylast = this->items._Myfirst;
  std::_For_each<DigitalLed * *,_lambda_a246c9d126492f70adaa09c76fae6a41_>(this->leds._Myfirst, this->leds._Mylast);
  std::_Container_base0::_Orphan_all(&this->leds);
  v2 = this->leds._Myfirst;
  this->leds._Mylast = v2;
  if ( v2 )
  {
    std::_Container_base0::_Orphan_all(&this->leds);
    operator delete(this->leds._Myfirst);
    this->leds._Myfirst = 0;
    this->leds._Mylast = 0;
    this->leds._Myend = 0;
  }
  if ( this->items._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->items);
    operator delete(this->items._Myfirst);
    this->items._Myfirst = 0;
    this->items._Mylast = 0;
    this->items._Myend = 0;
  }
  BonusInfo::~BonusInfo((SGearRatio *)&this->observer);
  GameObject::~GameObject(this);
}
DigitalPanels *DigitalPanels::`vector deleting destructor'(DigitalPanels *this, unsigned int a2)
{
  DigitalPanels::~DigitalPanels(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DigitalPanels::initPanels(DigitalPanels *this)
{
  DigitalPanels *v1; // esi
  std::vector<SplineIndexBound> *v2; // ebp
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  CarAvatar *v5; // ecx
  int v6; // edi
  std::wstring *v7; // eax
  int v8; // ebx
  CarAvatar *v9; // eax
  Node **v10; // esi
  Node **v11; // edi
  Node **v12; // ecx
  Node **v13; // eax
  std::wstring *v14; // ebx
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  DigitalLed *v19; // ebx
  std::wstring *v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // ebx
  Texture *v23; // eax
  void *v24; // ecx
  const std::wstring *v25; // eax
  const __m128i *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm0_4
  vec3f *v29; // eax
  SplineIndexBound *v30; // edx
  SplineIndexBound *v31; // ecx
  int v32; // ebx
  int v33; // edx
  unsigned int v34; // ecx
  Node **v35; // ecx
  SplineIndexBound *v36; // ecx
  SplineIndexBound *v37; // edx
  SplineIndexBound *v38; // eax
  Console *v39; // eax
  Console *v40; // eax
  Console *v41; // eax
  Console *v42; // eax
  int v43; // ebx
  std::wstring *v44; // eax
  Node **v45; // ebx
  double v46; // st7
  bool v47; // cf
  CarAvatar *v48; // eax
  float v49; // esi
  float v50; // edi
  DigitalPanels *v51; // edi
  int v52; // esi
  std::wstring *v53; // ebx
  CarAvatar *v54; // eax
  std::wstring *v55; // eax
  std::wstring *v56; // eax
  std::wstring *v57; // eax
  std::wstring *v58; // eax
  DisplayNode *v59; // ebx
  std::wstring *v60; // eax
  int v61; // eax
  int v62; // ebx
  Texture *v63; // eax
  void *v64; // ecx
  const std::wstring *v65; // eax
  std::allocator<wchar_t> *v66; // eax
  const __m128i *v67; // eax
  double v68; // st7
  float v69; // xmm1_4
  const vec3f *v70; // eax
  Console *v71; // eax
  Console *v72; // eax
  Console *v73; // eax
  Console *v74; // eax
  int v75; // ebx
  std::wstring *v76; // eax
  std::vector<ICollisionObject *> *v77; // ebp
  Node *v78; // esi
  int v79; // ebx
  TyreCompoundDef *v80; // eax
  unsigned int v81; // edi
  DigitalLed *v82; // esi
  DigitalLed *v83; // eax
  DigitalLed *v84; // esi
  std::wstring *v85; // eax
  bool v86; // al
  std::wstring v87; // [esp-60h] [ebp-29Ch] BYREF
  std::wstring v88; // [esp-48h] [ebp-284h] BYREF
  _BYTE v89[48]; // [esp-30h] [ebp-26Ch] BYREF
  int v90; // [esp+14h] [ebp-228h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > _S21; // [esp+18h] [ebp-224h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > _S20; // [esp+1Ch] [ebp-220h] BYREF
  DigitalPanels *v93; // [esp+20h] [ebp-21Ch]
  int _Val; // [esp+24h] [ebp-218h]
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > v95; // [esp+28h] [ebp-214h]
  int v96; // [esp+2Ch] [ebp-210h]
  int v97; // [esp+30h] [ebp-20Ch]
  DigitalLed *ld; // [esp+34h] [ebp-208h] BYREF
  std::vector<Node *> ns; // [esp+38h] [ebp-204h] BYREF
  _BYTE *v100; // [esp+44h] [ebp-1F8h]
  int *v101; // [esp+48h] [ebp-1F4h]
  std::wstring *v102; // [esp+4Ch] [ebp-1F0h]
  int v103; // [esp+50h] [ebp-1ECh]
  vec3f v104; // [esp+54h] [ebp-1E8h] BYREF
  DigitalPanelItem panel; // [esp+60h] [ebp-1DCh] BYREF
  vec4f v106; // [esp+68h] [ebp-1D4h] BYREF
  Texture v107; // [esp+78h] [ebp-1C4h] BYREF
  std::wstring key; // [esp+94h] [ebp-1A8h] BYREF
  std::wstring v109; // [esp+ACh] [ebp-190h] BYREF
  std::wstring p; // [esp+C4h] [ebp-178h] BYREF
  std::wstring filename; // [esp+DCh] [ebp-160h] BYREF
  std::wstring section; // [esp+F4h] [ebp-148h] BYREF
  std::wstring v113; // [esp+10Ch] [ebp-130h] BYREF
  std::wstring v114; // [esp+124h] [ebp-118h] BYREF
  std::wstring v115; // [esp+13Ch] [ebp-100h] BYREF
  std::wstring a_name; // [esp+154h] [ebp-E8h] BYREF
  Texture _Right; // [esp+16Ch] [ebp-D0h] BYREF
  std::wstring s; // [esp+188h] [ebp-B4h] BYREF
  INIReader r; // [esp+1A0h] [ebp-9Ch] BYREF
  std::wstring prefix; // [esp+1E4h] [ebp-58h] BYREF
  std::wstring v121; // [esp+1FCh] [ebp-40h] BYREF
  std::wstring result; // [esp+214h] [ebp-28h] BYREF
  int v123; // [esp+238h] [ebp-4h]

  v1 = this;
  v93 = this;
  *(float *)&v95._Ptr = 0.0;
  *(float *)&_S21._Ptr = 0.0;
  _printf("DigitalPanels::initPanel()\n");
  *(_DWORD *)&v89[40] = &v90;
  v2 = (std::vector<SplineIndexBound> *)&v1->items;
  std::_For_each<DigitalPanelItem *,_lambda_0c55fedeafba8993e34832c3aa51cef7_>(v1->items._Myfirst, v1->items._Mylast);
  std::_Container_base0::_Orphan_all(&v1->items);
  v1->items._Mylast = v1->items._Myfirst;
  *(_DWORD *)&v89[44] = &v90;
  std::_For_each<DigitalLed * *,_lambda_a246c9d126492f70adaa09c76fae6a41_>(v1->leds._Myfirst, v1->leds._Mylast);
  std::_Container_base0::_Orphan_all(&v1->leds);
  v1->leds._Mylast = v1->leds._Myfirst;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &v1->car->unixName);
  v123 = 0;
  v4 = std::operator+<wchar_t>(&v121, v3, L"/data/digital_panels.ini");
  v5 = v1->car;
  LOBYTE(v123) = 1;
  CarAvatar::openINI(v5, &r, v4);
  if ( v121._Myres >= 8 )
    operator delete(v121._Bx._Ptr);
  v121._Myres = 7;
  v121._Mysize = 0;
  v121._Bx._Buf[0] = 0;
  LOBYTE(v123) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&r, 0);
  if ( r.ready )
  {
    v6 = 0;
    v96 = 0;
    while ( 1 )
    {
      v7 = std::to_wstring((std::wstring *)&v107, v6);
      LOBYTE(v123) = 5;
      std::operator+<wchar_t>(&section, L"FULLPOSITION_SERIES_", v7);
      LOBYTE(v123) = 7;
      if ( v107.fileName._Mysize >= 8 )
        operator delete(v107.kid);
      v107.fileName._Mysize = 7;
      LOWORD(v107.kid) = 0;
      *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
      if ( !INIReader::hasSection(&r, &section) )
        break;
      key._Myres = 7;
      v1->lastPosition = 0;
      v101 = &v1->lastPosition;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"PREFIX", 6u);
      LOBYTE(v123) = 8;
      INIReader::getString(&r, &prefix, &section, &key);
      LOBYTE(v123) = 10;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      std::wstring::assign(&v109, L"START", 5u);
      LOBYTE(v123) = 11;
      _Val = INIReader::getInt(&r, &section, &v109);
      LOBYTE(v123) = 10;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      std::wstring::assign(&v109, L"END", 3u);
      LOBYTE(v123) = 12;
      v8 = INIReader::getInt(&r, &section, &v109);
      v103 = v8;
      LOBYTE(v123) = 10;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      std::wstring::assign(&v109, L"PARENT", 6u);
      LOBYTE(v123) = 13;
      INIReader::getString(&r, &p, &section, &v109);
      LOBYTE(v123) = 15;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      if ( std::wstring::compare(&p, 0, p._Mysize, L"NULL", 4u) )
      {
        ns._Myfirst = 0;
        ns._Mylast = 0;
        ns._Myend = 0;
        v9 = v1->car;
        LOBYTE(v123) = 16;
        v9->bodyTransform->findChildrenByName(v9->bodyTransform, &p, &ns);
        v10 = ns._Myfirst;
        v11 = ns._Mylast;
        if ( ns._Myfirst != ns._Mylast )
        {
          v12 = (Node **)_Val;
          do
          {
            v97 = *(int *)v10;
            v13 = v12;
            _S20._Ptr = v12;
            if ( (int)v12 <= v8 )
            {
              do
              {
                v14 = std::to_wstring(&v115, (int)v13);
                LOBYTE(v123) = 17;
                key._Myres = 7;
                key._Mysize = 0;
                key._Bx._Buf[0] = 0;
                std::wstring::assign(&key, L"content/cars/", 0xDu);
                LOBYTE(v123) = 18;
                v15 = std::operator+<wchar_t>(&v113, &key, &v93->car->unixName);
                LOBYTE(v123) = 19;
                v16 = std::operator+<wchar_t>(&a_name, v15, L"/texture/display_panel/");
                LOBYTE(v123) = 20;
                v17 = std::operator+<wchar_t>(&v114, v16, &prefix);
                LOBYTE(v123) = 21;
                v18 = std::operator+<wchar_t>(&s, v17, v14);
                LOBYTE(v123) = 22;
                std::operator+<wchar_t>(&filename, v18, L".dds");
                if ( s._Myres >= 8 )
                  operator delete(s._Bx._Ptr);
                s._Myres = 7;
                s._Mysize = 0;
                s._Bx._Buf[0] = 0;
                if ( v114._Myres >= 8 )
                  operator delete(v114._Bx._Ptr);
                v114._Myres = 7;
                v114._Mysize = 0;
                v114._Bx._Buf[0] = 0;
                if ( a_name._Myres >= 8 )
                  operator delete(a_name._Bx._Ptr);
                a_name._Myres = 7;
                a_name._Mysize = 0;
                a_name._Bx._Buf[0] = 0;
                if ( v113._Myres >= 8 )
                  operator delete(v113._Bx._Ptr);
                v113._Myres = 7;
                v113._Mysize = 0;
                v113._Bx._Buf[0] = 0;
                if ( key._Myres >= 8 )
                  operator delete(key._Bx._Ptr);
                key._Myres = 7;
                key._Mysize = 0;
                key._Bx._Buf[0] = 0;
                LOBYTE(v123) = 29;
                if ( v115._Myres >= 8 )
                  operator delete(v115._Bx._Ptr);
                v115._Myres = 7;
                v115._Bx._Buf[0] = 0;
                v115._Mysize = 0;
                if ( Path::fileExists((unsigned int)v14, &filename, 0) )
                {
                  panel.type = FullPosition;
                  v19 = (DigitalLed *)operator new(292);
                  ld = v19;
                  LOBYTE(v123) = 30;
                  if ( v19 )
                  {
                    v20 = std::to_wstring((std::wstring *)&_Right, (int)_S20._Ptr);
                    LOBYTE(v123) = 31;
                    v95._Ptr = (Node **)((unsigned int)v95._Ptr | 1);
                    _S21._Ptr = v95._Ptr;
                    std::operator+<wchar_t>((std::wstring *)&v89[24], &prefix, v20);
                    DisplayNode::DisplayNode((DisplayNode *)v19, *(std::wstring *)&v89[24]);
                    v22 = v21;
                  }
                  else
                  {
                    v22 = 0;
                  }
                  panel.displayNode = (DisplayNode *)v22;
                  v123 = 29;
                  if ( ((int)v95._Ptr & 1) != 0 )
                  {
                    v95._Ptr = (Node **)((unsigned int)v95._Ptr & 0xFFFFFFFE);
                    if ( _Right.fileName._Mysize >= 8 )
                      operator delete(_Right.kid);
                  }
                  v23 = ResourceStore::getTexture(v93->car->game->graphics->resourceStore._Myptr, &_Right, &filename, 0);
                  v24 = v23->kid;
                  v25 = &v23->fileName;
                  *(_DWORD *)(v22 + 188) = v24;
                  LOBYTE(v123) = 33;
                  if ( (const std::wstring *)(v22 + 192) != v25 )
                    std::wstring::assign((std::wstring *)(v22 + 192), v25, 0, 0xFFFFFFFF);
                  LOBYTE(v123) = 29;
                  OnSetupAppCreated::~OnSetupAppCreated(&_Right);
                  *(_DWORD *)&v89[44] = 5;
                  v107.fileName._Mysize = 7;
                  *(_DWORD *)&v89[40] = L"DIGIT";
                  *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
                  LOWORD(v107.kid) = 0;
                  *(float *)(v22 + 276) = (float)(int)_S20._Ptr;
                  std::wstring::assign((std::wstring *)&v107, *(const wchar_t **)&v89[40], *(unsigned int *)&v89[44]);
                  LOBYTE(v123) = 34;
                  *(_DWORD *)(v22 + 280) = INIReader::getInt(&r, &section, (const std::wstring *)&v107);
                  LOBYTE(v123) = 29;
                  if ( v107.fileName._Mysize >= 8 )
                    operator delete(v107.kid);
                  *(_DWORD *)(v22 + 284) = v101;
                  *(_DWORD *)&v89[44] = 5;
                  *(_DWORD *)&v89[40] = L"WIDTH";
                  *(_DWORD *)(v22 + 272) = 30;
                  v107.fileName._Mysize = 7;
                  *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
                  LOWORD(v107.kid) = 0;
                  std::wstring::assign((std::wstring *)&v107, *(const wchar_t **)&v89[40], *(unsigned int *)&v89[44]);
                  LOBYTE(v123) = 35;
                  *(float *)(v22 + 244) = INIReader::getFloat(&r, &section, (const std::wstring *)&v107);
                  LOBYTE(v123) = 29;
                  if ( v107.fileName._Mysize >= 8 )
                    operator delete(v107.kid);
                  v107.fileName._Mysize = 7;
                  *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
                  LOWORD(v107.kid) = 0;
                  std::wstring::assign((std::wstring *)&v107, L"HEIGHT", 6u);
                  LOBYTE(v123) = 36;
                  *(float *)(v22 + 248) = INIReader::getFloat(&r, &section, (const std::wstring *)&v107);
                  LOBYTE(v123) = 29;
                  if ( v107.fileName._Mysize >= 8 )
                    operator delete(v107.kid);
                  v107.fileName._Mysize = 7;
                  *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
                  LOWORD(v107.kid) = 0;
                  std::wstring::assign((std::wstring *)&v107, L"COLOR", 5u);
                  LOBYTE(v123) = 37;
                  v26 = (const __m128i *)INIReader::getFloat4(&r, &v106, &section, (const std::wstring *)&v107);
                  LOBYTE(v123) = 29;
                  *(__m128i *)(v22 + 252) = _mm_loadu_si128(v26);
                  if ( v107.fileName._Mysize >= 8 )
                    operator delete(v107.kid);
                  v107.fileName._Mysize = 7;
                  *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
                  LOWORD(v107.kid) = 0;
                  std::wstring::assign((std::wstring *)&v107, L"INTENSITY", 9u);
                  LOBYTE(v123) = 38;
                  *(float *)&_S21._Ptr = INIReader::getFloat(&r, &section, (const std::wstring *)&v107);
                  LOBYTE(v123) = 29;
                  if ( v107.fileName._Mysize >= 8 )
                    operator delete(v107.kid);
                  v27 = *(float *)&_S21._Ptr * 0.0039215689;
                  *(_DWORD *)&v89[44] = 8;
                  *(_DWORD *)&v89[40] = L"POSITION";
                  v107.fileName._Mysize = 7;
                  *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
                  v28 = (float)(*(float *)&_S21._Ptr * 0.0039215689) * *(float *)(v22 + 252);
                  LOWORD(v107.kid) = 0;
                  *(float *)(v22 + 252) = v28;
                  *(float *)(v22 + 256) = v27 * *(float *)(v22 + 256);
                  *(float *)(v22 + 260) = v27 * *(float *)(v22 + 260);
                  *(float *)(v22 + 264) = *(float *)(v22 + 264) * 0.0039215689;
                  std::wstring::assign((std::wstring *)&v107, *(const wchar_t **)&v89[40], *(unsigned int *)&v89[44]);
                  LOBYTE(v123) = 39;
                  v29 = INIReader::getFloat3(&r, &v104, &section, (const std::wstring *)&v107);
                  LOBYTE(v123) = 29;
                  *(vec3f *)(v22 + 52) = *v29;
                  if ( v107.fileName._Mysize >= 8 )
                    operator delete(v107.kid);
                  (*(void (**)(int, unsigned int))(*(_DWORD *)v97 + 4))(v97, v22);
                  v30 = v2->_Mylast;
                  if ( &panel >= (DigitalPanelItem *)v30 || v2->_Myfirst > (SplineIndexBound *)&panel )
                  {
                    if ( v30 == v2->_Myend )
                      std::vector<DriverNameDisplayer::CarDistandeOrder>::_Reserve(v2, 1u);
                    v38 = v2->_Mylast;
                    if ( v38 )
                    {
                      v38->minIndex = v22;
                      v38->maxIndex = 1;
                    }
                    ++v2->_Mylast;
                  }
                  else
                  {
                    v31 = v2->_Myend;
                    v32 = ((char *)&panel - (char *)v2->_Myfirst) >> 3;
                    if ( v30 == v31 && !(v31 - v30) )
                    {
                      v33 = v30 - v2->_Myfirst;
                      if ( v33 == 0x1FFFFFFF )
                        std::_Xlength_error("vector<T> too long");
                      v34 = v31 - v2->_Myfirst;
                      _S21._Ptr = (Node **)(v33 + 1);
                      if ( 0x1FFFFFFF - (v34 >> 1) >= v34 )
                        v35 = (Node **)((v34 >> 1) + v34);
                      else
                        v35 = 0;
                      if ( v35 < _S21._Ptr )
                        v35 = _S21._Ptr;
                      std::vector<ReplayLap>::_Reallocate(v2, (unsigned int)v35);
                    }
                    v36 = v2->_Mylast;
                    v37 = v2->_Myfirst;
                    if ( v36 )
                    {
                      v36->minIndex = v37[v32].minIndex;
                      v36->maxIndex = v37[v32].maxIndex;
                    }
                    ++v2->_Mylast;
                  }
                }
                else
                {
                  v100 = &v89[24];
                  *(_DWORD *)&v89[44] = 7;
                  *(_DWORD *)&v89[40] = 0;
                  *(_WORD *)&v89[24] = 0;
                  std::wstring::assign((std::wstring *)&v89[24], L"\n", 1u);
                  LOBYTE(v123) = 40;
                  ld = (DigitalLed *)v89;
                  *(_DWORD *)&v89[20] = 7;
                  *(_DWORD *)&v89[16] = 0;
                  *(_WORD *)v89 = 0;
                  std::wstring::assign((std::wstring *)v89, L" NOT FOUND", 0xAu);
                  LOBYTE(v123) = 41;
                  *(float *)&_S21._Ptr = COERCE_FLOAT(&v88);
                  v88._Myres = 7;
                  v88._Mysize = 0;
                  v88._Bx._Buf[0] = 0;
                  std::wstring::assign(&v88, &filename, 0, 0xFFFFFFFF);
                  LOBYTE(v123) = 42;
                  v102 = &v87;
                  v87._Myres = 7;
                  v87._Mysize = 0;
                  v87._Bx._Buf[0] = 0;
                  std::wstring::assign(&v87, L"[ERROR]: TEXTURE_BASE ", 0x16u);
                  LOBYTE(v123) = 43;
                  v39 = Console::singleton();
                  LOBYTE(v123) = 42;
                  v40 = Console::operator<<(v39, v87);
                  LOBYTE(v123) = 41;
                  v41 = Console::operator<<(v40, v88);
                  LOBYTE(v123) = 40;
                  v42 = Console::operator<<(v41, *(std::wstring *)v89);
                  LOBYTE(v123) = 29;
                  Console::operator<<(v42, *(std::wstring *)&v89[24]);
                }
                LOBYTE(v123) = 16;
                if ( filename._Myres >= 8 )
                  operator delete(filename._Bx._Ptr);
                v8 = v103;
                v13 = (Node **)((char *)_S20._Ptr + 1);
                _S20._Ptr = v13;
              }
              while ( (int)v13 <= v103 );
              v12 = (Node **)_Val;
            }
            ++v10;
          }
          while ( v10 != v11 );
          v10 = ns._Myfirst;
        }
        LOBYTE(v123) = 15;
        if ( v10 )
        {
          std::_Container_base0::_Orphan_all(&ns);
          operator delete(ns._Myfirst);
          ns._Myfirst = 0;
          ns._Mylast = 0;
          ns._Myend = 0;
        }
        v6 = v96;
        v1 = v93;
      }
      if ( p._Myres >= 8 )
        operator delete(p._Bx._Ptr);
      p._Myres = 7;
      p._Mysize = 0;
      p._Bx._Buf[0] = 0;
      if ( prefix._Myres >= 8 )
        operator delete(prefix._Bx._Ptr);
      ++v6;
      LOBYTE(v123) = 4;
      v96 = v6;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    LOBYTE(v123) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    v43 = 0;
    v96 = 0;
    while ( 1 )
    {
      v44 = std::to_wstring(&filename, v43);
      LOBYTE(v123) = 44;
      std::operator+<wchar_t>(&key, L"PUSH2PASS_SERIES_", v44);
      LOBYTE(v123) = 46;
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
      filename._Myres = 7;
      filename._Bx._Buf[0] = 0;
      filename._Mysize = 0;
      if ( !INIReader::hasSection(&r, &key) )
        break;
      *(_DWORD *)&v89[44] = 6;
      v1->boostCount = 0;
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      std::wstring::assign(&v109, L"PREFIX", *(unsigned int *)&v89[44]);
      LOBYTE(v123) = 47;
      INIReader::getString(&r, (std::wstring *)&_Right, &key, &v109);
      LOBYTE(v123) = 49;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      v107.fileName._Mysize = 7;
      *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
      LOWORD(v107.kid) = 0;
      std::wstring::assign((std::wstring *)&v107, L"START", 5u);
      LOBYTE(v123) = 50;
      *(float *)&v103 = COERCE_FLOAT(INIReader::getInt(&r, &key, (const std::wstring *)&v107));
      LOBYTE(v123) = 49;
      if ( v107.fileName._Mysize >= 8 )
        operator delete(v107.kid);
      v107.fileName._Mysize = 7;
      *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
      LOWORD(v107.kid) = 0;
      std::wstring::assign((std::wstring *)&v107, L"END", 3u);
      LOBYTE(v123) = 51;
      v45 = (Node **)INIReader::getInt(&r, &key, (const std::wstring *)&v107);
      _S20._Ptr = v45;
      LOBYTE(v123) = 49;
      if ( v107.fileName._Mysize >= 8 )
        operator delete(v107.kid);
      v107.fileName._Mysize = 7;
      *(_DWORD *)&v107.fileName._Bx._Alias[12] = 0;
      LOWORD(v107.kid) = 0;
      std::wstring::assign((std::wstring *)&v107, L"BLINK_HZ", 8u);
      LOBYTE(v123) = 52;
      v46 = INIReader::getFloat(&r, &key, (const std::wstring *)&v107);
      v47 = v107.fileName._Mysize < 8;
      v1->P2PblinkFrequency = v46;
      LOBYTE(v123) = 49;
      if ( !v47 )
        operator delete(v107.kid);
      p._Myres = 7;
      p._Mysize = 0;
      p._Bx._Buf[0] = 0;
      std::wstring::assign(&p, L"PARENT", 6u);
      LOBYTE(v123) = 53;
      INIReader::getString(&r, &s, &key, &p);
      LOBYTE(v123) = 55;
      if ( p._Myres >= 8 )
        operator delete(p._Bx._Ptr);
      p._Myres = 7;
      p._Mysize = 0;
      p._Bx._Buf[0] = 0;
      if ( std::wstring::compare(&s, 0, s._Mysize, L"NULL", 4u) )
      {
        v104.x = 0.0;
        v104.y = 0.0;
        v104.z = 0.0;
        v48 = v1->car;
        LOBYTE(v123) = 56;
        v48->bodyTransform->findChildrenByName(v48->bodyTransform, &s, (std::vector<Node *> *)&v104);
        v49 = v104.x;
        v50 = v104.y;
        _Val = LODWORD(v104.x);
        for ( ld = (DigitalLed *)LODWORD(v104.y); LODWORD(v49) != LODWORD(v50); _Val = LODWORD(v49) )
        {
          v101 = *(int **)LODWORD(v49);
          v97 = v103;
          if ( v103 <= (int)v45 )
          {
            v51 = v93;
            v52 = v103;
            do
            {
              v53 = std::to_wstring(&v114, v52);
              LOBYTE(v123) = 57;
              p._Myres = 7;
              p._Mysize = 0;
              p._Bx._Buf[0] = 0;
              std::wstring::assign(&p, L"content/cars/", 0xDu);
              v54 = v51->car;
              LOBYTE(v123) = 58;
              v55 = std::operator+<wchar_t>(&a_name, &p, &v54->unixName);
              LOBYTE(v123) = 59;
              v56 = std::operator+<wchar_t>(&v113, v55, L"/texture/display_panel/");
              LOBYTE(v123) = 60;
              v57 = std::operator+<wchar_t>(&v115, v56, (const std::wstring *)&_Right);
              LOBYTE(v123) = 61;
              v58 = std::operator+<wchar_t>(&filename, v57, v53);
              LOBYTE(v123) = 62;
              std::operator+<wchar_t>(&prefix, v58, L".dds");
              if ( filename._Myres >= 8 )
                operator delete(filename._Bx._Ptr);
              filename._Myres = 7;
              filename._Mysize = 0;
              filename._Bx._Buf[0] = 0;
              if ( v115._Myres >= 8 )
                operator delete(v115._Bx._Ptr);
              v115._Myres = 7;
              v115._Mysize = 0;
              v115._Bx._Buf[0] = 0;
              if ( v113._Myres >= 8 )
                operator delete(v113._Bx._Ptr);
              v113._Myres = 7;
              v113._Mysize = 0;
              v113._Bx._Buf[0] = 0;
              if ( a_name._Myres >= 8 )
                operator delete(a_name._Bx._Ptr);
              a_name._Myres = 7;
              a_name._Mysize = 0;
              a_name._Bx._Buf[0] = 0;
              if ( p._Myres >= 8 )
                operator delete(p._Bx._Ptr);
              p._Myres = 7;
              p._Mysize = 0;
              p._Bx._Buf[0] = 0;
              LOBYTE(v123) = 69;
              if ( v114._Myres >= 8 )
                operator delete(v114._Bx._Ptr);
              v114._Myres = 7;
              v114._Bx._Buf[0] = 0;
              v114._Mysize = 0;
              if ( Path::fileExists((unsigned int)v53, &prefix, 0) )
              {
                ns._Mylast = (Node **)2;
                v59 = (DisplayNode *)operator new(292);
                v102 = (std::wstring *)v59;
                LOBYTE(v123) = 70;
                if ( v59 )
                {
                  v60 = std::to_wstring((std::wstring *)&v107, v52);
                  LOBYTE(v123) = 71;
                  v95._Ptr = (Node **)((unsigned int)v95._Ptr | 2);
                  _S21._Ptr = v95._Ptr;
                  std::operator+<wchar_t>((std::wstring *)&v89[24], (const std::wstring *)&_Right, v60);
                  DisplayNode::DisplayNode(v59, *(std::wstring *)&v89[24]);
                  v51 = v93;
                  v62 = v61;
                }
                else
                {
                  v62 = 0;
                }
                ns._Myfirst = (Node **)v62;
                v123 = 69;
                if ( ((int)v95._Ptr & 2) != 0 )
                {
                  v95._Ptr = (Node **)((unsigned int)v95._Ptr & 0xFFFFFFFD);
                  if ( v107.fileName._Mysize >= 8 )
                    operator delete(v107.kid);
                }
                v63 = ResourceStore::getTexture(v51->car->game->graphics->resourceStore._Myptr, &v107, &prefix, 0);
                v64 = v63->kid;
                v65 = &v63->fileName;
                *(_DWORD *)(v62 + 188) = v64;
                LOBYTE(v123) = 73;
                if ( (const std::wstring *)(v62 + 192) != v65 )
                  std::wstring::assign((std::wstring *)(v62 + 192), v65, 0, 0xFFFFFFFF);
                LOBYTE(v123) = 69;
                OnSetupAppCreated::~OnSetupAppCreated(&v107);
                *(_DWORD *)&v89[44] = L"DIGIT";
                *(float *)(v62 + 276) = (float)v52;
                std::wstring::wstring((std::wstring *)&v107, *(const wchar_t **)&v89[44]);
                LOBYTE(v123) = 74;
                *(_DWORD *)(v62 + 280) = INIReader::getInt(&r, &key, (const std::wstring *)&v107);
                LOBYTE(v123) = 69;
                if ( v107.fileName._Mysize >= 8 )
                  operator delete(v107.kid);
                *(_DWORD *)(v62 + 284) = &v51->boostCount;
                *(_DWORD *)&v89[44] = L"WIDTH";
                *(_DWORD *)(v62 + 272) = 30;
                std::wstring::wstring((std::wstring *)&v107, *(const wchar_t **)&v89[44]);
                LOBYTE(v123) = 75;
                *(float *)(v62 + 244) = INIReader::getFloat(&r, &key, (const std::wstring *)&v107);
                LOBYTE(v123) = 69;
                if ( v107.fileName._Mysize >= 8 )
                  operator delete(v107.kid);
                std::wstring::wstring((std::wstring *)&v107, L"HEIGHT");
                LOBYTE(v123) = 76;
                *(float *)(v62 + 248) = INIReader::getFloat(&r, &key, (const std::wstring *)&v107);
                LOBYTE(v123) = 69;
                if ( v107.fileName._Mysize >= 8 )
                {
                  *(_DWORD *)&v89[44] = v107.fileName._Mysize + 1;
                  *(_DWORD *)&v89[40] = v107.kid;
                  v66 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                                     (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&v107,
                                                     (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&v90);
                  std::allocator<wchar_t>::deallocate(v66, *(wchar_t **)&v89[40], *(unsigned int *)&v89[44]);
                }
                v107.fileName._Mysize = 7;
                std::wstring::_Eos((std::wstring *)&v107, 0);
                std::wstring::wstring((std::wstring *)&v107, L"COLOR");
                LOBYTE(v123) = 77;
                v67 = (const __m128i *)INIReader::getFloat4(&r, (vec4f *)&section, &key, (const std::wstring *)&v107);
                LOBYTE(v123) = 69;
                *(__m128i *)(v62 + 252) = _mm_loadu_si128(v67);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
                std::wstring::wstring((std::wstring *)&v107, L"INTENSITY");
                LOBYTE(v123) = 78;
                v68 = INIReader::getFloat(&r, &key, (const std::wstring *)&v107);
                LOBYTE(v123) = 69;
                *(float *)&v97 = v68;
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
                v69 = *(float *)&v97 * 0.0039215689;
                *(_DWORD *)&v89[44] = L"POSITION";
                *(float *)(v62 + 252) = (float)(*(float *)&v97 * 0.0039215689) * *(float *)(v62 + 252);
                *(float *)(v62 + 256) = v69 * *(float *)(v62 + 256);
                *(float *)(v62 + 260) = v69 * *(float *)(v62 + 260);
                *(float *)(v62 + 264) = *(float *)(v62 + 264) * 0.0039215689;
                std::wstring::wstring((std::wstring *)&v107, *(const wchar_t **)&v89[44]);
                LOBYTE(v123) = 79;
                v70 = INIReader::getFloat3(&r, (vec3f *)&v106, &key, (const std::wstring *)&v107);
                mat44f::setTranslation((mat44f *)(v62 + 4), v70);
                LOBYTE(v123) = 69;
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
                (*(void (**)(int *, int))(*v101 + 4))(v101, v62);
                std::vector<DRSWingSetting>::push_back((std::vector<PerformancePair> *)v2, (PerformancePair *)&ns);
              }
              else
              {
                v102 = (std::wstring *)&v89[24];
                std::wstring::wstring((std::wstring *)&v89[24], L"\n");
                LOBYTE(v123) = 80;
                v100 = v89;
                std::wstring::wstring((std::wstring *)v89, L" NOT FOUND");
                LOBYTE(v123) = 81;
                *(float *)&v97 = COERCE_FLOAT(&v88);
                std::wstring::wstring(&v88, &prefix);
                LOBYTE(v123) = 82;
                *(float *)&_S21._Ptr = COERCE_FLOAT(&v87);
                std::wstring::wstring(&v87, L"[ERROR]: TEXTURE_BASE ");
                LOBYTE(v123) = 83;
                v71 = Console::singleton();
                LOBYTE(v123) = 82;
                v72 = Console::operator<<(v71, v87);
                LOBYTE(v123) = 81;
                v73 = Console::operator<<(v72, v88);
                LOBYTE(v123) = 80;
                v74 = Console::operator<<(v73, *(std::wstring *)v89);
                LOBYTE(v123) = 69;
                Console::operator<<(v74, *(std::wstring *)&v89[24]);
              }
              LOBYTE(v123) = 56;
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&prefix);
              v45 = _S20._Ptr;
              ++v52;
            }
            while ( v52 <= (int)_S20._Ptr );
            v49 = *(float *)&_Val;
            v50 = *(float *)&ld;
          }
          LODWORD(v49) += 4;
        }
        std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>((std::vector<SplineIndexBound> *)&v104);
        v1 = v93;
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v43 = v96 + 1;
      LOBYTE(v123) = 4;
      ++v96;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    }
    LOBYTE(v123) = 4;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    v75 = 0;
    _Val = 0;
    v76 = std::to_wstring((std::wstring *)&_Right, 0);
    LOBYTE(v123) = 84;
    std::operator+<wchar_t>((std::wstring *)&v107, L"PUSH2PASS_LED_", v76);
    LOBYTE(v123) = 86;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
    if ( INIReader::hasSection(&r, (const std::wstring *)&v107) )
    {
      v77 = (std::vector<ICollisionObject *> *)&v1->leds;
      do
      {
        v78 = v1->car->bodyTransform;
        std::vector<SetupTab *>::begin(
          (std::vector<TyreCompoundDef> *)&v78->nodes,
          (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
        std::vector<Mesh *>::end(
          (std::vector<TyreCompoundDef> *)&v78->nodes,
          (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21);
        if ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
               (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
               (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) )
        {
          v79 = (int)v93;
          do
          {
            v80 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20);
            *(_DWORD *)&v89[44] = 100;
            v81 = v80->index;
            v82 = (DigitalLed *)operator new(100);
            v102 = (std::wstring *)v82;
            LOBYTE(v123) = 87;
            if ( v82 )
            {
              *(_DWORD *)&v89[44] = v81;
              *(_DWORD *)&v89[40] = 20;
              std::wstring::wstring((std::wstring *)&v89[16], (const std::wstring *)&v107);
              DigitalLed::DigitalLed(
                v82,
                *(CarAvatar **)(v79 + 92),
                &r,
                *(std::wstring *)&v89[16],
                *(DigitalLedType *)&v89[40],
                *(Node **)&v89[44]);
              v84 = v83;
            }
            else
            {
              v84 = 0;
            }
            LOBYTE(v123) = 86;
            ld = v84;
            if ( DigitalLed::hasTargetMesh(v84) )
            {
              std::vector<SpinnerData *>::push_back(v77, (ICollisionObject *const *)&ld);
            }
            else if ( v84 )
            {
              DigitalLed::`scalar deleting destructor'(v84, 1u);
            }
            std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator++(&_S20);
          }
          while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
                    (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S20,
                    (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S21) );
          v75 = _Val;
        }
        ++v75;
        LOBYTE(v123) = 4;
        _Val = v75;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
        v85 = std::to_wstring((std::wstring *)&_Right, v75);
        LOBYTE(v123) = 84;
        std::operator+<wchar_t>((std::wstring *)&v107, L"PUSH2PASS_LED_", v85);
        LOBYTE(v123) = 86;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        v86 = INIReader::hasSection(&r, (const std::wstring *)&v107);
        v1 = v93;
      }
      while ( v86 );
    }
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v107);
  }
  v123 = -1;
  INIReader::~INIReader(&r);
}
void DigitalPanels::update(DigitalPanels *this, float deltaT)
{
  int v3; // eax
  int v4; // eax
  CarAvatar *v5; // ecx
  float v6; // xmm2_4
  DigitalLed **v7; // esi
  int v8; // ebx
  unsigned int v9; // ebp

  if ( (((char *)this->items._Mylast - (char *)this->items._Myfirst) & 0xFFFFFFF8) == 0 )
    return;
  if ( this->lastPosition >= 0 )
  {
    v3 = RaceManager::getCurrentSessionType(this->car->sim->raceManager);
    if ( v3 > 0 )
    {
      if ( v3 <= 2 )
      {
        v4 = RaceManager::getCarLeaderboardPosition(this->car->sim->raceManager, this->car);
        goto LABEL_8;
      }
      if ( v3 == 3 )
      {
        v4 = RaceManager::getCarRealTimePosition(this->car->sim->raceManager, this->car) + 1;
LABEL_8:
        this->lastPosition = v4;
        goto LABEL_9;
      }
    }
  }
LABEL_9:
  if ( this->boostCount >= 0 || this->P2PblinkFrequency > 0.0 )
  {
    v5 = this->car;
    v6 = this->P2PblinkFrequency;
    this->boostCount = v5->physicsState.p2pActivations;
    if ( v6 > 0.0 && v5->physicsState.p2pStatus == 3 && (int)(v5->game->gameTime.now / (float)(1000.0 / v6)) % 2 )
      this->boostCount = -1;
  }
  v7 = this->leds._Myfirst;
  v8 = 0;
  v9 = (unsigned int)((char *)this->leds._Mylast - (char *)v7 + 3) >> 2;
  if ( v7 > this->leds._Mylast )
    v9 = 0;
  if ( v9 )
  {
    do
    {
      DigitalLed::update(*v7, deltaT);
      ++v8;
      ++v7;
    }
    while ( v8 != v9 );
  }
  if ( this->observeINI != 0.0 )
  {
    if ( FileChangeObserver::hasChanged(&this->observer) )
    {
      INIReader::clearCache();
      DigitalPanels::initPanels(this);
    }
  }
}
