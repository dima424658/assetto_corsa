#include "steeringsystem.h"
void __userpurge SteeringSystem::init(SteeringSystem *this@<ecx>, unsigned int a2@<ebx>, Car *car)
{
  int v4; // eax
  int v5; // esi
  DynamicController v6; // [esp+Ch] [ebp-3Ch] BYREF
  std::wstring filename; // [esp+20h] [ebp-28h] BYREF
  int v8; // [esp+44h] [ebp-4h]

  this->linearRatio = 0.003;
  this->car = car;
  std::operator+<wchar_t>(&filename, &car->carDataPath, L"ctrl_4ws.ini");
  v8 = 0;
  if ( Path::fileExists(a2, &filename, 0) )
  {
    _printf("Initializing 4ws\n");
    DynamicController::DynamicController(&v6, car, &filename);
    v5 = v4;
    this->ctrl4ws.car = *(Car **)v4;
    LOBYTE(v8) = 1;
    std::vector<DynamicControllerStage>::operator=(
      &this->ctrl4ws.stages,
      (const std::vector<DynamicControllerStage> *)(v4 + 4));
    this->ctrl4ws.ready = *(_BYTE *)(v5 + 16);
    LOBYTE(v8) = 0;
    DynamicController::~DynamicController(&v6);
    this->has4ws = 1;
  }
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void SteeringSystem::step(SteeringSystem *this, float dt)
{
  int v3; // ecx
  int v4; // ecx
  float v5; // [esp+14h] [ebp-4h]

  (*(void (**)(ISuspension *, _DWORD))(**(_DWORD **)this->car->suspensions._Myfirst + 20))(
    *this->car->suspensions._Myfirst,
    COERCE_UNSIGNED_INT(this->car->finalSteerAngleSignal * this->linearRatio) ^ _xmm);
  (*(void (**)(_DWORD, _DWORD))(**((_DWORD **)this->car->suspensions._Myfirst + 1) + 20))(
    *((_DWORD *)this->car->suspensions._Myfirst + 1),
    COERCE_UNSIGNED_INT(this->car->finalSteerAngleSignal * this->linearRatio) ^ _xmm);
  if ( this->has4ws )
  {
    v5 = DynamicController::eval(&this->ctrl4ws);
    v3 = *((_DWORD *)this->car->suspensions._Myfirst + 2);
    (*(void (**)(int, _DWORD))(*(_DWORD *)v3 + 20))(v3, LODWORD(v5));
    v4 = *((_DWORD *)this->car->suspensions._Myfirst + 3);
    (*(void (**)(int, _DWORD))(*(_DWORD *)v4 + 20))(v4, LODWORD(v5));
  }
}
