#include "mousehider.h"
void MouseHider::MouseHider(MouseHider *this, Sim *aSim)
{
  int v3; // eax
  bool v4; // cf
  int v5; // eax
  int v6; // eax
  CarAvatar *v7; // eax
  ICarControlsProvider *v8; // eax
  KeyboardCarControl *v9; // eax
  Event<OnMouseWheelMovedEvent> *v10; // ecx
  Event<OnMouseWheelMovedEvent> *v11; // ecx
  std::wstring v12; // [esp-1Ch] [ebp-D4h] BYREF
  unsigned int v13; // [esp-4h] [ebp-BCh]
  MouseHider *v14; // [esp+18h] [ebp-A0h]
  std::wstring section; // [esp+1Ch] [ebp-9Ch] BYREF
  std::wstring key; // [esp+34h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+4Ch] [ebp-6Ch] BYREF
  INIReader r; // [esp+64h] [ebp-54h] BYREF
  int v19; // [esp+B4h] [ebp-4h]

  v14 = this;
  v13 = (unsigned int)aSim->game;
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  std::wstring::assign(&v12, L"MOUSE_HIDDENER", 0xEu);
  GameObject::GameObject(this, v12, (Game *)v13);
  v13 = 26;
  v19 = 0;
  v12._Myres = (unsigned int)L"system/cfg/mouse_hider.ini";
  this->__vftable = (MouseHider_vtbl *)&MouseHider::`vftable';
  this->sim = aSim;
  this->keyboardControls = 0;
  *(_WORD *)&this->firstUpdate = 0;
  this->lastTime = 0;
  this->hideInterval = 2500;
  this->interval = 2500;
  this->resetPosition = 1;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v12._Myres, v13);
  LOBYTE(v19) = 1;
  INIReader::INIReader(&r, &ifilename);
  LOBYTE(v19) = 3;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HIDE_INTERVAL", 0xDu);
    LOBYTE(v19) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v19) = 5;
    v3 = INIReader::getInt(&r, &section, &key);
    v4 = section._Myres < 8;
    this->hideInterval = v3 / 2;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v19) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"RESET_POSITION", 0xEu);
    LOBYTE(v19) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v19) = 7;
    v5 = INIReader::getInt(&r, &section, &key);
    v4 = section._Myres < 8;
    this->resetPosition = v5 != 0;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v19) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  v6 = this->hideInterval;
  v13 = 0;
  this->interval = v6;
  v7 = Sim::getCar(aSim, v13);
  v8 = CarAvatar::getControlsProvider(v7);
  v9 = (KeyboardCarControl *)__RTDynamicCast(
                               v8,
                               0,
                               &ICarControlsProvider `RTTI Type Descriptor',
                               &KeyboardCarControl `RTTI Type Descriptor',
                               0);
  if ( v9 )
    this->keyboardControls = v9;
  v13 = (unsigned int)this;
  v12._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_e6ab34ddb76a0a09a876fd341536965f_,0>,std::allocator<std::_Func_class<void,OnMouseMoveEvent const &>>,void,OnMouseMoveEvent const &>::`vftable';
  *(_DWORD *)&v12._Bx._Alias[4] = this;
  v12._Mysize = (unsigned int)&v12;
  v10 = (Event<OnMouseWheelMovedEvent> *)&aSim->game->window.evOnMouseMove;
  LOBYTE(v19) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v10,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v12,
    this);
  v13 = (unsigned int)this;
  v12._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_08c59d4de76f2cbfd8ff9029432d7cae_,0>,std::allocator<std::_Func_class<void,OnMouseUpEvent const &>>,void,OnMouseUpEvent const &>::`vftable';
  *(_DWORD *)&v12._Bx._Alias[4] = this;
  v12._Mysize = (unsigned int)&v12;
  v11 = (Event<OnMouseWheelMovedEvent> *)&aSim->game->window.evOnMouseUp;
  LOBYTE(v19) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    v11,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v12,
    this);
  LOBYTE(v19) = 0;
  INIReader::~INIReader(&r);
}
MouseHider *MouseHider::`scalar deleting destructor'(MouseHider *this, unsigned int a2)
{
  this->__vftable = (MouseHider_vtbl *)&MouseHider::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
bool MouseHider::isCursorInsideWindow(MouseHider *this, const tagPOINT *point)
{
  int v2; // eax
  bool result; // al
  tagRECT winRect; // [esp+0h] [ebp-14h] BYREF

  GetWindowRect((HWND)this->game->window.hWnd, &winRect);
  result = 0;
  if ( point->x >= winRect.left && point->x <= winRect.right )
  {
    v2 = point->y;
    if ( v2 >= winRect.top && v2 <= winRect.bottom )
      result = 1;
  }
  return result;
}
void MouseHider::showCursor(MouseHider *this, bool value)
{
  BOOL v3; // eax
  tagCURSORINFO pci; // [esp+4h] [ebp-14h] BYREF

  if ( this->forceHide )
  {
    this->game->gui->isPointerVisible = 0;
    ShowCursor(0);
  }
  else
  {
    pci.cbSize = 20;
    v3 = GetCursorInfo(&pci);
    if ( value )
    {
      if ( !v3 || pci.flags != 1 )
      {
        while ( ShowCursor(1) < 0 )
          ;
        this->interval = this->hideInterval;
      }
    }
    else if ( v3 && pci.flags == 1 )
    {
      while ( ShowCursor(0) >= 0 )
        ;
    }
    this->game->gui->isPointerVisible = value;
  }
}
void MouseHider::update(MouseHider *this, float deltaT)
{
  KeyboardCarControl *v3; // ecx
  Sim *v4; // edx
  Sim *v5; // ecx
  Game *v6; // ecx
  tagPOINT newpos; // [esp+4h] [ebp-1Ch] BYREF
  tagCURSORINFO pci; // [esp+Ch] [ebp-14h] BYREF

  v3 = this->keyboardControls;
  if ( !v3 )
    goto LABEL_11;
  if ( v3->mouseSteering )
  {
    v4 = this->sim;
    if ( v4->pauseMenu->visible || v4->escMenu->visible )
    {
      MouseHider::showCursor(this, 1);
      return;
    }
  }
  if ( !v3->mouseSteering
    || (v5 = this->sim, v5->escMenu->visible)
    || v5->pauseMenu->visible
    || ReplayManager::isInReplaymode(v5->replayManager) )
  {
LABEL_11:
    v6 = this->game;
    if ( v6->gameTime.now - (double)this->lastTime > (double)this->interval && RenderWindow::hasFocus(&v6->window) )
    {
      GetCursorPos(&newpos);
      if ( MouseHider::isCursorInsideWindow(this, &newpos) )
      {
        pci.cbSize = 20;
        if ( GetCursorInfo(&pci) && pci.flags == 1 && newpos.x == this->lastPoint.x && newpos.y == this->lastPoint.y )
          MouseHider::showCursor(this, 0);
        this->lastPoint = newpos;
      }
      this->lastTime = (unsigned int)this->game->gameTime.now;
    }
  }
  else
  {
    MouseHider::showCursor(this, 0);
  }
}
