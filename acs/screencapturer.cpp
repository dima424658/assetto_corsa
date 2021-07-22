#include "screencapturer.h"
void ScreenCapturer::ScreenCapturer(ScreenCapturer *this, std::wstring name, Sim *aSim)
{
  Sim *v4; // esi
  Sim *v5; // eax
  bool v6; // bl
  std::wstring *v7; // eax
  bool v8; // bl
  std::wstring *v9; // eax
  bool v10; // bl
  std::wstring *v11; // eax
  bool v12; // bl
  std::wstring v13; // [esp-1Ch] [ebp-F0h] BYREF
  int v14; // [esp-4h] [ebp-D8h]
  int v15; // [esp+14h] [ebp-C0h]
  ScreenCapturer *v16; // [esp+1Ch] [ebp-B8h]
  std::wstring section; // [esp+20h] [ebp-B4h] BYREF
  std::wstring key; // [esp+38h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+50h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+68h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+80h] [ebp-54h] BYREF
  int v22; // [esp+D0h] [ebp-4h]

  v4 = aSim;
  v16 = this;
  v15 = 0;
  v14 = (int)aSim->game;
  v22 = 0;
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  std::wstring::assign(&v13, &name, 0, 0xFFFFFFFF);
  GameObject::GameObject(this, v13, (Game *)v14);
  this->__vftable = (ScreenCapturer_vtbl *)&ScreenCapturer::`vftable';
  this->currentScreenshotName._Myres = 7;
  this->currentScreenshotName._Mysize = 0;
  this->currentScreenshotName._Bx._Buf[0] = 0;
  this->userPath._Myres = 7;
  this->userPath._Mysize = 0;
  this->userPath._Bx._Buf[0] = 0;
  v14 = (int)this;
  this->frameSkip = 0;
  this->flashTime = 0.0;
  this->readyToCapture = 0;
  this->imageFormat = 1;
  this->sim = v4;
  v13._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_e4a56bf8fb7b4d6c518f597aa74e8bf0_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
  *(_DWORD *)&v13._Bx._Alias[4] = this;
  v13._Mysize = (unsigned int)&v13;
  v5 = this->sim;
  LOBYTE(v22) = 3;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v5->game->evOnPreGUI,
    (std::function<void __cdecl(SessionInfo const &)>)v13,
    (void *)v14);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v22) = 5;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v22) = 7;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  v6 = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SCREENSHOT", 0xAu);
    LOBYTE(v22) = 8;
    v15 = 1;
    if ( INIReader::hasSection(&ini, &section) )
      v6 = 1;
  }
  v22 = 7;
  if ( (v15 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v6 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FORMAT", 6u);
    LOBYTE(v22) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SCREENSHOT", 0xAu);
    LOBYTE(v22) = 10;
    v7 = INIReader::getString(&ini, &result, &section, &key);
    v14 = 3;
    v13._Myres = (unsigned int)L"PNG";
    v13._Mysize = v7->_Mysize;
    LOBYTE(v22) = 11;
    v8 = std::wstring::compare(v7, 0, v13._Mysize, L"PNG", 3u) == 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v22) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v8 )
      this->imageFormat = 1;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FORMAT", 6u);
    LOBYTE(v22) = 12;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SCREENSHOT", 0xAu);
    LOBYTE(v22) = 13;
    v9 = INIReader::getString(&ini, &result, &section, &key);
    v14 = 3;
    v13._Myres = (unsigned int)L"JPG";
    v13._Mysize = v9->_Mysize;
    LOBYTE(v22) = 14;
    v10 = std::wstring::compare(v9, 0, v13._Mysize, L"JPG", 3u) == 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v22) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v10 )
      this->imageFormat = 0;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FORMAT", 6u);
    LOBYTE(v22) = 15;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SCREENSHOT", 0xAu);
    LOBYTE(v22) = 16;
    v11 = INIReader::getString(&ini, &result, &section, &key);
    v14 = 3;
    v13._Myres = (unsigned int)L"BMP";
    v13._Mysize = v11->_Mysize;
    LOBYTE(v22) = 17;
    v12 = std::wstring::compare(v11, 0, v13._Mysize, L"BMP", 3u) == 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v12 )
      this->imageFormat = 2;
  }
  LOBYTE(v22) = 3;
  INIReader::~INIReader(&ini);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void ScreenCapturer::~ScreenCapturer(ScreenCapturer *this)
{
  this->__vftable = (ScreenCapturer_vtbl *)&ScreenCapturer::`vftable';
  if ( this->userPath._Myres >= 8 )
    operator delete(this->userPath._Bx._Ptr);
  this->userPath._Myres = 7;
  this->userPath._Mysize = 0;
  this->userPath._Bx._Buf[0] = 0;
  if ( this->currentScreenshotName._Myres >= 8 )
    operator delete(this->currentScreenshotName._Bx._Ptr);
  this->currentScreenshotName._Myres = 7;
  this->currentScreenshotName._Mysize = 0;
  this->currentScreenshotName._Bx._Buf[0] = 0;
  GameObject::~GameObject(this);
}
ScreenCapturer *ScreenCapturer::`scalar deleting destructor'(ScreenCapturer *this, unsigned int a2)
{
  ScreenCapturer::~ScreenCapturer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
std::wstring *ScreenCapturer::getPath(ScreenCapturer *this, std::wstring *result)
{
  std::wstring *v3; // eax
  struct tm *v4; // eax
  struct tm *v5; // esi
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  std::wostream *v8; // eax
  std::wostream *v9; // eax
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  Sim *v16; // ecx
  CarAvatar *v17; // eax
  const std::wstring *v18; // eax
  TrackAvatar *v19; // eax
  const std::wstring *v20; // eax
  unsigned int v21; // eax
  std::wstring *v22; // eax
  const std::wstring *v23; // eax
  std::wstring *v24; // eax
  const std::wstring *v25; // eax
  std::wstring *v26; // eax
  const std::wstring *v27; // eax
  std::wstring *v28; // ecx
  std::wstring *v29; // eax
  const char *v31; // [esp-10h] [ebp-1FCh]
  const char *v32; // [esp-Ch] [ebp-1F8h]
  int v33; // [esp-8h] [ebp-1F4h]
  const char *v34; // [esp-8h] [ebp-1F4h]
  const char *v35; // [esp-4h] [ebp-1F0h]
  int v36; // [esp+0h] [ebp-1ECh]
  const char *v37; // [esp+0h] [ebp-1ECh]
  __int64 now; // [esp+1Ch] [ebp-1D0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v39; // [esp+24h] [ebp-1C8h] BYREF
  std::wstring filename; // [esp+D4h] [ebp-118h] BYREF
  std::wstring wFilename; // [esp+ECh] [ebp-100h] BYREF
  std::wstring v42; // [esp+104h] [ebp-E8h] BYREF
  std::wstring folder; // [esp+11Ch] [ebp-D0h] BYREF
  std::wstring string_s; // [esp+134h] [ebp-B8h] BYREF
  std::wstring v45; // [esp+14Ch] [ebp-A0h] BYREF
  std::wstring v46; // [esp+164h] [ebp-88h] BYREF
  std::wstring v47; // [esp+17Ch] [ebp-70h] BYREF
  std::wstring v48; // [esp+194h] [ebp-58h] BYREF
  std::wstring v49; // [esp+1ACh] [ebp-40h] BYREF
  std::wstring v50; // [esp+1C4h] [ebp-28h] BYREF
  int v51; // [esp+1E8h] [ebp-4h]

  string_s._Myres = 7;
  string_s._Mysize = 0;
  string_s._Bx._Buf[0] = 0;
  std::wstring::assign(&string_s, L"\\Assetto Corsa\\screens\\", 0x17u);
  v51 = 0;
  v3 = Path::getDocumentPath(&v45);
  LOBYTE(v51) = 1;
  std::operator+<wchar_t>(&folder, v3, &string_s);
  LOBYTE(v51) = 3;
  if ( v45._Myres >= 8 )
    operator delete(v45._Bx._Ptr);
  v45._Myres = 7;
  v45._Bx._Buf[0] = 0;
  v45._Mysize = 0;
  Path::createFolder(&folder);
  now = __time64(0);
  v4 = __localtime64(&now);
  *(_DWORD *)v39.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v39.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  v5 = v4;
  std::wios::wios(v39.gap68);
  HIDWORD(v39._Chcount) = 2;
  std::wiostream::basic_iostream<wchar_t>(&v39.gap10[8], &v39.gap10[32], 0);
  *(_DWORD *)&v39.gap10[*(_DWORD *)(*(_DWORD *)&v39.gap10[8] + 4) + 8] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v39.gap10[*(_DWORD *)(*(_DWORD *)&v39.gap10[8] + 4) + 4] = *(_DWORD *)(*(_DWORD *)&v39.gap10[8] + 4) - 104;
  std::wstreambuf::wstreambuf(&v39.gap10[32]);
  *(_DWORD *)&v39.gap10[32] = &std::wstringbuf::`vftable';
  *(_DWORD *)v39.gap68 = 0;
  *(_DWORD *)&v39.gap68[4] = 0;
  v36 = v5->tm_year;
  v33 = v5->tm_mon + 1;
  v6 = (std::wostream *)std::wostream::operator<<(&v39.gap10[24], v5->tm_mday);
  v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, v31);
  v8 = (std::wostream *)std::wostream::operator<<(v7, "-");
  v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v8, v32);
  v10 = (std::wostream *)std::wostream::operator<<(v9, v33);
  v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v10, v34);
  v12 = (std::wostream *)std::wostream::operator<<(v11, "-");
  v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v12, v35);
  v14 = (std::wostream *)std::wostream::operator<<(v13, v36);
  v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v14, v37);
  std::wostream::operator<<(v15, "-");
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"Screenshot_", 0xBu);
  v16 = this->sim;
  LOBYTE(v51) = 8;
  if ( Sim::getCar(v16, 0) )
  {
    v17 = Sim::getCar(this->sim, 0);
    v18 = std::operator+<wchar_t>(&v42, &v17->unixName, L"_");
    LOBYTE(v51) = 9;
    std::wstring::append(&filename, v18, 0, 0xFFFFFFFF);
    LOBYTE(v51) = 8;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
  }
  v19 = this->sim->track;
  if ( v19 )
  {
    v20 = std::operator+<wchar_t>(&v42, &v19->name, L"_");
    LOBYTE(v51) = 10;
    std::wstring::append(&filename, v20, 0, 0xFFFFFFFF);
    LOBYTE(v51) = 8;
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
  }
  v21 = this->imageFormat;
  if ( v21 )
  {
    if ( v21 == 2 )
    {
      v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v48);
      LOBYTE(v51) = 11;
      v25 = std::operator+<wchar_t>(&v46, v24, L".bmp");
      LOBYTE(v51) = 12;
      std::wstring::append(&filename, v25, 0, 0xFFFFFFFF);
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      if ( v48._Myres >= 8 )
        operator delete(v48._Bx._Ptr);
    }
    else
    {
      v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v50);
      LOBYTE(v51) = 15;
      v23 = std::operator+<wchar_t>(&v47, v22, L".jpg");
      LOBYTE(v51) = 16;
      std::wstring::append(&filename, v23, 0, 0xFFFFFFFF);
      if ( v47._Myres >= 8 )
        operator delete(v47._Bx._Ptr);
      v47._Myres = 7;
      v47._Mysize = 0;
      v47._Bx._Buf[0] = 0;
      if ( v50._Myres >= 8 )
        operator delete(v50._Bx._Ptr);
    }
  }
  else
  {
    v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v39, &v49);
    LOBYTE(v51) = 13;
    v27 = std::operator+<wchar_t>(&v42, v26, L".jpg");
    LOBYTE(v51) = 14;
    std::wstring::append(&filename, v27, 0, 0xFFFFFFFF);
    if ( v42._Myres >= 8 )
      operator delete(v42._Bx._Ptr);
    v42._Myres = 7;
    v42._Mysize = 0;
    v42._Bx._Buf[0] = 0;
    if ( v49._Myres >= 8 )
      operator delete(v49._Bx._Ptr);
  }
  wFilename._Myres = 7;
  wFilename._Mysize = 0;
  wFilename._Bx._Buf[0] = 0;
  v28 = &filename;
  if ( filename._Myres >= 8 )
    v28 = (std::wstring *)filename._Bx._Ptr;
  LOBYTE(v51) = 17;
  v29 = &filename;
  if ( filename._Myres >= 8 )
    v29 = (std::wstring *)filename._Bx._Ptr;
  std::wstring::replace(
    &wFilename,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&wFilename,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&wFilename,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v29,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)((char *)v28 + 2 * filename._Mysize));
  std::operator+<wchar_t>(result, &folder, &wFilename);
  if ( wFilename._Myres >= 8 )
    operator delete(wFilename._Bx._Ptr);
  wFilename._Myres = 7;
  wFilename._Mysize = 0;
  wFilename._Bx._Buf[0] = 0;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Bx._Buf[0] = 0;
  filename._Mysize = 0;
  LOBYTE(v51) = 3;
  *(_DWORD *)&v39.gap0[*(_DWORD *)(*(_DWORD *)v39.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&now + *(_DWORD *)(*(_DWORD *)v39.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v39.gap0 + 4) - 104;
  *(_DWORD *)&v39.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v39.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v39.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v39.gap68);
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
  folder._Myres = 7;
  folder._Mysize = 0;
  folder._Bx._Buf[0] = 0;
  if ( string_s._Myres >= 8 )
    operator delete(string_s._Bx._Ptr);
  return result;
}
void ScreenCapturer::renderHUD(ScreenCapturer *this, float dt)
{
  float *v3; // ebx
  Sim *v4; // eax
  float v5; // xmm0_4
  GLRenderer *v6; // esi
  float *v7; // eax
  Sim *v8; // eax
  int v9; // [esp+24h] [ebp-84h] BYREF
  mat44f vM; // [esp+28h] [ebp-80h] BYREF
  mat44f pM; // [esp+68h] [ebp-40h] BYREF

  v3 = &this->flashTime;
  if ( this->flashTime > 0.0 )
  {
    GraphicsManager::getViewMatrix(this->sim->game->graphics, &vM);
    GraphicsManager::getProjectionMatrix(this->sim->game->graphics, &pM);
    GraphicsManager::setDepthMode(this->sim->game->graphics, eDepthOff);
    GraphicsManager::setScreenSpaceMode(this->sim->game->graphics);
    GraphicsManager::setBlendMode(this->sim->game->graphics, eAlphaBlend);
    v4 = this->sim;
    v5 = *v3;
    v9 = 0;
    v6 = v4->game->graphics->gl;
    v7 = (float *)&v9;
    if ( v5 > 0.0 )
      v7 = v3;
    GLRenderer::color4f(v6, 3.0, 3.0, 3.0, *v7);
    GLRenderer::quad(
      v6,
      0.0,
      0.0,
      (float)this->sim->game->graphics->videoSettings.width,
      (float)this->sim->game->graphics->videoSettings.height,
      0,
      0);
    v8 = this->sim;
    *v3 = *v3 - dt;
    GraphicsManager::setDepthMode(v8->game->graphics, eDepthNormal);
    GraphicsManager::setViewMatrix(this->sim->game->graphics, &vM, 0);
    GraphicsManager::setProjectionMatrix(this->sim->game->graphics, &pM);
  }
}
void ScreenCapturer::saveScreen(ScreenCapturer *this)
{
  std::wstring *v2; // edi
  std::wstring *v3; // eax
  int v4; // [esp+0h] [ebp-4Ch]
  std::wstring path; // [esp+Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+24h] [ebp-28h] BYREF
  int v7; // [esp+48h] [ebp-4h]

  path._Myres = 7;
  path._Bx._Buf[0] = 0;
  path._Mysize = 0;
  std::wstring::assign(&path, &this->userPath, 0, 0xFFFFFFFF);
  v7 = 0;
  if ( !path._Mysize )
  {
    v2 = ScreenCapturer::getPath(this, &result);
    if ( &path != v2 )
    {
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
      path._Myres = 7;
      path._Mysize = 0;
      path._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&path, v2);
    }
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v3 = &path;
  if ( path._Myres >= 8 )
    v3 = (std::wstring *)path._Bx._Ptr;
  kglSaveScreenCapture(v3->_Bx._Buf, this->imageFormat, v4);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
}
void ScreenCapturer::takeScreen(ScreenCapturer *this, const std::wstring *path)
{
  std::wstring *v3; // ecx

  v3 = &this->userPath;
  if ( v3 != path )
    std::wstring::assign(v3, path, 0, 0xFFFFFFFF);
  if ( this->flashTime <= 0.0 )
    this->readyToCapture = 1;
}
