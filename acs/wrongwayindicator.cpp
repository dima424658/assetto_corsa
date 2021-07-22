#include "wrongwayindicator.h"
void __userpurge WrongWayIndicator::WrongWayIndicator(WrongWayIndicator *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *car)
{
  Event<OnReplayStatusChanged> *v4; // ecx
  Game *v5; // eax
  Texture *v6; // eax
  bool v7; // bl
  int v8; // eax
  bool v9; // cf
  std::wstring v10; // [esp-1Ch] [ebp-C0h] BYREF
  unsigned int v11; // [esp-4h] [ebp-A8h]
  WrongWayIndicator *v12; // [esp+18h] [ebp-8Ch]
  std::wstring filename; // [esp+1Ch] [ebp-88h] BYREF
  Texture result; // [esp+34h] [ebp-70h] BYREF
  INIReaderDocuments raceINI; // [esp+50h] [ebp-54h] BYREF
  int v16; // [esp+A0h] [ebp-4h]

  v12 = this;
  v11 = (unsigned int)car->game;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"WRONG WAY INDICATOR", 0x13u);
  GameObject::GameObject(this, v10, (Game *)v11);
  this->__vftable = (WrongWayIndicator_vtbl *)&WrongWayIndicator::`vftable';
  v16 = 0;
  this->evOnDrivingWrongWay.handlers._Myfirst = 0;
  this->evOnDrivingWrongWay.handlers._Mylast = 0;
  this->evOnDrivingWrongWay.handlers._Myend = 0;
  this->carAvatar = car;
  this->texture.kid = 0;
  this->texture.fileName._Myres = 7;
  this->texture.fileName._Mysize = 0;
  this->texture.fileName._Bx._Buf[0] = 0;
  v11 = (unsigned int)this;
  this->meterCounter = 0.0;
  this->lastPositionOnSpline = 0.0;
  this->penalties = 0;
  v10._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_15bee7ef677e544a22a0e0a0d49966b5_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v10._Bx._Alias[4] = this;
  v10._Mysize = (unsigned int)&v10;
  v4 = &car->sim->evOnReplayStatusChanged;
  LOBYTE(v16) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v4,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v10,
    (void *)v11);
  v11 = 28;
  this->isWrongWay = 0;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/texture/wrongway.png", v11);
  v5 = this->game;
  LOBYTE(v16) = 4;
  v6 = ResourceStore::getTexture(v5->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->texture.kid = v6->kid;
  LOBYTE(v16) = 5;
  if ( &this->texture.fileName != &v6->fileName )
    std::wstring::assign(&this->texture.fileName, &v6->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v16) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v16) = 2;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v11 = 0;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&raceINI, a2, v10, v11);
  LOBYTE(v16) = 6;
  if ( raceINI.ready )
  {
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"RACE", 4u);
    LOBYTE(v16) = 7;
    v7 = INIReader::hasSection(&raceINI, &filename);
    LOBYTE(v16) = 6;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    if ( v7 )
    {
      std::wstring::wstring((std::wstring *)&result, L"PENALTIES");
      LOBYTE(v16) = 8;
      std::wstring::wstring(&filename, L"RACE");
      LOBYTE(v16) = 9;
      v8 = INIReader::getInt(&raceINI, &filename, (const std::wstring *)&result);
      v9 = filename._Myres < 8;
      this->penalties = v8 != 0;
      if ( !v9 )
        operator delete(filename._Bx._Ptr);
      filename._Myres = 7;
      filename._Mysize = 0;
      filename._Bx._Buf[0] = 0;
      if ( result.fileName._Mysize >= 8 )
        operator delete(result.kid);
    }
  }
  LOBYTE(v16) = 2;
  INIReaderDocuments::~INIReaderDocuments(&raceINI);
}
void WrongWayIndicator::~WrongWayIndicator(WrongWayIndicator *this)
{
  this->__vftable = (WrongWayIndicator_vtbl *)&WrongWayIndicator::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->texture);
  if ( this->evOnDrivingWrongWay.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnDrivingWrongWay);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnDrivingWrongWay,
      (Task *)this->evOnDrivingWrongWay.handlers._Myfirst,
      (Task *)this->evOnDrivingWrongWay.handlers._Mylast);
    operator delete(this->evOnDrivingWrongWay.handlers._Myfirst);
    this->evOnDrivingWrongWay.handlers._Myfirst = 0;
    this->evOnDrivingWrongWay.handlers._Mylast = 0;
    this->evOnDrivingWrongWay.handlers._Myend = 0;
  }
  GameObject::~GameObject(this);
}
WrongWayIndicator *WrongWayIndicator::`scalar deleting destructor'(WrongWayIndicator *this, unsigned int a2)
{
  WrongWayIndicator::~WrongWayIndicator(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void WrongWayIndicator::renderHUD(WrongWayIndicator *this, float deltaT)
{
  ACCameraManager *v3; // eax
  void *v4; // eax
  Texture *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  GraphicsManager *v8; // ebx
  GLRenderer *v9; // ebx
  unsigned int v10; // esi
  unsigned int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm0_4
  float g; // [esp+Ch] [ebp-20h]
  float y; // [esp+24h] [ebp-8h]
  float x; // [esp+28h] [ebp-4h]

  v3 = this->carAvatar->sim->cameraManager;
  if ( !v3->randomMode && v3->mode != eTrack )
  {
    v4 = this->texture.kid;
    v5 = &this->texture;
    v6 = v4 ? kglTextureGetWidth(v4) : 0;
    x = (float)(this->game->graphics->videoSettings.width / 2 - (v6 >> 1));
    v7 = v5->kid ? kglTextureGetHeight(v5->kid) : 0;
    v8 = this->game->graphics;
    y = (float)(v8->videoSettings.height / 4 - (v7 >> 1));
    if ( this->isWrongWay )
    {
      GraphicsManager::setTexture(v8, 0, &this->texture);
      GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
      v9 = this->game->graphics->gl;
      GLRenderer::color4f(v9, 1.0, 1.0, 1.0, 1.0);
      if ( v5->kid )
        v10 = kglTextureGetHeight(v5->kid);
      else
        v10 = 0;
      if ( v5->kid )
        v11 = kglTextureGetWidth(v5->kid);
      else
        v11 = 0;
      v12 = (float)v10;
      g = v12;
      v13 = (float)v11;
      GLRenderer::quad(v9, x, y, v13, g, 1, 0);
    }
  }
}
void WrongWayIndicator::resetMeterCounter(WrongWayIndicator *this)
{
  this->meterCounter = 0.0;
}
void WrongWayIndicator::update(WrongWayIndicator *this, float deltaT)
{
  WrongWayIndicator *v2; // edi
  CarAvatar *v3; // ecx
  float v4; // xmm1_4
  InterpolatingSpline *v5; // esi
  vec3f *v6; // edi
  vec3f *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  CarAvatar *v11; // eax
  float v12; // xmm0_4
  CarAvatar *v13; // ecx
  const std::wstring *v14; // esi
  CarAvatar *v15; // eax
  const std::wstring *v16; // [esp-8h] [ebp-BCh]
  vec3f v17; // [esp+10h] [ebp-A4h] BYREF
  vec3f result; // [esp+1Ch] [ebp-98h] BYREF
  WrongWayIndicator *v19; // [esp+28h] [ebp-8Ch]
  std::wstring v20; // [esp+2Ch] [ebp-88h] BYREF
  std::wstring v21; // [esp+44h] [ebp-70h] BYREF
  std::wstring text; // [esp+5Ch] [ebp-58h] BYREF
  std::wstring v23; // [esp+74h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement setName; // [esp+8Ch] [ebp-28h] BYREF
  int v25; // [esp+B0h] [ebp-4h]

  v2 = this;
  v19 = this;
  CarAvatar::getRoadDirection(this->carAvatar, &result);
  v3 = v2->carAvatar;
  v4 = (float)((float)(result.x * COERCE_FLOAT(LODWORD(v3->physicsState.worldMatrix.M31) ^ _xmm))
             + (float)(result.y * COERCE_FLOAT(LODWORD(v3->physicsState.worldMatrix.M32) ^ _xmm)))
     + (float)(result.z * COERCE_FLOAT(LODWORD(v3->physicsState.worldMatrix.M33) ^ _xmm));
  v2->isWrongWay = v4 > 0.40000001;
  if ( v4 <= 0.40000001 )
  {
    v2->meterCounter = 0.0;
  }
  else if ( v2->lastPositionOnSpline > v3->physicsState.normalizedSplinePosition )
  {
    v5 = &TrackAvatar::getAISpline(v3->sim->track)->spline;
    v6 = InterpolatingSpline::splineToWorld(v5, &v17, v2->carAvatar->physicsState.normalizedSplinePosition);
    v7 = InterpolatingSpline::splineToWorld(v5, (vec3f *)&setName.name._Bx._Alias[12], v19->lastPositionOnSpline);
    v8 = v7->z - v6->z;
    v9 = (float)((float)((float)(v7->x - v6->x) * (float)(v7->x - v6->x))
               + (float)((float)(v7->y - v6->y) * (float)(v7->y - v6->y)))
       + (float)(v8 * v8);
    v10 = 0.0;
    if ( v9 != 0.0 )
      v10 = fsqrt(v9);
    v2 = v19;
    v11 = v19->carAvatar;
    v12 = v19->meterCounter + v10;
    v19->meterCounter = v12;
    if ( v11->sim->client || v12 <= 500.0 || !v2->penalties )
    {
      Event<std::wstring>::trigger(
        (Event<OnGearRequestEvent> *)&v2->evOnDrivingWrongWay,
        (const OnGearRequestEvent *)&v2->meterCounter);
    }
    else
    {
      std::wstring::wstring(&setName.name, L"PIT");
      v13 = v2->carAvatar;
      v25 = 0;
      CarAvatar::goToSpawnPosition(v13, &setName.name);
      v25 = -1;
      std::wstring::~wstring(&setName);
      std::wstring::wstring(&text, L"Driving wrong way");
      v25 = 1;
      std::wstring::wstring(&v23, L"Warning");
      LOBYTE(v25) = 2;
      v14 = acTranslate(&v21, &text);
      LOBYTE(v25) = 3;
      v16 = acTranslate(&v20, &v23);
      v15 = v2->carAvatar;
      LOBYTE(v25) = 4;
      SystemMessage::addMessage(v15->sim->systemMessage, v16, v14, eDefault);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v20);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v21);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v23);
      v25 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v2->meterCounter = 0.0;
      Event<std::wstring>::trigger(
        (Event<OnGearRequestEvent> *)&v2->evOnDrivingWrongWay,
        (const OnGearRequestEvent *)&v2->meterCounter);
    }
  }
  v2->lastPositionOnSpline = v2->carAvatar->physicsState.normalizedSplinePosition;
}
