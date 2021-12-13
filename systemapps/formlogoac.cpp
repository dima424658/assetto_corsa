#include "formlogoac.h"
void __userpurge FormLogoAC::FormLogoAC(FormLogoAC *this@<ecx>, unsigned int a2@<ebx>, ksgui::GUI *a_gui)
{
  const std::wstring *v4; // eax
  Texture *v5; // eax
  _DWORD *v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  float v9; // xmm0_4
  std::wstring v10; // [esp-14h] [ebp-78h] BYREF
  float w; // [esp+4h] [ebp-60h]
  float h; // [esp+8h] [ebp-5Ch]
  FormLogoAC *v13; // [esp+1Ch] [ebp-48h]
  std::wstring text; // [esp+20h] [ebp-44h] BYREF
  Texture result; // [esp+38h] [ebp-2Ch] BYREF
  int v16; // [esp+60h] [ebp-4h]

  h = 0.0;
  LODWORD(w) = a_gui;
  v13 = this;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"LOGO_AC", 7u);
  ksgui::Form::Form(this, a2, v10, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v16 = 0;
  LODWORD(h) = 7;
  this->__vftable = (FormLogoAC_vtbl *)&FormLogoAC::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"AC Logo", LODWORD(h));
  LOBYTE(v16) = 1;
  v4 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v16) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  LOBYTE(v16) = 0;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/logo_ac_app.png", 0x1Bu);
  LOBYTE(v16) = 3;
  v5 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v16) = 4;
  this->backTexture.kid = v5->kid;
  if ( &this->backTexture.fileName != &v5->fileName )
    std::wstring::assign(&this->backTexture.fileName, &v5->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v16) = 3;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v16) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v6 = this->backTexture.kid;
  if ( v6 )
    v7 = v6[10];
  else
    v7 = 0;
  if ( v6 )
    v8 = v6[9];
  else
    v8 = 0;
  v9 = (float)v7;
  ksgui::Form::setSize(this, (float)v8, v9);
  ksgui::Form::setAutoHideMode(this, 1);
}
