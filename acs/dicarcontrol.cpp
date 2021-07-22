#include "dicarcontrol.h
void __usercall DICarControl::DICarControl(DICarControl *this@<ecx>, char a2@<bl>)
{
  DirectInput *v3; // eax
  DirectInput *v4; // eax
  DirectInput *v5; // eax
  DirectInput *v6; // eax
  DirectInput *v7; // eax
  DirectInput *v8; // eax
  DirectInput *v9; // eax
  DirectInput *v10; // eax
  DirectInput *v11; // eax
  DirectInput *v12; // eax
  DirectInput *v13; // eax
  DirectInput *v14; // eax
  DirectInput *v15; // eax
  DirectInput *v16; // eax
  DirectInput *v17; // eax
  DirectInput *v18; // eax
  DirectInput *v19; // eax
  DirectInput *v20; // eax
  DirectInput *v21; // eax
  DirectInput *v22; // eax
  DirectInput *v23; // eax
  DirectInput *v24; // eax
  DirectInput *v25; // eax
  DirectInput *v26; // eax
  DirectInput *v27; // eax
  DirectInput *v28; // eax
  DirectInput *v29; // eax
  DirectInput *v30; // eax
  DirectInput *v31; // eax
  DirectInput *v32; // eax
  DirectInput *v33; // eax
  DirectInput *v34; // eax
  DirectInput *v35; // eax
  int v36; // eax
  bool v37; // cf
  bool v38; // bl
  int v39; // eax
  bool v40; // bl
  int v41; // eax
  float v42; // xmm0_4
  DIControlAxis_vtbl *v43; // eax
  bool v44; // bl
  bool v45; // bl
  bool v46; // bl
  bool v47; // bl
  bool v48; // bl
  bool v49; // bl
  bool v50; // bl
  bool v51; // bl
  bool v52; // bl
  bool v53; // bl
  bool v54; // bl
  bool v55; // bl
  InputDevice *v56; // ecx
  double v57; // st7
  bool v58; // bl
  bool v59; // bl
  bool v60; // bl
  bool v61; // bl
  bool v62; // bl
  bool v63; // bl
  bool v64; // bl
  bool v65; // bl
  bool v66; // bl
  bool v67; // bl
  bool v68; // bl
  bool v69; // bl
  bool v70; // bl
  double v71; // st7
  float v72; // xmm0_4
  double v73; // st7
  unsigned int v74; // eax
  std::allocator<wchar_t> *v75; // eax
  bool v76; // al
  bool v77; // bl
  char v78; // bl
  bool v79; // al
  bool v80; // bl
  bool v81; // al
  bool v82; // bl
  InputDevice *v83; // ecx
  const std::wstring *v84; // eax
  bool v85; // bl
  std::wstring v86; // [esp+D0h] [ebp-17Ch] BYREF
  DirectInput *v87; // [esp+E8h] [ebp-164h]
  float debouncingS; // [esp+100h] [ebp-14Ch]
  std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > v89; // [esp+107h] [ebp-145h] BYREF
  DICarControl *v90; // [esp+108h] [ebp-144h]
  std::wstring key; // [esp+10Ch] [ebp-140h] BYREF
  std::wstring section; // [esp+124h] [ebp-128h] BYREF
  std::wstring result; // [esp+13Ch] [ebp-110h] BYREF
  INIReaderDocuments r; // [esp+154h] [ebp-F8h] BYREF
  std::wstring v95; // [esp+198h] [ebp-B4h] BYREF
  std::wstring v96; // [esp+1B0h] [ebp-9Ch] BYREF
  std::wstring v97; // [esp+1C8h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+1E0h] [ebp-6Ch] BYREF
  INIReader vac; // [esp+1F8h] [ebp-54h] BYREF
  int v100; // [esp+248h] [ebp-4h]

  v90 = this;
  *(_WORD *)&this->isAutoclutchNeeded = 0;
  this->keyboardEnabled = 1;
  this->ffEnabled = 1;
  this->ffFilter = 0.0;
  this->suppressPenalties = 0;
  v100 = 0;
  this->__vftable = (DICarControl_vtbl *)&DICarControl::`vftable';
  DirectInput::singleton();
  v87 = v3;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"STEER", 5u);
  DIControlAxis::DIControlAxis(&this->steer, v86, v87);
  LOBYTE(v100) = 1;
  DirectInput::singleton();
  v87 = v4;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"THROTTLE", 8u);
  DIControlAxis::DIControlAxis(&this->gas, v86, v87);
  LOBYTE(v100) = 2;
  DirectInput::singleton();
  v87 = v5;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"BRAKES", 6u);
  DIControlAxis::DIControlAxis(&this->brake, v86, v87);
  LOBYTE(v100) = 3;
  DirectInput::singleton();
  v87 = v6;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"CLUTCH", 6u);
  DIControlAxis::DIControlAxis(&this->clutch, v86, v87);
  LOBYTE(v100) = 4;
  DirectInput::singleton();
  v87 = v7;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"GLANCELEFT", 0xAu);
  DIControlButton::DIControlButton(&this->glanceLeft, v86, v87);
  LOBYTE(v100) = 5;
  DirectInput::singleton();
  v87 = v8;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"GLANCERIGHT", 0xBu);
  DIControlButton::DIControlButton(&this->glanceRight, v86, v87);
  LOBYTE(v100) = 6;
  DirectInput::singleton();
  v87 = v9;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"GLANCEBACK", 0xAu);
  DIControlButton::DIControlButton(&this->glanceBack, v86, v87);
  LOBYTE(v100) = 7;
  DirectInput::singleton();
  v87 = v10;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"GEARUP", 6u);
  DIControlButton::DIControlButton(&this->gearUp, v86, v87);
  LOBYTE(v100) = 8;
  DirectInput::singleton();
  v87 = v11;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"GEARDN", 6u);
  DIControlButton::DIControlButton(&this->gearDn, v86, v87);
  LOBYTE(v100) = 9;
  DirectInput::singleton();
  v87 = v12;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"BALANCEUP", 9u);
  DIControlButton::DIControlButton(&this->brakeBalanceUp, v86, v87);
  LOBYTE(v100) = 10;
  DirectInput::singleton();
  v87 = v13;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"BALANCEDN", 9u);
  DIControlButton::DIControlButton(&this->brakeBalanceDn, v86, v87);
  LOBYTE(v100) = 11;
  DirectInput::singleton();
  v87 = v14;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"KERS", 4u);
  DIControlButton::DIControlButton(&this->kers, v86, v87);
  LOBYTE(v100) = 12;
  DirectInput::singleton();
  v87 = v15;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"DRS", 3u);
  DIControlButton::DIControlButton(&this->drs, v86, v87);
  LOBYTE(v100) = 13;
  DirectInput::singleton();
  v87 = v16;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"ABSUP", 5u);
  DIControlButton::DIControlButton(&this->absUp, v86, v87);
  LOBYTE(v100) = 14;
  DirectInput::singleton();
  v87 = v17;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"ABSDN", 5u);
  DIControlButton::DIControlButton(&this->absDn, v86, v87);
  LOBYTE(v100) = 15;
  DirectInput::singleton();
  v87 = v18;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"TCUP", 4u);
  DIControlButton::DIControlButton(&this->tcUp, v86, v87);
  LOBYTE(v100) = 16;
  DirectInput::singleton();
  v87 = v19;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"TCDN", 4u);
  DIControlButton::DIControlButton(&this->tcDn, v86, v87);
  LOBYTE(v100) = 17;
  DirectInput::singleton();
  v87 = v20;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"TURBOUP", 7u);
  DIControlButton::DIControlButton(&this->turboUp, v86, v87);
  LOBYTE(v100) = 18;
  DirectInput::singleton();
  v87 = v21;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"TURBODN", 7u);
  DIControlButton::DIControlButton(&this->turboDn, v86, v87);
  LOBYTE(v100) = 19;
  DirectInput::singleton();
  v87 = v22;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"ENGINE_BRAKE_UP", 0xFu);
  DIControlButton::DIControlButton(&this->engineBrakeUp, v86, v87);
  LOBYTE(v100) = 20;
  DirectInput::singleton();
  v87 = v23;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"ENGINE_BRAKE_DN", 0xFu);
  DIControlButton::DIControlButton(&this->engineBrakeDn, v86, v87);
  LOBYTE(v100) = 21;
  DirectInput::singleton();
  v87 = v24;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"MGUK_DELIVERY_UP", 0x10u);
  DIControlButton::DIControlButton(&this->MGUKDeliveryUp, v86, v87);
  LOBYTE(v100) = 22;
  DirectInput::singleton();
  v87 = v25;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"MGUK_DELIVERY_DN", 0x10u);
  DIControlButton::DIControlButton(&this->MGUKDeliveryDn, v86, v87);
  LOBYTE(v100) = 23;
  DirectInput::singleton();
  v87 = v26;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"MGUK_RECOVERY_UP", 0x10u);
  DIControlButton::DIControlButton(&this->MGUKRecoveryUp, v86, v87);
  LOBYTE(v100) = 24;
  DirectInput::singleton();
  v87 = v27;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"MGUK_RECOVERY_DN", 0x10u);
  DIControlButton::DIControlButton(&this->MGUKRecoveryDn, v86, v87);
  LOBYTE(v100) = 25;
  DirectInput::singleton();
  v87 = v28;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"MGUH_MODE", 9u);
  DIControlButton::DIControlButton(&this->MGUHMode, v86, v87);
  LOBYTE(v100) = 26;
  DirectInput::singleton();
  v87 = v29;
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  std::wstring::assign(&v86, L"ACTION_HEADLIGHTS", 0x11u);
  DIControlButton::DIControlButton(&this->actionTurnOnHeadlights, v86, v87);
  LOBYTE(v100) = 27;
  DirectInput::singleton();
  v87 = v30;
  std::wstring::wstring(&v86, L"ACTION_CHANGE_CAMERA");
  DIControlButton::DIControlButton(&this->actionChangeCamera, v86, v87);
  LOBYTE(v100) = 28;
  DirectInput::singleton();
  v87 = v31;
  std::wstring::wstring(&v86, L"ACTION_HORN");
  DIControlButton::DIControlButton(&this->actionHorn, v86, v87);
  LOBYTE(v100) = 29;
  DirectInput::singleton();
  v87 = v32;
  std::wstring::wstring(&v86, L"ACTION_HEADLIGHTS_FLASH");
  DIControlButton::DIControlButton(&this->actionFlashHeadlights, v86, v87);
  LOBYTE(v100) = 30;
  DirectInput::singleton();
  v87 = v33;
  std::wstring::wstring(&v86, L"HANDBRAKE");
  DIControlButton::DIControlButton(&this->handBrake, v86, v87);
  LOBYTE(v100) = 31;
  DirectInput::singleton();
  v87 = v34;
  std::wstring::wstring(&v86, L"HANDBRAKE");
  DIControlAxis::DIControlAxis(&this->handBrakeAxis, v86, v87);
  LOBYTE(v100) = 32;
  DIShifter::DIShifter(&this->shifter);
  this->ffUpgrades.curbsGain = 0.0;
  this->ffUpgrades.gforceGain = 0.0;
  this->ffUpgrades.slipsGain = 0.0;
  this->ffUpgrades.absGain = 0.0;
  this->minFF = 0.0;
  this->centerBoostGain = 0.0;
  strcpy((char *)&this->centerBoostRange, "���=");
  FFPostProcessor::FFPostProcessor(&this->ffPostProcessor, a2);
  LOBYTE(v100) = 33;
  this->ffCounter = 0;
  this->ffInterval = 1;
  this->currentVibration = 0.0;
  this->currentLock = 0.0;
  Trigger::Trigger(&this->shiftUpTrigger);
  LOBYTE(v100) = 34;
  Trigger::Trigger(&this->shiftDnTrigger);
  LOBYTE(v100) = 35;
  std::unique_ptr<AudioEvent>::unique_ptr<AudioEvent>(&this->lastSpeed);
  LOBYTE(v100) = 36;
  this->validated = 0;
  DICarControl::validate(this);
  DirectInput::singleton();
  v87 = (DirectInput *)L"system/cfg/assetto_corsa.ini";
  this->directInput = v35;
  std::wstring::wstring(&ifilename, (const wchar_t *)v87);
  LOBYTE(v100) = 37;
  INIReader::INIReader(&vac, &ifilename);
  LOBYTE(v100) = 39;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( vac.ready )
  {
    std::wstring::wstring(&key, L"FF_SKIP_STEPS");
    LOBYTE(v100) = 40;
    std::wstring::wstring(&section, L"FORCE_FEEDBACK");
    LOBYTE(v100) = 41;
    v36 = INIReader::getInt(&vac, &section, &key);
    v37 = section._Myres < 8;
    this->ffInterval = v36;
    if ( !v37 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v100) = 39;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  std::wstring::wstring(&key, L"SOFT_LOCK");
  LOBYTE(v100) = 42;
  v38 = INIReader::hasSection(&vac, &key);
  LOBYTE(v100) = 39;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v38 )
  {
    std::wstring::wstring(&key, L"ENABLED");
    LOBYTE(v100) = 43;
    std::wstring::wstring(&section, L"SOFT_LOCK");
    LOBYTE(v100) = 44;
    v39 = INIReader::getInt(&vac, &section, &key);
    v37 = section._Myres < 8;
    this->useSoftLock = v39 != 0;
    if ( !v37 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v100) = 39;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( this->useSoftLock )
      _printf("Soft lock enabled\n");
  }
  v87 = 0;
  std::wstring::wstring(&v86, L"cfg/controls.ini");
  INIReaderDocuments::INIReaderDocuments(&r, v38, v86, (bool)v87);
  LOBYTE(v100) = 45;
  std::wstring::wstring(&key, L"FF_SKIP_STEPS");
  LOBYTE(v100) = 46;
  v40 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v40 )
  {
    std::wstring::wstring(&key, L"VALUE");
    LOBYTE(v100) = 47;
    std::wstring::wstring(&section, L"FF_SKIP_STEPS");
    LOBYTE(v100) = 48;
    v41 = INIReader::getInt(&r, &section, &key);
    v37 = section._Myres < 8;
    this->ffInterval = v41;
    if ( !v37 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v100) = 45;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _printf("Overriding assettocorsa.ini FF_SKIP_STEPS with controls.ini value: %d\n", this->ffInterval);
  }
  std::wstring::wstring(&key, L"DEBOUNCING_MS");
  LOBYTE(v100) = 49;
  std::wstring::wstring(&section, L"STEER");
  LOBYTE(v100) = 50;
  debouncingS = INIReader::getFloat(&r, &section, &key) * 0.001;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v42 = debouncingS;
  LOBYTE(v87) = 1;
  this->shiftUpTrigger.accumulatorLimit = debouncingS;
  this->shiftDnTrigger.accumulatorLimit = v42;
  INIReader::setVerboseMode(&r, (bool)v87);
  v43 = this->steer.__vftable;
  v87 = 0;
  r.suppressErrorReporting = 1;
  v86._Myres = (unsigned int)&r;
  this->minFF = 0.0;
  v43->load(&this->steer, (INIReader *)v86._Myres, (bool)v87);
  this->gas.load(&this->gas, &r, 1);
  this->brake.load(&this->brake, &r, 1);
  this->gearDn.load(&this->gearDn, &r, 0);
  this->gearUp.load(&this->gearUp, &r, 0);
  this->clutch.load(&this->clutch, &r, 1);
  this->handBrakeAxis.load(&this->handBrakeAxis, &r, 1);
  DICarControl::initShifter(this, &r);
  std::wstring::wstring(&key, L"GLANCELEFT");
  LOBYTE(v100) = 51;
  v44 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v44 )
    this->glanceLeft.load(&this->glanceLeft, &r, 0);
  std::wstring::wstring(&key, L"GLANCERIGHT");
  LOBYTE(v100) = 52;
  v45 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v45 )
    this->glanceRight.load(&this->glanceRight, &r, 0);
  std::wstring::wstring(&key, L"GLANCEBACK");
  LOBYTE(v100) = 53;
  v46 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v46 )
    this->glanceBack.load(&this->glanceBack, &r, 0);
  std::wstring::wstring(&key, L"ACTION_CHANGE_CAMERA");
  LOBYTE(v100) = 54;
  v47 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v47 )
    this->actionChangeCamera.load(&this->actionChangeCamera, &r, 0);
  std::wstring::wstring(&key, L"ACTION_HEADLIGHTS");
  LOBYTE(v100) = 55;
  v48 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v48 )
    this->actionTurnOnHeadlights.load(&this->actionTurnOnHeadlights, &r, 0);
  std::wstring::wstring(&key, L"ACTION_HEADLIGHTS_FLASH");
  LOBYTE(v100) = 56;
  v49 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v49 )
    this->actionFlashHeadlights.load(&this->actionFlashHeadlights, &r, 0);
  std::wstring::wstring(&key, L"ACTION_HORN");
  LOBYTE(v100) = 57;
  v50 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v50 )
    this->actionHorn.load(&this->actionHorn, &r, 0);
  std::wstring::wstring(&key, L"HANDBRAKE");
  LOBYTE(v100) = 58;
  v51 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v51 )
    this->handBrake.load(&this->handBrake, &r, 0);
  std::wstring::wstring(&key, L"BALANCEDN");
  LOBYTE(v100) = 59;
  v52 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v52 )
    this->brakeBalanceDn.load(&this->brakeBalanceDn, &r, 0);
  std::wstring::wstring(&key, L"BALANCEUP");
  LOBYTE(v100) = 60;
  v53 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v53 )
    this->brakeBalanceUp.load(&this->brakeBalanceUp, &r, 0);
  std::wstring::wstring(&key, L"KERS");
  LOBYTE(v100) = 61;
  v54 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v54 )
    this->kers.load(&this->kers, &r, 0);
  std::wstring::wstring(&key, L"DRS");
  LOBYTE(v100) = 62;
  v55 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v55 )
    this->drs.load(&this->drs, &r, 0);
  v56 = this->steer.device;
  if ( v56 )
    InputDevice::initFF(v56);
  std::wstring::wstring(&key, L"GAMMA");
  LOBYTE(v100) = 63;
  std::wstring::wstring(&section, L"BRAKES");
  LOBYTE(v100) = 64;
  v57 = INIReader::getFloat(&r, &section, &key);
  v37 = section._Myres < 8;
  this->brakeGamma = v57;
  if ( !v37 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->brakeGamma == 0.0 )
    this->brakeGamma = 1.0;
  std::wstring::wstring(&key, L"ABSDN");
  LOBYTE(v100) = 65;
  v58 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v58 )
    this->absDn.load(&this->absDn, &r, 0);
  std::wstring::wstring(&key, L"ABSUP");
  LOBYTE(v100) = 66;
  v59 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v59 )
    this->absUp.load(&this->absUp, &r, 0);
  std::wstring::wstring(&key, L"TCDN");
  LOBYTE(v100) = 67;
  v60 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v60 )
    this->tcDn.load(&this->tcDn, &r, 0);
  std::wstring::wstring(&key, L"TCUP");
  LOBYTE(v100) = 68;
  v61 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v61 )
    this->tcUp.load(&this->tcUp, &r, 0);
  std::wstring::wstring(&key, L"TURBODN");
  LOBYTE(v100) = 69;
  v62 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v62 )
    this->turboDn.load(&this->turboDn, &r, 0);
  std::wstring::wstring(&key, L"TURBOUP");
  LOBYTE(v100) = 70;
  v63 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v63 )
    this->turboUp.load(&this->turboUp, &r, 0);
  std::wstring::wstring(&key, L"ENGINE_BRAKE_UP");
  LOBYTE(v100) = 71;
  v64 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v64 )
    this->engineBrakeUp.load(&this->engineBrakeUp, &r, 0);
  std::wstring::wstring(&key, L"ENGINE_BRAKE_DN");
  LOBYTE(v100) = 72;
  v65 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v65 )
    this->engineBrakeDn.load(&this->engineBrakeDn, &r, 0);
  std::wstring::wstring(&key, L"MGUK_DELIVERY_UP");
  LOBYTE(v100) = 73;
  v66 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v66 )
    this->MGUKDeliveryUp.load(&this->MGUKDeliveryUp, &r, 0);
  std::wstring::wstring(&key, L"MGUK_DELIVERY_DN");
  LOBYTE(v100) = 74;
  v67 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v67 )
    this->MGUKDeliveryDn.load(&this->MGUKDeliveryDn, &r, 0);
  std::wstring::wstring(&key, L"MGUK_RECOVERY_UP");
  LOBYTE(v100) = 75;
  v68 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v68 )
    this->MGUKRecoveryUp.load(&this->MGUKRecoveryUp, &r, 0);
  std::wstring::wstring(&key, L"MGUK_RECOVERY_DN");
  LOBYTE(v100) = 76;
  v69 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v69 )
    this->MGUKRecoveryDn.load(&this->MGUKRecoveryDn, &r, 0);
  std::wstring::wstring(&key, L"MGUH_MODE");
  LOBYTE(v100) = 77;
  v70 = INIReader::hasSection(&r, &key);
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v70 )
    this->MGUHMode.load(&this->MGUHMode, &r, 0);
  std::wstring::wstring(&key, L"STEER_FILTER");
  LOBYTE(v100) = 78;
  std::wstring::wstring(&section, L"STEER");
  LOBYTE(v100) = 79;
  v71 = INIReader::getFloat(&r, &section, &key);
  v37 = section._Myres < 8;
  debouncingS = v71;
  this->steerFilter = debouncingS * 333.33334;
  if ( !v37 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"FILTER_FF");
  LOBYTE(v100) = 80;
  std::wstring::wstring(&section, L"STEER");
  LOBYTE(v100) = 81;
  v72 = FLOAT_1_0;
  debouncingS = INIReader::getFloat(&r, &section, &key);
  if ( debouncingS <= 1.0 )
  {
    v72 = 0.0;
    if ( debouncingS >= 0.0 )
      v72 = debouncingS;
  }
  v37 = section._Myres < 8;
  this->ffFilter = v72;
  if ( !v37 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v100) = 45;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"FF_GAIN");
  LOBYTE(v100) = 82;
  std::wstring::wstring(&section, L"STEER");
  LOBYTE(v100) = 83;
  v73 = INIReader::getFloat(&r, &section, &key);
  v74 = section._Myres;
  this->ffGain = v73;
  if ( v74 >= 8 )
  {
    v87 = (DirectInput *)(v74 + 1);
    v86._Myres = (unsigned int)section._Bx._Ptr;
    v75 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                       (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&section,
                                       &v89);
    std::allocator<wchar_t>::deallocate(v75, (wchar_t *)v86._Myres, (unsigned int)v87);
  }
  section._Myres = 7;
  std::wstring::_Eos(&section, 0);
  LOBYTE(v100) = 45;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  std::wstring::wstring(&v97, L"SCALE");
  LOBYTE(v100) = 84;
  std::wstring::wstring(&key, L"STEER");
  LOBYTE(v100) = 85;
  this->steerScale = INIReader::getFloat(&r, &key, &v97);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
  LOBYTE(v100) = 45;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97);
  std::wstring::wstring(&v96, L"LOCK");
  LOBYTE(v100) = 86;
  std::wstring::wstring(&v97, L"STEER");
  LOBYTE(v100) = 87;
  this->steerLock = INIReader::getFloat(&r, &v97, &v96) * 0.5;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97);
  LOBYTE(v100) = 45;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v96);
  std::wstring::wstring(&v95, L"STEER_GAMMA");
  LOBYTE(v100) = 88;
  std::wstring::wstring(&v96, L"STEER");
  LOBYTE(v100) = 89;
  this->linearity = INIReader::getFloat(&r, &v96, &v95);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v96);
  LOBYTE(v100) = 45;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
  std::wstring::wstring(&result, L"SPEED_SENSITIVITY");
  LOBYTE(v100) = 90;
  std::wstring::wstring(&v95, L"STEER");
  LOBYTE(v100) = 91;
  this->speedSensitivity = INIReader::getFloat(&r, &v95, &result);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
  LOBYTE(v100) = 45;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  if ( this->linearity == 0.0 )
    this->linearity = 1.0;
  if ( this->steerLock == 0.0 )
    this->steerLock = 200.0;
  if ( this->steerScale == 0.0 )
    this->steerScale = 1.0;
  std::wstring::wstring(&result, L"FF_ENHANCEMENT");
  LOBYTE(v100) = 92;
  v76 = INIReader::hasSection(&r, &result);
  LOBYTE(v100) = 45;
  v77 = v76;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  if ( v77 )
  {
    std::wstring::wstring(&v95, L"CURBS");
    LOBYTE(v100) = 93;
    std::wstring::wstring(&result, L"FF_ENHANCEMENT");
    LOBYTE(v100) = 94;
    this->ffUpgrades.curbsGain = INIReader::getFloat(&r, &result, &v95);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
    std::wstring::wstring(&v96, L"ROAD");
    LOBYTE(v100) = 95;
    std::wstring::wstring(&result, L"FF_ENHANCEMENT");
    LOBYTE(v100) = 96;
    this->ffUpgrades.gforceGain = INIReader::getFloat(&r, &result, &v96);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v96);
    std::wstring::wstring(&v97, L"SLIPS");
    LOBYTE(v100) = 97;
    std::wstring::wstring(&result, L"FF_ENHANCEMENT");
    LOBYTE(v100) = 98;
    this->ffUpgrades.slipsGain = INIReader::getFloat(&r, &result, &v97);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97);
    std::wstring::wstring(&key, L"ABS");
    LOBYTE(v100) = 99;
    std::wstring::wstring(&result, L"FF_ENHANCEMENT");
    LOBYTE(v100) = 100;
    v78 = INIReader::hasKey(&r, &result, &key);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    if ( v78 )
    {
      std::wstring::wstring(&v95, L"ABS");
      LOBYTE(v100) = 101;
      std::wstring::wstring(&result, L"FF_ENHANCEMENT");
      LOBYTE(v100) = 102;
      this->ffUpgrades.absGain = INIReader::getFloat(&r, &result, &v95);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      LOBYTE(v100) = 45;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
    }
  }
  std::wstring::wstring(&result, L"FF_ENHANCEMENT_2");
  LOBYTE(v100) = 103;
  v79 = INIReader::hasSection(&r, &result);
  LOBYTE(v100) = 45;
  v80 = v79;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  if ( v80 )
  {
    std::wstring::wstring(&v95, L"UNDERSTEER");
    LOBYTE(v100) = 104;
    std::wstring::wstring(&result, L"FF_ENHANCEMENT_2");
    LOBYTE(v100) = 105;
    this->useFakeUndersteerFF = INIReader::getInt(&r, &result, &v95) != 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
  }
  std::wstring::wstring(&result, L"FF_TWEAKS");
  LOBYTE(v100) = 106;
  v81 = INIReader::hasSection(&r, &result);
  LOBYTE(v100) = 45;
  v82 = v81;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  if ( v82 )
  {
    std::wstring::wstring(&v95, L"MIN_FF");
    LOBYTE(v100) = 107;
    std::wstring::wstring(&result, L"FF_TWEAKS");
    LOBYTE(v100) = 108;
    this->minFF = INIReader::getFloat(&r, &result, &v95);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v95);
    std::wstring::wstring(&v96, L"CENTER_BOOST_GAIN");
    LOBYTE(v100) = 109;
    std::wstring::wstring(&result, L"FF_TWEAKS");
    LOBYTE(v100) = 110;
    this->centerBoostGain = INIReader::getFloat(&r, &result, &v96);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v96);
    std::wstring::wstring(&v97, L"CENTER_BOOST_RANGE");
    LOBYTE(v100) = 111;
    std::wstring::wstring(&result, L"FF_TWEAKS");
    LOBYTE(v100) = 112;
    this->centerBoostRange = INIReader::getFloat(&r, &result, &v97);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v100) = 45;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97);
  }
  v83 = this->steer.device;
  if ( v83 )
  {
    v84 = InputDevice::getName(v83, &result);
    LOBYTE(v100) = 113;
    v85 = std::operator==<wchar_t>(v84, L"SideWinder Force Feedback Wheel (USB)");
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    if ( v85 )
    {
      _printf("WARNING: SideWinder Force Feedback Wheel (USB) detected, forcing ffInterval to 4\n");
      this->ffInterval = 4;
    }
  }
  LOBYTE(v100) = 39;
  INIReaderDocuments::~INIReaderDocuments(&r);
  LOBYTE(v100) = 36;
  INIReader::~INIReader(&vac);
}
void DICarControl::~DICarControl(DICarControl *this)
{
  InputDevice *v2; // ecx

  this->__vftable = (DICarControl_vtbl *)&DICarControl::`vftable';
  v2 = this->steer.device;
  if ( v2 )
    InputDevice::sendFF(v2, 0.0, 0.0);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->lastSpeed);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->shiftDnTrigger);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->shiftUpTrigger);
  FFPostProcessor::~FFPostProcessor(&this->ffPostProcessor);
  DIControlAxis::~DIControlAxis(&this->handBrakeAxis);
  DIControlButton::~DIControlButton(&this->handBrake);
  DIControlButton::~DIControlButton(&this->actionFlashHeadlights);
  DIControlButton::~DIControlButton(&this->actionHorn);
  DIControlButton::~DIControlButton(&this->actionChangeCamera);
  DIControlButton::~DIControlButton(&this->actionTurnOnHeadlights);
  DIControlButton::~DIControlButton(&this->MGUHMode);
  DIControlButton::~DIControlButton(&this->MGUKRecoveryDn);
  DIControlButton::~DIControlButton(&this->MGUKRecoveryUp);
  DIControlButton::~DIControlButton(&this->MGUKDeliveryDn);
  DIControlButton::~DIControlButton(&this->MGUKDeliveryUp);
  DIControlButton::~DIControlButton(&this->engineBrakeDn);
  DIControlButton::~DIControlButton(&this->engineBrakeUp);
  DIControlButton::~DIControlButton(&this->turboDn);
  DIControlButton::~DIControlButton(&this->turboUp);
  DIControlButton::~DIControlButton(&this->tcDn);
  DIControlButton::~DIControlButton(&this->tcUp);
  DIControlButton::~DIControlButton(&this->absDn);
  DIControlButton::~DIControlButton(&this->absUp);
  DIControlButton::~DIControlButton(&this->drs);
  DIControlButton::~DIControlButton(&this->kers);
  DIControlButton::~DIControlButton(&this->brakeBalanceDn);
  DIControlButton::~DIControlButton(&this->brakeBalanceUp);
  DIControlButton::~DIControlButton(&this->gearDn);
  DIControlButton::~DIControlButton(&this->gearUp);
  DIControlButton::~DIControlButton(&this->glanceBack);
  DIControlButton::~DIControlButton(&this->glanceRight);
  DIControlButton::~DIControlButton(&this->glanceLeft);
  DIControlAxis::~DIControlAxis(&this->clutch);
  DIControlAxis::~DIControlAxis(&this->brake);
  DIControlAxis::~DIControlAxis(&this->gas);
  DIControlAxis::~DIControlAxis(&this->steer);
  this->__vftable = (DICarControl_vtbl *)&ICarControlsProvider::`vftable';
}
DICarControl *DICarControl::`scalar deleting destructor'(DICarControl *this, unsigned int a2)
{
  DICarControl::~DICarControl(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge DICarControl::acquireControls(DICarControl *this@<ecx>, int a2@<edi>, CarControls *controls, float dt, CarControlsInput *input)
{
  float v6; // xmm2_4
  float v7; // xmm4_4
  int v8; // ecx
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm3_4
  float v13; // xmm3_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // ecx
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  bool v23; // zf
  float v24; // xmm0_4
  InputDevice *v25; // eax
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // ecx
  bool v34; // al
  bool v35; // al
  bool v36; // al
  bool v37; // al
  bool v38; // al
  bool v39; // al
  bool v40; // al
  bool v41; // al
  bool v42; // al
  bool v43; // al
  bool v44; // al
  bool v45; // al
  bool v46; // al
  bool v47; // al
  bool v48; // al
  bool v49; // al
  bool v50; // al
  bool v51; // al
  float dta; // [esp+64h] [ebp+8h]
  float dtb; // [esp+64h] [ebp+8h]
  float inputa; // [esp+68h] [ebp+Ch]
  float inputb; // [esp+68h] [ebp+Ch]
  float inputc; // [esp+68h] [ebp+Ch]
  float inputd; // [esp+68h] [ebp+Ch]
  float inpute; // [esp+68h] [ebp+Ch]
  float inputf; // [esp+68h] [ebp+Ch]
  float inputg; // [esp+68h] [ebp+Ch]
  float inputh; // [esp+68h] [ebp+Ch]
  float inputi; // [esp+68h] [ebp+Ch]
  float inputj; // [esp+68h] [ebp+Ch]
  float inputk; // [esp+68h] [ebp+Ch]
  float inputl; // [esp+68h] [ebp+Ch]
  float inputm; // [esp+68h] [ebp+Ch]
  float inputn; // [esp+68h] [ebp+Ch]
  float inputo; // [esp+68h] [ebp+Ch]
  float inputp; // [esp+68h] [ebp+Ch]
  float inputq; // [esp+68h] [ebp+Ch]
  float inputr; // [esp+68h] [ebp+Ch]
  float inputs; // [esp+68h] [ebp+Ch]
  float inputt; // [esp+68h] [ebp+Ch]
  float inputu; // [esp+68h] [ebp+Ch]
  float inputv; // [esp+68h] [ebp+Ch]
  float inputw; // [esp+68h] [ebp+Ch]
  float inputx; // [esp+68h] [ebp+Ch]
  float inputy; // [esp+68h] [ebp+Ch]
  float inputz; // [esp+68h] [ebp+Ch]
  float inputba; // [esp+68h] [ebp+Ch]
  float inputbb; // [esp+68h] [ebp+Ch]
  float inputbc; // [esp+68h] [ebp+Ch]
  float inputbd; // [esp+68h] [ebp+Ch]
  float inputbe; // [esp+68h] [ebp+Ch]
  float inputbf; // [esp+68h] [ebp+Ch]
  float inputbg; // [esp+68h] [ebp+Ch]
  float isKeyboardEnabled; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnableda; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnabledd; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnablede; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnabledf; // [esp+6Ch] [ebp+10h]
  int isKeyboardEnabledb; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnabledc; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnabledg; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnabledh; // [esp+6Ch] [ebp+10h]
  float isKeyboardEnabledi; // [esp+6Ch] [ebp+10h]

  if ( !this->validated )
    return;
  this->lastSpeed.value = input->speed.value;
  v6 = FLOAT_1_0;
  v7 = FLOAT_N1_0;
  isKeyboardEnabled = ((double (__stdcall *)(_DWORD, int))this->steer.getValue)(0, a2) * this->steerScale;
  if ( this->linearity == 1.0 )
  {
    v10 = isKeyboardEnabled;
  }
  else
  {
    LODWORD(v9) = __libm_sse2_powf(v8).m128_u32[0];
    v6 = FLOAT_1_0;
    if ( isKeyboardEnabled <= 0.0 )
    {
      v7 = FLOAT_N1_0;
      if ( isKeyboardEnabled >= 0.0 )
        v10 = 0.0 * v9;
      else
        v10 = -1.0 * v9;
    }
    else
    {
      v7 = FLOAT_N1_0;
      v10 = 1.0 * v9;
    }
  }
  v11 = this->steerLock;
  if ( v11 > input->steerLock )
    v10 = (float)(v11 / input->steerLock) * v10;
  v12 = this->speedSensitivity;
  if ( v12 != 0.0 )
    v10 = v10 / (float)((float)(v12 * input->speed.value) + v6);
  v13 = this->steerFilter;
  if ( v13 > 0.0 )
  {
    v15 = v13 * *(float *)&input;
    if ( v15 <= v6 )
    {
      if ( v15 < 0.0 )
        v15 = 0.0;
    }
    else
    {
      v15 = v6;
    }
    v10 = (float)((float)(v10 - *(float *)(LODWORD(dt) + 44)) * v15) + *(float *)(LODWORD(dt) + 44);
  }
  this->currentLock = v10;
  if ( v10 <= v6 )
  {
    if ( v7 <= v10 )
      v7 = v10;
  }
  else
  {
    v7 = v6;
  }
  *(float *)(LODWORD(dt) + 44) = v7;
  isKeyboardEnableda = this->gas.getValue(&this->gas, 1);
  v16 = isKeyboardEnableda;
  if ( isKeyboardEnableda >= 0.02 )
  {
    v17 = FLOAT_1_0;
    if ( isKeyboardEnableda <= 1.0 )
    {
      v17 = 0.0;
      if ( isKeyboardEnableda >= 0.0 )
        goto LABEL_28;
    }
  }
  else
  {
    v17 = 0.0;
  }
  v16 = v17;
LABEL_28:
  *(float *)(LODWORD(dt) + 36) = v16;
  ((double (*)(DIControlAxis *, int))this->brake.getValue)(&this->brake, 1);
  v19 = __libm_sse2_powf(v18).m128_f32[0];
  v20 = FLOAT_1_0;
  if ( v19 > 1.0 || (v20 = 0.0, v19 < 0.0) )
    v19 = v20;
  *(float *)(LODWORD(dt) + 40) = v19;
  isKeyboardEnabledd = this->clutch.getValue(&this->clutch, 1);
  v21 = isKeyboardEnabledd;
  if ( isKeyboardEnabledd < 0.02 )
    v21 = 0.0;
  v22 = 1.0 - v21;
  if ( (float)(1.0 - v21) <= 1.0 )
  {
    if ( v22 < 0.0 )
      v22 = 0.0;
  }
  else
  {
    v22 = FLOAT_1_0;
  }
  *(float *)(LODWORD(dt) + 48) = v22;
  isKeyboardEnablede = this->handBrake.getValue(&this->handBrake, 1);
  if ( isKeyboardEnablede != 0.0
    || (isKeyboardEnabledf = DIControlButton::getKeyboardValue(&this->handBrake, this->keyboardEnabled),
        v23 = isKeyboardEnabledf == 0.0,
        isKeyboardEnabledb = 0,
        !v23) )
  {
    isKeyboardEnabledb = 1;
  }
  v24 = FLOAT_1_0;
  isKeyboardEnabledc = ((double (*)(DIControlAxis *, int))this->handBrakeAxis.getValue)(
                         &this->handBrakeAxis,
                         1)
                     + (float)isKeyboardEnabledb;
  if ( isKeyboardEnabledc <= 1.0 )
  {
    v24 = 0.0;
    if ( isKeyboardEnabledc >= 0.0 )
      v24 = isKeyboardEnabledc;
  }
  *(float *)(LODWORD(dt) + 16) = v24;
  if ( this->shifter.isActive && *(_BYTE *)(LODWORD(dt) + 12) )
  {
    *(_DWORD *)(LODWORD(dt) + 8) = 1;
    v25 = DirectInput::getDevice(this->directInput, this->shifter.joy);
    if ( v25 )
    {
      v26 = this->shifter.buttons[0];
      if ( v26 != -1 && v25->state.buttons[v26] )
        *(_DWORD *)(LODWORD(dt) + 8) = 0;
      v27 = this->shifter.buttons[1];
      if ( v27 != -1 && v25->state.buttons[v27] )
        *(_DWORD *)(LODWORD(dt) + 8) = 2;
      v28 = this->shifter.buttons[2];
      if ( v28 != -1 && v25->state.buttons[v28] )
        *(_DWORD *)(LODWORD(dt) + 8) = 3;
      v29 = this->shifter.buttons[3];
      if ( v29 != -1 && v25->state.buttons[v29] )
        *(_DWORD *)(LODWORD(dt) + 8) = 4;
      v30 = this->shifter.buttons[4];
      if ( v30 != -1 && v25->state.buttons[v30] )
        *(_DWORD *)(LODWORD(dt) + 8) = 5;
      v31 = this->shifter.buttons[5];
      if ( v31 != -1 && v25->state.buttons[v31] )
        *(_DWORD *)(LODWORD(dt) + 8) = 6;
      v32 = this->shifter.buttons[6];
      if ( v32 != -1 && v25->state.buttons[v32] )
        *(_DWORD *)(LODWORD(dt) + 8) = 7;
      v33 = this->shifter.buttons[7];
      if ( v33 != -1 && v25->state.buttons[v33] )
        *(_DWORD *)(LODWORD(dt) + 8) = 8;
    }
  }
  else
  {
    *(_DWORD *)(LODWORD(dt) + 8) = -1;
    isKeyboardEnabledg = this->gearUp.getValue(&this->gearUp, 1);
    v34 = 1;
    if ( !Trigger::keepSteady(&this->shiftUpTrigger, *(float *)&input, isKeyboardEnabledg > 0.0) )
    {
      isKeyboardEnabledh = DIControlButton::getKeyboardValue(&this->gearUp, this->keyboardEnabled);
      if ( isKeyboardEnabledh == 0.0 )
        v34 = 0;
    }
    *(_BYTE *)LODWORD(dt) = v34;
    isKeyboardEnabledi = this->gearDn.getValue(&this->gearDn, 1);
    v35 = 1;
    if ( !Trigger::keepSteady(&this->shiftDnTrigger, *(float *)&input, isKeyboardEnabledi > 0.0) )
    {
      inputa = DIControlButton::getKeyboardValue(&this->gearDn, this->keyboardEnabled);
      if ( inputa == 0.0 )
        v35 = 0;
    }
    *(_BYTE *)(LODWORD(dt) + 1) = v35;
  }
  inputb = this->brakeBalanceDn.getValue(&this->brakeBalanceDn, 1);
  v36 = 1;
  if ( inputb == 0.0 )
  {
    inputc = DIControlButton::getKeyboardValue(&this->brakeBalanceDn, this->keyboardEnabled);
    if ( inputc == 0.0 )
      v36 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 5) = v36;
  inputd = this->brakeBalanceUp.getValue(&this->brakeBalanceUp, 1);
  v37 = 1;
  if ( inputd == 0.0 )
  {
    inpute = DIControlButton::getKeyboardValue(&this->brakeBalanceUp, this->keyboardEnabled);
    if ( inpute == 0.0 )
      v37 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 4) = v37;
  inputf = this->kers.getValue(&this->kers, 1);
  v38 = 1;
  if ( inputf == 0.0 )
  {
    inputg = DIControlButton::getKeyboardValue(&this->kers, this->keyboardEnabled);
    if ( inputg == 0.0 )
      v38 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 3) = v38;
  inputh = this->drs.getValue(&this->drs, 1);
  v39 = 1;
  if ( inputh == 0.0 )
  {
    inputi = DIControlButton::getKeyboardValue(&this->drs, this->keyboardEnabled);
    if ( inputi == 0.0 )
      v39 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 2) = v39;
  inputj = this->tcDn.getValue(&this->tcDn, 1);
  v40 = 1;
  if ( inputj == 0.0 )
  {
    inputk = DIControlButton::getKeyboardValue(&this->tcDn, this->keyboardEnabled);
    if ( inputk == 0.0 )
      v40 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 23) = v40;
  inputl = this->tcUp.getValue(&this->tcUp, 1);
  v41 = 1;
  if ( inputl == 0.0 )
  {
    inputm = DIControlButton::getKeyboardValue(&this->tcUp, this->keyboardEnabled);
    if ( inputm == 0.0 )
      v41 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 22) = v41;
  inputn = this->absDn.getValue(&this->absDn, 1);
  v42 = 1;
  if ( inputn == 0.0 )
  {
    inputo = DIControlButton::getKeyboardValue(&this->absDn, this->keyboardEnabled);
    if ( inputo == 0.0 )
      v42 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 21) = v42;
  inputp = this->absUp.getValue(&this->absUp, 1);
  v43 = 1;
  if ( inputp == 0.0 )
  {
    inputq = DIControlButton::getKeyboardValue(&this->absUp, this->keyboardEnabled);
    if ( inputq == 0.0 )
      v43 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 20) = v43;
  inputr = this->turboDn.getValue(&this->turboDn, 1);
  v44 = 1;
  if ( inputr == 0.0 )
  {
    inputs = DIControlButton::getKeyboardValue(&this->turboDn, this->keyboardEnabled);
    if ( inputs == 0.0 )
      v44 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 25) = v44;
  inputt = this->turboUp.getValue(&this->turboUp, 1);
  v45 = 1;
  if ( inputt == 0.0 )
  {
    inputu = DIControlButton::getKeyboardValue(&this->turboUp, this->keyboardEnabled);
    if ( inputu == 0.0 )
      v45 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 24) = v45;
  inputv = this->engineBrakeDn.getValue(&this->engineBrakeDn, 1);
  v46 = 1;
  if ( inputv == 0.0 )
  {
    inputw = DIControlButton::getKeyboardValue(&this->engineBrakeDn, this->keyboardEnabled);
    if ( inputw == 0.0 )
      v46 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 27) = v46;
  inputx = this->engineBrakeUp.getValue(&this->engineBrakeUp, 1);
  v47 = 1;
  if ( inputx == 0.0 )
  {
    inputy = DIControlButton::getKeyboardValue(&this->engineBrakeUp, this->keyboardEnabled);
    if ( inputy == 0.0 )
      v47 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 26) = v47;
  inputz = this->MGUKRecoveryDn.getValue(&this->MGUKRecoveryDn, 1);
  v48 = 1;
  if ( inputz == 0.0 )
  {
    inputba = DIControlButton::getKeyboardValue(&this->MGUKRecoveryDn, this->keyboardEnabled);
    if ( inputba == 0.0 )
      v48 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 31) = v48;
  inputbb = this->MGUKRecoveryUp.getValue(&this->MGUKRecoveryUp, 1);
  v49 = 1;
  if ( inputbb == 0.0 )
  {
    inputbc = DIControlButton::getKeyboardValue(&this->MGUKRecoveryUp, this->keyboardEnabled);
    if ( inputbc == 0.0 )
      v49 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 30) = v49;
  inputbd = this->MGUKDeliveryDn.getValue(&this->MGUKDeliveryDn, 1);
  v50 = 1;
  if ( inputbd == 0.0 )
  {
    inputbe = DIControlButton::getKeyboardValue(&this->MGUKDeliveryDn, this->keyboardEnabled);
    if ( inputbe == 0.0 )
      v50 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 29) = v50;
  inputbf = this->MGUKDeliveryUp.getValue(&this->MGUKDeliveryUp, 1);
  v51 = 1;
  if ( inputbf == 0.0 )
  {
    inputbg = DIControlButton::getKeyboardValue(&this->MGUKDeliveryUp, this->keyboardEnabled);
    if ( inputbg == 0.0 )
      v51 = 0;
  }
  *(_BYTE *)(LODWORD(dt) + 28) = v51;
  dta = this->MGUHMode.getValue(&this->MGUHMode, 1);
  *(_BYTE *)(LODWORD(dt) + 32) = dta != 0.0
                              || (dtb = DIControlButton::getKeyboardValue(&this->MGUHMode, this->keyboardEnabled),
                                  dtb != 0.0);
}
bool DICarControl::getAction(DICarControl *this, DriverActions anAction)
{
  float v3; // xmm0_4
  bool result; // al
  float anActiona; // [esp+Ch] [ebp+4h]
  float anActionb; // [esp+Ch] [ebp+4h]
  float anActionc; // [esp+Ch] [ebp+4h]
  float anActiond; // [esp+Ch] [ebp+4h]
  float anActione; // [esp+Ch] [ebp+4h]
  float anActionf; // [esp+Ch] [ebp+4h]
  float anActiong; // [esp+Ch] [ebp+4h]
  float anActionh; // [esp+Ch] [ebp+4h]
  float anActioni; // [esp+Ch] [ebp+4h]
  float anActionj; // [esp+Ch] [ebp+4h]
  float anActionk; // [esp+Ch] [ebp+4h]
  float anActionl; // [esp+Ch] [ebp+4h]
  float anActionm; // [esp+Ch] [ebp+4h]
  float anActionn; // [esp+Ch] [ebp+4h]

  switch ( anAction )
  {
    case eLookingLeft:
      anActiong = this->glanceLeft.getValue(&this->glanceLeft, 1);
      if ( anActiong > 0.0 )
        goto LABEL_6;
      anActionh = DIControlButton::getKeyboardValue(&this->glanceLeft, this->keyboardEnabled);
      v3 = anActionh;
      break;
    case eLookingRight:
      anActioni = this->glanceRight.getValue(&this->glanceRight, 1);
      if ( anActioni > 0.0 )
        goto LABEL_6;
      anActionj = DIControlButton::getKeyboardValue(&this->glanceRight, this->keyboardEnabled);
      v3 = anActionj;
      break;
    case eHeadlightsSwitch:
      anActione = this->actionTurnOnHeadlights.getValue(&this->actionTurnOnHeadlights, 1);
      if ( anActione > 0.0 )
        goto LABEL_6;
      anActionf = DIControlButton::getKeyboardValue(&this->actionTurnOnHeadlights, this->keyboardEnabled);
      v3 = anActionf;
      break;
    case eChangingCamera:
      anActiona = this->actionChangeCamera.getValue(&this->actionChangeCamera, 1);
      if ( anActiona > 0.0 )
        goto LABEL_6;
      anActionb = DIControlButton::getKeyboardValue(&this->actionChangeCamera, this->keyboardEnabled);
      v3 = anActionb;
      break;
    case eHorn:
      anActionm = this->actionHorn.getValue(&this->actionHorn, 1);
      if ( anActionm > 0.0 )
        goto LABEL_6;
      anActionn = DIControlButton::getKeyboardValue(&this->actionHorn, this->keyboardEnabled);
      v3 = anActionn;
      break;
    case eLookingBack:
      anActionk = this->glanceBack.getValue(&this->glanceBack, 1);
      if ( anActionk > 0.0 )
        goto LABEL_6;
      anActionl = DIControlButton::getKeyboardValue(&this->glanceBack, this->keyboardEnabled);
      v3 = anActionl;
      break;
    case eHeadlightsFlash:
      anActionc = this->actionFlashHeadlights.getValue(&this->actionFlashHeadlights, 1);
      if ( anActionc > 0.0 )
        goto LABEL_6;
      anActiond = DIControlButton::getKeyboardValue(&this->actionFlashHeadlights, this->keyboardEnabled);
      v3 = anActiond;
      break;
    default:
      return 0;
  }
  if ( v3 == 0.0 )
    result = 0;
  else
LABEL_6:
    result = 1;
  return result;
}
double DICarControl::getFFGlobalGain(DICarControl *this)
{
  return this->ffGain;
}
const char *DICarControl::getName(DICarControl *this)
{
  return "Kunos Simulazioni DirectInput controls provider";
}
void DICarControl::initShifter(DICarControl *this, INIReader *ini)
{
  int v3; // eax
  bool v4; // cf
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  std::wstring section; // [esp+Ch] [ebp-70h] BYREF
  std::wstring key; // [esp+24h] [ebp-58h] BYREF
  std::wstring v16; // [esp+3Ch] [ebp-40h] BYREF
  std::wstring v17; // [esp+54h] [ebp-28h] BYREF
  int v18; // [esp+78h] [ebp-4h]

  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ACTIVE", 6u);
  v18 = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SHIFTER", 7u);
  LOBYTE(v18) = 1;
  v3 = INIReader::getInt(ini, &section, &key);
  v4 = section._Myres < 8;
  this->shifter.isActive = v3 != 0;
  if ( !v4 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  v18 = -1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->shifter.isActive )
  {
    this->shifter.isShifterPrefered = 1;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"JOY", 3u);
    v18 = 2;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 3;
    v5 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.joy = v5;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GEAR_R", 6u);
    v18 = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 5;
    v6 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.buttons[0] = v6;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GEAR_1", 6u);
    v18 = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 7;
    v7 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.buttons[1] = v7;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GEAR_2", 6u);
    v18 = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 9;
    v8 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.buttons[2] = v8;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GEAR_3", 6u);
    v18 = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 11;
    v9 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.buttons[3] = v9;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GEAR_4", 6u);
    v18 = 12;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 13;
    v10 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.buttons[4] = v10;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GEAR_5", 6u);
    v18 = 14;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 15;
    v11 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.buttons[5] = v11;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GEAR_6", 6u);
    v18 = 16;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SHIFTER", 7u);
    LOBYTE(v18) = 17;
    v12 = INIReader::getInt(ini, &section, &key);
    v4 = section._Myres < 8;
    this->shifter.buttons[6] = v12;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v18 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    std::wstring::assign(&v17, L"GEAR_7", 6u);
    v18 = 18;
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    std::wstring::assign(&v16, L"SHIFTER", 7u);
    LOBYTE(v18) = 19;
    v13 = INIReader::getInt(ini, &v16, &v17);
    v4 = v16._Myres < 8;
    this->shifter.buttons[7] = v13;
    if ( !v4 )
      operator delete(v16._Bx._Ptr);
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    if ( v17._Myres >= 8 )
      operator delete(v17._Bx._Ptr);
  }
}
void DICarControl::onAutoShifterChanged(DICarControl *this, bool newmode)
{
  if ( newmode )
  {
    this->shifter.isActive = 0;
  }
  else if ( this->shifter.isShifterPrefered )
  {
    this->shifter.isActive = 1;
  }
}
void DICarControl::sendFF(DICarControl *this, float ff, float damper, float userGain)
{
  double v5; // st7
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  int v13; // eax
  bool v14; // zf
  float v15; // xmm1_4
  float v; // xmm0_4
  float v17; // [esp+10h] [ebp-4h]
  float ffa; // [esp+18h] [ebp+4h]
  float ffb; // [esp+18h] [ebp+4h]

  if ( this->validated )
  {
    v5 = ((double (*)(DIControlAxis *, _DWORD))this->steer.getValue)(&this->steer, 0);
    v6 = this->centerBoostGain;
    v17 = v5;
    LODWORD(v7) = LODWORD(v17) & _xmm;
    if ( v6 == 0.0 || (v8 = this->centerBoostRange, v8 <= v7) )
      v9 = ff;
    else
      v9 = (float)((float)(1.0 - (float)(v7 / v8)) * v6) * ff;
    v10 = (float)((float)(this->lastSpeed.value * 3.5999999) - 1.0) * 0.2;
    if ( v10 <= 1.0 )
    {
      if ( v10 < 0.0 )
        v10 = 0.0;
    }
    else
    {
      v10 = FLOAT_1_0;
    }
    v11 = this->minFF * v10;
    if ( v11 > COERCE_FLOAT(LODWORD(v9) & _xmm) )
    {
      if ( v9 <= 0.0 )
      {
        if ( v9 >= 0.0 )
          v12 = 0.0;
        else
          v12 = FLOAT_N1_0;
      }
      else
      {
        v12 = FLOAT_1_0;
      }
      v9 = v12 * v11;
    }
    v13 = this->ffCounter;
    if ( v13 < this->ffInterval )
    {
      this->ffCounter = v13 + 1;
    }
    else
    {
      v14 = !this->ffEnabled;
      this->ffCounter = 0;
      if ( v14 )
        v9 = 0.0;
      if ( this->steer.device )
      {
        if ( this->useSoftLock && COERCE_FLOAT(LODWORD(this->currentLock) & _xmm) > 1.0 )
        {
          v15 = FLOAT_1_0;
          ffa = sign<float>(&this->currentLock);
          v = ffa;
        }
        else
        {
          v = (float)((float)(this->currentVibration + v9) * this->ffGain) * userGain;
          if ( this->ffPostProcessor.enabled )
          {
            ffb = FFPostProcessor::getProcessedFF(&this->ffPostProcessor, v);
            v = ffb;
          }
          v15 = damper;
        }
        InputDevice::sendFF(this->steer.device, v, v15);
      }
    }
  }
}
void DICarControl::setEngineRPM(DICarControl *this, float rpm, float minRpm, float maxRpm)
{
  InputDevice *v4; // ecx

  v4 = this->steer.device;
  if ( v4 )
    InputDevice::setG27Leds(v4, rpm, minRpm, maxRpm);
}
void DICarControl::setVibrations(DICarControl *this, const VibrationDef *vibrations)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = (float)((float)((float)(this->ffUpgrades.gforceGain * vibrations->gforce)
                     + (float)(this->ffUpgrades.curbsGain * vibrations->curbs))
             + (float)(this->ffUpgrades.slipsGain * vibrations->slips))
     + (float)(this->ffUpgrades.absGain * vibrations->abs);
  v3 = FLOAT_1_0;
  if ( v2 > 1.0 || (v3 = FLOAT_N1_0, v2 < -1.0) )
    this->currentVibration = v3;
  else
    this->currentVibration = v2;
}
void DICarControl::validate(DICarControl *this)
{
  std::wstring v2; // [esp-1Ch] [ebp-44h] BYREF
  int v3; // [esp-4h] [ebp-2Ch]
  ksSecurity sec; // [esp+Ch] [ebp-1Ch] BYREF
  int v5; // [esp+24h] [ebp-4h]

  ksSecurity::ksSecurity(&sec);
  v3 = 2;
  v5 = 0;
  v2._Myres = 7;
  v2._Mysize = 0;
  v2._Bx._Buf[0] = 0;
  std::wstring::assign(&v2, L"base", 4u);
  this->validated = ksSecurity::validate(&sec, v2, v3);
  v5 = -1;
  ksSecurity::~ksSecurity(&sec);
}
