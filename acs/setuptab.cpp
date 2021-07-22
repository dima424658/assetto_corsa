#include "setuptab.h"
void SetupTab::SetupTab(SetupTab *this, std::wstring aname, ksgui::GUI *aGui, Sim *sim)
{
  std::wstring *v5; // edi
  std::wstring *v6; // eax
  std::wstring *v7; // ecx
  std::wstring *v8; // eax
  ksgui::Label *v9; // ebx
  ksgui::Label *v10; // eax
  bool v11; // cf
  std::wstring v12; // [esp-14h] [ebp-60h] BYREF
  float top; // [esp+4h] [ebp-48h]
  ksgui::Label *v14; // [esp+18h] [ebp-34h]
  SetupTab *v15; // [esp+20h] [ebp-2Ch]
  std::wstring localized_name; // [esp+24h] [ebp-28h] BYREF
  int v17; // [esp+48h] [ebp-4h]

  v15 = this;
  v17 = 0;
  ksgui::Control::Control(this, &aname, aGui);
  this->__vftable = (SetupTab_vtbl *)&SetupTab::`vftable';
  this->items._Myfirst = 0;
  this->items._Mylast = 0;
  this->items._Myend = 0;
  this->spinners._Myfirst = 0;
  this->spinners._Mylast = 0;
  this->spinners._Myend = 0;
  v5 = &this->name;
  this->sim = sim;
  LOBYTE(v17) = 3;
  this->modifiedValues = 0;
  if ( &this->name != &aname )
    std::wstring::assign(&this->name, &aname, 0, 0xFFFFFFFF);
  acLocaleGetString(&localized_name, &this->name);
  LOBYTE(v17) = 4;
  if ( localized_name._Mysize )
  {
    v6 = &localized_name;
    if ( localized_name._Myres >= 8 )
      v6 = (std::wstring *)localized_name._Bx._Ptr;
    if ( this->name._Myres < 8 )
      v7 = &this->name;
    else
      v7 = (std::wstring *)v5->_Bx._Ptr;
    _printf("Localized %S is %S\n", v7->_Bx._Buf, v6->_Bx._Buf);
    if ( v5 != &localized_name )
      std::wstring::assign(&this->name, &localized_name, 0, 0xFFFFFFFF);
  }
  else
  {
    if ( this->name._Myres < 8 )
      v8 = &this->name;
    else
      v8 = (std::wstring *)v5->_Bx._Ptr;
    _printf("Localized %S is NOT FOUND\n", v8->_Bx._Buf);
  }
  v9 = (ksgui::Label *)operator new(284);
  v14 = v9;
  v10 = 0;
  LOBYTE(v17) = 5;
  if ( v9 )
  {
    top = *(float *)&this->gui;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, &this->name, 0, 0xFFFFFFFF);
    ksgui::Label::Label(v9, v12, (ksgui::GUI *)LODWORD(top));
  }
  LOBYTE(v17) = 4;
  this->titleLabel = v10;
  ksgui::Form::setPosition((ksgui::Form *)v10, 0.0, 4.0);
  this->titleLabel->fontAlign = eAlignCenter;
  ksgui::Control::addControl(this, this->titleLabel);
  top = 0.0;
  v12._Myres = (unsigned int)word_17BE9D8;
  *(_WORD *)&this->drawBorder = 0;
  std::wstring::assign(&this->text, (const wchar_t *)v12._Myres, LODWORD(top));
  ksgui::Form::setPosition((ksgui::Form *)this, 25.0, 65.0);
  ksgui::Control::setSize(this, 450.0, 625.0);
  ((void (*)(ksgui::Label *, _DWORD, int))this->titleLabel->setSize)(
    this->titleLabel,
    this->rect.right - this->rect.left,
    1106247680);
  ksgui::Control::setVisible(this, 1);
  v11 = localized_name._Myres < 8;
  *(_WORD *)&this->drawBorder = 256;
  this->backColor = (vec4f)_xmm;
  if ( !v11 )
    operator delete(localized_name._Bx._Ptr);
  if ( aname._Myres >= 8 )
    operator delete(aname._Bx._Ptr);
}
void SetupTab::~SetupTab(SetupTab *this)
{
  unsigned int v2; // ebx
  std::vector<SetupItemDef *> *v3; // edi
  wchar_t **v4; // esi
  std::vector<ksgui::Spinner *> *v5; // esi

  v2 = 0;
  v3 = &this->items;
  this->__vftable = (SetupTab_vtbl *)&SetupTab::`vftable';
  if ( this->items._Mylast - this->items._Myfirst )
  {
    do
    {
      v4 = (wchar_t **)v3->_Myfirst[v2];
      if ( v4 )
      {
        if ( (unsigned int)v4[23] >= 8 )
          operator delete(v4[18]);
        v4[23] = (wchar_t *)7;
        v4[22] = 0;
        *((_WORD *)v4 + 36) = 0;
        if ( (unsigned int)v4[5] >= 8 )
          operator delete(*v4);
        v4[5] = (wchar_t *)7;
        v4[4] = 0;
        *(_WORD *)v4 = 0;
        operator delete(v4);
      }
      ++v2;
    }
    while ( v2 < v3->_Mylast - v3->_Myfirst );
  }
  std::_Container_base0::_Orphan_all(v3);
  v5 = &this->spinners;
  v3->_Mylast = v3->_Myfirst;
  if ( this->spinners._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->spinners);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->spinners._Mylast = 0;
    this->spinners._Myend = 0;
  }
  if ( v3->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v3);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  ksgui::Control::~Control(this);
}
SetupTab *SetupTab::`vector deleting destructor'(SetupTab *this, unsigned int a2)
{
  SetupTab::~SetupTab(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SetupTab::addItem(SetupTab *this, SetupItemDef *item)
{
  ksgui::Spinner *v3; // ecx
  int v4; // eax
  int v5; // esi
  SetupItemDef *v6; // eax
  Font *v7; // eax
  volatile signed __int32 *v8; // ebx
  float v9; // xmm3_4
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  float v12; // xmm4_4
  float y; // xmm4_4
  __m128 v14; // xmm7
  float v15; // xmm5_4
  std::wstring *v16; // eax
  double v17; // xmm0_8
  int v18; // eax
  long double v19; // xmm0_8
  long double v20; // xmm0_8
  int v21; // eax
  SetupItemDef *v22; // eax
  SetupItemDef *v23; // eax
  _BYTE v24[28]; // [esp-Ch] [ebp-68h] BYREF
  SetupItemDef *newItem; // [esp+28h] [ebp-34h] BYREF
  volatile signed __int32 *v26; // [esp+2Ch] [ebp-30h]
  ksgui::Spinner *ns; // [esp+30h] [ebp-2Ch] BYREF
  std::wstring helpText; // [esp+34h] [ebp-28h] BYREF
  int v29; // [esp+58h] [ebp-4h]

  v3 = (ksgui::Spinner *)operator new(444);
  ns = v3;
  v29 = 0;
  if ( v3 )
  {
    ksgui::Spinner::Spinner(v3, &item->connection->name, this->gui, 1, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  ns = (ksgui::Spinner *)v5;
  v6 = (SetupItemDef *)operator new(24);
  newItem = v6;
  v29 = 1;
  if ( v6 )
    Font::Font((Font *)v6, eFontProportional, 12.0, 0, 0);
  else
    v7 = 0;
  v29 = -1;
  newItem = 0;
  v26 = 0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&newItem, v7);
  std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)(v5 + 128), (std::shared_ptr<Font> *)&newItem);
  v8 = v26;
  if ( v26 )
  {
    if ( !_InterlockedExchangeAdd(v26 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v8)(v8);
      if ( !_InterlockedExchangeAdd(v8 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v8 + 4))(v8);
    }
  }
  (*(void (**)(int, int, int))(*(_DWORD *)v5 + 28))(v5, 1127743488, 1101529088);
  v9 = (float)(item->py * 60.0) + 70.0;
  v10.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v9);
  v11.m128_i32[0] = LODWORD(v9) ^ LODWORD(FLOAT_N0_0) & LODWORD(v9);
  v11.m128_f32[0] = _mm_cmplt_ss(v11, (__m128)LODWORD(FLOAT_8388608_0)).m128_f32[0];
  v12 = (float)(v9 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v11.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v9)))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v11.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v9));
  v11.m128_f32[0] = v12 - v9;
  v11.m128_f32[0] = _mm_cmpgt_ss(v11, v10).m128_f32[0];
  v10.m128_f32[0] = (float)(item->px * 220.0) + 23.0;
  y = v12 - COERCE_FLOAT(v11.m128_i32[0] & LODWORD(FLOAT_1_0));
  v14.m128_i32[0] = LODWORD(FLOAT_N0_0) & v10.m128_i32[0];
  v11.m128_i32[0] = v10.m128_i32[0] ^ LODWORD(FLOAT_N0_0) & v10.m128_i32[0];
  LODWORD(v15) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v11, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & v10.m128_i32[0];
  v11.m128_f32[0] = (float)((float)(v10.m128_f32[0] + v15) - v15) - v10.m128_f32[0];
  ksgui::Spinner::setPosition(
    (ksgui::Spinner *)v5,
    (float)((float)(v10.m128_f32[0] + v15) - v15)
  - COERCE_FLOAT(_mm_cmpgt_ss(v11, v14).m128_u32[0] & LODWORD(FLOAT_1_0)),
    y);
  *(_BYTE *)(v5 + 317) = 1;
  v16 = &item->connection->units;
  if ( (std::wstring *)(v5 + 320) != v16 )
    std::wstring::assign((std::wstring *)(v5 + 320), v16, 0, 0xFFFFFFFF);
  *(float *)(v5 + 284) = item->connection->labelMultiplier;
  *(_DWORD *)&v24[24] = 7;
  *(_DWORD *)&v24[20] = 0;
  *(_WORD *)&v24[4] = 0;
  std::wstring::assign((std::wstring *)&v24[4], &item->name, 0, 0xFFFFFFFF);
  ksgui::Spinner::setLabelText((ksgui::Spinner *)v5, *(std::wstring *)&v24[4]);
  acLocaleGetSetupHelpText(&helpText, &item->helpKey);
  v29 = 2;
  if ( std::wstring::compare(&helpText, 0, helpText._Mysize, word_17BE9D8, 0) )
  {
    *(_DWORD *)&v24[24] = 7;
    *(_DWORD *)&v24[20] = 0;
    *(_WORD *)&v24[4] = 0;
    std::wstring::assign((std::wstring *)&v24[4], &helpText, 0, 0xFFFFFFFF);
    ksgui::PopOver::setText(*(ksgui::PopOver **)(v5 + 312), *(std::wstring *)&v24[4]);
    *(_DWORD *)&v24[24] = 7;
    *(_DWORD *)&v24[20] = 0;
    *(_WORD *)&v24[4] = 0;
    std::wstring::assign((std::wstring *)&v24[4], &item->name, 0, 0xFFFFFFFF);
    ksgui::PopOver::setLabelTitle(*(ksgui::PopOver **)(v5 + 312), *(std::wstring *)&v24[4]);
    *(_BYTE *)(v5 + 316) = 1;
  }
  else
  {
    *(_BYTE *)(v5 + 316) = 0;
  }
  if ( item->showClicksMode == eShowClicks )
  {
    v20 = item->minValue / item->step;
    *(_DWORD *)&v24[24] = 0;
    *(_DWORD *)&v24[20] = word_17BE9D8;
    *(_DWORD *)(v5 + 288) = (int)v20;
    *(_DWORD *)(v5 + 292) = (int)(item->maxValue / item->step);
    *(_DWORD *)(v5 + 296) = 1;
    std::wstring::assign((std::wstring *)(v5 + 320), *(const wchar_t **)&v24[20], *(unsigned int *)&v24[24]);
    v18 = (int)(item->connection->newValue / item->step + 0.5);
  }
  else if ( item->showClicksMode == eShowClicksAbs )
  {
    *(_DWORD *)(v5 + 288) = 0;
    v19 = item->maxValue - item->minValue;
    *(_DWORD *)&v24[24] = 0;
    *(_DWORD *)&v24[20] = word_17BE9D8;
    *(_DWORD *)(v5 + 292) = (int)(v19 / item->step);
    *(_DWORD *)(v5 + 296) = 1;
    std::wstring::assign((std::wstring *)(v5 + 320), *(const wchar_t **)&v24[20], *(unsigned int *)&v24[24]);
    *(float *)&v19 = item->minValue;
    v18 = (int)(float)((float)((float)(item->connection->newValue - *(float *)&v19) / (float)item->step) + 0.5);
  }
  else
  {
    *(_DWORD *)(v5 + 288) = (int)item->minValue;
    *(_DWORD *)(v5 + 292) = (int)item->maxValue;
    v17 = item->step;
    if ( v17 < 1.0 )
      *(_DWORD *)(v5 + 296) = 1;
    else
      *(_DWORD *)(v5 + 296) = (int)v17;
    v18 = (int)item->connection->newValue;
  }
  ksgui::Spinner::setValue((ksgui::Spinner *)v5, v18);
  v21 = ksgui::Spinner::getValue((ksgui::Spinner *)v5);
  *(_DWORD *)&v24[24] = this;
  item->defaultValue = v21;
  *(_DWORD *)v24 = &std::_Func_impl<std::_Callable_obj<_lambda_06d8555c694e659519f903dc91030213_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v24[4] = this;
  *(_DWORD *)&v24[16] = v24;
  LOBYTE(v29) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)(v5 + 300),
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v24,
    *(void **)&v24[24]);
  v22 = (SetupItemDef *)operator new(96);
  newItem = v22;
  LOBYTE(v29) = 4;
  if ( v22 )
    SetupItemDef::SetupItemDef(v22, item);
  else
    v23 = 0;
  newItem = v23;
  LOBYTE(v29) = 2;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->items,
    (ICollisionObject *const *)&newItem);
  *(_DWORD *)(v5 + 168) = newItem;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->spinners,
    (ICollisionObject *const *)&ns);
  this->addControl(this, ns);
  if ( helpText._Myres >= 8 )
    operator delete(helpText._Bx._Ptr);
}
void SetupTab::drawFrame(SetupTab *this, const ksgui::ksRect *wrect)
{
  GLRenderer *v2; // edi

  v2 = this->gui->graphics->gl;
  GLRenderer::color4f(v2, 0.25, 0.25, 0.25, 0.5);
  GLRenderer::begin(v2, eLinesStrip, 0);
  GLRenderer::vertex3f(v2, wrect->right, wrect->top, 0.0);
  GLRenderer::vertex3f(v2, wrect->right, wrect->bottom, 0.0);
  GLRenderer::vertex3f(v2, wrect->left, wrect->bottom, 0.0);
  GLRenderer::vertex3f(v2, wrect->left, wrect->top, 0.0);
  GLRenderer::vertex3f(v2, wrect->right, wrect->top, 0.0);
  GLRenderer::end(v2);
}
std::wstring *SetupTab::getStringToSave(SetupTab *this, std::wstring *result)
{
  unsigned int v3; // ebx
  int v4; // eax
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  std::wostream *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  std::wstring *v13; // [esp-8h] [ebp-E0h]
  int v14; // [esp-8h] [ebp-E0h]
  int v15; // [esp+18h] [ebp-C0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v16; // [esp+1Ch] [ebp-BCh] BYREF
  int v17; // [esp+D4h] [ebp-4h]

  *(_DWORD *)v16.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v16.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v16.gap68);
  v17 = 0;
  v15 = 2;
  std::wiostream::basic_iostream<wchar_t>(&v16, &v16.gap10[8], 0);
  v17 = 1;
  *(_DWORD *)&v16.gap0[*(_DWORD *)(*(_DWORD *)v16.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v15 + *(_DWORD *)(*(_DWORD *)v16.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v16.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v16.gap10[8]);
  *(_DWORD *)&v16.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v16.gap10[64] = 0;
  *(_DWORD *)&v16.gap10[68] = 0;
  v3 = 0;
  v4 = this->spinners._Mylast - this->spinners._Myfirst;
  v17 = 3;
  if ( v4 )
  {
    do
    {
      v13 = &this->spinners._Myfirst[v3]->name;
      v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v16.gap10, "[");
      v6 = std::operator<<<wchar_t>(v5, v13);
      v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, "]");
      std::wostream::operator<<(v7);
      v14 = ksgui::Spinner::getValue(this->spinners._Myfirst[v3]);
      v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v16.gap10, "VALUE=");
      v9 = std::wostream::operator<<(v8, v14);
      v10 = std::wostream::operator<<(v9);
      std::wostream::operator<<(v10);
      ++v3;
    }
    while ( v3 < this->spinners._Mylast - this->spinners._Myfirst );
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v16, result);
  v17 = -1;
  *(_DWORD *)&v16.gap0[*(_DWORD *)(*(_DWORD *)v16.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v15 + *(_DWORD *)(*(_DWORD *)v16.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v16.gap0 + 4) - 104;
  *(_DWORD *)&v16.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v16.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v16.gap10[8]) )
      std::wstreambuf::epptr(&v16.gap10[8]);
    else
      std::wstreambuf::egptr(&v16.gap10[8]);
    std::wstreambuf::eback(&v16.gap10[8]);
    v11 = std::wstreambuf::eback(&v16.gap10[8]);
    operator delete(v11);
  }
  std::wstreambuf::setg(&v16.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v16.gap10[8], 0, 0);
  *(_DWORD *)&v16.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v16.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v16.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v16.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v16.gap68);
  return result;
}
void SetupTab::loadFromINI(SetupTab *this, INIReader *ini, bool isFixed)
{
  unsigned int v4; // edi
  INIReader *i; // ebp
  unsigned int v6; // ebx
  ksgui::Spinner **v7; // eax
  int v8; // ebp
  ksgui::Spinner **v9; // eax
  ksgui::Spinner *v10; // eax
  std::wstring key; // [esp+18h] [ebp-28h] BYREF
  int v12; // [esp+3Ch] [ebp-4h]

  v4 = 0;
  for ( i = ini; v4 < this->spinners._Mylast - this->spinners._Myfirst; ++v4 )
  {
    v6 = v4;
    if ( INIReader::hasSection(i, &this->spinners._Myfirst[v4]->name) )
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"VALUE", 5u);
      v7 = this->spinners._Myfirst;
      v12 = 0;
      v8 = INIReader::getInt(i, &v7[v4]->name, &key);
      v12 = -1;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Bx._Buf[0] = 0;
      v9 = this->spinners._Myfirst;
      key._Mysize = 0;
      SetupTab::setValueToSpinner(this, v9[v6], isFixed, v8);
      i = ini;
    }
    else
    {
      v10 = this->spinners._Myfirst[v6];
      if ( v10->isReadOnly )
        return;
      v10->isReadOnly = 0;
    }
  }
}
void SetupTab::onVisibleChanged(SetupTab *this, bool value)
{
  CarAvatar *v3; // eax
  ksgui::Control **v4; // eax
  ksgui::Control **v5; // esi
  int v6; // edi
  unsigned int v7; // ebp
  ksgui::Spinner *v8; // eax
  ksgui::Spinner *v9; // ebx
  int v10; // eax

  if ( value )
  {
    if ( Sim::getCar(this->sim, 0)->raceEngineer._Myptr )
    {
      v3 = Sim::getCar(this->sim, 0);
      if ( RaceEngineer::getCar(v3->raceEngineer._Myptr) )
      {
        v4 = this->controls._Mylast;
        v5 = this->controls._Myfirst;
        v6 = 0;
        v7 = (unsigned int)((char *)v4 - (char *)v5 + 3) >> 2;
        if ( v5 > v4 )
          v7 = 0;
        if ( v7 )
        {
          do
          {
            v8 = (ksgui::Spinner *)__RTDynamicCast(
                                     *v5,
                                     0,
                                     &ksgui::Control `RTTI Type Descriptor',
                                     &ksgui::Spinner `RTTI Type Descriptor',
                                     0);
            v9 = v8;
            if ( v8 )
            {
              v10 = ksgui::Spinner::getValue(v8);
              ksgui::Spinner::setValue(v9, v10);
            }
            ++v6;
            ++v5;
          }
          while ( v6 != v7 );
        }
      }
    }
  }
}
void __userpurge SetupTab::render(SetupTab *this@<ecx>, __int64 a2@<esi:edi>, float dt)
{
  int v3; // edi
  int v4; // eax
  unsigned int v5; // esi
  ksgui::PopOver *v6; // ecx
  __int64 v7; // [esp+8h] [ebp-18h]
  ksgui::ksRect r; // [esp+10h] [ebp-10h] BYREF

  v7 = a2;
  LODWORD(a2) = this;
  ksgui::Control::render(this, (int)this, SHIDWORD(a2), dt, v7, r.left);
  v4 = *(_DWORD *)a2;
  r = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)(a2 + 28));
  (*(void (**)(_DWORD, ksgui::ksRect *))(v4 + 24))(a2, &r);
  SetupTab::drawFrame((SetupTab *)a2, &r);
  HIDWORD(a2) = 0;
  if ( (*(_DWORD *)(a2 + 304) - *(_DWORD *)(a2 + 300)) >> 2 )
  {
    do
    {
      v6 = *(ksgui::PopOver **)(*(_DWORD *)(*(_DWORD *)(v3 + 300) + 4 * v5) + 312);
      if ( v6->visible )
        ksgui::PopOver::renderPopOver(v6, dt);
      ++v5;
    }
    while ( v5 < (*(_DWORD *)(v3 + 304) - *(_DWORD *)(v3 + 300)) >> 2 );
  }
}
void SetupTab::resetToDefaultValues(SetupTab *this)
{
  unsigned int i; // edi
  ksgui::Spinner *v3; // ecx
  _DWORD *v4; // eax

  for ( i = 0; i < this->spinners._Mylast - this->spinners._Myfirst; ++i )
  {
    v3 = this->spinners._Myfirst[i];
    v4 = v3->tag;
    if ( v4 && !v3->isReadOnly )
      ksgui::Spinner::setValue(v3, v4[17]);
  }
  this->modifiedValues = 0;
}
void SetupTab::setValueToSpinner(SetupTab *this, ksgui::Spinner *sp, bool isFixed, int spinnerValue)
{
  ksgui::Spinner *v4; // esi
  ksgui::Spinner **v5; // eax
  ksgui::Spinner *v6; // ecx
  int v7; // [esp-4h] [ebp-4h]

  if ( isFixed )
  {
    sp->isReadOnly = 1;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&SetupTab::fixedVector,
      (ICollisionObject *const *)&sp);
    ksgui::Spinner::setValue(sp, spinnerValue);
  }
  else if ( (((char *)SetupTab::fixedVector._Mylast - (char *)SetupTab::fixedVector._Myfirst) & 0xFFFFFFFC) != 0 )
  {
    v4 = sp;
    sp->isReadOnly = 1;
    v5 = SetupTab::fixedVector._Myfirst;
    if ( SetupTab::fixedVector._Myfirst == SetupTab::fixedVector._Mylast )
      goto LABEL_9;
    while ( *v5 != v4 )
    {
      if ( ++v5 == SetupTab::fixedVector._Mylast )
        goto LABEL_9;
    }
    if ( v5 == SetupTab::fixedVector._Mylast )
    {
LABEL_9:
      ksgui::Spinner::setValue(v4, spinnerValue);
      v4->isReadOnly = 0;
    }
  }
  else
  {
    v6 = sp;
    v7 = spinnerValue;
    sp->isReadOnly = 0;
    ksgui::Spinner::setValue(v6, v7);
  }
}
