#include "keyboardmanager.h
void KeyboardManager::KeyboardManager(KeyboardManager *this, RenderWindow *arenderWindow)
{
  Event<OnKeyEvent> *v3; // ecx
  Event<OnKeyCharEvent> *v4; // ecx
  std::function<void __cdecl(SessionInfo const &)> v5; // [esp-1Ch] [ebp-3Ch] BYREF
  KeyboardManager *v6; // [esp-4h] [ebp-24h]
  KeyboardManager *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = this;
  this->__vftable = (KeyboardManager_vtbl *)&KeyboardManager::`vftable';
  this->renderWindow = arenderWindow;
  this->listeners._Myfirst = 0;
  this->listeners._Mylast = 0;
  this->listeners._Myend = 0;
  v6 = this;
  v8 = 0;
  this->focusListener = 0;
  v5._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_41758ac50f95efa4714a120fd0a1f20a_,0>,std::allocator<std::_Func_class<void,OnKeyEvent const &>>,void,OnKeyEvent const &>::`vftable';
  v5._Space._Pfn[1] = (void (__cdecl *)())this;
  v5._Impl = (std::_Func_base<void,SessionInfo const &> *)&v5;
  v3 = &this->renderWindow->evOnKeyDown;
  LOBYTE(v8) = 0;
  Event<float>::addHandler((Event<SessionInfo> *)v3, v5, v6);
  v6 = this;
  v5._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_48a7d9d50f1bb3d51f3bd346885a7e5c_,0>,std::allocator<std::_Func_class<void,OnKeyCharEvent const &>>,void,OnKeyCharEvent const &>::`vftable';
  v5._Space._Pfn[1] = (void (__cdecl *)())this;
  v5._Impl = (std::_Func_base<void,SessionInfo const &> *)&v5;
  v4 = &this->renderWindow->evOnKeyChar;
  LOBYTE(v8) = 0;
  Event<float>::addHandler((Event<SessionInfo> *)v4, v5, this);
}
void KeyboardManager::~KeyboardManager(KeyboardManager *this)
{
  std::vector<IKeyEventListener *> *v1; // esi

  v1 = &this->listeners;
  this->__vftable = (KeyboardManager_vtbl *)&KeyboardManager::`vftable';
  if ( this->listeners._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->listeners);
    operator delete(v1->_Myfirst);
    v1->_Myfirst = 0;
    v1->_Mylast = 0;
    v1->_Myend = 0;
  }
}
KeyboardManager *KeyboardManager::`scalar deleting destructor'(KeyboardManager *this, unsigned int a2)
{
  this->__vftable = (KeyboardManager_vtbl *)&KeyboardManager::`vftable';
  if ( this->listeners._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->listeners);
    operator delete(this->listeners._Myfirst);
    this->listeners._Myfirst = 0;
    this->listeners._Mylast = 0;
    this->listeners._Myend = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void KeyboardManager::onKeyPressEvent(KeyboardManager *this, const OnKeyCharEvent *message)
{
  IKeyEventListener *v3; // ecx
  IKeyEventListener **v4; // eax
  IKeyEventListener **v5; // esi
  int v6; // edi
  unsigned int v7; // ebx

  v3 = this->focusListener;
  if ( v3 )
    v3->onKeyChar(v3, message->key);
  v4 = this->listeners._Mylast;
  v5 = this->listeners._Myfirst;
  v6 = 0;
  v7 = (unsigned int)((char *)v4 - (char *)v5 + 3) >> 2;
  if ( v5 > v4 )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      (*v5)->onKeyChar(*v5, message->key);
      ++v6;
      ++v5;
    }
    while ( v6 != v7 );
  }
}
void KeyboardManager::releaseFocus(KeyboardManager *this, IKeyEventListener *l)
{
  if ( l == this->focusListener )
    this->focusListener = 0;
}
