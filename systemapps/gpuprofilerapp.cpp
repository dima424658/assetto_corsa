#include "gpuprofilerapp.h"
void __userpurge GPUProfilerApp::GPUProfilerApp(GPUProfilerApp *this@<ecx>, unsigned int a2@<ebx>, GraphicsManager *graphics, ksgui::GUI *igui)
{
  const std::wstring *v5; // eax
  std::wstring v6; // [esp-14h] [ebp-70h] BYREF
  float w; // [esp+4h] [ebp-58h]
  float h; // [esp+8h] [ebp-54h]
  GPUProfilerApp *v9; // [esp+18h] [ebp-44h]
  std::wstring text; // [esp+1Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+34h] [ebp-28h] BYREF
  int v12; // [esp+58h] [ebp-4h]

  h = 0.0;
  LODWORD(w) = igui;
  v9 = this;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, L"GPU_PROFILER", 0xCu);
  ksgui::Form::Form(this, a2, v6, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v12 = 0;
  this->graphics = graphics;
  LODWORD(h) = 12;
  LODWORD(w) = L"GPU profiler";
  this->__vftable = (GPUProfilerApp_vtbl *)&GPUProfilerApp::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, (const wchar_t *)LODWORD(w), LODWORD(h));
  LOBYTE(v12) = 1;
  v5 = acTranslate(&result, &text);
  LOBYTE(v12) = 2;
  this->formTitle->setText(this->formTitle, v5);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v12) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ksgui::Form::setSize(this, 300.0, 600.0);
  std::shared_ptr<Font>::operator=(&this->font, &this->gui->ksgui::Form::ksgui::Control::font);
}
void __userpurge GPUProfilerApp::render(GPUProfilerApp *this@<ecx>, int a2@<edi>, int a3@<esi>, float dt)
{
  GPUProfilerApp *v4; // ebx
  QueryData *v5; // esi
  QueryData *v6; // ecx
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  QueryData *v10; // esi
  long double *v11; // ebx
  std::wstring *v12; // ecx
  const std::wstring *v13; // eax
  std::wstring *v14; // ecx
  std::wostream *v15; // eax
  const std::wstring *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm0_4
  std::wstring *v19; // ecx
  const std::wstring *v20; // eax
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  const std::wstring *v23; // eax
  long double b; // [esp+4Ch] [ebp-18Ch]
  int b_4; // [esp+50h] [ebp-188h]
  int b_4a; // [esp+50h] [ebp-188h]
  int b_4b; // [esp+50h] [ebp-188h]
  __int64 v28; // [esp+54h] [ebp-184h]
  int v29; // [esp+54h] [ebp-184h]
  float v30; // [esp+5Ch] [ebp-17Ch]
  float v31; // [esp+90h] [ebp-148h]
  std::vector<QueryData> res; // [esp+9Ch] [ebp-13Ch] BYREF
  long double v34; // [esp+A8h] [ebp-130h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v35; // [esp+B0h] [ebp-128h] BYREF
  std::wstring result; // [esp+160h] [ebp-78h] BYREF
  std::wstring v37; // [esp+178h] [ebp-60h] BYREF
  int v38; // [esp+1D4h] [ebp-4h]

  v4 = this;
  GPUProfiler::setActive(this->graphics->gpuProfiler, 1);
  ksgui::Control::render(v4, a2, a3, dt, v28, v30);
  GPUProfiler::getResults(v4->graphics->gpuProfiler, &res);
  v38 = 0;
  v5 = res._Myfirst;
  v6 = res._Mylast;
  if ( (unsigned int)(res._Mylast - res._Myfirst) >= 2 )
  {
    v34 = res._Mylast[-1].lastTS - res._Myfirst->lastTS;
    if ( v34 != 0.0 )
    {
      *(_DWORD *)v35.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v35.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v35.gap68);
      LOBYTE(v38) = 1;
      std::wiostream::basic_iostream<wchar_t>(&v35, &v35.gap10[8], 0);
      v38 = 2;
      *(_DWORD *)&v35.gap0[*(_DWORD *)(*(_DWORD *)v35.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&v34 + *(_DWORD *)(*(_DWORD *)v35.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v35.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v35.gap10[8]);
      *(_DWORD *)&v35.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v35.gap10[64] = 0;
      *(_DWORD *)&v35.gap10[68] = 0;
      LOBYTE(v38) = 4;
      v7 = std::setprecision(&v37, 2, 0);
      v8 = std::wostream::operator<<(v35.gap10, std::fixed);
      if ( v8 )
        v9 = v8 + *(_DWORD *)(*(_DWORD *)v8 + 4);
      else
        v9 = 0;
      (*(void (__cdecl **)(int, _DWORD, _DWORD))v7)(v9, *(_DWORD *)(v7 + 8), *(_DWORD *)(v7 + 12));
      v31 = FLOAT_60_0;
      Font::setColor(v4->font._Ptr, 1.0, 1.0, 1.0, 1.0);
      v10 = res._Mylast;
      if ( res._Myfirst == res._Mylast )
      {
        v18 = FLOAT_60_0;
        v17 = FLOAT_30_0;
      }
      else
      {
        v11 = &res._Myfirst->lastResult;
        *(double *)v37._Bx._Buf = 1.0 / v34;
        do
        {
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          std::wstring::assign(&result, word_17BE9D8, 0);
          LOBYTE(v38) = 5;
          if ( (v35.gap10[68] & 1) != 0 )
            operator delete(**(void ***)&v35.gap10[20]);
          std::wstreambuf::setg(&v35.gap10[8], 0, 0, 0);
          std::wstreambuf::setp(&v35.gap10[8], 0, 0);
          v12 = &result;
          *(_DWORD *)&v35.gap10[64] = 0;
          b_4 = *(_DWORD *)&v35.gap10[68] & 0xFFFFFFFE;
          if ( result._Myres >= 8 )
            v12 = (std::wstring *)result._Bx._Ptr;
          *(_DWORD *)&v35.gap10[68] &= 0xFFFFFFFE;
          std::wstringbuf::_Init((std::wstringbuf *)&v35.gap10[8], v12->_Bx._Buf, result._Mysize, b_4);
          LOBYTE(v38) = 4;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          std::wostream::operator<<(v35.gap10, *(_DWORD *)v11, *((_DWORD *)v11 + 1), v29);
          Font::blitString(
            this->font._Ptr,
            this->rect.left + 10.0,
            v31 + this->rect.top,
            (const std::wstring *)(v11 + 2),
            1.0,
            eAlignLeft);
          v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v35, &result);
          LOBYTE(v38) = 6;
          Font::blitString(this->font._Ptr, this->rect.left + 170.0, v31 + this->rect.top, v13, 1.0, eAlignLeft);
          LOBYTE(v38) = 4;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          std::wstring::assign(&result, word_17BE9D8, 0);
          LOBYTE(v38) = 7;
          if ( (v35.gap10[68] & 1) != 0 )
            operator delete(**(void ***)&v35.gap10[20]);
          std::wstreambuf::setg(&v35.gap10[8], 0, 0, 0);
          std::wstreambuf::setp(&v35.gap10[8], 0, 0);
          v14 = &result;
          *(_DWORD *)&v35.gap10[64] = 0;
          b_4a = *(_DWORD *)&v35.gap10[68] & 0xFFFFFFFE;
          if ( result._Myres >= 8 )
            v14 = (std::wstring *)result._Bx._Ptr;
          *(_DWORD *)&v35.gap10[68] &= 0xFFFFFFFE;
          std::wstringbuf::_Init((std::wstringbuf *)&v35.gap10[8], v14->_Bx._Buf, result._Mysize, b_4a);
          LOBYTE(v38) = 4;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          v15 = (std::wostream *)std::wostream::operator<<(v35.gap10, (int)(*(double *)v37._Bx._Buf * *v11 * 100.0));
          std::operator<<<wchar_t,std::char_traits<wchar_t>>(v15, "%");
          v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v35, &result);
          LOBYTE(v38) = 8;
          Font::blitString(this->font._Ptr, this->rect.left + 250.0, v31 + this->rect.top, v16, 1.0, eAlignLeft);
          LOBYTE(v38) = 4;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          v11 += 6;
          v17 = FLOAT_30_0;
          v18 = v31 + 30.0;
          v31 = v31 + 30.0;
        }
        while ( v11 - 1 != (long double *)v10 );
        v4 = this;
      }
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, word_17BE9D8, 0);
      LOBYTE(v38) = 9;
      if ( (v35.gap10[68] & 1) != 0 )
        operator delete(**(void ***)&v35.gap10[20]);
      std::wstreambuf::setg(&v35.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v35.gap10[8], 0, 0);
      v19 = &result;
      *(_DWORD *)&v35.gap10[64] = 0;
      b_4b = *(_DWORD *)&v35.gap10[68] & 0xFFFFFFFE;
      if ( result._Myres >= 8 )
        v19 = (std::wstring *)result._Bx._Ptr;
      *(_DWORD *)&v35.gap10[68] &= 0xFFFFFFFE;
      std::wstringbuf::_Init((std::wstringbuf *)&v35.gap10[8], v19->_Bx._Buf, result._Mysize, b_4b);
      LOBYTE(v38) = 4;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"FRAME TIME", 0xAu);
      LOBYTE(v38) = 10;
      v20 = acTranslate(&v37, &result);
      LOBYTE(v38) = 11;
      b = v34;
      v21 = std::operator<<<wchar_t>((std::wostream *)v35.gap10, v20);
      v22 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v21, ": ");
      std::wostream::operator<<(v22, LODWORD(b), HIDWORD(b), v29);
      if ( v37._Myres >= 8 )
        operator delete(v37._Bx._Ptr);
      LOBYTE(v38) = 4;
      v37._Myres = 7;
      v37._Mysize = 0;
      v37._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v35, &result);
      LOBYTE(v38) = 12;
      Font::blitString(v4->font._Ptr, v4->rect.left + 10.0, v4->rect.top + (float)(v18 + v17), v23, 1.0, eAlignLeft);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      LOBYTE(v38) = 0;
      *(_DWORD *)&v35.gap0[*(_DWORD *)(*(_DWORD *)v35.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)((char *)&v34 + *(_DWORD *)(*(_DWORD *)v35.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v35.gap0 + 4) - 104;
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
      v5 = res._Myfirst;
      v6 = res._Mylast;
    }
  }
  if ( v5 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<QueryData>>>(v5, v6);
    operator delete(res._Myfirst);
  }
}
