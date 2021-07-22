#include "formchat.h
void FormChat::FormChat(FormChat *this, Sim *a_sim)
{
  unsigned int v3; // ebx
  Game *v4; // eax
  const std::wstring *v5; // eax
  Texture *v6; // eax
  Texture *v7; // eax
  Texture *v8; // eax
  Texture *v9; // eax
  int v10; // eax
  bool v11; // cf
  int v12; // eax
  int v13; // eax
  int v14; // eax
  double v15; // st7
  double v16; // st7
  unsigned __int16 v17; // ax
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  char v24; // al
  int v25; // eax
  char v26; // al
  int v27; // eax
  char v28; // al
  int v29; // eax
  char v30; // al
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  int i; // esi
  std::wstring *v36; // eax
  const std::wstring *v37; // eax
  std::wstring *v38; // eax
  const std::wstring *v39; // eax
  vec4f *v40; // eax
  __m128 v41; // xmm1
  float v42; // xmm0_4
  std::wstring *v43; // eax
  const std::wstring *v44; // eax
  vec4f *v45; // eax
  __m128 v46; // xmm1
  float v47; // xmm0_4
  float v48; // xmm1_4
  int v49; // eax
  float v50; // xmm0_4
  float v51; // xmm2_4
  void *(__cdecl *v52)(unsigned int); // esi
  ksgui::TextInput *v53; // ecx
  Font *v54; // eax
  ksgui::TextInput *v55; // eax
  ksgui::TextInput *v56; // ecx
  ksgui::TextInput_vtbl *v57; // eax
  ksgui::TextInput *v58; // esi
  std::wstring *v59; // eax
  int v60; // eax
  int v61; // esi
  CarAudioFMOD *v62; // eax
  Font *v63; // eax
  float v64; // edx
  float v65; // ecx
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm3_4
  float v69; // xmm2_4
  float v70; // xmm1_4
  CarAudioFMOD *v71; // esi
  std::wstring *v72; // eax
  int v73; // eax
  int v74; // esi
  int v75; // eax
  CarAudioFMOD *v76; // ebp
  ksgui::Control *v77; // eax
  const __m128i *v78; // eax
  vec4f v79; // xmm0
  FormChat::{ctor}::__l57::<lambda_04a2bbc2861b8b8492d5e5219f8f4385> *v80; // eax
  CarAudioFMOD *v81; // ebp
  ksgui::Control *v82; // eax
  const __m128i *v83; // eax
  vec4f v84; // xmm0
  float v85; // xmm1_4
  ksgui::Form *v86; // ecx
  FormChat::{ctor}::__l64::<lambda_d4908416bfa4be314f93e93faf6f967a> *v87; // eax
  CarAudioFMOD *v88; // ebp
  ksgui::Control *v89; // eax
  ksgui::Control *v90; // ecx
  ksgui::Control_vtbl *v91; // eax
  vec4f v92; // xmm0
  FormChat::{ctor}::__l71::<lambda_ff60238332d6a9f2579c0df9bd5040fd> *v93; // eax
  CarAudioFMOD *v94; // ebp
  ksgui::Control *v95; // eax
  int v96; // ebp
  ksgui::Control *v97; // ecx
  ksgui::Control_vtbl *v98; // eax
  FormChat::{ctor}::__l78::<lambda_aabb522cbe43a8980a2302a4304c68a2> *v99; // eax
  CarAudioFMOD *v100; // ebp
  ksgui::Control *v101; // eax
  const __m128i *v102; // eax
  FormChat::{ctor}::__l85::<lambda_7f2f50642fef201cc04c11fe81596d84> *v103; // eax
  CarAudioFMOD *v104; // esi
  ksgui::Control *v105; // eax
  const __m128i *v106; // eax
  FormChat::{ctor}::__l89::<lambda_257572317b4ec1c7908db41256e6869c> *v107; // eax
  float v108; // xmm0_4
  const __m128i *v109; // eax
  FormChat::{ctor}::__l90::<lambda_123893be2edc41f33e4058fb9db243ad> *v110; // eax
  _BYTE v111[28]; // [esp+78h] [ebp-160h] BYREF
  unsigned int left_4; // [esp+94h] [ebp-144h]
  float v113; // [esp+98h] [ebp-140h]
  float v114; // [esp+9Ch] [ebp-13Ch]
  int v115; // [esp+B8h] [ebp-120h] BYREF
  ksgui::Label *lbl; // [esp+BCh] [ebp-11Ch] BYREF
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v117; // [esp+C0h] [ebp-118h] BYREF
  ksgui::TextInput *v118[2]; // [esp+C4h] [ebp-114h] BYREF
  __int64 left; // [esp+CCh] [ebp-10Ch]
  vec4f v; // [esp+D4h] [ebp-104h] BYREF
  FormChat::ChatIntensities p; // [esp+E4h] [ebp-F4h] BYREF
  vec4f v122; // [esp+F4h] [ebp-E4h] BYREF
  FormChat *v123; // [esp+104h] [ebp-D4h]
  std::wstring key; // [esp+108h] [ebp-D0h] BYREF
  Texture result; // [esp+120h] [ebp-B8h] BYREF
  std::wstring text; // [esp+13Ch] [ebp-9Ch] BYREF
  std::wstring sect; // [esp+154h] [ebp-84h] BYREF
  std::wstring v128; // [esp+16Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+184h] [ebp-54h] BYREF
  int v130; // [esp+1D4h] [ebp-4h]

  v3 = 0;
  lbl = 0;
  left_4 = 1;
  v123 = this;
  v4 = a_sim->game;
  LODWORD(left) = 0;
  *(_DWORD *)&v111[24] = v4->gui;
  *(_DWORD *)&v111[20] = 7;
  *(_DWORD *)&v111[16] = 0;
  *(_WORD *)v111 = 0;
  std::wstring::assign((std::wstring *)v111, L"CHAT_APP", 8u);
  ksgui::Form::Form(this, 0, *(std::wstring *)v111, *(ksgui::GUI **)&v111[24], left_4);
  v130 = 0;
  this->__vftable = (FormChat_vtbl *)&FormChat::`vftable';
  this->messages._Myfirst = 0;
  this->messages._Mylast = 0;
  this->messages._Myend = 0;
  this->newMessages._Myfirst = 0;
  this->newMessages._Mylast = 0;
  this->newMessages._Myend = 0;
  this->shownMessages._Myfirst = 0;
  this->shownMessages._Mylast = 0;
  this->shownMessages._Myend = 0;
  this->times._Myfirst = 0;
  this->times._Mylast = 0;
  this->times._Myend = 0;
  this->rows._Myfirst = 0;
  this->rows._Mylast = 0;
  this->rows._Myend = 0;
  this->foreColors._Myfirst = 0;
  this->foreColors._Mylast = 0;
  this->foreColors._Myend = 0;
  this->backColors._Myfirst = 0;
  this->backColors._Mylast = 0;
  this->backColors._Myend = 0;
  this->serverForeColor.x = 0.0;
  this->serverForeColor.y = 0.0;
  this->serverForeColor.z = 0.0;
  this->serverForeColor.w = 0.0;
  this->serverBackColor.x = 0.0;
  this->serverBackColor.y = 0.0;
  this->serverBackColor.z = 0.0;
  this->serverBackColor.w = 0.0;
  this->playerForeColor.x = 0.0;
  this->playerForeColor.y = 0.0;
  this->playerForeColor.z = 0.0;
  this->playerForeColor.w = 0.0;
  this->playerBackColor.x = 0.0;
  this->playerBackColor.y = 0.0;
  this->playerBackColor.z = 0.0;
  this->playerBackColor.w = 0.0;
  *(_DWORD *)&this->mustUpdate = &unk_1000001;
  this->messageAlert = 0;
  this->topRow = -1;
  this->maxWidth = -1;
  this->lastMsgID = -1;
  this->addedLines = 0;
  *(_DWORD *)&this->debug = 256;
  this->FADE_MULT = 10.0;
  this->PREFADE_MULT = 10.0;
  *(_DWORD *)&this->EXPORT_ON_CLOSE = 655616;
  this->BG_INTENSITY_MAIN = 0.2;
  this->FONT_SIZE = 12.0;
  this->PIX_PER_CHAR = 7.0;
  this->TIME_ROW_W = 70.0;
  this->SINGLE_ROW_H = 17.0;
  this->SINGLE_ROW_W = 300.0;
  this->FWIDTH = 0.0;
  this->FHEIGHT = 0.0;
  this->currentTimeToLose = 0.0;
  this->TIME_TO_LOSE_FOCUS = 5.0;
  this->SCROLL_COLOR.x = 1.0;
  this->SCROLL_COLOR.y = 1.0;
  this->SCROLL_COLOR.z = 1.0;
  this->SCROLL_COLOR.w = 1.0;
  this->scrollTopTex.kid = 0;
  this->scrollTopTex.fileName._Myres = 7;
  this->scrollTopTex.fileName._Mysize = 0;
  this->scrollTopTex.fileName._Bx._Buf[0] = 0;
  this->scrollUpTex.kid = 0;
  this->scrollUpTex.fileName._Myres = 7;
  this->scrollUpTex.fileName._Mysize = 0;
  this->scrollUpTex.fileName._Bx._Buf[0] = 0;
  this->scrollDownTex.kid = 0;
  this->scrollDownTex.fileName._Myres = 7;
  this->scrollDownTex.fileName._Mysize = 0;
  this->scrollDownTex.fileName._Bx._Buf[0] = 0;
  this->scrollBottomTex.kid = 0;
  this->scrollBottomTex.fileName._Myres = 7;
  this->scrollBottomTex.fileName._Mysize = 0;
  this->scrollBottomTex.fileName._Bx._Buf[0] = 0;
  LOBYTE(v130) = 11;
  left_4 = 4;
  text._Mysize = 0;
  *(_DWORD *)&v111[24] = L"Chat";
  *(_WORD *)&this->devApp = 256;
  this->sim = a_sim;
  text._Myres = 7;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v111[24], left_4);
  LOBYTE(v130) = 12;
  v5 = acTranslate(&sect, &text);
  LOBYTE(v130) = 13;
  this->formTitle->setText(this->formTitle, v5);
  if ( sect._Myres >= 8 )
    operator delete(sect._Bx._Ptr);
  LOBYTE(v130) = 11;
  sect._Myres = 7;
  sect._Mysize = 0;
  sect._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/chatapp/scrollbarArrowTop.png", 0x29u);
  LOBYTE(v130) = 14;
  v6 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v130) = 15;
  this->scrollTopTex.kid = v6->kid;
  if ( &this->scrollTopTex.fileName != &v6->fileName )
    std::wstring::assign(&this->scrollTopTex.fileName, &v6->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v130) = 14;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v130) = 11;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/chatapp/scrollbarArrowUp.png", 0x28u);
  LOBYTE(v130) = 16;
  v7 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v130) = 17;
  this->scrollUpTex.kid = v7->kid;
  if ( &this->scrollUpTex.fileName != &v7->fileName )
    std::wstring::assign(&this->scrollUpTex.fileName, &v7->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v130) = 16;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v130) = 11;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/chatapp/scrollbarArrowDown.png", 0x2Au);
  LOBYTE(v130) = 18;
  v8 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v130) = 19;
  this->scrollDownTex.kid = v8->kid;
  if ( &this->scrollDownTex.fileName != &v8->fileName )
    std::wstring::assign(&this->scrollDownTex.fileName, &v8->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v130) = 18;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v130) = 11;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"content/gui/chatapp/scrollbarArrowBottom.png", 0x2Cu);
  LOBYTE(v130) = 20;
  v9 = ResourceStore::getTexture(this->gui->graphics->resourceStore._Myptr, &result, &text, 0);
  LOBYTE(v130) = 21;
  this->scrollBottomTex.kid = v9->kid;
  if ( &this->scrollBottomTex.fileName != &v9->fileName )
    std::wstring::assign(&this->scrollBottomTex.fileName, &v9->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v130) = 20;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v130) = 11;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  if ( this->sim->client )
  {
    *(_DWORD *)&v111[4] = &std::_Func_impl<std::_Callable_obj<_lambda_2d2948c64793069cb0b60de14497838f_,0>,std::allocator<std::_Func_class<void,OnChatMessageEvent const &>>,void,OnChatMessageEvent const &>::`vftable';
    *(_DWORD *)&v111[8] = this;
    *(_DWORD *)&v111[20] = &v111[4];
    LOBYTE(v130) = 11;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->sim->client->evOnChatMessage,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v111[4],
      this);
  }
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"system/cfg/chat_app.ini", 0x17u);
  LOBYTE(v130) = 23;
  INIReader::INIReader(&ini, &text);
  LOBYTE(v130) = 25;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    sect._Myres = 7;
    sect._Mysize = 0;
    sect._Bx._Buf[0] = 0;
    std::wstring::assign(&sect, L"OPTIONS", 7u);
    LOBYTE(v130) = 26;
    std::wstring::wstring(&key, L"DEBUG");
    LOBYTE(v130) = 27;
    v10 = INIReader::getInt(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->debug = v10 != 0;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SHOW_TIME");
    LOBYTE(v130) = 28;
    v12 = INIReader::getInt(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->showTimestamp = v12 != 0;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"EXPORT_ON_CLOSE");
    LOBYTE(v130) = 29;
    v13 = INIReader::getInt(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->EXPORT_ON_CLOSE = v13 != 0;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"OVERWRITE_EXPORT");
    LOBYTE(v130) = 30;
    v14 = INIReader::getInt(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->OVERWRITE_EXPORT = v14 != 0;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"PREFADE_MULT");
    LOBYTE(v130) = 31;
    v15 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->PREFADE_MULT = v15;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    if ( this->PREFADE_MULT == 0.0 )
      this->PREFADE_MULT = 10.0;
    std::wstring::wstring(&key, L"FADE_MULT");
    LOBYTE(v130) = 32;
    v16 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->FADE_MULT = v16;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    if ( this->FADE_MULT == 0.0 )
      this->FADE_MULT = 10.0;
    std::wstring::wstring(&key, L"ROW_COUNT");
    LOBYTE(v130) = 33;
    v17 = INIReader::getInt(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->ROW_COUNT = v17;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"BG_INTENSITY_MAIN");
    LOBYTE(v130) = 34;
    v18 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->BG_INTENSITY_MAIN = v18;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"FONT_SIZE");
    LOBYTE(v130) = 35;
    v19 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->FONT_SIZE = v19;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"PIX_PER_CHAR");
    LOBYTE(v130) = 36;
    v20 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->PIX_PER_CHAR = v20;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"TIME_ROW_W");
    LOBYTE(v130) = 37;
    v21 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->TIME_ROW_W = v21;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SINGLE_ROW_H");
    LOBYTE(v130) = 38;
    v22 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->SINGLE_ROW_H = v22;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SINGLE_ROW_W");
    LOBYTE(v130) = 39;
    v23 = INIReader::getFloat(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    v11 = key._Myres < 8;
    this->SINGLE_ROW_W = v23;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"BOLD");
    LOBYTE(v130) = 40;
    v24 = INIReader::hasKey(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    HIBYTE(v115) = v24;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v24 = HIBYTE(v115);
    }
    if ( v24 )
    {
      std::wstring::wstring(&key, L"BOLD");
      LOBYTE(v130) = 41;
      v25 = INIReader::getInt(&ini, &sect, &key);
      LOBYTE(v130) = 26;
      v11 = key._Myres < 8;
      this->fontIsBold = v25 != 0;
      if ( !v11 )
        operator delete(key._Bx._Ptr);
    }
    std::wstring::wstring(&key, L"ITALIC");
    LOBYTE(v130) = 42;
    v26 = INIReader::hasKey(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    HIBYTE(v115) = v26;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v26 = HIBYTE(v115);
    }
    if ( v26 )
    {
      std::wstring::wstring(&key, L"ITALIC");
      LOBYTE(v130) = 43;
      v27 = INIReader::getInt(&ini, &sect, &key);
      LOBYTE(v130) = 26;
      v11 = key._Myres < 8;
      this->fontIsItalic = v27 != 0;
      if ( !v11 )
        operator delete(key._Bx._Ptr);
    }
    std::wstring::wstring(&key, L"TIME_TO_LOSE_FOCUS");
    LOBYTE(v130) = 44;
    v28 = INIReader::hasKey(&ini, &sect, &key);
    LOBYTE(v130) = 26;
    HIBYTE(v115) = v28;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v28 = HIBYTE(v115);
    }
    if ( v28 )
    {
      std::wstring::wstring((std::wstring *)&result, L"TIME_TO_LOSE_FOCUS");
      LOBYTE(v130) = 45;
      v29 = INIReader::getInt(&ini, &sect, (const std::wstring *)&result);
      LOBYTE(v130) = 26;
      this->TIME_TO_LOSE_FOCUS = (float)v29;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    }
    std::wstring::wstring(&key, L"COLORS");
    LOBYTE(v130) = 46;
    v30 = INIReader::hasSection(&ini, &key);
    LOBYTE(v130) = 26;
    HIBYTE(v115) = v30;
    if ( key._Myres >= 8 )
    {
      operator delete(key._Bx._Ptr);
      v30 = HIBYTE(v115);
    }
    if ( v30 )
    {
      std::wstring::wstring(&key, L"SERVER_FORECOLOR");
      LOBYTE(v130) = 47;
      std::wstring::wstring((std::wstring *)&result, L"COLORS");
      LOBYTE(v130) = 48;
      v31 = (__m128)_mm_loadu_si128((const __m128i *)INIReader::getFloat4(
                                                       &ini,
                                                       (vec4f *)&p,
                                                       (const std::wstring *)&result,
                                                       &key));
      this->serverForeColor.x = v31.m128_f32[0] * 0.0039215689;
      this->serverForeColor.y = _mm_shuffle_ps(v31, v31, 85).m128_f32[0] * 0.0039215689;
      this->serverForeColor.z = _mm_shuffle_ps(v31, v31, 170).m128_f32[0] * 0.0039215689;
      this->serverForeColor.w = _mm_shuffle_ps(v31, v31, 255).m128_f32[0] * 0.0039215689;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      LOBYTE(v130) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&key, L"SERVER_BACKCOLOR");
      LOBYTE(v130) = 49;
      std::wstring::wstring((std::wstring *)&result, L"COLORS");
      LOBYTE(v130) = 50;
      v32 = (__m128)_mm_loadu_si128((const __m128i *)INIReader::getFloat4(
                                                       &ini,
                                                       (vec4f *)&p,
                                                       (const std::wstring *)&result,
                                                       &key));
      this->serverBackColor.x = v32.m128_f32[0] * 0.0039215689;
      this->serverBackColor.y = _mm_shuffle_ps(v32, v32, 85).m128_f32[0] * 0.0039215689;
      this->serverBackColor.z = _mm_shuffle_ps(v32, v32, 170).m128_f32[0] * 0.0039215689;
      this->serverBackColor.w = _mm_shuffle_ps(v32, v32, 255).m128_f32[0] * 0.0039215689;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      LOBYTE(v130) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&key, L"PLAYER_FORECOLOR");
      LOBYTE(v130) = 51;
      std::wstring::wstring((std::wstring *)&result, L"COLORS");
      LOBYTE(v130) = 52;
      v33 = (__m128)_mm_loadu_si128((const __m128i *)INIReader::getFloat4(
                                                       &ini,
                                                       (vec4f *)&p,
                                                       (const std::wstring *)&result,
                                                       &key));
      this->playerForeColor.x = v33.m128_f32[0] * 0.0039215689;
      this->playerForeColor.y = _mm_shuffle_ps(v33, v33, 85).m128_f32[0] * 0.0039215689;
      this->playerForeColor.z = _mm_shuffle_ps(v33, v33, 170).m128_f32[0] * 0.0039215689;
      this->playerForeColor.w = _mm_shuffle_ps(v33, v33, 255).m128_f32[0] * 0.0039215689;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      LOBYTE(v130) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::wstring(&key, L"PLAYER_BACKCOLOR");
      LOBYTE(v130) = 53;
      std::wstring::wstring((std::wstring *)&result, L"COLORS");
      LOBYTE(v130) = 54;
      v34 = (__m128)_mm_loadu_si128((const __m128i *)INIReader::getFloat4(
                                                       &ini,
                                                       (vec4f *)&p,
                                                       (const std::wstring *)&result,
                                                       &key));
      this->playerBackColor.x = v34.m128_f32[0] * 0.0039215689;
      this->playerBackColor.y = _mm_shuffle_ps(v34, v34, 85).m128_f32[0] * 0.0039215689;
      this->playerBackColor.z = _mm_shuffle_ps(v34, v34, 170).m128_f32[0] * 0.0039215689;
      this->playerBackColor.w = _mm_shuffle_ps(v34, v34, 255).m128_f32[0] * 0.0039215689;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      LOBYTE(v130) = 26;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      for ( i = 0; ; ++i )
      {
        std::wstring::wstring((std::wstring *)&result, L"COLORS");
        LOBYTE(v130) = 55;
        v36 = std::to_wstring(&key, i);
        LOBYTE(v130) = 56;
        v37 = std::operator+<wchar_t>(&v128, L"FORECOLOR_", v36);
        LOBYTE(v130) = 57;
        HIBYTE(v115) = INIReader::hasKey(&ini, (const std::wstring *)&result, v37);
        if ( v128._Myres >= 8 )
          operator delete(v128._Bx._Ptr);
        v128._Myres = 7;
        v128._Mysize = 0;
        v128._Bx._Buf[0] = 0;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        LOBYTE(v130) = 26;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( result.fileName._Mysize >= 8 )
          operator delete(result.kid);
        if ( !HIBYTE(v115) )
          break;
        std::wstring::wstring((std::wstring *)&result, L"COLORS");
        LOBYTE(v130) = 58;
        v38 = std::to_wstring(&v128, i);
        LOBYTE(v130) = 59;
        v39 = std::operator+<wchar_t>(&key, L"FORECOLOR_", v38);
        LOBYTE(v130) = 60;
        v40 = INIReader::getFloat4(&ini, (vec4f *)&p, (const std::wstring *)&result, v39);
        v41 = (__m128)_mm_loadu_si128((const __m128i *)v40);
        v.x = v41.m128_f32[0] * 0.0039215689;
        v.y = _mm_shuffle_ps(v41, v41, 85).m128_f32[0] * 0.0039215689;
        v42 = _mm_shuffle_ps(v41, v41, 170).m128_f32[0];
        v41.m128_f32[0] = v40->w * 0.0039215689;
        v.z = v42 * 0.0039215689;
        LODWORD(v.w) = v41.m128_i32[0];
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( v128._Myres >= 8 )
          operator delete(v128._Bx._Ptr);
        LOBYTE(v130) = 26;
        v128._Myres = 7;
        v128._Mysize = 0;
        v128._Bx._Buf[0] = 0;
        if ( result.fileName._Mysize >= 8 )
          operator delete(result.kid);
        std::vector<vec4f>::push_back(&this->foreColors, &v);
        std::wstring::wstring((std::wstring *)&result, L"COLORS");
        LOBYTE(v130) = 61;
        v43 = std::to_wstring(&v128, i);
        LOBYTE(v130) = 62;
        v44 = std::operator+<wchar_t>(&key, L"BACKCOLOR_", v43);
        LOBYTE(v130) = 63;
        v45 = INIReader::getFloat4(&ini, &v122, (const std::wstring *)&result, v44);
        v46 = (__m128)_mm_loadu_si128((const __m128i *)v45);
        v.x = v46.m128_f32[0] * 0.0039215689;
        v.y = _mm_shuffle_ps(v46, v46, 85).m128_f32[0] * 0.0039215689;
        v47 = _mm_shuffle_ps(v46, v46, 170).m128_f32[0];
        v46.m128_f32[0] = v45->w * 0.0039215689;
        v.z = v47 * 0.0039215689;
        LODWORD(v.w) = v46.m128_i32[0];
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( v128._Myres >= 8 )
          operator delete(v128._Bx._Ptr);
        LOBYTE(v130) = 26;
        v128._Myres = 7;
        v128._Mysize = 0;
        v128._Bx._Buf[0] = 0;
        if ( result.fileName._Mysize >= 8 )
          operator delete(result.kid);
        std::vector<vec4f>::push_back(&this->backColors, &v);
      }
      v3 = left;
    }
    LOBYTE(v130) = 25;
    if ( sect._Myres >= 8 )
      operator delete(sect._Bx._Ptr);
  }
  if ( !this->showTimestamp )
    this->TIME_ROW_W = 0.0;
  v48 = this->SINGLE_ROW_H;
  v49 = this->ROW_COUNT;
  LODWORD(left) = 0;
  v50 = this->SINGLE_ROW_W + this->TIME_ROW_W;
  v51 = this->HEADER_HEIGHT;
  v52 = operator new;
  left_4 = 24;
  *((float *)&left + 1) = v51;
  this->FWIDTH = v50 + v48;
  this->FHEIGHT = (float)((float)((float)v49 * v48) + v51) + v48;
  v53 = (ksgui::TextInput *)operator new(left_4);
  v118[0] = v53;
  LOBYTE(v130) = 64;
  if ( v53 )
    Font::Font((Font *)v53, eFontMonospaced, this->FONT_SIZE, this->fontIsItalic, this->fontIsBold);
  else
    v54 = 0;
  LOBYTE(v130) = 25;
  v.x = 0.0;
  v.y = 0.0;
  std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&v, v54);
  LOBYTE(v130) = 65;
  v118[0] = (ksgui::TextInput *)operator new(0x158u);
  LOBYTE(v130) = 66;
  if ( v118[0] )
  {
    left_4 = (unsigned int)this->gui;
    std::wstring::wstring((std::wstring *)&v111[4], L"CHAT_TEXT_INPUT");
    ksgui::TextInput::TextInput(v118[0], *(std::wstring *)&v111[4], (ksgui::GUI *)left_4);
    v56 = v55;
  }
  else
  {
    v56 = 0;
  }
  LOBYTE(v130) = 65;
  this->textInput = v56;
  if ( !v56->visible )
  {
    v57 = v56->__vftable;
    left_4 = 1;
    v56->visible = 1;
    ((void (__stdcall *)(unsigned int))v57->onVisibleChanged)(left_4);
  }
  this->textInput->backColor = (vec4f)_xmm;
  this->textInput->borderColor = (vec4f)_xmm;
  this->textInput->backColorUnfocus = (vec4f)_xmm;
  this->textInput->backColorFocus = (vec4f)_xmm;
  ksgui::Form::setPosition((ksgui::Form *)this->textInput, 0.0, this->FHEIGHT - this->SINGLE_ROW_H);
  ((void (*)(ksgui::TextInput *, _DWORD, _DWORD))this->textInput->setSize)(
    this->textInput,
    (float)(this->SINGLE_ROW_W + this->TIME_ROW_W) + this->SINGLE_ROW_H,
    LODWORD(this->SINGLE_ROW_H));
  std::shared_ptr<Font>::operator=(&this->textInput->font, (const std::shared_ptr<Font> *)&v);
  v118[0] = this->textInput;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)v118);
  left_4 = (unsigned int)this;
  v118[0]->parent = this;
  *(_DWORD *)&v111[4] = &std::_Func_impl<std::_Callable_obj<_lambda_038f9df3d2b0ed188288ed90b7ba8620_,0>,std::allocator<std::_Func_class<void,std::wstring const &>>,void,std::wstring const &>::`vftable';
  *(_DWORD *)&v111[8] = this;
  *(_DWORD *)&v111[20] = &v111[4];
  LOBYTE(v130) = 65;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->textInput->evKeyDown,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v111[4],
    (void *)left_4);
  *(_DWORD *)&v111[4] = &std::_Func_impl<std::_Callable_obj<_lambda_70b7a39c9dcc54dfd55ecf8a7d1bd48d_,0>,std::allocator<std::_Func_class<void,std::wstring const &>>,void,std::wstring const &>::`vftable';
  *(_DWORD *)&v111[8] = this;
  *(_DWORD *)&v111[20] = &v111[4];
  LOBYTE(v130) = 65;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->textInput->evValidate,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v111[4],
    this);
  v118[0] = 0;
  if ( this->ROW_COUNT )
  {
    do
    {
      v58 = (ksgui::TextInput *)v52(0x11Cu);
      v118[1] = v58;
      LOBYTE(v130) = 69;
      if ( v58 )
      {
        left_4 = (unsigned int)this->gui;
        v59 = std::to_wstring((std::wstring *)&result, (int)v118[0]);
        LOBYTE(v130) = 70;
        v3 |= 1u;
        lbl = (ksgui::Label *)v3;
        std::operator+<wchar_t>((std::wstring *)&v111[4], L"chat_time_t", v59);
        ksgui::Label::Label((ksgui::Label *)v58, *(std::wstring *)&v111[4], (ksgui::GUI *)left_4);
        v61 = v60;
      }
      else
      {
        v61 = 0;
      }
      lbl = (ksgui::Label *)v61;
      v130 = 65;
      if ( (v3 & 1) != 0 )
      {
        v3 &= 0xFFFFFFFE;
        if ( result.fileName._Mysize >= 8 )
          operator delete(result.kid);
      }
      v62 = (CarAudioFMOD *)operator new(0x18u);
      v117.__this = v62;
      LOBYTE(v130) = 72;
      if ( v62 )
        Font::Font((Font *)v62, eFontMonospaced, this->FONT_SIZE, 0, 0);
      else
        v63 = 0;
      LOBYTE(v130) = 65;
      v122.x = 0.0;
      v122.y = 0.0;
      std::shared_ptr<Font>::_Resetp<Font>((std::shared_ptr<Font> *)&v122, v63);
      std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)(v61 + 128), (std::shared_ptr<Font> *)&v122);
      v64 = v122.y;
      if ( LODWORD(v122.y) )
      {
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v122.y) + 4), 0xFFFFFFFF) )
        {
          (**(void (***)(float))LODWORD(v64))(COERCE_FLOAT(LODWORD(v64)));
          v65 = v122.y;
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v122.y) + 8), 0xFFFFFFFF) )
            (*(void (**)(float))(*(_DWORD *)LODWORD(v65) + 4))(COERCE_FLOAT(LODWORD(v65)));
        }
      }
      *(_DWORD *)(v61 + 152) = 2;
      *(_OWORD *)(v61 + 76) = _xmm;
      (*(void (**)(int, _DWORD, _DWORD))(*(_DWORD *)v61 + 28))(
        v61,
        LODWORD(this->TIME_ROW_W),
        LODWORD(this->SINGLE_ROW_H));
      v66 = *(float *)(v61 + 264);
      v67 = *(float *)(v61 + 40) - *(float *)(v61 + 36);
      v68 = *((float *)&left + 1);
      v69 = *(float *)(v61 + 32) - *(float *)(v61 + 28);
      *(_DWORD *)(v61 + 28) = 0;
      v70 = v67 + v68;
      *(float *)(v61 + 36) = v68;
      *(float *)(v61 + 32) = v69;
      *(float *)(v61 + 40) = v70;
      if ( v66 == 0.0 && *(float *)(v61 + 272) == 0.0 )
      {
        *(_DWORD *)(v61 + 264) = 0;
        *(float *)(v61 + 272) = v68;
        *(float *)(v61 + 268) = v69;
        *(float *)(v61 + 276) = v70;
      }
      std::wstring::wstring(&key, word_17BE9D8);
      LOBYTE(v130) = 73;
      (*(void (**)(int, std::wstring *))(*(_DWORD *)v61 + 68))(v61, &key);
      LOBYTE(v130) = 65;
      if ( key._Myres >= 8 )
        std::allocator<wchar_t>::deallocate((std::allocator<wchar_t> *)&v115 + 3, key._Bx._Ptr, key._Myres + 1);
      key._Myres = 7;
      std::wstring::_Eos(&key, 0);
      ksgui::Control::setVisible((ksgui::Control *)v61, 0);
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->times, (int *)&lbl);
      ksgui::Control::addControl(this, lbl);
      if ( this->showTimestamp )
        *(float *)&left = this->TIME_ROW_W;
      v71 = (CarAudioFMOD *)operator new(0x11Cu);
      v117.__this = v71;
      LOBYTE(v130) = 74;
      if ( v71 )
      {
        left_4 = (unsigned int)this->gui;
        v72 = std::to_wstring((std::wstring *)&result, (int)v118[0]);
        LOBYTE(v130) = 75;
        v3 |= 2u;
        lbl = (ksgui::Label *)v3;
        std::operator+<wchar_t>((std::wstring *)&v111[4], L"chat_lbl_t", v72);
        ksgui::Label::Label((ksgui::Label *)v71, *(std::wstring *)&v111[4], (ksgui::GUI *)left_4);
        v74 = v73;
      }
      else
      {
        v74 = 0;
      }
      lbl = (ksgui::Label *)v74;
      v130 = 65;
      if ( (v3 & 2) != 0 )
      {
        v3 &= 0xFFFFFFFD;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      }
      std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)(v74 + 128), (const std::shared_ptr<Font> *)&v);
      *(_DWORD *)(v74 + 152) = 0;
      (*(void (**)(int, _DWORD, _DWORD))(*(_DWORD *)v74 + 28))(
        v74,
        LODWORD(this->SINGLE_ROW_W),
        LODWORD(this->SINGLE_ROW_H));
      ksgui::Form::setPosition((ksgui::Form *)v74, *(float *)&left, *((float *)&left + 1));
      std::wstring::wstring((std::wstring *)&result, word_17BE9D8);
      LOBYTE(v130) = 77;
      (*(void (**)(int, Texture *))(*(_DWORD *)v74 + 68))(v74, &result);
      LOBYTE(v130) = 65;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      ksgui::Control::setVisible((ksgui::Control *)v74, 0);
      std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->rows, (int *)&lbl);
      ksgui::Control::addControl(this, lbl);
      *((float *)&left + 1) = this->SINGLE_ROW_H + *((float *)&left + 1);
      FormChat::ChatIntensities::ChatIntensities(&p, 1.0, 1.0, v113, v114);
      std::vector<FormChat::ChatIntensities>::push_back(&this->shownMessages, &p);
      v75 = this->ROW_COUNT;
      v52 = operator new;
      ++v118[0];
    }
    while ( (int)v118[0] < v75 );
  }
  v76 = (CarAudioFMOD *)v52(0x118u);
  v117.__this = v76;
  LOBYTE(v130) = 78;
  if ( v76 )
  {
    std::wstring::wstring((std::wstring *)&result, L"scrollTop");
    LOBYTE(v130) = 79;
    left_4 = (unsigned int)this->gui;
    v3 |= 4u;
    lbl = (ksgui::Label *)v3;
    ksgui::Control::Control((ksgui::Control *)v76, (const std::wstring *)&result, (ksgui::GUI *)left_4);
  }
  else
  {
    v77 = 0;
  }
  this->scrollTop = v77;
  v130 = 65;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  }
  std::wstring::wstring((std::wstring *)&result, word_17BE9D8);
  LOBYTE(v130) = 81;
  this->scrollTop->setText(this->scrollTop, (const std::wstring *)&result);
  LOBYTE(v130) = 65;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->scrollTop->setSize)(
    this->scrollTop,
    LODWORD(this->SINGLE_ROW_H),
    LODWORD(this->SINGLE_ROW_H));
  ((void (*)(ksgui::Control *, int))this->scrollTop->setRepeatInterval)(this->scrollTop, 1048576000);
  this->scrollTop->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->SCROLL_COLOR);
  Texture::operator=(&this->scrollTop->backTexture, &this->scrollTopTex);
  vec4f::vec4f((vec4f *)&p, 0.0, 0.0, 0.0, 1.0);
  v79 = (vec4f)_mm_loadu_si128(v78);
  this->scrollTop->backTextureColor = v79;
  this->scrollTop->drawBorder = 0;
  ksgui::Form::getHeaderHeight(this);
  ksgui::Form::setPosition((ksgui::Form *)this->scrollTop, this->FWIDTH - this->SINGLE_ROW_H, v79.x);
  left_4 = (unsigned int)this->scrollTop;
  CommandItem::CommandItem(&v117, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v111[4],
    v80);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->scrollTop->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v111[4],
    (void *)left_4);
  ksgui::Control::addControl(this, this->scrollTop);
  v81 = (CarAudioFMOD *)v52(0x118u);
  v117.__this = v81;
  LOBYTE(v130) = 82;
  if ( v81 )
  {
    std::wstring::wstring((std::wstring *)&result, L"scrollUp");
    LOBYTE(v130) = 83;
    left_4 = (unsigned int)this->gui;
    v3 |= 8u;
    lbl = (ksgui::Label *)v3;
    ksgui::Control::Control((ksgui::Control *)v81, (const std::wstring *)&result, (ksgui::GUI *)left_4);
  }
  else
  {
    v82 = 0;
  }
  this->scrollUp = v82;
  v130 = 65;
  if ( (v3 & 8) != 0 )
  {
    v3 &= 0xFFFFFFF7;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  }
  std::wstring::wstring((std::wstring *)&result, word_17BE9D8);
  LOBYTE(v130) = 85;
  this->scrollUp->setText(this->scrollUp, (const std::wstring *)&result);
  LOBYTE(v130) = 65;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->scrollUp->setSize)(
    this->scrollUp,
    LODWORD(this->SINGLE_ROW_H),
    LODWORD(this->SINGLE_ROW_H));
  ((void (*)(ksgui::Control *, int))this->scrollUp->setRepeatInterval)(this->scrollUp, 1048576000);
  this->scrollUp->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->SCROLL_COLOR);
  Texture::operator=(&this->scrollUp->backTexture, &this->scrollUpTex);
  vec4f::vec4f((vec4f *)&p, 0.0, 0.0, 0.0, 1.0);
  v84 = (vec4f)_mm_loadu_si128(v83);
  this->scrollUp->backTextureColor = v84;
  this->scrollUp->drawBorder = 0;
  ksgui::Form::getHeaderHeight(this);
  v85 = this->SINGLE_ROW_H;
  v86 = (ksgui::Form *)this->scrollUp;
  *(float *)&left_4 = v84.x + v85;
  v84.x = this->FWIDTH - v85;
  ksgui::Form::setPosition(v86, v84.x, *(float *)&left_4);
  left_4 = (unsigned int)this->scrollUp;
  CommandItem::CommandItem(&v117, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v111[4],
    v87);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->scrollUp->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v111[4],
    (void *)left_4);
  ksgui::Control::addControl(this, this->scrollUp);
  ksgui::Form::getHeaderHeight(this);
  LODWORD(left) = (int)(float)((float)((float)(this->FHEIGHT - v84.x) - (float)(this->SINGLE_ROW_H * 5.0)) * 0.5);
  v88 = (CarAudioFMOD *)v52(0x118u);
  v117.__this = v88;
  LOBYTE(v130) = 86;
  if ( v88 )
  {
    std::wstring::wstring((std::wstring *)&result, L"scrollHalfUp");
    LOBYTE(v130) = 87;
    left_4 = (unsigned int)this->gui;
    v3 |= 0x10u;
    lbl = (ksgui::Label *)v3;
    ksgui::Control::Control((ksgui::Control *)v88, (const std::wstring *)&result, (ksgui::GUI *)left_4);
  }
  else
  {
    v89 = 0;
  }
  this->scrollHalfUp = v89;
  v130 = 65;
  if ( (v3 & 0x10) != 0 )
  {
    v3 &= 0xFFFFFFEF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  }
  std::wstring::wstring((std::wstring *)&result, word_17BE9D8);
  LOBYTE(v130) = 89;
  this->scrollHalfUp->setText(this->scrollHalfUp, (const std::wstring *)&result);
  LOBYTE(v130) = 65;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  v90 = this->scrollHalfUp;
  v91 = v90->__vftable;
  *(float *)&left_4 = (float)(int)left;
  ((void (*)(ksgui::Control *, _DWORD, float))v91->setSize)(
    v90,
    LODWORD(this->SINGLE_ROW_H),
    (float)(int)left);
  ((void (*)(ksgui::Control *, int))this->scrollHalfUp->setRepeatInterval)(this->scrollHalfUp, 1048576000);
  v92 = (vec4f)_mm_loadu_si128((const __m128i *)&this->SCROLL_COLOR);
  this->scrollHalfUp->backColor = v92;
  this->scrollHalfUp->drawBorder = 0;
  ksgui::Form::getHeaderHeight(this);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->scrollHalfUp,
    this->FWIDTH - this->SINGLE_ROW_H,
    v92.x + (float)(this->SINGLE_ROW_H * 2.0));
  left_4 = (unsigned int)this->scrollHalfUp;
  CommandItem::CommandItem(&v117, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v111[4],
    v93);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->scrollHalfUp->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v111[4],
    (void *)left_4);
  ksgui::Control::addControl(this, this->scrollHalfUp);
  v94 = (CarAudioFMOD *)v52(0x118u);
  v117.__this = v94;
  LOBYTE(v130) = 90;
  if ( v94 )
  {
    std::wstring::wstring((std::wstring *)&result, L"scrollHalfDown");
    LOBYTE(v130) = 91;
    left_4 = (unsigned int)this->gui;
    v3 |= 0x20u;
    lbl = (ksgui::Label *)v3;
    ksgui::Control::Control((ksgui::Control *)v94, (const std::wstring *)&result, (ksgui::GUI *)left_4);
  }
  else
  {
    v95 = 0;
  }
  this->scrollHalfDown = v95;
  v130 = 65;
  if ( (v3 & 0x20) != 0 )
  {
    v3 &= 0xFFFFFFDF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  }
  std::wstring::wstring((std::wstring *)&result, word_17BE9D8);
  LOBYTE(v130) = 93;
  this->scrollHalfDown->setText(this->scrollHalfDown, (const std::wstring *)&result);
  LOBYTE(v130) = 65;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  v96 = left;
  v97 = this->scrollHalfDown;
  v98 = v97->__vftable;
  *(float *)&left_4 = (float)(int)left;
  ((void (*)(ksgui::Control *, _DWORD, float))v98->setSize)(
    v97,
    LODWORD(this->SINGLE_ROW_H),
    (float)(int)left);
  ((void (*)(ksgui::Control *, int))this->scrollHalfDown->setRepeatInterval)(
    this->scrollHalfDown,
    1048576000);
  this->scrollHalfDown->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->SCROLL_COLOR);
  this->scrollHalfDown->drawBorder = 0;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->scrollHalfDown,
    this->FWIDTH - this->SINGLE_ROW_H,
    (float)(this->FHEIGHT - (float)(this->SINGLE_ROW_H * 3.0)) - (float)v96);
  left_4 = (unsigned int)this->scrollHalfDown;
  CommandItem::CommandItem(&v117, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v111[4],
    v99);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->scrollHalfDown->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v111[4],
    (void *)left_4);
  ksgui::Control::addControl(this, this->scrollHalfDown);
  v100 = (CarAudioFMOD *)v52(0x118u);
  v117.__this = v100;
  LOBYTE(v130) = 94;
  if ( v100 )
  {
    std::wstring::wstring((std::wstring *)&result, L"scrollDown");
    LOBYTE(v130) = 95;
    left_4 = (unsigned int)this->gui;
    v3 |= 0x40u;
    lbl = (ksgui::Label *)v3;
    ksgui::Control::Control((ksgui::Control *)v100, (const std::wstring *)&result, (ksgui::GUI *)left_4);
  }
  else
  {
    v101 = 0;
  }
  this->scrollDown = v101;
  v130 = 65;
  if ( (v3 & 0x40) != 0 )
  {
    v3 &= 0xFFFFFFBF;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  }
  std::wstring::wstring((std::wstring *)&result, word_17BE9D8);
  LOBYTE(v130) = 97;
  this->scrollDown->setText(this->scrollDown, (const std::wstring *)&result);
  LOBYTE(v130) = 65;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->scrollDown->setSize)(
    this->scrollDown,
    LODWORD(this->SINGLE_ROW_H),
    LODWORD(this->SINGLE_ROW_H));
  ((void (*)(ksgui::Control *, int))this->scrollDown->setRepeatInterval)(this->scrollDown, 1048576000);
  this->scrollDown->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->SCROLL_COLOR);
  Texture::operator=(&this->scrollDown->backTexture, &this->scrollDownTex);
  vec4f::vec4f((vec4f *)&p, 0.0, 0.0, 0.0, 1.0);
  this->scrollDown->backTextureColor = (vec4f)_mm_loadu_si128(v102);
  this->scrollDown->drawBorder = 0;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->scrollDown,
    this->FWIDTH - this->SINGLE_ROW_H,
    this->FHEIGHT - (float)(this->SINGLE_ROW_H * 3.0));
  left_4 = (unsigned int)this->scrollDown;
  CommandItem::CommandItem(&v117, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v111[4],
    v103);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->scrollDown->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v111[4],
    (void *)left_4);
  ksgui::Control::addControl(this, this->scrollDown);
  v104 = (CarAudioFMOD *)v52(0x118u);
  v117.__this = v104;
  LOBYTE(v130) = 98;
  if ( v104 )
  {
    std::wstring::wstring((std::wstring *)&result, L"scrollBottom");
    LOBYTE(v130) = 99;
    left_4 = (unsigned int)this->gui;
    v3 |= 0x80u;
    lbl = (ksgui::Label *)v3;
    ksgui::Control::Control((ksgui::Control *)v104, (const std::wstring *)&result, (ksgui::GUI *)left_4);
  }
  else
  {
    v105 = 0;
  }
  this->scrollBottom = v105;
  v130 = 65;
  if ( (v3 & 0x80u) != 0 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  std::wstring::wstring((std::wstring *)&result, word_17BE9D8);
  LOBYTE(v130) = 101;
  this->scrollBottom->setText(this->scrollBottom, (const std::wstring *)&result);
  LOBYTE(v130) = 65;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))this->scrollBottom->setSize)(
    this->scrollBottom,
    LODWORD(this->SINGLE_ROW_H),
    LODWORD(this->SINGLE_ROW_H));
  ((void (*)(ksgui::Control *, int))this->scrollBottom->setRepeatInterval)(this->scrollBottom, 1048576000);
  this->scrollBottom->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&this->SCROLL_COLOR);
  Texture::operator=(&this->scrollBottom->backTexture, &this->scrollBottomTex);
  vec4f::vec4f((vec4f *)&p, 0.0, 0.0, 0.0, 1.0);
  this->scrollBottom->backTextureColor = (vec4f)_mm_loadu_si128(v106);
  this->scrollBottom->drawBorder = 0;
  ksgui::Form::setPosition(
    (ksgui::Form *)this->scrollBottom,
    this->FWIDTH - this->SINGLE_ROW_H,
    this->FHEIGHT - (float)(this->SINGLE_ROW_H * 2.0));
  left_4 = (unsigned int)this->scrollBottom;
  CommandItem::CommandItem(&v117, (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v111[4],
    v107);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->scrollBottom->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v111[4],
    (void *)left_4);
  ksgui::Control::addControl(this, this->scrollBottom);
  ksgui::Form::setSize(this, this->FWIDTH, this->FHEIGHT);
  v108 = this->BG_INTENSITY_MAIN;
  this->maxWidth = (int)(float)(this->SINGLE_ROW_W / this->PIX_PER_CHAR);
  vec4f::vec4f((vec4f *)&p, 0.0, 0.0, 0.0, v108);
  left_4 = (unsigned int)this;
  *(_DWORD *)&v111[24] = this;
  this->backColor = (vec4f)_mm_loadu_si128(v109);
  CommandItem::CommandItem(&v117, *(CarAudioFMOD **)&v111[24]);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v111[4],
    v110);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v111[4],
    (void *)left_4);
  *(_WORD *)&this->mustUpdate = 257;
  ksgui::Control::scaleByMult(this);
  std::shared_ptr<Material>::~shared_ptr<Material>((std::shared_ptr<Material> *)&v);
  LOBYTE(v130) = 11;
  INIReader::~INIReader(&ini);
}
FormChat *FormChat::`vector deleting destructor'(FormChat *this, unsigned int a2)
{
  FormChat::~FormChat(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FormChat::~FormChat(FormChat *this)
{
  struct tm *v2; // eax
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  unsigned int v9; // edi
  int v10; // ecx
  int v11; // ebp
  FormChat::ChatMessage *v12; // eax
  std::wostream *v13; // eax
  std::wstring *v14; // eax
  std::wstring *v15; // edi
  int v16; // ecx
  std::wostream *v17; // eax
  FormChat::ChatMessage *v18; // edi
  FormChat::ChatMessage *i; // ebp
  FormChat::ChatMessage *v20; // edi
  FormChat::ChatMessage *j; // ebp
  __int64 t; // [esp+14h] [ebp-170h] BYREF
  int v23; // [esp+1Ch] [ebp-168h]
  FormChat *v24; // [esp+20h] [ebp-164h]
  std::wofstream out; // [esp+24h] [ebp-160h] BYREF
  std::wstring msg; // [esp+CCh] [ebp-B8h] BYREF
  std::wstring result; // [esp+E4h] [ebp-A0h] BYREF
  std::wstring v28; // [esp+FCh] [ebp-88h] BYREF
  std::wstring filename; // [esp+114h] [ebp-70h] BYREF
  char mbstr[20]; // [esp+12Ch] [ebp-58h] BYREF
  unsigned int v31; // [esp+140h] [ebp-44h]
  std::wstring postfix; // [esp+144h] [ebp-40h] BYREF
  std::string s; // [esp+15Ch] [ebp-28h] BYREF
  int v34; // [esp+180h] [ebp-4h]

  v24 = this;
  this->__vftable = (FormChat_vtbl *)&FormChat::`vftable';
  v34 = 11;
  if ( this->EXPORT_ON_CLOSE )
  {
    postfix._Myres = 7;
    postfix._Mysize = 0;
    postfix._Bx._Buf[0] = 0;
    std::wstring::assign(&postfix, word_17BE9D8, 0);
    LOBYTE(v34) = 12;
    if ( this->OVERWRITE_EXPORT )
    {
      t = __time64(0);
      v2 = __localtime64(&t);
      if ( _strftime(mbstr, 0x14u, "%Y%m%d%H%M%S", v2) )
      {
        std::string::string(&s, mbstr);
        LOBYTE(v34) = 13;
        v3 = string2wstring(&result, &s);
        LOBYTE(v34) = 14;
        v4 = std::operator+<wchar_t>(&v28, L"_", v3);
        std::wstring::operator=(&postfix, v4);
        if ( v28._Myres >= 8 )
          operator delete(v28._Bx._Ptr);
        v28._Myres = 7;
        v28._Mysize = 0;
        v28._Bx._Buf[0] = 0;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        LOBYTE(v34) = 12;
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        if ( s._Myres >= 0x10 )
          operator delete(s._Bx._Ptr);
      }
    }
    v5 = Path::getDocumentPath((std::wstring *)mbstr);
    LOBYTE(v34) = 15;
    v6 = std::operator+<wchar_t>(&v28, v5, L"/Assetto Corsa/out/chat");
    LOBYTE(v34) = 16;
    v7 = std::operator+<wchar_t>(&result, v6, &postfix);
    LOBYTE(v34) = 17;
    std::operator+<wchar_t>(&filename, v7, L".txt");
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( v28._Myres >= 8 )
      operator delete(v28._Bx._Ptr);
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    LOBYTE(v34) = 21;
    if ( v31 >= 8 )
      operator delete(*(void **)mbstr);
    v31 = 7;
    *(_WORD *)mbstr = 0;
    v8 = &filename;
    if ( filename._Myres >= 8 )
      v8 = (std::wstring *)filename._Bx._Ptr;
    *(_DWORD *)&mbstr[16] = 0;
    std::wofstream::wofstream(&out, v8->_Bx._Buf, 2, 64, 1);
    v9 = 0;
    v23 = -1;
    msg._Myres = 7;
    msg._Mysize = 0;
    msg._Bx._Buf[0] = 0;
    LOBYTE(v34) = 23;
    v10 = (char *)this->messages._Mylast - (char *)this->messages._Myfirst;
    LODWORD(t) = 0;
    if ( v10 / 88 )
    {
      v11 = 0;
      do
      {
        v12 = this->messages._Myfirst;
        if ( v23 == v12[v11].msgid )
        {
          if ( v12[v11].space )
            std::wstring::append(&msg, L" ", 1u);
          std::wstring::append(&msg, &this->messages._Myfirst[v11].msg, 0, 0xFFFFFFFF);
        }
        else
        {
          v23 = v12[v11].msgid;
          if ( std::wstring::compare(&msg, 0, v9, word_17BE9D8, 0) )
          {
            v13 = std::operator<<<wchar_t>(&out, &msg);
            std::wostream::operator<<(v13);
          }
          v14 = std::operator+<wchar_t>((std::wstring *)&s, &this->messages._Myfirst[v11].time, L" ");
          LOBYTE(v34) = 24;
          v15 = std::operator+<wchar_t>(&result, v14, &this->messages._Myfirst[v11].msg);
          if ( &msg != v15 )
          {
            if ( msg._Myres >= 8 )
              operator delete(msg._Bx._Ptr);
            msg._Myres = 7;
            msg._Mysize = 0;
            msg._Bx._Buf[0] = 0;
            if ( v15->_Myres >= 8 )
            {
              msg._Bx._Ptr = v15->_Bx._Ptr;
              v15->_Bx._Ptr = 0;
            }
            else if ( v15->_Mysize != -1 )
            {
              _memmove(&msg, v15, 2 * (v15->_Mysize + 1));
            }
            msg._Mysize = v15->_Mysize;
            msg._Myres = v15->_Myres;
            v15->_Myres = 7;
            v15->_Mysize = 0;
            v15->_Bx._Buf[0] = 0;
          }
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          LOBYTE(v34) = 23;
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          if ( s._Myres >= 8 )
            operator delete(s._Bx._Ptr);
        }
        v16 = (char *)this->messages._Mylast - (char *)this->messages._Myfirst;
        ++v11;
        LODWORD(t) = t + 1;
        v9 = msg._Mysize;
      }
      while ( (unsigned int)t < v16 / 88 );
    }
    if ( std::wstring::compare(&msg, 0, v9, word_17BE9D8, 0) )
    {
      v17 = std::operator<<<wchar_t>(&out, &msg);
      std::wostream::operator<<(v17);
    }
    std::wofstream::close(&out);
    if ( msg._Myres >= 8 )
      operator delete(msg._Bx._Ptr);
    msg._Myres = 7;
    msg._Mysize = 0;
    msg._Bx._Buf[0] = 0;
    std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&out.gap58[8]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&out.gap58[8]);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    if ( postfix._Myres >= 8 )
      operator delete(postfix._Bx._Ptr);
  }
  LOBYTE(v34) = 10;
  OnSetupAppCreated::~OnSetupAppCreated(&this->scrollBottomTex);
  LOBYTE(v34) = 9;
  OnSetupAppCreated::~OnSetupAppCreated(&this->scrollDownTex);
  LOBYTE(v34) = 8;
  OnSetupAppCreated::~OnSetupAppCreated(&this->scrollUpTex);
  LOBYTE(v34) = 7;
  OnSetupAppCreated::~OnSetupAppCreated(&this->scrollTopTex);
  if ( this->backColors._Myfirst )
  {
    operator delete(this->backColors._Myfirst);
    this->backColors._Myfirst = 0;
    this->backColors._Mylast = 0;
    this->backColors._Myend = 0;
  }
  if ( this->foreColors._Myfirst )
  {
    operator delete(this->foreColors._Myfirst);
    this->foreColors._Myfirst = 0;
    this->foreColors._Mylast = 0;
    this->foreColors._Myend = 0;
  }
  if ( this->rows._Myfirst )
  {
    operator delete(this->rows._Myfirst);
    this->rows._Myfirst = 0;
    this->rows._Mylast = 0;
    this->rows._Myend = 0;
  }
  if ( this->times._Myfirst )
  {
    operator delete(this->times._Myfirst);
    this->times._Myfirst = 0;
    this->times._Mylast = 0;
    this->times._Myend = 0;
  }
  if ( this->shownMessages._Myfirst )
  {
    operator delete(this->shownMessages._Myfirst);
    this->shownMessages._Myfirst = 0;
    this->shownMessages._Mylast = 0;
    this->shownMessages._Myend = 0;
  }
  v18 = this->newMessages._Myfirst;
  if ( v18 )
  {
    for ( i = this->newMessages._Mylast; v18 != i; ++v18 )
      FormChat::ChatMessage::~ChatMessage(v18);
    operator delete(this->newMessages._Myfirst);
    this->newMessages._Myfirst = 0;
    this->newMessages._Mylast = 0;
    this->newMessages._Myend = 0;
  }
  v20 = this->messages._Myfirst;
  if ( v20 )
  {
    for ( j = this->messages._Mylast; v20 != j; ++v20 )
      FormChat::ChatMessage::~ChatMessage(v20);
    operator delete(this->messages._Myfirst);
    this->messages._Myfirst = 0;
    this->messages._Mylast = 0;
    this->messages._Myend = 0;
  }
  v34 = -1;
  this->__vftable = (FormChat_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void FormChat::render(FormChat *this, float dt)
{
  ksgui::Control *v3; // ecx
  bool v4; // al
  ksgui::Control *v5; // ecx
  bool v6; // al
  ksgui::Control *v7; // ecx
  bool v8; // al
  ksgui::Control *v9; // ecx
  bool v10; // al
  ksgui::Control *v11; // ecx
  bool v12; // al
  ksgui::Control *v13; // ecx
  bool v14; // al
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // edi
  FormChat::ChatMessage *i; // esi
  int v20; // ecx
  FormChat *v21; // esi
  FormChat::ChatMessage *v22; // eax
  FormChat::ChatMessage *v23; // eax
  int v24; // eax
  bool v25; // zf
  ksgui::Label **v26; // eax
  ksgui::Label *v27; // ecx
  ksgui::Label *v28; // ecx
  ksgui::Label_vtbl *v29; // eax
  int v30; // eax
  int v31; // edx
  __m128i v32; // xmm0
  ksgui::Label *v33; // ecx
  ksgui::Label_vtbl *v34; // eax
  ksgui::Label *v35; // ecx
  int v36; // eax
  std::vector<FormChat::ChatIntensities> *v37; // edi
  FormChat::ChatIntensities *v38; // edx
  const __m128i *v39; // eax
  FormChat::ChatIntensities *v40; // ecx
  __m128i v41; // xmm0
  ksgui::Label **v42; // eax
  ksgui::Label *v43; // eax
  FormChat::ChatIntensities *v44; // ecx
  float v45; // eax
  __m128i *v46; // ecx
  const __m128i *v47; // eax
  __m128i *v48; // eax
  unsigned int v49; // edx
  ksgui::Control *v50; // eax
  __m128i v51; // xmm0
  ksgui::Control *v52; // ecx
  ksgui::Control_vtbl *v53; // eax
  unsigned int v54; // edx
  int v55; // eax
  FormChat::ChatIntensities *v56; // ecx
  FormChat **v57; // eax
  float v58; // xmm1_4
  int v59; // ecx
  int v60; // ecx
  float v61; // xmm0_4
  unsigned int v62; // eax
  FormChat::ChatMessage v63; // [esp-24h] [ebp-120h] BYREF
  int v64; // [esp+34h] [ebp-C8h]
  __int64 v65; // [esp+38h] [ebp-C4h]
  float v66; // [esp+40h] [ebp-BCh]
  float v67; // [esp+4Ch] [ebp-B0h] BYREF
  int v68; // [esp+50h] [ebp-ACh] BYREF
  FormChat *v69; // [esp+54h] [ebp-A8h] BYREF
  float v70; // [esp+58h] [ebp-A4h] BYREF
  __m128i v71; // [esp+5Ch] [ebp-A0h] BYREF
  std::wstring v72; // [esp+74h] [ebp-88h] BYREF
  FormChat::ChatMessage __that; // [esp+8Ch] [ebp-70h] BYREF
  int v74; // [esp+F8h] [ebp-4h]

  v69 = this;
  v3 = this->scrollBottom;
  v4 = v69->drawBackground;
  LOBYTE(v67) = v4;
  if ( v3->visible != v4 )
  {
    v64 = LODWORD(v67);
    v3->visible = v4;
    v3->onVisibleChanged(v3, v64);
  }
  v5 = this->scrollDown;
  v6 = this->drawBackground;
  LOBYTE(v67) = v6;
  if ( v5->visible != v6 )
  {
    v64 = LODWORD(v67);
    v5->visible = v6;
    v5->onVisibleChanged(v5, v64);
  }
  v7 = this->scrollHalfDown;
  v8 = this->drawBackground;
  LOBYTE(v67) = v8;
  if ( v7->visible != v8 )
  {
    v64 = LODWORD(v67);
    v7->visible = v8;
    v7->onVisibleChanged(v7, v64);
  }
  v9 = this->scrollHalfUp;
  v10 = this->drawBackground;
  LOBYTE(v67) = v10;
  if ( v9->visible != v10 )
  {
    v64 = LODWORD(v67);
    v9->visible = v10;
    v9->onVisibleChanged(v9, v64);
  }
  v11 = this->scrollUp;
  v12 = this->drawBackground;
  LOBYTE(v67) = v12;
  if ( v11->visible != v12 )
  {
    v64 = LODWORD(v67);
    v11->visible = v12;
    v11->onVisibleChanged(v11, v64);
  }
  v13 = this->scrollTop;
  v14 = this->drawBackground;
  LOBYTE(v67) = v14;
  if ( v13->visible != v14 )
  {
    v64 = LODWORD(v67);
    v13->visible = v14;
    v13->onVisibleChanged(v13, v64);
  }
  v15 = &v67;
  v16 = this->currentTimeToLose - dt;
  v68 = 0;
  v67 = v16;
  if ( v16 <= 0.0 )
    v15 = (float *)&v68;
  v17 = *v15;
  this->currentTimeToLose = *v15;
  if ( v17 == 0.0 )
    this->textInput->hasFocus = 0;
  this->addedLines = 0;
  v18 = (int)this->newMessages._Mylast;
  for ( i = this->newMessages._Myfirst; i != (FormChat::ChatMessage *)v18; ++i )
  {
    FormChat::ChatMessage::ChatMessage(&__that, i);
    v74 = 0;
    FormChat::ChatMessage::ChatMessage((FormChat::ChatMessage *)&v63.msg, &__that);
    v63.msgid = v20;
    FormChat::addMessage(v69, v63, (int *)v64);
    v74 = -1;
    if ( __that.time._Myres >= 8 )
      operator delete(__that.time._Bx._Ptr);
    __that.time._Myres = 7;
    __that.time._Mysize = 0;
    __that.time._Bx._Buf[0] = 0;
    if ( __that.username._Myres >= 8 )
      operator delete(__that.username._Bx._Ptr);
    __that.username._Myres = 7;
    __that.username._Mysize = 0;
    __that.username._Bx._Buf[0] = 0;
    if ( __that.msg._Myres >= 8 )
      operator delete(__that.msg._Bx._Ptr);
  }
  v21 = v69;
  v22 = v69->newMessages._Myfirst;
  v67 = *(float *)&v69->newMessages._Mylast;
  v69 = (FormChat *)v22;
  if ( v22 != (FormChat::ChatMessage *)LODWORD(v67) )
  {
    v18 = (int)&v22->time._Myres;
    do
    {
      if ( *(_DWORD *)v18 >= 8u )
        operator delete(*(void **)(v18 - 20));
      *(_DWORD *)v18 = 7;
      *(_DWORD *)(v18 - 4) = 0;
      *(_WORD *)(v18 - 20) = 0;
      if ( *(_DWORD *)(v18 - 28) >= 8u )
        operator delete(*(void **)(v18 - 48));
      *(_DWORD *)(v18 - 28) = 7;
      *(_DWORD *)(v18 - 32) = 0;
      *(_WORD *)(v18 - 48) = 0;
      if ( *(_DWORD *)(v18 - 56) >= 8u )
        operator delete(*(void **)(v18 - 76));
      *(_DWORD *)(v18 - 56) = 7;
      *(_DWORD *)(v18 - 60) = 0;
      *(_WORD *)(v18 - 76) = 0;
      v18 += 88;
      v69 = (FormChat *)((char *)v69 + 88);
    }
    while ( v69 != (FormChat *)LODWORD(v67) );
  }
  v21->newMessages._Mylast = v21->newMessages._Myfirst;
  if ( v21->mustUpdate )
  {
    v23 = v21->messages._Myfirst;
    if ( v23 != v21->messages._Mylast )
    {
      v24 = ((int)((unsigned __int64)(780903145i64 * ((char *)v21->messages._Mylast - (char *)v23)) >> 32) >> 4)
          + ((unsigned int)((unsigned __int64)(780903145i64 * ((char *)v21->messages._Mylast - (char *)v23)) >> 32) >> 31)
          - 1;
      v25 = !v21->isLastRow;
      v69 = (FormChat *)v24;
      if ( v25 )
      {
        v24 = v21->topRow;
        v69 = (FormChat *)v24;
      }
      v18 = v21->ROW_COUNT - 1;
      v67 = *(float *)&v18;
      if ( v18 >= 0 )
      {
        v68 = 88 * v24;
        do
        {
          v72._Myres = 7;
          v72._Mysize = 0;
          v72._Bx._Buf[0] = 0;
          std::wstring::assign(&v72, word_17BE9D8, 0);
          v74 = 1;
          v21->rows._Myfirst[v18]->setText(v21->rows._Myfirst[v18], &v72);
          v74 = -1;
          if ( v72._Myres >= 8 )
            operator delete(v72._Bx._Ptr);
          v26 = v21->rows._Myfirst;
          v72._Myres = 7;
          v72._Mysize = 0;
          v26[v18]->backColor = 0i64;
          v72._Bx._Buf[0] = 0;
          std::wstring::assign(&v72, word_17BE9D8, 0);
          v74 = 2;
          v21->times._Myfirst[v18]->setText(v21->times._Myfirst[v18], &v72);
          v74 = -1;
          if ( v72._Myres >= 8 )
            operator delete(v72._Bx._Ptr);
          v21->times._Myfirst[v18]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&v21->rows._Myfirst[v18]->backColor);
          if ( v21->messages._Mylast - v21->messages._Myfirst > (unsigned int)v69 )
          {
            v27 = v21->rows._Myfirst[v18];
            v27->setText(v27, (const std::wstring *)((char *)&v21->messages._Myfirst->msg + v68));
            v18 = LODWORD(v67);
            v28 = v21->rows._Myfirst[LODWORD(v67)];
            if ( !v28->visible )
            {
              v29 = v28->__vftable;
              v64 = 1;
              v28->visible = 1;
              ((void (__stdcall *)(int))v29->onVisibleChanged)(v64);
            }
            v30 = *(int *)((char *)&v21->messages._Myfirst->userid + v68);
            if ( v30 )
            {
              if ( v30 == 1 )
              {
                v21->rows._Myfirst[v18]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&v21->serverForeColor);
                v32 = _mm_loadu_si128((const __m128i *)&v21->serverBackColor);
              }
              else
              {
                v31 = v68;
                v21->rows._Myfirst[v18]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&v21->foreColors._Myfirst[*(int *)((char *)&v21->messages._Myfirst->userid + v68) % (unsigned int)(v21->foreColors._Mylast - v21->foreColors._Myfirst)]);
                v32 = _mm_loadu_si128((const __m128i *)&v21->backColors._Myfirst[*(int *)((char *)&v21->messages._Myfirst->userid
                                                                                        + v31)
                                                                               % (unsigned int)(v21->backColors._Mylast
                                                                                              - v21->backColors._Myfirst)]);
              }
            }
            else
            {
              v21->rows._Myfirst[v18]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&v21->playerForeColor);
              v32 = _mm_loadu_si128((const __m128i *)&v21->playerBackColor);
            }
            v21->rows._Myfirst[v18]->backColor = (vec4f)v32;
            v21->times._Myfirst[v18]->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&v21->rows._Myfirst[v18]->backColor);
            v21->times._Myfirst[v18]->foreColor = (vec4f)_mm_loadu_si128((const __m128i *)&v21->rows._Myfirst[v18]->foreColor);
            if ( v21->showTimestamp )
            {
              v33 = v21->times._Myfirst[v18];
              if ( !v33->visible )
              {
                v34 = v33->__vftable;
                v64 = 1;
                v33->visible = 1;
                ((void (__stdcall *)(int))v34->onVisibleChanged)(v64);
              }
              if ( std::wstring::compare(
                     (std::wstring *)((char *)&v21->messages._Myfirst->time + v68),
                     0,
                     *(unsigned int *)((char *)&v21->messages._Myfirst->time._Mysize + v68),
                     word_17BE9D8,
                     0)
                && std::wstring::compare(
                     (std::wstring *)((char *)&v21->messages._Myfirst->username + v68),
                     0,
                     *(unsigned int *)((char *)&v21->messages._Myfirst->username._Mysize + v68),
                     word_17BE9D8,
                     0) )
              {
                v35 = v21->times._Myfirst[v18];
                v35->setText(v35, (const std::wstring *)((char *)&v21->messages._Myfirst->time + v68));
                v18 = LODWORD(v67);
              }
            }
            v36 = v21->addedLines;
            if ( v36 && v21->isLastRow )
            {
              v37 = &v21->shownMessages;
              v21->addedLines = v36 - 1;
              v38 = v21->shownMessages._Mylast;
              v39 = (const __m128i *)&v21->shownMessages._Myfirst[1];
              if ( v39 != (const __m128i *)v38 )
              {
                v40 = v21->shownMessages._Myfirst;
                do
                {
                  v41 = _mm_loadu_si128(v39++);
                  ++v40;
                  v40[-1] = (FormChat::ChatIntensities)v41;
                }
                while ( v39 != (const __m128i *)v38 );
              }
              --v21->shownMessages._Mylast;
              v42 = v21->rows._Myfirst;
              v71.m128i_i64[0] = 0x3F8000003F800000i64;
              v43 = v42[LODWORD(v67)];
              v44 = v21->shownMessages._Mylast;
              v71.m128i_i32[2] = LODWORD(v43->foreColor.w);
              v71.m128i_i32[3] = LODWORD(v43->backColor.w);
              if ( &v71 >= (__m128i *)v44 || v37->_Myfirst > (FormChat::ChatIntensities *)&v71 )
              {
                if ( v44 == v21->shownMessages._Myend )
                  std::vector<FormChat::ChatIntensities>::_Reserve(&v21->shownMessages, (unsigned int)v44);
                v48 = (__m128i *)v21->shownMessages._Mylast;
                if ( v48 )
                  *v48 = _mm_loadu_si128(&v71);
              }
              else
              {
                LODWORD(v45) = ((char *)&v71 - (char *)v37->_Myfirst) >> 4;
                v70 = v45;
                if ( v44 == v21->shownMessages._Myend )
                {
                  std::vector<FormChat::ChatIntensities>::_Reserve(&v21->shownMessages, (unsigned int)v44);
                  v45 = v70;
                }
                v46 = (__m128i *)v21->shownMessages._Mylast;
                v47 = (const __m128i *)&v37->_Myfirst[LODWORD(v45)];
                if ( v46 )
                  *v46 = _mm_loadu_si128(v47);
              }
              ++v21->shownMessages._Mylast;
              ++v21->topRow;
              v18 = LODWORD(v67);
            }
            v69 = (FormChat *)((char *)v69 - 1);
            v68 -= 88;
          }
          --v18;
          v67 = *(float *)&v18;
        }
        while ( v18 >= 0 );
      }
      v21->mustUpdate = 0;
    }
  }
  v49 = (int)((unsigned __int64)(780903145i64 * ((char *)v21->messages._Mylast - (char *)v21->messages._Myfirst)) >> 32) >> 4;
  if ( v21->topRow == v49 + (v49 >> 31) - 1
    || v21->messages._Mylast - v21->messages._Myfirst <= (unsigned int)v21->ROW_COUNT )
  {
    v50 = v21->scrollBottom;
    v51 = _mm_loadu_si128((const __m128i *)&v21->SCROLL_COLOR);
    v21->messageAlert = 0;
    v50->backColor = (vec4f)v51;
  }
  if ( v21->messageAlert )
  {
    v21->scrollBottom->backColor = (vec4f)_xmm;
    v52 = v21->scrollBottom;
    if ( !v52->visible )
    {
      v53 = v52->__vftable;
      v64 = 1;
      v52->visible = 1;
      ((void (__stdcall *)(int))v53->onVisibleChanged)(v64);
    }
  }
  v54 = 0;
  v55 = v21->shownMessages._Mylast - v21->shownMessages._Myfirst;
  v68 = 0;
  if ( v55 )
  {
    v18 = 0;
    do
    {
      if ( v21->resetVisibility )
      {
        *(float *)((char *)&v21->shownMessages._Myfirst->prefade + v18) = 1.0;
        *(float *)((char *)&v21->shownMessages._Myfirst->fade + v18) = 1.0;
      }
      else
      {
        v56 = v21->shownMessages._Myfirst;
        v57 = (FormChat **)&v70;
        v69 = 0;
        v58 = *(float *)((char *)&v56->prefade + v18);
        if ( v58 <= 0.0 )
        {
          v70 = *(float *)((char *)&v56->fade + v18) - (float)(dt / v21->FADE_MULT);
          if ( v70 <= 0.0 )
            v57 = &v69;
          *(_DWORD *)((char *)&v56->fade + v18) = *v57;
        }
        else
        {
          v70 = v58 - (float)(dt / v21->PREFADE_MULT);
          if ( v70 <= 0.0 )
            v57 = &v69;
          *(_DWORD *)((char *)&v56->prefade + v18) = *v57;
        }
        v54 = v68;
      }
      v59 = v68;
      v21->rows._Myfirst[v54]->foreColor.w = *(float *)((char *)&v21->shownMessages._Myfirst->fore + v18)
                                           * *(float *)((char *)&v21->shownMessages._Myfirst->fade + v18);
      v21->times._Myfirst[v59]->foreColor.w = v21->rows._Myfirst[v54]->foreColor.w;
      v60 = v68;
      v61 = *(float *)((char *)&v21->shownMessages._Myfirst->back + v18)
          * *(float *)((char *)&v21->shownMessages._Myfirst->fade + v18);
      v18 += 16;
      v21->rows._Myfirst[v68]->backColor.w = v61;
      v54 = v68 + 1;
      v21->times._Myfirst[v60]->backColor.w = v21->rows._Myfirst[v60]->backColor.w;
      v62 = v21->shownMessages._Mylast - v21->shownMessages._Myfirst;
      v68 = v54;
    }
    while ( v54 < v62 );
  }
  v21->resetVisibility = 0;
  ksgui::Control::render(v21, v18, (int)v21, dt, v65, v66);
}
void FormChat::addMessage(FormChat *this, const FormChat::ChatMessage data, int *lines)
{
  int *v4; // edx
  const wchar_t *v5; // eax
  const std::wstring *v6; // eax
  struct tm *v7; // eax
  std::wstring *v8; // ebx
  std::wstring *v9; // eax
  int v10; // eax
  std::wstring *v11; // ebx
  std::wstring *v12; // eax
  int v13; // ebx
  std::wstring *v14; // ebp
  char v15; // al
  std::wstring *v16; // ebx
  bool v17; // cf
  FormChat::ChatMessage v18; // [esp-5Ch] [ebp-19Ch] BYREF
  wchar_t *v19; // [esp-4h] [ebp-144h]
  char v20; // [esp+1Bh] [ebp-125h]
  __int64 t; // [esp+1Ch] [ebp-124h] BYREF
  std::wstring temp; // [esp+24h] [ebp-11Ch] BYREF
  std::wstring result; // [esp+3Ch] [ebp-104h] BYREF
  FormChat::ChatMessage cm; // [esp+54h] [ebp-ECh] BYREF
  std::wstring v25; // [esp+ACh] [ebp-94h] BYREF
  FormChat::ChatMessage c; // [esp+C4h] [ebp-7Ch] BYREF
  char mbstr[10]; // [esp+120h] [ebp-20h] BYREF
  int v28; // [esp+13Ch] [ebp-4h]

  v28 = 0;
  if ( this->debug )
  {
    v4 = (int *)&data.msg._Bx._Alias[4];
    v5 = &data.username._Bx._Buf[2];
    if ( data.userid >= 8u )
      v4 = *(int **)&data.msg._Bx._Alias[4];
    v19 = (wchar_t *)v4;
    if ( *(_DWORD *)&data.space >= 8u )
      v5 = *(const wchar_t **)&data.username._Bx._Alias[4];
    _printf("CM ADD %ls : %ls\n", v5, v19);
  }
  this->messageAlert = 1;
  FormChat::ChatMessage::ChatMessage(&cm, (const FormChat::ChatMessage *)&data.msg);
  temp._Myres = 7;
  temp._Mysize = 0;
  temp._Bx._Buf[0] = 0;
  LOBYTE(v28) = 2;
  if ( std::wstring::compare(&cm.username, 0, cm.username._Mysize, word_17BE9D8, 0) )
  {
    v6 = std::operator+<wchar_t>(&result, &cm.username, L": ");
    LOBYTE(v28) = 3;
    std::wstring::append(&temp, v6, 0, 0xFFFFFFFF);
    LOBYTE(v28) = 2;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    t = __time64(0);
    v7 = __localtime64(&t);
    if ( _strftime(mbstr, 0xAu, "%H:%M:%S", v7) )
    {
      std::string::string((std::string *)&result, mbstr);
      LOBYTE(v28) = 4;
      v8 = string2wstring(&v25, (const std::string *)&result);
      if ( &cm.time != v8 )
      {
        if ( cm.time._Myres >= 8 )
          operator delete(cm.time._Bx._Ptr);
        cm.time._Myres = 7;
        cm.time._Mysize = 0;
        cm.time._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&cm.time, v8);
      }
      if ( v25._Myres >= 8 )
        operator delete(v25._Bx._Ptr);
      LOBYTE(v28) = 2;
      v25._Myres = 7;
      v25._Mysize = 0;
      v25._Bx._Buf[0] = 0;
      if ( result._Myres >= 0x10 )
        operator delete(result._Bx._Ptr);
    }
  }
  std::wstring::append(&temp, &cm.msg, 0, 0xFFFFFFFF);
  v9 = std::wstring::substr(&temp, &result, 0, 1u);
  LOBYTE(v28) = 5;
  v10 = std::wstring::compare(v9, 0, v9->_Mysize, L" ", 1u);
  LOBYTE(v28) = 2;
  cm.space = v10 == 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v11 = ksTrim(&result, &temp);
  if ( &temp != v11 )
  {
    if ( temp._Myres >= 8 )
      operator delete(temp._Bx._Ptr);
    temp._Myres = 7;
    temp._Mysize = 0;
    temp._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&temp, v11);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( temp._Mysize <= this->maxWidth )
  {
    std::wstring::assign(&cm.msg, &temp, 0, 0xFFFFFFFF);
    std::vector<FormChat::ChatMessage>::push_back(&this->messages, &cm);
    ++this->addedLines;
  }
  else
  {
    v12 = std::wstring::substr(&temp, &result, 0, this->maxWidth);
    v13 = std::wstring::find_last_of(v12, L" ", this->maxWidth, 1u);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v13 == -1 )
      v13 = this->maxWidth;
    v14 = std::wstring::substr(&temp, &result, 0, v13);
    if ( &cm.msg != v14 )
    {
      if ( cm.msg._Myres >= 8 )
        operator delete(cm.msg._Bx._Ptr);
      cm.msg._Myres = 7;
      cm.msg._Mysize = 0;
      cm.msg._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&cm.msg, v14);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::vector<FormChat::ChatMessage>::push_back(&this->messages, &cm);
    ++this->addedLines;
    v15 = std::wstring::substr(&temp, &result, v13, 0xFFFFFFFF)->_Mysize != 0;
    v20 = v15;
    if ( result._Myres >= 8 )
    {
      operator delete(result._Bx._Ptr);
      v15 = v20;
    }
    if ( v15 )
    {
      FormChat::ChatMessage::ChatMessage(&c);
      LOBYTE(v28) = 6;
      c.userid = (int)data.username._Bx._Ptr;
      std::wstring::assign(&c.username, word_17BE9D8, 0);
      v16 = std::wstring::substr(&temp, &result, v13, 0xFFFFFFFF);
      if ( &c.msg != v16 )
      {
        if ( c.msg._Myres >= 8 )
          operator delete(c.msg._Bx._Ptr);
        c.msg._Myres = 7;
        c.msg._Mysize = 0;
        c.msg._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&c.msg, v16);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      c.msgid = (int)data.msg._Bx._Ptr;
      FormChat::ChatMessage::ChatMessage((FormChat::ChatMessage *)&v18.msg, &c);
      v18.msgid = (int)&this->addedLines;
      FormChat::addMessage(this, v18, (int *)v19);
      FormChat::ChatMessage::~ChatMessage(&c);
    }
  }
  v17 = temp._Myres < 8;
  this->mustUpdate = 1;
  if ( !v17 )
    operator delete(temp._Bx._Ptr);
  temp._Myres = 7;
  temp._Mysize = 0;
  temp._Bx._Buf[0] = 0;
  FormChat::ChatMessage::~ChatMessage(&cm);
  FormChat::ChatMessage::~ChatMessage((FormChat::ChatMessage *)&data.msg);
}
void FormChat::onChatMessage(FormChat *this, const OnChatMessageEvent *message)
{
  NetCarStateProvider *v3; // eax
  int v4; // ecx
  const std::wstring *v5; // eax
  FormChat::ChatMessage c; // [esp+Ch] [ebp-70h] BYREF
  int v7; // [esp+78h] [ebp-4h]

  FormChat::ChatMessage::ChatMessage(&c);
  v7 = 0;
  v3 = ACClient::getNetCarFromSessionID(this->sim->client, message->sessionID);
  if ( v3 )
  {
    v4 = v3->guid;
    v5 = &v3->driverInfo.name;
    c.userid = v4 + 2;
    if ( &c.username != v5 )
      std::wstring::assign(&c.username, v5, 0, 0xFFFFFFFF);
  }
  else if ( message->sessionID == 255 )
  {
    c.userid = 1;
    std::wstring::assign(&c.username, L"SERVER", 6u);
  }
  else
  {
    c.userid = 0;
    std::wstring::assign(&c.username, L"Me", 2u);
  }
  if ( &c.msg != &message->message )
    std::wstring::assign(&c.msg, &message->message, 0, 0xFFFFFFFF);
  c.msgid = ++this->lastMsgID;
  std::vector<FormChat::ChatMessage>::push_back(&this->newMessages, &c);
  FormChat::ChatMessage::~ChatMessage(&c);
}
void FormChat::onMouseMove(FormChat *this, const OnMouseMoveEvent *message)
{
  this->resetVisibility = this->hitTest(this, message->x - (int)this->rect.left, message->y - (int)this->rect.top);
  ksgui::Form::onMouseMove(this, message);
}
