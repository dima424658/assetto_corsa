#include "path.h"
void __cdecl Path::createFolder(const std::wstring *folder)
{
  const std::wstring *v1; // esi
  const std::wstring *v2; // eax
  DWORD v3; // eax

  v1 = folder;
  if ( folder->_Myres < 8 )
    v2 = folder;
  else
    v2 = (const std::wstring *)folder->_Bx._Ptr;
  v3 = GetFileAttributesW(v2->_Bx._Buf);
  if ( v3 == -1 || (v3 & 0x10) == 0 )
  {
    if ( folder->_Myres >= 8 )
      v1 = (const std::wstring *)folder->_Bx._Ptr;
    CreateDirectoryW(v1->_Bx._Buf, 0);
  }
}
void __cdecl Path::deleteFile(const std::wstring *path)
{
  const std::wstring *v1; // eax

  v1 = path;
  if ( path->_Myres >= 8 )
    v1 = (const std::wstring *)path->_Bx._Ptr;
  DeleteFileW(v1->_Bx._Buf);
}
char __cdecl Path::doesFilenameContainsIllegalChar(const std::wstring *filenameToCheck)
{
  unsigned int v1; // ecx
  const std::wstring *v2; // esi
  const std::wstring *v3; // ecx
  const std::wstring *v4; // edi
  char v5; // bl
  wchar_t _Ptr[2]; // [esp+Ch] [ebp-20h] BYREF
  std::wstring illegalChars; // [esp+10h] [ebp-1Ch] BYREF

  illegalChars._Myres = 7;
  illegalChars._Mysize = 0;
  illegalChars._Bx._Buf[0] = 0;
  std::wstring::assign(&illegalChars, L"\\/:?\"<>|*%$", 0xBu);
  v1 = filenameToCheck->_Myres;
  if ( v1 < 8 )
    v2 = filenameToCheck;
  else
    v2 = (const std::wstring *)filenameToCheck->_Bx._Ptr;
  if ( v1 < 8 )
    v3 = filenameToCheck;
  else
    v3 = (const std::wstring *)filenameToCheck->_Bx._Ptr;
  v4 = (const std::wstring *)((char *)v3 + 2 * filenameToCheck->_Mysize);
  if ( v2 == v4 )
  {
LABEL_10:
    v5 = 0;
  }
  else
  {
    while ( 1 )
    {
      *(_DWORD *)_Ptr = v2->_Bx._Buf[0];
      if ( std::wstring::find(&illegalChars, _Ptr, 0, 1u) != -1 )
        break;
      v2 = (const std::wstring *)((char *)v2 + 2);
      if ( v2 == v4 )
        goto LABEL_10;
    }
    v5 = 1;
  }
  if ( illegalChars._Myres >= 8 )
    operator delete(illegalChars._Bx._Ptr);
  return v5;
}
char __usercall Path::fileExists@<al>(unsigned int a1@<ebx>, const std::wstring *path, bool only_real_file)
{
  std::wstring *v3; // eax
  char v4; // bl
  TyreTester v6; // [esp+Bh] [ebp-129h] BYREF
  int v7; // [esp+11Ch] [ebp-18h]
  unsigned int v8; // [esp+120h] [ebp-14h]
  int v9; // [esp+130h] [ebp-4h]

  Path::getPlatformSpecificPath((std::wstring *)((char *)&v6.surf.sinLength + 1), path);
  v9 = 0;
  v3 = Path::getPath(
         (std::wstring *)((char *)&v6.status.travel + 1),
         (const std::wstring *)((char *)&v6.surf.sinLength + 1));
  LOBYTE(v9) = 1;
  std::operator+<wchar_t>((std::wstring *)((char *)&v6.surf.wavString[58] + 1), v3, L".acd");
  LOBYTE(v9) = 3;
  if ( v8 >= 8 )
    operator delete(*(_DWORD *)((char *)&v6.status.travel + 1));
  v8 = 7;
  *(_WORD *)((char *)&v6.status.travel + 1) = 0;
  v7 = 0;
  Path::getFileName(
    (std::wstring *)((char *)&v6.surf.sectorID + 1),
    (const std::wstring *)((char *)&v6.surf.sinLength + 1));
  LOBYTE(v9) = 4;
  FolderEncrypter::FolderEncrypter((std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *)&v6);
  LOBYTE(v9) = 5;
  if ( only_real_file
    || !FolderEncrypter::fileExists(
          (FolderEncrypter *)&v6,
          a1,
          (const std::wstring *)((char *)&v6.surf.wavString[58] + 1),
          (const std::wstring *)((char *)&v6.surf.sectorID + 1)) )
  {
    std::ifstream::ifstream(
      (std::ifstream *)((char *)&v6.ISuspension::__vftable + 1),
      (const std::wstring *)((char *)&v6.surf.sinLength + 1),
      1,
      64,
      1);
    LOBYTE(v9) = 5;
    if ( (*((_BYTE *)&v6.bumpStopRate
          + (unsigned int)(*(TyreTester_vtbl **)((char *)&v6.ISuspension::__vftable + 1))->getHubWorldMatrix
          + 1) & 6) != 0 )
    {
      std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)((char *)&v6.surf.wavString[22] + 1));
      *(_DWORD *)((char *)&v6.surf.wavString[22] + 1) = std::ios_base::`vftable';
      std::ios_base::_Ios_base_dtor((struct std::ios_base *)((char *)&v6.surf.wavString[22] + 1));
      v4 = 0;
    }
    else
    {
      std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)((char *)&v6.surf.wavString[22] + 1));
      *(_DWORD *)((char *)&v6.surf.wavString[22] + 1) = std::ios_base::`vftable';
      std::ios_base::_Ios_base_dtor((struct std::ios_base *)((char *)&v6.surf.wavString[22] + 1));
      v4 = 1;
    }
  }
  else
  {
    v4 = 1;
  }
  LOBYTE(v9) = 4;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart(&v6);
  if ( *(_DWORD *)((char *)&v6.surf.sinHeight + 1) >= 8u )
    operator delete(*(int *)((char *)&v6.surf.sectorID + 1));
  *(_QWORD *)((char *)&v6.surf.blackFlagTime + 1) = 0x700000000i64;
  *(_WORD *)((char *)&v6.surf.sectorID + 1) = 0;
  if ( *(_DWORD *)((char *)&v6.surf.gripMod + 1) >= 8u )
    operator delete(*(_DWORD *)((char *)&v6.surf.wavString[58] + 1));
  *(_QWORD *)((char *)&v6.surf.userPointer + 1) = 0x700000000i64;
  *(wchar_t *)((char *)&v6.surf.wavString[58] + 1) = 0;
  if ( *(_DWORD *)((char *)&v6.surf.vibrationLength + 1) >= 8u )
    operator delete(*(_DWORD *)((char *)&v6.surf.sinLength + 1));
  return v4;
}
bool __cdecl Path::folderExists(const std::wstring *folder)
{
  const std::wstring *v1; // eax
  DWORD v2; // eax

  v1 = folder;
  if ( folder->_Myres >= 8 )
    v1 = (const std::wstring *)folder->_Bx._Ptr;
  v2 = GetFileAttributesW(v1->_Bx._Buf);
  return v2 != -1 && (v2 & 0x10) != 0;
}
std::wstring *__cdecl Path::getDocumentPath(std::wstring *result)
{
  unsigned int v1; // ecx
  wchar_t szPath[260]; // [esp+8h] [ebp-20Ch] BYREF

  SHGetFolderPathW(0, 5, 0, 0, szPath);
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  if ( szPath[0] )
    v1 = wcslen(szPath);
  else
    v1 = 0;
  std::wstring::assign(result, szPath, v1);
  return result;
}
std::wstring *__cdecl Path::getFileName(std::wstring *result, const std::wstring *s)
{
  int v2; // eax

  v2 = std::wstring::find_last_of((std::wstring *)s, L"/\\", 0xFFFFFFFF, 2u);
  if ( v2 == -1 )
  {
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, s, 0, 0xFFFFFFFF);
  }
  else
  {
    std::wstring::substr((std::wstring *)s, result, v2 + 1, s->_Mysize - v2 - 1);
  }
  return result;
}
std::wstring *__cdecl Path::getFileNameWithoutExtension(std::wstring *result, const std::wstring *path)
{
  int v2; // eax
  std::wstring s; // [esp+Ch] [ebp-28h] BYREF
  int v5; // [esp+30h] [ebp-4h]

  Path::getFileName(&s, path);
  v5 = 0;
  v2 = std::wstring::find_last_of(&s, L".", 0xFFFFFFFF, 1u);
  if ( v2 == -1 )
    std::wstring::wstring(result, &s);
  else
    std::wstring::substr(&s, result, 0, v2);
  if ( s._Myres >= 8 )
    operator delete(s._Bx._Ptr);
  return result;
}
std::vector<std::wstring> *__cdecl Path::getFiles(std::vector<std::wstring> *result, const std::wstring *filter)
{
  wchar_t *v2; // eax
  std::wstring *v3; // ecx
  const wchar_t *v4; // ebp
  intptr_t v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // ecx
  std::vector<std::wstring> resulta; // [esp+18h] [ebp-29Ch] BYREF
  int v10; // [esp+28h] [ebp-28Ch]
  std::wstring v11; // [esp+2Ch] [ebp-288h] BYREF
  std::wstring _Val; // [esp+44h] [ebp-270h] BYREF
  std::wstring s; // [esp+5Ch] [ebp-258h] BYREF
  _wfinddata64i32_t c_file; // [esp+74h] [ebp-240h] BYREF
  int v15; // [esp+2B0h] [ebp-4h]

  v10 = 0;
  resulta._Myfirst = 0;
  resulta._Myend = 0;
  v15 = 0;
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(0, 0);
  resulta._Mylast = 0;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, filter, 0, 0xFFFFFFFF);
  LOBYTE(v15) = 1;
  v2 = (wchar_t *)operator new[](2 * (v11._Mysize + 1));
  v3 = &v11;
  v4 = v2;
  if ( v11._Myres >= 8 )
    v3 = (std::wstring *)v11._Bx._Ptr;
  _wcscpy_s(v2, v11._Mysize + 1, v3->_Bx._Buf);
  v4[v11._Mysize] = 0;
  v5 = __wfindfirst64i32(v4, &c_file);
  if ( v5 == -1 )
  {
    operator delete[](v4);
    result->_Myfirst = 0;
    result->_Mylast = 0;
    result->_Myend = 0;
  }
  else
  {
    if ( (c_file.attrib & 0x10) == 0 )
    {
      std::wstring::wstring(&s, c_file.name);
      LOBYTE(v15) = 2;
      std::wstring::wstring(&_Val, c_file.name);
      LOBYTE(v15) = 3;
      std::vector<std::wstring>::push_back(&resulta, &_Val);
      if ( _Val._Myres >= 8 )
        operator delete(_Val._Bx._Ptr);
      LOBYTE(v15) = 1;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
    }
    while ( !__wfindnext64i32(v5, &c_file) )
    {
      if ( (c_file.attrib & 0x10) == 0 )
      {
        v6 = 0;
        _Val._Myres = 7;
        _Val._Mysize = 0;
        _Val._Bx._Buf[0] = 0;
        if ( c_file.name[0] )
          v6 = wcslen(c_file.name);
        std::wstring::assign(&_Val, c_file.name, v6);
        LOBYTE(v15) = 4;
        s._Myres = 7;
        s._Mysize = 0;
        s._Bx._Buf[0] = 0;
        if ( c_file.name[0] )
          v7 = wcslen(c_file.name);
        else
          v7 = 0;
        std::wstring::assign(&s, c_file.name, v7);
        LOBYTE(v15) = 5;
        std::vector<std::wstring>::push_back(&resulta, &s);
        if ( s._Myres >= 8 )
          operator delete(s._Bx._Ptr);
        LOBYTE(v15) = 1;
        if ( _Val._Myres >= 8 )
          operator delete(_Val._Bx._Ptr);
      }
    }
    __findclose(v5);
    operator delete[](v4);
    *result = resulta;
  }
  if ( v11._Myres >= 8 )
    operator delete(v11._Bx._Ptr);
  return result;
}
std::vector<std::wstring> *__cdecl Path::getFolders(std::vector<std::wstring> *result, const std::wstring *folder)
{
  wchar_t *v2; // eax
  std::wstring *v3; // ecx
  const wchar_t *v4; // ebp
  intptr_t v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  std::vector<std::wstring> resulta; // [esp+18h] [ebp-29Ch] BYREF
  int v10; // [esp+28h] [ebp-28Ch]
  std::wstring v11; // [esp+2Ch] [ebp-288h] BYREF
  std::wstring s; // [esp+44h] [ebp-270h] BYREF
  std::wstring _Val; // [esp+5Ch] [ebp-258h] BYREF
  _wfinddata64i32_t c_file; // [esp+74h] [ebp-240h] BYREF
  int v15; // [esp+2B0h] [ebp-4h]

  v10 = 0;
  resulta._Myfirst = 0;
  resulta._Myend = 0;
  v15 = 0;
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(0, 0);
  resulta._Mylast = 0;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, folder, 0, 0xFFFFFFFF);
  LOBYTE(v15) = 1;
  v2 = (wchar_t *)operator new[](2 * (v11._Mysize + 1));
  v3 = &v11;
  v4 = v2;
  if ( v11._Myres >= 8 )
    v3 = (std::wstring *)v11._Bx._Ptr;
  _wcscpy_s(v2, v11._Mysize + 1, v3->_Bx._Buf);
  v4[v11._Mysize] = 0;
  v5 = __wfindfirst64i32(v4, &c_file);
  if ( v5 == -1 )
  {
    operator delete[](v4);
    result->_Myfirst = 0;
    result->_Mylast = 0;
    result->_Myend = 0;
  }
  else
  {
    if ( (c_file.attrib & 0x10) != 0 )
    {
      std::wstring::wstring(&s, c_file.name);
      LOBYTE(v15) = 2;
      if ( std::wstring::compare(&s, 0, s._Mysize, L".", 1u) && std::operator!=<wchar_t>(&s, L"..") )
      {
        std::wstring::wstring(&_Val, c_file.name);
        LOBYTE(v15) = 3;
        std::vector<std::wstring>::push_back(&resulta, &_Val);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Val);
      }
      LOBYTE(v15) = 1;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
    }
    while ( !__wfindnext64i32(v5, &c_file) )
    {
      if ( (c_file.attrib & 0x10) != 0 )
      {
        _Val._Myres = 7;
        _Val._Mysize = 0;
        _Val._Bx._Buf[0] = 0;
        if ( c_file.name[0] )
          v6 = wcslen(c_file.name);
        else
          v6 = 0;
        std::wstring::assign(&_Val, c_file.name, v6);
        LOBYTE(v15) = 4;
        if ( std::wstring::compare(&_Val, 0, _Val._Mysize, L".", 1u)
          && std::wstring::compare(&_Val, 0, _Val._Mysize, L"..", 2u) )
        {
          v7 = 0;
          s._Myres = 7;
          s._Mysize = 0;
          s._Bx._Buf[0] = 0;
          if ( c_file.name[0] )
            v7 = wcslen(c_file.name);
          std::wstring::assign(&s, c_file.name, v7);
          LOBYTE(v15) = 5;
          std::vector<std::wstring>::push_back(&resulta, &s);
          if ( s._Myres >= 8 )
            operator delete(s._Bx._Ptr);
        }
        LOBYTE(v15) = 1;
        if ( _Val._Myres >= 8 )
          operator delete(_Val._Bx._Ptr);
      }
    }
    __findclose(v5);
    operator delete[](v4);
    *result = resulta;
  }
  if ( v11._Myres >= 8 )
    operator delete(v11._Bx._Ptr);
  return result;
}
_FILETIME __cdecl Path::getLastModificationTime(const std::wstring *path)
{
  const std::wstring *v1; // eax
  HANDLE v2; // esi
  _FILETIME lastModificationTime; // [esp+0h] [ebp-18h] BYREF
  _FILETIME lastAccessTime; // [esp+8h] [ebp-10h] BYREF
  _FILETIME creationTime; // [esp+10h] [ebp-8h] BYREF

  v1 = path;
  if ( path->_Myres >= 8 )
    v1 = (const std::wstring *)path->_Bx._Ptr;
  v2 = CreateFileW(v1->_Bx._Buf, 0x80000000, 0, 0, 3u, 0x80u, 0);
  GetFileTime(v2, &creationTime, &lastAccessTime, &lastModificationTime);
  CloseHandle(v2);
  return lastModificationTime;
}
std::wstring *__cdecl Path::getPath(std::wstring *result, const std::wstring *s)
{
  int v2; // eax

  v2 = std::wstring::find_last_of((std::wstring *)s, L"/\\", 0xFFFFFFFF, 2u);
  if ( v2 == -1 )
  {
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, s, 0, 0xFFFFFFFF);
  }
  else
  {
    std::wstring::substr((std::wstring *)s, result, 0, v2);
  }
  return result;
}
std::wstring *__cdecl Path::getPlatformSpecificPath(std::wstring *result, const std::wstring *path)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, path, 0, 0xFFFFFFFF);
  return result;
}
std::wstring *__cdecl Path::readAllText(std::wstring *result, const std::wstring *filename)
{
  const std::wstring *v2; // ebx
  int v3; // eax
  struct std::locale::facet *v4; // esi
  unsigned int v5; // eax
  const std::wstring *v6; // eax
  int v7; // eax
  void (***v8)(_DWORD, int); // eax
  std::wstring *v9; // eax
  std::_Facet_base *v10; // eax
  std::_Facet_base *v11; // eax
  std::_Facet_base *v12; // eax
  std::locale utf8_locale; // [esp+1Ch] [ebp-1A0h] BYREF
  std::locale empty_locale; // [esp+20h] [ebp-19Ch] BYREF
  int v16; // [esp+24h] [ebp-198h] BYREF
  int v17; // [esp+28h] [ebp-194h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v18; // [esp+2Ch] [ebp-190h] BYREF
  std::wifstream f; // [esp+DCh] [ebp-E0h] BYREF
  std::wstring v20; // [esp+194h] [ebp-28h] BYREF
  int v21; // [esp+1B8h] [ebp-4h]

  v2 = filename;
  v17 = 0;
  std::locale::empty(&empty_locale);
  v21 = 0;
  v3 = operator new(52);
  v4 = (struct std::locale::facet *)v3;
  v16 = v3;
  LOBYTE(v21) = 1;
  if ( v3 )
  {
    std::codecvt<wchar_t,char,int>::codecvt<wchar_t,char,int>(v3, 0);
    v4->__vftable = (std::locale::facet_vtbl *)&std::codecvt_utf8<wchar_t,1114111,0>::`vftable';
  }
  else
  {
    v4 = 0;
  }
  LOBYTE(v21) = 0;
  utf8_locale._Ptr = std::locale::_Locimp::_New_Locimp(empty_locale._Ptr);
  if ( v4 )
  {
    v5 = std::locale::id::operator unsigned int(std::codecvt<wchar_t,char,int>::id._Id);
    std::locale::_Locimp::_Locimp_Addfac(utf8_locale._Ptr, v4, v5);
    if ( std::codecvt<wchar_t,char,int>::_Getcat(0, 0) != -1 )
    {
      utf8_locale._Ptr->_Catmask = 0;
      std::_Yarn<char>::operator=(&utf8_locale._Ptr->_Name, "*");
    }
  }
  LOBYTE(v21) = 2;
  v6 = Path::getPlatformSpecificPath(&v20, filename);
  LOBYTE(v21) = 3;
  std::wifstream::wifstream(&f, v6, 1, 64, 1);
  LOBYTE(v21) = 5;
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  v20._Myres = 7;
  v20._Bx._Buf[0] = 0;
  v20._Mysize = 0;
  v7 = *(_DWORD *)(*(_DWORD *)f.gap0 + 4);
  if ( (*((_BYTE *)&f._Chcount + v7 + 4) & 6) != 0 )
  {
    if ( filename->_Myres >= 8 )
      v2 = (const std::wstring *)filename->_Bx._Ptr;
    _printf("ERROR: Path::readAllText Cannot find file %S\n", v2->_Bx._Buf);
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, word_17BE9D8, 0);
    std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&f.gap64[12]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&f.gap64[12]);
    LOBYTE(v21) = 0;
    if ( utf8_locale._Ptr )
    {
      v11 = utf8_locale._Ptr->_Decref(utf8_locale._Ptr);
      if ( v11 )
        ((void (*)(std::_Facet_base *, int))v11->~_Facet_base)(v11, 1);
    }
  }
  else
  {
    std::wios::imbue((char *)&f + v7, &v16, &utf8_locale);
    if ( v16 )
    {
      v8 = (void (***)(_DWORD, int))(*(int (**)(int))(*(_DWORD *)v16 + 8))(v16);
      if ( v8 )
        (**v8)(v8, 1);
    }
    *(_DWORD *)v18.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v18.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v18.gap68);
    LOBYTE(v21) = 6;
    v17 = 2;
    std::wiostream::basic_iostream<wchar_t>(&v18, &v18.gap10[8], 0);
    v21 = 7;
    *(_DWORD *)&v18.gap0[*(_DWORD *)(*(_DWORD *)v18.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v17 + *(_DWORD *)(*(_DWORD *)v18.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v18.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v18.gap10[8]);
    *(_DWORD *)&v18.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v18.gap10[64] = 0;
    *(_DWORD *)&v18.gap10[68] = 0;
    LOBYTE(v21) = 9;
    v20._Myres = 7;
    v20._Mysize = 0;
    v20._Bx._Buf[0] = 0;
    std::wstring::assign(&v20, word_17BE9D8, 0);
    LOBYTE(v21) = 10;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v18.gap10[8]);
    v9 = &v20;
    if ( v20._Myres >= 8 )
      v9 = (std::wstring *)v20._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v18.gap10[8], v9->_Bx._Buf, v20._Mysize, *(int *)&v18.gap10[68]);
    LOBYTE(v21) = 9;
    if ( v20._Myres >= 8 )
      operator delete(v20._Bx._Ptr);
    std::wostream::operator<<(v18.gap10, f.gap10);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v18, result);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v18);
    std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&f.gap64[12]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&f.gap64[12]);
    LOBYTE(v21) = 0;
    if ( utf8_locale._Ptr )
    {
      v10 = utf8_locale._Ptr->_Decref(utf8_locale._Ptr);
      if ( v10 )
        ((void (*)(std::_Facet_base *, int))v10->~_Facet_base)(v10, 1);
    }
  }
  v21 = -1;
  if ( empty_locale._Ptr )
  {
    v12 = empty_locale._Ptr->_Decref(empty_locale._Ptr);
    if ( v12 )
      ((void (*)(std::_Facet_base *, int))v12->~_Facet_base)(v12, 1);
  }
  return result;
}
