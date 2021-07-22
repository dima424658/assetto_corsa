#include "nkutils.h"
void NKUtils::NKUtils(NKUtils *this)
{
  this->__vftable = (NKUtils_vtbl *)&NKUtils::`vftable';
}
void NKUtils::~NKUtils(NKUtils *this)
{
  this->__vftable = (NKUtils_vtbl *)&NKUtils::`vftable';
}
NKUtils *NKUtils::`vector deleting destructor'(NKUtils *this, unsigned int a2)
{
  this->__vftable = (NKUtils_vtbl *)&NKUtils::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
int NKUtils::getSectorID(NKUtils *this, std::wstring name)
{
  std::wstring *v2; // esi
  int v3; // edi
  int result; // eax
  int v5; // [esp+0h] [ebp-24h] BYREF
  wchar_t *EndPtr[2]; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  EndPtr[1] = (wchar_t *)&v5;
  v2 = &name;
  v7 = 0;
  if ( name._Myres >= 8 )
    v2 = (std::wstring *)name._Bx._Ptr;
  LOBYTE(v7) = 1;
  *__errno() = 0;
  v3 = _wcstol(v2->_Bx._Buf, EndPtr, 10);
  if ( v2 == (std::wstring *)EndPtr[0] )
    std::_Xinvalid_argument((const char *)&stru_17C4688);
  if ( *__errno() == 34 )
  {
    std::_Xout_of_range((const char *)&stru_17C4688.name._Myres);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
    result = 0;
  }
  else
  {
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    result = v3;
  }
  return result;
}
