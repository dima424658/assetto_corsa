#include "racefuelmonitor.h
void __userpurge RaceFuelMonitor::RaceFuelMonitor(RaceFuelMonitor *this@<ecx>, unsigned int a2@<ebx>, Sim *sim)
{
  const std::wstring *v4; // eax
  Font *v5; // eax
  Font *v6; // eax
  std::_Ref_count_base *v7; // esi
  std::wstring v8; // [esp-10h] [ebp-7Ch] BYREF
  float w; // [esp+8h] [ebp-64h]
  float h; // [esp+Ch] [ebp-60h]
  std::shared_ptr<Font> v11; // [esp+20h] [ebp-4Ch] BYREF
  RaceFuelMonitor *v12; // [esp+28h] [ebp-44h]
  std::wstring text; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+44h] [ebp-28h] BYREF
  int v15; // [esp+68h] [ebp-4h]

  h = 0.0;
  v12 = this;
  w = *(float *)&sim->game->gui;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"RACE_FUEL_MONITOR", 0x11u);
  ksgui::Form::Form(this, a2, v8, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v15 = 0;
  LODWORD(h) = 17;
  this->__vftable = (RaceFuelMonitor_vtbl *)&RaceFuelMonitor::`vftable';
  LODWORD(w) = L"Race Fuel Monitor";
  this->sim = sim;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, (const wchar_t *)LODWORD(w), LODWORD(h));
  LOBYTE(v15) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v15) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v15) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v5 = (Font *)operator new(0x18u);
  v11._Ptr = v5;
  LOBYTE(v15) = 3;
  if ( v5 )
    Font::Font(v5, eFontMonospaced, 14.0, 1, 1);
  else
    v6 = 0;
  LOBYTE(v15) = 0;
  v11 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v11, v6);
  v7 = this->font._Rep;
  this->font = v11;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Uses, 0xFFFFFFFF) )
    {
      v7->_Destroy(v7);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v7->_Weaks) )
        v7->_Delete_this(v7);
    }
  }
  ksgui::Form::setSize(this, 400.0, 800.0);
  this->devApp = 1;
}
void RaceFuelMonitor::render(RaceFuelMonitor *this, float dt)
{
  int v3; // edi
  unsigned int v4; // edx
  float v5; // xmm0_4
  Sim *v6; // ecx
  int v7; // eax
  CarAvatar *v8; // eax
  CarAvatar *v9; // ebx
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // edi
  char *v15; // ecx
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  std::wostream *v18; // edi
  char *v19; // ecx
  bool v20; // al
  Font *v21; // ecx
  const std::wstring *v22; // eax
  int v23; // [esp+1Ch] [ebp-144h]
  int g; // [esp+28h] [ebp-138h]
  const char *b; // [esp+2Ch] [ebp-134h]
  char *_Val; // [esp+30h] [ebp-130h]
  __int64 v27; // [esp+34h] [ebp-12Ch]
  int v28; // [esp+34h] [ebp-12Ch]
  float v29; // [esp+3Ch] [ebp-124h]
  int v30; // [esp+4Ch] [ebp-114h]
  float y; // [esp+50h] [ebp-110h]
  unsigned int v32; // [esp+54h] [ebp-10Ch]
  int v33; // [esp+58h] [ebp-108h]
  float x; // [esp+5Ch] [ebp-104h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v35; // [esp+60h] [ebp-100h] BYREF
  int v36[5]; // [esp+120h] [ebp-40h] BYREF
  std::wstring result; // [esp+134h] [ebp-2Ch] BYREF
  int v38; // [esp+154h] [ebp-Ch]
  int v39; // [esp+15Ch] [ebp-4h]

  v3 = 0;
  v33 = 0;
  ksgui::Control::render(this, 0, (int)this, dt, v27, v29);
  v4 = 0;
  v5 = this->rect.left + 10.0;
  v6 = this->sim;
  v32 = 0;
  v7 = (char *)v6->cars._Mylast - (char *)v6->cars._Myfirst;
  x = v5;
  y = this->rect.top + 80.0;
  if ( v7 >> 2 )
  {
    do
    {
      v8 = Sim::getCar(v6, v4);
      *(_DWORD *)v35.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      v9 = v8;
      *(_DWORD *)v35.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v35.gap68);
      v39 = 0;
      v33 = v3 | 1;
      std::wiostream::basic_iostream<wchar_t>(&v35, &v35.gap10[8], 0);
      v38 = 1;
      *(int *)((char *)&v33 + *(_DWORD *)(v33 + 4)) = (int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(unsigned int *)((char *)&v32 + *(_DWORD *)(v33 + 4)) = *(_DWORD *)(v33 + 4) - 104;
      std::wstreambuf::wstreambuf(v35.gap10);
      *(_DWORD *)v35.gap10 = &std::wstringbuf::`vftable';
      *(_DWORD *)&v35.gap10[56] = 0;
      *(_DWORD *)&v35.gap10[60] = 0;
      v38 = 3;
      std::wostream::operator<<(&v35._Chcount, std::fixed);
      v23 = (int)v9->physicsState.fuel;
      v10 = std::operator<<<wchar_t>((std::wostream *)&v35._Chcount, &v9->driverInfo.name);
      v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v10, " F:");
      v12 = (std::wostream *)std::wostream::operator<<(v11, v23);
      v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v12, b);
      std::wostream::operator<<(v13, v28);
      v30 = std::setprecision(v36, 2, 0);
      v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v35.gap10, " FxL:");
      if ( v14 )
        v15 = &v14->gap0[*(_DWORD *)(*(_DWORD *)v14->gap0 + 4)];
      else
        v15 = 0;
      (*(void (__cdecl **)(char *, _DWORD, _DWORD))v30)(v15, *(_DWORD *)(v30 + 8), *(_DWORD *)(v30 + 12));
      *(float *)&_Val = v9->physicsState.fuel / v9->physicsState.fuelLaps;
      std::wostream::operator<<(v14);
      std::setprecision(&v35.gap68[68], 2, 0);
      g = CarAvatar::getAILapsToComplete(v9);
      v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)((char *)&v35._Chcount + 4), " LTC:");
      v17 = (std::wostream *)std::wostream::operator<<(v16, g);
      v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v17, _Val);
      if ( v18 )
        v19 = &v18->gap0[*(_DWORD *)(*(_DWORD *)v18->gap0 + 4)];
      else
        v19 = 0;
      (*(void (__cdecl **)(char *, _DWORD, _DWORD))v30)(v19, *(_DWORD *)(v30 + 8), *(_DWORD *)(v30 + 12));
      std::wostream::operator<<(v18);
      v20 = CarAvatar::isRequestingPitStop(v9);
      v21 = this->font._Ptr;
      if ( v20 )
        Font::setColor(v21, 1.0, 0.0, 0.0, 1.0);
      else
        Font::setColor(v21, 1.0, 1.0, 1.0, 1.0);
      v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v35, &result);
      LOBYTE(v39) = 4;
      Font::blitString(this->font._Ptr, x, y, v22, 1.0, eAlignLeft);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v39 = -1;
      result._Bx._Buf[0] = 0;
      result._Myres = 7;
      result._Mysize = 0;
      y = y + 30.0;
      *(_DWORD *)&v35.gap0[*(_DWORD *)(*(_DWORD *)v35.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&x + *(_DWORD *)(*(_DWORD *)v35.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v35.gap0 + 4) - 104;
      *(_DWORD *)&v35.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v35.gap10[68] & 1) != 0 )
        operator delete(**(void ***)&v35.gap10[20]);
      std::wstreambuf::setg(&v35.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v35.gap10[8], 0, 0);
      *(_DWORD *)&v35.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v35.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v35.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v35.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v35.gap68);
      v6 = this->sim;
      v3 = v33;
      v4 = v32 + 1;
      v32 = v4;
    }
    while ( v4 < v6->cars._Mylast - v6->cars._Myfirst );
  }
}
