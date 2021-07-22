#include "qosoverlay.h"
void QOSOverlay::QOSOverlay(QOSOverlay *this, ACClient *client)
{
  ACClient *v3; // esi
  ACClient **v4; // ebp
  ACClient *v5; // eax
  TyreTester *v6; // eax
  TyreTester *v7; // esi
  ACClient *v8; // ebx
  std::wstring v9; // [esp-10h] [ebp-40h] BYREF
  Game *v10; // [esp+8h] [ebp-28h]
  QOSOverlay *v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+2Ch] [ebp-4h]

  v11 = this;
  v3 = client;
  v10 = client->game;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"QOS_OVERLAY", 0xBu);
  GameObject::GameObject(this, v9, v10);
  v4 = (ACClient **)&this->font;
  this->__vftable = (QOSOverlay_vtbl *)&QOSOverlay::`vftable';
  this->client = v3;
  v12 = 0;
  this->font._Myptr = 0;
  LOBYTE(v12) = 1;
  v5 = (ACClient *)operator new(24);
  client = v5;
  LOBYTE(v12) = 2;
  if ( v5 )
  {
    Font::Font((Font *)v5, eFontProportional, 16.0, 0, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  LOBYTE(v12) = 1;
  if ( v4 == &client )
  {
    if ( !v7 )
      return;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart(v7);
    v10 = (Game *)v7;
  }
  else
  {
    v8 = *v4;
    *v4 = (ACClient *)v7;
    if ( !v8 )
      return;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v8);
    v10 = (Game *)v8;
  }
  operator delete(v10);
}
QOSOverlay *QOSOverlay::`scalar deleting destructor'(QOSOverlay *this, unsigned int a2)
{
  Font *v3; // edi

  this->__vftable = (QOSOverlay_vtbl *)&QOSOverlay::`vftable';
  v3 = this->font._Myptr;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v3);
    operator delete(v3);
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void QOSOverlay::renderHUD(QOSOverlay *this, float dt)
{
  int v3; // eax
  int v4; // edi
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  Font *v7; // ecx
  Game *v8; // eax
  const std::wstring *g; // [esp+8h] [ebp-58h]
  std::wstring v10; // [esp+20h] [ebp-40h] BYREF
  std::wstring result; // [esp+38h] [ebp-28h] BYREF
  int v12; // [esp+5Ch] [ebp-4h]

  Font::setColor(this->font._Myptr, 1.0, 1.0, 0.0, 1.0);
  v3 = ACClient::getPing(this->client, 0);
  v4 = v3;
  if ( v3 <= 70 )
  {
    Font::setColor(this->font._Myptr, 0.0, 1.0, 0.0, 1.0);
    goto LABEL_5;
  }
  if ( v3 <= 120 )
  {
    Font::setColor(this->font._Myptr, 1.0, 1.0, 0.0, 1.0);
LABEL_5:
    if ( v4 <= 120 )
      goto LABEL_7;
  }
  Font::setColor(this->font._Myptr, 1.0, 0.0, 0.0, 1.0);
LABEL_7:
  v5 = std::to_wstring(&result, v4);
  v12 = 0;
  v6 = std::operator+<wchar_t>(&v10, L"P:", v5);
  v7 = this->font._Myptr;
  g = v6;
  v8 = this->game;
  LOBYTE(v12) = 1;
  Font::blitString(v7, (float)(v8->graphics->videoSettings.width - 50), 0.0, g, 1.0, eAlignLeft);
  if ( v10._Myres >= 8 )
    operator delete(v10._Bx._Ptr);
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
}
