#include "optionsmanager.h"
void OptionsManager::OptionsManager(OptionsManager *this)
{
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *v2; // eax
  float *v3; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  std::wstring _Keyval; // [esp+10h] [ebp-28h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  this->__vftable = (OptionsManager_vtbl *)&OptionsManager::`vftable';
  this->options._Myhead = 0;
  this->options._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,int>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TyreCompoundStrategy>> > *)&this->options);
  this->options._Myhead = v2;
  v8 = 0;
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"PROVIEW_MODE", 0xCu);
  LOBYTE(v8) = 1;
  v3 = std::map<std::wstring,float>::operator[](&this->options, &_Keyval);
  LOBYTE(v8) = 0;
  *v3 = 0.0;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"AUTOFLIP_RECOVERY", 0x11u);
  LOBYTE(v8) = 2;
  v4 = std::map<std::wstring,float>::operator[](&this->options, &_Keyval);
  LOBYTE(v8) = 0;
  *v4 = 1.0;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"RENDER_SPLINE", 0xDu);
  LOBYTE(v8) = 3;
  v5 = std::map<std::wstring,float>::operator[](&this->options, &_Keyval);
  LOBYTE(v8) = 0;
  *v5 = 0.0;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"DISABLE_SHOW_MODE", 0x11u);
  LOBYTE(v8) = 4;
  v6 = std::map<std::wstring,float>::operator[](&this->options, &_Keyval);
  LOBYTE(v8) = 0;
  *v6 = 0.0;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  OptionsManager::loadOptions(this);
}
void OptionsManager::~OptionsManager(OptionsManager *this)
{
  std::map<std::wstring,float> *v1; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (OptionsManager_vtbl *)&OptionsManager::`vftable';
  v1 = &this->options;
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->options,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->options._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->options._Myhead);
  operator delete(v1->_Myhead);
}
OptionsManager *OptionsManager::`scalar deleting destructor'(OptionsManager *this, unsigned int a2)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (OptionsManager_vtbl *)&OptionsManager::`vftable';
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->options,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->options._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->options._Myhead);
  operator delete(this->options._Myhead);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void OptionsManager::loadOptions(OptionsManager *this)
{
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *v2; // edi
  std::map<std::wstring,float> *v3; // ebx
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *i; // esi
  float *v5; // ebx
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *v6; // eax
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *k; // eax
  std::_Tree_node<std::pair<std::wstring const ,float>,void *> *j; // eax
  std::map<std::wstring,float> *v9; // [esp+14h] [ebp-88h]
  std::wstring ifilename; // [esp+18h] [ebp-84h] BYREF
  std::wstring section; // [esp+30h] [ebp-6Ch] BYREF
  INIReader r; // [esp+48h] [ebp-54h] BYREF
  int v13; // [esp+98h] [ebp-4h]

  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/options.ini", 0x16u);
  v13 = 0;
  INIReader::INIReader(&r, &ifilename);
  LOBYTE(v13) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&r, 1);
  if ( r.ready )
  {
    v2 = this->options._Myhead;
    v3 = &this->options;
    v9 = &this->options;
    for ( i = v2->_Left; i != v2; v3 = v9 )
    {
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"OPTIONS", 7u);
      LOBYTE(v13) = 3;
      v5 = std::map<std::wstring,float>::operator[](v3, &i->_Myval.first);
      *v5 = INIReader::getFloat(&r, &section, &i->_Myval.first);
      LOBYTE(v13) = 2;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( !i->_Isnil )
      {
        v6 = i->_Right;
        if ( v6->_Isnil )
        {
          for ( j = i->_Parent; !j->_Isnil; j = j->_Parent )
          {
            if ( i != j->_Right )
              break;
            i = j;
          }
          i = j;
        }
        else
        {
          i = i->_Right;
          for ( k = v6->_Left; !k->_Isnil; k = k->_Left )
            i = k;
        }
      }
    }
  }
  v13 = -1;
  INIReader::~INIReader(&r);
}
