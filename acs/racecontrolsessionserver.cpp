#include "racecontrolsessionserver.h
void RaceControlSessionServer::RaceControlSessionServer(RaceControlSessionServer *this, Sim *aSim)
{
  Game *v3; // eax
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  Font *v7; // eax
  Font *v8; // eax
  std::_Ref_count_base *v9; // edi
  std::shared_ptr<Font> _Right; // [esp+20h] [ebp-38h] BYREF
  Sim *v11; // [esp+28h] [ebp-30h]
  RaceControlSessionServer *v12; // [esp+2Ch] [ebp-2Ch]
  std::wstring iname; // [esp+30h] [ebp-28h] BYREF
  int v14; // [esp+54h] [ebp-4h]

  v12 = this;
  v11 = aSim;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"RACE_CONTROL_SESSION_SERVER", 0x1Bu);
  v3 = aSim->game;
  v14 = 0;
  ksgui::Control::Control(this, &iname, v3->gui);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->__vftable = (RaceControlSessionServer_vtbl *)&RaceControlSessionServer::`vftable';
  this->sim = aSim;
  this->titleFont._Ptr = 0;
  this->titleFont._Rep = 0;
  this->dataFont._Ptr = 0;
  this->dataFont._Rep = 0;
  LOBYTE(v14) = 4;
  v4 = (Font *)operator new(24);
  _Right._Ptr = v4;
  LOBYTE(v14) = 5;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 14.0, 1, 1);
  else
    v5 = 0;
  LOBYTE(v14) = 4;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v5);
  std::shared_ptr<Font>::operator=(&this->titleFont, &_Right);
  v6 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Weaks, 0xFFFFFFFF) )
        v6->_Delete_this(v6);
    }
  }
  v7 = (Font *)operator new(24);
  _Right._Ptr = v7;
  LOBYTE(v14) = 6;
  if ( v7 )
    Font::Font(v7, eFontProportional, 14.0, 0, 1);
  else
    v8 = 0;
  LOBYTE(v14) = 4;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v8);
  std::shared_ptr<Font>::operator=(&this->dataFont, &_Right);
  v9 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v9->_Destroy(v9);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v9->_Weaks) )
        ((void (*)(void))v9->_Delete_this)();
    }
  }
  this->sim = v11;
  *(_WORD *)&this->drawBorder = 0;
}
void RaceControlSessionServer::~RaceControlSessionServer(RaceControlSessionServer *this)
{
  std::_Ref_count_base *v2; // esi
  std::_Ref_count_base *v3; // esi

  this->__vftable = (RaceControlSessionServer_vtbl *)&RaceControlSessionServer::`vftable';
  v2 = this->dataFont._Rep;
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Uses, 0xFFFFFFFF) )
    {
      v2->_Destroy(v2);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Weaks, 0xFFFFFFFF) )
        v2->_Delete_this(v2);
    }
  }
  v3 = this->titleFont._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v3->_Weaks) )
        v3->_Delete_this(v3);
    }
  }
  ksgui::Control::~Control(this);
}
RaceControlSessionServer *RaceControlSessionServer::`scalar deleting destructor'(RaceControlSessionServer *this, unsigned int a2)
{
  RaceControlSessionServer::~RaceControlSessionServer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge RaceControlSessionServer::render(RaceControlSessionServer *this@<ecx>, int a2@<esi>, float dt)
{
  RaceControlSessionServer_vtbl *v4; // eax
  Sim *v5; // eax
  GLRenderer *v6; // ebp
  const std::wstring *v7; // eax
  Font *v8; // ecx
  Font *v9; // ecx
  ACClient *v10; // ecx
  const std::wstring *v11; // eax
  Font *v12; // ecx
  int v13; // ebx
  const std::wstring *v14; // eax
  Font *v15; // ecx
  Sim *v16; // eax
  const std::wstring *v17; // eax
  Font *v18; // ecx
  Sim *v19; // ecx
  const std::wstring *v20; // esi
  Sim *v21; // ecx
  std::wostream *v22; // eax
  std::wostream *v23; // eax
  std::wostream *v24; // eax
  const std::wstring *v25; // eax
  Font *v26; // ecx
  vec4f r; // xmm0
  int v28; // ebx
  const std::wstring *v29; // eax
  int v30; // eax
  int v31; // eax
  const std::wstring *v32; // eax
  const std::wstring *v33; // eax
  const std::wstring *v34; // eax
  const std::wstring *v35; // eax
  int v36; // eax
  int v37; // eax
  const std::wstring *v38; // eax
  const std::wstring *v39; // eax
  const std::wstring *v40; // eax
  const std::wstring *v41; // eax
  Font *v42; // ecx
  int v43; // ebx
  Sim *v44; // eax
  const std::wstring *v45; // eax
  const std::wstring *v46; // eax
  Font *v47; // ecx
  Sim *v48; // eax
  const std::wstring *v49; // eax
  const std::wstring *v50; // eax
  Font *v51; // ecx
  const std::wstring *v52; // eax
  Sim *v53; // ecx
  std::wostream *v54; // eax
  std::wostream *v55; // eax
  const std::wstring *v56; // eax
  Font *v57; // ecx
  const std::wstring *v58; // eax
  Sim *v59; // ecx
  std::wostream *v60; // eax
  std::wostream *v61; // eax
  const std::wstring *v62; // eax
  Font *v63; // ecx
  const std::wstring *v64; // eax
  Sim *v65; // ecx
  std::wostream *v66; // eax
  std::wostream *v67; // eax
  const std::wstring *v68; // eax
  Font *v69; // ecx
  Sim *v70; // eax
  const std::wstring *v71; // eax
  const std::wstring *v72; // eax
  Font *v73; // ecx
  Sim *v74; // eax
  JumpStartPenaltyMode v75; // eax
  __int32 v76; // eax
  const std::wstring *v77; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v78; // ecx
  const std::wstring *v79; // eax
  const std::wstring *v80; // eax
  const std::wstring *v81; // eax
  Font *v82; // ecx
  int height; // [esp+38h] [ebp-934h]
  int b; // [esp+3Ch] [ebp-930h]
  int ba; // [esp+3Ch] [ebp-930h]
  int bb; // [esp+3Ch] [ebp-930h]
  const wchar_t *a; // [esp+40h] [ebp-92Ch]
  __int64 v88; // [esp+44h] [ebp-928h]
  float v89; // [esp+4Ch] [ebp-920h]
  bool isDark; // [esp+77h] [ebp-8F5h] BYREF
  ksgui::ksRect wrect; // [esp+78h] [ebp-8F4h] BYREF
  int v92; // [esp+88h] [ebp-8E4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v93; // [esp+8Ch] [ebp-8E0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v94; // [esp+13Ch] [ebp-830h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v95; // [esp+1ECh] [ebp-780h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > data; // [esp+29Ch] [ebp-6D0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v97; // [esp+34Ch] [ebp-620h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v98; // [esp+3FCh] [ebp-570h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v99; // [esp+4ACh] [ebp-4C0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v100; // [esp+55Ch] [ebp-410h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v101; // [esp+60Ch] [ebp-360h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v102; // [esp+6BCh] [ebp-2B0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v103; // [esp+76Ch] [ebp-200h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v104; // [esp+81Ch] [ebp-150h] BYREF
  std::wstring text; // [esp+8CCh] [ebp-A0h] BYREF
  std::wstring t1; // [esp+8E4h] [ebp-88h] BYREF
  std::wstring t2; // [esp+8FCh] [ebp-70h] BYREF
  std::wstring result; // [esp+914h] [ebp-58h] BYREF
  std::wstring v109; // [esp+92Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v110; // [esp+944h] [ebp-28h] BYREF
  int v111; // [esp+964h] [ebp-8h]
  int v112; // [esp+968h] [ebp-4h]
  int retaddr; // [esp+96Ch] [ebp+0h]

  v92 = 0;
  if ( !this->sim->client )
    return;
  ksgui::Control::render(this, (int)this, a2, dt, v88, v89);
  v4 = this->__vftable;
  wrect.left = 0.0;
  wrect.top = 0.0;
  wrect.right = 1.0;
  wrect.bottom = 1.0;
  v4->getWorldRect(this, &wrect);
  v5 = this->sim;
  wrect.left = wrect.left + this->rect.left;
  wrect.top = this->rect.top + wrect.top;
  v6 = v5->game->graphics->gl;
  GLRenderer::color4f(v6, colTitleBar_7.x, colTitleBar_7.y, colTitleBar_7.z, colTitleBar_7.w);
  GLRenderer::quad(v6, wrect.left, wrect.top, this->rect.right - this->rect.left, 20.0, 0, 0);
  Font::setColor(this->titleFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  t2._Myres = 7;
  t2._Mysize = 0;
  t2._Bx._Buf[0] = 0;
  std::wstring::assign(&t2, L"SERVER", 6u);
  v112 = 0;
  v7 = acTranslate(&result, &t2);
  v8 = this->titleFont._Ptr;
  LOBYTE(v112) = 1;
  Font::blitString(v8, wrect.left + 10.0, wrect.top + 1.0, v7, 1.0, eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v112 = -1;
  if ( t2._Myres >= 8 )
    operator delete(t2._Bx._Ptr);
  wrect.top = wrect.top + 20.0;
  GLRenderer::color4f(v6, colDarkBar_7.x, colDarkBar_7.y, colDarkBar_7.z, colDarkBar_7.w);
  GLRenderer::quad(v6, wrect.left, wrect.top, this->rect.right - this->rect.left, 30.5, 0, 0);
  v9 = this->dataFont._Ptr;
  isDark = 0;
  t2._Bx = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
  Font::setColor(v9, (const vec4f *)&t2);
  v10 = this->sim->client;
  if ( v10->serverName._Mysize <= 0x1E )
  {
    *(_DWORD *)v98.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v98.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v98.gap68);
    v112 = 14;
    v13 = 4;
    v92 = 4;
    std::wiostream::basic_iostream<wchar_t>(&v98, &v98.gap10[8], 0);
    v112 = 15;
    *(_DWORD *)&v98.gap0[*(_DWORD *)(*(_DWORD *)v98.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v97.gap68[*(_DWORD *)(*(_DWORD *)v98.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v98.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v98.gap10[8]);
    *(_DWORD *)&v98.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v98.gap10[64] = 0;
    *(_DWORD *)&v98.gap10[68] = 0;
    v16 = this->sim;
    v112 = 17;
    std::operator<<<wchar_t>((std::wostream *)v98.gap10, &v16->client->serverName);
    v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v98, &text);
    v18 = this->dataFont._Ptr;
    LOBYTE(v112) = 18;
    Font::blitString(v18, wrect.left + 30.0, wrect.top + 6.0999999, v17, 1.0, eAlignLeft);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v112 = -1;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v98);
  }
  else
  {
    std::wstring::substr(&v10->serverName, &t1, 0, 0x1Eu);
    v112 = 2;
    std::wstring::substr(&this->sim->client->serverName, &t2, 0x1Eu, 0xFFFFFFFF);
    LOBYTE(v112) = 3;
    *(_DWORD *)data.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)data.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(data.gap68);
    LOBYTE(v112) = 4;
    v92 = 1;
    std::wiostream::basic_iostream<wchar_t>(&data, &data.gap10[8], 0);
    v112 = 5;
    *(_DWORD *)&data.gap0[*(_DWORD *)(*(_DWORD *)data.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v95.gap68[*(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)data.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&data.gap10[8]);
    *(_DWORD *)&data.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&data.gap10[64] = 0;
    *(_DWORD *)&data.gap10[68] = 0;
    LOBYTE(v112) = 7;
    std::operator<<<wchar_t>((std::wostream *)data.gap10, &t1);
    v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&data, &text);
    v12 = this->dataFont._Ptr;
    LOBYTE(v112) = 8;
    Font::blitString(v12, wrect.left + 30.0, (float)(wrect.top + 6.0999999) - 5.0, v11, 0.80000001, eAlignLeft);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    LOBYTE(v112) = 3;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&data);
    *(_DWORD *)v97.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v97.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v97.gap68);
    LOBYTE(v112) = 9;
    v13 = 3;
    v92 = 3;
    std::wiostream::basic_iostream<wchar_t>(&v97, &v97.gap10[8], 0);
    v112 = 10;
    *(_DWORD *)&v97.gap0[*(_DWORD *)(*(_DWORD *)v97.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&data.gap68[*(_DWORD *)(*(_DWORD *)v97.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v97.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v97.gap10[8]);
    *(_DWORD *)&v97.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v97.gap10[64] = 0;
    *(_DWORD *)&v97.gap10[68] = 0;
    LOBYTE(v112) = 12;
    std::operator<<<wchar_t>((std::wostream *)v97.gap10, &t2);
    v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v97, &text);
    v15 = this->dataFont._Ptr;
    LOBYTE(v112) = 13;
    Font::blitString(v15, wrect.left + 30.0, (float)(wrect.top + 6.0999999) + 7.0, v14, 0.80000001, eAlignLeft);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v97);
    if ( t2._Myres >= 8 )
      operator delete(t2._Bx._Ptr);
    t2._Myres = 7;
    t2._Mysize = 0;
    t2._Bx._Buf[0] = 0;
    v112 = -1;
    if ( t1._Myres >= 8 )
      operator delete(t1._Bx._Ptr);
  }
  v19 = this->sim;
  wrect.top = wrect.top + 30.5;
  if ( !RaceManager::getInvertedGridPositions(v19->raceManager) )
    goto LABEL_27;
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  *(_DWORD *)v99.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v99.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v99.gap68);
  retaddr = 19;
  v13 |= 8u;
  *(_DWORD *)v93.gap0 = v13;
  std::wiostream::basic_iostream<wchar_t>(&v99.gap0[4], &v99.gap10[12], 0);
  v111 = 20;
  *(_DWORD *)&v98.gap68[*(_DWORD *)(*(_DWORD *)&v98.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v98.gap68[*(_DWORD *)(*(_DWORD *)&v98.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v98.gap68[68] + 4)
                                                                         - 104;
  std::wstreambuf::wstreambuf(&v99.gap10[4]);
  *(_DWORD *)&v99.gap10[4] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v99.gap10[60] = 0;
  *(_DWORD *)&v99.gap10[64] = 0;
  v111 = 22;
  std::wstring::wstring((std::wstring *)&text._Myres, L"Race x2: Reversed Grid");
  LOBYTE(v111) = 23;
  v20 = acTranslate((std::wstring *)&t2._Myres, (const std::wstring *)&text._Myres);
  v21 = this->sim;
  LOBYTE(v111) = 24;
  height = RaceManager::getInvertedGridPositions(v21->raceManager);
  v22 = std::operator<<<wchar_t>((std::wostream *)((char *)&v99._Chcount + 4), v20);
  v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v22, L" ( TOP ");
  v24 = (std::wostream *)std::wostream::operator<<(v23, height);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v24, a);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v112) = 22;
  if ( t1._Myres >= 8 )
    operator delete(t1._Bx._Ptr);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v25 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v99, &text);
  v26 = this->dataFont._Ptr;
  LOBYTE(v112) = 25;
  Font::blitString(v26, wrect.left + 30.0, wrect.top + 6.0999999, v25, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v99);
  if ( isDark )
    r = colDarkBar_7;
  else
LABEL_27:
    r = colDarkTransp_6;
  GLRenderer::color4f(v6, r.x, r.y, r.z, r.w);
  GLRenderer::quad(v6, wrect.left, wrect.top, this->rect.right - this->rect.left, 30.5, 0, 0);
  *(_DWORD *)v93.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  isDark = !isDark;
  *(_DWORD *)v93.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v93.gap68);
  v112 = 26;
  v28 = v13 | 0x10;
  v92 = v28;
  std::wiostream::basic_iostream<wchar_t>(&v93, &v93.gap10[8], 0);
  v112 = 27;
  *(_DWORD *)&v93.gap0[*(_DWORD *)(*(_DWORD *)v93.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v92 + *(_DWORD *)(*(_DWORD *)v93.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v93.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v93.gap10[8]);
  *(_DWORD *)&v93.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v93.gap10[64] = 0;
  *(_DWORD *)&v93.gap10[68] = 0;
  v112 = 29;
  t2._Myres = 7;
  t2._Mysize = 0;
  t2._Bx._Buf[0] = 0;
  std::wstring::assign(&t2, L"TC: ", 4u);
  LOBYTE(v112) = 30;
  v29 = acTranslate(&result, &t2);
  LOBYTE(v112) = 31;
  std::operator<<<wchar_t>((std::wostream *)v93.gap10, v29);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v112) = 29;
  if ( t2._Myres >= 8 )
    operator delete(t2._Bx._Ptr);
  v30 = this->sim->client->serverDrivingAssists.tc;
  if ( v30 )
  {
    v31 = v30 - 1;
    if ( v31 )
    {
      if ( v31 == 1 )
      {
        std::wstring::wstring(&v110.name, L"Yes");
        LOBYTE(v112) = 36;
        v32 = acTranslate(&result, &v110.name);
        LOBYTE(v112) = 37;
        std::operator<<<wchar_t>((std::wostream *)v93.gap10, v32);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        LOBYTE(v112) = 29;
        if ( v110.name._Myres >= 8 )
          operator delete(v110.name._Bx._Ptr);
      }
    }
    else
    {
      std::wstring::wstring(&v109, L"Factory");
      LOBYTE(v112) = 34;
      v33 = acTranslate(&t2, &v109);
      LOBYTE(v112) = 35;
      std::operator<<<wchar_t>((std::wostream *)v93.gap10, v33);
      if ( t2._Myres >= 8 )
        operator delete(t2._Bx._Ptr);
      t2._Myres = 7;
      t2._Mysize = 0;
      t2._Bx._Buf[0] = 0;
      LOBYTE(v112) = 29;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
    }
  }
  else
  {
    std::wstring::wstring(&text, L"No");
    LOBYTE(v112) = 32;
    v34 = acTranslate(&t1, &text);
    LOBYTE(v112) = 33;
    std::operator<<<wchar_t>((std::wostream *)v93.gap10, v34);
    if ( t1._Myres >= 8 )
      operator delete(t1._Bx._Ptr);
    t1._Myres = 7;
    t1._Mysize = 0;
    t1._Bx._Buf[0] = 0;
    LOBYTE(v112) = 29;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  t2._Myres = 7;
  t2._Mysize = 0;
  t2._Bx._Buf[0] = 0;
  std::wstring::assign(&t2, L" / ABS: ", 8u);
  LOBYTE(v112) = 38;
  v35 = acTranslate(&t1, &t2);
  LOBYTE(v112) = 39;
  std::operator<<<wchar_t>((std::wostream *)v93.gap10, v35);
  if ( t1._Myres >= 8 )
    operator delete(t1._Bx._Ptr);
  t1._Myres = 7;
  t1._Mysize = 0;
  t1._Bx._Buf[0] = 0;
  LOBYTE(v112) = 29;
  if ( t2._Myres >= 8 )
    operator delete(t2._Bx._Ptr);
  v36 = this->sim->client->serverDrivingAssists.abs;
  if ( v36 )
  {
    v37 = v36 - 1;
    if ( v37 )
    {
      if ( v37 == 1 )
      {
        std::wstring::wstring(&v109, L"Yes");
        LOBYTE(v112) = 44;
        v38 = acTranslate(&t2, &v109);
        LOBYTE(v112) = 45;
        std::operator<<<wchar_t>((std::wostream *)v93.gap10, v38);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&t2);
        LOBYTE(v112) = 29;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v109);
      }
    }
    else
    {
      std::wstring::wstring(&v110.name, L"Factory");
      LOBYTE(v112) = 42;
      v39 = acTranslate(&t1, &v110.name);
      LOBYTE(v112) = 43;
      std::operator<<<wchar_t>((std::wostream *)v93.gap10, v39);
      if ( t1._Myres >= 8 )
        operator delete(t1._Bx._Ptr);
      t1._Myres = 7;
      t1._Mysize = 0;
      t1._Bx._Buf[0] = 0;
      LOBYTE(v112) = 29;
      std::wstring::~wstring(&v110);
    }
  }
  else
  {
    std::wstring::wstring(&text, L"No");
    LOBYTE(v112) = 40;
    v40 = acTranslate(&result, &text);
    LOBYTE(v112) = 41;
    std::operator<<<wchar_t>((std::wostream *)v93.gap10, v40);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v112) = 29;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v41 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v93, &text);
  v42 = this->dataFont._Ptr;
  LOBYTE(v112) = 46;
  Font::blitString(v42, wrect.left + 30.0, wrect.top + 6.0999999, v41, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v93);
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  *(_DWORD *)v94.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v94.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v94.gap68);
  v112 = 47;
  v43 = v28 | 0x20;
  v92 = v43;
  std::wiostream::basic_iostream<wchar_t>(&v94, &v94.gap10[8], 0);
  v112 = 48;
  *(_DWORD *)&v94.gap0[*(_DWORD *)(*(_DWORD *)v94.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v93.gap68[*(_DWORD *)(*(_DWORD *)v94.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v94.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v94.gap10[8]);
  *(_DWORD *)&v94.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v94.gap10[64] = 0;
  *(_DWORD *)&v94.gap10[68] = 0;
  v44 = this->sim;
  v112 = 50;
  if ( v44->client->serverDrivingAssists.stability )
  {
    std::wstring::wstring(&text, L"Stability Control: Allowed");
    LOBYTE(v112) = 51;
    v45 = acTranslate(&t1, &text);
    LOBYTE(v112) = 52;
  }
  else
  {
    std::wstring::wstring(&text, L"Stability Control: Not Allowed");
    LOBYTE(v112) = 53;
    v45 = acTranslate(&t1, &text);
    LOBYTE(v112) = 54;
  }
  std::operator<<<wchar_t>((std::wostream *)v94.gap10, v45);
  if ( t1._Myres >= 8 )
    operator delete(t1._Bx._Ptr);
  LOBYTE(v112) = 50;
  t1._Bx._Buf[0] = 0;
  t1._Mysize = 0;
  t1._Myres = 7;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v46 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v94, &text);
  v47 = this->dataFont._Ptr;
  LOBYTE(v112) = 55;
  Font::blitString(v47, wrect.left + 30.0, wrect.top + 6.0999999, v46, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v94);
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  *(_DWORD *)v95.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v95.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v95.gap68);
  v112 = 56;
  v92 = v43 | 0x40;
  std::wiostream::basic_iostream<wchar_t>(&v95, &v95.gap10[8], 0);
  v112 = 57;
  *(_DWORD *)&v95.gap0[*(_DWORD *)(*(_DWORD *)v95.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v94.gap68[*(_DWORD *)(*(_DWORD *)v95.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v95.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v95.gap10[8]);
  *(_DWORD *)&v95.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v95.gap10[64] = 0;
  *(_DWORD *)&v95.gap10[68] = 0;
  v48 = this->sim;
  v112 = 59;
  if ( v48->client->serverDrivingAssists.autoClutch )
  {
    std::wstring::wstring(&text, L"Auto Clutch: Allowed");
    LOBYTE(v112) = 60;
    v49 = acTranslate(&t1, &text);
    LOBYTE(v112) = 61;
  }
  else
  {
    std::wstring::wstring(&text, L"Auto Clutch: Not Allowed");
    LOBYTE(v112) = 62;
    v49 = acTranslate(&t1, &text);
    LOBYTE(v112) = 63;
  }
  std::operator<<<wchar_t>((std::wostream *)v95.gap10, v49);
  if ( t1._Myres >= 8 )
    operator delete(t1._Bx._Ptr);
  LOBYTE(v112) = 59;
  t1._Bx._Buf[0] = 0;
  t1._Mysize = 0;
  t1._Myres = 7;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v50 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v95, &text);
  v51 = this->dataFont._Ptr;
  LOBYTE(v112) = 64;
  Font::blitString(v51, wrect.left + 30.0, wrect.top + 6.0999999, v50, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v95);
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
    &v102,
    3,
    1);
  v112 = 65;
  std::wstring::wstring(&text, L"Damage: ");
  LOBYTE(v112) = 66;
  v52 = acTranslate(&t1, &text);
  v53 = this->sim;
  LOBYTE(v112) = 67;
  b = (int)(float)(v53->physicsAvatar->engine.mechanicalDamageRate * 100.0);
  v54 = std::operator<<<wchar_t>((std::wostream *)v102.gap10, v52);
  v55 = (std::wostream *)std::wostream::operator<<(v54, b);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v55, L"%");
  if ( t1._Myres >= 8 )
    operator delete(t1._Bx._Ptr);
  t1._Myres = 7;
  t1._Mysize = 0;
  t1._Bx._Buf[0] = 0;
  LOBYTE(v112) = 65;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v56 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v102, &text);
  v57 = this->dataFont._Ptr;
  LOBYTE(v112) = 68;
  Font::blitString(v57, wrect.left + 30.0, wrect.top + 6.0999999, v56, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v102);
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
    &v104,
    3,
    1);
  v112 = 69;
  std::wstring::wstring(&text, L"Fuel Rate: ");
  LOBYTE(v112) = 70;
  v58 = acTranslate(&t1, &text);
  v59 = this->sim;
  LOBYTE(v112) = 71;
  ba = (int)(float)(v59->physicsAvatar->engine.fuelConsumptionRate * 100.0);
  v60 = std::operator<<<wchar_t>((std::wostream *)v104.gap10, v58);
  v61 = (std::wostream *)std::wostream::operator<<(v60, ba);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v61, L"%");
  if ( t1._Myres >= 8 )
    operator delete(t1._Bx._Ptr);
  t1._Myres = 7;
  t1._Mysize = 0;
  t1._Bx._Buf[0] = 0;
  LOBYTE(v112) = 69;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v62 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v104, &text);
  v63 = this->dataFont._Ptr;
  LOBYTE(v112) = 72;
  Font::blitString(v63, wrect.left + 30.0, wrect.top + 6.0999999, v62, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v104);
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
    &v103,
    3,
    1);
  v112 = 73;
  std::wstring::wstring(&text, L"Tyre Wear Rate: ");
  LOBYTE(v112) = 74;
  v64 = acTranslate(&t1, &text);
  v65 = this->sim;
  LOBYTE(v112) = 75;
  bb = (int)(float)(v65->physicsAvatar->engine.tyreConsumptionRate * 100.0);
  v66 = std::operator<<<wchar_t>((std::wostream *)v103.gap10, v64);
  v67 = (std::wostream *)std::wostream::operator<<(v66, bb);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v67, L"%");
  if ( t1._Myres >= 8 )
    operator delete(t1._Bx._Ptr);
  t1._Myres = 7;
  t1._Mysize = 0;
  t1._Bx._Buf[0] = 0;
  LOBYTE(v112) = 73;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v68 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v103, &text);
  v69 = this->dataFont._Ptr;
  LOBYTE(v112) = 76;
  Font::blitString(v69, wrect.left + 30.0, wrect.top + 6.0999999, v68, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v103);
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
    &v101,
    3,
    1);
  v70 = this->sim;
  v112 = 77;
  if ( v70->physicsAvatar->engine.allowTyreBlankets )
  {
    std::wstring::wstring(&text, L"Tyre Blankets: Yes");
    LOBYTE(v112) = 78;
    v71 = acTranslate(&v109, &text);
    LOBYTE(v112) = 79;
  }
  else
  {
    std::wstring::wstring(&text, L"Tyre Blankets: No");
    LOBYTE(v112) = 80;
    v71 = acTranslate(&v109, &text);
    LOBYTE(v112) = 81;
  }
  std::operator<<<wchar_t>((std::wostream *)v101.gap10, v71);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v109);
  LOBYTE(v112) = 77;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v72 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v101, &text);
  v73 = this->dataFont._Ptr;
  LOBYTE(v112) = 82;
  Font::blitString(v73, wrect.left + 30.0, wrect.top + 6.0999999, v72, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v112 = -1;
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v101);
  RaceControlSessionServer::setBackground(this, &wrect, &isDark, v6);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
    &v100,
    3,
    1);
  v74 = this->sim;
  v112 = 83;
  v75 = v74->physicsAvatar->engine.penaltyRules.jumpStartPenaltyMode;
  if ( v75 == eLockOnGridMode )
  {
    std::wstring::wstring(&v110.name, L"False Start: No");
    LOBYTE(v112) = 84;
    v80 = acTranslate(&t2, &v110.name);
    LOBYTE(v112) = 85;
    std::operator<<<wchar_t>((std::wostream *)v100.gap10, v80);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&t2);
    v78 = &v110;
    goto LABEL_111;
  }
  v76 = v75 - 1;
  if ( !v76 )
  {
    std::wstring::wstring(&v109, L"False Start: Teleport To Pits");
    LOBYTE(v112) = 86;
    v79 = acTranslate(&result, &v109);
    LOBYTE(v112) = 87;
    std::operator<<<wchar_t>((std::wostream *)v100.gap10, v79);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    v78 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v109;
    goto LABEL_111;
  }
  if ( v76 == 1 )
  {
    std::wstring::wstring(&text, L"False Start: Drive-through");
    LOBYTE(v112) = 88;
    v77 = acTranslate(&t1, &text);
    LOBYTE(v112) = 89;
    std::operator<<<wchar_t>((std::wostream *)v100.gap10, v77);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&t1);
    v78 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
LABEL_111:
    LOBYTE(v112) = 83;
    std::wstring::~wstring(v78);
  }
  Font::setColor(this->dataFont._Ptr, 1.0, 1.0, 1.0, 1.0);
  v81 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v100, &text);
  v82 = this->dataFont._Ptr;
  LOBYTE(v112) = 90;
  Font::blitString(v82, wrect.left + 30.0, wrect.top + 6.0999999, v81, 1.0, eAlignLeft);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  wrect.top = wrect.top + 30.5;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v100);
}
void RaceControlSessionServer::setBackground(RaceControlSessionServer *this, ksgui::ksRect *wrect, bool *isDark, GLRenderer *gl)
{
  vec4f r; // xmm0

  if ( *isDark )
    r = colDarkBar_7;
  else
    r = colDarkTransp_6;
  GLRenderer::color4f(gl, r.x, r.y, r.z, r.w);
  GLRenderer::quad(gl, wrect->left, wrect->top, this->rect.right - this->rect.left, 30.5, 0, 0);
  *isDark = !*isDark;
}
