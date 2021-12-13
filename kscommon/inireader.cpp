#include "inireader.h"
void INIReader::INIReader(INIReader *this, const INIReader *__that)
{
  INIReader *v2; // edi
  const INIReader *v3; // esi
  std::wstring *v4; // ecx

  v2 = this;
  v3 = __that;
  v4 = &this->filename;
  this->__vftable = (INIReader_vtbl *)&INIReader::`vftable';
  v2->ready = v3->ready;
  v2->suppressErrorReporting = v3->suppressErrorReporting;
  v4->_Myres = 7;
  v4->_Mysize = 0;
  v4->_Bx._Buf[0] = 0;
  std::wstring::assign(v4, &v3->filename, 0, 0xFFFFFFFF);
  std::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>(
    &v2->sections,
    &v3->sections,
    (const std::allocator<std::pair<std::wstring const ,INISection> > *)&__that);
  v2->m_isEncrypted = v3->m_isEncrypted;
  v2->verbose = v3->verbose;
  v2->code._Myres = 7;
  v2->code._Mysize = 0;
  v2->code._Bx._Buf[0] = 0;
  std::wstring::assign(&v2->code, &v3->code, 0, 0xFFFFFFFF);
}
INIReader *INIReader::operator=(INIReader *this, const INIReader *__that)
{
  std::wstring *v3; // ecx
  std::map<std::wstring,INISection> *v4; // ebx

  v3 = &this->filename;
  this->ready = __that->ready;
  this->suppressErrorReporting = __that->suppressErrorReporting;
  if ( v3 != &__that->filename )
    std::wstring::assign(v3, &__that->filename, 0, 0xFFFFFFFF);
  v4 = &this->sections;
  if ( &this->sections != &__that->sections )
  {
    std::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::_Erase(
      &this->sections,
      v4->_Myhead->_Parent);
    v4->_Myhead->_Parent = v4->_Myhead;
    v4->_Myhead->_Left = v4->_Myhead;
    v4->_Myhead->_Right = v4->_Myhead;
    this->sections._Mysize = 0;
    std::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::_Copy<std::integral_constant<bool,0>>(
      &this->sections,
      &__that->sections,
      0);
  }
  this->m_isEncrypted = __that->m_isEncrypted;
  this->verbose = __that->verbose;
  if ( &this->code != &__that->code )
    std::wstring::assign(&this->code, &__that->code, 0, 0xFFFFFFFF);
  return this;
}
INIReader *INIReader::`scalar deleting destructor'(INIReader *this, unsigned int a2)
{
  INIReader::~INIReader(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
std::wstring *INIReader::getFileName(INIReader *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->filename, 0, 0xFFFFFFFF);
  return result;
}
void INIReader::INIReader(INIReader *this)
{
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::map<std::wstring,INISection> >> > *v2; // ecx
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v3; // eax

  this->__vftable = (INIReader_vtbl *)&INIReader::`vftable';
  *(_WORD *)&this->ready = 0;
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  v2 = (std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::map<std::wstring,INISection> >> > *)&this->sections;
  v2->_Myhead = 0;
  this->sections._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<enum SessionType const,ReplayAutosave>>>::_Buyheadnode(v2);
  this->sections._Myhead = v3;
  *(_WORD *)&this->m_isEncrypted = 0;
  this->code._Myres = 7;
  this->code._Mysize = 0;
  this->code._Bx._Buf[0] = 0;
  *(_WORD *)&this->ready = 0;
}
void INIReader::INIReader(INIReader *this, const std::wstring *ifilename)
{
  const std::wstring *v3; // esi
  std::wstring *v4; // ebp
  std::map<std::wstring,INISection> *v5; // ebx
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v6; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> *v7; // esi
  std::map<std::wstring,INISection> *v8; // esi
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  std::map<std::wstring,INISection> *v11; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > > > result; // [esp+18h] [ebp-60h] BYREF
  INIReader *v13; // [esp+1Ch] [ebp-5Ch]
  std::wstring v14; // [esp+20h] [ebp-58h] BYREF
  std::wstring crfn; // [esp+38h] [ebp-40h] BYREF
  std::wstring v16; // [esp+50h] [ebp-28h] BYREF
  int v17; // [esp+74h] [ebp-4h]

  v3 = ifilename;
  v4 = &this->filename;
  this->__vftable = (INIReader_vtbl *)&INIReader::`vftable';
  *(_WORD *)&this->ready = 0;
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  v13 = this;
  this->filename._Bx._Buf[0] = 0;
  v5 = &this->sections;
  v17 = 0;
  this->sections._Myhead = 0;
  this->sections._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<enum SessionType const,ReplayAutosave>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::map<std::wstring,INISection> >> > *)&this->sections);
  v5->_Myhead = v6;
  *(_WORD *)&this->m_isEncrypted = 0;
  this->code._Myres = 7;
  this->code._Mysize = 0;
  this->code._Bx._Buf[0] = 0;
  LOBYTE(v17) = 2;
  if ( v4 != ifilename )
    std::wstring::assign(v4, ifilename, 0, 0xFFFFFFFF);
  if ( INIReader::useCache )
  {
    v7 = INIReader::cache._Myhead;
    if ( (std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> *)std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::find((std::_Tree<std::_Tmap_traits<std::wstring,enum DynamicControllerInput,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,enum DynamicControllerInput> >,0> > *)&INIReader::cache, &result, v4)->_Ptr != v7 )
    {
      v8 = std::map<std::wstring,std::map<std::wstring,INISection>>::operator[](&INIReader::cache, v4);
      if ( v5 != v8 )
      {
        std::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::_Erase(
          v5,
          v5->_Myhead->_Parent);
        v5->_Myhead->_Parent = v5->_Myhead;
        v5->_Myhead->_Left = v5->_Myhead;
        v5->_Myhead->_Right = v5->_Myhead;
        v5->_Mysize = 0;
        std::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::_Copy<std::integral_constant<bool,0>>(
          v5,
          v8,
          0);
      }
      this->ready = 1;
      return;
    }
    v3 = ifilename;
  }
  v9 = Path::getPath(&v14, v3);
  LOBYTE(v17) = 3;
  std::operator+<wchar_t>(&crfn, v9, L".acd");
  LOBYTE(v17) = 5;
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
  v14._Myres = 7;
  v14._Bx._Buf[0] = 0;
  v14._Mysize = 0;
  if ( Path::fileExists((unsigned int)v5, &crfn, 0) )
  {
    v10 = Path::getFileName(&v16, v3);
    LOBYTE(v17) = 6;
    INIReader::loadEncrypt(this, v10, &crfn);
    LOBYTE(v17) = 5;
    if ( v16._Myres >= 8 )
      operator delete(v16._Bx._Ptr);
    this->m_isEncrypted = 1;
  }
  else
  {
    INIReader::load(this, v4);
  }
  if ( this->ready && INIReader::useCache )
  {
    v11 = std::map<std::wstring,std::map<std::wstring,INISection>>::operator[](&INIReader::cache, v4);
    std::map<std::wstring,INISection>::operator=(v11, v5);
  }
  if ( crfn._Myres >= 8 )
    operator delete(crfn._Bx._Ptr);
}
void INIReader::INIReader(INIReader *this, const std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *stream)
{
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::map<std::wstring,INISection> >> > *v3; // ecx
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v4; // eax
  std::wstring *v5; // esi
  std::wstring *v6; // edi
  std::wstring result; // [esp+14h] [ebp-28h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  this->__vftable = (INIReader_vtbl *)&INIReader::`vftable';
  *(_WORD *)&this->ready = 0;
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  v3 = (std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::map<std::wstring,INISection> >> > *)&this->sections;
  v8 = 0;
  v3->_Myhead = 0;
  this->sections._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<enum SessionType const,ReplayAutosave>>>::_Buyheadnode(v3);
  this->sections._Myhead = v4;
  v5 = &this->code;
  *(_WORD *)&this->m_isEncrypted = 0;
  this->code._Myres = 7;
  this->code._Mysize = 0;
  this->code._Bx._Buf[0] = 0;
  LOBYTE(v8) = 2;
  v6 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
         (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)stream,
         &result);
  if ( &this->code != v6 )
  {
    if ( this->code._Myres >= 8 )
      operator delete(v5->_Bx._Ptr);
    this->code._Myres = 7;
    this->code._Mysize = 0;
    v5->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->code, v6);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  INIReader::parse(this);
}
void INIReader::~INIReader(INIReader *this)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,INISection> > > > result; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (INIReader_vtbl *)&INIReader::`vftable';
  if ( this->code._Myres >= 8 )
    operator delete(this->code._Bx._Ptr);
  this->code._Myres = 7;
  this->code._Mysize = 0;
  this->code._Bx._Buf[0] = 0;
  std::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::erase(
    &this->sections,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,INISection> > > >)this->sections._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,INISection> > > >)this->sections._Myhead);
  operator delete(this->sections._Myhead);
  if ( this->filename._Myres >= 8 )
    operator delete(this->filename._Bx._Ptr);
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
}
void INIReader::errorReport(INIReader *this, std::wstring message)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // ecx
  std::wstring *v6; // eax
  std::wstring v7; // [esp-Ch] [ebp-64h] BYREF
  std::wstring v8; // [esp+18h] [ebp-40h] BYREF
  std::wstring result; // [esp+30h] [ebp-28h] BYREF
  int v10; // [esp+54h] [ebp-4h]

  v10 = 0;
  if ( INIReader::errorHandler && !this->suppressErrorReporting )
  {
    v3 = std::operator+<wchar_t>(&result, L"INIReader: ", &this->filename);
    LOBYTE(v10) = 1;
    v4 = std::operator+<wchar_t>(&v8, v3, L" > ");
    LOBYTE(v10) = 2;
    std::operator+<wchar_t>(&v7, v4, &message);
    ((void (*)(IErrorHandler *, wchar_t *, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int))INIReader::errorHandler->writeLine)(
      INIReader::errorHandler,
      v7._Bx._Ptr,
      *(_DWORD *)&v7._Bx._Alias[4],
      *(_DWORD *)&v7._Bx._Alias[8],
      *(_DWORD *)&v7._Bx._Alias[12],
      v7._Mysize,
      v7._Myres);
    if ( v8._Myres >= 8 )
      operator delete(v8._Bx._Ptr);
    v8._Myres = 7;
    v8._Mysize = 0;
    v8._Bx._Buf[0] = 0;
    LOBYTE(v10) = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  if ( INIReader::crashAtError )
  {
    v5 = &message;
    v6 = &this->filename;
    if ( message._Myres >= 8 )
      v5 = (std::wstring *)message._Bx._Ptr;
    if ( this->filename._Myres >= 8 )
      v6 = (std::wstring *)v6->_Bx._Ptr;
    _printf("INIReader Error: %S > %S\n", v6->_Bx._Buf, v5->_Bx._Buf);
    ksGenerateCrash();
  }
  if ( message._Myres >= 8 )
    operator delete(message._Bx._Ptr);
}
Curve *INIReader::getCurve(INIReader *this, Curve *result, const std::wstring *section, const std::wstring *key)
{
  std::wstring *v4; // ebx
  Curve *v5; // ebp
  int v6; // edi
  int v7; // esi
  std::wstring *v8; // esi
  std::wstring *v9; // esi
  std::wstring *v10; // edi
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  bool v16; // cf
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  const wchar_t *v19; // eax
  wchar_t _Ptr[2]; // [esp+20h] [ebp-164h] BYREF
  std::vector<std::wstring> splits; // [esp+24h] [ebp-160h] BYREF
  int v23; // [esp+30h] [ebp-154h]
  Curve *v24; // [esp+34h] [ebp-150h]
  float ref; // [esp+38h] [ebp-14Ch]
  Curve *v26; // [esp+3Ch] [ebp-148h]
  std::wstring *_Right; // [esp+40h] [ebp-144h]
  float val; // [esp+44h] [ebp-140h]
  std::wstring *v29; // [esp+48h] [ebp-13Ch]
  wchar_t *EndPtr; // [esp+4Ch] [ebp-138h] BYREF
  std::vector<std::wstring> sv; // [esp+50h] [ebp-134h] BYREF
  int v32; // [esp+60h] [ebp-124h]
  unsigned int v33; // [esp+64h] [ebp-120h]
  std::wstring code; // [esp+68h] [ebp-11Ch] BYREF
  std::wstring v35; // [esp+80h] [ebp-104h] BYREF
  std::wstring v36; // [esp+98h] [ebp-ECh] BYREF
  std::wstring v37; // [esp+B0h] [ebp-D4h] BYREF
  std::wstring splitter; // [esp+C8h] [ebp-BCh] BYREF
  std::wstring v39; // [esp+E0h] [ebp-A4h] BYREF
  std::wstring v40; // [esp+F8h] [ebp-8Ch] BYREF
  std::wstring v41; // [esp+110h] [ebp-74h] BYREF
  Curve res; // [esp+128h] [ebp-5Ch] BYREF
  int v43; // [esp+180h] [ebp-4h]

  v4 = (std::wstring *)this;
  v5 = result;
  _Right = (std::wstring *)section;
  v29 = (std::wstring *)key;
  v26 = result;
  v24 = result;
  v23 = 0;
  INIReader::getString(this, &code, section, key);
  v43 = 1;
  *(_DWORD *)_Ptr = 40;
  v6 = std::wstring::find(&code, _Ptr, 0, 1u);
  *(_DWORD *)_Ptr = 41;
  v7 = std::wstring::find(&code, _Ptr, 0, 1u);
  Curve::Curve(&res);
  LOBYTE(v43) = 2;
  if ( v6 == -1 || v7 == -1 )
    goto $LN770;
  v8 = std::wstring::substr(&code, &v35, v6 + 1, v7 - v6 - 1);
  if ( &code != v8 )
  {
    if ( code._Myres >= 8 )
      operator delete(code._Bx._Ptr);
    code._Myres = 7;
    code._Mysize = 0;
    code._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&code, v8);
  }
  if ( v35._Myres >= 8 )
    operator delete(v35._Bx._Ptr);
  std::wstring::wstring(&splitter, L"|");
  LOBYTE(v43) = 8;
  ksSplitString(&splits, &code, &splitter);
  LOBYTE(v43) = 10;
  if ( splitter._Myres >= 8 )
    operator delete(splitter._Bx._Ptr);
  v9 = splits._Myfirst;
  v10 = splits._Mylast;
  splitter._Myres = 7;
  splitter._Mysize = 0;
  splitter._Bx._Buf[0] = 0;
  if ( splits._Myfirst == splits._Mylast )
  {
LABEL_41:
    Curve::Curve(v5, &res);
    v23 = 1;
    if ( splits._Myfirst )
    {
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(splits._Myfirst, splits._Mylast);
      operator delete(splits._Myfirst);
      splits._Myfirst = 0;
      splits._Mylast = 0;
      splits._Myend = 0;
    }
    goto LABEL_56;
  }
  v5 = (Curve *)__errno;
  while ( 1 )
  {
    v37._Myres = 7;
    v37._Mysize = 0;
    v37._Bx._Buf[0] = 0;
    std::wstring::assign(&v37, L"=", 1u);
    LOBYTE(v43) = 11;
    ksSplitString(&sv, v9, &v37);
    LOBYTE(v43) = 13;
    if ( v37._Myres >= 8 )
      operator delete(v37._Bx._Ptr);
    v37._Bx._Buf[0] = 0;
    v37._Myres = 7;
    v37._Mysize = 0;
    if ( sv._Mylast - sv._Myfirst != 2 )
    {
      v11 = std::operator+<wchar_t>(&v41, L"Error, the value in [", _Right);
      LOBYTE(v43) = 14;
      v12 = std::operator+<wchar_t>(&v35, v11, L"] ");
      LOBYTE(v43) = 15;
      v13 = std::operator+<wchar_t>(&v36, v12, v29);
      LOBYTE(v43) = 16;
      v14 = std::operator+<wchar_t>(&v39, v13, L" is not a valid curve, at value:");
      LOBYTE(v43) = 17;
      v15 = std::operator+<wchar_t>(&v40, v14, v9);
      v16 = v15->_Myres < 8;
      LOBYTE(v43) = 18;
      if ( !v16 )
        v15 = (std::wstring *)v15->_Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v15->_Bx._Buf);
      ksGenerateCrash();
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      v40._Myres = 7;
      v40._Mysize = 0;
      v40._Bx._Buf[0] = 0;
      if ( v39._Myres >= 8 )
        operator delete(v39._Bx._Ptr);
      v39._Myres = 7;
      v39._Mysize = 0;
      v39._Bx._Buf[0] = 0;
      if ( v36._Myres >= 8 )
        operator delete(v36._Bx._Ptr);
      v36._Myres = 7;
      v36._Mysize = 0;
      v36._Bx._Buf[0] = 0;
      if ( v35._Myres >= 8 )
        operator delete(v35._Bx._Ptr);
      v35._Myres = 7;
      v35._Mysize = 0;
      v35._Bx._Buf[0] = 0;
      if ( v41._Myres >= 8 )
        operator delete(v41._Bx._Ptr);
      goto LABEL_37;
    }
    v4 = sv._Myfirst + 1;
    if ( sv._Myfirst[1]._Myres >= 8 )
      v4 = (std::wstring *)v4->_Bx._Ptr;
    *__errno() = 0;
    val = _wcstod(v4->_Bx._Buf, (wchar_t **)_Ptr);
    if ( v4 == *(std::wstring **)_Ptr )
      goto $LN769;
    if ( *__errno() == 34 )
      break;
    v4 = sv._Myfirst;
    if ( sv._Myfirst->_Myres >= 8 )
      v4 = (std::wstring *)sv._Myfirst->_Bx._Ptr;
    *__errno() = 0;
    ref = _wcstod(v4->_Bx._Buf, &EndPtr);
    if ( v4 == (std::wstring *)EndPtr )
      goto $LN769;
    if ( *__errno() == 34 )
      break;
    Curve::addValue(&res, ref, val);
LABEL_37:
    LOBYTE(v43) = 10;
    if ( sv._Myfirst )
    {
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(sv._Myfirst, sv._Mylast);
      operator delete(sv._Myfirst);
      sv._Myfirst = 0;
      sv._Mylast = 0;
      sv._Myend = 0;
    }
    if ( ++v9 == v10 )
    {
      v5 = v26;
      goto LABEL_41;
    }
  }
  std::_Xout_of_range("stof argument out of range");
$LN769:
  std::_Xinvalid_argument("invalid stof argument");
$LN770:
  v17 = Path::getPath(&v36, (const std::wstring *)&v4->_Bx._Alias[8]);
  LOBYTE(v43) = 3;
  v18 = std::operator+<wchar_t>(&v35, v17, L"/");
  LOBYTE(v43) = 4;
  std::operator+<wchar_t>((std::wstring *)&sv, v18, &code);
  if ( v35._Myres >= 8 )
    operator delete(v35._Bx._Ptr);
  v35._Myres = 7;
  v35._Mysize = 0;
  v35._Bx._Buf[0] = 0;
  LOBYTE(v43) = 7;
  if ( v36._Myres >= 8 )
    operator delete(v36._Bx._Ptr);
  v36._Myres = 7;
  v36._Bx._Buf[0] = 0;
  v36._Mysize = 0;
  if ( Path::fileExists((unsigned int)v4, (const std::wstring *)&sv, 0) )
  {
    v19 = (const wchar_t *)&sv;
    if ( v33 >= 8 )
      v19 = sv._Myfirst->_Bx._Buf;
    _printf("Loading curve from:%S\n", v19);
    Curve::load(&res, (const std::wstring *)&sv);
  }
  Curve::Curve(v5, &res);
  v23 = 1;
  if ( v33 >= 8 )
    operator delete(sv._Myfirst);
  v33 = 7;
  v32 = 0;
  LOWORD(sv._Myfirst) = 0;
LABEL_56:
  LOBYTE(v43) = 1;
  Curve::~Curve(&res);
  if ( code._Myres >= 8 )
    operator delete(code._Bx._Ptr);
  return v5;
}
vec2f *INIReader::getFloat2(INIReader *this, vec2f *result, const std::wstring *section, const std::wstring *key)
{
  result->y = 0.0;
  result->x = 0.0;
  INIReader::getVector2(this, section, key, &result->x, &result->y);
  return result;
}
vec3f *INIReader::getFloat3(INIReader *this, vec3f *result, const std::wstring *section, const std::wstring *key)
{
  const std::wstring *v4; // ebx
  const std::wstring *v5; // ebp

  v4 = key;
  v5 = section;
  result->y = 0.0;
  result->z = 0.0;
  result->x = 0.0;
  INIReader::getVector3(this, section, key, &result->x, &result->y, &result->z);
  if ( this->verbose )
  {
    if ( key->_Myres >= 8 )
      v4 = (const std::wstring *)key->_Bx._Ptr;
    if ( section->_Myres >= 8 )
      v5 = (const std::wstring *)section->_Bx._Ptr;
    _printf("[%S] %S: (%.3f,%.3f,%.3f)\n", v5->_Bx._Buf, v4->_Bx._Buf, result->x, result->y, result->z);
  }
  return result;
}
vec4f *INIReader::getFloat4(INIReader *this, vec4f *result, const std::wstring *section, const std::wstring *key)
{
  result->y = 0.0;
  result->w = 0.0;
  result->z = 0.0;
  result->x = 0.0;
  INIReader::getVector4(this, section, key, &result->x, &result->y, &result->z, &result->w);
  return result;
}
double INIReader::getFloat(INIReader *this, const std::wstring *section, const std::wstring *key)
{
  const std::wstring *v4; // ebx
  const std::wstring *v5; // edi
  unsigned int v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // esi
  wchar_t *v9; // xmm0_4
  std::wstring *v10; // esi
  wchar_t *EndPtr; // [esp+24h] [ebp-30h] BYREF
  wchar_t *v13; // [esp+28h] [ebp-2Ch] BYREF
  std::wstring v; // [esp+2Ch] [ebp-28h] BYREF
  int v15; // [esp+50h] [ebp-4h]

  v4 = key;
  v5 = section;
  INIReader::getString(this, &v, section, key);
  v6 = v._Mysize;
  v15 = 0;
  if ( v._Mysize == 1 )
  {
    v7 = &v;
    if ( v._Myres >= 8 )
      v7 = (std::wstring *)v._Bx._Ptr;
    if ( _isspace(v7->_Bx._Buf[0]) )
    {
      *(float *)&EndPtr = 0.0;
      goto LABEL_30;
    }
    v6 = v._Mysize;
  }
  if ( this->verbose )
  {
    if ( !v6 )
      goto LABEL_21;
    v8 = &v;
    if ( v._Myres >= 8 )
      v8 = (std::wstring *)v._Bx._Ptr;
    *__errno() = 0;
    *(float *)&v13 = _wcstod(v8->_Bx._Buf, &EndPtr);
    if ( v8 == (std::wstring *)EndPtr )
      std::_Xinvalid_argument("invalid stof argument");
    if ( *__errno() == 34 )
      std::_Xout_of_range("stof argument out of range");
    if ( key->_Myres >= 8 )
      v4 = (const std::wstring *)key->_Bx._Ptr;
    if ( section->_Myres >= 8 )
      v5 = (const std::wstring *)section->_Bx._Ptr;
    _printf("[%S] %S: %f\n", v5->_Bx._Buf, v4->_Bx._Buf, *(float *)&v13);
    v6 = v._Mysize;
  }
  if ( v6 )
  {
    v10 = &v;
    if ( v._Myres >= 8 )
      v10 = (std::wstring *)v._Bx._Ptr;
    *__errno() = 0;
    *(float *)&EndPtr = _wcstod(v10->_Bx._Buf, &v13);
    if ( v10 == (std::wstring *)v13 )
      std::_Xinvalid_argument("invalid stof argument");
    if ( *__errno() == 34 )
      std::_Xout_of_range("stof argument out of range");
    v9 = EndPtr;
    goto LABEL_29;
  }
LABEL_21:
  v9 = 0;
LABEL_29:
  EndPtr = v9;
LABEL_30:
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
  return *(float *)&EndPtr;
}
int INIReader::getHex(INIReader *this, const std::wstring *section, const std::wstring *key)
{
  const std::wstring *v4; // esi
  const std::wstring *v5; // edi
  const std::wstring *v6; // eax
  std::wstring *v7; // eax
  int v8; // eax
  bool v9; // bl
  int v10; // esi
  int v11; // eax
  unsigned int v13; // [esp-Ch] [ebp-104h]
  int myHex; // [esp+18h] [ebp-E0h] BYREF
  int v15; // [esp+1Ch] [ebp-DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v16; // [esp+20h] [ebp-D8h] BYREF
  std::wstring result; // [esp+D0h] [ebp-28h] BYREF
  int v18; // [esp+F4h] [ebp-4h]

  v4 = section;
  v5 = key;
  *(_DWORD *)v16.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v16.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  *(_DWORD *)v16.gap68 = std::wios::`vftable';
  v18 = 0;
  v15 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v16, &v16.gap10[8], 0);
  v18 = 1;
  *(_DWORD *)&v16.gap0[*(_DWORD *)(*(_DWORD *)v16.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v15 + *(_DWORD *)(*(_DWORD *)v16.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v16.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v16.gap10[8]);
  *(_DWORD *)&v16.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v16.gap10[64] = 0;
  *(_DWORD *)&v16.gap10[68] = 0;
  v18 = 3;
  v6 = INIReader::getString(this, &result, section, key);
  LOBYTE(v18) = 4;
  std::operator<<<wchar_t>((std::wostream *)v16.gap10, v6);
  LOBYTE(v18) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v7 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v16, &result);
  v13 = v7->_Mysize;
  LOBYTE(v18) = 5;
  v8 = std::wstring::compare(v7, 0, v13, word_17BE9D8, 0);
  LOBYTE(v18) = 3;
  v9 = v8 == 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( v9 )
  {
    v10 = -1;
  }
  else
  {
    v11 = std::wistream::operator>>(&v16, std::hex, &myHex);
    std::wistream::operator>>(v11);
    if ( this->verbose )
    {
      if ( key->_Myres >= 8 )
        v5 = (const std::wstring *)key->_Bx._Ptr;
      if ( section->_Myres >= 8 )
        v4 = (const std::wstring *)section->_Bx._Ptr;
      _printf("[%S] %S: %d\n", v4->_Bx._Buf, v5->_Bx._Buf, myHex);
    }
    v10 = myHex;
  }
  *(_DWORD *)&v16.gap0[*(_DWORD *)(*(_DWORD *)v16.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v15 + *(_DWORD *)(*(_DWORD *)v16.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v16.gap0 + 4) - 104;
  *(_DWORD *)&v16.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v16.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v16.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v16.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v16.gap68);
  return v10;
}
int INIReader::getInt(INIReader *this, const std::wstring *section, const std::wstring *key)
{
  const std::wstring *v4; // edi
  const std::wstring *v5; // esi
  int v6; // edi
  int v7; // eax
  std::wstring *v8; // esi
  wchar_t *EndPtr; // [esp+10h] [ebp-2Ch] BYREF
  std::wstring v; // [esp+14h] [ebp-28h] BYREF
  _EXCEPTION_REGISTRATION_RECORD *v12; // [esp+30h] [ebp-Ch]
  void *v13; // [esp+34h] [ebp-8h]
  int v14; // [esp+38h] [ebp-4h]

  v14 = -1;
  v13 = &_ehhandler__getInt_INIReader__QAEHABV__basic_string__WU__char_traits__W_std__V__allocator__W_2__std__0_Z;
  v12 = NtCurrentTeb()->NtTib.ExceptionList;
  v4 = key;
  v5 = section;
  INIReader::getString(this, &v, section, key);
  v14 = 0;
  if ( v._Mysize )
  {
    if ( this->verbose )
    {
      if ( key->_Myres >= 8 )
        v4 = (const std::wstring *)key->_Bx._Ptr;
      if ( section->_Myres >= 8 )
        v5 = (const std::wstring *)section->_Bx._Ptr;
      v7 = std::stoi(&v, 0, 10);
      _printf("[%S] %S: %d\n", v5->_Bx._Buf, v4->_Bx._Buf, v7);
    }
    v8 = &v;
    if ( v._Myres >= 8 )
      v8 = (std::wstring *)v._Bx._Ptr;
    *__errno() = 0;
    v6 = _wcstol(v8->_Bx._Buf, &EndPtr, 10);
    if ( v8 == (std::wstring *)EndPtr )
      std::_Xinvalid_argument((const char *)&stru_17C4688);
    if ( *__errno() == 34 )
    {
      std::_Xout_of_range((const char *)&stru_17C4688.name._Myres);
      JUMPOUT(0x718703);
    }
  }
  else
  {
    v6 = 0;
  }
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
  return v6;
}
void INIReader::getKeyes(INIReader *this, std::wstring section, std::vector<std::wstring> *keyes)
{
  std::vector<std::wstring> *v3; // ebp
  INISection *v4; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *v5; // edi
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *v6; // esi
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *v7; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *k; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *j; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > > v10; // [esp-8h] [ebp-6Ch]
  std::allocator<std::pair<std::wstring const ,std::wstring > > v11; // [esp+17h] [ebp-4Dh] BYREF
  INISection el; // [esp+18h] [ebp-4Ch] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > > result; // [esp+20h] [ebp-44h] BYREF
  std::pair<std::wstring const ,std::wstring > i; // [esp+24h] [ebp-40h] BYREF
  int v15; // [esp+60h] [ebp-4h]

  v3 = keyes;
  v15 = 0;
  v4 = std::map<std::wstring,INISection>::operator[](&this->sections, &section);
  std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>(
    &el.keys,
    &v4->keys,
    &v11);
  v5 = el.keys._Myhead;
  LOBYTE(v15) = 1;
  v6 = el.keys._Myhead->_Left;
  if ( el.keys._Myhead->_Left != el.keys._Myhead )
  {
    do
    {
      i.first._Myres = 7;
      i.first._Mysize = 0;
      i.first._Bx._Buf[0] = 0;
      std::wstring::assign((std::wstring *)&i.first, &v6->_Myval.first, 0, 0xFFFFFFFF);
      LOBYTE(v15) = 2;
      i.second._Bx._Buf[0] = 0;
      i.second._Myres = 7;
      i.second._Mysize = 0;
      std::wstring::assign(&i.second, &v6->_Myval.second, 0, 0xFFFFFFFF);
      LOBYTE(v15) = 3;
      std::vector<std::wstring>::push_back(v3, &i.first);
      LOBYTE(v15) = 1;
      if ( i.second._Myres >= 8 )
        operator delete(i.second._Bx._Ptr);
      i.second._Myres = 7;
      i.second._Mysize = 0;
      i.second._Bx._Buf[0] = 0;
      if ( i.first._Myres >= 8 )
        operator delete(i.first._Bx._Ptr);
      if ( !v6->_Isnil )
      {
        v7 = v6->_Right;
        if ( v7->_Isnil )
        {
          for ( j = v6->_Parent; !j->_Isnil; j = j->_Parent )
          {
            if ( v6 != j->_Right )
              break;
            v6 = j;
          }
          v6 = j;
        }
        else
        {
          v6 = v6->_Right;
          for ( k = v7->_Left; !k->_Isnil; k = k->_Left )
            v6 = k;
        }
      }
    }
    while ( v6 != v5 );
    v5 = el.keys._Myhead;
  }
  v10._Ptr = (std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *)v5->_Left;
  LOBYTE(v15) = 0;
  std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TagDocumentText> >,0> > *)&el,
    &result,
    v10,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > >)v5);
  operator delete(el.keys._Myhead);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
}
void INIReader::getSections(INIReader *this, std::vector<std::wstring> *outSections)
{
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v2; // edi
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v3; // esi
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v4; // eax
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *j; // eax
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *i; // eax
  std::allocator<std::pair<std::wstring const ,std::wstring > > v7; // [esp+17h] [ebp-35h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > > result; // [esp+18h] [ebp-34h] BYREF
  std::pair<std::wstring const ,INISection> s; // [esp+1Ch] [ebp-30h] BYREF
  int v10; // [esp+48h] [ebp-4h]

  v2 = this->sections._Myhead;
  v3 = v2->_Left;
  while ( v3 != v2 )
  {
    s.first._Myres = 7;
    s.first._Mysize = 0;
    s.first._Bx._Buf[0] = 0;
    std::wstring::assign((std::wstring *)&s.first, &v3->_Myval.first, 0, 0xFFFFFFFF);
    v10 = 0;
    std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>(
      &s.second.keys,
      &v3->_Myval.second.keys,
      &v7);
    v10 = 1;
    std::vector<std::wstring>::push_back(outSections, &s.first);
    v10 = -1;
    std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>::erase(
      (std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TagDocumentText> >,0> > *)&s.second,
      &result,
      (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > >)s.second.keys._Myhead->_Left,
      (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > >)s.second.keys._Myhead);
    operator delete(s.second.keys._Myhead);
    if ( s.first._Myres >= 8 )
      operator delete(s.first._Bx._Ptr);
    if ( !v3->_Isnil )
    {
      v4 = v3->_Right;
      if ( v4->_Isnil )
      {
        for ( i = v3->_Parent; !i->_Isnil; i = i->_Parent )
        {
          if ( v3 != i->_Right )
            break;
          v3 = i;
        }
        v3 = i;
      }
      else
      {
        v3 = v3->_Right;
        for ( j = v4->_Left; !j->_Isnil; j = j->_Left )
          v3 = j;
      }
    }
  }
}
std::wstring *INIReader::getString(INIReader *this, std::wstring *result, const std::wstring *section, const std::wstring *key)
{
  std::map<std::wstring,INISection> *v4; // ebp
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v5; // edi
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v6; // eax
  int v7; // esi
  const wchar_t *v8; // eax
  INISection *v9; // eax
  INISection *v10; // eax
  const std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring v15; // [esp-18h] [ebp-80h] BYREF
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v16; // [esp+14h] [ebp-54h]
  std::wstring *_Keyval; // [esp+18h] [ebp-50h]
  std::wstring *k; // [esp+1Ch] [ebp-4Ch]
  INIReader *v19; // [esp+20h] [ebp-48h]
  int v20; // [esp+24h] [ebp-44h]
  std::wstring message; // [esp+28h] [ebp-40h] BYREF
  std::wstring v22; // [esp+40h] [ebp-28h] BYREF
  int v23; // [esp+64h] [ebp-4h]

  v19 = this;
  v4 = &this->sections;
  v5 = this->sections._Myhead;
  k = (std::wstring *)key;
  _Keyval = (std::wstring *)section;
  v20 = 0;
  v6 = std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
         (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->sections,
         section);
  v7 = (int)v6;
  if ( v6 == (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)v4->_Myhead )
    goto LABEL_6;
  v8 = v6->_Myval.first._Bx._Buf;
  if ( *(_DWORD *)(v7 + 36) >= 8u )
    v8 = *(const wchar_t **)v8;
  if ( std::wstring::compare(_Keyval, 0, _Keyval->_Mysize, v8, *(_DWORD *)(v7 + 32)) < 0 )
LABEL_6:
    v16 = v4->_Myhead;
  else
    v16 = (std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *)v7;
  if ( v16 == v5 || (v9 = std::map<std::wstring,INISection>::operator[](v4, _Keyval), !INISection::hasKey(v9, k)) )
  {
    v12 = std::operator+<wchar_t>(&v22, L"KEY_NOT_FOUND: [", _Keyval);
    v23 = 0;
    v13 = std::operator+<wchar_t>(&message, v12, L"] ");
    LOBYTE(v23) = 1;
    std::operator+<wchar_t>(&v15, v13, k);
    INIReader::errorReport(v19, v15);
    if ( message._Myres >= 8 )
      operator delete(message._Bx._Ptr);
    message._Myres = 7;
    message._Mysize = 0;
    message._Bx._Buf[0] = 0;
    v23 = -1;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    result->_Myres = 7;
    v15._Myres = 0;
    result->_Mysize = 0;
    v15._Mysize = (unsigned int)word_17BE9D8;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, (const wchar_t *)v15._Mysize, v15._Myres);
  }
  else
  {
    v10 = std::map<std::wstring,INISection>::operator[](v4, _Keyval);
    v11 = std::map<std::wstring,std::wstring>::operator[](&v10->keys, k);
    result->_Myres = 7;
    v15._Myres = -1;
    v15._Mysize = 0;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, v11, v15._Mysize, v15._Myres);
  }
  return result;
}
void INIReader::getVector2(INIReader *this, const std::wstring *section, const std::wstring *key, float *x, float *y)
{
  std::wstring *v5; // eax
  wchar_t *v6; // esi
  unsigned int v7; // ecx
  std::wstring *v8; // esi
  bool v9; // cf
  wchar_t *v10; // edx
  unsigned int v11; // ecx
  std::wstring *v12; // esi
  wchar_t *EndPtr; // [esp+14h] [ebp-250h] BYREF
  wchar_t *v14; // [esp+18h] [ebp-24Ch] BYREF
  wchar_t *context; // [esp+1Ch] [ebp-248h] BYREF
  float *v16; // [esp+20h] [ebp-244h]
  std::wstring v17; // [esp+24h] [ebp-240h] BYREF
  std::wstring v; // [esp+3Ch] [ebp-228h] BYREF
  wchar_t buffer[256]; // [esp+54h] [ebp-210h] BYREF
  int v20; // [esp+260h] [ebp-4h]

  v16 = y;
  INIReader::getString(this, &v, section, key);
  v5 = &v;
  v20 = 0;
  if ( v._Myres >= 8 )
    v5 = (std::wstring *)v._Bx._Ptr;
  context = 0;
  _wcscpy_s(buffer, 0x100u, v5->_Bx._Buf);
  v6 = _wcstok_s(buffer, L",", &context);
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  if ( *v6 )
    v7 = wcslen(v6);
  else
    v7 = 0;
  std::wstring::assign(&v17, v6, v7);
  v8 = &v17;
  if ( v17._Myres >= 8 )
    v8 = (std::wstring *)v17._Bx._Ptr;
  LOBYTE(v20) = 1;
  *__errno() = 0;
  *(float *)&v14 = _wcstod(v8->_Bx._Buf, &EndPtr);
  if ( v8 == (std::wstring *)EndPtr )
    std::_Xinvalid_argument("invalid stof argument");
  if ( *__errno() == 34 )
    std::_Xout_of_range("stof argument out of range");
  v9 = v17._Myres < 8;
  *x = *(float *)&v14;
  LOBYTE(v20) = 0;
  if ( !v9 )
    operator delete(v17._Bx._Ptr);
  v10 = _wcstok_s(0, L",", &context);
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  if ( *v10 )
    v11 = wcslen(v10);
  else
    v11 = 0;
  std::wstring::assign(&v17, v10, v11);
  v12 = &v17;
  LOBYTE(v20) = 2;
  if ( v17._Myres >= 8 )
    v12 = (std::wstring *)v17._Bx._Ptr;
  *__errno() = 0;
  *(float *)&EndPtr = _wcstod(v12->_Bx._Buf, &v14);
  if ( v12 == (std::wstring *)v14 )
    std::_Xinvalid_argument("invalid stof argument");
  if ( *__errno() == 34 )
    std::_Xout_of_range("stof argument out of range");
  v9 = v17._Myres < 8;
  *v16 = *(float *)&EndPtr;
  if ( !v9 )
    operator delete(v17._Bx._Ptr);
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
}
void INIReader::getVector3(INIReader *this, const std::wstring *section, const std::wstring *key, float *x, float *y, float *z)
{
  const std::wstring *v7; // edi
  const std::wstring *v8; // esi
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  wchar_t *v12; // eax
  double v13; // st7
  bool v14; // cf
  wchar_t *v15; // eax
  double v16; // st7
  wchar_t *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring v24; // [esp-18h] [ebp-A60h] BYREF
  float *v25; // [esp+14h] [ebp-A34h]
  float *v26; // [esp+18h] [ebp-A30h]
  wchar_t *context; // [esp+1Ch] [ebp-A2Ch] BYREF
  std::wstring message; // [esp+20h] [ebp-A28h] BYREF
  std::wstring result; // [esp+38h] [ebp-A10h] BYREF
  std::wstring v; // [esp+50h] [ebp-9F8h] BYREF
  wchar_t buffer[1256]; // [esp+68h] [ebp-9E0h] BYREF
  int v32; // [esp+A44h] [ebp-4h]

  v7 = key;
  v8 = section;
  v26 = x;
  v25 = y;
  INIReader::getString(this, &v, section, key);
  v32 = 0;
  if ( v._Mysize )
  {
    context = 0;
    if ( v._Mysize < 0x4E8 )
    {
      v11 = &v;
      if ( v._Myres >= 8 )
        v11 = (std::wstring *)v._Bx._Ptr;
      _wcscpy_s(buffer, 0x4E8u, v11->_Bx._Buf);
      v12 = _wcstok_s(buffer, L",", &context);
      if ( v12 )
      {
        std::wstring::wstring(&message, v12);
        LOBYTE(v32) = 3;
        v13 = std::stof(&message, 0);
        v14 = message._Myres < 8;
        LOBYTE(v32) = 0;
        *v26 = v13;
        if ( !v14 )
          operator delete(message._Bx._Ptr);
        v15 = _wcstok_s(0, L",", &context);
        if ( v15 )
        {
          std::wstring::wstring(&result, v15);
          LOBYTE(v32) = 6;
          v16 = std::stof(&result, 0);
          LOBYTE(v32) = 0;
          *v25 = v16;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          v17 = _wcstok_s(0, L"\n\r", &context);
          if ( v17 )
          {
            std::wstring::wstring(&result, v17);
            LOBYTE(v32) = 9;
            *z = std::stof(&result, 0);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          }
          else
          {
            v24._Myres = (unsigned int)section;
            v24._Mysize = (unsigned int)L"NOT_3_ELEMENTS: [";
            *v26 = 0.0;
            *v25 = 0.0;
            *(_DWORD *)&v24._Bx._Alias[12] = &message;
            *z = 0.0;
            v18 = std::operator+<wchar_t>(
                    *(std::wstring **)&v24._Bx._Alias[12],
                    (const wchar_t *)v24._Mysize,
                    (const std::wstring *)v24._Myres);
            LOBYTE(v32) = 10;
            v19 = std::operator+<wchar_t>(&result, v18, L"] ");
            LOBYTE(v32) = 11;
            std::operator+<wchar_t>(&v24, v19, key);
            INIReader::errorReport(this, v24);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&message);
          }
        }
        else
        {
          v24._Myres = (unsigned int)section;
          v24._Mysize = (unsigned int)L"NOT_3_ELEMENTS: [";
          *v26 = 0.0;
          *v25 = 0.0;
          *(_DWORD *)&v24._Bx._Alias[12] = &message;
          *z = 0.0;
          v20 = std::operator+<wchar_t>(
                  *(std::wstring **)&v24._Bx._Alias[12],
                  (const wchar_t *)v24._Mysize,
                  (const std::wstring *)v24._Myres);
          LOBYTE(v32) = 7;
          v21 = std::operator+<wchar_t>(&result, v20, L"] ");
          LOBYTE(v32) = 8;
          std::operator+<wchar_t>(&v24, v21, key);
          INIReader::errorReport(this, v24);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&message);
        }
      }
      else
      {
        v24._Myres = (unsigned int)section;
        v24._Mysize = (unsigned int)L"NOT_3_ELEMENTS: [";
        *v26 = 0.0;
        *v25 = 0.0;
        *(_DWORD *)&v24._Bx._Alias[12] = &result;
        *z = 0.0;
        v22 = std::operator+<wchar_t>(
                *(std::wstring **)&v24._Bx._Alias[12],
                (const wchar_t *)v24._Mysize,
                (const std::wstring *)v24._Myres);
        LOBYTE(v32) = 4;
        v23 = std::operator+<wchar_t>(&message, v22, L"] ");
        LOBYTE(v32) = 5;
        std::operator+<wchar_t>(&v24, v23, key);
        INIReader::errorReport(this, v24);
        if ( message._Myres >= 8 )
          operator delete(message._Bx._Ptr);
        message._Myres = 7;
        message._Mysize = 0;
        message._Bx._Buf[0] = 0;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
    }
    else
    {
      v9 = std::operator+<wchar_t>(&result, L"STRING_LONGER_THAN_1256: [", section);
      LOBYTE(v32) = 1;
      v10 = std::operator+<wchar_t>(&message, v9, L"] ");
      LOBYTE(v32) = 2;
      std::operator+<wchar_t>(&v24, v10, key);
      INIReader::errorReport(this, v24);
      if ( message._Myres >= 8 )
        operator delete(message._Bx._Ptr);
      message._Myres = 7;
      message._Mysize = 0;
      message._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      if ( key->_Myres >= 8 )
        v7 = (const std::wstring *)key->_Bx._Ptr;
      if ( section->_Myres >= 8 )
        v8 = (const std::wstring *)section->_Bx._Ptr;
      _printf("ERROR: STRING_LONGER_THAN_1256 [%S] %S\n", v8->_Bx._Buf, v7->_Bx._Buf);
    }
  }
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
}
bool INIReader::getVector4(INIReader *this, const std::wstring *section, const std::wstring *key, float *x, float *y, float *z, float *w)
{
  std::wstring *v7; // eax
  wchar_t *v8; // edx
  unsigned int v9; // ecx
  std::wstring *v10; // esi
  bool v11; // cf
  wchar_t *v12; // edx
  unsigned int v13; // ecx
  std::wstring *v14; // esi
  wchar_t *v15; // edx
  unsigned int v16; // ecx
  std::wstring *v17; // esi
  wchar_t *v18; // edx
  unsigned int v19; // ecx
  std::wstring *v20; // esi
  bool v21; // bl
  wchar_t *v23; // [esp+1Ch] [ebp-258h] BYREF
  wchar_t *v24; // [esp+20h] [ebp-254h] BYREF
  wchar_t *context; // [esp+24h] [ebp-250h] BYREF
  wchar_t *v26; // [esp+28h] [ebp-24Ch] BYREF
  wchar_t *EndPtr; // [esp+2Ch] [ebp-248h] BYREF
  float *v28; // [esp+30h] [ebp-244h]
  std::wstring v29; // [esp+34h] [ebp-240h] BYREF
  std::wstring v; // [esp+4Ch] [ebp-228h] BYREF
  wchar_t buffer[256]; // [esp+64h] [ebp-210h] BYREF
  int v32; // [esp+270h] [ebp-4h]

  v24 = (wchar_t *)y;
  v26 = (wchar_t *)z;
  v28 = w;
  INIReader::getString(this, &v, section, key);
  v7 = &v;
  v32 = 0;
  if ( v._Myres >= 8 )
    v7 = (std::wstring *)v._Bx._Ptr;
  context = 0;
  _wcscpy_s(buffer, 0x100u, v7->_Bx._Buf);
  *x = 0.0;
  *y = 0.0;
  *z = 0.0;
  *w = 0.0;
  v8 = _wcstok_s(buffer, L",", &context);
  if ( v8 )
  {
    v29._Myres = 7;
    v29._Mysize = 0;
    v29._Bx._Buf[0] = 0;
    if ( *v8 )
      v9 = wcslen(v8);
    else
      v9 = 0;
    std::wstring::assign(&v29, v8, v9);
    v10 = &v29;
    LOBYTE(v32) = 1;
    if ( v29._Myres >= 8 )
      v10 = (std::wstring *)v29._Bx._Ptr;
    *__errno() = 0;
    *(float *)&v23 = _wcstod(v10->_Bx._Buf, &EndPtr);
    if ( v10 == (std::wstring *)EndPtr )
      std::_Xinvalid_argument("invalid stof argument");
    if ( *__errno() == 34 )
      std::_Xout_of_range("stof argument out of range");
    v11 = v29._Myres < 8;
    *x = *(float *)&v23;
    LOBYTE(v32) = 0;
    if ( !v11 )
      operator delete(v29._Bx._Ptr);
  }
  v12 = _wcstok_s(0, L",", &context);
  if ( v12 )
  {
    v29._Myres = 7;
    v29._Mysize = 0;
    v29._Bx._Buf[0] = 0;
    if ( *v12 )
      v13 = wcslen(v12);
    else
      v13 = 0;
    std::wstring::assign(&v29, v12, v13);
    v14 = &v29;
    LOBYTE(v32) = 2;
    if ( v29._Myres >= 8 )
      v14 = (std::wstring *)v29._Bx._Ptr;
    *__errno() = 0;
    *(float *)&EndPtr = _wcstod(v14->_Bx._Buf, &v23);
    if ( v14 == (std::wstring *)v23 )
      std::_Xinvalid_argument("invalid stof argument");
    if ( *__errno() == 34 )
      std::_Xout_of_range("stof argument out of range");
    v11 = v29._Myres < 8;
    LOBYTE(v32) = 0;
    *(float *)v24 = *(float *)&EndPtr;
    if ( !v11 )
      operator delete(v29._Bx._Ptr);
  }
  v15 = _wcstok_s(0, L",", &context);
  if ( v15 )
  {
    v29._Myres = 7;
    v29._Mysize = 0;
    v29._Bx._Buf[0] = 0;
    if ( *v15 )
      v16 = wcslen(v15);
    else
      v16 = 0;
    std::wstring::assign(&v29, v15, v16);
    v17 = &v29;
    LOBYTE(v32) = 3;
    if ( v29._Myres >= 8 )
      v17 = (std::wstring *)v29._Bx._Ptr;
    *__errno() = 0;
    *(float *)&v23 = _wcstod(v17->_Bx._Buf, &v24);
    if ( v17 == (std::wstring *)v24 )
      std::_Xinvalid_argument("invalid stof argument");
    if ( *__errno() == 34 )
      std::_Xout_of_range("stof argument out of range");
    v11 = v29._Myres < 8;
    LOBYTE(v32) = 0;
    *(float *)v26 = *(float *)&v23;
    if ( !v11 )
      operator delete(v29._Bx._Ptr);
  }
  v18 = _wcstok_s(0, L"\n", &context);
  if ( v18 )
  {
    v29._Myres = 7;
    v29._Mysize = 0;
    v29._Bx._Buf[0] = 0;
    if ( *v18 )
      v19 = wcslen(v18);
    else
      v19 = 0;
    std::wstring::assign(&v29, v18, v19);
    v20 = &v29;
    LOBYTE(v32) = 4;
    if ( v29._Myres >= 8 )
      v20 = (std::wstring *)v29._Bx._Ptr;
    *__errno() = 0;
    *(float *)&v24 = _wcstod(v20->_Bx._Buf, &v26);
    if ( v20 == (std::wstring *)v26 )
      std::_Xinvalid_argument("invalid stof argument");
    if ( *__errno() == 34 )
      std::_Xout_of_range("stof argument out of range");
    v11 = v29._Myres < 8;
    *v28 = *(float *)&v24;
    if ( !v11 )
      operator delete(v29._Bx._Ptr);
  }
  v21 = v._Mysize != 0;
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
  return v21;
}
char INIReader::hasKey(INIReader *this, const std::wstring *section, const std::wstring *key)
{
  const std::wstring *v4; // edi
  std::wstring *v5; // edi
  std::wstring *v6; // esi
  std::wstring v8; // [esp-1Ch] [ebp-40h] BYREF
  std::vector<std::wstring> *v9; // [esp-4h] [ebp-28h]
  std::vector<std::wstring> keyes; // [esp+Ch] [ebp-18h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  v4 = section;
  if ( !INIReader::hasSection(this, section) )
    return 0;
  keyes._Myfirst = 0;
  keyes._Mylast = 0;
  keyes._Myend = 0;
  v11 = 0;
  v9 = &keyes;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, v4, 0, 0xFFFFFFFF);
  INIReader::getKeyes(this, v8, v9);
  v5 = keyes._Mylast;
  v6 = keyes._Myfirst;
  LOBYTE(section) = 0;
  v9 = (std::vector<std::wstring> *)section;
  if ( std::_Find<std::wstring *,std::wstring>(keyes._Myfirst, keyes._Mylast, key) == v5 )
  {
    if ( v6 )
    {
      v9 = (std::vector<std::wstring> *)section;
      v8._Myres = (unsigned int)&section;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v6, v5);
      operator delete(v6);
    }
    return 0;
  }
  if ( v6 )
  {
    v9 = (std::vector<std::wstring> *)section;
    v8._Myres = (unsigned int)&section;
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v6, v5);
    operator delete(v6);
  }
  return 1;
}
BOOL INIReader::hasSection(INIReader *this, const std::wstring *section)
{
  std::map<std::wstring,INISection> *v2; // ebx
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v3; // edi
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v4; // eax
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v5; // esi
  const wchar_t *v6; // eax
  BOOL result; // eax

  v2 = &this->sections;
  v3 = this->sections._Myhead;
  v4 = std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
         (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->sections,
         section);
  v5 = (std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *)v4;
  if ( v4 == (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)v2->_Myhead )
    goto LABEL_6;
  v6 = v4->_Myval.first._Bx._Buf;
  if ( v5->_Myval.first._Myres >= 8 )
    v6 = *(const wchar_t **)v6;
  if ( std::wstring::compare((std::wstring *)section, 0, section->_Mysize, v6, v5->_Myval.first._Mysize) < 0 )
LABEL_6:
    result = v2->_Myhead != v3;
  else
    result = v5 != v3;
  return result;
}
void INIReader::load(INIReader *this, const std::wstring *filename)
{
  const std::wstring *v3; // esi
  int v4; // eax
  struct std::locale::facet *v5; // edi
  unsigned int v6; // eax
  const std::wstring *v7; // eax
  int v8; // ecx
  unsigned int v9; // edx
  const std::wstring *v10; // ecx
  void (***v11)(_DWORD, int); // eax
  std::wstring *v12; // edi
  std::wstring *v13; // esi
  std::_Facet_base *v14; // eax
  std::_Facet_base *v15; // eax
  std::locale utf8_locale; // [esp+24h] [ebp-19Ch] BYREF
  int v17; // [esp+28h] [ebp-198h] BYREF
  std::locale empty_locale; // [esp+2Ch] [ebp-194h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v19; // [esp+30h] [ebp-190h] BYREF
  std::wifstream file; // [esp+E0h] [ebp-E0h] BYREF
  std::wstring fn; // [esp+198h] [ebp-28h] BYREF
  int v22; // [esp+1BCh] [ebp-4h]

  v3 = filename;
  std::vector<std::wstring>::push_back(&INIReader::openedFiles, filename);
  std::locale::empty(&empty_locale);
  v22 = 0;
  v4 = operator new(52);
  v5 = (struct std::locale::facet *)v4;
  v17 = v4;
  LOBYTE(v22) = 1;
  if ( v4 )
  {
    std::codecvt<wchar_t,char,int>::codecvt<wchar_t,char,int>(v4, 0);
    v5->__vftable = (std::locale::facet_vtbl *)&std::codecvt_utf8<wchar_t,1114111,0>::`vftable';
  }
  else
  {
    v5 = 0;
  }
  LOBYTE(v22) = 0;
  utf8_locale._Ptr = std::locale::_Locimp::_New_Locimp(empty_locale._Ptr);
  if ( v5 )
  {
    v6 = std::locale::id::operator unsigned int(std::codecvt<wchar_t,char,int>::id._Id);
    std::locale::_Locimp::_Locimp_Addfac(utf8_locale._Ptr, v5, v6);
    if ( std::codecvt<wchar_t,char,int>::_Getcat(0, 0) != -1 )
    {
      utf8_locale._Ptr->_Catmask = 0;
      std::_Yarn<char>::operator=(&utf8_locale._Ptr->_Name, "*");
    }
  }
  LOBYTE(v22) = 2;
  v7 = Path::getPlatformSpecificPath(&fn, filename);
  LOBYTE(v22) = 3;
  std::wifstream::wifstream(&file, v7, 1, 64, 1);
  LOBYTE(v22) = 5;
  if ( fn._Myres >= 8 )
    operator delete(fn._Bx._Ptr);
  v8 = *(_DWORD *)file.gap0;
  fn._Bx._Buf[0] = 0;
  fn._Myres = 7;
  fn._Mysize = 0;
  if ( (*((_BYTE *)&file._Chcount + *(_DWORD *)(*(_DWORD *)file.gap0 + 4) + 4) & 6) != 0 )
  {
    this->ready = 0;
    fn._Myres = 7;
    fn._Mysize = 0;
    fn._Bx._Buf[0] = 0;
    v9 = filename->_Myres;
    LOBYTE(v22) = 6;
    if ( v9 < 8 )
      v10 = filename;
    else
      v10 = (const std::wstring *)filename->_Bx._Ptr;
    if ( v9 >= 8 )
      v3 = (const std::wstring *)filename->_Bx._Ptr;
    std::wstring::replace(
      &fn,
      (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&fn,
      (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&fn,
      (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v3,
      (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)((char *)v10 + 2 * filename->_Mysize));
    if ( fn._Myres >= 8 )
      operator delete(fn._Bx._Ptr);
  }
  else
  {
    this->ready = 1;
    std::wios::imbue((char *)&file + *(_DWORD *)(v8 + 4), &v17, &utf8_locale);
    if ( v17 )
    {
      v11 = (void (***)(_DWORD, int))(*(int (**)(int))(*(_DWORD *)v17 + 8))(v17);
      if ( v11 )
        (**v11)(v11, 1);
    }
    *(_DWORD *)v19.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v19.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v19.gap68);
    LOBYTE(v22) = 7;
    v17 = 1;
    std::wiostream::basic_iostream<wchar_t>(&v19, &v19.gap10[8], 0);
    v22 = 8;
    *(_DWORD *)&v19.gap0[*(_DWORD *)(*(_DWORD *)v19.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(std::locale::_Locimp **)((char *)&empty_locale._Ptr + *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)) = (std::locale::_Locimp *)(*(_DWORD *)(*(_DWORD *)v19.gap0 + 4) - 104);
    std::wstreambuf::wstreambuf(&v19.gap10[8]);
    *(_DWORD *)&v19.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v19.gap10[64] = 0;
    *(_DWORD *)&v19.gap10[68] = 0;
    LOBYTE(v22) = 10;
    std::wostream::operator<<(v19.gap10, file.gap10);
    v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v19, &fn);
    v13 = &this->code;
    if ( &this->code != v12 )
    {
      if ( this->code._Myres >= 8 )
        operator delete(v13->_Bx._Ptr);
      this->code._Myres = 7;
      this->code._Mysize = 0;
      v13->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->code, v12);
    }
    if ( fn._Myres >= 8 )
      operator delete(fn._Bx._Ptr);
    fn._Myres = 7;
    fn._Mysize = 0;
    fn._Bx._Buf[0] = 0;
    if ( !std::wfilebuf::close((std::wfilebuf *)file.gap10) )
      std::wios::setstate((char *)&file + *(_DWORD *)(*(_DWORD *)file.gap0 + 4), 2, 0);
    INIReader::parse(this);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v19);
  }
  std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&file.gap64[12]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file.gap64[12]);
  LOBYTE(v22) = 0;
  if ( utf8_locale._Ptr )
  {
    v14 = utf8_locale._Ptr->_Decref(utf8_locale._Ptr);
    if ( v14 )
      ((void (*)(std::_Facet_base *, int))v14->~_Facet_base)(v14, 1);
  }
  v22 = -1;
  if ( empty_locale._Ptr )
  {
    v15 = empty_locale._Ptr->_Decref(empty_locale._Ptr);
    if ( v15 )
      ((void (*)(std::_Facet_base *, int))v15->~_Facet_base)(v15, 1);
  }
}
void INIReader::loadEncrypt(INIReader *this, const std::wstring *filename, const std::wstring *dataFile)
{
  std::wstring *v4; // edi
  std::wstring *v5; // esi
  std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > v6; // [esp+13h] [ebp-35h] BYREF
  std::vector<char> fileContents; // [esp+14h] [ebp-34h] BYREF
  std::wstring result; // [esp+20h] [ebp-28h] BYREF
  int v9; // [esp+44h] [ebp-4h]

  FolderEncrypter::FolderEncrypter(&v6);
  v9 = 0;
  FolderEncrypter::decryptFile((FolderEncrypter *)&v6, &fileContents, dataFile, filename);
  LOBYTE(v9) = 1;
  v4 = ksDecodeUtf8(&result, &fileContents);
  v5 = &this->code;
  if ( &this->code != v4 )
  {
    if ( this->code._Myres >= 8 )
      operator delete(v5->_Bx._Ptr);
    this->code._Myres = 7;
    this->code._Mysize = 0;
    v5->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->code, v4);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->ready = std::wstring::compare(&this->code, 0, this->code._Mysize, L"NOT FOUND", 9u) != 0;
  INIReader::parse(this);
  if ( fileContents._Myfirst )
  {
    operator delete(fileContents._Myfirst);
    fileContents._Myfirst = 0;
    fileContents._Mylast = 0;
    fileContents._Myend = 0;
  }
  v9 = -1;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v6);
}
void INIReader::parse(INIReader *this)
{
  std::wstring *v2; // esi
  bool v3; // cf
  unsigned int v4; // eax
  std::wistream *v5; // eax
  int v6; // esi
  int v7; // eax
  std::wstring *v8; // esi
  std::_Tree_node<std::pair<std::wstring const ,std::wstring >,void *> *v9; // eax
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v10; // eax
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v11; // esi
  const wchar_t *v12; // eax
  std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *v13; // eax
  std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TagDocumentText> >,0> > *v14; // esi
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // esi
  std::wstring *v19; // esi
  INISection *v20; // eax
  std::wstring *v21; // eax
  INISection *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // esi
  INISection *v30; // eax
  const std::wstring *v31; // eax
  std::wistream *v32; // eax
  std::wstring v33; // [esp-18h] [ebp-1FCh] BYREF
  std::tuple<std::wstring const &> v34; // [esp+10h] [ebp-1D4h] BYREF
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::wstring >> > v35; // [esp+14h] [ebp-1D0h] BYREF
  int v36; // [esp+1Ch] [ebp-1C8h] BYREF
  _BYTE *v37; // [esp+20h] [ebp-1C4h]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,INISection> > > > v38; // [esp+24h] [ebp-1C0h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > > v39; // [esp+28h] [ebp-1BCh] BYREF
  std::wistream _Istr; // [esp+2Ch] [ebp-1B8h] BYREF
  char v41[76]; // [esp+94h] [ebp-150h] BYREF
  std::wstring _Keyval; // [esp+E0h] [ebp-104h] BYREF
  std::wstring v; // [esp+F8h] [ebp-ECh] BYREF
  std::wstring l; // [esp+110h] [ebp-D4h] BYREF
  std::wstring result; // [esp+128h] [ebp-BCh] BYREF
  std::wstring k; // [esp+140h] [ebp-A4h] BYREF
  std::wstring v47; // [esp+158h] [ebp-8Ch] BYREF
  std::wstring v48; // [esp+170h] [ebp-74h] BYREF
  std::wstring v49; // [esp+188h] [ebp-5Ch] BYREF
  std::wstring v50; // [esp+1A0h] [ebp-44h] BYREF
  std::wstring v51; // [esp+1B8h] [ebp-2Ch] BYREF
  int v52; // [esp+1E0h] [ebp-4h]

  v2 = &this->code;
  *(_DWORD *)_Istr.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)_Istr.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v41);
  v52 = 0;
  v34._Myfirst._Val = (const std::wstring *)1;
  std::wiostream::basic_iostream<wchar_t>(&_Istr, &_Istr.gap10[8], 0);
  v52 = 1;
  *(_DWORD *)&_Istr.gap0[*(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> **)((char *)&v39._Ptr
                                                                             + *(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4)) = (std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *)(*(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4) - 104);
  v37 = &_Istr.gap10[8];
  std::wstreambuf::wstreambuf(&_Istr.gap10[8]);
  v3 = this->code._Myres < 8;
  v4 = this->code._Mysize;
  LOBYTE(v52) = 2;
  *(_DWORD *)&_Istr.gap10[8] = &std::wstringbuf::`vftable';
  if ( !v3 )
    v2 = (std::wstring *)v2->_Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&_Istr.gap10[8], v2->_Bx._Buf, v4, 0);
  v52 = 5;
  l._Myres = 7;
  l._Mysize = 0;
  l._Bx._Buf[0] = 0;
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  v5 = std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&_Istr, &l, 0xAu);
  if ( (v5->gap0[*(_DWORD *)(*(_DWORD *)v5->gap0 + 4) + 12] & 6) == 0 )
  {
    do
    {
      v6 = std::wstring::find_first_of(&l, L"[", 0, 1u);
      v7 = std::wstring::find_first_of(&l, L"]", 0, 1u);
      if ( v6 == -1 || v7 == -1 )
      {
        v16 = std::wstring::find_first_of(&l, L"=", 0, 1u);
        v17 = std::wstring::find_first_of(&l, L";", 0, 1u);
        v18 = v17;
        if ( v16 == -1 || !_Keyval._Mysize || v17 != -1 && v17 <= v16 )
          goto LABEL_57;
        std::wstring::substr(&l, &k, 0, v16);
        v._Myres = 7;
        v._Mysize = 0;
        v._Bx._Buf[0] = 0;
        LOBYTE(v52) = 8;
        if ( v18 == -1 )
          v33._Myres = l._Mysize - v16 + 1;
        else
          v33._Myres = v18 - v16 - 1;
        v19 = std::wstring::substr(&l, &result, v16 + 1, v33._Myres);
        if ( &v != v19 )
        {
          if ( v._Myres >= 8 )
            operator delete(v._Bx._Ptr);
          v._Myres = 7;
          v._Mysize = 0;
          v._Bx._Buf[0] = 0;
          std::wstring::_Assign_rv(&v, v19);
        }
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        trim2(&v);
        v33._Myres = (unsigned int)&k;
        v20 = std::map<std::wstring,INISection>::operator[](&this->sections, &_Keyval);
        v21 = std::map<std::wstring,std::wstring>::operator[](&v20->keys, (const std::wstring *)v33._Myres);
        if ( std::wstring::compare(v21, 0, v21->_Mysize, word_17BE9D8, 0) )
        {
          v24 = std::operator+<wchar_t>(&v51, L"ERROR: MULTIPLE KEY FOUND IN FILE ", &this->filename);
          LOBYTE(v52) = 9;
          v25 = std::operator+<wchar_t>(&result, v24, L" [");
          LOBYTE(v52) = 10;
          v26 = std::operator+<wchar_t>(&v47, v25, &_Keyval);
          LOBYTE(v52) = 11;
          v27 = std::operator+<wchar_t>(&v49, v26, L"] ");
          LOBYTE(v52) = 12;
          v28 = std::operator+<wchar_t>(&v48, v27, &k);
          LOBYTE(v52) = 13;
          v29 = std::operator+<wchar_t>(&v50, v28, L" STILL USING OLD VALUE: ");
          LOBYTE(v52) = 14;
          v33._Myres = (unsigned int)&k;
          v30 = std::map<std::wstring,INISection>::operator[](&this->sections, &_Keyval);
          v31 = std::map<std::wstring,std::wstring>::operator[](&v30->keys, (const std::wstring *)v33._Myres);
          std::operator+<wchar_t>(&v33, v29, v31);
          INIReader::errorReport(this, v33);
          if ( v50._Myres >= 8 )
            operator delete(v50._Bx._Ptr);
          v50._Myres = 7;
          v50._Mysize = 0;
          v50._Bx._Buf[0] = 0;
          if ( v48._Myres >= 8 )
            operator delete(v48._Bx._Ptr);
          v48._Myres = 7;
          v48._Mysize = 0;
          v48._Bx._Buf[0] = 0;
          if ( v49._Myres >= 8 )
            operator delete(v49._Bx._Ptr);
          v49._Myres = 7;
          v49._Mysize = 0;
          v49._Bx._Buf[0] = 0;
          if ( v47._Myres >= 8 )
            operator delete(v47._Bx._Ptr);
          v47._Myres = 7;
          v47._Mysize = 0;
          v47._Bx._Buf[0] = 0;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( v51._Myres >= 8 )
            operator delete(v51._Bx._Ptr);
        }
        else
        {
          v33._Myres = (unsigned int)&k;
          v22 = std::map<std::wstring,INISection>::operator[](&this->sections, &_Keyval);
          v23 = std::map<std::wstring,std::wstring>::operator[](&v22->keys, (const std::wstring *)v33._Myres);
          if ( v23 != &v )
            std::wstring::assign(v23, &v, 0, 0xFFFFFFFF);
        }
        if ( v._Myres >= 8 )
          operator delete(v._Bx._Ptr);
        v._Myres = 7;
        v._Mysize = 0;
        v._Bx._Buf[0] = 0;
        LOBYTE(v52) = 5;
        if ( k._Myres < 8 )
          goto LABEL_57;
        v33._Myres = (unsigned int)k._Bx._Ptr;
      }
      else
      {
        v8 = std::wstring::substr(&l, &result, v6 + 1, v7 - v6 - 1);
        if ( &_Keyval != v8 )
        {
          if ( _Keyval._Myres >= 8 )
            operator delete(_Keyval._Bx._Ptr);
          _Keyval._Myres = 7;
          _Keyval._Mysize = 0;
          _Keyval._Bx._Buf[0] = 0;
          if ( v8->_Myres >= 8 )
          {
            _Keyval._Bx._Ptr = v8->_Bx._Ptr;
            v8->_Bx._Ptr = 0;
          }
          else if ( v8->_Mysize != -1 )
          {
            _memmove(&_Keyval, v8, 2 * (v8->_Mysize + 1));
          }
          _Keyval._Mysize = v8->_Mysize;
          _Keyval._Myres = v8->_Myres;
          v8->_Myres = 7;
          v8->_Mysize = 0;
          v8->_Bx._Buf[0] = 0;
        }
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v35._Myhead = 0;
        v35._Mysize = 0;
        std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,std::wstring>>>::_Buyheadnode(&v35);
        v35._Myhead = v9;
        LOBYTE(v52) = 6;
        v10 = (std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *)std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
                                                                                     (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->sections,
                                                                                     &_Keyval);
        v11 = v10;
        if ( v10 == this->sections._Myhead )
          goto LABEL_20;
        v12 = v10->_Myval.first._Bx._Buf;
        if ( v11->_Myval.first._Myres >= 8 )
          v12 = *(const wchar_t **)v12;
        if ( std::wstring::compare(&_Keyval, 0, _Keyval._Mysize, v12, v11->_Myval.first._Mysize) < 0 )
        {
LABEL_20:
          v34._Myfirst._Val = &_Keyval;
          v13 = (std::_Tree_node<std::pair<std::wstring const ,INISection>,void *> *)std::_Tree_buy<std::pair<std::wstring const,INISection>>::_Buynode<std::piecewise_construct_t const &,std::tuple<std::wstring const &>,std::tuple<>>(
                                                                                       &this->sections,
                                                                                       &piecewise_construct_73,
                                                                                       &v34,
                                                                                       (std::tuple<> *)&v36 + 3);
          std::_Tree<std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::_Insert_hint<std::pair<std::wstring const,INISection> &,std::_Tree_node<std::pair<std::wstring const,INISection>,void *> *>(
            &this->sections,
            &v38,
            (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,INISection> > > >)v11,
            &v13->_Myval,
            v13);
          v11 = v38._Ptr;
        }
        v14 = (std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TagDocumentText> >,0> > *)&v11->_Myval.second;
        if ( v14 != (std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TagDocumentText> >,0> > *)&v35 )
        {
          std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,TagDocumentText>>,0>>::_Erase(
            v14,
            v14->_Myhead->_Parent);
          v15 = v14->_Myhead;
          LOBYTE(v37) = 0;
          v33._Myres = (unsigned int)v37;
          v15->_Parent = v15;
          v14->_Myhead->_Left = v14->_Myhead;
          v14->_Myhead->_Right = v14->_Myhead;
          v33._Mysize = (unsigned int)&v35;
          v14->_Mysize = 0;
          std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>::_Copy<std::integral_constant<bool,0>>(
            (std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,std::wstring > >,0> > *)v14,
            (const std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,std::wstring > >,0> > *)v33._Mysize,
            (std::integral_constant<bool,0>)v33._Myres);
        }
        LOBYTE(v52) = 5;
        std::_Tree<std::_Tmap_traits<std::wstring,std::wstring,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::wstring>>,0>>::erase(
          (std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TagDocumentText> >,0> > *)&v35,
          &v39,
          (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > >)v35._Myhead->_Left,
          (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > >)v35._Myhead);
        v33._Myres = (unsigned int)v35._Myhead;
      }
      operator delete(v33._Myres);
LABEL_57:
      v32 = std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&_Istr, &l, 0xAu);
    }
    while ( (v32->gap0[*(_DWORD *)(*(_DWORD *)v32->gap0 + 4) + 12] & 6) == 0 );
  }
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  if ( l._Myres >= 8 )
    operator delete(l._Bx._Ptr);
  l._Myres = 7;
  l._Bx._Buf[0] = 0;
  l._Mysize = 0;
  *(_DWORD *)&_Istr.gap0[*(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> **)((char *)&v39._Ptr
                                                                             + *(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4)) = (std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *)(*(_DWORD *)(*(_DWORD *)_Istr.gap0 + 4) - 104);
  *(_DWORD *)&_Istr.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&_Istr.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&_Istr.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&_Istr.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v41);
}
void INIReader::printCode(INIReader *this)
{
  std::wstring *v1; // ecx

  v1 = &this->code;
  if ( v1->_Myres >= 8 )
    v1 = (std::wstring *)v1->_Bx._Ptr;
  _printf("%S\n", v1->_Bx._Buf);
}
void INIReader::setVerboseMode(INIReader *this, bool mode)
{
  this->verbose = mode && !this->m_isEncrypted;
}
