#include "acfont.h
void ACFont::ACFont(ACFont *this, Font *ifont, vec2f *off)
{
  this->font = ifont;
  this->__vftable = (ACFont_vtbl *)&ACFont::`vftable';
  this->offset.x = 0.0;
  this->offset.y = 0.0;
  this->offset = *off;
}
void ACFont::~ACFont(ACFont *this)
{
  this->__vftable = (ACFont_vtbl *)&ACFont::`vftable';
}
ACFont *ACFont::`scalar deleting destructor'(ACFont *this, unsigned int a2)
{
  this->__vftable = (ACFont_vtbl *)&ACFont::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACFont::blitString(ACFont *this, float x, float y, const std::wstring *message, acFontAlign align)
{
  Font::blitString(this->font, this->offset.x + x, this->offset.y + y, message, 1.0, (eFontAlign)align);
}
void ACFont::setColor(ACFont *this, float r, float g, float b)
{
  Font::setColor(this->font, r, g, b, 1.0);
}
void ACFont::setScale(ACFont *this, float scale)
{
  this->font->scale = scale;
}
