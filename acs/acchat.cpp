#include "acchat.h
void ACChat::ACChat(ACChat *this, Sim *aSim)
{
  Game *v3; // eax
  std::vector<ChatElement> *v4; // esi
  Font *v5; // eax
  Font *v6; // eax
  std::_Ref_count_base *v7; // edi
  Font *v8; // eax
  Font *v9; // eax
  std::_Ref_count_base *v10; // edi
  Font *v11; // eax
  Font *v12; // eax
  std::_Ref_count_base *v13; // edi
  Sim *v14; // eax
  ksgui::TextInput *v15; // edi
  ksgui::TextInput *v16; // eax
  Event<std::wstring > *v17; // ecx
  int v18; // ebx
  ChatElement *v19; // eax
  int v20; // edi
  ChatElement *v21; // ebx
  unsigned int v22; // edi
  ChatElement *v23; // edi
  std::wstring v24; // [esp-10h] [ebp-B4h] BYREF
  float h; // [esp+8h] [ebp-9Ch]
  std::shared_ptr<Font> _Right; // [esp+28h] [ebp-7Ch] BYREF
  int v27; // [esp+30h] [ebp-74h]
  ChatElement *v28; // [esp+34h] [ebp-70h]
  ACChat *v29; // [esp+38h] [ebp-6Ch]
  std::wstring iname; // [esp+3Ch] [ebp-68h] BYREF
  std::wstring v31; // [esp+54h] [ebp-50h] BYREF
  std::wstring v32; // [esp+6Ch] [ebp-38h] BYREF
  __int128 v33; // [esp+84h] [ebp-20h] BYREF
  int v34; // [esp+A0h] [ebp-4h]

  v29 = this;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"ACChat", 6u);
  v3 = aSim->game;
  v34 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (ACChat_vtbl *)&ACChat::`vftable';
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  this->playerNameFont._Ptr = 0;
  this->playerNameFont._Rep = 0;
  this->playerTextFont._Ptr = 0;
  this->playerTextFont._Rep = 0;
  this->inpTest = 0;
  this->sim = aSim;
  LODWORD(h) = 2;
  this->playerName._Myres = 7;
  this->playerName._Mysize = 0;
  v24._Myres = (unsigned int)L"Me";
  LOBYTE(v34) = 5;
  this->playerName._Bx._Buf[0] = 0;
  std::wstring::assign(&this->playerName, (const wchar_t *)v24._Myres, LODWORD(h));
  v4 = &this->texts;
  this->playerColor.x = 1.0;
  this->playerColor.y = 0.0;
  this->playerColor.z = 0.0;
  this->playerColor.w = 1.0;
  this->texts._Myfirst = 0;
  this->texts._Mylast = 0;
  this->texts._Myend = 0;
  LOBYTE(v34) = 7;
  v5 = (Font *)operator new(24);
  v27 = (int)v5;
  LOBYTE(v34) = 8;
  if ( v5 )
    Font::Font(v5, eFontMonospaced, 14.0, 1, 1);
  else
    v6 = 0;
  LOBYTE(v34) = 7;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v6);
  std::shared_ptr<Font>::operator=(&this->titleFont, &_Right);
  v7 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v7->_Destroy(v7);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v7->_Weaks, 0xFFFFFFFF) )
        v7->_Delete_this(v7);
    }
  }
  v8 = (Font *)operator new(24);
  v27 = (int)v8;
  LOBYTE(v34) = 9;
  if ( v8 )
    Font::Font(v8, eFontMonospaced, 14.0, 0, 1);
  else
    v9 = 0;
  LOBYTE(v34) = 7;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v9);
  std::shared_ptr<Font>::operator=(&this->playerNameFont, &_Right);
  v10 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v10->_Destroy(v10);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v10->_Weaks, 0xFFFFFFFF) )
        v10->_Delete_this(v10);
    }
  }
  v11 = (Font *)operator new(24);
  v27 = (int)v11;
  LOBYTE(v34) = 10;
  if ( v11 )
    Font::Font(v11, eFontProportional, 14.0, 1, 0);
  else
    v12 = 0;
  LOBYTE(v34) = 7;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v12);
  std::shared_ptr<Font>::operator=(&this->playerTextFont, &_Right);
  v13 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v13->_Destroy(v13);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v13->_Weaks) )
        v13->_Delete_this(v13);
    }
  }
  ksgui::Control::setSize(this, 620.0, 340.0);
  LODWORD(h) = this;
  v24._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_da4d08dd4ba38c2fb57b85b2222553ad_,0>,std::allocator<std::_Func_class<void,OnChatMessageEvent const &>>,void,OnChatMessageEvent const &>::`vftable';
  *(_DWORD *)&v24._Bx._Alias[4] = this;
  v24._Mysize = (unsigned int)&v24;
  v14 = this->sim;
  LOBYTE(v34) = 7;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v14->client->evOnChatMessage,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v24,
    this);
  v15 = (ksgui::TextInput *)operator new(344);
  v27 = (int)v15;
  v16 = 0;
  LOBYTE(v34) = 12;
  if ( v15 )
  {
    h = *(float *)&this->gui;
    v24._Myres = 7;
    v24._Mysize = 0;
    v24._Bx._Buf[0] = 0;
    std::wstring::assign(&v24, L"TEXT_INPUT", 0xAu);
    ksgui::TextInput::TextInput(v15, v24, (ksgui::GUI *)LODWORD(h));
  }
  LODWORD(h) = v16;
  LOBYTE(v34) = 7;
  this->inpTest = v16;
  ksgui::Control::addControl(this, (ksgui::Control *)LODWORD(h));
  LODWORD(h) = this;
  v24._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_76236101e3eaa907b75e3afcab748728_,0>,std::allocator<std::_Func_class<void,std::wstring const &>>,void,std::wstring const &>::`vftable';
  *(_DWORD *)&v24._Bx._Alias[4] = this;
  v24._Mysize = (unsigned int)&v24;
  v17 = &this->inpTest->evValidate;
  LOBYTE(v34) = 7;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v17,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v24,
    this);
  v18 = 19;
  v27 = 19;
  do
  {
    v31._Myres = 7;
    v31._Mysize = 0;
    v31._Bx._Buf[0] = 0;
    v32._Myres = 7;
    v32._Mysize = 0;
    v32._Bx._Buf[0] = 0;
    v33 = _xmm;
    v19 = this->texts._Mylast;
    LOBYTE(v34) = 14;
    if ( &v31 >= (std::wstring *)v19 || v4->_Myfirst > (ChatElement *)&v31 )
    {
      if ( v19 == this->texts._Myend )
        std::vector<ChatElement>::_Reserve(&this->texts, 1u);
      v23 = this->texts._Mylast;
      _Right._Ptr = (Font *)v23;
      v28 = v23;
      LOBYTE(v34) = 17;
      if ( v23 )
      {
        v23->playerName._Myres = 7;
        h = NAN;
        v23->playerName._Mysize = 0;
        v24._Myres = 0;
        v23->playerName._Bx._Buf[0] = 0;
        std::wstring::assign(&v23->playerName, &v31, v24._Myres, LODWORD(h));
        v23->text._Myres = 7;
        h = NAN;
        v23->text._Mysize = 0;
        v24._Myres = 0;
        v23->text._Bx._Buf[0] = 0;
        LOBYTE(v34) = 18;
        std::wstring::assign(&v23->text, &v32, v24._Myres, LODWORD(h));
        v23->color = (vec4f)_mm_loadu_si128((const __m128i *)&v33);
      }
    }
    else
    {
      v20 = (char *)&v31 - (char *)v4->_Myfirst;
      if ( v19 == this->texts._Myend )
        std::vector<ChatElement>::_Reserve(&this->texts, 1u);
      v21 = this->texts._Mylast;
      v22 = (unsigned int)v4->_Myfirst + (v20 & 0xFFFFFFC0);
      v28 = v21;
      _Right._Ptr = (Font *)v21;
      LOBYTE(v34) = 15;
      if ( v21 )
      {
        v21->playerName._Myres = 7;
        h = NAN;
        v24._Myres = 0;
        v21->playerName._Mysize = 0;
        v24._Mysize = v22;
        v21->playerName._Bx._Buf[0] = 0;
        std::wstring::assign(&v21->playerName, (const std::wstring *)v24._Mysize, v24._Myres, LODWORD(h));
        v21->text._Myres = 7;
        h = NAN;
        v21->text._Mysize = 0;
        v24._Myres = 0;
        v21->text._Bx._Buf[0] = 0;
        LOBYTE(v34) = 16;
        std::wstring::assign(&v21->text, (const std::wstring *)(v22 + 24), v24._Myres, LODWORD(h));
        v21->color = (vec4f)_mm_loadu_si128((const __m128i *)(v22 + 48));
      }
      v18 = v27;
    }
    ++this->texts._Mylast;
    LOBYTE(v34) = 7;
    if ( v32._Myres >= 8 )
      operator delete(v32._Bx._Ptr);
    if ( v31._Myres >= 8 )
      operator delete(v31._Bx._Ptr);
    v27 = --v18;
  }
  while ( v18 );
}
void ACChat::~ACChat(ACChat *this)
{
  std::vector<ChatElement> *v2; // edi
  std::_Ref_count_base *v3; // edi
  std::_Ref_count_base *v4; // edi
  std::_Ref_count_base *v5; // edi

  v2 = &this->texts;
  this->__vftable = (ACChat_vtbl *)&ACChat::`vftable';
  if ( this->texts._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->texts);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<ChatElement>>>(v2->_Myfirst, v2->_Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  if ( this->playerName._Myres >= 8 )
    operator delete(this->playerName._Bx._Ptr);
  this->playerName._Myres = 7;
  this->playerName._Mysize = 0;
  this->playerName._Bx._Buf[0] = 0;
  v3 = this->playerTextFont._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Weaks, 0xFFFFFFFF) )
        v3->_Delete_this(v3);
    }
  }
  v4 = this->playerNameFont._Rep;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Uses, 0xFFFFFFFF) )
    {
      v4->_Destroy(v4);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Weaks, 0xFFFFFFFF) )
        v4->_Delete_this(v4);
    }
  }
  v5 = this->titleFont._Rep;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v5->_Uses, 0xFFFFFFFF) )
    {
      v5->_Destroy(v5);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v5->_Weaks) )
        v5->_Delete_this(v5);
    }
  }
  ksgui::Control::~Control(this);
}
ACChat *ACChat::`vector deleting destructor'(ACChat *this, unsigned int a2)
{
  ACChat::~ACChat(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACChat::onChatMessage(ACChat *this, const OnChatMessageEvent *message)
{
  unsigned int v3; // ebx
  int v4; // edi
  ChatElement *v5; // ecx
  ChatElement *v6; // eax
  std::wstring *v7; // ecx
  NetCarStateProvider *v8; // eax
  unsigned int v9; // ecx
  std::wstring *v10; // ecx
  std::wstring *v11; // ecx
  std::wstring *v12; // ecx
  std::wstring *v13; // ebp
  std::wstring *v14; // ecx
  const std::wstring *v15; // eax
  std::wstring *v16; // ecx
  std::wstring description; // [esp+14h] [ebp-40h] BYREF
  std::wstring result; // [esp+2Ch] [ebp-28h] BYREF
  int v19; // [esp+50h] [ebp-4h]

  v3 = 0;
  if ( this->texts._Mylast - this->texts._Myfirst != 1 )
  {
    v4 = 0;
    do
    {
      v5 = &this->texts._Myfirst[v4];
      if ( v5 != &v5[1] )
        std::wstring::assign(&v5->playerName, &v5[1].playerName, 0, 0xFFFFFFFF);
      v6 = this->texts._Myfirst;
      v7 = &v6[v4].text;
      if ( v7 != &v6[v4 + 1].text )
        std::wstring::assign(v7, &v6[v4 + 1].text, 0, 0xFFFFFFFF);
      ++v3;
      this->texts._Myfirst[v4].color = (vec4f)_mm_loadu_si128((const __m128i *)&this->texts._Myfirst[v4 + 1].color);
      ++v4;
    }
    while ( v3 < this->texts._Mylast - this->texts._Myfirst - 1 );
  }
  v8 = ACClient::getNetCarFromSessionID(this->sim->client, message->sessionID);
  v9 = ((char *)this->texts._Mylast - (char *)this->texts._Myfirst) & 0xFFFFFFC0;
  if ( v8 )
  {
    v10 = (std::wstring *)((char *)&this->texts._Myfirst[-1].playerName + v9);
    if ( v10 != (std::wstring *)&v8->driverInfo )
      std::wstring::assign(v10, &v8->driverInfo.name, 0, 0xFFFFFFFF);
    v11 = (std::wstring *)((char *)&this->texts._Myfirst[-1].text
                         + (((char *)this->texts._Mylast - (char *)this->texts._Myfirst) & 0xFFFFFFC0));
    if ( v11 != &message->message )
      std::wstring::assign(v11, &message->message, 0, 0xFFFFFFFF);
  }
  else
  {
    v12 = (std::wstring *)((char *)&this->texts._Myfirst[-1].playerName + v9);
    if ( message->sessionID == 255 )
    {
      std::wstring::assign(v12, L"SERVER", 6u);
      v13 = &message->message;
      v14 = (std::wstring *)((char *)&this->texts._Myfirst[-1].text
                           + (((char *)this->texts._Mylast - (char *)this->texts._Myfirst) & 0xFFFFFFC0));
      if ( v14 != &message->message )
        std::wstring::assign(v14, v13, 0, 0xFFFFFFFF);
      description._Myres = 7;
      description._Mysize = 0;
      description._Bx._Buf[0] = 0;
      std::wstring::assign(&description, word_17BE9D8, 0);
      v19 = 0;
      v15 = std::operator+<wchar_t>(&result, L"SERVER:", v13);
      LOBYTE(v19) = 1;
      SystemMessage::addMessage(this->sim->systemMessage, v15, &description, eDefault);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( description._Myres >= 8 )
        operator delete(description._Bx._Ptr);
    }
    else
    {
      if ( v12 != &this->playerName )
        std::wstring::assign(v12, &this->playerName, 0, 0xFFFFFFFF);
      v16 = (std::wstring *)((char *)&this->texts._Myfirst[-1].text
                           + (((char *)this->texts._Mylast - (char *)this->texts._Myfirst) & 0xFFFFFFC0));
      if ( v16 != &message->message )
        std::wstring::assign(v16, &message->message, 0, 0xFFFFFFFF);
      *(__m128i *)((char *)&this->texts._Myfirst->playerName._Bx
                 + (((char *)this->texts._Mylast - (char *)this->texts._Myfirst) & 0xFFFFFFC0)
                 - 16) = _mm_loadu_si128((const __m128i *)&this->playerColor);
    }
  }
}
void __userpurge ACChat::render(ACChat *this@<ecx>, int a2@<esi>, float dt)
{
  ACChat_vtbl *v4; // eax
  Sim *v5; // eax
  GLRenderer *v6; // esi
  Font *v7; // ecx
  ksgui::Form *v8; // ecx
  float v9; // xmm1_4
  unsigned int v10; // ebx
  int v11; // esi
  ChatElement *v12; // ecx
  const std::wstring *v13; // eax
  Font *v14; // ecx
  Font *v15; // ecx
  unsigned int v16; // eax
  unsigned int r_8; // [esp+14h] [ebp-70h]
  __int64 v18; // [esp+20h] [ebp-64h]
  float v19; // [esp+28h] [ebp-5Ch]
  ksgui::ksRect wrect; // [esp+30h] [ebp-54h] BYREF
  float cc[7]; // [esp+40h] [ebp-44h] BYREF
  std::wstring s; // [esp+5Ch] [ebp-28h] BYREF
  int v23; // [esp+80h] [ebp-4h]

  ksgui::Control::render(this, (int)this, a2, dt, v18, v19);
  v4 = this->__vftable;
  wrect.left = 0.0;
  cc[0] = 0.0;
  wrect.top = 0.0;
  wrect.right = 1.0;
  wrect.bottom = 1.0;
  v4->getWorldRect(this, &wrect);
  v5 = this->sim;
  wrect.left = this->rect.left + wrect.left;
  wrect.top = this->rect.top + wrect.top;
  v6 = v5->game->graphics->gl;
  GLRenderer::color4f(v6, colTitleBar_1.x, colTitleBar_1.y, colTitleBar_1.z, colTitleBar_1.w);
  GLRenderer::quad(v6, wrect.left, wrect.top, this->rect.right - this->rect.left, 20.0, 0, 0);
  Font::setColor(this->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  s._Myres = 7;
  s._Mysize = 0;
  s._Bx._Buf[0] = 0;
  std::wstring::assign(&s, L"CHAT", 4u);
  v7 = this->titleFont._Ptr;
  v23 = 0;
  Font::blitString(v7, wrect.left + 10.0, wrect.top + 1.0, &s, 1.0, eAlignLeft);
  v23 = -1;
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  v8 = (ksgui::Form *)this->inpTest;
  v9 = this->rect.bottom - this->rect.top;
  wrect.top = wrect.top + 20.0;
  ksgui::Form::setPosition(v8, 10.0, (float)(v9 - (float)(v8->rect.bottom - v8->rect.top)) - 10.0);
  ((void (*)(ksgui::TextInput *, _DWORD, int))this->inpTest->setSize)(
    this->inpTest,
    (float)(this->rect.right - this->rect.left) - 20.0,
    1106247680);
  v10 = 0;
  if ( this->texts._Mylast - this->texts._Myfirst )
  {
    v11 = 0;
    do
    {
      Font::setColor(this->playerNameFont._Ptr, &this->texts._Myfirst[v11].color);
      v12 = &this->texts._Myfirst[v11];
      cc[1] = wrect.left + 15.0;
      r_8 = v12->playerName._Mysize;
      cc[2] = cc[0] + wrect.top;
      if ( std::wstring::compare(&v12->playerName, 0, r_8, word_17BE9D8, 0) )
      {
        v13 = std::operator+<wchar_t>(&s, &this->texts._Myfirst[v11].playerName, L":");
        v14 = this->playerNameFont._Ptr;
        v23 = 1;
        Font::blitString(v14, cc[1], cc[2] + 2.0, v13, 1.0, eAlignLeft);
        v23 = -1;
        if ( s._Myres >= 8 )
          operator delete(s._Bx._Ptr);
      }
      v15 = this->playerTextFont._Ptr;
      *(_OWORD *)&cc[3] = _xmm;
      Font::setColor(v15, (const vec4f *)&cc[3]);
      Font::blitString(
        this->playerTextFont._Ptr,
        (float)(this->playerNameFont._Ptr->scale * 0.57 * (double)(this->texts._Myfirst[v11].playerName._Mysize + 1))
      + cc[1],
        cc[2],
        &this->texts._Myfirst[v11].text,
        1.0,
        eAlignLeft);
      ++v10;
      ++v11;
      v16 = this->texts._Mylast - this->texts._Myfirst;
      cc[0] = cc[0] + 15.0;
    }
    while ( v10 < v16 );
  }
}
