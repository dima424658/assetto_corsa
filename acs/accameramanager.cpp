#include "accameramanager.h"
void ACCameraManager::ACCameraManager(ACCameraManager *this, Sim *isim, CameraForward *icamera)
{
  std::vector<int> *v4; // ebx
  CarAvatar *v5; // eax
  std::wstring *v6; // eax
  Texture *v7; // eax
  Texture *v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // ebp
  __m128 v12; // xmm0
  int *v13; // eax
  int v14; // esi
  int *v15; // ecx
  int *v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  CinematicFreeCamera *v19; // esi
  CinematicFreeCamera *v20; // eax
  CinematicFreeCamera *v21; // ebp
  GameObject **v22; // ecx
  std::vector<ICollisionObject *> *v23; // esi
  int v24; // eax
  GameObject **v25; // ecx
  GameObject **v26; // eax
  CameraMouseControl *v27; // esi
  CameraMouseControl *v28; // eax
  CameraMouseControl *v29; // ebp
  GameObject **v30; // ecx
  int v31; // eax
  GameObject **v32; // ecx
  GameObject **v33; // eax
  CameraOnBoardFree *v34; // ebp
  int v35; // eax
  CameraOnBoardFree *v36; // ecx
  ICollisionObject **v37; // eax
  int v38; // ebp
  ICollisionObject **v39; // edx
  _DWORD *v40; // eax
  CameraOnBoard *v41; // eax
  int v42; // eax
  CameraOnBoard *v43; // ecx
  ICollisionObject **v44; // eax
  int v45; // ebp
  ICollisionObject **v46; // edx
  _DWORD *v47; // eax
  CameraTrack *v48; // eax
  int v49; // eax
  CameraTrack *v50; // ecx
  ICollisionObject **v51; // eax
  int v52; // ebp
  ICollisionObject **v53; // edx
  _DWORD *v54; // eax
  Event<SessionInfo> *v55; // ecx
  CameraHelicopter *v56; // eax
  int v57; // eax
  int v58; // ebp
  ICollisionObject **v59; // ecx
  int v60; // eax
  ICollisionObject **v61; // ecx
  _DWORD *v62; // eax
  CameraCarManager *v63; // eax
  int v64; // eax
  CameraCarManager *v65; // ecx
  ICollisionObject **v66; // eax
  int v67; // ebp
  ICollisionObject **v68; // edx
  _DWORD *v69; // eax
  CameraModeStart *v70; // ebp
  const std::wstring *v71; // eax
  int v72; // eax
  CameraModeStart *v73; // ecx
  ICollisionObject **v74; // eax
  int v75; // ebp
  ICollisionObject **v76; // edx
  _DWORD *v77; // eax
  bool v78; // zf
  CameraDrivableManager *v79; // eax
  int v80; // eax
  CameraDrivableManager *v81; // ecx
  ICollisionObject **v82; // eax
  int v83; // ebp
  ICollisionObject **v84; // edx
  _DWORD *v85; // eax
  int v86; // edx
  GameObject **v87; // ecx
  unsigned int v88; // esi
  GameObject *v89; // eax
  CameraOnBoard *v90; // eax
  double v91; // st7
  bool v92; // cf
  double v93; // st7
  int v94; // eax
  float v95; // xmm0_4
  int *v96; // esi
  int *v97; // esi
  int *v98; // esi
  int *v99; // esi
  CameraMode v100; // eax
  DrivableCamera v101; // eax
  bool v102; // bl
  vec3f *v103; // eax
  Sim *v104; // eax
  _BYTE v105[28]; // [esp-20h] [ebp-1ECh] BYREF
  unsigned int v106; // [esp-4h] [ebp-1D0h]
  CameraOnBoardFree *v107; // [esp+1Ch] [ebp-1B0h]
  unsigned int v108; // [esp+20h] [ebp-1ACh]
  void *v109; // [esp+24h] [ebp-1A8h]
  char v110; // [esp+2Bh] [ebp-1A1h]
  Sim *sim; // [esp+2Ch] [ebp-1A0h]
  CameraDrivableManager *v112; // [esp+30h] [ebp-19Ch] BYREF
  CameraMouseControl *v113; // [esp+34h] [ebp-198h] BYREF
  CameraOnBoardFree *v114; // [esp+38h] [ebp-194h] BYREF
  int tmp; // [esp+3Ch] [ebp-190h] BYREF
  int v116; // [esp+40h] [ebp-18Ch] BYREF
  CameraTrack *v117; // [esp+44h] [ebp-188h] BYREF
  CinematicFreeCamera *v118; // [esp+48h] [ebp-184h] BYREF
  CameraModeStart *v119; // [esp+4Ch] [ebp-180h] BYREF
  CameraOnBoard *v120; // [esp+50h] [ebp-17Ch] BYREF
  int v121[2]; // [esp+54h] [ebp-178h] BYREF
  std::wstring section; // [esp+5Ch] [ebp-170h] BYREF
  std::wstring v123; // [esp+74h] [ebp-158h] BYREF
  std::wstring key; // [esp+8Ch] [ebp-140h] BYREF
  Texture v125; // [esp+A4h] [ebp-128h] BYREF
  std::wstring tp; // [esp+C0h] [ebp-10Ch] BYREF
  std::wstring result; // [esp+D8h] [ebp-F4h] BYREF
  INIReader ini; // [esp+F0h] [ebp-DCh] BYREF
  INIReaderDocuments cameraManagerINI; // [esp+134h] [ebp-98h] BYREF
  INIReaderDocuments videoEditINI; // [esp+178h] [ebp-54h] BYREF
  int v131; // [esp+1C8h] [ebp-4h]

  v108 = 0;
  v121[1] = (int)this;
  sim = isim;
  v106 = (unsigned int)isim->game;
  *(_DWORD *)&v105[24] = 7;
  *(_DWORD *)&v105[20] = 0;
  *(_WORD *)&v105[4] = 0;
  std::wstring::assign((std::wstring *)&v105[4], L"CAMERA_MANAGER", 0xEu);
  GameObject::GameObject(this, *(std::wstring *)&v105[4], (Game *)v106);
  this->__vftable = (ACCameraManager_vtbl *)&ACCameraManager::`vftable';
  v131 = 0;
  this->evOnCameraSelectedIndex.handlers._Myfirst = 0;
  this->evOnCameraSelectedIndex.handlers._Mylast = 0;
  this->evOnCameraSelectedIndex.handlers._Myend = 0;
  this->evOnCameraUpdateDone.handlers._Myfirst = 0;
  this->evOnCameraUpdateDone.handlers._Mylast = 0;
  this->evOnCameraUpdateDone.handlers._Myend = 0;
  v4 = &this->randomCameraProbabilities;
  this->mouseControl = 0;
  this->cinematicMouseControl = 0;
  this->randomCameraProbabilities._Myfirst = 0;
  this->randomCameraProbabilities._Mylast = 0;
  this->randomCameraProbabilities._Myend = 0;
  this->camera = icamera;
  this->randomMode = 0;
  this->sim = isim;
  this->fadeMode.mode = eFadeColor;
  this->fadeMode.fadeTime = 0.0;
  this->fadeMode.fadeTotalTime = 0.0;
  this->fadeMode.sender = 0;
  this->fadeTexture.kid = 0;
  this->fadeTexture.fileName._Myres = 7;
  this->fadeTexture.fileName._Mysize = 0;
  this->fadeTexture.fileName._Bx._Buf[0] = 0;
  this->fadeColor.x = 0.0;
  this->fadeColor.y = 0.0;
  this->fadeColor.z = 0.0;
  this->evOnFadeInFinished.handlers._Myfirst = 0;
  this->evOnFadeInFinished.handlers._Mylast = 0;
  this->evOnFadeInFinished.handlers._Myend = 0;
  this->persistanceCameraMode.lastCameraMode = eCockpit;
  this->persistanceCameraMode.lastDrivableCameraMode = eChase;
  v106 = 0;
  LOBYTE(v131) = 5;
  this->isKeyboardCameraControlEnabled = 1;
  v5 = Sim::getCar(isim, v106);
  v6 = std::operator+<wchar_t>(&result, L"content\\cars\\", &v5->unixName);
  LOBYTE(v131) = 6;
  std::operator+<wchar_t>(&tp, v6, L"\\ui\\fade_texture.png");
  LOBYTE(v131) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( Path::fileExists((unsigned int)v4, &tp, 0) )
  {
    v7 = ResourceStore::getTexture(this->game->graphics->resourceStore._Myptr, &v125, &tp, 0);
    this->fadeTexture.kid = v7->kid;
    LOBYTE(v131) = 9;
    if ( &this->fadeTexture.fileName != &v7->fileName )
      std::wstring::assign(&this->fadeTexture.fileName, &v7->fileName, 0, 0xFFFFFFFF);
  }
  else
  {
    std::wstring::assign(&tp, L"content\\gui\\fade\\fade_default.png", 0x21u);
    if ( !Path::fileExists((unsigned int)v4, &tp, 0) )
    {
      _printf("WARNING: Failed to load car default fade texture\n");
      goto LABEL_12;
    }
    v8 = ResourceStore::getTexture(this->game->graphics->resourceStore._Myptr, &v125, &tp, 0);
    this->fadeTexture.kid = v8->kid;
    LOBYTE(v131) = 10;
    if ( &this->fadeTexture.fileName != &v8->fileName )
      std::wstring::assign(&this->fadeTexture.fileName, &v8->fileName, 0, 0xFFFFFFFF);
  }
  LOBYTE(v131) = 8;
  OnSetupAppCreated::~OnSetupAppCreated(&v125);
LABEL_12:
  this->randomOldCameraTime = 0.0;
  this->randomCameraMinTime = 5.0;
  this->randomCameraMaxTime = 10.0;
  v9 = _rand();
  v10 = 4;
  this->lastRandomCamera = eTrack;
  v11 = 0;
  v107 = (CameraOnBoardFree *)4;
  v12 = (__m128)COERCE_UNSIGNED_INT((float)v9);
  v12.m128_f32[0] = (float)((float)(v12.m128_f32[0] * 0.000030518509) * 5.0) + this->randomCameraMinTime;
  LODWORD(this->randomCameraTime) = v12.m128_i32[0];
  do
  {
    v13 = this->randomCameraProbabilities._Mylast;
    v11 += 25;
    tmp = v11;
    if ( &tmp >= v13 || v4->_Myfirst > &tmp )
    {
      if ( v13 == this->randomCameraProbabilities._Myend )
      {
        std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->randomCameraProbabilities, 1u);
        v10 = (int)v107;
      }
      v16 = this->randomCameraProbabilities._Mylast;
      if ( v16 )
        *v16 = v11;
    }
    else
    {
      v14 = &tmp - v4->_Myfirst;
      if ( v13 == this->randomCameraProbabilities._Myend )
      {
        std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->randomCameraProbabilities, 1u);
        v10 = (int)v107;
      }
      v15 = this->randomCameraProbabilities._Mylast;
      if ( v15 )
        *v15 = v4->_Myfirst[v14];
    }
    ++this->randomCameraProbabilities._Mylast;
    v107 = (CameraOnBoardFree *)--v10;
  }
  while ( v10 );
  v106 = 0;
  this->currentGlobalCameraIndex = 0;
  *(_DWORD *)&v105[24] = 7;
  *(_DWORD *)&v105[20] = 0;
  *(_WORD *)&v105[4] = 0;
  std::wstring::assign((std::wstring *)&v105[4], L"cfg/video_editing.ini", 0x15u);
  INIReaderDocuments::INIReaderDocuments(&videoEditINI, (unsigned int)v4, *(std::wstring *)&v105[4], v106);
  LOBYTE(v131) = 11;
  if ( !videoEditINI.ready )
    goto LABEL_27;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"CINEMATIC_CAMERAS", 0x11u);
  LOBYTE(v131) = 12;
  v108 = 1;
  if ( !INIReader::hasSection(&videoEditINI, &section) )
    goto LABEL_27;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ACTIVE", 6u);
  v131 = 13;
  v108 = 3;
  v123._Myres = 7;
  v123._Mysize = 0;
  v123._Bx._Buf[0] = 0;
  std::wstring::assign(&v123, L"CINEMATIC_CAMERAS", 0x11u);
  v131 = 14;
  v108 = 7;
  v17 = INIReader::getInt(&videoEditINI, &v123, &key);
  v110 = 1;
  if ( !v17 )
LABEL_27:
    v110 = 0;
  v18 = v108;
  if ( (v108 & 4) != 0 )
  {
    v18 = v108 & 0xFFFFFFFB;
    v108 &= 0xFFFFFFFB;
    if ( v123._Myres >= 8 )
    {
      operator delete(v123._Bx._Ptr);
      v18 = v108;
    }
    v123._Myres = 7;
    v123._Mysize = 0;
    v123._Bx._Buf[0] = 0;
  }
  if ( (v18 & 2) != 0 )
  {
    v18 &= 0xFFFFFFFD;
    v108 = v18;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v18 = v108;
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v131 = 11;
  if ( (v18 & 1) != 0 )
  {
    v108 = v18 & 0xFFFFFFFE;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  if ( v110 )
  {
    v19 = (CinematicFreeCamera *)operator new(244);
    v107 = (CameraOnBoardFree *)v19;
    LOBYTE(v131) = 15;
    if ( v19 )
    {
      v106 = (unsigned int)this->game;
      *(_DWORD *)&v105[24] = this->camera;
      *(_DWORD *)&v105[20] = 7;
      *(_DWORD *)&v105[16] = 0;
      *(_WORD *)v105 = 0;
      std::wstring::assign((std::wstring *)v105, L"MOUSE", 5u);
      CinematicFreeCamera::CinematicFreeCamera(
        v19,
        (unsigned int)v4,
        *(std::wstring *)v105,
        *(Camera **)&v105[24],
        (Game *)v106);
      v21 = v20;
    }
    else
    {
      v21 = 0;
    }
    v22 = this->gameObjects._Mylast;
    v23 = (std::vector<ICollisionObject *> *)&this->gameObjects;
    LOBYTE(v131) = 11;
    v118 = v21;
    if ( &v118 >= v22 || v23->_Myfirst > (ICollisionObject **)&v118 )
    {
      if ( v22 == this->gameObjects._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
      v26 = this->gameObjects._Mylast;
      if ( v26 )
        *v26 = v21;
    }
    else
    {
      v24 = ((char *)&v118 - (char *)v23->_Myfirst) >> 2;
      v107 = (CameraOnBoardFree *)v24;
      if ( v22 == this->gameObjects._Myend )
      {
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
        v24 = (int)v107;
      }
      v25 = this->gameObjects._Mylast;
      if ( v25 )
      {
        *v25 = (GameObject *)v23->_Myfirst[v24];
        ++this->gameObjects._Mylast;
        v21->parent = this;
        this->cinematicMouseControl = v21;
        goto LABEL_68;
      }
    }
    ++this->gameObjects._Mylast;
    v21->parent = this;
    this->cinematicMouseControl = v21;
  }
  else
  {
    v27 = (CameraMouseControl *)operator new(124);
    v109 = v27;
    LOBYTE(v131) = 16;
    if ( v27 )
    {
      v106 = (unsigned int)this->game;
      *(_DWORD *)&v105[24] = this->camera;
      *(_DWORD *)&v105[20] = 7;
      *(_DWORD *)&v105[16] = 0;
      *(_WORD *)v105 = 0;
      std::wstring::assign((std::wstring *)v105, L"MOUSE", 5u);
      CameraMouseControl::CameraMouseControl(v27, *(std::wstring *)v105, *(Camera **)&v105[24], (Game *)v106);
      v29 = v28;
    }
    else
    {
      v29 = 0;
    }
    v30 = this->gameObjects._Mylast;
    v23 = (std::vector<ICollisionObject *> *)&this->gameObjects;
    LOBYTE(v131) = 11;
    v113 = v29;
    if ( &v113 >= v30 || v23->_Myfirst > (ICollisionObject **)&v113 )
    {
      if ( v30 == this->gameObjects._Myend )
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
      v33 = this->gameObjects._Mylast;
      if ( v33 )
        *v33 = v29;
    }
    else
    {
      v31 = ((char *)&v113 - (char *)v23->_Myfirst) >> 2;
      v107 = (CameraOnBoardFree *)v31;
      if ( v30 == this->gameObjects._Myend )
      {
        std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&this->gameObjects, 1u);
        v31 = (int)v107;
      }
      v32 = this->gameObjects._Mylast;
      if ( v32 )
        *v32 = (GameObject *)v23->_Myfirst[v31];
    }
    ++this->gameObjects._Mylast;
    v29->parent = this;
    this->mouseControl = v29;
  }
LABEL_68:
  v34 = (CameraOnBoardFree *)operator new(352);
  v109 = v34;
  LOBYTE(v131) = 17;
  if ( v34 )
  {
    v106 = (unsigned int)this->sim;
    *(_DWORD *)&v105[24] = this->camera;
    *(_DWORD *)&v105[20] = 7;
    *(_DWORD *)&v105[16] = 0;
    *(_WORD *)v105 = 0;
    std::wstring::assign((std::wstring *)v105, &this->name, 0, 0xFFFFFFFF);
    CameraOnBoardFree::CameraOnBoardFree(
      v34,
      (unsigned int)v4,
      *(std::wstring *)v105,
      *(Camera **)&v105[24],
      (Sim *)v106);
    v36 = (CameraOnBoardFree *)v35;
    v107 = (CameraOnBoardFree *)v35;
  }
  else
  {
    v36 = 0;
    v107 = 0;
  }
  v37 = v23->_Mylast;
  LOBYTE(v131) = 11;
  v114 = v36;
  if ( &v114 >= (CameraOnBoardFree **)v37 || v23->_Myfirst > (ICollisionObject **)&v114 )
  {
    if ( v37 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v36 = v107;
    }
    v40 = v23->_Mylast;
    if ( v40 )
      *v40 = v36;
  }
  else
  {
    v38 = ((char *)&v114 - (char *)v23->_Myfirst) >> 2;
    if ( v37 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v36 = v107;
    }
    v39 = v23->_Mylast;
    if ( v39 )
      *v39 = v23->_Myfirst[v38];
  }
  ++v23->_Mylast;
  v36->parent = this;
  v106 = 260;
  this->cameraOnBoardFree = v36;
  v41 = (CameraOnBoard *)operator new(v106);
  v109 = v41;
  LOBYTE(v131) = 18;
  if ( v41 )
  {
    CameraOnBoard::CameraOnBoard(v41, (_BYTE)this - 116, v12, this->game, this->camera, this->sim);
    v43 = (CameraOnBoard *)v42;
    v107 = (CameraOnBoardFree *)v42;
  }
  else
  {
    v43 = 0;
    v107 = 0;
  }
  v44 = v23->_Mylast;
  LOBYTE(v131) = 11;
  v120 = v43;
  if ( &v120 >= (CameraOnBoard **)v44 || v23->_Myfirst > (ICollisionObject **)&v120 )
  {
    if ( v44 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v43 = (CameraOnBoard *)v107;
    }
    v47 = v23->_Mylast;
    if ( v47 )
      *v47 = v43;
  }
  else
  {
    v45 = ((char *)&v120 - (char *)v23->_Myfirst) >> 2;
    if ( v44 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v43 = (CameraOnBoard *)v107;
    }
    v46 = v23->_Mylast;
    if ( v46 )
      *v46 = v23->_Myfirst[v45];
  }
  ++v23->_Mylast;
  v43->parent = this;
  v106 = 136;
  this->cameraOnBoard = v43;
  v48 = (CameraTrack *)operator new(v106);
  v109 = v48;
  LOBYTE(v131) = 19;
  if ( v48 )
  {
    CameraTrack::CameraTrack(v48, this->sim, this->camera);
    v50 = (CameraTrack *)v49;
    v107 = (CameraOnBoardFree *)v49;
  }
  else
  {
    v50 = 0;
    v107 = 0;
  }
  v51 = v23->_Mylast;
  LOBYTE(v131) = 11;
  v117 = v50;
  if ( &v117 >= (CameraTrack **)v51 || v23->_Myfirst > (ICollisionObject **)&v117 )
  {
    if ( v51 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v50 = (CameraTrack *)v107;
    }
    v54 = v23->_Mylast;
    if ( v54 )
      *v54 = v50;
  }
  else
  {
    v52 = ((char *)&v117 - (char *)v23->_Myfirst) >> 2;
    if ( v51 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v50 = (CameraTrack *)v107;
    }
    v53 = v23->_Mylast;
    if ( v53 )
      *v53 = v23->_Myfirst[v52];
  }
  ++v23->_Mylast;
  v106 = (unsigned int)this;
  v50->parent = this;
  this->cameraTrack = v50;
  *(_DWORD *)&v105[4] = &std::_Func_impl<std::_Callable_obj<_lambda_5e83a24f9ed0e174be47eb11727406f8_,0>,std::allocator<std::_Func_class<void,ACCamera const &>>,void,ACCamera const &>::`vftable';
  *(_DWORD *)&v105[8] = this;
  *(_DWORD *)&v105[20] = &v105[4];
  v55 = (Event<SessionInfo> *)&this->cameraTrack->evOnCameraChanged;
  LOBYTE(v131) = 11;
  Event<float>::addHandler(v55, *(std::function<void __cdecl(SessionInfo const &)> *)&v105[4], (void *)v106);
  v56 = (CameraHelicopter *)operator new(72);
  v109 = v56;
  LOBYTE(v131) = 21;
  if ( v56 )
  {
    CameraHelicopter::CameraHelicopter(v56, this->sim, this->camera);
    v58 = v57;
  }
  else
  {
    v58 = 0;
  }
  v59 = v23->_Mylast;
  LOBYTE(v131) = 11;
  v116 = v58;
  if ( &v116 >= (int *)v59 || v23->_Myfirst > (ICollisionObject **)&v116 )
  {
    if ( v59 == v23->_Myend )
      std::vector<SVar *>::_Reserve(v23, 1u);
    v62 = v23->_Mylast;
    if ( v62 )
      *v62 = v58;
  }
  else
  {
    v60 = ((char *)&v116 - (char *)v23->_Myfirst) >> 2;
    v107 = (CameraOnBoardFree *)v60;
    if ( v59 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v60 = (int)v107;
    }
    v61 = v23->_Mylast;
    if ( v61 )
      *v61 = v23->_Myfirst[v60];
  }
  ++v23->_Mylast;
  *(_DWORD *)(v58 + 36) = this;
  this->cameraHelicopter = (CameraHelicopter *)v58;
  *(_DWORD *)&v123._Bx._Alias[8] = 1101004800;
  *(_QWORD *)(v58 + 52) = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_30_0), (__m128)LODWORD(FLOAT_180_0)).m128_u64[0];
  v106 = 64;
  *(_DWORD *)(v58 + 60) = 1101004800;
  v63 = (CameraCarManager *)operator new(v106);
  v109 = v63;
  LOBYTE(v131) = 22;
  if ( v63 )
  {
    CameraCarManager::CameraCarManager(v63, this->sim, this->camera);
    v65 = (CameraCarManager *)v64;
    v107 = (CameraOnBoardFree *)v64;
  }
  else
  {
    v65 = 0;
    v107 = 0;
  }
  v66 = v23->_Mylast;
  LOBYTE(v131) = 11;
  v121[0] = (int)v65;
  if ( v121 >= (int *)v66 || v23->_Myfirst > (ICollisionObject **)v121 )
  {
    if ( v66 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v65 = (CameraCarManager *)v107;
    }
    v69 = v23->_Mylast;
    if ( v69 )
      *v69 = v65;
  }
  else
  {
    v67 = ((char *)v121 - (char *)v23->_Myfirst) >> 2;
    if ( v66 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v65 = (CameraCarManager *)v107;
    }
    v68 = v23->_Mylast;
    if ( v68 )
      *v68 = v23->_Myfirst[v67];
  }
  ++v23->_Mylast;
  v65->parent = this;
  v106 = 192;
  this->cameraCar = v65;
  v70 = (CameraModeStart *)operator new(v106);
  v109 = v70;
  LOBYTE(v131) = 23;
  if ( v70 )
  {
    v71 = TrackAvatar::getConfig(sim->track, (std::wstring *)&v125);
    v108 |= 8u;
    LOBYTE(v131) = 24;
    CameraModeStart::CameraModeStart(v70, sim, this->cameraTrack, this->camera, &sim->track->name, v71);
    v73 = (CameraModeStart *)v72;
    v107 = (CameraOnBoardFree *)v72;
  }
  else
  {
    v73 = 0;
    v107 = 0;
  }
  v74 = v23->_Mylast;
  v131 = 25;
  v119 = v73;
  if ( &v119 >= (CameraModeStart **)v74 || v23->_Myfirst > (ICollisionObject **)&v119 )
  {
    if ( v74 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v73 = (CameraModeStart *)v107;
    }
    v77 = v23->_Mylast;
    if ( v77 )
      *v77 = v73;
  }
  else
  {
    v75 = ((char *)&v119 - (char *)v23->_Myfirst) >> 2;
    if ( v74 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v73 = (CameraModeStart *)v107;
    }
    v76 = v23->_Mylast;
    if ( v76 )
      *v76 = v23->_Myfirst[v75];
  }
  ++v23->_Mylast;
  v78 = (v108 & 8) == 0;
  v73->parent = this;
  this->cameraStart = v73;
  v131 = 11;
  if ( !v78 && v125.fileName._Mysize >= 8 )
    operator delete(v125.kid);
  v106 = 224;
  this->imageGeneratorCamera = 0;
  v79 = (CameraDrivableManager *)operator new(v106);
  v109 = v79;
  LOBYTE(v131) = 26;
  if ( v79 )
  {
    CameraDrivableManager::CameraDrivableManager(v79, (unsigned int)v4, this->sim, this->camera);
    v81 = (CameraDrivableManager *)v80;
    v107 = (CameraOnBoardFree *)v80;
  }
  else
  {
    v81 = 0;
    v107 = 0;
  }
  v82 = v23->_Mylast;
  LOBYTE(v131) = 11;
  v112 = v81;
  if ( &v112 >= (CameraDrivableManager **)v82 || v23->_Myfirst > (ICollisionObject **)&v112 )
  {
    if ( v82 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v81 = (CameraDrivableManager *)v107;
    }
    v85 = v23->_Mylast;
    if ( v85 )
      *v85 = v81;
  }
  else
  {
    v83 = ((char *)&v112 - (char *)v23->_Myfirst) >> 2;
    if ( v82 == v23->_Myend )
    {
      std::vector<SVar *>::_Reserve(v23, 1u);
      v81 = (CameraDrivableManager *)v107;
    }
    v84 = v23->_Mylast;
    if ( v84 )
      *v84 = v23->_Myfirst[v83];
  }
  ++v23->_Mylast;
  v81->parent = this;
  v86 = 0;
  this->cameraDrivable = v81;
  v87 = (GameObject **)v23->_Myfirst;
  v88 = (unsigned int)((char *)this->gameObjects._Mylast - (char *)v23->_Myfirst + 3) >> 2;
  if ( v87 > this->gameObjects._Mylast )
    v88 = 0;
  if ( v88 )
  {
    do
    {
      v89 = *v87++;
      ++v86;
      v89->isActive = 0;
    }
    while ( v86 != v88 );
  }
  v90 = this->cameraOnBoard;
  v106 = 28;
  *(_DWORD *)&v105[24] = L"system/cfg/random_camera.ini";
  key._Myres = 7;
  v90->isActive = 1;
  this->mode = eCockpit;
  this->lastDrivingMode = eCockpit;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, *(const wchar_t **)&v105[24], v106);
  LOBYTE(v131) = 27;
  INIReader::INIReader(&ini, &key);
  LOBYTE(v131) = 29;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"MINIMUM_TIME", 0xCu);
    LOBYTE(v131) = 30;
    v123._Myres = 7;
    v123._Mysize = 0;
    v123._Bx._Buf[0] = 0;
    std::wstring::assign(&v123, L"SETTINGS", 8u);
    LOBYTE(v131) = 31;
    v91 = INIReader::getFloat(&ini, &v123, &section);
    v92 = v123._Myres < 8;
    this->randomCameraMinTime = v91;
    if ( !v92 )
      operator delete(v123._Bx._Ptr);
    v123._Myres = 7;
    v123._Mysize = 0;
    v123._Bx._Buf[0] = 0;
    LOBYTE(v131) = 29;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    v123._Myres = 7;
    v123._Mysize = 0;
    v123._Bx._Buf[0] = 0;
    std::wstring::assign(&v123, L"MAXIMUM_TIME", 0xCu);
    LOBYTE(v131) = 32;
    std::wstring::wstring(&section, L"SETTINGS");
    LOBYTE(v131) = 33;
    v93 = INIReader::getFloat(&ini, &section, &v123);
    v92 = section._Myres < 8;
    this->randomCameraMaxTime = v93;
    if ( !v92 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v131) = 29;
    if ( v123._Myres >= 8 )
      operator delete(v123._Bx._Ptr);
    *(float *)&sim = this->randomCameraMaxTime - this->randomCameraMinTime;
    v94 = _rand();
    v95 = this->randomCameraMinTime;
    v106 = (unsigned int)L"PROBABILITY";
    this->randomCameraTime = v95 + (float)((float)((float)v94 * 0.000030518509) * *(float *)&sim);
    std::wstring::wstring(&v123, (const wchar_t *)v106);
    LOBYTE(v131) = 34;
    std::wstring::wstring(&section, L"CAMERA_COCKPIT");
    v96 = v4->_Myfirst;
    LOBYTE(v131) = 35;
    *v96 = INIReader::getInt(&ini, &section, &v123);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v131) = 29;
    if ( v123._Myres >= 8 )
      operator delete(v123._Bx._Ptr);
    std::wstring::wstring(&v123, L"PROBABILITY");
    LOBYTE(v131) = 36;
    std::wstring::wstring(&section, L"CAMERA_CAR");
    v97 = v4->_Myfirst;
    LOBYTE(v131) = 37;
    v97[1] = *v97 + INIReader::getInt(&ini, &section, &v123);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v131) = 29;
    if ( v123._Myres >= 8 )
      operator delete(v123._Bx._Ptr);
    std::wstring::wstring(&v123, L"PROBABILITY");
    LOBYTE(v131) = 38;
    std::wstring::wstring(&section, L"CAMERA_DRIVABLE");
    v98 = v4->_Myfirst;
    LOBYTE(v131) = 39;
    v98[2] = v98[1] + INIReader::getInt(&ini, &section, &v123);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v131) = 29;
    if ( v123._Myres >= 8 )
      operator delete(v123._Bx._Ptr);
    std::wstring::wstring(&v123, L"PROBABILITY");
    LOBYTE(v131) = 40;
    std::wstring::wstring(&section, L"CAMERA_TRACK");
    v99 = v4->_Myfirst;
    LOBYTE(v131) = 41;
    v99[3] = v99[2] + INIReader::getInt(&ini, &section, &v123);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v131) = 29;
    if ( v123._Myres >= 8 )
      operator delete(v123._Bx._Ptr);
  }
  v106 = 0;
  std::wstring::wstring((std::wstring *)&v105[4], L"cfg/camera_manager.ini");
  INIReaderDocuments::INIReaderDocuments(&cameraManagerINI, (unsigned int)v4, *(std::wstring *)&v105[4], v106);
  LOBYTE(v131) = 42;
  if ( cameraManagerINI.ready )
  {
    std::wstring::wstring(&v123, L"MODE");
    LOBYTE(v131) = 43;
    std::wstring::wstring(&section, L"LAST_CAMERA");
    LOBYTE(v131) = 44;
    v100 = INIReader::getInt(&cameraManagerINI, &section, &v123);
    v92 = section._Myres < 8;
    this->persistanceCameraMode.lastCameraMode = v100;
    if ( !v92 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v131) = 42;
    if ( v123._Myres >= 8 )
      operator delete(v123._Bx._Ptr);
    std::wstring::wstring(&v123, L"DRIVABLE_MODE");
    LOBYTE(v131) = 45;
    std::wstring::wstring(&section, L"LAST_CAMERA");
    LOBYTE(v131) = 46;
    v101 = INIReader::getInt(&cameraManagerINI, &section, &v123);
    v92 = section._Myres < 8;
    this->persistanceCameraMode.lastDrivableCameraMode = v101;
    if ( !v92 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v131) = 42;
    if ( v123._Myres >= 8 )
      operator delete(v123._Bx._Ptr);
    std::wstring::wstring(&section, L"FADE");
    LOBYTE(v131) = 47;
    v102 = INIReader::hasSection(&cameraManagerINI, &section);
    LOBYTE(v131) = 42;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v102 )
    {
      std::wstring::wstring((std::wstring *)&v125, L"COLOR");
      LOBYTE(v131) = 48;
      std::wstring::wstring(&section, L"FADE");
      LOBYTE(v131) = 49;
      v103 = INIReader::getFloat3(&cameraManagerINI, (vec3f *)&v123, &section, (const std::wstring *)&v125);
      v92 = section._Myres < 8;
      this->fadeColor = *v103;
      if ( !v92 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( v125.fileName._Mysize >= 8 )
        operator delete(v125.kid);
    }
  }
  v106 = (unsigned int)this;
  *(_DWORD *)&v105[4] = &std::_Func_impl<std::_Callable_obj<_lambda_5d20acf28da395ad9126c0d1d99304b2_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
  *(_DWORD *)&v105[8] = this;
  *(_DWORD *)&v105[20] = &v105[4];
  v104 = this->sim;
  LOBYTE(v131) = 42;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v104->game->evOnPostGui,
    *(std::function<void __cdecl(SessionInfo const &)> *)&v105[4],
    this);
  this->fadeMode.fadeTime = 4.0;
  this->fadeMode.fadeTotalTime = 4.0;
  LOBYTE(v131) = 29;
  INIReaderDocuments::~INIReaderDocuments(&cameraManagerINI);
  LOBYTE(v131) = 11;
  INIReader::~INIReader(&ini);
  LOBYTE(v131) = 8;
  INIReaderDocuments::~INIReaderDocuments(&videoEditINI);
  if ( tp._Myres >= 8 )
    operator delete(tp._Bx._Ptr);
}
void ACCameraManager::~ACCameraManager(ACCameraManager *this)
{
  std::wstring *v2; // eax
  std::wstring *v3; // eax
  std::wstring *v4; // edi
  const wchar_t *v5; // edx
  std::wstring *v6; // ecx
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // edi
  const wchar_t *v11; // edx
  std::wstring *v12; // ecx
  std::wstring *v13; // eax
  std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > **v14; // edi
  bool v15; // zf
  std::vector<int> *v16; // edi
  CameraMode v17; // [esp-4h] [ebp-13Ch]
  ACCameraManager *v18; // [esp+14h] [ebp-124h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > value; // [esp+18h] [ebp-120h] BYREF
  std::wstring result; // [esp+C8h] [ebp-70h] BYREF
  std::wstring section; // [esp+E0h] [ebp-58h] BYREF
  std::wstring parameter; // [esp+F8h] [ebp-40h] BYREF
  std::wstring filename; // [esp+110h] [ebp-28h] BYREF
  int v24; // [esp+134h] [ebp-4h]

  v18 = this;
  this->__vftable = (ACCameraManager_vtbl *)&ACCameraManager::`vftable';
  v24 = 5;
  v2 = Path::getDocumentPath(&result);
  LOBYTE(v24) = 6;
  std::operator+<wchar_t>(&filename, v2, L"/Assetto Corsa/cfg/camera_manager.ini");
  LOBYTE(v24) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"LAST_CAMERA", 0xBu);
  LOBYTE(v24) = 9;
  parameter._Myres = 7;
  parameter._Mysize = 0;
  parameter._Bx._Buf[0] = 0;
  std::wstring::assign(&parameter, L"MODE", 4u);
  LOBYTE(v24) = 10;
  *(_DWORD *)value.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)value.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(value.gap68);
  LOBYTE(v24) = 11;
  std::wiostream::basic_iostream<wchar_t>(&value, &value.gap10[8], 0);
  v24 = 12;
  *(_DWORD *)&value.gap0[*(_DWORD *)(*(_DWORD *)value.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(ACCameraManager **)((char *)&v18 + *(_DWORD *)(*(_DWORD *)value.gap0 + 4)) = (ACCameraManager *)(*(_DWORD *)(*(_DWORD *)value.gap0 + 4) - 104);
  std::wstreambuf::wstreambuf(&value.gap10[8]);
  *(_DWORD *)&value.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&value.gap10[64] = 0;
  *(_DWORD *)&value.gap10[68] = 0;
  v17 = this->persistanceCameraMode.lastCameraMode;
  LOBYTE(v24) = 14;
  std::wostream::operator<<(value.gap10, v17);
  v3 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&value, &result);
  v4 = &filename;
  v5 = (const wchar_t *)v3;
  if ( filename._Myres >= 8 )
    v4 = (std::wstring *)filename._Bx._Ptr;
  if ( v3->_Myres >= 8 )
    v5 = v3->_Bx._Ptr;
  v6 = &parameter;
  if ( parameter._Myres >= 8 )
    v6 = (std::wstring *)parameter._Bx._Ptr;
  v7 = &section;
  if ( section._Myres >= 8 )
    v7 = (std::wstring *)section._Bx._Ptr;
  WritePrivateProfileStringW(v7->_Bx._Buf, v6->_Bx._Buf, v5, v4->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wstring::assign(&section, L"LAST_CAMERA", 0xBu);
  std::wstring::assign(&parameter, L"DRIVABLE_MODE", 0xDu);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, word_17BE9D8, 0);
  LOBYTE(v24) = 15;
  std::wstringbuf::_Tidy((std::wstringbuf *)&value.gap10[8]);
  v8 = &result;
  if ( result._Myres >= 8 )
    v8 = (std::wstring *)result._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&value.gap10[8], v8->_Bx._Buf, result._Mysize, *(int *)&value.gap10[68]);
  LOBYTE(v24) = 14;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wostream::operator<<(value.gap10, this->persistanceCameraMode.lastDrivableCameraMode);
  v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&value, &result);
  v10 = &filename;
  v11 = (const wchar_t *)v9;
  if ( filename._Myres >= 8 )
    v10 = (std::wstring *)filename._Bx._Ptr;
  if ( v9->_Myres >= 8 )
    v11 = v9->_Bx._Ptr;
  v12 = &parameter;
  if ( parameter._Myres >= 8 )
    v12 = (std::wstring *)parameter._Bx._Ptr;
  v13 = &section;
  if ( section._Myres >= 8 )
    v13 = (std::wstring *)section._Bx._Ptr;
  WritePrivateProfileStringW(v13->_Bx._Buf, v12->_Bx._Buf, v11, v10->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v24) = 10;
  *(_DWORD *)&value.gap0[*(_DWORD *)(*(_DWORD *)value.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(ACCameraManager **)((char *)&v18 + *(_DWORD *)(*(_DWORD *)value.gap0 + 4)) = (ACCameraManager *)(*(_DWORD *)(*(_DWORD *)value.gap0 + 4) - 104);
  *(_DWORD *)&value.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&value.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&value.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&value.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(value.gap68);
  if ( parameter._Myres >= 8 )
    operator delete(parameter._Bx._Ptr);
  parameter._Myres = 7;
  parameter._Mysize = 0;
  parameter._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  v14 = (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > **)&this->evOnFadeInFinished;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  LOBYTE(v24) = 4;
  if ( this->evOnFadeInFinished.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnFadeInFinished);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnFadeInFinished,
      *v14,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnFadeInFinished.handlers._Mylast);
    operator delete(*v14);
    *v14 = 0;
    this->evOnFadeInFinished.handlers._Mylast = 0;
    this->evOnFadeInFinished.handlers._Myend = 0;
  }
  LOBYTE(v24) = 3;
  OnSetupAppCreated::~OnSetupAppCreated(&this->fadeTexture);
  v15 = this->randomCameraProbabilities._Myfirst == 0;
  v16 = &this->randomCameraProbabilities;
  LOBYTE(v24) = 2;
  if ( !v15 )
  {
    std::_Container_base0::_Orphan_all(&this->randomCameraProbabilities);
    operator delete(v16->_Myfirst);
    v16->_Myfirst = 0;
    this->randomCameraProbabilities._Mylast = 0;
    this->randomCameraProbabilities._Myend = 0;
  }
  v15 = this->evOnCameraUpdateDone.handlers._Myfirst == 0;
  LOBYTE(v24) = 1;
  if ( !v15 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnCameraUpdateDone);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnCameraUpdateDone,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnCameraUpdateDone.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnCameraUpdateDone.handlers._Mylast);
    operator delete(this->evOnCameraUpdateDone.handlers._Myfirst);
    this->evOnCameraUpdateDone.handlers._Myfirst = 0;
    this->evOnCameraUpdateDone.handlers._Mylast = 0;
    this->evOnCameraUpdateDone.handlers._Myend = 0;
  }
  v15 = this->evOnCameraSelectedIndex.handlers._Myfirst == 0;
  LOBYTE(v24) = 0;
  if ( !v15 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnCameraSelectedIndex);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnCameraSelectedIndex,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnCameraSelectedIndex.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnCameraSelectedIndex.handlers._Mylast);
    operator delete(this->evOnCameraSelectedIndex.handlers._Myfirst);
    this->evOnCameraSelectedIndex.handlers._Myfirst = 0;
    this->evOnCameraSelectedIndex.handlers._Mylast = 0;
    this->evOnCameraSelectedIndex.handlers._Myend = 0;
  }
  v24 = -1;
  GameObject::~GameObject(this);
}
ACCameraManager *ACCameraManager::`vector deleting destructor'(ACCameraManager *this, unsigned int a2)
{
  ACCameraManager::~ACCameraManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACCameraManager::fadeIn(ACCameraManager *this, FadeModeDef aFadeMode)
{
  _printf("ACCameraManager::fadeIn\n");
  this->fadeMode = (FadeModeDef)_mm_loadu_si128((const __m128i *)&aFadeMode);
}
bool ACCameraManager::isCameraOnBoard(ACCameraManager *this, CarAvatar *car)
{
  unsigned int v3; // esi
  CameraMode v4; // eax
  bool result; // al

  v3 = Sim::getFocusedCarIndex(this->sim);
  result = 0;
  if ( CarAvatar::getGuid(car) == v3 )
  {
    v4 = this->mode;
    if ( v4 == eCockpit || v4 == eDrivable && this->cameraDrivable->currentMode == eDash )
      result = 1;
  }
  return result;
}
bool ACCameraManager::isVirtualMirrorOn(ACCameraManager *this)
{
  CameraMode v1; // eax

  v1 = this->mode;
  return v1 == eCockpit || v1 == eDrivable;
}
void ACCameraManager::loadPreviousSessionUserCamera(ACCameraManager *this)
{
  CameraMode v2; // eax
  int v3; // eax
  unsigned int v4; // eax
  std::pair<void *,std::function<void __cdecl(int const &)> > *v5; // esi
  std::_Func_base<void,int const &> **v6; // ebx
  CameraMode v7; // eax

  CameraDrivableManager::setCurrentCamera(this->cameraDrivable, this->persistanceCameraMode.lastDrivableCameraMode);
  v2 = this->persistanceCameraMode.lastCameraMode;
  if ( this->randomMode )
    this->mode = eOnBoardFree;
  this->randomMode = 0;
  this->mode = v2;
  switch ( v2 )
  {
    case eCockpit:
      this->currentGlobalCameraIndex = 0;
      this->lastDrivingMode = eCockpit;
      break;
    case eCar:
    case eFree:
      this->camera->nearPlane = 0.050000001;
      break;
    case eDrivable:
      v3 = this->cameraDrivable->currentMode + 1;
      this->lastDrivingMode = eDrivable;
      goto LABEL_10;
    case eTrack:
      v4 = this->cameraTrack->currentSet;
      goto LABEL_9;
    case eOnBoardFree:
      v4 = CameraTrack::getCameraTrackCount(this->cameraTrack);
LABEL_9:
      v3 = v4 + 6;
LABEL_10:
      this->currentGlobalCameraIndex = v3;
      break;
    default:
      break;
  }
  ACCameraManager::setAudioDistanceScale(this);
  v5 = this->evOnCameraSelectedIndex.handlers._Myfirst;
  if ( v5 != this->evOnCameraSelectedIndex.handlers._Mylast )
  {
    v6 = &v5->second._Impl;
    do
    {
      if ( !*v6 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x53ABF8);
      }
      (*v6)->_Do_call(*v6, &this->currentGlobalCameraIndex);
      ++v5;
      v6 += 8;
    }
    while ( v5 != this->evOnCameraSelectedIndex.handlers._Mylast );
  }
  if ( !this->randomMode && (v7 = this->mode) == eCockpit || (v7 = this->mode, v7 == eDrivable) )
  {
    this->persistanceCameraMode.lastCameraMode = v7;
    this->persistanceCameraMode.lastDrivableCameraMode = this->cameraDrivable->currentMode;
  }
}
void ACCameraManager::registerToFadeInEvent(ACCameraManager *this, std::function<void __cdecl(bool const &)> f, void *sender)
{
  void *v4; // ebx
  Event<bool> *v5; // edi
  int v6; // eax
  std::_Func_base<void,bool const &>_vtbl *v7; // eax
  std::_Func_base<void,OnPhysicsStepCompleted const &> *v8; // eax
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v9; // [esp-1Ch] [ebp-40h] BYREF
  void *v10; // [esp-4h] [ebp-28h]
  OnGearRequestEvent message; // [esp+13h] [ebp-11h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  v4 = sender;
  v5 = &this->evOnFadeInFinished;
  v6 = this->evOnFadeInFinished.handlers._Mylast - this->evOnFadeInFinished.handlers._Myfirst;
  v12 = 0;
  if ( v6 )
  {
    LOBYTE(message.request) = 1;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFadeInFinished, &message);
    Event<OnStepCompleteEvent>::removeHandler((Event<vec3f> *)v5, this->fadeMode.sender);
  }
  v10 = v4;
  *(GearChangeRequest *)((char *)&message.request + 1) = (GearChangeRequest)&v9;
  v9._Impl = 0;
  LOBYTE(v12) = 1;
  if ( f._Impl )
  {
    v7 = f._Impl->__vftable;
    if ( (std::function<void __cdecl(bool const &)> *)f._Impl == &f )
      v8 = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)((int (__stdcall *)(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *))v7->_Copy)(&v9);
    else
      v8 = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)((int (__stdcall *)(_DWORD))v7->_Copy)(0);
    v9._Impl = v8;
  }
  else
  {
    v9._Impl = 0;
  }
  LOBYTE(v12) = 0;
  Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)v5, v9, v10);
  v12 = -1;
  if ( f._Impl )
    ((void (__stdcall *)(bool))f._Impl->_Delete_this)(f._Impl != (std::_Func_base<void,bool const &> *)&f);
}
void ACCameraManager::setAudioDistanceScale(ACCameraManager *this)
{
  Sim *v2; // ecx
  CameraMode v3; // ebp
  unsigned int i; // esi
  CarAvatar *v5; // eax
  unsigned int v6; // ebx
  CameraMouseControl *v7; // ecx
  CinematicFreeCamera *v8; // ecx
  unsigned int v9; // esi
  DrivableCamera v10; // eax
  CarAvatar *v11; // eax
  CarAvatar *v12; // eax

  if ( this->game->audioEngine )
  {
    v2 = this->sim;
    v3 = this->mode;
    for ( i = 0; i < v2->cars._Mylast - v2->cars._Myfirst; ++i )
    {
      v5 = Sim::getCar(v2, i);
      CarAvatar::resetMultVolume(v5);
      v2 = this->sim;
    }
    v6 = Sim::getFocusedCarIndex(this->sim);
    switch ( v3 )
    {
      case eCar:
        v9 = this->cameraCar->currentCameraIndex;
        if ( !Sim::getCar(this->sim, v6)->cameras._Myfirst[v9].externalSound )
          goto LABEL_17;
        goto LABEL_16;
      case eDrivable:
        v10 = this->cameraDrivable->currentMode;
        if ( v10 == eChase || v10 == eChase2 || v10 == eBonnet || v10 == eBumper )
        {
LABEL_16:
          v11 = Sim::getCar(this->sim, v6);
          CarAvatar::setMultVolume(v11, 1, 1);
          v12 = Sim::getCar(this->sim, v6);
          CarAvatar::setMultVolume(v12, 0, 1);
        }
        goto LABEL_17;
      case eTrack:
        CameraTrack::setAudioDistanceScale(this->cameraTrack);
        return;
      case eFree:
        v7 = this->mouseControl;
        if ( v7 )
          CameraMouseControl::setAudioDistanceScale(v7);
        v8 = this->cinematicMouseControl;
        if ( v8 )
          CinematicFreeCamera::setAudioDistanceScale(v8);
        return;
      default:
LABEL_17:
        AudioEngine::setDistanceScale(this->game->audioEngine, 1.0);
        break;
    }
  }
}
void ACCameraManager::setCameraCarIndex(ACCameraManager *this, int index)
{
  if ( this->mode == eCar )
    CameraCarManager::setCurrentCamera(this->cameraCar, index);
}
void ACCameraManager::setDrivableCarIndex(ACCameraManager *this, int index)
{
  CameraMode v3; // eax
  CameraMode v4; // eax
  std::pair<void *,std::function<void __cdecl(int const &)> > *v5; // esi
  std::_Func_base<void,int const &> **v6; // ebx
  CameraMode v7; // eax

  if ( this->mode == eCar || this->mode == eFree )
    this->camera->nearPlane = 0.050000001;
  v3 = index != 0 ? 2 : 0;
  this->mode = v3;
  if ( v3 )
  {
    this->cameraDrivable->currentMode = index - 1;
    v4 = this->mode;
    this->currentGlobalCameraIndex = index;
    this->lastDrivingMode = v4;
  }
  else
  {
    this->currentGlobalCameraIndex = 0;
    this->lastDrivingMode = eCockpit;
  }
  ACCameraManager::setAudioDistanceScale(this);
  v5 = this->evOnCameraSelectedIndex.handlers._Myfirst;
  if ( v5 != this->evOnCameraSelectedIndex.handlers._Mylast )
  {
    v6 = &v5->second._Impl;
    do
    {
      if ( !*v6 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x53AF56);
      }
      (*v6)->_Do_call(*v6, &this->currentGlobalCameraIndex);
      ++v5;
      v6 += 8;
    }
    while ( v5 != this->evOnCameraSelectedIndex.handlers._Mylast );
  }
  if ( !this->randomMode && (v7 = this->mode) == eCockpit || (v7 = this->mode, v7 == eDrivable) )
  {
    this->persistanceCameraMode.lastCameraMode = v7;
    this->persistanceCameraMode.lastDrivableCameraMode = this->cameraDrivable->currentMode;
  }
}
void ACCameraManager::setKeyboardInputEnabled(ACCameraManager *this, bool value)
{
  this->isKeyboardCameraControlEnabled = value;
}
void ACCameraManager::setMode(ACCameraManager *this, CameraMode imode, bool force, bool pIsRandom)
{
  CameraMode v5; // eax
  char v6; // al
  CameraMode v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  std::pair<void *,std::function<void __cdecl(int const &)> > *v10; // esi
  std::_Func_base<void,int const &> **v11; // ebx
  CameraMode v12; // eax
  _BYTE result[28]; // [esp+Ch] [ebp-1Ch] BYREF

  if ( this->randomMode && !pIsRandom )
    this->mode = eOnBoardFree;
  this->randomMode = pIsRandom;
  v5 = this->mode;
  this->mode = imode;
  if ( !force )
  {
    switch ( imode )
    {
      case eCockpit:
        if ( v5 )
        {
          if ( v5 == eDrivable )
          {
            v6 = CameraDrivableManager::nextMode(this->cameraDrivable);
            v7 = eDrivable;
            if ( v6 )
              v7 = eCockpit;
            this->mode = v7;
          }
          else
          {
            this->mode = this->lastDrivingMode;
          }
        }
        else
        {
          this->mode = eDrivable;
        }
        break;
      case eCar:
      case eFree:
        this->camera->nearPlane = 0.050000001;
        break;
      case eTrack:
        if ( v5 == eTrack )
        {
          CameraTrack::nextSet(this->cameraTrack, (std::wstring *)result);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)result);
        }
        break;
      default:
        break;
    }
  }
  switch ( this->mode )
  {
    case eCockpit:
      this->currentGlobalCameraIndex = 0;
      this->lastDrivingMode = eCockpit;
      break;
    case eCar:
    case eFree:
      this->camera->nearPlane = 0.050000001;
      break;
    case eDrivable:
      v8 = this->cameraDrivable->currentMode + 1;
      this->lastDrivingMode = eDrivable;
      goto LABEL_23;
    case eTrack:
      v9 = this->cameraTrack->currentSet;
      goto LABEL_22;
    case eOnBoardFree:
      v9 = CameraTrack::getCameraTrackCount(this->cameraTrack);
LABEL_22:
      v8 = v9 + 6;
LABEL_23:
      this->currentGlobalCameraIndex = v8;
      break;
    default:
      break;
  }
  ACCameraManager::setAudioDistanceScale(this);
  v10 = this->evOnCameraSelectedIndex.handlers._Myfirst;
  if ( v10 != this->evOnCameraSelectedIndex.handlers._Mylast )
  {
    v11 = &v10->second._Impl;
    do
    {
      if ( !*v11 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x53B104);
      }
      (*v11)->_Do_call(*v11, &this->currentGlobalCameraIndex);
      ++v10;
      v11 += 8;
    }
    while ( v10 != this->evOnCameraSelectedIndex.handlers._Mylast );
  }
  if ( !this->randomMode && (v12 = this->mode) == eCockpit || (v12 = this->mode, v12 == eDrivable) )
  {
    this->persistanceCameraMode.lastCameraMode = v12;
    this->persistanceCameraMode.lastDrivableCameraMode = this->cameraDrivable->currentMode;
  }
}
void ACCameraManager::stepCameraRandom(ACCameraManager *this, int lastCarIndex)
{
  int v3; // eax
  int *v4; // ecx
  CameraMode v5; // ebx
  __m128i v6; // xmm1
  unsigned int v7; // eax
  float v8; // xmm1_4
  int v9; // eax
  double v10; // st7
  CameraTrack *v11; // ecx
  unsigned int v12; // esi
  CameraTrack *v13; // ecx
  int v14; // eax
  double v15; // st7
  CameraCarManager *v16; // ecx
  unsigned int v17; // esi
  CameraCarManager *v18; // ecx
  int v19; // eax
  double v20; // st7
  CameraDrivableManager *v21; // ecx
  DrivableCamera v22; // esi
  CameraDrivableManager *v23; // ecx
  float v24; // xmm0_4
  float v25; // [esp+20h] [ebp-28h]
  float v26; // [esp+20h] [ebp-28h]
  float v27; // [esp+20h] [ebp-28h]
  std::wstring result; // [esp+2Ch] [ebp-1Ch] BYREF

  v25 = (float)this->randomCameraProbabilities._Myfirst[3];
  v3 = _rand();
  v4 = this->randomCameraProbabilities._Myfirst;
  v5 = eCockpit;
  v6 = _mm_cvtsi32_si128(v3);
  v7 = 0;
  v8 = (float)(_mm_cvtepi32_ps(v6).m128_f32[0] * 0.000030518509) * v25;
  while ( (float)*v4 <= v8 )
  {
    ++v7;
    ++v4;
    if ( v7 >= 4 )
      goto LABEL_15;
  }
  v5 = v7;
  switch ( v7 )
  {
    case 3u:
      v26 = (float)CameraTrack::getCameraTrackCount(this->cameraTrack) - 1.0;
      v9 = _rand();
      v10 = _round((double)(int)(float)((float)((float)v9 * 0.000030518509) * v26));
      v11 = this->cameraTrack;
      v12 = v11->currentSet;
      CameraTrack::setCurrentCameraSet(v11, (int)v10);
      v13 = this->cameraTrack;
      if ( v12 == v13->currentSet )
      {
        CameraTrack::nextSet(v13, &result);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
      break;
    case 1u:
      v27 = (float)CameraCarManager::getCameraCount(this->cameraCar) - 1.0;
      v14 = _rand();
      v15 = _round((double)(int)(float)((float)((float)v14 * 0.000030518509) * v27));
      v16 = this->cameraCar;
      v17 = v16->currentCameraIndex;
      CameraCarManager::setCurrentCamera(v16, (int)v15);
      v18 = this->cameraCar;
      if ( v17 == v18->currentCameraIndex )
        CameraCarManager::nextCamera(v18);
      break;
    case 2u:
      v19 = _rand();
      v20 = _round((double)(int)(float)((float)((float)v19 * 0.000030518509) * 4.0));
      v21 = this->cameraDrivable;
      v22 = v21->currentMode;
      CameraDrivableManager::setCurrentCamera(v21, (int)v20);
      v23 = this->cameraDrivable;
      if ( v23->currentMode == v22 )
        CameraDrivableManager::nextMode(v23);
      break;
  }
LABEL_15:
  ACCameraManager::setMode(this, v5, 0, 1);
  v24 = this->randomCameraMaxTime - this->randomCameraMinTime;
  this->lastRandomCamera = v5;
  this->randomCameraTime = (float)((float)((float)_rand() * 0.000030518509) * v24) + this->randomCameraMinTime;
}
void ACCameraManager::update(ACCameraManager *this, float deltaT)
{
  int v3; // ecx
  GameObject **v4; // edx
  unsigned int v5; // edi
  GameObject *v6; // eax
  float v7; // xmm1_4
  int v8; // eax
  bool v9; // cl
  CinematicFreeCamera *v10; // eax

  v3 = 0;
  v4 = this->gameObjects._Myfirst;
  v5 = (unsigned int)((char *)this->gameObjects._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > this->gameObjects._Mylast )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      v6 = *v4++;
      ++v3;
      v6->isActive = 0;
    }
    while ( v3 != v5 );
  }
  if ( this->randomMode )
  {
    v7 = this->randomOldCameraTime;
    if ( this->randomCameraTime <= v7 )
    {
      v8 = Sim::getFocusedCarIndex(this->sim);
      ACCameraManager::stepCameraRandom(this, v8);
      this->randomOldCameraTime = 0.0;
    }
    else
    {
      this->randomOldCameraTime = v7 + deltaT;
    }
  }
  switch ( this->mode )
  {
    case eCar:
      this->cameraCar->isActive = 1;
      break;
    case eDrivable:
      this->cameraDrivable->isActive = 1;
      break;
    case eTrack:
      this->cameraTrack->isActive = 1;
      break;
    case eHelicopter:
      this->cameraHelicopter->isActive = 1;
      break;
    case eOnBoardFree:
      this->cameraOnBoardFree->isActive = 1;
      break;
    case eFree:
      if ( this->mouseControl )
      {
        v9 = RenderWindow::hasFocus(&this->game->window) && this->isKeyboardCameraControlEnabled;
        this->mouseControl->isActive = v9;
      }
      v10 = this->cinematicMouseControl;
      if ( v10 )
        v10->isActive = 1;
      break;
    case eStart:
      this->cameraStart->isActive = 1;
      break;
    default:
      this->cameraOnBoard->isActive = 1;
      break;
  }
}
