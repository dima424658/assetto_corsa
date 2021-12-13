#include "car.h"
void __userpurge Car::Car(Car *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, PhysicsEngine *iengine, const std::wstring *iunixName, const std::wstring *config)
{
  float v6; // ebx
  const std::wstring *v7; // edi
  std::wstring *v8; // ecx
  bool v9; // cf
  const std::wstring *v10; // eax
  int v11; // ecx
  PhysicsEngine *v12; // ecx
  IPhysicsCore *v13; // eax
  int v14; // eax
  PhysicsEngine *v15; // ecx
  IPhysicsCore *v16; // eax
  const std::wstring *v17; // eax
  const std::wstring *v18; // eax
  std::wstring *v19; // eax
  IPhysicsCore *v20; // eax
  double v21; // st7
  int i; // edi
  std::wstring *v23; // esi
  std::wstring *v24; // esi
  ISuspension *v25; // esi
  SuspensionStrut *v26; // eax
  ISuspension *v27; // eax
  Suspension *v28; // eax
  ISuspension *v29; // eax
  SuspensionML *v30; // eax
  ISuspension *v31; // eax
  SuspensionAxle *v32; // eax
  ISuspension *v33; // eax
  SuspensionAxle *v34; // eax
  ISuspension *v35; // eax
  SuspensionAxle *v36; // eax
  _DWORD *v37; // ecx
  _DWORD *v38; // esi
  int v39; // esi
  int v40; // edi
  const std::wstring *v41; // ebx
  const wchar_t *v42; // eax
  void (*v43)(const char *const, ...); // edi
  int v44; // eax
  int v45; // eax
  char v46; // al
  int v47; // ecx
  Event<SessionInfo> *v48; // ecx
  Event<SessionInfo> *v49; // ecx
  std::wstring *v50; // eax
  const std::wstring *v51; // eax
  char v52; // al
  AISpline *v53; // esi
  double v54; // st7
  float v55; // xmm0_4
  double v56; // st7
  double v57; // st7
  double v58; // st7
  std::wstring *v59; // eax
  _BYTE v60[36]; // [esp+Ch] [ebp-1E8h] BYREF
  ISuspension *crsus; // [esp+4Ch] [ebp-1A8h] BYREF
  bool v62; // [esp+53h] [ebp-1A1h]
  float efpl; // [esp+54h] [ebp-1A0h] BYREF
  std::vector<std::wstring> *v64; // [esp+58h] [ebp-19Ch]
  std::wstring *v65; // [esp+5Ch] [ebp-198h]
  RaceEngineer eng; // [esp+64h] [ebp-190h] BYREF
  Car *v67; // [esp+70h] [ebp-184h]
  std::wstring section; // [esp+74h] [ebp-180h] BYREF
  std::wstring key; // [esp+8Ch] [ebp-168h] BYREF
  std::wstring sus_type; // [esp+A4h] [ebp-150h] BYREF
  std::wstring v71; // [esp+BCh] [ebp-138h] BYREF
  std::wstring result; // [esp+D4h] [ebp-120h] BYREF
  std::wstring v73; // [esp+ECh] [ebp-108h] BYREF
  std::wstring v74; // [esp+104h] [ebp-F0h] BYREF
  INIReader ini; // [esp+11Ch] [ebp-D8h] BYREF
  INIReader fini; // [esp+164h] [ebp-90h] BYREF
  int v77; // [esp+1F0h] [ebp-4h]
  int savedregs; // [esp+1F4h] [ebp+0h] BYREF

  v6 = *(float *)&this;
  efpl = *(float *)&this;
  v7 = config;
  this->__vftable = (Car_vtbl *)&Car::`vftable';
  this->powerClassIndex = 0.0;
  v67 = this;
  this->evOnStepComplete.handlers._Myfirst = 0;
  this->evOnStepComplete.handlers._Mylast = 0;
  this->evOnStepComplete.handlers._Myend = 0;
  v77 = 0;
  this->evOnControlsProviderChanged.handlers._Myfirst = 0;
  this->evOnControlsProviderChanged.handlers._Mylast = 0;
  this->evOnControlsProviderChanged.handlers._Myend = 0;
  this->evOnLapCompleted.handlers._Myfirst = 0;
  this->evOnLapCompleted.handlers._Mylast = 0;
  this->evOnLapCompleted.handlers._Myend = 0;
  this->evOnSectorSplit.handlers._Myfirst = 0;
  this->evOnSectorSplit.handlers._Mylast = 0;
  this->evOnSectorSplit.handlers._Myend = 0;
  this->evOnForcedPositionCompleted.handlers._Myfirst = 0;
  this->evOnForcedPositionCompleted.handlers._Mylast = 0;
  this->evOnForcedPositionCompleted.handlers._Myend = 0;
  this->evOnTyreCompoundChanged.handlers._Myfirst = 0;
  this->evOnTyreCompoundChanged.handlers._Mylast = 0;
  this->evOnTyreCompoundChanged.handlers._Myend = 0;
  this->evOnCollisionEvent.handlers._Myfirst = 0;
  this->evOnCollisionEvent.handlers._Mylast = 0;
  this->evOnCollisionEvent.handlers._Myend = 0;
  this->evOnJumpStartEvent.handlers._Myfirst = 0;
  this->evOnJumpStartEvent.handlers._Mylast = 0;
  this->evOnJumpStartEvent.handlers._Myend = 0;
  this->evOnPush2Pass.handlers._Myfirst = 0;
  this->evOnPush2Pass.handlers._Mylast = 0;
  this->evOnPush2Pass.handlers._Myend = 0;
  this->carHalfWidth = 1.0;
  this->userFFGain = 1.0;
  this->isRetired = 0;
  v64 = &this->tyreCompounds;
  this->tyreCompounds._Myfirst = 0;
  this->tyreCompounds._Mylast = 0;
  this->tyreCompounds._Myend = 0;
  this->ksPhysics = iengine;
  this->rigidAxle = 0;
  *(_WORD *)&this->controls.kers = 0;
  this->controls.brakeBalanceDn = 0;
  this->controls.handBrake = 0.0;
  *(_DWORD *)&this->controls.absUp = 0;
  *(_DWORD *)&this->controls.turboUp = 0;
  *(_DWORD *)&this->controls.MGUKDeliveryUp = 0;
  this->controls.MGUHMode = 0;
  *(_WORD *)&this->controls.gearUp = 0;
  this->controls.gas = 0.0;
  this->controls.brake = 0.0;
  this->controls.clutch = 0.0;
  this->controls.steer = 0.0;
  this->controls.requestedGearIndex = -1;
  this->controls.isShifterSupported = 0;
  this->controls.drs = 0;
  this->unixName._Myres = 7;
  this->unixName._Mysize = 0;
  v65 = &this->unixName;
  this->unixName._Bx._Buf[0] = 0;
  v8 = &this->configName;
  v8->_Myres = 7;
  v8->_Mysize = 0;
  *(_DWORD *)&v60[32] = -1;
  *(_DWORD *)&v60[28] = 0;
  *(_DWORD *)&v60[24] = config;
  v8->_Bx._Buf[0] = 0;
  std::wstring::assign(v8, *(const std::wstring **)&v60[24], *(unsigned int *)&v60[28], *(unsigned int *)&v60[32]);
  *(_DWORD *)(LODWORD(v6) + 304) = 7;
  *(_DWORD *)(LODWORD(v6) + 300) = 0;
  *(_WORD *)(LODWORD(v6) + 284) = 0;
  *(_DWORD *)(LODWORD(v6) + 316) = 0;
  *(_DWORD *)(LODWORD(v6) + 320) = 0;
  *(_DWORD *)(LODWORD(v6) + 324) = 0;
  TimeTransponder::TimeTransponder((TimeTransponder *)(LODWORD(v6) + 328));
  CarColliderManager::CarColliderManager((CarColliderManager *)(LODWORD(v6) + 420));
  Drivetrain::Drivetrain((Drivetrain *)(LODWORD(v6) + 504));
  *(_WORD *)(LODWORD(v6) + 1728) = 0;
  *(_DWORD *)(LODWORD(v6) + 1732) = 0;
  *(_DWORD *)(LODWORD(v6) + 1736) = 0;
  *(_DWORD *)(LODWORD(v6) + 1740) = 4;
  *(_DWORD *)(LODWORD(v6) + 1744) = 0;
  *(_DWORD *)(LODWORD(v6) + 1748) = 0;
  Curve::Curve((Curve *)(LODWORD(v6) + 1752));
  *(_DWORD *)(LODWORD(v6) + 1828) = 0;
  *(_DWORD *)(LODWORD(v6) + 1832) = 1065353216;
  *(_WORD *)(LODWORD(v6) + 1836) = 0;
  *(_DWORD *)(LODWORD(v6) + 1840) = 0;
  *(_BYTE *)(LODWORD(v6) + 1844) = 0;
  *(_DWORD *)(LODWORD(v6) + 1848) = 0;
  *(_DWORD *)(LODWORD(v6) + 1852) = 0;
  *(_DWORD *)(LODWORD(v6) + 1856) = 0;
  *(_DWORD *)(LODWORD(v6) + 1860) = 0;
  *(_DWORD *)(LODWORD(v6) + 1864) = 0;
  *(_BYTE *)(LODWORD(v6) + 1868) = 0;
  Curve::Curve((Curve *)(LODWORD(v6) + 1872));
  *(_WORD *)(LODWORD(v6) + 1948) = 0;
  *(_DWORD *)(LODWORD(v6) + 1952) = 0;
  AeroMap::AeroMap((AeroMap *)(LODWORD(v6) + 1956));
  `eh vector constructor iterator'(
    (void *)(LODWORD(v6) + 2040),
    0x660u,
    4,
    (void (*)(void *))Tyre::Tyre,
    (void (*)(void *))Tyre::~Tyre);
  *(_DWORD *)(LODWORD(v6) + 8568) = 0;
  *(_DWORD *)(LODWORD(v6) + 8572) = 0;
  *(_DWORD *)(LODWORD(v6) + 8576) = 0;
  BrakeSystem::BrakeSystem((BrakeSystem *)(LODWORD(v6) + 8584));
  Autoclutch::Autoclutch((Autoclutch *)(LODWORD(v6) + 9232));
  Telemetry::Telemetry((Telemetry *)(LODWORD(v6) + 9496));
  *(_BYTE *)(LODWORD(v6) + 9720) = 0;
  Curve::Curve((Curve *)(LODWORD(v6) + 9728));
  *(_DWORD *)(LODWORD(v6) + 9848) = 0;
  *(_WORD *)(LODWORD(v6) + 9852) = 0;
  *(_DWORD *)(LODWORD(v6) + 9856) = 0;
  *(_DWORD *)(LODWORD(v6) + 9860) = 0;
  *(_WORD *)(LODWORD(v6) + 9864) = 0;
  *(_DWORD *)(LODWORD(v6) + 9868) = 0;
  *(_WORD *)(LODWORD(v6) + 9872) = 0;
  *(_WORD *)(LODWORD(v6) + 9876) = 0;
  *(_DWORD *)(LODWORD(v6) + 9880) = 0;
  *(_DWORD *)(LODWORD(v6) + 9884) = 0;
  *(_DWORD *)(LODWORD(v6) + 9888) = 0;
  *(_DWORD *)(LODWORD(v6) + 9892) = 0;
  *(_DWORD *)(LODWORD(v6) + 9896) = 0;
  *(_DWORD *)(LODWORD(v6) + 9900) = 0;
  *(_DWORD *)(LODWORD(v6) + 9904) = 0;
  *(_DWORD *)(LODWORD(v6) + 9908) = 0;
  *(_DWORD *)(LODWORD(v6) + 9912) = 0;
  *(_DWORD *)(LODWORD(v6) + 9916) = 0;
  *(_DWORD *)(LODWORD(v6) + 9920) = 0;
  *(_DWORD *)(LODWORD(v6) + 9924) = 1;
  `eh vector constructor iterator'(
    (void *)(LODWORD(v6) + 9928),
    0x24u,
    2,
    (void (*)(void *))AntirollBar::AntirollBar,
    (void (*)(void *))AntirollBar::~AntirollBar);
  *(_DWORD *)(LODWORD(v6) + 10000) = 0;
  *(_BYTE *)(LODWORD(v6) + 10004) = 0;
  *(_DWORD *)(LODWORD(v6) + 10008) = 0;
  *(_DWORD *)(LODWORD(v6) + 10012) = 0;
  *(_QWORD *)(LODWORD(v6) + 10016) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 10024) = 0;
  *(_DWORD *)(LODWORD(v6) + 10028) = 0;
  *(_OWORD *)(LODWORD(v6) + 10032) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 10064) = 0;
  *(_OWORD *)(LODWORD(v6) + 10048) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 10068) = 0;
  *(_WORD *)(LODWORD(v6) + 10072) = 0;
  *(_BYTE *)(LODWORD(v6) + 10074) = 0;
  *(_BYTE *)(LODWORD(v6) + 10096) = 0;
  *(_DWORD *)(LODWORD(v6) + 10100) = 0;
  *(_DWORD *)(LODWORD(v6) + 10104) = 0;
  *(_DWORD *)(LODWORD(v6) + 10108) = 0;
  *(_DWORD *)(LODWORD(v6) + 10112) = 0;
  *(_DWORD *)(LODWORD(v6) + 10116) = 0;
  *(_DWORD *)(LODWORD(v6) + 10120) = 0;
  *(_DWORD *)(LODWORD(v6) + 10124) = 0;
  *(_QWORD *)(LODWORD(v6) + 10128) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 10136) = 0;
  *(_OWORD *)(LODWORD(v6) + 10144) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 10168) = 0;
  *(_QWORD *)(LODWORD(v6) + 10160) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 10176) = 0;
  *(_DWORD *)(LODWORD(v6) + 10180) = 0;
  *(_DWORD *)(LODWORD(v6) + 10184) = 0;
  *(_BYTE *)(LODWORD(v6) + 10188) = 0;
  *(_DWORD *)(LODWORD(v6) + 10192) = 0;
  *(_DWORD *)(LODWORD(v6) + 10196) = 0;
  *(_DWORD *)(LODWORD(v6) + 10200) = 0;
  *(_DWORD *)(LODWORD(v6) + 10204) = 0;
  *(_DWORD *)(LODWORD(v6) + 10208) = -1082130432;
  *(_DWORD *)(LODWORD(v6) + 10212) = 1065353216;
  *(_DWORD *)(LODWORD(v6) + 10216) = 1065353216;
  *(_DWORD *)(LODWORD(v6) + 10220) = 1;
  *(_DWORD *)(LODWORD(v6) + 10244) = 7;
  *(_DWORD *)(LODWORD(v6) + 10240) = 0;
  *(_WORD *)(LODWORD(v6) + 10224) = 0;
  *(_DWORD *)(LODWORD(v6) + 10248) = 0x10000;
  *(_DWORD *)(LODWORD(v6) + 10252) = 0;
  *(_DWORD *)(LODWORD(v6) + 10256) = 0;
  *(_DWORD *)(LODWORD(v6) + 10260) = 0;
  *(_DWORD *)(LODWORD(v6) + 10264) = 0;
  *(_BYTE *)(LODWORD(v6) + 10268) = 0;
  *(_DWORD *)(LODWORD(v6) + 10272) = 0;
  Kers::Kers((Kers *)(LODWORD(v6) + 10276));
  ERS::ERS((ERS *)(LODWORD(v6) + 10432));
  *(double *)(LODWORD(v6) + 10864) = DOUBLE_5000_0;
  *(_DWORD *)(LODWORD(v6) + 10872) = 0;
  *(_DWORD *)(LODWORD(v6) + 10876) = -1;
  *(_BYTE *)(LODWORD(v6) + 10880) = 0;
  *(_DWORD *)(LODWORD(v6) + 10884) = 0;
  *(_DWORD *)(LODWORD(v6) + 10888) = 0;
  *(_DWORD *)(LODWORD(v6) + 10892) = 0;
  *(_DWORD *)(LODWORD(v6) + 10896) = 0;
  *(_DWORD *)(LODWORD(v6) + 10900) = 0;
  *(_DWORD *)(LODWORD(v6) + 10904) = 0;
  *(_DWORD *)(LODWORD(v6) + 10908) = 0;
  *(_DWORD *)(LODWORD(v6) + 10912) = 0;
  *(_DWORD *)(LODWORD(v6) + 10916) = 0;
  *(_DWORD *)(LODWORD(v6) + 10920) = 0;
  *(_DWORD *)(LODWORD(v6) + 10924) = 0;
  *(_DWORD *)(LODWORD(v6) + 10928) = 0;
  *(_QWORD *)(LODWORD(v6) + 10936) = 0i64;
  mat44f::mat44f((mat44f *)(LODWORD(v6) + 10944));
  *(_DWORD *)(LODWORD(v6) + 11008) = 0;
  *(_DWORD *)(LODWORD(v6) + 11012) = 0;
  *(_DWORD *)(LODWORD(v6) + 11016) = 0;
  *(_DWORD *)(LODWORD(v6) + 11020) = 0;
  *(_DWORD *)(LODWORD(v6) + 11040) = 0;
  *(_BYTE *)(LODWORD(v6) + 11044) = 0;
  *(_DWORD *)(LODWORD(v6) + 11048) = 0;
  *(_DWORD *)(LODWORD(v6) + 11052) = 0;
  *(_OWORD *)(LODWORD(v6) + 11056) = 0i64;
  *(_BYTE *)(LODWORD(v6) + 11104) = 0;
  *(_OWORD *)(LODWORD(v6) + 11072) = 0i64;
  *(double *)(LODWORD(v6) + 11088) = DOUBLE_N100_0;
  *(_QWORD *)(LODWORD(v6) + 11096) = 0i64;
  `eh vector constructor iterator'(
    (void *)(LODWORD(v6) + 11112),
    0x4Cu,
    2,
    (void (*)(void *))HeaveSpring::HeaveSpring,
    (void (*)(void *))HeaveSpring::~HeaveSpring);
  *(_DWORD *)(LODWORD(v6) + 11268) = 0;
  *(_BYTE *)(LODWORD(v6) + 11272) = 0;
  DynamicController::DynamicController((DynamicController *)(LODWORD(v6) + 11276));
  *(_QWORD *)(LODWORD(v6) + 11296) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 11304) = 0;
  *(_DWORD *)(LODWORD(v6) + 11308) = 0;
  *(_DWORD *)(LODWORD(v6) + 11312) = 1065353216;
  *(_DWORD *)(LODWORD(v6) + 11316) = 0;
  *(_DWORD *)(LODWORD(v6) + 11324) = 0;
  ThermalObject::ThermalObject((ThermalObject *)(LODWORD(v6) + 11328));
  *(_BYTE *)(LODWORD(v6) + 11360) = 0;
  *(_DWORD *)(LODWORD(v6) + 11364) = -1;
  *(_BYTE *)(LODWORD(v6) + 11368) = 0;
  *(_DWORD *)(LODWORD(v6) + 11372) = 0;
  *(_DWORD *)(LODWORD(v6) + 11376) = 0;
  *(_DWORD *)(LODWORD(v6) + 11380) = 0;
  *(_DWORD *)(LODWORD(v6) + 11384) = 0;
  *(_DWORD *)(LODWORD(v6) + 11388) = 0;
  *(_DWORD *)(LODWORD(v6) + 11392) = 0;
  *(_DWORD *)(LODWORD(v6) + 11396) = 1082130432;
  *(_DWORD *)(LODWORD(v6) + 11400) = 0x40000000;
  *(_DWORD *)(LODWORD(v6) + 11404) = 0x40000000;
  *(_DWORD *)(LODWORD(v6) + 11408) = 0x40000000;
  Triangle::Triangle((Triangle *)(LODWORD(v6) + 11412));
  *(_DWORD *)(LODWORD(v6) + 11468) = 1065353216;
  *(_DWORD *)(LODWORD(v6) + 11472) = 1065353216;
  *(_DWORD *)(LODWORD(v6) + 11476) = 0;
  *(_DWORD *)(LODWORD(v6) + 11480) = 0;
  *(_DWORD *)(LODWORD(v6) + 11484) = 0;
  *(_DWORD *)(LODWORD(v6) + 11488) = 0;
  *(_DWORD *)(LODWORD(v6) + 11492) = 0;
  *(_DWORD *)(LODWORD(v6) + 11496) = 1048576000;
  *(_DWORD *)(LODWORD(v6) + 11500) = 0;
  *(_QWORD *)(LODWORD(v6) + 11512) = 0i64;
  *(_BYTE *)(LODWORD(v6) + 11520) = 0;
  *(_OWORD *)(LODWORD(v6) + 11528) = 0i64;
  *(_DWORD *)(LODWORD(v6) + 11544) = 0;
  mat44f::mat44f((mat44f *)(LODWORD(v6) + 11548));
  *(_DWORD *)(LODWORD(v6) + 11612) = 0;
  *(_DWORD *)(LODWORD(v6) + 11616) = 0;
  *(_DWORD *)(LODWORD(v6) + 11620) = 0;
  *(_DWORD *)(LODWORD(v6) + 11624) = 0;
  *(_DWORD *)(LODWORD(v6) + 11636) = 0;
  *(_DWORD *)(LODWORD(v6) + 11640) = 0;
  *(_DWORD *)(LODWORD(v6) + 11644) = 0;
  *(_DWORD *)(LODWORD(v6) + 11648) = 0;
  *(_DWORD *)(LODWORD(v6) + 11652) = 0;
  *(_DWORD *)(LODWORD(v6) + 11656) = 0;
  *(_DWORD *)(LODWORD(v6) + 11724) = 0;
  *(_DWORD *)(LODWORD(v6) + 11728) = 0;
  *(_DWORD *)(LODWORD(v6) + 11732) = 0;
  *(_DWORD *)(LODWORD(v6) + 11736) = 0;
  *(_DWORD *)(LODWORD(v6) + 11740) = 0;
  *(_DWORD *)(LODWORD(v6) + 11744) = 0;
  *(_DWORD *)(LODWORD(v6) + 11748) = 0;
  *(_DWORD *)(LODWORD(v6) + 11752) = 0;
  *(_DWORD *)(LODWORD(v6) + 11756) = 0;
  *(_DWORD *)(LODWORD(v6) + 11760) = 0;
  *(_DWORD *)(LODWORD(v6) + 11764) = 0;
  *(_DWORD *)(LODWORD(v6) + 11768) = 0;
  *(_DWORD *)(LODWORD(v6) + 11772) = 1065353216;
  *(_DWORD *)(LODWORD(v6) + 11776) = 50;
  *(_BYTE *)(LODWORD(v6) + 11780) = 0;
  *(_DWORD *)(LODWORD(v6) + 11784) = 0;
  *(_DWORD *)(LODWORD(v6) + 11788) = 0;
  *(_DWORD *)(LODWORD(v6) + 11792) = 0;
  *(_DWORD *)(LODWORD(v6) + 11796) = 0;
  *(_DWORD *)(LODWORD(v6) + 11800) = 0;
  *(_DWORD *)(LODWORD(v6) + 11804) = 0;
  *(_DWORD *)(LODWORD(v6) + 11808) = 0;
  *(_DWORD *)(LODWORD(v6) + 11812) = 0;
  *(_BYTE *)(LODWORD(v6) + 11816) = 0;
  *(_BYTE *)(LODWORD(v6) + 11820) = 0;
  *(_DWORD *)(LODWORD(v6) + 11824) = 1092616192;
  *(_DWORD *)(LODWORD(v6) + 11828) = 1036831949;
  *(_DWORD *)(LODWORD(v6) + 11832) = 0x40000000;
  *(_DWORD *)(LODWORD(v6) + 11836) = 0x40000000;
  *(_DWORD *)(LODWORD(v6) + 11840) = 0x40000000;
  *(_DWORD *)(LODWORD(v6) + 11844) = 0;
  *(_DWORD *)(LODWORD(v6) + 11848) = 0;
  *(_DWORD *)(LODWORD(v6) + 11852) = 0;
  LOBYTE(v77) = 45;
  *(_WORD *)(LODWORD(v6) + 11856) = 0;
  std::unique_ptr<AudioEvent>::unique_ptr<AudioEvent>((Speed *)(LODWORD(v6) + 11860));
  *(_DWORD *)(LODWORD(v6) + 11864) = 1060991140;
  *(_BYTE *)(LODWORD(v6) + 11868) = 0;
  v9 = config->_Myres < 8;
  LOBYTE(v77) = 46;
  if ( !v9 )
    v7 = (const std::wstring *)config->_Bx._Ptr;
  if ( iunixName->_Myres < 8 )
    v10 = iunixName;
  else
    v10 = (const std::wstring *)iunixName->_Bx._Ptr;
  _printf("Creating car: %S [%S]\n", v10->_Bx._Buf, v7->_Bx._Buf);
  *(_DWORD *)(LODWORD(v6) + 11500) = 0;
  *(_DWORD *)(LODWORD(v6) + 11024) = 0;
  *(_DWORD *)(LODWORD(v6) + 11028) = 0;
  *(_DWORD *)(LODWORD(v6) + 11032) = 0;
  *(_DWORD *)(LODWORD(v6) + 11036) = 0;
  v11 = *(_DWORD *)(LODWORD(v6) + 168);
  *(_QWORD *)(LODWORD(v6) + 11536) = 0i64;
  *(_QWORD *)(LODWORD(v6) + 10016) = 0i64;
  *(_WORD *)(LODWORD(v6) + 10932) = 0;
  *(_BYTE *)(LODWORD(v6) + 11504) = 0;
  *(double *)(LODWORD(v6) + 11696) = DOUBLE_N1_0e8;
  *(_DWORD *)(LODWORD(v6) + 9492) = (*(_DWORD *)(v11 + 8) - *(_DWORD *)(v11 + 4)) >> 2;
  *(_DWORD *)(LODWORD(v6) + 148) = 0;
  if ( (const std::wstring *)(LODWORD(v6) + 236) != iunixName )
    std::wstring::assign((std::wstring *)(LODWORD(v6) + 236), iunixName, 0, 0xFFFFFFFF);
  Car::initCarDataPath((Car *)LODWORD(v6));
  v12 = *(PhysicsEngine **)(LODWORD(v6) + 168);
  *(_DWORD *)(LODWORD(v6) + 11356) = 1065353216;
  *(double *)(LODWORD(v6) + 11664) = DOUBLE_30_0;
  *(double *)(LODWORD(v6) + 11680) = DOUBLE_30_0;
  *(_DWORD *)(LODWORD(v6) + 11688) = 1106247680;
  v13 = PhysicsEngine::getCore(v12);
  v14 = (int)v13->createRigidBody(v13);
  v15 = *(PhysicsEngine **)(LODWORD(v6) + 168);
  *(_DWORD *)(LODWORD(v6) + 152) = v14;
  v16 = PhysicsEngine::getCore(v15);
  *(_DWORD *)(LODWORD(v6) + 156) = v16->createRigidBody(v16);
  *(_DWORD *)(LODWORD(v6) + 312) = 994352038;
  *(_DWORD *)(LODWORD(v6) + 11632) = 0;
  *(_DWORD *)(LODWORD(v6) + 11320) = 0;
  *(_DWORD *)(LODWORD(v6) + 11612) = 0;
  *(_DWORD *)(LODWORD(v6) + 224) = 1128792064;
  *(_DWORD *)(LODWORD(v6) + 228) = 1094713344;
  Car::initCarData((Car *)LODWORD(v6));
  BrakeSystem::init((BrakeSystem *)(LODWORD(v6) + 8584), LODWORD(v6), (Car *)LODWORD(v6));
  v17 = std::operator+<wchar_t>(&result, (const std::wstring *)(LODWORD(v6) + 284), L"suspensions.ini");
  LOBYTE(v77) = 47;
  v18 = Car::getConfigPath((Car *)LODWORD(v6), &v74, v17);
  LOBYTE(v77) = 48;
  INIReader::INIReader(&ini, v18);
  if ( v74._Myres >= 8 )
    operator delete(v74._Bx._Ptr);
  v74._Myres = 7;
  v74._Mysize = 0;
  v74._Bx._Buf[0] = 0;
  LOBYTE(v77) = 51;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TYPE", 4u);
  LOBYTE(v77) = 52;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v77) = 53;
  v19 = INIReader::getString(&ini, &v71, &section, &key);
  *(_DWORD *)&v60[32] = 4;
  *(_DWORD *)&v60[28] = L"AXLE";
  *(_DWORD *)&v60[24] = v19->_Mysize;
  LOBYTE(v77) = 54;
  v62 = std::wstring::compare(v19, 0, *(unsigned int *)&v60[24], L"AXLE", 4u) == 0;
  if ( v71._Myres >= 8 )
    operator delete(v71._Bx._Ptr);
  v71._Myres = 7;
  v71._Mysize = 0;
  v71._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v77) = 51;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v62 )
  {
    _printf("Creating rigid axle body\n");
    v20 = PhysicsEngine::getCore(*(PhysicsEngine **)(LODWORD(v6) + 168));
    *(_DWORD *)(LODWORD(v6) + 160) = v20->createRigidBody(v20);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"TORQUE_REACTION", 0xFu);
    LOBYTE(v77) = 55;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AXLE", 4u);
    LOBYTE(v77) = 56;
    v21 = INIReader::getFloat(&ini, &section, &key);
    v9 = section._Myres < 8;
    *(float *)(LODWORD(v6) + 11312) = v21;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  for ( i = 0; i < 4; ++i )
  {
    sus_type._Myres = 7;
    sus_type._Mysize = 0;
    sus_type._Bx._Buf[0] = 0;
    LOBYTE(v77) = 57;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"TYPE", 4u);
    if ( i >= 2 )
    {
      LOBYTE(v77) = 60;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"REAR", 4u);
      LOBYTE(v77) = 61;
      v24 = INIReader::getString(&ini, &v71, &section, &key);
      if ( &sus_type != v24 )
      {
        if ( sus_type._Myres >= 8 )
          operator delete(sus_type._Bx._Ptr);
        sus_type._Myres = 7;
        sus_type._Mysize = 0;
        sus_type._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&sus_type, v24);
      }
    }
    else
    {
      LOBYTE(v77) = 58;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"FRONT", 5u);
      LOBYTE(v77) = 59;
      v23 = INIReader::getString(&ini, &v71, &section, &key);
      if ( &sus_type != v23 )
      {
        if ( sus_type._Myres >= 8 )
          operator delete(sus_type._Bx._Ptr);
        sus_type._Myres = 7;
        sus_type._Mysize = 0;
        sus_type._Bx._Buf[0] = 0;
        if ( v23->_Myres >= 8 )
        {
          sus_type._Bx._Ptr = v23->_Bx._Ptr;
          v23->_Bx._Ptr = 0;
        }
        else if ( v23->_Mysize != -1 )
        {
          _memmove(&sus_type, v23, 2 * (v23->_Mysize + 1));
        }
        sus_type._Mysize = v23->_Mysize;
        sus_type._Myres = v23->_Myres;
        v23->_Myres = 7;
        v23->_Mysize = 0;
        v23->_Bx._Buf[0] = 0;
      }
    }
    if ( v71._Myres >= 8 )
      operator delete(v71._Bx._Ptr);
    v71._Myres = 7;
    v71._Bx._Buf[0] = 0;
    v71._Mysize = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v77) = 57;
    section._Bx._Buf[0] = 0;
    section._Mysize = 0;
    section._Myres = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    *(float *)&v25 = 0.0;
    *(float *)&crsus = 0.0;
    if ( !std::wstring::compare(&sus_type, 0, sus_type._Mysize, L"STRUT", 5u) )
    {
      *(float *)&v26 = COERCE_FLOAT(operator new(424));
      crsus = v26;
      LOBYTE(v77) = 62;
      if ( *(float *)&v26 == 0.0 )
      {
        *(float *)&v25 = 0.0;
      }
      else
      {
        SuspensionStrut::SuspensionStrut(v26, SLODWORD(v6), (int)&savedregs, i, (Car *)LODWORD(v6), i);
        v25 = v27;
      }
      LOBYTE(v77) = 57;
      if ( i >= 2 )
        *(_DWORD *)(LODWORD(v6) + 11308) = 1;
      else
        *(_DWORD *)(LODWORD(v6) + 11304) = 1;
      crsus = v25;
    }
    if ( !std::wstring::compare(&sus_type, 0, sus_type._Mysize, L"DWB", 3u) )
    {
      *(float *)&v28 = COERCE_FLOAT(operator new(464));
      crsus = v28;
      LOBYTE(v77) = 63;
      if ( *(float *)&v28 == 0.0 )
      {
        *(float *)&v25 = 0.0;
      }
      else
      {
        Suspension::Suspension(v28, SLODWORD(v6), (int)&savedregs, (Car *)LODWORD(v6), i);
        v25 = v29;
      }
      LOBYTE(v77) = 57;
      if ( i >= 2 )
        *(_DWORD *)(LODWORD(v6) + 11308) = 0;
      else
        *(_DWORD *)(LODWORD(v6) + 11304) = 0;
      crsus = v25;
    }
    if ( !std::wstring::compare(&sus_type, 0, sus_type._Mysize, L"ML", 2u) )
    {
      *(float *)&v30 = COERCE_FLOAT(operator new(164));
      crsus = v30;
      LOBYTE(v77) = 64;
      if ( *(float *)&v30 == 0.0 )
      {
        *(float *)&v25 = 0.0;
      }
      else
      {
        SuspensionML::SuspensionML(v30, (Car *)LODWORD(v6), i);
        v25 = v31;
      }
      LOBYTE(v77) = 57;
      if ( i >= 2 )
        *(_DWORD *)(LODWORD(v6) + 11308) = 3;
      else
        *(_DWORD *)(LODWORD(v6) + 11304) = 3;
      crsus = v25;
    }
    if ( !std::wstring::compare(&sus_type, 0, sus_type._Mysize, L"AXLE", 4u) && i >= 2 )
    {
      *(_DWORD *)(LODWORD(v6) + 11308) = 2;
      *(_DWORD *)&v60[32] = 140;
      if ( i == 2 )
      {
        *(float *)&v32 = COERCE_FLOAT(operator new(*(_DWORD *)&v60[32]));
        crsus = v32;
        LOBYTE(v77) = 65;
        if ( *(float *)&v32 != 0.0 )
        {
          SuspensionAxle::SuspensionAxle(v32, (Car *)LODWORD(v6), Left, (const std::wstring *)(LODWORD(v6) + 284));
          v25 = v33;
LABEL_75:
          LOBYTE(v77) = 57;
          crsus = v25;
          goto LABEL_76;
        }
      }
      else
      {
        *(float *)&v34 = COERCE_FLOAT(operator new(*(_DWORD *)&v60[32]));
        crsus = v34;
        LOBYTE(v77) = 66;
        if ( *(float *)&v34 != 0.0 )
        {
          SuspensionAxle::SuspensionAxle(v34, (Car *)LODWORD(v6), Middle, (const std::wstring *)(LODWORD(v6) + 284));
          v25 = v35;
          goto LABEL_75;
        }
      }
      *(float *)&v25 = 0.0;
      goto LABEL_75;
    }
