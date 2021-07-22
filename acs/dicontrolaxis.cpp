#include "dicontrolaxis.h
void DIControlAxis::DIControlAxis(DIControlAxis *this, std::wstring iname, DirectInput *di)
{
  bool v4; // cf
  std::wstring v5; // [esp-1Ch] [ebp-34h] BYREF
  DirectInput *v6; // [esp-4h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-4h]

  v6 = di;
  v7 = 0;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, &iname, 0, 0xFFFFFFFF);
  DIControlInput::DIControlInput(this, v5, v6);
  v4 = iname._Myres < 8;
  this->__vftable = (DIControlAxis_vtbl *)&DIControlAxis::`vftable';
  this->hasMoved = 0;
  if ( !v4 )
    operator delete(iname._Bx._Ptr);
}
void DIControlAxis::~DIControlAxis(DIControlAxis *this)
{
  this->__vftable = (DIControlAxis_vtbl *)&DIControlAxis::`vftable';
  DIControlInput::~DIControlInput(this);
}
DIControlAxis *DIControlAxis::`scalar deleting destructor'(DIControlAxis *this, unsigned int a2)
{
  this->__vftable = (DIControlAxis_vtbl *)&DIControlAxis::`vftable';
  DIControlInput::~DIControlInput(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double DIControlAxis::getValue(DIControlAxis *this, bool useRange)
{
  InputDevice *v2; // edx
  int v3; // eax
  float v4; // xmm0_4
  float useRangea; // [esp+Ch] [ebp+4h]

  v2 = this->device;
  if ( v2 )
  {
    v3 = this->axis.index;
    if ( v3 != -1 )
    {
      v4 = *(&v2->state.x + v3);
      if ( useRange )
      {
        if ( this->hasMoved || (this->hasMoved = v4 != 0.0) )
        {
          useRangea = this->axis.minv;
          if ( (float)(this->axis.maxv - useRangea) != 0.0 )
            return (v4 - useRangea) / (float)(this->axis.maxv - this->axis.minv);
        }
      }
      else
      {
        if ( this->hasMoved )
          return v4;
        this->hasMoved = v4 != 0.0;
        if ( v4 != 0.0 )
          return v4;
      }
    }
  }
  return 0.0;
}
void DIControlAxis::load(DIControlAxis *this, INIReader *reader, bool loadRange)
{
  int v4; // eax
  bool v5; // cf
  int v6; // eax
  double v7; // st7
  double v8; // st7
  std::wstring key; // [esp+10h] [ebp-40h] BYREF
  std::wstring v10; // [esp+28h] [ebp-28h] BYREF
  int v11; // [esp+4Ch] [ebp-4h]

  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"JOY", 3u);
  v11 = 0;
  v4 = INIReader::getInt(reader, &this->name, &key);
  v5 = key._Myres < 8;
  this->axis.joy = v4;
  v11 = -1;
  if ( !v5 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"AXLE", 4u);
  v11 = 1;
  v6 = INIReader::getInt(reader, &this->name, &key);
  v5 = key._Myres < 8;
  this->axis.index = v6;
  v11 = -1;
  if ( !v5 )
    operator delete(key._Bx._Ptr);
  if ( loadRange )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN", 3u);
    v11 = 2;
    v7 = INIReader::getFloat(reader, &this->name, &key);
    v5 = key._Myres < 8;
    this->axis.minv = v7;
    v11 = -1;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
    std::wstring::assign(&v10, L"MAX", 3u);
    v11 = 3;
    v8 = INIReader::getFloat(reader, &this->name, &v10);
    v5 = v10._Myres < 8;
    this->axis.maxv = v8;
    v11 = -1;
    if ( !v5 )
      operator delete(v10._Bx._Ptr);
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
  }
  else
  {
    this->axis.minv = 0.0;
    this->axis.maxv = 0.0;
  }
  this->device = DirectInput::getDevice(this->directInput, this->axis.joy);
}
