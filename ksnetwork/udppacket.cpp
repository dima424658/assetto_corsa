#include "udppacket.h
void UDPPacket::UDPPacket(UDPPacket *this)
{
  this->targetIP = 0i64;
  this->data = 0;
  this->currentDataPos = 0;
  this->size = 0;
  this->data = (unsigned __int8 *)operator new[](0x800u);
}
void UDPPacket::UDPPacket(UDPPacket *this, const std::vector<unsigned char> *idata)
{
  unsigned __int8 *v3; // eax

  this->targetIP = 0i64;
  this->data = 0;
  v3 = (unsigned __int8 *)operator new[](idata->_Mylast - idata->_Myfirst);
  this->data = v3;
  memcpy(v3, idata->_Myfirst, idata->_Mylast - idata->_Myfirst);
  this->currentDataPos = 0;
  this->size = idata->_Mylast - idata->_Myfirst;
}
void UDPPacket::~UDPPacket(UDPPacket *this)
{
  if ( this->data )
    operator delete[](this->data);
}
void UDPPacket::UDPPacket(UDPPacket *this, const UDPMessage *msg)
{
  unsigned __int8 *v3; // eax
  IPAddress v4; // xmm0

  this->targetIP = 0i64;
  this->data = 0;
  v3 = (unsigned __int8 *)operator new[](msg->size);
  this->data = v3;
  memcpy(v3, msg->data, msg->size);
  v4 = (IPAddress)_mm_loadu_si128((const __m128i *)&msg->srcAddress);
  this->currentDataPos = 0;
  this->targetIP = v4;
  this->size = msg->size;
}
void UDPPacket::UDPPacket(UDPPacket *this, const UDPPacket *r)
{
  unsigned __int8 *v3; // eax

  this->targetIP = 0i64;
  this->data = 0;
  v3 = (unsigned __int8 *)operator new[](r->size);
  this->data = v3;
  memcpy(v3, r->data, r->size);
  this->targetIP = (IPAddress)_mm_loadu_si128((const __m128i *)r);
  this->currentDataPos = r->currentDataPos;
  this->size = r->size;
}
UDPPacket *UDPPacket::operator=(UDPPacket *this, const UDPPacket *r)
{
  unsigned __int8 *v3; // eax

  v3 = (unsigned __int8 *)operator new[](r->size);
  this->data = v3;
  memcpy(v3, r->data, r->size);
  this->targetIP = (IPAddress)_mm_loadu_si128((const __m128i *)r);
  this->currentDataPos = r->currentDataPos;
  this->size = r->size;
  return this;
}
unsigned int UDPPacket::getSize(UDPPacket *this)
{
  return this->size;
}
void UDPPacket::send(UDPPacket *this, UDPSocket *sok)
{
  int v2; // [esp-10h] [ebp-24h]
  struct sockaddr to; // [esp+0h] [ebp-14h] BYREF

  v2 = this->size;
  to = (struct sockaddr)_mm_loadu_si128((const __m128i *)this);
  sendto(sok->soc, (const char *)this->data, v2, 0, &to, 16);
}
void UDPPacket::send(UDPPacket *this, TCPSocket *sok)
{
  std::wstring *v3; // eax
  unsigned int v4; // esi
  std::wstring v5; // [esp+14h] [ebp-830h] BYREF
  unsigned __int8 buffer[2048]; // [esp+2Ch] [ebp-818h] BYREF
  int v7; // [esp+840h] [ebp-4h]

  if ( this->size > 0x7FE )
  {
    v5._Myres = 7;
    v5._Mysize = 0;
    v5._Bx._Buf[0] = 0;
    std::wstring::assign(&v5, L"ERROR: Trying to send a TCP packet bigger than 2046", 0x33u);
    v7 = 0;
    v3 = &v5;
    if ( v5._Myres >= 8 )
      v3 = (std::wstring *)v5._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v3->_Bx._Buf);
    ksGenerateCrash();
    if ( v5._Myres >= 8 )
      operator delete(v5._Bx._Ptr);
  }
  v4 = this->size;
  memcpy(&buffer[2], this->data, v4);
  *(_WORD *)buffer = v4;
  send(sok->soc, (const char *)buffer, v4 + 2, 0);
}
void UDPPacket::writeStringANSI(UDPPacket *this, const std::wstring *st)
{
  const std::string *v3; // eax
  std::string result; // [esp+8h] [ebp-2Ch] BYREF
  int v5; // [esp+30h] [ebp-4h]

  v3 = wstring2string(&result, st);
  v5 = 0;
  UDPPacket::writeString(this, v3);
  if ( result._Myres >= 0x10 )
    operator delete(result._Bx._Ptr);
}
void UDPPacket::writeString(UDPPacket *this, const std::wstring *st)
{
  unsigned int v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // edi
  const std::wstring *v6; // ecx
  size_t v7; // esi
  __int64 v8; // [esp-4h] [ebp-410h]
  int data[256]; // [esp+8h] [ebp-404h] BYREF

  v3 = st->_Mysize;
  if ( v3 >= 0xFF )
  {
    LODWORD(v8) = st->_Mysize;
    _printf("ERROR: UDPPacket::writeString called with wstring length over 255 (%llu)\n", v8);
  }
  else
  {
    v4 = 0;
    if ( v3 )
    {
      v5 = st->_Myres;
      do
      {
        if ( v5 < 8 )
          v6 = st;
        else
          v6 = (const std::wstring *)st->_Bx._Ptr;
        data[v4] = v6->_Bx._Buf[v4];
        ++v4;
      }
      while ( v4 < v3 );
    }
    this->data[this->size++] = st->_Mysize;
    v7 = 4 * st->_Mysize;
    memcpy(&this->data[this->size], data, v7);
    this->size += v7;
  }
}
void UDPPacket::writeString(UDPPacket *this, const std::string *st)
{
  const std::string *v2; // esi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  __int64 v6; // [esp-4h] [ebp-2Ch]
  std::string pExceptionObject; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = st;
  v4 = st->_Mysize;
  if ( v4 >= 0xFF )
  {
    LODWORD(v6) = st->_Mysize;
    _printf("ERROR: UDPPacket::writeString called with string length over 255 (%llu)\n", v6);
    pExceptionObject._Myres = 15;
    pExceptionObject._Mysize = 0;
    pExceptionObject._Bx._Buf[0] = 0;
    std::string::assign(&pExceptionObject, "UDPPacket::writeString called with string length over 255", 0x39u);
    _CxxThrowException(
      &pExceptionObject,
      (_ThrowInfo *)&_TI4_AV__basic_string_DU__char_traits_D_std__V__allocator_D_2__std__);
  }
  this->data[this->size++] = v4;
  v5 = st->_Mysize;
  if ( st->_Myres >= 0x10 )
    v2 = (const std::string *)st->_Bx._Ptr;
  memcpy(&this->data[this->size], v2, v5);
  this->size += v5;
}
std::wstring *UDPPacket::readStringW(UDPPacket *this, std::wstring *result)
{
  unsigned int v3; // edi
  unsigned int v4; // ecx
  bool v5; // cf
  signed int v6; // eax
  unsigned __int8 *i; // ebx
  std::wstring *v8; // edx
  std::wstring *v9; // eax

  v3 = UDPPacket::read<unsigned char>(this);
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  v4 = result->_Mysize;
  if ( v3 > v4 )
  {
    std::wstring::append(result, v3 - v4, 0);
  }
  else
  {
    v5 = result->_Myres < 8;
    result->_Mysize = v3;
    if ( v5 )
      result->_Bx._Buf[v3] = 0;
    else
      result->_Bx._Ptr[v3] = 0;
  }
  v6 = 0;
  for ( i = &this->data[this->currentDataPos]; v6 < (int)v3; ++v6 )
  {
    if ( result->_Myres < 8 )
      v8 = result;
    else
      v8 = (std::wstring *)result->_Bx._Ptr;
    v8->_Bx._Buf[v6] = *(_WORD *)&i[4 * v6];
  }
  v9 = result;
  this->currentDataPos += 4 * v3;
  return v9;
}
std::wstring *UDPPacket::readBigStringW(UDPPacket *this, std::wstring *result)
{
  unsigned int v3; // edi
  unsigned int v4; // ecx
  bool v5; // cf
  signed int v6; // eax
  unsigned __int8 *i; // ebx
  std::wstring *v8; // edx
  std::wstring *v9; // eax

  v3 = (unsigned __int16)UDPPacket::read<unsigned short>(this);
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  v4 = result->_Mysize;
  if ( v3 > v4 )
  {
    std::wstring::append(result, v3 - v4, 0);
  }
  else
  {
    v5 = result->_Myres < 8;
    result->_Mysize = v3;
    if ( v5 )
      result->_Bx._Buf[v3] = 0;
    else
      result->_Bx._Ptr[v3] = 0;
  }
  v6 = 0;
  for ( i = &this->data[this->currentDataPos]; v6 < (int)v3; ++v6 )
  {
    if ( result->_Myres < 8 )
      v8 = result;
    else
      v8 = (std::wstring *)result->_Bx._Ptr;
    v8->_Bx._Buf[v6] = *(_WORD *)&i[4 * v6];
  }
  v9 = result;
  this->currentDataPos += 4 * v3;
  return v9;
}
std::string *UDPPacket::readString(UDPPacket *this, std::string *result)
{
  unsigned __int8 v3; // al
  size_t v4; // edi
  unsigned int v5; // ecx
  bool v6; // cf
  std::string *v7; // eax
  std::string *v8; // eax

  v3 = UDPPacket::read<unsigned char>(this);
  v4 = v3;
  result->_Myres = 15;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  v5 = result->_Mysize;
  if ( v3 > v5 )
  {
    std::string::append(result, v3 - v5, 0);
  }
  else
  {
    v6 = result->_Myres < 0x10;
    result->_Mysize = v3;
    if ( v6 )
      result->_Bx._Buf[v3] = 0;
    else
      result->_Bx._Ptr[v3] = 0;
  }
  if ( result->_Myres < 0x10 )
    v7 = result;
  else
    v7 = (std::string *)result->_Bx._Ptr;
  memcpy(v7, &this->data[this->currentDataPos], v4);
  v8 = result;
  this->currentDataPos += v4;
  return v8;
}
bool UDPPacket::isEOF(UDPPacket *this)
{
  unsigned int v1; // eax

  v1 = this->size;
  return this->currentDataPos >= v1 && v1;
}
unsigned __int8 UDPPacket::read<unsigned char>(UDPPacket *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  std::wstring *v4; // eax
  unsigned int v5; // ecx
  unsigned __int8 result; // al
  std::wstring v7; // [esp+10h] [ebp-2Ch] BYREF
  int v8; // [esp+38h] [ebp-4h]

  v2 = this->currentDataPos;
  v3 = this->size;
  if ( v2 >= v3 )
  {
    _printf("ERROR: UDPPacket data read out of range: %d size %d\n", v2, v3);
    if ( this->size )
      _printf("OFFENDING PACKET HAD ID: %d\n", *this->data);
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, L"UDPPAcket out of bounds", 0x17u);
    v8 = 0;
    v4 = &v7;
    if ( v7._Myres >= 8 )
      v4 = (std::wstring *)v7._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v4->_Bx._Buf);
    ksGenerateCrash();
    if ( v7._Myres >= 8 )
      operator delete(v7._Bx._Ptr);
  }
  v5 = this->currentDataPos;
  result = this->data[v5];
  this->currentDataPos = v5 + 1;
  return result;
}
int UDPPacket::read<unsigned short>(UDPPacket *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  std::wstring *v4; // eax
  unsigned int v5; // ecx
  int result; // eax
  std::wstring v7; // [esp+10h] [ebp-2Ch] BYREF
  int v8; // [esp+38h] [ebp-4h]

  v2 = this->currentDataPos;
  v3 = this->size;
  if ( v2 >= v3 )
  {
    _printf("ERROR: UDPPacket data read out of range: %d size %d\n", v2, v3);
    if ( this->size )
      _printf("OFFENDING PACKET HAD ID: %d\n", *this->data);
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, L"UDPPAcket out of bounds", 0x17u);
    v8 = 0;
    v4 = &v7;
    if ( v7._Myres >= 8 )
      v4 = (std::wstring *)v7._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v4->_Bx._Buf);
    ksGenerateCrash();
    if ( v7._Myres >= 8 )
      operator delete(v7._Bx._Ptr);
  }
  v5 = this->currentDataPos;
  result = *(unsigned __int16 *)&this->data[v5];
  this->currentDataPos = v5 + 2;
  return result;
}
int UDPPacket::read<short>(UDPPacket *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  std::wstring *v4; // eax
  unsigned int v5; // ecx
  int result; // eax
  std::wstring v7; // [esp+Ch] [ebp-28h] BYREF
  int v8; // [esp+30h] [ebp-4h]

  v2 = this->currentDataPos;
  v3 = this->size;
  if ( v2 >= v3 )
  {
    _printf("ERROR: UDPPacket data read out of range: %d size %d\n", v2, v3);
    if ( this->size )
      _printf("OFFENDING PACKET HAD ID: %d\n", *this->data);
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, L"UDPPAcket out of bounds", 0x17u);
    v4 = &v7;
    v8 = 0;
    if ( v7._Myres >= 8 )
      v4 = (std::wstring *)v7._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v4->_Bx._Buf);
    ksGenerateCrash();
    if ( v7._Myres >= 8 )
      operator delete(v7._Bx._Ptr);
  }
  v5 = this->currentDataPos;
  result = *(unsigned __int16 *)&this->data[v5];
  this->currentDataPos = v5 + 2;
  return result;
}
unsigned int UDPPacket::read<unsigned int>(UDPPacket *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  std::wstring *v4; // eax
  unsigned int v5; // ecx
  unsigned int result; // eax
  std::wstring v7; // [esp+Ch] [ebp-28h] BYREF
  int v8; // [esp+30h] [ebp-4h]

  v2 = this->currentDataPos;
  v3 = this->size;
  if ( v2 >= v3 )
  {
    _printf("ERROR: UDPPacket data read out of range: %d size %d\n", v2, v3);
    if ( this->size )
      _printf("OFFENDING PACKET HAD ID: %d\n", *this->data);
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, L"UDPPAcket out of bounds", 0x17u);
    v4 = &v7;
    v8 = 0;
    if ( v7._Myres >= 8 )
      v4 = (std::wstring *)v7._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v4->_Bx._Buf);
    ksGenerateCrash();
    if ( v7._Myres >= 8 )
      operator delete(v7._Bx._Ptr);
  }
  v5 = this->currentDataPos;
  result = *(_DWORD *)&this->data[v5];
  this->currentDataPos = v5 + 4;
  return result;
}
double UDPPacket::read<float>(UDPPacket *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  std::wstring *v4; // eax
  unsigned int v5; // ecx
  double result; // st7
  std::wstring v7; // [esp+10h] [ebp-28h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  v2 = this->currentDataPos;
  v3 = this->size;
  if ( v2 >= v3 )
  {
    _printf("ERROR: UDPPacket data read out of range: %d size %d\n", v2, v3);
    if ( this->size )
      _printf("OFFENDING PACKET HAD ID: %d\n", *this->data);
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, L"UDPPAcket out of bounds", 0x17u);
    v4 = &v7;
    v8 = 0;
    if ( v7._Myres >= 8 )
      v4 = (std::wstring *)v7._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v4->_Bx._Buf);
    ksGenerateCrash();
    if ( v7._Myres >= 8 )
      operator delete(v7._Bx._Ptr);
  }
  v5 = this->currentDataPos;
  result = *(float *)&this->data[v5];
  this->currentDataPos = v5 + 4;
  return result;
}
vec3f *UDPPacket::read<vec3f>(UDPPacket *this, vec3f *result)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  std::wstring *v5; // eax
  vec3f *v6; // eax
  vec3f *v7; // eoff
  std::wstring v8; // [esp+10h] [ebp-28h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v3 = this->currentDataPos;
  v4 = this->size;
  if ( v3 >= v4 )
  {
    _printf("ERROR: UDPPacket data read out of range: %d size %d\n", v3, v4);
    if ( this->size )
      _printf("OFFENDING PACKET HAD ID: %d\n", *this->data);
    v8._Myres = 7;
    v8._Mysize = 0;
    v8._Bx._Buf[0] = 0;
    std::wstring::assign(&v8, L"UDPPAcket out of bounds", 0x17u);
    v5 = &v8;
    v9 = 0;
    if ( v8._Myres >= 8 )
      v5 = (std::wstring *)v8._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v5->_Bx._Buf);
    ksGenerateCrash();
    if ( v8._Myres >= 8 )
      operator delete(v8._Bx._Ptr);
  }
  v6 = result;
  v7 = (vec3f *)&this->data[this->currentDataPos];
  *result = *v7;
  this->currentDataPos += 12;
  return v6;
}
__int64 UDPPacket::read<__int64>(UDPPacket *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  std::wstring *v4; // eax
  unsigned int v5; // esi
  __int64 result; // rax
  std::wstring v7; // [esp+Ch] [ebp-28h] BYREF
  int v8; // [esp+30h] [ebp-4h]

  v2 = this->currentDataPos;
  v3 = this->size;
  if ( v2 >= v3 )
  {
    _printf("ERROR: UDPPacket data read out of range: %d size %d\n", v2, v3);
    if ( this->size )
      _printf("OFFENDING PACKET HAD ID: %d\n", *this->data);
    v7._Myres = 7;
    v7._Mysize = 0;
    v7._Bx._Buf[0] = 0;
    std::wstring::assign(&v7, L"UDPPAcket out of bounds", 0x17u);
    v4 = &v7;
    v8 = 0;
    if ( v7._Myres >= 8 )
      v4 = (std::wstring *)v7._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v4->_Bx._Buf);
    ksGenerateCrash();
    if ( v7._Myres >= 8 )
      operator delete(v7._Bx._Ptr);
  }
  v5 = this->currentDataPos;
  result = *(_QWORD *)&this->data[v5];
  this->currentDataPos = v5 + 8;
  return result;
}
