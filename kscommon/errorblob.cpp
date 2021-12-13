#include "errorblob.h"
void ErrorBlob::ErrorBlob(ErrorBlob *this)
{
  this->__vftable = (ErrorBlob_vtbl *)&ErrorBlob::`vftable';
  this->blob._Myfirst = 0;
  this->blob._Mylast = 0;
  this->blob._Myend = 0;
}
void ErrorBlob::~ErrorBlob(ErrorBlob *this)
{
  std::wstring *v2; // eax

  this->__vftable = (ErrorBlob_vtbl *)&ErrorBlob::`vftable';
  v2 = this->blob._Myfirst;
  if ( v2 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v2, this->blob._Mylast);
    operator delete(this->blob._Myfirst);
    this->blob._Myfirst = 0;
    this->blob._Mylast = 0;
    this->blob._Myend = 0;
  }
}
ErrorBlob *ErrorBlob::`vector deleting destructor'(ErrorBlob *this, unsigned int a2)
{
  std::wstring *v3; // eax

  this->__vftable = (ErrorBlob_vtbl *)&ErrorBlob::`vftable';
  v3 = this->blob._Myfirst;
  if ( v3 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v3, this->blob._Mylast);
    operator delete(this->blob._Myfirst);
    this->blob._Myfirst = 0;
    this->blob._Mylast = 0;
    this->blob._Myend = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
