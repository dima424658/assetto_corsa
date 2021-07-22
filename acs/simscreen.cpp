#include "simscreen.h"
void SimScreen::SimScreen(SimScreen *this, Sim *isim)
{
  Game *v3; // eax
  ksgui::GUI *v4; // ecx
  std::wstring v5; // [esp-1Ch] [ebp-38h] BYREF
  Game *v6; // [esp-4h] [ebp-20h]
  SimScreen *v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+18h] [ebp-4h]

  v7 = this;
  v6 = isim->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"SIM_SCREEN", 0xAu);
  GameObject::GameObject(this, v5, v6);
  v3 = this->game;
  this->__vftable = (SimScreen_vtbl *)&SimScreen::`vftable';
  this->sim = isim;
  v6 = (Game *)1;
  v4 = v3->gui;
  v8 = 0;
  ksgui::Control::setVisible(v4->taskbar, 1);
}
SimScreen *SimScreen::`scalar deleting destructor'(SimScreen *this, unsigned int a2)
{
  this->__vftable = (SimScreen_vtbl *)&SimScreen::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge SimScreen::render(SimScreen *this@<ecx>, __int64 a2@<esi:edi>, float deltaT)
{
  Sim::renderScene(this->sim, a2, deltaT);
}
