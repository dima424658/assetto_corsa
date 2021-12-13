#include "actimeflow.h"
void __userpurge ACTimeFlow::ACTimeFlow(ACTimeFlow *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  const std::wstring *v4; // eax
  Font *v5; // eax
  Font *v6; // eax
  std::_Ref_count_base *v7; // edi
  GameObject *v8; // eax
  Texture *v9; // eax
  Texture *v10; // eax
  Texture *v11; // eax
  _BYTE v12[32]; // [esp-Ch] [ebp-90h] BYREF
  float h; // [esp+14h] [ebp-70h]
  std::shared_ptr<Font> v14; // [esp+34h] [ebp-50h] BYREF
  ACTimeFlow *v15; // [esp+3Ch] [ebp-48h]
  std::wstring text; // [esp+40h] [ebp-44h] BYREF
  Texture result; // [esp+58h] [ebp-2Ch] BYREF
  int v18; // [esp+80h] [ebp-4h]

  LODWORD(h) = 1;
  v15 = this;
  *(_DWORD *)&v12[28] = aSim->game->gui;
  *(_DWORD *)&v12[24] = 7;
  *(_DWORD *)&v12[20] = 0;
  *(_WORD *)&v12[4] = 0;
  std::wstring::assign((std::wstring *)&v12[4], L"TIME_FLOW", 9u);
  ksgui::Form::Form(this, a2, *(std::wstring *)&v12[4], *(ksgui::GUI **)&v12[28], SLOBYTE(h));
  v18 = 0;
  this->__vftable = (ACTimeFlow_vtbl *)&ACTimeFlow::`vftable';
  this->texDayTime.kid = 0;
  this->texDayTime.fileName._Myres = 7;
  this->texDayTime.fileName._Mysize = 0;
  this->texDayTime.fileName._Bx._Buf[0] = 0;
  this->texSessionTime.kid = 0;
  this->texSessionTime.fileName._Myres = 7;
  this->texSessionTime.fileName._Mysize = 0;
  this->texSessionTime.fileName._Bx._Buf[0] = 0;
  this->texMultiplier.kid = 0;
  this->texMultiplier.fileName._Myres = 7;
  this->texMultiplier.fileName._Mysize = 0;
  this->texMultiplier.fileName._Bx._Buf[0] = 0;
  this->tod._Myres = 7;
  this->tod._Mysize = 0;
  this->tod._Bx._Buf[0] = 0;
  this->st._Myres = 7;
  this->st._Mysize = 0;
  this->st._Bx._Buf[0] = 0;
  LOBYTE(v18) = 5;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Time of the day", 0xFu);
  LOBYTE(v18) = 6;
  this->formTitle->setText(this->formTitle, &text);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  LODWORD(h) = this;
  this->devApp = 0;
  *(_DWORD *)&v12[8] = &std::_Func_impl<std::_Callable_obj<_lambda_98eac5797f8cad175fdb11dc42275aa5_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v12[12] = this;
  *(_DWORD *)&v12[24] = &v12[8];
  LOBYTE(v18) = 5;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&aSim->evOnReplayStatusChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v12[8],
    (void *)LODWORD(h));
  this->active = 1;
  this->y = 0.0;
  this->sim = aSim;
  ksgui::Form::setSize(this, 300.0, 150.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Time of the day", 0xFu);
  LOBYTE(v18) = 8;
  v4 = acTranslate((std::wstring *)&result, &text);
  LOBYTE(v18) = 9;
  this->formTitle->setText(this->formTitle, v4);
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  LOBYTE(v18) = 5;
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v5 = (Font *)operator new(0x18u);
  v14._Ptr = v5;
  LOBYTE(v18) = 10;
  if ( v5 )
    Font::Font(v5, eFontProportional, 20.0, 0, 0);
  else
    v6 = 0;
  LOBYTE(v18) = 5;
  v14 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v14, v6);
  v7 = this->font._Rep;
  this->font = v14;
  if ( v7 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Uses, 0xFFFFFFFF) )
    {
      v7->_Destroy(v7);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v7->_Weaks) )
        v7->_Delete_this(v7);
    }
  }
  Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  h = 0.0;
  *(_DWORD *)&v12[28] = &SunAnimator `RTTI Type Descriptor';
  *(_DWORD *)&v12[24] = &GameObject `RTTI Type Descriptor';
  *(_DWORD *)&v12[20] = 7;
  *(_DWORD *)&v12[16] = 0;
  *(_WORD *)v12 = 0;
  std::wstring::assign((std::wstring *)v12, L"SUN_ANIMATOR", 0xCu);
  v8 = GameObject::getGameObject(this->sim, *(std::wstring *)v12);
  this->sunAnim = (SunAnimator *)__RTDynamicCast(v8, 0, *(_DWORD *)&v12[24], *(_DWORD *)&v12[28], LODWORD(h));
  *(_DWORD *)&v12[8] = &std::_Func_impl<std::_Callable_obj<_lambda_7001a55ed7e68206b91fedb1b8917b81_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v12[12] = this;
  *(_DWORD *)&v12[24] = &v12[8];
  LOBYTE(v18) = 5;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&aSim->game->gui->taskbar->evAppDismiss,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v12[8],
    this);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/actimeflow/inapp_time.png", 0x25u);
  LOBYTE(v18) = 12;
  v9 = ResourceStore::getTexture(this->sim->game->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v18) = 13;
  this->texDayTime.kid = v9->kid;
  if ( &this->texDayTime.fileName != &v9->fileName )
    std::wstring::assign(&this->texDayTime.fileName, &v9->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v18) = 12;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v18) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/actimeflow/inapp_sessiontime.png", 0x2Cu);
  LOBYTE(v18) = 14;
  v10 = ResourceStore::getTexture(this->sim->game->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v18) = 15;
  this->texSessionTime.kid = v10->kid;
  if ( &this->texSessionTime.fileName != &v10->fileName )
    std::wstring::assign(&this->texSessionTime.fileName, &v10->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v18) = 14;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v18) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/actimeflow/inapp_multi.png", 0x26u);
  LOBYTE(v18) = 16;
  v11 = ResourceStore::getTexture(this->sim->game->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v18) = 17;
  this->texMultiplier.kid = v11->kid;
  if ( &this->texMultiplier.fileName != &v11->fileName )
    std::wstring::assign(&this->texMultiplier.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v18) = 16;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v18) = 5;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ACTimeFlow *, _DWORD))this->scaleByMult)(this, LODWORD(this->scaleMult));
}
ACTimeFlow *ACTimeFlow::`vector deleting destructor'(ACTimeFlow *this, unsigned int a2)
{
  ACTimeFlow::~ACTimeFlow(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge ACTimeFlow::render(ACTimeFlow *this@<ecx>, int a2@<esi>, float dt)
{
  float v4; // xmm1_4
  ACTimeFlow_vtbl *v5; // eax
  __m128 v6; // xmm4
  float v7; // xmm7_4
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  float v10; // xmm6_4
  float v11; // xmm6_4
  int v12; // eax
  float v13; // xmm7_4
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  float v16; // xmm2_4
  std::wostream *v17; // ecx
  std::wostream *v18; // eax
  std::wostream *v19; // ecx
  std::wostream *v20; // eax
  std::wostream *v21; // ecx
  float v22; // xmm5_4
  __m128 v23; // xmm7
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  float v26; // xmm2_4
  float v27; // xmm2_4
  float v28; // xmm6_4
  int v29; // esi
  std::wostream *v30; // ecx
  std::wostream *v31; // ecx
  std::wostream *v32; // ecx
  SunAnimator *v33; // ecx
  std::wostream *v34; // eax
  std::wostream *v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // esi
  std::wstring *v38; // eax
  std::wstring *v39; // esi
  GLRenderer *v40; // esi
  float g; // [esp+38h] [ebp-280h]
  float _Val; // [esp+40h] [ebp-278h]
  char *_Vala; // [esp+40h] [ebp-278h]
  __int64 v44; // [esp+44h] [ebp-274h]
  const char *v45; // [esp+44h] [ebp-274h]
  const char *v46; // [esp+48h] [ebp-270h]
  float v47; // [esp+4Ch] [ebp-26Ch]
  vec2f pos; // [esp+60h] [ebp-258h] BYREF
  int v49[2]; // [esp+68h] [ebp-250h] BYREF
  float v50; // [esp+70h] [ebp-248h]
  float v51; // [esp+74h] [ebp-244h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > dayTime; // [esp+78h] [ebp-240h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > sessionTime; // [esp+128h] [ebp-190h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > multiplier; // [esp+1D8h] [ebp-E0h] BYREF
  std::wstring result; // [esp+28Ch] [ebp-2Ch] BYREF
  int v56; // [esp+2B4h] [ebp-4h]

  v49[0] = 0;
  ksgui::Control::render(this, (int)this, a2, dt, v44, v47);
  v4 = this->scaleMult;
  v5 = this->__vftable;
  v51 = v4 * 10.0;
  v50 = v4 * 65.0;
  *(float *)v49 = v4 * 20.0;
  *(float *)&v49[1] = v4 * 40.0;
  v5->localToWorld(this, &pos, (const vec2f *)v49);
  if ( this->active )
  {
    *(_DWORD *)dayTime.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)dayTime.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(dayTime.gap68);
    v56 = 0;
    v49[0] = 1;
    std::wiostream::basic_iostream<wchar_t>(&dayTime, &dayTime.gap10[8], 0);
    v56 = 1;
    *(_DWORD *)&dayTime.gap0[*(_DWORD *)(*(_DWORD *)dayTime.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v51 + *(_DWORD *)(*(_DWORD *)dayTime.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)dayTime.gap0 + 4)
                                                                         - 104;
    std::wstreambuf::wstreambuf(&dayTime.gap10[8]);
    *(_DWORD *)&dayTime.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&dayTime.gap10[64] = 0;
    *(_DWORD *)&dayTime.gap10[68] = 0;
    v56 = 3;
    *(_DWORD *)sessionTime.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)sessionTime.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(sessionTime.gap68);
    LOBYTE(v56) = 4;
    v49[0] = 3;
    std::wiostream::basic_iostream<wchar_t>(&sessionTime, &sessionTime.gap10[8], 0);
    v56 = 5;
    *(_DWORD *)&sessionTime.gap0[*(_DWORD *)(*(_DWORD *)sessionTime.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&dayTime.gap68[*(_DWORD *)(*(_DWORD *)sessionTime.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)sessionTime.gap0
                                                                                             + 4)
                                                                                 - 104;
    std::wstreambuf::wstreambuf(&sessionTime.gap10[8]);
    *(_DWORD *)&sessionTime.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&sessionTime.gap10[64] = 0;
    *(_DWORD *)&sessionTime.gap10[68] = 0;
    LOBYTE(v56) = 7;
    *(_DWORD *)multiplier.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)multiplier.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(multiplier.gap68);
    LOBYTE(v56) = 8;
    v49[0] = 7;
    std::wiostream::basic_iostream<wchar_t>(&multiplier, &multiplier.gap10[8], 0);
    v56 = 9;
    *(_DWORD *)&multiplier.gap0[*(_DWORD *)(*(_DWORD *)multiplier.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&sessionTime.gap68[*(_DWORD *)(*(_DWORD *)multiplier.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)multiplier.gap0
                                                                                                + 4)
                                                                                    - 104;
    std::wstreambuf::wstreambuf(&multiplier.gap10[8]);
    *(_DWORD *)&multiplier.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&multiplier.gap10[64] = 0;
    *(_DWORD *)&multiplier.gap10[68] = 0;
    LOBYTE(v56) = 11;
    v6.m128_f32[0] = FLOAT_8388608_0;
    v7 = (float)((float)(this->sim->game->graphics->lightingSettings.angle + 80.0) * 0.0625) + 8.0;
    v8.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v7);
    v9.m128_i32[0] = LODWORD(v7) ^ LODWORD(FLOAT_N0_0) & LODWORD(v7);
    v9.m128_f32[0] = _mm_cmplt_ss(v9, v6).m128_f32[0];
    v10 = (float)(v7 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v7)))
        - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v7));
    v9.m128_f32[0] = v10 - v7;
    v11 = v10 - COERCE_FLOAT(_mm_cmpgt_ss(v9, v8).m128_u32[0] & LODWORD(FLOAT_1_0));
    v12 = (int)v11;
    v13 = (float)(v7 - v11) * 60.0;
    v14.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v13);
    v9.m128_i32[0] = LODWORD(v13) ^ LODWORD(FLOAT_N0_0) & LODWORD(v13);
    v9.m128_f32[0] = _mm_cmplt_ss(v9, v6).m128_f32[0];
    v8.m128_f32[0] = (float)(v13
                           + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v13)))
                   - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v13));
    v9.m128_f32[0] = v8.m128_f32[0] - v13;
    v15.m128_f32[0] = FLOAT_8388608_0;
    v6.m128_f32[0] = (float)(v13
                           - (float)(v8.m128_f32[0]
                                   - COERCE_FLOAT(_mm_cmpgt_ss(v9, v14).m128_u32[0] & LODWORD(FLOAT_1_0))))
                   * 60.0;
    v14.m128_i32[0] = LODWORD(FLOAT_N0_0) & v6.m128_i32[0];
    v9.m128_i32[0] = v6.m128_i32[0] ^ LODWORD(FLOAT_N0_0) & v6.m128_i32[0];
    v9.m128_f32[0] = _mm_cmplt_ss(v9, v15).m128_f32[0];
    v8.m128_f32[0] = (float)(v6.m128_f32[0] + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | v14.m128_i32[0]))
                   - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | v14.m128_i32[0]);
    v9.m128_f32[0] = v8.m128_f32[0] - v6.m128_f32[0];
    v16 = v8.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v9, v14).m128_u32[0] & LODWORD(FLOAT_1_0));
    if ( (int)v11 <= 17 )
    {
      if ( v12 >= 8 )
      {
        if ( v12 >= 10 )
          v17 = (std::wostream *)dayTime.gap10;
        else
          v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)dayTime.gap10, "0");
        v18 = (std::wostream *)std::wostream::operator<<(v17, (int)v11);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v18, v46);
        if ( (int)v13 >= 10 )
          v19 = (std::wostream *)&dayTime.gap10[8];
        else
          v19 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&dayTime.gap10[8], "0");
        v20 = (std::wostream *)std::wostream::operator<<(v19, (int)v13);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v20, v45);
        if ( (int)v16 >= 10 )
          v21 = (std::wostream *)&dayTime.gap10[4];
        else
          v21 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&dayTime.gap10[4], "0");
        std::wostream::operator<<(v21, (int)v16);
      }
      else
      {
        std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)dayTime.gap10, "8:00:00");
      }
    }
    else
    {
      std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)dayTime.gap10, "18:00:00");
    }
    v22 = (this->sim->game->gameTime.now - this->sim->game->gameTime.startTime) * 0.001;
    v23.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v22);
    v24.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v22 * 0.00027777778);
    v25.m128_i32[0] = COERCE_UNSIGNED_INT(v22 * 0.00027777778) ^ v24.m128_i32[0];
    v25.m128_f32[0] = _mm_cmplt_ss(v25, (__m128)LODWORD(FLOAT_8388608_0)).m128_f32[0];
    v26 = (float)((float)(v22 * 0.00027777778)
                + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v25.m128_i32[0] | v24.m128_i32[0]))
        - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v25.m128_i32[0] | v24.m128_i32[0]);
    v25.m128_f32[0] = v26 - (float)(v22 * 0.00027777778);
    v27 = v26 - COERCE_FLOAT(_mm_cmpgt_ss(v25, v24).m128_u32[0] & LODWORD(FLOAT_1_0));
    v25.m128_i32[0] = LODWORD(v22) ^ LODWORD(FLOAT_N0_0) & LODWORD(v22);
    LODWORD(v28) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v25, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v22);
    v25.m128_f32[0] = (float)((float)(v22 + v28) - v28) - v22;
    v29 = (int)(float)((int)(float)((float)((float)(v22 + v28) - v28)
                                  - COERCE_FLOAT(_mm_cmpgt_ss(v25, v23).m128_u32[0] & LODWORD(FLOAT_1_0)))
                     % 60);
    if ( (int)v27 >= 10 )
      v30 = (std::wostream *)sessionTime.gap10;
    else
      v30 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)sessionTime.gap10, "0");
    std::wostream::operator<<(v30, (int)v27);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&sessionTime.gap10[4], (const char *)&Manip);
    if ( (int)(float)(v22 * 0.016666668) % 60 >= 10 )
      v31 = (std::wostream *)&sessionTime.gap10[4];
    else
      v31 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&sessionTime.gap10[4], "0");
    std::wostream::operator<<(v31, (int)(float)(v22 * 0.016666668) % 60);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&sessionTime.gap10[4], (const char *)&Manip);
    if ( v29 >= 10 )
      v32 = (std::wostream *)&sessionTime.gap10[4];
    else
      v32 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&sessionTime.gap10[4], "0");
    std::wostream::operator<<(v32, v29);
    v33 = this->sunAnim;
    if ( v33 )
    {
      _Val = SunAnimator::getVelocityMultiplier(v33);
      std::wostream::operator<<(multiplier.gap10, LODWORD(_Val));
      g = SunAnimator::getVelocityMultiplier(this->sunAnim);
      v34 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
              (std::wostream *)((char *)&dayTime._Chcount + 4),
              (const char *)&Manip._Pfun + 4);
      v35 = (std::wostream *)std::wostream::operator<<(v34, LODWORD(g));
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v35, _Vala);
    }
    v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&dayTime, &result);
    v37 = &this->tod;
    v49[0] = (int)v36;
    if ( &this->tod != v36 )
    {
      if ( this->tod._Myres >= 8 )
      {
        operator delete(v37->_Bx._Ptr);
        v36 = (std::wstring *)v49[0];
      }
      this->tod._Myres = 7;
      this->tod._Mysize = 0;
      v37->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->tod, v36);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v38 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&sessionTime, &result);
    v39 = &this->st;
    v49[0] = (int)v38;
    if ( &this->st != v38 )
    {
      if ( this->st._Myres >= 8 )
      {
        operator delete(v39->_Bx._Ptr);
        v38 = (std::wstring *)v49[0];
      }
      this->st._Myres = 7;
      this->st._Mysize = 0;
      v39->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->st, v38);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    *(_DWORD *)&multiplier.gap0[*(_DWORD *)(*(_DWORD *)multiplier.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&sessionTime.gap68[*(_DWORD *)(*(_DWORD *)multiplier.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)multiplier.gap0
                                                                                                + 4)
                                                                                    - 104;
    *(_DWORD *)&multiplier.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&multiplier.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&multiplier.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&multiplier.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(multiplier.gap68);
    *(_DWORD *)&sessionTime.gap0[*(_DWORD *)(*(_DWORD *)sessionTime.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&dayTime.gap68[*(_DWORD *)(*(_DWORD *)sessionTime.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)sessionTime.gap0
                                                                                             + 4)
                                                                                 - 104;
    *(_DWORD *)&sessionTime.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&sessionTime.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&sessionTime.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&sessionTime.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(sessionTime.gap68);
    v56 = -1;
    *(_DWORD *)&dayTime.gap0[*(_DWORD *)(*(_DWORD *)dayTime.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v51 + *(_DWORD *)(*(_DWORD *)dayTime.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)dayTime.gap0 + 4)
                                                                         - 104;
    *(_DWORD *)&dayTime.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&dayTime.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&dayTime.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&dayTime.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(dayTime.gap68);
  }
  else
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"Time paused", 0xBu);
    v56 = 12;
    Font::blitString(
      this->font._Ptr,
      (float)(pos.x + v50) - (float)(this->scaleMult * 20.0),
      pos.y - (float)(this->scaleMult * 25.0),
      &result,
      1.0,
      eAlignLeft);
    v56 = -1;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v40 = this->sim->game->gui->graphics->gl;
  GLRenderer::color4f(v40, 1.0, 1.0, 1.0, 1.0);
  GraphicsManager::setTexture(this->sim->game->gui->graphics, 0, &this->texDayTime);
  GLRenderer::quad(v40, pos.x, pos.y, this->scaleMult * 48.0, this->scaleMult * 48.0, 1, 0);
  Font::blitString(this->font._Ptr, pos.x + v50, pos.y + v51, &this->tod, this->scaleMult, eAlignLeft);
  GraphicsManager::setTexture(this->sim->game->gui->graphics, 0, &this->texSessionTime);
  GLRenderer::quad(
    v40,
    pos.x,
    (float)(this->scaleMult * 45.0) + pos.y,
    this->scaleMult * 48.0,
    this->scaleMult * 48.0,
    1,
    0);
  Font::blitString(
    this->font._Ptr,
    pos.x + v50,
    (float)((float)(this->scaleMult * 45.0) + pos.y) + v51,
    &this->st,
    this->scaleMult,
    eAlignLeft);
}
void ACTimeFlow::~ACTimeFlow(ACTimeFlow *this)
{
  this->__vftable = (ACTimeFlow_vtbl *)&ACTimeFlow::`vftable';
  if ( this->st._Myres >= 8 )
    operator delete(this->st._Bx._Ptr);
  this->st._Myres = 7;
  this->st._Mysize = 0;
  this->st._Bx._Buf[0] = 0;
  if ( this->tod._Myres >= 8 )
    operator delete(this->tod._Bx._Ptr);
  this->tod._Myres = 7;
  this->tod._Mysize = 0;
  this->tod._Bx._Buf[0] = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&this->texMultiplier);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texSessionTime);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texDayTime);
  this->__vftable = (ACTimeFlow_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
