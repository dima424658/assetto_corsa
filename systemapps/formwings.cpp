#include "formwings.h"
void FormWings::FormWings(FormWings *this, CarAvatar *a_car)
{
  const std::wstring *v3; // eax
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  _BYTE v7[28]; // [esp-10h] [ebp-80h] BYREF
  float h; // [esp+Ch] [ebp-64h]
  std::shared_ptr<Font> v9; // [esp+24h] [ebp-4Ch] BYREF
  FormWings *v10; // [esp+2Ch] [ebp-44h]
  std::wstring text; // [esp+30h] [ebp-40h] BYREF
  std::wstring result; // [esp+48h] [ebp-28h] BYREF
  int v13; // [esp+6Ch] [ebp-4h]

  h = 0.0;
  v10 = this;
  *(_DWORD *)&v7[24] = a_car->game->gui;
  *(_DWORD *)&v7[20] = 7;
  *(_DWORD *)&v7[16] = 0;
  *(_WORD *)v7 = 0;
  std::wstring::assign((std::wstring *)v7, L"WINGS", 5u);
  ksgui::Form::Form(this, (unsigned int)a_car, *(std::wstring *)v7, *(ksgui::GUI **)&v7[24], SLOBYTE(h));
  v13 = 0;
  LODWORD(h) = 5;
  this->__vftable = (FormWings_vtbl *)&FormWings::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Wings", LODWORD(h));
  LOBYTE(v13) = 1;
  v3 = acTranslate(&result, &text);
  LOBYTE(v13) = 2;
  this->formTitle->setText(this->formTitle, v3);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v13) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  LODWORD(h) = 24;
  this->car = a_car;
  v4 = (Font *)operator new(LODWORD(h));
  v9._Ptr = v4;
  LOBYTE(v13) = 3;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 12.0, 0, 0);
  else
    v5 = 0;
  LOBYTE(v13) = 0;
  v9 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v9, v5);
  v6 = this->font._Rep;
  this->font = v9;
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  ksgui::Form::setSize(this, 400.0, 600.0);
  *(_DWORD *)&v7[4] = &std::_Func_impl<std::_Callable_obj<_lambda_658c70aa79bc230d452be7da80b18909_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v7[8] = this;
  *(_DWORD *)&v7[20] = &v7[4];
  LOBYTE(v13) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->car->sim->renderFinishedNodeEvent->evOnRender,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v7[4],
    this);
}
void __userpurge FormWings::render(FormWings *this@<ecx>, int a2@<esi>, float dt)
{
  Font *v4; // ecx
  FormWings_vtbl *v5; // eax
  const std::wstring *v6; // eax
  CarAvatar *v7; // eax
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v8; // xmm0
  WingState *v9; // esi
  WingState *v10; // edi
  int v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  std::wostream *v18; // eax
  FormWings *v19; // edi
  const std::wstring *v20; // eax
  std::wstring *v21; // eax
  int v22; // ecx
  std::wostream *v23; // eax
  std::wostream *v24; // eax
  std::wostream *v25; // eax
  const std::wstring *v26; // eax
  int x_4; // [esp+30h] [ebp-174h]
  const char *x_4a; // [esp+30h] [ebp-174h]
  int x_4b; // [esp+30h] [ebp-174h]
  const char *x_4c; // [esp+30h] [ebp-174h]
  const char *g; // [esp+34h] [ebp-170h]
  int b; // [esp+38h] [ebp-16Ch]
  const char *ba; // [esp+38h] [ebp-16Ch]
  int bb; // [esp+38h] [ebp-16Ch]
  __int64 v35; // [esp+40h] [ebp-164h]
  int v36; // [esp+40h] [ebp-164h]
  float v37; // [esp+48h] [ebp-15Ch]
  __int64 x; // [esp+54h] [ebp-150h] BYREF
  float v39; // [esp+5Ch] [ebp-148h] BYREF
  float v40; // [esp+60h] [ebp-144h] BYREF
  int v41; // [esp+64h] [ebp-140h] BYREF
  int v42; // [esp+68h] [ebp-13Ch] BYREF
  int v43; // [esp+6Ch] [ebp-138h] BYREF
  float v44; // [esp+70h] [ebp-134h] BYREF
  int v45; // [esp+74h] [ebp-130h] BYREF
  FormWings *v46; // [esp+78h] [ebp-12Ch]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v47; // [esp+7Ch] [ebp-128h] BYREF
  std::wstring text; // [esp+12Ch] [ebp-78h] BYREF
  std::wstring v49; // [esp+144h] [ebp-60h] BYREF
  std::wstring result; // [esp+15Ch] [ebp-48h] BYREF
  __m128i i; // [esp+174h] [ebp-30h]
  int v52; // [esp+1A0h] [ebp-4h]

  v46 = this;
  text._Bx._Ptr = 0;
  ksgui::Control::render(this, (int)this, a2, dt, v35, v37);
  v4 = this->font._Ptr;
  v39 = 30.0;
  v45 = 0;
  Font::setColor(v4, 1.0, 1.0, 0.0, 1.0);
  v5 = this->__vftable;
  *(_QWORD *)text._Bx._Buf = 0x41F0000041200000i64;
  v5->localToWorld(this, (vec2f *)&x, (const vec2f *)&text);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"NAME", 4u);
  v52 = 0;
  v6 = acTranslate((std::wstring *)&result._Bx._Alias[8], &text);
  LOBYTE(v52) = 1;
  Font::blitString(this->font._Ptr, *(float *)&x, *((float *)&x + 1), v6, 1.0, eAlignLeft);
  if ( i.m128i_i32[1] >= 8u )
    operator delete(*(void **)&result._Bx._Alias[8]);
  v52 = -1;
  i.m128i_i64[0] = 0x700000000i64;
  result._Bx._Buf[4] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"AOA", 3u);
  v52 = 2;
  Font::blitString(this->font._Ptr, *(float *)&x + 100.0, *((float *)&x + 1), &text, 1.0, eAlignRight);
  v52 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"GH", 2u);
  v52 = 3;
  Font::blitString(this->font._Ptr, *(float *)&x + 140.0, *((float *)&x + 1), &text, 1.0, eAlignRight);
  v52 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"CL", 2u);
  v52 = 4;
  Font::blitString(this->font._Ptr, *(float *)&x + 180.0, *((float *)&x + 1), &text, 1.0, eAlignRight);
  v52 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"CD", 2u);
  v52 = 5;
  Font::blitString(this->font._Ptr, *(float *)&x + 220.0, *((float *)&x + 1), &text, 1.0, eAlignRight);
  v52 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"�", 1u);
  v52 = 6;
  Font::blitString(this->font._Ptr, *(float *)&x + 260.0, *((float *)&x + 1), &text, 1.0, eAlignRight);
  v52 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"YAW", 3u);
  v52 = 7;
  Font::blitString(this->font._Ptr, *(float *)&x + 300.0, *((float *)&x + 1), &text, 1.0, eAlignRight);
  v52 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  *(_DWORD *)&v49._Bx._Alias[8] = &v44;
  *(_DWORD *)&v49._Bx._Alias[12] = &v41;
  v49._Mysize = (unsigned int)&v42;
  v49._Myres = (unsigned int)&v40;
  result._Bx._Ptr = (wchar_t *)&v43;
  v39 = v39 + 20.0;
  *(_DWORD *)&result._Bx._Alias[4] = &v39;
  v7 = this->car;
  *(_QWORD *)v49._Bx._Buf = __PAIR64__(&v45, (unsigned int)this);
  v8 = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_mm_load_si128((const __m128i *)&v49);
  v44 = 0.0;
  v43 = 0;
  v41 = 0;
  v40 = 0.0;
  v42 = 0;
  v9 = v7->wingsStatus._Mylast;
  v10 = v7->wingsStatus._Myfirst;
  *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&result._Bx + 8) = v8;
  for ( i = _mm_load_si128((const __m128i *)&v49._Mysize); v10 != v9; ++v10 )
    lambda_688874ebe683a9e63fed80aceac55e50_::operator()(
      (FormWings::render::__l14::<lambda_688874ebe683a9e63fed80aceac55e50> *)&result._Bx._Alias[8],
      v10);
  *(_DWORD *)v47.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v47.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v47.gap68);
  text._Mysize = 1;
  std::wiostream::basic_iostream<wchar_t>(v47.gap10, &v47.gap10[24], 0);
  *(_DWORD *)&v47.gap10[*(_DWORD *)(*(_DWORD *)v47.gap10 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v47._Chcount + *(_DWORD *)(*(_DWORD *)v47.gap10 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v47.gap10 + 4)
                                                                                 - 104;
  std::wstreambuf::wstreambuf(&v47.gap10[24]);
  *(_DWORD *)&v47.gap10[24] = &std::wstringbuf::`vftable';
  *(_DWORD *)v47.gap60 = 0;
  *(_DWORD *)&v47.gap60[4] = 0;
  v11 = std::setprecision(&text._Mysize, 2, 0);
  (*(void (__cdecl **)(_BYTE *, _DWORD, _DWORD))v11)(
    &v47.gap10[*(_DWORD *)(*(_DWORD *)&v47.gap10[16] + 4) + 16],
    *(_DWORD *)(v11 + 8),
    *(_DWORD *)(v11 + 12));
  std::wostream::operator<<(&v47.gap10[16], std::fixed);
  v36 = v45;
  b = (int)(float)((float)(*(float *)v47.gap0 / v44) * 100.0);
  x_4 = *(_DWORD *)&v47.gap0[4];
  v12 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v47.gap10[16], "TOT CL:");
  v13 = (std::wostream *)std::wostream::operator<<(v12, x_4);
  v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, x_4a);
  v15 = (std::wostream *)std::wostream::operator<<(v14, " @ ");
  v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v15, g);
  v17 = (std::wostream *)std::wostream::operator<<(v16, b);
  v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v17, ba);
  std::wostream::operator<<(v18, v36);
  v19 = v46;
  Font::setColor(v46->font._Ptr, 1.0, 1.0, 0.0, 1.0);
  v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v47,
          (std::wstring *)&result._Bx._Alias[8]);
  LOBYTE(v52) = 12;
  Font::blitString(v19->font._Ptr, *(float *)&x + 10.0, *((float *)&x + 1) + 540.0, v20, 1.0, eAlignLeft);
  LOBYTE(v52) = 11;
  if ( i.m128i_i32[1] >= 8u )
    operator delete(*(void **)&result._Bx._Alias[8]);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v52) = 13;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v47.gap10[8]);
  v21 = &text;
  if ( text._Myres >= 8 )
    v21 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v47.gap10[8], v21->_Bx._Buf, text._Mysize, *(int *)&v47.gap10[68]);
  LOBYTE(v52) = 11;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  bb = v22;
  x_4b = (int)v40;
  v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v47.gap10, "TOT(KG) DOWNF: ");
  v24 = (std::wostream *)std::wostream::operator<<(v23, x_4b);
  v25 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v24, x_4c);
  std::wostream::operator<<(v25, bb);
  v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v47, &v49);
  LOBYTE(v52) = 14;
  Font::blitString(v19->font._Ptr, *(float *)&x + 10.0, *((float *)&x + 1) + 555.0, v26, 1.0, eAlignLeft);
  if ( v49._Myres >= 8 )
    operator delete(v49._Bx._Ptr);
  *(_DWORD *)&v47.gap0[*(_DWORD *)(*(_DWORD *)v47.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(FormWings **)((char *)&v46 + *(_DWORD *)(*(_DWORD *)v47.gap0 + 4)) = (FormWings *)(*(_DWORD *)(*(_DWORD *)v47.gap0
                                                                                                 + 4)
                                                                                     - 104);
  *(_DWORD *)&v47.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v47.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v47.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v47.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v47.gap68);
}
void FormWings::onRenderNode(FormWings *this, const OnNodeRenderEvent *ev)
{
  GraphicsManager *v3; // ecx
  GLRenderer *v4; // ebp
  CarAvatar *v5; // eax
  WingData *v6; // ebx
  WingData *i; // esi
  int v8; // esi
  int v9; // ebx
  CarAvatar *v10; // ecx
  WingData *v11; // eax
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  CarAvatar *v17; // ecx
  WingState *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  WingData *v22; // eax
  float v23; // xmm6_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  FormWings::onRenderNode::__l12::<lambda_ad449b5959aa2ecefc91e9886e575a88> v29; // [esp+1Ch] [ebp-18h] BYREF
  float v30; // [esp+24h] [ebp-10h]
  float v; // [esp+28h] [ebp-Ch] BYREF
  float v32; // [esp+2Ch] [ebp-8h]
  float v33; // [esp+30h] [ebp-4h]
  const OnNodeRenderEvent *eva; // [esp+38h] [ebp+4h]

  if ( this->visible
    && this->car->physicsInfo.wingData._Myfirst != this->car->physicsInfo.wingData._Mylast
    && ev->renderContext->meshFilter->passID == Opaque )
  {
    v3 = this->gui->graphics;
    v4 = v3->gl;
    GraphicsManager::setDepthMode(v3, eDepthOff);
    GLRenderer::color3f(v4, 0.0, 1.0, 0.0);
    v5 = this->car;
    v29.gl = v4;
    v29.__this = this;
    v6 = v5->physicsInfo.wingData._Mylast;
    for ( i = v5->physicsInfo.wingData._Myfirst; i != v6; ++i )
      lambda_ad449b5959aa2ecefc91e9886e575a88_::operator()(&v29, i);
    GLRenderer::begin(v4, eLines, 0);
    GLRenderer::color3f(v4, 5.0, 0.0, 5.0);
    eva = 0;
    if ( this->car->wingsStatus._Mylast - this->car->wingsStatus._Myfirst )
    {
      v8 = 0;
      v9 = 0;
      do
      {
        v10 = this->car;
        v11 = v10->physicsInfo.wingData._Myfirst;
        v29.gl = 0;
        v29.__this = 0;
        v30 = 0.0;
        v12 = v11[v8].position.x;
        v13 = v11[v8].position.y;
        v14 = v11[v8].position.z;
        v15 = (float)((float)((float)(v10->physicsState.worldMatrix.M12 * v12)
                            + (float)(v10->physicsState.worldMatrix.M22 * v13))
                    + (float)(v10->physicsState.worldMatrix.M32 * v14))
            + v10->physicsState.worldMatrix.M42;
        v16 = (float)((float)((float)(v10->physicsState.worldMatrix.M13 * v12)
                            + (float)(v10->physicsState.worldMatrix.M23 * v13))
                    + (float)(v10->physicsState.worldMatrix.M33 * v14))
            + v10->physicsState.worldMatrix.M43;
        *(float *)&v29.gl = (float)((float)((float)(v10->physicsState.worldMatrix.M21 * v13)
                                          + (float)(v12 * v10->physicsState.worldMatrix.M11))
                                  + (float)(v10->physicsState.worldMatrix.M31 * v14))
                          + v10->physicsState.worldMatrix.M41;
        *(float *)&v29.__this = v15;
        v30 = v16;
        GLRenderer::vertex3fv(v4, (const float *)&v29);
        v17 = this->car;
        v18 = v17->wingsStatus._Myfirst;
        v19 = v18[v9].liftVector.x;
        v20 = v18[v9].liftVector.y;
        v21 = v18[v9].liftVector.z;
        v22 = v17->physicsInfo.wingData._Myfirst;
        v23 = v22[v8].position.x + (float)(v19 * 0.001);
        v24 = v22[v8].position.z;
        v25 = v22[v8].position.y + (float)(v20 * 0.001);
        v = 0.0;
        v32 = 0.0;
        v33 = 0.0;
        v26 = v24 + (float)(v21 * 0.001);
        v27 = (float)((float)((float)(v17->physicsState.worldMatrix.M22 * v25)
                            + (float)(v17->physicsState.worldMatrix.M12 * v23))
                    + (float)(v17->physicsState.worldMatrix.M32 * v26))
            + v17->physicsState.worldMatrix.M42;
        v28 = (float)((float)((float)(v17->physicsState.worldMatrix.M23 * v25)
                            + (float)(v17->physicsState.worldMatrix.M13 * v23))
                    + (float)(v17->physicsState.worldMatrix.M33 * v26))
            + v17->physicsState.worldMatrix.M43;
        v = (float)((float)((float)(v17->physicsState.worldMatrix.M21 * v25)
                          + (float)(v23 * v17->physicsState.worldMatrix.M11))
                  + (float)(v17->physicsState.worldMatrix.M31 * v26))
          + v17->physicsState.worldMatrix.M41;
        v32 = v27;
        v33 = v28;
        GLRenderer::vertex3fv(v4, &v);
        ++v9;
        eva = (const OnNodeRenderEvent *)((char *)eva + 1);
        ++v8;
      }
      while ( (unsigned int)eva < this->car->wingsStatus._Mylast - this->car->wingsStatus._Myfirst );
    }
    GLRenderer::end(v4);
    GraphicsManager::setDepthMode(this->gui->graphics, eDepthNormal);
  }
}
