#include "drivermodel.h"
void DriverModel::DriverModel(DriverModel *this, CarAvatar *car, GraphicsManager *graphics, bool a_isHR)
{
  CarAvatar *v5; // edi
  unsigned int v6; // ebx
  Sim *v7; // eax
  const std::wstring *v8; // esi
  std::wstring *v9; // eax
  double v10; // st7
  bool v11; // cf
  Event<OnReplayStatusChanged> *v12; // ecx
  std::wstring *v13; // eax
  unsigned __int16 v14; // ax
  bool v15; // zf
  char v16; // al
  double v17; // st7
  double v18; // st7
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  Console *v28; // eax
  Console *v29; // eax
  Console *v30; // eax
  Console *v31; // eax
  std::wstring *v32; // eax
  const std::wstring *v33; // eax
  const std::wstring *v34; // eax
  const std::wstring *v35; // eax
  const std::wstring *v36; // eax
  std::wstring *v37; // esi
  std::wstring *v38; // eax
  std::wstring *v39; // eax
  const std::wstring *v40; // eax
  bool v41; // bl
  const std::wstring *v42; // eax
  const std::wstring *v43; // eax
  const std::wstring *v44; // eax
  const wchar_t *v45; // eax
  std::wstring *v46; // eax
  Node *v47; // eax
  const std::wstring *v48; // eax
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  CarAudioFMOD *v51; // eax
  AnimationPlayer *v52; // eax
  double v53; // st7
  std::wstring *v54; // eax
  std::wstring *v55; // eax
  std::wstring *v56; // eax
  std::wstring *v57; // eax
  std::wstring *v58; // eax
  std::wstring *v59; // eax
  std::wstring *v60; // eax
  CarAudioFMOD *v61; // eax
  AnimationPlayer *v62; // eax
  Node *v63; // ecx
  CarAudioFMOD *v64; // esi
  Node *v65; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v66; // ecx
  Node *v67; // ecx
  CarAudioFMOD *v68; // esi
  Node *v69; // eax
  Node *v70; // edi
  std::vector<Node *> *v71; // esi
  int v72; // ecx
  int v73; // edx
  char *v74; // ecx
  unsigned int v75; // esi
  Node *v76; // edi
  int v77; // eax
  Node *v78; // esi
  AnimationBlender *v79; // edi
  CarAudioFMOD *v80; // eax
  AnimationPlayer *v81; // eax
  Node *v82; // ecx
  CarAudioFMOD *v83; // esi
  Node *v84; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v85; // ecx
  Node *v86; // ecx
  CarAudioFMOD *v87; // esi
  Node *v88; // eax
  Node *v89; // edi
  std::vector<Node *> *v90; // esi
  int v91; // ecx
  Node **v92; // edx
  Node **v93; // eax
  int v94; // esi
  unsigned int v95; // edi
  Node *v96; // ecx
  int v97; // eax
  Node *v98; // esi
  AnimationBlender *v99; // ecx
  Node *v100; // ecx
  int v101; // eax
  Node *v102; // ecx
  int v103; // eax
  int v104; // eax
  double v105; // st7
  double v106; // st7
  double v107; // st7
  double v108; // st7
  Node *v109; // ecx
  Node *v110; // eax
  Node *v111; // eax
  int i; // esi
  std::wostream *v113; // eax
  const std::wstring *v114; // eax
  char v115; // al
  const std::wstring *v116; // eax
  Node *v117; // eax
  bool v118; // al
  bool v119; // bl
  HeadMovement *v120; // esi
  DriverModel::{ctor}::__l138::<lambda_2780e4c819495c962915f982c35600b3> *v121; // eax
  Sim *v122; // ecx
  Console *v123; // eax
  bool v124; // al
  int v125; // ebx
  int v126; // ebx
  bool v127; // al
  Sim *v128; // ecx
  Console *v129; // eax
  Sim *v130; // ecx
  Console *v131; // eax
  Sim *v132; // ecx
  Console *v133; // eax
  Sim *v134; // ecx
  Console *v135; // eax
  Sim *v136; // ecx
  Console *v137; // eax
  std::wstring v138; // [esp-3Ch] [ebp-5A8h] BYREF
  _BYTE filter[72]; // [esp-24h] [ebp-590h] BYREF
  char v140; // [esp+43h] [ebp-529h]
  Node *n; // [esp+44h] [ebp-528h]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v142; // [esp+48h] [ebp-524h] BYREF
  Node *v143; // [esp+4Ch] [ebp-520h]
  GraphicsManager *v144[2]; // [esp+50h] [ebp-51Ch] BYREF
  CarAvatar *v145; // [esp+58h] [ebp-514h]
  _BYTE *v146; // [esp+5Ch] [ebp-510h]
  _BYTE *v147; // [esp+60h] [ebp-50Ch]
  DriverModel *v148; // [esp+64h] [ebp-508h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v149; // [esp+68h] [ebp-504h] BYREF
  std::ifstream in; // [esp+118h] [ebp-454h] BYREF
  std::wstring custom_skin; // [esp+1D0h] [ebp-39Ch] BYREF
  Animation ani; // [esp+1E8h] [ebp-384h] BYREF
  int v153; // [esp+1F8h] [ebp-374h]
  unsigned int v154; // [esp+1FCh] [ebp-370h]
  std::wstring filename; // [esp+200h] [ebp-36Ch] BYREF
  std::wstring key; // [esp+218h] [ebp-354h] BYREF
  std::wstring s; // [esp+230h] [ebp-33Ch] BYREF
  std::wstring v158; // [esp+248h] [ebp-324h] BYREF
  std::wstring ob; // [esp+260h] [ebp-30Ch] BYREF
  std::wstring v160; // [esp+278h] [ebp-2F4h] BYREF
  std::wstring driverSkin; // [esp+290h] [ebp-2DCh] BYREF
  std::wstring down_shift_filename; // [esp+2A8h] [ebp-2C4h] BYREF
  std::wstring v163; // [esp+2C0h] [ebp-2ACh] BYREF
  std::wstring v164; // [esp+2D8h] [ebp-294h] BYREF
  INIReader ini; // [esp+2F0h] [ebp-27Ch] BYREF
  std::wstring _Left; // [esp+334h] [ebp-238h] BYREF
  std::wstring v167; // [esp+34Ch] [ebp-220h] BYREF
  std::wstring section; // [esp+364h] [ebp-208h] BYREF
  std::wstring base_pos_filename; // [esp+37Ch] [ebp-1F0h] BYREF
  std::wstring result; // [esp+394h] [ebp-1D8h] BYREF
  std::wstring v171; // [esp+3ACh] [ebp-1C0h] BYREF
  std::wstring shift_filename; // [esp+3C4h] [ebp-1A8h] BYREF
  INIReader iniS; // [esp+3DCh] [ebp-190h] BYREF
  std::wstring steer_filename; // [esp+420h] [ebp-14Ch] BYREF
  std::wstring dataPath; // [esp+438h] [ebp-134h] BYREF
  std::wstring inifn; // [esp+450h] [ebp-11Ch] BYREF
  KN5IO kn; // [esp+468h] [ebp-104h] BYREF
  INIReader assettoCorsaIni; // [esp+4D4h] [ebp-98h] BYREF
  INIReader r; // [esp+518h] [ebp-54h] BYREF
  int v180; // [esp+568h] [ebp-4h]

  v5 = car;
  v6 = 0;
  n = 0;
  v144[0] = graphics;
  v7 = car->sim;
  v8 = &car->unixName;
  v148 = this;
  v145 = car;
  v143 = 0;
  *(_DWORD *)&filter[68] = v7->game;
  n = (Node *)&car->unixName;
  std::operator+<wchar_t>((std::wstring *)&filter[44], L"DRIVER_", &car->unixName);
  GameObject::GameObject(this, *(std::wstring *)&filter[44], *(Game **)&filter[68]);
  this->__vftable = (DriverModel_vtbl *)&DriverModel::`vftable';
  this->headMovement.maxG = 1.0;
  this->headMovement.rollMaxDeg = -12.0;
  this->headMovement.pitchMaxDeg = -10.0;
  this->headMovement.yawMaxDeg = 20.0;
  this->headMovement.filter = 0.15000001;
  v180 = 0;
  this->driverIniVersion = 1;
  this->debugHideHeadMode = 0;
  std::vector<MaterialVar *>::vector<MaterialVar *>(&this->shiftBlender);
  this->forceHidden = 0;
  mat44f::mat44f(&this->nextRestMatrix);
  this->localAcc.x = 0.0;
  this->localAcc.y = 0.0;
  this->localAcc.z = 0.0;
  this->headHideNodes._Myfirst = 0;
  this->headHideNodes._Mylast = 0;
  this->headHideNodes._Myend = 0;
  this->shiftTimings.blendTimeMult = 0.5;
  this->shiftTimings.positiveTimeMult = 1.0;
  this->shiftTimings.staticTimeMult = 0.5;
  this->shiftTimings.negativeTimeMult = 1.0;
  this->isHR = a_isHR;
  this->gearChangeTimer = DOUBLE_0_3;
  *(_DWORD *)&filter[68] = 13;
  *(_DWORD *)&filter[64] = L"content/cars/";
  LOBYTE(v180) = 2;
  this->shiftHandsInverted = 0;
  this->lastGear = 0;
  this->gearTimer = 0.0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, *(const wchar_t **)&filter[64], *(unsigned int *)&filter[68]);
  LOBYTE(v180) = 3;
  v9 = std::operator+<wchar_t>(&result, &_Left, &car->unixName);
  LOBYTE(v180) = 4;
  std::operator+<wchar_t>(&dataPath, v9, L"/data/drivetrain.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v180) = 7;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  _Left._Mysize = 0;
  CarAvatar::openINI(car, &r, &dataPath);
  LOBYTE(v180) = 8;
  if ( r.ready )
  {
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"CHANGE_DN_TIME", 0xEu);
    LOBYTE(v180) = 9;
    v154 = 7;
    v153 = 0;
    LOWORD(ani.sets._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&ani, L"GEARBOX", 7u);
    LOBYTE(v180) = 10;
    v10 = INIReader::getFloat(&r, (const std::wstring *)&ani, &filename);
    v11 = v154 < 8;
    this->gearChangeTimer = v10 * 0.001;
    if ( !v11 )
      operator delete(ani.sets._Myfirst);
    v154 = 7;
    v153 = 0;
    LOWORD(ani.sets._Myfirst) = 0;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
  *(_DWORD *)&filter[68] = this;
  this->shiftDownPlayer = 0;
  this->paddleShifts = 0;
  this->paddleShiftStatus = ePaddleNoShifting;
  this->headAnimationTime = 0.0;
  this->headAnimationMult = 5.0;
  this->headMaxRAD = 0.64999998;
  *(_DWORD *)&filter[44] = &std::_Func_impl<std::_Callable_obj<_lambda_99b8e5248e5499b81401c3852418c453_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&filter[48] = this;
  *(_DWORD *)&filter[60] = &filter[44];
  v12 = &car->sim->evOnReplayStatusChanged;
  LOBYTE(v180) = 8;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v12,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&filter[44],
    *(void **)&filter[68]);
  *(GraphicsManager **)&filter[68] = v144[0];
  this->oldRpm = 0.0;
  this->lockAnimation = 0;
  this->animationEnabled = 1;
  KN5IO::KN5IO(&kn, *(GraphicsManager **)&filter[68]);
  *(_DWORD *)&filter[68] = 13;
  LOBYTE(v180) = 12;
  *(_DWORD *)&filter[64] = L"content/cars/";
  this->car = car;
  this->preLoadRPM = 0;
  this->steerPlayer = 0;
  this->shiftPlayer = 0;
  this->preLoadShift = 0;
  v167._Myres = 7;
  v167._Mysize = 0;
  v167._Bx._Buf[0] = 0;
  std::wstring::assign(&v167, *(const wchar_t **)&filter[64], *(unsigned int *)&filter[68]);
  LOBYTE(v180) = 13;
  v13 = std::operator+<wchar_t>(&v171, &v167, v8);
  LOBYTE(v180) = 14;
  std::operator+<wchar_t>(&inifn, v13, L"/data/driver3d.ini");
  if ( v171._Myres >= 8 )
    operator delete(v171._Bx._Ptr);
  v171._Myres = 7;
  v171._Mysize = 0;
  v171._Bx._Buf[0] = 0;
  LOBYTE(v180) = 17;
  if ( v167._Myres >= 8 )
    operator delete(v167._Bx._Ptr);
  v167._Myres = 7;
  v167._Bx._Buf[0] = 0;
  this->shiftAnimationStatus = eNoShift;
  v167._Mysize = 0;
  CarAvatar::openINI(car, &ini, &inifn);
  LOBYTE(v180) = 18;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"VERSION", 7u);
  LOBYTE(v180) = 19;
  v154 = 7;
  v153 = 0;
  LOWORD(ani.sets._Myfirst) = 0;
  std::wstring::assign((std::wstring *)&ani, L"HEADER", 6u);
  LOBYTE(v180) = 20;
  v140 = INIReader::hasKey(&ini, (const std::wstring *)&ani, &filename);
  if ( v154 >= 8 )
    operator delete(ani.sets._Myfirst);
  v154 = 7;
  v153 = 0;
  LOWORD(ani.sets._Myfirst) = 0;
  LOBYTE(v180) = 18;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  if ( v140 )
  {
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"VERSION", 7u);
    LOBYTE(v180) = 21;
    v154 = 7;
    v153 = 0;
    LOWORD(ani.sets._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&ani, L"HEADER", 6u);
    LOBYTE(v180) = 22;
    v14 = INIReader::getInt(&ini, (const std::wstring *)&ani, &filename);
    v11 = v154 < 8;
    this->driverIniVersion = v14;
    if ( !v11 )
      operator delete(ani.sets._Myfirst);
    v154 = 7;
    v153 = 0;
    LOWORD(ani.sets._Myfirst) = 0;
    LOBYTE(v180) = 18;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"INVERT_SHIFTING_HANDS", 0x15u);
  LOBYTE(v180) = 23;
  v154 = 7;
  v153 = 0;
  LOWORD(ani.sets._Myfirst) = 0;
  std::wstring::assign((std::wstring *)&ani, L"SHIFT_ANIMATION", 0xFu);
  LOBYTE(v180) = 24;
  v140 = INIReader::getInt(&ini, (const std::wstring *)&ani, &filename) > 0;
  if ( v154 >= 8 )
    operator delete(ani.sets._Myfirst);
  v154 = 7;
  v153 = 0;
  LOWORD(ani.sets._Myfirst) = 0;
  LOBYTE(v180) = 18;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  if ( v140 )
    this->shiftHandsInverted = 1;
  v15 = !ini.ready;
  this->driver_root = 0;
  if ( v15 )
  {
    v120 = &this->headMovement;
    goto LABEL_222;
  }
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"HEAD_ANIMATION", 0xEu);
  LOBYTE(v180) = 25;
  v16 = INIReader::hasSection(&ini, &filename);
  v140 = v16;
  LOBYTE(v180) = 18;
  if ( filename._Myres >= 8 )
  {
    operator delete(filename._Bx._Ptr);
    v16 = v140;
  }
  if ( v16 )
  {
    std::wstring::wstring(&custom_skin, L"SPEED");
    LOBYTE(v180) = 26;
    std::wstring::wstring(&filename, L"HEAD_ANIMATION");
    LOBYTE(v180) = 27;
    v17 = INIReader::getFloat(&ini, &filename, &custom_skin);
    v11 = filename._Myres < 8;
    this->headAnimationMult = v17;
    if ( !v11 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    LOBYTE(v180) = 18;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    std::wstring::wstring(&custom_skin, L"MAX_DEGREES");
    LOBYTE(v180) = 28;
    std::wstring::wstring(&filename, L"HEAD_ANIMATION");
    LOBYTE(v180) = 29;
    v18 = INIReader::getFloat(&ini, &filename, &custom_skin);
    v11 = filename._Myres < 8;
    this->headMaxRAD = v18 * 0.017453;
    if ( !v11 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    LOBYTE(v180) = 18;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
  }
  v19 = std::operator+<wchar_t>(&v164, L"content/cars/", v8);
  LOBYTE(v180) = 30;
  std::operator+<wchar_t>(&base_pos_filename, v19, L"/driver_base_pos.knh");
  LOBYTE(v180) = 32;
  if ( v164._Myres >= 8 )
    operator delete(v164._Bx._Ptr);
  v164._Myres = 7;
  v164._Bx._Buf[0] = 0;
  v164._Mysize = 0;
  if ( Path::fileExists(0, &base_pos_filename, 0) )
  {
    _printf("USING DEFAULT DRIVER SYSTEM\n");
    std::wstring::wstring(&key, L"NAME");
    LOBYTE(v180) = 33;
    std::wstring::wstring(&section, L"MODEL");
    LOBYTE(v180) = 34;
    v20 = INIReader::getString(&ini, &driverSkin, &section, &key);
    LOBYTE(v180) = 35;
    v21 = std::operator+<wchar_t>(&down_shift_filename, L"content/driver/", v20);
    LOBYTE(v180) = 36;
    std::operator+<wchar_t>(&filename, v21, L".kn5");
    if ( down_shift_filename._Myres >= 8 )
      operator delete(down_shift_filename._Bx._Ptr);
    down_shift_filename._Myres = 7;
    down_shift_filename._Mysize = 0;
    down_shift_filename._Bx._Buf[0] = 0;
    if ( driverSkin._Myres >= 8 )
      operator delete(driverSkin._Bx._Ptr);
    driverSkin._Myres = 7;
    driverSkin._Mysize = 0;
    driverSkin._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v180) = 41;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( !this->isHR )
    {
      std::wstring::wstring(&v158, L"NAME");
      LOBYTE(v180) = 42;
      std::wstring::wstring(&custom_skin, L"MODEL");
      LOBYTE(v180) = 43;
      v22 = INIReader::getString(&ini, &v160, &custom_skin, &v158);
      LOBYTE(v180) = 44;
      v23 = std::operator+<wchar_t>(&ob, L"content/driver/", v22);
      LOBYTE(v180) = 45;
      v24 = std::operator+<wchar_t>(&s, v23, L"_B.kn5");
      std::wstring::operator=(&filename, v24);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&custom_skin);
      LOBYTE(v180) = 41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
    }
    if ( !Path::fileExists(0, &filename, 0) )
    {
      if ( this->isHR )
      {
        v144[1] = (GraphicsManager *)&filter[48];
        std::wstring::wstring((std::wstring *)&filter[48], L"\n");
        LOBYTE(v180) = 50;
        v147 = &filter[24];
        std::wstring::wstring((std::wstring *)&filter[24], L"' not found");
        LOBYTE(v180) = 51;
        v146 = filter;
        std::wstring::wstring((std::wstring *)filter, &filename);
        LOBYTE(v180) = 52;
        v142.__this = (CarAudioFMOD *)&v138;
        std::wstring::wstring(&v138, L"Error: driver file '");
        LOBYTE(v180) = 53;
        v28 = Console::singleton();
        LOBYTE(v180) = 52;
        v29 = Console::operator<<(v28, v138);
        LOBYTE(v180) = 51;
        v30 = Console::operator<<(v29, *(std::wstring *)filter);
        LOBYTE(v180) = 50;
        v31 = Console::operator<<(v30, *(std::wstring *)&filter[24]);
        LOBYTE(v180) = 41;
        Console::operator<<(v31, *(std::wstring *)&filter[48]);
      }
      else
      {
        *(_DWORD *)&filter[68] = L"NAME";
        this->isHR = 1;
        std::wstring::wstring(&v158, *(const wchar_t **)&filter[68]);
        LOBYTE(v180) = 46;
        std::wstring::wstring(&custom_skin, L"MODEL");
        LOBYTE(v180) = 47;
        v25 = INIReader::getString(&ini, &v160, &custom_skin, &v158);
        LOBYTE(v180) = 48;
        v26 = std::operator+<wchar_t>(&ob, L"content/driver/", v25);
        LOBYTE(v180) = 49;
        v27 = std::operator+<wchar_t>(&s, v26, L".kn5");
        std::wstring::operator=(&filename, v27);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&custom_skin);
        LOBYTE(v180) = 41;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
      }
    }
    v140 = 1;
    BYTE1(v6) = 0;
    if ( !CarAvatar::getGuid(car) )
    {
      v32 = Path::getDocumentPath(&s);
      LOBYTE(v180) = 54;
      std::operator+<wchar_t>(&custom_skin, v32, L"/Assetto Corsa/cfg/driverskin.ini");
      LOBYTE(v180) = 56;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
      if ( Path::fileExists(v6, &custom_skin, 0) )
      {
        INIReader::INIReader(&iniS, &custom_skin);
        LOBYTE(v180) = 57;
        if ( iniS.ready )
        {
          std::wstring::wstring(&v160, L"NAME");
          LOBYTE(v180) = 58;
          std::wstring::wstring(&v158, L"MODEL");
          LOBYTE(v180) = 59;
          v33 = INIReader::getString(&ini, &ob, &v158, &v160);
          LOBYTE(v180) = 60;
          LOBYTE(v6) = INIReader::hasSection(&iniS, v33);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
          LOBYTE(v180) = 57;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
          if ( (_BYTE)v6 )
          {
            std::wstring::wstring(&ob, L"SUIT");
            LOBYTE(v180) = 61;
            std::wstring::wstring(&v160, L"NAME");
            LOBYTE(v180) = 62;
            std::wstring::wstring(&v158, L"MODEL");
            LOBYTE(v180) = 63;
            v34 = INIReader::getString(&ini, &v163, &v158, &v160);
            LOBYTE(v180) = 64;
            DriverModel::loadDriverSkin(this, &kn, &iniS, v34, &ob);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
            LOBYTE(v180) = 57;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
            std::wstring::wstring(&v160, L"GLOVES");
            LOBYTE(v180) = 65;
            std::wstring::wstring(&v158, L"NAME");
            LOBYTE(v180) = 66;
            std::wstring::wstring(&ob, L"MODEL");
            LOBYTE(v180) = 67;
            v35 = INIReader::getString(&ini, &v163, &ob, &v158);
            LOBYTE(v180) = 68;
            DriverModel::loadDriverSkin(this, &kn, &iniS, v35, &v160);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
            LOBYTE(v180) = 57;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
            std::wstring::wstring(&v160, L"HELMET");
            LOBYTE(v180) = 69;
            std::wstring::wstring(&v158, L"NAME");
            LOBYTE(v180) = 70;
            std::wstring::wstring(&ob, L"MODEL");
            LOBYTE(v180) = 71;
            v36 = INIReader::getString(&ini, &v163, &ob, &v158);
            LOBYTE(v180) = 72;
            DriverModel::loadDriverSkin(this, &kn, &iniS, v36, &v160);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
            BYTE1(v6) = 1;
            v140 = 0;
          }
        }
        LOBYTE(v180) = 56;
        INIReader::~INIReader(&iniS);
      }
      LOBYTE(v180) = 41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&custom_skin);
    }
    v37 = CarAvatar::getCurrentSkin(car, &custom_skin);
    LOBYTE(v180) = 73;
    v38 = std::operator+<wchar_t>(&v158, L"content/cars/", &car->unixName);
    LOBYTE(v180) = 74;
    v39 = std::operator+<wchar_t>(&v160, v38, L"/skins/");
    LOBYTE(v180) = 75;
    std::operator+<wchar_t>((std::wstring *)&ani, v39, v37);
    if ( v160._Myres >= 8 )
      operator delete(v160._Bx._Ptr);
    v160._Myres = 7;
    v160._Mysize = 0;
    v160._Bx._Buf[0] = 0;
    if ( v158._Myres >= 8 )
      operator delete(v158._Bx._Ptr);
    v158._Myres = 7;
    v158._Mysize = 0;
    v158._Bx._Buf[0] = 0;
    LOBYTE(v180) = 79;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    custom_skin._Myres = 7;
    custom_skin._Mysize = 0;
    custom_skin._Bx._Buf[0] = 0;
    if ( !BYTE1(v6) )
    {
      std::operator+<wchar_t>(&driverSkin, (const std::wstring *)&ani, L"/skin.ini");
      LOBYTE(v180) = 80;
      if ( Path::fileExists(v6, &driverSkin, 0) )
      {
        CarAvatar::openINI(car, &iniS, &driverSkin);
        LOBYTE(v180) = 81;
        if ( iniS.ready )
        {
          std::wstring::wstring(&down_shift_filename, L"NAME");
          LOBYTE(v180) = 82;
          std::wstring::wstring(&ob, L"MODEL");
          LOBYTE(v180) = 83;
          v40 = INIReader::getString(&ini, &v163, &ob, &down_shift_filename);
          LOBYTE(v180) = 84;
          v41 = INIReader::hasSection(&iniS, v40);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
          LOBYTE(v180) = 81;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&down_shift_filename);
          if ( v41 )
          {
            std::wstring::wstring(&key, L"SUIT");
            LOBYTE(v180) = 85;
            std::wstring::wstring(&down_shift_filename, L"NAME");
            LOBYTE(v180) = 86;
            std::wstring::wstring(&ob, L"MODEL");
            LOBYTE(v180) = 87;
            v42 = INIReader::getString(&ini, &v163, &ob, &down_shift_filename);
            LOBYTE(v180) = 88;
            DriverModel::loadDriverSkin(this, &kn, &iniS, v42, &key);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&down_shift_filename);
            LOBYTE(v180) = 81;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
            std::wstring::wstring(&section, L"GLOVES");
            LOBYTE(v180) = 89;
            std::wstring::wstring(&down_shift_filename, L"NAME");
            LOBYTE(v180) = 90;
            std::wstring::wstring(&ob, L"MODEL");
            LOBYTE(v180) = 91;
            v43 = INIReader::getString(&ini, &v163, &ob, &down_shift_filename);
            LOBYTE(v180) = 92;
            DriverModel::loadDriverSkin(this, &kn, &iniS, v43, &section);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&down_shift_filename);
            LOBYTE(v180) = 81;
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
            std::wstring::wstring(&s, L"HELMET");
            LOBYTE(v180) = 93;
            std::wstring::wstring(&down_shift_filename, L"NAME");
            LOBYTE(v180) = 94;
            std::wstring::wstring(&ob, L"MODEL");
            LOBYTE(v180) = 95;
            v44 = INIReader::getString(&ini, &v163, &ob, &down_shift_filename);
            LOBYTE(v180) = 96;
            DriverModel::loadDriverSkin(this, &kn, &iniS, v44, &s);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&down_shift_filename);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
            v140 = 0;
          }
        }
        LOBYTE(v180) = 80;
        INIReader::~INIReader(&iniS);
      }
      LOBYTE(v180) = 79;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&driverSkin);
    }
    if ( v140 )
    {
      v45 = (const wchar_t *)&ani;
      if ( v154 >= 8 )
        v45 = ani.sets._Myfirst->targetName._Bx._Buf;
      std::wstring::wstring(&s, v45);
      LOBYTE(v180) = 97;
      KN5IO::addTextureFolder(&kn, &s);
      LOBYTE(v180) = 79;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    }
    v46 = &filename;
    if ( filename._Myres >= 8 )
      v46 = (std::wstring *)filename._Bx._Ptr;
    std::wstring::wstring(&driverSkin, v46->_Bx._Buf);
    LOBYTE(v180) = 98;
    v47 = KN5IO::load(&kn, &driverSkin);
    v11 = driverSkin._Myres < 8;
    this->driver_root = v47;
    LOBYTE(v180) = 79;
    if ( !v11 )
      operator delete(driverSkin._Bx._Ptr);
    GraphicsManager::compile(v144[0], this->driver_root);
    v48 = Path::getPlatformSpecificPath(&driverSkin, &base_pos_filename);
    LOBYTE(v180) = 99;
    std::ifstream::ifstream(&in, v48, 32, 64, 1);
    LOBYTE(v180) = 101;
    if ( driverSkin._Myres >= 8 )
      operator delete(driverSkin._Bx._Ptr);
    driverSkin._Myres = 7;
    driverSkin._Bx._Buf[0] = 0;
    *(_DWORD *)&filter[68] = this->isHR;
    *(_DWORD *)&filter[64] = this->driver_root;
    driverSkin._Mysize = 0;
    loadDriverBasePos(&in, *(Node **)&filter[64], filter[68]);
    std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
    std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
    if ( v154 >= 8 )
      operator delete(ani.sets._Myfirst);
    v154 = 7;
    v153 = 0;
    LOWORD(ani.sets._Myfirst) = 0;
    LOBYTE(v180) = 32;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    v8 = (const std::wstring *)n;
    v6 = (unsigned int)v143;
  }
  std::wstring::wstring(&v158, L"content/cars/");
  LOBYTE(v180) = 102;
  v50 = std::operator+<wchar_t>(&custom_skin, v49, v8);
  LOBYTE(v180) = 103;
  std::operator+<wchar_t>(&steer_filename, v50, L"/animations/steer.ksanim");
  if ( custom_skin._Myres >= 8 )
    operator delete(custom_skin._Bx._Ptr);
  custom_skin._Myres = 7;
  custom_skin._Mysize = 0;
  custom_skin._Bx._Buf[0] = 0;
  LOBYTE(v180) = 106;
  if ( v158._Myres >= 8 )
    operator delete(v158._Bx._Ptr);
  v158._Myres = 7;
  v158._Bx._Buf[0] = 0;
  v158._Mysize = 0;
  if ( Path::fileExists(v6, &steer_filename, 0) )
  {
    std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&ani);
    LOBYTE(v180) = 107;
    Animation::load(&ani, &steer_filename);
    v51 = (CarAudioFMOD *)operator new(28);
    v142.__this = v51;
    LOBYTE(v180) = 108;
    if ( v51 )
      AnimationPlayer::AnimationPlayer((AnimationPlayer *)v51, &ani, this->driver_root, eAllNodes);
    else
      v52 = 0;
    *(_DWORD *)&filter[68] = L"LOCK";
    LOBYTE(v180) = 107;
    this->steerPlayer = v52;
    std::wstring::wstring(&v160, *(const wchar_t **)&filter[68]);
    LOBYTE(v180) = 109;
    std::wstring::wstring(&key, L"STEER_ANIMATION");
    LOBYTE(v180) = 110;
    v53 = INIReader::getFloat(&ini, &key, &v160);
    v11 = key._Myres < 8;
    this->animationLock = v53;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v160._Myres >= 8 )
      operator delete(v160._Bx._Ptr);
    LOBYTE(v180) = 106;
    std::vector<AnimationSet>::_Tidy(&ani);
  }
  std::wstring::wstring(&driverSkin, L"content/cars/");
  LOBYTE(v180) = 111;
  v55 = std::operator+<wchar_t>(&v160, v54, v8);
  LOBYTE(v180) = 112;
  std::operator+<wchar_t>(&shift_filename, v55, L"/animations/shift.ksanim");
  if ( v160._Myres >= 8 )
    operator delete(v160._Bx._Ptr);
  v160._Myres = 7;
  v160._Mysize = 0;
  v160._Bx._Buf[0] = 0;
  LOBYTE(v180) = 115;
  if ( driverSkin._Myres >= 8 )
    operator delete(driverSkin._Bx._Ptr);
  driverSkin._Myres = 7;
  driverSkin._Bx._Buf[0] = 0;
  driverSkin._Mysize = 0;
  if ( Path::fileExists(v6, &shift_filename, 0) )
  {
    this->shiftDownPlayer = 0;
    v79 = &this->shiftBlender;
    goto LABEL_144;
  }
  std::wstring::wstring(&s, L"content/cars/");
  LOBYTE(v180) = 116;
  v57 = std::operator+<wchar_t>(&v158, v56, v8);
  LOBYTE(v180) = 117;
  v58 = std::operator+<wchar_t>(&custom_skin, v57, L"/animations/shift_up.ksanim");
  std::wstring::operator=(&shift_filename, v58);
  if ( custom_skin._Myres >= 8 )
    operator delete(custom_skin._Bx._Ptr);
  custom_skin._Myres = 7;
  custom_skin._Mysize = 0;
  custom_skin._Bx._Buf[0] = 0;
  if ( v158._Myres >= 8 )
    operator delete(v158._Bx._Ptr);
  v158._Myres = 7;
  v158._Mysize = 0;
  v158._Bx._Buf[0] = 0;
  LOBYTE(v180) = 115;
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  std::wstring::wstring(&v158, L"content/cars/");
  LOBYTE(v180) = 118;
  v60 = std::operator+<wchar_t>(&custom_skin, v59, v8);
  LOBYTE(v180) = 119;
  std::operator+<wchar_t>(&down_shift_filename, v60, L"/animations/shift_dw.ksanim");
  if ( custom_skin._Myres >= 8 )
    operator delete(custom_skin._Bx._Ptr);
  custom_skin._Myres = 7;
  custom_skin._Mysize = 0;
  custom_skin._Bx._Buf[0] = 0;
  LOBYTE(v180) = 122;
  if ( v158._Myres >= 8 )
    operator delete(v158._Bx._Ptr);
  v158._Myres = 7;
  v158._Mysize = 0;
  v158._Bx._Buf[0] = 0;
  std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&ani);
  LOBYTE(v180) = 123;
  Animation::load(&ani, &down_shift_filename);
  v61 = (CarAudioFMOD *)operator new(28);
  v142.__this = v61;
  LOBYTE(v180) = 124;
  if ( v61 )
    AnimationPlayer::AnimationPlayer((AnimationPlayer *)v61, &ani, this->driver_root, eAllNodes);
  else
    v62 = 0;
  v15 = !this->shiftHandsInverted;
  LOBYTE(v180) = 123;
  this->shiftDownPlayer = v62;
  if ( v15 )
  {
    std::wstring::wstring(&v164, L"DRIVER:RIG_HAND_L");
    v67 = this->driver_root;
    LOBYTE(v180) = -127;
    v143 = v67->findChildByName(v67, &v164, 1);
    LOBYTE(v180) = 123;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v164);
    v68 = (CarAudioFMOD *)operator new(188);
    v142.__this = v68;
    LOBYTE(v180) = -126;
    if ( v68 )
    {
      std::wstring::wstring(&key, L"DRIVER:FINGERS_L");
      LOBYTE(v180) = -125;
      v6 = 2;
      n = (Node *)2;
      Node::Node((Node *)v68, &key);
      n = v69;
    }
    else
    {
      n = 0;
    }
    v180 = 123;
    if ( (v6 & 2) == 0 )
      goto LABEL_136;
    v6 &= 0xFFFFFFFD;
    v66 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
  }
  else
  {
    std::wstring::wstring(&s, L"DRIVER:RIG_HAND_R");
    v63 = this->driver_root;
    LOBYTE(v180) = 125;
    v143 = v63->findChildByName(v63, &s, 1);
    LOBYTE(v180) = 123;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    v64 = (CarAudioFMOD *)operator new(188);
    v142.__this = v64;
    LOBYTE(v180) = 126;
    if ( v64 )
    {
      std::wstring::wstring(&ob, L"DRIVER:FINGERS_R");
      LOBYTE(v180) = 127;
      v6 = 1;
      n = (Node *)1;
      Node::Node((Node *)v64, &ob);
      n = v65;
    }
    else
    {
      n = 0;
    }
    v180 = 123;
    if ( (v6 & 1) == 0 )
      goto LABEL_136;
    v6 &= 0xFFFFFFFE;
    v66 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob;
  }
  std::wstring::~wstring(v66);
LABEL_136:
  v70 = n;
  v71 = &v143->nodes;
  std::vector<int>::operator=((std::vector<unsigned int> *)&n->nodes, (const std::vector<unsigned int> *)&v143->nodes);
  std::_Container_base0::_Orphan_all(v71);
  v72 = (int)v143;
  v71->_Mylast = v71->_Myfirst;
  (*(void (**)(int, Node *))(*(_DWORD *)v72 + 4))(v72, v70);
  v73 = 0;
  v74 = (char *)v70->nodes._Myfirst;
  v75 = (unsigned int)((char *)v70->nodes._Mylast - v74 + 3) >> 2;
  if ( (Node **)v74 > v70->nodes._Mylast )
    v75 = 0;
  if ( v75 )
  {
    v76 = n;
    do
    {
      v77 = *(_DWORD *)v74;
      v74 += 4;
      ++v73;
      *(_DWORD *)(v77 + 148) = v76;
    }
    while ( v73 != v75 );
  }
  v78 = n;
  v79 = &this->shiftBlender;
  AnimationBlender::addTargetNode(&this->shiftBlender, n, 1);
  AnimationPlayer::activateNodes(this->shiftDownPlayer, v78);
  this->paddleShifts = 1;
  LOBYTE(v180) = 122;
  std::vector<AnimationSet>::_Tidy(&ani);
  LOBYTE(v180) = 115;
  if ( down_shift_filename._Myres >= 8 )
    operator delete(down_shift_filename._Bx._Ptr);
LABEL_144:
  if ( Path::fileExists(v6, &shift_filename, 0) )
  {
    std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&ani);
    LOBYTE(v180) = -123;
    Animation::load(&ani, &shift_filename);
    v80 = (CarAudioFMOD *)operator new(28);
    v142.__this = v80;
    LOBYTE(v180) = -122;
    if ( v80 )
      AnimationPlayer::AnimationPlayer((AnimationPlayer *)v80, &ani, this->driver_root, eAllNodes);
    else
      v81 = 0;
    v15 = !this->paddleShifts;
    LOBYTE(v180) = -123;
    this->shiftPlayer = v81;
    if ( v15 )
    {
      if ( this->shiftHandsInverted )
      {
        std::wstring::wstring(&s, L"DRIVER:RIG_Clave_L");
        v100 = this->driver_root;
        LOBYTE(v180) = -113;
        v101 = (int)v100->findChildByName(v100, &s, 1);
        LOBYTE(v180) = -123;
        v98 = (Node *)v101;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
        if ( !v98 )
          _printf("ERROR: COULDN'T FIND DRIVER:RIG_Clave_L\n");
      }
      else
      {
        std::wstring::wstring(&s, L"DRIVER:RIG_Clave_R");
        v102 = this->driver_root;
        LOBYTE(v180) = -112;
        v103 = (int)v102->findChildByName(v102, &s, 1);
        LOBYTE(v180) = -123;
        v98 = (Node *)v103;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
        if ( !v98 )
          _printf("ERROR: COULDN'T FIND DRIVER:RIG_Clave_R\n");
      }
      v99 = v79;
      goto LABEL_173;
    }
    if ( this->shiftHandsInverted )
    {
      std::wstring::wstring(&s, L"DRIVER:RIG_HAND_L");
      v82 = this->driver_root;
      LOBYTE(v180) = -121;
      v143 = v82->findChildByName(v82, &s, 1);
      LOBYTE(v180) = -123;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
      v83 = (CarAudioFMOD *)operator new(188);
      v142.__this = v83;
      LOBYTE(v180) = -120;
      if ( v83 )
      {
        std::wstring::wstring(&ob, L"DRIVER:FINGERS_L");
        LOBYTE(v180) = -119;
        v6 |= 4u;
        n = (Node *)v6;
        Node::Node((Node *)v83, &ob);
        n = v84;
      }
      else
      {
        n = 0;
      }
      v180 = 133;
      if ( (v6 & 4) == 0 )
        goto LABEL_161;
      v6 &= 0xFFFFFFFB;
      v85 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob;
    }
    else
    {
      std::wstring::wstring(&custom_skin, L"DRIVER:RIG_HAND_R");
      v86 = this->driver_root;
      LOBYTE(v180) = -117;
      v143 = v86->findChildByName(v86, &custom_skin, 1);
      LOBYTE(v180) = -123;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&custom_skin);
      v87 = (CarAudioFMOD *)operator new(188);
      v142.__this = v87;
      LOBYTE(v180) = -116;
      if ( v87 )
      {
        std::wstring::wstring(&v158, L"DRIVER:FINGERS_R");
        LOBYTE(v180) = -115;
        v6 |= 8u;
        n = (Node *)v6;
        Node::Node((Node *)v87, &v158);
        n = v88;
      }
      else
      {
        n = 0;
      }
      v180 = 133;
      if ( (v6 & 8) == 0 )
        goto LABEL_161;
      v6 &= 0xFFFFFFF7;
      v85 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158;
    }
    std::wstring::~wstring(v85);
LABEL_161:
    v89 = n;
    v90 = &v143->nodes;
    std::vector<int>::operator=((std::vector<unsigned int> *)&n->nodes, (const std::vector<unsigned int> *)&v143->nodes);
    std::_Container_base0::_Orphan_all(v90);
    v91 = (int)v143;
    v90->_Mylast = v90->_Myfirst;
    (*(void (**)(int, Node *))(*(_DWORD *)v91 + 4))(v91, v89);
    v92 = v89->nodes._Myfirst;
    v93 = v89->nodes._Mylast;
    v94 = 0;
    v95 = (unsigned int)((char *)v93 - (char *)v92 + 3) >> 2;
    if ( v92 > v93 )
      v95 = 0;
    if ( v95 )
    {
      v96 = n;
      do
      {
        v97 = (int)*v92++;
        ++v94;
        *(_DWORD *)(v97 + 148) = v96;
      }
      while ( v94 != v95 );
    }
    v98 = n;
    v99 = &this->shiftBlender;
LABEL_173:
    AnimationBlender::addTargetNode(v99, v98, 1);
    AnimationPlayer::activateNodes(this->shiftPlayer, v98);
    std::wstring::wstring(&custom_skin, L"PRELOAD_RPM");
    LOBYTE(v180) = -111;
    std::wstring::wstring(&key, L"SHIFT_ANIMATION");
    LOBYTE(v180) = -110;
    v104 = INIReader::getInt(&ini, &key, &custom_skin);
    v11 = key._Myres < 8;
    this->preLoadRPM = v104;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v180) = -123;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    std::wstring::wstring(&custom_skin, L"BLEND_TIME");
    LOBYTE(v180) = -109;
    std::wstring::wstring(&key, L"SHIFT_ANIMATION");
    LOBYTE(v180) = -108;
    v105 = INIReader::getFloat(&ini, &key, &custom_skin);
    v11 = key._Myres < 8;
    this->shiftTimings.blendTimeMult = 1000.0 / v105;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v180) = -123;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    std::wstring::wstring(&custom_skin, L"POSITIVE_TIME");
    LOBYTE(v180) = -107;
    std::wstring::wstring(&key, L"SHIFT_ANIMATION");
    LOBYTE(v180) = -106;
    v106 = INIReader::getFloat(&ini, &key, &custom_skin);
    v11 = key._Myres < 8;
    this->shiftTimings.positiveTimeMult = 1000.0 / v106;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v180) = -123;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    std::wstring::wstring(&custom_skin, L"STATIC_TIME");
    LOBYTE(v180) = -105;
    std::wstring::wstring(&key, L"SHIFT_ANIMATION");
    LOBYTE(v180) = -104;
    v107 = INIReader::getFloat(&ini, &key, &custom_skin);
    v11 = key._Myres < 8;
    this->shiftTimings.staticTimeMult = 1000.0 / v107;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v180) = -123;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    std::wstring::wstring(&custom_skin, L"NEGATIVE_TIME");
    LOBYTE(v180) = -103;
    std::wstring::wstring(&key, L"SHIFT_ANIMATION");
    LOBYTE(v180) = -102;
    v108 = INIReader::getFloat(&ini, &key, &custom_skin);
    v11 = key._Myres < 8;
    this->shiftTimings.negativeTimeMult = 1000.0 / v108;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    v144[0] = (GraphicsManager *)LODWORD(this->shiftTimings.blendTimeMult);
    if ( __fdtest((float *)v144) > 0 )
    {
      *(_DWORD *)&filter[68] = "ERROR: SHIFT ANIMATION BLEND_TIME CANNOT BE 0\n";
      this->shiftTimings.blendTimeMult = 2.0;
      _printf(*(const char *const *)&filter[68]);
    }
    v144[0] = (GraphicsManager *)LODWORD(this->shiftTimings.positiveTimeMult);
    if ( __fdtest((float *)v144) > 0 )
    {
      *(_DWORD *)&filter[68] = "ERROR: SHIFT ANIMATION POSITIVE_TIME CANNOT BE 0\n";
      this->shiftTimings.positiveTimeMult = 1.0;
      _printf(*(const char *const *)&filter[68]);
    }
    v144[0] = (GraphicsManager *)LODWORD(this->shiftTimings.negativeTimeMult);
    if ( __fdtest((float *)v144) > 0 )
    {
      *(_DWORD *)&filter[68] = "ERROR: SHIFT ANIMATION STATIC_TIME CANNOT BE 0\n";
      this->shiftTimings.negativeTimeMult = 1.0;
      _printf(*(const char *const *)&filter[68]);
    }
    v144[0] = (GraphicsManager *)LODWORD(this->shiftTimings.staticTimeMult);
    if ( __fdtest((float *)v144) > 0 )
    {
      *(_DWORD *)&filter[68] = "ERROR: SHIFT ANIMATION NEGATIVE_TIME CANNOT BE 0\n";
      this->shiftTimings.staticTimeMult = 1.0;
      _printf(*(const char *const *)&filter[68]);
    }
    LOBYTE(v180) = 115;
    std::vector<AnimationSet>::_Tidy(&ani);
  }
  std::wstring::wstring(&custom_skin, L"DRIVER:RIG_Nek");
  v109 = this->driver_root;
  LOBYTE(v180) = -101;
  v110 = v109->findChildByName(v109, &custom_skin, 1);
  v11 = custom_skin._Myres < 8;
  this->neckNode = v110;
  LOBYTE(v180) = 115;
  if ( !v11 )
    operator delete(custom_skin._Bx._Ptr);
  v111 = this->neckNode;
  if ( v111 )
  {
    *(__m128i *)&this->nextRestMatrix.M11 = _mm_loadu_si128((const __m128i *)&v111->matrix);
    *(__m128i *)&this->nextRestMatrix.M21 = _mm_loadu_si128((const __m128i *)&v111->matrix.M21);
    *(__m128i *)&this->nextRestMatrix.M31 = _mm_loadu_si128((const __m128i *)&v111->matrix.M31);
    *(__m128i *)&this->nextRestMatrix.M41 = _mm_loadu_si128((const __m128i *)&v111->matrix.M41);
  }
  for ( i = 0; ; ++i )
  {
    *(_DWORD *)v149.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v149.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v149.gap68);
    LOBYTE(v180) = -100;
    v6 |= 0x80u;
    n = (Node *)v6;
    std::wiostream::basic_iostream<wchar_t>(&v149, &v149.gap10[8], 0);
    v180 = 157;
    *(_DWORD *)&v149.gap0[*(_DWORD *)(*(_DWORD *)v149.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(DriverModel **)((char *)&v148 + *(_DWORD *)(*(_DWORD *)v149.gap0 + 4)) = (DriverModel *)(*(_DWORD *)(*(_DWORD *)v149.gap0 + 4)
                                                                                             - 104);
    std::wstreambuf::wstreambuf(&v149.gap10[8]);
    *(_DWORD *)&v149.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v149.gap10[64] = 0;
    *(_DWORD *)&v149.gap10[68] = 0;
    *(_DWORD *)&filter[68] = i;
    LOBYTE(v180) = -97;
    v113 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v149.gap10, "HIDE_OBJECT_");
    std::wostream::operator<<(v113, *(_DWORD *)&filter[68]);
    v114 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v149, &s);
    LOBYTE(v180) = -96;
    v115 = INIReader::hasSection(&ini, v114);
    v140 = v115;
    LOBYTE(v180) = -97;
    if ( s._Myres >= 8 )
    {
      operator delete(s._Bx._Ptr);
      v115 = v140;
    }
    if ( !v115 )
      break;
    std::wstring::wstring(&s, L"NAME");
    LOBYTE(v180) = -95;
    v116 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v149, &custom_skin);
    LOBYTE(v180) = -94;
    INIReader::getString(&ini, &ob, v116, &s);
    if ( custom_skin._Myres >= 8 )
      operator delete(custom_skin._Bx._Ptr);
    custom_skin._Myres = 7;
    custom_skin._Mysize = 0;
    custom_skin._Bx._Buf[0] = 0;
    LOBYTE(v180) = -91;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    v117 = this->driver_root->findChildByName(this->driver_root, &ob, 1);
    if ( v117 )
      DriverModel::addNodeHierarchyToHeadHide(this, v117);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
    LOBYTE(v180) = 115;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v149);
  }
  v143 = (Node *)v6;
  LOBYTE(v180) = 115;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v149);
  std::wstring::wstring(&s, L"HEAD_MOVEMENT");
  LOBYTE(v180) = -90;
  v118 = INIReader::hasSection(&ini, &s);
  LOBYTE(v180) = 115;
  v119 = v118;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
  if ( v119 )
  {
    std::wstring::wstring(&ob, L"FILTER");
    LOBYTE(v180) = -89;
    std::wstring::wstring(&s, L"HEAD_MOVEMENT");
    *(_DWORD *)&filter[68] = 1015580809;
    LOBYTE(v180) = -88;
    *(float *)&filter[64] = INIReader::getFloat(&ini, &s, &ob);
    this->headMovement.filter = filterToLerpDeltaK(*(float *)&filter[64], *(float *)&filter[68]);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LOBYTE(v180) = 115;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
    std::wstring::wstring(&custom_skin, L"PITCH_MAX_DEG");
    LOBYTE(v180) = -87;
    std::wstring::wstring(&s, L"HEAD_MOVEMENT");
    LOBYTE(v180) = -86;
    this->headMovement.pitchMaxDeg = INIReader::getFloat(&ini, &s, &custom_skin);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LOBYTE(v180) = 115;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&custom_skin);
    std::wstring::wstring(&v158, L"YAW_MAX_DEG");
    LOBYTE(v180) = -85;
    std::wstring::wstring(&s, L"HEAD_MOVEMENT");
    LOBYTE(v180) = -84;
    this->headMovement.yawMaxDeg = INIReader::getFloat(&ini, &s, &v158);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LOBYTE(v180) = 115;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
    std::wstring::wstring(&down_shift_filename, L"ROLL_MAX_DEG");
    LOBYTE(v180) = -83;
    std::wstring::wstring(&s, L"HEAD_MOVEMENT");
    LOBYTE(v180) = -82;
    this->headMovement.rollMaxDeg = INIReader::getFloat(&ini, &s, &down_shift_filename);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LOBYTE(v180) = 115;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&down_shift_filename);
    std::wstring::wstring(&v164, L"MAX_G");
    LOBYTE(v180) = -81;
    std::wstring::wstring(&s, L"HEAD_MOVEMENT");
    LOBYTE(v180) = -80;
    v120 = &this->headMovement;
    this->headMovement.maxG = INIReader::getFloat(&ini, &s, &v164);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v164);
  }
  else
  {
    this->headMovement.filter = filterToLerpDeltaK(this->headMovement.filter, 0.016666668);
    v120 = &this->headMovement;
  }
  if ( this->driverIniVersion < 2u )
  {
    this->headMovement.pitchMaxDeg = this->headMovement.pitchMaxDeg * 0.66666669;
    this->headMovement.yawMaxDeg = this->headMovement.yawMaxDeg * 0.66666669;
    this->headMovement.rollMaxDeg = this->headMovement.rollMaxDeg * 0.66666669;
  }
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&shift_filename);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&steer_filename);
  LOBYTE(v180) = 18;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&base_pos_filename);
  v6 = (unsigned int)v143;
  v5 = v145;
LABEL_222:
  *(_DWORD *)&filter[68] = 1065353216;
  *(_DWORD *)&filter[64] = 0;
  CommandItem::CommandItem(&v142, (CarAudioFMOD *)this);
  v146 = &filter[40];
  std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
    (std::function<void __cdecl(SVar *,float)> *)&filter[40],
    v121);
  LOBYTE(v180) = -79;
  v147 = &filter[16];
  std::wstring::wstring((std::wstring *)&filter[16], L"hideHead");
  v122 = v5->sim;
  LOBYTE(v180) = -78;
  v123 = Sim::getConsole(v122);
  LOBYTE(v180) = 18;
  Console::addVarLambda(
    v123,
    *(std::wstring *)&filter[16],
    *(std::function<void __cdecl(SVar *,float)> *)&filter[40],
    filter[64],
    *(float *)&filter[68]);
  std::wstring::wstring(&s, L"system/cfg/assetto_corsa.ini");
  LOBYTE(v180) = -77;
  INIReader::INIReader(&assettoCorsaIni, &s);
  LOBYTE(v180) = -75;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
  if ( !assettoCorsaIni.ready
    || (std::wstring::wstring(&ob, L"DRIVER"),
        LOBYTE(v180) = -74,
        v6 |= 0x10u,
        n = (Node *)v6,
        v124 = INIReader::hasSection(&assettoCorsaIni, &ob),
        v140 = 1,
        !v124) )
  {
    v140 = 0;
  }
  v180 = 181;
  if ( (v6 & 0x10) != 0 )
  {
    v6 &= 0xFFFFFFEF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
  }
  if ( v140 )
  {
    std::wstring::wstring(&base_pos_filename, L"HIDE");
    v125 = v6 | 0x20;
    LOBYTE(v180) = -73;
    n = (Node *)v125;
    std::wstring::wstring(&ob, L"DRIVER");
    v180 = 184;
    v126 = v125 | 0x40;
    n = (Node *)v126;
    if ( INIReader::getInt(&assettoCorsaIni, &ob, &base_pos_filename) || (v127 = Sim::isVrRoom(v5->sim), v140 = 0, v127) )
      v140 = 1;
    if ( (v126 & 0x40) != 0 )
    {
      LOBYTE(v126) = v126 & 0xBF;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ob);
    }
    v180 = 181;
    if ( (v126 & 0x20) != 0 )
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&base_pos_filename);
    Node::setActive(this->driver_root, v140 == 0);
    this->forceHidden = !Node::getActive(this->driver_root);
  }
  if ( !CarAvatar::getGuid(v5) )
  {
    *(_DWORD *)&filter[68] = 1065353216;
    *(_DWORD *)&filter[64] = 0;
    *(_DWORD *)&filter[60] = 0;
    *(_DWORD *)&filter[56] = &this->headMovement.rollMaxDeg;
    v142.__this = (CarAudioFMOD *)&filter[32];
    std::wstring::wstring((std::wstring *)&filter[32], L"headRoll");
    v128 = v5->sim;
    LOBYTE(v180) = -71;
    v129 = Sim::getConsole(v128);
    LOBYTE(v180) = -75;
    Console::addVar(
      v129,
      *(std::wstring *)&filter[32],
      *(float **)&filter[56],
      *(IVarCallback **)&filter[60],
      filter[64],
      *(float *)&filter[68]);
    *(_DWORD *)&filter[68] = 1065353216;
    *(_DWORD *)&filter[64] = 0;
    *(_DWORD *)&filter[60] = 0;
    *(_DWORD *)&filter[56] = &this->headMovement.pitchMaxDeg;
    v142.__this = (CarAudioFMOD *)&filter[32];
    std::wstring::wstring((std::wstring *)&filter[32], L"headPitch");
    v130 = v5->sim;
    LOBYTE(v180) = -70;
    v131 = Sim::getConsole(v130);
    LOBYTE(v180) = -75;
    Console::addVar(
      v131,
      *(std::wstring *)&filter[32],
      *(float **)&filter[56],
      *(IVarCallback **)&filter[60],
      filter[64],
      *(float *)&filter[68]);
    *(_DWORD *)&filter[68] = 1065353216;
    *(_DWORD *)&filter[64] = 0;
    *(_DWORD *)&filter[60] = 0;
    *(_DWORD *)&filter[56] = &this->headMovement.yawMaxDeg;
    v142.__this = (CarAudioFMOD *)&filter[32];
    std::wstring::wstring((std::wstring *)&filter[32], L"headYaw");
    v132 = v5->sim;
    LOBYTE(v180) = -69;
    v133 = Sim::getConsole(v132);
    LOBYTE(v180) = -75;
    Console::addVar(
      v133,
      *(std::wstring *)&filter[32],
      *(float **)&filter[56],
      *(IVarCallback **)&filter[60],
      filter[64],
      *(float *)&filter[68]);
    *(_DWORD *)&filter[68] = 1065353216;
    *(_DWORD *)&filter[64] = 0;
    *(_DWORD *)&filter[60] = 0;
    *(_DWORD *)&filter[56] = v120;
    v142.__this = (CarAudioFMOD *)&filter[32];
    std::wstring::wstring((std::wstring *)&filter[32], L"headMaxG");
    v134 = v5->sim;
    LOBYTE(v180) = -68;
    v135 = Sim::getConsole(v134);
    LOBYTE(v180) = -75;
    Console::addVar(
      v135,
      *(std::wstring *)&filter[32],
      *(float **)&filter[56],
      *(IVarCallback **)&filter[60],
      filter[64],
      *(float *)&filter[68]);
    *(_DWORD *)&filter[68] = 1065353216;
    *(_DWORD *)&filter[64] = 0;
    *(_DWORD *)&filter[60] = 0;
    *(_DWORD *)&filter[56] = &this->headMovement.filter;
    v142.__this = (CarAudioFMOD *)&filter[32];
    std::wstring::wstring((std::wstring *)&filter[32], L"headFilter");
    v136 = v5->sim;
    LOBYTE(v180) = -67;
    v137 = Sim::getConsole(v136);
    LOBYTE(v180) = -75;
    Console::addVar(
      v137,
      *(std::wstring *)&filter[32],
      *(float **)&filter[56],
      *(IVarCallback **)&filter[60],
      filter[64],
      *(float *)&filter[68]);
  }
  LOBYTE(v180) = 18;
  INIReader::~INIReader(&assettoCorsaIni);
  LOBYTE(v180) = 17;
  INIReader::~INIReader(&ini);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&inifn);
  LOBYTE(v180) = 8;
  KN5IO::~KN5IO(&kn);
  LOBYTE(v180) = 7;
  INIReader::~INIReader(&r);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&dataPath);
}
void DriverModel::~DriverModel(DriverModel *this)
{
  AnimationPlayer *v2; // edi
  AnimationPlayer *v3; // edi
  std::vector<Renderable *> *v4; // edi

  this->__vftable = (DriverModel_vtbl *)&DriverModel::`vftable';
  v2 = this->steerPlayer;
  if ( v2 )
  {
    std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v2);
    operator delete(v2);
  }
  v3 = this->shiftPlayer;
  if ( v3 )
  {
    std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(this->shiftPlayer);
    operator delete(v3);
  }
  v4 = &this->headHideNodes;
  if ( this->headHideNodes._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->headHideNodes);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->headHideNodes._Mylast = 0;
    this->headHideNodes._Myend = 0;
  }
  std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>((std::vector<SplineIndexBound> *)&this->shiftBlender);
  GameObject::~GameObject(this);
}
DriverModel *DriverModel::`scalar deleting destructor'(DriverModel *this, unsigned int a2)
{
  DriverModel::~DriverModel(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DriverModel::addNodeHierarchyToHeadHide(DriverModel *this, Node *n)
{
  Node *v2; // edi
  Node **v4; // eax
  Node **v5; // esi
  int v6; // edi
  unsigned int v7; // ebx

  v2 = n;
  n = (Node *)__RTDynamicCast(n, 0, &Node `RTTI Type Descriptor', &Renderable `RTTI Type Descriptor', 0);
  if ( n )
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&this->headHideNodes,
      (ICollisionObject *const *)&n);
  v4 = v2->nodes._Mylast;
  v5 = v2->nodes._Myfirst;
  v6 = 0;
  v7 = (unsigned int)((char *)v4 - (char *)v5 + 3) >> 2;
  if ( v5 > v4 )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      DriverModel::addNodeHierarchyToHeadHide(this, *v5);
      ++v6;
      ++v5;
    }
    while ( v6 != v7 );
  }
}
void DriverModel::animateHShifter(DriverModel *this, float dt)
{
  float v2; // xmm3_4
  CarAvatar *v4; // ecx
  float v5; // xmm2_4
  int v6; // edx
  float v7; // xmm4_4
  float p; // xmm1_4
  AnimationPlayer *v9; // ecx
  float v10; // xmm1_4
  float blend; // xmm0_4
  AnimationPlayer *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  AnimationPlayer *v16; // ecx
  float v17; // xmm0_4

  v2 = FLOAT_0_2;
  v4 = this->car;
  v5 = (float)this->preLoadRPM;
  v6 = v4->physicsState.gear;
  if ( v6 == 1 && (float)(v4->physicsState.speed.value * 3.5999999) < 5.0 )
  {
    v5 = v5 * 0.5;
    v2 = FLOAT_0_0099999998;
  }
  v7 = v4->physicsState.engineRPM;
  p = 0.0;
  if ( v7 <= v5 || v6 >= v4->physicsInfo.maxGear + 1 || this->shiftAnimationStatus || v4->physicsState.gas <= v2 )
  {
    if ( this->preLoadShift && (v2 > v4->physicsState.gas || (float)(v5 * 0.69999999) > v7) )
      this->preLoadShift = 0;
  }
  else
  {
    this->paddleShiftStatus = ePaddleShiftingUp;
    this->shiftAnimationStatus = eBlendToZero;
    this->shiftBlendTime = 0.0;
    this->preLoadShift = 1;
  }
  this->oldRpm = v4->physicsState.engineRPM;
  switch ( this->shiftAnimationStatus )
  {
    case eNoShift:
      AnimationPlayer::setCurrentPos(this->shiftPlayer, 0.0, 0.0);
      AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftPlayer, 0.0);
      this->shiftBlendTime = 0.0;
      break;
    case eBlendToZero:
      v9 = this->shiftPlayer;
      this->shiftBlendTime = (float)(this->shiftTimings.blendTimeMult * dt) + this->shiftBlendTime;
      AnimationPlayer::setCurrentPos(v9, 0.0, 0.0);
      v10 = this->shiftBlendTime;
      blend = FLOAT_1_0;
      if ( v10 <= 1.0 )
      {
        blend = 0.0;
        if ( v10 >= 0.0 )
          blend = this->shiftBlendTime;
      }
      AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftPlayer, blend);
      if ( this->shiftBlendTime >= 1.0 )
      {
        this->shiftAnimationStatus = ePositive;
        this->shiftBlendTime = 0.0;
      }
      break;
    case ePositive:
      v15 = (float)(this->shiftTimings.positiveTimeMult * dt) + this->shiftBlendTime;
      this->shiftBlendTime = v15;
      if ( v15 <= 1.0 )
      {
        if ( v15 >= 0.0 )
          p = v15;
      }
      else
      {
        p = FLOAT_1_0;
      }
      AnimationPlayer::setCurrentPos(this->shiftPlayer, p, 0.0);
      if ( this->shiftBlendTime >= 1.0 )
      {
        this->shiftAnimationStatus = eChanging;
        this->shiftBlendTime = 0.0;
      }
      break;
    case eChanging:
      v16 = this->shiftPlayer;
      this->shiftBlendTime = (float)(this->shiftTimings.staticTimeMult * dt) + this->shiftBlendTime;
      AnimationPlayer::setCurrentPos(v16, 1.0, COERCE_FLOAT(1));
      if ( this->shiftBlendTime >= 1.0 && !this->preLoadShift )
      {
        this->shiftAnimationStatus = eNegative;
        this->shiftBlendTime = 0.0;
      }
      break;
    case eNegative:
      v17 = (float)(this->shiftTimings.negativeTimeMult * dt) + this->shiftBlendTime;
      this->shiftBlendTime = v17;
      if ( (float)(1.0 - v17) <= 1.0 )
      {
        if ( (float)(1.0 - v17) >= 0.0 )
          p = 1.0 - v17;
      }
      else
      {
        p = FLOAT_1_0;
      }
      AnimationPlayer::setCurrentPos(this->shiftPlayer, p, 0.0);
      if ( this->shiftBlendTime >= 1.0 )
      {
        this->shiftAnimationStatus = eBlendToSteer;
        this->shiftBlendTime = 0.0;
      }
      break;
    case eBlendToSteer:
      v12 = this->shiftPlayer;
      this->shiftBlendTime = (float)(this->shiftTimings.blendTimeMult * dt) + this->shiftBlendTime;
      AnimationPlayer::setCurrentPos(v12, 0.0, 0.0);
      v13 = FLOAT_1_0;
      v14 = 1.0 - this->shiftBlendTime;
      if ( v14 <= 1.0 )
      {
        v13 = 0.0;
        if ( v14 >= 0.0 )
          v13 = 1.0 - this->shiftBlendTime;
      }
      AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftPlayer, v13);
      if ( this->shiftBlendTime >= 1.0 )
      {
        this->shiftAnimationStatus = eNoShift;
        this->shiftBlendTime = 0.0;
      }
      break;
    default:
      return;
  }
}
void DriverModel::animatePaddles(DriverModel *this, float dt)
{
  PaddleShiftStatus v3; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4
  PaddleShiftStatus v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  PaddleShiftStatus v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  PaddleShiftStatus v12; // eax
  float blend; // [esp+4h] [ebp-Ch]
  float v; // [esp+8h] [ebp-8h]
  float va; // [esp+8h] [ebp-8h]

  switch ( this->shiftAnimationStatus )
  {
    case eNoShift:
      AnimationPlayer::setCurrentPos(this->shiftPlayer, 0.0, 0.0);
      AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftPlayer, 0.0);
      AnimationPlayer::setCurrentPos(this->shiftDownPlayer, 0.0, 0.0);
      AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftDownPlayer, 0.0);
      this->shiftBlendTime = 0.0;
      return;
    case eBlendToZero:
      v3 = this->paddleShiftStatus;
      this->shiftBlendTime = (float)(this->shiftTimings.blendTimeMult * dt) + this->shiftBlendTime;
      if ( v3 == ePaddleShiftingUp )
      {
        AnimationPlayer::setCurrentPos(this->shiftPlayer, 0.0, 0.0);
        v4 = this->shiftBlendTime;
        v5 = FLOAT_1_0;
        if ( v4 <= 1.0 )
        {
          v5 = 0.0;
          if ( v4 >= 0.0 )
            v5 = this->shiftBlendTime;
        }
        AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftPlayer, v5);
      }
      else if ( v3 == ePaddleShiftingDown )
      {
        AnimationPlayer::setCurrentPos(this->shiftDownPlayer, 0.0, 0.0);
        v = saturate(this->shiftBlendTime);
        AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftDownPlayer, v);
      }
      if ( this->shiftBlendTime > 1.0 )
      {
        this->shiftAnimationStatus = ePositive;
        this->shiftBlendTime = 0.0;
      }
      return;
    case ePositive:
      v8 = 0.0;
      v9 = this->paddleShiftStatus;
      v10 = FLOAT_1_0;
      v11 = (float)(this->shiftTimings.positiveTimeMult * dt) + this->shiftBlendTime;
      this->shiftBlendTime = v11;
      if ( v9 == ePaddleShiftingUp )
      {
        if ( v11 <= 1.0 )
        {
          if ( v11 >= 0.0 )
            v8 = v11;
          AnimationPlayer::setCurrentPos(this->shiftPlayer, v8, 0.0);
        }
        else
        {
          AnimationPlayer::setCurrentPos(this->shiftPlayer, 1.0, 0.0);
        }
      }
      else
      {
        if ( v9 != ePaddleShiftingDown )
          goto LABEL_31;
        blend = saturate(v11);
        AnimationPlayer::setCurrentPos(this->shiftDownPlayer, blend, 0.0);
      }
      v10 = FLOAT_1_0;
