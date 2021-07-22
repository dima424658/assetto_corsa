#include "splashscreen.h"
void __userpurge SplashScreen::SplashScreen(SplashScreen *this@<ecx>, unsigned int a2@<ebx>, Game *igame)
{
  int v4; // eax
  double v5; // st7
  bool v6; // cf
  char v7; // al
  char v8; // bl
  Game *v9; // eax
  Texture *v10; // eax
  Game *v11; // eax
  ksgui::GUI *v12; // eax
  Game *v13; // ecx
  Font *v14; // eax
  Font *v15; // eax
  char v16; // al
  wchar_t v17; // ax
  std::wstring *v18; // esi
  Game *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  Game *v23; // eax
  int v24; // eax
  std::wstring *v25; // esi
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wstring *v28; // esi
  std::wstring *v29; // esi
  std::wstring *v30; // eax
  std::wstring *v31; // eax
  Event<double> *v32; // ecx
  std::wstring v33; // [esp-10h] [ebp-23Ch] BYREF
  int v34; // [esp+8h] [ebp-224h]
  Font *v35; // [esp+24h] [ebp-208h]
  SplashScreen *v36; // [esp+28h] [ebp-204h]
  std::wifstream is; // [esp+2Ch] [ebp-200h] BYREF
  std::wstring label; // [esp+E4h] [ebp-148h] BYREF
  std::wstring resolution; // [esp+FCh] [ebp-130h] BYREF
  std::wstring section; // [esp+114h] [ebp-118h] BYREF
  std::wstring ifilename; // [esp+12Ch] [ebp-100h] BYREF
  std::wstring v42; // [esp+144h] [ebp-E8h] BYREF
  Texture result; // [esp+15Ch] [ebp-D0h] BYREF
  std::wstring v44; // [esp+178h] [ebp-B4h] BYREF
  std::wstring v45; // [esp+190h] [ebp-9Ch] BYREF
  std::wstring v46; // [esp+1A8h] [ebp-84h] BYREF
  std::wstring v47; // [esp+1C0h] [ebp-6Ch] BYREF
  INIReader fadeINI; // [esp+1D8h] [ebp-54h] BYREF
  int v49; // [esp+228h] [ebp-4h]

  v34 = (int)igame;
  v36 = this;
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  std::wstring::assign(&v33, L"splash", 6u);
  GameObject::GameObject(this, v33, (Game *)v34);
  this->__vftable = (SplashScreen_vtbl *)&SplashScreen::`vftable';
  v49 = 0;
  this->textures._Myfirst = 0;
  this->textures._Mylast = 0;
  this->textures._Myend = 0;
  this->currentTexture = 0;
  this->masterVolume = 1.0;
  this->txLogo.kid = 0;
  this->txLogo.fileName._Myres = 7;
  this->txLogo.fileName._Mysize = 0;
  this->txLogo.fileName._Bx._Buf[0] = 0;
  this->txTrackLogo.kid = 0;
  this->txTrackLogo.fileName._Myres = 7;
  this->txTrackLogo.fileName._Mysize = 0;
  this->txTrackLogo.fileName._Bx._Buf[0] = 0;
  this->txPhysX.kid = 0;
  this->txPhysX.fileName._Myres = 7;
  this->txPhysX.fileName._Mysize = 0;
  this->txPhysX.fileName._Bx._Buf[0] = 0;
  this->messages._Myfirst = 0;
  this->messages._Mylast = 0;
  this->messages._Myend = 0;
  this->currentMessage._Myres = 7;
  this->currentMessage._Mysize = 0;
  this->currentMessage._Bx._Buf[0] = 0;
  this->hints._Myfirst = 0;
  this->hints._Mylast = 0;
  this->hints._Myend = 0;
  this->serverHints._Myfirst = 0;
  this->serverHints._Mylast = 0;
  this->serverHints._Myend = 0;
  this->car0name._Myres = 7;
  this->car0name._Mysize = 0;
  this->car0name._Bx._Buf[0] = 0;
  this->refreshThread._Thr._Id = 0;
  LOBYTE(v49) = 10;
  v4 = __Mtx_init(&this->messagesMutex._Mtx, 2);
  if ( v4 )
    std::_Throw_C_error(v4);
  LOBYTE(v49) = 11;
  this->refreshEndFlag._My_val = 0;
  v34 = 20;
  this->fadeOutMaxCounter = 0.0;
  v33._Myres = (unsigned int)L"system/cfg/fades.ini";
  this->fadeOutCounter = 0.0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v33._Myres, v34);
  LOBYTE(v49) = 12;
  INIReader::INIReader(&fadeINI, &ifilename);
  LOBYTE(v49) = 14;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( fadeINI.ready )
  {
    label._Myres = 7;
    label._Mysize = 0;
    label._Bx._Buf[0] = 0;
    std::wstring::assign(&label, L"MS", 2u);
    LOBYTE(v49) = 15;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FADE_OUT_LOADING", 0x10u);
    LOBYTE(v49) = 16;
    v5 = INIReader::getFloat(&fadeINI, &section, &label);
    v6 = section._Myres < 8;
    this->fadeOutMaxCounter = v5 * 0.001;
    if ( !v6 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v49) = 14;
    if ( label._Myres >= 8 )
      operator delete(label._Bx._Ptr);
    this->fadeOutCounter = this->fadeOutMaxCounter;
  }
  label._Myres = 7;
  label._Mysize = 0;
  label._Bx._Buf[0] = 0;
  std::wstring::assign(&label, L"content/gui/splash.png", 0x16u);
  LOBYTE(v49) = 17;
  v7 = Path::fileExists(a2, &label, 0);
  LOBYTE(v49) = 14;
  v8 = v7;
  if ( label._Myres >= 8 )
    operator delete(label._Bx._Ptr);
  if ( v8 )
  {
    label._Myres = 7;
    label._Mysize = 0;
    label._Bx._Buf[0] = 0;
    std::wstring::assign(&label, L"content/gui/splash.png", 0x16u);
    v9 = this->game;
    LOBYTE(v49) = 18;
    v10 = ResourceStore::getTexture(v9->graphics->resourceStore._Myptr, &result, &label, 0);
    LOBYTE(v49) = 19;
    std::vector<Texture>::push_back(&this->textures, v10);
    LOBYTE(v49) = 18;
    OnSetupAppCreated::~OnSetupAppCreated(&result);
    LOBYTE(v49) = 14;
    if ( label._Myres >= 8 )
      operator delete(label._Bx._Ptr);
  }
  v11 = this->game;
  this->loadedSim = 0;
  this->screenCount = 0;
  this->loader = 0;
  v12 = v11->gui;
  v34 = 24;
  v12->isActive = 0;
  this->game->isSuppressingAudioUpdate = 1;
  v13 = this->game;
  this->currentX = 0.0;
  this->oldVSync = v13->graphics->videoSettings.vSync;
  v13->graphics->videoSettings.vSync = 1;
  v14 = (Font *)operator new(v34);
  v35 = v14;
  LOBYTE(v49) = 20;
  if ( v14 )
    Font::Font(v14, eFontProportional, 14.0, 0, 0);
  else
    v15 = 0;
  v34 = 1;
  v33._Myres = 64;
  v33._Mysize = 1;
  *(_DWORD *)&v33._Bx._Alias[12] = "changelog.txt";
  LOBYTE(v49) = 14;
  this->font = v15;
  std::wifstream::wifstream(&is, *(const char **)&v33._Bx._Alias[12], v33._Mysize, v33._Myres, v34);
  LOBYTE(v49) = 21;
  v16 = std::ios_base::operator bool((char *)&is + *(_DWORD *)(*(_DWORD *)is.gap0 + 4));
  label._Myres = 7;
  label._Mysize = 0;
  if ( v16 )
  {
    label._Bx._Buf[0] = 0;
    LOBYTE(v49) = 22;
    v17 = std::wios::widen((char *)&is + *(_DWORD *)(*(_DWORD *)is.gap0 + 4), 10);
    std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&is, &label, v17);
    v18 = std::to_wstring(&v47, this->game->graphics->videoSettings.height);
    v19 = this->game;
    LOBYTE(v49) = 23;
    v20 = std::to_wstring(&v44, v19->graphics->videoSettings.width);
    LOBYTE(v49) = 24;
    v21 = std::operator+<wchar_t>(&ifilename, L" - ", v20);
    LOBYTE(v49) = 25;
    v22 = std::operator+<wchar_t>(&section, v21, L"x");
    LOBYTE(v49) = 26;
    std::operator+<wchar_t>(&resolution, v22, v18);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( ifilename._Myres >= 8 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    if ( v44._Myres >= 8 )
      operator delete(v44._Bx._Ptr);
    v44._Myres = 7;
    v44._Mysize = 0;
    v44._Bx._Buf[0] = 0;
    LOBYTE(v49) = 31;
    if ( v47._Myres >= 8 )
      operator delete(v47._Bx._Ptr);
    v47._Myres = 7;
    v47._Bx._Buf[0] = 0;
    v23 = this->game;
    v47._Mysize = 0;
    v24 = v23->graphics->videoSettings.aaSamples;
    if ( v24 <= 1 )
    {
      v29 = std::operator+<wchar_t>((std::wstring *)&result, &resolution, L" AA: OFF");
      if ( &resolution != v29 )
      {
        if ( resolution._Myres >= 8 )
          operator delete(resolution._Bx._Ptr);
        resolution._Myres = 7;
        resolution._Mysize = 0;
        resolution._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&resolution, v29);
      }
    }
    else
    {
      v25 = std::to_wstring((std::wstring *)&result, v24);
      LOBYTE(v49) = 32;
      v26 = std::operator+<wchar_t>(&v42, &resolution, L" AA: ");
      LOBYTE(v49) = 33;
      v27 = std::operator+<wchar_t>(&v46, v26, v25);
      LOBYTE(v49) = 34;
      v28 = std::operator+<wchar_t>(&v45, v27, L"X");
      if ( &resolution != v28 )
      {
        if ( resolution._Myres >= 8 )
          operator delete(resolution._Bx._Ptr);
        resolution._Myres = 7;
        resolution._Mysize = 0;
        resolution._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&resolution, v28);
      }
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
      v45._Myres = 7;
      v45._Mysize = 0;
      v45._Bx._Buf[0] = 0;
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v42._Myres = 7;
      v42._Mysize = 0;
      v42._Bx._Buf[0] = 0;
      LOBYTE(v49) = 31;
    }
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    v30 = std::operator+<wchar_t>((std::wstring *)&result, L"Assetto Corsa Steam (32bit)", &label);
    LOBYTE(v49) = 35;
    v31 = std::operator+<wchar_t>(&v42, v30, &resolution);
    LOBYTE(v49) = 36;
    std::vector<std::wstring>::push_back(&this->messages, v31);
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    if ( resolution._Myres >= 8 )
      operator delete(resolution._Bx._Ptr);
    resolution._Myres = 7;
    resolution._Mysize = 0;
    resolution._Bx._Buf[0] = 0;
  }
  else
  {
    label._Bx._Buf[0] = 0;
    std::wstring::assign(&label, L"Steam Early Access 0.2", 0x16u);
    LOBYTE(v49) = 37;
    std::vector<std::wstring>::push_back(&this->messages, &label);
  }
  LOBYTE(v49) = 21;
  if ( label._Myres >= 8 )
    operator delete(label._Bx._Ptr);
  SplashScreen::initHints(this, v8);
  v34 = (int)this;
  v33._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_ce339457d759b347ea5ace4f3121da81_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(_DWORD *)&v33._Bx._Alias[4] = this;
  v33._Mysize = (unsigned int)&v33;
  v32 = &this->game->evOnEndFrame;
  LOBYTE(v49) = 21;
  Event<float>::addHandler((Event<SessionInfo> *)v32, (std::function<void __cdecl(SessionInfo const &)>)v33, this);
  std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&is.gap64[12]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&is.gap64[12]);
  LOBYTE(v49) = 11;
  INIReader::~INIReader(&fadeINI);
}
void SplashScreen::~SplashScreen(SplashScreen *this)
{
  Font *v2; // edi
  std::vector<std::wstring> *v3; // edi
  std::vector<std::wstring> *v4; // edi
  std::vector<std::wstring> *v5; // edi

  this->__vftable = (SplashScreen_vtbl *)&SplashScreen::`vftable';
  v2 = this->font;
  if ( v2 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v2);
    operator delete(v2);
  }
  __Mtx_destroy((_Mtx_t)&this->messagesMutex);
  if ( this->refreshThread._Thr._Id )
    terminate();
  if ( this->car0name._Myres >= 8 )
    operator delete(this->car0name._Bx._Ptr);
  this->car0name._Myres = 7;
  this->car0name._Mysize = 0;
  v3 = &this->serverHints;
  this->car0name._Bx._Buf[0] = 0;
  if ( this->serverHints._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->serverHints);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v3->_Myfirst, this->serverHints._Mylast);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->serverHints._Mylast = 0;
    this->serverHints._Myend = 0;
  }
  v4 = &this->hints;
  if ( this->hints._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->hints);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v4->_Myfirst, this->hints._Mylast);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->hints._Mylast = 0;
    this->hints._Myend = 0;
  }
  if ( this->currentMessage._Myres >= 8 )
    operator delete(this->currentMessage._Bx._Ptr);
  this->currentMessage._Myres = 7;
  this->currentMessage._Mysize = 0;
  v5 = &this->messages;
  this->currentMessage._Bx._Buf[0] = 0;
  if ( this->messages._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->messages);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v5->_Myfirst, this->messages._Mylast);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->messages._Mylast = 0;
    this->messages._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->txPhysX);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txTrackLogo);
  OnSetupAppCreated::~OnSetupAppCreated(&this->txLogo);
  std::vector<Texture>::_Tidy(&this->textures);
  GameObject::~GameObject(this);
}
SplashScreen *SplashScreen::`scalar deleting destructor'(SplashScreen *this, unsigned int a2)
{
  SplashScreen::~SplashScreen(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SplashScreen::addLoadingCar(SplashScreen *this, const std::wstring *carUnixName)
{
  ;
}
void __usercall SplashScreen::initHints(SplashScreen *this@<ecx>, char a2@<bl>)
{
  bool v3; // bl
  bool v4; // bl
  std::wstring v5; // [esp-1Ch] [ebp-C8h] BYREF
  BOOL v6; // [esp-4h] [ebp-B0h]
  int v7; // [esp+Ch] [ebp-A0h]
  std::wstring key; // [esp+10h] [ebp-9Ch] BYREF
  std::wstring section; // [esp+28h] [ebp-84h] BYREF
  std::wstring carmodel; // [esp+40h] [ebp-6Ch] BYREF
  INIReaderDocuments ini; // [esp+58h] [ebp-54h] BYREF
  int v12; // [esp+A8h] [ebp-4h]

  v6 = 0;
  v7 = 0;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, v5, v6);
  v12 = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ACTIVE", 6u);
    LOBYTE(v12) = 1;
    v7 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"REMOTE", 6u);
    v12 = 2;
    v7 = 3;
    v3 = INIReader::getInt(&ini, &section, &key) || Sim::forceOnline;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v12 = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( !v3 )
    {
      std::wstring::wstring(&section, L"ACTIVE");
      LOBYTE(v12) = 3;
      std::wstring::wstring(&key, L"REPLAY");
      LOBYTE(v12) = 4;
      v4 = INIReader::getInt(&ini, &key, &section) != 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v12) = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      if ( !v4 )
      {
        std::wstring::wstring(&section, L"MODEL");
        LOBYTE(v12) = 5;
        std::wstring::wstring(&key, L"RACE");
        LOBYTE(v12) = 6;
        INIReader::getString(&ini, &carmodel, &key, &section);
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        LOBYTE(v12) = 9;
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Bx._Buf[0] = 0;
        section._Mysize = 0;
        SplashScreen::loadHints(this, v4, &carmodel);
        if ( carmodel._Myres >= 8 )
          operator delete(carmodel._Bx._Ptr);
        carmodel._Myres = 7;
        carmodel._Mysize = 0;
        carmodel._Bx._Buf[0] = 0;
      }
    }
  }
  v12 = -1;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
void __userpurge SplashScreen::loadHints(SplashScreen *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *carmodel)
{
  std::wstring *v4; // esi
  std::wstring *v5; // eax
  Texture *v6; // eax
  void *v7; // ecx
  std::wstring *v8; // eax
  std::wstring *v9; // ecx
  std::vector<std::wstring> *v10; // eax
  std::wstring *v11; // edi
  Texture v12; // [esp+14h] [ebp-B0h] BYREF
  std::wstring _Left; // [esp+30h] [ebp-94h] BYREF
  std::wstring v14; // [esp+48h] [ebp-7Ch] BYREF
  std::wstring result; // [esp+60h] [ebp-64h] BYREF
  std::wstring car_logo_filename; // [esp+78h] [ebp-4Ch] BYREF
  CarHintLoader hl; // [esp+90h] [ebp-34h] BYREF
  int v18; // [esp+C0h] [ebp-4h]

  v4 = &this->car0name;
  if ( &this->car0name != carmodel )
    std::wstring::assign(&this->car0name, carmodel, 0, 0xFFFFFFFF);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v18 = 0;
  v5 = std::operator+<wchar_t>(&result, &_Left, v4);
  LOBYTE(v18) = 1;
  std::operator+<wchar_t>(&car_logo_filename, v5, L"/logo.png");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v18) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  _Left._Mysize = 0;
  if ( Path::fileExists(a2, &car_logo_filename, 0) )
  {
    v6 = ResourceStore::getTexture(this->game->graphics->resourceStore._Myptr, &v12, &car_logo_filename, 0);
    v7 = v6->kid;
    v8 = &v6->fileName;
    this->txLogo.kid = v7;
    v9 = &this->txLogo.fileName;
    LOBYTE(v18) = 5;
    if ( &this->txLogo.fileName == v8 )
      goto LABEL_12;
  }
  else
  {
    v12.kid = 0;
    v12.fileName._Myres = 7;
    v12.fileName._Mysize = 0;
    v12.fileName._Bx._Buf[0] = 0;
    this->txLogo.kid = 0;
    v9 = &this->txLogo.fileName;
    v8 = &v12.fileName;
    LOBYTE(v18) = 6;
    if ( &this->txLogo.fileName == &v12.fileName )
      goto LABEL_12;
  }
  std::wstring::assign(v9, v8, 0, 0xFFFFFFFF);
LABEL_12:
  LOBYTE(v18) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&v12);
  v12.fileName._Mysize = 7;
  *(_DWORD *)&v12.fileName._Bx._Alias[12] = 0;
  LOWORD(v12.kid) = 0;
  std::wstring::assign((std::wstring *)&v12, word_17BE9D8, 0);
  LOBYTE(v18) = 7;
  CarHintLoader::CarHintLoader(&hl, v4, (const std::wstring *)&v12);
  LOBYTE(v18) = 9;
  if ( v12.fileName._Mysize >= 8 )
    operator delete(v12.kid);
  v12.fileName._Mysize = 7;
  LOWORD(v12.kid) = 0;
  *(_DWORD *)&v12.fileName._Bx._Alias[12] = 0;
  v10 = CarHintLoader::getHints(&hl, (std::vector<std::wstring> *)&v14);
  LOBYTE(v18) = 10;
  std::vector<std::wstring>::operator=(&this->hints, v10);
  LOBYTE(v18) = 9;
  if ( v14._Bx._Ptr )
  {
    std::_Container_base0::_Orphan_all(&v14);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(
      (std::wstring *)v14._Bx._Ptr,
      *(std::wstring **)&v14._Bx._Alias[4]);
    operator delete(v14._Bx._Ptr);
  }
  v11 = CarHintLoader::getCarName(&hl, &v14);
  if ( v4 != v11 )
  {
    if ( v4->_Myres >= 8 )
      operator delete(v4->_Bx._Ptr);
    v4->_Myres = 7;
    v4->_Mysize = 0;
    v4->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(v4, v11);
  }
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
  LOBYTE(v18) = 4;
  CarHintLoader::~CarHintLoader(&hl);
  if ( car_logo_filename._Myres >= 8 )
    operator delete(car_logo_filename._Bx._Ptr);
}
void __userpurge SplashScreen::postRender(SplashScreen *this@<ecx>, unsigned int a2@<ebx>, int a3@<esi>, __m128 a4@<xmm3>, __m128 a5@<xmm4>, float deltaT)
{
  double v7; // st7
  std::_Func_base<void> *v8; // ecx
  Game *v9; // ecx
  ICollisionObject *v10; // eax
  int v11; // eax
  int v12; // ebx
  Game *v13; // eax
  GameObject *v14; // esi
  double v15; // st7
  std::function<void __cdecl(void)> v16; // [esp-10h] [ebp-48h] BYREF
  char v17; // [esp+1Fh] [ebp-19h] BYREF
  ICollisionObject *_Val; // [esp+20h] [ebp-18h] BYREF
  double v19; // [esp+24h] [ebp-14h]
  int v20; // [esp+34h] [ebp-4h]

  if ( this->screenCount >= 1 && !this->loadedSim )
  {
    v7 = AudioEngine::getVolume(this->game->audioEngine, 1);
    (&v16._Impl)[1] = v8;
    v9 = this->game;
    this->masterVolume = v7;
    AudioEngine::setVolume(v9->audioEngine, a3, 0.0);
    v19 = ksGetTime();
    v10 = (ICollisionObject *)operator new(388);
    _Val = v10;
    v20 = 0;
    if ( v10 )
    {
      Sim::Sim((Sim *)v10, a2, a4, a5, this->game);
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    v13 = this->game;
    v20 = -1;
    _Val = (ICollisionObject *)v12;
    v14 = v13->root;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&v14->gameObjects, &_Val);
    *(_DWORD *)(v12 + 36) = v14;
    *(_BYTE *)(v12 + 32) = 1;
    this->game->gui->isActive = 1;
    this->game->graphics->videoSettings.vSync = this->oldVSync;
    Sim::onPostLoad((Sim *)v12);
    this->loadedSim = 1;
    std::_Container_base0::_Orphan_all(&this->messages);
    (&v16._Impl)[1] = (std::_Func_base<void> *)_Val;
    v16._Impl = (std::_Func_base<void> *)&v17;
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(this->messages._Myfirst, this->messages._Mylast);
    this->messages._Mylast = this->messages._Myfirst;
    this->game->isSuppressingAudioUpdate = 0;
    v16._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_1213171aa219c38b7d20c3b5d349fb43_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    v16._Space._Pfn[1] = (void (__cdecl *)())this;
    v16._Impl = (std::_Func_base<void> *)&v16;
    v20 = -1;
    Sim::executeOnMainThread((Sim *)v12, v16);
    v15 = ksGetTime();
    _printf("TIME TO INIT: %f\n", v15 - v19);
  }
}
void SplashScreen::renderHUD(SplashScreen *this, float deltaT)
{
  int v3; // edi
  Texture *v4; // eax
  const Texture *v5; // esi
  GraphicsManager *v6; // ecx
  GLRenderer *v7; // ebx
  float v8; // xmm0_4
  float *v9; // eax
  unsigned int v10; // ecx
  void *v11; // eax
  unsigned int v12; // ecx
  float v13; // xmm0_4
  unsigned int v14; // edi
  unsigned int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  bool v18; // zf
  float v19; // xmm0_4
  float v20; // xmm1_4
  Texture *v21; // esi
  unsigned int v22; // eax
  GraphicsManager *v23; // ecx
  unsigned int v24; // edi
  unsigned int v25; // eax
  float v26; // xmm0_4
  float v27; // xmm0_4
  Texture *v28; // esi
  unsigned int v29; // ecx
  void *v30; // eax
  unsigned int v31; // edi
  unsigned int v32; // eax
  float v33; // xmm0_4
  float v34; // xmm0_4
  Font *v35; // ecx
  int v36; // eax
  std::wstring *v37; // edi
  std::wstring *v38; // esi
  float v39; // xmm0_4
  int v40; // eax
  Font *v41; // ecx
  std::wstring *v42; // edi
  std::wstring *v43; // esi
  float v44; // xmm0_4
  std::wstring *v45; // edi
  std::wstring *v46; // esi
  float v47; // xmm0_4
  float v48; // xmm0_4
  float g; // [esp+Ch] [ebp-44h]
  float ga; // [esp+Ch] [ebp-44h]
  float gb; // [esp+Ch] [ebp-44h]
  float x; // [esp+2Ch] [ebp-24h] BYREF
  std::lock_guard<std::mutex> lock; // [esp+30h] [ebp-20h] BYREF
  vec4f cc; // [esp+34h] [ebp-1Ch] BYREF
  int v55; // [esp+4Ch] [ebp-4h]
  float deltaTa; // [esp+54h] [ebp+4h]
  float deltaTb; // [esp+54h] [ebp+4h]
  float deltaTc; // [esp+54h] [ebp+4h]

  v3 = this->currentTexture;
  v4 = this->textures._Myfirst;
  v5 = &v4[v3];
  if ( !this->loadedSim )
    this->currentTexture = (v3 + 1) % (unsigned int)(this->textures._Mylast - v4);
  GraphicsManager::setScreenRenderTargets(this->game->graphics);
  v6 = this->game->graphics;
  v7 = v6->gl;
  GraphicsManager::setDepthMode(v6, eDepthOff);
  GraphicsManager::setTexture(this->game->graphics, 0, v5);
  GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
  v8 = this->fadeOutCounter / this->fadeOutMaxCounter;
  v9 = &x;
  *(float *)&lock._MyMutex = 0.0;
  x = v8;
  if ( v8 <= 0.0 )
    v9 = (float *)&lock;
  GLRenderer::color4f(v7, 0.1, 0.1, 0.1, *v9);
  GLRenderer::quad(
    v7,
    0.0,
    0.0,
    (float)this->game->graphics->videoSettings.width,
    (float)this->game->graphics->videoSettings.height,
    0,
    0);
  if ( v5->kid )
    v10 = kglTextureGetWidth(v5->kid);
  else
    v10 = 0;
  v11 = v5->kid;
  x = (double)((this->game->graphics->videoSettings.width - v10) >> 1) + 0.0;
  if ( v11 )
    v12 = kglTextureGetHeight(v11);
  else
    v12 = 0;
  v13 = (float)(this->game->graphics->videoSettings.height / 2 - (v12 >> 1));
  *(float *)&lock._MyMutex = v13;
  GLRenderer::color4f(v7, 1.0, 1.0, 1.0, this->fadeOutCounter / this->fadeOutMaxCounter);
  if ( v5->kid )
    v14 = kglTextureGetHeight(v5->kid);
  else
    v14 = 0;
  if ( v5->kid )
    v15 = kglTextureGetWidth(v5->kid);
  else
    v15 = 0;
  v16 = (float)v14;
  g = v16;
  v17 = (float)v15;
  GLRenderer::quad(v7, x, *(float *)&lock._MyMutex, v17, g, 1, 0);
  Font::blitString(
    this->font,
    (float)(this->game->graphics->videoSettings.width / 2),
    (float)this->game->graphics->videoSettings.height - 20.0,
    &this->currentMessage,
    1.0,
    eAlignCenter);
  v18 = !this->loadedSim;
  v19 = (float)((float)this->game->graphics->videoSettings.height * 0.33333334) * 2.0;
  x = (float)(this->game->graphics->videoSettings.width / 2);
  *(float *)&lock._MyMutex = v19;
  if ( !v18 )
  {
    v20 = deltaT;
    if ( deltaT > 0.1 )
      v20 = FLOAT_0_1;
    this->fadeOutCounter = this->fadeOutCounter - v20;
  }
  if ( this->fadeOutCounter < 0.0 )
    this->isActive = 0;
  v21 = &this->txTrackLogo;
  if ( this->txTrackLogo.kid )
  {
    v22 = kglTextureGetWidth(v21->kid);
    v23 = this->game->graphics;
    x = (float)(x + 200.0) - (float)((double)(v22 >> 1) + 0.0);
    GraphicsManager::setTexture(v23, 0, &this->txTrackLogo);
    if ( v21->kid )
      v24 = kglTextureGetHeight(v21->kid);
    else
      v24 = 0;
    if ( v21->kid )
      v25 = kglTextureGetWidth(v21->kid);
    else
      v25 = 0;
    v26 = (float)v24;
    ga = v26;
    v27 = (float)v25;
    GLRenderer::quad(v7, x, *(float *)&lock._MyMutex, v27, ga, 1, 0);
  }
  v28 = &this->txLogo;
  deltaTa = (float)this->game->graphics->videoSettings.height - 200.0;
  if ( this->txLogo.kid )
  {
    GraphicsManager::setTexture(this->game->graphics, 0, &this->txLogo);
    if ( v28->kid )
      v29 = kglTextureGetWidth(v28->kid);
    else
      v29 = 0;
    v30 = v28->kid;
    *(float *)&lock._MyMutex = (float)(this->game->graphics->videoSettings.width - v29) - 500.0;
    if ( v30 )
      v31 = kglTextureGetHeight(v30);
    else
      v31 = 0;
    if ( v28->kid )
      v32 = kglTextureGetWidth(v28->kid);
    else
      v32 = 0;
    v33 = (float)v31;
    gb = v33;
    v34 = (float)v32;
    GLRenderer::quad(v7, *(float *)&lock._MyMutex, deltaTa, v34, gb, 1, 0);
  }
  v35 = this->font;
  x = (float)(this->game->graphics->videoSettings.height - 14);
  cc = (vec4f)_xmm;
  Font::setColor(v35, &cc);
  lock._MyMutex = &this->messagesMutex;
  v36 = __Mtx_lock((_Mtx_t)&this->messagesMutex);
  if ( v36 )
    std::_Throw_C_error(v36);
  v37 = this->messages._Mylast;
  v38 = this->messages._Myfirst;
  v55 = 0;
  if ( v38 != v37 )
  {
    v39 = x;
    do
    {
      Font::blitString(this->font, 0.0, v39, v38++, 0.69999999, eAlignLeft);
      v39 = x + 20.0;
      x = x + 20.0;
    }
    while ( v38 != v37 );
  }
  v55 = -1;
  v40 = __Mtx_unlock((_Mtx_t)&this->messagesMutex);
  if ( v40 )
    std::_Throw_C_error(v40);
  Font::setColor(this->font, 1.0, 1.0, 1.0, 1.0);
  v41 = this->font;
  *(float *)&lock._MyMutex = (float)this->game->graphics->videoSettings.width - 20.0;
  Font::blitString(v41, *(float *)&lock._MyMutex, deltaTa, &this->car0name, 2.0, eAlignRight);
  deltaTb = deltaTa + 40.0;
  Font::setColor(this->font, 0.69999999, 0.69999999, 0.69999999, 1.0);
  v42 = this->hints._Mylast;
  v43 = this->hints._Myfirst;
  if ( v43 != v42 )
  {
    v44 = deltaTb;
    do
    {
      Font::blitString(this->font, *(float *)&lock._MyMutex, v44, v43++, 1.0, eAlignRight);
      v44 = deltaTb + 20.0;
      deltaTb = deltaTb + 20.0;
    }
    while ( v43 != v42 );
  }
  deltaTc = (float)this->game->graphics->videoSettings.height - 250.0;
  Font::setColor(this->font, 1.0, 1.0, 1.0, 1.0);
  Font::setColor(this->font, 0.69999999, 0.69999999, 0.69999999, 1.0);
  v45 = this->serverHints._Mylast;
  v46 = this->serverHints._Myfirst;
  if ( v46 != v45 )
  {
    v47 = deltaTc;
    do
    {
      Font::blitString(this->font, 20.0, v47, v46++, 1.0, eAlignLeft);
      v47 = deltaTc + 20.0;
      deltaTc = deltaTc + 20.0;
    }
    while ( v46 != v45 );
  }
  Font::setColor(this->font, 1.0, 1.0, 1.0, 1.0);
  ++this->screenCount;
  if ( this->loadedSim )
  {
    v48 = this->fadeOutCounter / this->fadeOutMaxCounter;
    if ( v48 <= 1.0 )
    {
      if ( v48 < 0.0 )
        v48 = 0.0;
    }
    else
    {
      v48 = FLOAT_1_0;
    }
    AudioEngine::setVolume(this->game->audioEngine, (int)v46, (float)(1.0 - v48) * this->masterVolume);
  }
}
void SplashScreen::setCurrentMessage(SplashScreen *this, const std::wstring *msg)
{
  std::wstring *v3; // edx
  std::vector<std::wstring> *v4; // ecx
  unsigned int v5; // edx

  v3 = this->messages._Mylast;
  v4 = &this->messages;
  v5 = (int)((unsigned __int64)(715827883i64 * ((char *)v3 - (char *)v4->_Myfirst)) >> 32) >> 2;
  if ( v5 + (v5 >> 31) )
  {
    if ( &this->currentMessage != msg )
      std::wstring::assign(&this->currentMessage, msg, 0, 0xFFFFFFFF);
  }
  else
  {
    std::vector<std::wstring>::push_back(v4, msg);
  }
  ((void (*)(SplashScreen *, int))this->renderHUD)(this, 1065353216);
  GraphicsManager::endScene(this->game->graphics);
}
void __userpurge SplashScreen::setOnlinePlayerCar(SplashScreen *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *model, const std::wstring *config)
{
  SplashScreen::loadHints(this, a2, model);
  ((void (*)(SplashScreen *, int))this->renderHUD)(this, 1065353216);
  GraphicsManager::endScene(this->game->graphics);
}
void SplashScreen::setServerHints(SplashScreen *this, const std::vector<std::wstring> *ihints)
{
  std::vector<std::wstring>::operator=(&this->serverHints, ihints);
  ((void (*)(SplashScreen *, int))this->renderHUD)(this, 1065353216);
  GraphicsManager::endScene(this->game->graphics);
}