LABEL_76:
    if ( *(float *)&v25 == 0.0 )
    {
      v59 = &sus_type;
      *(_DWORD *)&v60[32] = i;
      if ( sus_type._Myres >= 8 )
        v59 = (std::wstring *)sus_type._Bx._Ptr;
      _printf("ERROR: Cannot create suspension type: %S  for wheel:%d\n", v59->_Bx._Buf, *(_DWORD *)&v60[32]);
      _exit(1);
    }
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)(LODWORD(v6) + 8568),
      (ICollisionObject *const *)&crsus);
    *(float *)&v60[32] = v6;
    *(_DWORD *)&v60[28] = *(_DWORD *)(LODWORD(v6) + 9492);
    *(_DWORD *)&v60[24] = i;
    *(_QWORD *)&v60[16] = 0x700000000i64;
    *(_WORD *)v60 = 0;
    std::wstring::assign((std::wstring *)v60, (const std::wstring *)(LODWORD(v6) + 284), 0, 0xFFFFFFFF);
    Tyre::init(
      (Tyre *)(1632 * i + LODWORD(v6) + 2040),
      *(ISuspension **)(*(_DWORD *)(LODWORD(v6) + 8568) + 4 * i),
      *(IRayTrackCollisionProvider **)(*(_DWORD *)(LODWORD(v6) + 168) + 308),
      *(std::wstring *)v60,
      *(int *)&v60[24],
      *(int *)&v60[28],
      *(Car **)&v60[32]);
    if ( !std::wstring::compare(&sus_type, 0, sus_type._Mysize, L"AXLE", 4u) && i == 2 )
    {
      v36 = (SuspensionAxle *)__RTDynamicCast(
                                crsus,
                                0,
                                &ISuspension `RTTI Type Descriptor',
                                &SuspensionAxle `RTTI Type Descriptor',
                                0);
      SuspensionAxle::printRollCenter(v36, *(float *)(LODWORD(v6) + 5320));
    }
    LOBYTE(v77) = 51;
    if ( sus_type._Myres >= 8 )
      operator delete(sus_type._Bx._Ptr);
  }
  v37 = *(_DWORD **)(LODWORD(v6) + 7960);
  v38 = (_DWORD *)(LODWORD(v6) + 7944);
  if ( v37 )
  {
    (*(void (__stdcall **)(bool))(*v37 + 16))(v37 != v38);
    *(_DWORD *)(LODWORD(v6) + 7960) = 0;
  }
  *v38 = &std::_Func_impl<std::_Callable_obj<_lambda_98ef5105ea1ca57f0a44e8ebc6e062bd_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  *(float *)(LODWORD(v6) + 7948) = v6;
  *(_DWORD *)(LODWORD(v6) + 7960) = LODWORD(v6) + 7944;
  v39 = (*(_DWORD *)(LODWORD(v6) + 4668) - *(_DWORD *)(LODWORD(v6) + 4664)) / 712;
  if ( (*(_DWORD *)(LODWORD(v6) + 3036) - *(_DWORD *)(LODWORD(v6) + 3032)) / 712 == v39
    && (v39 = (*(_DWORD *)(LODWORD(v6) + 6300) - *(_DWORD *)(LODWORD(v6) + 6296)) / 712,
        (*(_DWORD *)(LODWORD(v6) + 3036) - *(_DWORD *)(LODWORD(v6) + 3032)) / 712 == v39)
    && (v39 = (*(_DWORD *)(LODWORD(v6) + 3036) - *(_DWORD *)(LODWORD(v6) + 3032)) / 712,
        v39 == (*(_DWORD *)(LODWORD(v6) + 7932) - *(_DWORD *)(LODWORD(v6) + 7928)) / 712) )
  {
    v40 = *(_DWORD *)(LODWORD(v6) + 3036);
    v39 = *(_DWORD *)(LODWORD(v6) + 3032);
    if ( v39 != v40 )
    {
      v41 = (const std::wstring *)(v39 + 4);
      do
      {
        std::vector<std::wstring>::push_back(v64, v41);
        if ( v41->_Myres < 8 )
          v42 = (const wchar_t *)v41;
        else
          v42 = v41->_Bx._Ptr;
        _printf("TYRE COMPOUND: %S\n", v42);
        v39 += 712;
        v41 = (const std::wstring *)((char *)v41 + 712);
      }
      while ( v39 != v40 );
      v6 = efpl;
    }
    v43 = (void (*)(const char *const, ...))_printf;
  }
  else
  {
    v43 = (void (*)(const char *const, ...))_printf;
    _printf("ERROR: Tyre compound count does not match!\n");
  }
  Car::initHeaveSprings((Car *)LODWORD(v6));
  v44 = (*(int (**)(_DWORD, std::wstring *))(***(_DWORD ***)(LODWORD(v6) + 8568) + 40))(
          **(_DWORD **)(LODWORD(v6) + 8568),
          &section);
  *(_DWORD *)&v60[32] = &section;
  *(_DWORD *)(LODWORD(v6) + 11732) = *(_DWORD *)(v44 + 8);
  *(_DWORD *)(LODWORD(v6) + 11744) = *(_DWORD *)((*(int (**)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(LODWORD(v6) + 8568) + 8)
                                                                                       + 40))(
                                                   *(_DWORD *)(*(_DWORD *)(LODWORD(v6) + 8568) + 8),
                                                   *(_DWORD *)&v60[32])
                                               + 8);
  Car::initAeroMap((Car *)LODWORD(v6));
  ERS::init((ERS *)(LODWORD(v6) + 10432), (Car *)LODWORD(v6));
  if ( !*(_BYTE *)(LODWORD(v6) + 10440) )
    Kers::init((Kers *)(LODWORD(v6) + 10276), (Car *)LODWORD(v6));
  SteeringSystem::init((SteeringSystem *)(LODWORD(v6) + 11264), LODWORD(v6), (Car *)LODWORD(v6));
  v45 = *(_DWORD *)(LODWORD(v6) + 232);
  *(float *)&v60[32] = v6;
  *(_DWORD *)(LODWORD(v6) + 11264) = v45;
  Drivetrain::init((Drivetrain *)(LODWORD(v6) + 504), *(Car **)&v60[32]);
  v46 = *(_BYTE *)(LODWORD(v6) + 1400);
  *(float *)&v60[32] = v6;
  *(_BYTE *)(LODWORD(v6) + 184) = v46;
  Autoclutch::init((Autoclutch *)(LODWORD(v6) + 9232), *(Car **)&v60[32]);
  AutoBlip::init((AutoBlip *)(LODWORD(v6) + 9720), (Car *)LODWORD(v6));
  AutoShifter::init((AutoShifter *)(LODWORD(v6) + 9832), (Car *)LODWORD(v6));
  GearChanger::init((GearChanger *)(LODWORD(v6) + 9864), (Car *)LODWORD(v6));
  EDL::init((EDL *)(LODWORD(v6) + 9876), (Car *)LODWORD(v6));
  Car::buildARBS((Car *)LODWORD(v6), LODWORD(v6));
  ABS::init((ABS *)(LODWORD(v6) + 1728), (Car *)LODWORD(v6));
  TractionControl::init((TractionControl *)(LODWORD(v6) + 1836), (Car *)LODWORD(v6));
  SpeedLimiter::init((SpeedLimiter *)(LODWORD(v6) + 1948), (Car *)LODWORD(v6));
  v47 = *(_DWORD *)(LODWORD(v6) + 168);
  *(_DWORD *)&v60[32] = &efpl;
  *(_DWORD *)(LODWORD(v6) + 11628) = 0;
  efpl = v6;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)(v47 + 4),
    *(ICollisionObject *const **)&v60[32]);
  Car::updateBodyMass((Car *)LODWORD(v6), v39);
  CarColliderManager::init((CarColliderManager *)(LODWORD(v6) + 420), (Car *)LODWORD(v6));
  SetupManager::init((SetupManager *)(LODWORD(v6) + 10176), (Car *)LODWORD(v6));
  if ( !*(_DWORD *)(LODWORD(v6) + 9492) )
    Telemetry::init((Telemetry *)(LODWORD(v6) + 9496), (Car *)LODWORD(v6));
  SplineLocator::init((SplineLocator *)(LODWORD(v6) + 11792), (Car *)LODWORD(v6));
  StabilityControl::init((StabilityControl *)(LODWORD(v6) + 10000), (Car *)LODWORD(v6));
  DriftModeComponent::init((DriftModeComponent *)(LODWORD(v6) + 10024), (Car *)LODWORD(v6));
  PerformanceMeter::init((PerformanceMeter *)(LODWORD(v6) + 10096), (Car *)LODWORD(v6));
  LapInvalidator::init((LapInvalidator *)(LODWORD(v6) + 10864), (Car *)LODWORD(v6));
  PenaltyManager::init((PenaltyManager *)(LODWORD(v6) + 10888), (Car *)LODWORD(v6));
  *(float *)&v60[32] = v6;
  *(_DWORD *)(LODWORD(v6) + 11704) = 0;
  *(_DWORD *)(LODWORD(v6) + 11708) = 0;
  *(_DWORD *)(LODWORD(v6) + 11712) = 0;
  *(_DWORD *)(LODWORD(v6) + 11716) = 0;
  *(_DWORD *)(LODWORD(v6) + 11720) = 0;
  TimeTransponder::init((TimeTransponder *)(LODWORD(v6) + 328), *(Car **)&v60[32]);
  SlipStream::init((SlipStream *)(LODWORD(v6) + 11412), *(PhysicsEngine **)(LODWORD(v6) + 168));
  FuelLapEvaluator::init((FuelLapEvaluator *)(LODWORD(v6) + 11048), (Car *)LODWORD(v6));
  *(float *)&v60[32] = v6;
  *(_DWORD *)&v60[8] = &std::_Func_impl<std::_Callable_obj<_lambda_4cec3139fbe4904c3edc6b11bdde67b4_,0>,std::allocator<std::_Func_class<void,SessionInfo const &>>,void,SessionInfo const &>::`vftable';
  *(float *)&v60[12] = v6;
  *(_DWORD *)&v60[24] = &v60[8];
  v48 = (Event<SessionInfo> *)(*(_DWORD *)(LODWORD(v6) + 168) + 84);
  LOBYTE(v77) = 51;
  Event<float>::addHandler(v48, *(std::function<void __cdecl(SessionInfo const &)> *)&v60[8], (void *)LODWORD(v6));
  *(float *)&v60[32] = v6;
  *(_DWORD *)&v60[8] = &std::_Func_impl<std::_Callable_obj<_lambda_88fc3e94da5f4b0c80945ac999a9b9a8_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(float *)&v60[12] = v6;
  *(_DWORD *)&v60[24] = &v60[8];
  v49 = (Event<SessionInfo> *)(*(_DWORD *)(LODWORD(v6) + 168) + 60);
  LOBYTE(v77) = 51;
  Event<float>::addHandler(v49, *(std::function<void __cdecl(SessionInfo const &)> *)&v60[8], (void *)LODWORD(v6));
  v50 = std::operator+<wchar_t>(&v73, L"content/cars/", (const std::wstring *)(LODWORD(v6) + 236));
  LOBYTE(v77) = 69;
  v51 = std::operator+<wchar_t>(&v71, v50, L"/data/fuel_cons.ini");
  LOBYTE(v77) = 70;
  INIReader::INIReader(&fini, v51);
  if ( v71._Myres >= 8 )
    operator delete(v71._Bx._Ptr);
  v71._Myres = 7;
  v71._Mysize = 0;
  v71._Bx._Buf[0] = 0;
  LOBYTE(v77) = 73;
  if ( v73._Myres >= 8 )
    operator delete(v73._Bx._Ptr);
  v73._Myres = 7;
  v73._Mysize = 0;
  v73._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"FUEL_EVAL", 9u);
  LOBYTE(v77) = 74;
  v52 = INIReader::hasSection(&fini, &key);
  v62 = v52;
  LOBYTE(v77) = 73;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v52 = v62;
  }
  if ( v52 )
  {
    v53 = AISplineRecorder::getBestLapSpline(*(AISplineRecorder **)(*(_DWORD *)(*(_DWORD *)(LODWORD(v6) + 168) + 308)
                                                                  + 96));
    if ( v53 )
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"KM_PER_LITER", 0xCu);
      LOBYTE(v77) = 75;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"FUEL_EVAL", 9u);
      LOBYTE(v77) = 76;
      efpl = 1.0 / (INIReader::getFloat(&fini, &section, &key) * 1000.0);
      v54 = Spline::length(&v53->spline);
      v9 = section._Myres < 8;
      *(float *)(LODWORD(v6) + 11544) = v54 * efpl;
      if ( !v9 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v77) = 73;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  RaceEngineer::RaceEngineer(&eng, (Car *)LODWORD(v6));
  v55 = *(float *)(LODWORD(v6) + 11544);
  LOBYTE(v77) = 77;
  if ( v55 == 0.0 )
  {
    *(float *)(LODWORD(v6) + 11544) = RaceEngineer::evaluateFuelPerLapFromTrackSpline(&eng, LODWORD(v6), a2, a3);
  }
  else
  {
    efpl = RaceEngineer::evaluateFuelPerLapFromTrackSpline(&eng, LODWORD(v6), a2, a3);
    v43("Using fuel per lap %f instead of eng calculated: %f\n", *(float *)(LODWORD(v6) + 11544), efpl);
  }
  efpl = RaceEngineer::getFrontTrack(&eng);
  *(float *)&v64 = RaceEngineer::getRearTrack(&eng);
  if ( efpl <= *(float *)&v64 )
    v56 = RaceEngineer::getRearTrack(&eng);
  else
    v56 = RaceEngineer::getFrontTrack(&eng);
  *(float *)&crsus = v56;
  v60[32] = 1;
  *(float *)(LODWORD(v6) + 124) = (float)(*(float *)&crsus * 0.5) + 0.30000001;
  efpl = 1.0 / Car::getTotalMass((Car *)LODWORD(v6), v60[32]);
  v57 = Engine::getMaxPowerW((Engine *)(LODWORD(v6) + 720));
  *(float *)(LODWORD(v6) + 12) = v57 * efpl;
  if ( *(_DWORD *)(LODWORD(v6) + 256) >= 8u )
    v65 = *(std::wstring **)(LODWORD(v6) + 236);
  *(double *)&v60[28] = Car::getTotalMass((Car *)LODWORD(v6), 1);
  efpl = Engine::getMaxPowerW((Engine *)(LODWORD(v6) + 720));
  *(double *)&v60[20] = (float)(efpl * 0.00134102);
  v58 = Engine::getMaxPowerW((Engine *)(LODWORD(v6) + 720));
  v43(
    "POWER CLASS INDEX: %f (%S) PW:%f (%f HP) W:%f\n",
    *(float *)(LODWORD(v6) + 12),
    v65->_Bx._Buf,
    v58,
    *(double *)&v60[20],
    *(double *)&v60[28]);
  *(_BYTE *)(LODWORD(v6) + 11868) = 0;
  LOBYTE(v77) = 73;
  RaceEngineer::~RaceEngineer(&eng);
  LOBYTE(v77) = 51;
  INIReader::~INIReader(&fini);
  LOBYTE(v77) = 46;
  INIReader::~INIReader(&ini);
}
void Car::~Car(Car *this)
{
  double v2; // xmm0_8
  PhysicsEngine *v3; // eax
  long double v4; // xmm0_8
  AISplineRecorder *v5; // ecx
  AISpline *v6; // eax
  double v7; // xmm0_8
  long double v8; // st7
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  ICarControlsProvider *v11; // ecx
  ISuspension **v12; // esi
  int v13; // ebx
  unsigned int v14; // ecx
  float v15; // eax
  IRigidBody *v16; // ecx
  IRigidBody *v17; // ecx
  int v18; // eax
  _BYTE *v19; // ebx
  bool v20; // zf
  std::vector<ISuspension *> *v21; // ebx
  std::vector<std::wstring> *v22; // ebx
  float v23; // eax
  wchar_t **v24; // esi
  Event<std::pair<int,int> > *v25; // esi
  float v26; // eax
  std::pair<void *,std::function<void __cdecl(std::pair<int,int> const &)> > *v27; // ebx
  std::_Func_base<void,std::pair<int,int> const &> **v28; // esi
  Event<double> *v29; // esi
  float v30; // eax
  std::pair<void *,std::function<void __cdecl(double const &)> > *v31; // ebx
  std::_Func_base<void,double const &> **v32; // esi
  Event<OnCollisionEvent> *v33; // esi
  float v34; // eax
  std::pair<void *,std::function<void __cdecl(OnCollisionEvent const &)> > *v35; // ebx
  std::_Func_base<void,OnCollisionEvent const &> **v36; // esi
  Event<std::pair<int,int> > *v37; // esi
  float v38; // eax
  std::pair<void *,std::function<void __cdecl(std::pair<int,int> const &)> > *v39; // ebx
  std::_Func_base<void,std::pair<int,int> const &> **v40; // esi
  Event<vec3f> *v41; // esi
  float v42; // eax
  std::pair<void *,std::function<void __cdecl(vec3f const &)> > *v43; // ebx
  std::_Func_base<void,vec3f const &> **v44; // esi
  Event<OnSectorSplitEvent> *v45; // esi
  float v46; // eax
  std::pair<void *,std::function<void __cdecl(OnSectorSplitEvent const &)> > *v47; // ebx
  std::_Func_base<void,OnSectorSplitEvent const &> **v48; // esi
  std::wstring v49; // [esp+10h] [ebp-DCh] BYREF
  float l; // [esp+54h] [ebp-98h]
  float v51; // [esp+58h] [ebp-94h]
  Car *v52; // [esp+5Ch] [ebp-90h]
  std::wstring filename; // [esp+60h] [ebp-8Ch] BYREF
  std::wstring docs; // [esp+78h] [ebp-74h] BYREF
  std::wstring result; // [esp+90h] [ebp-5Ch] BYREF
  int v56; // [esp+E8h] [ebp-4h]

  v52 = this;
  this->__vftable = (Car_vtbl *)&Car::`vftable';
  v2 = this->fuelLapEvaluator.totalM;
  v3 = this->ksPhysics;
  v56 = 46;
  v4 = v2 * 0.001 / this->fuelLapEvaluator.totalLiters;
  v5 = v3->track->aiSplineRecorder._Myptr;
  v51 = (float)v4 * 1000.0;
  v6 = AISplineRecorder::getBestLapSpline(v5);
  if ( v6 )
  {
    l = Spline::length(&v6->spline);
    v7 = l;
    l = l / v51;
    *(double *)&v49._Mysize = v7;
    *(double *)&v49._Bx._Alias[8] = this->expectedFuelPerLap;
    v8 = FuelLapEvaluator::getFuelPerLap(&this->fuelLapEvaluator);
    _printf(
      "km_per_liter: %f lap_eval: %f  , evaluator: %f (guess: %f), length:%f\n",
      (float)(v51 * 0.001),
      l,
      (double)v8,
      *(double *)&v49._Bx._Alias[8],
      v7);
  }
  v9 = &this->unixName;
  if ( this->unixName._Myres >= 8 )
    v9 = (std::wstring *)v9->_Bx._Ptr;
  _printf("PCI: %S = %.1f\n", v9->_Bx._Buf, this->powerClassIndex);
  this->fuelTankJoint->release(this->fuelTankJoint);
  if ( !this->physicsGUID )
  {
    Path::getDocumentPath(&docs);
    LOBYTE(v56) = 47;
    v10 = std::operator+<wchar_t>(&result, &docs, L"/Assetto Corsa/aim");
    LOBYTE(v56) = 48;
    Path::createFolder(v10);
    LOBYTE(v56) = 47;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::operator+<wchar_t>(&filename, &docs, L"/Assetto Corsa/aim/telemetry_dump.act");
    LOBYTE(v56) = 49;
    v49._Myres = 7;
    v49._Mysize = 0;
    v49._Bx._Buf[0] = 0;
    std::wstring::assign(&v49, &filename, 0, 0xFFFFFFFF);
    Telemetry::save(&this->telemetry, v49);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    LOBYTE(v56) = 46;
    if ( docs._Myres >= 8 )
      operator delete(docs._Bx._Ptr);
  }
  PhysicsEngine::removeCar(this->ksPhysics, this);
  if ( this->externalControl )
  {
    v11 = this->controlsProvider;
    if ( v11 )
      ((void (*)(ICarControlsProvider *, int))v11->~ICarControlsProvider)(v11, 1);
  }
  v12 = this->suspensions._Myfirst;
  v13 = 0;
  v14 = (unsigned int)((char *)this->suspensions._Mylast - (char *)v12 + 3) >> 2;
  if ( v12 > this->suspensions._Mylast )
    *(float *)&v14 = 0.0;
  v51 = *(float *)&v14;
  if ( *(float *)&v14 != 0.0 )
  {
    v15 = *(float *)&v14;
    do
    {
      if ( *v12 )
      {
        ((void (*)(ISuspension *, int))(*v12)->~ISuspension)(*v12, 1);
        v15 = v51;
      }
      ++v13;
      ++v12;
    }
    while ( v13 != LODWORD(v15) );
  }
  v16 = this->rigidAxle;
  if ( v16 )
    v16->release(v16);
  v17 = this->body;
  if ( v17 )
    v17->release(v17);
  LOBYTE(v56) = 45;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->valueCache);
  LOBYTE(v56) = 44;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->splineLocator);
  LOBYTE(v56) = 43;
  SlipStream::~SlipStream(&this->slipStream);
  LOBYTE(v56) = 42;
  ThermalObject::~ThermalObject(&this->water);
  LOBYTE(v56) = 41;
  AntirollBar::~AntirollBar(&this->steeringSystem);
  LOBYTE(v56) = 40;
  `eh vector destructor iterator'(this->heaveSprings, 0x4Cu, 2, (void (*)(void *))HeaveSpring::~HeaveSpring);
  LOBYTE(v56) = 39;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->fuelLapEvaluator);
  LOBYTE(v56) = 38;
  PenaltyManager::~PenaltyManager(&this->penaltyManager);
  LOBYTE(v56) = 37;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->lapInvalidator);
  LOBYTE(v56) = 36;
  ERS::~ERS(&this->ers);
  LOBYTE(v56) = 35;
  Kers::~Kers(&this->kers);
  LOBYTE(v56) = 34;
  TimeEvaluation::~TimeEvaluation(&this->drs);
  if ( this->screenName._Myres >= 8 )
    operator delete(this->screenName._Bx._Ptr);
  this->screenName._Myres = 7;
  this->screenName._Mysize = 0;
  this->screenName._Bx._Buf[0] = 0;
  LOBYTE(v56) = 32;
  SetupManager::~SetupManager(&this->setupManager);
  LOBYTE(v56) = 31;
  PerformanceMeter::~PerformanceMeter(&this->performanceMeter);
  LOBYTE(v56) = 30;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->driftMode);
  LOBYTE(v56) = 29;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->stabilityControl);
  LOBYTE(v56) = 28;
  `eh vector destructor iterator'(this->antirollBars, 0x24u, 2, (void (*)(void *))AntirollBar::~AntirollBar);
  LOBYTE(v56) = 27;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->edl);
  LOBYTE(v56) = 26;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->gearChanger);
  LOBYTE(v56) = 25;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->autoShift);
  LOBYTE(v56) = 24;
  DynamicControllerStage::~DynamicControllerStage((DynamicControllerStage *)&this->autoBlip);
  LOBYTE(v56) = 23;
  Telemetry::~Telemetry(&this->telemetry);
  LOBYTE(v56) = 22;
  Autoclutch::~Autoclutch(&this->autoClutch);
  LODWORD(l) = &this->brakeSystem;
  LOBYTE(v56) = 52;
  DynamicController::~DynamicController(&this->brakeSystem.ebbController);
  v18 = *(_DWORD *)this->brakeSystem.tempRunFile.gap0;
  v19 = &this->brakeSystem.tempRunFile.gap58[8];
  LOBYTE(v56) = 51;
  *(_DWORD *)&v19[*(_DWORD *)(v18 + 4) - 96] = &std::ofstream::`vftable';
  *(_DWORD *)&v19[*(_DWORD *)(*(_DWORD *)this->brakeSystem.tempRunFile.gap0 + 4) - 100] = *(_DWORD *)(*(_DWORD *)this->brakeSystem.tempRunFile.gap0 + 4)
                                                                                        - 96;
  v20 = *(_DWORD *)&this->brakeSystem.tempRunFile._Filebuffer[4] == 0;
  *(_DWORD *)&this->brakeSystem.tempRunFile.gap0[4] = &std::filebuf::`vftable';
  if ( !v20 && **(Car ***)&this->brakeSystem.tempRunFile.gap0[16] == (Car *)&this->brakeSystem.tempRunFile.gap0[72] )
    std::streambuf::setg(
      &this->brakeSystem.tempRunFile.gap0[4],
      *(_DWORD *)&this->brakeSystem.tempRunFile.gap0[60],
      *(_DWORD *)&this->brakeSystem.tempRunFile.gap0[60],
      *(_DWORD *)&this->brakeSystem.tempRunFile.gap0[64]);
  if ( this->brakeSystem.tempRunFile._Filebuffer[0] )
  {
    if ( *(_DWORD *)&this->brakeSystem.tempRunFile._Filebuffer[4] )
    {
      std::filebuf::_Endwrite((std::filebuf *)&this->brakeSystem.tempRunFile.gap0[4]);
      _fclose(*(FILE **)&this->brakeSystem.tempRunFile._Filebuffer[4]);
    }
    this->brakeSystem.tempRunFile._Filebuffer[0] = 0;
    this->brakeSystem.tempRunFile.gap0[73] = 0;
    std::streambuf::_Init(&this->brakeSystem.tempRunFile.gap0[4]);
    *(_DWORD *)&this->brakeSystem.tempRunFile._Filebuffer[4] = 0;
    *(_DWORD *)&this->brakeSystem.tempRunFile.gap0[76] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&this->brakeSystem.tempRunFile.gap0[68] = 0;
  }
  std::streambuf::~streambuf<char,std::char_traits<char>>(&this->brakeSystem.tempRunFile.gap0[4]);
  std::ostream::~ostream<char,std::char_traits<char>>(&this->brakeSystem.tempRunFile.gap0[8]);
  std::ios::~ios<char,std::char_traits<char>>(v19);
  LOBYTE(v56) = 50;
  DynamicController::~DynamicController(&this->brakeSystem.steerBrake.controller);
  LOBYTE(v56) = 21;
  `eh vector destructor iterator'(this->brakeSystem.discs, 0x5Cu, 4, (void (*)(void *))BrakeDisc::~BrakeDisc);
  v20 = this->suspensions._Myfirst == 0;
  v21 = &this->suspensions;
  LOBYTE(v56) = 20;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all(&this->suspensions);
    operator delete(v21->_Myfirst);
    v21->_Myfirst = 0;
    this->suspensions._Mylast = 0;
    this->suspensions._Myend = 0;
  }
  LOBYTE(v56) = 19;
  `eh vector destructor iterator'(this->tyres, 0x660u, 4, (void (*)(void *))Tyre::~Tyre);
  LOBYTE(v56) = 18;
  AeroMap::~AeroMap(&this->aeroMap);
  LOBYTE(v56) = 17;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->speedLimiter);
  LOBYTE(v56) = 16;
  TractionControl::~TractionControl(&this->tractionControl);
  LOBYTE(v56) = 15;
  ABS::~ABS(&this->abs);
  LOBYTE(v56) = 14;
  Drivetrain::~Drivetrain(&this->drivetrain);
  LOBYTE(v56) = 13;
  CarColliderManager::~CarColliderManager(&this->colliderManager);
  LOBYTE(v56) = 12;
  TimeTransponder::~TimeTransponder(&this->transponder);
  if ( this->carDataPath._Myres >= 8 )
    operator delete(this->carDataPath._Bx._Ptr);
  this->carDataPath._Myres = 7;
  this->carDataPath._Mysize = 0;
  this->carDataPath._Bx._Buf[0] = 0;
  if ( this->configName._Myres >= 8 )
    operator delete(this->configName._Bx._Ptr);
  this->configName._Myres = 7;
  this->configName._Mysize = 0;
  this->configName._Bx._Buf[0] = 0;
  if ( this->unixName._Myres >= 8 )
    operator delete(this->unixName._Bx._Ptr);
  this->unixName._Myres = 7;
  this->unixName._Mysize = 0;
  v22 = &this->tyreCompounds;
  this->unixName._Bx._Buf[0] = 0;
  LOBYTE(v56) = 8;
  if ( this->tyreCompounds._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->tyreCompounds);
    v23 = *(float *)&this->tyreCompounds._Mylast;
    v24 = (wchar_t **)v22->_Myfirst;
    for ( l = v23; v24 != (wchar_t **)LODWORD(v23); v24 += 6 )
    {
      if ( (unsigned int)v24[5] >= 8 )
      {
        operator delete(*v24);
        v23 = l;
      }
      v24[5] = (wchar_t *)7;
      v24[4] = 0;
      *(_WORD *)v24 = 0;
    }
    operator delete(v22->_Myfirst);
    v22->_Myfirst = 0;
    this->tyreCompounds._Mylast = 0;
    this->tyreCompounds._Myend = 0;
  }
  v20 = this->evOnPush2Pass.handlers._Myfirst == 0;
  v25 = &this->evOnPush2Pass;
  LOBYTE(v56) = 7;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnPush2Pass);
    v26 = *(float *)&this->evOnPush2Pass.handlers._Mylast;
    v27 = v25->handlers._Myfirst;
    l = v26;
    if ( v27 != (std::pair<void *,std::function<void __cdecl(std::pair<int,int> const &)> > *)LODWORD(v26) )
    {
      v28 = &v27->second._Impl;
      do
      {
        if ( *v28 )
        {
          ((void (__stdcall *)(bool))(*v28)->_Delete_this)(*v28 != (std::_Func_base<void,std::pair<int,int> const &> *)(v28 - 4));
          v26 = l;
          *v28 = 0;
        }
        ++v27;
        v28 += 8;
      }
      while ( v27 != (std::pair<void *,std::function<void __cdecl(std::pair<int,int> const &)> > *)LODWORD(v26) );
      v25 = &this->evOnPush2Pass;
    }
    operator delete(v25->handlers._Myfirst);
    v25->handlers._Myfirst = 0;
    v25->handlers._Mylast = 0;
    v25->handlers._Myend = 0;
  }
  v20 = this->evOnJumpStartEvent.handlers._Myfirst == 0;
  v29 = &this->evOnJumpStartEvent;
  LOBYTE(v56) = 6;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnJumpStartEvent);
    v30 = *(float *)&this->evOnJumpStartEvent.handlers._Mylast;
    v31 = v29->handlers._Myfirst;
    l = v30;
    if ( v31 != (std::pair<void *,std::function<void __cdecl(double const &)> > *)LODWORD(v30) )
    {
      v32 = &v31->second._Impl;
      do
      {
        if ( *v32 )
        {
          ((void (__stdcall *)(bool))(*v32)->_Delete_this)(*v32 != (std::_Func_base<void,double const &> *)(v32 - 4));
          v30 = l;
          *v32 = 0;
        }
        ++v31;
        v32 += 8;
      }
      while ( v31 != (std::pair<void *,std::function<void __cdecl(double const &)> > *)LODWORD(v30) );
      v29 = &this->evOnJumpStartEvent;
    }
    operator delete(v29->handlers._Myfirst);
    v29->handlers._Myfirst = 0;
    v29->handlers._Mylast = 0;
    v29->handlers._Myend = 0;
  }
  v20 = this->evOnCollisionEvent.handlers._Myfirst == 0;
  v33 = &this->evOnCollisionEvent;
  LOBYTE(v56) = 5;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnCollisionEvent);
    v34 = *(float *)&this->evOnCollisionEvent.handlers._Mylast;
    v35 = v33->handlers._Myfirst;
    l = v34;
    if ( v35 != (std::pair<void *,std::function<void __cdecl(OnCollisionEvent const &)> > *)LODWORD(v34) )
    {
      v36 = &v35->second._Impl;
      do
      {
        if ( *v36 )
        {
          ((void (__stdcall *)(bool))(*v36)->_Delete_this)(*v36 != (std::_Func_base<void,OnCollisionEvent const &> *)(v36 - 4));
          v34 = l;
          *v36 = 0;
        }
        ++v35;
        v36 += 8;
      }
      while ( v35 != (std::pair<void *,std::function<void __cdecl(OnCollisionEvent const &)> > *)LODWORD(v34) );
      v33 = &this->evOnCollisionEvent;
    }
    operator delete(v33->handlers._Myfirst);
    v33->handlers._Myfirst = 0;
    v33->handlers._Mylast = 0;
    v33->handlers._Myend = 0;
  }
  v20 = this->evOnTyreCompoundChanged.handlers._Myfirst == 0;
  v37 = &this->evOnTyreCompoundChanged;
  LOBYTE(v56) = 4;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnTyreCompoundChanged);
    v38 = *(float *)&this->evOnTyreCompoundChanged.handlers._Mylast;
    v39 = v37->handlers._Myfirst;
    l = v38;
    if ( v39 != (std::pair<void *,std::function<void __cdecl(std::pair<int,int> const &)> > *)LODWORD(v38) )
    {
      v40 = &v39->second._Impl;
      do
      {
        if ( *v40 )
        {
          ((void (__stdcall *)(bool))(*v40)->_Delete_this)(*v40 != (std::_Func_base<void,std::pair<int,int> const &> *)(v40 - 4));
          v38 = l;
          *v40 = 0;
        }
        ++v39;
        v40 += 8;
      }
      while ( v39 != (std::pair<void *,std::function<void __cdecl(std::pair<int,int> const &)> > *)LODWORD(v38) );
      v37 = &this->evOnTyreCompoundChanged;
    }
    operator delete(v37->handlers._Myfirst);
    v37->handlers._Myfirst = 0;
    v37->handlers._Mylast = 0;
    v37->handlers._Myend = 0;
  }
  v20 = this->evOnForcedPositionCompleted.handlers._Myfirst == 0;
  v41 = &this->evOnForcedPositionCompleted;
  LOBYTE(v56) = 3;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnForcedPositionCompleted);
    v42 = *(float *)&this->evOnForcedPositionCompleted.handlers._Mylast;
    v43 = v41->handlers._Myfirst;
    l = v42;
    if ( v43 != (std::pair<void *,std::function<void __cdecl(vec3f const &)> > *)LODWORD(v42) )
    {
      v44 = &v43->second._Impl;
      do
      {
        if ( *v44 )
        {
          ((void (__stdcall *)(bool))(*v44)->_Delete_this)(*v44 != (std::_Func_base<void,vec3f const &> *)(v44 - 4));
          v42 = l;
          *v44 = 0;
        }
        ++v43;
        v44 += 8;
      }
      while ( v43 != (std::pair<void *,std::function<void __cdecl(vec3f const &)> > *)LODWORD(v42) );
      v41 = &this->evOnForcedPositionCompleted;
    }
    operator delete(v41->handlers._Myfirst);
    v41->handlers._Myfirst = 0;
    v41->handlers._Mylast = 0;
    v41->handlers._Myend = 0;
  }
  v20 = this->evOnSectorSplit.handlers._Myfirst == 0;
  v45 = &this->evOnSectorSplit;
  LOBYTE(v56) = 2;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnSectorSplit);
    v46 = *(float *)&this->evOnSectorSplit.handlers._Mylast;
    v47 = v45->handlers._Myfirst;
    l = v46;
    if ( v47 != (std::pair<void *,std::function<void __cdecl(OnSectorSplitEvent const &)> > *)LODWORD(v46) )
    {
      v48 = &v47->second._Impl;
      do
      {
        if ( *v48 )
        {
          ((void (__stdcall *)(bool))(*v48)->_Delete_this)(*v48 != (std::_Func_base<void,OnSectorSplitEvent const &> *)(v48 - 4));
          v46 = l;
          *v48 = 0;
        }
        ++v47;
        v48 += 8;
      }
      while ( v47 != (std::pair<void *,std::function<void __cdecl(OnSectorSplitEvent const &)> > *)LODWORD(v46) );
      v45 = &this->evOnSectorSplit;
    }
    operator delete(v45->handlers._Myfirst);
    v45->handlers._Myfirst = 0;
    v45->handlers._Mylast = 0;
    v45->handlers._Myend = 0;
  }
  v20 = this->evOnLapCompleted.handlers._Myfirst == 0;
  LOBYTE(v56) = 1;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnLapCompleted);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnLapCompleted,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnLapCompleted.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnLapCompleted.handlers._Mylast);
    operator delete(this->evOnLapCompleted.handlers._Myfirst);
    this->evOnLapCompleted.handlers._Myfirst = 0;
    this->evOnLapCompleted.handlers._Mylast = 0;
    this->evOnLapCompleted.handlers._Myend = 0;
  }
  v20 = this->evOnControlsProviderChanged.handlers._Myfirst == 0;
  LOBYTE(v56) = 0;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnControlsProviderChanged);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnControlsProviderChanged,
      (Task *)this->evOnControlsProviderChanged.handlers._Myfirst,
      (Task *)this->evOnControlsProviderChanged.handlers._Mylast);
    operator delete(this->evOnControlsProviderChanged.handlers._Myfirst);
    this->evOnControlsProviderChanged.handlers._Myfirst = 0;
    this->evOnControlsProviderChanged.handlers._Mylast = 0;
    this->evOnControlsProviderChanged.handlers._Myend = 0;
  }
  v20 = this->evOnStepComplete.handlers._Myfirst == 0;
  v56 = -1;
  if ( !v20 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnStepComplete);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnStepComplete,
      (Task *)this->evOnStepComplete.handlers._Myfirst,
      (Task *)this->evOnStepComplete.handlers._Mylast);
    operator delete(this->evOnStepComplete.handlers._Myfirst);
    this->evOnStepComplete.handlers._Myfirst = 0;
    this->evOnStepComplete.handlers._Mylast = 0;
    this->evOnStepComplete.handlers._Myend = 0;
  }
}
Car *Car::`vector deleting destructor'(Car *this, unsigned int a2)
{
  Car::~Car(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Car::addPenalty(Car *this, long double ptime)
{
  long double v3; // xmm0_8
  long double v4; // [esp+0h] [ebp-18h]
  double v5; // [esp+8h] [ebp-10h]

  if ( this->penaltyTime > 0.0 )
  {
    this->disableMinSpeedPenaltyClear = 1;
    _printf("SUPPRESSING MIN SPEED PENALTY CLEAR\n");
  }
  _printf("Adding penalty PT: %f -> ", (double)this->penaltyTime);
  v5 = this->penaltyTimeAccumulator;
  v4 = ptime + this->penaltyTime;
  this->penaltyTime = v4;
  _printf("%f  PTA:%f -> ", (double)v4, v5);
  v3 = this->penaltyTimeAccumulator + ptime;
  this->penaltyTimeAccumulator = v3;
  _printf("%f\n", (double)v3);
}
void __usercall Car::buildARBS(Car *this@<ecx>, unsigned int a2@<ebx>)
{
  std::wstring *v3; // esi
  const std::wstring *v4; // eax
  const std::wstring *v5; // eax
  ISuspension **v6; // ecx
  double v7; // st7
  bool v8; // cf
  double v9; // st7
  const std::wstring *v10; // eax
  const std::wstring *v11; // eax
  std::wstring *v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // esi
  ISuspension *susFront[2]; // [esp+Ch] [ebp-F4h] BYREF
  ISuspension *susRear[2]; // [esp+14h] [ebp-ECh] BYREF
  std::wstring section; // [esp+1Ch] [ebp-E4h] BYREF
  std::wstring key; // [esp+34h] [ebp-CCh] BYREF
  std::wstring result; // [esp+4Ch] [ebp-B4h] BYREF
  std::wstring front_arb; // [esp+64h] [ebp-9Ch] BYREF
  std::wstring rear_arb; // [esp+7Ch] [ebp-84h] BYREF
  std::wstring v24; // [esp+94h] [ebp-6Ch] BYREF
  INIReader r; // [esp+ACh] [ebp-54h] BYREF
  int v26; // [esp+FCh] [ebp-4h]

  v3 = &this->carDataPath;
  v4 = std::operator+<wchar_t>(&result, &this->carDataPath, L"suspensions.ini");
  v26 = 0;
  v5 = Car::getConfigPath(this, &v24, v4);
  LOBYTE(v26) = 1;
  INIReader::INIReader(&r, v5);
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  LOBYTE(v26) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v6 = this->suspensions._Myfirst;
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  susFront[0] = *v6;
  susFront[1] = v6[1];
  susRear[0] = v6[2];
  susRear[1] = v6[3];
  AntirollBar::init(this->antirollBars, this->body, susFront);
  AntirollBar::init(&this->antirollBars[1], this->body, susRear);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"FRONT", 5u);
  LOBYTE(v26) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ARB", 3u);
  LOBYTE(v26) = 6;
  v7 = INIReader::getFloat(&r, &section, &key);
  v8 = section._Myres < 8;
  this->antirollBars[0].k = v7;
  if ( !v8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v26) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"REAR", 4u);
  LOBYTE(v26) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ARB", 3u);
  LOBYTE(v26) = 8;
  v9 = INIReader::getFloat(&r, &section, &key);
  v8 = section._Myres < 8;
  this->antirollBars[1].k = v9;
  if ( !v8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v26) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v10 = std::operator+<wchar_t>(&key, v3, L"ctrl_arb_front.ini");
  LOBYTE(v26) = 9;
  Car::getConfigPath(this, &front_arb, v10);
  LOBYTE(v26) = 11;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Bx._Buf[0] = 0;
  key._Mysize = 0;
  v11 = std::operator+<wchar_t>(&result, v3, L"ctrl_arb_rear.ini");
  LOBYTE(v26) = 12;
  Car::getConfigPath(this, &rear_arb, v11);
  LOBYTE(v26) = 14;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( Path::fileExists(a2, &front_arb, 0) )
  {
    v12 = &front_arb;
    if ( front_arb._Myres >= 8 )
      v12 = (std::wstring *)front_arb._Bx._Ptr;
    _printf("Loading front ARB controller from: %S\n", v12->_Bx._Buf);
    DynamicController::DynamicController((DynamicController *)&section, this, &front_arb);
    v14 = v13;
    this->antirollBars[0].ctrl.car = *(Car **)v13;
    LOBYTE(v26) = 15;
    std::vector<DynamicControllerStage>::operator=(
      &this->antirollBars[0].ctrl.stages,
      (const std::vector<DynamicControllerStage> *)(v13 + 4));
    this->antirollBars[0].ctrl.ready = *(_BYTE *)(v14 + 16);
    LOBYTE(v26) = 14;
    DynamicController::~DynamicController((DynamicController *)&section);
  }
  if ( Path::fileExists(a2, &rear_arb, 0) )
  {
    DynamicController::DynamicController((DynamicController *)&section, this, &rear_arb);
    v16 = v15;
    this->antirollBars[1].ctrl.car = *(Car **)v15;
    LOBYTE(v26) = 16;
    std::vector<DynamicControllerStage>::operator=(
      &this->antirollBars[1].ctrl.stages,
      (const std::vector<DynamicControllerStage> *)(v15 + 4));
    this->antirollBars[1].ctrl.ready = *(_BYTE *)(v16 + 16);
    LOBYTE(v26) = 14;
    DynamicController::~DynamicController((DynamicController *)&section);
  }
  if ( rear_arb._Myres >= 8 )
    operator delete(rear_arb._Bx._Ptr);
  rear_arb._Myres = 7;
  rear_arb._Mysize = 0;
  rear_arb._Bx._Buf[0] = 0;
  if ( front_arb._Myres >= 8 )
    operator delete(front_arb._Bx._Ptr);
  front_arb._Myres = 7;
  front_arb._Mysize = 0;
  front_arb._Bx._Buf[0] = 0;
  v26 = -1;
  INIReader::~INIReader(&r);
}
double Car::calcBodyMass(Car *this)
{
  int i; // esi
  double v3; // st7
  float unsprung; // [esp+0h] [ebp-4h]

  unsprung = 0.0;
  for ( i = 0; i < 4; ++i )
  {
    v3 = ((double (*)(ISuspension *))this->suspensions._Myfirst[i]->getMass)(this->suspensions._Myfirst[i])
       + unsprung;
    unsprung = v3;
  }
  return this->mass - v3 + this->ballastKG;
}
void Car::clearPenalty(Car *this)
{
  if ( this->penaltyTime > 0.0 )
  {
    _printf("Clearing penalties\n");
    this->disableMinSpeedPenaltyClear = 0;
    *(_OWORD *)&this->penaltyTimeAccumulator = 0i64;
  }
}
void Car::forcePosition(Car *this, const vec3f *pos, bool invalidateTransponder)
{
  Car *v3; // ebx
  float v4; // eax
  IRigidBody_vtbl *v5; // esi
  int v6; // eax
  char *v7; // esi
  int v8; // ebp
  unsigned int v9; // ecx
  unsigned int v10; // ebx
  int v11; // edi
  Tyre *i; // esi
  std::pair<void *,std::function<void __cdecl(vec3f const &)> > *v13; // esi
  std::_Func_base<void,vec3f const &> **v14; // edi
  vec3f lpos; // [esp+38h] [ebp-30h] BYREF
  RaceEngineer re; // [esp+44h] [ebp-24h] BYREF
  vec3f v18; // [esp+50h] [ebp-18h] BYREF
  int v19; // [esp+64h] [ebp-4h]

  v3 = this;
  RaceEngineer::RaceEngineer(&re, this);
  v19 = 0;
  v4 = pos->z;
  *(_QWORD *)&lpos.x = *(_QWORD *)&pos->x;
  lpos.z = v4;
  lpos.y = RaceEngineer::getBaseCarHeight(&re) + 0.0099999998 + lpos.y;
  Car::reset(v3);
  ((void (*)(IRigidBody *, int))v3->body->stop)(v3->body, 1065353216);
  v3->body->setPosition(v3->body, &lpos);
  v5 = v3->fuelTankBody->__vftable;
  v6 = (int)v3->body->localToWorld(v3->body, &v18, &v3->fuelTankPos);
  v5->setPosition(v3->fuelTankBody, (const vec3f *)v6);
  v7 = (char *)v3->suspensions._Myfirst;
  v8 = 0;
  v9 = (unsigned int)((char *)v3->suspensions._Mylast - v7 + 3) >> 2;
  if ( (ISuspension **)v7 > v3->suspensions._Mylast )
    v9 = 0;
  if ( v9 )
  {
    v10 = v9;
    do
    {
      v11 = *(_DWORD *)v7;
      (*(void (**)(_DWORD))(**(_DWORD **)v7 + 76))(*(_DWORD *)v7);
      (*(void (**)(int))(*(_DWORD *)v11 + 32))(v11);
      ++v8;
      v7 += 4;
    }
    while ( v8 != v10 );
    v3 = this;
  }
  Drivetrain::reset(&v3->drivetrain);
  BrakeSystem::reset(&v3->brakeSystem);
  for ( i = v3->tyres; i != (Tyre *)&v3->suspensions; ++i )
    Tyre::reset(i);
  Drivetrain::setCurrentGear(&v3->drivetrain, 1, 1);
  if ( invalidateTransponder )
    TimeTransponder::invalidate(&v3->transponder);
  v13 = v3->evOnForcedPositionCompleted.handlers._Myfirst;
  if ( v13 != v3->evOnForcedPositionCompleted.handlers._Mylast )
  {
    v14 = &v13->second._Impl;
    do
    {
      if ( !*v14 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x732245);
      }
      (*v14)->_Do_call(*v14, &lpos);
      ++v13;
      v14 += 8;
    }
    while ( v13 != v3->evOnForcedPositionCompleted.handlers._Mylast );
  }
  ((void (*)(IRigidBody *, int))v3->body->stop)(v3->body, 1065353216);
  ((void (*)(IRigidBody *, int))v3->fuelTankBody->stop)(v3->fuelTankBody, 1065353216);
  v3->framesToSleep = 50;
  SplineLocator::reset(&v3->splineLocator);
  v19 = -1;
  RaceEngineer::~RaceEngineer(&re);
}
void Car::forceRotation(Car *this, const vec3f *ihed)
{
  __int64 v3; // xmm0_8
  float v4; // eax
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  IRigidBody *v9; // ecx
  ISuspension **v10; // eax
  ISuspension **v11; // esi
  const vec3f *v12; // edi
  unsigned int v13; // ecx
  Car *v14; // esi
  mat44f v15; // [esp+18h] [ebp-50h] BYREF
  __int64 v16; // [esp+58h] [ebp-10h]
  float v17; // [esp+60h] [ebp-8h]
  Car *v18; // [esp+64h] [ebp-4h]
  const vec3f *iheda; // [esp+6Ch] [ebp+4h]

  v3 = *(_QWORD *)&ihed->x;
  v4 = ihed->z;
  v18 = this;
  v16 = v3;
  v17 = v4;
  mat44f::mat44f(&v15);
  mat44f::loadIdentity(&v15);
  v5 = (float)(*((float *)&v16 + 1) * 0.0) - v17;
  v6 = *(float *)&v16 - (float)(*((float *)&v16 + 1) * 0.0);
  v7 = (float)(v17 * 0.0) - (float)(*(float *)&v16 * 0.0);
  v8 = fsqrt((float)((float)(v5 * v5) + (float)(v7 * v7)) + (float)(v6 * v6));
  if ( v8 != 0.0 )
  {
    v6 = v6 * (float)(1.0 / v8);
    v5 = v5 * (float)(1.0 / v8);
    v7 = v7 * (float)(1.0 / v8);
  }
  v9 = this->body;
  LODWORD(v15.M31) = v16 ^ _xmm;
  LODWORD(v15.M32) = HIDWORD(v16) ^ _xmm;
  LODWORD(v15.M33) = LODWORD(v17) ^ _xmm;
  v15.M21 = 0.0;
  v15.M22 = 1.0;
  v15.M23 = 0.0;
  v15.M11 = v5;
  v15.M12 = v7;
  v15.M13 = v6;
  v9->setRotation(v9, &v15);
  this->fuelTankBody->setRotation(this->fuelTankBody, &v15);
  v10 = this->suspensions._Mylast;
  v11 = this->suspensions._Myfirst;
  v12 = 0;
  v13 = (unsigned int)((char *)v10 - (char *)v11 + 3) >> 2;
  if ( v11 > v10 )
    v13 = 0;
  iheda = (const vec3f *)v13;
  if ( v13 )
  {
    do
    {
      (*v11)->attach(*v11);
      v12 = (const vec3f *)((char *)v12 + 1);
      ++v11;
    }
    while ( v12 != iheda );
  }
  v14 = v18;
  ((void (*)(IRigidBody *, int))v18->body->stop)(v18->body, 1065353216);
  ((void (*)(IRigidBody *, int))v14->fuelTankBody->stop)(v14->fuelTankBody, 1065353216);
}
void Car::getAIState(Car *this, AIState *state)
{
  vec3f *v3; // eax
  AIDriver *v4; // edi
  AISpline *v5; // eax

  v3 = (vec3f *)__RTDynamicCast(
                  this->controlsProvider,
                  0,
                  &ICarControlsProvider `RTTI Type Descriptor',
                  &AIDriver `RTTI Type Descriptor',
                  0);
  v4 = (AIDriver *)v3;
  if ( v3 )
  {
    state->isActive = 1;
    state->currentSteerSignal = v3[42].z;
    state->targetLateralOffset = v3[43].y;
    state->brakeTargetSpeed = v3[3].x;
    state->targetSpeed = v3[31].z;
    state->currentNormalizedSplinePosition = this->splineLocatorData.npos;
    state->steerTarget = v3[5];
    state->gasBrakeTarget = v3[2].y;
    v5 = AISplineRecorder::getBestLapSpline(this->ksPhysics->track->aiSplineRecorder._Myptr);
    state->brakeTargetDist = Spline::length(&v5->spline)
                           * (float)(v4->brakePoint.targetNormalized - this->splineLocatorData.npos);
    state->outsideOffset = AIDriver::getOutsideOffset(v4);
    state->projDNRPM = v4->prjDNRPM;
    state->currentPush = AIDriver::getLateralPush(v4);
    state->understeerFactor = v4->understeerFactor;
  }
  else
  {
    state->isActive = 0;
  }
}
double Car::getBackDistanceFromCar(Car *this, Car *car)
{
  float dist; // [esp+4h] [ebp+4h]

  dist = this->splineLocatorData.npos - car->splineLocatorData.npos;
  if ( dist < 0.0 )
    dist = dist + 1.0;
  return Spline::length(&this->splineLocator.currentSpline->spline) * dist;
}
double Car::getCGHeight(Car *this)
{
  Tyre *v1; // eax
  float v2; // xmm1_4
  float groundy; // [esp+8h] [ebp-10h]
  char v5[12]; // [esp+Ch] [ebp-Ch] BYREF

  v1 = this->tyres;
  v2 = 0.0;
  groundy = 0.0;
  if ( this->tyres != (Tyre *)&this->suspensions )
  {
    do
    {
      v2 = v2 + v1->contactPoint.y;
      ++v1;
    }
    while ( v1 != (Tyre *)&this->suspensions );
    groundy = v2;
  }
  return *(float *)(((int (*)(IRigidBody *, char *, _DWORD))this->body->getPosition)(this->body, v5, 0) + 4)
       - groundy * 0.25;
}
std::wstring *Car::getConfigPath(Car *this, std::wstring *result, const std::wstring *filename)
{
  std::wstring *v4; // esi
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring config_data_folder_file; // [esp+18h] [ebp-A0h] BYREF
  std::wstring v11; // [esp+30h] [ebp-88h] BYREF
  std::wstring v12; // [esp+48h] [ebp-70h] BYREF
  std::wstring v13; // [esp+60h] [ebp-58h] BYREF
  std::wstring v14; // [esp+78h] [ebp-40h] BYREF
  std::wstring v15; // [esp+90h] [ebp-28h] BYREF
  int v16; // [esp+B4h] [ebp-4h]

  if ( !this->configName._Mysize )
  {
LABEL_17:
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, filename, 0, 0xFFFFFFFF);
    return result;
  }
  v4 = Path::getFileName(&v15, filename);
  v16 = 0;
  v5 = std::operator+<wchar_t>(&v13, L"content/cars/", &this->unixName);
  LOBYTE(v16) = 1;
  v6 = std::operator+<wchar_t>(&v12, v5, L"/data_");
  LOBYTE(v16) = 2;
  v7 = std::operator+<wchar_t>(&v11, v6, &this->configName);
  LOBYTE(v16) = 3;
  v8 = std::operator+<wchar_t>(&v14, v7, L"/");
  LOBYTE(v16) = 4;
  std::operator+<wchar_t>(&config_data_folder_file, v8, v4);
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  if ( v11._Myres >= 8 )
    operator delete(v11._Bx._Ptr);
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  if ( v12._Myres >= 8 )
    operator delete(v12._Bx._Ptr);
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  LOBYTE(v16) = 10;
  if ( v15._Myres >= 8 )
    operator delete(v15._Bx._Ptr);
  v15._Myres = 7;
  v15._Bx._Buf[0] = 0;
  v15._Mysize = 0;
  if ( !Path::fileExists((unsigned int)this, &config_data_folder_file, 0) )
  {
    v16 = -1;
    if ( config_data_folder_file._Myres >= 8 )
      operator delete(config_data_folder_file._Bx._Ptr);
    goto LABEL_17;
  }
  std::wstring::wstring(result, &config_data_folder_file);
  if ( config_data_folder_file._Myres >= 8 )
    operator delete(config_data_folder_file._Bx._Ptr);
  return result;
}
ICarControlsProvider *Car::getControlsProvider(Car *this)
{
  return this->controlsProvider;
}
void Car::getEngagement(Car *this, const float engagement_length, float *left, float *right)
{
  float v4; // xmm0_4
  Car *v5; // edi
  float v6; // xmm2_4
  PhysicsEngine *v7; // eax
  int *v8; // esi
  Car **v9; // eax
  bool v10; // cc
  unsigned int v11; // eax
  int v12; // eax
  int v13; // ecx
  IRigidBody_vtbl *v14; // edi
  int v15; // eax
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  char v21[8]; // [esp+Ch] [ebp-40h] BYREF
  _DWORD v22[4]; // [esp+14h] [ebp-38h]
  __int64 v23; // [esp+24h] [ebp-28h] BYREF
  float v24; // [esp+2Ch] [ebp-20h]
  float v25; // [esp+30h] [ebp-1Ch]
  int v26; // [esp+34h] [ebp-18h]
  int v27; // [esp+38h] [ebp-14h]
  Car *v28; // [esp+3Ch] [ebp-10h]
  unsigned int v29; // [esp+40h] [ebp-Ch]
  float v30; // [esp+44h] [ebp-8h]
  float v31; // [esp+48h] [ebp-4h]

  v4 = FLOAT_N1_0;
  v5 = this;
  v30 = FLOAT_N1_0;
  v6 = -1.0;
  v28 = this;
  v31 = -1.0;
  v26 = 0;
  v7 = this->ksPhysics;
  v8 = (int *)v7->cars._Myfirst;
  v9 = v7->cars._Mylast;
  v29 = (unsigned int)((char *)v9 - (char *)v8 + 3) >> 2;
  v10 = v8 <= (int *)v9;
  v11 = v29;
  if ( !v10 )
    v11 = 0;
  v29 = v11;
  if ( v11 )
  {
    do
    {
      v12 = *v8;
      v27 = v12;
      if ( (Car *)v12 != v5 )
      {
        if ( v12 + 2040 != v12 + 8568 )
        {
          v13 = v12 + 2856;
          while ( !*(_DWORD *)v13 || !*(_BYTE *)(*(_DWORD *)v13 + 168) )
          {
            v13 += 1632;
            if ( v13 - 816 == v12 + 8568 )
              goto LABEL_10;
          }
          goto LABEL_31;
        }
LABEL_10:
        v14 = v5->body->__vftable;
        v15 = (*(int (**)(_DWORD, char *, _DWORD))(**(_DWORD **)(v27 + 152) + 80))(
                *(_DWORD *)(v27 + 152),
                v21,
                0);
        v14->worldToLocal(v28->body, (vec3f *)&v23, (const vec3f *)v15);
        *(_QWORD *)&v22[1] = v23;
        *(float *)&v22[3] = v24;
        v25 = v24;
        LODWORD(v16) = __libm_sse2_asinf().m128_u32[0];
        if ( v25 <= 0.0 )
        {
          if ( v25 >= 0.0 )
            v17 = 0.0;
          else
            v17 = FLOAT_N1_0;
        }
        else
        {
          v17 = FLOAT_1_0;
        }
        v5 = v28;
        v18 = v17 * v16;
        v19 = v28->splineLocatorData.npos - *(float *)(v27 + 11008);
        v20 = v18 * 57.29578;
        if ( v19 < 0.0 )
          v19 = v19 + 1.0;
        if ( engagement_length <= COERCE_FLOAT(LODWORD(v25) & _xmm)
          || (float)(v28->splineLocatorData.splineLength * 0.0) >= 15.0
          && (float)(v28->splineLocatorData.splineLength * v19) >= 15.0
          || COERCE_FLOAT(LODWORD(v20) & _xmm) <= 25.0 )
        {
          v6 = v31;
        }
        else
        {
          if ( *(float *)&v23 > 0.0 )
          {
            v4 = v30;
            if ( v30 < 0.0 || v30 > *(float *)&v23 )
            {
              v4 = *(float *)&v23;
              v30 = *(float *)&v23;
            }
            v6 = v31;
            goto LABEL_31;
          }
          v6 = v31;
          if ( v31 < 0.0 || v31 > COERCE_FLOAT(v23 ^ _xmm) )
          {
            LODWORD(v6) = v23 ^ _xmm;
            LODWORD(v31) = v23 ^ _xmm;
          }
        }
        v4 = v30;
      }
LABEL_31:
      ++v8;
      ++v26;
    }
    while ( v26 != v29 );
  }
  *left = v4;
  *right = v6;
}
double Car::getFinalFF(Car *this)
{
  return ((double (*)(ICarControlsProvider *))this->controlsProvider->getFFGlobalGain)(this->controlsProvider)
       * (this->lastFF
        * this->userFFGain);
}
double Car::getFrontWheelAngle(Car *this)
{
  IRigidBody *v2; // ecx
  IRigidBody *v3; // ecx
  float v4; // xmm5_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  int v10; // xmm6_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm5_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v19; // [esp+0h] [ebp-C8h]
  float v20; // [esp+4h] [ebp-C4h]
  float v21; // [esp+8h] [ebp-C0h]
  int v22; // [esp+14h] [ebp-B4h] BYREF
  float v23; // [esp+18h] [ebp-B0h]
  int v24; // [esp+1Ch] [ebp-ACh] BYREF
  float v25; // [esp+20h] [ebp-A8h] BYREF
  float v26; // [esp+24h] [ebp-A4h]
  float v27; // [esp+2Ch] [ebp-9Ch]
  vec3f v28; // [esp+34h] [ebp-94h] BYREF
  char v29[24]; // [esp+48h] [ebp-80h] BYREF
  int v30; // [esp+60h] [ebp-68h]
  int v31; // [esp+64h] [ebp-64h]
  int v32; // [esp+68h] [ebp-60h]
  char v33[20]; // [esp+84h] [ebp-44h] BYREF
  int v34; // [esp+98h] [ebp-30h]
  int v35; // [esp+9Ch] [ebp-2Ch]
  int v36; // [esp+A0h] [ebp-28h]

  (*(void (**)(ISuspension *, char *))(**(_DWORD **)this->suspensions._Myfirst + 4))(
    *this->suspensions._Myfirst,
    v29);
  (*(void (**)(_DWORD, char *))(**((_DWORD **)this->suspensions._Myfirst + 1) + 4))(
    *((_DWORD *)this->suspensions._Myfirst + 1),
    v33);
  v2 = this->body;
  v24 = v30 ^ _xmm;
  LODWORD(v25) = v31 ^ _xmm;
  LODWORD(v26) = v32 ^ _xmm;
  v2->worldToLocalNormal(v2, &v28, (const vec3f *)&v24);
  v3 = this->body;
  v22 = v34 ^ _xmm;
  LODWORD(v23) = v35 ^ _xmm;
  v24 = v36 ^ _xmm;
  v3->worldToLocalNormal(v3, (vec3f *)&v25, (const vec3f *)&v22);
  v4 = v27;
  v5 = FLOAT_1_0;
  v20 = v26;
  v6 = fsqrt((float)(v26 * v26) + (float)(v4 * v4));
  if ( v6 != 0.0 )
  {
    v7 = 1.0 / v6;
    v4 = v7 * v27;
    v20 = v7 * v26;
  }
  v19 = v23;
  v21 = v25;
  v8 = fsqrt((float)(v23 * v23) + (float)(v25 * v25));
  if ( v8 != 0.0 )
  {
    v9 = 1.0 / v8;
    v21 = v9 * v25;
    v19 = v9 * v23;
  }
  v10 = _xmm;
  v11 = FLOAT_N1_0;
  LODWORD(v12) = LODWORD(v4) ^ _xmm;
  if ( v12 <= -1.0 || v12 >= 1.0 )
  {
    v13 = 0.0;
  }
  else
  {
    v5 = FLOAT_1_0;
    LODWORD(v13) = __libm_sse2_acosf().m128_u32[0];
    v11 = FLOAT_N1_0;
    v10 = _xmm;
  }
  if ( v20 <= 0.0 )
  {
    if ( v20 >= 0.0 )
      v14 = 0.0;
    else
      v14 = v11;
  }
  else
  {
    v14 = v5;
  }
  v15 = v14 * v13;
  if ( COERCE_FLOAT(LODWORD(v21) ^ v10) <= v11 || v5 <= COERCE_FLOAT(LODWORD(v21) ^ v10) )
  {
    v16 = 0.0;
  }
  else
  {
    LODWORD(v16) = __libm_sse2_acosf().m128_u32[0];
    v11 = FLOAT_N1_0;
  }
  if ( v19 <= 0.0 )
  {
    if ( v19 >= 0.0 )
      v17 = 0.0;
    else
      v17 = v11;
  }
  else
  {
    v17 = FLOAT_1_0;
  }
  return (float)((float)((float)(v17 * v16) + v15) * 0.5);
}
double Car::getFuelPerLap(Car *this)
{
  double result; // st7
  float fuelxlap; // [esp+4h] [ebp-4h]

  result = FuelLapEvaluator::getFuelPerLap(&this->fuelLapEvaluator);
  fuelxlap = result;
  if ( fuelxlap <= 0.0 )
    result = this->expectedFuelPerLap;
  return result;
}
plane4f *Car::getGroundPlane(Car *this, plane4f *result)
{
  plane4f *v2; // eax
  float v3; // xmm2_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // [esp+0h] [ebp-8h]
  float v19; // [esp+4h] [ebp-4h]

  v2 = result;
  result->normal.x = 0.0;
  result->normal.y = 0.0;
  result->normal.z = 0.0;
  v3 = this->tyres[0].unmodifiedContactPoint.x;
  v4 = this->tyres[2].unmodifiedContactPoint.x - v3;
  v5 = this->tyres[0].unmodifiedContactPoint.y;
  v6 = this->tyres[1].unmodifiedContactPoint.x - v3;
  v7 = this->tyres[2].unmodifiedContactPoint.y - v5;
  v8 = this->tyres[0].unmodifiedContactPoint.z;
  v9 = this->tyres[1].unmodifiedContactPoint.y - v5;
  v10 = this->tyres[1].unmodifiedContactPoint.z - v8;
  v11 = this->tyres[2].unmodifiedContactPoint.z - v8;
  v12 = (float)(v11 * v9) - (float)(v7 * v10);
  v19 = (float)(v4 * v10) - (float)(v11 * v6);
  v18 = (float)(v7 * v6) - (float)(v4 * v9);
  v13 = (float)((float)(v19 * v19) + (float)(v12 * v12)) + (float)(v18 * v18);
  if ( v13 <= 0.0 )
  {
    result->d = 0.0;
  }
  else
  {
    v14 = 1.0 / fsqrt(v13);
    v15 = v14 * v19;
    v16 = v14 * v18;
    v17 = v14 * v12;
    result->normal.y = v15;
    result->normal.z = v16;
    result->normal.x = v17;
    LODWORD(result->d) = COERCE_UNSIGNED_INT(
                           (float)((float)(this->tyres[0].unmodifiedContactPoint.x * v17)
                                 + (float)(this->tyres[0].unmodifiedContactPoint.y * v15))
                         + (float)(v16 * this->tyres[0].unmodifiedContactPoint.z)) ^ _xmm;
  }
  return v2;
}
vec3f *Car::getGroundWindVector(Car *this, vec3f *result)
{
  PhysicsEngine *v3; // eax
  float v4; // xmm7_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  vec3f *v7; // eax
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  plane4f p; // [esp+4h] [ebp-10h] BYREF

  Car::getGroundPlane(this, &p);
  v3 = this->ksPhysics;
  v4 = v3->wind.vector.y;
  v5 = v3->wind.vector.x;
  v6 = v3->wind.vector.z;
  v7 = result;
  v8 = (float)((float)(v5 * p.normal.x) + (float)(v4 * p.normal.y)) + (float)(v6 * p.normal.z);
  v9 = (float)(v6 - (float)(p.normal.z * v8)) * 0.44;
  v10 = (float)(v4 - (float)(v8 * p.normal.y)) * 0.44;
  result->x = (float)(v5 - (float)(v8 * p.normal.x)) * 0.44;
  result->z = v9;
  result->y = v10;
  return v7;
}
vec3f *Car::getLocalAngularVelocity(Car *this, vec3f *result)
{
  this->body->getLocalAngularVelocity(this->body, result);
  return result;
}
vec3f *Car::getLocalVelocity(Car *this, vec3f *result)
{
  this->body->getLocalVelocity(this->body, result);
  return result;
}
long double Car::getPenaltyTime(Car *this)
{
  long double result; // st7

  if ( this->penaltyTime <= 0.0 )
    result = 0.0;
  else
    result = this->penaltyTimeAccumulator;
  return result;
}
void Car::getPhysicsState(Car *this, CarPhysicsState *state)
{
  Car *v2; // edi
  CarPhysicsState *v3; // esi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  double v7; // st7
  float v8; // xmm0_4
  bool v9; // al
  float v10; // xmm0_4
  int v11; // edx
  float v12; // ecx
  TyreThermalState *v13; // eax
  float v14; // esi
  double v15; // xmm1_8
  float *v16; // ecx
  ISuspension **v17; // eax
  double v18; // st7
  float *v19; // ecx
  float v20; // xmm0_4
  const __m128i *v21; // eax
  bool v22; // cf
  int v23; // ecx
  __m128i v24; // xmm0
  __m128i v25; // xmm1
  __m128i v26; // xmm2
  __m128i v27; // xmm3
  float *v28; // edx
  bool v29; // zf
  const void *v30; // eax
  int v31; // ecx
  int v32; // ecx
  int *v33; // eax
  float *v34; // ecx
  int v35; // eax
  double v36; // xmm0_8
  float *v37; // eax
  const __m128i *v38; // eax
  CarPhysicsState *v39; // edi
  Car *v40; // esi
  double v41; // st7
  float *v42; // eax
  CarPhysicsState *v43; // ecx
  float v44; // xmm7_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm6_4
  float v50; // xmm1_4
  float v51; // xmm5_4
  float v52; // xmm4_4
  float v53; // xmm6_4
  float v54; // xmm6_4
  float v55; // xmm3_4
  float v56; // xmm1_4
  float v57; // eax
  float v58; // eax
  float v59; // eax
  int v60; // eax
  float v61; // eax
  Tyre *v62; // eax
  float v63; // xmm0_4
  float v64; // xmm0_4
  IRigidBody *v65; // ecx
  IRigidBody_vtbl *v66; // eax
  int v67; // eax
  CarPhysicsState *v68; // ecx
  int *v69; // esi
  int v70; // eax
  int v71; // xmm0_4
  int v72; // eax
  float *v73; // esi
  vec3f *v74; // eax
  float v75; // xmm2_4
  float v76; // xmm0_4
  float v77; // xmm1_4
  double v78; // st7
  int v79; // [esp+28h] [ebp-C8h]
  plane4f result; // [esp+38h] [ebp-B8h] BYREF
  mat44f v81; // [esp+48h] [ebp-A8h] BYREF
  PerformanceSplit v82; // [esp+88h] [ebp-68h] BYREF
  RaceEngineer v83; // [esp+98h] [ebp-58h] BYREF
  __int64 v84; // [esp+A4h] [ebp-4Ch]
  __int64 v85; // [esp+ACh] [ebp-44h]
  float v86; // [esp+B4h] [ebp-3Ch]
  TyreThermalState *v87; // [esp+B8h] [ebp-38h]
  float v88; // [esp+BCh] [ebp-34h]
  __m128i *v89; // [esp+C0h] [ebp-30h]
  RaceEngineer v90; // [esp+C4h] [ebp-2Ch] BYREF
  int index; // [esp+D0h] [ebp-20h]
  float *v92; // [esp+D4h] [ebp-1Ch]
  int v93; // [esp+D8h] [ebp-18h]
  Car *icar; // [esp+DCh] [ebp-14h]
  float v95; // [esp+E0h] [ebp-10h]
  int v96; // [esp+ECh] [ebp-4h]

  v2 = this;
  icar = this;
  if ( (dword_186F158 & 1) == 0 )
  {
    perfCounter_31.name = "Car::getPhysicsState";
    dword_186F158 |= 1u;
    perfCounter_31.group = Physics;
    perfCounter_31.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Car::getPhysicsState" | 0xFF000000;
  }
  v3 = state;
  state->statusBytes = 0;
  if ( this->lightsOn )
    v3->statusBytes = 1;
  if ( this->drs.isPresent )
  {
    if ( this->drs.isAvailable )
      v3->statusBytes |= 2u;
    if ( this->drs.isActive )
      v3->statusBytes |= 4u;
  }
  v3->p2pStatus = 0;
  if ( this->drivetrain.acEngine.p2p.enabled )
  {
    if ( this->drivetrain.acEngine.p2p.active )
    {
      v3->p2pStatus = 3;
    }
    else if ( this->drivetrain.acEngine.p2p.activations <= 0
           || this->drivetrain.acEngine.p2p.timeAccum <= this->drivetrain.acEngine.p2p.coolDownS )
    {
      v3->p2pStatus = 1;
    }
    else
    {
      v3->p2pStatus = 2;
    }
    v3->p2pActivations = this->drivetrain.acEngine.p2p.activations;
  }
  v4 = this->lockControlsTime - this->ksPhysics->physicsTime;
  v3->lockControlsTime = v4;
  v3->physicsGUID = this->physicsGUID;
  v3->water = this->water.t;
  v3->fuel = this->fuel;
  v3->fuelLaps = FuelLapEvaluator::getFuelLaps(&this->fuelLapEvaluator);
  v3->airDensity = v2->aeroMap.airDensity;
  v3->timeStamp = v2->ksPhysics->physicsTime;
  v3->groundPlane = (plane4f)_mm_loadu_si128((const __m128i *)Car::getGroundPlane(v2, &result));
  if ( v2->ers.present )
  {
    v5 = v2->ers.charge;
    v3->kersCharge = v5;
    v3->kersInput = v2->ers.input;
    v3->kersCurrentKJ = v2->ers.currentJ * 0.001;
    v3->kersIsCharging = v2->ers.isCharging;
  }
  else
  {
    v3->kersCharge = v2->kers.charge;
    v3->kersInput = v2->kers.input;
    v3->kersCurrentKJ = v2->kers.currentJ * 0.001;
  }
  LODWORD(v84) = &v2->drivetrain.acEngine;
  v3->turboBoostLevel = Engine::getTurboBoostLevel(&v2->drivetrain.acEngine);
  v3->turboBov = v2->drivetrain.acEngine.bov;
  v3->engineLifeLeft = v2->drivetrain.acEngine.lifeLeft;
  v95 = Drivetrain::getDrivetrainSpeed(&v2->drivetrain);
  LODWORD(v3->drivetrainSpeed) = LODWORD(v95) & _xmm;
  v3->turboBoost = v2->drivetrain.acEngine.status.turboBoost;
  v6 = 0.0;
  v95 = Drivetrain::getEngineRPM(&v2->drivetrain);
  v88 = 0.0;
  if ( v95 >= 0.0 )
  {
    v95 = Drivetrain::getEngineRPM(&v2->drivetrain);
    v6 = v95;
  }
  v3->engineRPM = v6;
  v3->lastFF_Pure = v2->lastFF;
  v7 = ((double (*)(ICarControlsProvider *))v2->controlsProvider->getFFGlobalGain)(v2->controlsProvider);
  v95 = v2->userFFGain * v2->lastFF;
  v3->lastFF_Final = v7 * v95;
  v3->normalizedSplinePosition = v2->splineLocatorData.npos;
  v8 = v2->driftMode.points;
  v3->driftPoints = v8;
  v3->instantDrift = v2->driftMode.instantDrift;
  v9 = !v2->driftMode.invalid && v2->driftMode.drifting;
  v3->isDriftValid = v9;
  v3->driftComboCounter = v2->driftMode.comboCounter;
  v3->driftBonusOn = v2->driftMode.extremeDrifting;
  PerformanceMeter::getCurrentSplit(&v2->performanceMeter, &v82);
  v10 = v82.t;
  v3->performanceMeter = v10;
  v3->performanceMeterSpeedDiffMS = v82.speedMS;
  v3->isGearGrinding = v2->drivetrain.isGearGrinding;
  v3->gearRpmWindow = Drivetrain::getRpmWindowStatus(&v2->drivetrain);
  v11 = 0;
  v3->damageZoneLevel[0] = v2->damageZoneLevel[0];
  LODWORD(v12) = -2804 - (_DWORD)v3;
  v3->damageZoneLevel[1] = v2->damageZoneLevel[1];
  v3->damageZoneLevel[2] = v2->damageZoneLevel[2];
  v3->damageZoneLevel[3] = v2->damageZoneLevel[3];
  v3->damageZoneLevel[4] = v2->damageZoneLevel[4];
  HIDWORD(v84) = v2->brakeSystem.discs;
  HIDWORD(v85) = v3->tyreContactNormal;
  LODWORD(v85) = v3->tyreSurfaceDef;
  v89 = (__m128i *)v3->suspensionMatrix;
  v92 = v3->wear;
  LODWORD(v95) = &v2->tyres[0].modelData.maxWearKM;
  v13 = v3->tyreThermalStates;
  index = 0;
  LODWORD(v14) = &v2->tyres[0].modelData.maxWearKM;
  v87 = v13;
  v86 = v12;
  do
  {
    Car::getTyreThermalState(v2, v11, v13);
    if ( *(float *)LODWORD(v14) == 0.0 )
    {
      v16 = v92;
      *v92 = -1.0;
    }
    else
    {
      v15 = *(double *)(LODWORD(v14) + 212) / *(float *)LODWORD(v14);
      if ( v15 >= 1.0 )
        v15 = DOUBLE_1_0;
      v16 = v92;
      *v92 = v15;
      v16[4] = *(float *)(LODWORD(v14) + 288);
    }
    *(v16 - 201) = *(double *)(LODWORD(v14) + 260);
    v17 = v2->suspensions._Myfirst;
    v93 = (int)v16 + LODWORD(v86);
    v18 = ((double (*)(_DWORD))*(_DWORD *)(**(_DWORD **)((char *)v17 + (_DWORD)v16 + LODWORD(v86)) + 68))(*(ISuspension **)((char *)v17 + (_DWORD)v16 + LODWORD(v86)));
    v19 = v92;
    v79 = index;
    *(v92 - 205) = v18;
    *(v19 - 212) = *(float *)(LODWORD(v14) + 252);
    v20 = *(double *)(LODWORD(v14) + 236);
    *(v19 - 222) = v20;
    *(v19 - 218) = *(double *)(LODWORD(v14) + 244);
    v21 = (const __m128i *)Car::getTyreMatrix(v2, &v81, v79);
    v22 = (unsigned int)index < 4;
    v23 = (int)v89;
    v89[16] = _mm_loadu_si128(v21);
    *(__m128i *)(v23 + 272) = _mm_loadu_si128(v21 + 1);
    *(__m128i *)(v23 + 288) = _mm_loadu_si128(v21 + 2);
    *(__m128i *)(v23 + 304) = _mm_loadu_si128(v21 + 3);
    if ( v22 )
    {
      (*(void (**)(_DWORD, mat44f *))(**(_DWORD **)((char *)v2->suspensions._Myfirst + v93) + 4))(
        *(ISuspension **)((char *)v2->suspensions._Myfirst + v93),
        &v81);
      v24 = _mm_loadu_si128((const __m128i *)&v81.M41);
      v23 = (int)v89;
      v25 = _mm_loadu_si128((const __m128i *)&v81.M31);
      v26 = _mm_loadu_si128((const __m128i *)&v81.M21);
      v27 = _mm_loadu_si128((const __m128i *)&v81);
    }
    else
    {
      v24 = 0i64;
      v27 = 0i64;
      v26 = 0i64;
      v25 = 0i64;
    }
    *(__m128i *)v23 = v27;
    *(__m128i *)(v23 + 16) = v26;
    *(__m128i *)(v23 + 32) = v25;
    *(__m128i *)(v23 + 48) = v24;
    if ( *(_BYTE *)(LODWORD(v14) + 144) || v2->sleepingFrames > v2->framesToSleep )
    {
      v28 = v92;
      *(v92 - 554) = 0.0;
    }
    else
    {
      v28 = v92;
      *(v92 - 554) = *(float *)(LODWORD(v14) + 128);
    }
    v29 = (index & 1) == 0;
    *(v28 - 524) = *(float *)(LODWORD(v14) + 148);
    *(v28 - 520) = *(float *)(LODWORD(v14) + 152);
    *(v28 - 516) = *(float *)(LODWORD(v14) + 112);
    *(v28 - 512) = *(float *)(LODWORD(v14) + 160);
    if ( v29 )
      *(v28 - 275) = *(float *)(LODWORD(v14) + 116);
    else
      *((_DWORD *)v28 - 275) = *(_DWORD *)(LODWORD(v14) + 116) ^ _xmm;
    *(v28 - 528) = *(float *)(LODWORD(v14) + 124);
    *(v28 - 508) = *(float *)(LODWORD(v14) + 140);
    v30 = *(const void **)(LODWORD(v14) + 396);
    if ( v30 )
    {
      qmemcpy((void *)v85, v30, 0xBCu);
      v2 = icar;
      v14 = v95;
    }
    v31 = HIDWORD(v85);
    *(v28 - 504) = *(float *)(LODWORD(v14) + 172);
    *(v28 - 532) = *(float *)(LODWORD(v14) + 120) * 57.29578;
    *(_QWORD *)(v31 - 48) = *(_QWORD *)(LODWORD(v14) + 372);
    *(_DWORD *)(v31 - 40) = *(_DWORD *)(LODWORD(v14) + 380);
    *(_QWORD *)v31 = *(_QWORD *)(LODWORD(v14) + 384);
    *(_DWORD *)(v31 + 8) = *(_DWORD *)(LODWORD(v14) + 392);
    v32 = v93;
    *(v28 - 271) = *(float *)(LODWORD(v14) - 404);
    *(v28 - 267) = *(float *)(LODWORD(v14) - 404) - *(float *)(LODWORD(v14) + 108);
    v33 = (int *)(*(int (**)(_DWORD))(**(_DWORD **)((char *)v2->suspensions._Myfirst + v32) + 36))(*(ISuspension **)((char *)v2->suspensions._Myfirst + v32));
    v34 = v92;
    ++v87;
    v11 = index + 1;
    v35 = *v33;
    HIDWORD(v85) += 12;
    v89 += 4;
    LODWORD(v85) = v85 + 188;
    *((_DWORD *)v92 - 263) = v35;
    v36 = *(double *)(LODWORD(v14) + 212);
    LODWORD(v14) += 1632;
    v37 = (float *)HIDWORD(v84);
    HIDWORD(v84) += 92;
    index = v11;
    v95 = v14;
    *(v34 - 247) = v36;
    *(v34 - 4) = *v37;
    v13 = v87;
    v92 = v34 + 1;
  }
  while ( v11 < 4 );
  v38 = (const __m128i *)((int (*)(IRigidBody *, mat44f *, _DWORD))v2->body->getWorldMatrix)(
                           v2->body,
                           &v81,
                           0);
  v39 = state;
  v40 = icar;
  *(__m128i *)&state->worldMatrix.M11 = _mm_loadu_si128(v38);
  *(__m128i *)&v39->worldMatrix.M21 = _mm_loadu_si128(v38 + 1);
  *(__m128i *)&v39->worldMatrix.M31 = _mm_loadu_si128(v38 + 2);
  *(__m128i *)&v39->worldMatrix.M41 = _mm_loadu_si128(v38 + 3);
  if ( v39->speed.value >= 2.0 || v40->setupManager.minimumHeight_m <= 0.0 )
  {
    v93 = 2;
    LODWORD(v95) = v39->rideHeight;
    state = (CarPhysicsState *)&v40->ridePickupPoint[0].z;
    do
    {
      v42 = (float *)((int (*)(IRigidBody *, mat44f *, _DWORD))v40->body->getWorldMatrix)(v40->body, &v81, 0);
      v43 = state;
      v44 = v39->groundPlane.normal.y;
      v45 = state[-1].caster[2];
      v46 = state[-1].caster[1];
      v47 = v42[1] * v46;
      v48 = (float)(v42[4] * v45) + (float)(*v42 * v46);
      v49 = v42[2] * v46;
      v50 = v39->groundPlane.normal.x;
      v51 = (float)(v48 + (float)(v42[8] * *(float *)&state->physicsGUID)) + v42[12];
      v52 = (float)((float)(v47 + (float)(v42[5] * v45)) + (float)(v42[9] * *(float *)&state->physicsGUID)) + v42[13];
      v53 = (float)(v49 + (float)(v42[6] * v45)) + (float)(v42[10] * *(float *)&state->physicsGUID);
      state = (CarPhysicsState *)LODWORD(v39->groundPlane.normal.z);
      v54 = v53 + v42[14];
      v55 = (float)((float)(v50 * 0.0) + (float)(v44 * -1.0)) + (float)(v39->groundPlane.normal.z * 0.0);
      if ( v55 == 0.0 )
        v56 = 0.0;
      else
        v56 = (float)((float)((float)((float)((float)((float)(v50 * v51) + (float)(v44 * v52))
                                            + (float)(*(float *)&state * v54))
                                    + v39->groundPlane.d)
                            * (float)(-1.0 / v55))
                    * -1.0)
            + v52;
      v57 = v95;
      state = (CarPhysicsState *)&v43->worldMatrix.M13;
      *(float *)LODWORD(v95) = v52 - v56;
      v29 = v93-- == 1;
      LODWORD(v95) = LODWORD(v57) + 4;
    }
    while ( !v29 );
  }
  else
  {
    RaceEngineer::RaceEngineer(&v90, v40);
    v96 = 0;
    v39->rideHeight[0] = RaceEngineer::evalFrontRideHeight(&v90);
    v41 = RaceEngineer::evalRearRideHeight(&v90);
    v96 = -1;
    v39->rideHeight[1] = v41;
    RaceEngineer::~RaceEngineer(&v90);
  }
  *(_QWORD *)&v39->accG.x = *(_QWORD *)&v40->accG.x;
  v39->accG.z = v40->accG.z;
  v39->steer = v40->steerLock * v40->controls.steer;
  v39->gas = v40->controls.gas;
  v39->brake = v40->controls.brake;
  v39->clutch = v40->controls.clutch;
  v39->gear = v40->drivetrain.currentGear;
  v39->speed = LODWORD(Car::getSpeed(v40, (Speed *)&state)->value);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&state);
  v40->body->getVelocity(v40->body, (vec3f *)&v90);
  v58 = v90.fuelPerLapEvaluated;
  *(_QWORD *)&v39->velocity.x = *(_QWORD *)&v90.__vftable;
  v39->velocity.z = v58;
  v40->body->getLocalVelocity(v40->body, (vec3f *)&v90);
  v59 = v90.fuelPerLapEvaluated;
  *(_QWORD *)&v39->localVelocity.x = *(_QWORD *)&v90.__vftable;
  v39->localVelocity.z = v59;
  v60 = (int)v40->body->getAngularVelocity(v40->body, (vec3f *)&v90);
  *(_QWORD *)&v39->angularVelocity.x = *(_QWORD *)v60;
  v39->angularVelocity.z = *(float *)(v60 + 8);
  v40->body->getLocalAngularVelocity(v40->body, (vec3f *)&v90);
  v61 = v90.fuelPerLapEvaluated;
  *(_QWORD *)&v39->localAngularVelocity.x = *(_QWORD *)&v90.__vftable;
  v39->localAngularVelocity.z = v61;
  v62 = v40->tyres;
  if ( v40->tyres == (Tyre *)&v40->suspensions )
  {
    v64 = 0.0;
  }
  else
  {
    do
    {
      v63 = v62->contactPoint.y;
      ++v62;
      v64 = v63 + v88;
      v88 = v64;
    }
    while ( v62 != (Tyre *)&v40->suspensions );
  }
  v65 = v40->body;
  v66 = v65->__vftable;
  v88 = v64 * 0.25;
  v67 = ((int (*)(IRigidBody *, RaceEngineer *, _DWORD))v66->getPosition)(v65, &v90, 0);
  v39->cgHeight = *(float *)(v67 + 4) - v88;
  v39->isEngineLimiterOn = v40->drivetrain.acEngine.isLimiterOn(&v40->drivetrain.acEngine);
  v68 = 0;
  v39->lapTime = v40->transponder.t;
  v39->lastLap = v40->transponder.lastLap;
  v39->bestLap = v40->transponder.bestLap;
  v39->lapCount = v40->transponder.lapCount;
  v39->aero.CD = v40->aeroMap.dynamicCD;
  v39->aero.CL_Front = v40->aeroMap.dynamicCL;
  v39->aero.CL_Rear = v40->aeroMap.dynamicCL;
  v39->bodyWorkVolume = 0.0;
  *(float *)&state = 0.0;
  do
  {
    v69 = *(int **)(&v68->physicsGUID + (unsigned int)v40->suspensions._Myfirst);
    v70 = ((int (*)(IRigidBody *, mat44f *, _DWORD))icar->body->getWorldMatrix)(icar->body, &v81, 0);
    v86 = *(float *)(v70 + 16);
    v95 = *(float *)(v70 + 20);
    v71 = *(int *)(v70 + 24);
    v72 = *v69;
    v93 = v71;
    v73 = (float *)(*(int (**)(int *, RaceEngineer *))(v72 + 80))(v69, &v90);
    v74 = icar->body->getVelocity(icar->body, &result.normal.y);
    state = (CarPhysicsState *)((char *)state + 4);
    v68 = state;
    v75 = v74->x - *v73;
    v76 = v74->y - v73[1];
    v77 = v74->z - v73[2];
    v40 = icar;
    v39->bodyWorkVolume = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                         (float)((float)(v75 * v86) + (float)(v76 * v95))
                                       + (float)(v77 * *(float *)&v93)) & _xmm)
                        + v39->bodyWorkVolume;
  }
  while ( (int)v68 < 16 );
  v39->limiterRPM = (*(int (**)(_DWORD))(*(_DWORD *)v84 + 4))(v84);
  v39->isRetired = v40->isRetired;
  v39->setupState = v40->setupManager.setupState;
  v39->actionsState.state = 0;
  if ( !v40->isControlsLocked && v40->ksPhysics->physicsTime > v40->lockControlsTime )
  {
    if ( v40->controlsProvider->getAction(v40->controlsProvider, eLookingLeft) )
      v39->actionsState.state |= 1u;
    else
      v39->actionsState.state &= 0xFFFFFFFE;
    if ( v40->controlsProvider->getAction(v40->controlsProvider, eLookingRight) )
      v39->actionsState.state |= 2u;
    else
      v39->actionsState.state &= 0xFFFFFFFD;
    if ( v40->controlsProvider->getAction(v40->controlsProvider, eHeadlightsSwitch) )
      v39->actionsState.state |= 0x10u;
    else
      v39->actionsState.state &= 0xFFFFFFEF;
    if ( v40->controlsProvider->getAction(v40->controlsProvider, eHeadlightsFlash) )
      v39->actionsState.state |= 0x400u;
    else
      v39->actionsState.state &= 0xFFFFFBFF;
    if ( v40->controlsProvider->getAction(v40->controlsProvider, eChangingCamera) )
      v39->actionsState.state |= 0x20u;
    else
      v39->actionsState.state &= 0xFFFFFFDF;
    if ( v40->controlsProvider->getAction(v40->controlsProvider, eHorn) )
      v39->actionsState.state |= 0x40u;
    else
      v39->actionsState.state &= 0xFFFFFFBF;
    if ( v40->controlsProvider->getAction(v40->controlsProvider, eLookingBack) )
      v39->actionsState.state |= 0x200u;
    else
      v39->actionsState.state &= 0xFFFFFDFF;
    if ( v40->controls.gearUp )
      v39->actionsState.state |= 0x80u;
    else
      v39->actionsState.state &= 0xFFFFFF7F;
    if ( v40->controls.gearDn )
      v39->actionsState.state |= 0x100u;
    else
      v39->actionsState.state &= 0xFFFFFEFF;
    if ( v40->controls.tcUp )
      v39->actionsState.state |= 0x800u;
    else
      v39->actionsState.state &= 0xFFFFF7FF;
    if ( v40->controls.tcDn )
      v39->actionsState.state |= 0x1000u;
    else
      v39->actionsState.state &= 0xFFFFEFFF;
    if ( v40->controls.absUp )
      v39->actionsState.state |= 0x2000u;
    else
      v39->actionsState.state &= 0xFFFFDFFF;
    if ( v40->controls.absDn )
      v39->actionsState.state |= 0x4000u;
    else
      v39->actionsState.state &= 0xFFFFBFFF;
    if ( v40->controls.turboUp )
      v39->actionsState.state |= 0x8000u;
    else
      v39->actionsState.state &= 0xFFFF7FFF;
    if ( v40->controls.turboDn )
      v39->actionsState.state |= 0x10000u;
    else
      v39->actionsState.state &= 0xFFFEFFFF;
    if ( v40->controls.brakeBalanceUp )
      v39->actionsState.state |= 0x20000u;
    else
      v39->actionsState.state &= 0xFFFDFFFF;
    if ( v40->controls.brakeBalanceDn )
      v39->actionsState.state |= 0x40000u;
    else
      v39->actionsState.state &= 0xFFFBFFFF;
    if ( v40->controls.drs )
      v39->actionsState.state |= 0x80000u;
    else
      v39->actionsState.state &= 0xFFF7FFFF;
    if ( v40->controls.kers )
      v39->actionsState.state |= 0x100000u;
    else
      v39->actionsState.state &= 0xFFEFFFFF;
    if ( v40->controls.engineBrakeUp )
      v39->actionsState.state |= 0x200000u;
    else
      v39->actionsState.state &= 0xFFDFFFFF;
    if ( v40->controls.engineBrakeDn )
      v39->actionsState.state |= (unsigned int)&_ImageBase;
    else
      v39->actionsState.state &= 0xFFBFFFFF;
    if ( v40->controls.MGUHMode )
      v39->actionsState.state |= 0x8000000u;
    else
      v39->actionsState.state &= 0xF7FFFFFF;
    if ( v40->controls.MGUKDeliveryUp )
      v39->actionsState.state |= (unsigned int)&loc_800000;
    else
      v39->actionsState.state &= 0xFF7FFFFF;
    if ( v40->controls.MGUKDeliveryDn )
      v39->actionsState.state |= (unsigned int)&unk_1000000;
    else
      v39->actionsState.state &= 0xFEFFFFFF;
    if ( v40->controls.MGUKRecoveryUp )
      v39->actionsState.state |= 0x2000000u;
    else
      v39->actionsState.state &= 0xFDFFFFFF;
    if ( v40->controls.MGUKRecoveryDn )
      v39->actionsState.state |= 0x4000000u;
    else
      v39->actionsState.state &= 0xFBFFFFFF;
  }
  if ( !v40->physicsGUID )
  {
    RaceEngineer::RaceEngineer(&v83, v40);
    v96 = 1;
    v39->antiSquat = RaceEngineer::getAntiSquat(&v83);
    v39->caster[0] = RaceEngineer::getCasterRAD(&v83, *v40->suspensions._Myfirst) * 57.29578;
    v78 = RaceEngineer::getCasterRAD(&v83, (ISuspension *)*((_DWORD *)v40->suspensions._Myfirst + 1));
    v96 = -1;
    v39->caster[1] = v78 * 57.29578;
    RaceEngineer::~RaceEngineer(&v83);
  }
}
PitStopTime *Car::getPitstopTime(Car *this, PitStopTime *result, float fuel_to_add, bool changeTyres, bool repairBody, bool repairEngine, bool repairSus, bool useRandomizer)
{
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v13; // xmm6_4
  float *v14; // eax
  int v15; // ecx
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  int i; // esi
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  PitStopTime *v23; // eax
  float v24; // [esp+0h] [ebp-8h]
  float resulta; // [esp+Ch] [ebp+4h]
  float changeTyresb; // [esp+14h] [ebp+Ch]
  float changeTyresa; // [esp+14h] [ebp+Ch]
  float useRandomizera; // [esp+24h] [ebp+1Ch]

  v9 = 0.0;
  v10 = 0.0;
  v24 = 0.0;
  v11 = 0.0;
  result->total = 0.0;
  result->tyres = 0.0;
  result->repair = 0.0;
  result->fuel = 0.0;
  resulta = 0.0;
  if ( useRandomizer )
  {
    v10 = 0.0;
    v11 = 0.0;
    v9 = (float)_rand() * 0.000030518509;
    v24 = v9;
  }
  if ( changeTyres )
    v10 = this->pitTimings.tyreChangeTimeSec + v9;
  v13 = this->pitTimings.fuelChangeTimeSec * fuel_to_add;
  useRandomizera = v13;
  if ( v13 > 0.0 )
  {
    v13 = v13 + v9;
    useRandomizera = v13;
  }
  result->tyres = v10;
  if ( v13 > v10 )
    v10 = v13;
  result->total = v10;
  if ( repairBody )
  {
    v14 = this->damageZoneLevel;
    v15 = 4;
    do
    {
      if ( *v14 > 0.0 )
      {
        v16 = *v14 * 0.0099999998;
        if ( v16 <= 1.0 )
        {
          if ( v16 < 0.0 )
            v16 = 0.0;
        }
        else
        {
          v16 = FLOAT_1_0;
        }
        v11 = v11 + (float)((float)((float)((float)(this->pitTimings.bodyRepairTimeSec - 2.0) * v16) + 2.0) + v9);
      }
      ++v14;
      --v15;
    }
    while ( v15 );
    resulta = v11;
  }
  if ( repairEngine )
  {
    v17 = this->drivetrain.acEngine.lifeLeft;
    if ( v17 < 1000.0 )
    {
      v18 = 1000.0 - v17;
      if ( (float)(1000.0 - v17) < 0.0 )
        v18 = 0.0;
      v11 = v11 + (float)((float)((float)(this->pitTimings.engineRepairTimeSec * v18) * 0.1) + v9);
      resulta = v11;
    }
  }
  if ( repairSus )
  {
    for ( i = 0; i < 4; ++i )
    {
      changeTyresb = this->suspensions._Myfirst[i]->getDamage(this->suspensions._Myfirst[i]);
      if ( changeTyresb <= 0.0 )
      {
        v11 = resulta;
      }
      else
      {
        v20 = FLOAT_1_0;
        changeTyresa = this->suspensions._Myfirst[i]->getDamage(this->suspensions._Myfirst[i]);
        v21 = changeTyresa;
        if ( changeTyresa > 1.0 || (v20 = 0.0, changeTyresa < 0.0) )
          v21 = v20;
        v11 = (float)((float)(this->pitTimings.suspRepairTimeSec * v21) + v24) + resulta;
        resulta = v11;
      }
    }
    v13 = useRandomizera;
  }
  v22 = result->total;
  result->repair = v11;
  if ( v22 <= v11 )
    v22 = v11;
  result->total = v22;
  v23 = result;
  result->fuel = v13;
  return v23;
}
float Car::getRestrictor(Car *this)
{
  return _roundf(this->drivetrain.acEngine.restrictor * 400.0);
}
Speed *Car::getSpeed(Car *this, Speed *result)
{
  Speed *v2; // eax

  v2 = result;
  LODWORD(result->value) = this->valueCache.speed;
  return v2;
}
double Car::getSteerFF(Car *this)
{
  ISuspension **v2; // eax
  ISuspension *v3; // esi
  int v4; // ecx
  double v5; // st7
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  PhysicsEngine *v9; // eax
  float v10; // xmm3_4
  float v11; // xmm4_4
  double v12; // xmm5_8
  float v13; // xmm3_4
  double v14; // xmm0_8
  double v15; // xmm1_8
  double v16; // xmm7_8
  double v17; // xmm4_8
  double v18; // xmm2_8
  double v19; // xmm6_8
  double v20; // xmm0_8
  float v21; // xmm2_4
  float v22; // xmm1_4
  float value; // xmm0_4
  double v24; // st7
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  ICarControlsProvider *v29; // eax
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v33; // [esp+10h] [ebp-14h]
  float v34; // [esp+10h] [ebp-14h]
  float v35; // [esp+14h] [ebp-10h]
  float v36; // [esp+14h] [ebp-10h]
  float v37; // [esp+14h] [ebp-10h]
  float v38; // [esp+18h] [ebp-Ch]
  double v39; // [esp+1Ch] [ebp-8h]

  v2 = this->suspensions._Myfirst;
  v3 = *v2;
  v35 = v2[1]->getSteerTorque(v2[1]);
  v5 = ((double (*)(ISuspension *))v3->getSteerTorque)(v3);
  v6 = this->steerLock * this->controls.steer;
  v7 = v6 - this->lastSteerPosition;
  LODWORD(v8) = LODWORD(this->steerRatio) & _xmm;
  v36 = v5 + v35;
  v9 = this->ksPhysics;
  this->mzCurrent = (float)((float)(this->mzCurrent - v36) * this->controlsProvider->ffFilter) + v36;
  v10 = this->mzCurrent;
  v11 = (float)((float)((float)(v7 * 333.33334) / v8)
              * (float)((float)(COERCE_FLOAT(LODWORD(this->tyres[1].status.angularVelocity) & _xmm)
                              + COERCE_FLOAT(LODWORD(this->tyres[0].status.angularVelocity) & _xmm))
                      * this->tyres[0].data.angularInertia))
      * v9->gyroWheelGain;
  this->lastSteerPosition = v6;
  this->lastPureMZFF = v10 * 1.4;
  v12 = this->tyres[0].status.flatSpot;
  v13 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v10 + v11) ^ _xmm) * 1.4;
  v38 = v11;
  v39 = v12;
  v33 = v13;
  if ( v12 <= this->tyres[1].status.flatSpot )
  {
    v12 = this->tyres[1].status.flatSpot;
    v39 = v12;
  }
  v14 = this->tyres[0].status.blister;
  v15 = this->tyres[1].status.blister;
  if ( v14 <= v15 )
    v16 = this->tyres[1].status.blister;
  else
    v16 = this->tyres[0].status.blister;
  v17 = this->tyres[2].status.blister;
  v18 = this->tyres[3].status.blister;
  if ( v17 <= v18 )
    v19 = this->tyres[3].status.blister;
  else
    v19 = this->tyres[2].status.blister;
  if ( v16 <= v19 )
  {
    if ( v17 <= v18 )
      v14 = this->tyres[3].status.blister;
    else
      v14 = this->tyres[2].status.blister;
  }
  else if ( v14 <= v15 )
  {
    v14 = this->tyres[1].status.blister;
  }
  v20 = v14 * 0.003;
  if ( v12 <= v20 )
    v39 = v20;
  v21 = FLOAT_1_0;
  v22 = COERCE_FLOAT(LODWORD(this->tyres[0].status.angularVelocity) & _xmm)
      + COERCE_FLOAT(LODWORD(this->tyres[1].status.angularVelocity) & _xmm);
  value = (float)(v22 * 0.003) + this->flatSpotPhase;
  this->flatSpotPhase = value;
  if ( v22 > 7.0 )
  {
    v24 = ksSawToothWave(value, 12.56636);
    v21 = FLOAT_1_0;
    v25 = v39;
    v37 = v24;
    v13 = (float)((float)((float)((float)((float)(v37 * v25) * (float)this->ksPhysics->flatSpotFFGain)
                                * (float)(this->tyres[1].status.load + this->tyres[0].status.load))
                        * 0.5)
                + 1.0)
        + v13;
    v33 = (float)((float)((float)((float)((float)(v37 * v25) * (float)this->ksPhysics->flatSpotFFGain)
                                * (float)(this->tyres[1].status.load + this->tyres[0].status.load))
                        * 0.5)
                + 1.0)
        + v33;
  }
  v26 = 0.0;
  if ( this->steerAssist == v21 )
  {
    LODWORD(v34) = COERCE_UNSIGNED_INT(this->ffMult * v13) ^ _xmm;
  }
  else
  {
    v21 = FLOAT_1_0;
    LODWORD(v27) = __libm_sse2_powf(v4).m128_u32[0];
    v26 = 0.0;
    if ( v33 <= 0.0 )
    {
      if ( v33 >= 0.0 )
        v28 = 0.0;
      else
        v28 = FLOAT_N1_0;
    }
    else
    {
      v28 = FLOAT_1_0;
    }
    LODWORD(v34) = COERCE_UNSIGNED_INT(v28 * v27) ^ _xmm;
  }
  v29 = this->controlsProvider;
  this->lastGyroFF = v38 * 1.4;
  if ( !v29 || !v29->useFakeUndersteerFF )
    return v34;
  v30 = (float)((float)(this->tyres[1].status.ndSlip + this->tyres[0].status.ndSlip) * 0.5) - v21;
  if ( v30 <= v21 )
  {
    if ( v30 >= 0.0 )
      v31 = (float)((float)(this->tyres[1].status.ndSlip + this->tyres[0].status.ndSlip) * 0.5) - v21;
    else
      v31 = 0.0;
  }
  else
  {
    v31 = v21;
  }
  if ( (float)((float)(v31 * 5.5) + v21) > 2.5 )
    return v34 / 2.5;
  if ( v30 <= v21 )
  {
    if ( v30 >= 0.0 )
      v26 = (float)((float)(this->tyres[1].status.ndSlip + this->tyres[0].status.ndSlip) * 0.5) - v21;
  }
  else
  {
    v26 = v21;
  }
  return v34 / (float)((float)(v26 * 5.5) + v21);
}
mat44f *Car::getSuspensionMatrix(Car *this, mat44f *result, unsigned int index)
{
  ISuspension *v3; // ecx

  if ( index >= 4 )
  {
    mat44f::mat44f(result);
  }
  else
  {
    v3 = this->suspensions._Myfirst[index];
    v3->getHubWorldMatrix(v3, result);
  }
  return result;
}
long double Car::getTotalKM(Car *this)
{
  return this->fuelLapEvaluator.totalM * 0.001;
}
double Car::getTotalMass(Car *this, bool withFuel)
{
  ISuspension **v2; // eax
  ISuspension *v3; // edi
  ISuspension *v4; // ebx
  ISuspension *v5; // ebp
  ISuspension *v6; // esi
  double result; // st7
  IRigidBody *v8; // esi
  float withFuela; // [esp+18h] [ebp+4h]
  float withFuelb; // [esp+18h] [ebp+4h]
  float withFuelc; // [esp+18h] [ebp+4h]
  float withFueld; // [esp+18h] [ebp+4h]
  float withFuele; // [esp+18h] [ebp+4h]
  float withFuelf; // [esp+18h] [ebp+4h]
  float withFuelg; // [esp+18h] [ebp+4h]
  float withFuelh; // [esp+18h] [ebp+4h]

  v2 = this->suspensions._Myfirst;
  v3 = v2[1];
  v4 = v2[2];
  v5 = v2[3];
  if ( withFuel )
  {
    v6 = *v2;
    withFuela = this->body->getMass(this->body);
    withFuelb = ((double (*)(ISuspension *))v6->getMass)(v6) + withFuela;
    withFuelc = ((double (*)(ISuspension *))v3->getMass)(v3) + withFuelb;
    withFueld = ((double (*)(ISuspension *))v4->getMass)(v4) + withFuelc;
    result = ((double (*)(ISuspension *))v5->getMass)(v5) + withFueld + this->fuel * this->fuelKG;
  }
  else
  {
    v8 = this->body;
    withFuele = (*v2)->getMass(*v2);
    withFuelf = ((double (*)(IRigidBody *))v8->getMass)(v8) + withFuele;
    withFuelg = ((double (*)(ISuspension *))v3->getMass)(v3) + withFuelf;
    withFuelh = ((double (*)(ISuspension *))v4->getMass)(v4) + withFuelg;
    result = ((double (*)(ISuspension *))v5->getMass)(v5) + withFuelh;
  }
  return result;
}
mat44f *Car::getTyreMatrix(Car *this, mat44f *result, int index)
{
  ISuspension *v4; // ecx
  mat44f *v5; // eax
  mat44f *v6; // eax
  float v7; // [esp+8h] [ebp-8Ch]
  float v8; // [esp+Ch] [ebp-88h]
  float v9; // [esp+10h] [ebp-84h]
  mat44f m; // [esp+14h] [ebp-80h] BYREF
  mat44f v11; // [esp+54h] [ebp-40h] BYREF

  if ( index >= 4 )
  {
    mat44f::mat44f(result);
    v6 = result;
  }
  else
  {
    v4 = this->suspensions._Myfirst[index];
    v5 = v4->getHubWorldMatrix(v4, &v11);
    v8 = v5->M41;
    v9 = v5->M42;
    v7 = v5->M43;
    Tyre::getFinalTyreRotation(&this->tyres[index], &m);
    v6 = result;
    m.M41 = v8;
    m.M42 = v9;
    m.M43 = v7;
    *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&m);
    *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&m.M21);
    *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&m.M31);
    *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&m.M41);
  }
  return v6;
}
void Car::getTyreThermalState(Car *this, int index, TyreThermalState *state)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ebp
  TyreThermalState *v7; // eax
  TyreThermalModel *v8; // ebx
  int v9; // esi
  TyreThermalState *v10; // edi
  TyreThermalPatch *v11; // eax
  int v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+18h] [ebp-Ch]
  Car *v14; // [esp+1Ch] [ebp-8h]
  int v15; // [esp+20h] [ebp-4h]
  TyreThermalState *indexa; // [esp+28h] [ebp+4h]

  v4 = 0;
  v14 = this;
  v12 = 0;
  v5 = index % 2;
  v6 = 2;
  v13 = index % 2;
  v15 = index;
  v7 = state;
  v8 = &this->tyres[index].thermalModel;
  indexa = state;
  do
  {
    v9 = 0;
    v10 = v7;
    do
    {
      if ( v5 )
        v11 = TyreThermalModel::getPatchAt(v8, v4, v9);
      else
        v11 = TyreThermalModel::getPatchAt(v8, v6, v9);
      v4 = v12;
      ++v9;
      v5 = v13;
      v10->temps[0][0] = v11->T;
      v10 = (TyreThermalState *)((char *)v10 + 12);
    }
    while ( v9 < 12 );
    v4 = v12 + 1;
    v7 = (TyreThermalState *)&indexa->temps[0][1];
    ++v12;
    --v6;
    indexa = (TyreThermalState *)((char *)indexa + 4);
  }
  while ( v6 > -1 );
  state->coreTemp = v14->tyres[v15].thermalModel.coreTemp;
  state->thermalInput = (float)(v14->ksPhysics->roadTemperature + v14->tyres[v15].status.thermalInput) * 0.07692308;
  state->dynamicPressure = v14->tyres[v15].status.pressureDynamic;
  state->staticPressure = v14->tyres[v15].status.pressureStatic;
  state->cpTemperature = TyreThermalModel::getCurrentCPTemp(v8, v14->tyres[v15].status.camberRAD);
  *(_QWORD *)state->lastSetIMO = *(_QWORD *)v14->tyres[v15].status.lastTempIMO;
  state->lastSetIMO[2] = v14->tyres[v15].status.lastTempIMO[2];
  state->lastGrain = v14->tyres[v15].status.lastGrain;
  state->lastBlister = v14->tyres[v15].status.lastBlister;
  state->mult = v14->tyres[v15].thermalModel.thermalMultD;
  state->isHot = v14->tyres[v15].thermalModel.practicalTemp >= v14->tyres[v15].data.blisterThreshold;
}
vec3f *Car::getVelocity(Car *this, vec3f *result)
{
  this->body->getVelocity(this->body, result);
  return result;
}
double Car::getWheelSterAngleDEG(Car *this, int index)
{
  float v2; // xmm0_4
  IRigidBody *v3; // ecx
  int v4; // eax
  vec3f v6; // [esp+0h] [ebp-18h] BYREF
  __int64 v7; // [esp+Ch] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-4h]

  LODWORD(v7) = LODWORD(this->tyres[index].worldRotation.M31) ^ _xmm;
  HIDWORD(v7) = LODWORD(this->tyres[index].worldRotation.M32) ^ _xmm;
  v2 = this->tyres[index].worldRotation.M33;
  v3 = this->body;
  v8 = LODWORD(v2) ^ _xmm;
  v4 = (int)v3->worldToLocalNormal(v3, &v6, (const vec3f *)&v7);
  v7 = *(_QWORD *)v4;
  v8 = *(_DWORD *)(v4 + 8);
  return (float)(__libm_sse2_asinf().m128_f32[0] * 57.29578);
}
void Car::getWingState(Car *this, std::vector<WingState> *ws)
{
  std::vector<WingState> *v2; // eax
  std::vector<WingState> result; // [esp+4h] [ebp-18h] BYREF
  int v4; // [esp+18h] [ebp-4h]

  v2 = AeroMap::getWingStatus(&this->aeroMap, &result);
  v4 = 0;
  std::vector<WingState>::operator=(ws, v2);
  v4 = -1;
  if ( result._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&result);
    operator delete(result._Myfirst);
  }
}
void Car::initAeroMap(Car *this)
{
  ISuspension **v2; // eax
  std::wstring v3; // [esp-18h] [ebp-38h] BYREF
  vec3f rearAP; // [esp+8h] [ebp-18h] BYREF
  vec3f frontAP; // [esp+14h] [ebp-Ch] BYREF

  (*(void (**)(ISuspension *, vec3f *))(**(_DWORD **)this->suspensions._Myfirst + 40))(
    *this->suspensions._Myfirst,
    &frontAP);
  v2 = this->suspensions._Myfirst;
  frontAP.x = 0.0;
  frontAP.y = 0.0;
  v2[2]->getBasePosition(v2[2], &rearAP);
  rearAP.x = 0.0;
  rearAP.y = 0.0;
  v3._Myres = 7;
  v3._Mysize = 0;
  v3._Bx._Buf[0] = 0;
  std::wstring::assign(&v3, &this->carDataPath, 0, 0xFFFFFFFF);
  AeroMap::init(&this->aeroMap, this, &frontAP, &rearAP, v3);
  DRS::init(&this->drs, this);
}
void Car::initCarData(Car *this)
{
  const std::wstring *v2; // eax
  const std::wstring *v3; // eax
  std::wstring *v4; // ebx
  std::wstring *v5; // edi
  double v6; // st7
  bool v7; // cf
  bool v8; // bl
  vec3f *v9; // eax
  vec3f *v10; // eax
  bool v11; // bl
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  float v17; // xmm0_4
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // xmm1_8
  double v23; // st7
  double v24; // st7
  unsigned __int64 v25; // xmm1_8
  vec3f *v26; // eax
  IRigidBody *v27; // ecx
  IPhysicsCore *v28; // eax
  unsigned int v29; // [esp+4Ch] [ebp-124h]
  unsigned int v30; // [esp+4Ch] [ebp-124h]
  __int64 v31; // [esp+50h] [ebp-120h] BYREF
  vec3f li; // [esp+5Ch] [ebp-114h] BYREF
  std::wstring v33; // [esp+68h] [ebp-108h] BYREF
  std::wstring key; // [esp+80h] [ebp-F0h] BYREF
  std::wstring section; // [esp+98h] [ebp-D8h] BYREF
  INIReader r; // [esp+B0h] [ebp-C0h] BYREF
  std::wstring v37; // [esp+FCh] [ebp-74h] BYREF
  std::wstring result; // [esp+114h] [ebp-5Ch] BYREF
  int v39; // [esp+16Ch] [ebp-4h]

  v2 = std::operator+<wchar_t>(&result, &this->carDataPath, L"car.ini");
  v39 = 0;
  v3 = Car::getConfigPath(this, &v37, v2);
  LOBYTE(v39) = 1;
  INIReader::INIReader(&r, v3);
  if ( v37._Myres >= 8 )
    operator delete(v37._Bx._Ptr);
  v37._Myres = 7;
  v37._Mysize = 0;
  v37._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SCREEN_NAME", 0xBu);
  LOBYTE(v39) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"INFO", 4u);
  LOBYTE(v39) = 6;
  v4 = INIReader::getString(&r, &v33, &section, &key);
  v5 = &this->screenName;
  if ( &this->screenName != v4 )
  {
    if ( this->screenName._Myres >= 8 )
      operator delete(v5->_Bx._Ptr);
    this->screenName._Myres = 7;
    this->screenName._Mysize = 0;
    v5->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->screenName, v4);
  }
  if ( v33._Myres >= 8 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TOTALMASS", 9u);
  LOBYTE(v39) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v39) = 8;
  v6 = INIReader::getFloat(&r, &section, &key);
  v7 = section._Myres < 8;
  this->mass = v6;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"EXPLICIT_INERTIA", 0x10u);
  LOBYTE(v39) = 9;
  v8 = INIReader::hasSection(&r, &key);
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  std::wstring::assign(&v33, L"INERTIA", 7u);
  if ( v8 )
  {
    LOBYTE(v39) = 10;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"EXPLICIT_INERTIA", 0x10u);
    LOBYTE(v39) = 11;
    v9 = INIReader::getFloat3(&r, (vec3f *)&section, &key, &v33);
    v7 = key._Myres < 8;
    this->explicitInertia = *v9;
    if ( !v7 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v39) = 4;
    if ( v33._Myres >= 8 )
      operator delete(v33._Bx._Ptr);
    ((void (*)(IRigidBody *, _DWORD, _DWORD, _DWORD, _DWORD))this->body->setMassExplicitInertia)(
      this->body,
      LODWORD(this->mass),
      LODWORD(this->explicitInertia.x),
      LODWORD(this->explicitInertia.y),
      LODWORD(this->explicitInertia.z));
  }
  else
  {
    LOBYTE(v39) = 12;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BASIC", 5u);
    LOBYTE(v39) = 13;
    v10 = INIReader::getFloat3(&r, (vec3f *)&section, &key, &v33);
    v7 = key._Myres < 8;
    this->bodyInertia = *v10;
    if ( !v7 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v39) = 4;
    if ( v33._Myres >= 8 )
      operator delete(v33._Bx._Ptr);
    ((void (*)(IRigidBody *, _DWORD, _DWORD, _DWORD, _DWORD))this->body->setMassBox)(
      this->body,
      LODWORD(this->mass),
      LODWORD(this->bodyInertia.x),
      LODWORD(this->bodyInertia.y),
      LODWORD(this->bodyInertia.z));
  }
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  std::wstring::assign(&v33, L"FUEL_EXT", 8u);
  LOBYTE(v39) = 14;
  v11 = INIReader::hasSection(&r, &v33);
  LOBYTE(v39) = 4;
  if ( v33._Myres >= 8 )
    operator delete(v33._Bx._Ptr);
  if ( v11 )
  {
    v33._Myres = 7;
    v33._Mysize = 0;
    v33._Bx._Buf[0] = 0;
    std::wstring::assign(&v33, L"KG_PER_LITER", 0xCu);
    LOBYTE(v39) = 15;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FUEL_EXT", 8u);
    LOBYTE(v39) = 16;
    v12 = INIReader::getFloat(&r, &key, &v33);
    v7 = key._Myres < 8;
    this->fuelKG = v12;
    if ( !v7 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v39) = 4;
    if ( v33._Myres >= 8 )
      operator delete(v33._Bx._Ptr);
    _printf("Using fuelKG: %f\n", this->fuelKG);
  }
  this->body->getLocalInertia(this->body, &li);
  _printf("LOCAL INERTIA: %f %f %f\n", li.x, li.y, li.z);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  std::wstring::assign(&v33, L"FFMULT", 6u);
  LOBYTE(v39) = 17;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CONTROLS", 8u);
  LOBYTE(v39) = 18;
  v13 = INIReader::getFloat(&r, &key, &v33);
  v7 = key._Myres < 8;
  this->ffMult = v13 * 0.001;
  if ( !v7 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( v33._Myres >= 8 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  std::wstring::assign(&v33, L"STEER_LOCK", 0xAu);
  LOBYTE(v39) = 19;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CONTROLS", 8u);
  LOBYTE(v39) = 20;
  v14 = INIReader::getFloat(&r, &key, &v33);
  v7 = key._Myres < 8;
  this->steerLock = v14;
  if ( !v7 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( v33._Myres >= 8 )
    operator delete(v33._Bx._Ptr);
  std::wstring::wstring(&key, L"STEER_RATIO");
  LOBYTE(v39) = 21;
  std::wstring::wstring(&v33, L"CONTROLS");
  LOBYTE(v39) = 22;
  v15 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  this->steerRatio = v15;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"LINEAR_STEER_ROD_RATIO");
  LOBYTE(v39) = 23;
  std::wstring::wstring(&v33, L"CONTROLS");
  LOBYTE(v39) = 24;
  v16 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  this->steerLinearRatio = v16;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v17 = this->steerLinearRatio;
  v31 = 0i64;
  if ( v17 == 0.0 )
    this->steerLinearRatio = 0.003;
  std::wstring::wstring(&key, L"STEER_ASSIST");
  LOBYTE(v39) = 25;
  std::wstring::wstring(&v33, L"CONTROLS");
  LOBYTE(v39) = 26;
  v18 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  this->steerAssist = v18;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->steerAssist == *(float *)&v31 )
    this->steerAssist = 1.0;
  std::wstring::wstring(&key, L"CONSUMPTION");
  LOBYTE(v39) = 27;
  std::wstring::wstring(&v33, L"FUEL");
  LOBYTE(v39) = 28;
  v19 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  this->fuelConsumptionK = v19;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"FUEL");
  LOBYTE(v39) = 29;
  std::wstring::wstring(&v33, L"FUEL");
  LOBYTE(v39) = 30;
  v20 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  this->fuel = v20;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"MAX_FUEL");
  LOBYTE(v39) = 31;
  std::wstring::wstring(&v33, L"FUEL");
  LOBYTE(v39) = 32;
  v21 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  this->maxFuel = v21;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->maxFuel == 0.0 )
    this->maxFuel = DOUBLE_30_0;
  v22 = this->fuel;
  if ( v22 == 0.0 )
  {
    this->fuel = DOUBLE_30_0;
    this->requestedFuel = 30.0;
  }
  else
  {
    this->requestedFuel = v22;
  }
  std::wstring::wstring(&key, L"PICKUP_FRONT_HEIGHT");
  LOBYTE(v39) = 33;
  std::wstring::wstring(&v33, L"RIDE");
  LOBYTE(v39) = 34;
  v23 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  *(float *)&v29 = v23;
  *(_DWORD *)&section._Bx._Alias[8] = 0;
  *(_QWORD *)&this->ridePickupPoint[0].x = _mm_unpacklo_ps((__m128)(unsigned int)v31, (__m128)v29).m128_u64[0];
  this->ridePickupPoint[0].z = 0.0;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"PICKUP_REAR_HEIGHT");
  LOBYTE(v39) = 35;
  std::wstring::wstring(&v33, L"RIDE");
  LOBYTE(v39) = 36;
  v24 = INIReader::getFloat(&r, &v33, &key);
  v7 = v33._Myres < 8;
  *(float *)&v30 = v24;
  v25 = _mm_unpacklo_ps((__m128)_mm_loadl_epi64((const __m128i *)&v31), (__m128)v30).m128_u64[0];
  *(_DWORD *)&section._Bx._Alias[8] = 0;
  *(_QWORD *)&this->ridePickupPoint[1].x = v25;
  this->ridePickupPoint[1].z = 0.0;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  std::wstring::wstring(&key, L"POSITION");
  LOBYTE(v39) = 37;
  std::wstring::wstring(&v33, L"FUELTANK");
  LOBYTE(v39) = 38;
  v26 = INIReader::getFloat3(&r, (vec3f *)&section, &v33, &key);
  v7 = v33._Myres < 8;
  this->fuelTankPos = *v26;
  if ( !v7 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v39) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v27 = this->fuelTankBody;
  key._Myres = 7;
  key._Bx._Buf[0] = 0;
  key._Mysize = 0;
  ((void (*)(IRigidBody *, int, int, int, int))v27->setMassBox)(
    v27,
    1065353216,
    1056964608,
    1056964608,
    1056964608);
  this->fuelTankBody->setPosition(this->fuelTankBody, &this->fuelTankPos);
  v28 = PhysicsEngine::getCore(this->ksPhysics);
  this->fuelTankJoint = v28->createFixedJoint(v28, this->fuelTankBody, this->body);
  this->water.tmass = 20.0;
  this->water.coolSpeedK = 0.0020000001;
  Car::initPitstopTimings(this);
  v39 = -1;
  INIReader::~INIReader(&r);
}
void Car::initCarDataPath(Car *this)
{
  std::wstring *v2; // eax
  std::wstring *v3; // edi
  std::wstring *v4; // esi
  std::wstring _Left; // [esp+Ch] [ebp-58h] BYREF
  std::wstring v6; // [esp+24h] [ebp-40h] BYREF
  std::wstring result; // [esp+3Ch] [ebp-28h] BYREF
  int v8; // [esp+60h] [ebp-4h]

  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v8 = 0;
  v2 = std::operator+<wchar_t>(&result, &_Left, &this->unixName);
  LOBYTE(v8) = 1;
  v3 = std::operator+<wchar_t>(&v6, v2, L"/data/");
  v4 = &this->carDataPath;
  if ( v4 != v3 )
  {
    if ( v4->_Myres >= 8 )
      operator delete(v4->_Bx._Ptr);
    v4->_Myres = 7;
    v4->_Mysize = 0;
    v4->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(v4, v3);
  }
  if ( v6._Myres >= 8 )
    operator delete(v6._Bx._Ptr);
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  if ( v4->_Myres >= 8 )
    v4 = (std::wstring *)v4->_Bx._Ptr;
  _printf("Data path: %S\n", v4->_Bx._Buf);
}
void Car::initColliderMesh(Car *this, Mesh *mesh, mat44f *bodyMatrix)
{
  Mesh *v3; // edi
  int v4; // ecx
  MeshVertex *v5; // ecx
  __m128 v6; // xmm0
  float v7; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  int v10; // esi
  float v11; // xmm5_4
  int v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm3_4
  vec3f *v15; // edi
  Mesh *v16; // edx
  MeshVertex *v17; // eoff
  float v18; // xmm2_4
  float v19; // xmm1_4
  unsigned int v20; // edx
  Car *v21; // ecx
  __m128 v22; // xmm2
  float v23; // xmm3_4
  __m128 v24; // xmm1
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  __m128 v29; // xmm0
  float v30; // xmm6_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  __m128i v33; // xmm0
  __m128i v34; // [esp-14h] [ebp-E8h]
  __m128i v35; // [esp-4h] [ebp-D8h]
  __m128i v36; // [esp+Ch] [ebp-C8h]
  int v37; // [esp+34h] [ebp-A0h]
  float v38; // [esp+4Ch] [ebp-88h]
  float v39; // [esp+58h] [ebp-7Ch]
  std::vector<vec3f> v40; // [esp+5Ch] [ebp-78h] BYREF
  unsigned int v41; // [esp+68h] [ebp-6Ch]
  float v42; // [esp+6Ch] [ebp-68h]
  Car *v43; // [esp+70h] [ebp-64h]
  float v44; // [esp+74h] [ebp-60h]
  Mesh *v45; // [esp+78h] [ebp-5Ch]
  float v46; // [esp+7Ch] [ebp-58h]
  int v47; // [esp+80h] [ebp-54h]
  DebugTimer v48; // [esp+84h] [ebp-50h] BYREF
  std::wstring iname; // [esp+ACh] [ebp-28h] BYREF
  int v50; // [esp+D0h] [ebp-4h]

  v43 = this;
  v3 = mesh;
  v45 = mesh;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Car::initColliderMesh", 0x15u);
  v50 = 0;
  DebugTimer::DebugTimer(&v48, &iname);
  LOBYTE(v50) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v4 = (char *)mesh->vertices._Mylast - (char *)mesh->vertices._Myfirst;
  iname._Bx._Buf[0] = 0;
  iname._Myres = 7;
  iname._Mysize = 0;
  std::vector<vec3f>::vector<vec3f>(&v40, v4 / 44);
  v5 = mesh->vertices._Myfirst;
  LOBYTE(v50) = 3;
  v6.m128_u64[0] = *(_QWORD *)&v5->pos.x;
  v7 = v5->pos.z;
  v41 = 0;
  v8 = v6.m128_f32[1];
  if ( mesh->vertices._Mylast - mesh->vertices._Myfirst )
  {
    v9 = v7;
    v10 = 0;
    v11 = v6.m128_f32[1];
    v12 = 0;
    v13 = v6.m128_f32[0];
    v14 = v6.m128_f32[0];
    v15 = v40._Myfirst;
    v42 = v7;
    v44 = v6.m128_f32[1];
    v46 = v6.m128_f32[0];
    v47 = v6.m128_i32[0];
    while ( 1 )
    {
      v16 = v45;
      v17 = &v45->vertices._Myfirst[v12];
      *(_QWORD *)&v15[v10].x = *(_QWORD *)&v17->pos.x;
      v15[v10].z = v17->pos.z;
      v15 = v40._Myfirst;
      v18 = v40._Myfirst[v10].x;
      if ( v18 <= v13 )
        v46 = v40._Myfirst[v10].x;
      v19 = v40._Myfirst[v10].y;
      if ( v19 <= v11 )
        v11 = v40._Myfirst[v10].y;
      v6 = (__m128)LODWORD(v40._Myfirst[v10].z);
      if ( v6.m128_f32[0] <= v9 )
        v9 = v40._Myfirst[v10].z;
      if ( v14 <= v18 )
        v14 = v18;
      if ( v8 <= v19 )
        v8 = v40._Myfirst[v10].y;
      if ( v7 <= v6.m128_f32[0] )
        v7 = v40._Myfirst[v10].z;
      ++v41;
      v47 = v12 * 44 + 44;
      ++v10;
      ++v12;
      v20 = (int)((unsigned __int64)(780903145i64 * ((char *)v16->vertices._Mylast - (char *)v16->vertices._Myfirst)) >> 32) >> 3;
      if ( v41 >= v20 + (v20 >> 31) )
        break;
      v13 = v46;
    }
    v3 = v45;
    v6.m128_f32[0] = v14;
    v42 = v9;
    v44 = v11;
    v47 = LODWORD(v14);
  }
  else
  {
    v42 = v7;
    v44 = v6.m128_f32[1];
    v46 = v6.m128_f32[0];
    v6 = (__m128)v6.m128_u32[0];
  }
  v21 = v43;
  v22 = (__m128)LODWORD(bodyMatrix->M42);
  v23 = bodyMatrix->M41 + v46;
  v24 = v22;
  v22.m128_f32[0] = v22.m128_f32[0] + v44;
  v24.m128_f32[0] = v24.m128_f32[0] + v8;
  v25 = bodyMatrix->M43;
  v26 = v25 + v42;
  v27 = v25 + v7;
  v6.m128_f32[0] = bodyMatrix->M41 + v6.m128_f32[0];
  v28 = v6.m128_f32[0] - v23;
  v29 = _mm_unpacklo_ps(v6, v24);
  *(_QWORD *)&v43->bounds.max.x = v29.m128_u64[0];
  v29.m128_f32[0] = v23;
  *(_QWORD *)&v21->bounds.min.x = _mm_unpacklo_ps(v29, v22).m128_u64[0];
  v24.m128_f32[0] = v27 - v26;
  LODWORD(v30) = LODWORD(v28) & _xmm;
  v39 = v26;
  LODWORD(v31) = LODWORD(v26) & _xmm;
  v38 = v27;
  LODWORD(v32) = LODWORD(v27) & _xmm;
  v24.m128_i32[0] &= _xmm;
  v21->bounds.max.z = v38;
  v21->bounds.min.z = v39;
  LODWORD(v21->bounds.length) = v24.m128_i32[0];
  v21->bounds.width = v30;
  v21->bounds.lengthFront = v32;
  v21->bounds.lengthRear = v31;
  _printf("Car bounds L: %f W:%f , front: %f rear: %f\n", v24.m128_f32[0], v30, v32, v31);
  v37 = v43->physicsGUID + 1;
  v34 = _mm_loadu_si128((const __m128i *)bodyMatrix);
  v35 = _mm_loadu_si128((const __m128i *)&bodyMatrix->M21);
  v36 = _mm_loadu_si128((const __m128i *)&bodyMatrix->M31);
  v33 = _mm_loadu_si128((const __m128i *)&bodyMatrix->M41);
  v47 = v3->indices._Mylast - v3->indices._Myfirst;
  ((void (*)(IRigidBody *, vec3f *, int, unsigned __int16 *, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int))v43->body->addMeshCollider)(
    v43->body,
    v40._Myfirst,
    v40._Mylast - v40._Myfirst,
    v45->indices._Myfirst,
    v47,
    v34.m128i_i32[0],
    v34.m128i_i32[1],
    v34.m128i_i32[2],
    v34.m128i_i32[3],
    v35.m128i_i32[0],
    v35.m128i_i32[1],
    v35.m128i_i32[2],
    v35.m128i_i32[3],
    v36.m128i_i32[0],
    v36.m128i_i32[1],
    v36.m128i_i32[2],
    v36.m128i_i32[3],
    v33.m128i_i32[0],
    v33.m128i_i32[1],
    v33.m128i_i32[2],
    v33.m128i_i32[3],
    4,
    30,
    v37);
  LOBYTE(v50) = 2;
  if ( v40._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v40);
    operator delete(v40._Myfirst);
    v40._Myfirst = 0;
    v40._Mylast = 0;
    v40._Myend = 0;
  }
  v50 = -1;
  DebugTimer::~DebugTimer(&v48);
}
void Car::initHeaveSprings(Car *this)
{
  int v2; // esi
  Suspension *v3; // eax
  Suspension *dwsus[4]; // [esp+Ch] [ebp-14h]

  v2 = 0;
  while ( 1 )
  {
    v3 = (Suspension *)__RTDynamicCast(
                         this->suspensions._Myfirst[v2],
                         0,
                         &ISuspension `RTTI Type Descriptor',
                         &Suspension `RTTI Type Descriptor',
                         0);
    dwsus[v2] = v3;
    if ( !v3 )
      break;
    if ( ++v2 >= 4 )
    {
      HeaveSpring::init(this->heaveSprings, this, dwsus[0], dwsus[1], 1);
      HeaveSpring::init(&this->heaveSprings[1], this, dwsus[2], dwsus[3], 0);
      return;
    }
  }
  _printf("IGNORING HEAVE SPRING BECAUSE SUSPENSION %d  IS NOT DOUBLE WISHBONE\n", v2);
}
void Car::initPitstopTimings(Car *this)
{
  const std::wstring *v2; // eax
  const std::wstring *v3; // eax
  bool v4; // bl
  double v5; // st7
  bool v6; // cf
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  char v11; // [esp+Ch] [ebp-B8h]
  std::wstring v12; // [esp+10h] [ebp-B4h] BYREF
  std::wstring section; // [esp+28h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+40h] [ebp-84h] BYREF
  std::wstring v15; // [esp+58h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+70h] [ebp-54h] BYREF
  int v17; // [esp+C0h] [ebp-4h]

  v11 = 0;
  v2 = std::operator+<wchar_t>(&result, &this->carDataPath, L"car.ini");
  v17 = 0;
  v3 = Car::getConfigPath(this, &v15, v2);
  LOBYTE(v17) = 1;
  INIReader::INIReader(&ini, v3);
  if ( v15._Myres >= 8 )
    operator delete(v15._Bx._Ptr);
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  LOBYTE(v17) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v4 = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PIT_STOP", 8u);
    LOBYTE(v17) = 5;
    v11 = 1;
    if ( INIReader::hasSection(&ini, &section) )
      v4 = 1;
  }
  v17 = 4;
  if ( (v11 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v4 )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TYRE_CHANGE_TIME_SEC", 0x14u);
    LOBYTE(v17) = 6;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"PIT_STOP", 8u);
    LOBYTE(v17) = 7;
    v5 = INIReader::getFloat(&ini, &v12, &section);
    v6 = v12._Myres < 8;
    this->pitTimings.tyreChangeTimeSec = v5;
    if ( !v6 )
      operator delete(v12._Bx._Ptr);
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    LOBYTE(v17) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FUEL_LITER_TIME_SEC", 0x13u);
    LOBYTE(v17) = 8;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"PIT_STOP", 8u);
    LOBYTE(v17) = 9;
    v7 = INIReader::getFloat(&ini, &v12, &section);
    v6 = v12._Myres < 8;
    this->pitTimings.fuelChangeTimeSec = v7;
    if ( !v6 )
      operator delete(v12._Bx._Ptr);
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    LOBYTE(v17) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"BODY_REPAIR_TIME_SEC", 0x14u);
    LOBYTE(v17) = 10;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"PIT_STOP", 8u);
    LOBYTE(v17) = 11;
    v8 = INIReader::getFloat(&ini, &v12, &section);
    v6 = v12._Myres < 8;
    this->pitTimings.bodyRepairTimeSec = v8;
    if ( !v6 )
      operator delete(v12._Bx._Ptr);
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    LOBYTE(v17) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ENGINE_REPAIR_TIME_SEC", 0x16u);
    LOBYTE(v17) = 12;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"PIT_STOP", 8u);
    LOBYTE(v17) = 13;
    v9 = INIReader::getFloat(&ini, &v12, &section);
    v6 = v12._Myres < 8;
    this->pitTimings.engineRepairTimeSec = v9;
    if ( !v6 )
      operator delete(v12._Bx._Ptr);
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    LOBYTE(v17) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SUSP_REPAIR_TIME_SEC", 0x14u);
    LOBYTE(v17) = 14;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, L"PIT_STOP", 8u);
    LOBYTE(v17) = 15;
    v10 = INIReader::getFloat(&ini, &v12, &section);
    v6 = v12._Myres < 8;
    this->pitTimings.suspRepairTimeSec = v10;
    if ( !v6 )
      operator delete(v12._Bx._Ptr);
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
  }
  v17 = -1;
  INIReader::~INIReader(&ini);
}
char Car::isInPitLane(Car *this)
{
  SurfaceDef **v1; // eax

  if ( this->tyres == (Tyre *)&this->suspensions )
    return 0;
  v1 = &this->tyres[0].surfaceDef;
  while ( !*v1 || !(*v1)->isPitlane )
  {
    v1 += 408;
    if ( v1 - 204 == (SurfaceDef **)&this->suspensions )
      return 0;
  }
  return 1;
}
BOOL Car::isInPits(Car *this)
{
  float *v1; // eax
  float v3; // [esp+8h] [ebp-18h]
  float v4; // [esp+Ch] [ebp-14h]
  float v5; // [esp+10h] [ebp-10h]
  char v6[12]; // [esp+14h] [ebp-Ch] BYREF

  v3 = this->pitPosition.M41;
  v4 = this->pitPosition.M42;
  v5 = this->pitPosition.M43;
  v1 = (float *)((int (*)(IRigidBody *, char *, _DWORD))this->body->getPosition)(this->body, v6, 0);
  return (float)((float)((float)((float)(v1[1] - v4) * (float)(v1[1] - v4))
                       + (float)((float)(*v1 - v3) * (float)(*v1 - v3)))
               + (float)((float)(v1[2] - v5) * (float)(v1[2] - v5))) <= 9.0;
}
bool Car::isMinSpeedPenaltyClearDisabled(Car *this)
{
  return this->disableMinSpeedPenaltyClear;
}
BOOL Car::isSleeping(Car *this)
{
  return this->sleepingFrames > this->framesToSleep;
}
void Car::lockControls(Car *this, bool lock)
{
  this->isControlsLocked = lock;
}
void Car::lockControlsUntil(Car *this, long double time, long double start)
{
  double v3; // xmm1_8
  double v4; // xmm1_8

  v3 = 0.0;
  if ( time == 0.0 )
    goto LABEL_4;
  v4 = this->lockControlsTime;
  if ( v4 > this->ksPhysics->physicsTime )
  {
    v3 = v4 + time;
LABEL_4:
    this->lockControlsTime = v3;
    return;
  }
  this->lockControlsTime = time + start;
}
void __userpurge Car::onCollisionCallBack(Car *this@<ecx>, int a2@<edi>, void *userData0, void *shape0, void *userData1, void *shape1, vec3f normal, __int128 pos, int a9)
{
  IRigidBody *v11; // eax
  IRigidBody *v12; // edi
  int v13; // eax
  IRigidBody *v14; // ecx
  int v15; // eax
  __int64 v16; // xmm0_8
  float v17; // eax
  vec3f *v18; // eax
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  char v22; // al
  float v23; // xmm3_4
  float v24; // xmm0_4
  vec3f *v25; // eax
  float v26; // xmm1_4
  PhysicsEngine *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  unsigned int v40; // eax
  float v41; // xmm0_4
  int (*v42)(_DWORD); // eax
  IRigidBody *v43; // eax
  PhysicsEngine *v44; // ecx
  int v46[5]; // [esp+34h] [ebp-8Ch] BYREF
  __int64 v47; // [esp+48h] [ebp-78h]
  _DWORD v48[6]; // [esp+50h] [ebp-70h]
  OnCollisionEvent v49; // [esp+68h] [ebp-58h] BYREF
  _BYTE result[8]; // [esp+90h] [ebp-30h] BYREF
  vec3f result_8; // [esp+98h] [ebp-28h] BYREF
  IRigidBody *v52; // [esp+A4h] [ebp-1Ch]
  float v53; // [esp+A8h] [ebp-18h]
  vec3f v; // [esp+ACh] [ebp-14h] BYREF
  IRigidBody *v55; // [esp+B8h] [ebp-8h]
  int v56; // [esp+BCh] [ebp-4h]
  void *retaddr; // [esp+C0h] [ebp+0h]
  float userData1a; // [esp+CCh] [ebp+Ch]
  float userData1b; // [esp+CCh] [ebp+Ch]

  v11 = this->body;
  if ( userData0 == v11 || userData1 == v11 )
  {
    v12 = (IRigidBody *)userData0;
    if ( userData0 == v11 )
      v12 = (IRigidBody *)userData1;
    v55 = v12;
    HIWORD(v56) = 0;
    if ( shape1 )
    {
      if ( (*(int (__fastcall **)(void *, void *, int))(*(_DWORD *)shape1 + 12))(shape1, userData1, a2) == 1
        || (v13 = (*(int (**)(void *))(*(_DWORD *)shape1 + 12))(shape1), BYTE2(v56) = 0, v13 == 16) )
      {
        BYTE2(v56) = 1;
      }
    }
    if ( *(float *)&shape0 != 0.0 )
      HIBYTE(v56) = (*(int (__fastcall **)(void *, void *))(*(_DWORD *)shape0 + 12))(shape0, userData1) == 1
                 || (*(int (**)(void *))(*(_DWORD *)shape0 + 12))(shape0) == 16;
    v14 = this->body;
    this->lastCollisionTime = this->ksPhysics->physicsTime;
    ((void (*)(IRigidBody *, vec3f *, __int128 *, int))v14->worldToLocal)(v14, &result_8, &pos, a2);
    userData1a = 0.0;
    v53 = 0.0;
    v.x = 0.0;
    if ( v56 )
    {
      v15 = (*(int (**)(int, _BYTE *, char *))(*(_DWORD *)v56 + 132))(v56, result, (char *)&pos + 4);
      v16 = *(_QWORD *)v15;
      v17 = *(float *)(v15 + 8);
      *(_QWORD *)&v.y = v16;
      v55 = (IRigidBody *)LODWORD(v17);
      v.x = v17;
      v53 = *((float *)&v16 + 1);
      userData1a = *(float *)&v16;
    }
    v18 = this->body->getPointVelocity(this->body, result, (char *)&pos + 4);
    v19 = v18->x - userData1a;
    v20 = v18->z - v.x;
    v21 = normal.z * (float)(v18->y - v53);
    v22 = HIBYTE(retaddr);
    LODWORD(v23) = COERCE_UNSIGNED_INT((float)((float)(v21 + (float)(normal.y * v19)) + (float)(*(float *)&pos * v20)) * 3.5999999) ^ _xmm;
    userData1b = v23;
    if ( *(float *)&shape0 != 0.0 && shape1 && !HIWORD(retaddr) )
    {
      v22 = 0;
      this->lastCollisionWithCarTime = this->ksPhysics->physicsTime;
    }
    if ( v23 > 0.0 && !v22 && !BYTE2(retaddr) )
    {
      if ( (float)(this->ksPhysics->mechanicalDamageRate * v23) > 150.0 )
        Engine::blowUp(&this->drivetrain.acEngine);
      LODWORD(v24) = _mm_loadl_epi64((const __m128i *)&result_8.y).m128i_u32[0];
      v55 = v52;
      v.y = v24;
      v.z = 0.0;
      v25 = normalize((vec3f *)result, (vec3f *)&v.y);
      v26 = (float)((float)(v25->y * 0.0) + (float)(v25->x * 0.0)) + v25->z;
      v27 = this->ksPhysics;
      if ( COERCE_FLOAT(LODWORD(v26) & _xmm) <= 0.70700002 )
      {
        v29 = v27->mechanicalDamageRate * v23;
        if ( result_8.y >= 0.0 )
        {
          if ( v29 <= this->damageZoneLevel[2] )
            v29 = this->damageZoneLevel[2];
          this->damageZoneLevel[2] = v29;
        }
        else
        {
          if ( v29 <= this->damageZoneLevel[3] )
            v29 = this->damageZoneLevel[3];
          this->damageZoneLevel[3] = v29;
        }
      }
      else
      {
        v28 = v27->mechanicalDamageRate * v23;
        if ( *(float *)&v52 <= 0.0 )
        {
          if ( v28 <= this->damageZoneLevel[1] )
            v28 = this->damageZoneLevel[1];
          this->damageZoneLevel[1] = v28;
        }
        else
        {
          if ( v28 <= this->damageZoneLevel[0] )
            v28 = this->damageZoneLevel[0];
          this->damageZoneLevel[0] = v28;
        }
      }
      v30 = this->ksPhysics->mechanicalDamageRate * v23;
      if ( v30 <= this->damageZoneLevel[4] )
        v30 = this->damageZoneLevel[4];
      this->damageZoneLevel[4] = v30;
    }
    v31 = this->damageZoneLevel[0];
    v32 = FLOAT_0_5;
    if ( v31 > 0.0 )
    {
      v33 = this->damageZoneLevel[2];
      if ( v33 > 0.0 )
      {
        (*(void (**)(ISuspension *, _DWORD))(**(_DWORD **)this->suspensions._Myfirst + 60))(
          *this->suspensions._Myfirst,
          (float)(v33 + v31) * 0.5);
        v32 = FLOAT_0_5;
      }
    }
    v34 = this->damageZoneLevel[0];
    if ( v34 > 0.0 )
    {
      v35 = this->damageZoneLevel[3];
      if ( v35 > 0.0 )
        (*(void (**)(_DWORD, _DWORD))(**((_DWORD **)this->suspensions._Myfirst + 1) + 60))(
          *((_DWORD *)this->suspensions._Myfirst + 1),
          (float)(v35 + v34) * v32);
    }
    v36 = this->damageZoneLevel[1];
    if ( v36 > 0.0 )
    {
      v37 = this->damageZoneLevel[2];
      if ( v37 > 0.0 )
        (*(void (**)(_DWORD, _DWORD))(**((_DWORD **)this->suspensions._Myfirst + 2) + 60))(
          *((_DWORD *)this->suspensions._Myfirst + 2),
          (float)(v37 + v36) * 0.5);
    }
    v38 = this->damageZoneLevel[1];
    if ( v38 > 0.0 )
    {
      v39 = this->damageZoneLevel[3];
      if ( v39 > 0.0 )
        (*(void (**)(_DWORD, _DWORD))(**((_DWORD **)this->suspensions._Myfirst + 3) + 60))(
          *((_DWORD *)this->suspensions._Myfirst + 3),
          (float)(v39 + v38) * 0.5);
    }
    v40 = this->physicsGUID;
    v46[3] = -1082130432;
    v48[4] = 0;
    v48[5] = 0;
    v49.body = 0;
    v46[0] = 0;
    v48[0] = HIDWORD(pos);
    v48[3] = pos;
    v41 = (float)v40;
    v42 = *(int (**)(_DWORD))(*(_DWORD *)LODWORD(normal.x) + 12);
    *(float *)&v46[1] = v41;
    v46[2] = a9;
    *(float *)&v46[4] = userData1b;
    v47 = *(_QWORD *)((char *)&pos + 4);
    *(_QWORD *)&v48[1] = *(_QWORD *)&normal.y;
    v43 = (IRigidBody *)v42(LODWORD(normal.x));
    v44 = this->ksPhysics;
    v49.body = v43;
    Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(&v44->eventQueue, v46);
    if ( *(float *)&shape0 > 0.0 && !HIWORD(v56) )
    {
      OnCollisionEvent::OnCollisionEvent(&v49);
      v49.body = v55;
      v49.colliderGroup = (*(int (**)(_DWORD))(*(_DWORD *)LODWORD(normal.x) + 12))(LODWORD(normal.x));
      v49.relPos = result_8;
      v49.worldPos = (vec3f)pos;
      LODWORD(v49.relativeSpeed) = shape0;
      Event<std::wstring>::trigger(
        (Event<OnGearRequestEvent> *)&this->evOnCollisionEvent,
        (const OnGearRequestEvent *)&v49);
    }
  }
}
void Car::onNewSession(Car *this, const SessionInfo *si)
{
  bool v3; // zf
  PhysicsEngine *v4; // ebp
  std::pair<void *,std::function<void __cdecl(OnFlagEvent const &)> > *v5; // esi
  std::_Func_base<void,OnFlagEvent const &> **v6; // edi
  int v7[3]; // [esp+10h] [ebp-Ch] BYREF

  v3 = !this->blackFlagged;
  this->isRetired = 0;
  if ( !v3 )
  {
    v4 = this->ksPhysics;
    this->blackFlagged = 0;
    v7[2] = 0;
    v7[0] = (int)this;
    v7[1] = 1;
    v5 = v4->evOnFlagEvent.handlers._Myfirst;
    if ( v5 != v4->evOnFlagEvent.handlers._Mylast )
    {
      v6 = &v5->second._Impl;
      do
      {
        if ( !*v6 )
        {
          std::_Xbad_function_call();
          JUMPOUT(0x73710B);
        }
        (*v6)->_Do_call(*v6, (const OnFlagEvent *)v7);
        ++v5;
        v6 += 8;
      }
      while ( v5 != v4->evOnFlagEvent.handlers._Mylast );
    }
  }
  PerformanceMeter::reset(&this->performanceMeter);
}
void Car::onTyresStepCompleted(Car *this)
{
  double v2; // st7
  PhysicsEngine *v3; // edi
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // [esp+10h] [ebp-10h]
  float v8; // [esp+14h] [ebp-Ch]
  Speed result; // [esp+18h] [ebp-8h] BYREF
  Speed v10; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->controlsProvider )
  {
    v2 = Car::getSteerFF(this);
    v3 = this->ksPhysics;
    this->lastFF = v2;
    v8 = 0.0;
    if ( v3->mzLowSpeedReduction.speedKMH != 0.0 )
    {
      v4 = FLOAT_1_0;
      v5 = (float)(Car::getSpeed(this, &result)->value * 3.5999999) / v3->mzLowSpeedReduction.speedKMH;
      v7 = v5;
      if ( v5 > 1.0 || (v4 = 0.0, v5 < 0.0) )
        v7 = v4;
      v10.value = v3->mzLowSpeedReduction.minValue;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      this->lastFF = (float)((float)((float)(1.0 - v10.value) * v7) + v10.value) * this->lastFF;
    }
    if ( !this->isControlsLocked && !this->blackFlagged )
    {
      v6 = 1.0 - (float)((float)(Car::getSpeed(this, &v10)->value * 3.5999999) * 0.1);
      if ( v6 <= 1.0 )
      {
        if ( v6 >= 0.0 )
          v8 = v6;
      }
      else
      {
        v8 = FLOAT_1_0;
      }
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v10);
      ((void (*)(ICarControlsProvider *, _DWORD, _DWORD, _DWORD))this->controlsProvider->sendFF)(
        this->controlsProvider,
        LODWORD(this->lastFF),
        (float)((float)((float)(1.0 - this->ksPhysics->damperMinValue) * v8) + this->ksPhysics->damperMinValue)
      * this->ksPhysics->damperGain,
        LODWORD(this->userFFGain));
    }
  }
  else
  {
    this->mzCurrent = 0.0;
  }
}
void Car::pollControls(Car *this, float dt)
{
  ICarControlsProvider *v3; // ecx
  int v4; // eax
  ICarControlsProvider *v5; // esi
  ICarControlsProvider_vtbl *v6; // edi
  float v7; // xmm0_4
  float v8; // xmm5_4
  int v9; // esi
  float v10; // xmm7_4
  int v11; // edx
  float v12; // xmm6_4
  float v13; // xmm4_4
  float *v14; // ecx
  float v15; // xmm3_4
  float v16; // eax
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float period; // xmm6_4
  int v21; // ecx
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  int (*v28)(int); // eax
  float v29; // xmm2_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  bool v32; // zf
  double v33; // st7
  int v34; // ecx
  int v35; // ecx
  Engine_vtbl *v36; // eax
  Engine *v37; // ecx
  ICarControlsProvider *v38; // esi
  ICarControlsProvider_vtbl *v39; // edi
  int v40; // eax
  float v41; // [esp+14h] [ebp-5Ch]
  __int128 v42; // [esp+2Ch] [ebp-44h] BYREF
  float v43; // [esp+3Ch] [ebp-34h]
  float v44; // [esp+40h] [ebp-30h] BYREF
  Speed v45; // [esp+44h] [ebp-2Ch] BYREF
  float value; // [esp+48h] [ebp-28h]
  Speed result; // [esp+4Ch] [ebp-24h] BYREF
  float v48; // [esp+50h] [ebp-20h]
  float v49; // [esp+54h] [ebp-1Ch]
  float v50; // [esp+58h] [ebp-18h]
  float v51; // [esp+5Ch] [ebp-14h]
  float v52; // [esp+60h] [ebp-10h]
  int v53; // [esp+6Ch] [ebp-4h]
  float dta; // [esp+74h] [ebp+4h]

  v49 = *(float *)&this;
  v44 = 0.0;
  std::unique_ptr<AudioEvent>::unique_ptr<AudioEvent>(&v45);
  v53 = 0;
  v45.value = Car::getSpeed(this, &result)->value;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v3 = this->controlsProvider;
  v44 = this->steerLock;
  if ( v3 )
  {
    if ( this->isControlsLocked || this->blackFlagged )
    {
      this->controls.gas = 0.0;
      this->controls.brake = 0.0;
      this->controls.steer = 0.0;
      this->controls.clutch = 0.0;
      *(_WORD *)&this->controls.gearUp = 0;
      this->controls.kers = 0;
      v42 = 0i64;
      v43 = 0.0;
      v3->setVibrations(v3, (const VibrationDef *)&v42);
      ((void (*)(ICarControlsProvider *, _DWORD, _DWORD, _DWORD))this->controlsProvider->sendFF)(
        this->controlsProvider,
        0,
        0,
        LODWORD(this->userFFGain));
      v36 = this->drivetrain.acEngine.__vftable;
      v37 = &this->drivetrain.acEngine;
      v38 = this->controlsProvider;
      v39 = v38->__vftable;
      v40 = v36->getLimiterRPM(v37);
      ((void (*)(ICarControlsProvider *, _DWORD, int, float))v39->setEngineRPM)(
        v38,
        0,
        1148846080,
        (float)v40);
    }
    else
    {
      ((void (__stdcall *)(CarControls *, _DWORD, float *))v3->acquireControls)(&this->controls, LODWORD(dt), &v44);
      v4 = this->drivetrain.acEngine.getLimiterRPM(&this->drivetrain.acEngine);
      v5 = this->controlsProvider;
      v6 = v5->__vftable;
      v7 = (float)v4;
      v41 = Drivetrain::getEngineRPM((Drivetrain *)(LODWORD(v49) + 504));
      ((void (*)(ICarControlsProvider *, _DWORD, _DWORD, _DWORD))v6->setEngineRPM)(
        v5,
        LODWORD(v41),
        v7 * 0.75,
        v7 * 0.94999999);
      v8 = v45.value;
      v9 = LODWORD(v49);
      v10 = 0.0;
      v43 = 0.0;
      v11 = 4;
      result.value = v45.value;
      v12 = 0.0;
      v13 = 0.0;
      v14 = (float *)(LODWORD(v49) + 2856);
      v15 = 0.0;
      value = (float)(v45.value * dt) + *(float *)(LODWORD(v49) + 11760);
      *(float *)(LODWORD(v49) + 11760) = value;
      v42 = 0i64;
      do
      {
        v16 = *v14;
        if ( !*(_DWORD *)v14 )
          goto LABEL_11;
        v17 = *(float *)(LODWORD(v16) + 180);
        if ( v17 > v10 )
          v10 = *(float *)(LODWORD(v16) + 180);
        v18 = *(float *)(LODWORD(v16) + 184);
        if ( v18 == 0.0 || v17 == 0.0 )
        {
LABEL_11:
          v19 = FLOAT_1_0;
        }
        else
        {
          v12 = v12 + v18;
          v19 = FLOAT_1_0;
          v13 = v13 + 1.0;
        }
        if ( v15 <= (float)(*(v14 - 61) * 0.75) )
          v15 = *(v14 - 61) * 0.75;
        v14 += 408;
        --v11;
      }
      while ( v11 );
      v48 = v10;
      v49 = v15;
      if ( v19 >= v15 )
      {
        v19 = FLOAT_1_0;
        v49 = v15 * v15;
      }
      period = v12 / v13;
      if ( v10 != 0.0 && period != 0.0 )
      {
        v52 = *(float *)(v9 + 2572);
        if ( v52 <= v19 )
        {
          if ( v52 < 0.0 )
            v52 = 0.0;
        }
        else
        {
          v52 = v19;
        }
        v51 = *(float *)(v9 + 4204);
        if ( v51 <= v19 )
        {
          if ( v51 < 0.0 )
            v51 = 0.0;
        }
        else
        {
          v51 = v19;
        }
        if ( v8 <= v19 )
        {
          if ( v8 >= 0.0 )
            v50 = v8;
          else
            v50 = 0.0;
        }
        else
        {
          v50 = v19;
        }
        value = ksSawToothWave(value, period);
        *(float *)&v42 = (float)((float)((float)(value * v52) * v51) * v48) * v50;
      }
      *(float *)(v9 + 11764) = dt + *(float *)(v9 + 11764);
      LODWORD(v22) = __libm_sse2_sinf(v14).m128_u32[0];
      LODWORD(v23) = *(_DWORD *)(v9 + 320) & _xmm;
      if ( v23 <= 1.0 )
      {
        if ( v23 < 0.0 )
          v23 = 0.0;
      }
      else
      {
        v23 = FLOAT_1_0;
      }
      *((float *)&v42 + 1) = v22 * v23;
      LODWORD(v24) = __libm_sse2_sinf(v21).m128_u32[0];
      v25 = v49 * 0.40000001;
      v26 = FLOAT_1_0;
      if ( (float)(v49 * 0.40000001) > 1.0 || (v26 = 0.0, v25 < 0.0) )
        v25 = v26;
      v27 = *(double *)(v9 + 512);
      v28 = *(int (**)(int))(*(_DWORD *)(v9 + 720) + 4);
      *((float *)&v42 + 2) = v24 * v25;
      v29 = (float)((float)(v27 * 0.15915507) * 60.0) / (float)v28(v9 + 720);
      if ( v29 <= 1.0 )
      {
        if ( v29 >= 0.0 )
          *((float *)&v42 + 3) = v29;
        else
          HIDWORD(v42) = 0;
      }
      else
      {
        HIDWORD(v42) = 1065353216;
      }
      v30 = result.value;
      if ( result.value <= 1.0 )
      {
        if ( result.value >= 0.0 )
          v31 = result.value;
        else
          v31 = 0.0;
      }
      else
      {
        v31 = FLOAT_1_0;
      }
      *(float *)&v42 = v31 * *(float *)&v42;
      if ( result.value <= 1.0 )
      {
        if ( result.value < 0.0 )
          v30 = 0.0;
      }
      else
      {
        v30 = FLOAT_1_0;
      }
      v32 = *(_BYTE *)(v9 + 1728) == 0;
      *((float *)&v42 + 2) = v30 * *((float *)&v42 + 2);
      if ( v32 || !ABS::isInAction((ABS *)(v9 + 1728)) )
      {
        v35 = *(_DWORD *)(v9 + 11612);
        v43 = 0.0;
        (*(void (**)(int, __int128 *))(*(_DWORD *)v35 + 36))(v35, &v42);
      }
      else
      {
        if ( result.value <= 1.0 )
        {
          if ( result.value >= 0.0 )
            dta = result.value;
          else
            dta = 0.0;
        }
        else
        {
          dta = 1.0;
        }
        v33 = ksSquareWave();
        v34 = *(_DWORD *)(v9 + 11612);
        v43 = v33 * dta;
        (*(void (**)(int, __int128 *))(*(_DWORD *)v34 + 36))(v34, &v42);
      }
    }
  }
  v53 = -1;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v45);
}
void Car::postStep(Car *this, float dt)
{
  int v3; // ecx
  PhysicsEngine *v4; // eax
  std::pair<void *,std::function<void __cdecl(OnStepCompleteEvent const &)> > *v5; // esi
  std::_Func_base<void,OnStepCompleteEvent const &> **v6; // edi
  IRigidBody *v7; // esi
  int v8; // eax
  const vec3f *v9; // eax
  float v10; // xmm0_4
  InterpolatingSpline *v11; // ecx
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm0_4
  AISpline *v15; // eax
  float nsplinepos; // [esp+10h] [ebp-8Ch]
  float nsplineposa; // [esp+10h] [ebp-8Ch]
  vec3f vel; // [esp+1Ch] [ebp-80h] BYREF
  int v19[2]; // [esp+28h] [ebp-74h] BYREF
  long double v20; // [esp+30h] [ebp-6Ch]
  float sides[2]; // [esp+38h] [ebp-64h] BYREF
  Car *v22; // [esp+40h] [ebp-5Ch]
  AISplinePayload result; // [esp+44h] [ebp-58h] BYREF

  v3 = dword_186F13C;
  v22 = this;
  if ( (dword_186F13C & 1) == 0 )
  {
    perfCounter_29.name = "Car::postStep";
    v3 = dword_186F13C | 1;
    perfCounter_29.group = Physics;
    dword_186F13C |= 1u;
    perfCounter_29.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Car::postStep" | 0xFF000000;
  }
  if ( (v3 & 2) == 0 )
  {
    perfCounter_30.name = "Car::postStep (OnStepCompleteEvent)";
    perfCounter_30.group = Physics;
    dword_186F13C = v3 | 2;
    perfCounter_30.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Car::postStep (OnStepCompleteEvent)" | 0xFF000000;
  }
  v4 = this->ksPhysics;
  v5 = this->evOnStepComplete.handlers._Myfirst;
  v19[0] = (int)this;
  v20 = v4->physicsTime;
  if ( v5 != this->evOnStepComplete.handlers._Mylast )
  {
    v6 = &v5->second._Impl;
    do
    {
      if ( !*v6 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x737A9A);
      }
      (*v6)->_Do_call(*v6, (const OnStepCompleteEvent *)v19);
      ++v5;
      v6 += 8;
    }
    while ( v5 != v22->evOnStepComplete.handlers._Mylast );
    this = v22;
  }
  v7 = this->body;
  v8 = ((int (*)(IRigidBody *))v7->getVelocity)(v7);
  v9 = (const vec3f *)((int (*)(IRigidBody *, int *, _DWORD, int))v7->getPosition)(v7, v19, 0, v8);
  SlipStream::setPosition(&this->slipStream, v9, &vel);
  LODWORD(v10) = LODWORD(this->splineLocator.offset) ^ _xmm;
  v11 = &this->splineLocator.currentSpline->spline;
  this->splineLocatorData.isOutsideTrackLimits = this->splineLocator.isOutsideLimits;
  this->splineLocatorData.npos = this->splineLocator.normalizedPos;
  this->splineLocatorData.currentIndex = this->splineLocator.currentIndex;
  this->splineLocatorData.lateralOffset = v10;
  v12 = Spline::length(v11);
  nsplinepos = this->splineLocatorData.npos;
  this->splineLocatorData.splineLength = v12;
  SplineLocator::getSides(&this->splineLocator, sides, nsplinepos);
  v13 = sides[0];
  this->splineLocatorData.sideVelocity = (float)(sides[0] - this->splineLocatorData.sides[0]) / dt;
  v14 = sides[1];
  this->splineLocatorData.sides[0] = v13;
  this->splineLocatorData.sides[1] = v14;
  nsplineposa = this->splineLocator.normalizedPos;
  v15 = AISplineRecorder::getBestLapSpline(this->ksPhysics->track->aiSplineRecorder._Myptr);
  AISpline::payloadAtPosition(v15, &result, nsplineposa);
  this->splineLocatorData.sidesFromIL[0] = result.sides[0];
  this->splineLocatorData.sidesFromIL[1] = result.sides[1];
}
void Car::reset(Car *this)
{
  bool v2; // zf
  long double v3; // xmm0_8

  v2 = !this->kers.present;
  v3 = this->requestedFuel;
  this->hasGridPosition = 0;
  this->water.t = 60.0;
  this->framesToSleep = 50;
  this->fuel = v3;
  *(_OWORD *)&this->penaltyTimeAccumulator = 0i64;
  if ( !v2 )
    Kers::reset(&this->kers);
  if ( this->ers.present )
    ERS::reset(&this->ers);
  this->isCollisionOffForPits = 0;
}
void Car::resetSplineLocator(Car *this)
{
  SplineLocator::resetToClosestPoint(&this->splineLocator);
}
void Car::resetSuspensionDamageLevel(Car *this)
{
  ISuspension **v1; // esi
  unsigned int v2; // ebx
  int v3; // edi

  v1 = this->suspensions._Myfirst;
  v2 = (unsigned int)((char *)this->suspensions._Mylast - (char *)v1 + 3) >> 2;
  v3 = 0;
  if ( v1 > this->suspensions._Mylast )
    v2 = 0;
  if ( v2 )
  {
    do
    {
      (*v1)->resetDamage(*v1);
      ++v3;
      ++v1;
    }
    while ( v3 != v2 );
  }
}
void Car::setBallastKG(Car *this, float kg)
{
  this->ballastKG = kg;
}
void Car::setBlackFlag(Car *this, bool isflagged, PenaltyDescription type)
{
  PhysicsEngine *v3; // ebx
  std::pair<void *,std::function<void __cdecl(OnFlagEvent const &)> > *v4; // esi
  std::_Func_base<void,OnFlagEvent const &> **v5; // edi
  OnFlagEvent ev; // [esp+8h] [ebp-Ch] BYREF

  ev.description = type;
  v3 = this->ksPhysics;
  this->blackFlagged = isflagged;
  ev.car = this;
  ev.type = !isflagged;
  v4 = v3->evOnFlagEvent.handlers._Myfirst;
  if ( v4 != v3->evOnFlagEvent.handlers._Mylast )
  {
    v5 = &v4->second._Impl;
    do
    {
      if ( !*v5 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x737BE2);
      }
      (*v5)->_Do_call(*v5, &ev);
      ++v4;
      v5 += 8;
    }
    while ( v4 != v3->evOnFlagEvent.handlers._Mylast );
  }
}
void Car::setControllerProvider(Car *this, ICarControlsProvider *cp)
{
  ICarControlsProvider *v3; // ecx
  std::pair<void *,std::function<void __cdecl(OnControlsProviderChanged const &)> > *v4; // esi
  ICarControlsProvider *v5; // eax
  std::_Func_base<void,OnControlsProviderChanged const &> **v6; // edi
  OnControlsProviderChanged ev; // [esp+8h] [ebp-8h] BYREF

  v3 = this->controlsProvider;
  if ( v3 )
    ((void (*)(ICarControlsProvider *, int))v3->~ICarControlsProvider)(v3, 1);
  this->controlsProvider = cp;
  __RTDynamicCast(cp, 0, &ICarControlsProvider `RTTI Type Descriptor', &AIDriver `RTTI Type Descriptor', 0);
  v4 = this->evOnControlsProviderChanged.handlers._Myfirst;
  v5 = this->controlsProvider;
  ev.car = this;
  ev.newControlsProvider = v5;
  if ( v4 != this->evOnControlsProviderChanged.handlers._Mylast )
  {
    v6 = &v4->second._Impl;
    do
    {
      if ( !*v6 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x737C6C);
      }
      (*v6)->_Do_call(*v6, &ev);
      ++v4;
      v6 += 8;
    }
    while ( v4 != this->evOnControlsProviderChanged.handlers._Mylast );
  }
}
void Car::setDamageLevel(Car *this, float v)
{
  __m128 v2; // xmm0

  v2 = _mm_shuffle_ps((__m128)LODWORD(v), (__m128)LODWORD(v), 0);
  *(__m128 *)this->damageZoneLevel = v2;
  LODWORD(this->damageZoneLevel[4]) = v2.m128_i32[0];
}
void Car::setDamageLevel(Car *this, float v, int index)
{
  this->damageZoneLevel[index] = v;
}
int Car::setFuelForLaps(Car *this, int laps, float mult)
{
  double v4; // xmm2_8
  float v5; // xmm1_4
  float v6; // xmm0_4
  int result; // eax
  double v8; // xmm2_8
  float v9; // [esp+48h] [ebp-8h]
  float fuelxlap; // [esp+4Ch] [ebp-4h]

  fuelxlap = FuelLapEvaluator::getFuelPerLap(&this->fuelLapEvaluator);
  _printf("CAR: %u  setting fuel for %d laps, with mult=%f\n", this->physicsGUID, laps, mult);
  if ( fuelxlap <= 0.0 )
  {
    fuelxlap = this->expectedFuelPerLap;
    _printf("Using RaceEnginner,");
  }
  else
  {
    _printf("Using fuelLapEvaluator,");
  }
  v4 = this->maxFuel;
  v5 = (float)((float)laps * fuelxlap) * mult;
  if ( v4 <= v5 )
  {
    v8 = v4 / fuelxlap;
    _printf("CANNOT COMPLETED REQUESTED AMOUNT OF LAPS! Laps=%f [%d]\n", v8, (int)v8);
    result = (int)v8;
  }
  else
  {
    v6 = v4;
    v9 = v6;
    if ( v5 <= v6 )
    {
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = (float)((float)laps * fuelxlap) * mult;
        v9 = v6;
      }
      else
      {
        v9 = 0.0;
      }
    }
    _printf("Car::setRequestedFuel: %f\n", v6);
    this->requestedFuel = v9;
    this->fuel = v9;
    _printf(" fuelxlap=%f fuel %f\n", fuelxlap, v9);
    result = laps;
  }
  return result;
}
void Car::setRequestedFuel(Car *this, float value, bool changeValue)
{
  _printf("Car::setRequestedFuel: %f\n", value);
  this->fuel = value;
  if ( changeValue )
    this->requestedFuel = value;
}
void Car::setRestrictor(Car *this, float value)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = value * 0.0024999999;
  v3 = FLOAT_1_0;
  if ( (float)(value * 0.0024999999) > 1.0 || (v3 = 0.0, v2 < 0.0) )
    this->drivetrain.acEngine.restrictor = v3;
  else
    this->drivetrain.acEngine.restrictor = v2;
}
void Car::setSlipStreamEffects(Car *this, float receive, float generationSpeedFactor)
{
  _printf("Car::setSlipStreamEffects: receive:%f speed_factor:%f\n", receive, generationSpeedFactor);
  this->slipStreamEffectGain = 1.0;
  this->slipStream.speedFactor = generationSpeedFactor * 0.5;
}
void __userpurge Car::step(Car *this@<ecx>, int a2@<esi>, float dt)
{
  Car *v3; // edi
  float *v4; // eax
  ISuspension **v5; // esi
  int v6; // edx
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  ISuspension **v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // edi
  unsigned int v13; // edi
  PhysicsEngine *v14; // eax
  double v15; // xmm0_8
  bool v16; // al
  bool v17; // zf
  IRigidBody *v18; // ecx
  IRigidBody_vtbl *v19; // eax
  vec3f *(*v20)(IRigidBody *, vec3f *, float); // eax
  float *v21; // eax
  float v22; // xmm1_4
  double v23; // xmm0_8
  double v24; // st7
  PhysicsEngine *v25; // eax
  long double v26; // xmm0_8
  double v27; // xmm1_8
  PenaltyMode v28; // eax
  long double v29; // xmm1_8
  float *v30; // eax
  float v31; // xmm2_4
  float v32; // xmm0_4
  Car *v33; // eax
  float *v34; // eax
  IRigidBody *v35; // ecx
  float v36; // eax
  unsigned __int64 v37; // xmm5_8
  float v38; // xmm3_4
  int v39; // xmm1_4
  int v40; // xmm2_4
  int v41; // eax
  vec3f v42; // [esp+38h] [ebp-40h] BYREF
  int v43[3]; // [esp+44h] [ebp-34h] BYREF
  unsigned __int64 v44; // [esp+50h] [ebp-28h] BYREF
  float v45; // [esp+58h] [ebp-20h]
  float Px; // [esp+5Ch] [ebp-1Ch] BYREF
  PerformanceSplit result; // [esp+60h] [ebp-18h] BYREF
  float v48; // [esp+70h] [ebp-8h]
  int v49; // [esp+74h] [ebp-4h]

  v3 = this;
  *((_DWORD *)&result.speedMS + 1) = this;
  if ( (dword_186F12C & 1) == 0 )
  {
    perfCounter_28.name = "Car::step";
    dword_186F12C |= 1u;
    perfCounter_28.group = Physics;
    perfCounter_28.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Car::step" | 0xFF000000;
  }
  if ( !this->physicsGUID )
  {
    v4 = (float *)((int (*)(IRigidBody *, vec3f *, int))this->body->getVelocity)(this->body, &v42, a2);
    v5 = v3->suspensions._Myfirst;
    v6 = 0;
    v7 = v4[1];
    v8 = *v4;
    v9 = v4[2];
    v10 = v3->suspensions._Mylast;
    v11 = (unsigned int)((char *)v10 - (char *)v5 + 3) >> 2;
    if ( (float)((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9)) >= 1.0 )
    {
      v49 = 0;
      if ( v5 > v10 )
        v11 = 0;
      if ( v11 )
      {
        v13 = v11;
        do
        {
          ((void (__fastcall *)(ISuspension *, int, int, _DWORD))(*v5)->setERPCFM)(
            *v5,
            v6,
            1050253722,
            LODWORD((*v5)->baseCFM));
          ++v5;
          ++v49;
        }
        while ( v49 != v13 );
        v3 = (Car *)LODWORD(v48);
      }
      ((void (__fastcall *)(IJoint *, int, int))v3->fuelTankJoint->setERPCFM)(v3->fuelTankJoint, v6, 1050253722);
    }
    else
    {
      v49 = 0;
      if ( v5 > v10 )
        v11 = 0;
      if ( v11 )
      {
        v12 = v11;
        do
        {
          ((void (__fastcall *)(ISuspension *, int, int, int))(*v5)->setERPCFM)(*v5, v6, 1063675494, 869711765);
          ++v5;
          ++v49;
        }
        while ( v49 != v12 );
        v3 = (Car *)LODWORD(v48);
      }
      ((void (__fastcall *)(IJoint *, int, int))v3->fuelTankJoint->setERPCFM)(v3->fuelTankJoint, v6, 1063675494);
    }
    a2 = -1082130432;
  }
  if ( v3->isControlsLocked
    || (v14 = v3->ksPhysics, v15 = v3->lockControlsTime, HIBYTE(v49) = 0, v15 > v14->physicsTime) )
  {
    HIBYTE(v49) = 1;
  }
  Car::pollControls(v3, dt);
  v16 = v3->controlsProvider->getAction(v3->controlsProvider, eHeadlightsSwitch);
  if ( v3->controlsProvider && v16 && !v3->lastLigthSwitchState )
    v3->lightsOn = !v3->lightsOn;
  v17 = !v3->blackFlagged;
  v3->lastLigthSwitchState = v16;
  if ( !v17 )
  {
    v18 = v3->body;
    Px = v3->pitPosition.M41;
    v19 = v18->__vftable;
    *((_DWORD *)&result.speedMS + 1) = LODWORD(v3->pitPosition.M42);
    v20 = v19->getPosition;
    v48 = v3->pitPosition.M43;
    v21 = (float *)((int (__stdcall *)(vec3f *, _DWORD))v20)(&v42, 0);
    if ( (float)((float)((float)((float)(v21[1] - *(&result.speedMS + 1)) * (float)(v21[1] - *(&result.speedMS + 1)))
                       + (float)((float)(*v21 - Px) * (float)(*v21 - Px)))
               + (float)((float)(v21[2] - v48) * (float)(v21[2] - v48))) > 9.0 )
    {
      HIDWORD(result.t) = LODWORD(v3->pitPosition.M31) ^ _xmm;
      LODWORD(result.speedMS) = LODWORD(v3->pitPosition.M32) ^ _xmm;
      *((_DWORD *)&result.speedMS + 1) = LODWORD(v3->pitPosition.M33) ^ _xmm;
      Car::forceRotation(v3, (const vec3f *)((char *)&result.t + 4));
      HIDWORD(result.t) = LODWORD(v3->pitPosition.M41);
      result.speedMS = v3->pitPosition.M42;
      *((_DWORD *)&result.speedMS + 1) = LODWORD(v3->pitPosition.M43);
      Car::forcePosition(v3, (const vec3f *)((char *)&result.t + 4), 1);
    }
  }
  Car::updateAirPressure(v3);
  v22 = v3->drivetrain.acEngine.status.turboBoost;
  v23 = 0.0;
  if ( v22 >= 0.0 )
    v23 = v22;
  *(double *)&result.speedMS = v23;
  v24 = Drivetrain::getEngineRPM(&v3->drivetrain);
  v25 = v3->ksPhysics;
  Px = v24;
  v26 = v3->fuel
      - (float)((float)(COERCE_FLOAT(LODWORD(Px) & _xmm) * dt) * v3->drivetrain.acEngine.gasUsage)
      * (*(double *)&result.speedMS + 1.0)
      * v3->fuelConsumptionK
      * 0.001
      * v25->fuelConsumptionRate;
  v3->fuel = v26;
  if ( v26 > 0.0 )
  {
    v3->drivetrain.acEngine.fuelPressure = 1.0;
  }
  else
  {
    v3->fuel = 0.0;
    v3->drivetrain.acEngine.fuelPressure = 0.0;
  }
  Car::updateBodyMass(v3, a2);
  if ( v3->controlsProvider )
  {
    if ( HIBYTE(v49) )
    {
      v3->controls.gas = 0.0;
      v3->controls.brake = 1.0;
      v3->controls.clutch = 0.0;
      v3->controls.steer = 0.0;
    }
    if ( v3->isGentleStopping )
    {
      v3->controls.gas = 0.0;
      v3->controls.brake = 0.2;
    }
    v27 = v3->penaltyTime;
    if ( v27 > 0.0 )
    {
      v28 = v3->ksPhysics->penaltyMode;
      if ( v28 )
      {
        if ( v28 == RecoverTime )
          v3->penaltyTime = v3->penaltyPerfTarget - PerformanceMeter::getCurrentSplit(&v3->performanceMeter, &result)->t;
      }
      else
      {
        if ( v3->controls.gas >= 0.1 )
        {
          v3->penaltyTimeAccumulator = v27;
        }
        else
        {
          v29 = v3->penaltyTimeAccumulator - dt;
          v3->penaltyTimeAccumulator = v29;
          if ( v29 <= 0.0 )
          {
            *(_OWORD *)&v3->penaltyTimeAccumulator = 0i64;
            v3->disableMinSpeedPenaltyClear = 0;
          }
        }
        if ( !v3->disableMinSpeedPenaltyClear )
        {
          v30 = (float *)v3->body->getVelocity(v3->body, &v42);
          v31 = (float)((float)(*v30 * *v30) + (float)(v30[1] * v30[1])) + (float)(v30[2] * v30[2]);
          if ( v31 == 0.0 || fsqrt(v31) < 9.7222223 )
            *(_OWORD *)&v3->penaltyTimeAccumulator = 0i64;
        }
      }
    }
  }
  *(&result.speedMS + 1) = (float)(v3->steerLock * v3->controls.steer) / v3->steerRatio;
  Px = *(&result.speedMS + 1);
  if ( __fdtest(&Px) <= 0 )
    v32 = *(&result.speedMS + 1);
  else
    v32 = 0.0;
  v33 = (Car *)v3->tyres;
  v3->finalSteerAngleSignal = v32;
  HIBYTE(v49) = 1;
  if ( v3->tyres != (Tyre *)&v3->suspensions )
  {
    while ( *((float *)&v33->drivetrain.engine.oldVelocity + 1) > 0.0 )
    {
      v33 = (Car *)((char *)v33 + 1632);
      if ( v33 == (Car *)&v3->suspensions )
        goto LABEL_60;
    }
    HIBYTE(v49) = 0;
  }
LABEL_60:
  Autoclutch::step(&v3->autoClutch, dt);
  *((Speed *)&result.speedMS + 1) = LODWORD(Car::getSpeed(v3, (Speed *)&Px)->value);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&Px);
  if ( *(&result.speedMS + 1) >= 0.5
    || (v34 = (float *)v3->body->getAngularVelocity(v3->body, &v42),
        (float)((float)((float)(*v34 * *v34) + (float)(v34[1] * v34[1])) + (float)(v34[2] * v34[2])) >= 1.0) )
  {
    v3->sleepingFrames = 0;
  }
  else
  {
    if ( (v3->controls.gas <= 0.0099999998 || v3->controls.clutch <= 0.0099999998 || v3->drivetrain.currentGear == 1)
      && HIBYTE(v49) )
    {
      ++v3->sleepingFrames;
    }
    else
    {
      v3->sleepingFrames = 0;
    }
    if ( v3->sleepingFrames > v3->framesToSleep )
    {
      ((void (*)(IRigidBody *, int))v3->body->stop)(v3->body, 1065185444);
      ((void (*)(IRigidBody *, int))v3->fuelTankBody->stop)(v3->fuelTankBody, 1065185444);
    }
  }
  v3->body->getVelocity(v3->body, (vec3f *)&v44);
  v35 = v3->body;
  v36 = v45;
  v37 = _mm_unpacklo_ps((__m128)(unsigned int)v44, (__m128)HIDWORD(v44)).m128_u64[0];
  v38 = (float)((float)(*(float *)&v44 - v3->lastVelocity.x) * (float)(1.0 / dt)) * 0.10197838;
  *(float *)&v39 = (float)((float)(*((float *)&v44 + 1) - v3->lastVelocity.y) * (float)(1.0 / dt)) * 0.10197838;
  *(float *)&v40 = (float)((float)(v45 - v3->lastVelocity.z) * (float)(1.0 / dt)) * 0.10197838;
  *(_QWORD *)&v3->lastVelocity.x = v37;
  v3->lastVelocity.z = v36;
  *(float *)v43 = v38;
  v43[1] = v39;
  v43[2] = v40;
  v44 = v37;
  v41 = (int)v35->worldToLocalNormal(v35, &v42, (const vec3f *)v43);
  *(_QWORD *)&v3->accG.x = *(_QWORD *)v41;
  v3->accG.z = *(float *)(v41 + 8);
  Car::stepThermalObjects(v3, dt);
  Car::stepComponents(v3, dt);
  Car::updateColliderStatus(v3, dt);
  if ( !v3->physicsGUID )
    Car::stepJumpStart(v3, dt);
}
void Car::stepComponents(Car *this, float dt)
{
  ISuspension **v3; // esi
  int v4; // ebx
  unsigned int v5; // ebp
  Tyre *i; // esi
  HeaveSpring *j; // esi
  AntirollBar *k; // esi

  BrakeSystem::step(&this->brakeSystem, dt);
  EDL::step(&this->edl, dt);
  v3 = this->suspensions._Myfirst;
  v4 = 0;
  v5 = (unsigned int)((char *)this->suspensions._Mylast - (char *)v3 + 3) >> 2;
  if ( v3 > this->suspensions._Mylast )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      ((void (*)(ISuspension *, _DWORD))(*v3)->step)(*v3, LODWORD(dt));
      ++v4;
      ++v3;
    }
    while ( v4 != v5 );
  }
  for ( i = this->tyres; i != (Tyre *)&this->suspensions; ++i )
    Tyre::step(i, *(float *)&this, dt);
  for ( j = this->heaveSprings; j != (HeaveSpring *)&this->steeringSystem; ++j )
  {
    if ( j->k != 0.0 )
      HeaveSpring::step(j, dt);
  }
  DRS::step(&this->drs, dt);
  AeroMap::step(&this->aeroMap, dt);
  if ( this->kers.present )
    Kers::step(&this->kers, dt);
  if ( this->ers.present )
    ERS::step(&this->ers, dt);
  SteeringSystem::step(&this->steeringSystem, dt);
  AutoBlip::step(&this->autoBlip, dt);
  AutoShifter::step(&this->autoShift, dt);
  GearChanger::step(&this->gearChanger, dt);
  Drivetrain::step(&this->drivetrain, dt);
  for ( k = this->antirollBars; k != (AntirollBar *)&this->stabilityControl; ++k )
    AntirollBar::step(k, dt);
  ABS::step(&this->abs, dt);
  TractionControl::step(&this->tractionControl, dt);
  SpeedLimiter::step(&this->speedLimiter, dt);
  CarColliderManager::step(&this->colliderManager, dt);
  SetupManager::step(&this->setupManager, dt);
  if ( !this->physicsGUID )
  {
    Telemetry::step(&this->telemetry, dt);
    DriftModeComponent::step(&this->driftMode, dt);
    PerformanceMeter::step(&this->performanceMeter, dt);
    LapInvalidator::step(&this->lapInvalidator, dt);
    PenaltyManager::step(&this->penaltyManager, dt);
  }
  SplineLocator::step(&this->splineLocator, dt);
  StabilityControl::step(&this->stabilityControl, dt);
  TimeTransponder::step(&this->transponder, dt);
  FuelLapEvaluator::step(&this->fuelLapEvaluator, dt);
}
void Car::stepJumpStart(Car *this, float dt)
{
  PhysicsEngine *v3; // ecx
  double v4; // xmm1_8
  float *v5; // eax
  int v6; // eax
  char v7[12]; // [esp+Ch] [ebp-2Ch] BYREF
  __m128i v8; // [esp+18h] [ebp-20h]
  __m128i v9; // [esp+28h] [ebp-10h]

  if ( !PhysicsEngine::hasSessionStarted(this->ksPhysics, 0.0) )
  {
    v3 = this->ksPhysics;
    v4 = v3->lockGearboxAtStartTimeMS;
    if ( v4 != 0.0 && this->lockControlsTime <= 0.0 )
    {
      v8 = _mm_loadu_si128((const __m128i *)&v3->sessionInfo);
      v9 = _mm_loadu_si128((const __m128i *)&v3->sessionInfo.timeSecs);
      if ( this->hasGridPosition && *(double *)&v8.m128i_i64[1] - v4 <= v3->physicsTime )
      {
        v5 = (float *)((int (*)(IRigidBody *, char *, _DWORD))this->body->getPosition)(this->body, v7, 0);
        if ( (float)((float)((float)(v5[2] - this->gridPosition.z) * (float)(v5[2] - this->gridPosition.z))
                   + (float)((float)(*v5 - this->gridPosition.x) * (float)(*v5 - this->gridPosition.x))) > 0.010000001 )
        {
          PenaltyManager::addJumpStartPenalty(&this->penaltyManager);
          Event<std::wstring>::trigger(
            (Event<OnGearRequestEvent> *)&this->evOnJumpStartEvent,
            (const OnGearRequestEvent *)&this->ksPhysics->physicsTime);
        }
      }
      else
      {
        v6 = ((int (*)(IRigidBody *, char *, _DWORD))this->body->getPosition)(this->body, v7, 0);
        *(_QWORD *)&this->gridPosition.x = *(_QWORD *)v6;
        this->gridPosition.z = *(float *)(v6 + 8);
        this->hasGridPosition = 1;
      }
    }
  }
}
void Car::stepPreCacheValues(Car *this, float dt)
{
  vec3f *v3; // eax
  float v4; // xmm2_4
  float ms; // xmm0_4
  ISuspension **v6; // eax
  IRigidBody *v7; // esi
  ISuspension *v8; // edi
  ISuspension *v9; // ebx
  ISuspension *v10; // ebp
  double v11; // st7
  IRigidBody_vtbl *v12; // eax
  double v13; // st7
  float (*v14)(ISuspension *); // eax
  double v15; // st7
  float (*v16)(ISuspension *); // eax
  double v17; // st7
  float (*v18)(ISuspension *); // eax
  double v19; // st7
  int v20; // esi
  double v21; // st7
  Speed result; // [esp+18h] [ebp-14h] BYREF
  Car *v23; // [esp+1Ch] [ebp-10h]
  char v24[12]; // [esp+20h] [ebp-Ch] BYREF

  v23 = this;
  v3 = this->body->getVelocity(this->body, v24);
  v4 = (float)((float)(v3->x * v3->x) + (float)(v3->y * v3->y)) + (float)(v3->z * v3->z);
  ms = 0.0;
  if ( v4 != 0.0 )
    ms = fsqrt(v4);
  this->valueCache.speed = LODWORD(Speed::fromMS(&result, ms)->value);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v6 = this->suspensions._Myfirst;
  v7 = this->body;
  v8 = v6[1];
  v9 = v6[2];
  v10 = v6[3];
  v11 = ((double (*)(ISuspension *))(*v6)->getMass)(*v6);
  v12 = v7->__vftable;
  result.value = v11;
  v13 = ((double (*)(IRigidBody *))v12->getMass)(v7);
  v14 = v8->getMass;
  result.value = v13 + result.value;
  v15 = ((double (*)(ISuspension *))v14)(v8);
  v16 = v9->getMass;
  result.value = v15 + result.value;
  v17 = ((double (*)(ISuspension *))v16)(v9);
  v18 = v10->getMass;
  result.value = v17 + result.value;
  v19 = ((double (*)(ISuspension *))v18)(v10);
  v20 = (int)v23;
  result.value = v19 + result.value;
  v21 = Engine::getMaxPowerW(&v23->drivetrain.acEngine);
  *(float *)(v20 + 12) = v21 / result.value;
}
void Car::stepThermalObjects(Car *this, float dt)
{
  double v3; // st7
  float v4; // xmm0_4
  Engine_vtbl *v5; // eax
  int v6; // eax
  PhysicsEngine *v7; // eax
  const Speed *heat; // [esp+8h] [ebp-20h]
  float rpm; // [esp+14h] [ebp-14h] BYREF
  float v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v3 = Drivetrain::getEngineRPM(&this->drivetrain);
  v4 = (float)this->drivetrain.acEngine.data.minimum;
  rpm = v3;
  if ( rpm > (float)(v4 * 0.80000001) )
  {
    v5 = this->drivetrain.acEngine.__vftable;
    v10 = this->controls.gas;
    v6 = v5->getLimiterRPM(&this->drivetrain.acEngine);
    ThermalObject::addHeadSource(&this->water, (float)((float)((float)(rpm / (float)v6) * 20.0) * v10) + 85.0);
  }
  heat = Car::getSpeed(this, (Speed *)&rpm);
  v7 = this->ksPhysics;
  v11 = 0;
  ThermalObject::step(&this->water, dt, v7->ambientTemperature, heat);
  v11 = -1;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&rpm);
}
void Car::updateAirPressure(Car *this)
{
  PhysicsEngine *v2; // eax
  int v3; // edi
  SlipStream **v4; // esi
  SlipStream **v5; // eax
  unsigned int v6; // ebp
  SlipStream *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // [esp+14h] [ebp-18h]
  float base_air_density; // [esp+18h] [ebp-14h]
  float se; // [esp+1Ch] [ebp-10h]
  vec3f pos; // [esp+20h] [ebp-Ch] BYREF

  base_air_density = PhysicsEngine::getAirDensity(this->ksPhysics);
  if ( this->slipStreamEffectGain <= 0.0 )
  {
    this->aeroMap.airDensity = base_air_density;
  }
  else
  {
    v10 = FLOAT_1_0;
    ((void (__stdcall *)(vec3f *, _DWORD))this->body->getPosition)(&pos, 0);
    v2 = this->ksPhysics;
    v3 = 0;
    v4 = v2->slipStreams._Myfirst;
    v5 = v2->slipStreams._Mylast;
    v6 = (unsigned int)((char *)v5 - (char *)v4 + 3) >> 2;
    if ( v4 > v5 )
      v6 = 0;
    if ( v6 )
    {
      v7 = &this->slipStream;
      do
      {
        if ( *v4 != v7 )
        {
          se = SlipStream::getSlipEffect(*v4, &pos) * this->slipStreamEffectGain;
          v8 = 1.0 - se;
          if ( (float)(1.0 - se) <= 1.0 )
          {
            if ( v8 >= 0.0 )
              v9 = 1.0 - se;
            else
              v9 = 0.0;
          }
          else
          {
            v9 = FLOAT_1_0;
          }
          if ( v10 > v9 )
          {
            v10 = 1.0 - se;
            if ( v8 <= 1.0 )
            {
              if ( v8 < 0.0 )
                v10 = 0.0;
            }
            else
            {
              v10 = FLOAT_1_0;
            }
          }
          v7 = &this->slipStream;
        }
        ++v3;
        ++v4;
      }
      while ( v3 != v6 );
    }
    this->aeroMap.airDensity = (float)((float)(base_air_density - (float)(v10 * base_air_density))
                                     * (float)(0.75 / this->slipStreamEffectGain))
                             + (float)(v10 * base_air_density);
  }
}
void __usercall Car::updateBodyMass(Car *this@<ecx>, int a2@<esi>)
{
  IRigidBody_vtbl *v3; // esi
  float *v4; // eax
  IRigidBody_vtbl *v5; // edx
  float v6; // [esp+10h] [ebp-20h]
  vec3f v7; // [esp+14h] [ebp-1Ch]
  float v9; // [esp+2Ch] [ebp-4h] BYREF
  int retaddr; // [esp+30h] [ebp+0h] BYREF

  if ( (dword_186F168 & 1) == 0 )
  {
    perfCounter_32.name = "Car::updateBodyMass";
    dword_186F168 |= 1u;
    perfCounter_32.group = Physics;
    perfCounter_32.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Car::updateBodyMass" | 0xFF000000;
  }
  if ( this->ksPhysics->physicsTime - this->lastBodyMassUpdateTime > 1000.0 )
  {
    if ( this->bodyInertia.x == 0.0 && this->bodyInertia.y == 0.0 && this->bodyInertia.z == 0.0 )
    {
      ((void (*)(IRigidBody *, _DWORD, _DWORD, _DWORD, _DWORD, int))this->body->setMassExplicitInertia)(
        this->body,
        LODWORD(this->mass),
        LODWORD(this->explicitInertia.x),
        LODWORD(this->explicitInertia.y),
        LODWORD(this->explicitInertia.z),
        a2);
      _printf("explicit\n");
    }
    else
    {
      v7 = this->bodyInertia;
      v3 = this->body->__vftable;
      v6 = Car::calcBodyMass(this);
      ((void (*)(IRigidBody *, _DWORD, _DWORD, _DWORD, _DWORD, int))v3->setMassBox)(
        this->body,
        LODWORD(v6),
        LODWORD(v7.x),
        LODWORD(v7.y),
        LODWORD(v7.z),
        a2);
    }
    v4 = &v9;
    retaddr = 1036831949;
    v5 = this->fuelTankBody->__vftable;
    v9 = this->fuelKG * this->fuel;
    if ( v9 <= 0.1 )
      v4 = (float *)&retaddr;
    ((void (__stdcall *)(_DWORD, int, int))v5->setMassBox)(*(_DWORD *)v4, 1056964608, 1056964608);
    this->lastBodyMassUpdateTime = this->ksPhysics->physicsTime;
  }
}
void Car::updateColliderStatus(Car *this, float dt)
{
  Tyre *v3; // ecx
  Tyre *v4; // edx
  SurfaceDef **v5; // ecx
  PhysicsEngine *v6; // edi
  Car **v7; // esi
  Car **v8; // edi
  float *v9; // eax
  unsigned int v10; // esi
  vec3f mypos; // [esp+1Ch] [ebp-58h] BYREF
  char v12[12]; // [esp+28h] [ebp-4Ch] BYREF
  char v13[64]; // [esp+34h] [ebp-40h] BYREF

  v3 = this->tyres;
  v4 = v3 + 4;
  if ( v3 == &v3[4] )
  {
LABEL_6:
    if ( this->isCollisionOffForPits )
    {
      ((void (*)(IRigidBody *, vec3f *, _DWORD))this->body->getPosition)(this->body, &mypos, 0);
      v6 = this->ksPhysics;
      v7 = v6->cars._Myfirst;
      v8 = v6->cars._Mylast;
      if ( v7 == v8 )
      {
LABEL_11:
        this->isCollisionOffForPits = 0;
      }
      else
      {
        while ( 1 )
        {
          if ( *v7 != this )
          {
            v9 = (float *)((int (*)(IRigidBody *, char *, _DWORD))(*v7)->body->getPosition)(
                            (*v7)->body,
                            v12,
                            0);
            if ( (float)((float)((float)((float)(v9[1] - mypos.y) * (float)(v9[1] - mypos.y))
                               + (float)((float)(*v9 - mypos.x) * (float)(*v9 - mypos.x)))
                       + (float)((float)(v9[2] - mypos.z) * (float)(v9[2] - mypos.z))) < 36.0 )
              break;
          }
          if ( ++v7 == v8 )
            goto LABEL_11;
        }
      }
    }
  }
  else
  {
    v5 = &v3->surfaceDef;
    while ( !*v5 || !(*v5)->isPitlane )
    {
      v5 += 408;
      if ( v5 - 204 == (SurfaceDef **)v4 )
        goto LABEL_6;
    }
    this->isCollisionOffForPits = 1;
  }
  v10 = 2;
  if ( std::wstring::compare(&this->unixName, 0, this->unixName._Mysize, L"spectator", 9u) )
  {
    v10 = 26;
    if ( !this->isCollisionOffForPits )
      v10 = 30;
  }
  if ( *(float *)(((int (*)(IRigidBody *, char *, _DWORD))this->body->getWorldMatrix)(this->body, v13, 0) + 20) < 0.25 )
    v10 |= 1u;
  this->body->setMeshCollideMask(this->body, 0, v10);
}
