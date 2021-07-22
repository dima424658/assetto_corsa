#include "surfacesmanager.h
void SurfacesManager::SurfacesManager(SurfacesManager *this, TrackAvatar *track)
{
  std::_Tree_node<std::pair<std::wstring const ,SurfaceDef>,void *> *v3; // eax
  SurfaceDef *v4; // eax
  int v5; // eax
  bool v6; // cf
  char v7; // al
  std::wstring *v8; // esi
  std::wstring *v9; // esi
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // esi
  std::wstring v13; // [esp-18h] [ebp-1C0h] BYREF
  char v14; // [esp+17h] [ebp-191h]
  SurfacesManager *v15; // [esp+1Ch] [ebp-18Ch]
  SurfaceDef sdwall; // [esp+20h] [ebp-188h] BYREF
  std::wstring data_folder; // [esp+DCh] [ebp-CCh] BYREF
  std::wstring _Keyval; // [esp+F4h] [ebp-B4h] BYREF
  std::wstring key; // [esp+10Ch] [ebp-9Ch] BYREF
  std::wstring ifilename; // [esp+124h] [ebp-84h] BYREF
  std::wstring result; // [esp+13Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+154h] [ebp-54h] BYREF
  int v23; // [esp+1A4h] [ebp-4h]

  this->__vftable = (SurfacesManager_vtbl *)&SurfacesManager::`vftable';
  v15 = this;
  this->surfaces._Myhead = 0;
  this->surfaces._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,SurfaceDef>>>::_Buyheadnode(&this->surfaces);
  this->surfaces._Myhead = v3;
  v23 = 0;
  this->enableCrash = 0;
  SurfaceDef::SurfaceDef(&sdwall);
  sdwall.collisionCategory = 2;
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"WALL", 4u);
  LOBYTE(v23) = 1;
  v4 = std::map<std::wstring,SurfaceDef>::operator[](&this->surfaces, &_Keyval);
  LOBYTE(v23) = 0;
  qmemcpy(v4, &sdwall, sizeof(SurfaceDef));
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v23) = 2;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v23) = 4;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"WARNINGS_AS_ERRORS", 0x12u);
  LOBYTE(v23) = 5;
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"ASSETTO_CORSA", 0xDu);
  LOBYTE(v23) = 6;
  v5 = INIReader::getInt(&ini, &_Keyval, &key);
  v6 = _Keyval._Myres < 8;
  this->enableCrash = v5 != 0;
  if ( !v6 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  LOBYTE(v23) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  std::wstring::assign(&v13, L"system/data/surfaces.ini", 0x18u);
  SurfacesManager::loadSurfaceDefinitions(this, v13);
  data_folder._Myres = 7;
  data_folder._Mysize = 0;
  data_folder._Bx._Buf[0] = 0;
  LOBYTE(v23) = 7;
  v7 = TrackAvatar::getConfig(track, &key)->_Mysize == 0;
  v14 = v7;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v7 = v14;
  }
  if ( v7 )
  {
    v8 = std::operator+<wchar_t>(&key, L"content/tracks/", &track->name);
    if ( &data_folder != v8 )
    {
      if ( data_folder._Myres >= 8 )
        operator delete(data_folder._Bx._Ptr);
      data_folder._Myres = 7;
      data_folder._Mysize = 0;
      data_folder._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&data_folder, v8);
    }
    if ( key._Myres >= 8 )
    {
      v13._Myres = (unsigned int)key._Bx._Ptr;
LABEL_30:
      operator delete(v13._Myres);
      goto LABEL_31;
    }
  }
  else
  {
    v9 = TrackAvatar::getConfig(track, &result);
    LOBYTE(v23) = 8;
    v10 = std::operator+<wchar_t>(&ifilename, L"content/tracks/", &track->name);
    LOBYTE(v23) = 9;
    v11 = std::operator+<wchar_t>(&_Keyval, v10, L"/");
    LOBYTE(v23) = 10;
    v12 = std::operator+<wchar_t>(&key, v11, v9);
    if ( &data_folder != v12 )
    {
      if ( data_folder._Myres >= 8 )
        operator delete(data_folder._Bx._Ptr);
      data_folder._Myres = 7;
      data_folder._Mysize = 0;
      data_folder._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&data_folder, v12);
    }
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( _Keyval._Myres >= 8 )
      operator delete(_Keyval._Bx._Ptr);
    _Keyval._Myres = 7;
    _Keyval._Mysize = 0;
    _Keyval._Bx._Buf[0] = 0;
    if ( ifilename._Myres >= 8 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    LOBYTE(v23) = 7;
    if ( result._Myres >= 8 )
    {
      v13._Myres = (unsigned int)result._Bx._Ptr;
      goto LABEL_30;
    }
  }
LABEL_31:
  std::operator+<wchar_t>(&v13, &data_folder, L"/data/surfaces.ini");
  SurfacesManager::loadSurfaceDefinitions(this, v13);
  if ( data_folder._Myres >= 8 )
    operator delete(data_folder._Bx._Ptr);
  data_folder._Myres = 7;
  data_folder._Mysize = 0;
  data_folder._Bx._Buf[0] = 0;
  LOBYTE(v23) = 0;
  INIReader::~INIReader(&ini);
}
void SurfacesManager::~SurfacesManager(SurfacesManager *this)
{
  std::map<std::wstring,SurfaceDef> *v1; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (SurfacesManager_vtbl *)&SurfacesManager::`vftable';
  v1 = &this->surfaces;
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->surfaces,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->surfaces._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->surfaces._Myhead);
  operator delete(v1->_Myhead);
}
SurfacesManager *SurfacesManager::`vector deleting destructor'(SurfacesManager *this, unsigned int a2)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (SurfacesManager_vtbl *)&SurfacesManager::`vftable';
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->surfaces,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->surfaces._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->surfaces._Myhead);
  operator delete(this->surfaces._Myhead);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
