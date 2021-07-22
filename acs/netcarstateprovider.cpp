#include "netcarstateprovider.h
void NetCarStateProvider::NetCarStateProvider(NetCarStateProvider *this, const NetCarStateProviderDef *def)
{
  NetCarState *v3; // esi
  int i; // edi
  NetCarStateProvider *v5; // edi
  std::wstring *v6; // ecx
  int v7; // eax
  bool v8; // cf
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  int v11; // eax
  float v12; // esi
  Event<SessionInfo> *v13; // ecx
  IPhysicsCore *v14; // eax
  int v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // edx
  unsigned int v19; // ecx
  Node *v20; // eax
  std::unique_ptr<Node> *v21; // esi
  Node *v22; // ecx
  int v23; // esi
  int v24; // edi
  int v25; // edx
  int v26; // eax
  std::wstring *v27; // ecx
  int v28; // ecx
  int v29; // ecx
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v30; // xmm3
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v31; // xmm1
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v32; // xmm2
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v33; // xmm0
  int v34; // eax
  __m128i v35; // xmm0
  NetCarStateProvider *v36; // esi
  const __m128i *v37; // edi
  std::wstring **v38; // eax
  float v39; // xmm1_4
  std::wstring *v40; // xmm2_4
  __m128i v41; // xmm0
  __m128i v42; // xmm0
  float v43; // xmm1_4
  float v44; // xmm4_4
  float v45; // xmm1_4
  __m128i v46; // [esp+28h] [ebp-2F0h]
  __m128i v47; // [esp+38h] [ebp-2E0h]
  std::wstring v48; // [esp+48h] [ebp-2D0h] BYREF
  unsigned int v49; // [esp+60h] [ebp-2B8h]
  int v50; // [esp+64h] [ebp-2B4h]
  int v51; // [esp+68h] [ebp-2B0h]
  float v52; // [esp+74h] [ebp-2A4h] BYREF
  float v53; // [esp+78h] [ebp-2A0h]
  NetCarStateProvider *v54; // [esp+7Ch] [ebp-29Ch]
  std::wstring *_Right[4]; // [esp+80h] [ebp-298h] BYREF
  mat44f v56; // [esp+90h] [ebp-288h] BYREF
  float v57; // [esp+D0h] [ebp-248h]
  NetCarStateProvider *v58; // [esp+E4h] [ebp-234h]
  mat44f v59; // [esp+E8h] [ebp-230h] BYREF
  std::wstring section; // [esp+128h] [ebp-1F0h] BYREF
  std::wstring key; // [esp+148h] [ebp-1D0h] BYREF
  std::wstring v62; // [esp+170h] [ebp-1A8h] BYREF
  std::wstring v63; // [esp+188h] [ebp-190h] BYREF
  std::wstring ifilename; // [esp+1B0h] [ebp-168h] BYREF
  std::wstring result; // [esp+1C8h] [ebp-150h] BYREF
  std::wstring v66; // [esp+1E8h] [ebp-130h] BYREF
  INIReader v67; // [esp+200h] [ebp-118h] BYREF
  INIReader v68; // [esp+248h] [ebp-D0h] BYREF
  KN5IO v69; // [esp+290h] [ebp-88h] BYREF
  int v70; // [esp+314h] [ebp-4h]

  v54 = this;
  LODWORD(v56.M12) = def;
  v58 = this;
  v49 = (unsigned int)def->client->game;
  v48._Myres = 7;
  v48._Mysize = 0;
  v48._Bx._Buf[0] = 0;
  std::wstring::assign(&v48, L"NETCAR_STATE_PROVIDER", 0x15u);
  GameObject::GameObject(this, v48, (Game *)v49);
  v70 = 0;
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&ICarPhysicsStateProvider::`vftable';
  this->GameObject::__vftable = (NetCarStateProvider_vtbl *)&NetCarStateProvider::`vftable'{for `GameObject'};
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&NetCarStateProvider::`vftable'{for `ICarPhysicsStateProvider'};
  this->evOnSectorSplit.handlers._Myfirst = 0;
  this->evOnSectorSplit.handlers._Mylast = 0;
  this->evOnSectorSplit.handlers._Myend = 0;
  this->driverInfo.name._Myres = 7;
  this->driverInfo.name._Mysize = 0;
  this->driverInfo.name._Bx._Buf[0] = 0;
  this->driverInfo.team._Myres = 7;
  this->driverInfo.team._Mysize = 0;
  this->driverInfo.team._Bx._Buf[0] = 0;
  this->driverInfo.nationality._Myres = 7;
  this->driverInfo.nationality._Mysize = 0;
  this->driverInfo.nationality._Bx._Buf[0] = 0;
  this->driverInfo.nationCode._Myres = 7;
  this->driverInfo.nationCode._Mysize = 0;
  this->driverInfo.nationCode._Bx._Buf[0] = 0;
  this->errorVector.x = 0.0;
  this->errorVector.y = 0.0;
  this->errorVector.z = 0.0;
  this->guid = 0;
  this->ping = 0;
  this->currentSplits._Myfirst = 0;
  this->currentSplits._Mylast = 0;
  this->currentSplits._Myend = 0;
  this->personalBestSplits._Myfirst = 0;
  this->personalBestSplits._Mylast = 0;
  this->personalBestSplits._Myend = 0;
  *(_OWORD *)&this->lastUpdateTime = 0i64;
  this->laps._Myfirst = 0;
  this->laps._Mylast = 0;
  this->laps._Myend = 0;
  *(_WORD *)&this->p2p.enabled = 0;
  this->p2p.coolDownS = 0.0;
  this->p2p.timeS = 0.0;
  this->p2p.timeAccum = 0.0;
  this->p2p.activations = 0;
  this->hasEverReceivedAPacket = 0;
  this->ballastKG = 0.0;
  this->restrictor = 0.0;
  this->hasCollisionInThisStep = 0.0;
  this->qos.goodPackets = 0;
  this->qos.badPackets = 0;
  LOBYTE(v70) = 6;
  mat44f::mat44f(&this->bodyMatrix);
  this->wheelMatrix[0].M11 = 0.0;
  this->wheelMatrix[0].M12 = 0.0;
  this->wheelMatrix[0].M13 = 0.0;
  this->wheelMatrix[0].M14 = 0.0;
  this->wheelMatrix[0].M21 = 0.0;
  this->wheelMatrix[0].M22 = 0.0;
  this->wheelMatrix[0].M23 = 0.0;
  this->wheelMatrix[0].M24 = 0.0;
  this->wheelMatrix[0].M31 = 0.0;
  this->wheelMatrix[0].M32 = 0.0;
  this->wheelMatrix[0].M33 = 0.0;
  this->wheelMatrix[0].M34 = 0.0;
  this->wheelMatrix[0].M41 = 0.0;
  this->wheelMatrix[0].M42 = 0.0;
  this->wheelMatrix[0].M43 = 0.0;
  this->wheelMatrix[0].M44 = 0.0;
  this->wheelMatrix[1].M11 = 0.0;
  this->wheelMatrix[1].M12 = 0.0;
  this->wheelMatrix[1].M13 = 0.0;
  this->wheelMatrix[1].M14 = 0.0;
  this->wheelMatrix[1].M21 = 0.0;
  this->wheelMatrix[1].M22 = 0.0;
  this->wheelMatrix[1].M23 = 0.0;
  this->wheelMatrix[1].M24 = 0.0;
  this->wheelMatrix[1].M31 = 0.0;
  this->wheelMatrix[1].M32 = 0.0;
  this->wheelMatrix[1].M33 = 0.0;
  this->wheelMatrix[1].M34 = 0.0;
  this->wheelMatrix[1].M41 = 0.0;
  this->wheelMatrix[1].M42 = 0.0;
  this->wheelMatrix[1].M43 = 0.0;
  this->wheelMatrix[1].M44 = 0.0;
  this->wheelMatrix[2].M11 = 0.0;
  this->wheelMatrix[2].M12 = 0.0;
  this->wheelMatrix[2].M13 = 0.0;
  this->wheelMatrix[2].M14 = 0.0;
  this->wheelMatrix[2].M21 = 0.0;
  this->wheelMatrix[2].M22 = 0.0;
  this->wheelMatrix[2].M23 = 0.0;
  this->wheelMatrix[2].M24 = 0.0;
  this->wheelMatrix[2].M31 = 0.0;
  this->wheelMatrix[2].M32 = 0.0;
  this->wheelMatrix[2].M33 = 0.0;
  this->wheelMatrix[2].M34 = 0.0;
  this->wheelMatrix[2].M41 = 0.0;
  this->wheelMatrix[2].M42 = 0.0;
  this->wheelMatrix[2].M43 = 0.0;
  this->wheelMatrix[2].M44 = 0.0;
  this->wheelMatrix[3].M11 = 0.0;
  this->wheelMatrix[3].M12 = 0.0;
  this->wheelMatrix[3].M13 = 0.0;
  this->wheelMatrix[3].M14 = 0.0;
  this->wheelMatrix[3].M21 = 0.0;
  this->wheelMatrix[3].M22 = 0.0;
  this->wheelMatrix[3].M23 = 0.0;
  this->wheelMatrix[3].M24 = 0.0;
  this->wheelMatrix[3].M31 = 0.0;
  this->wheelMatrix[3].M32 = 0.0;
  this->wheelMatrix[3].M33 = 0.0;
  this->wheelMatrix[3].M34 = 0.0;
  this->wheelMatrix[3].M41 = 0.0;
  this->wheelMatrix[3].M42 = 0.0;
  this->wheelMatrix[3].M43 = 0.0;
  this->wheelMatrix[3].M44 = 0.0;
  this->suspMatrix[0].M11 = 0.0;
  this->suspMatrix[0].M12 = 0.0;
  this->suspMatrix[0].M13 = 0.0;
  this->suspMatrix[0].M14 = 0.0;
  this->suspMatrix[0].M21 = 0.0;
  this->suspMatrix[0].M22 = 0.0;
  this->suspMatrix[0].M23 = 0.0;
  this->suspMatrix[0].M24 = 0.0;
  this->suspMatrix[0].M31 = 0.0;
  this->suspMatrix[0].M32 = 0.0;
  this->suspMatrix[0].M33 = 0.0;
  this->suspMatrix[0].M34 = 0.0;
  this->suspMatrix[0].M41 = 0.0;
  this->suspMatrix[0].M42 = 0.0;
  this->suspMatrix[0].M43 = 0.0;
  this->suspMatrix[0].M44 = 0.0;
  this->suspMatrix[1].M11 = 0.0;
  this->suspMatrix[1].M12 = 0.0;
  this->suspMatrix[1].M13 = 0.0;
  this->suspMatrix[1].M14 = 0.0;
  this->suspMatrix[1].M21 = 0.0;
  this->suspMatrix[1].M22 = 0.0;
  this->suspMatrix[1].M23 = 0.0;
  this->suspMatrix[1].M24 = 0.0;
  this->suspMatrix[1].M31 = 0.0;
  this->suspMatrix[1].M32 = 0.0;
  v3 = this->netStates;
  this->suspMatrix[1].M33 = 0.0;
  this->suspMatrix[1].M34 = 0.0;
  this->suspMatrix[1].M41 = 0.0;
  this->suspMatrix[1].M42 = 0.0;
  this->suspMatrix[1].M43 = 0.0;
  this->suspMatrix[1].M44 = 0.0;
  this->suspMatrix[2].M11 = 0.0;
  this->suspMatrix[2].M12 = 0.0;
  this->suspMatrix[2].M13 = 0.0;
  this->suspMatrix[2].M14 = 0.0;
  this->suspMatrix[2].M21 = 0.0;
  this->suspMatrix[2].M22 = 0.0;
  this->suspMatrix[2].M23 = 0.0;
  this->suspMatrix[2].M24 = 0.0;
  this->suspMatrix[2].M31 = 0.0;
  this->suspMatrix[2].M32 = 0.0;
  this->suspMatrix[2].M33 = 0.0;
  this->suspMatrix[2].M34 = 0.0;
  this->suspMatrix[2].M41 = 0.0;
  this->suspMatrix[2].M42 = 0.0;
  this->suspMatrix[2].M43 = 0.0;
  this->suspMatrix[2].M44 = 0.0;
  this->suspMatrix[3].M11 = 0.0;
  this->suspMatrix[3].M12 = 0.0;
  this->suspMatrix[3].M13 = 0.0;
  this->suspMatrix[3].M14 = 0.0;
  this->suspMatrix[3].M21 = 0.0;
  this->suspMatrix[3].M22 = 0.0;
  this->suspMatrix[3].M23 = 0.0;
  this->suspMatrix[3].M24 = 0.0;
  this->suspMatrix[3].M31 = 0.0;
  this->suspMatrix[3].M32 = 0.0;
  this->suspMatrix[3].M33 = 0.0;
  this->suspMatrix[3].M34 = 0.0;
  this->suspMatrix[3].M41 = 0.0;
  this->suspMatrix[3].M42 = 0.0;
  this->suspMatrix[3].M43 = 0.0;
  this->suspMatrix[3].M44 = 0.0;
  for ( i = 2; i >= 0; --i )
    NetCarState::NetCarState(v3++);
  v5 = v54;
  v6 = &v54->unixName;
  v49 = -1;
  v48._Myres = 0;
  v54->lastScreenPos.x = 0.0;
  v5->lastScreenPos.y = 0.0;
  v5->lastScreenPos.z = 0.0;
  v5->wheelBasePosLS[0].M11 = 0.0;
  v5->wheelBasePosLS[0].M12 = 0.0;
  v5->wheelBasePosLS[0].M13 = 0.0;
  v5->wheelBasePosLS[0].M14 = 0.0;
  v5->wheelBasePosLS[0].M21 = 0.0;
  v5->wheelBasePosLS[0].M22 = 0.0;
  v5->wheelBasePosLS[0].M23 = 0.0;
  v5->wheelBasePosLS[0].M24 = 0.0;
  v5->wheelBasePosLS[0].M31 = 0.0;
  v5->wheelBasePosLS[0].M32 = 0.0;
  v5->wheelBasePosLS[0].M33 = 0.0;
  v5->wheelBasePosLS[0].M34 = 0.0;
  v5->wheelBasePosLS[0].M41 = 0.0;
  v5->wheelBasePosLS[0].M42 = 0.0;
  v5->wheelBasePosLS[0].M43 = 0.0;
  v5->wheelBasePosLS[0].M44 = 0.0;
  v5->wheelBasePosLS[1].M11 = 0.0;
  v5->wheelBasePosLS[1].M12 = 0.0;
  v5->wheelBasePosLS[1].M13 = 0.0;
  v5->wheelBasePosLS[1].M14 = 0.0;
  v5->wheelBasePosLS[1].M21 = 0.0;
  v5->wheelBasePosLS[1].M22 = 0.0;
  v5->wheelBasePosLS[1].M23 = 0.0;
  v5->wheelBasePosLS[1].M24 = 0.0;
  v5->wheelBasePosLS[1].M31 = 0.0;
  v5->wheelBasePosLS[1].M32 = 0.0;
  v5->wheelBasePosLS[1].M33 = 0.0;
  v5->wheelBasePosLS[1].M34 = 0.0;
  v5->wheelBasePosLS[1].M41 = 0.0;
  v5->wheelBasePosLS[1].M42 = 0.0;
  v5->wheelBasePosLS[1].M43 = 0.0;
  v5->wheelBasePosLS[1].M44 = 0.0;
  v5->wheelBasePosLS[2].M11 = 0.0;
  v5->wheelBasePosLS[2].M12 = 0.0;
  v5->wheelBasePosLS[2].M13 = 0.0;
  v5->wheelBasePosLS[2].M14 = 0.0;
  v5->wheelBasePosLS[2].M21 = 0.0;
  v5->wheelBasePosLS[2].M22 = 0.0;
  v5->wheelBasePosLS[2].M23 = 0.0;
  v5->wheelBasePosLS[2].M24 = 0.0;
  v5->wheelBasePosLS[2].M31 = 0.0;
  v5->wheelBasePosLS[2].M32 = 0.0;
  v5->wheelBasePosLS[2].M33 = 0.0;
  v5->wheelBasePosLS[2].M34 = 0.0;
  v5->wheelBasePosLS[2].M41 = 0.0;
  v5->wheelBasePosLS[2].M42 = 0.0;
  v5->wheelBasePosLS[2].M43 = 0.0;
  v5->wheelBasePosLS[2].M44 = 0.0;
  v5->wheelBasePosLS[3].M11 = 0.0;
  v5->wheelBasePosLS[3].M12 = 0.0;
  v5->wheelBasePosLS[3].M13 = 0.0;
  v5->wheelBasePosLS[3].M14 = 0.0;
  v5->wheelBasePosLS[3].M21 = 0.0;
  v5->wheelBasePosLS[3].M22 = 0.0;
  v5->wheelBasePosLS[3].M23 = 0.0;
  v5->wheelBasePosLS[3].M24 = 0.0;
  v5->wheelBasePosLS[3].M31 = 0.0;
  v5->wheelBasePosLS[3].M32 = 0.0;
  v5->wheelBasePosLS[3].M33 = 0.0;
  v5->wheelBasePosLS[3].M34 = 0.0;
  v5->wheelBasePosLS[3].M41 = 0.0;
  v5->wheelBasePosLS[3].M42 = 0.0;
  v5->wheelBasePosLS[3].M43 = 0.0;
  v5->wheelBasePosLS[3].M44 = 0.0;
  v6->_Myres = 7;
  v6->_Mysize = 0;
  v6->_Bx._Buf[0] = 0;
  _Right[1] = (std::wstring *)(LODWORD(v56.M12) + 80);
  std::wstring::assign(v6, (const std::wstring *)(LODWORD(v56.M12) + 80), v48._Myres, v49);
  v5->lastVelocity.x = 0.0;
  v5->lastVelocity.y = 0.0;
  v5->lastVelocity.z = 0.0;
  v5->instantVelocity.x = 0.0;
  v5->instantVelocity.y = 0.0;
  v5->instantVelocity.z = 0.0;
  LOBYTE(v70) = 7;
  v5->currentVelocity.x = 0.0;
  v5->currentVelocity.y = 0.0;
  v5->currentVelocity.z = 0.0;
  CarPhysicsState::CarPhysicsState(&v5->state);
  v5->wingStates._Myfirst = 0;
  v5->wingStates._Mylast = 0;
  v5->wingStates._Myend = 0;
  v5->wingControllerLists._Myfirst = 0;
  v5->wingControllerLists._Mylast = 0;
  v5->wingControllerLists._Myend = 0;
  v5->colliderModel._Myptr = 0;
  mat44f::mat44f(&v5->pitPosition);
  Triangle::Triangle(&v5->slipStream.triangle);
  v5->slipStream.speedFactorMult = 1.0;
  v5->slipStream.effectGainMult = 1.0;
  v5->slipStream.dir.x = 0.0;
  v5->slipStream.dir.y = 0.0;
  v5->slipStream.dir.z = 0.0;
  v5->slipStream.physicsEngine = 0;
  v5->slipStream.length = 0.0;
  v5->slipStream.speedFactor = 0.25;
  v5->oldDriverInfo.name._Myres = 7;
  v5->oldDriverInfo.name._Mysize = 0;
  v5->oldDriverInfo.name._Bx._Buf[0] = 0;
  v5->oldDriverInfo.team._Myres = 7;
  v5->oldDriverInfo.team._Mysize = 0;
  v5->oldDriverInfo.team._Bx._Buf[0] = 0;
  v5->oldDriverInfo.nationality._Myres = 7;
  v5->oldDriverInfo.nationality._Mysize = 0;
  v5->oldDriverInfo.nationality._Bx._Buf[0] = 0;
  v5->oldDriverInfo.nationCode._Myres = 7;
  v5->oldDriverInfo.nationCode._Mysize = 0;
  v5->oldDriverInfo.nationCode._Bx._Buf[0] = 0;
  v5->isDisconnected = 1;
  v5->drsWingSettings._Myfirst = 0;
  v5->drsWingSettings._Mylast = 0;
  v5->drsWingSettings._Myend = 0;
  v49 = 136;
  LOBYTE(v70) = 14;
  v5->smoothVelocity.x = 0.0;
  v5->smoothVelocity.y = 0.0;
  v5->smoothVelocity.z = 0.0;
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&v5->incomingStateQueue, v49);
  v5->incomingStateQueue.__vftable = (Concurrency::concurrent_queue<NetCarState,std::allocator<NetCarState> >_vtbl *)&Concurrency::concurrent_queue<NetCarState,std::allocator<NetCarState>>::`vftable';
  v5->stateCache._Myfirst = 0;
  v5->stateCache._Mylast = 0;
  v5->stateCache._Myend = 0;
  v5->graphicsOffset.x = 0.0;
  v5->graphicsOffset.y = 0.0;
  v5->graphicsOffset.z = 0.0;
  LOBYTE(v70) = 16;
  v5->tyreLocalRotation[0].M11 = 0.0;
  v5->tyreLocalRotation[0].M12 = 0.0;
  v5->tyreLocalRotation[0].M13 = 0.0;
  v5->tyreLocalRotation[0].M14 = 0.0;
  v5->tyreLocalRotation[0].M21 = 0.0;
  v5->tyreLocalRotation[0].M22 = 0.0;
  v5->tyreLocalRotation[0].M23 = 0.0;
  v5->tyreLocalRotation[0].M24 = 0.0;
  v5->tyreLocalRotation[0].M31 = 0.0;
  v5->tyreLocalRotation[0].M32 = 0.0;
  v5->tyreLocalRotation[0].M33 = 0.0;
  v5->tyreLocalRotation[0].M34 = 0.0;
  v5->tyreLocalRotation[0].M41 = 0.0;
  v5->tyreLocalRotation[0].M42 = 0.0;
  v5->tyreLocalRotation[0].M43 = 0.0;
  v5->tyreLocalRotation[0].M44 = 0.0;
  v5->tyreLocalRotation[1].M11 = 0.0;
  v5->tyreLocalRotation[1].M12 = 0.0;
  v5->tyreLocalRotation[1].M13 = 0.0;
  v5->tyreLocalRotation[1].M14 = 0.0;
  v5->tyreLocalRotation[1].M21 = 0.0;
  v5->tyreLocalRotation[1].M22 = 0.0;
  v5->tyreLocalRotation[1].M23 = 0.0;
  v5->tyreLocalRotation[1].M24 = 0.0;
  v5->tyreLocalRotation[1].M31 = 0.0;
  v5->tyreLocalRotation[1].M32 = 0.0;
  v5->tyreLocalRotation[1].M33 = 0.0;
  v5->tyreLocalRotation[1].M34 = 0.0;
  v5->tyreLocalRotation[1].M41 = 0.0;
  v5->tyreLocalRotation[1].M42 = 0.0;
  v5->tyreLocalRotation[1].M43 = 0.0;
  v5->tyreLocalRotation[1].M44 = 0.0;
  v5->tyreLocalRotation[2].M11 = 0.0;
  v5->tyreLocalRotation[2].M12 = 0.0;
  v5->tyreLocalRotation[2].M13 = 0.0;
  v5->tyreLocalRotation[2].M14 = 0.0;
  v5->tyreLocalRotation[2].M21 = 0.0;
  v5->tyreLocalRotation[2].M22 = 0.0;
  v5->tyreLocalRotation[2].M23 = 0.0;
  v5->tyreLocalRotation[2].M24 = 0.0;
  v5->tyreLocalRotation[2].M31 = 0.0;
  v5->tyreLocalRotation[2].M32 = 0.0;
  v5->tyreLocalRotation[2].M33 = 0.0;
  v5->tyreLocalRotation[2].M34 = 0.0;
  v5->tyreLocalRotation[2].M41 = 0.0;
  v5->tyreLocalRotation[2].M42 = 0.0;
  v5->tyreLocalRotation[2].M43 = 0.0;
  v5->tyreLocalRotation[2].M44 = 0.0;
  v5->tyreLocalRotation[3].M11 = 0.0;
  v5->tyreLocalRotation[3].M12 = 0.0;
  v5->tyreLocalRotation[3].M13 = 0.0;
  v5->tyreLocalRotation[3].M14 = 0.0;
  v5->tyreLocalRotation[3].M21 = 0.0;
  v5->tyreLocalRotation[3].M22 = 0.0;
  v5->tyreLocalRotation[3].M23 = 0.0;
  v5->tyreLocalRotation[3].M24 = 0.0;
  v5->tyreLocalRotation[3].M31 = 0.0;
  v5->tyreLocalRotation[3].M32 = 0.0;
  v5->tyreLocalRotation[3].M33 = 0.0;
  v5->tyreLocalRotation[3].M34 = 0.0;
  v5->tyreLocalRotation[3].M41 = 0.0;
  v5->tyreLocalRotation[3].M42 = 0.0;
  v5->tyreLocalRotation[3].M43 = 0.0;
  v5->tyreLocalRotation[3].M44 = 0.0;
  v5->lastDistanceV.x = 0.0;
  v5->lastDistanceV.y = 0.0;
  v5->lastDistanceV.z = 0.0;
  v5->lastAxis.x = 0.0;
  v5->lastAxis.y = 0.0;
  v5->lastAxis.z = 0.0;
  v5->splineLocationData.currentIndex = -1;
  v49 = 28;
  v5->carVerticalOffset = 0.0;
  v5->useLog = 1;
  v48._Myres = (unsigned int)L"system/cfg/assetto_corsa.ini";
  *(_OWORD *)&v5->lagDebug.rcvTime = 0i64;
  v5->lagDebug.wasLagging = 0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v48._Myres, v49);
  LOBYTE(v70) = 17;
  INIReader::INIReader(&v68, &ifilename);
  LOBYTE(v70) = 19;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( v68.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MULTI_LOG", 9u);
    LOBYTE(v70) = 20;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DEBUG", 5u);
    LOBYTE(v70) = 21;
    v7 = INIReader::getInt(&v68, &section, &key);
    v8 = section._Myres < 8;
    v5->useLog = v7 > 0;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v70) = 19;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v9 = std::operator+<wchar_t>(&result, L"content/cars/", _Right[1]);
  LOBYTE(v70) = 22;
  v10 = std::operator+<wchar_t>(&v63, v9, L"/data/engine.ini");
  LOBYTE(v70) = 23;
  INIReader::INIReader(&v67, v10);
  if ( v63._Myres >= 8 )
    operator delete(v63._Bx._Ptr);
  v63._Myres = 7;
  v63._Mysize = 0;
  v63._Bx._Buf[0] = 0;
  LOBYTE(v70) = 26;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v67.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LIMITER", 7u);
    LOBYTE(v70) = 27;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ENGINE_DATA", 0xBu);
    LOBYTE(v70) = 28;
    v11 = INIReader::getInt(&v67, &section, &key);
    v8 = section._Myres < 8;
    v5->state.limiterRPM = v11;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v70) = 26;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v12 = v56.M12;
  v5->guid = *(unsigned __int8 *)(LODWORD(v56.M12) + 5);
  v5->bestLap = 0;
  v5->lastLap = 0;
  v5->lastTime = 0.0;
  v5->currentAOA = 0.0;
  v5->lastSliceTimeStamp = 0.0;
  v5->lastIntegrationTime = 0.0;
  v5->client = *(ACClient **)LODWORD(v12);
  v5->rayCastProvider = *(IRayTrackCollisionProvider **)(LODWORD(v12) + 104);
  v5->sessionID = *(_BYTE *)(LODWORD(v12) + 4);
  mat44f::loadIdentity(&v5->bodyMatrix);
  v5->lastStepGas = 0.0;
  v5->lastStepSpeedkmh = 0.0;
  v5->wheelMatrix[0].M11 = 1.0;
  v5->wheelMatrix[0].M12 = 0.0;
  v5->wheelMatrix[0].M13 = 0.0;
  v5->wheelMatrix[0].M14 = 0.0;
  v5->wheelMatrix[0].M21 = 0.0;
  v5->wheelMatrix[0].M22 = 1.0;
  v5->wheelMatrix[0].M23 = 0.0;
  v5->wheelMatrix[0].M24 = 0.0;
  v5->wheelMatrix[0].M31 = 0.0;
  v5->wheelMatrix[0].M32 = 0.0;
  v5->wheelMatrix[0].M33 = 1.0;
  v5->wheelMatrix[0].M34 = 0.0;
  v5->wheelMatrix[0].M41 = 0.0;
  v5->wheelMatrix[0].M42 = 0.0;
  v5->wheelMatrix[0].M43 = 0.0;
  v5->wheelMatrix[0].M44 = 1.0;
  v5->suspMatrix[0].M11 = 1.0;
  v5->suspMatrix[0].M12 = 0.0;
  v5->suspMatrix[0].M13 = 0.0;
  v5->suspMatrix[0].M14 = 0.0;
  v5->suspMatrix[0].M21 = 0.0;
  v5->suspMatrix[0].M22 = 1.0;
  v5->suspMatrix[0].M23 = 0.0;
  v5->suspMatrix[0].M24 = 0.0;
  v5->suspMatrix[0].M31 = 0.0;
  v5->suspMatrix[0].M32 = 0.0;
  v5->suspMatrix[0].M33 = 1.0;
  v5->suspMatrix[0].M34 = 0.0;
  v5->suspMatrix[0].M41 = 0.0;
  v5->suspMatrix[0].M42 = 0.0;
  v5->suspMatrix[0].M43 = 0.0;
  v5->suspMatrix[0].M44 = 1.0;
  v5->tyreLocalRotation[0].M11 = 1.0;
  v5->tyreLocalRotation[0].M12 = 0.0;
  v5->tyreLocalRotation[0].M13 = 0.0;
  v5->tyreLocalRotation[0].M14 = 0.0;
  v5->tyreLocalRotation[0].M21 = 0.0;
  v5->tyreLocalRotation[0].M22 = 1.0;
  v5->tyreLocalRotation[0].M23 = 0.0;
  v5->tyreLocalRotation[0].M24 = 0.0;
  v5->tyreLocalRotation[0].M31 = 0.0;
  v5->tyreLocalRotation[0].M32 = 0.0;
  v5->tyreLocalRotation[0].M33 = 1.0;
  v5->tyreLocalRotation[0].M34 = 0.0;
  v5->tyreLocalRotation[0].M41 = 0.0;
  v5->tyreLocalRotation[0].M42 = 0.0;
  v5->tyreLocalRotation[0].M43 = 0.0;
  v5->tyreLocalRotation[0].M44 = 1.0;
  v5->wheelMatrix[1].M11 = 1.0;
  v5->wheelMatrix[1].M12 = 0.0;
  v5->wheelMatrix[1].M13 = 0.0;
  v5->wheelMatrix[1].M14 = 0.0;
  v5->wheelMatrix[1].M21 = 0.0;
  v5->wheelMatrix[1].M22 = 1.0;
  v5->wheelMatrix[1].M23 = 0.0;
  v5->wheelMatrix[1].M24 = 0.0;
  v5->wheelMatrix[1].M31 = 0.0;
  v5->wheelMatrix[1].M32 = 0.0;
  v5->wheelMatrix[1].M33 = 1.0;
  v5->wheelMatrix[1].M34 = 0.0;
  v5->wheelMatrix[1].M41 = 0.0;
  v5->wheelMatrix[1].M42 = 0.0;
  v5->wheelMatrix[1].M43 = 0.0;
  v5->wheelMatrix[1].M44 = 1.0;
  v5->suspMatrix[1].M11 = 1.0;
  v5->suspMatrix[1].M12 = 0.0;
  v5->suspMatrix[1].M13 = 0.0;
  v5->suspMatrix[1].M14 = 0.0;
  v5->suspMatrix[1].M21 = 0.0;
  v5->suspMatrix[1].M22 = 1.0;
  v5->suspMatrix[1].M23 = 0.0;
  v5->suspMatrix[1].M24 = 0.0;
  v5->suspMatrix[1].M31 = 0.0;
  v5->suspMatrix[1].M32 = 0.0;
  v5->suspMatrix[1].M33 = 1.0;
  v5->suspMatrix[1].M34 = 0.0;
  v5->suspMatrix[1].M41 = 0.0;
  v5->suspMatrix[1].M42 = 0.0;
  v5->suspMatrix[1].M43 = 0.0;
  v5->suspMatrix[1].M44 = 1.0;
  v5->tyreLocalRotation[1].M11 = 1.0;
  v5->tyreLocalRotation[1].M12 = 0.0;
  v5->tyreLocalRotation[1].M13 = 0.0;
  v5->tyreLocalRotation[1].M14 = 0.0;
  v5->tyreLocalRotation[1].M21 = 0.0;
  v5->tyreLocalRotation[1].M22 = 1.0;
  v5->tyreLocalRotation[1].M23 = 0.0;
  v5->tyreLocalRotation[1].M24 = 0.0;
  v5->tyreLocalRotation[1].M31 = 0.0;
  v5->tyreLocalRotation[1].M32 = 0.0;
  v5->tyreLocalRotation[1].M33 = 1.0;
  v5->tyreLocalRotation[1].M34 = 0.0;
  v5->tyreLocalRotation[1].M41 = 0.0;
  v5->tyreLocalRotation[1].M42 = 0.0;
  v5->tyreLocalRotation[1].M43 = 0.0;
  v5->tyreLocalRotation[1].M44 = 1.0;
  v5->wheelMatrix[2].M11 = 1.0;
  v5->wheelMatrix[2].M12 = 0.0;
  v5->wheelMatrix[2].M13 = 0.0;
  v5->wheelMatrix[2].M14 = 0.0;
  v5->wheelMatrix[2].M21 = 0.0;
  v5->wheelMatrix[2].M22 = 1.0;
  v5->wheelMatrix[2].M23 = 0.0;
  v5->wheelMatrix[2].M24 = 0.0;
  v5->wheelMatrix[2].M31 = 0.0;
  v5->wheelMatrix[2].M32 = 0.0;
  v5->wheelMatrix[2].M33 = 1.0;
  v5->wheelMatrix[2].M34 = 0.0;
  v5->wheelMatrix[2].M41 = 0.0;
  v5->wheelMatrix[2].M42 = 0.0;
  v5->wheelMatrix[2].M43 = 0.0;
  v5->wheelMatrix[2].M44 = 1.0;
  v5->suspMatrix[2].M11 = 1.0;
  v5->suspMatrix[2].M12 = 0.0;
  v5->suspMatrix[2].M13 = 0.0;
  v5->suspMatrix[2].M14 = 0.0;
  v5->suspMatrix[2].M21 = 0.0;
  v5->suspMatrix[2].M22 = 1.0;
  v5->suspMatrix[2].M23 = 0.0;
  v5->suspMatrix[2].M24 = 0.0;
  v5->suspMatrix[2].M31 = 0.0;
  v5->suspMatrix[2].M32 = 0.0;
  v5->suspMatrix[2].M33 = 1.0;
  v5->suspMatrix[2].M34 = 0.0;
  v5->suspMatrix[2].M41 = 0.0;
  v5->suspMatrix[2].M42 = 0.0;
  v5->suspMatrix[2].M43 = 0.0;
  v5->suspMatrix[2].M44 = 1.0;
  v5->tyreLocalRotation[2].M11 = 1.0;
  v5->tyreLocalRotation[2].M12 = 0.0;
  v5->tyreLocalRotation[2].M13 = 0.0;
  v5->tyreLocalRotation[2].M14 = 0.0;
  v5->tyreLocalRotation[2].M21 = 0.0;
  v5->tyreLocalRotation[2].M22 = 1.0;
  v5->tyreLocalRotation[2].M23 = 0.0;
  v5->tyreLocalRotation[2].M24 = 0.0;
  v5->tyreLocalRotation[2].M31 = 0.0;
  v5->tyreLocalRotation[2].M32 = 0.0;
  v5->tyreLocalRotation[2].M33 = 1.0;
  v5->tyreLocalRotation[2].M34 = 0.0;
  v5->tyreLocalRotation[2].M41 = 0.0;
  v5->tyreLocalRotation[2].M42 = 0.0;
  v5->tyreLocalRotation[2].M43 = 0.0;
  v5->tyreLocalRotation[2].M44 = 1.0;
  v5->wheelMatrix[3].M11 = 1.0;
  v5->wheelMatrix[3].M12 = 0.0;
  v5->wheelMatrix[3].M13 = 0.0;
  v5->wheelMatrix[3].M14 = 0.0;
  v5->wheelMatrix[3].M21 = 0.0;
  v5->wheelMatrix[3].M22 = 1.0;
  v5->wheelMatrix[3].M23 = 0.0;
  v5->wheelMatrix[3].M24 = 0.0;
  v5->wheelMatrix[3].M31 = 0.0;
  v5->wheelMatrix[3].M32 = 0.0;
  v5->wheelMatrix[3].M33 = 1.0;
  v5->wheelMatrix[3].M34 = 0.0;
  v5->wheelMatrix[3].M41 = 0.0;
  v5->wheelMatrix[3].M42 = 0.0;
  v5->wheelMatrix[3].M43 = 0.0;
  v5->wheelMatrix[3].M44 = 1.0;
  v5->suspMatrix[3].M11 = 1.0;
  v5->suspMatrix[3].M12 = 0.0;
  v5->suspMatrix[3].M13 = 0.0;
  v5->suspMatrix[3].M14 = 0.0;
  v5->suspMatrix[3].M21 = 0.0;
  v5->suspMatrix[3].M22 = 1.0;
  v5->suspMatrix[3].M23 = 0.0;
  v5->suspMatrix[3].M24 = 0.0;
  v5->suspMatrix[3].M31 = 0.0;
  v5->suspMatrix[3].M32 = 0.0;
  v5->suspMatrix[3].M33 = 1.0;
  v5->suspMatrix[3].M34 = 0.0;
  v5->suspMatrix[3].M41 = 0.0;
  v5->suspMatrix[3].M42 = 0.0;
  v5->suspMatrix[3].M43 = 0.0;
  v5->suspMatrix[3].M44 = 1.0;
  v5->tyreLocalRotation[3].M11 = 1.0;
  v5->tyreLocalRotation[3].M12 = 0.0;
  v5->tyreLocalRotation[3].M13 = 0.0;
  v5->tyreLocalRotation[3].M14 = 0.0;
  v5->tyreLocalRotation[3].M21 = 0.0;
  v5->tyreLocalRotation[3].M22 = 1.0;
  v5->tyreLocalRotation[3].M23 = 0.0;
  v5->tyreLocalRotation[3].M24 = 0.0;
  v5->tyreLocalRotation[3].M31 = 0.0;
  v5->tyreLocalRotation[3].M32 = 0.0;
  v5->tyreLocalRotation[3].M33 = 1.0;
  v5->tyreLocalRotation[3].M34 = 0.0;
  v5->tyreLocalRotation[3].M41 = 0.0;
  v5->tyreLocalRotation[3].M42 = 0.0;
  v5->tyreLocalRotation[3].M43 = 0.0;
  v5->tyreLocalRotation[3].M44 = 1.0;
  if ( &v5->driverInfo != (DriverInfo *)(LODWORD(v12) + 8) )
    std::wstring::assign(&v5->driverInfo.name, (const std::wstring *)(LODWORD(v12) + 8), 0, 0xFFFFFFFF);
  if ( &v5->driverInfo.team != (std::wstring *)(LODWORD(v12) + 32) )
    std::wstring::assign(&v5->driverInfo.team, (const std::wstring *)(LODWORD(v12) + 32), 0, 0xFFFFFFFF);
  if ( &v5->driverInfo.nationCode != (std::wstring *)(LODWORD(v12) + 56) )
    std::wstring::assign(&v5->driverInfo.nationCode, (const std::wstring *)(LODWORD(v12) + 56), 0, 0xFFFFFFFF);
  v5->avatar = 0;
  NetCarStateProvider::initPhysicsValues(v5);
  v49 = (unsigned int)v5;
  v48._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_62ce881c8e81cb63ae863b7bae1f48cb_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(_DWORD *)&v48._Bx._Alias[4] = v5;
  v48._Mysize = (unsigned int)&v48;
  v13 = (Event<SessionInfo> *)(*(_DWORD *)(LODWORD(v12) + 108) + 116);
  LOBYTE(v70) = 26;
  Event<float>::addHandler(v13, (std::function<void __cdecl(SessionInfo const &)>)v48, v5);
  v14 = PhysicsEngine::getCore((PhysicsEngine *)(*(_DWORD *)(LODWORD(v12) + 108) + 56));
  v15 = (int)v14->createRigidBody(v14);
  v5->body = (IRigidBody *)v15;
  (*(void (**)(int, int, int, int, int))(*(_DWORD *)v15 + 28))(
    v15,
    1148846080,
    1068708659,
    1065353216,
    1082130432);
  v16 = std::operator+<wchar_t>(&v66, L"content/cars/", (const std::wstring *)(LODWORD(v12) + 80));
  LOBYTE(v70) = 30;
  std::operator+<wchar_t>(&v62, v16, L"/collider.kn5");
  LOBYTE(v70) = 32;
  if ( v66._Myres >= 8 )
    operator delete(v66._Bx._Ptr);
  v66._Myres = 7;
  v66._Bx._Buf[0] = 0;
  v17 = &v62;
  if ( v62._Myres >= 8 )
    v17 = (std::wstring *)v62._Bx._Ptr;
  v66._Mysize = 0;
  _printf("LOADING COLLIDER MESH FILE: %S FOR NETCAR\n", v17->_Bx._Buf);
  KN5IO::KN5IO(&v69, v5->game->graphics);
  v18 = &v62;
  section._Myres = 7;
  if ( v62._Myres >= 8 )
    v18 = (std::wstring *)v62._Bx._Ptr;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v70) = 33;
  if ( v18->_Bx._Buf[0] )
    v19 = wcslen(v18->_Bx._Buf);
  else
    v19 = 0;
  std::wstring::assign(&section, v18->_Bx._Buf, v19);
  LOBYTE(v70) = 34;
  v20 = KN5IO::load(&v69, &section);
  v21 = &v5->colliderModel;
  if ( &v5->colliderModel == (std::unique_ptr<Node> *)&v52 )
  {
    if ( v20 )
      ((void (*)(Node *, int))v20->~Node)(v20, 1);
  }
  else
  {
    v22 = v21->_Myptr;
    v21->_Myptr = v20;
    if ( v22 )
      ((void (*)(Node *, int))v22->~Node)(v22, 1);
  }
  LOBYTE(v70) = 33;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v23 = __RTDynamicCast(
          *(*v21->_Myptr->nodes._Myfirst)->nodes._Myfirst,
          0,
          &Node `RTTI Type Descriptor',
          &Mesh `RTTI Type Descriptor',
          0);
  _Right[1] = (std::wstring *)v23;
  std::vector<vec3f>::vector<vec3f>(
    (std::vector<vec3f> *)&_Right[2],
    (*(_DWORD *)&_Right[1][9]._Bx._Alias[12] - *(_DWORD *)&_Right[1][9]._Bx._Alias[8]) / 44);
  LOBYTE(v70) = 35;
  v53 = 0.0;
  if ( (*(_DWORD *)(v23 + 228) - *(_DWORD *)(v23 + 224)) / 44 )
  {
    v24 = 0;
    v25 = 0;
    do
    {
      v26 = *(_DWORD *)(v23 + 224);
      v24 += 6;
      v27 = _Right[2];
      ++LODWORD(v53);
      *(_QWORD *)&_Right[2]->_Bx._Buf[v24 - 6] = *(_QWORD *)(v26 + v25);
      *(_DWORD *)&v27->_Bx._Buf[v24 - 2] = *(_DWORD *)(v26 + v25 + 8);
      v28 = *(_DWORD *)(v23 + 228) - *(_DWORD *)(v23 + 224);
      _Right[0] = (std::wstring *)(v25 + 44);
      v25 += 44;
    }
    while ( LODWORD(v53) < v28 / 44 );
    v5 = v54;
  }
  mat44f::createIdentity((mat44f *)&v56.M13);
  v56.M43 = v5->graphicsOffset.x;
  v56.M44 = v5->graphicsOffset.y;
  v57 = v5->graphicsOffset.z;
  if ( v5->graphicsPitchRotation == 0.0 )
  {
    section._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_load_si128((const __m128i *)&v56.M43);
    key._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_load_si128((const __m128i *)&v56.M33);
    v63._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_load_si128((const __m128i *)&v56.M23);
    result._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_load_si128((const __m128i *)&v56.M13);
  }
  else
  {
    LODWORD(v53) = __libm_sse2_cosf(v50, v51).m128_u32[0];
    LODWORD(v52) = __libm_sse2_sinf(v29).m128_u32[0];
    *(float *)_Right = 1.0 - v53;
    mat44f::mat44f(&v59);
    v59.M44 = 1.0;
    v59.M11 = v53 + *(float *)_Right;
    v59.M22 = v53 + (float)(*(float *)_Right * 0.0);
    v59.M33 = v59.M22;
    v30 = *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)&v59.M41;
    v59.M12 = (float)(v52 * 0.0) + (float)(*(float *)_Right * 0.0);
    v59.M21 = (float)(*(float *)_Right * 0.0) - (float)(v52 * 0.0);
    v59.M13 = v59.M21;
    v59.M31 = v59.M12;
    v59.M23 = v52 + (float)(*(float *)_Right * 0.0);
    v59.M32 = (float)(*(float *)_Right * 0.0) - v52;
    v31 = *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)&v59.M21;
    v32 = *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)&v59.M31;
    v33 = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)DirectX::XMMatrixMultiply(
                                                                   (__m128 *)&v56.M13,
                                                                   *(__m128 *)&v59.M11);
    section._Bx = v30;
    key._Bx = v32;
    v63._Bx = v31;
    result._Bx = v33;
  }
  v34 = std::wstring::compare(&v5->unixName, 0, v5->unixName._Mysize, L"spectator", 9u);
  v35 = _mm_load_si128((const __m128i *)&result);
  v49 = v5->guid + 1;
  if ( v34 )
    v48._Myres = 4;
  else
    v48._Myres = 0;
  v48._Mysize = 8;
  v46 = _mm_load_si128((const __m128i *)&v63);
  v47 = _mm_load_si128((const __m128i *)&key);
  v48._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_load_si128((const __m128i *)&section);
  LODWORD(v52) = (*(_DWORD *)(v23 + 240) - *(_DWORD *)(v23 + 236)) >> 1;
  ((void (*)(IRigidBody *, std::wstring *, int, unsigned int, _DWORD, int, int, int, int, int, int, int, int, int, int, int, int, wchar_t *, _DWORD, _DWORD, _DWORD, int, unsigned int, unsigned int))v54->body->addMeshCollider)(
    v54->body,
    _Right[2],
    ((char *)_Right[3] - (char *)_Right[2]) / 12,
    _Right[1][9]._Myres,
    LODWORD(v52),
    v35.m128i_i32[0],
    v35.m128i_i32[1],
    v35.m128i_i32[2],
    v35.m128i_i32[3],
    v46.m128i_i32[0],
    v46.m128i_i32[1],
    v46.m128i_i32[2],
    v46.m128i_i32[3],
    v47.m128i_i32[0],
    v47.m128i_i32[1],
    v47.m128i_i32[2],
    v47.m128i_i32[3],
    v48._Bx._Ptr,
    *(_DWORD *)&v48._Bx._Alias[4],
    *(_DWORD *)&v48._Bx._Alias[8],
    *(_DWORD *)&v48._Bx._Alias[12],
    8,
    v48._Myres,
    v49);
  v36 = v54;
  v37 = (const __m128i *)LODWORD(v56.M12);
  v54->state.physicsGUID = v54->guid;
  PhysicsEngine::addAdditionalPhysicsProvider(
    (PhysicsEngine *)(v37[6].m128i_i32[3] + 56),
    &v36->ICarPhysicsStateProvider);
  v38 = (std::wstring **)&v52;
  LODWORD(v39) = COERCE_UNSIGNED_INT(v36->wheelBasePosLS[2].M42 - v36->tyreRadius[2]) ^ _xmm;
  v40 = (std::wstring *)(COERCE_UNSIGNED_INT(v36->wheelBasePosLS[0].M42 - v36->tyreRadius[0]) ^ _xmm);
  *(__m128i *)&v36->pitPosition.M11 = _mm_loadu_si128(v37 + 7);
  v41 = _mm_loadu_si128(v37 + 8);
  if ( v39 <= *(float *)&v40 )
    v38 = _Right;
  v52 = v39;
  *(__m128i *)&v36->pitPosition.M21 = v41;
  v42 = _mm_loadu_si128(v37 + 9);
  _Right[0] = v40;
  v43 = *(float *)v38;
  *(__m128i *)&v36->pitPosition.M31 = v42;
  *(__m128i *)&v36->pitPosition.M41 = _mm_loadu_si128(v37 + 10);
  *(float *)v42.m128i_i32 = v36->pitPosition.M41 + (float)(v36->pitPosition.M21 * v43);
  v44 = (float)(v36->pitPosition.M23 * v43) + v36->pitPosition.M43;
  v45 = v36->pitPosition.M42 + (float)(v36->pitPosition.M22 * v43);
  LODWORD(v36->pitPosition.M41) = v42.m128i_i32[0];
  v36->pitPosition.M43 = v44;
  v36->pitPosition.M42 = v45;
  SlipStream::init(&v36->slipStream, (PhysicsEngine *)(v37[6].m128i_i32[3] + 56));
  NetCarStateProvider::initWings(v36);
  NetCarStateProvider::initDRS(v36);
  NetCarStateProvider::initP2P(v36);
  if ( v36->isDisconnected )
    v36->body->setMeshCollideCategory(v36->body, 0, 0);
  LOBYTE(v70) = 33;
  if ( _Right[2] )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&_Right[2]);
    operator delete(_Right[2]);
    _Right[2] = 0;
    _Right[3] = 0;
    v56.M11 = 0.0;
  }
  LOBYTE(v70) = 32;
  KN5IO::~KN5IO(&v69);
  if ( v62._Myres >= 8 )
    operator delete(v62._Bx._Ptr);
  v62._Myres = 7;
  v62._Mysize = 0;
  v62._Bx._Buf[0] = 0;
  LOBYTE(v70) = 19;
  INIReader::~INIReader(&v67);
  LOBYTE(v70) = 16;
  INIReader::~INIReader(&v68);
}
void NetCarStateProvider::~NetCarStateProvider(NetCarStateProvider *this)
{
  std::vector<DRSWingSetting> *v2; // edi
  Node *v3; // ecx
  std::vector<WingState> *v4; // edi
  std::vector<Lap> *v5; // edi
  std::vector<unsigned int> *v6; // edi
  std::vector<unsigned int> *v7; // edi

  this->GameObject::__vftable = (NetCarStateProvider_vtbl *)&NetCarStateProvider::`vftable'{for `GameObject'};
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&NetCarStateProvider::`vftable'{for `ICarPhysicsStateProvider'};
  std::vector<CarPhysicsState>::_Tidy(&this->stateCache);
  Concurrency::concurrent_queue<NetCarState,std::allocator<NetCarState>>::~concurrent_queue<NetCarState,std::allocator<NetCarState>>(&this->incomingStateQueue);
  v2 = &this->drsWingSettings;
  if ( this->drsWingSettings._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->drsWingSettings);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    this->drsWingSettings._Mylast = 0;
    this->drsWingSettings._Myend = 0;
  }
  SetupItemText::~SetupItemText(&this->oldDriverInfo);
  SlipStream::~SlipStream(&this->slipStream);
  v3 = this->colliderModel._Myptr;
  if ( v3 )
    ((void (*)(Node *, int))v3->~Node)(v3, 1);
  std::vector<std::vector<std::unique_ptr<DynamicWingController>>>::_Tidy(&this->wingControllerLists);
  v4 = &this->wingStates;
  if ( this->wingStates._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->wingStates);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->wingStates._Mylast = 0;
    this->wingStates._Myend = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->state.speed);
  if ( this->unixName._Myres >= 8 )
    operator delete(this->unixName._Bx._Ptr);
  this->unixName._Myres = 7;
  this->unixName._Mysize = 0;
  v5 = &this->laps;
  this->unixName._Bx._Buf[0] = 0;
  if ( this->laps._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->laps);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(v5->_Myfirst, this->laps._Mylast);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->laps._Mylast = 0;
    this->laps._Myend = 0;
  }
  v6 = &this->personalBestSplits;
  if ( this->personalBestSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->personalBestSplits);
    operator delete(v6->_Myfirst);
    v6->_Myfirst = 0;
    this->personalBestSplits._Mylast = 0;
    this->personalBestSplits._Myend = 0;
  }
  v7 = &this->currentSplits;
  if ( this->currentSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->currentSplits);
    operator delete(v7->_Myfirst);
    v7->_Myfirst = 0;
    this->currentSplits._Mylast = 0;
    this->currentSplits._Myend = 0;
  }
  SetupItemText::~SetupItemText(&this->driverInfo);
  if ( this->evOnSectorSplit.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnSectorSplit);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnSectorSplit,
      (Task *)this->evOnSectorSplit.handlers._Myfirst,
      (Task *)this->evOnSectorSplit.handlers._Mylast);
    operator delete(this->evOnSectorSplit.handlers._Myfirst);
    this->evOnSectorSplit.handlers._Myfirst = 0;
    this->evOnSectorSplit.handlers._Mylast = 0;
    this->evOnSectorSplit.handlers._Myend = 0;
  }
  this->ICarPhysicsStateProvider::__vftable = (ICarPhysicsStateProvider_vtbl *)&ICarPhysicsStateProvider::`vftable';
  GameObject::~GameObject(this);
}
NetCarStateProvider *NetCarStateProvider::`vector deleting destructor'(char *this, unsigned int a2)
{
  return NetCarStateProvider::`vector deleting destructor'((NetCarStateProvider *)(this - 52), a2);
}
NetCarStateProvider *NetCarStateProvider::`vector deleting destructor'(NetCarStateProvider *this, unsigned int a2)
{
  NetCarStateProvider::~NetCarStateProvider(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void NetCarStateProvider::activateP2P(NetCarStateProvider *this)
{
  --this->p2p.activations;
  this->p2p.timeAccum = 0.0;
  this->p2p.active = 1;
}
void NetCarStateProvider::debugLag(NetCarStateProvider *this, bool isLagging, long double physics_time)
{
  double v4; // xmm1_8
  bool v5; // bl

  this->lagDebug.physicsTime = physics_time;
  v4 = this->netStates[0].rcvTime;
  this->lagDebug.rcvTime = v4;
  v5 = isLagging && this->hasEverReceivedAPacket;
  if ( this->lagDebug.wasLagging )
    goto LABEL_9;
  if ( v5 )
  {
    _printf(
      "CAR S.ID: %d WASN'T LAGGING, NOW LAG. TD:%f PT:%f RT:%f\n",
      this->sessionID,
      (double)(physics_time - v4),
      (double)physics_time,
      v4);
    this->lagDebug.wasLagging = 1;
  }
  if ( this->lagDebug.wasLagging )
  {
LABEL_9:
    if ( !v5 )
    {
      _printf(
        "CAR S.ID:%d  STOPPED LAGGING, NOW LAG TD:%f PT:%f RT:%f\n",
        this->sessionID,
        (double)this->lagDebug.physicsTime - (double)this->lagDebug.rcvTime,
        (double)this->lagDebug.physicsTime,
        (double)this->lagDebug.rcvTime);
      this->lagDebug.wasLagging = 0;
    }
  }
}
void NetCarStateProvider::getPhysicsState(NetCarStateProvider *this, CarPhysicsState *physicsState)
{
  this->state.damageZoneLevel[0] = 20.0;
  this->state.slipAngle[3] = 100.0;
  this->state.engineLifeLeft = 1.0;
  this->state.slipRatio[0] = 100.0;
  this->state.turboBov = 1.0;
  this->state.slipRatio[1] = 100.0;
  this->state.turboBoostLevel = 1.0;
  this->state.slipRatio[2] = 100.0;
  this->state.tyreGrain[0] = 1.0;
  qmemcpy(physicsState, &this->unixName._Mysize, sizeof(CarPhysicsState));
}
mat44f *NetCarStateProvider::getSmoothBodyMatrix(NetCarStateProvider *this, mat44f *result, long double physics_time, CarPhysicsState *state)
{
  mat44f *v4; // edi
  float v6; // xmm6_4
  double v7; // xmm0_8
  float v8; // xmm0_4
  double v9; // xmm5_8
  double v10; // xmm4_8
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm7_4
  __m128 v14; // xmm3
  float v15; // xmm5_4
  __m128 v16; // xmm4
  float v17; // xmm0_4
  float v18; // xmm5_4
  __m128 v19; // xmm0
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  mat44f *v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  __m128 v32; // xmm7
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm6_4
  const __m128i *v36; // eax
  float v37; // xmm0_4
  float v38; // xmm1_4
  unsigned int v39; // xmm1_4
  float v40; // xmm2_4
  IRayTrackCollisionProvider *v41; // ecx
  int v42; // xmm0_4
  double v43; // xmm0_8
  __int128 v44; // xmm5
  float v45; // xmm0_4
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  float v48; // xmm2_4
  float v49; // xmm0_4
  Speed *v50; // eax
  mat44f *v51; // eax
  int v52; // [esp+14h] [ebp-E4h]
  int v53; // [esp+18h] [ebp-E0h]
  mat44f v54; // [esp+1Ch] [ebp-DCh] BYREF
  int v55; // [esp+5Ch] [ebp-9Ch] BYREF
  __int128 v56; // [esp+60h] [ebp-98h]
  int v57; // [esp+70h] [ebp-88h]
  int v58; // [esp+74h] [ebp-84h]
  char v59; // [esp+78h] [ebp-80h]
  int v60; // [esp+7Ch] [ebp-7Ch]
  mat44f matrix2; // [esp+80h] [ebp-78h] BYREF
  float v62; // [esp+C8h] [ebp-30h]
  int v63; // [esp+CCh] [ebp-2Ch] BYREF
  long double v64; // [esp+D0h] [ebp-28h]
  float v65; // [esp+D8h] [ebp-20h]
  float v66; // [esp+DCh] [ebp-1Ch]
  float v67; // [esp+E0h] [ebp-18h]
  float v68; // [esp+E4h] [ebp-14h]
  float v69; // [esp+E8h] [ebp-10h]
  vec3f translation; // [esp+ECh] [ebp-Ch] BYREF

  v4 = result;
  translation.x = 0.0;
  translation.y = 0.0;
  translation.z = 0.0;
  mat44f::createFromEuler(result, &this->netStates[0].rotation, &translation);
  translation.x = 0.0;
  translation.y = 0.0;
  translation.z = 0.0;
  mat44f::createFromEuler(&matrix2, &this->netStates[1].rotation, &translation);
  v6 = FLOAT_1_0;
  v7 = this->client->remoteFactor;
  v64 = physics_time - this->netStates[0].rcvTime;
  v8 = v64 / v7;
  v65 = 1.0 - v8;
  if ( (float)(1.0 - v8) <= 1.0 )
  {
    if ( (float)(1.0 - v8) < 0.0 )
      v65 = 0.0;
  }
  else
  {
    v65 = FLOAT_1_0;
  }
  v9 = this->netStates[0].timeStamp;
  v10 = this->netStates[1].timeStamp;
  translation = this->netStates[0].velocity;
  v11 = (v9 - v10) * 0.001;
  *(float *)&result = v11;
  if ( v11 == 0.0 )
  {
    v13 = 0.0;
    v69 = 0.0;
    *(float *)&result = 0.0;
  }
  else
  {
    v12 = (float)(this->netStates[0].velocity.z - this->netStates[1].velocity.z) * (float)(1.0 / *(float *)&result);
    v13 = (float)(this->netStates[0].velocity.x - this->netStates[1].velocity.x) * (float)(1.0 / *(float *)&result);
    v69 = (float)(this->netStates[0].velocity.y - this->netStates[1].velocity.y) * (float)(1.0 / *(float *)&result);
    *(float *)&result = v12;
  }
  if ( v9 > v10 )
  {
    v14 = (__m128)LODWORD(translation.y);
    v15 = translation.x;
    v16 = (__m128)LODWORD(translation.z);
    if ( (float)((float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v15 * v15))
               + (float)(v16.m128_f32[0] * v16.m128_f32[0])) <= 1.0 )
    {
      this->currentAOA = 0.0;
    }
    else
    {
      translation = this->netStates[0].velocity;
      v17 = v64 * 0.001;
      v16.m128_f32[0] = v16.m128_f32[0] + (float)(*(float *)&result * v17);
      v14.m128_f32[0] = v14.m128_f32[0] + (float)(v69 * v17);
      v18 = v15 + (float)(v13 * v17);
      v69 = translation.y;
      v68 = translation.z;
      v19 = (__m128)LODWORD(translation.z);
      *((float *)&v64 + 1) = v18;
      v67 = v14.m128_f32[0];
      v66 = v16.m128_f32[0];
      v62 = v16.m128_f32[0];
      result = (mat44f *)LODWORD(translation.x);
      v20 = fsqrt(
              (float)((float)(translation.x * translation.x) + (float)(translation.y * translation.y))
            + (float)(v19.m128_f32[0] * v19.m128_f32[0]));
      if ( v20 != 0.0 )
      {
        v19 = (__m128)LODWORD(FLOAT_1_0);
        v69 = translation.y * (float)(1.0 / v20);
        *(float *)&result = translation.x * (float)(1.0 / v20);
        v68 = translation.z * (float)(1.0 / v20);
      }
      v19.m128_f32[0] = v18;
      *(_QWORD *)&translation.x = _mm_unpacklo_ps(v19, v14).m128_u64[0];
      v21 = v14.m128_f32[0] * v14.m128_f32[0];
      translation.z = v62;
      v22 = translation.y;
      v23 = v62;
      v24 = fsqrt((float)(v21 + (float)(v18 * v18)) + (float)(v16.m128_f32[0] * v16.m128_f32[0]));
      if ( v24 == 0.0 )
      {
        v26 = translation.x;
      }
      else
      {
        v25 = 1.0 / v24;
        v26 = v18 * (float)(1.0 / v24);
        v22 = translation.y * v25;
        v23 = v62 * v25;
      }
      v27 = (float)((float)(v26 * *(float *)&result) + (float)(v22 * v69)) + (float)(v23 * v68);
      if ( v27 <= -1.0 || v27 >= 1.0 )
      {
        *(float *)&result = 0.0;
      }
      else
      {
        v28 = (mat44f *)__libm_sse2_acosf().m128_u32[0];
        v16 = (__m128)LODWORD(v66);
        v18 = *((float *)&v64 + 1);
        v6 = FLOAT_1_0;
        result = v28;
      }
      v29 = this->netStates[0].velocity.z;
      v30 = this->netStates[0].velocity.y;
      v32 = (__m128)LODWORD(v67);
      v31 = this->netStates[0].velocity.x;
      v32.m128_f32[0] = (float)(v67 * v29) - (float)(v16.m128_f32[0] * v30);
      v16.m128_f32[0] = (float)(v16.m128_f32[0] * v31) - (float)(v18 * v29);
      *(_QWORD *)&translation.x = _mm_unpacklo_ps(v32, v16).m128_u64[0];
      v62 = (float)(v18 * v30) - (float)(v67 * v31);
      translation.z = v62;
      v33 = fsqrt(
              (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v32.m128_f32[0] * v32.m128_f32[0]))
            + (float)(v62 * v62));
      if ( v33 == 0.0 )
      {
        v66 = translation.z;
        v69 = translation.y;
        v67 = translation.x;
      }
      else
      {
        v69 = translation.y * (float)(v6 / v33);
        v67 = v32.m128_f32[0] * (float)(v6 / v33);
        v66 = translation.z * (float)(v6 / v33);
      }
      result = (mat44f *)((unsigned int)result ^ _xmm);
      LODWORD(v68) = __libm_sse2_cosf(v52, v53).m128_u32[0];
      HIDWORD(v64) = __libm_sse2_sinf().m128_u32[0];
      *(float *)&result = 1.0 - v68;
      mat44f::mat44f(&matrix2);
      matrix2.M44 = 1.0;
      matrix2.M22 = (float)((float)(v69 * v69) * *(float *)&result) + v68;
      matrix2.M11 = (float)((float)(v67 * v67) * *(float *)&result) + v68;
      v34 = (float)(v67 * v69) * *(float *)&result;
      matrix2.M33 = (float)((float)(v66 * v66) * *(float *)&result) + v68;
      matrix2.M21 = v34 - (float)(v66 * *((float *)&v64 + 1));
      matrix2.M12 = (float)(v66 * *((float *)&v64 + 1)) + v34;
      v35 = (float)(v69 * v66) * *(float *)&result;
      matrix2.M13 = (float)((float)(v67 * v66) * *(float *)&result) - (float)(v69 * *((float *)&v64 + 1));
      matrix2.M31 = (float)(v69 * *((float *)&v64 + 1)) + (float)((float)(v67 * v66) * *(float *)&result);
      matrix2.M23 = (float)(v67 * *((float *)&v64 + 1)) + v35;
      matrix2.M32 = v35 - (float)(v67 * *((float *)&v64 + 1));
      mul(v4, v4, &matrix2);
    }
    *(__m128i *)&matrix2.M11 = _mm_loadu_si128((const __m128i *)v4);
    *(__m128i *)&matrix2.M21 = _mm_loadu_si128((const __m128i *)&v4->M21);
    *(__m128i *)&matrix2.M31 = _mm_loadu_si128((const __m128i *)&v4->M31);
    *(__m128i *)&matrix2.M41 = _mm_loadu_si128((const __m128i *)&v4->M41);
    v36 = (const __m128i *)lerp(&v54, &this->bodyMatrix, &matrix2, 0.1);
    *(__m128i *)&v4->M11 = _mm_loadu_si128(v36);
    *(__m128i *)&v4->M21 = _mm_loadu_si128(v36 + 1);
    *(__m128i *)&v4->M31 = _mm_loadu_si128(v36 + 2);
    *(__m128i *)&v4->M41 = _mm_loadu_si128(v36 + 3);
  }
  NetCarStateProvider::projectNetStatePos(this, &translation, 0, physics_time);
  if ( (float)((float)((float)(this->errorVector.x * this->errorVector.x)
                     + (float)(this->errorVector.y * this->errorVector.y))
             + (float)(this->errorVector.z * this->errorVector.z)) >= 9.0 )
  {
    *(vec3f *)&v4->M41 = translation;
  }
  else
  {
    v37 = translation.y + (float)(this->errorVector.y * v65);
    v38 = translation.z + (float)(this->errorVector.z * v65);
    v4->M41 = translation.x + (float)(v65 * this->errorVector.x);
    v4->M42 = v37;
    v4->M43 = v38;
  }
  *(float *)&v39 = v4->M42 + 1.0;
  v40 = v4->M43;
  v4->M44 = 1.0;
  v41 = this->rayCastProvider;
  v56 = 0i64;
  v57 = 0;
  v42 = LODWORD(v4->M41);
  v58 = 0;
  v55 = 0;
  v59 = 0;
  v60 = 0;
  translation.x = 0.0;
  translation.y = -1.0;
  translation.z = 0.0;
  v63 = v42;
  v64 = COERCE_DOUBLE(__PAIR64__(LODWORD(v40), v39));
  ((void (*)(IRayTrackCollisionProvider *, int *, vec3f *, int *, int))v41->rayCast)(
    v41,
    &v63,
    &translation,
    &v55,
    1092616192);
  if ( v59 )
    v4->M42 = this->netStates[0].targetHeight + *((float *)&v56 + 1);
  v43 = (physics_time - this->lastIntegrationTime) * 0.001;
  if ( v43 != 0.0 )
  {
    v44 = LODWORD(FLOAT_1_0);
    v45 = v43;
    *(float *)&v44 = 1.0 / v45;
    v46 = (__m128)v44;
    v47 = (__m128)v44;
    v46.m128_f32[0] = *(float *)&v44 * (float)(v4->M41 - this->bodyMatrix.M41);
    v47.m128_f32[0] = *(float *)&v44 * (float)(v4->M42 - this->bodyMatrix.M42);
    *(float *)&v44 = *(float *)&v44 * (float)(v4->M43 - this->bodyMatrix.M43);
    *(_QWORD *)&this->instantVelocity.x = _mm_unpacklo_ps(v46, v47).m128_u64[0];
    v62 = *(float *)&v44;
    LODWORD(this->instantVelocity.z) = v44;
  }
  v48 = (float)((float)(this->instantVelocity.x * this->instantVelocity.x)
              + (float)(this->instantVelocity.y * this->instantVelocity.y))
      + (float)(this->instantVelocity.z * this->instantVelocity.z);
  v49 = 0.0;
  if ( v48 != 0.0 )
    v49 = fsqrt(v48);
  v50 = Speed::fromMS((Speed *)&result, v49);
  state->speed = LODWORD(v50->value);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v51 = v4;
  this->lastIntegrationTime = physics_time;
  return v51;
}
mat44f *NetCarStateProvider::getTyreMatrix(NetCarStateProvider *this, mat44f *result, int index)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm2
  __int128 v10; // xmm3
  mat44f *v11; // eax
  DirectX::XMMATRIX M2; // [esp+10h] [ebp-40h] BYREF

  mat44f::createIdentity(result);
  v4 = *(__m128 *)&this->wheelMatrix[index].M21;
  v5 = *(__m128 *)&this->wheelMatrix[index].M31;
  v6 = *(__m128 *)&this->wheelMatrix[index].M41;
  M2.r[0] = *(__m128 *)&this->wheelMatrix[index].M11;
  v7 = *(__m128 *)&this->tyreLocalRotation[index].M11;
  M2.r[1] = v4;
  v8 = *(_OWORD *)&this->tyreLocalRotation[index].M21;
  M2.r[2] = v5;
  v9 = *(_OWORD *)&this->tyreLocalRotation[index].M31;
  M2.r[3] = v6;
  v10 = *(_OWORD *)&this->tyreLocalRotation[index].M41;
  *(__m128 *)&result->M11 = DirectX::XMMatrixMultiply(M2.r, v7);
  v11 = result;
  *(_OWORD *)&result->M21 = v8;
  *(_OWORD *)&result->M31 = v9;
  *(_OWORD *)&result->M41 = v10;
  return v11;
}
void NetCarStateProvider::getWingState(NetCarStateProvider *this, std::vector<WingState> *ws)
{
  std::vector<WingState>::operator=(ws, (const std::vector<WingState> *)this->state.wearMult);
}
void NetCarStateProvider::initDRS(NetCarStateProvider *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  unsigned int i; // esi
  std::wstring *v5; // eax
  DRSWingSetting s; // [esp+Ch] [ebp-ECh] BYREF
  std::wstring key; // [esp+14h] [ebp-E4h] BYREF
  std::wstring v8; // [esp+2Ch] [ebp-CCh] BYREF
  std::wstring result; // [esp+44h] [ebp-B4h] BYREF
  std::wstring v10; // [esp+5Ch] [ebp-9Ch] BYREF
  std::wstring section; // [esp+74h] [ebp-84h] BYREF
  std::wstring dataPath; // [esp+8Ch] [ebp-6Ch] BYREF
  INIReader r; // [esp+A4h] [ebp-54h] BYREF
  int v14; // [esp+F4h] [ebp-4h]

  v2 = std::operator+<wchar_t>(&result, L"content/cars/", &this->unixName);
  v14 = 0;
  std::operator+<wchar_t>(&dataPath, v2, L"/data/");
  LOBYTE(v14) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v3 = std::operator+<wchar_t>(&v8, &dataPath, L"drs.ini");
  LOBYTE(v14) = 3;
  INIReader::INIReader(&r, v3);
  LOBYTE(v14) = 5;
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  if ( r.ready )
  {
    for ( i = 0; i < this->wingStates._Mylast - this->wingStates._Myfirst; ++i )
    {
      v5 = std::to_wstring(&v10, i);
      LOBYTE(v14) = 6;
      std::operator+<wchar_t>(&section, L"WING_", v5);
      LOBYTE(v14) = 8;
      if ( v10._Myres >= 8 )
        operator delete(v10._Bx._Ptr);
      v10._Myres = 7;
      v10._Bx._Buf[0] = 0;
      v10._Mysize = 0;
      if ( INIReader::hasSection(&r, &section) )
      {
        s.index = i;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"EFFECT", 6u);
        LOBYTE(v14) = 9;
        s.angle = INIReader::getFloat(&r, &section, &key);
        LOBYTE(v14) = 8;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        std::vector<DRSWingSetting>::push_back(
          (std::vector<PerformancePair> *)&this->drsWingSettings,
          (PerformancePair *)&s);
      }
      LOBYTE(v14) = 5;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
  }
  LOBYTE(v14) = 2;
  INIReader::~INIReader(&r);
  if ( dataPath._Myres >= 8 )
    operator delete(dataPath._Bx._Ptr);
}
void NetCarStateProvider::initP2P(NetCarStateProvider *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  bool v4; // bl
  double v5; // st7
  bool v6; // cf
  double v7; // st7
  std::wstring section; // [esp+Ch] [ebp-B4h] BYREF
  std::wstring v9; // [esp+24h] [ebp-9Ch] BYREF
  std::wstring v10; // [esp+3Ch] [ebp-84h] BYREF
  std::wstring result; // [esp+54h] [ebp-6Ch] BYREF
  INIReader r; // [esp+6Ch] [ebp-54h] BYREF
  int v13; // [esp+BCh] [ebp-4h]

  v2 = std::operator+<wchar_t>(&result, L"content/cars/", &this->unixName);
  v13 = 0;
  v3 = std::operator+<wchar_t>(&v10, v2, L"/data/engine.ini");
  LOBYTE(v13) = 1;
  INIReader::INIReader(&r, v3);
  if ( v10._Myres >= 8 )
    operator delete(v10._Bx._Ptr);
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  LOBYTE(v13) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"PUSH_TO_PASS", 0xCu);
  LOBYTE(v13) = 5;
  v4 = INIReader::hasSection(&r, &section);
  LOBYTE(v13) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v4 )
  {
    this->p2p.enabled = 1;
    this->p2p.activations = 0;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"COOLDOWN_SECONDS", 0x10u);
    LOBYTE(v13) = 6;
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    std::wstring::assign(&v9, L"PUSH_TO_PASS", 0xCu);
    LOBYTE(v13) = 7;
    v5 = INIReader::getFloat(&r, &v9, &section);
    v6 = v9._Myres < 8;
    this->p2p.coolDownS = v5;
    if ( !v6 )
      operator delete(v9._Bx._Ptr);
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    LOBYTE(v13) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    this->p2p.timeAccum = this->p2p.coolDownS;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TIME_SECONDS", 0xCu);
    LOBYTE(v13) = 8;
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    std::wstring::assign(&v9, L"PUSH_TO_PASS", 0xCu);
    LOBYTE(v13) = 9;
    v7 = INIReader::getFloat(&r, &v9, &section);
    v6 = v9._Myres < 8;
    this->p2p.timeS = v7;
    if ( !v6 )
      operator delete(v9._Bx._Ptr);
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
  }
  v13 = -1;
  INIReader::~INIReader(&r);
}
void NetCarStateProvider::initPhysicsValues(NetCarStateProvider *this)
{
  NetCarStateProvider *v1; // edi
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  float v4; // xmm5_4
  float v5; // xmm4_4
  const std::wstring *v6; // eax
  std::wstring *v7; // esi
  float *v8; // edi
  double v9; // st7
  bool v10; // cf
  const std::wstring *v11; // eax
  vec3f *v12; // eax
  double v13; // st7
  float v14; // [esp+Ch] [ebp-218h]
  float v15; // [esp+10h] [ebp-214h]
  float v17; // [esp+18h] [ebp-20Ch]
  float v18; // [esp+1Ch] [ebp-208h]
  float v19; // [esp+20h] [ebp-204h]
  float v20; // [esp+24h] [ebp-200h]
  int v21; // [esp+24h] [ebp-200h]
  INIReader v22; // [esp+28h] [ebp-1FCh] BYREF
  INIReader v23; // [esp+6Ch] [ebp-1B8h] BYREF
  INIReader v24; // [esp+B0h] [ebp-174h] BYREF
  std::wstring _Left; // [esp+F4h] [ebp-130h] BYREF
  std::wstring result; // [esp+10Ch] [ebp-118h] BYREF
  std::wstring v27; // [esp+124h] [ebp-100h] BYREF
  std::wstring v28; // [esp+13Ch] [ebp-E8h] BYREF
  std::wstring v29; // [esp+154h] [ebp-D0h] BYREF
  std::wstring v30; // [esp+16Ch] [ebp-B8h] BYREF
  std::wstring section; // [esp+184h] [ebp-A0h] BYREF
  std::wstring key; // [esp+19Ch] [ebp-88h] BYREF
  std::wstring ptr; // [esp+1B4h] [ebp-70h] BYREF
  std::wstring v34; // [esp+1CCh] [ebp-58h] BYREF
  std::wstring v35; // [esp+1E4h] [ebp-40h] BYREF
  std::wstring v36; // [esp+1FCh] [ebp-28h] BYREF
  int v37; // [esp+220h] [ebp-4h]

  v1 = this;
  v2 = std::operator+<wchar_t>(&result, L"content/cars/", &this->unixName);
  v37 = 0;
  std::operator+<wchar_t>(&_Left, v2, L"/data/");
  LOBYTE(v37) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v3 = std::operator+<wchar_t>(&v29, &_Left, L"suspensions.ini");
  LOBYTE(v37) = 3;
  INIReader::INIReader(&v24, v3);
  LOBYTE(v37) = 5;
  if ( v29._Myres >= 8 )
    operator delete(v29._Bx._Ptr);
  v29._Myres = 7;
  v29._Mysize = 0;
  v29._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"WHEELBASE", 9u);
  LOBYTE(v37) = 6;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v37) = 7;
  v17 = INIReader::getFloat(&v24, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"CG_LOCATION", 0xBu);
  LOBYTE(v37) = 8;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"BASIC", 5u);
  LOBYTE(v37) = 9;
  v20 = INIReader::getFloat(&v24, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v37) = 10;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v37) = 11;
  v14 = INIReader::getFloat(&v24, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v37) = 12;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FRONT", 5u);
  LOBYTE(v37) = 13;
  v18 = INIReader::getFloat(&v24, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASEY", 5u);
  LOBYTE(v37) = 14;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v37) = 15;
  v15 = INIReader::getFloat(&v24, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACK", 5u);
  LOBYTE(v37) = 16;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REAR", 4u);
  LOBYTE(v37) = 17;
  v19 = INIReader::getFloat(&v24, &section, &key) * 0.5;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v1->wheelBasePosLS[0].M11 = 1.0;
  v1->wheelBasePosLS[1].M11 = 1.0;
  v1->wheelBasePosLS[0].M12 = 0.0;
  v1->wheelBasePosLS[0].M13 = 0.0;
  v1->wheelBasePosLS[0].M14 = 0.0;
  v1->wheelBasePosLS[0].M21 = 0.0;
  v1->wheelBasePosLS[0].M22 = 1.0;
  v1->wheelBasePosLS[0].M23 = 0.0;
  v1->wheelBasePosLS[0].M24 = 0.0;
  v1->wheelBasePosLS[0].M31 = 0.0;
  v1->wheelBasePosLS[0].M32 = 0.0;
  v1->wheelBasePosLS[0].M33 = 1.0;
  v1->wheelBasePosLS[0].M34 = 0.0;
  v1->wheelBasePosLS[0].M41 = 0.0;
  v1->wheelBasePosLS[0].M42 = 0.0;
  v1->wheelBasePosLS[0].M43 = 0.0;
  v1->wheelBasePosLS[0].M44 = 1.0;
  v1->wheelBasePosLS[1].M12 = 0.0;
  v1->wheelBasePosLS[1].M13 = 0.0;
  v1->wheelBasePosLS[1].M14 = 0.0;
  v1->wheelBasePosLS[1].M21 = 0.0;
  v1->wheelBasePosLS[1].M22 = 1.0;
  v1->wheelBasePosLS[1].M23 = 0.0;
  v1->wheelBasePosLS[1].M24 = 0.0;
  v1->wheelBasePosLS[1].M31 = 0.0;
  v1->wheelBasePosLS[1].M32 = 0.0;
  v1->wheelBasePosLS[1].M33 = 1.0;
  v1->wheelBasePosLS[1].M34 = 0.0;
  v1->wheelBasePosLS[1].M41 = 0.0;
  v1->wheelBasePosLS[1].M42 = 0.0;
  v1->wheelBasePosLS[1].M43 = 0.0;
  v1->wheelBasePosLS[1].M44 = 1.0;
  v1->wheelBasePosLS[2].M11 = 1.0;
  v1->wheelBasePosLS[2].M12 = 0.0;
  v1->wheelBasePosLS[2].M13 = 0.0;
  v1->wheelBasePosLS[2].M14 = 0.0;
  v1->wheelBasePosLS[2].M21 = 0.0;
  v1->wheelBasePosLS[2].M22 = 1.0;
  v1->wheelBasePosLS[2].M23 = 0.0;
  v1->wheelBasePosLS[2].M24 = 0.0;
  v1->wheelBasePosLS[2].M31 = 0.0;
  v1->wheelBasePosLS[2].M32 = 0.0;
  v1->wheelBasePosLS[2].M33 = 1.0;
  v1->wheelBasePosLS[2].M34 = 0.0;
  v1->wheelBasePosLS[2].M41 = 0.0;
  v1->wheelBasePosLS[2].M42 = 0.0;
  v1->wheelBasePosLS[2].M43 = 0.0;
  v1->wheelBasePosLS[2].M44 = 1.0;
  v1->wheelBasePosLS[3].M11 = 1.0;
  v4 = (float)(1.0 - v20) * v17;
  v1->wheelBasePosLS[3].M12 = 0.0;
  v1->wheelBasePosLS[3].M13 = 0.0;
  v1->wheelBasePosLS[3].M14 = 0.0;
  v1->wheelBasePosLS[3].M21 = 0.0;
  v1->wheelBasePosLS[3].M22 = 1.0;
  LODWORD(v5) = COERCE_UNSIGNED_INT(v20 * v17) ^ _xmm;
  v1->wheelBasePosLS[3].M23 = 0.0;
  v1->wheelBasePosLS[3].M24 = 0.0;
  v1->wheelBasePosLS[3].M31 = 0.0;
  v1->wheelBasePosLS[3].M32 = 0.0;
  v1->wheelBasePosLS[3].M33 = 1.0;
  v1->wheelBasePosLS[3].M34 = 0.0;
  v1->wheelBasePosLS[3].M41 = 0.0;
  v1->wheelBasePosLS[3].M42 = 0.0;
  v1->wheelBasePosLS[3].M43 = 0.0;
  v1->wheelBasePosLS[3].M44 = 1.0;
  v1->wheelBasePosLS[0].M41 = v18;
  v1->wheelBasePosLS[0].M42 = v14;
  v1->wheelBasePosLS[0].M43 = v4;
  LODWORD(v1->wheelBasePosLS[1].M41) = LODWORD(v18) ^ _xmm;
  v1->wheelBasePosLS[1].M42 = v14;
  v1->wheelBasePosLS[1].M43 = v4;
  v1->wheelBasePosLS[2].M41 = v19;
  v1->wheelBasePosLS[2].M42 = v15;
  v1->wheelBasePosLS[2].M43 = v5;
  LODWORD(v1->wheelBasePosLS[3].M41) = LODWORD(v19) ^ _xmm;
  v1->wheelBasePosLS[3].M42 = v15;
  v1->wheelBasePosLS[3].M43 = v5;
  v6 = std::operator+<wchar_t>(&v28, &_Left, L"tyres.ini");
  LOBYTE(v37) = 18;
  INIReader::INIReader(&v22, v6);
  LOBYTE(v37) = 20;
  if ( v28._Myres >= 8 )
    operator delete(v28._Bx._Ptr);
  v28._Myres = 7;
  v28._Mysize = 0;
  v28._Bx._Buf[0] = 0;
  ptr._Myres = 7;
  ptr._Mysize = 0;
  ptr._Bx._Buf[0] = 0;
  std::wstring::assign(&ptr, L"FRONT", 5u);
  LOBYTE(v37) = 21;
  v34._Myres = 7;
  v34._Mysize = 0;
  v34._Bx._Buf[0] = 0;
  std::wstring::assign(&v34, L"FRONT", 5u);
  LOBYTE(v37) = 22;
  v35._Myres = 7;
  v35._Mysize = 0;
  v35._Bx._Buf[0] = 0;
  std::wstring::assign(&v35, L"REAR", 4u);
  LOBYTE(v37) = 23;
  v36._Myres = 7;
  v36._Mysize = 0;
  v36._Bx._Buf[0] = 0;
  std::wstring::assign(&v36, L"REAR", 4u);
  LOBYTE(v37) = 24;
  v7 = &ptr;
  v8 = v1->tyreRadius;
  v21 = 4;
  do
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"RADIUS", 6u);
    LOBYTE(v37) = 25;
    v9 = INIReader::getFloat(&v22, v7, &key);
    v10 = key._Myres < 8;
    *v8 = v9;
    LOBYTE(v37) = 24;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    ++v8;
    ++v7;
    --v21;
  }
  while ( v21 );
  v11 = std::operator+<wchar_t>(&v27, &_Left, L"car.ini");
  LOBYTE(v37) = 26;
  INIReader::INIReader(&v23, v11);
  LOBYTE(v37) = 28;
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  v30._Myres = 7;
  v30._Mysize = 0;
  v30._Bx._Buf[0] = 0;
  std::wstring::assign(&v30, L"GRAPHICS_OFFSET", 0xFu);
  LOBYTE(v37) = 29;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASIC", 5u);
  LOBYTE(v37) = 30;
  v12 = INIReader::getFloat3(&v23, (vec3f *)&section._Bx._Alias[12], &key, &v30);
  v10 = key._Myres < 8;
  this->graphicsOffset = *v12;
  if ( !v10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v37) = 28;
  if ( v30._Myres >= 8 )
    operator delete(v30._Bx._Ptr);
  v30._Myres = 7;
  v30._Mysize = 0;
  v30._Bx._Buf[0] = 0;
  std::wstring::assign(&v30, L"GRAPHICS_PITCH_ROTATION", 0x17u);
  LOBYTE(v37) = 31;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BASIC", 5u);
  LOBYTE(v37) = 32;
  v13 = INIReader::getFloat(&v23, &key, &v30);
  v10 = key._Myres < 8;
  this->graphicsPitchRotation = v13 * 0.017453;
  if ( !v10 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( v30._Myres >= 8 )
    operator delete(v30._Bx._Ptr);
  LOBYTE(v37) = 24;
  INIReader::~INIReader(&v23);
  LOBYTE(v37) = 20;
  `eh vector destructor iterator'(&ptr, 0x18u, 4, (void (*)(void *))std::wstring::~wstring);
  LOBYTE(v37) = 5;
  INIReader::~INIReader(&v22);
  LOBYTE(v37) = 2;
  INIReader::~INIReader(&v24);
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
}
void NetCarStateProvider::initWings(NetCarStateProvider *this)
{
  NetCarStateProvider *v1; // edi
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  int v4; // ebx
  unsigned int i; // esi
  int v6; // eax
  std::wstring *v7; // ecx
  std::wostream *v8; // eax
  const std::wstring *v9; // eax
  bool v10; // al
  bool v11; // al
  const std::wstring *v12; // eax
  int j; // ebp
  int v14; // eax
  std::wstring *v15; // ecx
  std::wostream *v16; // eax
  const std::wstring *v17; // eax
  bool v18; // al
  bool v19; // al
  const std::wstring *v20; // eax
  int v21; // ebp
  DynamicWingController *v22; // esi
  const std::wstring *v23; // eax
  DynamicWingController *v24; // eax
  DynamicWingController *v25; // edi
  std::unique_ptr<DynamicWingController> *v26; // edx
  std::vector<std::unique_ptr<DynamicWingController>> *v27; // esi
  std::unique_ptr<DynamicWingController> *v28; // ecx
  int v29; // edx
  unsigned int v30; // ecx
  unsigned int v31; // ecx
  std::unique_ptr<DynamicWingController> *v32; // eax
  int v33; // [esp+1Ah] [ebp-1F4h]
  int v34; // [esp+1Ah] [ebp-1F4h]
  bool v35; // [esp+39h] [ebp-1D5h]
  bool v36; // [esp+39h] [ebp-1D5h]
  int v37; // [esp+3Eh] [ebp-1D0h]
  std::vector<std::vector<std::unique_ptr<DynamicWingController>>> *v38; // [esp+46h] [ebp-1C8h]
  NetCarStateProvider *v39; // [esp+4Ah] [ebp-1C4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v40; // [esp+4Eh] [ebp-1C0h] BYREF
  WingState ws; // [esp+FEh] [ebp-110h] BYREF
  std::wstring key; // [esp+142h] [ebp-CCh] BYREF
  std::wstring v43; // [esp+15Ah] [ebp-B4h] BYREF
  std::wstring v44; // [esp+172h] [ebp-9Ch] BYREF
  std::wstring v45; // [esp+18Ah] [ebp-84h] BYREF
  std::wstring result; // [esp+1A2h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+1BAh] [ebp-54h] BYREF
  int v48; // [esp+20Ah] [ebp-4h]

  v1 = this;
  v39 = this;
  v2 = std::operator+<wchar_t>(&result, L"content/cars/", &this->unixName);
  v48 = 0;
  v3 = std::operator+<wchar_t>(&v45, v2, L"/data/aero.ini");
  LOBYTE(v48) = 1;
  INIReader::INIReader(&ini, v3);
  if ( v45._Myres >= 8 )
    operator delete(v45._Bx._Ptr);
  v45._Myres = 7;
  v45._Mysize = 0;
  v45._Bx._Buf[0] = 0;
  LOBYTE(v48) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  *(_DWORD *)v40.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v40.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v40.gap68);
  LOBYTE(v48) = 5;
  v4 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v40, &v40.gap10[8], 0);
  v48 = 6;
  *(_DWORD *)&v40.gap0[*(_DWORD *)(*(_DWORD *)v40.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(NetCarStateProvider **)((char *)&v39 + *(_DWORD *)(*(_DWORD *)v40.gap0 + 4)) = (NetCarStateProvider *)(*(_DWORD *)(*(_DWORD *)v40.gap0 + 4) - 104);
  std::wstreambuf::wstreambuf(&v40.gap10[8]);
  *(_DWORD *)&v40.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v40.gap10[64] = 0;
  *(_DWORD *)&v40.gap10[68] = 0;
  LOBYTE(v48) = 8;
  for ( i = 0; ; ++i )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, word_17BE9D8, 0);
    LOBYTE(v48) = 9;
    if ( (v40.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v40.gap10[8]) )
        std::wstreambuf::epptr(&v40.gap10[8]);
      else
        std::wstreambuf::egptr(&v40.gap10[8]);
      std::wstreambuf::eback(&v40.gap10[8]);
      v6 = std::wstreambuf::eback(&v40.gap10[8]);
      operator delete(v6);
    }
    std::wstreambuf::setg(&v40.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v40.gap10[8], 0, 0);
    v7 = &key;
    *(_DWORD *)&v40.gap10[64] = 0;
    v33 = *(_DWORD *)&v40.gap10[68] & 0xFFFFFFFE;
    if ( key._Myres >= 8 )
      v7 = (std::wstring *)key._Bx._Ptr;
    *(_DWORD *)&v40.gap10[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v40.gap10[8], v7->_Bx._Buf, key._Mysize, v33);
    LOBYTE(v48) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v40.gap10, "WING_");
    std::wostream::operator<<(v8, i);
    v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
    LOBYTE(v48) = 10;
    v10 = INIReader::hasSection(&ini, v9);
    LOBYTE(v48) = 8;
    v11 = !v10;
    v35 = v11;
    if ( v44._Myres >= 8 )
    {
      operator delete(v44._Bx._Ptr);
      v11 = v35;
    }
    if ( v11 )
      break;
    ws.isVertical = 0;
    *(_OWORD *)&ws.aoa = 0i64;
    *(_OWORD *)&ws.groundHeight = 0i64;
    *(_OWORD *)&ws.angleMult = _xmm;
    ws.liftVector.x = 0.0;
    ws.liftVector.y = 0.0;
    ws.liftVector.z = 0.0;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ANGLE", 5u);
    LOBYTE(v48) = 11;
    v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v43);
    LOBYTE(v48) = 12;
    ws.inputAngle = INIReader::getFloat(&ini, v12, &key);
    if ( v43._Myres >= 8 )
      operator delete(v43._Bx._Ptr);
    v43._Myres = 7;
    v43._Mysize = 0;
    v43._Bx._Buf[0] = 0;
    LOBYTE(v48) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::vector<WingState>::push_back(&v1->wingStates, &ws);
  }
  v38 = &v1->wingControllerLists;
  std::vector<std::vector<std::unique_ptr<DynamicWingController>>>::resize(&v1->wingControllerLists, i);
  for ( j = 0; ; j = v37 + 1 )
  {
    v37 = j;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, word_17BE9D8, 0);
    LOBYTE(v48) = 13;
    if ( (v40.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v40.gap10[8]) )
        std::wstreambuf::epptr(&v40.gap10[8]);
      else
        std::wstreambuf::egptr(&v40.gap10[8]);
      std::wstreambuf::eback(&v40.gap10[8]);
      v14 = std::wstreambuf::eback(&v40.gap10[8]);
      operator delete(v14);
    }
    std::wstreambuf::setg(&v40.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v40.gap10[8], 0, 0);
    v15 = &key;
    *(_DWORD *)&v40.gap10[64] = 0;
    v34 = *(_DWORD *)&v40.gap10[68] & 0xFFFFFFFE;
    if ( key._Myres >= 8 )
      v15 = (std::wstring *)key._Bx._Ptr;
    *(_DWORD *)&v40.gap10[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v40.gap10[8], v15->_Bx._Buf, key._Mysize, v34);
    LOBYTE(v48) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v40.gap10, "DYNAMIC_CONTROLLER_");
    std::wostream::operator<<(v16, j);
    v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v43);
    LOBYTE(v48) = 14;
    v18 = INIReader::hasSection(&ini, v17);
    LOBYTE(v48) = 8;
    v19 = !v18;
    v36 = v19;
    if ( v43._Myres >= 8 )
    {
      operator delete(v43._Bx._Ptr);
      v19 = v36;
    }
    if ( v19 )
      break;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"WING", 4u);
    LOBYTE(v48) = 15;
    v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v43);
    LOBYTE(v48) = 16;
    v21 = INIReader::getInt(&ini, v20, &key);
    if ( v43._Myres >= 8 )
      operator delete(v43._Bx._Ptr);
    v43._Myres = 7;
    v43._Mysize = 0;
    v43._Bx._Buf[0] = 0;
    LOBYTE(v48) = 8;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    v22 = (DynamicWingController *)operator new(108);
    LOBYTE(v48) = 17;
    if ( v22 )
    {
      v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v40, &v44);
      LOBYTE(v48) = 18;
      v4 |= 1u;
      DynamicWingController::DynamicWingController(v22, &v1->state, &v1->unixName, &ini, v23);
      v25 = v24;
    }
    else
    {
      v25 = 0;
    }
    v48 = 19;
    v26 = v38->_Myfirst[v21]._Mylast;
    v27 = &v38->_Myfirst[v21];
    v28 = v27->_Myend;
    if ( v26 == v28 && !(v28 - v26) )
    {
      v29 = v26 - v27->_Myfirst;
      if ( v29 == 0x3FFFFFFF )
        std::_Xlength_error("vector<T> too long");
      v30 = v28 - v27->_Myfirst;
      if ( 0x3FFFFFFF - (v30 >> 1) >= v30 )
        v31 = (v30 >> 1) + v30;
      else
        v31 = 0;
      if ( v31 < v29 + 1 )
        v31 = v29 + 1;
      std::vector<std::unique_ptr<DynamicWingController>>::_Reallocate(v27, v31);
    }
    v32 = v27->_Mylast;
    if ( v32 )
      v32->_Myptr = v25;
    ++v27->_Mylast;
    v48 = 8;
    if ( (v4 & 1) != 0 )
    {
      v4 &= 0xFFFFFFFE;
      if ( v44._Myres >= 8 )
        operator delete(v44._Bx._Ptr);
      v44._Myres = 7;
      v44._Mysize = 0;
      v44._Bx._Buf[0] = 0;
    }
    v1 = v39;
  }
  LOBYTE(v48) = 4;
  *(_DWORD *)&v40.gap0[*(_DWORD *)(*(_DWORD *)v40.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(NetCarStateProvider **)((char *)&v39 + *(_DWORD *)(*(_DWORD *)v40.gap0 + 4)) = (NetCarStateProvider *)(*(_DWORD *)(*(_DWORD *)v40.gap0 + 4) - 104);
  *(_DWORD *)&v40.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v40.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v40.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v40.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v40.gap68);
  v48 = -1;
  INIReader::~INIReader(&ini);
}
void NetCarStateProvider::onRemoteStateReceived(NetCarStateProvider *this, NetCarState *s)
{
  unsigned __int8 v3; // al
  unsigned __int8 v4; // cl
  ACClient *v5; // ecx
  long double v6; // st7
  float v7; // edx
  int v8; // esi
  unsigned __int8 v9; // dl
  double v10; // xmm2_8
  double v11; // xmm1_8
  float v12; // xmm4_4
  __m128 v13; // xmm3
  float v14; // xmm2_4
  __m128 v15; // xmm6
  __m128 v16; // xmm5
  float v17; // xmm0_4
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  float v20; // xmm1_4
  float v21; // xmm0_4
  __m128 v22; // xmm1
  float v23; // xmm7_4
  float v24; // xmm2_4
  unsigned __int64 v25; // xmm3_8
  float v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  double v31; // xmm2_8
  double v32; // xmm7_8
  float v33; // xmm1_4
  double v34; // xmm2_8
  double v35; // xmm7_8
  float v36; // xmm0_4
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  float v39; // xmm5_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm4_4
  float v44; // xmm1_4
  float v45; // xmm5_4
  __m128 v46; // xmm2
  float v47; // xmm3_4
  float v48; // xmm5_4
  float v49; // xmm4_4
  __m128 v50; // xmm1
  float v51; // xmm0_4
  __int64 v52; // xmm0_8
  float v53; // eax
  mat44f v54; // [esp+8h] [ebp-B8h] BYREF
  mat44f result; // [esp+48h] [ebp-78h] BYREF
  float v56; // [esp+90h] [ebp-30h]
  __int64 v57; // [esp+94h] [ebp-2Ch]
  float v58; // [esp+9Ch] [ebp-24h]
  _BYTE v59[12]; // [esp+A0h] [ebp-20h] BYREF
  float v60; // [esp+ACh] [ebp-14h]
  float v61; // [esp+B0h] [ebp-10h]
  vec3f translation; // [esp+B4h] [ebp-Ch] BYREF
  float sa; // [esp+C4h] [ebp+4h]
  float sb; // [esp+C4h] [ebp+4h]

  v61 = *(float *)&this;
  this->isDisconnected = 0;
  v3 = this->netStates[0].pakSequenceId;
  v4 = s->pakSequenceId;
  if ( v4 > v3
    || v4 < 0xAu && v3 > 0xF0u
    || COERCE_DOUBLE(COERCE_UNSIGNED_INT64(s->timeStamp - this->netStates[0].timeStamp) & _xmm) > 1000.0 )
  {
    v5 = this->client;
    this->ping = s->ping;
    v6 = ACClient::getPhysicsTime(v5);
    v7 = v61;
    s->rcvTime = v6;
    LODWORD(v7) += 880;
    qmemcpy(&this->netStates[2], &this->netStates[1], sizeof(this->netStates[2]));
    qmemcpy(&this->netStates[1], (const void *)LODWORD(v7), sizeof(this->netStates[1]));
    qmemcpy((void *)LODWORD(v7), s, 0x88u);
    v8 = LODWORD(v61);
    v9 = *(_BYTE *)(LODWORD(v61) + 944) - *(_BYTE *)(LODWORD(v61) + 1080);
    v10 = (double)v9 * *(double *)(*(_DWORD *)(LODWORD(v61) + 296) + 664) + *(double *)(LODWORD(v61) + 1064);
    if ( v9 < 5u )
    {
      v11 = *(double *)(LODWORD(v61) + 928);
      if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v10 - v11) & _xmm) < 1000.0 )
        *(double *)(LODWORD(v61) + 928) = (v11 - v10) * 0.3 + v10;
    }
    if ( v9 == 1 )
      ++*(_DWORD *)(v8 + 288);
    else
      ++*(_DWORD *)(v8 + 292);
    translation.x = 0.0;
    translation.y = 0.0;
    translation.z = 0.0;
    *(_QWORD *)&v59[4] = 0i64;
    mat44f::createFromEuler(&result, (const vec3f *)(v8 + 892), &translation);
    translation.x = 0.0;
    translation.y = 0.0;
    translation.z = 0.0;
    mat44f::createFromEuler(&v54, (const vec3f *)(v8 + 1028), &translation);
    translation = *(vec3f *)(v8 + 904);
    v12 = translation.z;
    v13 = (__m128)LODWORD(translation.x);
    v61 = COERCE_FLOAT(LODWORD(result.M32) ^ _xmm) * -1.0;
    sa = COERCE_FLOAT(LODWORD(result.M33) ^ _xmm) * -1.0;
    v14 = translation.y;
    v15 = (__m128)_mm_loadl_epi64((const __m128i *)&v59[4]);
    v16 = (__m128)LODWORD(FLOAT_1_0);
    v58 = COERCE_FLOAT(LODWORD(result.M31) ^ _xmm) * -1.0;
    v57 = *(_QWORD *)&translation.x;
    v60 = translation.z;
    v17 = fsqrt((float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v14 * v14)) + (float)(v12 * v12));
    if ( v17 != v15.m128_f32[0] )
    {
      v18 = (__m128)LODWORD(FLOAT_1_0);
      v18.m128_f32[0] = 1.0 / v17;
      v19 = v18;
      v19.m128_f32[0] = v18.m128_f32[0] * translation.x;
      v13 = v19;
      v14 = v18.m128_f32[0] * translation.y;
      *(float *)&v57 = v18.m128_f32[0] * translation.x;
      *((float *)&v57 + 1) = v18.m128_f32[0] * translation.y;
      v12 = v18.m128_f32[0] * translation.z;
      v60 = v18.m128_f32[0] * translation.z;
    }
    v20 = (float)((float)(v14 * v61)
                + (float)(v13.m128_f32[0] * (float)(COERCE_FLOAT(LODWORD(result.M31) ^ _xmm) * -1.0)))
        + (float)(v12 * sa);
    if ( v20 <= -1.0 || v20 >= 1.0 )
    {
      v21 = v15.m128_f32[0];
    }
    else
    {
      v21 = v14;
      __libm_sse2_acosf();
      v14 = *((float *)&v57 + 1);
      v15 = (__m128)_mm_loadl_epi64((const __m128i *)&v59[4]);
      v16 = (__m128)LODWORD(FLOAT_1_0);
      v13 = (__m128)(unsigned int)v57;
      v12 = v60;
    }
    *(float *)(v8 + 988) = v21;
    v22 = v13;
    v23 = (float)(v12 * v61) - (float)(v14 * sa);
    v22.m128_f32[0] = (float)(v13.m128_f32[0] * sa) - (float)(v12 * v58);
    v24 = (float)(v14 * v58) - (float)(v13.m128_f32[0] * v61);
    v13.m128_f32[0] = v23;
    v25 = _mm_unpacklo_ps(v13, v22).m128_u64[0];
    *(_QWORD *)v59 = v25;
    translation.z = v24;
    v26 = v24;
    *(float *)&v59[8] = v24;
    v27 = fsqrt((float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v23 * v23)) + (float)(v24 * v24));
    if ( v27 != v15.m128_f32[0] )
    {
      *(float *)v59 = (float)(v16.m128_f32[0] / v27) * v23;
      *(float *)&v59[4] = (float)(v16.m128_f32[0] / v27) * *(float *)&v59[4];
      v25 = *(_QWORD *)v59;
      *(float *)&v59[8] = (float)(v16.m128_f32[0] / v27) * *(float *)&v59[8];
      v26 = *(float *)&v59[8];
    }
    *(_QWORD *)(v8 + 992) = v25;
    v28 = v15.m128_f32[0];
    *(float *)(v8 + 1000) = v26;
    v29 = v15.m128_f32[0];
    v30 = *(float *)(v8 + 356);
    *(_QWORD *)(v8 + 1288) = _mm_unpacklo_ps((__m128)*(unsigned int *)(v8 + 348), (__m128)*(unsigned int *)(v8 + 352)).m128_u64[0];
    v31 = *(double *)(v8 + 4840);
    translation.z = v30;
    *(float *)(v8 + 1296) = v30;
    v32 = *(double *)(v8 + 928);
    v33 = v15.m128_f32[0];
    v34 = (v31 - v32) * 0.001;
    v35 = (v32 - *(double *)(v8 + 1064)) * 0.001;
    *(double *)&v59[4] = v34;
    if ( v35 != 0.0 )
    {
      v36 = v35;
      v16.m128_f32[0] = v16.m128_f32[0] / v36;
      v37 = v16;
      v38 = v16;
      v37.m128_f32[0] = v16.m128_f32[0] * (float)(*(float *)(v8 + 904) - *(float *)(v8 + 1040));
      v34 = *(double *)&v59[4];
      v38.m128_f32[0] = v16.m128_f32[0] * (float)(*(float *)(v8 + 908) - *(float *)(v8 + 1044));
      v39 = v16.m128_f32[0] * (float)(*(float *)(v8 + 912) - *(float *)(v8 + 1048));
      *(_QWORD *)&translation.x = _mm_unpacklo_ps(v37, v38).m128_u64[0];
      v29 = translation.y;
      v33 = translation.x;
      v56 = v39;
      translation.z = v39;
      v28 = v39;
    }
    v40 = v34;
    v41 = (float)((float)(v29 * 0.5) * v40) * v40;
    v42 = *(float *)(v8 + 908) * v40;
    v43 = (float)((float)(v28 * 0.5) * v40) * v40;
    sb = (float)((float)(v33 * 0.5) * v40) * v40;
    v44 = *(float *)(v8 + 912) * v40;
    v45 = *(float *)(v8 + 904) * v40;
    v46 = (__m128)*(unsigned int *)(v8 + 1288);
    v58 = v41;
    v47 = *(float *)(v8 + 884);
    v48 = v45 + *(float *)(v8 + 880);
    v60 = v43;
    v49 = *(float *)(v8 + 888) + v44;
    v50 = (__m128)*(unsigned int *)(v8 + 1292);
    v46.m128_f32[0] = v46.m128_f32[0] - (float)(v48 + sb);
    v50.m128_f32[0] = v50.m128_f32[0] - (float)((float)(v47 + v42) + v58);
    v51 = *(float *)(v8 + 1296) - (float)(v49 + v60);
    *(_QWORD *)(v8 + 168) = _mm_unpacklo_ps(v46, v50).m128_u64[0];
    v56 = v51;
    v52 = *(_QWORD *)(v8 + 1596);
    v53 = v56;
    *(_QWORD *)(v8 + 1584) = v52;
    *(float *)(v8 + 176) = v53;
    *(_DWORD *)(v8 + 1592) = *(_DWORD *)(v8 + 1604);
    if ( (float)((float)((float)(*(float *)&v52 * *(float *)&v52)
                       + (float)(*(float *)(v8 + 1600) * *(float *)(v8 + 1600)))
               + (float)(*(float *)(v8 + 1604) * *(float *)(v8 + 1604))) < 2.0 )
    {
      *(_QWORD *)(v8 + 168) = _mm_unpacklo_ps(v15, v15).m128_u64[0];
      *(_DWORD *)(v8 + 176) = 0;
    }
  }
}
vec3f *NetCarStateProvider::projectNetStatePos(NetCarStateProvider *this, vec3f *result, int ti, long double t)
{
  int v4; // edx
  float v5; // xmm4_4
  float v6; // xmm6_4
  double v7; // xmm3_8
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  vec3f *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm5_4
  __int64 v19; // [esp+0h] [ebp-Ch]

  v4 = ti;
  v5 = 0.0;
  v6 = (this->netStates[0].timeStamp - this->netStates[1].timeStamp) * 0.001;
  v7 = (t - this->netStates[ti].timeStamp) * 0.001;
  if ( v6 == 0.0 )
  {
    v9 = 0.0;
    v10 = 0.0;
  }
  else
  {
    v8 = 1.0 / v6;
    v5 = (float)(1.0 / v6) * (float)(this->netStates[0].velocity.x - this->netStates[1].velocity.x);
    v9 = (float)(1.0 / v6) * (float)(this->netStates[0].velocity.y - this->netStates[1].velocity.y);
    v10 = v8 * (float)(this->netStates[0].velocity.z - this->netStates[1].velocity.z);
  }
  v11 = result;
  v12 = v7 * v7;
  v13 = (float)(v5 * 0.5) * v12;
  v14 = (float)(v9 * 0.5) * v12;
  v15 = (float)(v10 * 0.5) * v12;
  v19 = *(_QWORD *)&this->netStates[v4].velocity.x;
  v16 = v7;
  v17 = this->netStates[v4].pos.y + (float)(*((float *)&v19 + 1) * v16);
  v18 = v15 + (float)(this->netStates[v4].pos.z + (float)(this->netStates[v4].velocity.z * v16));
  result->x = v13 + (float)(this->netStates[v4].pos.x + (float)(*(float *)&v19 * v16));
  result->y = v14 + v17;
  result->z = v18;
  return v11;
}
void NetCarStateProvider::resetDamage(NetCarStateProvider *this)
{
  float *v1; // ecx
  int v2; // edx
  int v3; // esi

  v1 = this->state.damageZoneLevel;
  v2 = 0;
  v3 = 5;
  if ( v1 > v1 + 5 )
    v3 = 0;
  if ( v3 )
  {
    do
    {
      ++v2;
      *v1++ = 0.0;
    }
    while ( v2 != v3 );
  }
}
void NetCarStateProvider::setCarAvatar(NetCarStateProvider *this, CarAvatar *av)
{
  this->avatar = av;
  av->carNode->isActive = 0;
  CarAvatar::setDriverInfo(av, &this->driverInfo);
  av->physicsInfo.tyreWidth[0] = 0.2;
  av->physicsInfo.tyreWidth[1] = 0.2;
  av->physicsInfo.tyreWidth[2] = 0.2;
  av->physicsInfo.tyreWidth[3] = 0.2;
}
void NetCarStateProvider::setDamageZoneLevel(NetCarStateProvider *this, float *zones)
{
  *(__m128i *)this->state.damageZoneLevel = _mm_loadu_si128((const __m128i *)zones);
  this->state.damageZoneLevel[4] = zones[4];
}
void NetCarStateProvider::step(NetCarStateProvider *this, long double physics_time)
{
  NetCarStateProvider *v2; // edi
  IRayTrackCollisionProvider *v3; // ecx
  float v4; // xmm0_4
  float v5; // xmm0_4
  Sim *v6; // ecx
  CarAvatar *v7; // eax
  Car *v8; // esi
  char v9; // al
  _DWORD *v10; // eax
  IRigidBody *v11; // ecx
  int v12; // xmm0_4
  IRigidBody_vtbl *v13; // eax
  float *v14; // eax
  float v15; // xmm2_4
  long double v16; // xmm0_8
  unsigned int v17; // eax
  long double v18; // xmm0_8
  const __m128i *v19; // eax
  __m128 *v20; // ecx
  int v21; // esi
  __m128i v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __int128 v27; // xmm1
  __int128 v28; // xmm2
  __int128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __int128 v32; // xmm0
  __int128 v33; // xmm3
  __int128 v34; // xmm2
  __int128 v35; // xmm1
  int v36; // xmm0_4
  float v37; // xmm0_4
  __m128 v38; // xmm3
  __int128 v39; // xmm3
  __m128 v40; // xmm1
  __int128 v41; // xmm0
  __m128 v42; // xmm2
  __int128 v43; // xmm1
  __int128 v44; // xmm2
  float v45; // xmm0_4
  __int128 v46; // xmm3
  __m128 v47; // xmm1
  __int128 v48; // xmm0
  __m128 v49; // xmm2
  __int128 v50; // xmm1
  __int128 v51; // xmm2
  __m128 v52; // xmm0
  bool v53; // cc
  __int128 v54; // xmm3
  __m128 v55; // xmm1
  __int128 v56; // xmm0
  __m128 v57; // xmm2
  __int128 v58; // xmm1
  __int128 v59; // xmm2
  float v60; // xmm0_4
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __int128 v63; // xmm0
  __m128 v64; // xmm2
  __int128 v65; // xmm3
  __int128 v66; // xmm2
  __int128 v67; // xmm1
  IRayTrackCollisionProvider *v68; // ecx
  float v69; // xmm1_4
  int v70; // xmm2_4
  unsigned int v71; // xmm0_4
  IRayTrackCollisionProvider_vtbl *v72; // eax
  bool (*v73)(IRayTrackCollisionProvider *, const vec3f *, const vec3f *, RayCastResult *, float); // eax
  float v74; // xmm2_4
  float v75; // xmm0_4
  float v76; // xmm1_4
  float v77; // xmm2_4
  IRigidBody *v78; // ecx
  void *v79; // edi
  float v80; // xmm0_4
  int v81; // eax
  __int64 v82; // xmm0_8
  vec3f *v83; // ecx
  __int64 v84; // xmm0_8
  float v85; // eax
  _DWORD *v86; // ecx
  __m128 v87; // xmm0
  __int128 v88; // xmm1
  __int128 v89; // xmm2
  __int128 v90; // xmm3
  __m128 v91; // xmm0
  const __m128i *v92; // eax
  __m128i v93; // xmm0
  int v94; // ecx
  __m128i v95; // xmm0
  int v96; // eax
  float *v97; // eax
  float v98; // xmm1_4
  bool v99; // zf
  float v100; // xmm0_4
  const __m128i *v101; // esi
  float v102; // xmm2_4
  float v103; // xmm0_4
  float v104; // xmm3_4
  float v105; // xmm4_4
  float v106; // xmm2_4
  long double v107; // xmm1_8
  double v108; // xmm0_8
  float v109; // xmm4_4
  float v110; // xmm7_4
  float v111; // xmm2_4
  float v112; // xmm3_4
  float v113; // xmm5_4
  float v114; // xmm2_4
  float v115; // xmm7_4
  float v116; // xmm1_4
  float v117; // xmm6_4
  float v118; // xmm0_4
  float v119; // xmm1_4
  float v120; // xmm0_4
  float v121; // xmm1_4
  __m128i v122; // xmm0
  __m128i v123; // xmm0
  float v124; // eax
  __m128 v125; // xmm5
  __m128 v126; // xmm4
  float v127; // xmm3_4
  float v128; // xmm1_4
  float v129; // xmm3_4
  __m128 v130; // xmm1
  __m128 v131; // xmm2
  __m128 v132; // xmm3
  __m128 v133; // xmm0
  __m128 v134; // xmm5
  __m128 v135; // xmm6
  __m128 v136; // xmm1
  IRigidBody *v137; // ecx
  IRigidBody *v138; // ecx
  IRigidBody_vtbl *v139; // eax
  IRigidBody *v140; // ecx
  float *v141; // eax
  IRigidBody *v142; // ecx
  unsigned int v143; // xmm4_4
  unsigned int v144; // xmm2_4
  AISplineRecorder *v145; // esi
  AISpline *v146; // eax
  IRigidBody *v147; // esi
  int v148; // eax
  const vec3f *v149; // eax
  const vec3f *v150; // [esp+4Ch] [ebp-2C0h]
  int v151; // [esp+58h] [ebp-2B4h]
  int v152; // [esp+5Ch] [ebp-2B0h]
  int v153; // [esp+60h] [ebp-2ACh]
  float Px[4]; // [esp+64h] [ebp-2A8h] BYREF
  bool isLagging[16]; // [esp+74h] [ebp-298h] BYREF
  int index[4]; // [esp+84h] [ebp-288h] BYREF
  _QWORD v157[9]; // [esp+94h] [ebp-278h] BYREF
  __m128 pDeterminant; // [esp+DCh] [ebp-230h] BYREF
  unsigned __int64 v159; // [esp+F8h] [ebp-214h] BYREF
  float v160; // [esp+100h] [ebp-20Ch]
  __int128 v161; // [esp+104h] [ebp-208h] BYREF
  vec3f *v162; // [esp+114h] [ebp-1F8h]
  const void *v163; // [esp+118h] [ebp-1F4h] BYREF
  _BYTE v164[20]; // [esp+11Ch] [ebp-1F0h] BYREF
  int v165; // [esp+130h] [ebp-1DCh]
  char result; // [esp+134h] [ebp-1D8h]
  int result_4; // [esp+138h] [ebp-1D4h]
  __m128 result_8[3]; // [esp+13Ch] [ebp-1D0h] BYREF
  __m128 result_56; // [esp+16Ch] [ebp-1A0h]
  __m128 v170[3]; // [esp+17Ch] [ebp-190h] BYREF
  __int128 v171; // [esp+1ACh] [ebp-160h]
  __m128 v172[3]; // [esp+1BCh] [ebp-150h] BYREF
  __int128 v173; // [esp+1ECh] [ebp-120h]
  __m128 v174[3]; // [esp+1FCh] [ebp-110h] BYREF
  __int128 v175; // [esp+22Ch] [ebp-E0h]
  __m128 v176[3]; // [esp+23Ch] [ebp-D0h] BYREF
  __int128 v177; // [esp+26Ch] [ebp-A0h]
  __m128 v178[3]; // [esp+27Ch] [ebp-90h] BYREF
  __int128 v179; // [esp+2ACh] [ebp-60h]
  DirectX::XMMATRIX M2_8; // [esp+2BCh] [ebp-50h] BYREF

  v2 = this;
  *(_DWORD *)&isLagging[12] = this;
  if ( this->isDisconnected )
  {
    this->body->setMeshCollideCategory(this->body, 0, 0);
  }
  else
  {
    if ( this->netStates[0].timeStamp != this->lastSliceTimeStamp )
    {
      v3 = this->rayCastProvider;
      *(_DWORD *)&v164[16] = 0;
      *(_OWORD *)v164 = 0i64;
      *(float *)&v161 = v2->netStates[0].pos.x;
      v4 = v2->netStates[0].pos.y + 1.0;
      v165 = 0;
      v163 = 0;
      *((float *)&v161 + 1) = v4;
      v5 = v2->netStates[0].pos.z;
      result = 0;
      result_4 = 0;
      v159 = 0xBF80000000000000ui64;
      v160 = 0.0;
      *((float *)&v161 + 2) = v5;
      ((void (*)(IRayTrackCollisionProvider *, __int128 *, unsigned __int64 *, const void **, int))v3->rayCast)(
        v3,
        &v161,
        &v159,
        &v163,
        1092616192);
      if ( result )
        v2->netStates[0].targetHeight = v2->netStates[0].pos.y - *(float *)&v164[4];
      v2->lastSliceTimeStamp = v2->netStates[0].timeStamp;
    }
    v6 = v2->avatar->sim;
    isLagging[0] = physics_time - v2->netStates[0].rcvTime > 5000.0;
    v7 = Sim::getCar(v6, 0);
    v8 = RaceEngineer::getCar(v7->raceEngineer._Myptr);
    v9 = Car::isInPitLane(v8);
    if ( isLagging[0] || v9 )
    {
      v2->body->setMeshCollideCategory(v2->body, 0, 0);
    }
    else if ( !v2->body->getMeshCollideCategory(v2->body, 0) )
    {
      v10 = (_DWORD *)((int (*)(IRigidBody *, __m128 *, _DWORD))v8->body->getWorldMatrix)(
                        v8->body,
                        result_8,
                        0);
      v11 = v2->body;
      index[0] = v10[12];
      *(_DWORD *)&isLagging[4] = v10[13];
      v12 = v10[14];
      v13 = v11->__vftable;
      *(_DWORD *)&isLagging[8] = v12;
      v14 = (float *)((int (*)(IRigidBody *, __m128 *, _DWORD))v13->getWorldMatrix)(v11, result_8, 0);
      v15 = (float)((float)((float)(*(float *)&isLagging[4] - v14[13]) * (float)(*(float *)&isLagging[4] - v14[13]))
                  + (float)((float)(*(float *)index - v14[12]) * (float)(*(float *)index - v14[12])))
          + (float)((float)(*(float *)&isLagging[8] - v14[14]) * (float)(*(float *)&isLagging[8] - v14[14]));
      if ( v15 != 0.0 && fsqrt(v15) > 6.0 )
        v2->body->setMeshCollideCategory(v2->body, 0, 8u);
    }
    if ( v2->useLog )
      NetCarStateProvider::debugLag(v2, isLagging[0], physics_time);
    if ( isLagging[0] )
    {
      NetCarStateProvider::stepLagging(v2, physics_time);
    }
    else
    {
      v2->state.statusBytes = 0;
      if ( (v2->netStates[0].statusBytes & 0x20) != 0 )
        v2->state.statusBytes = 1;
      if ( (v2->netStates[0].statusBytes & 0x40) != 0 )
        v2->state.actionsState.state |= 0x40u;
      else
        v2->state.actionsState.state &= 0xFFFFFFBF;
      if ( (v2->netStates[0].statusBytes & 0x100) != 0 )
        v2->state.actionsState.state |= 0x400u;
      else
        v2->state.actionsState.state &= 0xFFFFFBFF;
      v16 = v2->state.timeStamp - v2->lastTime;
      v2->state.kersIsCharging = (v2->netStates[0].statusBytes & 0x200) != 0;
      v2->state.performanceMeter = v2->netStates[0].performanceDelta;
      v17 = (unsigned int)v16;
      v18 = v2->state.timeStamp;
      v2->state.lapTime = v17;
      v2->lastUpdateTime = v18;
      v19 = (const __m128i *)NetCarStateProvider::getSmoothBodyMatrix(v2, (mat44f *)result_8, physics_time, &v2->state);
      v20 = (__m128 *)&v2->bodyMatrix;
      index[2] = 0;
      v21 = (int)&v2->wheelBasePosLS[0].M31;
      *(_DWORD *)&isLagging[8] = 1;
      index[0] = (int)&v2->wheelBasePosLS[0].M31;
      *(__m128i *)&v2->bodyMatrix.M11 = _mm_loadu_si128(v19);
      *(__m128i *)&v2->bodyMatrix.M21 = _mm_loadu_si128(v19 + 1);
      *(__m128i *)&v2->bodyMatrix.M31 = _mm_loadu_si128(v19 + 2);
      v22 = _mm_loadu_si128(v19 + 3);
      index[1] = (int)v2->netStates[0].tyreAngularSpeed;
      v162 = v2->state.tyreContactPoint;
      *(__m128i *)&v2->bodyMatrix.M41 = v22;
      HIDWORD(v161) = v2->state.tyreSurfaceDef;
      while ( 1 )
      {
        v23 = v20[1];
        v24 = v20[2];
        v25 = v20[3];
        M2_8.r[0] = *v20;
        v26 = *(__m128 *)(v21 - 32);
        M2_8.r[1] = v23;
        v27 = *(_OWORD *)(v21 - 16);
        M2_8.r[2] = v24;
        v28 = *(_OWORD *)v21;
        M2_8.r[3] = v25;
        v29 = *(_OWORD *)(v21 + 16);
        *(__m128 *)(v21 - 968) = DirectX::XMMatrixMultiply(M2_8.r, v26);
        *(_OWORD *)(v21 - 952) = v27;
        *(_OWORD *)(v21 - 936) = v28;
        *(_OWORD *)(v21 - 920) = v29;
        v30 = *(__m128 *)&v2->bodyMatrix.M21;
        v31 = *(__m128 *)&v2->bodyMatrix.M31;
        v32 = *(_OWORD *)&v2->bodyMatrix.M41;
        v170[0] = *(__m128 *)&v2->bodyMatrix.M11;
        v33 = *(_OWORD *)(v21 + 16);
        v170[1] = v30;
        v34 = *(_OWORD *)v21;
        v170[2] = v31;
        v35 = *(_OWORD *)(v21 - 16);
        v171 = v32;
        *(__m128 *)(v21 - 712) = DirectX::XMMatrixMultiply(v170, *(__m128 *)(v21 - 32));
        *(_OWORD *)(v21 - 696) = v35;
        *(_OWORD *)(v21 - 680) = v34;
        *(_OWORD *)(v21 - 664) = v33;
        v36 = *(_DWORD *)(v21 - 920);
        *(_DWORD *)isLagging = *(_DWORD *)(v21 - 916);
        Px[3] = *(float *)(v21 - 912);
        *(_DWORD *)&isLagging[4] = v36;
        if ( __fdtest((float *)&isLagging[4]) > 0 || __fdtest((float *)isLagging) > 0 || __fdtest(&Px[3]) > 0 )
        {
          _printf("ERROR: Netcar wheel matrix is not finite\n");
          _printf(
            "|%f %f %f %f|\n",
            *(float *)(v21 - 968),
            *(float *)(v21 - 952),
            *(float *)(v21 - 936),
            *(float *)(v21 - 920));
          _printf(
            "|%f %f %f %f|\n",
            *(float *)(v21 - 964),
            *(float *)(v21 - 948),
            *(float *)(v21 - 932),
            *(float *)(v21 - 916));
          _printf(
            "|%f %f %f %f|\n",
            *(float *)(v21 - 960),
            *(float *)(v21 - 944),
            *(float *)(v21 - 928),
            *(float *)(v21 - 912));
          _printf(
            "|%f %f %f %f|\n",
            *(float *)(v21 - 956),
            *(float *)(v21 - 940),
            *(float *)(v21 - 924),
            *(float *)(v21 - 908));
        }
        if ( (index[2] & 1) != 0 )
          v37 = FLOAT_N0_034906;
        else
          v37 = FLOAT_0_034906;
        *(float *)&isLagging[4] = v37;
        *(_DWORD *)isLagging = __libm_sse2_cosf(v152, v153).m128_u32[0];
        *(_DWORD *)&isLagging[4] = __libm_sse2_sinf().m128_u32[0];
        Px[3] = 1.0 - *(float *)isLagging;
        mat44f::mat44f((mat44f *)&v157[1]);
        HIDWORD(v157[8]) = 1065353216;
        v38 = *(__m128 *)(v21 - 712);
        *(float *)&v157[6] = Px[3] + *(float *)isLagging;
        v174[0] = v38;
        v39 = *(_OWORD *)&v157[7];
        *((float *)&v157[3] + 1) = *(float *)isLagging + (float)(Px[3] * 0.0);
        *(float *)&v157[1] = *((float *)&v157[3] + 1);
        *((float *)&v157[1] + 1) = *(float *)&isLagging[4] + (float)(Px[3] * 0.0);
        *(float *)&v157[3] = (float)(Px[3] * 0.0) - *(float *)&isLagging[4];
        *(float *)&v157[2] = (float)(Px[3] * 0.0) - (float)(*(float *)&isLagging[4] * 0.0);
        *(float *)&v157[5] = (float)(*(float *)&isLagging[4] * 0.0) + (float)(Px[3] * 0.0);
        v40 = *(__m128 *)(v21 - 680);
        *(float *)&v157[4] = *(float *)&v157[5];
        v41 = *(_OWORD *)(v21 - 664);
        *((float *)&v157[5] + 1) = *(float *)&v157[2];
        v42 = *(__m128 *)(v21 - 696);
        v174[2] = v40;
        v43 = *(_OWORD *)&v157[3];
        v174[1] = v42;
        v44 = *(_OWORD *)&v157[5];
        v175 = v41;
        *(__m128 *)(v21 - 712) = DirectX::XMMatrixMultiply(v174, *(__m128 *)&v157[1]);
        v45 = 1.0 - *(float *)isLagging;
        *(_OWORD *)(v21 - 696) = v43;
        *(_OWORD *)(v21 - 680) = v44;
        *(_OWORD *)(v21 - 664) = v39;
        Px[3] = v45;
        mat44f::mat44f((mat44f *)&v157[1]);
        HIDWORD(v157[8]) = 1065353216;
        *(float *)&v157[6] = Px[3] + *(float *)isLagging;
        *(float *)&v157[1] = *(float *)isLagging + (float)(Px[3] * 0.0);
        *((float *)&v157[3] + 1) = *(float *)&v157[1];
        *((float *)&v157[1] + 1) = *(float *)&isLagging[4] + (float)(Px[3] * 0.0);
        *(float *)&v157[3] = (float)(Px[3] * 0.0) - *(float *)&isLagging[4];
        v178[0] = *(__m128 *)(v21 - 968);
        v46 = *(_OWORD *)&v157[7];
        *(float *)&v157[2] = (float)(Px[3] * 0.0) - (float)(*(float *)&isLagging[4] * 0.0);
        *(float *)&v157[5] = (float)(*(float *)&isLagging[4] * 0.0) + (float)(Px[3] * 0.0);
        v47 = *(__m128 *)(v21 - 936);
        *(float *)&v157[4] = *(float *)&v157[5];
        v48 = *(_OWORD *)(v21 - 920);
        *((float *)&v157[5] + 1) = *(float *)&v157[2];
        v49 = *(__m128 *)(v21 - 952);
        v178[2] = v47;
        v50 = *(_OWORD *)&v157[3];
        v178[1] = v49;
        v51 = *(_OWORD *)&v157[5];
        v179 = v48;
        v52 = DirectX::XMMatrixMultiply(v178, *(__m128 *)&v157[1]);
        v53 = index[2] < 2;
        *(__m128 *)(v21 - 968) = v52;
        *(_OWORD *)(v21 - 952) = v50;
        *(_OWORD *)(v21 - 936) = v51;
        *(_OWORD *)(v21 - 920) = v46;
        if ( v53 )
        {
          Px[3] = COERCE_FLOAT(LODWORD(v2->netStates[0].wheelAngle) ^ _xmm) * 0.017453;
          *(_DWORD *)isLagging = __libm_sse2_cosf(v152, v153).m128_u32[0];
          *(_DWORD *)&isLagging[4] = __libm_sse2_sinf().m128_u32[0];
          Px[3] = 1.0 - *(float *)isLagging;
          mat44f::mat44f((mat44f *)&v157[1]);
          HIDWORD(v157[8]) = 1065353216;
          *((float *)&v157[3] + 1) = Px[3] + *(float *)isLagging;
          *(float *)&v157[6] = *(float *)isLagging + (float)(Px[3] * 0.0);
          *(float *)&v157[1] = *(float *)&v157[6];
          *((float *)&v157[1] + 1) = (float)(*(float *)&isLagging[4] * 0.0) + (float)(Px[3] * 0.0);
          *(float *)&v157[3] = (float)(Px[3] * 0.0) - (float)(*(float *)&isLagging[4] * 0.0);
          *(float *)&v157[2] = (float)(Px[3] * 0.0) - *(float *)&isLagging[4];
          v172[0] = *(__m128 *)(v21 - 712);
          v54 = *(_OWORD *)&v157[7];
          *(float *)&v157[5] = *(float *)&isLagging[4] + (float)(Px[3] * 0.0);
          v55 = *(__m128 *)(v21 - 680);
          *(float *)&v157[4] = *((float *)&v157[1] + 1);
          v56 = *(_OWORD *)(v21 - 664);
          *((float *)&v157[5] + 1) = *(float *)&v157[3];
          v57 = *(__m128 *)(v21 - 696);
          v172[2] = v55;
          v58 = *(_OWORD *)&v157[3];
          v172[1] = v57;
          v59 = *(_OWORD *)&v157[5];
          v173 = v56;
          *(__m128 *)(v21 - 712) = DirectX::XMMatrixMultiply(v172, *(__m128 *)&v157[1]);
          v60 = 1.0 - *(float *)isLagging;
          *(_OWORD *)(v21 - 696) = v58;
          *(_OWORD *)(v21 - 680) = v59;
          *(_OWORD *)(v21 - 664) = v54;
          Px[3] = v60;
          mat44f::mat44f((mat44f *)&v157[1]);
          HIDWORD(v157[8]) = 1065353216;
          *((float *)&v157[3] + 1) = Px[3] + *(float *)isLagging;
          *(float *)&v157[1] = *(float *)isLagging + (float)(Px[3] * 0.0);
          *(float *)&v157[6] = *(float *)&v157[1];
          *((float *)&v157[1] + 1) = (float)(*(float *)&isLagging[4] * 0.0) + (float)(Px[3] * 0.0);
          *(float *)&v157[3] = (float)(Px[3] * 0.0) - (float)(*(float *)&isLagging[4] * 0.0);
          *(float *)&v157[2] = (float)(Px[3] * 0.0) - *(float *)&isLagging[4];
          *(float *)&v157[5] = *(float *)&isLagging[4] + (float)(Px[3] * 0.0);
          v61 = *(__m128 *)(v21 - 968);
          v62 = *(__m128 *)(v21 - 936);
          *(float *)&v157[4] = *((float *)&v157[1] + 1);
          v63 = *(_OWORD *)(v21 - 920);
          *((float *)&v157[5] + 1) = *(float *)&v157[3];
          v64 = *(__m128 *)(v21 - 952);
          v176[0] = v61;
          v65 = *(_OWORD *)&v157[7];
          v176[1] = v64;
          v66 = *(_OWORD *)&v157[5];
          v176[2] = v62;
          v67 = *(_OWORD *)&v157[3];
          v177 = v63;
          *(__m128 *)(v21 - 968) = DirectX::XMMatrixMultiply(v176, *(__m128 *)&v157[1]);
          *(_OWORD *)(v21 - 952) = v67;
          *(_OWORD *)(v21 - 936) = v66;
          *(_OWORD *)(v21 - 920) = v65;
        }
        v68 = v2->rayCastProvider;
        v69 = *(float *)(v21 - 664);
        v70 = *(_DWORD *)(v21 - 656);
        *(_OWORD *)v164 = 0i64;
        *(float *)&v71 = *(float *)(v21 - 660) + 1.0;
        *(_DWORD *)&v164[16] = 0;
        v165 = 0;
        v163 = 0;
        result = 0;
        result_4 = 0;
        v159 = 0xBF80000000000000ui64;
        v160 = 0.0;
        *(_QWORD *)&v161 = __PAIR64__(v71, LODWORD(v69));
        DWORD2(v161) = v70;
        v72 = v68->__vftable;
        Px[3] = v69;
        v73 = v72->rayCast;
        *(_DWORD *)&isLagging[4] = v70;
        if ( ((unsigned __int8 (*)(IRayTrackCollisionProvider *, __int128 *, unsigned __int64 *, const void **, int))v73)(
               v68,
               &v161,
               &v159,
               &v163,
               1084227584) )
        {
          v2->body->worldToLocal(v2->body, (vec3f *)&index[3], (const vec3f *)v164);
          v74 = *(float *)(v21 + 20);
          v75 = *(float *)(index[1] + 3896);
          v76 = (float)(v74 + 0.1) - v75;
          v77 = (float)(v74 - 0.1) - v75;
          if ( *(float *)v157 <= v76 )
          {
            if ( v77 <= *(float *)v157 )
              v76 = *(float *)v157;
            else
              v76 = v77;
          }
          v78 = v2->body;
          *(float *)v157 = v76;
          v78->localToWorld(v78, (vec3f *)&pDeterminant, (const vec3f *)&index[3]);
          v79 = (void *)HIDWORD(v161);
          v80 = *(float *)(index[1] + 3896) + pDeterminant.m128_f32[1];
          *(float *)(v21 - 664) = Px[3];
          v81 = v165;
          *(float *)(v21 - 660) = v80;
          *(_DWORD *)(v21 - 656) = *(_DWORD *)&isLagging[4];
          *(__m128i *)(v21 - 968) = _mm_loadu_si128((const __m128i *)(v21 - 712));
          *(__m128i *)(v21 - 952) = _mm_loadu_si128((const __m128i *)(v21 - 696));
          *(__m128i *)(v21 - 936) = _mm_loadu_si128((const __m128i *)(v21 - 680));
          *(__m128i *)(v21 - 920) = _mm_loadu_si128((const __m128i *)(v21 - 664));
          v82 = *(_QWORD *)&v164[12];
          qmemcpy(v79, v163, 0xBCu);
          v83 = v162;
          v21 = index[0];
          v2 = *(NetCarStateProvider **)&isLagging[12];
          *(_QWORD *)&v162[4].x = v82;
          v84 = *(_QWORD *)v164;
          LODWORD(v83[4].z) = v81;
          v85 = *(float *)&v164[8];
          *(_QWORD *)&v83->x = v84;
          v83->z = v85;
        }
        v86 = (_DWORD *)index[1];
        if ( COERCE_FLOAT(*(_DWORD *)index[1] & _xmm) < 0.2 )
          *(_DWORD *)index[1] = 0;
        v86[315] = *v86;
        if ( *(float *)v86 != 0.0 )
        {
          Px[3] = *(float *)v86 * 0.003;
          *(_DWORD *)&isLagging[4] = __libm_sse2_cosf(v152, v153).m128_u32[0];
          index[0] = __libm_sse2_sinf().m128_u32[0];
          Px[3] = 1.0 - *(float *)&isLagging[4];
          mat44f::mat44f((mat44f *)&v157[1]);
          HIDWORD(v157[8]) = 1065353216;
          *(float *)&v157[1] = Px[3] + *(float *)&isLagging[4];
          *((float *)&v157[3] + 1) = (float)(Px[3] * 0.0) + *(float *)&isLagging[4];
          *(float *)&v157[6] = *((float *)&v157[3] + 1);
          *((float *)&v157[1] + 1) = (float)(*(float *)index * 0.0) + (float)(Px[3] * 0.0);
          *(float *)&v157[3] = (float)(Px[3] * 0.0) - (float)(*(float *)index * 0.0);
          *(float *)&v157[2] = *(float *)&v157[3];
          *(float *)&v157[5] = *((float *)&v157[1] + 1);
          *(float *)&v157[4] = *(float *)index + (float)(Px[3] * 0.0);
          *((float *)&v157[5] + 1) = (float)(Px[3] * 0.0) - *(float *)index;
          result_8[0] = *(__m128 *)&v157[1];
          v87 = *(__m128 *)(v21 + 3548);
          result_8[1] = *(__m128 *)&v157[3];
          v88 = *(_OWORD *)(v21 + 3564);
          result_8[2] = *(__m128 *)&v157[5];
          v89 = *(_OWORD *)(v21 + 3580);
          result_56 = *(__m128 *)&v157[7];
          v90 = *(_OWORD *)(v21 + 3596);
          v91 = DirectX::XMMatrixMultiply(result_8, v87);
          v86 = (_DWORD *)index[1];
          *(__m128 *)(v21 + 3548) = v91;
          *(_OWORD *)(v21 + 3564) = v88;
          *(_OWORD *)(v21 + 3580) = v89;
          *(_OWORD *)(v21 + 3596) = v90;
        }
        if ( (*(_DWORD *)&isLagging[8] & v2->netStates[0].statusBytes) != 0 )
        {
          v86[341] = 1070386381;
          v86[353] = 1101004800;
          v86[349] = 1080452710;
        }
        else
        {
          v86[349] = 0;
          v86[341] = 0;
        }
        v151 = index[2];
        v86[337] = 0;
        *(__m128i *)(v21 + 360) = _mm_loadu_si128((const __m128i *)(v21 - 712));
        *(__m128i *)(v21 + 376) = _mm_loadu_si128((const __m128i *)(v21 - 696));
        *(__m128i *)(v21 + 392) = _mm_loadu_si128((const __m128i *)(v21 - 680));
        *(__m128i *)(v21 + 408) = _mm_loadu_si128((const __m128i *)(v21 - 664));
        v92 = (const __m128i *)NetCarStateProvider::getTyreMatrix(v2, (mat44f *)&v157[1], v151);
        index[1] += 4;
        HIDWORD(v161) += 188;
        v93 = _mm_loadu_si128(v92);
        ++v162;
        v94 = __ROL4__(*(_DWORD *)&isLagging[8], 1);
        *(__m128i *)(v21 + 616) = v93;
        *(_DWORD *)&isLagging[8] = v94;
        *(__m128i *)(v21 + 632) = _mm_loadu_si128(v92 + 1);
        *(__m128i *)(v21 + 648) = _mm_loadu_si128(v92 + 2);
        v95 = _mm_loadu_si128(v92 + 3);
        v96 = index[2] + 1;
        *(__m128i *)(v21 + 664) = v95;
        v21 += 64;
        index[2] = v96;
        index[0] = v21;
        if ( v96 >= 4 )
          break;
        v20 = (__m128 *)&v2->bodyMatrix;
      }
      if ( v2->p2p.enabled )
      {
        v97 = (float *)&isLagging[12];
        v98 = v2->p2p.timeAccum + 0.003;
        Px[3] = 1000.0;
        *(float *)&isLagging[12] = v98;
        if ( v98 >= 1000.0 )
          v97 = &Px[3];
        v99 = !v2->p2p.active;
        v100 = *v97;
        v2->p2p.timeAccum = *v97;
        if ( !v99 && v100 > v2->p2p.timeS )
        {
          v2->p2p.timeAccum = 0.0;
          v2->p2p.active = 0;
        }
        v99 = !v2->p2p.active;
        v2->state.p2pStatus = 0;
        if ( v99 )
        {
          if ( v2->p2p.activations <= 0 || v2->p2p.timeAccum <= v2->p2p.coolDownS )
            v2->state.p2pStatus = 1;
          else
            v2->state.p2pStatus = 2;
        }
        else
        {
          v2->state.p2pStatus = 3;
        }
        v2->state.p2pActivations = v2->p2p.activations;
      }
      v101 = (const __m128i *)&v2->bodyMatrix;
      v102 = v2->bodyMatrix.M43;
      v103 = (float)((float)((float)((float)(v2->state.tyreContactPoint[1].y + v2->state.tyreContactPoint[0].y)
                                   + v2->state.tyreContactPoint[2].y)
                           + v2->state.tyreContactPoint[3].y)
                   * 0.25)
           + v2->netStates[0].targetHeight;
      v2->bodyMatrix.M41 = v2->bodyMatrix.M41;
      v2->bodyMatrix.M43 = v102;
      v2->bodyMatrix.M42 = v103;
      v104 = (float)(COERCE_FLOAT(LODWORD(v2->state.wheelAngularSpeed[2]) & _xmm)
                   + COERCE_FLOAT(LODWORD(v2->state.wheelAngularSpeed[3]) & _xmm))
           * 0.5;
      v105 = v104 * 0.02;
      if ( (float)(v104 * 0.02) <= 1.0 )
      {
        if ( v105 < 0.0 )
          v105 = 0.0;
      }
      else
      {
        v105 = FLOAT_1_0;
      }
      v106 = v2->state.drivetrainSpeed;
      v107 = physics_time - v2->netStates[0].rcvTime;
      v108 = v2->client->remoteFactor;
      pDeterminant.m128_u64[0] = 0i64;
      pDeterminant.m128_i32[2] = 0;
      v2->state.timeStamp = physics_time;
      *(float *)&v107 = v107 / v108;
      *(float *)&v108 = (float)(1.0 - v105) * 0.7;
      v2->state.drivetrainSpeed = (float)((float)(*(float *)&v107 * (float)(*(float *)&v108 + 0.02))
                                        * (float)(v104 - v106))
                                + v106;
      *(float *)&v107 = v2->state.tyreContactPoint[2].z;
      v109 = v2->state.tyreContactPoint[1].y - v2->state.tyreContactPoint[0].y;
      v110 = v2->state.tyreContactPoint[2].y - v2->state.tyreContactPoint[0].y;
      v111 = v2->state.tyreContactPoint[1].z;
      v112 = v2->state.tyreContactPoint[2].x - v2->state.tyreContactPoint[0].x;
      *(float *)&isLagging[12] = v2->state.tyreContactPoint[1].x - v2->state.tyreContactPoint[0].x;
      v113 = v2->state.tyreContactPoint[0].z;
      *(float *)&v107 = *(float *)&v107 - v113;
      Px[3] = v113;
      v114 = v111 - v113;
      *(float *)&isLagging[8] = (float)(*(float *)&v107 * v109) - (float)(v110 * v114);
      v115 = (float)(v110 * *(float *)&isLagging[12]) - (float)(v112 * v109);
      *(float *)&isLagging[12] = (float)(v112 * v114) - (float)(*(float *)&v107 * *(float *)&isLagging[12]);
      v116 = (float)((float)(*(float *)&isLagging[12] * *(float *)&isLagging[12])
                   + (float)(*(float *)&isLagging[8] * *(float *)&isLagging[8]))
           + (float)(v115 * v115);
      if ( v116 <= 0.0 )
      {
        pDeterminant.m128_i32[3] = 0;
      }
      else
      {
        v117 = 1.0 / fsqrt(v116);
        pDeterminant.m128_f32[1] = v117 * *(float *)&isLagging[12];
        v118 = (float)(v117 * *(float *)&isLagging[12]) * v2->state.tyreContactPoint[0].y;
        pDeterminant.m128_f32[0] = v117 * *(float *)&isLagging[8];
        v119 = (float)(v117 * *(float *)&isLagging[8]) * v2->state.tyreContactPoint[0].x;
        pDeterminant.m128_f32[2] = v117 * v115;
        pDeterminant.m128_i32[3] = COERCE_UNSIGNED_INT((float)(v118 + v119) + (float)((float)(v117 * v115) * Px[3])) ^ _xmm;
      }
      v2->state.groundPlane = (plane4f)_mm_loadu_si128((const __m128i *)&pDeterminant);
      v2->state.gear = v2->netStates[0].gearIndex;
      v120 = (float)v2->netStates[0].engineRPM;
      v160 = v2->smoothVelocity.z;
      v2->state.engineRPM = v120;
      v2->lastStepSpeedkmh = v2->state.speed.value * 3.5999999;
      v121 = (float)((float)(v2->netStates[0].gas - v2->lastStepGas) * 0.050000001) + v2->lastStepGas;
      *(__m128i *)&v2->state.worldMatrix.M11 = _mm_loadu_si128(v101);
      v122 = _mm_loadu_si128((const __m128i *)&v2->bodyMatrix.M21);
      v2->state.gas = v121;
      *(__m128i *)&v2->state.worldMatrix.M21 = v122;
      v123 = _mm_loadu_si128((const __m128i *)&v2->bodyMatrix.M31);
      v2->lastStepGas = v121;
      *(__m128i *)&v2->state.worldMatrix.M31 = v123;
      *(__m128i *)&v2->state.worldMatrix.M41 = _mm_loadu_si128((const __m128i *)&v2->bodyMatrix.M41);
      v124 = v2->netStates[0].velocity.z;
      v159 = *(_QWORD *)&v2->smoothVelocity.x;
      *(_QWORD *)&v161 = *(_QWORD *)&v2->netStates[0].velocity.x;
      v125 = (__m128)(unsigned int)v161;
      v126 = (__m128)DWORD1(v161);
      *((float *)&v161 + 2) = v124;
      v125.m128_f32[0] = (float)((float)(*(float *)&v161 - *(float *)&v159) * 0.003) + *(float *)&v159;
      v126.m128_f32[0] = (float)((float)(*((float *)&v161 + 1) - *((float *)&v159 + 1)) * 0.003) + *((float *)&v159 + 1);
      v127 = (float)((float)(v124 - v160) * 0.003) + v160;
      *(_QWORD *)&v2->smoothVelocity.x = _mm_unpacklo_ps(v125, v126).m128_u64[0];
      pDeterminant.m128_f32[2] = v127;
      v2->smoothVelocity.z = v127;
      v128 = (float)((float)(v2->smoothVelocity.y - v2->state.velocity.y) * 333.33334) * 0.10197838;
      v129 = (float)((float)(v2->smoothVelocity.z - v2->state.velocity.z) * 333.33334) * 0.10197838;
      *(float *)index = (float)((float)(v2->smoothVelocity.x - v2->state.velocity.x) * 333.33334) * 0.10197838;
      *(float *)&isLagging[12] = v128;
      *(float *)&isLagging[8] = v129;
      mat44f::mat44f((mat44f *)result_8);
      v130 = *(__m128 *)&v2->bodyMatrix.M21;
      v131 = *(__m128 *)&v2->bodyMatrix.M31;
      v132 = *(__m128 *)&v2->bodyMatrix.M41;
      v133 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)v101, v130, v131, v132);
      v134 = v130;
      v135 = v130;
      result_56 = v132;
      v135.m128_f32[0] = (float)(v130.m128_f32[0] * *(float *)&isLagging[12])
                       + (float)(v133.m128_f32[0] * *(float *)index);
      v136 = _mm_shuffle_ps(v130, v130, 85);
      v135.m128_f32[0] = v135.m128_f32[0] + (float)(v131.m128_f32[0] * *(float *)&isLagging[8]);
      v126.m128_f32[0] = _mm_shuffle_ps(v133, v133, 170).m128_f32[0] * *(float *)index;
      v136.m128_f32[0] = (float)(v136.m128_f32[0] * *(float *)&isLagging[12])
                       + (float)(_mm_shuffle_ps(v133, v133, 85).m128_f32[0] * *(float *)index);
      v133.m128_f32[0] = _mm_shuffle_ps(v131, v131, 85).m128_f32[0];
      v134.m128_f32[0] = (float)(_mm_shuffle_ps(v134, v134, 170).m128_f32[0] * *(float *)&isLagging[12])
                       + v126.m128_f32[0];
      v131.m128_f32[0] = _mm_shuffle_ps(v131, v131, 170).m128_f32[0] * *(float *)&isLagging[8];
      v136.m128_f32[0] = v136.m128_f32[0] + (float)(v133.m128_f32[0] * *(float *)&isLagging[8]);
      *(_QWORD *)&v2->state.velocity.x = *(_QWORD *)&v2->smoothVelocity.x;
      *(_QWORD *)&v2->state.accG.x = _mm_unpacklo_ps(v135, v136).m128_u64[0];
      pDeterminant.m128_f32[2] = v134.m128_f32[0] + v131.m128_f32[0];
      v2->state.accG.z = v134.m128_f32[0] + v131.m128_f32[0];
      v2->state.velocity.z = v2->smoothVelocity.z;
      if ( (v2->netStates[0].statusBytes & 0x10) != 0 )
        v2->state.brake = 1.0;
      else
        v2->state.brake = 0.0;
      v137 = v2->body;
      v2->state.steer = v2->netStates[0].steerAngle;
      v137->setRotation(v137, &v2->bodyMatrix);
      v138 = v2->body;
      index[3] = LODWORD(v2->bodyMatrix.M41);
      v157[0] = *(_QWORD *)&v2->bodyMatrix.M42;
      v138->setPosition(v138, (const vec3f *)&index[3]);
      v139 = v2->body->__vftable;
      *(float *)&isLagging[12] = v2->hasCollisionInThisStep;
      if ( *(float *)&isLagging[12] >= 0.0 )
      {
        v141 = (float *)((int (__stdcall *)(__m128 *))v139->getVelocity)(&pDeterminant);
        v142 = v2->body;
        *(float *)&v143 = v2->netStates[0].velocity.y
                        + (float)((float)(v141[1] - v2->netStates[0].velocity.y) * *(float *)&isLagging[12]);
        *(float *)&v144 = v2->netStates[0].velocity.z
                        + (float)((float)(v141[2] - v2->netStates[0].velocity.z) * *(float *)&isLagging[12]);
        *(float *)&index[3] = v2->netStates[0].velocity.x
                            + (float)((float)(*v141 - v2->netStates[0].velocity.x) * *(float *)&isLagging[12]);
        v157[0] = __PAIR64__(v144, v143);
        v142->setVelocity(v142, (const vec3f *)&index[3]);
      }
      else
      {
        ((void (__stdcall *)(vec3f *))v139->setVelocity)(&v2->netStates[0].velocity);
        v140 = v2->body;
        index[3] = 0;
        v157[0] = 0i64;
        v140->setAngularVelocity(v140, (const vec3f *)&index[3]);
      }
      v145 = v2->avatar->sim->physicsAvatar->engine.track->aiSplineRecorder._Myptr;
      v150 = (const vec3f *)((int (*)(void))v2->body->getPosition)();
      v146 = AISplineRecorder::getBestLapSpline(v145);
      v2->state.normalizedSplinePosition = SplineLocator::locateOnSpline(v146, v150, (int *)&pDeterminant);
      NetCarStateProvider::stepWings(v2);
      v147 = v2->body;
      v148 = ((int (*)(IRigidBody *, _QWORD *, _DWORD))v147->getVelocity)(v147, &v157[8], 0);
      v149 = (const vec3f *)((int (*)(IRigidBody *, int *, _DWORD, int))v147->getPosition)(
                              v147,
                              &index[2],
                              0,
                              v148);
      SlipStream::setPosition(&v2->slipStream, v149, (const vec3f *)&v2->splineLocationData);
      v2->hasCollisionInThisStep = v2->hasCollisionInThisStep - 0.003;
    }
  }
}
void NetCarStateProvider::stepLagging(NetCarStateProvider *this, long double physics_time)
{
  float *v3; // esi
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm2
  __int128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __int128 v14; // xmm3
  __int128 v15; // xmm2
  __int128 v16; // xmm1
  float v17; // xmm0_4
  IRayTrackCollisionProvider *v18; // ecx
  __int64 v19; // xmm1_8
  float v20; // xmm2_4
  float v21; // xmm0_4
  IRayTrackCollisionProvider_vtbl *v22; // eax
  bool (*v23)(IRayTrackCollisionProvider *, const vec3f *, const vec3f *, RayCastResult *, float); // eax
  char v24; // al
  __m128 v25; // xmm2
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // ecx
  NetCarStateProvider *v29; // eax
  const __m128i *v30; // eax
  int v31; // ecx
  __m128i v32; // xmm0
  float v33; // xmm1_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm0_4
  float v44; // xmm6_4
  __m128 v45; // xmm3
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  IRigidBody *v50; // ecx
  __m128i v51; // xmm0
  __m128i v52; // xmm0
  __m128i v53; // xmm0
  IRigidBody *v54; // ecx
  IRigidBody *v55; // ecx
  CarAvatar *v56; // eax
  AISpline *v57; // eax
  int v58; // [esp+1Ch] [ebp-144h]
  float v59; // [esp+28h] [ebp-138h] BYREF
  vec3f pos; // [esp+2Ch] [ebp-134h] BYREF
  float Px; // [esp+38h] [ebp-128h] BYREF
  NetCarStateProvider *v62; // [esp+3Ch] [ebp-124h]
  float v63[4]; // [esp+40h] [ebp-120h] BYREF
  __m128i v64; // [esp+50h] [ebp-110h] BYREF
  int v65[3]; // [esp+68h] [ebp-F8h] BYREF
  int v66; // [esp+74h] [ebp-ECh] BYREF
  _BYTE v67[24]; // [esp+78h] [ebp-E8h]
  char v68; // [esp+90h] [ebp-D0h]
  int v69; // [esp+94h] [ebp-CCh]
  __int64 v70; // [esp+98h] [ebp-C8h] BYREF
  DirectX::XMMATRIX v71; // [esp+A0h] [ebp-C0h] BYREF
  DirectX::XMMATRIX M2; // [esp+E0h] [ebp-80h] BYREF
  mat44f result; // [esp+120h] [ebp-40h] BYREF

  v63[3] = 0.0;
  v70 = 0i64;
  v62 = (NetCarStateProvider *)this->state.wheelAngularSpeed;
  v3 = &this->wheelBasePosLS[0].M31;
  LODWORD(v63[2]) = this->state.tyreContactNormal;
  do
  {
    v4 = *(__m128 *)&this->pitPosition.M21;
    v5 = *(__m128 *)&this->pitPosition.M31;
    v6 = *(__m128 *)&this->pitPosition.M41;
    M2.r[0] = *(__m128 *)&this->pitPosition.M11;
    v7 = *(__m128 *)(v3 - 8);
    M2.r[1] = v4;
    v8 = *((_OWORD *)v3 - 1);
    M2.r[2] = v5;
    v9 = *(_OWORD *)v3;
    M2.r[3] = v6;
    v10 = *((_OWORD *)v3 + 1);
    *(__m128 *)(v3 - 242) = DirectX::XMMatrixMultiply(M2.r, v7);
    *(_OWORD *)(v3 - 238) = v8;
    *(_OWORD *)(v3 - 234) = v9;
    *(_OWORD *)(v3 - 230) = v10;
    v11 = *(__m128 *)&this->pitPosition.M21;
    v12 = *(__m128 *)&this->pitPosition.M31;
    v13 = *(__m128 *)&this->pitPosition.M41;
    v71.r[0] = *(__m128 *)&this->pitPosition.M11;
    v14 = *((_OWORD *)v3 + 1);
    v71.r[1] = v11;
    v15 = *(_OWORD *)v3;
    v71.r[2] = v12;
    v16 = *((_OWORD *)v3 - 1);
    v71.r[3] = v13;
    *(__m128 *)(v3 - 178) = DirectX::XMMatrixMultiply(v71.r, *(__m128 *)(v3 - 8));
    *(_OWORD *)(v3 - 174) = v16;
    *(_OWORD *)(v3 - 170) = v15;
    *(_OWORD *)(v3 - 166) = v14;
    v17 = *(v3 - 230);
    v59 = *(v3 - 229);
    v63[0] = *(v3 - 228);
    Px = v17;
    if ( __fdtest(&Px) > 0 || __fdtest(&v59) > 0 || __fdtest(v63) > 0 )
    {
      _printf("ERROR: Netcar wheel matrix is not finite\n");
      _printf("|%f %f %f %f|\n", *(v3 - 242), *(v3 - 238), *(v3 - 234), *(v3 - 230));
      _printf("|%f %f %f %f|\n", *(v3 - 241), *(v3 - 237), *(v3 - 233), *(v3 - 229));
      _printf("|%f %f %f %f|\n", *(v3 - 240), *(v3 - 236), *(v3 - 232), *(v3 - 228));
      _printf("|%f %f %f %f|\n", *(v3 - 239), *(v3 - 235), *(v3 - 231), *(v3 - 227));
    }
    v18 = this->rayCastProvider;
    v19 = *((unsigned int *)v3 - 166);
    v20 = *(v3 - 164);
    *(_OWORD *)v67 = 0i64;
    v21 = *(v3 - 165) + 1.0;
    *(_QWORD *)&v67[16] = 0i64;
    v66 = 0;
    v68 = 0;
    v69 = 0;
    v65[0] = 0;
    v65[1] = -1082130432;
    v65[2] = 0;
    LODWORD(pos.x) = v19;
    pos.y = v21;
    pos.z = v20;
    v22 = v18->__vftable;
    *(_QWORD *)v63 = v19;
    v23 = v22->rayCast;
    Px = v20;
    v24 = ((int (*)(IRayTrackCollisionProvider *, vec3f *, int *, int *, int))v23)(
            v18,
            &pos,
            v65,
            &v66,
            1092616192);
    v25 = (__m128)*(unsigned int *)&v67[4];
    if ( v24 )
    {
      v26 = *(float *)&v62->state.tyreSurfaceDef[1].wavString[10];
      *((_DWORD *)v3 - 166) = _mm_loadl_epi64((const __m128i *)v63).m128i_u32[0];
      v27 = Px;
      *(v3 - 164) = Px;
      *(v3 - 165) = v26 + v25.m128_f32[0];
      *(__m128i *)(v3 - 242) = _mm_loadu_si128((const __m128i *)(v3 - 178));
      *(__m128i *)(v3 - 238) = _mm_loadu_si128((const __m128i *)(v3 - 174));
      *(__m128i *)(v3 - 234) = _mm_loadu_si128((const __m128i *)(v3 - 170));
      *(__m128i *)(v3 - 230) = _mm_loadu_si128((const __m128i *)(v3 - 166));
    }
    else
    {
      v27 = Px;
    }
    v28 = v63[2];
    v58 = LODWORD(v63[3]);
    *(_QWORD *)(LODWORD(v63[2]) - 48) = _mm_unpacklo_ps((__m128)_mm_loadl_epi64((const __m128i *)v63), v25).m128_u64[0];
    *(_QWORD *)LODWORD(v28) = *(_QWORD *)&v67[12];
    *(float *)&v64.m128i_i32[2] = v27;
    *(float *)(LODWORD(v28) - 40) = v27;
    *(_DWORD *)(LODWORD(v28) + 8) = *(_DWORD *)&v67[20];
    v29 = v62;
    v62->GameObject::__vftable = 0;
    *(_DWORD *)&v29->driverInfo.team._Bx._Alias[8] = 0;
    *(__m128i *)(v3 + 90) = _mm_loadu_si128((const __m128i *)(v3 - 178));
    *(__m128i *)(v3 + 94) = _mm_loadu_si128((const __m128i *)(v3 - 174));
    *(__m128i *)(v3 + 98) = _mm_loadu_si128((const __m128i *)(v3 - 170));
    *(__m128i *)(v3 + 102) = _mm_loadu_si128((const __m128i *)(v3 - 166));
    v30 = (const __m128i *)NetCarStateProvider::getTyreMatrix(this, &result, v58);
    v62 = (NetCarStateProvider *)((char *)v62 + 4);
    LODWORD(v63[2]) += 12;
    v32 = _mm_loadu_si128(v30);
    v31 = ++LODWORD(v63[3]);
    *(__m128i *)(v3 + 154) = v32;
    *(__m128i *)(v3 + 158) = _mm_loadu_si128(v30 + 1);
    *(__m128i *)(v3 + 162) = _mm_loadu_si128(v30 + 2);
    *(__m128i *)(v3 + 166) = _mm_loadu_si128(v30 + 3);
    v3 += 16;
  }
  while ( v31 < 4 );
  this->state.timeStamp = physics_time;
  v33 = this->state.tyreContactPoint[0].y;
  v34 = this->state.tyreContactPoint[2].y - v33;
  v35 = this->state.tyreContactPoint[0].z;
  v36 = this->state.tyreContactPoint[1].y - v33;
  v37 = this->state.tyreContactPoint[2].z - v35;
  v38 = this->state.tyreContactPoint[0].x;
  v39 = this->state.tyreContactPoint[1].z - v35;
  v40 = this->state.tyreContactPoint[2].x - v38;
  v41 = this->state.tyreContactPoint[1].x - v38;
  v59 = v35;
  v64.m128i_i64[0] = 0i64;
  v64.m128i_i32[2] = 0;
  v42 = (float)(v37 * v36) - (float)(v34 * v39);
  v43 = v40;
  v44 = (float)(v34 * v41) - (float)(v40 * v36);
  v45 = (__m128)_mm_loadl_epi64((const __m128i *)&v70);
  v63[0] = (float)(v43 * v39) - (float)(v37 * v41);
  v46 = (float)((float)(v63[0] * v63[0]) + (float)(v42 * v42)) + (float)(v44 * v44);
  if ( v46 <= v45.m128_f32[0] )
  {
    v64.m128i_i32[3] = 0;
  }
  else
  {
    v47 = 1.0 / fsqrt(v46);
    *(float *)&v64.m128i_i32[1] = v47 * v63[0];
    v48 = (float)(v47 * v63[0]) * this->state.tyreContactPoint[0].y;
    *(float *)v64.m128i_i32 = v47 * v42;
    v49 = (float)(v47 * v42) * this->state.tyreContactPoint[0].x;
    *(float *)&v64.m128i_i32[2] = v47 * v44;
    v64.m128i_i32[3] = COERCE_UNSIGNED_INT((float)(v48 + v49) + (float)((float)(v47 * v44) * v59)) ^ _xmm;
  }
  v50 = this->body;
  this->state.groundPlane = (plane4f)_mm_loadu_si128(&v64);
  v64.m128i_i32[2] = 0;
  v51 = _mm_loadu_si128((const __m128i *)&this->pitPosition);
  *(_QWORD *)&this->state.velocity.x = _mm_unpacklo_ps(v45, v45).m128_u64[0];
  *(__m128i *)&this->state.worldMatrix.M11 = v51;
  this->state.gear = 1;
  v52 = _mm_loadu_si128((const __m128i *)&this->pitPosition.M21);
  this->state.engineRPM = 0.0;
  this->state.gas = 0.0;
  *(__m128i *)&this->state.worldMatrix.M21 = v52;
  this->state.velocity.z = 0.0;
  v53 = _mm_loadu_si128((const __m128i *)&this->pitPosition.M31);
  this->state.brake = 0.0;
  this->state.steer = 0.0;
  *(__m128i *)&this->state.worldMatrix.M31 = v53;
  *(__m128i *)&this->state.worldMatrix.M41 = _mm_loadu_si128((const __m128i *)&this->pitPosition.M41);
  v50->setRotation(v50, &this->bodyMatrix);
  v54 = this->body;
  pos = *(vec3f *)&this->bodyMatrix.M41;
  v54->setPosition(v54, &pos);
  this->body->setVelocity(this->body, &this->instantVelocity);
  v55 = this->body;
  pos.x = 0.0;
  pos.y = 0.0;
  pos.z = 0.0;
  v55->setAngularVelocity(v55, &pos);
  v56 = this->avatar;
  pos = *(vec3f *)&this->state.worldMatrix.M41;
  v57 = AISplineRecorder::getBestLapSpline(v56->sim->physicsAvatar->engine.track->aiSplineRecorder._Myptr);
  this->state.normalizedSplinePosition = SplineLocator::locateOnSpline(
                                           v57,
                                           &pos,
                                           &this->splineLocationData.currentIndex);
}
void NetCarStateProvider::stepWings(NetCarStateProvider *this)
{
  int v2; // ebp
  int v3; // ecx
  std::vector<std::unique_ptr<DynamicWingController>> *v4; // edi
  DynamicWingController **v5; // esi
  float v6; // xmm0_4
  DynamicWingController **v7; // edi
  DynamicWingController *v8; // ecx
  DRSWingSetting *v9; // ecx
  DRSWingSetting *i; // eax
  float v11; // edx
  int v12; // edi
  float v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h]

  v15 = 0;
  if ( !(this->wingStates._Mylast - this->wingStates._Myfirst) )
    goto LABEL_17;
  v2 = 0;
  v3 = 0;
  v14 = 0;
  do
  {
    v4 = this->wingControllerLists._Myfirst;
    v5 = *(DynamicWingController ***)((char *)&v4->_Myfirst + v3);
    v6 = this->wingStates._Myfirst[v2].inputAngle;
    v7 = *(DynamicWingController ***)((char *)&v4->_Mylast + v3);
    v13 = v6;
    if ( v5 == v7 )
      goto LABEL_16;
    do
    {
      DynamicWingController::step(*v5);
      v8 = *v5;
      if ( (*v5)->combinatorMode == eAdd )
      {
        v6 = v8->outputAngle + v13;
        v13 = v6;
      }
      else if ( (*v5)->combinatorMode == eMult )
      {
        v6 = v8->outputAngle * v13;
        v13 = v6;
      }
      else
      {
        v6 = v13;
      }
      if ( v6 <= v8->upLimit )
      {
        if ( v8->downLimit <= v6 )
          goto LABEL_14;
        v6 = v8->downLimit;
      }
      else
      {
        v6 = v8->upLimit;
      }
      v13 = v6;
LABEL_14:
      ++v5;
    }
    while ( v5 != v7 );
    v3 = v14;
LABEL_16:
    v14 = v3 + 12;
    ++v15;
    this->wingStates._Myfirst[v2++].angle = v6;
    v3 += 12;
  }
  while ( v15 < this->wingStates._Mylast - this->wingStates._Myfirst );
LABEL_17:
  if ( (this->netStates[0].statusBytes & 0x400) != 0 )
  {
    v9 = this->drsWingSettings._Mylast;
    for ( i = this->drsWingSettings._Myfirst; i != v9; this->wingStates._Myfirst[v12].angle = v11 )
    {
      v11 = i->angle;
      v12 = i->index;
      ++i;
    }
  }
}
void NetCarStateProvider::update(NetCarStateProvider *this, float dt)
{
  CarAvatar *v2; // edx
  bool v3; // al

  v2 = this->avatar;
  if ( v2 )
  {
    v3 = this->game->gameTime.now - this->netStates[0].rcvTime > 5000.0 || this->isDisconnected;
    this->isDisconnected = v3;
    v2->carNode->isActive = !v3;
  }
}
