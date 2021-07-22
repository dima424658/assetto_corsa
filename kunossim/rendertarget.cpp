#include "rendertarget.h
void RenderTarget::RenderTarget(RenderTarget *this, GraphicsManager *graphics, eRenderTargetFormat fmt, unsigned int iwidth, unsigned int iheight, bool hasColor, bool hasDepth, int mips)
{
  unsigned int v9; // eax
  int v10; // edx
  void *v11; // eax
  eRenderTargetFormat v12; // eax
  int v13; // ecx
  void *v14; // eax

  this->__vftable = (RenderTarget_vtbl *)&RenderTarget::`vftable';
  this->width = iwidth;
  this->height = iheight;
  this->kidColor = 0;
  this->kidDepth = 0;
  this->format = fmt;
  this->hasNullDepth = 0;
  if ( hasColor )
  {
    v9 = 0;
    v10 = 1;
    switch ( fmt )
    {
      case eR8G8B8A8:
        v9 = 0;
        break;
      case eR16G16B16A16:
        v9 = 1;
        break;
      case eR32F:
        v9 = 2;
        break;
      case eR32Typeless:
        v9 = 4;
        break;
      case eR16F:
        v9 = 3;
        break;
      case eR16G16B16A16_MS:
        v9 = 1;
        goto LABEL_10;
      case eR8G8B8A8_MS:
        v9 = 0;
LABEL_10:
        v10 = graphics->videoSettings.aaSamples;
        break;
      default:
        break;
    }
    kglCreateRenderTarget(iwidth, iheight, v9, v10, mips);
    this->kidColor = v11;
  }
  if ( hasDepth )
  {
    v12 = this->format;
    v13 = 1;
    if ( v12 == eR16G16B16A16_MS || v12 == eR32Typeless_MS || v12 == eR8G8B8A8_MS )
      v13 = graphics->videoSettings.aaSamples;
    kglCreateRenderTargetDepth(this->width, this->height, v13, mips);
    this->kidDepth = v14;
  }
}
void RenderTarget::~RenderTarget(RenderTarget *this)
{
  void *v2; // eax

  v2 = this->kidColor;
  this->__vftable = (RenderTarget_vtbl *)&RenderTarget::`vftable';
  if ( v2 )
    kglDestroyRenderTarget(v2);
  if ( this->kidDepth )
    kglDestroyRenderTarget(this->kidDepth);
}
RenderTarget *RenderTarget::`scalar deleting destructor'(RenderTarget *this, unsigned int a2)
{
  void *v3; // eax

  v3 = this->kidColor;
  this->__vftable = (RenderTarget_vtbl *)&RenderTarget::`vftable';
  if ( v3 )
    kglDestroyRenderTarget(v3);
  if ( this->kidDepth )
    kglDestroyRenderTarget(this->kidDepth);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void RenderTarget::clear(RenderTarget *this)
{
  void *v2; // eax
  void *v3; // eax
  float black[4]; // [esp+8h] [ebp-14h] BYREF

  *(_OWORD *)black = _xmm;
  v2 = this->kidColor;
  if ( v2 )
    kglRenderTargetClear(v2, black, 1.0);
  v3 = this->kidDepth;
  if ( v3 )
    kglRenderTargetClear(v3, black, 1.0);
}
