#include "directinput.h"
void DirectInput::DirectInput(DirectInput *this)
{
  IDirectInput8W **v2; // edi

  this->__vftable = (DirectInput_vtbl *)&DirectInput::`vftable';
  this->guids._Myfirst = 0;
  this->guids._Mylast = 0;
  this->guids._Myend = 0;
  this->devices._Myfirst = 0;
  this->devices._Mylast = 0;
  this->devices._Myend = 0;
  v2 = &this->lpDI;
  this->lpDI = 0;
  if ( DirectInput8Create(DirectInput::hInstance, 0x800u, &IID_IDirectInput8W, (LPVOID *)&this->lpDI, 0) < 0 || !*v2 )
    _printf("DirectInput8Create FAILED\n");
  DirectInput::initJoys(this);
}
DirectInput *DirectInput::`vector deleting destructor'(DirectInput *this, unsigned int a2)
{
  DirectInput::~DirectInput(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DirectInput::~DirectInput(DirectInput *this)
{
  IDirectInput8W *v2; // ecx
  std::pair<_GUID,std::wstring > *v3; // ecx

  this->__vftable = (DirectInput_vtbl *)&DirectInput::`vftable';
  std::_For_each<InputDevice * *,_lambda_6452013f698eed48c996500d868acda6_>(
    this->devices._Myfirst,
    this->devices._Mylast);
  v2 = this->lpDI;
  if ( v2 )
    v2->Release(this->lpDI);
  if ( this->devices._Myfirst )
  {
    operator delete(this->devices._Myfirst);
    this->devices._Myfirst = 0;
    this->devices._Mylast = 0;
    this->devices._Myend = 0;
  }
  v3 = this->guids._Myfirst;
  if ( v3 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::pair<_GUID,std::wstring>>>>(v3, this->guids._Mylast);
    operator delete(this->guids._Myfirst);
    this->guids._Myfirst = 0;
    this->guids._Mylast = 0;
    this->guids._Myend = 0;
  }
}
void DirectInput::initJoys(DirectInput *this)
{
  DirectInput *v1; // ebp
  const __m128i *v2; // esi
  std::pair<_GUID,std::wstring > *v3; // edi
  std::vector<ksgui::CustomSpinner *> *v4; // ebx
  InputDevice *v5; // edx
  __m128i v6; // xmm0
  InputDevice *v7; // eax
  InputDevice *v8; // ebp
  InputDevice **v9; // ecx
  ksgui::CustomSpinner **v10; // eax
  int v11; // ebp
  ksgui::CustomSpinner **v12; // ecx
  _DWORD *v13; // eax
  _GUID v14; // [esp-18h] [ebp-4Ch]
  InputDevice *id; // [esp+18h] [ebp-1Ch] BYREF
  DirectInput *v16; // [esp+1Ch] [ebp-18h]
  InputDevice *v17; // [esp+20h] [ebp-14h]
  int v18; // [esp+30h] [ebp-4h]

  v1 = this;
  v16 = this;
  this->lpDI->EnumDevices(this->lpDI, 4u, EnumJoysticksCallbackDI, this, 1u);
  v2 = (const __m128i *)v1->guids._Myfirst;
  v3 = v1->guids._Mylast;
  if ( v2 != (const __m128i *)v3 )
  {
    v4 = (std::vector<ksgui::CustomSpinner *> *)&v1->devices;
    do
    {
      v5 = (InputDevice *)operator new(0xECu);
      v17 = v5;
      v18 = 0;
      if ( v5 )
      {
        v6 = _mm_loadu_si128(v2);
        *(_DWORD *)&v14.Data2 = v1;
        *(_QWORD *)v14.Data4 = v6.m128i_i64[0];
        v14.Data1 = (unsigned int)&v2[1];
        InputDevice::InputDevice(v5, v14, (const std::wstring *)v6.m128i_i32[2], (DirectInput *)v6.m128i_i32[3]);
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      v18 = -1;
      v9 = &id;
      v10 = v4->_Mylast;
      id = v8;
      if ( &id >= (InputDevice **)v10
        || (v9 = (InputDevice **)v4->_Myfirst, v4->_Myfirst > (ksgui::CustomSpinner **)&id) )
      {
        if ( v10 == v4->_Myend )
          std::vector<ksgui::CustomSpinner *>::_Reserve(v4, (unsigned int)v9);
        v13 = v4->_Mylast;
        if ( v13 )
          *v13 = v8;
      }
      else
      {
        v11 = &id - v9;
        if ( v10 == v4->_Myend )
          std::vector<ksgui::CustomSpinner *>::_Reserve(v4, (unsigned int)v4->_Myfirst);
        v12 = v4->_Mylast;
        if ( v12 )
          *v12 = v4->_Myfirst[v11];
      }
      ++v4->_Mylast;
      v2 = (const __m128i *)((char *)v2 + 40);
      v1 = v16;
    }
    while ( v2 != (const __m128i *)v3 );
  }
}
void __cdecl DirectInput::singleton()
{
  DirectInput *v0; // eax
  DirectInput *v1; // eax

  if ( !DirectInput::m_singleton )
  {
    if ( DirectInput::hWnd == (HWND__ *)DirectInput::m_singleton )
      _printf("ERROR: Trying to create DirectInput with a null hWnd\n");
    v0 = (DirectInput *)operator new(0x20u);
    if ( v0 )
    {
      DirectInput::DirectInput(v0);
      DirectInput::m_singleton = v1;
    }
    else
    {
      DirectInput::m_singleton = 0;
    }
  }
}
int DirectInput::cleanup()
{
  int result; // eax

  if ( DirectInput::m_singleton )
    result = ((int (*)(DirectInput *, int))DirectInput::m_singleton->~DirectInput)(
               DirectInput::m_singleton,
               1);
  DirectInput::m_singleton = 0;
  return result;
}
InputDevice *DirectInput::getDevice(DirectInput *this, int index)
{
  InputDevice *result; // eax

  if ( index < 0 || index >= (unsigned int)(this->devices._Mylast - this->devices._Myfirst) )
    result = 0;
  else
    result = this->devices._Myfirst[index];
  return result;
}
void DirectInput::poll(DirectInput *this)
{
  InputDevice **v1; // esi
  unsigned int v2; // ebx
  int v3; // edi

  v1 = this->devices._Myfirst;
  v2 = (unsigned int)((char *)this->devices._Mylast - (char *)v1 + 3) >> 2;
  v3 = 0;
  if ( v1 > this->devices._Mylast )
    v2 = 0;
  if ( v2 )
  {
    do
    {
      InputDevice::poll(*v1);
      ++v3;
      ++v1;
    }
    while ( v3 != v2 );
  }
}
void DirectInput::forceFF(DirectInput *this, float v)
{
  InputDevice **v2; // esi
  unsigned int v3; // ebx
  int v4; // edi

  v2 = this->devices._Myfirst;
  v3 = (unsigned int)((char *)this->devices._Mylast - (char *)v2 + 3) >> 2;
  v4 = 0;
  if ( v2 > this->devices._Mylast )
    v3 = 0;
  if ( v3 )
  {
    do
    {
      InputDevice::sendFF(*v2, v, 0.0);
      ++v4;
      ++v2;
    }
    while ( v4 != v3 );
  }
}
