#include "ghostcarrecorder.h"
void GhostCarRecorder::GhostCarRecorder(GhostCarRecorder *this, CarAvatar *iavatar, Car *icar, bool isRecording, bool isPlaying)
{
  Event<OnNewSessionEvent> *v6; // ecx
  DriverInfo *v7; // eax
  Event<OnStepCompleteEvent> *v8; // ecx
  Event<OnLapCompletedEvent> *v9; // ecx
  std::wstring v10; // [esp-1Ch] [ebp-48h] BYREF
  Game *v11; // [esp-4h] [ebp-30h]
  GhostCarRecorder *v12; // [esp+1Ch] [ebp-10h]
  int v13; // [esp+28h] [ebp-4h]

  v12 = this;
  v11 = iavatar->game;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"GHOST_CAR_RECORDER", 0x12u);
  GameObject::GameObject(this, v10, v11);
  this->__vftable = (GhostCarRecorder_vtbl *)&GhostCarRecorder::`vftable';
  this->blend = 0.0;
  this->lastLapStartingTime = 0.0;
  this->car = icar;
  this->avatar = iavatar;
  v13 = 0;
  this->recordingBuffer._Myfirst = 0;
  this->recordingBuffer._Mylast = 0;
  this->recordingBuffer._Myend = 0;
  this->playingBuffer._Myfirst = 0;
  this->playingBuffer._Mylast = 0;
  this->playingBuffer._Myend = 0;
  this->ghostDriverName._Myres = 7;
  this->ghostDriverName._Mysize = 0;
  this->ghostDriverName._Bx._Buf[0] = 0;
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  this->carUnixName._Myres = 7;
  this->carUnixName._Mysize = 0;
  this->carUnixName._Bx._Buf[0] = 0;
  this->trackConfig._Myres = 7;
  this->trackConfig._Mysize = 0;
  this->trackConfig._Bx._Buf[0] = 0;
  v11 = (Game *)this;
  this->version = 0;
  this->advantageTimeMS = 0.0;
  this->suspensionWheelsEnabled = 1;
  v10._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_17408a0c1a7b7bb0b9359d4a03ef83a9_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v10._Bx._Alias[4] = this;
  v10._Mysize = (unsigned int)&v10;
  v6 = &iavatar->sim->evOnNewSession;
  LOBYTE(v13) = 6;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v6,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v10,
    v11);
  v7 = &this->avatar->driverInfo;
  *(_WORD *)&this->linePassedForTheFirstTime = 256;
  this->currentFrame = 0;
  this->currentLap = 0;
  *(_OWORD *)&this->lastRecordTime = 0i64;
  if ( &this->ghostDriverName != (std::wstring *)v7 )
    std::wstring::assign(&this->ghostDriverName, &v7->name, 0, 0xFFFFFFFF);
  v11 = (Game *)this;
  this->needToSave = 0;
  this->ghostCarLap = -1;
  v10._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_cf5d4e7fcd47e539c5aa1d25e4769e2f_,0>,std::allocator<std::_Func_class<void,OnStepCompleteEvent const &>>,void,OnStepCompleteEvent const &>::`vftable';
  *(_DWORD *)&v10._Bx._Alias[4] = this;
  v10._Mysize = (unsigned int)&v10;
  v8 = &this->car->evOnStepComplete;
  LOBYTE(v13) = 6;
  Event<float>::addHandler((Event<SessionInfo> *)v8, (std::function<void __cdecl(SessionInfo const &)>)v10, v11);
  v11 = (Game *)this;
  v10._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_e753e19317a64fba2fd930fdd0794f0f_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  *(_DWORD *)&v10._Bx._Alias[4] = this;
  v10._Mysize = (unsigned int)&v10;
  v9 = &this->car->evOnLapCompleted;
  LOBYTE(v13) = 6;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v9,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v10,
    this);
  this->recordingSwitch = isRecording;
  this->playingSwitch = isPlaying;
  GhostCarRecorder::loadGhostCarRecorderCustomParameters(this, (unsigned int)&this->ghostDriverName);
  this->currentFrame = 0;
}
void GhostCarRecorder::~GhostCarRecorder(GhostCarRecorder *this)
{
  this->__vftable = (GhostCarRecorder_vtbl *)&GhostCarRecorder::`vftable';
  if ( this->needToSave )
    GhostCarRecorder::saveGhostCarRecording(this);
  if ( this->trackConfig._Myres >= 8 )
    operator delete(this->trackConfig._Bx._Ptr);
  this->trackConfig._Myres = 7;
  this->trackConfig._Mysize = 0;
  this->trackConfig._Bx._Buf[0] = 0;
  if ( this->carUnixName._Myres >= 8 )
    operator delete(this->carUnixName._Bx._Ptr);
  this->carUnixName._Myres = 7;
  this->carUnixName._Mysize = 0;
  this->carUnixName._Bx._Buf[0] = 0;
  if ( this->trackName._Myres >= 8 )
    operator delete(this->trackName._Bx._Ptr);
  this->trackName._Myres = 7;
  this->trackName._Mysize = 0;
  this->trackName._Bx._Buf[0] = 0;
  if ( this->ghostDriverName._Myres >= 8 )
    operator delete(this->ghostDriverName._Bx._Ptr);
  this->ghostDriverName._Myres = 7;
  this->ghostDriverName._Mysize = 0;
  this->ghostDriverName._Bx._Buf[0] = 0;
  if ( this->playingBuffer._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->playingBuffer);
    operator delete(this->playingBuffer._Myfirst);
    this->playingBuffer._Myfirst = 0;
    this->playingBuffer._Mylast = 0;
    this->playingBuffer._Myend = 0;
  }
  if ( this->recordingBuffer._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->recordingBuffer);
    operator delete(this->recordingBuffer._Myfirst);
    this->recordingBuffer._Myfirst = 0;
    this->recordingBuffer._Mylast = 0;
    this->recordingBuffer._Myend = 0;
  }
  GameObject::~GameObject(this);
}
GhostCarRecorder *GhostCarRecorder::`scalar deleting destructor'(GhostCarRecorder *this, unsigned int a2)
{
  GhostCarRecorder::~GhostCarRecorder(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
mat44f *GhostCarRecorder::getBodyMatrix(GhostCarRecorder *this, mat44f *result)
{
  lerp(
    result,
    &this->playingBuffer._Myfirst[this->currentFrame].body,
    &this->playingBuffer._Myfirst[this->currentFrame + 1].body,
    this->blend);
  return result;
}
std::wstring *GhostCarRecorder::getGhostCarFileName(GhostCarRecorder *this, std::wstring *result, bool onConstructor)
{
  std::wstring *v4; // eax
  std::wstring *v5; // edx
  std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v6; // ecx
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // esi
  std::wstring *v11; // eax
  int v12; // eax
  bool v13; // al
  std::wstring *v14; // eax
  std::wstring *v15; // ecx
  CarAvatar *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // esi
  std::wstring *v19; // esi
  CarAvatar *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // ecx
  CarAvatar *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // esi
  int v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  std::wstring *v31; // eax
  std::wstring *v32; // esi
  std::wstring *v33; // eax
  std::wstring *v34; // eax
  std::wstring *v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // eax
  std::wstring *v38; // esi
  unsigned int v40; // [esp-Ch] [ebp-110h]
  std::wstring *v41; // [esp-4h] [ebp-108h]
  bool v42; // [esp+13h] [ebp-F1h]
  std::wstring ghostCarSavedName; // [esp+1Ch] [ebp-E8h] BYREF
  std::wstring v44; // [esp+34h] [ebp-D0h] BYREF
  std::wstring v45; // [esp+4Ch] [ebp-B8h] BYREF
  std::wstring v46; // [esp+64h] [ebp-A0h] BYREF
  std::wstring v47; // [esp+7Ch] [ebp-88h] BYREF
  std::wstring v48; // [esp+94h] [ebp-70h] BYREF
  std::wstring v49; // [esp+ACh] [ebp-58h] BYREF
  std::wstring newFolderName; // [esp+C4h] [ebp-40h] BYREF
  std::wstring v51; // [esp+DCh] [ebp-28h] BYREF
  int v52; // [esp+100h] [ebp-4h]

  newFolderName._Myres = 7;
  newFolderName._Mysize = 0;
  newFolderName._Bx._Buf[0] = 0;
  v52 = 1;
  if ( onConstructor )
  {
    v4 = &this->avatar->sim->track->name;
    if ( this->avatar->sim->track->name._Myres >= 8 )
    {
      v5 = (std::wstring *)v4->_Bx._Ptr;
      goto LABEL_7;
    }
  }
  else
  {
    v4 = &this->trackName;
    if ( this->trackName._Myres >= 8 )
    {
      v5 = (std::wstring *)v4->_Bx._Ptr;
      goto LABEL_7;
    }
  }
  v5 = v4;
LABEL_7:
  v6._Ptr = &v5->_Bx._Buf[v4->_Mysize];
  if ( v4->_Myres >= 8 )
    v4 = (std::wstring *)v4->_Bx._Ptr;
  std::wstring::replace(
    &newFolderName,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&newFolderName,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&newFolderName,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v4,
    v6);
  v7 = Path::getDocumentPath(&v44);
  LOBYTE(v52) = 2;
  std::operator+<wchar_t>(result, v7, L"/Assetto Corsa/GhostCar");
  LOBYTE(v52) = 1;
  if ( v44._Myres >= 8 )
    operator delete(v44._Bx._Ptr);
  Path::createFolder(result);
  v8 = Path::getDocumentPath(&v44);
  LOBYTE(v52) = 3;
  v9 = std::operator+<wchar_t>(&v45, v8, L"/Assetto Corsa/GhostCar/");
  LOBYTE(v52) = 4;
  v10 = std::operator+<wchar_t>(&v46, v9, &newFolderName);
  if ( result != v10 )
  {
    if ( result->_Myres >= 8 )
      operator delete(result->_Bx._Ptr);
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(result, v10);
  }
  if ( v46._Myres >= 8 )
    operator delete(v46._Bx._Ptr);
  v46._Myres = 7;
  v46._Mysize = 0;
  v46._Bx._Buf[0] = 0;
  if ( v45._Myres >= 8 )
    operator delete(v45._Bx._Ptr);
  v45._Myres = 7;
  v45._Mysize = 0;
  v45._Bx._Buf[0] = 0;
  LOBYTE(v52) = 1;
  if ( v44._Myres >= 8 )
    operator delete(v44._Bx._Ptr);
  Path::createFolder(result);
  ghostCarSavedName._Myres = 7;
  ghostCarSavedName._Mysize = 0;
  ghostCarSavedName._Bx._Buf[0] = 0;
  LOBYTE(v52) = 5;
  if ( onConstructor )
  {
    v11 = TrackAvatar::getConfig(this->avatar->sim->track, &v44);
    v40 = v11->_Mysize;
    LOBYTE(v52) = 6;
    v12 = std::wstring::compare(v11, 0, v40, word_17BE9D8, 0);
    LOBYTE(v52) = 5;
    v13 = v12 == 0;
    v42 = v13;
    if ( v44._Myres >= 8 )
    {
      operator delete(v44._Bx._Ptr);
      v13 = v42;
    }
    if ( v13 )
    {
      v14 = std::operator+<wchar_t>(&v44, L"/GHOST_CAR_", &this->avatar->driverInfo.name);
      LOBYTE(v52) = 7;
      v15 = std::operator+<wchar_t>(&v48, v14, L"_");
      v16 = this->avatar;
      LOBYTE(v52) = 8;
      v17 = std::operator+<wchar_t>(&v46, v15, &v16->unixName);
      LOBYTE(v52) = 9;
      v18 = std::operator+<wchar_t>(&v45, v17, L".ghost");
      if ( &ghostCarSavedName != v18 )
      {
        ghostCarSavedName._Myres = 7;
        ghostCarSavedName._Mysize = 0;
        ghostCarSavedName._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&ghostCarSavedName, v18);
      }
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
      v45._Myres = 7;
      v45._Mysize = 0;
      v45._Bx._Buf[0] = 0;
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      if ( v48._Myres >= 8 )
        operator delete(v48._Bx._Ptr);
      v48._Myres = 7;
      v48._Mysize = 0;
      v48._Bx._Buf[0] = 0;
      LOBYTE(v52) = 5;
      if ( v44._Myres >= 8 )
        operator delete(v44._Bx._Ptr);
      goto LABEL_75;
    }
    v19 = TrackAvatar::getConfig(this->avatar->sim->track, &v51);
    v20 = this->avatar;
    LOBYTE(v52) = 10;
    v21 = std::operator+<wchar_t>(&v44, L"/GHOST_CAR_", &v20->driverInfo.name);
    LOBYTE(v52) = 11;
    v22 = std::operator+<wchar_t>(&v47, v21, L"_");
    v23 = this->avatar;
    LOBYTE(v52) = 12;
    v24 = std::operator+<wchar_t>(&v49, v22, &v23->unixName);
    LOBYTE(v52) = 13;
    v25 = std::operator+<wchar_t>(&v46, v24, L"_");
    LOBYTE(v52) = 14;
    v26 = std::operator+<wchar_t>(&v45, v25, v19);
    LOBYTE(v52) = 15;
    v27 = std::operator+<wchar_t>(&v48, v26, L".ghost");
    if ( &ghostCarSavedName != v27 )
    {
      ghostCarSavedName._Myres = 7;
      ghostCarSavedName._Mysize = 0;
      ghostCarSavedName._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&ghostCarSavedName, v27);
    }
    if ( v48._Myres >= 8 )
      operator delete(v48._Bx._Ptr);
    v48._Myres = 7;
    v48._Mysize = 0;
    v48._Bx._Buf[0] = 0;
    if ( v45._Myres >= 8 )
      operator delete(v45._Bx._Ptr);
    v45._Myres = 7;
    v45._Mysize = 0;
    v45._Bx._Buf[0] = 0;
    if ( v46._Myres >= 8 )
      operator delete(v46._Bx._Ptr);
    v46._Myres = 7;
    v46._Mysize = 0;
    v46._Bx._Buf[0] = 0;
    if ( v49._Myres >= 8 )
      operator delete(v49._Bx._Ptr);
    v49._Myres = 7;
    v49._Mysize = 0;
    v49._Bx._Buf[0] = 0;
    if ( v47._Myres >= 8 )
      operator delete(v47._Bx._Ptr);
    v47._Myres = 7;
    v47._Mysize = 0;
    v47._Bx._Buf[0] = 0;
    if ( v44._Myres >= 8 )
      operator delete(v44._Bx._Ptr);
    v44._Myres = 7;
    v44._Mysize = 0;
    v44._Bx._Buf[0] = 0;
  }
  else
  {
    v28 = std::wstring::compare(&this->trackConfig, 0, this->trackConfig._Mysize, word_17BE9D8, 0);
    v41 = &this->ghostDriverName;
    if ( v28 )
    {
      v33 = std::operator+<wchar_t>(&v51, L"/GHOST_CAR_", v41);
      LOBYTE(v52) = 19;
      v34 = std::operator+<wchar_t>(&v45, v33, L"_");
      LOBYTE(v52) = 20;
      v35 = std::operator+<wchar_t>(&v48, v34, &this->carUnixName);
      LOBYTE(v52) = 21;
      v36 = std::operator+<wchar_t>(&v49, v35, L"_");
      LOBYTE(v52) = 22;
      v37 = std::operator+<wchar_t>(&v47, v36, &this->trackConfig);
      LOBYTE(v52) = 23;
      v38 = std::operator+<wchar_t>(&v44, v37, L".ghost");
      if ( &ghostCarSavedName != v38 )
      {
        ghostCarSavedName._Myres = 7;
        ghostCarSavedName._Mysize = 0;
        ghostCarSavedName._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&ghostCarSavedName, v38);
      }
      if ( v44._Myres >= 8 )
        operator delete(v44._Bx._Ptr);
      v44._Myres = 7;
      v44._Mysize = 0;
      v44._Bx._Buf[0] = 0;
      if ( v47._Myres >= 8 )
        operator delete(v47._Bx._Ptr);
      v47._Myres = 7;
      v47._Mysize = 0;
      v47._Bx._Buf[0] = 0;
      if ( v49._Myres >= 8 )
        operator delete(v49._Bx._Ptr);
      v49._Myres = 7;
      v49._Mysize = 0;
      v49._Bx._Buf[0] = 0;
      if ( v48._Myres >= 8 )
        operator delete(v48._Bx._Ptr);
      v48._Myres = 7;
      v48._Mysize = 0;
      v48._Bx._Buf[0] = 0;
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
      v45._Myres = 7;
      v45._Mysize = 0;
      v45._Bx._Buf[0] = 0;
    }
    else
    {
      v29 = std::operator+<wchar_t>(&v51, L"/GHOST_CAR_", v41);
      LOBYTE(v52) = 16;
      v30 = std::operator+<wchar_t>(&v49, v29, L"_");
      LOBYTE(v52) = 17;
      v31 = std::operator+<wchar_t>(&v47, v30, &this->carUnixName);
      LOBYTE(v52) = 18;
      v32 = std::operator+<wchar_t>(&v44, v31, L".ghost");
      if ( &ghostCarSavedName != v32 )
      {
        ghostCarSavedName._Myres = 7;
        ghostCarSavedName._Mysize = 0;
        ghostCarSavedName._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&ghostCarSavedName, v32);
      }
      if ( v44._Myres >= 8 )
        operator delete(v44._Bx._Ptr);
      v44._Myres = 7;
      v44._Mysize = 0;
      v44._Bx._Buf[0] = 0;
      if ( v47._Myres >= 8 )
        operator delete(v47._Bx._Ptr);
      v47._Myres = 7;
      v47._Mysize = 0;
      v47._Bx._Buf[0] = 0;
      if ( v49._Myres >= 8 )
        operator delete(v49._Bx._Ptr);
      v49._Myres = 7;
      v49._Mysize = 0;
      v49._Bx._Buf[0] = 0;
    }
  }
  LOBYTE(v52) = 5;
  if ( v51._Myres >= 8 )
    operator delete(v51._Bx._Ptr);
