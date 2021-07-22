#include "trackdescription.h
void __userpurge TrackDescription::TrackDescription(TrackDescription *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  const std::wstring *v4; // eax
  ksgui::Label *v5; // esi
  ksgui::Label *v6; // eax
  Font *v7; // eax
  Font *v8; // eax
  ksgui::Label *v9; // ecx
  volatile signed __int32 *v10; // esi
  ksgui::Label *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  _BYTE v16[28]; // [esp-10h] [ebp-80h] BYREF
  float h; // [esp+Ch] [ebp-64h]
  int _Val; // [esp+20h] [ebp-50h] BYREF
  std::shared_ptr<Font> v19; // [esp+24h] [ebp-4Ch] BYREF
  TrackDescription *v20; // [esp+2Ch] [ebp-44h]
  std::wstring text; // [esp+30h] [ebp-40h] BYREF
  std::wstring result; // [esp+48h] [ebp-28h] BYREF
  int v23; // [esp+6Ch] [ebp-4h]

  LODWORD(h) = 1;
  v20 = this;
  *(_DWORD *)&v16[24] = aSim->game->gui;
  *(_DWORD *)&v16[20] = 7;
  *(_DWORD *)&v16[16] = 0;
  *(_WORD *)v16 = 0;
  std::wstring::assign((std::wstring *)v16, L"TRACK_DESCRIPTION", 0x11u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v16, *(ksgui::GUI **)&v16[24], SLOBYTE(h));
  v23 = 0;
  LODWORD(h) = 17;
  this->__vftable = (TrackDescription_vtbl *)&TrackDescription::`vftable';
  *(_DWORD *)&v16[24] = L"Track Description";
  this->sim = aSim;
  *(_WORD *)&this->devApp = 256;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v16[24], LODWORD(h));
  LOBYTE(v23) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v23) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v23) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Form::setSize(this, 450.0, 80.0);
  v5 = (ksgui::Label *)operator new(0x11Cu);
  _Val = (int)v5;
  LOBYTE(v23) = 3;
  if ( v5 )
  {
    h = *(float *)&this->sim->game->gui;
    *(_DWORD *)&v16[24] = 7;
    *(_DWORD *)&v16[20] = 0;
    *(_WORD *)&v16[4] = 0;
    std::wstring::assign((std::wstring *)&v16[4], L"TRACK_SECTION_DESCRIPTION", 0x19u);
    ksgui::Label::Label(v5, *(std::wstring *)&v16[4], (ksgui::GUI *)LODWORD(h));
  }
  else
  {
    v6 = 0;
  }
  LOBYTE(v23) = 0;
  LODWORD(h) = 24;
  this->sectionDescription = v6;
  v7 = (Font *)operator new(LODWORD(h));
  v19._Ptr = v7;
  LOBYTE(v23) = 4;
  if ( v7 )
    Font::Font(v7, eFontProportional, 30.0, 0, 0);
  else
    v8 = 0;
  LOBYTE(v23) = 0;
  v19 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v19, v8);
  v9 = this->sectionDescription;
  v10 = (volatile signed __int32 *)v9->font._Rep;
  v9->font = v19;
  if ( v10 )
  {
    if ( !_InterlockedExchangeAdd(v10 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v10)(v10);
      if ( !_InterlockedDecrement(v10 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v10 + 4))(v10);
    }
  }
  this->sectionDescription->font._Ptr->shadowed = 1;
  v11 = this->sectionDescription;
  v12 = v11->rectBase.left;
  v13 = v11->rect.bottom - v11->rect.top;
  v14 = v11->rect.right - v11->rect.left;
  v11->rect.top = 35.0;
  v11->rect.left = 0.0;
  v15 = v13 + 35.0;
  v11->rect.right = v14;
  v11->rect.bottom = v15;
  if ( v12 == 0.0 && v11->rectBase.top == 0.0 )
  {
    v11->rectBase.left = 0.0;
    v11->rectBase.top = 35.0;
    v11->rectBase.right = v14;
    v11->rectBase.bottom = v15;
  }
  ((void (*)(ksgui::Label *, _DWORD, int))this->sectionDescription->setSize)(
    this->sectionDescription,
    this->rect.right - this->rect.left,
    1112014848);
  this->sectionDescription->fontAlign = eAlignCenter;
  _Val = (int)this->sectionDescription;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  LODWORD(h) = _Val;
  *(_DWORD *)(_Val + 148) = this;
  ((void (*)(TrackDescription *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
}
void __userpurge TrackDescription::render(TrackDescription *this@<ecx>, int a2@<edi>, float dt)
{
  unsigned int v4; // eax
  CarAvatar *v5; // eax
  const std::wstring *v6; // eax
  __int64 v7; // [esp+4h] [ebp-34h]
  std::wstring result; // [esp+Ch] [ebp-2Ch] BYREF
  int v9; // [esp+34h] [ebp-4h]

  ksgui::Control::render(this, a2, (int)this, dt, v7, *(float *)&result._Bx._Ptr);
  v4 = Sim::getFocusedCarIndex(this->sim);
  v5 = Sim::getCar(this->sim, v4);
  v6 = TrackAvatar::getSectorDescription(this->sim->track, &result, v5->physicsState.normalizedSplinePosition);
  v9 = 0;
  this->sectionDescription->setText(this->sectionDescription, v6);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
}
