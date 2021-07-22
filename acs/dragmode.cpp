#include "dragmode.h
void DragMode::DragMode(DragMode *this, Sim *aSim)
{
  std::_Tree_node<std::pair<CarAvatar * const,std::vector<Lap> >,void *> *v3; // eax
  unsigned int v4; // eax
  bool v5; // cf
  Font *v6; // eax
  Font *v7; // eax
  volatile signed __int32 *v8; // esi
  Sim *v9; // ebp
  GameObject **v10; // esi
  TrackAvatar *v11; // edi
  mat44f *v12; // eax
  mat44f *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  Sim *v17; // eax
  int v18; // eax
  int v19; // eax
  Sim *v20; // eax
  int v21; // eax
  float *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DragMode::DragStatus> > > v25; // xmm4_4
  unsigned int v26; // esi
  float v27; // xmm5_4
  float v28; // xmm6_4
  DragMode::DragStatus *v29; // xmm7_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DragMode::DragStatus> > > v32; // xmm4_4
  float v33; // xmm0_4
  Sim *v34; // ecx
  unsigned int i; // esi
  Sim *v36; // ecx
  CarAvatar *v37; // eax
  Event<OnNewSessionEvent> *v38; // ecx
  Sim *v39; // eax
  Texture *v40; // eax
  Sim *v41; // eax
  Texture *v42; // eax
  Sim *v43; // eax
  Texture *v44; // eax
  Sim *v45; // eax
  Texture *v46; // eax
  Sim *v47; // eax
  Texture *v48; // eax
  Sim *v49; // eax
  Texture *v50; // eax
  Sim *v51; // eax
  Texture *v52; // eax
  Sim *v53; // eax
  Texture *v54; // eax
  Sim *v55; // eax
  long double v56; // st7
  DragMode::DragStatus *v57; // eax
  _BYTE v58[56]; // [esp+0h] [ebp-12Ch] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DragMode::DragStatus> > > _S17; // [esp+40h] [ebp-ECh] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DragMode::DragStatus> > > _S18; // [esp+44h] [ebp-E8h] BYREF
  float v61; // [esp+48h] [ebp-E4h]
  float v62; // [esp+4Ch] [ebp-E0h]
  float v63; // [esp+50h] [ebp-DCh]
  float v64; // [esp+54h] [ebp-D8h]
  float v65; // [esp+58h] [ebp-D4h]
  float v66; // [esp+5Ch] [ebp-D0h]
  DragMode *v67; // [esp+60h] [ebp-CCh]
  mat44f result; // [esp+64h] [ebp-C8h] BYREF
  std::wstring key; // [esp+A4h] [ebp-88h] BYREF
  Texture section; // [esp+BCh] [ebp-70h] BYREF
  INIReaderDocuments raceINI; // [esp+D8h] [ebp-54h] BYREF
  int v72; // [esp+128h] [ebp-4h]

  v67 = this;
  *(_DWORD *)&v58[24] = aSim->game;
  *(_DWORD *)&v58[20] = 7;
  *(_DWORD *)&v58[16] = 0;
  *(_WORD *)v58 = 0;
  std::wstring::assign((std::wstring *)v58, L"DRAG_MODE", 9u);
  GameMode::GameMode(this, *(std::wstring *)v58, *(Game **)&v58[24]);
  this->__vftable = (DragMode_vtbl *)&DragMode::`vftable';
  v72 = 0;
  this->lapTimes._Myhead = 0;
  this->lapTimes._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::pair<unsigned int,std::pair<unsigned int,float>> const,FW1FontWrapper::CFW1GlyphProvider::GlyphMap *>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::pair<unsigned int,std::pair<unsigned int,float> > const ,FW1FontWrapper::CFW1GlyphProvider::GlyphMap *>> > *)&this->lapTimes);
  this->lapTimes._Myhead = v3;
  this->carStatus._Myfirst = 0;
  this->carStatus._Mylast = 0;
  this->carStatus._Myend = 0;
  this->status = eDragStill;
  this->sim = aSim;
  this->font._Ptr = 0;
  this->font._Rep = 0;
  this->matchNumber = 5;
  this->startTime = 0.0;
  this->nullCounter = 0.0;
  this->semaphore = 0;
  this->texTree.kid = 0;
  this->texTree.fileName._Myres = 7;
  this->texTree.fileName._Mysize = 0;
  this->texTree.fileName._Bx._Buf[0] = 0;
  this->texTime.kid = 0;
  this->texTime.fileName._Myres = 7;
  this->texTime.fileName._Mysize = 0;
  this->texTime.fileName._Bx._Buf[0] = 0;
  this->texPlayerCar.kid = 0;
  this->texPlayerCar.fileName._Myres = 7;
  this->texPlayerCar.fileName._Mysize = 0;
  this->texPlayerCar.fileName._Bx._Buf[0] = 0;
  this->texAICar.kid = 0;
  this->texAICar.fileName._Myres = 7;
  this->texAICar.fileName._Mysize = 0;
  this->texAICar.fileName._Bx._Buf[0] = 0;
  this->texTrack.kid = 0;
  this->texTrack.fileName._Myres = 7;
  this->texTrack.fileName._Mysize = 0;
  this->texTrack.fileName._Bx._Buf[0] = 0;
  this->texFinishSpeed.kid = 0;
  this->texFinishSpeed.fileName._Myres = 7;
  this->texFinishSpeed.fileName._Mysize = 0;
  this->texFinishSpeed.fileName._Bx._Buf[0] = 0;
  this->texFalseStart.kid = 0;
  this->texFalseStart.fileName._Myres = 7;
  this->texFalseStart.fileName._Mysize = 0;
  this->texFalseStart.fileName._Bx._Buf[0] = 0;
  this->texDisqualified.kid = 0;
  this->texDisqualified.fileName._Myres = 7;
  this->texDisqualified.fileName._Mysize = 0;
  this->texDisqualified.fileName._Bx._Buf[0] = 0;
  LOBYTE(v72) = 11;
  InterpolatingSpline::InterpolatingSpline(&this->trackSpline);
  *(_DWORD *)&v58[24] = 0;
  this->countDown = 0.0;
  LOBYTE(v72) = 12;
  *(_DWORD *)&v58[20] = 7;
  *(_DWORD *)&v58[16] = 0;
  *(_WORD *)v58 = 0;
  std::wstring::assign((std::wstring *)v58, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&raceINI, (unsigned int)this, *(std::wstring *)v58, v58[24]);
  LOBYTE(v72) = 13;
  if ( raceINI.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MATCHES", 7u);
    LOBYTE(v72) = 14;
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    std::wstring::assign((std::wstring *)&section, L"SESSION_0", 9u);
    LOBYTE(v72) = 15;
    v4 = INIReader::getInt(&raceINI, (const std::wstring *)&section, &key);
    v5 = section.fileName._Mysize < 8;
    this->matchNumber = v4;
    if ( !v5 )
      operator delete(section.kid);
    section.fileName._Mysize = 7;
    *(_DWORD *)&section.fileName._Bx._Alias[12] = 0;
    LOWORD(section.kid) = 0;
    LOBYTE(v72) = 13;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  PauseMenu::blankButton(this->sim->pauseMenu, ePauseMenuPits, 1);
  v6 = (Font *)operator new(24);
  section.kid = v6;
  LOBYTE(v72) = 16;
  if ( v6 )
    Font::Font(v6, eFontMonospaced, 45.0, 0, 0);
  else
    v7 = 0;
  LOBYTE(v72) = 13;
  *(_QWORD *)&section.kid = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&section, v7);
  std::shared_ptr<Font>::operator=(&this->font, (std::shared_ptr<Font> *)&section);
  v8 = (volatile signed __int32 *)section.fileName._Bx._Ptr;
  if ( section.fileName._Bx._Ptr )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)section.fileName._Bx._Ptr + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v8)(v8);
      if ( !_InterlockedDecrement(v8 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v8 + 4))(v8);
    }
  }
  v9 = this->sim;
  this->trackSpline.interpolationMode = eLinear;
  v10 = v9->gameObjects._Myfirst;
  if ( v10 == v9->gameObjects._Mylast )
  {
LABEL_16:
    v11 = 0;
  }
  else
  {
    while ( 1 )
    {
      v11 = (TrackAvatar *)__RTDynamicCast(
                             *v10,
                             0,
                             &GameObject `RTTI Type Descriptor',
                             &TrackAvatar `RTTI Type Descriptor',
                             0);
      if ( v11 )
        break;
      if ( ++v10 == v9->gameObjects._Mylast )
        goto LABEL_16;
    }
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"START", 5u);
  LOBYTE(v72) = 17;
  v12 = TrackAvatar::getSpawnPosition(v11, &result, &key, 0);
  LOBYTE(v72) = 13;
  _S18._Ptr = (DragMode::DragStatus *)LODWORD(v12->M41);
  v62 = v12->M42;
  _S17._Ptr = (DragMode::DragStatus *)LODWORD(v12->M43);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"START", 5u);
  LOBYTE(v72) = 18;
  v13 = TrackAvatar::getSpawnPosition(v11, &result, &key, 1u);
  LOBYTE(v72) = 13;
  v14 = v13->M41;
  v15 = v13->M42;
  v16 = v13->M43;
  v64 = v14;
  v63 = v15;
  v61 = v16;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v14 = v64;
    v15 = v63;
  }
  key._Myres = 7;
  key._Mysize = 0;
  v64 = (float)(v14 + *(float *)&_S18._Ptr) * 0.5;
  v63 = (float)(v15 + v62) * 0.5;
  *(float *)&_S17._Ptr = (float)(*(float *)&_S17._Ptr + v61) * 0.5;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"AC_OPEN_FINISH_L", 0x10u);
  v17 = this->sim;
  LOBYTE(v72) = 19;
  v18 = (int)v17->trackNode->findChildByName(v17->trackNode, &key, 1);
  v19 = (*(int (**)(int, mat44f *))(*(_DWORD *)v18 + 32))(v18, &result);
  LOBYTE(v72) = 13;
  v65 = *(float *)(v19 + 48);
  v66 = *(float *)(v19 + 52);
  section.kid = *(void **)(v19 + 56);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"AC_OPEN_FINISH_R", 0x10u);
  v20 = this->sim;
  LOBYTE(v72) = 20;
  v21 = (int)v20->trackNode->findChildByName(v20->trackNode, &key, 1);
  v22 = (float *)(*(int (**)(int, mat44f *))(*(_DWORD *)v21 + 32))(v21, &result);
  LOBYTE(v72) = 13;
  v23 = v22[12];
  v24 = v22[13];
  v25._Ptr = (DragMode::DragStatus *)v22[14];
  v61 = v23;
  v62 = v24;
  _S18._Ptr = v25._Ptr;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v23 = v61;
    v24 = v62;
    v25._Ptr = _S18._Ptr;
  }
  v26 = 0;
  v27 = v64;
  v28 = v63;
  v29 = _S17._Ptr;
  v30 = (float)((float)(v23 + v65) * 0.5) - v64;
  v31 = (float)((float)(v24 + v66) * 0.5) - v63;
  *(float *)&v32._Ptr = (float)((float)(*(float *)&v25._Ptr + *(float *)&section.kid) * 0.5) - *(float *)&_S17._Ptr;
  v61 = v30;
  v62 = v31;
  _S18._Ptr = v32._Ptr;
  do
  {
    v33 = (float)v26 * 0.0099999998;
    *(float *)&section.kid = (float)(v30 * v33) + v27;
    *(float *)&section.fileName._Bx._Ptr = (float)(v31 * v33) + v28;
    *(float *)&section.fileName._Bx._Alias[4] = (float)(*(float *)&v32._Ptr * v33) + *(float *)&v29;
    InterpolatingSpline::addPoint(&this->trackSpline, (const vec3f *)&section, 0);
    v30 = v61;
    ++v26;
    v31 = v62;
    v32._Ptr = _S18._Ptr;
    v27 = v64;
    v28 = v63;
    v29 = _S17._Ptr;
  }
  while ( v26 <= 0x64 );
  InterpolatingSpline::computeSplineLength(&this->trackSpline);
  *(_DWORD *)&v58[4] = &std::_Func_impl<std::_Callable_obj<_lambda_fe3e2d2911d89ff42537cca7524c0bb0_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  *(_DWORD *)&v58[8] = this;
  *(_DWORD *)&v58[20] = &v58[4];
  v34 = this->sim;
  LOBYTE(v72) = 13;
  PhysicsAvatar::executeOnPhysicsThread(v34->physicsAvatar, *(std::function<void __cdecl(void)> *)&v58[4]);
  for ( i = 0; i < this->sim->cars._Mylast - this->sim->cars._Myfirst; ++i )
  {
    *(_DWORD *)&v58[24] = this;
    section.kid = v58;
    *(_DWORD *)v58 = &std::_Func_impl<std::_Callable_obj<_lambda_948c74b361cec92a1e3318daa7f0ad7e_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
    *(_DWORD *)&v58[4] = this;
    *(_DWORD *)&v58[16] = v58;
    v36 = this->sim;
    LOBYTE(v72) = 23;
    v37 = Sim::getCar(v36, i);
    LOBYTE(v72) = 13;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v37->evOnLapCompleted,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v58,
      *(void **)&v58[24]);
  }
  *(_DWORD *)&v58[24] = this;
  *(_DWORD *)v58 = &std::_Func_impl<std::_Callable_obj<_lambda_fe2febafcb0d0c7b4a2860cec11fef99_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v58[4] = this;
  *(_DWORD *)&v58[16] = v58;
  v38 = &this->sim->evOnNewSession;
  LOBYTE(v72) = 13;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v38,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v58,
    this);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/xmas_tree.png", 0x1Eu);
  v39 = this->sim;
  LOBYTE(v72) = 25;
  v40 = ResourceStore::getTexture(v39->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texTree.kid = v40->kid;
  LOBYTE(v72) = 26;
  if ( &this->texTree.fileName != &v40->fileName )
    std::wstring::assign(&this->texTree.fileName, &v40->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 25;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v72) = 13;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/time_icon.png", 0x1Eu);
  v41 = this->sim;
  LOBYTE(v72) = 27;
  v42 = ResourceStore::getTexture(v41->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texTime.kid = v42->kid;
  LOBYTE(v72) = 28;
  if ( &this->texTime.fileName != &v42->fileName )
    std::wstring::assign(&this->texTime.fileName, &v42->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 27;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v72) = 13;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/player_car.png", 0x1Fu);
  v43 = this->sim;
  LOBYTE(v72) = 29;
  v44 = ResourceStore::getTexture(v43->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texPlayerCar.kid = v44->kid;
  LOBYTE(v72) = 30;
  if ( &this->texPlayerCar.fileName != &v44->fileName )
    std::wstring::assign(&this->texPlayerCar.fileName, &v44->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 29;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v72) = 13;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/ai_car.png", 0x1Bu);
  v45 = this->sim;
  LOBYTE(v72) = 31;
  v46 = ResourceStore::getTexture(v45->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texAICar.kid = v46->kid;
  LOBYTE(v72) = 32;
  if ( &this->texAICar.fileName != &v46->fileName )
    std::wstring::assign(&this->texAICar.fileName, &v46->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 31;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v72) = 13;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/race_straightline.png", 0x26u);
  v47 = this->sim;
  LOBYTE(v72) = 33;
  v48 = ResourceStore::getTexture(v47->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texTrack.kid = v48->kid;
  LOBYTE(v72) = 34;
  if ( &this->texTrack.fileName != &v48->fileName )
    std::wstring::assign(&this->texTrack.fileName, &v48->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 33;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v72) = 13;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/speed_icon.png", 0x1Fu);
  v49 = this->sim;
  LOBYTE(v72) = 35;
  v50 = ResourceStore::getTexture(v49->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texFinishSpeed.kid = v50->kid;
  LOBYTE(v72) = 36;
  if ( &this->texFinishSpeed.fileName != &v50->fileName )
    std::wstring::assign(&this->texFinishSpeed.fileName, &v50->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 35;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v72) = 13;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/disqualified.png", 0x21u);
  v51 = this->sim;
  LOBYTE(v72) = 37;
  v52 = ResourceStore::getTexture(v51->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texDisqualified.kid = v52->kid;
  LOBYTE(v72) = 38;
  if ( &this->texDisqualified.fileName != &v52->fileName )
    std::wstring::assign(&this->texDisqualified.fileName, &v52->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 37;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  LOBYTE(v72) = 13;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/drag/false_start.png", 0x20u);
  v53 = this->sim;
  LOBYTE(v72) = 39;
  v54 = ResourceStore::getTexture(v53->game->graphics->resourceStore._Myptr, &section, &key, 0);
  this->texFalseStart.kid = v54->kid;
  LOBYTE(v72) = 40;
  if ( &this->texFalseStart.fileName != &v54->fileName )
    std::wstring::assign(&this->texFalseStart.fileName, &v54->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v72) = 39;
  OnSetupAppCreated::~OnSetupAppCreated(&section);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  *(_DWORD *)&v58[24] = this;
  *(_DWORD *)v58 = &std::_Func_impl<std::_Callable_obj<_lambda_935505485ff394ee7ad7c4e49c35124d_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v58[4] = this;
  *(_DWORD *)&v58[16] = v58;
  v55 = this->sim;
  LOBYTE(v72) = 13;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v55->escMenu->evOnDriveMenuPressed,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v58,
    this);
  v56 = DragMode::generateStartTime(this);
  *(_DWORD *)&v58[24] = &_S17;
  this->startTime = v56;
  std::vector<SetupTab *>::begin(
    (std::vector<TyreCompoundDef> *)&this->carStatus,
    *(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > **)&v58[24]);
  std::vector<Mesh *>::end(
    (std::vector<TyreCompoundDef> *)&this->carStatus,
    (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S18);
  while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
            (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17,
            (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S18) )
  {
    v57 = (DragMode::DragStatus *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S17);
    DragMode::DragStatus::reset(v57, this->startTime);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DragMode::DragStatus>>>::operator++(&_S17);
  }
  LOBYTE(v72) = 12;
  INIReaderDocuments::~INIReaderDocuments(&raceINI);
}
void DragMode::~DragMode(DragMode *this)
{
  std::_Ref_count_base *v2; // esi
  bool v3; // zf
  std::vector<DragMode::DragStatus> *v4; // esi
  std::_Tree_node<std::pair<CarAvatar * const,std::vector<Lap> >,void *> *v5; // [esp-4h] [ebp-28h]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,std::vector<Lap> > > > > result; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  this->__vftable = (DragMode_vtbl *)&DragMode::`vftable';
  v7 = 3;
  InterpolatingSpline::~InterpolatingSpline(&this->trackSpline);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texDisqualified);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texFalseStart);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texFinishSpeed);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texTrack);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texAICar);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texPlayerCar);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texTime);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texTree);
  v2 = this->font._Rep;
  LOBYTE(v7) = 2;
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Uses, 0xFFFFFFFF) )
    {
      v2->_Destroy(v2);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v2->_Weaks) )
        v2->_Delete_this(v2);
    }
  }
  v3 = this->carStatus._Myfirst == 0;
  v4 = &this->carStatus;
  LOBYTE(v7) = 1;
  if ( !v3 )
  {
    std::_Container_base0::_Orphan_all(&this->carStatus);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->carStatus._Mylast = 0;
    this->carStatus._Myend = 0;
  }
  v5 = this->lapTimes._Myhead;
  LOBYTE(v7) = 0;
  std::_Tree<std::_Tmap_traits<CarAvatar *,std::vector<Lap>,std::less<CarAvatar *>,std::allocator<std::pair<CarAvatar * const,std::vector<Lap>>>,0>>::erase(
    &this->lapTimes,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,std::vector<Lap> > > > >)v5->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,std::vector<Lap> > > > >)v5);
  operator delete(this->lapTimes._Myhead);
  v7 = -1;
  GameMode::~GameMode(this);
}
DragMode *DragMode::`scalar deleting destructor'(DragMode *this, unsigned int a2)
{
  DragMode::~DragMode(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DragMode::computeCarTimes(DragMode *this)
{
  DragMode::DragStatus *v2; // eax
  float v3; // xmm0_4
  bool v4; // zf
  unsigned int *v5; // ecx
  CarAvatar **v6; // eax
  DragMode::DragStatus *v7; // eax
  unsigned int *v8; // ecx
  CarAvatar **v9; // eax
  CarAvatar *v10; // [esp+Ch] [ebp-78h] BYREF
  CarAvatar *_Keyval; // [esp+10h] [ebp-74h] BYREF
  Lap aiLap; // [esp+14h] [ebp-70h] BYREF
  Lap playerLap; // [esp+44h] [ebp-40h] BYREF
  int v14; // [esp+80h] [ebp-4h]

  v2 = this->carStatus._Myfirst;
  v3 = v2->playerTime;
  v10 = (CarAvatar *)LODWORD(v2[1].playerTime);
  playerLap.splits._Myfirst = 0;
  playerLap.splits._Mylast = 0;
  playerLap.splits._Myend = 0;
  playerLap.compound._Myres = 7;
  playerLap.compound._Mysize = 0;
  playerLap.compound._Bx._Buf[0] = 0;
  playerLap.time = 0;
  playerLap.isValid = 0;
  playerLap.cuts = 0;
  v14 = 0;
  if ( !v2->disqualified || (v4 = !v2->falseStart, playerLap.isValid = 0, v4) )
    playerLap.isValid = 1;
  playerLap.time = (unsigned int)(float)(v3 * 1000.0);
  std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&playerLap.splits, 1u);
  v5 = playerLap.splits._Mylast;
  if ( playerLap.splits._Mylast )
  {
    *playerLap.splits._Mylast = playerLap.time;
    v5 = playerLap.splits._Mylast;
  }
  playerLap.splits._Mylast = v5 + 1;
  _Keyval = Sim::getCar(this->sim, 0);
  v6 = std::map<CarAvatar *,std::vector<Lap>>::operator[](&this->lapTimes, &_Keyval);
  std::vector<Lap>::push_back((std::vector<Lap> *)v6, &playerLap);
  aiLap.splits._Myfirst = 0;
  aiLap.splits._Mylast = 0;
  aiLap.splits._Myend = 0;
  aiLap.compound._Myres = 7;
  aiLap.compound._Mysize = 0;
  aiLap.compound._Bx._Buf[0] = 0;
  aiLap.time = 0;
  aiLap.isValid = 0;
  aiLap.cuts = 0;
  v7 = this->carStatus._Myfirst;
  LOBYTE(v14) = 1;
  if ( !v7[1].disqualified || (v4 = !v7[1].falseStart, aiLap.isValid = 0, v4) )
    aiLap.isValid = 1;
  aiLap.time = (unsigned int)(float)(*(float *)&v10 * 1000.0);
  std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&aiLap.splits, 1u);
  v8 = aiLap.splits._Mylast;
  if ( aiLap.splits._Mylast )
  {
    *aiLap.splits._Mylast = aiLap.time;
    v8 = aiLap.splits._Mylast;
  }
  aiLap.splits._Mylast = v8 + 1;
  *(float *)&v10 = COERCE_FLOAT(Sim::getCar(this->sim, 1u));
  v9 = std::map<CarAvatar *,std::vector<Lap>>::operator[](&this->lapTimes, &v10);
  std::vector<Lap>::push_back((std::vector<Lap> *)v9, &aiLap);
  LOBYTE(v14) = 0;
  if ( aiLap.compound._Myres >= 8 )
    operator delete(aiLap.compound._Bx._Ptr);
  aiLap.compound._Myres = 7;
  aiLap.compound._Mysize = 0;
  aiLap.compound._Bx._Buf[0] = 0;
  if ( aiLap.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&aiLap.splits);
    operator delete(aiLap.splits._Myfirst);
    aiLap.splits._Myfirst = 0;
    aiLap.splits._Mylast = 0;
    aiLap.splits._Myend = 0;
  }
  v14 = -1;
  if ( playerLap.compound._Myres >= 8 )
    operator delete(playerLap.compound._Bx._Ptr);
  playerLap.compound._Myres = 7;
  playerLap.compound._Mysize = 0;
  playerLap.compound._Bx._Buf[0] = 0;
  if ( playerLap.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&playerLap.splits);
    operator delete(playerLap.splits._Myfirst);
  }
}
long double DragMode::generateStartTime(DragMode *this)
{
  return (float)((float)_rand() * 0.000030518509) * 10000.0 + this->game->gameTime.now + 10000.0;
}
bool DragMode::isGameOver(DragMode *this)
{
  unsigned int v1; // edx
  Sim *v2; // esi
  unsigned int v3; // ebp
  float v4; // xmm1_4
  int v5; // ebx
  int v6; // esi
  DragMode::DragStatus *v7; // edi
  unsigned int v8; // ebx
  int v9; // ecx
  DragMode *v11; // [esp+8h] [ebp-8h]
  unsigned int v12; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v2 = this->sim;
  v3 = 0;
  v11 = this;
  v4 = (float)this->matchNumber;
  v12 = (int)(float)(v4
                   / (float)((double)(v2->cars._Mylast - v2->cars._Myfirst)
                           + _xmm[(unsigned int)((char *)v2->cars._Mylast - (char *)v2->cars._Myfirst) >> 31]))
      + 1;
  if ( v2->cars._Mylast - v2->cars._Myfirst )
  {
    v5 = (char *)v2->cars._Mylast - (char *)v2->cars._Myfirst;
    v6 = 0;
    v7 = this->carStatus._Myfirst;
    v8 = v5 >> 2;
    v9 = 0;
    do
    {
      if ( v7[v9].numberOfWins > *(unsigned int *)((char *)&v7->numberOfWins + v6) )
      {
        v3 = v1;
        v6 = v9 * 64;
      }
      ++v1;
      ++v9;
    }
    while ( v1 < v8 );
    this = v11;
  }
  return this->carStatus._Myfirst[v3].numberOfWins >= v12;
}
void DragMode::newMatch(DragMode *this, float secondsFade)
{
  ACCameraManager *v3; // ecx
  Sim *v4; // ecx
  Sim *v5; // ecx
  std::function<void __cdecl(bool const &)> v6; // [esp-1Ch] [ebp-48h] BYREF
  DragMode *v7; // [esp-4h] [ebp-30h]
  __m128i v8; // [esp+10h] [ebp-1Ch] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v3 = this->sim->cameraManager;
  if ( !v3
    || (((char *)v3->evOnFadeInFinished.handlers._Mylast - (char *)v3->evOnFadeInFinished.handlers._Myfirst) & 0xFFFFFFE0) != 0 )
  {
    DragMode::resetMatch(this);
  }
  else
  {
    v7 = this;
    v6._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_2a80c05f81b661595b49780cab788282_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
    v6._Space._Pfn[1] = (void (__cdecl *)())this;
    v6._Impl = (std::_Func_base<void,bool const &> *)&v6;
    v4 = this->sim;
    v9 = -1;
    ACCameraManager::registerToFadeInEvent(v4->cameraManager, v6, this);
    v5 = this->sim;
    v8.m128i_i64[1] = __PAIR64__((unsigned int)this, LODWORD(secondsFade));
    v8.m128i_i64[0] = 0i64;
    ACCameraManager::fadeIn(v5->cameraManager, (FadeModeDef)_mm_loadu_si128(&v8));
  }
}
void DragMode::onFinishLanePassed(DragMode *this, const unsigned int *carIndex)
{
  unsigned int v3; // ecx
  DragMode::DragStatus *v4; // edx
  float v5; // xmm0_4
  float v6; // xmm0_4
  DragMode::DragStatus *v7; // ecx
  unsigned int v8; // eax
  int v9; // edx
  DragMode::DragStatus *v10; // ecx
  char v11; // bl
  const __m128i *v12; // eax
  DragMode::DragStatus *v13; // edi
  int v14; // ebp
  bool v15; // al
  __m128i c_16; // [esp+1Ch] [ebp-30h]

  v3 = *carIndex << 6;
  v4 = this->carStatus._Myfirst;
  v5 = (*(CarAvatar **)((char *)&v4->avatar + v3))->physicsState.speed.value;
  if ( Speed::useMPH )
    v6 = v5 * 2.2369363;
  else
    v6 = v5 * 3.5999999;
  *(int *)((char *)&v4->finalSpeed + v3) = (int)v6;
  v7 = this->carStatus._Myfirst;
  v8 = *carIndex << 6;
  v9 = *(int *)((char *)&v7->finalSpeed + v8);
  if ( v9 > *(int *)((char *)&v7->maxSpeed + v8) )
    *(int *)((char *)&v7->maxSpeed + v8) = v9;
  CarAvatar::setGentleStop(this->carStatus._Myfirst[*carIndex].avatar, 1);
  v10 = this->carStatus._Mylast;
  v11 = 1;
  v12 = (const __m128i *)this->carStatus._Myfirst;
  if ( v12 != (const __m128i *)v10 )
  {
    v13 = this->carStatus._Myfirst;
    v14 = v12[4 * *carIndex].m128i_i32[2];
    do
    {
      c_16 = _mm_loadu_si128(v12 + 1);
      if ( _mm_cvtsi128_si32(_mm_srli_si128(_mm_loadu_si128(v12), 8)) != v14 && c_16.m128i_i32[2] )
        v11 = 0;
      v12 += 4;
    }
    while ( v12 != (const __m128i *)v10 );
    if ( !v11 && this->status == eDragRaceOn )
    {
      if ( v13[1].playerTime <= v13->playerTime )
        ++v13[1].numberOfWins;
      else
        ++v13->numberOfWins;
      DragMode::computeCarTimes(this);
      v15 = DragMode::isGameOver(this);
      this->countDown = 2.5;
      if ( v15 )
        this->status = eDragGameOver;
      this->verifyConditions(this);
    }
  }
}
void DragMode::renderDragGUI(DragMode *this, float dt)
{
  GLRenderer *v3; // ebx
  Texture *v4; // ebp
  unsigned int v5; // esi
  unsigned int v6; // eax
  float v7; // xmm0_4
  DragMode::DragStatus *v8; // eax
  float v9; // xmm0_4
  const std::wstring *v10; // eax
  const std::wstring *v11; // esi
  void *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  Texture *v15; // ebp
  unsigned int v16; // esi
  unsigned int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm0_4
  CarAvatar *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  double v23; // st7
  DragMode::DragStatus *v24; // eax
  CarAvatar *v25; // eax
  float v26; // xmm1_4
  float v27; // xmm2_4
  double v28; // st7
  Sim *v29; // eax
  Texture *v30; // esi
  unsigned int v31; // eax
  unsigned int v32; // esi
  unsigned int v33; // ecx
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  std::wstring *v37; // eax
  const std::wstring *v38; // eax
  Font *v39; // ecx
  Texture *v40; // esi
  unsigned int v41; // ebp
  unsigned int v42; // esi
  unsigned int v43; // eax
  float v44; // xmm0_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  std::wstring *v47; // eax
  const std::wstring *v48; // eax
  Font *v49; // ecx
  Texture *v50; // ebp
  unsigned int v51; // esi
  unsigned int v52; // eax
  float v53; // xmm0_4
  float v54; // xmm0_4
  std::wstring *v55; // eax
  const std::wstring *v56; // eax
  const std::wstring *v57; // eax
  Font *v58; // ecx
  Texture *v59; // ebp
  unsigned int v60; // esi
  unsigned int v61; // eax
  float v62; // xmm0_4
  std::wstring *v63; // eax
  const std::wstring *v64; // esi
  void *v65; // ecx
  unsigned int v66; // eax
  float r; // [esp+18h] [ebp-110h]
  float ra; // [esp+18h] [ebp-110h]
  float rb; // [esp+18h] [ebp-110h]
  float rc; // [esp+18h] [ebp-110h]
  float g; // [esp+1Ch] [ebp-10Ch]
  float ga; // [esp+1Ch] [ebp-10Ch]
  float gb; // [esp+1Ch] [ebp-10Ch]
  float gc; // [esp+1Ch] [ebp-10Ch]
  float v75; // [esp+40h] [ebp-E8h]
  float x; // [esp+40h] [ebp-E8h]
  float v77; // [esp+40h] [ebp-E8h]
  float v78; // [esp+44h] [ebp-E4h]
  float v79; // [esp+44h] [ebp-E4h]
  unsigned int v80; // [esp+48h] [ebp-E0h]
  float v81; // [esp+4Ch] [ebp-DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v82; // [esp+50h] [ebp-D8h] BYREF
  std::wstring result; // [esp+100h] [ebp-28h] BYREF
  int v84; // [esp+124h] [ebp-4h]

  v3 = this->game->graphics->gl;
  GLRenderer::color4f(v3, 0.0, 0.0, 0.0, 0.5);
  v78 = (float)this->game->graphics->videoSettings.width * 0.5;
  GLRenderer::quad(v3, v78 - 270.0, 80.0, 540.0, 85.0, 0, 0);
  GLRenderer::color4f(v3, 0.60000002, 0.60000002, 0.60000002, 0.5);
  GLRenderer::begin(v3, eLinesStrip, 0);
  GLRenderer::vertex3f(v3, v78 - 270.0, 80.0, 0.0);
  GLRenderer::vertex3f(v3, v78 + 270.0, 80.0, 0.0);
  GLRenderer::vertex3f(v3, v78 + 270.0, 165.0, 0.0);
  GLRenderer::vertex3f(v3, v78 - 270.0, 165.0, 0.0);
  GLRenderer::vertex3f(v3, v78 - 270.0, 80.0, 0.0);
  GLRenderer::end(v3);
  GraphicsManager::setBlendMode(this->sim->game->graphics, eAlphaBlend);
  GLRenderer::color4f(v3, 1.0, 1.0, 1.0, 1.0);
  v4 = &this->texTime;
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->texTime);
  if ( this->texTime.kid )
    v5 = kglTextureGetHeight(v4->kid);
  else
    v5 = 0;
  if ( v4->kid )
    v6 = kglTextureGetWidth(v4->kid);
  else
    v6 = 0;
  v7 = (float)v5;
  v75 = v78 - 260.0;
  r = (float)v6;
  GLRenderer::quad(v3, v78 - 260.0, 90.0, r, v7, 1, 0);
  *(_DWORD *)v82.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v82.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v82.gap68);
  v84 = 0;
  std::wiostream::basic_iostream<wchar_t>(&v82, &v82.gap10[8], 0);
  v84 = 1;
  *(_DWORD *)&v82.gap0[*(_DWORD *)(*(_DWORD *)v82.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v81 + *(_DWORD *)(*(_DWORD *)v82.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v82.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v82.gap10[8]);
  *(_DWORD *)&v82.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v82.gap10[64] = 0;
  *(_DWORD *)&v82.gap10[68] = 0;
  v8 = this->carStatus._Myfirst;
  v84 = 3;
  v9 = v8->playerTime;
  if ( v9 < 0.0 )
  {
    std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v82.gap10, &byte_17C29BB);
  }
  else
  {
    v10 = timeToDragTime(&result, v9);
    LOBYTE(v84) = 4;
    std::operator<<<wchar_t>((std::wostream *)v82.gap10, v10);
    LOBYTE(v84) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
  v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v82, &result);
  v12 = v4->kid;
  LOBYTE(v84) = 5;
  if ( v12 )
    v13 = kglTextureGetWidth(v12);
  else
    v13 = 0;
  Font::blitString(this->font._Ptr, (float)((float)v13 + v75) + 10.0, 100.0, v11, 1.0, eAlignLeft);
  LOBYTE(v84) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v4->kid )
    v14 = kglTextureGetWidth(v4->kid);
  else
    v14 = 0;
  x = (float)((float)(4 * v14) + v75) + 10.0;
  GLRenderer::color4f(v3, 0.60000002, 0.60000002, 0.60000002, 0.5);
  GLRenderer::begin(v3, eLinesStrip, 0);
  GLRenderer::vertex3f(v3, x, 95.0, 0.0);
  GLRenderer::vertex3f(v3, x, 150.0, 0.0);
  GLRenderer::end(v3);
  GLRenderer::color4f(v3, 1.0, 1.0, 1.0, 1.0);
  v15 = &this->texTrack;
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->texTrack);
  if ( this->texTrack.kid )
    v16 = kglTextureGetHeight(v15->kid);
  else
    v16 = 0;
  if ( v15->kid )
    v17 = kglTextureGetWidth(v15->kid);
  else
    v17 = 0;
  v18 = (float)v16;
  g = v18;
  v19 = (float)v17;
  GLRenderer::quad(v3, x, 85.0, v19, g, 1, 0);
  v20 = this->carStatus._Myfirst->avatar;
  v21 = v20->physicsState.worldMatrix.M42;
  v22 = v20->physicsState.worldMatrix.M43;
  result._Bx._Ptr = (wchar_t *)LODWORD(v20->physicsState.worldMatrix.M41);
  *(_QWORD *)&result._Bx._Alias[4] = __PAIR64__(LODWORD(v22), LODWORD(v21));
  v23 = InterpolatingSpline::worldToSpline(&this->trackSpline, (const vec3f *)&result, -1);
  v24 = this->carStatus._Myfirst;
  this->playerPerc = v23;
  v25 = v24[1].avatar;
  v26 = v25->physicsState.worldMatrix.M42;
  v27 = v25->physicsState.worldMatrix.M43;
  result._Bx._Ptr = (wchar_t *)LODWORD(v25->physicsState.worldMatrix.M41);
  *(_QWORD *)&result._Bx._Alias[4] = __PAIR64__(LODWORD(v27), LODWORD(v26));
  v28 = InterpolatingSpline::worldToSpline(&this->trackSpline, (const vec3f *)&result, -1);
  v29 = this->sim;
  v30 = &this->texPlayerCar;
  this->aiPerc = v28;
  GraphicsManager::setTexture(v29->game->graphics, 0, &this->texPlayerCar);
  if ( this->texPlayerCar.kid )
    v31 = kglTextureGetHeight(v30->kid);
  else
    v31 = 0;
  v80 = v31;
  if ( v30->kid )
    v32 = kglTextureGetWidth(v30->kid);
  else
    v32 = 0;
  if ( v15->kid )
    v33 = kglTextureGetWidth(v15->kid);
  else
    v33 = 0;
  v81 = x + 40.0;
  v34 = (float)v80;
  ga = v34;
  v35 = (float)v32;
  ra = v35;
  v36 = (float)(v33 - 60);
  GLRenderer::quad(v3, (float)(int)(float)((float)(v36 * this->playerPerc) + (float)(x + 40.0)), 100.0, ra, ga, 1, 0);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, word_17BE9D8, 0);
  LOBYTE(v84) = 6;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v82.gap10[8]);
  v37 = &result;
  if ( result._Myres >= 8 )
    v37 = (std::wstring *)result._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v82.gap10[8], v37->_Bx._Buf, result._Mysize, *(int *)&v82.gap10[68]);
  LOBYTE(v84) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wostream::operator<<(v82.gap10, this->carStatus._Myfirst->numberOfWins);
  v38 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v82, &result);
  v39 = this->font._Ptr;
  LOBYTE(v84) = 7;
  v77 = x + 10.0;
  Font::blitString(v39, v77, 95.0, v38, 0.5, eAlignLeft);
  LOBYTE(v84) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v40 = &this->texAICar;
  GraphicsManager::setTexture(this->sim->game->graphics, 0, &this->texAICar);
  if ( this->texAICar.kid )
    v41 = kglTextureGetHeight(v40->kid);
  else
    v41 = 0;
  if ( v40->kid )
    v42 = kglTextureGetWidth(v40->kid);
  else
    v42 = 0;
  if ( this->texTrack.kid )
    v43 = kglTextureGetWidth(this->texTrack.kid);
  else
    v43 = 0;
  v44 = (float)v41;
  gb = v44;
  v45 = (float)v42;
  rb = v45;
  v46 = (float)(v43 - 60);
  GLRenderer::quad(v3, (float)(int)(float)((float)(v46 * this->aiPerc) + v81), 125.0, rb, gb, 1, 0);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, word_17BE9D8, 0);
  LOBYTE(v84) = 8;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v82.gap10[8]);
  v47 = &result;
  if ( result._Myres >= 8 )
    v47 = (std::wstring *)result._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v82.gap10[8], v47->_Bx._Buf, result._Mysize, *(int *)&v82.gap10[68]);
  LOBYTE(v84) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wostream::operator<<(v82.gap10, this->carStatus._Myfirst[1].numberOfWins);
  v48 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v82, &result);
  v49 = this->font._Ptr;
  LOBYTE(v84) = 9;
  Font::blitString(v49, v77, 115.0, v48, 0.5, eAlignLeft);
  LOBYTE(v84) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( this->carStatus._Myfirst->reactionTime > 0.0 )
  {
    GLRenderer::color4f(v3, 0.0, 0.0, 0.0, 0.5);
    GLRenderer::quad(v3, (float)(v78 - 275.0) - 250.0, 80.0, 250.0, 85.0, 0, 0);
    GLRenderer::color4f(v3, 0.60000002, 0.60000002, 0.60000002, 0.5);
    GLRenderer::begin(v3, eLinesStrip, 0);
    GLRenderer::vertex3f(v3, v78 - 275.0, 80.0, 0.0);
    v81 = v78 - 525.0;
    GLRenderer::vertex3f(v3, v78 - 525.0, 80.0, 0.0);
    GLRenderer::vertex3f(v3, v81, 165.0, 0.0);
    GLRenderer::vertex3f(v3, v78 - 275.0, 165.0, 0.0);
    GLRenderer::vertex3f(v3, v78 - 275.0, 80.0, 0.0);
    GLRenderer::end(v3);
    v50 = &this->texTree;
    GraphicsManager::setTexture(this->game->graphics, 0, &this->texTree);
    GLRenderer::color4f(v3, 1.0, 1.0, 1.0, 1.0);
    if ( this->texTree.kid )
      v51 = kglTextureGetHeight(v50->kid);
    else
      v51 = 0;
    if ( v50->kid )
      v52 = kglTextureGetWidth(v50->kid);
    else
      v52 = 0;
    v53 = (float)v51;
    gc = v53;
    v54 = (float)v52;
    GLRenderer::quad(v3, v78 - 515.0, 90.0, v54, gc, 1, 0);
    GLRenderer::color4f(v3, 1.0, 0.0, 0.0, 1.0);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v84) = 10;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v82.gap10[8]);
    v55 = &result;
    if ( result._Myres >= 8 )
      v55 = (std::wstring *)result._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v82.gap10[8], v55->_Bx._Buf, result._Mysize, *(int *)&v82.gap10[68]);
    LOBYTE(v84) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v56 = timeToReactionTime(&result, this->carStatus._Myfirst->reactionTime);
    LOBYTE(v84) = 11;
    std::operator<<<wchar_t>((std::wostream *)v82.gap10, v56);
    LOBYTE(v84) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    v57 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v82, &result);
    v58 = this->font._Ptr;
    LOBYTE(v84) = 12;
    Font::blitString(v58, v78 - 400.0, 95.0, v57, 0.89999998, eAlignCenter);
    LOBYTE(v84) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  if ( this->carStatus._Myfirst->finalSpeed )
  {
    GLRenderer::color4f(v3, 0.0, 0.0, 0.0, 0.5);
    GLRenderer::quad(v3, v78 + 275.0, 80.0, 250.0, 85.0, 0, 0);
    GLRenderer::color4f(v3, 0.60000002, 0.60000002, 0.60000002, 0.5);
    GLRenderer::begin(v3, eLinesStrip, 0);
    GLRenderer::vertex3f(v3, v78 + 275.0, 80.0, 0.0);
    v81 = v78 + 525.0;
    GLRenderer::vertex3f(v3, v78 + 525.0, 80.0, 0.0);
    GLRenderer::vertex3f(v3, v81, 165.0, 0.0);
    GLRenderer::vertex3f(v3, v78 + 275.0, 165.0, 0.0);
    GLRenderer::vertex3f(v3, v78 + 275.0, 80.0, 0.0);
    GLRenderer::end(v3);
    v59 = &this->texFinishSpeed;
    GraphicsManager::setTexture(this->game->graphics, 0, &this->texFinishSpeed);
    GLRenderer::color4f(v3, 1.0, 1.0, 1.0, 1.0);
    if ( this->texFinishSpeed.kid )
      v60 = kglTextureGetHeight(v59->kid);
    else
      v60 = 0;
    if ( v59->kid )
      v61 = kglTextureGetWidth(v59->kid);
    else
      v61 = 0;
    v62 = (float)v60;
    v79 = v78 + 290.0;
    rc = (float)v61;
    GLRenderer::quad(v3, v79, 90.0, rc, v62, 1, 0);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v84) = 13;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v82.gap10[8]);
    v63 = &result;
    if ( result._Myres >= 8 )
      v63 = (std::wstring *)result._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v82.gap10[8], v63->_Bx._Buf, result._Mysize, *(int *)&v82.gap10[68]);
    LOBYTE(v84) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wostream::operator<<(v82.gap10, this->carStatus._Myfirst->finalSpeed);
    Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    v64 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v82, &result);
    v65 = v59->kid;
    LOBYTE(v84) = 14;
    if ( v65 )
      v66 = kglTextureGetWidth(v65);
    else
      v66 = 0;
    Font::blitString(this->font._Ptr, (float)((float)v66 + v79) + 20.0, 95.0, v64, 0.89999998, eAlignLeft);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v84 = -1;
  *(_DWORD *)&v82.gap0[*(_DWORD *)(*(_DWORD *)v82.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v81 + *(_DWORD *)(*(_DWORD *)v82.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v82.gap0 + 4) - 104;
  *(_DWORD *)&v82.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v82.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v82.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v82.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v82.gap68);
}
void DragMode::renderDragPenalty(DragMode *this, float dt)
{
  Game *v3; // eax
  DragMode::DragStatus *v4; // eax
  std::wstring *v5; // eax
  Texture *v6; // edi
  unsigned int v7; // ebp
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm0_4
  DragMode::DragStatus *v12; // eax
  std::wstring *v13; // eax
  Texture *v14; // edi
  unsigned int v15; // ebp
  unsigned int v16; // ebx
  unsigned int v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm0_4
  float g; // [esp+14h] [ebp-100h]
  float ga; // [esp+14h] [ebp-100h]
  GLRenderer *v22; // [esp+38h] [ebp-DCh]
  int v23[4]; // [esp+3Ch] [ebp-D8h] BYREF
  std::wostream _Ostr; // [esp+4Ch] [ebp-C8h] BYREF
  char v25[72]; // [esp+A4h] [ebp-70h] BYREF
  std::wstring v26; // [esp+ECh] [ebp-28h] BYREF
  int v27; // [esp+110h] [ebp-4h]

  v23[0] = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)_Ostr.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v25);
  v27 = 0;
  v22 = (GLRenderer *)1;
  std::wiostream::basic_iostream<wchar_t>(v23, &_Ostr.gap0[8], 0);
  v27 = 1;
  *(int *)((char *)v23 + *(_DWORD *)(v23[0] + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(GLRenderer **)((char *)&v22 + *(_DWORD *)(v23[0] + 4)) = (GLRenderer *)(*(_DWORD *)(v23[0] + 4) - 104);
  std::wstreambuf::wstreambuf(&_Ostr.gap0[8]);
  *(_DWORD *)&_Ostr.gap0[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&_Ostr.gap0[64] = 0;
  *(_DWORD *)&_Ostr.gap0[68] = 0;
  v3 = this->game;
  v27 = 3;
  v22 = v3->graphics->gl;
  GLRenderer::color4f(v22, 1.0, 1.0, 1.0, 1.0);
  v4 = this->carStatus._Myfirst;
  if ( v4->falseStart || v4[1].falseStart )
  {
    v26._Myres = 7;
    v26._Mysize = 0;
    v26._Bx._Buf[0] = 0;
    std::wstring::assign(&v26, word_17BE9D8, 0);
    LOBYTE(v27) = 4;
    std::wstringbuf::_Tidy((std::wstringbuf *)&_Ostr.gap0[8]);
    v5 = &v26;
    if ( v26._Myres >= 8 )
      v5 = (std::wstring *)v26._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&_Ostr.gap0[8], v5->_Bx._Buf, v26._Mysize, *(int *)&_Ostr.gap0[68]);
    LOBYTE(v27) = 3;
    if ( v26._Myres >= 8 )
      operator delete(v26._Bx._Ptr);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(&_Ostr, "FALSE START!");
    v6 = &this->texFalseStart;
    GraphicsManager::setTexture(this->game->graphics, 0, &this->texFalseStart);
    if ( this->texFalseStart.kid )
      v7 = kglTextureGetHeight(v6->kid);
    else
      v7 = 0;
    if ( v6->kid )
      v8 = kglTextureGetWidth(v6->kid);
    else
      v8 = 0;
    if ( v6->kid )
      v9 = kglTextureGetWidth(v6->kid);
    else
      v9 = 0;
    v10 = (float)v7;
    g = v10;
    v11 = (float)v8;
    GLRenderer::quad(v22, (float)(this->game->graphics->videoSettings.width / 2 - (v9 >> 1)), 165.0, v11, g, 1, 0);
  }
  v12 = this->carStatus._Myfirst;
  if ( v12->disqualified || v12[1].disqualified )
  {
    v26._Myres = 7;
    v26._Mysize = 0;
    v26._Bx._Buf[0] = 0;
    std::wstring::assign(&v26, word_17BE9D8, 0);
    LOBYTE(v27) = 5;
    std::wstringbuf::_Tidy((std::wstringbuf *)&_Ostr.gap0[8]);
    v13 = &v26;
    if ( v26._Myres >= 8 )
      v13 = (std::wstring *)v26._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&_Ostr.gap0[8], v13->_Bx._Buf, v26._Mysize, *(int *)&_Ostr.gap0[68]);
    LOBYTE(v27) = 3;
    if ( v26._Myres >= 8 )
      operator delete(v26._Bx._Ptr);
    v26._Myres = 7;
    v26._Bx._Buf[0] = 0;
    v26._Mysize = 0;
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(&_Ostr, "DISQUALIFIED");
    v14 = &this->texDisqualified;
    GraphicsManager::setTexture(this->game->graphics, 0, &this->texDisqualified);
    if ( this->texDisqualified.kid )
      v15 = kglTextureGetHeight(v14->kid);
    else
      v15 = 0;
    if ( v14->kid )
      v16 = kglTextureGetWidth(v14->kid);
    else
      v16 = 0;
    if ( v14->kid )
      v17 = kglTextureGetWidth(v14->kid);
    else
      v17 = 0;
    v18 = (float)v15;
    ga = v18;
    v19 = (float)v16;
    GLRenderer::quad(v22, (float)(this->game->graphics->videoSettings.width / 2 - (v17 >> 1)), 165.0, v19, ga, 1, 0);
  }
  v27 = -1;
  *(int *)((char *)v23 + *(_DWORD *)(v23[0] + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(GLRenderer **)((char *)&v22 + *(_DWORD *)(v23[0] + 4)) = (GLRenderer *)(*(_DWORD *)(v23[0] + 4) - 104);
  *(_DWORD *)&_Ostr.gap0[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&_Ostr.gap0[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&_Ostr.gap0[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&_Ostr.gap0[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v25);
}
void DragMode::renderHUD(DragMode *this, float dt)
{
  DragMode::eDragModeStatus v3; // eax
  __int32 v4; // eax
  int v5; // [esp+20h] [ebp-C0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > debugSs; // [esp+24h] [ebp-BCh] BYREF
  int v7; // [esp+DCh] [ebp-4h]

  v5 = 0;
  if ( this->carStatus._Myfirst != this->carStatus._Mylast
    && !ReplayManager::isInReplaymode(this->sim->replayManager)
    && !this->sim->pauseMenu->visible )
  {
    *(_DWORD *)debugSs.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)debugSs.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(debugSs.gap68);
    v7 = 0;
    v5 = 1;
    std::wiostream::basic_iostream<wchar_t>(&debugSs, &debugSs.gap10[8], 0);
    v7 = 1;
    *(_DWORD *)&debugSs.gap0[*(_DWORD *)(*(_DWORD *)debugSs.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v5 + *(_DWORD *)(*(_DWORD *)debugSs.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)debugSs.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&debugSs.gap10[8]);
    *(_DWORD *)&debugSs.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&debugSs.gap10[64] = 0;
    *(_DWORD *)&debugSs.gap10[68] = 0;
    v7 = 3;
    std::wostream::operator<<(debugSs.gap10);
    v3 = this->status;
    if ( v3 && (v4 = v3 - 1) != 0 )
    {
      if ( v4 == 1 )
      {
        DragMode::renderDragGUI(this, dt);
        DragMode::renderDragPenalty(this, dt);
      }
    }
    else
    {
      DragMode::renderDragGUI(this, dt);
    }
    v7 = -1;
    *(_DWORD *)&debugSs.gap0[*(_DWORD *)(*(_DWORD *)debugSs.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v5 + *(_DWORD *)(*(_DWORD *)debugSs.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)debugSs.gap0 + 4) - 104;
    *(_DWORD *)&debugSs.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&debugSs.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&debugSs.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&debugSs.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(debugSs.gap68);
  }
}
void DragMode::resetMatch(DragMode *this)
{
  double v2; // xmm2_8
  StartingTrackSemaphore *v3; // eax
  DragMode::DragStatus *v4; // esi
  DragMode::DragStatus *i; // edi
  ESCMenu *v6; // ecx

  this->nullCounter = 0.0;
  v2 = (float)((float)_rand() * 0.000030518509);
  v3 = this->semaphore;
  this->startTime = v2 * 10000.0 + this->game->gameTime.now + 10000.0;
  if ( v3 )
    v3->disqualifiedOn = 0;
  v4 = this->carStatus._Myfirst;
  for ( i = this->carStatus._Mylast; v4 != i; ++v4 )
    DragMode::DragStatus::reset(v4, this->startTime);
  v6 = this->sim->escMenu;
  if ( v6 && !v6->visible )
    ksgui::Control::setVisible(v6, 1);
  this->status = eDragStill;
  this->nullCounter = 0.0;
}
void DragMode::update(DragMode *this, float dt)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  Sim *v5; // ecx
  Sim *v6; // ecx
  ACCameraManager *v7; // ecx
  DragMode::eDragModeStatus v8; // eax
  __int32 v9; // eax
  int v10; // eax
  bool v11; // zf
  DragMode::DragStatus *v12; // edi
  DragMode::DragStatus *j; // esi
  unsigned int *v14; // eax
  AIDriverDrag *v15; // ecx
  unsigned __int64 v16; // xmm2_8
  int v17; // eax
  DragMode::DragStatus *v18; // edi
  DragMode::DragStatus *k; // esi
  DragMode::DragStatus *v20; // edi
  const __m128i *l; // esi
  __m128i v22; // xmm0
  __m128i v23; // xmm1
  int v24; // eax
  StartingTrackSemaphore *v25; // ecx
  long double v26; // xmm2_8
  DragMode::DragStatus *v27; // edi
  DragMode::DragStatus *i; // esi
  AIDriverDrag *v29; // ecx
  std::function<void __cdecl(bool const &)> v30; // [esp-14h] [ebp-90h] BYREF
  float secondsFade; // [esp+4h] [ebp-78h]
  __m128i v32; // [esp+20h] [ebp-5Ch] BYREF
  DragMode::DragStatus c; // [esp+30h] [ebp-4Ch]
  int v34; // [esp+78h] [ebp-4h]

  if ( ReplayManager::isInReplaymode(this->sim->replayManager) || this->sim->pauseMenu->visible )
  {
    if ( (this->startTime - this->game->gameTime.now > 0.0 || this->status != eDragRaceOn)
      && this->status == eDragRaceOn )
    {
      v24 = _rand();
      v25 = this->semaphore;
      v26 = (float)((float)v24 * 0.000030518509) * 10000.0 + this->game->gameTime.now + 10000.0;
      this->startTime = v26;
      StartingTrackSemaphore::setCustomStartTime(v25, v26);
      v27 = this->carStatus._Mylast;
      for ( i = this->carStatus._Myfirst; i != v27; ++i )
      {
        v29 = i->aiDriver;
        if ( v29 )
          ((void (*)(AIDriverDrag *, _DWORD, _DWORD))v29->setStartTime)(
            v29,
            LODWORD(this->startTime),
            HIDWORD(this->startTime));
      }
    }
  }
  else
  {
    v3 = this->countDown;
    if ( v3 > 0.0 )
    {
      v4 = v3 - dt;
      this->countDown = v4;
      if ( v4 <= 0.0 )
      {
        if ( this->status )
        {
          DragMode::newMatch(this, 1.0);
        }
        else
        {
          LODWORD(secondsFade) = this;
          v30._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_3d84fecd0731a23756b3efb891057847_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
          v30._Space._Pfn[1] = (void (__cdecl *)())this;
          v30._Impl = (std::_Func_base<void,bool const &> *)&v30;
          v5 = this->sim;
          v34 = -1;
          ACCameraManager::registerToFadeInEvent(v5->cameraManager, v30, this);
          v6 = this->sim;
          v32.m128i_i32[0] = 0;
          v32.m128i_i32[3] = (int)this;
          v7 = v6->cameraManager;
          *(__int64 *)((char *)v32.m128i_i64 + 4) = 0x4020000000000000i64;
          ACCameraManager::fadeIn(v7, (FadeModeDef)_mm_loadu_si128(&v32));
        }
      }
    }
    v8 = this->status;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 == 2 )
        {
          v10 = _rand();
          v11 = this->semaphore == 0;
          this->startTime = (float)((float)v10 * 0.000030518509) * 10000.0 + this->game->gameTime.now + 10000.0;
          if ( v11 )
            this->semaphore = GameObject::getGameObject<StartingTrackSemaphore>(this->sim);
          StartingTrackSemaphore::setCustomStartTime(this->semaphore, this->startTime);
          v12 = this->carStatus._Mylast;
          for ( j = this->carStatus._Myfirst; j != v12; ++j )
          {
            CarAvatar::setGentleStop(j->avatar, 1);
            v14 = (unsigned int *)j->avatar;
            v15 = j->aiDriver;
            v16 = _mm_unpacklo_ps((__m128)v14[103], (__m128)v14[104]).m128_u64[0];
            v32.m128i_i32[2] = v14[105];
            v17 = v32.m128i_i32[2];
            *(_QWORD *)&j->stillPosition.x = v16;
            LODWORD(j->stillPosition.z) = v17;
            if ( v15 )
              ((void (*)(AIDriverDrag *, _DWORD, _DWORD))v15->setStartTime)(
                v15,
                LODWORD(this->startTime),
                HIDWORD(this->startTime));
          }
        }
      }
      else
      {
        v18 = this->carStatus._Mylast;
        for ( k = this->carStatus._Myfirst; k != v18; ++k )
          CarAvatar::setGentleStop(k->avatar, 0);
        DragMode::updateDragRace(this, dt);
      }
    }
    else
    {
      v20 = this->carStatus._Mylast;
      for ( l = (const __m128i *)this->carStatus._Myfirst; l != (const __m128i *)v20; l += 4 )
      {
        v22 = _mm_loadu_si128(l + 1);
        LODWORD(secondsFade) = 1;
        v23 = _mm_loadu_si128(l);
        *(__m128i *)&c.reactionTime = v22;
        *(__m128i *)&c.splineSide = _mm_loadu_si128(l + 2);
        *(__m128i *)&c.spawnPosition.z = _mm_loadu_si128(l + 3);
        CarAvatar::setGentleStop((CarAvatar *)_mm_cvtsi128_si32(_mm_srli_si128(v23, 8)), 1);
      }
    }
  }
}
void DragMode::updateDragRace(DragMode *this, float dt)
{
  DragMode::DragStatus *v3; // eax
  CarAvatar *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  double v7; // st7
  DragMode::DragStatus *v8; // eax
  CarAvatar *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  DragMode::DragStatus *v12; // edi
  DragMode::DragStatus *v13; // esi
  float *i; // ebp
  float *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  int v19; // esi
  unsigned int v20; // edi
  bool v21; // al
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  DragMode::DragStatus *v26; // edi
  DragMode::DragStatus *v27; // esi
  float v28; // xmm1_4
  StartingTrackSemaphore *v29; // eax
  unsigned int v30; // ebp
  int v31; // edi
  bool v32; // al
  DragMode::DragStatus *v33; // [esp+14h] [ebp-18h]
  float pos; // [esp+18h] [ebp-14h]
  DragMode::DragStatus *v35; // [esp+1Ch] [ebp-10h]
  vec3f carPos; // [esp+20h] [ebp-Ch] BYREF
  DragMode::DragStatus *dta; // [esp+30h] [ebp+4h]

  if ( this->startTime - this->game->gameTime.now <= 0.0 && this->status == eDragRaceOn )
  {
    v3 = this->carStatus._Myfirst;
    this->nullCounter = 0.0;
    v4 = v3->avatar;
    v5 = v4->physicsState.worldMatrix.M42;
    v6 = v4->physicsState.worldMatrix.M43;
    carPos.x = v4->physicsState.worldMatrix.M41;
    carPos.y = v5;
    carPos.z = v6;
    v7 = InterpolatingSpline::worldToSpline(&this->trackSpline, &carPos, -1);
    v8 = this->carStatus._Myfirst;
    this->playerPerc = v7;
    v9 = v8[1].avatar;
    v10 = v9->physicsState.worldMatrix.M42;
    v11 = v9->physicsState.worldMatrix.M43;
    carPos.x = v9->physicsState.worldMatrix.M41;
    carPos.y = v10;
    carPos.z = v11;
    this->aiPerc = InterpolatingSpline::worldToSpline(&this->trackSpline, &carPos, -1);
    v12 = this->carStatus._Mylast;
    v13 = this->carStatus._Myfirst;
    v35 = v12;
    v33 = v13;
    if ( v13 != v12 )
    {
      for ( i = &v13->stillPosition.z; ; i += 16 )
      {
        v15 = (float *)*((_DWORD *)i - 13);
        v16 = v15[104];
        v17 = v15[105];
        carPos.x = v15[103];
        carPos.y = v16;
        carPos.z = v17;
        pos = InterpolatingSpline::getSignedDistanceFromSpline(&this->trackSpline, &carPos, 0.5);
        if ( pos <= 0.0 )
        {
          if ( pos >= 0.0 )
            v18 = 0.0;
          else
            v18 = FLOAT_N1_0;
        }
        else
        {
          v18 = FLOAT_1_0;
        }
        if ( *(i - 7) == v18 )
          goto LABEL_19;
        if ( !*((_DWORD *)i - 9) )
          break;
LABEL_21:
        v22 = (float)((float)((float)(carPos.y - *(i - 1)) * (float)(carPos.y - *(i - 1)))
                    + (float)((float)(carPos.x - *(i - 2)) * (float)(carPos.x - *(i - 2))))
            + (float)((float)(carPos.z - *i) * (float)(carPos.z - *i));
        if ( v22 != 0.0 && fsqrt(v22) > 2.0 && this->status == eDragRaceOn && *(i - 11) == 0.0 )
        {
          v23 = *(i - 10);
          v24 = *(i - 6);
          *(i - 11) = v23;
          if ( v24 > v23 && !v13->falseStart )
            *(i - 6) = v23;
        }
        v33 = ++v13;
        if ( v13 == v12 )
          return;
      }
      this->status = eDragRaceSuspended;
      *((_BYTE *)i - 59) = 1;
      if ( this->carStatus._Mylast - this->carStatus._Myfirst )
      {
        v19 = 0;
        v20 = 0;
        do
        {
          if ( v20 != CarAvatar::getGuid(*((CarAvatar **)i - 13)) )
          {
            ++this->carStatus._Myfirst[v19].numberOfWins;
            DragMode::computeCarTimes(this);
            v21 = DragMode::isGameOver(this);
            this->countDown = 2.5;
            if ( v21 )
              this->status = eDragGameOver;
          }
          ++v20;
          ++v19;
        }
        while ( v20 < this->carStatus._Mylast - this->carStatus._Myfirst );
        v13 = v33;
        v12 = v35;
      }
LABEL_19:
      if ( !*((_DWORD *)i - 9) )
        *(i - 10) = *(i - 10) + dt;
      goto LABEL_21;
    }
  }
  else
  {
    v25 = this->nullCounter;
    if ( v25 >= 1.0 )
    {
      v26 = this->carStatus._Mylast;
      v27 = this->carStatus._Myfirst;
      for ( dta = v26; v27 != v26; ++v27 )
      {
        v28 = (float)((float)(v27->avatar->bodyMatrix.M43 - v27->stillPosition.z)
                    * (float)(v27->avatar->bodyMatrix.M43 - v27->stillPosition.z))
            + (float)((float)(v27->avatar->bodyMatrix.M41 - v27->stillPosition.x)
                    * (float)(v27->avatar->bodyMatrix.M41 - v27->stillPosition.x));
        if ( v28 != 0.0 && fsqrt(v28) > 0.1 && this->status == eDragRaceOn )
        {
          v27->falseStart = 1;
          v29 = this->semaphore;
          if ( v29 )
            v29->disqualifiedOn = 1;
          this->status = eDragRaceSuspended;
          v30 = 0;
          if ( this->carStatus._Mylast - this->carStatus._Myfirst )
          {
            v31 = 0;
            do
            {
              if ( v30 != CarAvatar::getGuid(v27->avatar) )
              {
                ++this->carStatus._Myfirst[v31].numberOfWins;
                DragMode::computeCarTimes(this);
                v32 = DragMode::isGameOver(this);
                this->countDown = 2.5;
                if ( v32 )
                  this->status = eDragGameOver;
              }
              ++v30;
              ++v31;
            }
            while ( v30 < this->carStatus._Mylast - this->carStatus._Myfirst );
            v26 = dta;
          }
        }
      }
    }
    else
    {
      this->nullCounter = v25 + dt;
    }
  }
}
void DragMode::verifyConditions(DragMode *this)
{
  unsigned int v2; // ebx
  int v3; // edi
  GameMode::ConditionDef *v4; // ecx
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  Sim *v7; // ecx
  GameMode::ConditionDef *v8; // eax
  std::wstring imessage; // [esp+10h] [ebp-40h] BYREF
  std::wstring result; // [esp+28h] [ebp-28h] BYREF
  int v11; // [esp+4Ch] [ebp-4h]

  v2 = 0;
  if ( this->conditions._Mylast - this->conditions._Myfirst )
  {
    v3 = 0;
    do
    {
      v4 = this->conditions._Myfirst;
      if ( this->carStatus._Myfirst->numberOfWins >= v4[v3].objective && !v4[v3].achieved )
      {
        imessage._Myres = 7;
        imessage._Mysize = 0;
        imessage._Bx._Buf[0] = 0;
        std::wstring::assign(&imessage, L"Drag challenge", 0xEu);
        v5 = &this->conditions._Myfirst->name;
        v11 = 0;
        v6 = std::operator+<wchar_t>(&result, (std::wstring *)((char *)v5 + v3 * 56), L" Achieved");
        v7 = this->sim;
        LOBYTE(v11) = 1;
        SystemMessage::addMessage(v7->systemMessage, &imessage, v6, eDefault);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        v11 = -1;
        if ( imessage._Myres >= 8 )
          operator delete(imessage._Bx._Ptr);
        imessage._Myres = 7;
        imessage._Bx._Buf[0] = 0;
        v8 = this->conditions._Myfirst;
        imessage._Mysize = 0;
        v8[v3].achieved = 1;
        GameMode::setTier(this, v2);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->conditions._Mylast - this->conditions._Myfirst );
  }
}
unsigned int DragMode::getNumberOfPlayerWins(DragMode *this)
{
  unsigned int result; // eax

  if ( (((char *)this->carStatus._Mylast - (char *)this->carStatus._Myfirst) & 0xFFFFFFC0) != 0 )
    result = this->carStatus._Myfirst->numberOfWins;
  else
    result = 0;
  return result;
}
unsigned int DragMode::getNumberOfRuns(DragMode *this)
{
  unsigned int result; // eax

  if ( (((char *)this->carStatus._Mylast - (char *)this->carStatus._Myfirst) & 0xFFFFFFC0) != 0 )
    result = this->carStatus._Myfirst->numberOfWins + this->carStatus._Myfirst[1].numberOfWins;
  else
    result = 0;
  return result;
}
