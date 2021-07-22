#include "dicontrolbutton.h
void DIControlButton::DIControlButton(DIControlButton *this, std::wstring iname, DirectInput *di)
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
  this->__vftable = (DIControlButton_vtbl *)&DIControlButton::`vftable';
  this->combineWithKeyboard = 0;
  this->keyboardKey = -1;
  if ( !v4 )
    operator delete(iname._Bx._Ptr);
}
void DIControlButton::~DIControlButton(DIControlButton *this)
{
  this->__vftable = (DIControlButton_vtbl *)&DIControlButton::`vftable';
  DIControlInput::~DIControlInput(this);
}
DIControlButton *DIControlButton::`scalar deleting destructor'(DIControlButton *this, unsigned int a2)
{
  this->__vftable = (DIControlButton_vtbl *)&DIControlButton::`vftable';
  DIControlInput::~DIControlInput(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double DIControlButton::getKeyboardValue(DIControlButton *this, bool isKeyboardEnabled)
{
  double result; // st7

  if ( this->combineWithKeyboard && isKeyboardEnabled && this->keyboardKey != -1 )
    result = (double)GetAsyncKeyState(this->keyboardKey);
  else
    result = 0.0;
  return result;
}
double DIControlButton::getValue(DIControlButton *this, bool useRange)
{
  InputDevice *v2; // edx
  int v3; // eax
  double result; // st7

  v2 = this->device;
  if ( !v2 || (v3 = this->axis.index, v3 == -1) )
    result = 0.0;
  else
    result = (double)v2->state.buttons[v3];
  return result;
}
void DIControlButton::load(DIControlButton *this, INIReader *reader, bool loadRange)
{
  bool v4; // bl
  int v5; // eax
  bool v6; // cf
  int v7; // eax
  int v8; // eax
  int v9; // eax
  std::wstring key; // [esp+10h] [ebp-58h] BYREF
  std::wstring section; // [esp+28h] [ebp-40h] BYREF
  std::wstring v12; // [esp+40h] [ebp-28h] BYREF
  int v13; // [esp+64h] [ebp-4h]

  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ADVANCED", 8u);
  v13 = 0;
  v4 = INIReader::hasSection(reader, &section);
  v13 = -1;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v4 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"COMBINE_WITH_KEYBOARD_CONTROL", 0x1Du);
    v13 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ADVANCED", 8u);
    LOBYTE(v13) = 2;
    v5 = INIReader::getInt(reader, &section, &key);
    v6 = section._Myres < 8;
    this->combineWithKeyboard = v5 > 0;
    if ( !v6 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v13 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"JOY", 3u);
  v13 = 3;
  v7 = INIReader::getInt(reader, &this->name, &key);
  v6 = key._Myres < 8;
  this->axis.joy = v7;
  v13 = -1;
  if ( !v6 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"BUTTON", 6u);
  v13 = 4;
  v8 = INIReader::getInt(reader, &this->name, &key);
  v6 = key._Myres < 8;
  this->axis.index = v8;
  v13 = -1;
  if ( !v6 )
    operator delete(key._Bx._Ptr);
  this->device = DirectInput::getDevice(this->directInput, this->axis.joy);
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  std::wstring::assign(&v12, L"KEY", 3u);
  v13 = 5;
  v9 = INIReader::getHex(reader, &this->name, &v12);
  v6 = v12._Myres < 8;
  this->keyboardKey = v9;
  if ( !v6 )
    operator delete(v12._Bx._Ptr);
}
