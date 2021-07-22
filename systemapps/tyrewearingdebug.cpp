#include "tyrewearingdebug.h
void TyreWearingDebug::TyreWearingDebug(TyreWearingDebug *this, Sim *aSim)
{
  const std::wstring *v3; // eax
  std::wstring v4; // [esp-14h] [ebp-74h] BYREF
  float w; // [esp+4h] [ebp-5Ch]
  float h; // [esp+8h] [ebp-58h]
  TyreWearingDebug *v7; // [esp+1Ch] [ebp-44h]
  std::wstring text; // [esp+20h] [ebp-40h] BYREF
  std::wstring result; // [esp+38h] [ebp-28h] BYREF
  int v10; // [esp+5Ch] [ebp-4h]

  h = 0.0;
  v7 = this;
  w = *(float *)&aSim->game->gui;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"TYRE_WEARING_DEBUG", 0x12u);
  ksgui::Form::Form(this, (unsigned int)aSim, v4, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v10 = 0;
  LODWORD(h) = 10;
  this->__vftable = (TyreWearingDebug_vtbl *)&TyreWearingDebug::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Tyre debug", LODWORD(h));
  LOBYTE(v10) = 1;
  v3 = acTranslate(&result, &text);
  LOBYTE(v10) = 2;
  this->formTitle->setText(this->formTitle, v3);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v10) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->sim = aSim;
  ksgui::Form::setSize(this, 250.0, 450.0);
  std::shared_ptr<Font>::operator=(&this->font, &this->gui->ksgui::Form::ksgui::Control::font);
}
void __userpurge TyreWearingDebug::render(TyreWearingDebug *this@<ecx>, int a2@<edi>, float dt)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  Car *v6; // ebx
  unsigned int v7; // esi
  long double *v8; // ebx
  const std::wstring *v9; // eax
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  int v12; // eax
  const std::wstring *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  int v16; // eax
  const std::wstring *v17; // esi
  float v18; // xmm0_4
  std::wostream *v19; // eax
  std::wostream *v20; // eax
  int v21; // eax
  const std::wstring *v22; // eax
  std::wostream *v23; // eax
  std::wostream *v24; // eax
  int v25; // eax
  const std::wstring *v26; // eax
  std::wostream *v27; // eax
  std::wostream *v28; // eax
  int v29; // eax
  const std::wstring *v30; // eax
  double ref; // [esp+3Ch] [ebp-190h]
  int ref_4; // [esp+40h] [ebp-18Ch]
  __int64 v33; // [esp+48h] [ebp-184h]
  float v34; // [esp+50h] [ebp-17Ch]
  float v35; // [esp+94h] [ebp-138h]
  int v36; // [esp+98h] [ebp-134h]
  unsigned int v37; // [esp+9Ch] [ebp-130h]
  TyreWearingDebug *v38; // [esp+A0h] [ebp-12Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v39; // [esp+A4h] [ebp-128h] BYREF
  std::wstring result; // [esp+158h] [ebp-74h] BYREF
  std::wstring text; // [esp+170h] [ebp-5Ch] BYREF
  int v42; // [esp+1C8h] [ebp-4h]

  v38 = this;
  v36 = 0;
  ksgui::Control::render(this, a2, (int)this, dt, v33, v34);
  v35 = FLOAT_30_0;
  this->font._Ptr->scale = 15.0;
  v4 = Sim::getFocusedCarIndex(this->sim);
  if ( Sim::getCar(this->sim, v4)->physicsStateProvider )
  {
    v5 = Sim::getFocusedCarIndex(this->sim);
    if ( Sim::getCar(this->sim, v5) )
    {
      v6 = *this->sim->physicsAvatar->engine.cars._Myfirst;
      if ( v6 )
      {
        v7 = 0;
        v37 = 0;
        v8 = &v6->tyres[0].status.virtualKM;
        do
        {
          *(_DWORD *)v39.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v39.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v39.gap68);
          v42 = 0;
          v36 |= 1u;
          std::wiostream::basic_iostream<wchar_t>(&v39, &v39.gap10[8], 0);
          v42 = 1;
          *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(TyreWearingDebug **)((char *)&v38 + *(_DWORD *)(*(_DWORD *)v39.gap0 + 4)) = (TyreWearingDebug *)(*(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104);
          std::wstreambuf::wstreambuf(&v39.gap10[8]);
          *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v39.gap10[64] = 0;
          *(_DWORD *)&v39.gap10[68] = 0;
          v42 = 3;
          text._Myres = 7;
          text._Mysize = 0;
          text._Bx._Buf[0] = 0;
          std::wstring::assign(&text, L"- TYRE", 6u);
          LOBYTE(v42) = 4;
          v9 = acTranslate(&result, &text);
          LOBYTE(v42) = 5;
          v10 = std::operator<<<wchar_t>((std::wostream *)v39.gap10, v9);
          v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v10, L" : ");
          v12 = std::wostream::operator<<(v11, v7);
          std::wostream::operator<<(v12);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          LOBYTE(v42) = 3;
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( text._Myres >= 8 )
            operator delete(text._Bx._Ptr);
          text._Myres = 7;
          text._Mysize = 0;
          text._Bx._Buf[0] = 0;
          std::wstring::assign(&text, L"v.KM", 4u);
          LOBYTE(v42) = 6;
          v13 = acTranslate(&result, &text);
          LOBYTE(v42) = 7;
          ref = *v8;
          v14 = std::operator<<<wchar_t>((std::wostream *)v39.gap10, v13);
          v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v14, L" : ");
          v16 = std::wostream::operator<<(v15, LODWORD(ref), HIDWORD(ref), std::endl<wchar_t,std::char_traits<wchar_t>>);
          std::wostream::operator<<(v16);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          LOBYTE(v42) = 3;
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( text._Myres >= 8 )
            operator delete(text._Bx._Ptr);
          text._Myres = 7;
          text._Mysize = 0;
          text._Bx._Buf[0] = 0;
          std::wstring::assign(&text, L"value", 5u);
          LOBYTE(v42) = 8;
          v17 = acTranslate(&result, &text);
          LOBYTE(v42) = 9;
          v18 = *v8;
          Curve::getValue((Curve *)(v8 - 58), v18);
          v19 = std::operator<<<wchar_t>((std::wostream *)v39.gap10, v17);
          v20 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v19, L" : ");
          v21 = std::wostream::operator<<(v20);
          std::wostream::operator<<(v21);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          LOBYTE(v42) = 3;
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( text._Myres >= 8 )
            operator delete(text._Bx._Ptr);
          text._Myres = 7;
          text._Mysize = 0;
          text._Bx._Buf[0] = 0;
          std::wstring::assign(&text, L"coreTemp", 8u);
          LOBYTE(v42) = 10;
          v22 = acTranslate(&result, &text);
          LOBYTE(v42) = 11;
          v23 = std::operator<<<wchar_t>((std::wostream *)v39.gap10, v22);
          v24 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v23, L" : ");
          v25 = std::wostream::operator<<(v24);
          std::wostream::operator<<(v25);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          LOBYTE(v42) = 3;
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( text._Myres >= 8 )
            operator delete(text._Bx._Ptr);
          text._Myres = 7;
          text._Mysize = 0;
          text._Bx._Buf[0] = 0;
          std::wstring::assign(&text, L"active", 6u);
          LOBYTE(v42) = 12;
          v26 = acTranslate(&result, &text);
          LOBYTE(v42) = 13;
          ref_4 = *((unsigned __int8 *)v8 + 332);
          v27 = std::operator<<<wchar_t>((std::wostream *)v39.gap10, v26);
          v28 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v27, L" : ");
          v29 = std::wostream::operator<<(v28, ref_4, std::endl<wchar_t,std::char_traits<wchar_t>>);
          std::wostream::operator<<(v29);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          LOBYTE(v42) = 3;
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( text._Myres >= 8 )
            operator delete(text._Bx._Ptr);
          v30 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &result);
          LOBYTE(v42) = 14;
          Font::blitString(v38->font._Ptr, v38->rect.left + 30.0, v38->rect.top + v35, v30, 1.0, eAlignLeft);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          v42 = -1;
          result._Bx._Buf[0] = 0;
          result._Myres = 7;
          result._Mysize = 0;
          v35 = v35 + 100.0;
          *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(TyreWearingDebug **)((char *)&v38 + *(_DWORD *)(*(_DWORD *)v39.gap0 + 4)) = (TyreWearingDebug *)(*(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104);
          *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
          std::wstringbuf::_Tidy((std::wstringbuf *)&v39.gap10[8]);
          std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[8]);
          std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[16]);
          std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v39.gap68);
          v8 += 204;
          v7 = v37 + 1;
          v37 = v7;
        }
        while ( v7 < 4 );
      }
    }
  }
}
