#include "tabbar.h
void TabBar::TabBar(TabBar *this, std::wstring name, ksgui::GUI *igui)
{
  ksgui::Control *v4; // eax
  ksgui::Control *v5; // edi
  ksgui::Control *v6; // eax
  ksgui::Control *v7; // eax
  ksgui::Control *v8; // eax
  Texture *v9; // eax
  ksgui::Control *v10; // ecx
  std::wstring *v11; // ecx
  ksgui::Control *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  ksgui::Control *v17; // eax
  ksgui::Control *v18; // eax
  ksgui::Control *v19; // eax
  Texture *v20; // eax
  ksgui::Control *v21; // ecx
  std::wstring *v22; // ecx
  ksgui::Control *v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  std::function<void __cdecl(OnMouseWheelMovedEvent const &)> v29; // [esp-Ch] [ebp-8Ch] BYREF
  unsigned int v30; // [esp+Ch] [ebp-74h]
  TabBar *v31; // [esp+24h] [ebp-5Ch]
  ksgui::Control *v32[2]; // [esp+28h] [ebp-58h]
  int _Val; // [esp+30h] [ebp-50h] BYREF
  int v34; // [esp+34h] [ebp-4Ch] BYREF
  int v35; // [esp+38h] [ebp-48h]
  Texture result; // [esp+3Ch] [ebp-44h] BYREF
  std::wstring iname; // [esp+58h] [ebp-28h] BYREF
  int v38; // [esp+7Ch] [ebp-4h]

  v31 = this;
  v34 = (int)igui;
  v35 = 0;
  _Val = 0;
  v38 = 0;
  ksgui::Control::Control(this, &name, igui);
  this->__vftable = (TabBar_vtbl *)&TabBar::`vftable';
  this->evOnCellSelected.handlers._Myfirst = 0;
  this->evOnCellSelected.handlers._Mylast = 0;
  this->evOnCellSelected.handlers._Myend = 0;
  this->selectedColor.x = 0.0;
  this->selectedColor.y = 0.0;
  this->selectedColor.z = 0.0;
  this->selectedColor.w = 0.0;
  this->unselectedColor.x = 0.0;
  this->unselectedColor.y = 0.0;
  this->unselectedColor.z = 0.0;
  this->unselectedColor.w = 0.0;
  this->rolloverColor.x = 0.0;
  this->rolloverColor.y = 0.0;
  this->rolloverColor.z = 0.0;
  this->rolloverColor.w = 0.0;
  this->elements._Myfirst = 0;
  this->elements._Mylast = 0;
  this->elements._Myend = 0;
  *(_QWORD *)v32 = 0i64;
  this->selectedColor = (vec4f)_xmm;
  this->mouse.x = 0;
  v4 = v32[1];
  this->unselectedColor = 0i64;
  v30 = 280;
  this->rolloverColor = (vec4f)_xmm;
  this->mouse.y = (int)v4;
  this->borderColor = (vec4f)_xmm;
  this->tabBarX = 0.0;
  this->rollOnIndex = 0;
  *(_WORD *)&this->drawBorder = 257;
  this->backColor = (vec4f)_xmm;
  this->topIndex = 0;
  v5 = (ksgui::Control *)operator new(v30);
  v32[1] = v5;
  v6 = 0;
  LOBYTE(v38) = 4;
  if ( v5 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"LEFT", 4u);
    LOBYTE(v38) = 5;
    v30 = (unsigned int)this->gui;
    v35 = 1;
    _Val = 1;
    ksgui::Control::Control(v5, &iname, (ksgui::GUI *)v30);
  }
  v38 = 3;
  this->leftScroller = v6;
  if ( (v35 & 1) != 0 )
  {
    v35 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v7 = this->leftScroller;
  v30 = 49;
  (&v29._Impl)[1] = (std::_Func_base<void,OnMouseWheelMovedEvent const &> *)L"content/gui/controls/tabbar/scroll_left_small.png";
  iname._Myres = 7;
  v7->drawBackground = 0;
  v8 = this->leftScroller;
  iname._Mysize = 0;
  v8->drawBorder = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, (const wchar_t *)(&v29._Impl)[1], v30);
  LOBYTE(v38) = 7;
  v9 = ResourceStore::getTexture(*(ResourceStore **)(*(_DWORD *)(v34 + 8) + 336), &result, &iname, 0);
  LOBYTE(v38) = 8;
  v10 = this->leftScroller;
  v10->backTexture.kid = v9->kid;
  v11 = &v10->backTexture.fileName;
  if ( v11 != &v9->fileName )
    std::wstring::assign(v11, &v9->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v38) = 7;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v38) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v12 = this->leftScroller;
  v13 = v12->rectBase.left;
  v14 = v12->rect.right - v12->rect.left;
  v15 = v12->rect.bottom - v12->rect.top;
  v12->rect.top = 0.0;
  v12->rect.left = 2.0;
  v16 = v14 + 2.0;
  v12->rect.bottom = v15;
  v12->rect.right = v16;
  if ( v13 == 0.0 && v12->rectBase.top == 0.0 )
  {
    v12->rectBase.left = 2.0;
    v12->rectBase.top = 0.0;
    v12->rectBase.right = v16;
    v12->rectBase.bottom = v15;
  }
  ((void (*)(ksgui::Control *, int, int))this->leftScroller->setSize)(
    this->leftScroller,
    1103101952,
    1107558400);
  _Val = (int)this->leftScroller;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  v30 = 280;
  *(_DWORD *)(_Val + 148) = this;
  v32[1] = (ksgui::Control *)operator new(v30);
  LOBYTE(v38) = 9;
  if ( v32[1] )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"RIGHT", 5u);
    LOBYTE(v38) = 10;
    v30 = (unsigned int)this->gui;
    v35 |= 2u;
    _Val = v35;
    ksgui::Control::Control(v32[1], &iname, (ksgui::GUI *)v30);
  }
  else
  {
    v17 = 0;
  }
  this->rightScroller = v17;
  v38 = 3;
  if ( (v35 & 2) != 0 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v18 = this->rightScroller;
  v30 = 50;
  (&v29._Impl)[1] = (std::_Func_base<void,OnMouseWheelMovedEvent const &> *)L"content/gui/controls/tabbar/scroll_right_small.png";
  iname._Myres = 7;
  v18->drawBackground = 0;
  v19 = this->rightScroller;
  iname._Mysize = 0;
  v19->drawBorder = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, (const wchar_t *)(&v29._Impl)[1], v30);
  LOBYTE(v38) = 12;
  v20 = ResourceStore::getTexture(*(ResourceStore **)(*(_DWORD *)(v34 + 8) + 336), &result, &iname, 0);
  LOBYTE(v38) = 13;
  v21 = this->rightScroller;
  v21->backTexture.kid = v20->kid;
  v22 = &v21->backTexture.fileName;
  if ( v22 != &v20->fileName )
    std::wstring::assign(v22, &v20->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v38) = 12;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v38) = 3;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v23 = this->rightScroller;
  v24 = v23->rectBase.left;
  v25 = v23->rect.right - v23->rect.left;
  v26 = v23->rect.bottom - v23->rect.top;
  v23->rect.top = 2.0;
  v23->rect.left = 2.0;
  v27 = v25 + 2.0;
  v28 = v26 + 2.0;
  v23->rect.right = v27;
  v23->rect.bottom = v28;
  if ( v24 == 0.0 && v23->rectBase.top == 0.0 )
  {
    v23->rectBase.left = 2.0;
    v23->rectBase.top = 2.0;
    v23->rectBase.right = v27;
    v23->rectBase.bottom = v28;
  }
  ((void (*)(ksgui::Control *, int, int))this->rightScroller->setSize)(
    this->rightScroller,
    1103101952,
    1107558400);
  v34 = (int)this->rightScroller;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &v34);
  v30 = (unsigned int)this;
  *(_DWORD *)(v34 + 148) = this;
  v29._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_fe11ff885f9187f517dcab75665bb098_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  v29._Space._Pfn[1] = (void (__cdecl *)())this;
  v29._Impl = (std::_Func_base<void,OnMouseWheelMovedEvent const &> *)&v29;
  LOBYTE(v38) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->leftScroller->evClicked,
    v29,
    (void *)v30);
  v29._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_5d308dca4a93e0d78f34fea3775734ad_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  v29._Space._Pfn[1] = (void (__cdecl *)())this;
  v29._Impl = (std::_Func_base<void,OnMouseWheelMovedEvent const &> *)&v29;
  LOBYTE(v38) = 3;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->rightScroller->evClicked,
    v29,
    this);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
TabBar *TabBar::`scalar deleting destructor'(TabBar *this, unsigned int a2)
{
  TabBar::~TabBar(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TabBar::orderAlphabetically(TabBar *this, unsigned int beginIndex, unsigned int endIndex)
{
  std::_Sort<ksgui::Label * *,int,_lambda_9b8ddcb336fad3a01a4c2e5686bdfd5f_>(
    &this->elements._Myfirst[beginIndex],
    &this->elements._Myfirst[endIndex],
    (int)(4 * endIndex - 4 * beginIndex) >> 2,
    (TabBar::orderAlphabetically::__l3::<lambda_9b8ddcb336fad3a01a4c2e5686bdfd5f>)endIndex);
}
void TabBar::~TabBar(TabBar *this)
{
  std::pair<void *,std::function<void __cdecl(OnCellSelected const &)> > *v2; // eax

  this->__vftable = (TabBar_vtbl *)&TabBar::`vftable';
  if ( this->elements._Myfirst )
  {
    operator delete(this->elements._Myfirst);
    this->elements._Myfirst = 0;
    this->elements._Mylast = 0;
    this->elements._Myend = 0;
  }
  v2 = this->evOnCellSelected.handlers._Myfirst;
  if ( v2 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::pair<void *,std::function<void __cdecl (bool const &)>>>>>(
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)v2,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnCellSelected.handlers._Mylast);
    operator delete(this->evOnCellSelected.handlers._Myfirst);
    this->evOnCellSelected.handlers._Myfirst = 0;
    this->evOnCellSelected.handlers._Mylast = 0;
    this->evOnCellSelected.handlers._Myend = 0;
  }
  ksgui::Control::~Control(this);
}
void TabBar::addTab(TabBar *this, std::wstring name, unsigned int myIndex)
{
  ksgui::Label *v4; // esi
  int *v5; // eax
  int *v6; // esi
  int v7; // eax
  __m128i v8; // xmm0
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  TabBar_vtbl *v14; // eax
  std::wstring v15; // [esp-10h] [ebp-40h] BYREF
  ksgui::GUI *v16; // [esp+8h] [ebp-28h]
  ksgui::Label *tab; // [esp+1Ch] [ebp-14h] BYREF
  int v18; // [esp+2Ch] [ebp-4h]

  v18 = 1;
  v4 = (ksgui::Label *)operator new(0x11Cu);
  tab = v4;
  if ( v4 )
  {
    v16 = this->gui;
    v15._Myres = 7;
    v15._Mysize = 0;
    v15._Bx._Buf[0] = 0;
    std::wstring::assign(&v15, &name, 0, 0xFFFFFFFF);
    ksgui::Label::Label(v4, v15, v16);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  LOBYTE(v18) = 0;
  v7 = *v6;
  tab = (ksgui::Label *)v6;
  (*(void (**)(int *, std::wstring *))(v7 + 68))(v6, &name);
  (*(void (**)(int *, int, int))(*v6 + 28))(v6, 1128792064, 1107558400);
  v8 = _mm_loadu_si128((const __m128i *)&this->unselectedColor);
  v16 = (ksgui::GUI *)this;
  *(__m128i *)(v6 + 11) = v8;
  *((_WORD *)v6 + 100) = 256;
  v6[38] = 2;
  v15._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_5b811461632966e03786fb7487dffe30_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v15._Bx._Alias[4] = this;
  v15._Mysize = (unsigned int)&v15;
  LOBYTE(v18) = 0;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v6 + 13,
    (std::function<void __cdecl(OnMouseWheelMovedEvent const &)>)v15,
    v16);
  v9 = *((float *)v6 + 8) - *((float *)v6 + 7);
  v10 = *((float *)v6 + 10) - *((float *)v6 + 9);
  *(double *)v8.m128i_i64 = (double)(this->elements._Mylast - this->elements._Myfirst)
                          + _xmm[(unsigned int)((char *)this->elements._Mylast - (char *)this->elements._Myfirst) >> 31];
  v6[9] = 0;
  *((float *)v6 + 10) = v10;
  v11 = *(double *)v8.m128i_i64;
  v8.m128i_i32[0] = v6[66];
  v12 = (float)(v11 * 200.0) + 226.0;
  *((float *)v6 + 7) = v12;
  v13 = v9 + v12;
  *((float *)v6 + 8) = v13;
  if ( *(float *)v8.m128i_i32 == 0.0 && *((float *)v6 + 68) == 0.0 )
  {
    *((float *)v6 + 66) = v12;
    v6[68] = 0;
    *((float *)v6 + 67) = v13;
    *((float *)v6 + 69) = v10;
  }
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->elements, (int *)&tab);
  v14 = this->__vftable;
  v16 = (ksgui::GUI *)tab;
  this->topIndex = 0;
  v14->addControl(this, (ksgui::Control *)v16);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void TabBar::updateTabBarPosition(TabBar *this)
{
  ksgui::Control *v2; // edx
  TabBar_vtbl *v3; // eax
  ksgui::Control *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm1_4

  v2 = this->parent;
  v3 = this->__vftable;
  this->tabBarX = (float)((float)(v2->rect.right - v2->rect.left) * 0.0099999998) * 8.5;
  ((void (__cdecl *)(_DWORD, int))v3->setSize)(
    (float)((float)(v2->rect.right - v2->rect.left) * 0.0099999998) * 88.0,
    1108082688);
  v4 = this->rightScroller;
  v5 = v4->rectBase.left;
  v6 = (float)(this->rect.right - this->rect.left) - 24.0;
  v7 = v4->rect.right - v4->rect.left;
  v8 = v4->rect.bottom - v4->rect.top;
  v4->rect.top = 0.0;
  v9 = v6 - 1.0;
  v4->rect.bottom = v8;
  v4->rect.left = v9;
  v10 = v7 + v9;
  v4->rect.right = v10;
  if ( v5 == 0.0 && v4->rectBase.top == 0.0 )
  {
    v4->rectBase.left = v9;
    v4->rectBase.top = 0.0;
    v4->rectBase.right = v10;
    v4->rectBase.bottom = v8;
  }
  v11 = this->rectBase.left;
  v12 = this->rect.right - this->rect.left;
  v13 = this->tabBarX;
  v14 = this->rect.bottom - this->rect.top;
  this->rect.top = 0.0;
  v15 = v12 + v13;
  this->rect.left = v13;
  this->rect.bottom = v14;
  this->rect.right = v15;
  if ( v11 == 0.0 && this->rectBase.top == 0.0 )
  {
    this->rectBase.left = v13;
    this->rectBase.top = 0.0;
    this->rectBase.right = v15;
    this->rectBase.bottom = v14;
  }
}
void __userpurge TabBar::render(TabBar *this@<ecx>, int a2@<edi>, float dt)
{
  ksgui::Control *v4; // ecx
  unsigned int v5; // edi
  GLRenderer *v6; // edx
  ksgui::Label *v7; // ecx
  bool v8; // al
  ksgui::Label *v9; // eax
  __m128i v10; // xmm0
  ksgui::Label **v11; // ecx
  __int64 v12; // [esp+20h] [ebp-20h]
  GLRenderer *v13; // [esp+28h] [ebp-18h]
  GLRenderer *i; // [esp+28h] [ebp-18h]
  _DWORD v15[5]; // [esp+2Ch] [ebp-14h] BYREF

  TabBar::updateTabBarPosition(this);
  TabBar::updateRollOnIndex(this, &this->mouse);
  TabBar::updateTabs(this, dt * 2500.0);
  ksgui::Control::render(v4, a2, (int)this, dt, v12, *(float *)&v13);
  v5 = 0;
  v6 = this->controlGLR;
  for ( i = v6; v5 < this->elements._Mylast - this->elements._Myfirst; v6 = i )
  {
    v7 = this->elements._Myfirst[v5];
    v8 = v7->rect.left > this->leftScroller->rect.left && this->rightScroller->rect.left > v7->rect.right;
    if ( v7->visible != v8 )
    {
      v7->visible = v8;
      v7->onVisibleChanged(v7, v8);
      v6 = i;
    }
    v9 = this->elements._Myfirst[v5];
    if ( v9->visible )
    {
      if ( v5 == this->topIndex )
      {
        v10 = _mm_loadu_si128((const __m128i *)&this->selectedColor);
      }
      else if ( this->rollOnIndex == v5 )
      {
        v10 = _mm_loadu_si128((const __m128i *)&this->rolloverColor);
      }
      else
      {
        v10 = _mm_loadu_si128((const __m128i *)&this->unselectedColor);
      }
      v9->backColor = (vec4f)v10;
      if ( v5 < this->elements._Mylast - this->elements._Myfirst - 1 )
      {
        GLRenderer::color4f(v6, 1.0, 1.0, 1.0, 1.0);
        v11 = this->elements._Myfirst;
        *(__m128i *)&v15[1] = _mm_loadu_si128((const __m128i *)&v11[v5]->rect);
        v11[v5]->getWorldRect(v11[v5], (ksgui::ksRect *)&v15[1]);
        GLRenderer::quad(i, *(float *)&v15[2] - 1.0, 5.0, 2.0, 21.0, 0, 0);
      }
    }
    ++v5;
  }
}
void __usercall TabBar::updateTabs(TabBar *this@<ecx>, float a2@<xmm1>)
{
  ksgui::Label **v3; // eax
  unsigned int v5; // edx
  float v6; // xmm2_4
  float v7; // xmm1_4
  unsigned int v8; // edx
  float v9; // xmm1_4
  float v10; // xmm1_4
  ksgui::Label *v11; // eax
  ksgui::Label *v12; // eax
  double v13; // xmm0_8
  unsigned int v14; // edx
  float i; // xmm1_4
  ksgui::Label *v16; // eax

  v3 = this->elements._Myfirst;
  if ( v3 != this->elements._Mylast )
  {
    v5 = this->topIndex;
    v6 = v3[v5]->rect.left - 226.0;
    if ( COERCE_FLOAT(LODWORD(v6) & _xmm) <= a2 )
    {
      v13 = (double)v5;
      v14 = 0;
      for ( i = 226.0 - (float)((float)v13 * 200.0);
            v14 < this->elements._Mylast - this->elements._Myfirst;
            v16->rect.right = i )
      {
        this->elements._Myfirst[v14]->rect.left = i;
        i = i + 200.0;
        v16 = this->elements._Myfirst[v14++];
      }
    }
    else
    {
      v7 = 0.0;
      if ( v6 <= 0.0 )
      {
        if ( v6 < 0.0 )
          v7 = FLOAT_N1_0;
      }
      else
      {
        v7 = FLOAT_1_0;
      }
      v8 = 0;
      LODWORD(v9) = LODWORD(v7) ^ _xmm;
      if ( this->elements._Mylast - this->elements._Myfirst )
      {
        v10 = v9 * a2;
        do
        {
          v11 = this->elements._Myfirst[v8];
          v11->rect.left = v10 + v11->rect.left;
          v12 = this->elements._Myfirst[v8++];
          v12->rect.right = v10 + v12->rect.right;
        }
        while ( v8 < this->elements._Mylast - this->elements._Myfirst );
      }
    }
  }
}
void TabBar::onTabClicked(TabBar *this, const ksgui::OnControlClicked *message)
{
  unsigned int v3; // esi
  std::wstring *v4; // ecx
  ksgui::Label *v5; // eax
  std::pair<void *,std::function<void __cdecl(OnCellSelected const &)> > *v6; // esi
  std::_Func_base<void,OnCellSelected const &> **v7; // ebx
  OnCellSelected ev; // [esp+Ch] [ebp-Ch] BYREF

  v3 = 0;
  this->elements._Myfirst[this->topIndex]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->unselectedColor);
  for ( ev.oldIndex = this->topIndex; v3 < this->elements._Mylast - this->elements._Myfirst; ++v3 )
  {
    v4 = &message->control->name;
    if ( message->control->name._Myres >= 8 )
      v4 = (std::wstring *)v4->_Bx._Ptr;
    v5 = this->elements._Myfirst[v3];
    if ( !std::wstring::compare(&v5->name, 0, v5->name._Mysize, v4->_Bx._Buf, message->control->name._Mysize) )
      this->topIndex = v3;
  }
  v6 = this->evOnCellSelected.handlers._Myfirst;
  ev.newIndex = this->topIndex;
  ev.tabBar = this;
  if ( v6 != this->evOnCellSelected.handlers._Mylast )
  {
    v7 = &v6->second._Impl;
    do
    {
      if ( !*v7 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x44D10E);
      }
      (*v7)->_Do_call(*v7, &ev);
      ++v6;
      v7 += 8;
    }
    while ( v6 != this->evOnCellSelected.handlers._Mylast );
  }
  this->elements._Myfirst[this->topIndex]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->selectedColor);
}
void TabBar::updateRollOnIndex(TabBar *this, const LastMousePosition *lm)
{
  TabBar_vtbl *v3; // eax
  float v4; // xmm0_4
  unsigned int v5; // eax
  ksgui::ksRect wrect; // [esp+8h] [ebp-10h] BYREF

  v3 = this->__vftable;
  wrect = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)&this->rect);
  v3->getWorldRect(this, &wrect);
  if ( (float)lm->y >= 35.0
    || (v4 = (float)lm->x, v4 <= (float)(wrect.left + 24.0))
    || (float)(wrect.right - 24.0) <= v4 )
  {
    this->rollOnIndex = this->topIndex;
  }
  else
  {
    v5 = (unsigned int)(float)((float)(v4 - (float)(wrect.left + 24.0)) * 0.0049999999);
    if ( v5 <= this->elements._Mylast - this->elements._Myfirst )
      this->rollOnIndex = this->topIndex - 1 + v5;
  }
}
void TabBar::onMouseMove(TabBar *this, const OnMouseMoveEvent *message)
{
  this->mouse.x = message->x;
  this->mouse.y = message->y;
  TabBar::updateRollOnIndex(this, &this->mouse);
}
int TabBar::getTabNamesCount(TabBar *this)
{
  return this->elements._Mylast - this->elements._Myfirst;
}
