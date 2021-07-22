#include "lollipopcrew.h
void __userpurge LollipopCrew::LollipopCrew(LollipopCrew *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, CarAvatar *aCar, mat44f matrix, float side, std::wstring skin)
{
  Sim *v9; // eax
  Game *v10; // eax
  char v11; // al
  std::wstring *v12; // edx
  unsigned int v13; // ecx
  Node *v14; // eax
  bool v15; // cf
  Node *v16; // eax
  Node *v17; // eax
  float v18; // xmm7_4
  Node *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  Sim *v22; // eax
  int v23; // ecx
  Node *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm2_4
  Node *v27; // esi
  int v28; // ecx
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm6_4
  float v36; // xmm2_4
  __int128 v37; // xmm3
  float v38; // xmm2_4
  float v39; // xmm6_4
  float v40; // xmm0_4
  __int128 v41; // xmm3
  float v42; // xmm1_4
  __int128 v43; // xmm2
  __int128 v44; // xmm1
  __int128 v45; // xmm0
  __int128 v46; // xmm2
  __int128 v47; // xmm1
  AnimationPlayer *v48; // ecx
  AnimationPlayer *v49; // eax
  AnimationPlayer *v50; // eax
  AnimationPlayer *v51; // eax
  AnimationPlayer *v52; // eax
  AnimationPlayer *v53; // eax
  std::wstring v54; // [esp-18h] [ebp-1CCh] BYREF
  int v55; // [esp+0h] [ebp-1B4h]
  int v56; // [esp+8h] [ebp-1ACh]
  int v57; // [esp+Ch] [ebp-1A8h]
  mat44f v58; // [esp+10h] [ebp-1A4h] BYREF
  LollipopCrew *v59; // [esp+50h] [ebp-164h]
  int v60; // [esp+54h] [ebp-160h] BYREF
  _BYTE v61[44]; // [esp+58h] [ebp-15Ch] OVERLAPPED
  char v62; // [esp+86h] [ebp-12Eh]
  char v63; // [esp+87h] [ebp-12Dh]
  _BYTE v64[12]; // [esp+88h] [ebp-12Ch] BYREF
  _BYTE kn_100[64]; // [esp+F8h] [ebp-BCh] OVERLAPPED BYREF
  _DWORD v66[3]; // [esp+14Ch] [ebp-68h] BYREF
  std::wstring crewskin; // [esp+158h] [ebp-5Ch] BYREF
  _DWORD v68[2]; // [esp+170h] [ebp-44h] BYREF
  unsigned int v69; // [esp+178h] [ebp-3Ch]
  std::wstring v70; // [esp+17Ch] [ebp-38h] BYREF
  int *v71; // [esp+198h] [ebp-1Ch]
  int v72; // [esp+19Ch] [ebp-18h]
  void *v73; // [esp+1A0h] [ebp-14h]
  int v74; // [esp+1A4h] [ebp-10h]
  int v75; // [esp+1A8h] [ebp-Ch]
  int v76; // [esp+1ACh] [ebp-8h]
  int v77; // [esp+1B0h] [ebp-4h] BYREF
  int retaddr; // [esp+1B4h] [ebp+0h]

  v75 = a2;
  v76 = retaddr;
  v74 = -1;
  v73 = &_ehhandler___0LollipopCrew__QAE_PAVCarAvatar__Vmat44f__MV__basic_string__WU__char_traits__W_std__V__allocator__W_2__std___Z;
  v72 = (int)NtCurrentTeb()->NtTib.ExceptionList;
  v71 = &v77;
  v57 = a4;
  v56 = a3;
  v59 = this;
  v9 = aCar->sim;
  v74 = 0;
  v55 = (int)v9->game;
  v54._Myres = 7;
  v54._Mysize = 0;
  v54._Bx._Buf[0] = 0;
  std::wstring::assign(&v54, L"LOLLIPOP_CREW", 0xDu);
  GameObject::GameObject(this, v54, (Game *)v55);
  LOBYTE(v74) = 1;
  this->__vftable = (LollipopCrew_vtbl *)&LollipopCrew::`vftable';
  this->targetLolliPosition = 1.0;
  this->animationSpeed = 1.0;
  std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&this->animation);
  LOBYTE(v74) = 2;
  std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&this->animationIdleUp);
  LOBYTE(v74) = 3;
  std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&this->animationIdleDw);
  this->player = 0;
  this->playerIdleUp = 0;
  this->playerIdleDw = 0;
  this->sim = aCar->sim;
  v10 = this->game;
  this->car = aCar;
  LOBYTE(v74) = 4;
  KN5IO::KN5IO((KN5IO *)v64, v10->graphics);
  LOBYTE(v74) = 5;
  std::operator+<wchar_t>((std::wstring *)v66, &skin, L"/skin.ini");
  LOBYTE(v74) = 6;
  v63 = 1;
  if ( !Path::fileExists((unsigned int)&v77, (const std::wstring *)v66, 0) )
    goto LABEL_20;
  CarAvatar::openINI(this->car, (INIReader *)kn_100, (const std::wstring *)v66);
  LOBYTE(v74) = 7;
  if ( kn_100[4] )
  {
    std::wstring::wstring(&v70, L"CREW");
    LOBYTE(v74) = 8;
    v11 = INIReader::hasSection((INIReader *)kn_100, &v70);
    v62 = v11;
    LOBYTE(v74) = 7;
    if ( v70._Myres >= 8 )
    {
      operator delete(v70._Bx._Ptr);
      v11 = v62;
    }
    if ( v11 )
    {
      std::wstring::wstring((std::wstring *)&crewskin._Bx._Alias[12], L"SUIT");
      LOBYTE(v74) = 9;
      std::wstring::wstring(&v70, L"CREW");
      LOBYTE(v74) = 10;
      LollipopCrew::loadCrewSkin(
        this,
        (KN5IO *)v64,
        (INIReader *)kn_100,
        &v70,
        (const std::wstring *)&crewskin._Bx._Alias[12]);
      if ( v70._Myres >= 8 )
        operator delete(v70._Bx._Ptr);
      v70._Myres = 7;
      v70._Mysize = 0;
      v70._Bx._Buf[0] = 0;
      LOBYTE(v74) = 7;
      if ( v69 >= 8 )
        operator delete(*(_DWORD *)&crewskin._Bx._Alias[12]);
      std::wstring::wstring((std::wstring *)&crewskin._Bx._Alias[12], L"HELMET");
      LOBYTE(v74) = 11;
      std::wstring::wstring(&v70, L"CREW");
      LOBYTE(v74) = 12;
      LollipopCrew::loadCrewSkin(
        this,
        (KN5IO *)v64,
        (INIReader *)kn_100,
        &v70,
        (const std::wstring *)&crewskin._Bx._Alias[12]);
      if ( v70._Myres >= 8 )
        operator delete(v70._Bx._Ptr);
      v70._Myres = 7;
      v70._Mysize = 0;
      v70._Bx._Buf[0] = 0;
      LOBYTE(v74) = 7;
      if ( v69 >= 8 )
        operator delete(*(_DWORD *)&crewskin._Bx._Alias[12]);
      std::wstring::wstring((std::wstring *)&crewskin._Bx._Alias[12], L"BRAND");
      LOBYTE(v74) = 13;
      std::wstring::wstring(&v70, L"CREW");
      LOBYTE(v74) = 14;
      LollipopCrew::loadCrewSkin(
        this,
        (KN5IO *)v64,
        (INIReader *)kn_100,
        &v70,
        (const std::wstring *)&crewskin._Bx._Alias[12]);
      if ( v70._Myres >= 8 )
        operator delete(v70._Bx._Ptr);
      v70._Myres = 7;
      v70._Mysize = 0;
      v70._Bx._Buf[0] = 0;
      if ( v69 >= 8 )
        operator delete(*(_DWORD *)&crewskin._Bx._Alias[12]);
      v63 = 0;
    }
  }
  LOBYTE(v74) = 6;
  INIReader::~INIReader((INIReader *)kn_100);
  if ( v63 )
  {
LABEL_20:
    v12 = &skin;
    v70._Myres = 7;
    if ( skin._Myres >= 8 )
      v12 = (std::wstring *)skin._Bx._Ptr;
    v70._Mysize = 0;
    v70._Bx._Buf[0] = 0;
    if ( v12->_Bx._Buf[0] )
      v13 = wcslen(v12->_Bx._Buf);
    else
      v13 = 0;
    std::wstring::assign(&v70, v12->_Bx._Buf, v13);
    LOBYTE(v74) = 15;
    KN5IO::addTextureFolder((KN5IO *)v64, &v70);
    LOBYTE(v74) = 6;
    if ( v70._Myres >= 8 )
      operator delete(v70._Bx._Ptr);
  }
  v70._Myres = 7;
  v70._Mysize = 0;
  v70._Bx._Buf[0] = 0;
  if ( side >= 0.0 )
  {
    std::wstring::assign(&v70, L"content/objects3D/pitcrew_Left.kn5", 0x22u);
    LOBYTE(v74) = 20;
    v16 = KN5IO::load((KN5IO *)v64, &v70);
    v15 = v70._Myres < 8;
    this->node = v16;
    LOBYTE(v74) = 6;
    if ( !v15 )
      operator delete(v70._Bx._Ptr);
    v70._Myres = 7;
    v70._Mysize = 0;
    v70._Bx._Buf[0] = 0;
    std::wstring::assign(&v70, L"content/objects3D/pitcrew_Left.ksanim", 0x25u);
    LOBYTE(v74) = 21;
    Animation::load(&this->animation, &v70);
    LOBYTE(v74) = 6;
    if ( v70._Myres >= 8 )
      operator delete(v70._Bx._Ptr);
    v70._Myres = 7;
    v70._Mysize = 0;
    v70._Bx._Buf[0] = 0;
    std::wstring::assign(&v70, L"content/objects3D/pitcrew_Left_idle_up.ksanim", 0x2Du);
    LOBYTE(v74) = 22;
    Animation::load(&this->animationIdleUp, &v70);
    LOBYTE(v74) = 6;
    if ( v70._Myres >= 8 )
      operator delete(v70._Bx._Ptr);
    v70._Myres = 7;
    v70._Mysize = 0;
    v70._Bx._Buf[0] = 0;
    std::wstring::assign(&v70, L"content/objects3D/pitcrew_Left_idle_dw.ksanim", 0x2Du);
    LOBYTE(v74) = 23;
  }
  else
  {
    std::wstring::assign(&v70, L"content/objects3D/pitcrew.kn5", 0x1Du);
    LOBYTE(v74) = 16;
    v14 = KN5IO::load((KN5IO *)v64, &v70);
    v15 = v70._Myres < 8;
    this->node = v14;
    LOBYTE(v74) = 6;
    if ( !v15 )
      operator delete(v70._Bx._Ptr);
    v70._Myres = 7;
    v70._Mysize = 0;
    v70._Bx._Buf[0] = 0;
    std::wstring::assign(&v70, L"content/objects3D/pitcrew.ksanim", 0x20u);
    LOBYTE(v74) = 17;
    Animation::load(&this->animation, &v70);
    LOBYTE(v74) = 6;
    if ( v70._Myres >= 8 )
      operator delete(v70._Bx._Ptr);
    v70._Myres = 7;
    v70._Mysize = 0;
    v70._Bx._Buf[0] = 0;
    std::wstring::assign(&v70, L"content/objects3D/pitcrew_idle_up.ksanim", 0x28u);
    LOBYTE(v74) = 18;
    Animation::load(&this->animationIdleUp, &v70);
    LOBYTE(v74) = 6;
    if ( v70._Myres >= 8 )
      operator delete(v70._Bx._Ptr);
    v70._Myres = 7;
    v70._Mysize = 0;
    v70._Bx._Buf[0] = 0;
    std::wstring::assign(&v70, L"content/objects3D/pitcrew_idle_dw.ksanim", 0x28u);
    LOBYTE(v74) = 19;
  }
  Animation::load(&this->animationIdleDw, &v70);
  LOBYTE(v74) = 6;
  if ( v70._Myres >= 8 )
    operator delete(v70._Bx._Ptr);
  GraphicsManager::compile(this->game->graphics, this->node);
  v17 = this->node;
  v18 = side;
  *(__m128i *)&v17->matrix.M11 = _mm_loadu_si128((const __m128i *)&matrix);
  *(__m128i *)&v17->matrix.M21 = _mm_loadu_si128((const __m128i *)&matrix.M21);
  *(__m128i *)&v17->matrix.M31 = _mm_loadu_si128((const __m128i *)&matrix.M31);
  *(__m128i *)&v17->matrix.M41 = _mm_loadu_si128((const __m128i *)&matrix.M41);
  v19 = this->node;
  v20 = (float)(matrix.M42 + (float)(COERCE_FLOAT(LODWORD(matrix.M32) ^ _xmm) * -4.0))
      + (float)((float)(matrix.M12 * v18) * 2.0);
  v21 = (float)(matrix.M43 + (float)(COERCE_FLOAT(LODWORD(matrix.M33) ^ _xmm) * -4.0))
      + (float)((float)(matrix.M13 * v18) * 2.0);
  v19->matrix.M41 = (float)(matrix.M41 + (float)(COERCE_FLOAT(LODWORD(matrix.M31) ^ _xmm) * -4.0))
                  + (float)((float)(matrix.M11 * v18) * 2.0);
  v19->matrix.M43 = v21;
  v19->matrix.M42 = v20;
  v22 = this->sim;
  *(_DWORD *)&v61[16] = 0;
  *(_DWORD *)&v61[20] = 0;
  v60 = 0;
  *(_OWORD *)v61 = 0i64;
  v61[24] = 0;
  *(_DWORD *)&v61[28] = 0;
  v23 = (int)&v22->track->physicsTrack;
  v68[0] = 0;
  v68[1] = -1082130432;
  v69 = 0;
  v55 = 1092616192;
  v54._Myres = (unsigned int)&v60;
  *(float *)&v70._Bx._Alias[12] = (float)(matrix.M41 + (float)(COERCE_FLOAT(LODWORD(matrix.M31) ^ _xmm) * -4.0))
                                + (float)((float)(matrix.M11 * v18) * 2.0);
  v54._Mysize = (unsigned int)v68;
  *(float *)&v70._Myres = (float)(matrix.M43 + (float)(COERCE_FLOAT(LODWORD(matrix.M33) ^ _xmm) * -4.0))
                        + (float)((float)(matrix.M13 * side) * 2.0);
  *(_DWORD *)&v54._Bx._Alias[12] = &v70._Bx._Alias[12];
  *(float *)&v70._Mysize = (float)((float)(matrix.M42 + (float)(COERCE_FLOAT(LODWORD(matrix.M32) ^ _xmm) * -4.0))
                                 + (float)((float)(matrix.M12 * v18) * 2.0))
                         + 1.0;
  (*(void (**)(int, char *, _DWORD *, int *, int))(*(_DWORD *)v23 + 4))(
    v23,
    &v70._Bx._Alias[12],
    v68,
    &v60,
    1092616192);
  if ( v61[24] )
  {
    v24 = this->node;
    v25 = *(float *)&v61[4];
    v26 = v24->matrix.M43;
    v24->matrix.M41 = v24->matrix.M41;
    v24->matrix.M42 = v25;
    v24->matrix.M43 = v26;
  }
  v27 = this->node;
  *(_DWORD *)&v61[36] = __libm_sse2_cosf(v73, v74).m128_u32[0];
  *(_DWORD *)&v61[40] = __libm_sse2_sinf(v28).m128_u32[0];
  *(float *)&v61[32] = 1.0 - *(float *)&v61[36];
  mat44f::mat44f(&v58);
  v29 = v27->matrix.M22;
  v30 = v27->matrix.M21;
  v31 = v27->matrix.M23;
  v58.M44 = 1.0;
  v58.M22 = (float)((float)(v29 * v29) * *(float *)&v61[32]) + *(float *)&v61[36];
  v58.M11 = (float)((float)(v30 * v30) * *(float *)&v61[32]) + *(float *)&v61[36];
  v58.M33 = (float)((float)(v31 * v31) * *(float *)&v61[32]) + *(float *)&v61[36];
  v32 = (float)(v30 * v29) * *(float *)&v61[32];
  v33 = (float)(*(float *)&v61[40] * v31) + v32;
  v34 = *(float *)&v61[40] * v29;
  v35 = v29 * v31;
  v58.M21 = v32 - (float)(*(float *)&v61[40] * v31);
  v36 = v30 * v31;
  v37 = *(_OWORD *)&v27->matrix.M41;
  v38 = v36 * *(float *)&v61[32];
  v58.M12 = v33;
  v39 = v35 * *(float *)&v61[32];
  v40 = v38 - v34;
  *(_OWORD *)&kn_100[48] = v37;
  v41 = *(_OWORD *)&v58.M41;
  v42 = v34 + v38;
  v43 = *(_OWORD *)&v27->matrix.M31;
  v58.M13 = v40;
  *(_OWORD *)&kn_100[32] = v43;
  v58.M31 = v42;
  v44 = *(_OWORD *)&v27->matrix.M21;
  v58.M23 = (float)(*(float *)&v61[40] * v30) + v39;
  v45 = *(_OWORD *)&v27->matrix.M11;
  v58.M32 = v39 - (float)(*(float *)&v61[40] * v30);
  v46 = *(_OWORD *)&v58.M31;
  *(_OWORD *)kn_100 = v45;
  *(_OWORD *)&kn_100[16] = v44;
  v47 = *(_OWORD *)&v58.M21;
  *(__m128 *)&v27->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)kn_100, *(__m128 *)&v58.M11);
  v72 = 28;
  *(_OWORD *)&v27->matrix.M21 = v47;
  *(_OWORD *)&v27->matrix.M31 = v46;
  *(_OWORD *)&v27->matrix.M41 = v41;
  v48 = (AnimationPlayer *)operator new(v72);
  *(_DWORD *)&v61[40] = v48;
  LOBYTE(v74) = 24;
  if ( v48 )
    AnimationPlayer::AnimationPlayer(v48, &this->animation, this->node, eOnlyAnimated);
  else
    v49 = 0;
  v72 = 28;
  LOBYTE(v74) = 6;
  this->player = v49;
  v50 = (AnimationPlayer *)operator new(v72);
  *(_DWORD *)&v61[40] = v50;
  LOBYTE(v74) = 25;
  if ( v50 )
    AnimationPlayer::AnimationPlayer(v50, &this->animationIdleUp, this->node, eOnlyAnimated);
  else
    v51 = 0;
  v72 = 28;
  LOBYTE(v74) = 6;
  this->playerIdleUp = v51;
  v52 = (AnimationPlayer *)operator new(v72);
  *(_DWORD *)&v61[40] = v52;
  LOBYTE(v74) = 26;
  if ( v52 )
    AnimationPlayer::AnimationPlayer(v52, &this->animationIdleDw, this->node, eOnlyAnimated);
  else
    v53 = 0;
  v72 = (int)this->node;
  LOBYTE(v74) = 6;
  this->playerIdleDw = v53;
  setMeshProperties((Node *)v72);
  if ( *(_DWORD *)&crewskin._Bx._Alias[8] >= 8u )
    operator delete(v66[0]);
  *(_QWORD *)&crewskin._Bx._Alias[4] = 0x700000000i64;
  LOWORD(v66[0]) = 0;
  LOBYTE(v74) = 4;
  KN5IO::~KN5IO((KN5IO *)v64);
  if ( skin._Myres >= 8 )
    operator delete(skin._Bx._Ptr);
}
LollipopCrew *LollipopCrew::`scalar deleting destructor'(LollipopCrew *this, unsigned int a2)
{
  this->__vftable = (LollipopCrew_vtbl *)&LollipopCrew::`vftable';
  std::vector<AnimationSet>::_Tidy(&this->animationIdleDw);
  std::vector<AnimationSet>::_Tidy(&this->animationIdleUp);
  std::vector<AnimationSet>::_Tidy(&this->animation);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void LollipopCrew::loadCrewSkin(LollipopCrew *this, KN5IO *kn, INIReader *iniS, const std::wstring *section, const std::wstring *key)
{
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // esi
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  KN5IO_vtbl *v10; // eax
  int v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  KN5IO_vtbl *v14; // eax
  std::wstring iniSkin; // [esp+14h] [ebp-70h] BYREF
  std::wstring v16; // [esp+2Ch] [ebp-58h] BYREF
  std::wstring nm; // [esp+44h] [ebp-40h] BYREF
  std::wstring result; // [esp+5Ch] [ebp-28h] BYREF
  int v19; // [esp+80h] [ebp-4h]

  iniSkin._Myres = 7;
  iniSkin._Mysize = 0;
  iniSkin._Bx._Buf[0] = 0;
  v19 = 0;
  if ( INIReader::hasKey(iniS, section, key) )
  {
    v5 = INIReader::getString(iniS, &result, section, key);
    LOBYTE(v19) = 1;
    v6 = std::operator+<wchar_t>(&v16, L"content/texture/crew_", key);
    LOBYTE(v19) = 2;
    v7 = std::operator+<wchar_t>(&nm, v6, v5);
    if ( &iniSkin != v7 )
    {
      iniSkin._Myres = 7;
      iniSkin._Mysize = 0;
      iniSkin._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&iniSkin, v7);
    }
    if ( nm._Myres >= 8 )
      operator delete(nm._Bx._Ptr);
    nm._Myres = 7;
    nm._Mysize = 0;
    nm._Bx._Buf[0] = 0;
    if ( v16._Myres >= 8 )
      operator delete(v16._Bx._Ptr);
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    LOBYTE(v19) = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v8 = &iniSkin;
    if ( iniSkin._Myres >= 8 )
      v8 = (std::wstring *)iniSkin._Bx._Ptr;
    _printf("searching %ls \n", v8->_Bx._Buf);
    if ( Path::folderExists(&iniSkin) )
    {
      v9 = &iniSkin;
      if ( iniSkin._Myres >= 8 )
        v9 = (std::wstring *)iniSkin._Bx._Ptr;
      std::wstring::wstring(&v16, v9->_Bx._Buf);
      v10 = kn->__vftable;
      LOBYTE(v19) = 3;
      v10->addTextureFolder(kn, &v16);
      LOBYTE(v19) = 0;
      if ( v16._Myres >= 8 )
        operator delete(v16._Bx._Ptr);
    }
    v11 = std::wstring::find_last_of(&iniSkin, L"\\", 0xFFFFFFFF, 1u);
    if ( v11 >= 0 )
    {
      v12 = std::wstring::substr(&iniSkin, &v16, 0, v11 + 1);
      LOBYTE(v19) = 4;
      std::operator+<wchar_t>(&nm, v12, L"_nm");
      LOBYTE(v19) = 6;
      if ( v16._Myres >= 8 )
        operator delete(v16._Bx._Ptr);
      v16._Myres = 7;
      v16._Bx._Buf[0] = 0;
      v16._Mysize = 0;
      if ( Path::folderExists(&nm) )
      {
        v13 = &nm;
        if ( nm._Myres >= 8 )
          v13 = (std::wstring *)nm._Bx._Ptr;
        std::wstring::wstring(&result, v13->_Bx._Buf);
        v14 = kn->__vftable;
        LOBYTE(v19) = 7;
        v14->addTextureFolder(kn, &result);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
      if ( nm._Myres >= 8 )
        operator delete(nm._Bx._Ptr);
    }
  }
  if ( iniSkin._Myres >= 8 )
    operator delete(iniSkin._Bx._Ptr);
}
void LollipopCrew::update(LollipopCrew *this, float dt)
{
  PitStop *v3; // eax
  int v4; // eax

  if ( CarAvatar::getGuid(this->car) )
  {
    if ( !CarAvatar::isInPit(this->car) )
    {
      this->targetLolliPosition = 0.0;
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  v3 = this->sim->pitStop;
  if ( !v3 )
    goto LABEL_9;
  v4 = v3->state - 1;
  if ( !v4 )
  {
LABEL_8:
    this->targetLolliPosition = 1.0;
    goto LABEL_9;
  }
  if ( v4 == 3 )
    this->targetLolliPosition = 0.0;
LABEL_9:
  LollipopCrew::updateCurrentPosition(this, dt);
}
void LollipopCrew::updateCurrentPosition(LollipopCrew *this, float dt)
{
  double v3; // st7
  float v4; // xmm0_4
  bool v5; // cc
  float v6; // xmm0_4
  float p; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float cp; // [esp+Ch] [ebp-4h]
  float currentPos; // [esp+14h] [ebp+4h]
  float currentPosa; // [esp+14h] [ebp+4h]

  v3 = AnimationPlayer::getCurrentPos(this->player);
  v4 = this->targetLolliPosition;
  cp = v3;
  if ( cp == v4 )
  {
    if ( cp == 0.0 )
    {
      currentPos = AnimationPlayer::getCurrentPos(this->playerIdleUp) + (float)(dt * 0.083333336);
      v9 = currentPos;
      if ( currentPos > 1.0 )
        v9 = currentPos - 1.0;
      AnimationPlayer::setCurrentPos(this->playerIdleUp, v9, 0.0);
    }
    else
    {
      currentPosa = AnimationPlayer::getCurrentPos(this->playerIdleDw) + (float)(dt * 0.083333336);
      v10 = currentPosa;
      if ( currentPosa > 1.0 )
        v10 = currentPosa - 1.0;
      AnimationPlayer::setCurrentPos(this->playerIdleDw, v10, 0.0);
    }
  }
  else
  {
    v5 = cp <= v4;
    v6 = this->animationSpeed * dt;
    if ( v5 )
      p = v6 + cp;
    else
      p = cp - v6;
    v8 = FLOAT_1_0;
    if ( p > 1.0 || (v8 = 0.0, p < 0.0) )
      p = v8;
    AnimationPlayer::setCurrentPos(this->player, p, 0.0);
  }
}