SurfaceDef *SurfacesManager::getSurface(SurfacesManager *this, SurfaceDef *result, std::wstring name)
{
  SurfacesManager *v3; // ebp
  SurfaceDef *v4; // edi
  std::pair<std::wstring,SurfaceDef> *v5; // esi
  std::_Tree_node<std::pair<std::wstring const ,SurfaceDef>,void *> *v6; // eax
  std::_Tree_node<std::pair<std::wstring const ,SurfaceDef>,void *> *v7; // ebx
  const wchar_t *v8; // eax
  std::pair<std::wstring,SurfaceDef> *v9; // esi
  int v10; // edi
  std::pair<std::wstring,SurfaceDef> *v11; // ebp
  SurfaceDef *v12; // edi
  char *v13; // esi
  std::_Tree_node<std::pair<std::wstring const ,SurfaceDef>,void *> *v14; // eax
  std::_Tree_node<std::pair<std::wstring const ,SurfaceDef>,void *> *j; // eax
  std::_Tree_node<std::pair<std::wstring const ,SurfaceDef>,void *> *i; // eax
  std::pair<std::wstring,SurfaceDef> *v17; // ebp
  SurfaceDef *v18; // eax
  std::wstring *v19; // eax
  SurfacesManager *v20; // ebx
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  std::wstring *v23; // eax
  SurfaceDef *v24; // esi
  std::vector<std::pair<std::wstring,SurfaceDef>> res; // [esp+18h] [ebp-1C8h] BYREF
  SurfacesManager::getSurface::__l20::<lambda_95f350032d24590ba7f8ab2718cae5d7> _Func; // [esp+28h] [ebp-1B8h] BYREF
  SurfacesManager *v27; // [esp+2Ch] [ebp-1B4h]
  SurfaceDef *v28; // [esp+30h] [ebp-1B0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v29; // [esp+34h] [ebp-1ACh] BYREF
  std::wstring v30; // [esp+E4h] [ebp-FCh] BYREF
  std::wstring _Right; // [esp+FCh] [ebp-E4h] BYREF
  char v32[188]; // [esp+114h] [ebp-CCh] BYREF
  int v33; // [esp+1DCh] [ebp-4h]

  v3 = this;
  v27 = this;
  v4 = result;
  v28 = result;
  _Func.ss = 0;
  v5 = 0;
  v33 = 0;
  res._Myfirst = 0;
  res._Mylast = 0;
  res._Myend = 0;
  v6 = this->surfaces._Myhead;
  LOBYTE(v33) = 1;
  v7 = v6->_Left;
  if ( v6->_Left != v6 )
  {
    while ( 1 )
    {
      v8 = (const wchar_t *)(v7->_Myval.first._Myres < 8 ? &v7->_Myval : v7->_Myval.first._Bx._Ptr);
      if ( std::wstring::find(&name, v8, 0, v7->_Myval.first._Mysize) != -1 )
        break;
LABEL_20:
      if ( !v7->_Isnil )
      {
        v14 = v7->_Right;
        if ( v14->_Isnil )
        {
          for ( i = v7->_Parent; !i->_Isnil; i = i->_Parent )
          {
            if ( v7 != i->_Right )
              break;
            v7 = i;
          }
          v7 = i;
        }
        else
        {
          v7 = v7->_Right;
          for ( j = v14->_Left; !j->_Isnil; j = j->_Left )
            v7 = j;
        }
      }
      if ( v7 == v3->surfaces._Myhead )
      {
        v4 = v28;
        goto LABEL_31;
      }
    }
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    std::wstring::assign(&_Right, &v7->_Myval.first, 0, 0xFFFFFFFF);
    qmemcpy(v32, &v7->_Myval.second, sizeof(v32));
    v9 = res._Mylast;
    LOBYTE(v33) = 2;
    if ( (std::pair<std::wstring,SurfaceDef> *)&_Right >= res._Mylast
      || res._Myfirst > (std::pair<std::wstring,SurfaceDef> *)&_Right )
    {
      if ( res._Mylast == res._Myend )
      {
        std::vector<std::pair<std::wstring,SurfaceDef>>::_Reserve(&res, 1u);
        v9 = res._Mylast;
      }
      if ( !v9 )
        goto LABEL_17;
      std::wstring::wstring(&v9->first, &_Right);
      v12 = &v9->second;
      v13 = v32;
    }
    else
    {
      v10 = ((char *)&_Right - (char *)res._Myfirst) / 212;
      if ( res._Mylast == res._Myend )
      {
        std::vector<std::pair<std::wstring,SurfaceDef>>::_Reserve(&res, 1u);
        v9 = res._Mylast;
      }
      v11 = &res._Myfirst[v10];
      if ( !v9 )
        goto LABEL_17;
      std::wstring::wstring(&v9->first, &res._Myfirst[v10].first);
      v12 = &v9->second;
      v13 = (char *)&v11->second;
    }
    v12->collisionCategory = 0;
    v12->damping = 0.0;
    v12->granularity = 0.0;
    v12->vibrationGain = 0.0;
    v12->vibrationLength = 1.5;
    qmemcpy(v12, v13, sizeof(SurfaceDef));
    v9 = res._Mylast;
LABEL_17:
    v5 = v9 + 1;
    LOBYTE(v33) = 1;
    res._Mylast = v5;
    if ( _Right._Myres >= 8 )
    {
      operator delete(_Right._Bx._Ptr);
      v5 = res._Mylast;
    }
    v3 = v27;
    goto LABEL_20;
  }
LABEL_31:
  v17 = res._Myfirst;
  if ( v5 - res._Myfirst == 1 )
  {
    v4->collisionCategory = 0;
    v4->damping = 0.0;
    v4->granularity = 0.0;
    v4->vibrationGain = 0.0;
    v4->vibrationLength = 1.5;
    LOBYTE(v33) = 0;
    qmemcpy(v4, &v17->second, sizeof(SurfaceDef));
    if ( v17 )
    {
      std::_Container_base0::_Orphan_all(&res);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::pair<std::wstring,SurfaceDef>>>>(
        res._Myfirst,
        res._Mylast);
      operator delete(res._Myfirst);
      res._Myfirst = 0;
      res._Mylast = 0;
      res._Myend = 0;
    }
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    v18 = v28;
  }
  else
  {
    if ( res._Myfirst == v5 )
    {
      v19 = &name;
      if ( name._Myres >= 8 )
        v19 = (std::wstring *)name._Bx._Ptr;
      _printf("ERROR: SURFACE NOT FOUND FOR OBJECT:%S\n", v19->_Bx._Buf);
      v20 = v27;
      if ( v27->enableCrash )
        ksGenerateCrash();
      v5 = res._Mylast;
    }
    else
    {
      v20 = v27;
    }
    if ( (unsigned int)(v5 - res._Myfirst) > 1 )
    {
      *(_DWORD *)v29.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v29.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v29.gap68);
      LOBYTE(v33) = 3;
      _Func.ss = (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)1;
      std::wiostream::basic_iostream<wchar_t>(&v29, &v29.gap10[8], 0);
      v33 = 4;
      *(_DWORD *)&v29.gap0[*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(SurfaceDef **)((char *)&v28 + *(_DWORD *)(*(_DWORD *)v29.gap0 + 4)) = (SurfaceDef *)(*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)
                                                                                           - 104);
      std::wstreambuf::wstreambuf(&v29.gap10[8]);
      *(_DWORD *)&v29.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v29.gap10[64] = 0;
      *(_DWORD *)&v29.gap10[68] = 0;
      LOBYTE(v33) = 6;
      v21 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v29.gap10, "ERROR: Mesh ");
      v22 = std::operator<<<wchar_t>(v21, &name);
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v22, " CAN BE:");
      _Func.ss = &v29;
      std::_For_each<std::pair<std::wstring,SurfaceDef> *,_lambda_95f350032d24590ba7f8ab2718cae5d7_>(
        res._Myfirst,
        res._Mylast,
        &_Func);
      v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v29, &v30);
      if ( v23->_Myres >= 8 )
        v23 = (std::wstring *)v23->_Bx._Ptr;
      _printf("%S\n", v23->_Bx._Buf);
      if ( v30._Myres >= 8 )
        operator delete(v30._Bx._Ptr);
      if ( v20->enableCrash )
        ksGenerateCrash();
      LOBYTE(v33) = 1;
      *(_DWORD *)&v29.gap0[*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(SurfaceDef **)((char *)&v28 + *(_DWORD *)(*(_DWORD *)v29.gap0 + 4)) = (SurfaceDef *)(*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)
                                                                                           - 104);
      *(_DWORD *)&v29.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v29.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v29.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v29.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v29.gap68);
    }
    v24 = v28;
    SurfaceDef::SurfaceDef(v28);
    LOBYTE(v33) = 0;
    if ( res._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&res);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::pair<std::wstring,SurfaceDef>>>>(
        res._Myfirst,
        res._Mylast);
      operator delete(res._Myfirst);
      res._Myfirst = 0;
      res._Mylast = 0;
      res._Myend = 0;
    }
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    v18 = v24;
  }
  return v18;
}
void SurfacesManager::loadSurfaceDefinitions(SurfacesManager *this, std::wstring filename)
{
  SurfacesManager *v2; // esi
  int v3; // ebx
  int v4; // ebp
  std::wostream *v5; // eax
  const std::wstring *v6; // eax
  bool v7; // bl
  const std::wstring *v8; // eax
  const std::wstring *v9; // eax
  const std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // ecx
  SurfaceDef *v13; // edx
  wchar_t v14; // ax
  const std::wstring *v15; // eax
  const std::wstring *v16; // eax
  const std::wstring *v17; // eax
  const std::wstring *v18; // eax
  const std::wstring *v19; // eax
  const std::wstring *v20; // eax
  const std::wstring *v21; // eax
  const std::wstring *v22; // eax
  const std::wstring *v23; // eax
  const std::wstring *v24; // eax
  SurfaceDef *v25; // eax
  bool v26; // zf
  std::wstring *v27; // eax
  int v28; // [esp+18h] [ebp-228h]
  SurfacesManager *v29; // [esp+1Ch] [ebp-224h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v30; // [esp+20h] [ebp-220h] BYREF
  std::wstring v31; // [esp+D0h] [ebp-170h] BYREF
  std::wstring v32; // [esp+E8h] [ebp-158h] BYREF
  std::wstring result; // [esp+100h] [ebp-140h] BYREF
  std::wstring key; // [esp+118h] [ebp-128h] BYREF
  INIReader r; // [esp+130h] [ebp-110h] BYREF
  SurfaceDef sd; // [esp+174h] [ebp-CCh] BYREF
  int v37; // [esp+23Ch] [ebp-4h]

  v2 = this;
  v29 = this;
  v3 = 0;
  v37 = 0;
  INIReader::INIReader(&r, &filename);
  LOBYTE(v37) = 1;
  if ( r.ready )
  {
    v4 = 0;
    do
    {
      *(_DWORD *)v30.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v30.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v30.gap68);
      LOBYTE(v37) = 2;
      v28 = v3 | 1;
      std::wiostream::basic_iostream<wchar_t>(&v30, &v30.gap10[8], 0);
      v37 = 3;
      *(_DWORD *)&v30.gap0[*(_DWORD *)(*(_DWORD *)v30.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(SurfacesManager **)((char *)&v29 + *(_DWORD *)(*(_DWORD *)v30.gap0 + 4)) = (SurfacesManager *)(*(_DWORD *)(*(_DWORD *)v30.gap0 + 4) - 104);
      std::wstreambuf::wstreambuf(&v30.gap10[8]);
      *(_DWORD *)&v30.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v30.gap10[64] = 0;
      *(_DWORD *)&v30.gap10[68] = 0;
      LOBYTE(v37) = 5;
      v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v30.gap10, "SURFACE_");
      std::wostream::operator<<(v5, v4);
      v6 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &key);
      LOBYTE(v37) = 6;
      v7 = INIReader::hasSection(&r, v6);
      LOBYTE(v37) = 5;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v7 )
      {
        SurfaceDef::SurfaceDef(&sd);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"DIRT_ADDITIVE", 0xDu);
        LOBYTE(v37) = 7;
        v8 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &result);
        LOBYTE(v37) = 8;
        sd.dirtAdditiveK = INIReader::getFloat(&r, v8, &v31);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"FRICTION", 8u);
        LOBYTE(v37) = 9;
        v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &result);
        LOBYTE(v37) = 10;
        sd.gripMod = INIReader::getFloat(&r, v9, &v31);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        sd.collisionCategory = 1;
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"WAV", 3u);
        LOBYTE(v37) = 11;
        v10 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 12;
        v11 = INIReader::getString(&r, &result, v10, &v31);
        v12 = v11;
        if ( v11->_Myres >= 8 )
          v12 = (std::wstring *)v11->_Bx._Ptr;
        v13 = &sd;
        do
        {
          v14 = v12->_Bx._Buf[0];
          v12 = (std::wstring *)((char *)v12 + 2);
          v13->wavString[0] = v14;
          v13 = (SurfaceDef *)((char *)v13 + 2);
        }
        while ( v14 );
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"WAV_PITCH", 9u);
        LOBYTE(v37) = 13;
        v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 14;
        sd.wavPitchSpeed = INIReader::getFloat(&r, v15, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"BLACK_FLAG_TIME", 0xFu);
        LOBYTE(v37) = 15;
        v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 16;
        sd.blackFlagTime = INIReader::getFloat(&r, v16, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"IS_VALID_TRACK", 0xEu);
        LOBYTE(v37) = 17;
        v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 18;
        sd.isValidTrack = INIReader::getInt(&r, v17, &v31) != 0;
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"SIN_HEIGHT", 0xAu);
        LOBYTE(v37) = 19;
        v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 20;
        sd.sinHeight = INIReader::getFloat(&r, v18, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"SIN_LENGTH", 0xAu);
        LOBYTE(v37) = 21;
        v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 22;
        sd.sinLength = INIReader::getFloat(&r, v19, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"IS_PITLANE", 0xAu);
        LOBYTE(v37) = 23;
        v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 24;
        sd.isPitlane = INIReader::getInt(&r, v20, &v31) != 0;
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"DAMPING", 7u);
        LOBYTE(v37) = 25;
        v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 26;
        sd.damping = INIReader::getFloat(&r, v21, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"VIBRATION_GAIN", 0xEu);
        LOBYTE(v37) = 27;
        v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 28;
        sd.vibrationGain = INIReader::getFloat(&r, v22, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"VIBRATION_LENGTH", 0x10u);
        LOBYTE(v37) = 29;
        v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 30;
        sd.vibrationLength = INIReader::getFloat(&r, v23, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 5;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        std::wstring::assign(&v31, L"KEY", 3u);
        LOBYTE(v37) = 31;
        v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v30, &v32);
        LOBYTE(v37) = 32;
        INIReader::getString(&r, &key, v24, &v31);
        if ( v32._Myres >= 8 )
          operator delete(v32._Bx._Ptr);
        v32._Myres = 7;
        v32._Mysize = 0;
        v32._Bx._Buf[0] = 0;
        LOBYTE(v37) = 35;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Bx._Buf[0] = 0;
        v31._Mysize = 0;
        v25 = std::map<std::wstring,SurfaceDef>::operator[](&v2->surfaces, &key);
        qmemcpy(v25, &sd, sizeof(SurfaceDef));
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        v2 = v29;
      }
      ++v4;
      LOBYTE(v37) = 1;
      *(_DWORD *)&v30.gap0[*(_DWORD *)(*(_DWORD *)v30.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(SurfacesManager **)((char *)&v29 + *(_DWORD *)(*(_DWORD *)v30.gap0 + 4)) = (SurfacesManager *)(*(_DWORD *)(*(_DWORD *)v30.gap0 + 4) - 104);
      *(_DWORD *)&v30.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v30.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v30.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v30.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v30.gap68);
      v26 = !v7;
      v3 = v28;
    }
    while ( !v26 );
  }
  else
  {
    v27 = &filename;
    if ( filename._Myres >= 8 )
      v27 = (std::wstring *)filename._Bx._Ptr;
    _printf("WARNING: Surface definition file %S not found\n", v27->_Bx._Buf);
  }
  LOBYTE(v37) = 0;
  INIReader::~INIReader(&r);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
