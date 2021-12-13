#include "ipaddress.h"
void IPAddress::IPAddress(IPAddress *this)
{
  *this = 0i64;
}
void IPAddress::IPAddress(IPAddress *this, const std::wstring *addr, unsigned __int16 port)
{
  bool v4; // cf
  std::string *v5; // eax
  unsigned __int16 v6; // ax
  std::string naddr; // [esp+4h] [ebp-1Ch] BYREF

  wstring2string(&naddr, addr);
  v4 = naddr._Myres < 0x10;
  *this = 0i64;
  this->sokaddr.sin_family = 2;
  v5 = &naddr;
  if ( !v4 )
    v5 = (std::string *)naddr._Bx._Ptr;
  this->sokaddr.sin_addr.S_un.S_addr = inet_addr(v5->_Bx._Buf);
  v6 = htons(port);
  v4 = naddr._Myres < 0x10;
  this->sokaddr.sin_port = v6;
  if ( !v4 )
    operator delete(naddr._Bx._Ptr);
}
