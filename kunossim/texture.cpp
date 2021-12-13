#include "texture.h"
void Texture::Texture(Texture *this)
{
  this->kid = 0;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
}
Texture *Texture::operator=(Texture *this, const Texture *__that)
{
  std::wstring *v3; // ecx

  v3 = &this->fileName;
  this->kid = __that->kid;
  if ( v3 != &__that->fileName )
    std::wstring::assign(v3, &__that->fileName, 0, 0xFFFFFFFF);
  return this;
}
unsigned int Texture::height(Texture *this)
{
  unsigned int result; // eax

  if ( this->kid )
    result = *((_DWORD *)this->kid + 10);
  else
    result = 0;
  return result;
}
unsigned int Texture::width(Texture *this)
{
  unsigned int result; // eax

  if ( this->kid )
    result = *((_DWORD *)this->kid + 9);
  else
    result = 0;
  return result;
}
void Texture::Texture(Texture *this, const std::wstring *filename)
{
  std::wstring *v2; // ebx
  const std::wstring *v3; // eax

  v2 = &this->fileName;
  this->kid = 0;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  if ( filename->_Myres < 8 )
    v3 = filename;
  else
    v3 = (const std::wstring *)filename->_Bx._Ptr;
  this->kid = (void *)kglCreateTextureFromFile(v3->_Bx._Buf);
  if ( v2 != filename )
    std::wstring::assign(v2, filename, 0, 0xFFFFFFFF);
}
void Texture::Texture(Texture *this, const RenderTarget *rt)
{
  this->kid = 0;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  this->kid = kglCreateTextureFromRT(rt->kidColor);
}
void Texture::Texture(Texture *this, unsigned __int8 *buffer, unsigned int size)
{
  void *v4; // eax

  this->kid = 0;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  kglCreateTextureFromBuffer(buffer, size);
  this->kid = v4;
}
void Texture::Texture(Texture *this, unsigned __int8 *buffer, unsigned int width, unsigned int height, PixelFormat aFormat)
{
  unsigned int v6; // eax
  void *v7; // eax

  this->kid = 0;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  if ( aFormat == eRGBA8 )
  {
    v6 = 1;
  }
  else if ( aFormat == eRGBA32 )
  {
    v6 = 2;
  }
  else
  {
    v6 = 0;
  }
  kglCreateTextureFromBufferWithFormat(buffer, v6, width, height);
  this->kid = v7;
}
void Texture::release(Texture *this)
{
  if ( this->kid )
  {
    kglDestroyTexture(this->kid);
    this->kid = 0;
  }
}
