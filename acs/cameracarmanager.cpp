#include "cameracarmanager.h
void CameraCarManager::CameraCarManager(CameraCarManager *this, Sim *a_sim, CameraForward *a_camera)
{
  std::wstring v4; // [esp-1Ch] [ebp-24h] BYREF
  Game *v5; // [esp-4h] [ebp-Ch]

  v5 = a_sim->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"CAMERA_CAR_MANAGER", 0x12u);
  GameObject::GameObject(this, v4, v5);
  this->camera = a_camera;
  this->sim = a_sim;
  this->__vftable = (CameraCarManager_vtbl *)&CameraCarManager::`vftable';
  this->currentCameraIndex = 0;
}
CameraCarManager *CameraCarManager::`scalar deleting destructor'(CameraCarManager *this, unsigned int a2)
{
  this->__vftable = (CameraCarManager_vtbl *)&CameraCarManager::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
int CameraCarManager::getCameraCount(CameraCarManager *this)
{
  unsigned int v2; // eax
  CarAvatar *v3; // eax

  v2 = Sim::getFocusedCarIndex(this->sim);
  v3 = Sim::getCar(this->sim, v2);
  return v3->cameras._Mylast - v3->cameras._Myfirst;
}
void CameraCarManager::nextCamera(CameraCarManager *this)
{
  Sim *v2; // ecx
  unsigned int v3; // eax
  CarAvatar *v4; // eax

  v2 = this->sim;
  ++this->currentCameraIndex;
  v3 = Sim::getFocusedCarIndex(v2);
  v4 = Sim::getCar(this->sim, v3);
  if ( this->currentCameraIndex >= v4->cameras._Mylast - v4->cameras._Myfirst )
    this->currentCameraIndex = 0;
}
void CameraCarManager::setCurrentCamera(CameraCarManager *this, unsigned int cameraIndex)
{
  unsigned int v3; // eax
  CarAvatar *v4; // eax

  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  if ( cameraIndex < v4->cameras._Mylast - v4->cameras._Myfirst )
    this->currentCameraIndex = cameraIndex;
}
void CameraCarManager::update(CameraCarManager *this, float dt)
{
  unsigned int v3; // eax
  CarAvatar *v4; // esi
  Node *v5; // eax
  __m128 *v6; // ecx
  __m128 v7; // xmm1
  CameraForward *v8; // esi
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  unsigned int v15; // eax
  CarAvatar *v16; // eax
  DirectX::XMMATRIX M2; // [esp+20h] [ebp-40h] BYREF

  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  if ( this->currentCameraIndex >= v4->cameras._Mylast - v4->cameras._Myfirst )
    this->currentCameraIndex = 0;
  this->camera->dofFactor = 0.0;
  this->camera->fov = v4->cameras._Myfirst[this->currentCameraIndex].fov;
  this->camera->exposure = v4->cameras._Myfirst[this->currentCameraIndex].exposure;
  this->camera->minExposure = this->sim->hdrLevels.minExposure;
  this->camera->maxExposure = this->sim->hdrLevels.maxExposure;
  this->camera->chromaticAberrationEnabled = 1;
  this->camera->lensFlare = 1;
  CameraShadowMapped::setShadowMapsSplits(this->camera, 1.3, 80.0, 250.0, 500.0);
  v5 = v4->bodyTransform;
  v6 = (__m128 *)&v4->cameras._Myfirst[this->currentCameraIndex];
  v7 = *(__m128 *)&v5->matrix.M21;
  v8 = this->camera;
  v9 = *(__m128 *)&v5->matrix.M31;
  v10 = *(__m128 *)&v5->matrix.M41;
  M2.r[0] = *(__m128 *)&v5->matrix.M11;
  v11 = *v6;
  M2.r[1] = v7;
  v12 = v6[1];
  M2.r[2] = v9;
  v13 = v6[2];
  M2.r[3] = v10;
  v14 = v6[3];
  *(__m128 *)&v8->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, v11);
  *(__m128 *)&v8->matrix.M21 = v12;
  *(__m128 *)&v8->matrix.M31 = v13;
  *(__m128 *)&v8->matrix.M41 = v14;
  v15 = Sim::getFocusedCarIndex(this->sim);
  v16 = Sim::getCar(this->sim, v15);
  AudioEngine::setListener(this->game->audioEngine, &this->camera->matrix, &v16->physicsState.velocity);
}
