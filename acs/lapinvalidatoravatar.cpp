#include "lapinvalidatoravatar.h
void LapInvalidatorAvatar::LapInvalidatorAvatar(LapInvalidatorAvatar *this, Sim *sim)
{
  Game *v3; // eax
  Texture *v4; // eax
  Font *v5; // eax
  Font *v6; // eax
  Font *v7; // esi
  std::wstring v8; // [esp-10h] [ebp-74h] BYREF
  unsigned int v9; // [esp+8h] [ebp-5Ch]
  Font *v10; // [esp+18h] [ebp-4Ch]
  LapInvalidatorAvatar *v11; // [esp+1Ch] [ebp-48h]
  std::wstring filename; // [esp+20h] [ebp-44h] BYREF
  Texture result; // [esp+38h] [ebp-2Ch] BYREF
  int v14; // [esp+60h] [ebp-4h]

  v11 = this;
  v9 = (unsigned int)sim->game;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"LAP_INVALIDATOR_AVATAR", 0x16u);
  GameObject::GameObject(this, v8, (Game *)v9);
  this->__vftable = (LapInvalidatorAvatar_vtbl *)&LapInvalidatorAvatar::`vftable';
  this->sim = sim;
  v14 = 0;
  this->font._Myptr = 0;
  this->dangerIcon.kid = 0;
  this->dangerIcon.fileName._Myres = 7;
  this->dangerIcon.fileName._Mysize = 0;
  this->dangerIcon.fileName._Bx._Buf[0] = 0;
  this->backColor.x = 0.0;
  this->backColor.y = 0.0;
  this->backColor.z = 0.0;
  this->backColor.w = 0.0;
  v9 = 26;
  this->borderColor.x = 0.0;
  this->borderColor.y = 0.0;
  this->borderColor.z = 0.0;
  this->borderColor.w = 0.0;
  v8._Myres = (unsigned int)L"content/texture/danger.png";
  LOBYTE(v14) = 2;
  this->invalidLapMessageTime = 0.0;
  this->lastCurrentLapValid = 1;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, (const wchar_t *)v8._Myres, v9);
  v3 = sim->game;
  LOBYTE(v14) = 3;
  v4 = ResourceStore::getTexture(v3->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->dangerIcon.kid = v4->kid;
  LOBYTE(v14) = 4;
  if ( &this->dangerIcon.fileName != &v4->fileName )
    std::wstring::assign(&this->dangerIcon.fileName, &v4->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v14) = 3;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v14) = 2;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v5 = (Font *)operator new(24);
  v10 = v5;
  LOBYTE(v14) = 5;
  if ( v5 )
    Font::Font(v5, eFontProportional, 15.0, 0, 0);
  else
    v6 = 0;
  v7 = this->font._Myptr;
  LOBYTE(v14) = 2;
  this->font._Myptr = v6;
  if ( v7 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v7);
    operator delete(v7);
  }
  this->backColor = (vec4f)_xmm;
  this->borderColor = (vec4f)_xmm;
}
LapInvalidatorAvatar *LapInvalidatorAvatar::`scalar deleting destructor'(LapInvalidatorAvatar *this, unsigned int a2)
{
  Font *v3; // edi

  this->__vftable = (LapInvalidatorAvatar_vtbl *)&LapInvalidatorAvatar::`vftable';
  OnSetupAppCreated::~OnSetupAppCreated(&this->dangerIcon);
  v3 = this->font._Myptr;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v3);
    operator delete(v3);
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void LapInvalidatorAvatar::renderHUD(LapInvalidatorAvatar *this, float deltaT)
{
  float v2; // ebp
  CarAvatar *v3; // eax
  _DWORD *v4; // ecx
  int v5; // eax
  float *v6; // esi
  SystemMessage *v7; // ecx
  float v8; // xmm1_4
  int v9; // eax
  GLRenderer *v10; // edi
  Sim *v11; // ecx
  CarAvatar *v12; // eax
  std::wstring *v13; // ebp
  std::wstring *v14; // ebx
  std::wstring *v15; // edi
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // ebx
  std::wstring *v26; // edi
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  std::wstring *v31; // eax
  float v32; // xmm1_4
  Font *v33; // ecx
  std::wstring *v34; // eax
  SessionType v35; // esi
  CarAvatar *v36; // eax
  bool v37; // al
  float v38; // xmm1_4
  int v39; // ecx
  float *v40; // esi
  int v41; // eax
  SystemMessage *v42; // ecx
  float v43; // xmm1_4
  int v44; // eax
  GLRenderer *v45; // edi
  const std::wstring *v46; // eax
  const std::wstring *v47; // eax
  float v48; // xmm1_4
  Font *v49; // ecx
  const std::wstring *v50; // eax
  const std::wstring *v51; // eax
  Font *v52; // ecx
  float v53; // [esp+40h] [ebp-37Ch] BYREF
  int v54; // [esp+44h] [ebp-378h] BYREF
  float v55; // [esp+48h] [ebp-374h] BYREF
  long double pen; // [esp+4Ch] [ebp-370h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v57; // [esp+54h] [ebp-368h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v58; // [esp+104h] [ebp-2B8h] BYREF
  std::wstring line; // [esp+1B4h] [ebp-208h] BYREF
  std::wstring text; // [esp+1CCh] [ebp-1F0h] BYREF
  std::wstring result; // [esp+1E4h] [ebp-1D8h] BYREF
  std::wstring penalty; // [esp+1FCh] [ebp-1C0h] BYREF
  std::wstring v63; // [esp+214h] [ebp-1A8h] BYREF
  std::wstring v64; // [esp+22Ch] [ebp-190h] BYREF
  std::wstring v65; // [esp+244h] [ebp-178h] BYREF
  std::wstring v66; // [esp+25Ch] [ebp-160h] BYREF
  std::wstring v67; // [esp+274h] [ebp-148h] BYREF
  std::wstring v68; // [esp+28Ch] [ebp-130h] BYREF
  std::wstring v69; // [esp+2A4h] [ebp-118h] BYREF
  std::wstring v70; // [esp+2BCh] [ebp-100h] BYREF
  std::wstring v71; // [esp+2D4h] [ebp-E8h] BYREF
  Session v72; // [esp+2ECh] [ebp-D0h] BYREF
  std::wstring v73; // [esp+34Ch] [ebp-70h] BYREF
  std::wstring v74; // [esp+364h] [ebp-58h] BYREF
  std::wstring v75; // [esp+37Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v76; // [esp+394h] [ebp-28h] BYREF
  int v77; // [esp+3B8h] [ebp-4h]

  v2 = *(float *)&this;
  LODWORD(v53) = this;
  v54 = 0;
  v3 = Sim::getCar(this->sim, 0);
  pen = CarAvatar::hasPenalty(v3);
  if ( pen <= 0.0
    || ReplayManager::isInReplaymode(*(ReplayManager **)(*(_DWORD *)(LODWORD(v2) + 52) + 228))
    || (v4 = *(_DWORD **)(LODWORD(v2) + 52), *(_BYTE *)(v4[37] + 244)) )
  {
    v35 = RaceManager::getCurrentSession(*(RaceManager **)(*(_DWORD *)(LODWORD(v2) + 52) + 224), &v72)->sessionType;
    if ( v72.name._Myres >= 8 )
      operator delete(v72.name._Bx._Ptr);
    v72.name._Myres = 7;
    v72.name._Mysize = 0;
    v72.name._Bx._Buf[0] = 0;
    if ( v72.spawSet._Myres >= 8 )
      operator delete(v72.spawSet._Bx._Ptr);
    if ( v35 != Drag && v35 != Drift && v35 != TimeAttack && v35 != Race )
    {
      v36 = Sim::getCar(*(Sim **)(LODWORD(v2) + 52), 0);
      v37 = CarAvatar::isCurrentLapValid(v36);
      if ( !v37 && *(_BYTE *)(LODWORD(v2) + 124) )
        *(_DWORD *)(LODWORD(v2) + 120) = 1084227584;
      v38 = *(float *)(LODWORD(v2) + 120);
      *(_BYTE *)(LODWORD(v2) + 124) = v37;
      if ( v38 > 0.0 )
      {
        *(_DWORD *)v57.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v57.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v57.gap68);
        v77 = 25;
        v54 = 1;
        std::wiostream::basic_iostream<wchar_t>(&v57, &v57.gap10[8], 0);
        v77 = 26;
        *(_DWORD *)&v57.gap0[*(_DWORD *)(*(_DWORD *)v57.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)((char *)&pen + *(_DWORD *)(*(_DWORD *)v57.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v57.gap0 + 4)
                                                                             - 104;
        std::wstreambuf::wstreambuf(&v57.gap10[8]);
        *(_DWORD *)&v57.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v57.gap10[64] = 0;
        *(_DWORD *)&v57.gap10[68] = 0;
        v39 = *(_DWORD *)(LODWORD(v2) + 52);
        v40 = &v53;
        v77 = 28;
        v41 = *(_DWORD *)(v39 + 4);
        v42 = *(SystemMessage **)(v39 + 216);
        v43 = *(float *)(*(_DWORD *)(*(_DWORD *)(v41 + 252) + 92) + 28) - 1.0;
        v44 = *(_DWORD *)(*(_DWORD *)(LODWORD(v2) + 4) + 192);
        v53 = v43;
        v55 = (float)*(int *)(v44 + 20);
        if ( v55 <= v43 )
          v40 = &v55;
        SystemMessage::clearMessage(v42);
        v45 = *(GLRenderer **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v2) + 52) + 4) + 192) + 692);
        GLRenderer::color4f(v45, (const vec4f *)(LODWORD(v2) + 88));
        GLRenderer::quad(v45, 0.0, 0.0, *v40, 79.0, 0, 0);
        GLRenderer::color4f(v45, (const vec4f *)(LODWORD(v2) + 104));
        GLRenderer::begin(v45, eLines, 0);
        GLRenderer::vertex3f(v45, 0.0, 80.0, 0.0);
        GLRenderer::vertex3f(v45, *v40, 80.0, 0.0);
        GLRenderer::end(v45);
        GLRenderer::color4f(v45, 1.0, 1.0, 1.0, 1.0);
        std::wstring::wstring(&text, L"CUT DETECTED");
        LOBYTE(v77) = 29;
        v46 = acTranslate(&result, &text);
        LOBYTE(v77) = 30;
        std::operator<<<wchar_t>((std::wostream *)v57.gap10, v46);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        LOBYTE(v77) = 28;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        Font::setColor(*(Font **)(LODWORD(v2) + 56), 1.0, 0.0, 0.0, 1.0);
        *(_BYTE *)(*(_DWORD *)(LODWORD(v2) + 56) + 4) = 1;
        v47 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v57, &result);
        v48 = *v40 * 0.5;
        v49 = *(Font **)(LODWORD(v2) + 56);
        LOBYTE(v77) = 31;
        v53 = v48;
        Font::blitString(v49, v48, 5.0, v47, 2.0, eAlignCenter);
        LOBYTE(v77) = 28;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        *(_DWORD *)v58.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v58.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v58.gap68);
        LOBYTE(v77) = 32;
        v54 = 3;
        std::wiostream::basic_iostream<wchar_t>(&v58, &v58.gap10[8], 0);
        v77 = 33;
        *(_DWORD *)&v58.gap0[*(_DWORD *)(*(_DWORD *)v58.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)&v57.gap68[*(_DWORD *)(*(_DWORD *)v58.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v58.gap0 + 4) - 104;
        std::wstreambuf::wstreambuf(&v58.gap10[8]);
        *(_DWORD *)&v58.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v58.gap10[64] = 0;
        *(_DWORD *)&v58.gap10[68] = 0;
        LOBYTE(v77) = 35;
        std::wstring::wstring(&text, L"LAP WILL NOT COUNT");
        LOBYTE(v77) = 36;
        v50 = acTranslate(&result, &text);
        LOBYTE(v77) = 37;
        std::operator<<<wchar_t>((std::wostream *)v58.gap10, v50);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        LOBYTE(v77) = 35;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        v51 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v58, &result);
        v52 = *(Font **)(LODWORD(v2) + 56);
        LOBYTE(v77) = 38;
        Font::blitString(v52, v53, 40.0, v51, 2.0, eAlignCenter);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        *(float *)(LODWORD(v2) + 120) = *(float *)(LODWORD(v2) + 120) - deltaT;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v58);
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v57);
      }
    }
  }
  else
  {
    v5 = v4[1];
    v6 = (float *)&v54;
    v7 = (SystemMessage *)v4[54];
    v8 = *(float *)(*(_DWORD *)(*(_DWORD *)(v5 + 252) + 92) + 28) - 1.0;
    v9 = *(_DWORD *)(*(_DWORD *)(LODWORD(v2) + 4) + 192);
    v54 = LODWORD(v8);
    v55 = (float)*(int *)(v9 + 20);
    if ( v55 <= v8 )
      v6 = &v55;
    SystemMessage::clearMessage(v7);
    v10 = *(GLRenderer **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v2) + 52) + 4) + 192) + 692);
    GLRenderer::color4f(v10, (const vec4f *)(LODWORD(v2) + 88));
    GLRenderer::quad(v10, 0.0, 0.0, *v6, 79.0, 0, 0);
    GLRenderer::color4f(v10, (const vec4f *)(LODWORD(v2) + 104));
    GLRenderer::begin(v10, eLines, 0);
    GLRenderer::vertex3f(v10, 0.0, 80.0, 0.0);
    GLRenderer::vertex3f(v10, *v6, 80.0, 0.0);
    GLRenderer::end(v10);
    GLRenderer::color4f(v10, 1.0, 1.0, 1.0, 1.0);
    penalty._Myres = 7;
    penalty._Mysize = 0;
    penalty._Bx._Buf[0] = 0;
    v11 = *(Sim **)(LODWORD(v2) + 52);
    v77 = 0;
    v12 = Sim::getCar(v11, 0);
    if ( CarAvatar::isMinSpeedPenaltyClearDisabled(v12) )
    {
      std::wstring::wstring(&v64, L"SECONDS");
      LOBYTE(v77) = 16;
      std::wstring::wstring(&text, L"PENALTY, SLOW DOWN FOR");
      LOBYTE(v77) = 17;
      v25 = acTranslate(&v70, &v64);
      LOBYTE(v77) = 18;
      v26 = std::to_wstring(&v68, (int)pen);
      LOBYTE(v77) = 19;
      v27 = acTranslate(&v65, &text);
      LOBYTE(v77) = 20;
      v28 = std::operator+<wchar_t>(&v67, v27, L" ");
      LOBYTE(v77) = 21;
      v29 = std::operator+<wchar_t>(&v69, v28, v26);
      LOBYTE(v77) = 22;
      v30 = std::operator+<wchar_t>(&v66, v29, L" ");
      LOBYTE(v77) = 23;
      v31 = std::operator+<wchar_t>(&result, v30, v25);
      std::wstring::operator=(&penalty, v31);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v66);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v67);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v65);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      LOBYTE(v77) = 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v64);
    }
    else
    {
      line._Myres = 7;
      line._Mysize = 0;
      line._Bx._Buf[0] = 0;
      LOBYTE(v77) = 1;
      if ( Speed::useMPH )
        std::wstring::assign(&line, L"21 MPH");
      else
        std::wstring::assign(&line, L"35 KMH");
      std::wstring::wstring(&text, L"OR SLOW DOWN TO");
      LOBYTE(v77) = 2;
      std::wstring::wstring(&v64, L"SECONDS");
      LOBYTE(v77) = 3;
      std::wstring::wstring(&v63, L"PENALTY, SLOW DOWN FOR");
      LOBYTE(v77) = 4;
      v13 = acTranslate(&result, &text);
      LOBYTE(v77) = 5;
      v14 = acTranslate(&v66, &v64);
      LOBYTE(v77) = 6;
      v15 = std::to_wstring(&v69, (int)pen);
      LOBYTE(v77) = 7;
      v16 = acTranslate(&v67, &v63);
      LOBYTE(v77) = 8;
      v17 = std::operator+<wchar_t>(&v65, v16, L" ");
      LOBYTE(v77) = 9;
      v18 = std::operator+<wchar_t>(&v68, v17, v15);
      LOBYTE(v77) = 10;
      v19 = std::operator+<wchar_t>(&v70, v18, L" ");
      LOBYTE(v77) = 11;
      v20 = std::operator+<wchar_t>(&v74, v19, v14);
      LOBYTE(v77) = 12;
      v21 = std::operator+<wchar_t>(&v75, v20, L" ");
      LOBYTE(v77) = 13;
      v22 = std::operator+<wchar_t>(&v71, v21, v13);
      LOBYTE(v77) = 14;
      v23 = std::operator+<wchar_t>(&v76.name, v22, L" ");
      LOBYTE(v77) = 15;
      v24 = std::operator+<wchar_t>(&v73, v23, &line);
      std::wstring::operator=(&penalty, v24);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v73);
      std::wstring::~wstring(&v76);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v71);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v75);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v74);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v70);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v68);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v65);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v67);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v69);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v66);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v63);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v64);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      LOBYTE(v77) = 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&line);
      v2 = v53;
    }
    Font::setColor(*(Font **)(LODWORD(v2) + 56), 1.0, 0.0, 0.0, 1.0);
    v32 = *v6 * 0.5;
    *(_BYTE *)(*(_DWORD *)(LODWORD(v2) + 56) + 4) = 1;
    v33 = *(Font **)(LODWORD(v2) + 56);
    v53 = v32;
    Font::blitString(v33, v32, 5.0, &penalty, 2.0, eAlignCenter);
    std::wstring::wstring(&v63, L"BEFORE THE END OF CURRENT LAP");
    LOBYTE(v77) = 24;
    v34 = acTranslate(&line, &v63);
    std::wstring::operator=(&penalty, v34);
    if ( line._Myres >= 8 )
      operator delete(line._Bx._Ptr);
    line._Myres = 7;
    line._Mysize = 0;
    line._Bx._Buf[0] = 0;
    LOBYTE(v77) = 0;
    if ( v63._Myres >= 8 )
      operator delete(v63._Bx._Ptr);
    Font::blitString(*(Font **)(LODWORD(v2) + 56), v53, 40.0, &penalty, 2.0, eAlignCenter);
    if ( penalty._Myres >= 8 )
      operator delete(penalty._Bx._Ptr);
  }
}
