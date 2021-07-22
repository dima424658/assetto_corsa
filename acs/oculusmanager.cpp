#include "oculusmanager.h"
void __userpurge OculusManager::OculusManager(OculusManager *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim, StereoCameraForward *aStereoCamera)
{
  Game *v5; // eax
  Texture *v6; // eax
  Game *v7; // eax
  bool v8; // bl
  std::wstring v9; // [esp-1Ch] [ebp-1C0h] BYREF
  Game *v10; // [esp-4h] [ebp-1A8h]
  unsigned int deviceIndex[3]; // [esp+10h] [ebp-194h] BYREF
  std::wstring filename; // [esp+1Ch] [ebp-188h] BYREF
  Texture result; // [esp+34h] [ebp-170h] BYREF
  INIReaderDocuments ini; // [esp+50h] [ebp-154h] BYREF
  wchar_t desc[128]; // [esp+94h] [ebp-110h] BYREF
  int v16; // [esp+1A0h] [ebp-4h]

  deviceIndex[2] = (unsigned int)this;
  v10 = aSim->game;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"OCULUS_MANAGER", 0xEu);
  GameObject::GameObject(this, v9, v10);
  this->camera = aStereoCamera;
  this->__vftable = (OculusManager_vtbl *)&OculusManager::`vftable';
  this->sim = aSim;
  this->firstUpdate = 0;
  this->srcBeep = 0;
  this->acLogoTexture.kid = 0;
  this->acLogoTexture.fileName._Myres = 7;
  this->acLogoTexture.fileName._Mysize = 0;
  v16 = 0;
  this->acLogoTexture.fileName._Bx._Buf[0] = 0;
  LOBYTE(v16) = 1;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/fade/fade_default.png", 0x21u);
  v5 = this->game;
  LOBYTE(v16) = 2;
  v6 = ResourceStore::getTexture(v5->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->acLogoTexture.kid = v6->kid;
  LOBYTE(v16) = 3;
  if ( &this->acLogoTexture.fileName != &v6->fileName )
    std::wstring::assign(&this->acLogoTexture.fileName, &v6->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v16) = 2;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v16) = 1;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v7 = this->game;
  v10 = 0;
  v7->isRenderingGui = 0;
  this->game->isSwappingBuffer = 0;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"cfg/oculus.ini", 0xEu);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, v9, (bool)v10);
  LOBYTE(v16) = 4;
  if ( ini.ready )
  {
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    std::wstring::assign((std::wstring *)&result, L"AUTOSELECT_RIFT_AUDIO_DEVICE", 0x1Cu);
    LOBYTE(v16) = 5;
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"SETTINGS", 8u);
    LOBYTE(v16) = 6;
    v8 = INIReader::getInt(&ini, &filename, (const std::wstring *)&result) != 0;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    LOBYTE(v16) = 4;
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    if ( v8 )
    {
      _printf("Autoselecting Oculus Rift Audio Device\n");
      deviceIndex[0] = 0;
      if ( ovr_GetAudioDeviceOutWaveId(deviceIndex) )
      {
        _printf("CANNOT FIND OCULUS AUDIO DEVICE\n");
      }
      else
      {
        _printf("Selecting audio device: %d\n", deviceIndex[0]);
        ovr_GetAudioDeviceOutGuidStr(desc);
        _printf("Device name: %S\n", desc);
        AudioEngine::setDriver(this->game->audioEngine, deviceIndex[0]);
      }
    }
  }
  LOBYTE(v16) = 1;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
OculusManager *OculusManager::`vector deleting destructor'(OculusManager *this, unsigned int a2)
{
  this->__vftable = (OculusManager_vtbl *)&OculusManager::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->acLogoTexture);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void OculusManager::update(OculusManager *this, float dt)
{
  Sim *v3; // ecx
  int v4; // eax

  if ( !this->firstUpdate )
  {
    v3 = this->sim;
    this->firstUpdate = 1;
    ACCameraManager::setMode(v3->cameraManager, eCockpit, 1, 0);
    StereoCameraForward::resetHeadPosition(this->camera);
  }
  v4 = Sim::getCar(this->sim, 0)->physicsState.actionsState.state;
  if ( (v4 & 1) != 0 && (v4 & 2) != 0 )
    StereoCameraForward::resetHeadPosition(this->camera);
}
