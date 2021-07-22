#include "tagdocumentreader.h
void TagDocumentReader::TagDocumentReader(TagDocumentReader *this, std::wstring inputFile)
{
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v3; // eax
  std::wstring v4; // [esp-18h] [ebp-34h] BYREF
  TagDocumentReader *v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+18h] [ebp-4h]

  v5 = this;
  v6 = 0;
  this->document._Myhead = 0;
  this->document._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<CarAvatar * const,Lap>>>::_Buyheadnode(&this->document);
  this->document._Myhead = v3;
  LOBYTE(v6) = 1;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, &inputFile, 0, 0xFFFFFFFF);
  TagDocumentReader::load(this, v4);
  if ( inputFile._Myres >= 8 )
    operator delete(inputFile._Bx._Ptr);
}
void TagDocumentReader::TagDocumentReader(TagDocumentReader *this)
{
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v2; // eax

  this->document._Myhead = 0;
  this->document._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<CarAvatar * const,Lap>>>::_Buyheadnode(&this->document);
  this->document._Myhead = v2;
}
TagDocumentText *TagDocumentReader::getText(TagDocumentReader *this, TagDocumentText *result, std::wstring key)
{
  TagDocumentText *v3; // esi
  bool v4; // cf

  v3 = std::map<std::wstring,TagDocumentText>::operator[](&this->document, &key);
  result->text._Myres = 7;
  result->text._Mysize = 0;
  result->text._Bx._Buf[0] = 0;
  std::wstring::assign(&result->text, &v3->text, 0, 0xFFFFFFFF);
  v4 = key._Myres < 8;
  result->linesCount = v3->linesCount;
  if ( !v4 )
    operator delete(key._Bx._Ptr);
  return result;
}
void TagDocumentReader::load(TagDocumentReader *this, std::wstring inputFile)
{
  unsigned int v3; // ebp
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v4; // eax
  std::codecvt_utf8<wchar_t,1114111,0> *v5; // esi
  const std::wstring *v6; // eax
  void (***v7)(_DWORD, int); // eax
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v8; // eax
  int v9; // eax
  wchar_t v10; // ax
  int v11; // esi
  wchar_t v12; // ax
  std::wostream *v13; // eax
  int i; // eax
  std::wstring *v15; // ecx
  wchar_t v16; // ax
  std::wstring *v17; // eax
  std::wostream *v18; // eax
  std::wstring *v19; // edi
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v20; // eax
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v21; // esi
  const wchar_t *v22; // eax
  std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *v23; // eax
  std::wstring *v24; // esi
  std::wstring *v25; // eax
  std::_Facet_base *v26; // eax
  std::_Facet_base *v27; // eax
  std::wstring *v28; // eax
  std::tuple<std::wstring &&> v29; // [esp+34h] [ebp-208h] BYREF
  int v30; // [esp+38h] [ebp-204h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > > v31; // [esp+3Ch] [ebp-200h] BYREF
  std::locale empty_locale; // [esp+40h] [ebp-1FCh] BYREF
  std::locale utf8_locale; // [esp+44h] [ebp-1F8h] BYREF
  std::wstring _Right; // [esp+48h] [ebp-1F4h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > sectionText; // [esp+60h] [ebp-1DCh] BYREF
  std::wifstream stream; // [esp+110h] [ebp-12Ch] BYREF
  std::wstring text; // [esp+1C8h] [ebp-74h] BYREF
  std::wstring section; // [esp+1E0h] [ebp-5Ch] BYREF
  std::wstring result; // [esp+1F8h] [ebp-44h] BYREF
  std::wstring v40; // [esp+210h] [ebp-2Ch] BYREF
  wchar_t *v41; // [esp+228h] [ebp-14h]
  int v42; // [esp+238h] [ebp-4h]

  v3 = 0;
  v29._Myfirst._Val = 0;
  v42 = 0;
  if ( Path::fileExists((unsigned int)this, &inputFile, 0) )
  {
    std::locale::empty(&empty_locale);
    LOBYTE(v42) = 1;
    v4 = (std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *)operator new(52);
    v5 = (std::codecvt_utf8<wchar_t,1114111,0> *)v4;
    v31._Ptr = v4;
    LOBYTE(v42) = 2;
    if ( v4 )
    {
      std::codecvt<wchar_t,char,int>::codecvt<wchar_t,char,int>(v4, 0);
      v5->__vftable = (std::codecvt_utf8<wchar_t,1114111,0>_vtbl *)&std::codecvt_utf8<wchar_t,1114111,0>::`vftable';
    }
    else
    {
      v5 = 0;
    }
    LOBYTE(v42) = 1;
    std::locale::locale(&utf8_locale, &empty_locale, v5);
    LOBYTE(v42) = 3;
    v6 = Path::getPlatformSpecificPath(&result, &inputFile);
    LOBYTE(v42) = 4;
    std::wifstream::wifstream(&stream, v6, 1, 64, 1);
    LOBYTE(v42) = 6;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    std::wios::imbue((char *)&stream + *(_DWORD *)(*(_DWORD *)stream.gap0 + 4), &v29, &utf8_locale);
    if ( v29._Myfirst._Val )
    {
      v7 = (void (***)(_DWORD, int))(*((int (**)(std::wstring *))v29._Myfirst._Val->_Bx._Ptr + 2))(v29._Myfirst._Val);
      if ( v7 )
        (**v7)(v7, 1);
    }
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v8 = this->document._Myhead;
    LOBYTE(v42) = 7;
    std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,TagDocumentText>>,0>>::_Erase(
      &this->document,
      v8->_Parent);
    this->document._Myhead->_Parent = this->document._Myhead;
    this->document._Myhead->_Left = this->document._Myhead;
    this->document._Myhead->_Right = this->document._Myhead;
    v9 = *(_DWORD *)stream.gap0;
    this->document._Mysize = 0;
    v10 = std::wios::widen((char *)&stream + *(_DWORD *)(v9 + 4), 10);
    std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&stream, &section, v10);
    while ( (*((_BYTE *)&stream._Chcount + *(_DWORD *)(*(_DWORD *)stream.gap0 + 4) + 4) & 1) == 0 )
    {
      *(_DWORD *)sectionText.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)sectionText.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(sectionText.gap68);
      LOBYTE(v42) = 8;
      v3 |= 1u;
      v29._Myfirst._Val = (std::wstring *)v3;
      std::wiostream::basic_iostream<wchar_t>(&sectionText, &sectionText.gap10[8], 0);
      v42 = 9;
      *(_DWORD *)&sectionText.gap0[*(_DWORD *)(*(_DWORD *)sectionText.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(unsigned int *)((char *)&_Right._Myres + *(_DWORD *)(*(_DWORD *)sectionText.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)sectionText.gap0 + 4)
                                                                                               - 104;
      std::wstreambuf::wstreambuf(&sectionText.gap10[8]);
      *(_DWORD *)&sectionText.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&sectionText.gap10[64] = 0;
      *(_DWORD *)&sectionText.gap10[68] = 0;
      v11 = 0;
      text._Myres = 7;
      text._Mysize = 0;
      text._Bx._Buf[0] = 0;
      LOBYTE(v42) = 12;
      v12 = std::wios::widen((char *)&stream + *(_DWORD *)(*(_DWORD *)stream.gap0 + 4), 10);
      std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&stream, &text, v12);
      v13 = std::operator<<<wchar_t>((std::wostream *)sectionText.gap10, &text);
      std::wostream::operator<<(v13);
      for ( i = *(_DWORD *)(*(_DWORD *)stream.gap0 + 4);
            (*((_BYTE *)&stream._Chcount + i + 4) & 1) == 0;
            i = *(_DWORD *)(*(_DWORD *)stream.gap0 + 4) )
      {
        v15 = &text;
        if ( text._Myres >= 8 )
          v15 = (std::wstring *)text._Bx._Ptr;
        if ( v15->_Bx._Buf[0] == 91 )
          break;
        v16 = std::wios::widen((char *)&stream + i, 10);
        std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&stream, &text, v16);
        v17 = &text;
        if ( text._Myres >= 8 )
          v17 = (std::wstring *)text._Bx._Ptr;
        if ( v17->_Bx._Buf[0] != 91 )
        {
          v18 = std::operator<<<wchar_t>((std::wostream *)sectionText.gap10, &text);
          std::wostream::operator<<(v18);
          ++v11;
        }
      }
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&sectionText, &_Right);
      v40._Myres = 7;
      v40._Mysize = 0;
      v40._Bx._Buf[0] = 0;
      LOBYTE(v42) = 14;
      std::wstring::assign(&v40, &_Right, 0, 0xFFFFFFFF);
      v41 = (wchar_t *)v11;
      if ( _Right._Myres >= 8 )
        operator delete(_Right._Bx._Ptr);
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      LOBYTE(v42) = 15;
      v19 = std::wstring::substr(&section, &result, 1u, section._Mysize - 2);
      LOBYTE(v42) = 16;
      v20 = (std::_Tree_node<std::pair<std::wstring const ,TagDocumentText>,void *> *)std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
                                                                                        (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)this,
                                                                                        v19);
      v21 = v20;
      if ( v20 == this->document._Myhead )
        goto LABEL_26;
      v22 = v20->_Myval.first._Bx._Buf;
      if ( v21->_Myval.first._Myres >= 8 )
        v22 = *(const wchar_t **)v22;
      if ( std::wstring::compare(v19, 0, v19->_Mysize, v22, v21->_Myval.first._Mysize) < 0 )
      {
LABEL_26:
        v29._Myfirst._Val = v19;
        v23 = std::_Tree_buy<std::pair<std::wstring const,TagDocumentText>>::_Buynode<std::piecewise_construct_t const &,std::tuple<std::wstring &&>,std::tuple<>>(
                &this->document,
                &piecewise_construct_95,
                &v29,
                (std::tuple<> *)&v30 + 3);
        std::_Tree<std::_Tmap_traits<std::wstring,TagDocumentText,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,TagDocumentText>>,0>>::_Insert_hint<std::pair<std::wstring const,TagDocumentText> &,std::_Tree_node<std::pair<std::wstring const,TagDocumentText>,void *> *>(
          &this->document,
          &v31,
          (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TagDocumentText> > > >)v21,
          &v23->_Myval,
          v23);
        v21 = v31._Ptr;
      }
      v24 = &v21->_Myval.second.text;
      if ( v24 != &v40 )
        std::wstring::assign(v24, &v40, 0, 0xFFFFFFFF);
      v24[1]._Bx._Ptr = v41;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v42) = 12;
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      if ( text._Mysize )
      {
        v25 = &text;
        if ( text._Myres >= 8 )
          v25 = (std::wstring *)text._Bx._Ptr;
        if ( v25->_Bx._Buf[0] == 91 )
          std::wstring::assign(&section, &text, 0, 0xFFFFFFFF);
      }
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      text._Myres = 7;
      text._Bx._Buf[0] = 0;
      text._Mysize = 0;
      LOBYTE(v42) = 7;
      *(_DWORD *)&sectionText.gap0[*(_DWORD *)(*(_DWORD *)sectionText.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(unsigned int *)((char *)&_Right._Myres + *(_DWORD *)(*(_DWORD *)sectionText.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)sectionText.gap0 + 4)
                                                                                               - 104;
      *(_DWORD *)&sectionText.gap10[8] = &std::wstringbuf::`vftable';
      if ( (sectionText.gap10[68] & 1) != 0 )
        operator delete(**(_DWORD **)&sectionText.gap10[20]);
      std::wstreambuf::setg(&sectionText.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&sectionText.gap10[8], 0, 0);
      *(_DWORD *)&sectionText.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&sectionText.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&sectionText.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&sectionText.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(sectionText.gap68);
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&stream.gap64[12]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&stream.gap64[12]);
    LOBYTE(v42) = 1;
    if ( utf8_locale._Ptr )
    {
      v26 = utf8_locale._Ptr->_Decref(utf8_locale._Ptr);
      if ( v26 )
        ((void (*)(std::_Facet_base *, int))v26->~_Facet_base)(v26, 1);
    }
    LOBYTE(v42) = 0;
    if ( empty_locale._Ptr )
    {
      v27 = empty_locale._Ptr->_Decref(empty_locale._Ptr);
      if ( v27 )
        ((void (*)(std::_Facet_base *, int))v27->~_Facet_base)(v27, 1);
    }
  }
  else
  {
    v28 = &inputFile;
    if ( inputFile._Myres >= 8 )
      v28 = (std::wstring *)inputFile._Bx._Ptr;
    _printf("TagDocumentReader:: couldn't load %S\n", v28->_Bx._Buf);
  }
  if ( inputFile._Myres >= 8 )
    operator delete(inputFile._Bx._Ptr);
}
