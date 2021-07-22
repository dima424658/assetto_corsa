#include "digitalinstruments.h
void DigitalInstruments::DigitalInstruments(DigitalInstruments *this, CarAvatar *a_car)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  std::wstring v5; // [esp-1Ch] [ebp-70h] BYREF
  Game *v6; // [esp-4h] [ebp-58h]
  DigitalInstruments *v7; // [esp+10h] [ebp-44h]
  std::wstring v8; // [esp+14h] [ebp-40h] BYREF
  std::wstring result; // [esp+2Ch] [ebp-28h] BYREF
  int v10; // [esp+50h] [ebp-4h]

  v7 = this;
  v6 = a_car->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"DIGITAL_INSTRUMENTS", 0x13u);
  GameObject::GameObject(this, v5, v6);
  v10 = 0;
  v6 = (Game *)&a_car->unixName;
  this->__vftable = (DigitalInstruments_vtbl *)&DigitalInstruments::`vftable';
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", (const std::wstring *)v6);
  LOBYTE(v10) = 1;
  v4 = std::operator+<wchar_t>(&v8, v3, L"/data/digital_instruments.ini");
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
  DigitalInstruments::initInstruments(this);
}
void DigitalInstruments::~DigitalInstruments(DigitalInstruments *this)
{
  this->__vftable = (DigitalInstruments_vtbl *)&DigitalInstruments::`vftable';
  if ( this->leds._Myfirst )
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
DigitalInstruments *DigitalInstruments::`vector deleting destructor'(DigitalInstruments *this, unsigned int a2)
{
  DigitalInstruments::~DigitalInstruments(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DigitalInstruments::initInstruments(DigitalInstruments *this)
{
  DigitalInstruments *v1; // edi
  float v2; // ebx
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  CarAvatar *v5; // ecx
  char *v6; // esi
  std::vector<DigitalItem *> *v7; // ebp
  std::wostream *v8; // eax
  const std::wstring *v9; // eax
  char v10; // al
  DigitalItem *v11; // esi
  const std::wstring *v12; // eax
  int v13; // eax
  int v14; // esi
  DigitalItem **v15; // eax
  int v16; // esi
  DigitalItem **v17; // ecx
  _DWORD *v18; // eax
  int v19; // eax
  ICollisionObject *v20; // ebp
  char *v21; // esi
  std::wostream *v22; // eax
  const std::wstring *v23; // eax
  char v24; // al
  const std::wstring *v25; // eax
  const std::wstring *v26; // esi
  const std::wstring *v27; // edi
  vec3f *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // esi
  Material *v32; // ecx
  MaterialVar *v33; // eax
  float v34; // ecx
  Material *v35; // ecx
  MaterialVar *v36; // eax
  Material *v37; // ecx
  MaterialVar *v38; // eax
  Material *v39; // ecx
  MaterialVar *v40; // eax
  const std::wstring *v41; // eax
  Console *v42; // eax
  Console *v43; // eax
  Console *v44; // eax
  Console *v45; // eax
  const std::wstring *v46; // eax
  std::wstring *v47; // eax
  char *v48; // esi
  std::wostream *v49; // eax
  const std::wstring *v50; // eax
  char v51; // al
  ICollisionObject *v52; // esi
  ICollisionObject *v53; // eax
  char *v54; // esi
  std::wostream *v55; // eax
  const std::wstring *v56; // eax
  char v57; // al
  ICollisionObject *v58; // eax
  float v59; // eax
  float v60; // esi
  const std::wstring *v61; // eax
  const std::wstring *v62; // eax
  char *v63; // esi
  std::wostream *v64; // eax
  const std::wstring *v65; // eax
  char v66; // al
  const std::wstring *v67; // eax
  ICollisionObject *v68; // eax
  DigitalLed *v69; // esi
  ICollisionObject *v70; // eax
  float v71; // eax
  float v72; // esi
  const std::wstring *v73; // eax
  const std::wstring *v74; // eax
  char *v75; // esi
  std::wostream *v76; // eax
  const std::wstring *v77; // eax
  char v78; // al
  ICollisionObject *v79; // esi
  ICollisionObject *v80; // eax
  int i; // ebx
  std::wostream *v82; // eax
  const std::wstring *v83; // eax
  char v84; // al
  ICollisionObject *v85; // esi
  ICollisionObject *v86; // eax
  int j; // ebx
  std::wostream *v88; // eax
  const std::wstring *v89; // eax
  char v90; // al
  ICollisionObject *v91; // esi
  ICollisionObject *v92; // eax
  int k; // ebx
  std::wostream *v94; // eax
  const std::wstring *v95; // eax
  char v96; // al
  ICollisionObject *v97; // esi
  ICollisionObject *v98; // eax
  char *v99; // ebx
  std::wostream *v100; // eax
  const std::wstring *v101; // eax
  bool v102; // bl
  ICollisionObject *v103; // eax
  float v104; // eax
  float v105; // esi
  const std::wstring *v106; // eax
  Mesh *v107; // ebx
  ICollisionObject *v108; // eax
  Material *v109; // eax
  std::_Ref_count_base *v110; // ebx
  const std::wstring *v111; // eax
  const std::wstring *v112; // eax
  std::allocator<wchar_t> *v113; // eax
  const std::wstring *v114; // eax
  std::wstring *v115; // eax
  char *v116; // ebx
  std::wostream *v117; // eax
  const std::wstring *v118; // eax
  bool v119; // al
  bool v120; // bl
  ICollisionObject *v121; // esi
  ICollisionObject *v122; // eax
  char *v123; // ebx
  std::wostream *v124; // eax
  const std::wstring *v125; // eax
  bool v126; // al
  bool v127; // bl
  const std::wstring *v128; // eax
  const std::wstring *v129; // eax
  const std::wstring *v130; // eax
  const std::wstring *v131; // eax
  const std::wstring *v132; // eax
  const std::wstring *v133; // eax
  char v134; // bl
  const std::wstring *v135; // eax
  const std::wstring *v136; // eax
  char v137; // bl
  const std::wstring *v138; // eax
  std::wostream *v139; // eax
  ICollisionObject *v140; // esi
  ICollisionObject *v141; // eax
  bool v142; // cf
  int v143; // ebx
  std::wostream *v144; // eax
  const std::wstring *v145; // eax
  bool v146; // al
  bool v147; // bl
  const std::wstring *v148; // eax
  const std::wstring *v149; // eax
  const std::wstring *v150; // eax
  const std::wstring *v151; // eax
  const std::wstring *v152; // eax
  const std::wstring *v153; // eax
  const std::wstring *v154; // eax
  float v155; // xmm4_4
  std::wostream *v156; // eax
  ICollisionObject *v157; // esi
  ICollisionObject *v158; // eax
  int v159; // eax
  Material *v160; // xmm1_4
  float v161; // xmm0_4
  char *v162; // ebx
  std::wostream *v163; // eax
  const std::wstring *v164; // eax
  bool v165; // al
  bool v166; // bl
  const std::wstring *v167; // eax
  const std::wstring *v168; // eax
  const std::wstring *v169; // eax
  int v170; // ebx
  const std::wstring *v171; // eax
  float v172; // ebx
  float v173; // ebx
  const std::wstring *v174; // eax
  char v175; // al
  const std::wstring *v176; // eax
  const std::wstring *v177; // eax
  float v178; // ebx
  const std::wstring *v179; // eax
  int v180; // ebx
  float v181; // ebx
  const std::wstring *v182; // eax
  char v183; // al
  const std::wstring *v184; // eax
  const std::wstring *v185; // eax
  const std::wstring *v186; // eax
  int v187; // ebx
  std::wostream *v188; // eax
  Material *v189; // esi
  Material *v190; // eax
  DigitalLed **v191; // eax
  int v192; // ebx
  std::wostream *v193; // eax
  const std::wstring *v194; // eax
  bool v195; // al
  bool v196; // bl
  const std::wstring *v197; // eax
  const std::wstring *v198; // eax
  const std::wstring *v199; // eax
  const std::wstring *v200; // eax
  const std::wstring *v201; // eax
  std::wostream *v202; // eax
  ICollisionObject *v203; // esi
  ICollisionObject *v204; // eax
  DigitalLed **v205; // eax
  ICollisionObject *v206; // xmm1_4
  DigitalLed *v207; // eax
  float v208; // xmm0_4
  int v209; // esi
  int v210; // ebx
  std::wostream *v211; // eax
  const std::wstring *v212; // eax
  bool v213; // al
  bool v214; // bl
  const std::wstring *v215; // eax
  const std::wstring *v216; // eax
  const std::wstring *v217; // eax
  const std::wstring *v218; // eax
  char v219; // bl
  const std::wstring *v220; // eax
  float v221; // esi
  const std::wstring *v222; // eax
  float v223; // esi
  const std::wstring *v224; // eax
  char v225; // bl
  const std::wstring *v226; // eax
  const std::wstring *v227; // eax
  ICollisionObject *v228; // xmm0_4
  float v229; // xmm2_4
  std::wostream *v230; // eax
  ICollisionObject *v231; // ebx
  ICollisionObject *v232; // eax
  DigitalLed **v233; // eax
  ICollisionObject *v234; // xmm1_4
  DigitalLed *v235; // eax
  float v236; // xmm0_4
  int v237; // ebx
  std::wostream *v238; // eax
  const std::wstring *v239; // eax
  bool v240; // al
  bool v241; // bl
  const std::wstring *v242; // eax
  const std::wstring *v243; // eax
  const std::wstring *v244; // eax
  const std::wstring *v245; // eax
  const std::wstring *v246; // eax
  int v247; // ebx
  std::wostream *v248; // eax
  ICollisionObject *v249; // esi
  ICollisionObject *v250; // eax
  DigitalLed **v251; // eax
  const std::wstring *v252; // edi
  DigitalLed **v253; // esi
  int v254; // eax
  int v255; // ebx
  std::wostream *v256; // eax
  const std::wstring *v257; // eax
  bool v258; // al
  bool v259; // bl
  const std::wstring *v260; // eax
  const std::wstring *v261; // eax
  const std::wstring *v262; // eax
  const std::wstring *v263; // eax
  bool v264; // bl
  const std::wstring *v265; // eax
  double v266; // st7
  const std::wstring *v267; // eax
  std::wostream *v268; // eax
  ICollisionObject *v269; // esi
  ICollisionObject *v270; // eax
  DigitalLed **v271; // eax
  ICollisionObject *v272; // xmm1_4
  DigitalLed *v273; // eax
  float v274; // xmm0_4
  int v275; // ebx
  std::wostream *v276; // eax
  const std::wstring *v277; // eax
  bool v278; // al
  bool v279; // bl
  const std::wstring *v280; // eax
  const std::wstring *v281; // eax
  const std::wstring *v282; // eax
  const std::wstring *v283; // eax
  int v284; // ebx
  std::wostream *v285; // eax
  ICollisionObject *v286; // esi
  ICollisionObject *v287; // eax
  DigitalLed **v288; // eax
  DigitalLed *v289; // eax
  int v290; // ebx
  std::wostream *v291; // eax
  const std::wstring *v292; // eax
  bool v293; // al
  bool v294; // bl
  const std::wstring *v295; // eax
  const std::wstring *v296; // eax
  const std::wstring *v297; // eax
  const std::wstring *v298; // eax
  int v299; // ebx
  std::wostream *v300; // eax
  ICollisionObject *v301; // esi
  ICollisionObject *v302; // eax
  DigitalLed **v303; // eax
  DigitalLed *v304; // eax
  int v305; // ebx
  std::wostream *v306; // eax
  const std::wstring *v307; // eax
  bool v308; // al
  bool v309; // bl
  const std::wstring *v310; // eax
  const std::wstring *v311; // eax
  const std::wstring *v312; // eax
  const std::wstring *v313; // eax
  int v314; // ebx
  std::wostream *v315; // eax
  ICollisionObject *v316; // esi
  ICollisionObject *v317; // eax
  const std::wstring *v318; // esi
  DigitalLed **v319; // edi
  DigitalLed **v320; // eax
  DigitalLed *v321; // eax
  int v322; // ebx
  std::wostream *v323; // eax
  const std::wstring *v324; // eax
  bool v325; // al
  bool v326; // bl
  const std::wstring *v327; // eax
  const std::wstring *v328; // eax
  const std::wstring *v329; // eax
  const std::wstring *v330; // eax
  bool v331; // bh
  const std::wstring *v332; // eax
  char v333; // bl
  const std::wstring *v334; // eax
  std::wostream *v335; // eax
  ICollisionObject *v336; // esi
  ICollisionObject *v337; // eax
  DigitalLed **v338; // eax
  ICollisionObject *v339; // xmm1_4
  DigitalLed *v340; // eax
  float v341; // xmm0_4
  TyreCompoundDef *v342; // eax
  DigitalInstruments *v343; // ebx
  unsigned int v344; // edi
  vec3f *v345; // esi
  vec3f *v346; // esi
  TyreCompoundDef *v347; // eax
  unsigned int v348; // esi
  std::shared_ptr<Material> *v349; // eax
  Game *v350; // ecx
  vec3f *v351; // eax
  int v352; // ecx
  float v353; // xmm0_4
  int v354; // ecx
  const __m128i *v355; // eax
  const __m128i *v356; // eax
  __m128i v357; // xmm0
  float *v358; // eax
  Game *v359; // ecx
  std::shared_ptr<Material> *v360; // eax
  std::shared_ptr<Material> *v361; // eax
  int v362; // esi
  int v363; // ecx
  const __m128i *v364; // eax
  std::wstring v365; // [esp+38h] [ebp-13E4h] BYREF
  std::wstring v366; // [esp+50h] [ebp-13CCh] BYREF
  _BYTE valueSwitch[48]; // [esp+68h] [ebp-13B4h] BYREF
  int v368; // [esp+C4h] [ebp-1358h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > v369; // [esp+C8h] [ebp-1354h] BYREF
  ICollisionObject *_Val; // [esp+CCh] [ebp-1350h] BYREF
  ICollisionObject *v371; // [esp+D0h] [ebp-134Ch] BYREF
  float v372; // [esp+D4h] [ebp-1348h]
  float v373; // [esp+D8h] [ebp-1344h]
  float v374; // [esp+DCh] [ebp-1340h]
  float v375; // [esp+E0h] [ebp-133Ch]
  std::shared_ptr<Material> v376; // [esp+E4h] [ebp-1338h] BYREF
  bool excluded[8]; // [esp+ECh] [ebp-1330h]
  float mx; // [esp+F4h] [ebp-1328h]
  unsigned int v379; // [esp+F8h] [ebp-1324h]
  DigitalInstruments *v380; // [esp+FCh] [ebp-1320h]
  int v381; // [esp+100h] [ebp-131Ch] BYREF
  vec3f c; // [esp+104h] [ebp-1318h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v383; // [esp+110h] [ebp-130Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v384; // [esp+1C0h] [ebp-125Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v385; // [esp+270h] [ebp-11ACh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v386; // [esp+320h] [ebp-10FCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v387; // [esp+3D0h] [ebp-104Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v388; // [esp+480h] [ebp-F9Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v389; // [esp+530h] [ebp-EECh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v390; // [esp+5E0h] [ebp-E3Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v391; // [esp+690h] [ebp-D8Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v392; // [esp+740h] [ebp-CDCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v393; // [esp+7F0h] [ebp-C2Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v394; // [esp+8A0h] [ebp-B7Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v395; // [esp+950h] [ebp-ACCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v396; // [esp+A00h] [ebp-A1Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v397; // [esp+AB0h] [ebp-96Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v398; // [esp+B60h] [ebp-8BCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v399; // [esp+C10h] [ebp-80Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v400; // [esp+CC0h] [ebp-75Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v401; // [esp+D70h] [ebp-6ACh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v402; // [esp+E20h] [ebp-5FCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v403; // [esp+ED0h] [ebp-54Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v404; // [esp+F80h] [ebp-49Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v405; // [esp+1030h] [ebp-3ECh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v406; // [esp+10E0h] [ebp-33Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v407; // [esp+1190h] [ebp-28Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v408; // [esp+1240h] [ebp-1DCh] BYREF
  std::wstring vname; // [esp+12F0h] [ebp-12Ch] BYREF
  std::wstring key; // [esp+1308h] [ebp-114h] BYREF
  std::wstring v411; // [esp+1320h] [ebp-FCh] BYREF
  std::wstring _Right; // [esp+1338h] [ebp-E4h] BYREF
  INIReader ini; // [esp+1350h] [ebp-CCh] BYREF
  std::wstring _Str; // [esp+1394h] [ebp-88h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v415; // [esp+13ACh] [ebp-70h] BYREF
  std::wstring s; // [esp+13DCh] [ebp-40h] BYREF
  std::wstring result; // [esp+13F4h] [ebp-28h] BYREF
  int v418; // [esp+1418h] [ebp-4h]

  v1 = this;
  v380 = this;
  v2 = 0.0;
  v374 = 0.0;
  _printf("DigitalInstruments::initInstruments()\n");
  *(_DWORD *)&valueSwitch[40] = &v368;
  std::_For_each<DigitalItem * *,_lambda_3b876c65a175e7caf594000a85a6b604_>(v1->items._Myfirst, v1->items._Mylast);
  std::_Container_base0::_Orphan_all(&v1->items);
  v1->items._Mylast = v1->items._Myfirst;
  *(_DWORD *)&valueSwitch[44] = &v368;
  *(_DWORD *)&valueSwitch[40] = v1->leds._Mylast;
  _Val = (ICollisionObject *)&v1->leds;
  std::_For_each<DigitalLed * *,_lambda_a246c9d126492f70adaa09c76fae6a41_>(
    v1->leds._Myfirst,
    *(DigitalLed ***)&valueSwitch[40]);
  std::_Container_base0::_Orphan_all(&v1->leds);
  v1->leds._Mylast = v1->leds._Myfirst;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &v1->car->unixName);
  v418 = 0;
  v4 = std::operator+<wchar_t>(&s, v3, L"/data/digital_instruments.ini");
  v5 = v1->car;
  LOBYTE(v418) = 1;
  CarAvatar::openINI(v5, &ini, v4);
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  LOBYTE(v418) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    v6 = 0;
    v7 = &v1->items;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      *(_DWORD *)v383.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v383.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v383.gap68);
      LOBYTE(v418) = 5;
      LODWORD(v2) |= 0x2000u;
      v374 = v2;
      std::wiostream::basic_iostream<wchar_t>(&v383, &v383.gap10[8], 0);
      v418 = 6;
      *(_DWORD *)&v383.gap0[*(_DWORD *)(*(_DWORD *)v383.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&c.z + *(_DWORD *)(*(_DWORD *)v383.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v383.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v383.gap10[8]);
      *(_DWORD *)&v383.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v383.gap10[64] = 0;
      *(_DWORD *)&v383.gap10[68] = 0;
      LOBYTE(v418) = 8;
      v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v383.gap10, "ITEM_");
      std::wostream::operator<<(v8, v6);
      v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v383, &key);
      LOBYTE(v418) = 9;
      v10 = INIReader::hasSection(&ini, v9);
      LOBYTE(v368) = v10;
      LOBYTE(v418) = 8;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v10 = v368;
      }
      if ( !v10 )
        break;
      *(float *)&v11 = COERCE_FLOAT(operator new(168));
      v372 = *(float *)&v11;
      LOBYTE(v418) = 10;
      if ( *(float *)&v11 == 0.0 )
      {
        v14 = 0;
      }
      else
      {
        v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v383, &key);
        *(_DWORD *)&valueSwitch[44] = &v1->items;
        *(_DWORD *)&valueSwitch[40] = v12;
        LOBYTE(v418) = 11;
        *(_DWORD *)&valueSwitch[36] = &ini;
        *(_DWORD *)&valueSwitch[32] = v1->car;
        LODWORD(v2) |= 1u;
        v374 = v2;
        DigitalItem::DigitalItem(v11, *(CarAvatar **)&valueSwitch[32], &ini, v12, &v1->items);
        v14 = v13;
      }
      v15 = v1->items._Mylast;
      v418 = 12;
      v381 = v14;
      if ( &v381 >= (int *)v15 || v7->_Myfirst > (DigitalItem **)&v381 )
      {
        if ( v15 == v1->items._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v1->items, 1u);
        v18 = v1->items._Mylast;
        if ( v18 )
          *v18 = v14;
      }
      else
      {
        v16 = ((char *)&v381 - (char *)v7->_Myfirst) >> 2;
        if ( v15 == v1->items._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v1->items, 1u);
        v17 = v1->items._Mylast;
        if ( v17 )
          *v17 = v7->_Myfirst[v16];
      }
      ++v1->items._Mylast;
      v418 = 8;
      if ( (LOBYTE(v2) & 1) != 0 )
      {
        LODWORD(v2) &= 0xFFFFFFFE;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
      }
      v6 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      *(_DWORD *)&v383.gap0[*(_DWORD *)(*(_DWORD *)v383.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&c.z + *(_DWORD *)(*(_DWORD *)v383.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v383.gap0 + 4) - 104;
      *(_DWORD *)&v383.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v383.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v383.gap10[8]) )
          std::wstreambuf::epptr(&v383.gap10[8]);
        else
          std::wstreambuf::egptr(&v383.gap10[8]);
        std::wstreambuf::eback(&v383.gap10[8]);
        v19 = std::wstreambuf::eback(&v383.gap10[8]);
        operator delete(v19);
      }
      std::wstreambuf::setg(&v383.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v383.gap10[8], 0, 0);
      *(_DWORD *)&v383.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v383.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v383.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v383.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v383.gap68);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v383);
    v20 = _Val;
    v21 = 0;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      *(_DWORD *)v384.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v384.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v384.gap68);
      LOBYTE(v418) = 13;
      LODWORD(v2) |= 0x4000u;
      v374 = v2;
      std::wiostream::basic_iostream<wchar_t>(&v384, &v384.gap10[8], 0);
      v418 = 14;
      *(_DWORD *)&v384.gap0[*(_DWORD *)(*(_DWORD *)v384.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v383.gap68[*(_DWORD *)(*(_DWORD *)v384.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v384.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v384.gap10[8]);
      *(_DWORD *)&v384.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v384.gap10[64] = 0;
      *(_DWORD *)&v384.gap10[68] = 0;
      *(_DWORD *)&valueSwitch[44] = v21;
      LOBYTE(v418) = 16;
      v22 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v384.gap10, "DISPLAY_");
      std::wostream::operator<<(v22, *(_DWORD *)&valueSwitch[44]);
      v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v384, &key);
      LOBYTE(v418) = 17;
      v24 = INIReader::hasSection(&ini, v23);
      LOBYTE(v368) = v24;
      LOBYTE(v418) = 16;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v24 = v368;
      }
      if ( !v24 )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"NAME", 4u);
      *(_DWORD *)&valueSwitch[44] = 1;
      LOBYTE(v418) = 18;
      v25 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v384, &_Str);
      LOBYTE(v418) = 19;
      INIReader::getString(&ini, (std::wstring *)&valueSwitch[20], v25, &key);
      v372 = COERCE_FLOAT(Node::getNodeChild<Mesh>(v1->car->bodyTransform, *(std::wstring *)&valueSwitch[20], valueSwitch[44]));
      if ( _Str._Myres >= 8 )
        operator delete(_Str._Bx._Ptr);
      _Str._Myres = 7;
      _Str._Mysize = 0;
      _Str._Bx._Buf[0] = 0;
      LOBYTE(v418) = 16;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      std::wstring::assign(&_Right, L"INTENSITY", 9u);
      LOBYTE(v418) = 20;
      vname._Myres = 7;
      vname._Mysize = 0;
      vname._Bx._Buf[0] = 0;
      std::wstring::assign(&vname, L"EMISSIVE", 8u);
      LOBYTE(v418) = 21;
      v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v384, &v415.name);
      LOBYTE(v418) = 22;
      v27 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v384, &v411);
      LOBYTE(v418) = 23;
      *(float *)&_Val = INIReader::getFloat(&ini, v26, &_Right);
      v28 = INIReader::getFloat3(&ini, (vec3f *)&v415.score, v27, &vname);
      v29 = v28->y * *(float *)&_Val;
      v30 = v28->z * *(float *)&_Val;
      c.x = *(float *)&_Val * v28->x;
      c.y = v29;
      c.z = v30;
      if ( v411._Myres >= 8 )
        operator delete(v411._Bx._Ptr);
      v411._Myres = 7;
      v411._Mysize = 0;
      v411._Bx._Buf[0] = 0;
      if ( v415.name._Myres >= 8 )
        operator delete(v415.name._Bx._Ptr);
      v415.name._Myres = 7;
      v415.name._Mysize = 0;
      v415.name._Bx._Buf[0] = 0;
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      vname._Myres = 7;
      vname._Mysize = 0;
      vname._Bx._Buf[0] = 0;
      LOBYTE(v418) = 16;
      if ( _Right._Myres >= 8 )
        operator delete(_Right._Bx._Ptr);
      v31 = LODWORD(v372);
      if ( v372 == 0.0 )
      {
        std::wstring::wstring(&vname, L"NAME");
        LOBYTE(v418) = 28;
        *(float *)&_Val = COERCE_FLOAT(&valueSwitch[24]);
        std::wstring::wstring((std::wstring *)&valueSwitch[24], L"\n");
        LOBYTE(v418) = 29;
        v372 = COERCE_FLOAT(valueSwitch);
        std::wstring::wstring((std::wstring *)valueSwitch, L"NOT FOUND");
        LOBYTE(v418) = 30;
        v41 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v384, &key);
        LOBYTE(v418) = 31;
        *(float *)&v371 = COERCE_FLOAT(&v366);
        INIReader::getString(&ini, &v366, v41, &vname);
        LOBYTE(v418) = 32;
        v376._Ptr = (Material *)&v365;
        std::wstring::wstring(&v365, L"[ERROR]: DISPLAY MESH ");
        LOBYTE(v418) = 33;
        v42 = Console::singleton();
        LOBYTE(v418) = 32;
        v43 = Console::operator<<(v42, v365);
        LOBYTE(v418) = 31;
        v44 = Console::operator<<(v43, v366);
        LOBYTE(v418) = 34;
        v45 = Console::operator<<(v44, *(std::wstring *)valueSwitch);
        LOBYTE(v418) = 35;
        Console::operator<<(v45, *(std::wstring *)&valueSwitch[24]);
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        LOBYTE(v418) = 16;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        if ( INIReader::crashAtError )
        {
          std::wstring::wstring(&_Right, L"NAME");
          LOBYTE(v418) = 36;
          v46 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v384, &vname);
          LOBYTE(v418) = 37;
          v47 = INIReader::getString(&ini, &key, v46, &_Right);
          if ( v47->_Myres >= 8 )
            v47 = (std::wstring *)v47->_Bx._Ptr;
          _printf("[ERROR]: DISPLAY MESH %S\n", v47->_Bx._Buf);
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          if ( vname._Myres >= 8 )
            operator delete(vname._Bx._Ptr);
          vname._Myres = 7;
          vname._Mysize = 0;
          vname._Bx._Buf[0] = 0;
          LOBYTE(v418) = 16;
          if ( _Right._Myres >= 8 )
            operator delete(_Right._Bx._Ptr);
          ksGenerateCrash();
        }
      }
      else
      {
        std::wstring::wstring(&vname, L"ksEmissive");
        v32 = *(Material **)(v31 + 248);
        LOBYTE(v418) = 24;
        v33 = Material::getVar(v32, &vname);
        v34 = c.z;
        *(_QWORD *)&v33->fValue3.x = *(_QWORD *)&c.x;
        v33->fValue3.z = v34;
        MaterialVar::set(v33);
        LOBYTE(v418) = 16;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        std::wstring::wstring(&vname, L"ksDiffuse");
        v35 = *(Material **)(v31 + 248);
        LOBYTE(v418) = 25;
        v36 = Material::getVar(v35, &vname);
        v36->fValue = 0.0;
        MaterialVar::set(v36);
        LOBYTE(v418) = 16;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        std::wstring::wstring(&vname, L"ksAmbient");
        v37 = *(Material **)(v31 + 248);
        LOBYTE(v418) = 26;
        v38 = Material::getVar(v37, &vname);
        v38->fValue = 0.0;
        MaterialVar::set(v38);
        LOBYTE(v418) = 16;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        std::wstring::wstring(&vname, L"ksSpecular");
        v39 = *(Material **)(v31 + 248);
        LOBYTE(v418) = 27;
        v40 = Material::getVar(v39, &vname);
        v40->fValue = 0.0;
        MaterialVar::set(v40);
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
      }
      v21 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      *(_DWORD *)&v384.gap0[*(_DWORD *)(*(_DWORD *)v384.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v383.gap68[*(_DWORD *)(*(_DWORD *)v384.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v384.gap0 + 4) - 104;
      *(_DWORD *)&v384.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v384.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v384.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v384.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v384.gap68);
      v1 = v380;
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v384);
    v48 = 0;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      *(_DWORD *)v389.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v389.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v389.gap68);
      LOBYTE(v418) = 38;
      LODWORD(v2) |= 0x8000u;
      v374 = v2;
      std::wiostream::basic_iostream<wchar_t>(&v389, &v389.gap10[8], 0);
      v418 = 39;
      *(_DWORD *)&v389.gap0[*(_DWORD *)(*(_DWORD *)v389.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v388.gap68[*(_DWORD *)(*(_DWORD *)v389.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v389.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v389.gap10[8]);
      *(_DWORD *)&v389.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v389.gap10[64] = 0;
      *(_DWORD *)&v389.gap10[68] = 0;
      *(_DWORD *)&valueSwitch[44] = v48;
      LOBYTE(v418) = 41;
      v49 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v389.gap10, "LED_");
      std::wostream::operator<<(v49, *(_DWORD *)&valueSwitch[44]);
      v50 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v389, &key);
      LOBYTE(v418) = 42;
      v51 = INIReader::hasSection(&ini, v50);
      LOBYTE(v368) = v51;
      LOBYTE(v418) = 41;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v51 = v368;
      }
      if ( !v51 )
        break;
      *(float *)&v52 = COERCE_FLOAT(operator new(100));
      _Val = v52;
      LOBYTE(v418) = 43;
      if ( *(float *)&v52 == 0.0 )
      {
        *(float *)&v53 = 0.0;
      }
      else
      {
        *(_DWORD *)&valueSwitch[44] = 0;
        *(_DWORD *)&valueSwitch[40] = 0;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v389,
          (std::wstring *)&valueSwitch[16]);
        DigitalLed::DigitalLed(
          (DigitalLed *)v52,
          v1->car,
          &ini,
          *(std::wstring *)&valueSwitch[16],
          *(DigitalLedType *)&valueSwitch[40],
          *(Node **)&valueSwitch[44]);
      }
      _Val = v53;
      LOBYTE(v418) = 41;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      v48 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v389);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v389);
    v54 = 0;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      *(_DWORD *)v387.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v387.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v387.gap68);
      LOBYTE(v418) = 44;
      LODWORD(v2) |= 0x10000u;
      v374 = v2;
      std::wiostream::basic_iostream<wchar_t>(&v387, &v387.gap10[8], 0);
      v418 = 45;
      *(_DWORD *)&v387.gap0[*(_DWORD *)(*(_DWORD *)v387.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v386.gap68[*(_DWORD *)(*(_DWORD *)v387.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v387.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v387.gap10[8]);
      *(_DWORD *)&v387.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v387.gap10[64] = 0;
      *(_DWORD *)&v387.gap10[68] = 0;
      *(_DWORD *)&valueSwitch[44] = v54;
      LOBYTE(v418) = 47;
      v55 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v387.gap10, "FUEL_");
      std::wostream::operator<<(v55, *(_DWORD *)&valueSwitch[44]);
      v56 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v387, &key);
      LOBYTE(v418) = 48;
      v57 = INIReader::hasSection(&ini, v56);
      LOBYTE(v368) = v57;
      LOBYTE(v418) = 47;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v57 = v368;
      }
      if ( !v57 )
        break;
      *(float *)&v58 = COERCE_FLOAT(operator new(100));
      _Val = v58;
      LOBYTE(v418) = 49;
      if ( *(float *)&v58 == 0.0 )
      {
        v60 = 0.0;
      }
      else
      {
        DigitalLed::DigitalLed((DigitalLed *)v58, v1->car);
        v60 = v59;
      }
      *(_DWORD *)&valueSwitch[44] = L"OBJECT_NAME";
      LOBYTE(v418) = 47;
      *(float *)&_Val = v60;
      *(_DWORD *)LODWORD(v60) = 2;
      std::wstring::wstring(&vname, *(const wchar_t **)&valueSwitch[44]);
      *(_DWORD *)&valueSwitch[44] = 1;
      LOBYTE(v418) = 50;
      v61 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v387, &key);
      LOBYTE(v418) = 51;
      INIReader::getString(&ini, (std::wstring *)&valueSwitch[20], v61, &vname);
      *(_DWORD *)(LODWORD(v60) + 96) = Node::getNodeChild<Mesh>(
                                         v1->car->bodyTransform,
                                         *(std::wstring *)&valueSwitch[20],
                                         valueSwitch[44]);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v418) = 47;
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      std::wstring::wstring(&vname, L"FUEL_SWITCH");
      LOBYTE(v418) = 52;
      v62 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v387, &key);
      LOBYTE(v418) = 53;
      *(float *)(LODWORD(v60) + 4) = (float)INIReader::getInt(&ini, v62, &vname);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v418) = 47;
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      v54 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v387);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v387);
    v63 = 0;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      *(_DWORD *)v385.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v385.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v385.gap68);
      LOBYTE(v418) = 54;
      LODWORD(v2) |= 0x20000u;
      v374 = v2;
      std::wiostream::basic_iostream<wchar_t>(&v385, &v385.gap10[8], 0);
      v418 = 55;
      *(_DWORD *)&v385.gap0[*(_DWORD *)(*(_DWORD *)v385.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v384.gap68[*(_DWORD *)(*(_DWORD *)v385.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v385.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v385.gap10[8]);
      *(_DWORD *)&v385.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v385.gap10[64] = 0;
      *(_DWORD *)&v385.gap10[68] = 0;
      *(_DWORD *)&valueSwitch[44] = v63;
      LOBYTE(v418) = 57;
      v64 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v385.gap10, "FUEL_WARNING_");
      std::wostream::operator<<(v64, *(_DWORD *)&valueSwitch[44]);
      v65 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v385, &key);
      LOBYTE(v418) = 58;
      v66 = INIReader::hasSection(&ini, v65);
      LOBYTE(v368) = v66;
      LOBYTE(v418) = 57;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v66 = v368;
      }
      if ( !v66 )
        break;
      std::wstring::wstring(&vname, L"EMISSIVE");
      LOBYTE(v418) = 59;
      v67 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v385, &key);
      LOBYTE(v418) = 60;
      LOBYTE(v368) = INIReader::hasKey(&ini, v67, &vname);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v418) = 57;
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      *(float *)&v68 = COERCE_FLOAT(operator new(100));
      if ( (_BYTE)v368 )
      {
        v69 = (DigitalLed *)v68;
        _Val = v68;
        LOBYTE(v418) = 61;
        if ( *(float *)&v68 == 0.0 )
        {
          *(float *)&v70 = 0.0;
        }
        else
        {
          *(_DWORD *)&valueSwitch[44] = 0;
          *(_DWORD *)&valueSwitch[40] = 3;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            &v385,
            (std::wstring *)&valueSwitch[16]);
          DigitalLed::DigitalLed(
            v69,
            v1->car,
            &ini,
            *(std::wstring *)&valueSwitch[16],
            *(DigitalLedType *)&valueSwitch[40],
            *(Node **)&valueSwitch[44]);
        }
        _Val = v70;
        LOBYTE(v418) = 57;
        std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      }
      else
      {
        _Val = v68;
        LOBYTE(v418) = 62;
        if ( *(float *)&v68 == 0.0 )
        {
          v72 = 0.0;
        }
        else
        {
          DigitalLed::DigitalLed((DigitalLed *)v68, v1->car);
          v72 = v71;
        }
        *(_DWORD *)&valueSwitch[44] = L"OBJECT_NAME";
        LOBYTE(v418) = 57;
        *(float *)&_Val = v72;
        *(_DWORD *)LODWORD(v72) = 3;
        std::wstring::wstring(&vname, *(const wchar_t **)&valueSwitch[44]);
        *(_DWORD *)&valueSwitch[44] = 1;
        LOBYTE(v418) = 63;
        v73 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v385, &key);
        LOBYTE(v418) = 64;
        INIReader::getString(&ini, (std::wstring *)&valueSwitch[20], v73, &vname);
        *(_DWORD *)(LODWORD(v72) + 96) = Node::getNodeChild<Mesh>(
                                           v1->car->bodyTransform,
                                           *(std::wstring *)&valueSwitch[20],
                                           valueSwitch[44]);
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        LOBYTE(v418) = 57;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        std::wstring::wstring(&vname, L"FUEL_SWITCH");
        LOBYTE(v418) = 65;
        v74 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v385, &key);
        LOBYTE(v418) = 66;
        *(float *)(LODWORD(v72) + 4) = (float)INIReader::getInt(&ini, v74, &vname);
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        LOBYTE(v418) = 57;
        if ( vname._Myres >= 8 )
          operator delete(vname._Bx._Ptr);
        std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      }
      v63 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v385);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v385);
    v75 = 0;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      *(_DWORD *)v388.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v388.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v388.gap68);
      LOBYTE(v418) = 67;
      LODWORD(v2) |= 0x40000u;
      v374 = v2;
      std::wiostream::basic_iostream<wchar_t>(&v388, &v388.gap10[8], 0);
      v418 = 68;
      *(_DWORD *)&v388.gap0[*(_DWORD *)(*(_DWORD *)v388.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v387.gap68[*(_DWORD *)(*(_DWORD *)v388.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v388.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v388.gap10[8]);
      *(_DWORD *)&v388.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v388.gap10[64] = 0;
      *(_DWORD *)&v388.gap10[68] = 0;
      *(_DWORD *)&valueSwitch[44] = v75;
      LOBYTE(v418) = 70;
      v76 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v388.gap10, "TYRE_LOCK_SLIP_");
      std::wostream::operator<<(v76, *(_DWORD *)&valueSwitch[44]);
      v77 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v388, &key);
      LOBYTE(v418) = 71;
      v78 = INIReader::hasSection(&ini, v77);
      LOBYTE(v368) = v78;
      LOBYTE(v418) = 70;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v78 = v368;
      }
      if ( !v78 )
        break;
      *(float *)&v79 = COERCE_FLOAT(operator new(100));
      _Val = v79;
      LOBYTE(v418) = 72;
      if ( *(float *)&v79 == 0.0 )
      {
        *(float *)&v80 = 0.0;
      }
      else
      {
        *(_DWORD *)&valueSwitch[44] = 0;
        *(_DWORD *)&valueSwitch[40] = 19;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v388,
          (std::wstring *)&valueSwitch[16]);
        DigitalLed::DigitalLed(
          (DigitalLed *)v79,
          v1->car,
          &ini,
          *(std::wstring *)&valueSwitch[16],
          *(DigitalLedType *)&valueSwitch[40],
          *(Node **)&valueSwitch[44]);
      }
      _Val = v80;
      LOBYTE(v418) = 70;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      v75 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v388);
    }
    *(float *)&v379 = v2;
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v388);
    for ( i = 0; ; ++i )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v404,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = i;
      LOBYTE(v418) = 73;
      v82 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v404.gap10, "DRS_AVAILABLE_");
      std::wostream::operator<<(v82, *(_DWORD *)&valueSwitch[44]);
      v83 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v404, &key);
      LOBYTE(v418) = 74;
      v84 = INIReader::hasSection(&ini, v83);
      LOBYTE(v368) = v84;
      LOBYTE(v418) = 73;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v84 = v368;
      }
      if ( !v84 )
        break;
      *(float *)&v85 = COERCE_FLOAT(operator new(100));
      _Val = v85;
      LOBYTE(v418) = 75;
      if ( *(float *)&v85 == 0.0 )
      {
        *(float *)&v86 = 0.0;
      }
      else
      {
        *(_DWORD *)&valueSwitch[44] = 0;
        *(_DWORD *)&valueSwitch[40] = 12;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v404,
          (std::wstring *)&valueSwitch[16]);
        DigitalLed::DigitalLed(
          (DigitalLed *)v85,
          v1->car,
          &ini,
          *(std::wstring *)&valueSwitch[16],
          *(DigitalLedType *)&valueSwitch[40],
          *(Node **)&valueSwitch[44]);
      }
      _Val = v86;
      LOBYTE(v418) = 73;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      LOBYTE(v418) = 4;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v404);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v404);
    for ( j = 0; ; ++j )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v401,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = j;
      LOBYTE(v418) = 76;
      v88 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v401.gap10, "DRS_ENABLED_");
      std::wostream::operator<<(v88, *(_DWORD *)&valueSwitch[44]);
      v89 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v401, &key);
      LOBYTE(v418) = 77;
      v90 = INIReader::hasSection(&ini, v89);
      LOBYTE(v368) = v90;
      LOBYTE(v418) = 76;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v90 = v368;
      }
      if ( !v90 )
        break;
      *(float *)&v91 = COERCE_FLOAT(operator new(100));
      _Val = v91;
      LOBYTE(v418) = 78;
      if ( *(float *)&v91 == 0.0 )
      {
        *(float *)&v92 = 0.0;
      }
      else
      {
        *(_DWORD *)&valueSwitch[44] = 0;
        *(_DWORD *)&valueSwitch[40] = 13;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v401,
          (std::wstring *)&valueSwitch[16]);
        DigitalLed::DigitalLed(
          (DigitalLed *)v91,
          v1->car,
          &ini,
          *(std::wstring *)&valueSwitch[16],
          *(DigitalLedType *)&valueSwitch[40],
          *(Node **)&valueSwitch[44]);
      }
      _Val = v92;
      LOBYTE(v418) = 76;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      LOBYTE(v418) = 4;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v401);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v401);
    for ( k = 0; ; ++k )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v402,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = k;
      LOBYTE(v418) = 79;
      v94 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v402.gap10, "KERS_ENABLED_");
      std::wostream::operator<<(v94, *(_DWORD *)&valueSwitch[44]);
      v95 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v402, &key);
      LOBYTE(v418) = 80;
      v96 = INIReader::hasSection(&ini, v95);
      LOBYTE(v368) = v96;
      LOBYTE(v418) = 79;
      if ( key._Myres >= 8 )
      {
        operator delete(key._Bx._Ptr);
        v96 = v368;
      }
      if ( !v96 )
        break;
      *(float *)&v97 = COERCE_FLOAT(operator new(100));
      _Val = v97;
      LOBYTE(v418) = 81;
      if ( *(float *)&v97 == 0.0 )
      {
        *(float *)&v98 = 0.0;
      }
      else
      {
        *(_DWORD *)&valueSwitch[44] = 0;
        *(_DWORD *)&valueSwitch[40] = 14;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v402,
          (std::wstring *)&valueSwitch[16]);
        DigitalLed::DigitalLed(
          (DigitalLed *)v97,
          v1->car,
          &ini,
          *(std::wstring *)&valueSwitch[16],
          *(DigitalLedType *)&valueSwitch[40],
          *(Node **)&valueSwitch[44]);
      }
      _Val = v98;
      LOBYTE(v418) = 79;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      LOBYTE(v418) = 4;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v402);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v402);
    v99 = 0;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v397,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v99;
      LOBYTE(v418) = 82;
      v100 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v397.gap10, "PERF_LED_");
      std::wostream::operator<<(v100, *(_DWORD *)&valueSwitch[44]);
      v101 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v397, &key);
      LOBYTE(v418) = 83;
      v102 = INIReader::hasSection(&ini, v101);
      LOBYTE(v418) = 82;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( !v102 )
        break;
      *(float *)&v103 = COERCE_FLOAT(operator new(100));
      _Val = v103;
      LOBYTE(v418) = 84;
      if ( *(float *)&v103 == 0.0 )
      {
        v105 = 0.0;
      }
      else
      {
        DigitalLed::DigitalLed((DigitalLed *)v103, v1->car);
        v105 = v104;
      }
      *(_DWORD *)&valueSwitch[44] = L"OBJECT_NAME";
      LOBYTE(v418) = 82;
      *(float *)&v371 = v105;
      *(_DWORD *)LODWORD(v105) = 10;
      std::wstring::wstring(&key, *(const wchar_t **)&valueSwitch[44]);
      LOBYTE(v418) = 85;
      v106 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v397, &_Str);
      LOBYTE(v418) = 86;
      INIReader::getString(&ini, &_Right, v106, &key);
      if ( _Str._Myres >= 8 )
        operator delete(_Str._Bx._Ptr);
      _Str._Myres = 7;
      _Str._Mysize = 0;
      _Str._Bx._Buf[0] = 0;
      LOBYTE(v418) = 89;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      *(_DWORD *)&valueSwitch[44] = 1;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      *(_DWORD *)&valueSwitch[36] = 0;
      *(_DWORD *)&valueSwitch[40] = 7;
      *(_WORD *)&valueSwitch[20] = 0;
      std::wstring::assign((std::wstring *)&valueSwitch[20], &_Right, 0, 0xFFFFFFFF);
      *(float *)&v107 = COERCE_FLOAT(
                          Node::getNodeChild<Mesh>(
                            v1->car->bodyTransform,
                            *(std::wstring *)&valueSwitch[20],
                            valueSwitch[44]));
      v372 = *(float *)&v107;
      if ( *(float *)&v107 == 0.0 )
      {
        v115 = &_Right;
        if ( _Right._Myres >= 8 )
          v115 = (std::wstring *)_Right._Bx._Ptr;
        _printf("ERROR: Digital Led target %S\n", v115->_Bx._Buf);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v397);
        goto LABEL_345;
      }
      *(float *)&v108 = COERCE_FLOAT(operator new(104));
      _Val = v108;
      LOBYTE(v418) = 90;
      if ( *(float *)&v108 == 0.0 )
        v109 = 0;
      else
        Material::Material((Material *)v108, v107->material._Ptr);
      LOBYTE(v418) = 89;
      v376._Ptr = 0;
      v376._Rep = 0;
      std::shared_ptr<Material>::_Resetp<Material>(&v376, v109);
      _Val = (ICollisionObject *)&v107->material;
      std::shared_ptr<Material>::operator=(&v107->material, &v376);
      v110 = v376._Rep;
      if ( v376._Rep )
      {
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v376._Rep->_Uses, 0xFFFFFFFF) )
        {
          v110->_Destroy(v110);
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v110->_Weaks, 0xFFFFFFFF) )
            v110->_Delete_this(v110);
        }
      }
      std::wstring::wstring(&vname, L"ksEmissive");
      LOBYTE(v418) = 91;
      *(_DWORD *)(LODWORD(v105) + 92) = Material::getVar((Material *)_Val->__vftable, &vname);
      LOBYTE(v418) = 89;
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      *(_DWORD *)&valueSwitch[44] = L"EMISSIVE_NEG";
      *(float *)(LODWORD(v105) + 96) = v372;
      std::wstring::wstring(&v411, *(const wchar_t **)&valueSwitch[44]);
      LOBYTE(v418) = 92;
      v111 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v397, &vname);
      LOBYTE(v418) = 93;
      *(vec3f *)(LODWORD(v105) + 8) = *INIReader::getFloat3(&ini, (vec3f *)&v415.score, v111, &v411);
      if ( vname._Myres >= 8 )
        operator delete(vname._Bx._Ptr);
      vname._Myres = 7;
      vname._Mysize = 0;
      vname._Bx._Buf[0] = 0;
      LOBYTE(v418) = 89;
      if ( v411._Myres >= 8 )
        operator delete(v411._Bx._Ptr);
      std::wstring::wstring(&vname, L"EMISSIVE_POS");
      LOBYTE(v418) = 94;
      v112 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v397, &v411);
      LOBYTE(v418) = 95;
      *(vec3f *)(LODWORD(v105) + 20) = *INIReader::getFloat3(&ini, &c, v112, &vname);
      if ( v411._Myres >= 8 )
        operator delete(v411._Bx._Ptr);
      v411._Myres = 7;
      v411._Bx._Buf[0] = 0;
      v411._Mysize = 0;
      LOBYTE(v418) = 89;
      if ( vname._Myres >= 8 )
      {
        *(_DWORD *)&valueSwitch[44] = vname._Myres + 1;
        *(_DWORD *)&valueSwitch[40] = vname._Bx._Ptr;
        v113 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                            (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&vname,
                                            (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&v368);
        std::allocator<wchar_t>::deallocate(v113, *(wchar_t **)&valueSwitch[40], *(unsigned int *)&valueSwitch[44]);
      }
      vname._Myres = 7;
      std::wstring::_Eos(&vname, 0);
      std::wstring::wstring(&vname, L"EMISSIVE_BASE");
      LOBYTE(v418) = 96;
      v114 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v397, &v411);
      LOBYTE(v418) = 97;
      *(vec3f *)(LODWORD(v105) + 32) = *INIReader::getFloat3(&ini, (vec3f *)&v415, v114, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 89;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v99 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v397);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v397);
    v116 = 0;
    *(float *)&v369._Ptr = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v403,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v116;
      LOBYTE(v418) = 98;
      v117 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v403.gap10, "TURBO_BOOST_LED_");
      std::wostream::operator<<(v117, *(_DWORD *)&valueSwitch[44]);
      v118 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v403, &key);
      LOBYTE(v418) = 99;
      v119 = INIReader::hasSection(&ini, v118);
      LOBYTE(v418) = 98;
      v120 = v119;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v120 )
        break;
      *(float *)&v121 = COERCE_FLOAT(operator new(100));
      _Val = v121;
      LOBYTE(v418) = 100;
      if ( *(float *)&v121 == 0.0 )
      {
        *(float *)&v122 = 0.0;
      }
      else
      {
        *(_DWORD *)&valueSwitch[44] = 0;
        *(_DWORD *)&valueSwitch[40] = 15;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v403,
          (std::wstring *)&valueSwitch[16]);
        DigitalLed::DigitalLed(
          (DigitalLed *)v121,
          v1->car,
          &ini,
          *(std::wstring *)&valueSwitch[16],
          *(DigitalLedType *)&valueSwitch[40],
          *(Node **)&valueSwitch[44]);
      }
      _Val = v122;
      LOBYTE(v418) = 98;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
      v116 = (char *)&v369._Ptr->index + 1;
      LOBYTE(v418) = 4;
      ++v369._Ptr;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v403);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v403);
    v123 = 0;
    v376._Ptr = 0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v391,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v123;
      LOBYTE(v418) = 101;
      v124 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v391.gap10, "RPM_SERIE_");
      std::wostream::operator<<(v124, *(_DWORD *)&valueSwitch[44]);
      v125 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &key);
      LOBYTE(v418) = 102;
      v126 = INIReader::hasSection(&ini, v125);
      LOBYTE(v418) = 101;
      v127 = v126;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v127 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = 103;
      v128 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &_Str);
      LOBYTE(v418) = 104;
      INIReader::getString(&ini, &_Right, v128, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_INDEX");
      LOBYTE(v418) = 108;
      v129 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
      LOBYTE(v418) = 109;
      v375 = (float)INIReader::getInt(&ini, v129, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_INDEX");
      LOBYTE(v418) = 110;
      v130 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
      LOBYTE(v418) = 111;
      *(float *)&excluded[4] = (float)INIReader::getInt(&ini, v130, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"RPM_START");
      LOBYTE(v418) = 112;
      v131 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
      LOBYTE(v418) = 113;
      v374 = (float)INIReader::getInt(&ini, v131, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"RPM_END");
      LOBYTE(v418) = 114;
      v132 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
      LOBYTE(v418) = 115;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v132, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      mx = FLOAT_N1_0;
      std::wstring::wstring(&vname, L"BLINK_SWITCH");
      LOBYTE(v418) = 116;
      v133 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
      LOBYTE(v418) = 117;
      v134 = INIReader::hasKey(&ini, v133, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      if ( v134 )
      {
        std::wstring::wstring(&vname, L"BLINK_SWITCH");
        LOBYTE(v418) = 118;
        v135 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
        LOBYTE(v418) = 119;
        *(float *)&_Val = INIReader::getFloat(&ini, v135, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
        LOBYTE(v418) = 107;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        mx = *(float *)&_Val;
      }
      v373 = 0.0;
      std::wstring::wstring(&vname, L"BLINK_HZ");
      LOBYTE(v418) = 120;
      v136 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
      LOBYTE(v418) = 121;
      v137 = INIReader::hasKey(&ini, v136, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 107;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      if ( v137 )
      {
        std::wstring::wstring(&vname, L"BLINK_HZ");
        LOBYTE(v418) = 122;
        v138 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &v411);
        LOBYTE(v418) = 123;
        *(float *)&_Val = INIReader::getFloat(&ini, v138, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
        LOBYTE(v418) = 107;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        v373 = *(float *)&_Val;
      }
      *(float *)&v369._Ptr = (float)(*(float *)&v369._Ptr - v374) / (float)(*(float *)&excluded[4] - v375);
      if ( *(float *)&excluded[4] >= v375 )
      {
        do
        {
          std::wstring::wstring(&vname, word_17BE9D8);
          LOBYTE(v418) = 124;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v391, &vname);
          LOBYTE(v418) = 107;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          *(float *)&valueSwitch[44] = v375;
          v139 = std::operator<<<wchar_t>((std::wostream *)v391.gap10, &_Right);
          std::wostream::operator<<(v139);
          *(float *)&v140 = COERCE_FLOAT(operator new(100));
          _Val = v140;
          LOBYTE(v418) = 125;
          if ( *(float *)&v140 == 0.0 )
          {
            *(float *)&v141 = 0.0;
          }
          else
          {
            *(float *)&valueSwitch[44] = v373;
            *(float *)&valueSwitch[40] = mx;
            *(float *)&valueSwitch[36] = v374;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v391,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v140,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          _Val = v141;
          LOBYTE(v418) = 107;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
          v374 = *(float *)&v369._Ptr + v374;
          v142 = *(float *)&excluded[4] < (float)(v375 + 1.0);
          v375 = v375 + 1.0;
        }
        while ( !v142 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v123 = &v376._Ptr->name._Bx._Alias[1];
      LOBYTE(v418) = 4;
      ++v376._Ptr;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v391);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v391);
    v143 = 0;
    *(_DWORD *)&excluded[4] = 0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v392,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v143;
      LOBYTE(v418) = 126;
      v144 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v392.gap10, "GFORCE_SERIE_");
      std::wostream::operator<<(v144, *(_DWORD *)&valueSwitch[44]);
      v145 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &key);
      LOBYTE(v418) = 127;
      v146 = INIReader::hasSection(&ini, v145);
      LOBYTE(v418) = 126;
      v147 = v146;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v147 )
        break;
      std::wstring::wstring(&vname, L"PREFIX");
      LOBYTE(v418) = 0x80;
      v148 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &v411);
      LOBYTE(v418) = -127;
      INIReader::getString(&ini, &_Str, v148, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -124;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&_Right, L"START_INDEX");
      LOBYTE(v418) = -123;
      v149 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &v415.name);
      LOBYTE(v418) = -122;
      v375 = (float)INIReader::getInt(&ini, v149, &_Right);
      std::wstring::~wstring(&v415);
      LOBYTE(v418) = -124;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      std::wstring::wstring(&_Right, L"END_INDEX");
      LOBYTE(v418) = -121;
      v150 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &v415.name);
      LOBYTE(v418) = -120;
      *(float *)&v376._Ptr = (float)INIReader::getInt(&ini, v150, &_Right);
      std::wstring::~wstring(&v415);
      LOBYTE(v418) = -124;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      std::wstring::wstring(&_Right, L"FORCE_START");
      LOBYTE(v418) = -119;
      v151 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &v415.name);
      LOBYTE(v418) = -118;
      *(float *)&_Val = INIReader::getFloat(&ini, v151, &_Right) * 1000.0;
      std::wstring::~wstring(&v415);
      LOBYTE(v418) = -124;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      std::wstring::wstring(&_Right, L"FORCE_END");
      LOBYTE(v418) = -117;
      v152 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &v415.name);
      LOBYTE(v418) = -116;
      v372 = INIReader::getFloat(&ini, v152, &_Right) * 1000.0;
      std::wstring::~wstring(&v415);
      LOBYTE(v418) = -124;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      std::wstring::wstring(&_Right, L"SIGN");
      LOBYTE(v418) = -115;
      v153 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &v415.name);
      LOBYTE(v418) = -114;
      *(float *)&v371 = (float)INIReader::getInt(&ini, v153, &_Right);
      std::wstring::~wstring(&v415);
      LOBYTE(v418) = -124;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      *(float *)&v369._Ptr = 0.0;
      std::wstring::wstring(&_Right, L"DIRECTION");
      LOBYTE(v418) = -113;
      v154 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &v415.name);
      LOBYTE(v418) = -112;
      INIReader::getString(&ini, &key, v154, &_Right);
      std::wstring::~wstring(&v415);
      LOBYTE(v418) = -109;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      if ( std::operator==<wchar_t>(&key, L"X") )
        *(float *)&v369._Ptr = 0.0;
      if ( std::operator==<wchar_t>(&key, L"Y") )
        *(float *)&v369._Ptr = FLOAT_1_0;
      if ( std::operator==<wchar_t>(&key, L"Z") )
        v155 = FLOAT_2_0;
      else
        v155 = *(float *)&v369._Ptr;
      v369._Ptr = (TyreCompoundDef *)_Val;
      v372 = (float)(v372 - *(float *)&_Val) / (float)(*(float *)&v376._Ptr - v375);
      if ( *(float *)&v376._Ptr >= v375 )
      {
        do
        {
          std::wstring::wstring(&vname, word_17BE9D8);
          LOBYTE(v418) = -108;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v392, &vname);
          LOBYTE(v418) = -109;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          *(float *)&valueSwitch[44] = v375;
          v156 = std::operator<<<wchar_t>((std::wostream *)v392.gap10, &_Str);
          std::wostream::operator<<(v156);
          *(float *)&v157 = COERCE_FLOAT(operator new(100));
          _Val = v157;
          LOBYTE(v418) = -107;
          if ( *(float *)&v157 == 0.0 )
          {
            *(float *)&v158 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&valueSwitch[36] = v369;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v392,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v157,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          _Val = v158;
          LOBYTE(v418) = -109;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &_Val);
          (*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20))->type = GFORCES;
          (*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20))->gForce = (int)v155;
          v159 = (int)*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          v160 = v376._Ptr;
          *(float *)&v369._Ptr = v372 + *(float *)&v369._Ptr;
          v161 = v375 + 1.0;
          *(_DWORD *)(v159 + 76) = (int)*(float *)&v371;
          v375 = v161;
        }
        while ( *(float *)&v160 >= v161 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      v143 = *(_DWORD *)&excluded[4] + 1;
      LOBYTE(v418) = 4;
      ++*(_DWORD *)&excluded[4];
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v392);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v392);
    v162 = 0;
    *(float *)&_Val = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v386,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v162;
      LOBYTE(v418) = -106;
      v163 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v386.gap10, "KERS_CHARGE_SERIE_");
      std::wostream::operator<<(v163, *(_DWORD *)&valueSwitch[44]);
      v164 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &key);
      LOBYTE(v418) = -105;
      v165 = INIReader::hasSection(&ini, v164);
      LOBYTE(v418) = -106;
      v166 = v165;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v166 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = -104;
      v167 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &v411);
      LOBYTE(v418) = -103;
      INIReader::getString(&ini, &_Str, v167, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -100;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_INDEX");
      LOBYTE(v418) = -99;
      v168 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &_Right);
      LOBYTE(v418) = -98;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v168, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      LOBYTE(v418) = -100;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_INDEX");
      LOBYTE(v418) = -97;
      v169 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &_Right);
      LOBYTE(v418) = -96;
      v372 = (float)INIReader::getInt(&ini, v169, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      LOBYTE(v418) = -100;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v373 = FLOAT_1_0;
      v376._Ptr = 0;
      v375 = FLOAT_100_0;
      std::wstring::wstring(&_Right, L"PERC_START");
      v170 = v379 | 2;
      LOBYTE(v418) = -95;
      LODWORD(v374) = v379 | 2;
      v171 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
               &v386,
               (std::wstring *)&v415.score);
      v418 = 162;
      LODWORD(v172) = v170 | 4;
      v374 = v172;
      if ( !INIReader::hasKey(&ini, v171, &_Right) )
        goto LABEL_224;
      std::wstring::wstring(&vname, L"PERC_END");
      v418 = 163;
      LODWORD(v173) = LODWORD(v172) | 8;
      v374 = v173;
      v174 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &v415.name);
      v418 = 164;
      LODWORD(v172) = LODWORD(v173) | 0x10;
      v374 = v172;
      v175 = INIReader::hasKey(&ini, v174, &vname);
      LOBYTE(v368) = 1;
      if ( !v175 )
LABEL_224:
        LOBYTE(v368) = 0;
      if ( (LOBYTE(v172) & 0x10) != 0 )
      {
        LODWORD(v172) &= 0xFFFFFFEF;
        std::wstring::~wstring(&v415);
      }
      if ( (LOBYTE(v172) & 8) != 0 )
      {
        LODWORD(v172) &= 0xFFFFFFF7;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      }
      if ( (LOBYTE(v172) & 4) != 0 )
      {
        LODWORD(v172) &= 0xFFFFFFFB;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v415.score);
      }
      v418 = 156;
      if ( (LOBYTE(v172) & 2) != 0 )
      {
        LODWORD(v172) &= 0xFFFFFFFD;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      }
      if ( (_BYTE)v368 )
      {
        std::wstring::wstring(&vname, L"PERC_START");
        LOBYTE(v418) = -91;
        v176 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &_Right);
        LOBYTE(v418) = -90;
        *(float *)&v371 = INIReader::getFloat(&ini, v176, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -100;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        std::wstring::wstring(&vname, L"PERC_END");
        LOBYTE(v418) = -89;
        v177 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &_Right);
        LOBYTE(v418) = -88;
        mx = INIReader::getFloat(&ini, v177, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -100;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        v376._Ptr = (Material *)v371;
        v373 = *(float *)&v371;
        v375 = mx;
      }
      excluded[4] = 0;
      *(float *)&v371 = 0.0;
      mx = 0.0;
      std::wstring::wstring(&_Right, L"SHOW_MIN");
      LOBYTE(v418) = -87;
      LODWORD(v178) = LODWORD(v172) | 0x20;
      v374 = v178;
      v179 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
               &v386,
               (std::wstring *)&v415.score);
      v418 = 170;
      v180 = LODWORD(v178) | 0x40;
      v379 = v180;
      v374 = *(float *)&v180;
      if ( !INIReader::hasKey(&ini, v179, &_Right) )
        goto LABEL_237;
      std::wstring::wstring(&vname, L"SHOW_MAX");
      v418 = 171;
      LODWORD(v181) = v180 | 0x80;
      v374 = v181;
      v182 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &v415.name);
      v418 = 172;
      v180 = LODWORD(v181) | 0x100;
      v379 = v180;
      v374 = *(float *)&v180;
      v183 = INIReader::hasKey(&ini, v182, &vname);
      LOBYTE(v368) = 1;
      if ( !v183 )
LABEL_237:
        LOBYTE(v368) = 0;
      if ( (v180 & 0x100) != 0 )
      {
        v180 &= 0xFFFFFEFF;
        v379 = v180;
        std::wstring::~wstring(&v415);
      }
      if ( (v180 & 0x80u) != 0 )
      {
        v180 &= 0xFFFFFF7F;
        v379 = v180;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      }
      if ( (v180 & 0x40) != 0 )
      {
        v180 &= 0xFFFFFFBF;
        v379 = v180;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v415.score);
      }
      v418 = 156;
      if ( (v180 & 0x20) != 0 )
      {
        v379 = v180 & 0xFFFFFFDF;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      }
      if ( (_BYTE)v368 )
      {
        std::wstring::wstring(&vname, L"SHOW_MIN");
        LOBYTE(v418) = -83;
        v184 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &_Right);
        LOBYTE(v418) = -82;
        *(float *)&v371 = INIReader::getFloat(&ini, v184, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -100;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        std::wstring::wstring(&vname, L"SHOW_MAX");
        LOBYTE(v418) = -81;
        v185 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &_Right);
        LOBYTE(v418) = -80;
        mx = INIReader::getFloat(&ini, v185, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -100;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        std::wstring::wstring(&vname, L"SHOW_EXCLUDED");
        LOBYTE(v418) = -79;
        v186 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &_Right);
        LOBYTE(v418) = -78;
        excluded[4] = INIReader::getInt(&ini, v186, &vname) != 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -100;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      }
      v375 = (float)(v375 - *(float *)&v376._Ptr) / (float)(v372 - *(float *)&v369._Ptr);
      if ( v372 >= *(float *)&v369._Ptr )
      {
        v187 = *(_DWORD *)&excluded[4];
        do
        {
          std::wstring::wstring(&vname, word_17BE9D8);
          LOBYTE(v418) = -77;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v386, &vname);
          LOBYTE(v418) = -100;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&valueSwitch[44] = v369;
          v188 = std::operator<<<wchar_t>((std::wostream *)v386.gap10, &_Str);
          std::wostream::operator<<(v188);
          v189 = (Material *)operator new(100);
          v376._Ptr = v189;
          LOBYTE(v418) = -76;
          if ( v189 )
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(float *)&valueSwitch[36] = v373;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v386,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v189,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          else
          {
            v190 = 0;
          }
          v376._Ptr = v190;
          LOBYTE(v418) = -100;
          std::vector<SpinnerData *>::push_back(
            (std::vector<ICollisionObject *> *)v20,
            (ICollisionObject *const *)&v376);
          (*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20))->type = KERS_CHARGE;
          v191 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          *(_DWORD *)&valueSwitch[44] = v187;
          DigitalLed::setShowLimits(*v191, *(float *)&v371, mx, v187);
          v373 = v375 + v373;
          v142 = v372 < (float)(*(float *)&v369._Ptr + 1.0);
          *(float *)&v369._Ptr = *(float *)&v369._Ptr + 1.0;
        }
        while ( !v142 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      v162 = (char *)&_Val->__vftable + 1;
      LOBYTE(v418) = 4;
      _Val = (ICollisionObject *)((char *)_Val + 1);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v386);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v386);
    v192 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v395,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v192;
      LOBYTE(v418) = -75;
      v193 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v395.gap10, "TURBO_BOOST_SERIE_");
      std::wostream::operator<<(v193, *(_DWORD *)&valueSwitch[44]);
      v194 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v395, &key);
      LOBYTE(v418) = -74;
      v195 = INIReader::hasSection(&ini, v194);
      LOBYTE(v418) = -75;
      v196 = v195;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v196 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = -73;
      v197 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v395, &_Str);
      LOBYTE(v418) = -72;
      INIReader::getString(&ini, &_Right, v197, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = -69;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_INDEX");
      LOBYTE(v418) = -68;
      v198 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v395, &v411);
      LOBYTE(v418) = -67;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v198, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -69;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_INDEX");
      LOBYTE(v418) = -66;
      v199 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v395, &v411);
      LOBYTE(v418) = -65;
      *(float *)&_Val = (float)INIReader::getInt(&ini, v199, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -69;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"BOOST_START");
      LOBYTE(v418) = -64;
      v200 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v395, &v411);
      LOBYTE(v418) = -63;
      *(float *)&v371 = INIReader::getFloat(&ini, v200, &vname) * 100.0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -69;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"BOOST_END");
      LOBYTE(v418) = -62;
      v201 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v395, &v411);
      LOBYTE(v418) = -61;
      *(float *)&v376._Ptr = INIReader::getFloat(&ini, v201, &vname) * 100.0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -69;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v373 = *(float *)&v371;
      *(float *)&v376._Ptr = (float)(*(float *)&v376._Ptr - *(float *)&v371)
                           / (float)(*(float *)&_Val - *(float *)&v369._Ptr);
      if ( *(float *)&_Val >= *(float *)&v369._Ptr )
      {
        do
        {
          std::wstring::wstring(&vname, word_17BE9D8);
          LOBYTE(v418) = -60;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v395, &vname);
          LOBYTE(v418) = -69;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&valueSwitch[44] = v369;
          v202 = std::operator<<<wchar_t>((std::wostream *)v395.gap10, &_Right);
          std::wostream::operator<<(v202);
          *(float *)&v203 = COERCE_FLOAT(operator new(100));
          v371 = v203;
          LOBYTE(v418) = -59;
          if ( *(float *)&v203 == 0.0 )
          {
            *(float *)&v204 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(float *)&valueSwitch[36] = v373;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v395,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v203,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v204;
          LOBYTE(v418) = -69;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          v205 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          v206 = _Val;
          v207 = *v205;
          v373 = *(float *)&v376._Ptr + v373;
          v208 = *(float *)&v369._Ptr + 1.0;
          v207->type = TURBO_BOOST;
          *(float *)&v369._Ptr = v208;
        }
        while ( *(float *)&v206 >= v208 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v192 = LODWORD(v372) + 1;
      LOBYTE(v418) = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v395);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v395);
    v209 = v379;
    v210 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v390,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v210;
      LOBYTE(v418) = -58;
      v211 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v390.gap10, "KERS_INPUT_SERIE_");
      std::wostream::operator<<(v211, *(_DWORD *)&valueSwitch[44]);
      v212 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &key);
      LOBYTE(v418) = -57;
      v213 = INIReader::hasSection(&ini, v212);
      LOBYTE(v418) = -58;
      v214 = v213;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v214 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = -56;
      v215 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &v411);
      LOBYTE(v418) = -55;
      INIReader::getString(&ini, &_Str, v215, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -52;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_INDEX");
      LOBYTE(v418) = -51;
      v216 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &_Right);
      LOBYTE(v418) = -50;
      *(float *)&excluded[4] = INIReader::getFloat(&ini, v216, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      LOBYTE(v418) = -52;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_INDEX");
      LOBYTE(v418) = -49;
      v217 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &_Right);
      LOBYTE(v418) = -48;
      *(float *)&_Val = INIReader::getFloat(&ini, v217, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      LOBYTE(v418) = -52;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      LOBYTE(v368) = 0;
      std::wstring::wstring(&vname, L"INVERTED");
      LOBYTE(v418) = -47;
      v218 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &_Right);
      LOBYTE(v418) = -46;
      v219 = INIReader::hasKey(&ini, v218, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      LOBYTE(v418) = -52;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      if ( v219 )
      {
        std::wstring::wstring(&vname, L"INVERTED");
        LOBYTE(v418) = -45;
        v220 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &_Right);
        LOBYTE(v418) = -44;
        LOBYTE(v368) = INIReader::getInt(&ini, v220, &vname) != 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -52;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      }
      *(float *)&v369._Ptr = FLOAT_1_0;
      *(float *)&v371 = 0.0;
      v373 = FLOAT_100_0;
      std::wstring::wstring(&_Right, L"PERC_START");
      LOBYTE(v418) = -43;
      LODWORD(v221) = v209 | 0x200;
      v374 = v221;
      v222 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
               &v390,
               (std::wstring *)&v415.score);
      v418 = 214;
      v209 = LODWORD(v221) | 0x400;
      v374 = *(float *)&v209;
      if ( !INIReader::hasKey(&ini, v222, &_Right) )
        goto LABEL_270;
      std::wstring::wstring(&vname, L"PERC_END");
      v418 = 215;
      LODWORD(v223) = v209 | 0x800;
      v374 = v223;
      v224 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &v415.name);
      v418 = 216;
      v209 = LODWORD(v223) | 0x1000;
      v374 = *(float *)&v209;
      if ( INIReader::hasKey(&ini, v224, &vname) )
        v225 = 1;
      else
LABEL_270:
        v225 = 0;
      if ( (v209 & 0x1000) != 0 )
      {
        v209 &= 0xFFFFEFFF;
        std::wstring::~wstring(&v415);
      }
      if ( (v209 & 0x800) != 0 )
      {
        v209 &= 0xFFFFF7FF;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      }
      if ( (v209 & 0x400) != 0 )
      {
        v209 &= 0xFFFFFBFF;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v415.score);
      }
      v418 = 204;
      if ( (v209 & 0x200) != 0 )
      {
        v209 &= 0xFFFFFDFF;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      }
      if ( v225 )
      {
        std::wstring::wstring(&vname, L"PERC_START");
        LOBYTE(v418) = -39;
        v226 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &_Right);
        LOBYTE(v418) = -38;
        *(float *)&v371 = INIReader::getFloat(&ini, v226, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -52;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        std::wstring::wstring(&vname, L"PERC_END");
        LOBYTE(v418) = -37;
        v227 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &_Right);
        LOBYTE(v418) = -36;
        *(float *)&v376._Ptr = INIReader::getFloat(&ini, v227, &vname);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
        LOBYTE(v418) = -52;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
        v228 = v371;
        v229 = *(float *)&v376._Ptr;
        v369._Ptr = (TyreCompoundDef *)v371;
      }
      else
      {
        v229 = v373;
        v228 = v371;
      }
      v375 = *(float *)&excluded[4];
      v373 = (float)(v229 - *(float *)&v228) / (float)(*(float *)&_Val - *(float *)&excluded[4]);
      if ( *(float *)&_Val >= *(float *)&excluded[4] )
      {
        do
        {
          std::wstring::wstring(&vname, word_17BE9D8);
          LOBYTE(v418) = -35;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v390, &vname);
          LOBYTE(v418) = -52;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          *(float *)&valueSwitch[44] = v375;
          v230 = std::operator<<<wchar_t>((std::wostream *)v390.gap10, &_Str);
          std::wostream::operator<<(v230);
          *(float *)&v231 = COERCE_FLOAT(operator new(100));
          v371 = v231;
          LOBYTE(v418) = -34;
          if ( *(float *)&v231 == 0.0 )
          {
            *(float *)&v232 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&valueSwitch[36] = v369;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v390,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v231,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v232;
          LOBYTE(v418) = -52;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          (*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20))->type = KERS_INPUT;
          v233 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          v234 = _Val;
          v235 = *v233;
          *(float *)&v369._Ptr = v373 + *(float *)&v369._Ptr;
          v236 = v375 + 1.0;
          v235->inverted = v368;
          v375 = v236;
        }
        while ( *(float *)&v234 >= v236 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      v210 = LODWORD(v372) + 1;
      LOBYTE(v418) = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v390);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v390);
    v237 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v396,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v237;
      LOBYTE(v418) = -33;
      v238 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v396.gap10, "DRS_SERIE_");
      std::wostream::operator<<(v238, *(_DWORD *)&valueSwitch[44]);
      v239 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v396, &key);
      LOBYTE(v418) = -32;
      v240 = INIReader::hasSection(&ini, v239);
      LOBYTE(v418) = -33;
      v241 = v240;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v241 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = -31;
      v242 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v396, &_Str);
      LOBYTE(v418) = -30;
      INIReader::getString(&ini, &_Right, v242, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = -27;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_ANGLE");
      LOBYTE(v418) = -26;
      v243 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v396, &v411);
      LOBYTE(v418) = -25;
      *(float *)&v371 = (float)INIReader::getInt(&ini, v243, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -27;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_ANGLE");
      LOBYTE(v418) = -24;
      v244 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v396, &v411);
      LOBYTE(v418) = -23;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v244, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -27;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"LED_COUNT");
      LOBYTE(v418) = -22;
      v245 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v396, &v411);
      LOBYTE(v418) = -21;
      *(float *)&_Val = (float)INIReader::getInt(&ini, v245, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -27;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"INVERTED_DRS");
      LOBYTE(v418) = -20;
      v246 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v396, &v411);
      LOBYTE(v418) = -19;
      LOBYTE(v368) = INIReader::getInt(&ini, v246, &vname) != 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -27;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v247 = 0;
      *(float *)&v369._Ptr = (float)(*(float *)&v369._Ptr - *(float *)&v371) / *(float *)&_Val;
      v373 = *(float *)&v369._Ptr + *(float *)&v371;
      if ( *(float *)&_Val > 0.0 )
      {
        do
        {
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v405,
            3,
            1);
          *(_DWORD *)&valueSwitch[44] = v247;
          LOBYTE(v418) = -18;
          v248 = std::operator<<<wchar_t>((std::wostream *)v405.gap10, &_Right);
          std::wostream::operator<<(v248, *(_DWORD *)&valueSwitch[44]);
          *(float *)&v249 = COERCE_FLOAT(operator new(100));
          v371 = v249;
          LOBYTE(v418) = -17;
          if ( *(float *)&v249 == 0.0 )
          {
            *(float *)&v250 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(float *)&valueSwitch[36] = v373;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v405,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v249,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v250;
          LOBYTE(v418) = -18;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          v251 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          *(_DWORD *)&valueSwitch[44] = L"WING_NUMBER";
          (*v251)->type = DRS;
          std::wstring::wstring(&vname, *(const wchar_t **)&valueSwitch[44]);
          LOBYTE(v418) = -16;
          v252 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v396, &v411);
          LOBYTE(v418) = -15;
          v253 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          (*v253)->selectedWing = INIReader::getInt(&ini, v252, &vname);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          v254 = (int)*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          LOBYTE(v418) = -27;
          v373 = v373 + *(float *)&v369._Ptr;
          *(_BYTE *)(v254 + 56) = v368;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v405);
          ++v247;
          v1 = v380;
        }
        while ( *(float *)&_Val > (float)v247 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v237 = LODWORD(v372) + 1;
      LOBYTE(v418) = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v396);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v396);
    v255 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v394,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v255;
      LOBYTE(v418) = -14;
      v256 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v394.gap10, "KERS_LOAD_SERIE_");
      std::wostream::operator<<(v256, *(_DWORD *)&valueSwitch[44]);
      v257 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &key);
      LOBYTE(v418) = -13;
      v258 = INIReader::hasSection(&ini, v257);
      LOBYTE(v418) = -14;
      v259 = v258;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v259 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = -12;
      v260 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &_Str);
      LOBYTE(v418) = -11;
      INIReader::getString(&ini, &_Right, v260, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = -8;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_INDEX");
      LOBYTE(v418) = -7;
      v261 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &v411);
      LOBYTE(v418) = -6;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v261, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -8;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_INDEX");
      LOBYTE(v418) = -5;
      v262 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &v411);
      LOBYTE(v418) = -4;
      *(float *)&_Val = (float)INIReader::getInt(&ini, v262, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -8;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"INVERTED");
      LOBYTE(v418) = -3;
      v263 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &v411);
      LOBYTE(v418) = -2;
      v264 = INIReader::getInt(&ini, v263, &vname) != 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -8;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"PERC_START");
      LOBYTE(v418) = -1;
      v265 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &v411);
      v418 = 256;
      v266 = INIReader::getFloat(&ini, v265, &vname);
      v418 = 255;
      *(float *)&v371 = v266;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = -8;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"PERC_END");
      v418 = 257;
      v267 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &v411);
      LOBYTE(v418) = 2;
      *(float *)&v376._Ptr = INIReader::getFloat(&ini, v267, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      v418 = 248;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v373 = *(float *)&v371;
      *(float *)&v376._Ptr = (float)(*(float *)&v376._Ptr - *(float *)&v371)
                           / (float)(*(float *)&_Val - *(float *)&v369._Ptr);
      if ( *(float *)&_Val >= *(float *)&v369._Ptr )
      {
        do
        {
          std::wstring::wstring(&vname, word_17BE9D8);
          v418 = 259;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v394, &vname);
          v418 = 248;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&valueSwitch[44] = v369;
          v268 = std::operator<<<wchar_t>((std::wostream *)v394.gap10, &_Right);
          std::wostream::operator<<(v268);
          *(float *)&v269 = COERCE_FLOAT(operator new(100));
          v371 = v269;
          v418 = 260;
          if ( *(float *)&v269 == 0.0 )
          {
            *(float *)&v270 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(float *)&valueSwitch[36] = v373;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v394,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v269,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v270;
          v418 = 248;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          (*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20))->type = KERS_LOAD;
          v271 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          v272 = _Val;
          v273 = *v271;
          v373 = *(float *)&v376._Ptr + v373;
          v274 = *(float *)&v369._Ptr + 1.0;
          v273->inverted = v264;
          *(float *)&v369._Ptr = v274;
        }
        while ( *(float *)&v272 >= v274 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v255 = LODWORD(v372) + 1;
      LOBYTE(v418) = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v394);
    }
    LOBYTE(v418) = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v394);
    v275 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v400,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v275;
      v418 = 261;
      v276 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v400.gap10, "WATER_TEMP_");
      std::wostream::operator<<(v276, *(_DWORD *)&valueSwitch[44]);
      v277 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v400, &key);
      LOBYTE(v418) = 6;
      v278 = INIReader::hasSection(&ini, v277);
      LOBYTE(v418) = 5;
      v279 = v278;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v279 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = 7;
      v280 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v400, &_Str);
      LOBYTE(v418) = 8;
      INIReader::getString(&ini, &_Right, v280, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = 11;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_TEMP");
      LOBYTE(v418) = 12;
      v281 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v400, &v411);
      LOBYTE(v418) = 13;
      *(float *)&v371 = (float)INIReader::getInt(&ini, v281, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 11;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_TEMP");
      LOBYTE(v418) = 14;
      v282 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v400, &v411);
      LOBYTE(v418) = 15;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v282, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 11;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"LED_COUNT");
      LOBYTE(v418) = 16;
      v283 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v400, &v411);
      LOBYTE(v418) = 17;
      *(float *)&_Val = (float)INIReader::getInt(&ini, v283, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 11;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v284 = 0;
      *(float *)&v369._Ptr = (float)(*(float *)&v369._Ptr - *(float *)&v371) / *(float *)&_Val;
      v373 = *(float *)&v369._Ptr + *(float *)&v371;
      if ( *(float *)&_Val > 0.0 )
      {
        do
        {
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v408,
            3,
            1);
          *(_DWORD *)&valueSwitch[44] = v284;
          LOBYTE(v418) = 18;
          v285 = std::operator<<<wchar_t>((std::wostream *)v408.gap10, &_Right);
          std::wostream::operator<<(v285, *(_DWORD *)&valueSwitch[44]);
          *(float *)&v286 = COERCE_FLOAT(operator new(100));
          v371 = v286;
          LOBYTE(v418) = 19;
          if ( *(float *)&v286 == 0.0 )
          {
            *(float *)&v287 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(float *)&valueSwitch[36] = v373;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v408,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v286,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v287;
          LOBYTE(v418) = 18;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          v288 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          LOBYTE(v418) = 11;
          v289 = *v288;
          v373 = v373 + *(float *)&v369._Ptr;
          v289->type = WATER_TEMP;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v408);
          ++v284;
        }
        while ( *(float *)&_Val > (float)v284 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v275 = LODWORD(v372) + 1;
      v418 = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v400);
    }
    v418 = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v400);
    v290 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v399,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v290;
      v418 = 276;
      v291 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v399.gap10, "SPEED_SERIE_");
      std::wostream::operator<<(v291, *(_DWORD *)&valueSwitch[44]);
      v292 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v399, &key);
      LOBYTE(v418) = 21;
      v293 = INIReader::hasSection(&ini, v292);
      LOBYTE(v418) = 20;
      v294 = v293;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v294 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = 22;
      v295 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v399, &_Str);
      LOBYTE(v418) = 23;
      INIReader::getString(&ini, &_Right, v295, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_SPEED");
      LOBYTE(v418) = 27;
      v296 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v399, &v411);
      LOBYTE(v418) = 28;
      *(float *)&v371 = (float)INIReader::getInt(&ini, v296, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_SPEED");
      LOBYTE(v418) = 29;
      v297 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v399, &v411);
      LOBYTE(v418) = 30;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v297, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"LED_COUNT");
      LOBYTE(v418) = 31;
      v298 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v399, &v411);
      LOBYTE(v418) = 32;
      *(float *)&_Val = (float)INIReader::getInt(&ini, v298, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v299 = 0;
      *(float *)&v369._Ptr = (float)(*(float *)&v369._Ptr - *(float *)&v371) / *(float *)&_Val;
      v373 = *(float *)&v369._Ptr + *(float *)&v371;
      if ( *(float *)&_Val > 0.0 )
      {
        do
        {
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v407,
            3,
            1);
          *(_DWORD *)&valueSwitch[44] = v299;
          LOBYTE(v418) = 33;
          v300 = std::operator<<<wchar_t>((std::wostream *)v407.gap10, &_Right);
          std::wostream::operator<<(v300, *(_DWORD *)&valueSwitch[44]);
          *(float *)&v301 = COERCE_FLOAT(operator new(100));
          v371 = v301;
          LOBYTE(v418) = 34;
          if ( *(float *)&v301 == 0.0 )
          {
            *(float *)&v302 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(float *)&valueSwitch[36] = v373;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v407,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v301,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v302;
          LOBYTE(v418) = 33;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          v303 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          LOBYTE(v418) = 26;
          v304 = *v303;
          v373 = v373 + *(float *)&v369._Ptr;
          v304->type = SPEED;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v407);
          ++v299;
        }
        while ( *(float *)&_Val > (float)v299 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v290 = LODWORD(v372) + 1;
      v418 = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v399);
    }
    v418 = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v399);
    v305 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v398,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v305;
      v418 = 291;
      v306 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v398.gap10, "POWER_918_");
      std::wostream::operator<<(v306, *(_DWORD *)&valueSwitch[44]);
      v307 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v398, &key);
      LOBYTE(v418) = 36;
      v308 = INIReader::hasSection(&ini, v307);
      LOBYTE(v418) = 35;
      v309 = v308;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v309 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = 37;
      v310 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v398, &_Str);
      LOBYTE(v418) = 38;
      INIReader::getString(&ini, &_Right, v310, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = 41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_TORQUE");
      LOBYTE(v418) = 42;
      v311 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v398, &v411);
      LOBYTE(v418) = 43;
      *(float *)&v371 = (float)INIReader::getInt(&ini, v311, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_TORQUE");
      LOBYTE(v418) = 44;
      v312 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v398, &v411);
      LOBYTE(v418) = 45;
      *(float *)&v369._Ptr = (float)INIReader::getInt(&ini, v312, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"LED_COUNT");
      LOBYTE(v418) = 46;
      v313 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v398, &v411);
      LOBYTE(v418) = 47;
      *(float *)&_Val = (float)INIReader::getInt(&ini, v313, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v314 = 0;
      *(float *)&v369._Ptr = (float)(*(float *)&v369._Ptr - *(float *)&v371) / *(float *)&_Val;
      v373 = *(float *)&v369._Ptr + *(float *)&v371;
      if ( *(float *)&_Val > 0.0 )
      {
        do
        {
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v406,
            3,
            1);
          *(_DWORD *)&valueSwitch[44] = v314;
          LOBYTE(v418) = 48;
          v315 = std::operator<<<wchar_t>((std::wostream *)v406.gap10, &_Right);
          std::wostream::operator<<(v315, *(_DWORD *)&valueSwitch[44]);
          *(float *)&v316 = COERCE_FLOAT(operator new(100));
          v371 = v316;
          LOBYTE(v418) = 49;
          if ( *(float *)&v316 == 0.0 )
          {
            *(float *)&v317 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(float *)&valueSwitch[36] = v373;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v406,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v316,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v317;
          LOBYTE(v418) = 48;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          std::wstring::wstring(&vname, L"FILTER");
          LOBYTE(v418) = 50;
          v318 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v398, &v411);
          LOBYTE(v418) = 51;
          v319 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          (*v319)->showMin = INIReader::getFloat(&ini, v318, &vname);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          v320 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          LOBYTE(v418) = 41;
          v321 = *v320;
          v373 = v373 + *(float *)&v369._Ptr;
          v321->type = POWER_918;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v406);
          ++v314;
          v1 = v380;
        }
        while ( *(float *)&_Val > (float)v314 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v305 = LODWORD(v372) + 1;
      v418 = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v398);
    }
    v418 = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v398);
    v322 = 0;
    v372 = 0.0;
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v393,
        3,
        1);
      *(_DWORD *)&valueSwitch[44] = v322;
      v418 = 308;
      v323 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v393.gap10, "KERS_RECHARGE_SERIE_");
      std::wostream::operator<<(v323, *(_DWORD *)&valueSwitch[44]);
      v324 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &key);
      LOBYTE(v418) = 53;
      v325 = INIReader::hasSection(&ini, v324);
      LOBYTE(v418) = 52;
      v326 = v325;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      if ( !v326 )
        break;
      std::wstring::wstring(&key, L"PREFIX");
      LOBYTE(v418) = 54;
      v327 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &_Str);
      LOBYTE(v418) = 55;
      INIReader::getString(&ini, &_Right, v327, &key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Str);
      LOBYTE(v418) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&vname, L"START_INDEX");
      LOBYTE(v418) = 59;
      v328 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &v411);
      LOBYTE(v418) = 60;
      *(float *)&v376._Ptr = INIReader::getFloat(&ini, v328, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"END_INDEX");
      LOBYTE(v418) = 61;
      v329 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &v411);
      LOBYTE(v418) = 62;
      *(float *)&_Val = INIReader::getFloat(&ini, v329, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      std::wstring::wstring(&vname, L"NORM_MAX");
      LOBYTE(v418) = 63;
      v330 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &v411);
      LOBYTE(v418) = 64;
      *(float *)&v371 = INIReader::getFloat(&ini, v330, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      v331 = 0;
      std::wstring::wstring(&vname, L"INVERTED");
      LOBYTE(v418) = 65;
      v332 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &v411);
      LOBYTE(v418) = 66;
      v333 = INIReader::hasKey(&ini, v332, &vname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
      LOBYTE(v418) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      if ( v333 )
      {
        std::wstring::wstring(&vname, L"INVERTED");
        LOBYTE(v418) = 67;
        v334 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &v411);
        LOBYTE(v418) = 68;
        v331 = INIReader::getInt(&ini, v334, &vname) != 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v411);
        LOBYTE(v418) = 58;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
      }
      v142 = *(float *)&_Val < *(float *)&v376._Ptr;
      *(float *)&v369._Ptr = 0.0;
      v373 = *(float *)&v376._Ptr;
      *(float *)&v376._Ptr = *(float *)&v371 / (float)(*(float *)&_Val - *(float *)&v376._Ptr);
      if ( !v142 )
      {
        do
        {
          std::wstring::wstring(&vname, word_17BE9D8);
          LOBYTE(v418) = 69;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v393, &vname);
          LOBYTE(v418) = 58;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&vname);
          *(float *)&valueSwitch[44] = v373;
          v335 = std::operator<<<wchar_t>((std::wostream *)v393.gap10, &_Right);
          std::wostream::operator<<(v335);
          *(float *)&v336 = COERCE_FLOAT(operator new(100));
          v371 = v336;
          LOBYTE(v418) = 70;
          if ( *(float *)&v336 == 0.0 )
          {
            *(float *)&v337 = 0.0;
          }
          else
          {
            *(_DWORD *)&valueSwitch[44] = 0;
            *(_DWORD *)&valueSwitch[40] = -1082130432;
            *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&valueSwitch[36] = v369;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v393,
              (std::wstring *)&valueSwitch[12]);
            DigitalLed::DigitalLed(
              (DigitalLed *)v336,
              v1->car,
              *(std::wstring *)&valueSwitch[12],
              *(float *)&valueSwitch[36],
              *(float *)&valueSwitch[40],
              *(float *)&valueSwitch[44]);
          }
          v371 = v337;
          LOBYTE(v418) = 58;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v20, &v371);
          (*std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20))->type = KERS_RECHARGE;
          v338 = std::vector<DigitalLed *>::back((std::vector<DigitalLed *> *)v20);
          v339 = _Val;
          v340 = *v338;
          *(float *)&v369._Ptr = *(float *)&v376._Ptr + *(float *)&v369._Ptr;
          v341 = v373 + 1.0;
          v340->inverted = v331;
          v373 = v341;
        }
        while ( *(float *)&v339 >= v341 );
      }
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Right);
      v322 = LODWORD(v372) + 1;
      v418 = 4;
      ++LODWORD(v372);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v393);
    }
    v418 = 4;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v393);
    if ( !v1->game->graphics->videoSettings.ppHDREnabled )
    {
      std::vector<SetupTab *>::begin((std::vector<TyreCompoundDef> *)v20, &v369);
      std::vector<Mesh *>::end(
        (std::vector<TyreCompoundDef> *)v20,
        (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_Val);
      while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
                &v369,
                (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_Val) )
      {
        v342 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(&v369);
        v343 = v380;
        v344 = v342->index;
        v345 = (vec3f *)(v342->index + 8);
        *v345 = *GraphicsManager::getLDRColor(v380->game->graphics, (vec3f *)&v415, v345);
        *(vec3f *)(v344 + 20) = *GraphicsManager::getLDRColor(
                                   v343->game->graphics,
                                   (vec3f *)&v415.score,
                                   (const vec3f *)(v344 + 20));
        v346 = (vec3f *)(v344 + 32);
        v1 = v343;
        *v346 = *GraphicsManager::getLDRColor(v343->game->graphics, &c, v346);
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator++((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > *)&v369);
      }
      std::vector<SetupTab *>::begin((std::vector<TyreCompoundDef> *)&v1->items, &v369);
      std::vector<Mesh *>::end(
        (std::vector<TyreCompoundDef> *)&v1->items,
        (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_Val);
      while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
                &v369,
                (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_Val) )
      {
        v347 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(&v369);
        v348 = v347->index;
        vec3f::vec3f((vec3f *)&v376, *(float *)(v348 + 4), *(float *)(v348 + 8), *(float *)(v347->index + 12));
        vec3f::vec3f(&c, *(float *)(v348 + 20), *(float *)(v348 + 24), *(float *)(v348 + 28));
        v349 = (std::shared_ptr<Material> *)GraphicsManager::getLDRColor(
                                              v1->game->graphics,
                                              (vec3f *)&v415,
                                              (const vec3f *)&v376);
        v350 = v1->game;
        v376 = *v349;
        *(_DWORD *)excluded = v349[1]._Ptr;
        v351 = GraphicsManager::getLDRColor(v350->graphics, (vec3f *)&v415.score, &c);
        *(_DWORD *)&valueSwitch[44] = v352;
        *(_QWORD *)&c.x = *(_QWORD *)&v351->x;
        v353 = *(float *)(v348 + 16);
        c.z = v351->z;
        vec4f::vec4f((vec4f *)&_Right, (const vec3f *)&v376, v353);
        *(_DWORD *)&valueSwitch[44] = v354;
        *(__m128i *)(v348 + 4) = _mm_loadu_si128(v355);
        vec4f::vec4f((vec4f *)&vname, &c, *(float *)(v348 + 32));
        v357 = _mm_loadu_si128(v356);
        v358 = *(float **)(v348 + 52);
        *(__m128i *)(v348 + 20) = v357;
        if ( v358 )
        {
          vec3f::vec3f((vec3f *)&v411, v358[54], v358[55], v358[56]);
          v359 = v1->game;
          v376 = *v360;
          *(_DWORD *)excluded = v360[1]._Ptr;
          v361 = (std::shared_ptr<Material> *)GraphicsManager::getLDRColor(
                                                v359->graphics,
                                                (vec3f *)&_Str,
                                                (const vec3f *)&v376);
          v362 = *(_DWORD *)(v348 + 52);
          *(_DWORD *)&valueSwitch[44] = v363;
          v376 = *v361;
          *(_DWORD *)excluded = v361[1]._Ptr;
          vec4f::vec4f((vec4f *)&key, (const vec3f *)&v376, *(float *)(v362 + 228));
          *(__m128i *)(v362 + 216) = _mm_loadu_si128(v364);
        }
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator++((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Node *> > > *)&v369);
      }
    }
  }
LABEL_345:
  v418 = -1;
  INIReader::~INIReader(&ini);
}
void DigitalInstruments::update(DigitalInstruments *this, float deltaT)
{
  unsigned int v3; // esi
  DigitalItem **v4; // esi
  unsigned int v5; // ebx
  int v6; // edi
  DigitalLed **v7; // esi
  int v8; // edi
  unsigned int v9; // ebx

  v3 = Sim::getFocusedCarIndex(this->car->sim);
  if ( CarAvatar::getGuid(this->car) == v3 )
  {
    v4 = this->items._Myfirst;
    v5 = (unsigned int)((char *)this->items._Mylast - (char *)v4 + 3) >> 2;
    v6 = 0;
    if ( v4 > this->items._Mylast )
      v5 = 0;
    if ( v5 )
    {
      do
      {
        DigitalItem::update(*v4, deltaT);
        ++v6;
        ++v4;
      }
      while ( v6 != v5 );
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
        DigitalInstruments::initInstruments(this);
      }
    }
  }
}