LABEL_31:
      if ( this->shiftBlendTime > v10 )
      {
        this->shiftAnimationStatus = eChanging;
        this->shiftBlendTime = 0.0;
      }
      return;
    case eChanging:
      v12 = this->paddleShiftStatus;
      this->shiftBlendTime = (float)(this->shiftTimings.staticTimeMult * dt) + this->shiftBlendTime;
      if ( v12 == ePaddleShiftingUp )
      {
        AnimationPlayer::setCurrentPos(this->shiftPlayer, 1.0, COERCE_FLOAT(1));
      }
      else if ( v12 == ePaddleShiftingDown )
      {
        AnimationPlayer::setCurrentPos(this->shiftDownPlayer, 1.0, COERCE_FLOAT(1));
      }
      if ( this->shiftBlendTime > 1.0 && !this->preLoadShift )
      {
        this->shiftAnimationStatus = eBlendToSteer;
        this->shiftBlendTime = 0.0;
      }
      return;
    case eBlendToSteer:
      v6 = this->paddleShiftStatus;
      this->shiftBlendTime = (float)(this->shiftTimings.blendTimeMult * dt) + this->shiftBlendTime;
      if ( v6 == ePaddleShiftingUp )
      {
        AnimationPlayer::setCurrentPos(this->shiftPlayer, 0.0, 0.0);
        v7 = 1.0 - this->shiftBlendTime;
        if ( v7 <= 1.0 )
        {
          if ( v7 < 0.0 )
            v7 = 0.0;
          AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftPlayer, v7);
        }
        else
        {
          AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftPlayer, 1.0);
        }
      }
      else if ( v6 == ePaddleShiftingDown )
      {
        AnimationPlayer::setCurrentPos(this->shiftDownPlayer, 0.0, 0.0);
        va = saturate(1.0 - this->shiftBlendTime);
        AnimationBlender::blendAnimations(&this->shiftBlender, this->steerPlayer, this->shiftDownPlayer, va);
      }
      if ( this->shiftBlendTime > 1.0 )
      {
        this->shiftAnimationStatus = eNoShift;
        this->shiftBlendTime = 0.0;
      }
      return;
    default:
      return;
  }
}
vec3f *DriverModel::getEyesPosition(DriverModel *this, vec3f *result)
{
  Node *v2; // ecx
  vec3f *v3; // eax
  vec3f pos; // [esp+0h] [ebp-Ch] BYREF

  v2 = this->neckNode;
  if ( v2 )
  {
    pos.x = 0.0;
    pos.y = 0.13;
    pos.z = 0.14;
    Node::localToWorld(v2, result, &pos);
    v3 = result;
  }
  else
  {
    v3 = result;
    result->x = 0.0;
    result->y = 0.0;
    result->z = 0.0;
  }
  return v3;
}
double DriverModel::getShiftDownPlayerCurrentPosition(DriverModel *this)
{
  AnimationPlayer *v1; // ecx
  double result; // st7

  v1 = this->shiftDownPlayer;
  if ( v1 )
    result = AnimationPlayer::getCurrentPos(v1);
  else
    result = 0.0;
  return result;
}
void DriverModel::loadDriverSkin(DriverModel *this, KN5IO *kn, INIReader *iniS, const std::wstring *section, const std::wstring *key)
{
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // esi
  std::wstring *v8; // eax
  KN5IO_vtbl *v9; // eax
  int v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  KN5IO_vtbl *v13; // eax
  std::wstring iniSkin; // [esp+14h] [ebp-70h] BYREF
  std::wstring v15; // [esp+2Ch] [ebp-58h] BYREF
  std::wstring nm; // [esp+44h] [ebp-40h] BYREF
  std::wstring result; // [esp+5Ch] [ebp-28h] BYREF
  int v18; // [esp+80h] [ebp-4h]

  iniSkin._Myres = 7;
  iniSkin._Mysize = 0;
  iniSkin._Bx._Buf[0] = 0;
  v18 = 0;
  if ( INIReader::hasKey(iniS, section, key) )
  {
    v5 = INIReader::getString(iniS, &result, section, key);
    LOBYTE(v18) = 1;
    v6 = std::operator+<wchar_t>(&v15, L"content/texture/driver_", key);
    LOBYTE(v18) = 2;
    v7 = std::operator+<wchar_t>(&nm, v6, v5);
    if ( &iniSkin != v7 )
    {
      iniSkin._Myres = 7;
      iniSkin._Mysize = 0;
      iniSkin._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&iniSkin, v7);
    }
    if ( nm._Myres >= 8 )
      operator delete(nm._Bx._Ptr);
    nm._Myres = 7;
    nm._Mysize = 0;
    nm._Bx._Buf[0] = 0;
    if ( v15._Myres >= 8 )
      operator delete(v15._Bx._Ptr);
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    LOBYTE(v18) = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( Path::folderExists(&iniSkin) )
    {
      v8 = &iniSkin;
      if ( iniSkin._Myres >= 8 )
        v8 = (std::wstring *)iniSkin._Bx._Ptr;
      std::wstring::wstring(&v15, v8->_Bx._Buf);
      v9 = kn->__vftable;
      LOBYTE(v18) = 3;
      v9->addTextureFolder(kn, &v15);
      LOBYTE(v18) = 0;
      if ( v15._Myres >= 8 )
        operator delete(v15._Bx._Ptr);
    }
    v10 = std::wstring::find_last_of(&iniSkin, L"\\", 0xFFFFFFFF, 1u);
    if ( v10 >= 0 )
    {
      v11 = std::wstring::substr(&iniSkin, &v15, 0, v10 + 1);
      LOBYTE(v18) = 4;
      std::operator+<wchar_t>(&nm, v11, L"_nm");
      LOBYTE(v18) = 6;
      if ( v15._Myres >= 8 )
        operator delete(v15._Bx._Ptr);
      v15._Myres = 7;
      v15._Bx._Buf[0] = 0;
      v15._Mysize = 0;
      if ( Path::folderExists(&nm) )
      {
        v12 = &nm;
        if ( nm._Myres >= 8 )
          v12 = (std::wstring *)nm._Bx._Ptr;
        std::wstring::wstring(&result, v12->_Bx._Buf);
        v13 = kn->__vftable;
        LOBYTE(v18) = 7;
        v13->addTextureFolder(kn, &result);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
      if ( nm._Myres >= 8 )
        operator delete(nm._Bx._Ptr);
    }
  }
  if ( iniSkin._Myres >= 8 )
    operator delete(iniSkin._Bx._Ptr);
}
void DriverModel::setLockedPosition(DriverModel *this)
{
  AnimationPlayer *v1; // ecx

  v1 = this->steerPlayer;
  if ( v1 )
    AnimationPlayer::setCurrentPos(v1, 0.5, 0.0);
}
void DriverModel::setVisible(DriverModel *this, bool v)
{
  this->driver_root->isActive = v && !this->forceHidden;
}
void __userpurge DriverModel::updateHeadMovement(DriverModel *this@<ecx>, int a2@<edi>, int a3@<esi>, float *dt, float *dynDeltaT, vec3f *accG, int a7, __int128 a8, __int128 a9, mat44f a10, DirectX::XMMATRIX M2, DirectX::XMMATRIX a12, __m128 a13)
{
  float v14; // xmm6_4
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  Node *v21; // esi
  __int128 v22; // xmm1
  __int128 v23; // xmm2
  __int128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __int128 v28; // xmm1
  __int128 v29; // xmm2
  __int128 v30; // xmm3
  __m128 v31; // xmm0
  Node *v32; // esi
  __m128 v33; // xmm0
  __int128 v34; // xmm1
  __int128 v35; // xmm2
  __int128 v36; // xmm3
  Node *v37; // esi
  __int128 v38; // xmm1
  __int128 v39; // xmm2
  __int128 v40; // xmm3
  int v42; // [esp+0h] [ebp-168h]
  int v43; // [esp+0h] [ebp-168h]
  int v44; // [esp+0h] [ebp-168h]
  int v45; // [esp+4h] [ebp-164h]
  int v46; // [esp+4h] [ebp-164h]
  int v47; // [esp+4h] [ebp-164h]
  float v48; // [esp+Ch] [ebp-15Ch]
  float v49; // [esp+Ch] [ebp-15Ch]
  float v50; // [esp+Ch] [ebp-15Ch]
  vec3f v51; // [esp+18h] [ebp-150h]
  float v52; // [esp+18h] [ebp-150h]
  float v53; // [esp+18h] [ebp-150h]
  vec3f v54; // [esp+28h] [ebp-140h]
  mat44f v55; // [esp+78h] [ebp-F0h] BYREF
  mat44f v56; // [esp+B8h] [ebp-B0h] BYREF
  mat44f v57; // [esp+F8h] [ebp-70h] BYREF
  __m128i v58; // [esp+138h] [ebp-30h]
  __m128i v59; // [esp+148h] [ebp-20h]
  void *retaddr; // [esp+16Ch] [ebp+4h]
  float dta; // [esp+170h] [ebp+8h]

  v51 = this->localAcc;
  v54 = *accG;
  v14 = this->headMovement.filter * *dt;
  if ( v14 <= 1.0 )
  {
    if ( v14 < 0.0 )
      v14 = 0.0;
  }
  else
  {
    v14 = FLOAT_1_0;
  }
  v15 = (__m128)LODWORD(v51.x);
  v16 = (__m128)LODWORD(v51.y);
  v16.m128_f32[0] = v51.y + (float)((float)(v54.y - v51.y) * v14);
  v15.m128_f32[0] = v51.x + (float)((float)(v54.x - v51.x) * v14);
  *(_QWORD *)&this->localAcc.x = _mm_unpacklo_ps(v15, v16).m128_u64[0];
  this->localAcc.z = v51.z + (float)((float)(v54.z - v51.z) * v14);
  v58 = _mm_loadu_si128((const __m128i *)&this->nextRestMatrix.M31);
  v59 = _mm_loadu_si128((const __m128i *)&this->nextRestMatrix.M41);
  v48 = __libm_sse2_cosf(a2, a3).m128_f32[0];
  v52 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f((mat44f *)&v57.M13);
  v58.m128i_i32[1] = 1065353216;
  v57.M41 = (float)(1.0 - v48) + v48;
  v57.M13 = (float)((float)(1.0 - v48) * 0.0) + v48;
  v57.M24 = v57.M13;
  v57.M14 = v52 + (float)((float)(1.0 - v48) * 0.0);
  v57.M23 = (float)((float)(1.0 - v48) * 0.0) - v52;
  v57.M21 = (float)((float)(1.0 - v48) * 0.0) - (float)(v52 * 0.0);
  v57.M33 = (float)(v52 * 0.0) + (float)((float)(1.0 - v48) * 0.0);
  v57.M31 = v57.M33;
  v57.M34 = v57.M21;
  v49 = __libm_sse2_cosf(v42, v45).m128_f32[0];
  v53 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f((mat44f *)&v55.M13);
  v56.M12 = 1.0;
  v55.M13 = (float)(1.0 - v49) + v49;
  v55.M24 = (float)((float)(1.0 - v49) * 0.0) + v49;
  v55.M41 = v55.M24;
  v55.M14 = (float)(v53 * 0.0) + (float)((float)(1.0 - v49) * 0.0);
  v55.M23 = (float)((float)(1.0 - v49) * 0.0) - (float)(v53 * 0.0);
  v55.M21 = v55.M23;
  v55.M33 = v55.M14;
  v55.M31 = v53 + (float)((float)(1.0 - v49) * 0.0);
  v55.M34 = (float)((float)(1.0 - v49) * 0.0) - v53;
  v50 = __libm_sse2_cosf(v43, v46).m128_f32[0];
  v17 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f((mat44f *)&v56.M13);
  v18 = 0.0;
  v57.M12 = 1.0;
  v56.M24 = (float)(1.0 - v50) + v50;
  v56.M13 = (float)((float)(1.0 - v50) * 0.0) + v50;
  v56.M41 = v56.M13;
  v56.M14 = (float)(v17 * 0.0) + (float)((float)(1.0 - v50) * 0.0);
  v56.M23 = (float)((float)(1.0 - v50) * 0.0) - (float)(v17 * 0.0);
  v56.M21 = (float)((float)(1.0 - v50) * 0.0) - v17;
  v56.M33 = v17 + (float)((float)(1.0 - v50) * 0.0);
  v19 = this->headAnimationTime;
  v20 = this->headAnimationMult * *dynDeltaT;
  v56.M31 = v56.M14;
  v56.M34 = v56.M23;
  if ( COERCE_FLOAT(LODWORD(v19) & _xmm) <= v20 )
  {
    this->headAnimationTime = 0.0;
  }
  else
  {
    if ( v19 <= 0.0 )
    {
      if ( v19 < 0.0 )
        v18 = FLOAT_N1_0;
    }
    else
    {
      v18 = FLOAT_1_0;
    }
    this->headAnimationTime = v19 - (float)(v18 * v20);
  }
  COERCE_FLOAT(retaddr = (void *)__libm_sse2_cosf(v44, v47).m128_i32[0]);
  dta = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&a10);
  v21 = this->neckNode;
  a10.M44 = 1.0;
  a10.M22 = (float)(1.0 - *(float *)&retaddr) + *(float *)&retaddr;
  a10.M11 = (float)((float)(1.0 - *(float *)&retaddr) * 0.0) + *(float *)&retaddr;
  a10.M33 = a10.M11;
  a10.M12 = (float)(dta * 0.0) + (float)((float)(1.0 - *(float *)&retaddr) * 0.0);
  a10.M21 = (float)((float)(1.0 - *(float *)&retaddr) * 0.0) - (float)(dta * 0.0);
  a10.M13 = (float)((float)(1.0 - *(float *)&retaddr) * 0.0) - dta;
  a10.M31 = dta + (float)((float)(1.0 - *(float *)&retaddr) * 0.0);
  a10.M23 = a10.M12;
  a10.M32 = a10.M21;
  v22 = *(_OWORD *)&STACK[0x270];
  v23 = *(_OWORD *)&STACK[0x280];
  v24 = *(_OWORD *)&STACK[0x290];
  *(__m128 *)&v21->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, a13);
  v25 = a12.r[0];
  *(_OWORD *)&v21->matrix.M21 = v22;
  v26 = a12.r[1];
  *(_OWORD *)&v21->matrix.M31 = v23;
  v27 = a12.r[2];
  *(_OWORD *)&v21->matrix.M41 = v24;
  a12.r[0] = v25;
  a12.r[1] = v26;
  v28 = *(_OWORD *)&a10.M21;
  a12.r[2] = v27;
  v29 = *(_OWORD *)&a10.M31;
  v30 = *(_OWORD *)&a10.M41;
  v31 = DirectX::XMMatrixMultiply(a12.r, *(__m128 *)&a10.M11);
  v32 = this->neckNode;
  *(__m128 *)&a10.M11 = v31;
  *(_OWORD *)&a10.M21 = v28;
  *(_OWORD *)&a10.M31 = v29;
  v33 = *(__m128 *)&v32->matrix.M11;
  v34 = *(_OWORD *)&v32->matrix.M21;
  *(_OWORD *)&a10.M41 = v30;
  v35 = *(_OWORD *)&v32->matrix.M31;
  v36 = *(_OWORD *)&v32->matrix.M41;
  *(__m128 *)&v32->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&a10, v33);
  *(_OWORD *)&v32->matrix.M21 = v34;
  *(_OWORD *)&a10.M11 = a8;
  *(_OWORD *)&v32->matrix.M31 = v35;
  *(_OWORD *)&v32->matrix.M41 = v36;
  v37 = this->neckNode;
  *(_OWORD *)&a10.M21 = a9;
  *(_OWORD *)&a10.M31 = *(_OWORD *)&STACK[0x2A0];
  v38 = *(_OWORD *)&v37->matrix.M21;
  v39 = *(_OWORD *)&v37->matrix.M31;
  v40 = *(_OWORD *)&v37->matrix.M41;
  *(_OWORD *)&a10.M41 = *(_OWORD *)&STACK[0x2B0];
  *(__m128 *)&v37->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&a10, *(__m128 *)&v37->matrix.M11);
  *(_OWORD *)&v37->matrix.M21 = v38;
  *(_OWORD *)&v37->matrix.M31 = v39;
  *(_OWORD *)&v37->matrix.M41 = v40;
}
