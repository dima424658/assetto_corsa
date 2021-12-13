#include "udpsocket.h"
void UDPSocket::UDPSocket(UDPSocket *this)
{
  this->listeners._Myfirst = 0;
  this->listeners._Mylast = 0;
  this->listeners._Myend = 0;
  this->ping = 0;
  this->lastPingTime = 0.0;
  this->soc = socket(2, 2, 17);
  this->isBlocking = 1;
}
void UDPSocket::~UDPSocket(UDPSocket *this)
{
  std::function<void __cdecl(UDPMessage const &)> *v2; // ecx
  unsigned int v3; // [esp-8h] [ebp-10h]

  v3 = this->soc;
  this->shutdownFlag = 1;
  shutdown(v3, 2);
  closesocket(this->soc);
  v2 = this->listeners._Myfirst;
  if ( v2 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::function<void __cdecl (UDPMessage const &)>>>>(
      v2,
      this->listeners._Mylast);
    operator delete(this->listeners._Myfirst);
    this->listeners._Myfirst = 0;
    this->listeners._Mylast = 0;
    this->listeners._Myend = 0;
  }
}
void UDPSocket::setBlockingMode(UDPSocket *this, BOOL imode)
{
  imode = !imode;
  ioctlsocket(this->soc, -2147195266, (u_long *)&imode);
}
void UDPSocket::addListener(UDPSocket *this, std::function<void __cdecl(UDPMessage const &)> listener)
{
  std::vector<std::function<void __cdecl (UDPMessage const &)>>::push_back(&this->listeners, &listener);
  if ( listener._Impl )
    ((void (__stdcall *)(bool))listener._Impl->_Delete_this)(listener._Impl != (std::_Func_base<void,UDPMessage const &> *)&listener);
}
