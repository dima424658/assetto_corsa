#include "font.h"
void Font::Font(Font *this, const std::wstring *fontFamily, eFontType fontType, float size, int italic, int bold)
{
  std::wstring v7; // [esp-20h] [ebp-24h] BYREF
  int v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]

  v9 = bold;
  v8 = italic;
  this->shadowPixelDistance = 2.0;
  this->currentAlpha = 1.0;
  if ( fontType )
  {
    if ( fontType != eFontMonospaced && fontType == eFontCustom )
    {
      v7._Myres = 7;
      v7._Mysize = 0;
      v7._Bx._Buf[0] = 0;
      std::wstring::assign(&v7, fontFamily, 0, 0xFFFFFFFF);
    }
    else
    {
      std::wstring::wstring(&v7, L"Consolas");
    }
  }
  else
  {
    std::wstring::wstring(&v7, L"Segoe UI");
  }
  this->kid = Font::getFontWrapper((int)this, v7, v8, v9);
  this->scale = size;
  this->color = -1;
  this->shadowed = 0;
}
void Font::Font(Font *this, eFontType fontType, float size, int italic, int bold)
{
  std::wstring v6; // [esp-20h] [ebp-24h] BYREF
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]

  v8 = bold;
  v7 = italic;
  this->shadowPixelDistance = 2.0;
  this->currentAlpha = 1.0;
  if ( fontType )
    std::wstring::wstring(&v6, L"Consolas");
  else
    std::wstring::wstring(&v6, L"Segoe UI");
  this->kid = Font::getFontWrapper((int)this, v6, v7, v8);
  this->scale = size;
  this->color = -1;
  this->shadowed = 0;
}
void Font::blitString(Font *this, float x, float y, const std::wstring *s, float ascale, eFontAlign align)
{
  const std::wstring *v6; // ebp
  float v8; // xmm1_4
  unsigned int v9; // esi
  int v10; // eax
  unsigned int v11; // eax

  v6 = s;
  if ( this->shadowed )
  {
    v8 = this->shadowPixelDistance;
    v9 = this->color;
    v10 = (int)(float)(this->currentAlpha * 255.0);
    this->shadowed = 0;
    this->color = (unsigned __int8)v10 << 24;
    Font::blitString(this, v8 + x, v8 + y, s, ascale, align);
    this->color = v9;
    this->shadowed = 1;
  }
  v11 = 0;
  if ( align == eAlignRight )
  {
    v11 = 2;
  }
  else if ( align == eAlignCenter )
  {
    v11 = 1;
  }
  if ( s->_Myres >= 8 )
    v6 = (const std::wstring *)s->_Bx._Ptr;
  kglBlitStringWide(this->kid, x, y, v6->_Bx._Buf, this->scale * ascale, v11, this->color);
}
void Font::cleanup()
{
  std::_Tree_node<std::pair<std::wstring const ,void *>,void *> *v0; // esi
  const wchar_t *v1; // eax
  std::_Tree_node<std::pair<std::wstring const ,void *>,void *> *v2; // eax
  std::_Tree_node<std::pair<std::wstring const ,void *>,void *> *j; // eax
  std::_Tree_node<std::pair<std::wstring const ,void *>,void *> *i; // eax

  v0 = Font::fontWrappers._Myhead->_Left;
  while ( v0 != Font::fontWrappers._Myhead )
  {
    v1 = v0->_Myval.first._Bx._Buf;
    if ( v0->_Myval.first._Myres >= 8 )
      v1 = *(const wchar_t **)v1;
    _printf("Destroyng font: %S\n", v1);
    kglDestroySampler(v0->_Myval.second);
    if ( !v0->_Isnil )
    {
      v2 = v0->_Right;
      if ( v2->_Isnil )
      {
        for ( i = v0->_Parent; !i->_Isnil; i = i->_Parent )
        {
          if ( v0 != i->_Right )
            break;
          v0 = i;
        }
        v0 = i;
      }
      else
      {
        v0 = v0->_Right;
        for ( j = v2->_Left; !j->_Isnil; j = j->_Left )
          v0 = j;
      }
    }
  }
}
void *__usercall Font::getFontWrapper@<eax>(int a1@<esi>, std::wstring name, unsigned __int8 italic, unsigned __int8 bold)
{
  unsigned __int8 v4; // bl
  void *v5; // esi
  std::wstring *v6; // ecx
  std::wstring *v7; // eax
  unsigned __int8 v9; // [esp+Ch] [ebp-2Ch]
  std::wstring finalFontName; // [esp+10h] [ebp-28h] BYREF
  int v11; // [esp+34h] [ebp-4h]

  v4 = bold;
  v9 = italic;
  v11 = 0;
  finalFontName._Bx._Buf[0] = 0;
  finalFontName._Myres = 7;
  finalFontName._Mysize = 0;
  std::wstring::assign(&finalFontName, &name, 0, 0xFFFFFFFF);
  LOBYTE(v11) = 1;
  if ( v9 )
    std::wstring::append(&finalFontName, L" Italic", 7u);
  if ( v4 )
    std::wstring::append(&finalFontName, L" Bold", 5u);
  if ( *std::map<std::wstring,void *>::operator[](&Font::fontWrappers, &finalFontName) )
  {
    v5 = *std::map<std::wstring,void *>::operator[](&Font::fontWrappers, &finalFontName);
  }
  else
  {
    v6 = &name;
    if ( name._Myres >= 8 )
      v6 = (std::wstring *)name._Bx._Ptr;
    v5 = (void *)kglCreateFont(a1, v6->_Bx._Buf, v9, v4);
    if ( v5 )
    {
      *std::map<std::wstring,void *>::operator[](&Font::fontWrappers, &finalFontName) = v5;
    }
    else
    {
      v7 = &name;
      if ( name._Myres >= 8 )
        v7 = (std::wstring *)name._Bx._Ptr;
      _printf("ERROR: pFW1Factory->CreateFontWrapper(%S) failed\n", v7->_Bx._Buf);
    }
  }
  if ( finalFontName._Myres >= 8 )
    operator delete(finalFontName._Bx._Ptr);
  finalFontName._Myres = 7;
  finalFontName._Mysize = 0;
  finalFontName._Bx._Buf[0] = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  return v5;
}
void Font::setColor(Font *this, const vec4f *cc)
{
  this->color = (unsigned __int8)(int)(float)(cc->x * 255.0) | (((unsigned __int8)(int)(float)(cc->y * 255.0) | ((((unsigned __int8)(int)(float)(cc->w * 255.0) << 8) | (unsigned __int8)(int)(float)(cc->z * 255.0)) << 8)) << 8);
  this->currentAlpha = cc->w;
}
void Font::setColor(Font *this, float r, float g, float b, float a)
{
  this->currentAlpha = a;
  this->color = (unsigned __int8)(int)(float)(r * 255.0) | (((unsigned __int8)(int)(float)(g * 255.0) | (((unsigned __int8)(int)(float)(b * 255.0) | ((unsigned __int8)(int)(float)(a * 255.0) << 8)) << 8)) << 8);
}
