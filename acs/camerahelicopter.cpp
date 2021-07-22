#include "camerahelicopter.h
void CameraHelicopter::CameraHelicopter(CameraHelicopter *this, Sim *a_sim, CameraForward *a_camera)
{
  std::wstring v4; // [esp-1Ch] [ebp-24h] BYREF
  Game *v5; // [esp-4h] [ebp-Ch]

  v5 = a_sim->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"HELICOPTER CAMERA", 0x11u);
  GameObject::GameObject(this, v4, v5);
  this->__vftable = (CameraHelicopter_vtbl *)&CameraHelicopter::`vftable';
  this->helicopterOffset.x = 0.0;
  this->helicopterOffset.y = 0.0;
  this->helicopterOffset.z = 0.0;
  this->camera = a_camera;
  this->sim = a_sim;
}
CameraHelicopter *CameraHelicopter::`vector deleting destructor'(CameraHelicopter *this, unsigned int a2)
{
  this->__vftable = (CameraHelicopter_vtbl *)&CameraHelicopter::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraHelicopter::update(CameraHelicopter *this, float deltaT)
{
  unsigned int v3; // eax
  CarAvatar *v4; // eax
  Sim *v5; // ecx
  unsigned int v6; // eax
  Node *v7; // eax
  const __m128i *v8; // eax
  CameraForward *v9; // ecx
  __m128i v10; // xmm0
  vec3f cameraTarget; // [esp+4h] [ebp-58h] BYREF
  vec3f cameraPosition; // [esp+10h] [ebp-4Ch] BYREF
  mat44f result; // [esp+1Ch] [ebp-40h] BYREF

  v3 = Sim::getFocusedCarIndex(this->sim);
  v4 = Sim::getCar(this->sim, v3);
  v5 = this->sim;
  cameraTarget = *(vec3f *)&v4->bodyTransform->matrix.M41;
  v6 = Sim::getFocusedCarIndex(v5);
  v7 = Sim::getCar(this->sim, v6)->bodyTransform;
  cameraPosition.x = this->helicopterOffset.x + v7->matrix.M41;
  cameraPosition.y = this->helicopterOffset.y + v7->matrix.M42;
  cameraPosition.z = this->helicopterOffset.z + v7->matrix.M43;
  v8 = (const __m128i *)mat44f::createTarget(&result, &cameraPosition, &cameraTarget);
  v9 = this->camera;
  cameraPosition.x = 0.0;
  cameraPosition.y = 0.0;
  v10 = _mm_loadu_si128(v8);
  cameraPosition.z = 0.0;
  *(__m128i *)&v9->matrix.M11 = v10;
  *(__m128i *)&v9->matrix.M21 = _mm_loadu_si128(v8 + 1);
  *(__m128i *)&v9->matrix.M31 = _mm_loadu_si128(v8 + 2);
  *(__m128i *)&v9->matrix.M41 = _mm_loadu_si128(v8 + 3);
  this->camera->fov = 20.0;
  this->camera->nearPlane = 1.0;
  this->camera->farPlane = 35000.0;
  this->camera->dofFactor = 0.0;
  AudioEngine::setListener(this->game->audioEngine, &this->camera->matrix, &cameraPosition);
}