LABEL_75:
  std::wstring::append(result, &ghostCarSavedName, 0, 0xFFFFFFFF);
  if ( ghostCarSavedName._Myres >= 8 )
    operator delete(ghostCarSavedName._Bx._Ptr);
  ghostCarSavedName._Myres = 7;
  ghostCarSavedName._Mysize = 0;
  ghostCarSavedName._Bx._Buf[0] = 0;
  if ( newFolderName._Myres >= 8 )
    operator delete(newFolderName._Bx._Ptr);
  return result;
}
mat44f *GhostCarRecorder::getSuspensionMatrix(GhostCarRecorder *this, mat44f *result, int index)
{
  lerp(
    result,
    &this->playingBuffer._Myfirst->body + index + 8 * this->currentFrame + this->currentFrame + 5,
    &this->playingBuffer._Myfirst->body + index + 8 * this->currentFrame + this->currentFrame + 14,
    this->blend);
  return result;
}
mat44f *GhostCarRecorder::getTyreMatrix(GhostCarRecorder *this, mat44f *result, int index)
{
  lerp(
    result,
    &this->playingBuffer._Myfirst->body + index + 8 * this->currentFrame + this->currentFrame + 1,
    &this->playingBuffer._Myfirst->body + index + 8 * this->currentFrame + this->currentFrame + 10,
    this->blend);
  return result;
}
void __usercall GhostCarRecorder::loadGhostCarRecorderCustomParameters(GhostCarRecorder *this@<ecx>, unsigned int a2@<ebx>)
{
  bool v3; // bl
  std::wstring *v4; // ecx
  std::wstring *v5; // eax
  double v6; // st7
  bool v7; // cf
  _BYTE v8[28]; // [esp-1Ch] [ebp-E0h] BYREF
  std::wstring fileToLoad; // [esp+10h] [ebp-B4h] BYREF
  std::wstring filePathName; // [esp+28h] [ebp-9Ch] BYREF
  std::wstring section; // [esp+40h] [ebp-84h] BYREF
  std::wstring key; // [esp+58h] [ebp-6Ch] BYREF
  INIReaderDocuments r; // [esp+70h] [ebp-54h] BYREF
  int v14; // [esp+C0h] [ebp-4h]

  *(_DWORD *)&v8[24] = 0;
  *(_DWORD *)&v8[20] = 7;
  *(_DWORD *)&v8[16] = 0;
  *(_WORD *)v8 = 0;
  std::wstring::assign((std::wstring *)v8, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&r, a2, *(std::wstring *)v8, v8[24]);
  v14 = 0;
  if ( r.ready )
  {
    filePathName._Myres = 7;
    filePathName._Mysize = 0;
    filePathName._Bx._Buf[0] = 0;
    std::wstring::assign(&filePathName, L"LOAD", 4u);
    LOBYTE(v14) = 1;
    fileToLoad._Myres = 7;
    fileToLoad._Mysize = 0;
    fileToLoad._Bx._Buf[0] = 0;
    std::wstring::assign(&fileToLoad, L"GHOST_CAR", 9u);
    LOBYTE(v14) = 2;
    v3 = INIReader::getInt(&r, &fileToLoad, &filePathName) != 0;
    if ( fileToLoad._Myres >= 8 )
      operator delete(fileToLoad._Bx._Ptr);
    fileToLoad._Myres = 7;
    fileToLoad._Mysize = 0;
    fileToLoad._Bx._Buf[0] = 0;
    LOBYTE(v14) = 0;
    if ( filePathName._Myres >= 8 )
      operator delete(filePathName._Bx._Ptr);
    if ( v3 )
    {
      std::wstring::wstring(&key, L"FILE");
      LOBYTE(v14) = 3;
      std::wstring::wstring(&section, L"GHOST_CAR");
      LOBYTE(v14) = 4;
      INIReader::getString(&r, &filePathName, &section, &key);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      fileToLoad._Myres = 7;
      fileToLoad._Mysize = 0;
      fileToLoad._Bx._Buf[0] = 0;
      v4 = &filePathName;
      if ( filePathName._Myres >= 8 )
        v4 = (std::wstring *)filePathName._Bx._Ptr;
      LOBYTE(v14) = 8;
      *(_DWORD *)&v8[24] = (char *)v4 + 2 * filePathName._Mysize;
      v5 = &filePathName;
      if ( filePathName._Myres >= 8 )
        v5 = (std::wstring *)filePathName._Bx._Ptr;
      std::wstring::replace(
        &fileToLoad,
        (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&fileToLoad,
        (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&fileToLoad,
        (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v5,
        *(std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&v8[24]);
      if ( !fileToLoad._Mysize
        || (*(_DWORD *)&v8[24] = 7,
            *(_DWORD *)&v8[20] = 0,
            *(_WORD *)&v8[4] = 0,
            std::wstring::assign((std::wstring *)&v8[4], &fileToLoad, 0, 0xFFFFFFFF),
            !GhostCarRecorder::loadGhostCarRecording(this, *(std::wstring *)&v8[4])) )
      {
        GhostCarRecorder::getGhostCarFileName(this, (std::wstring *)&v8[4], 1);
        GhostCarRecorder::loadGhostCarRecording(this, *(std::wstring *)&v8[4]);
      }
      if ( fileToLoad._Myres >= 8 )
        operator delete(fileToLoad._Bx._Ptr);
      fileToLoad._Myres = 7;
      fileToLoad._Mysize = 0;
      fileToLoad._Bx._Buf[0] = 0;
      LOBYTE(v14) = 0;
      if ( filePathName._Myres >= 8 )
        operator delete(filePathName._Bx._Ptr);
    }
    filePathName._Myres = 7;
    filePathName._Mysize = 0;
    filePathName._Bx._Buf[0] = 0;
    std::wstring::assign(&filePathName, L"SECONDS_ADVANTAGE", 0x11u);
    LOBYTE(v14) = 9;
    fileToLoad._Myres = 7;
    fileToLoad._Mysize = 0;
    fileToLoad._Bx._Buf[0] = 0;
    std::wstring::assign(&fileToLoad, L"GHOST_CAR", 9u);
    LOBYTE(v14) = 10;
    v6 = INIReader::getFloat(&r, &fileToLoad, &filePathName);
    v7 = fileToLoad._Myres < 8;
    this->advantageTimeMS = v6 * 1000.0;
    if ( !v7 )
      operator delete(fileToLoad._Bx._Ptr);
    fileToLoad._Myres = 7;
    fileToLoad._Mysize = 0;
    fileToLoad._Bx._Buf[0] = 0;
    if ( filePathName._Myres >= 8 )
      operator delete(filePathName._Bx._Ptr);
    filePathName._Myres = 7;
    filePathName._Mysize = 0;
    filePathName._Bx._Buf[0] = 0;
  }
  else
  {
    _printf("ERROR: GHOST CAR error in reading ini file\n");
  }
  v14 = -1;
  INIReaderDocuments::~INIReaderDocuments(&r);
}
char GhostCarRecorder::loadGhostCarRecording(GhostCarRecorder *this, std::wstring filename)
{
  int v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  bool v10; // bl
  char v11; // bl
  std::vector<char> buffer; // [esp+9Ch] [ebp-104h] BYREF
  int framecount; // [esp+A8h] [ebp-F8h] BYREF
  int v15; // [esp+ACh] [ebp-F4h]
  unsigned int trackConfigSize; // [esp+B0h] [ebp-F0h] BYREF
  unsigned int trackNameSize; // [esp+B4h] [ebp-ECh] BYREF
  unsigned int ghostDriverNameSize; // [esp+B8h] [ebp-E8h] BYREF
  unsigned int carUnixNameSize; // [esp+BCh] [ebp-E4h] BYREF
  std::ifstream in; // [esp+C0h] [ebp-E0h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement result; // [esp+178h] [ebp-28h] BYREF
  int v22; // [esp+19Ch] [ebp-4h]

  v15 = 0;
  v22 = 0;
  std::ifstream::ifstream(&in, &filename, 33, 64, 1);
  LOBYTE(v22) = 1;
  if ( !*(_DWORD *)in._Filebuffer )
  {
    _printf("ERROR: GHOST CAR :: couldn't open File\n");
LABEL_30:
    v11 = 0;
    goto LABEL_31;
  }
  std::istream::read(&in, &this->version);
  v3 = this->version;
  if ( v3 < 3 )
  {
    if ( !std::filebuf::close((std::filebuf *)in.gap10) )
      std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
    goto LABEL_30;
  }
  buffer._Myfirst = 0;
  buffer._Mylast = 0;
  buffer._Myend = 0;
  LOBYTE(v22) = 2;
  std::istream::read(&in, &this->suspensionWheelsEnabled);
  std::istream::read(&in, &ghostDriverNameSize);
  std::vector<char>::resize(&buffer, ghostDriverNameSize);
  std::istream::read(&in, buffer._Myfirst);
  v4 = ksDecodeUtf8(&result.name, &buffer);
  std::wstring::operator=(&this->ghostDriverName, v4);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::istream::read(&in, &trackNameSize);
  std::vector<char>::resize(&buffer, trackNameSize);
  std::istream::read(&in, buffer._Myfirst);
  v5 = ksDecodeUtf8(&result.name, &buffer);
  std::wstring::operator=(&this->trackName, v5);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::istream::read(&in, &trackConfigSize);
  std::vector<char>::resize(&buffer, trackConfigSize);
  std::istream::read(&in, buffer._Myfirst);
  v6 = ksDecodeUtf8(&result.name, &buffer);
  std::wstring::operator=(&this->trackConfig, v6);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  std::istream::read(&in, &carUnixNameSize);
  std::vector<char>::resize(&buffer, carUnixNameSize);
  std::istream::read(&in, buffer._Myfirst);
  v7 = ksDecodeUtf8(&result.name, &buffer);
  std::wstring::operator=(&this->carUnixName, v7);
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  v8 = &this->avatar->sim->track->name;
  if ( this->avatar->sim->track->name._Myres >= 8 )
    v8 = (std::wstring *)v8->_Bx._Ptr;
  v10 = 1;
  if ( !std::wstring::compare(
          &this->trackName,
          0,
          this->trackName._Mysize,
          v8->_Bx._Buf,
          this->avatar->sim->track->name._Mysize)
    && !std::operator!=<wchar_t>(&this->carUnixName, &this->avatar->unixName) )
  {
    v9 = TrackAvatar::getConfig(this->avatar->sim->track, &result.name);
    LOBYTE(v22) = 3;
    v15 = 1;
    if ( !std::operator!=<wchar_t>(&this->trackConfig, v9) )
      v10 = 0;
  }
  v22 = 2;
  if ( (v15 & 1) != 0 )
    std::wstring::~wstring(&result);
  if ( v10 )
  {
    if ( !std::filebuf::close((std::filebuf *)in.gap10) )
      std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
    std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>((std::vector<SplineIndexBound> *)&buffer);
    goto LABEL_30;
  }
  std::istream::read(&in, &this->ghostCarLap);
  std::istream::read(&in, &framecount);
  std::vector<GhostCarFrame>::resize(&this->playingBuffer, framecount);
  std::istream::read(&in, this->playingBuffer._Myfirst);
  LOBYTE(v22) = 1;
  std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>((std::vector<SplineIndexBound> *)&buffer);
  if ( !std::filebuf::close((std::filebuf *)in.gap10) )
    std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
  v11 = 1;
LABEL_31:
  std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
  std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  return v11;
}
void GhostCarRecorder::onLapCompleted(GhostCarRecorder *this, const OnLapCompletedEvent *message)
{
  Car *v3; // ecx
  DriverInfo *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  Car *v8; // eax
  unsigned int v9; // ecx
  CarAvatar *v10; // ecx
  std::function<void __cdecl(void)> v11; // [esp-18h] [ebp-54h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement result; // [esp+14h] [ebp-28h] BYREF
  int v13; // [esp+38h] [ebp-4h]

  v3 = this->car;
  if ( v3->transponder.wasLastLapValid && this->isGhostCarLapValid && v3->transponder.lastLap < this->ghostCarLap )
  {
    if ( !this->recordingSwitch )
      goto LABEL_15;
    if ( !TimeTransponder::getCuts(&v3->transponder) )
    {
      v4 = &this->avatar->driverInfo;
      if ( &this->ghostDriverName != (std::wstring *)v4 )
        std::wstring::assign(&this->ghostDriverName, &v4->name, 0, 0xFFFFFFFF);
      v5 = &this->avatar->sim->track->name;
      if ( &this->trackName != v5 )
        std::wstring::assign(&this->trackName, v5, 0, 0xFFFFFFFF);
      v6 = TrackAvatar::getConfig(this->avatar->sim->track, &result.name);
      std::wstring::operator=(&this->trackConfig, v6);
      std::wstring::~wstring(&result);
      v7 = &this->avatar->unixName;
      if ( &this->carUnixName != v7 )
        std::wstring::assign(&this->carUnixName, v7, 0, 0xFFFFFFFF);
      this->ghostCarLap = this->car->transponder.lastLap;
      std::vector<GhostCarFrame>::operator=(&this->playingBuffer, &this->recordingBuffer);
      v8 = this->car;
      this->version = 4;
      this->needToSave = 1;
      v9 = v8->transponder.lastLap;
      v11._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_f2f448810aa79f7c0de2871735813746_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
      *(_QWORD *)&v11._Space._Alias[4] = __PAIR64__((unsigned int)this, v9);
      v11._Impl = (std::_Func_base<void> *)&v11;
      v10 = this->avatar;
      v13 = -1;
      Sim::executeOnMainThread(v10->sim, v11);
    }
  }
  if ( this->recordingSwitch )
  {
    std::_Container_base0::_Orphan_all(&this->recordingBuffer);
    this->recordingBuffer._Mylast = this->recordingBuffer._Myfirst;
  }
LABEL_15:
  this->isGhostCarLapValid = 1;
}
void GhostCarRecorder::onStepComplete(GhostCarRecorder *this, const OnStepCompleteEvent *ev)
{
  Car *v3; // eax
  const __m128i *v4; // eax
  int v5; // ebx
  __m128i *v6; // edi
  const __m128i *v7; // eax
  Car *v8; // ecx
  const __m128i *v9; // eax
  mat44f result; // [esp+14h] [ebp-284h] BYREF
  GhostCarFrame r; // [esp+54h] [ebp-244h] BYREF

  v3 = this->car;
  if ( v3->transponder.finishLinePassed )
    this->linePassedForTheFirstTime = 1;
  if ( ev->physicsTime - this->lastRecordTime >= 129.0 )
  {
    if ( this->recordingSwitch && this->linePassedForTheFirstTime && this->isGhostCarLapValid )
    {
      if ( v3->transponder.t > this->ghostCarLap )
        this->isGhostCarLapValid = 0;
      GhostCarFrame::GhostCarFrame(&r);
      v4 = (const __m128i *)((int (*)(IRigidBody *, mat44f *, _DWORD))this->car->body->getWorldMatrix)(
                              this->car->body,
                              &result,
                              0);
      v5 = 0;
      v6 = (__m128i *)r.wheels;
      *(__m128i *)&r.body.M11 = _mm_loadu_si128(v4);
      *(__m128i *)&r.body.M21 = _mm_loadu_si128(v4 + 1);
      *(__m128i *)&r.body.M31 = _mm_loadu_si128(v4 + 2);
      *(__m128i *)&r.body.M41 = _mm_loadu_si128(v4 + 3);
      do
      {
        v7 = (const __m128i *)Car::getSuspensionMatrix(this->car, &result, v5);
        v8 = this->car;
        v6[16] = _mm_loadu_si128(v7);
        v6[17] = _mm_loadu_si128(v7 + 1);
        v6[18] = _mm_loadu_si128(v7 + 2);
        v6[19] = _mm_loadu_si128(v7 + 3);
        v9 = (const __m128i *)Car::getTyreMatrix(v8, &result, v5++);
        v6 += 4;
        v6[-4] = _mm_loadu_si128(v9);
        v6[-3] = _mm_loadu_si128(v9 + 1);
        v6[-2] = _mm_loadu_si128(v9 + 2);
        v6[-1] = _mm_loadu_si128(v9 + 3);
      }
      while ( v5 < 4 );
      std::vector<GhostCarFrame>::push_back(&this->recordingBuffer, &r);
    }
    this->lastRecordTime = ev->physicsTime;
  }
  if ( this->playingSwitch
    && this->linePassedForTheFirstTime
    && this->playingBuffer._Myfirst != this->playingBuffer._Mylast
    && this->car->transponder.finishLinePassed )
  {
    this->currentFrame = 0;
  }
  this->currentLap = this->car->transponder.lapCount;
}
char GhostCarRecorder::saveGhostCarRecording(GhostCarRecorder *this)
{
  std::vector<char> encodedCarUnixName; // [esp+A4h] [ebp-11Ch] BYREF
  std::vector<char> encodedTrackConfig; // [esp+B0h] [ebp-110h] BYREF
  std::vector<char> encodedGhostDriverName; // [esp+BCh] [ebp-104h] BYREF
  std::vector<char> encodedTrackName; // [esp+C8h] [ebp-F8h] BYREF
  int framecount; // [esp+D4h] [ebp-ECh] BYREF
  unsigned int ghostDriverNameSize; // [esp+D8h] [ebp-E8h] BYREF
  unsigned int trackNameSize; // [esp+DCh] [ebp-E4h] BYREF
  int version; // [esp+E0h] [ebp-E0h] BYREF
  unsigned int trackConfigSize; // [esp+E4h] [ebp-DCh] BYREF
  unsigned int carUnixNameSize; // [esp+E8h] [ebp-D8h] BYREF
  int enableSuspension; // [esp+ECh] [ebp-D4h] BYREF
  std::ofstream out; // [esp+F0h] [ebp-D0h] BYREF
  std::wstring filename; // [esp+198h] [ebp-28h] BYREF
  int v16; // [esp+1BCh] [ebp-4h]

  GhostCarRecorder::getGhostCarFileName(this, &filename, 0);
  v16 = 0;
  std::ofstream::ofstream(&out, &filename, 34, 64, 1);
  LOBYTE(v16) = 1;
  version = 4;
  std::ostream::write(&out, &version, 4, 0);
  enableSuspension = 1;
  std::ostream::write(&out, &enableSuspension, 4, 0);
  ksEncodeUtf8(&encodedGhostDriverName, &this->ghostDriverName);
  ghostDriverNameSize = encodedGhostDriverName._Mylast - encodedGhostDriverName._Myfirst;
  LOBYTE(v16) = 2;
  std::ostream::write(&out, &ghostDriverNameSize, 4, 0);
  std::ostream::write(
    &out,
    encodedGhostDriverName._Myfirst,
    encodedGhostDriverName._Mylast - encodedGhostDriverName._Myfirst,
    0);
  ksEncodeUtf8(&encodedTrackName, &this->trackName);
  trackNameSize = encodedTrackName._Mylast - encodedTrackName._Myfirst;
  LOBYTE(v16) = 3;
  std::ostream::write(&out, &trackNameSize, 4, 0);
  std::ostream::write(&out, encodedTrackName._Myfirst, encodedTrackName._Mylast - encodedTrackName._Myfirst, 0);
  ksEncodeUtf8(&encodedTrackConfig, &this->trackConfig);
  trackConfigSize = encodedTrackConfig._Mylast - encodedTrackConfig._Myfirst;
  LOBYTE(v16) = 4;
  std::ostream::write(&out, &trackConfigSize, 4, 0);
  std::ostream::write(&out, encodedTrackConfig._Myfirst, encodedTrackConfig._Mylast - encodedTrackConfig._Myfirst, 0);
  ksEncodeUtf8(&encodedCarUnixName, &this->carUnixName);
  carUnixNameSize = encodedCarUnixName._Mylast - encodedCarUnixName._Myfirst;
  LOBYTE(v16) = 5;
  std::ostream::write(&out, &carUnixNameSize, 4, 0);
  std::ostream::write(&out, encodedCarUnixName._Myfirst, encodedCarUnixName._Mylast - encodedCarUnixName._Myfirst, 0);
  std::ostream::write(&out, &this->ghostCarLap, 4, 0);
  framecount = this->playingBuffer._Mylast - this->playingBuffer._Myfirst;
  std::ostream::write(&out, &framecount, 4, 0);
  std::ostream::write(
    &out,
    this->playingBuffer._Myfirst,
    576 * (this->playingBuffer._Mylast - this->playingBuffer._Myfirst),
    0);
  if ( !std::filebuf::close((std::filebuf *)&out.gap0[4]) )
    std::ios::setstate((char *)&out + *(_DWORD *)(*(_DWORD *)out.gap0 + 4), 2, 0);
  LOBYTE(v16) = 4;
  if ( encodedCarUnixName._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&encodedCarUnixName);
    operator delete(encodedCarUnixName._Myfirst);
    encodedCarUnixName._Myfirst = 0;
    encodedCarUnixName._Mylast = 0;
    encodedCarUnixName._Myend = 0;
  }
  LOBYTE(v16) = 3;
  if ( encodedTrackConfig._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&encodedTrackConfig);
    operator delete(encodedTrackConfig._Myfirst);
    encodedTrackConfig._Myfirst = 0;
    encodedTrackConfig._Mylast = 0;
    encodedTrackConfig._Myend = 0;
  }
  LOBYTE(v16) = 2;
  if ( encodedTrackName._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&encodedTrackName);
    operator delete(encodedTrackName._Myfirst);
    encodedTrackName._Myfirst = 0;
    encodedTrackName._Mylast = 0;
    encodedTrackName._Myend = 0;
  }
  LOBYTE(v16) = 1;
  if ( encodedGhostDriverName._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&encodedGhostDriverName);
    operator delete(encodedGhostDriverName._Myfirst);
    encodedGhostDriverName._Myfirst = 0;
    encodedGhostDriverName._Mylast = 0;
    encodedGhostDriverName._Myend = 0;
  }
  std::ofstream::~ofstream<char,std::char_traits<char>>((std::ofstream *)&out.gap58[8]);
  std::ios::~ios<char,std::char_traits<char>>(&out.gap58[8]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  return 1;
}
void GhostCarRecorder::setCurrentFrame(GhostCarRecorder *this, unsigned int frame)
{
  int v3; // ecx

  if ( frame >= ((int)((unsigned __int64)(954437177i64
                                        * ((char *)this->playingBuffer._Mylast - (char *)this->playingBuffer._Myfirst)) >> 32) >> 7)
              + ((unsigned int)((unsigned __int64)(954437177i64
                                                 * ((char *)this->playingBuffer._Mylast
                                                  - (char *)this->playingBuffer._Myfirst)) >> 32) >> 31)
              - 2 )
  {
    v3 = (char *)this->playingBuffer._Mylast - (char *)this->playingBuffer._Myfirst;
    this->currentFrame = ((int)((unsigned __int64)(954437177i64 * v3) >> 32) >> 7)
                       + ((unsigned int)((unsigned __int64)(954437177i64 * v3) >> 32) >> 31)
                       - 2;
  }
  else
  {
    this->currentFrame = frame;
  }
}
bool GhostCarRecorder::shouldDisplayGhostCar(GhostCarRecorder *this)
{
  GhostCarFrame *v1; // eax

  v1 = this->playingBuffer._Myfirst;
  return v1 != this->playingBuffer._Mylast
      && this->currentFrame < ((int)((unsigned __int64)(954437177i64 * ((char *)this->playingBuffer._Mylast - (char *)v1)) >> 32) >> 7)
                            + ((unsigned int)((unsigned __int64)(954437177i64
                                                               * ((char *)this->playingBuffer._Mylast - (char *)v1)) >> 32) >> 31)
                            - 2
      && this->playingSwitch
      && this->linePassedForTheFirstTime;
}
