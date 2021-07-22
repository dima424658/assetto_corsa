#include "vivemanager.h"
void ViveManager::ViveManager(ViveManager *this, Sim *aSim, StereoCameraVive *aStereoCamera)
{
  Game *v4; // eax
  Texture *v5; // eax
  std::wstring v6; // [esp-1Ch] [ebp-74h] BYREF
  Game *v7; // [esp-4h] [ebp-5Ch]
  ViveManager *v8; // [esp+10h] [ebp-48h]
  std::wstring filename; // [esp+14h] [ebp-44h] BYREF
  Texture result; // [esp+2Ch] [ebp-2Ch] BYREF
  int v11; // [esp+54h] [ebp-4h]

  v8 = this;
  v7 = aSim->game;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, L"VIVE_MANAGER", 0xCu);
  GameObject::GameObject(this, v6, v7);
  this->camera = aStereoCamera;
  this->__vftable = (ViveManager_vtbl *)&ViveManager::`vftable';
  this->sim = aSim;
  this->firstUpdate = 0;
  this->srcBeep = 0;
  this->acLogoTexture.kid = 0;
  this->acLogoTexture.fileName._Myres = 7;
  this->acLogoTexture.fileName._Mysize = 0;
  v11 = 0;
  this->acLogoTexture.fileName._Bx._Buf[0] = 0;
  LOBYTE(v11) = 1;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/fade/fade_default.png", 0x21u);
  v4 = this->game;
  LOBYTE(v11) = 2;
  v5 = ResourceStore::getTexture(v4->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->acLogoTexture.kid = v5->kid;
  LOBYTE(v11) = 3;
  if ( &this->acLogoTexture.fileName != &v5->fileName )
    std::wstring::assign(&this->acLogoTexture.fileName, &v5->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v11) = 2;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  this->game->isRenderingGui = 0;
  this->game->isSwappingBuffer = 0;
}
ViveManager *ViveManager::`scalar deleting destructor'(ViveManager *this, unsigned int a2)
{
  this->__vftable = (ViveManager_vtbl *)&ViveManager::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->acLogoTexture);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ViveManager::update(ViveManager *this, float dt)
{
  Sim *v3; // ecx
  Sim *v4; // ecx
  Sim *v5; // ecx
  ACCameraManager *v6; // ecx
  int v7; // eax
  std::function<void __cdecl(bool const &)> v8; // [esp-1Ch] [ebp-48h] BYREF
  ViveManager *v9; // [esp-4h] [ebp-30h]
  __m128i v10; // [esp+10h] [ebp-1Ch] BYREF
  int v11; // [esp+28h] [ebp-4h]

  if ( !this->firstUpdate )
  {
    v3 = this->sim;
    v9 = 0;
    (&v8._Impl)[1] = (std::_Func_base<void,bool const &> *)1;
    this->firstUpdate = 1;
    ACCameraManager::setMode(v3->cameraManager, eCockpit, (bool)(&v8._Impl)[1], (bool)v9);
    StereoCameraVive::resetHeadPosition(this->camera);
    if ( this->sim->isRoomVR )
    {
      v9 = this;
      v8._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_1031aa408336c756c37781a723b40cd3_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
      v8._Space._Pfn[1] = (void (__cdecl *)())this;
      v8._Impl = (std::_Func_base<void,bool const &> *)&v8;
      v4 = this->sim;
      v11 = -1;
      ACCameraManager::registerToFadeInEvent(v4->cameraManager, v8, this);
      v5 = this->sim;
      v10.m128i_i32[0] = 0;
      v10.m128i_i32[3] = (int)this;
      v6 = v5->cameraManager;
      *(__int64 *)((char *)v10.m128i_i64 + 4) = 0x3F00000000000000i64;
      ACCameraManager::fadeIn(v6, (FadeModeDef)_mm_loadu_si128(&v10));
    }
  }
  v7 = Sim::getCar(this->sim, 0)->physicsState.actionsState.state;
  if ( (v7 & 1) != 0 && (v7 & 2) != 0 )
    StereoCameraVive::resetHeadPosition(this->camera);
}
