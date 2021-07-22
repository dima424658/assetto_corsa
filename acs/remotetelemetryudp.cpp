#include "remotetelemetryudp.h
void RemoteTelemetryUDP::RemoteTelemetryUDP(RemoteTelemetryUDP *this, Sim *aSim, CarAvatar *aCar)
{
  int v4; // eax
  unsigned int v5; // eax
  std::wstring v6; // [esp-1Ch] [ebp-3Ch] BYREF
  u_long v7; // [esp-4h] [ebp-24h]
  unsigned int nonBlocking; // [esp+8h] [ebp-18h] BYREF
  sockaddr_in local; // [esp+Ch] [ebp-14h] BYREF

  v7 = (u_long)aSim->game;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, L"RT_UDP", 6u);
  GameObject::GameObject(this, v6, (Game *)v7);
  this->__vftable = (RemoteTelemetryUDP_vtbl *)&RemoteTelemetryUDP::`vftable';
  this->listeners._Myfirst = 0;
  this->listeners._Mylast = 0;
  this->listeners._Myend = 0;
  this->rti.size = 328;
  this->rti.identifier = 97;
  this->rti.size = 328;
  this->car = aCar;
  v4 = aCar->physicsState.lapCount;
  v7 = 9996;
  v6._Myres = (unsigned int)"RemoteTelemetryUDP :: creating socket on port %d\n";
  this->lastLapCount = v4;
  _printf((const char *const)v6._Myres, v7);
  v5 = socket(2, 2, 0);
  v7 = 0;
  this->sok = v5;
  local.sin_addr.S_un.S_addr = htonl(v7);
  local.sin_family = 2;
  local.sin_port = htons(0x270Cu);
  if ( bind(this->sok, (const struct sockaddr *)&local, 16) == -1 )
    _printf("ERROR BINDING LISTENER SOCKET\n");
  nonBlocking = 1;
  if ( ioctlsocket(this->sok, -2147195266, &nonBlocking) )
  {
    _printf("RemoteTelemetryUDP :: failed to set non-blocking socket\n");
    closesocket(this->sok);
  }
}
RemoteTelemetryUDP *RemoteTelemetryUDP::`scalar deleting destructor'(RemoteTelemetryUDP *this, unsigned int a2)
{
  this->__vftable = (RemoteTelemetryUDP_vtbl *)&RemoteTelemetryUDP::`vftable';
  closesocket(this->sok);
  if ( this->listeners._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->listeners);
    operator delete(this->listeners._Myfirst);
    this->listeners._Myfirst = 0;
    this->listeners._Mylast = 0;
    this->listeners._Myend = 0;
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void RemoteTelemetryUDP::listen(RemoteTelemetryUDP *this)
{
  RTListener *v2; // eax
  RTListener *v3; // edx
  int v4; // edi
  std::wstring *v5; // ecx
  CarAvatar *v6; // ecx
  int *v7; // eax
  int v8; // edi
  wchar_t **v9; // ecx
  int *v10; // eax
  CarAvatar *v11; // eax
  TrackAvatar *v12; // ecx
  int *v13; // ecx
  int *v14; // ecx
  RTListener *v15; // eax
  RTListener *v16; // ecx
  __m128i v17; // xmm0
  RTListener *v18; // eax
  RTListener *v19; // ecx
  __m128i v20; // xmm0
  RTListener *v21; // eax
  RTListener *v22; // ecx
  ACClient *v23; // eax
  int v24; // eax
  sockaddr_in v25; // xmm0
  CarAvatar *v26; // ecx
  sockaddr_in v27; // xmm0
  unsigned int i; // edi
  CarAvatar *v29; // eax
  CarAvatar *v30; // ebx
  ACClient *v31; // ecx
  int *v32; // ecx
  int *v33; // ecx
  int idSession; // [esp+10h] [ebp-3E0h] BYREF
  int fromLength; // [esp+14h] [ebp-3DCh] BYREF
  sockaddr_in from; // [esp+18h] [ebp-3D8h] BYREF
  struct sockaddr to; // [esp+28h] [ebp-3C8h] BYREF
  CarCollisionBox _Val; // [esp+38h] [ebp-3B8h] BYREF
  RTDriverInfo info; // [esp+54h] [ebp-39Ch] BYREF
  wchar_t _Ptr[50]; // [esp+124h] [ebp-2CCh] BYREF
  wchar_t v41[50]; // [esp+188h] [ebp-268h] BYREF
  unsigned __int8 buffer[512]; // [esp+1ECh] [ebp-204h] BYREF

  fromLength = 16;
  if ( recvfrom(this->sok, (char *)buffer, 512, 0, (struct sockaddr *)&from, &fromLength) >= 0 )
  {
    switch ( *(_DWORD *)&buffer[8] )
    {
      case 0:
        v2 = this->listeners._Myfirst;
        v3 = this->listeners._Mylast;
        if ( v2 != v3 )
        {
          while ( v2->address.sin_addr.S_un.S_addr != from.sin_addr.S_un.S_addr || v2->address.sin_port != from.sin_port )
          {
            if ( ++v2 == v3 )
              goto LABEL_9;
          }
          std::vector<RTListener>::erase(
            &this->listeners,
            (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<RTListener> > > *)&idSession,
            (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RTListener> > >)v2);
        }
LABEL_9:
        v4 = 50;
        v5 = &this->car->unixName;
        if ( this->car->unixName._Mysize < 0x32 )
          v4 = this->car->unixName._Mysize;
        if ( this->car->unixName._Myres >= 8 )
          v5 = (std::wstring *)v5->_Bx._Ptr;
        if ( v4 )
          memcpy(&info, v5, 2 * v4);
        v6 = this->car;
        v7 = &idSession;
        idSession = v4;
        if ( v4 >= 50 )
          v7 = (int *)&CHAR_LENGHT;
        v8 = 50;
        v9 = (wchar_t **)&v6->driverInfo;
        info.driverName[*v7] = 37;
        if ( (unsigned int)v9[4] < 0x32 )
          v8 = (int)v9[4];
        if ( (unsigned int)v9[5] >= 8 )
          v9 = (wchar_t **)*v9;
        if ( v8 )
          memcpy(info.carName, v9, 2 * v8);
        idSession = v8;
        v10 = &idSession;
        if ( v8 >= 50 )
          v10 = (int *)&CHAR_LENGHT;
        info.carName[*v10] = 37;
        v11 = this->car;
        info.idSession = 4242;
        info.idLocal = 1;
        v12 = v11->sim->track;
        if ( v12 )
        {
          idSession = std::wstring::copy(&v12->name, _Ptr, 0x32u, 0);
          v13 = &idSession;
          if ( idSession >= 50 )
            v13 = (int *)&CHAR_LENGHT;
          _Ptr[*v13] = 37;
          idSession = std::wstring::copy(&this->car->sim->track->name, v41, 0x32u, 0);
          v14 = &idSession;
          if ( idSession >= 50 )
            v14 = (int *)&CHAR_LENGHT;
          v41[*v14] = 37;
        }
        else
        {
          _Ptr[0] = 37;
          v41[0] = 37;
        }
        to.sa_family = 2;
        *(_DWORD *)&to.sa_data[2] = from.sin_addr.S_un.S_addr;
        *(_WORD *)to.sa_data = from.sin_port;
        sendto(this->sok, (const char *)&info, 408, 0, &to, 16);
        break;
      case 1:
        v15 = this->listeners._Myfirst;
        v16 = this->listeners._Mylast;
        if ( v15 == v16 )
        {
LABEL_37:
          v17 = _mm_loadu_si128((const __m128i *)&from);
          _Val.centre.z = *(float *)buffer;
          _Val.centre.y = 0.0;
          *(__m128i *)&_Val.size.x = v17;
          LOBYTE(_Val.centre.x) = 0;
          std::vector<GrooveMesh>::push_back((std::vector<CarCollisionBox> *)&this->listeners, &_Val);
        }
        else
        {
          while ( v15->address.sin_addr.S_un.S_addr != from.sin_addr.S_un.S_addr
               || v15->address.sin_port != from.sin_port )
          {
            if ( ++v15 == v16 )
              goto LABEL_37;
          }
        }
        break;
      case 2:
        v18 = this->listeners._Myfirst;
        v19 = this->listeners._Mylast;
        if ( v18 == v19 )
        {
LABEL_42:
          v20 = _mm_loadu_si128((const __m128i *)&from);
          _Val.centre.z = *(float *)buffer;
          _Val.centre.y = 0.0;
          *(__m128i *)&_Val.size.x = v20;
          LOBYTE(_Val.centre.x) = 1;
          std::vector<GrooveMesh>::push_back((std::vector<CarCollisionBox> *)&this->listeners, &_Val);
        }
        else
        {
          while ( v18->address.sin_addr.S_un.S_addr != from.sin_addr.S_un.S_addr
               || v18->address.sin_port != from.sin_port )
          {
            if ( ++v18 == v19 )
              goto LABEL_42;
          }
        }
        break;
      case 3:
        v21 = this->listeners._Myfirst;
        v22 = this->listeners._Mylast;
        if ( v21 != v22 )
        {
          while ( v21->address.sin_addr.S_un.S_addr != from.sin_addr.S_un.S_addr
               || v21->address.sin_port != from.sin_port )
          {
            if ( ++v21 == v22 )
              return;
          }
          std::vector<RTListener>::erase(
            &this->listeners,
            (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<RTListener> > > *)&idSession,
            (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<RTListener> > >)v21);
        }
        break;
      case 4:
        v26 = this->car;
        *(_DWORD *)&to.sa_family = 0;
        *(_DWORD *)&to.sa_data[2] = 0;
        v27 = (sockaddr_in)_mm_loadu_si128((const __m128i *)&from);
        *(_DWORD *)&to.sa_family = v26->sim->connectedCarsCount;
        *(_DWORD *)&to.sa_data[2] = v26->sim->cars._Mylast - v26->sim->cars._Myfirst;
        RemoteTelemetryUDP::sendMessage(this, v27, this->sok, &to, 8);
        for ( i = 0; i < *(_DWORD *)&to.sa_data[2]; ++i )
        {
          v29 = Sim::getCar(this->car->sim, i);
          v30 = v29;
          if ( !i || CarAvatar::isConnected(v29) )
          {
            info.idLocal = CarAvatar::getGuid(v30);
            v31 = this->car->sim->client;
            if ( v31 )
              info.idSession = ACClient::getSessionIDFromCarAvatar(v31, v30);
            idSession = std::wstring::copy(&v30->driverInfo.name, info.driverName, 0x32u, 0);
            v32 = &idSession;
            if ( idSession >= 50 )
              v32 = (int *)&CHAR_LENGHT;
            info.driverName[*v32] = 37;
            idSession = std::wstring::copy(&v30->unixName, info.carName, 0x32u, 0);
            v33 = &idSession;
            if ( idSession >= 50 )
              v33 = (int *)&CHAR_LENGHT;
            info.carName[*v33] = 37;
            LOWORD(_Val.centre.x) = 2;
            LODWORD(_Val.centre.y) = from.sin_addr.S_un.S_addr;
            HIWORD(_Val.centre.x) = from.sin_port;
            sendto(this->sok, (const char *)&info, 208, 0, (const struct sockaddr *)&_Val, 16);
          }
        }
        break;
      case 5:
        v23 = this->car->sim->client;
        if ( v23 )
        {
          v24 = ACClient::getSessionIDFromCarAvatar(v23, this->car);
          v25 = (sockaddr_in)_mm_loadu_si128((const __m128i *)&from);
          idSession = v24;
          RemoteTelemetryUDP::sendMessage(this, v25, this->sok, &idSession, 4);
        }
        break;
      default:
        return;
    }
  }
}
void RemoteTelemetryUDP::onLapUpdateEvent(RemoteTelemetryUDP *this, int carId)
{
  CarAvatar *v3; // ebx
  wchar_t **v4; // ecx
  int v5; // edi
  int *v6; // eax
  int v7; // edi
  wchar_t **v8; // ecx
  int *v9; // eax
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // ebx
  int v13; // edi
  RTListener *v14; // eax
  __m128i v15; // xmm1
  int v16; // [esp+4h] [ebp-ECh] BYREF
  struct sockaddr to; // [esp+8h] [ebp-E8h] BYREF
  RTLap aLap; // [esp+18h] [ebp-D8h] BYREF

  if ( this->listeners._Myfirst != this->listeners._Mylast )
  {
    v3 = this->car;
    v4 = (wchar_t **)&v3->unixName;
    aLap.carID = carId;
    v5 = 50;
    if ( v3->unixName._Mysize < 0x32 )
      v5 = v3->unixName._Mysize;
    if ( v3->unixName._Myres >= 8 )
      v4 = (wchar_t **)*v4;
    if ( v5 )
      memcpy(aLap.carName, v4, 2 * v5);
    v16 = v5;
    v6 = &v16;
    if ( v5 >= 50 )
      v6 = (int *)&CHAR_LENGHT;
    v7 = 50;
    aLap.carName[*v6] = 37;
    v8 = (wchar_t **)&v3->driverInfo;
    if ( v3->driverInfo.name._Mysize < 0x32 )
      v7 = v3->driverInfo.name._Mysize;
    if ( v3->driverInfo.name._Myres >= 8 )
      v8 = (wchar_t **)*v8;
    if ( v7 )
      memcpy(aLap.driverName, v8, 2 * v7);
    v16 = v7;
    v9 = &v16;
    if ( v7 >= 50 )
      v9 = (int *)&CHAR_LENGHT;
    aLap.driverName[*v9] = 37;
    v10 = (char *)this->listeners._Mylast - (char *)this->listeners._Myfirst;
    aLap.lap = v3->physicsState.lapCount - 1;
    v11 = v3->physicsState.lastLap;
    v12 = 0;
    aLap.time = v11;
    if ( v10 / 28 )
    {
      v13 = 0;
      do
      {
        v14 = this->listeners._Myfirst;
        if ( v14[v13].isSpot )
        {
          v15 = _mm_loadu_si128((const __m128i *)&v14[v13].address);
          to.sa_family = 2;
          *(_DWORD *)&to.sa_data[2] = _mm_cvtsi128_si32(_mm_srli_si128(v15, 4));
          *(_WORD *)to.sa_data = (unsigned int)_mm_cvtsi128_si32(v15) >> 16;
          sendto(this->sok, (const char *)&aLap, 212, 0, &to, 16);
        }
        ++v12;
        ++v13;
      }
      while ( v12 < this->listeners._Mylast - this->listeners._Myfirst );
    }
  }
}
void RemoteTelemetryUDP::sendMessage(RemoteTelemetryUDP *this, sockaddr_in destination, unsigned int socket, const void *data, int size)
{
  sockaddr_in address; // [esp+0h] [ebp-14h] BYREF

  address.sin_family = 2;
  address.sin_addr.S_un.S_addr = destination.sin_addr.S_un.S_addr;
  address.sin_port = destination.sin_port;
  sendto(socket, (const char *)data, size, 0, (const struct sockaddr *)&address, 16);
}
void RemoteTelemetryUDP::update(RemoteTelemetryUDP *this, float dt)
{
  RemoteTelemetryUDP::listen(this);
  RemoteTelemetryUDP::updateListeners(this);
}
void RemoteTelemetryUDP::updateListeners(RemoteTelemetryUDP *this)
{
  unsigned int v2; // ebx
  int v3; // edi
  RTListener *v4; // eax
  __m128i v5; // xmm1
  struct sockaddr to; // [esp+4h] [ebp-14h] BYREF

  if ( this->listeners._Myfirst != this->listeners._Mylast )
  {
    RemoteTelemetryUDP::updateRTCarInfo(this);
    v2 = 0;
    if ( this->listeners._Mylast - this->listeners._Myfirst )
    {
      v3 = 0;
      do
      {
        v4 = this->listeners._Myfirst;
        if ( !v4[v3].isSpot )
        {
          v5 = _mm_loadu_si128((const __m128i *)&v4[v3].address);
          to.sa_family = 2;
          *(_DWORD *)&to.sa_data[2] = _mm_cvtsi128_si32(_mm_srli_si128(v5, 4));
          *(_WORD *)to.sa_data = (unsigned int)_mm_cvtsi128_si32(v5) >> 16;
          sendto(this->sok, &this->rti.identifier, 328, 0, &to, 16);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->listeners._Mylast - this->listeners._Myfirst );
    }
  }
  if ( this->lastLapCount != this->car->physicsState.lapCount )
  {
    RemoteTelemetryUDP::onLapUpdateEvent(this, 0);
    this->lastLapCount = this->car->physicsState.lapCount;
  }
}
void RemoteTelemetryUDP::updateRTCarInfo(RemoteTelemetryUDP *this)
{
  CarAvatar *v2; // ecx
  bool v3; // al
  CarAvatar *v4; // ecx
  bool v5; // al
  CarAvatar *v6; // ecx
  bool v7; // al
  CarAvatar *v8; // ecx
  CarAvatar *v9; // ecx
  bool v10; // al
  bool v11; // cf
  CarAvatar *v12; // ecx
  CarAvatar *v13; // eax
  unsigned __int64 v14; // xmm2_8
  float v15; // eax
  vec3f wp; // [esp+8h] [ebp-28h] BYREF
  int v17; // [esp+18h] [ebp-18h]
  unsigned int v18; // [esp+1Ch] [ebp-14h]
  int v19; // [esp+2Ch] [ebp-4h]

  v2 = this->car;
  this->rti.speed_Kmh = v2->physicsState.speed.value * 3.5999999;
  this->rti.speed_Ms = v2->physicsState.speed.value;
  this->rti.speed_Mph = v2->physicsState.speed.value * 2.2369363;
  v3 = CarAvatar::isAbsEnabled(v2);
  v4 = this->car;
  this->rti.isAbsEnabled = v3;
  v5 = CarAvatar::isAbsInAction(v4);
  v6 = this->car;
  this->rti.isAbsInAction = v5;
  v7 = CarAvatar::isTcInAction(v6);
  v8 = this->car;
  this->rti.isTcInAction = v7;
  this->rti.isTcEnabled = CarAvatar::isTcEnabled(v8);
  v18 = 7;
  v17 = 0;
  LOWORD(wp.x) = 0;
  std::wstring::assign((std::wstring *)&wp, L"PIT", 3u);
  v9 = this->car;
  v19 = 0;
  v10 = CarAvatar::isInSpawnPosition(v9, (const std::wstring *)&wp);
  v11 = v18 < 8;
  this->rti.isInPit = v10;
  if ( !v11 )
    operator delete(LODWORD(wp.x));
  v12 = this->car;
  this->rti.accG_vertical = v12->physicsState.accG.x;
  this->rti.accG_horizontal = v12->physicsState.accG.y;
  this->rti.accG_frontal = v12->physicsState.accG.z;
  this->rti.lapTime = v12->physicsState.lapTime;
  this->rti.lastLap = v12->physicsState.lastLap;
  this->rti.bestLap = v12->physicsState.bestLap;
  this->rti.lapCount = v12->physicsState.lapCount;
  this->rti.brake = v12->physicsState.brake;
  this->rti.clutch = v12->physicsState.clutch;
  this->rti.gas = v12->physicsState.gas;
  this->rti.engineRPM = v12->physicsState.engineRPM;
  this->rti.isEngineLimiterOn = v12->physicsState.isEngineLimiterOn;
  this->rti.steer = v12->physicsState.steer;
  this->rti.brake = v12->physicsState.brake;
  this->rti.clutch = v12->physicsState.clutch;
  this->rti.gear = v12->physicsState.gear;
  this->rti.cgHeight = v12->physicsState.cgHeight;
  this->rti.carPositionNormalized = v12->physicsState.normalizedSplinePosition;
  this->rti.carSlope = 0.0;
  this->rti.wheelAngularSpeed[0] = v12->physicsState.wheelAngularSpeed[0];
  this->rti.slipAngle[0] = this->car->physicsState.slipAngle[0];
  this->rti.slipAngle_ContactPatch[0] = 0.0;
  this->rti.slipRatio[0] = this->car->physicsState.slipRatio[0];
  this->rti.tyreSlip[0] = this->car->physicsState.tyreSlip[0];
  this->rti.ndSlip[0] = this->car->physicsState.ndSlip[0];
  this->rti.load[0] = this->car->physicsState.load[0];
  this->rti.Dy[0] = this->car->physicsState.Dy[0];
  this->rti.Mz[0] = this->car->physicsState.Mz[0];
  this->rti.tyreDirtyLevel[0] = this->car->physicsState.tyreDirtyLevel[0];
  this->rti.camberRAD[0] = this->car->physicsState.camberRAD[0];
  this->rti.tyreRadius[0] = this->car->physicsState.tyreRadius[0];
  this->rti.tyreLoadedRadius[0] = this->car->physicsState.tyreLoadedRadius[0];
  this->rti.suspensionHeight[0] = this->car->physicsState.suspensionTravel[0];
  this->rti.wheelAngularSpeed[1] = this->car->physicsState.wheelAngularSpeed[1];
  this->rti.slipAngle[1] = this->car->physicsState.slipAngle[1];
  this->rti.slipAngle_ContactPatch[1] = 0.0;
  this->rti.slipRatio[1] = this->car->physicsState.slipRatio[1];
  this->rti.tyreSlip[1] = this->car->physicsState.tyreSlip[1];
  this->rti.ndSlip[1] = this->car->physicsState.ndSlip[1];
  this->rti.load[1] = this->car->physicsState.load[1];
  this->rti.Dy[1] = this->car->physicsState.Dy[1];
  this->rti.Mz[1] = this->car->physicsState.Mz[1];
  this->rti.tyreDirtyLevel[1] = this->car->physicsState.tyreDirtyLevel[1];
  this->rti.camberRAD[1] = this->car->physicsState.camberRAD[1];
  this->rti.tyreRadius[1] = this->car->physicsState.tyreRadius[1];
  this->rti.tyreLoadedRadius[1] = this->car->physicsState.tyreLoadedRadius[1];
  this->rti.suspensionHeight[1] = this->car->physicsState.suspensionTravel[1];
  this->rti.wheelAngularSpeed[2] = this->car->physicsState.wheelAngularSpeed[2];
  this->rti.slipAngle[2] = this->car->physicsState.slipAngle[2];
  this->rti.slipAngle_ContactPatch[2] = 0.0;
  this->rti.slipRatio[2] = this->car->physicsState.slipRatio[2];
  this->rti.tyreSlip[2] = this->car->physicsState.tyreSlip[2];
  this->rti.ndSlip[2] = this->car->physicsState.ndSlip[2];
  this->rti.load[2] = this->car->physicsState.load[2];
  this->rti.Dy[2] = this->car->physicsState.Dy[2];
  this->rti.Mz[2] = this->car->physicsState.Mz[2];
  this->rti.tyreDirtyLevel[2] = this->car->physicsState.tyreDirtyLevel[2];
  this->rti.camberRAD[2] = this->car->physicsState.camberRAD[2];
  this->rti.tyreRadius[2] = this->car->physicsState.tyreRadius[2];
  this->rti.tyreLoadedRadius[2] = this->car->physicsState.tyreLoadedRadius[2];
  this->rti.suspensionHeight[2] = this->car->physicsState.suspensionTravel[2];
  this->rti.wheelAngularSpeed[3] = this->car->physicsState.wheelAngularSpeed[3];
  this->rti.slipAngle[3] = this->car->physicsState.slipAngle[3];
  this->rti.slipAngle_ContactPatch[3] = 0.0;
  this->rti.slipRatio[3] = this->car->physicsState.slipRatio[3];
  this->rti.tyreSlip[3] = this->car->physicsState.tyreSlip[3];
  this->rti.ndSlip[3] = this->car->physicsState.ndSlip[3];
  this->rti.load[3] = this->car->physicsState.load[3];
  this->rti.Dy[3] = this->car->physicsState.Dy[3];
  this->rti.Mz[3] = this->car->physicsState.Mz[3];
  this->rti.tyreDirtyLevel[3] = this->car->physicsState.tyreDirtyLevel[3];
  this->rti.camberRAD[3] = this->car->physicsState.camberRAD[3];
  this->rti.tyreRadius[3] = this->car->physicsState.tyreRadius[3];
  this->rti.tyreLoadedRadius[3] = this->car->physicsState.tyreLoadedRadius[3];
  this->rti.suspensionHeight[3] = this->car->physicsState.suspensionTravel[3];
  v13 = this->car;
  v14 = _mm_unpacklo_ps(
          (__m128)LODWORD(v13->physicsState.worldMatrix.M41),
          (__m128)LODWORD(v13->physicsState.worldMatrix.M42)).m128_u64[0];
  wp.z = v13->physicsState.worldMatrix.M43;
  v15 = wp.z;
  *(_QWORD *)this->rti.carCoordinates = v14;
  this->rti.carCoordinates[2] = v15;
}
