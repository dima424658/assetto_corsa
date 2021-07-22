#include "joypadmanager.h
void JoypadManager::~JoypadManager(JoypadManager *this)
{
  if ( this->joypad._Myptr )
    operator delete(this->joypad._Myptr);
}
void JoypadManager::JoypadManager(JoypadManager *this)
{
  Joypad *v2; // eax
  Joypad *v3; // ecx

  this->joypad._Myptr = 0;
  v2 = (Joypad *)operator new(20);
  if ( v2 )
    v2->__vftable = (Joypad_vtbl *)&X360Joypad::`vftable';
  else
    v2 = 0;
  v3 = this->joypad._Myptr;
  this->joypad._Myptr = v2;
  if ( v3 )
    operator delete(v3);
}
