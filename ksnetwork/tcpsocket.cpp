#include "tcpsocket.h
void TCPSocket::TCPSocket(TCPSocket *this)
{
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&this->chNewConnections.queue, 4u);
  this->chNewConnections.queue.__vftable = (Concurrency::concurrent_queue<unsigned int,std::allocator<unsigned int> >_vtbl *)&Concurrency::concurrent_queue<unsigned int,std::allocator<unsigned int>>::`vftable';
  this->listeners._Myfirst = 0;
  this->listeners._Mylast = 0;
  this->listeners._Myend = 0;
  this->listenerThread._Thr._Id = 0;
  this->isExiting = 0;
  *(_WORD *)&this->isBlocking = 1;
  this->buffer.cursor = 0;
  this->recvBuffer = (unsigned __int8 *)operator new[](0x10000u);
}
void TCPSocket::~TCPSocket(TCPSocket *this)
{
  std::function<void __cdecl(UDPMessage const &)> *v2; // ecx

  if ( this->isServer )
  {
    shutdown(this->listenSock, 2);
    closesocket(this->soc);
    this->isExiting = 1;
    std::thread::join(&this->listenerThread);
  }
  if ( this->recvBuffer )
    operator delete[](this->recvBuffer);
  shutdown(this->soc, 2);
  closesocket(this->soc);
  if ( this->listenerThread._Thr._Id )
    terminate();
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
  Concurrency::concurrent_queue<unsigned int,std::allocator<unsigned int>>::~concurrent_queue<unsigned int,std::allocator<unsigned int>>(&this->chNewConnections.queue);
}
BOOL TCPSocket::connect(TCPSocket *this, const IPAddress *target)
{
  unsigned int v3; // eax
  int v4; // esi
  int nagleoff; // [esp+4h] [ebp-4h] BYREF

  v3 = socket(2, 1, 0);
  this->soc = v3;
  nagleoff = 1;
  if ( setsockopt(v3, 0xFFFF, 1, (const char *)&nagleoff, 4) == -1 )
    _printf("ERROR: Could not set TCP_NODELAY\n");
  v4 = connect(this->soc, (const struct sockaddr *)target, 16);
  _printf("TCP connect returns: %d\n", v4);
  return v4 == 0;
}
void TCPSocket::setBlockingMode(TCPSocket *this, BOOL imode)
{
  imode = !imode;
  ioctlsocket(this->soc, -2147195266, (u_long *)&imode);
}
void TCPSocket::addListener(TCPSocket *this, std::function<void __cdecl(UDPMessage const &)> listener)
{
  std::vector<std::function<void __cdecl (UDPMessage const &)>>::push_back(&this->listeners, &listener);
  if ( listener._Impl )
    ((void (__stdcall *)(bool))listener._Impl->_Delete_this)(listener._Impl != (std::_Func_base<void,UDPMessage const &> *)&listener);
}
std::vector<unsigned char> *TCPSocket::receivePacket(TCPSocket *this, std::vector<unsigned char> *result)
{
  int v3; // edi
  TCPQueue *v4; // esi
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v8; // ecx
  std::vector<unsigned char> pakdata; // [esp+10h] [ebp-820h] BYREF
  TCPQueue *v10; // [esp+1Ch] [ebp-814h]
  TCPSocket *v11; // [esp+20h] [ebp-810h]
  int v12; // [esp+24h] [ebp-80Ch]
  unsigned __int8 message[2048]; // [esp+28h] [ebp-808h] BYREF

  v12 = 0;
  v11 = this;
  v3 = recv(this->soc, (char *)message, 2048, 0);
  if ( v3 <= 0 )
  {
LABEL_7:
    result->_Myfirst = 0;
    result->_Mylast = 0;
    result->_Myend = 0;
  }
  else
  {
    v4 = &this->buffer;
    v10 = v4;
    while ( 1 )
    {
      TCPQueue::push(v4, message, v3);
      TCPQueue::getPacket(v4, &pakdata);
      v5 = pakdata._Myfirst;
      v6 = pakdata._Mylast;
      if ( pakdata._Myfirst != pakdata._Mylast )
        break;
      v3 = recv(v11->soc, (char *)message, 2048, 0);
      if ( v5 )
      {
        operator delete(v5);
        pakdata._Myfirst = 0;
        pakdata._Mylast = 0;
        pakdata._Myend = 0;
      }
      v4 = v10;
      if ( v3 <= 0 )
        goto LABEL_7;
    }
    v8 = pakdata._Myend;
    result->_Myfirst = pakdata._Myfirst;
    result->_Mylast = v6;
    result->_Myend = v8;
  }
  return result;
}
int TCPSocket::receive(TCPSocket *this, int maxPackets)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  unsigned __int8 *v6; // eax
  std::function<void __cdecl(UDPMessage const &)> *v7; // esi
  std::function<void __cdecl(UDPMessage const &)> *v8; // edi
  std::_Func_base<void,UDPMessage const &> *v9; // ecx
  int v11; // [esp+10h] [ebp-3Ch]
  std::vector<unsigned char> pakdata; // [esp+14h] [ebp-38h] BYREF
  UDPMessage msg; // [esp+20h] [ebp-2Ch] BYREF
  int v14; // [esp+48h] [ebp-4h]

  v3 = 0;
  v11 = 0;
  v4 = 1;
  while ( v3 < maxPackets )
  {
    if ( v4 <= 0 )
      break;
    v5 = recv(this->soc, (char *)this->recvBuffer, 2048, 0);
    v4 = v5;
    if ( v5 > 0 )
      TCPQueue::push(&this->buffer, this->recvBuffer, v5);
    TCPQueue::getPacket(&this->buffer, &pakdata);
    v14 = 0;
    v6 = pakdata._Myfirst;
    if ( pakdata._Myfirst != pakdata._Mylast )
    {
      v7 = this->listeners._Myfirst;
      v8 = this->listeners._Mylast;
      msg.data = pakdata._Myfirst;
      msg.size = pakdata._Mylast - pakdata._Myfirst;
      if ( v7 != v8 )
      {
        do
        {
          v9 = v7->_Impl;
          if ( !v9 )
          {
            std::_Xbad_function_call();
            JUMPOUT(0x4542DB);
          }
          v9->_Do_call(v9, &msg);
          ++v7;
        }
        while ( v7 != v8 );
        v6 = pakdata._Myfirst;
      }
      v3 = v11;
      v4 = 1;
    }
    ++v3;
    v14 = -1;
    v11 = v3;
    if ( v6 )
    {
      operator delete(v6);
      pakdata._Myfirst = 0;
      pakdata._Mylast = 0;
      pakdata._Myend = 0;
    }
  }
  return v3;
}
