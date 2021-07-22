#include "udpcommandlistener.h"
void UDPCommandListener::UDPCommandListener(UDPCommandListener *this, Sim *a_sim)
{
  unsigned int v3; // eax
  std::wstring v4; // [esp-1Ch] [ebp-3Ch] BYREF
  Game *v5; // [esp-4h] [ebp-24h]
  sockaddr_in local; // [esp+Ch] [ebp-14h] BYREF

  v5 = a_sim->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"UDPCOMMAND_LISTENER", 0x13u);
  GameObject::GameObject(this, v4, v5);
  v5 = 0;
  v4._Myres = 2;
  v4._Mysize = 2;
  this->__vftable = (UDPCommandListener_vtbl *)&UDPCommandListener::`vftable';
  this->sim = a_sim;
  v3 = socket(v4._Mysize, v4._Myres, (int)v5);
  v5 = 0;
  this->sok = v3;
  local.sin_addr.S_un.S_addr = htonl((u_long)v5);
  local.sin_family = 2;
  local.sin_port = htons(0x25C2u);
  if ( bind(this->sok, (const struct sockaddr *)&local, 16) == -1 )
    _printf("ERROR: BINDING LISTENER SOCKET UdpCommandListener\n");
}
UDPCommandListener *UDPCommandListener::`scalar deleting destructor'(UDPCommandListener *this, unsigned int a2)
{
  unsigned int v4; // [esp-4h] [ebp-8h]

  v4 = this->sok;
  this->__vftable = (UDPCommandListener_vtbl *)&UDPCommandListener::`vftable';
  closesocket(v4);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void UDPCommandListener::update(UDPCommandListener *this, float dt)
{
  int v3; // edi
  bool v4; // sf
  CarAvatar *v5; // eax
  RaceManager *v6; // eax
  RaceManager *v7; // eax
  Sim *v8; // ecx
  ACCameraManager *v9; // ecx
  ACCameraManager *v10; // ecx
  Sim *v11; // ecx
  CarAvatar *v12; // eax
  Sim *v13; // ecx
  CarAvatar *v14; // eax
  Sim *v15; // ecx
  CarAvatar *v16; // eax
  int v17; // eax
  std::function<void __cdecl(bool const &)> v18; // [esp-1Ch] [ebp-1080h] BYREF
  void *v19; // [esp-4h] [ebp-1068h]
  UDPCommandListener::update::__l23::<lambda_912136b37263743446bae8b488d9d8ec> _Func[2]; // [esp+24h] [ebp-1040h] BYREF
  u_long argp; // [esp+38h] [ebp-102Ch] BYREF
  int fromlen; // [esp+3Ch] [ebp-1028h] BYREF
  std::wstring v23; // [esp+40h] [ebp-1024h] BYREF
  std::wstring setName; // [esp+58h] [ebp-100Ch] BYREF
  std::wstring v25; // [esp+70h] [ebp-FF4h] BYREF
  struct sockaddr from; // [esp+88h] [ebp-FDCh] BYREF
  char buf; // [esp+98h] [ebp-FCCh] BYREF
  unsigned __int8 v28; // [esp+99h] [ebp-FCBh]
  int v29; // [esp+1060h] [ebp-4h]

  argp = 1;
  v19 = &argp;
  (&v18._Impl)[1] = (std::_Func_base<void,bool const &> *)1074030207;
  v18._Impl = (std::_Func_base<void,bool const &> *)this->sok;
  fromlen = 16;
  ioctlsocket((SOCKET)v18._Impl, 1074030207, &argp);
  if ( argp )
  {
    v3 = recvfrom(this->sok, &buf, 4028, 0, &from, &fromlen);
    v4 = v3 < 0;
    if ( v3 > 0 )
    {
      switch ( buf )
      {
        case 'B':
          this->sim->game->shutdown(this->sim->game);
          goto LABEL_24;
        case 'C':
          v19 = this;
          v18._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_df73c82f9df2c2244d38459c7bb82623_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
          goto LABEL_9;
        case 'D':
          v7 = GameObject::getGameObject<RaceManager>(this->sim);
          RaceManager::restartCurrentSession(v7);
          goto LABEL_24;
        case 'E':
          Sim::startGame(this->sim);
          goto LABEL_24;
        case 'F':
          v19 = this;
          v18._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_5cf5a81ef9aba7a6a405b421046456ba_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
          goto LABEL_9;
        case 'G':
          v19 = this;
          v18._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_5c1f10e5b22fca5993dfaa11ae8b0ddf_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
          goto LABEL_9;
        case 'H':
          v19 = this;
          v18._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_3af8efd96a78e1fc4a470c549272da59_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
          goto LABEL_9;
        case 'I':
          v10 = this->sim->cameraManager;
          if ( v10->mode == eCar )
          {
            CameraCarManager::nextCamera(v10->cameraCar);
          }
          else
          {
            v19 = this;
            v18._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_0c645c8f62b2e0a797f57343fdc0cac4_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
LABEL_9:
            v18._Space._Pfn[1] = (void (__cdecl *)())this;
            v18._Impl = (std::_Func_base<void,bool const &> *)&v18;
            v29 = -1;
LABEL_10:
            ACCameraManager::registerToFadeInEvent(this->sim->cameraManager, v18, v19);
            v8 = this->sim;
            _Func[0].__this = 0;
            _Func[1].value = (int)this;
            _Func[1].__this = 0;
            v9 = v8->cameraManager;
            _Func[0].value = 0;
            ACCameraManager::fadeIn(v9, (FadeModeDef)_mm_loadu_si128((const __m128i *)_Func));
          }
LABEL_24:
          v4 = v3 < 0;
          break;
        case 'J':
          v19 = this;
          v18._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_72ee87b325e3dcd28ed3f121a3b115a3_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
          goto LABEL_9;
        case 'K':
          std::wstring::wstring(&setName, L"PIT");
          v11 = this->sim;
          v29 = 6;
          v12 = Sim::getCar(v11, 0);
          CarAvatar::goToSpawnPosition(v12, &setName);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
          goto LABEL_24;
        case 'L':
          std::wstring::wstring(&v23, L"PIT");
          v15 = this->sim;
          v29 = 8;
          v16 = Sim::getCar(v15, 0);
          CarAvatar::goToSpawnPosition(v16, &v23);
          v29 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v23);
          Sim::activateEscMenu(this->sim);
          ESCMenu::setRaceControlScreen(this->sim->escMenu);
          goto LABEL_24;
        case 'M':
          v19 = this;
          _Func[0].value = v28;
          _Func[0].__this = this;
          std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(&v18, _Func);
          goto LABEL_10;
        case 'N':
          v19 = this;
          _Func[0].value = v28;
          _Func[0].__this = this;
          std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
            &v18,
            (UDPCommandListener::update::__l28::<lambda_381add0e37bf178173b8ad19696695e2> *)_Func);
          goto LABEL_10;
        case 'O':
          std::wstring::wstring(&v25, L"PIT");
          v13 = this->sim;
          v29 = 7;
          v14 = Sim::getCar(v13, v28);
          CarAvatar::goToSpawnPosition(v14, &v25);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v25);
          goto LABEL_24;
        case 'P':
          v5 = Sim::getCar(this->sim, 0);
          CarAvatar::setGentleStop(v5, 1);
          goto LABEL_24;
        case 'Q':
          v6 = GameObject::getGameObject<RaceManager>(this->sim);
          RaceManager::skipCurrentSession(v6);
          goto LABEL_24;
        default:
          goto LABEL_24;
      }
    }
    if ( v4 )
    {
      v17 = WSAGetLastError();
      _printf("Socket error UDP Command listener %d\n", v17);
    }
  }
}
