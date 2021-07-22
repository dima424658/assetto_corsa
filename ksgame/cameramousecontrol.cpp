#include "cameramousecontrol.h
void CameraMouseControl::CameraMouseControl(CameraMouseControl *this, std::wstring name, Camera *camera, Game *igame)
{
  Camera *v5; // esi
  std::wstring v6; // [esp-1Ch] [ebp-CCh] BYREF
  unsigned int v7; // [esp-4h] [ebp-B4h]
  float userDistanceScale; // [esp+Ch] [ebp-A4h]
  CameraMouseControl *v9; // [esp+10h] [ebp-A0h]
  std::wstring ifilename; // [esp+14h] [ebp-9Ch] BYREF
  std::wstring section; // [esp+2Ch] [ebp-84h] BYREF
  std::wstring key; // [esp+44h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+5Ch] [ebp-54h] BYREF
  int v14; // [esp+ACh] [ebp-4h]

  v5 = camera;
  v9 = this;
  v7 = (unsigned int)igame;
  v14 = 0;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, &name, 0, 0xFFFFFFFF);
  GameObject::GameObject(this, v6, (Game *)v7);
  v7 = (unsigned int)v5;
  LOBYTE(v14) = 1;
  this->__vftable = (CameraMouseControl_vtbl *)&CameraMouseControl::`vftable';
  CameraMouseControlBase::CameraMouseControlBase(&this->base, (Camera *)v7);
  this->initialized = 0;
  v7 = 27;
  this->prevPosition.x = 0.0;
  this->prevPosition.y = 0.0;
  this->prevPosition.z = 0.0;
  v6._Myres = (unsigned int)L"system/cfg/camera_track.ini";
  LOBYTE(v14) = 2;
  this->base.moveSpeed = 25.0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v6._Myres, v7);
  LOBYTE(v14) = 3;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v14) = 5;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISTANCE_SCALE", 0xEu);
    LOBYTE(v14) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAMERA_SETTINGS", 0xFu);
    LOBYTE(v14) = 7;
    userDistanceScale = INIReader::getFloat(&ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    this->distanceScale = 1.0 / userDistanceScale;
  }
  LOBYTE(v14) = 2;
  INIReader::~INIReader(&ini);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
CameraMouseControl *CameraMouseControl::`scalar deleting destructor'(CameraMouseControl *this, unsigned int a2)
{
  this->__vftable = (CameraMouseControl_vtbl *)&CameraMouseControl::`vftable';
  CameraMouseControlBase::~CameraMouseControlBase(&this->base);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraMouseControl::setAudioDistanceScale(CameraMouseControl *this)
{
  AudioEngine::setDistanceScale(this->game->audioEngine, this->distanceScale);
}
void CameraMouseControl::update(CameraMouseControl *this, float deltaT)
{
  GameObject *v3; // eax
  GameObject *v4; // ecx
  GameObject *v5; // eax
  float v6; // xmm3_4
  float v7; // xmm4_4
  const mat44f *v8; // eax
  __int64 currPosition; // [esp+Ch] [ebp-58h]
  float currPosition_8; // [esp+14h] [ebp-50h]
  vec3f velocity; // [esp+18h] [ebp-4Ch] BYREF
  char v12[64]; // [esp+24h] [ebp-40h] BYREF

  CameraMouseControlBase::update(&this->base, deltaT);
  v3 = GameObject::getParent((GameObject *)&this->base);
  v4 = (GameObject *)&this->base;
  currPosition = *(_QWORD *)&v3[1].game;
  currPosition_8 = *(float *)&v3[1].name._Bx._Alias[4];
  if ( this->initialized )
  {
    v5 = GameObject::getParent(v4);
    v6 = *((float *)&currPosition + 1) - this->prevPosition.y;
    v7 = currPosition_8 - this->prevPosition.z;
    velocity.x = (float)(1.0 / deltaT) * (float)(*(float *)&currPosition - this->prevPosition.x);
    velocity.y = (float)(1.0 / deltaT) * v6;
    velocity.z = (float)(1.0 / deltaT) * v7;
  }
  else
  {
    v5 = GameObject::getParent(v4);
    velocity.x = 0.0;
    velocity.y = 0.0;
    velocity.z = 0.0;
  }
  v8 = (const mat44f *)((int (*)(GameObject *, char *))v5->renderAudio)(v5, v12);
  AudioEngine::setListener(this->game->audioEngine, v8, &velocity);
  *(_QWORD *)&this->prevPosition.x = currPosition;
  this->prevPosition.z = currPosition_8;
  this->initialized = 1;
}
