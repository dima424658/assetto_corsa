#include "renderwindow.h"
void RenderWindow::RenderWindow(RenderWindow *this, std::wstring name, VideoSettings *videoSettings)
{
  VideoSettings *v3; // esi
  int v5; // ecx
  std::wstring *v6; // eax
  HWND v7; // eax

  v3 = videoSettings;
  v5 = 0;
  this->__vftable = (RenderWindow_vtbl *)&RenderWindow::`vftable';
  this->evOnMouseDown.handlers._Myfirst = 0;
  this->evOnMouseDown.handlers._Mylast = 0;
  this->evOnMouseDown.handlers._Myend = 0;
  this->evOnMouseWheelMoved.handlers._Myfirst = 0;
  this->evOnMouseWheelMoved.handlers._Mylast = 0;
  this->evOnMouseWheelMoved.handlers._Myend = 0;
  this->evOnMouseUp.handlers._Myfirst = 0;
  this->evOnMouseUp.handlers._Mylast = 0;
  this->evOnMouseUp.handlers._Myend = 0;
  this->evOnMouseMove.handlers._Myfirst = 0;
  this->evOnMouseMove.handlers._Mylast = 0;
  this->evOnMouseMove.handlers._Myend = 0;
  this->evOnWindowResize.handlers._Myfirst = 0;
  this->evOnWindowResize.handlers._Mylast = 0;
  this->evOnWindowResize.handlers._Myend = 0;
  this->evOnKeyChar.handlers._Myfirst = 0;
  this->evOnKeyChar.handlers._Mylast = 0;
  this->evOnKeyChar.handlers._Myend = 0;
  this->evOnKeyDown.handlers._Myfirst = 0;
  this->evOnKeyDown.handlers._Mylast = 0;
  this->evOnKeyDown.handlers._Myend = 0;
  this->evOnWindowClosed.handlers._Myfirst = 0;
  this->evOnWindowClosed.handlers._Mylast = 0;
  this->evOnWindowClosed.handlers._Myend = 0;
  this->evOnKeyUp.handlers._Myfirst = 0;
  this->evOnKeyUp.handlers._Mylast = 0;
  this->evOnKeyUp.handlers._Myend = 0;
  this->disableEventsWithMouseHidden = 1;
  rw = this;
  if ( v3->isFullscreen )
    v5 = 1;
  v6 = &name;
  if ( name._Myres >= 8 )
    v6 = (std::wstring *)name._Bx._Ptr;
  v7 = kglOpenWindow(v6->_Bx._Buf, v3->width, v3->height, v5 | 4);
  this->hWnd = v7;
  v3->hWnd = v7;
  kglWindowSetOnResize(onResize);
  kglWindowSetOnMouseDown(onMouseDown);
  kglWindowSetOnMouseUp(onMouseUp);
  kglWindowSetOnMouseWheel(onMouseWheel);
  kglWindowSetOnKeyDown(onKeyDown);
  kglWindowSetOnChar(onChar);
  kglWindowSetOnMouseMove(onMouseMove);
  kglWindowSetOnClose(onClose);
  kglWindowSetOnKeyUp(onKeyUp);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void RenderWindow::~RenderWindow(RenderWindow *this)
{
  this->__vftable = (RenderWindow_vtbl *)&RenderWindow::`vftable';
  if ( this->evOnKeyUp.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnKeyUp);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnKeyUp,
      (Task *)this->evOnKeyUp.handlers._Myfirst,
      (Task *)this->evOnKeyUp.handlers._Mylast);
    operator delete(this->evOnKeyUp.handlers._Myfirst);
    this->evOnKeyUp.handlers._Myfirst = 0;
    this->evOnKeyUp.handlers._Mylast = 0;
    this->evOnKeyUp.handlers._Myend = 0;
  }
  if ( this->evOnWindowClosed.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnWindowClosed);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnWindowClosed,
      (Task *)this->evOnWindowClosed.handlers._Myfirst,
      (Task *)this->evOnWindowClosed.handlers._Mylast);
    operator delete(this->evOnWindowClosed.handlers._Myfirst);
    this->evOnWindowClosed.handlers._Myfirst = 0;
    this->evOnWindowClosed.handlers._Mylast = 0;
    this->evOnWindowClosed.handlers._Myend = 0;
  }
  if ( this->evOnKeyDown.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnKeyDown);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnKeyDown,
      (Task *)this->evOnKeyDown.handlers._Myfirst,
      (Task *)this->evOnKeyDown.handlers._Mylast);
    operator delete(this->evOnKeyDown.handlers._Myfirst);
    this->evOnKeyDown.handlers._Myfirst = 0;
    this->evOnKeyDown.handlers._Mylast = 0;
    this->evOnKeyDown.handlers._Myend = 0;
  }
  if ( this->evOnKeyChar.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnKeyChar);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnKeyChar,
      (Task *)this->evOnKeyChar.handlers._Myfirst,
      (Task *)this->evOnKeyChar.handlers._Mylast);
    operator delete(this->evOnKeyChar.handlers._Myfirst);
    this->evOnKeyChar.handlers._Myfirst = 0;
    this->evOnKeyChar.handlers._Mylast = 0;
    this->evOnKeyChar.handlers._Myend = 0;
  }
  if ( this->evOnWindowResize.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnWindowResize);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnWindowResize,
      (Task *)this->evOnWindowResize.handlers._Myfirst,
      (Task *)this->evOnWindowResize.handlers._Mylast);
    operator delete(this->evOnWindowResize.handlers._Myfirst);
    this->evOnWindowResize.handlers._Myfirst = 0;
    this->evOnWindowResize.handlers._Mylast = 0;
    this->evOnWindowResize.handlers._Myend = 0;
  }
  if ( this->evOnMouseMove.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnMouseMove);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnMouseMove,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseMove.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseMove.handlers._Mylast);
    operator delete(this->evOnMouseMove.handlers._Myfirst);
    this->evOnMouseMove.handlers._Myfirst = 0;
    this->evOnMouseMove.handlers._Mylast = 0;
    this->evOnMouseMove.handlers._Myend = 0;
  }
  if ( this->evOnMouseUp.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnMouseUp);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnMouseUp,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseUp.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseUp.handlers._Mylast);
    operator delete(this->evOnMouseUp.handlers._Myfirst);
    this->evOnMouseUp.handlers._Myfirst = 0;
    this->evOnMouseUp.handlers._Mylast = 0;
    this->evOnMouseUp.handlers._Myend = 0;
  }
  if ( this->evOnMouseWheelMoved.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnMouseWheelMoved);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnMouseWheelMoved,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseWheelMoved.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseWheelMoved.handlers._Mylast);
    operator delete(this->evOnMouseWheelMoved.handlers._Myfirst);
    this->evOnMouseWheelMoved.handlers._Myfirst = 0;
    this->evOnMouseWheelMoved.handlers._Mylast = 0;
    this->evOnMouseWheelMoved.handlers._Myend = 0;
  }
  if ( this->evOnMouseDown.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnMouseDown);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnMouseDown,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseDown.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMouseDown.handlers._Mylast);
    operator delete(this->evOnMouseDown.handlers._Myfirst);
    this->evOnMouseDown.handlers._Myfirst = 0;
    this->evOnMouseDown.handlers._Mylast = 0;
    this->evOnMouseDown.handlers._Myend = 0;
  }
}
RenderWindow *RenderWindow::`scalar deleting destructor'(RenderWindow *this, unsigned int a2)
{
  RenderWindow::~RenderWindow(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
BOOL RenderWindow::hasFocus(RenderWindow *this)
{
  return kglWindowHasFocus(this->hWnd);
}
void RenderWindow::setFocus(RenderWindow *this)
{
  kglWindowSetFocus(this->hWnd);
}
BOOL RenderWindow::step(RenderWindow *this)
{
  return kglWindowStep() != 0;
}
