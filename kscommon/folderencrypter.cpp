#include "folderencrypter.h
void FolderEncrypter::FolderEncrypter(std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *this)
{
  ;
}
void FolderEncrypter::check(FolderEncrypter *this, const std::wstring *dataFile, const std::wstring *filename, const std::wstring *real_file)
{
  const std::wstring *v4; // edx
  const std::wstring *v5; // ecx
  const std::wstring *v6; // eax
  std::wstring *v7; // eax
  unsigned int v8; // esi
  std::wstring *v9; // eax
  std::wstring *v10; // ecx
  unsigned int *v11; // ecx
  unsigned int v12; // edi
  unsigned int *v13; // ecx
  unsigned int v14; // edx
  bool v15; // cc
  FolderEncrypter **v16; // ecx
  unsigned int v17; // esi
  std::wstring *v18; // eax
  std::wstring *v19; // esi
  std::wstring *v20; // eax
  FolderEncrypter *v21; // [esp+14h] [ebp-84h] BYREF
  unsigned int v22; // [esp+18h] [ebp-80h] BYREF
  std::vector<char> result; // [esp+1Ch] [ebp-7Ch] BYREF
  std::wstring code; // [esp+28h] [ebp-70h] BYREF
  std::wstring stp; // [esp+40h] [ebp-58h] BYREF
  std::wstring content_real; // [esp+58h] [ebp-40h] BYREF
  std::wstring v27; // [esp+70h] [ebp-28h] BYREF
  int v28; // [esp+94h] [ebp-4h]

  v21 = this;
  if ( real_file->_Myres < 8 )
    v4 = real_file;
  else
    v4 = (const std::wstring *)real_file->_Bx._Ptr;
  if ( filename->_Myres < 8 )
    v5 = filename;
  else
    v5 = (const std::wstring *)filename->_Bx._Ptr;
  if ( dataFile->_Myres < 8 )
    v6 = dataFile;
  else
    v6 = (const std::wstring *)dataFile->_Bx._Ptr;
  _printf("Checking encryption on data file: %S file:%S agains:%S\n", v6->_Bx._Buf, v5->_Bx._Buf, v4->_Bx._Buf);
  Path::readAllText(&content_real, real_file);
  v28 = 0;
  if ( FolderEncrypter::fileExists(v21, (unsigned int)_printf, dataFile, filename) )
  {
    FolderEncrypter::decryptFile(v21, &result, dataFile, filename);
    LOBYTE(v28) = 1;
    ksDecodeUtf8(&code, &result);
    v7 = &code;
    if ( code._Myres >= 8 )
      v7 = (std::wstring *)code._Bx._Ptr;
    LOBYTE(v28) = 2;
    if ( std::wstring::compare(&content_real, 0, content_real._Mysize, v7->_Bx._Buf, code._Mysize) )
    {
      _printf("CHECK FAILED. Size real: %d  encrypted:%d\n", content_real._Mysize, code._Mysize);
      v8 = 0;
      if ( content_real._Mysize )
      {
        while ( v8 < code._Mysize )
        {
          v9 = &content_real;
          v10 = &code;
          if ( content_real._Myres >= 8 )
            v9 = (std::wstring *)content_real._Bx._Ptr;
          if ( code._Myres >= 8 )
            v10 = (std::wstring *)code._Bx._Ptr;
          if ( v9->_Bx._Buf[v8] != v10->_Bx._Buf[v8] )
          {
            _printf("DIFFERENCE AT:%d\n", v8);
            v22 = 0;
            v21 = (FolderEncrypter *)(v8 - 10);
            v11 = (unsigned int *)&v21;
            if ( (int)(v8 - 10) <= 0 )
              v11 = &v22;
            v12 = *v11;
            v13 = &v22;
            if ( code._Mysize >= content_real._Mysize )
              v13 = (unsigned int *)&v21;
            v21 = (FolderEncrypter *)content_real._Mysize;
            v22 = code._Mysize;
            v14 = *v13;
            v15 = (int)*v13 < (int)(v8 + 10);
            v16 = (FolderEncrypter **)&v22;
            v21 = (FolderEncrypter *)(v8 + 10);
            if ( !v15 )
              v16 = &v21;
            v22 = v14;
            v17 = (unsigned int)&(*v16)[-v12];
            std::wstring::substr(&content_real, &stp, v12, v17);
            v18 = &stp;
            LOBYTE(v28) = 3;
            if ( stp._Myres >= 8 )
              v18 = (std::wstring *)stp._Bx._Ptr;
            _printf("REAL:\n%S\n", v18->_Bx._Buf);
            v19 = std::wstring::substr(&code, &v27, v12, v17);
            if ( &stp != v19 )
            {
              if ( stp._Myres >= 8 )
                operator delete(stp._Bx._Ptr);
              stp._Myres = 7;
              stp._Mysize = 0;
              stp._Bx._Buf[0] = 0;
              std::wstring::_Assign_rv(&stp, v19);
            }
            if ( v27._Myres >= 8 )
              operator delete(v27._Bx._Ptr);
            v20 = &stp;
            if ( stp._Myres >= 8 )
              v20 = (std::wstring *)stp._Bx._Ptr;
            _printf("ENCR:\n%S\n", v20->_Bx._Buf);
            if ( stp._Myres >= 8 )
              operator delete(stp._Bx._Ptr);
            break;
          }
          if ( ++v8 >= content_real._Mysize )
            break;
        }
      }
    }
    else
    {
      _printf("ok\n");
    }
    if ( code._Myres >= 8 )
      operator delete(code._Bx._Ptr);
    code._Myres = 7;
    code._Bx._Buf[0] = 0;
    code._Mysize = 0;
    if ( result._Myfirst )
    {
      operator delete(result._Myfirst);
      result._Myfirst = 0;
      result._Mylast = 0;
      result._Myend = 0;
    }
  }
  else
  {
    _printf("FILE DOES NOT EXISTS IN DATA\n");
  }
  if ( content_real._Myres >= 8 )
    operator delete(content_real._Bx._Ptr);
}
char FolderEncrypter::checkKey(FolderEncrypter *this, std::ifstream *file)
{
  std::ifstream *v2; // esi
  unsigned int *v3; // eax
  int v5; // [esp+8h] [ebp-Ch]
  int header; // [esp+10h] [ebp-4h] BYREF

  v2 = file;
  std::istream::read(file, &header, 4, 0);
  if ( header == -1111 )
  {
    std::istream::read(v2, &file, 4, 0);
    v3 = FolderEncrypter::keys._Myfirst;
    if ( FolderEncrypter::keys._Myfirst == FolderEncrypter::keys._Mylast )
      return 0;
    while ( (std::ifstream *)*v3 != file )
    {
      if ( ++v3 == FolderEncrypter::keys._Mylast )
        return 0;
    }
  }
  else
  {
    std::istream::seekg(v2, 0, 0, 0, 0, 0, v5);
  }
  return 1;
}
std::vector<char> *FolderEncrypter::decryptFile(FolderEncrypter *this, std::vector<char> *result, const std::wstring *dataFile, const std::wstring *filename)
{
  const std::wstring *v5; // eax
  bool v6; // cf
  const std::wstring *v7; // eax
  int v8; // eax
  int v9; // ecx
  char *v11; // edi
  char *v12; // esi
  char *v13; // ebx
  signed int v14; // ebp
  std::wstring *v15; // ecx
  char v16; // al
  char *v17; // ebp
  std::vector<char> *v18; // ebp
  int *v19; // eax
  std::wstring v20; // [esp+2h] [ebp-590h] BYREF
  int v21; // [esp+2Eh] [ebp-564h] BYREF
  unsigned int _Count; // [esp+32h] [ebp-560h] BYREF
  std::vector<char> code; // [esp+36h] [ebp-55Ch] BYREF
  int v24; // [esp+42h] [ebp-550h]
  int ns; // [esp+46h] [ebp-54Ch] BYREF
  int i; // [esp+4Ah] [ebp-548h]
  int bs; // [esp+4Eh] [ebp-544h] BYREF
  std::vector<char> *v28; // [esp+52h] [ebp-540h]
  ksSecurity sec; // [esp+56h] [ebp-53Ch] BYREF
  std::vector<char> *v30; // [esp+66h] [ebp-52Ch]
  std::ifstream data; // [esp+6Ah] [ebp-528h] BYREF
  std::wstring pswd; // [esp+122h] [ebp-470h] BYREF
  std::wstring wff; // [esp+13Ah] [ebp-458h] BYREF
  std::vector<int> buffer; // [esp+152h] [ebp-440h] BYREF
  int v35; // [esp+162h] [ebp-430h]
  unsigned int v36; // [esp+166h] [ebp-42Ch]
  std::wstring cCurrentPath; // [esp+16Ah] [ebp-428h] BYREF
  char ff[1024]; // [esp+182h] [ebp-410h] BYREF
  int v39; // [esp+58Eh] [ebp-4h]

  v28 = result;
  v30 = result;
  v24 = 0;
  Path::getPath(&cCurrentPath, dataFile);
  v39 = 1;
  ksSecurity::ksSecurity(&sec);
  LOBYTE(v39) = 2;
  Path::getFileName(&v20, &cCurrentPath);
  ksSecurity::keyFromString(&sec, &pswd, v20);
  LOBYTE(v39) = 3;
  v5 = Path::getPlatformSpecificPath((std::wstring *)&buffer, dataFile);
  LOBYTE(v39) = 4;
  std::ifstream::ifstream(&data, v5, 32, 64, 1);
  LOBYTE(v39) = 6;
  if ( v36 >= 8 )
    operator delete(buffer._Myfirst);
  v36 = 7;
  LOWORD(buffer._Myfirst) = 0;
  v35 = 0;
  if ( !FolderEncrypter::checkKey(this, &data) )
  {
    result->_Myfirst = 0;
    result->_Mylast = 0;
    result->_Myend = 0;
    v24 = 1;
LABEL_18:
    std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&data.gap64[12]);
    std::ios::~ios<char,std::char_traits<char>>(&data.gap64[12]);
    if ( pswd._Myres >= 8 )
      operator delete(pswd._Bx._Ptr);
    pswd._Myres = 7;
    pswd._Mysize = 0;
    pswd._Bx._Buf[0] = 0;
    LOBYTE(v39) = 1;
    ksSecurity::~ksSecurity(&sec);
    if ( cCurrentPath._Myres >= 8 )
      operator delete(cCurrentPath._Bx._Ptr);
    return result;
  }
  if ( (*((_BYTE *)&data._Chcount + *(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 4) & 1) != 0 )
  {
LABEL_15:
    std::wstring::wstring(&wff, L"NOT FOUND");
    LOBYTE(v39) = 10;
    ksEncodeUtf8(result, &wff);
    v24 = 1;
    if ( wff._Myres >= 8 )
      operator delete(wff._Bx._Ptr);
    wff._Myres = 7;
    wff._Mysize = 0;
    wff._Bx._Buf[0] = 0;
    goto LABEL_18;
  }
  while ( 1 )
  {
    *(_QWORD *)&v20._Mysize = 4i64;
    std::istream::read(&data, &ns);
    *(_QWORD *)&v20._Mysize = ns;
    std::istream::read(&data, ff);
    if ( (unsigned int)ns >= 0x400 )
    {
      __report_rangecheckfailure((unsigned int)result, (unsigned int)filename, (unsigned int)dataFile);
      JUMPOUT(0x71E568);
    }
    v20._Myres = ns;
    ff[ns] = 0;
    ksDecodeUtf8(&wff, ff, v20._Myres);
    v6 = filename->_Myres < 8;
    LOBYTE(v39) = 7;
    v7 = v6 ? filename : filename->_Bx._Ptr;
    v8 = std::wstring::compare(&wff, 0, wff._Mysize, v7->_Bx._Buf, filename->_Mysize);
    *(_QWORD *)&v20._Mysize = 4i64;
    if ( !v8 )
      break;
    std::istream::read(&data, &bs);
    std::istream::seekg(&data, 4 * bs, 0, 1);
    v9 = *(_DWORD *)data.gap0;
    LOBYTE(v39) = 6;
    if ( (*((_BYTE *)&data._Chcount + *(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 4) & 6) != 0 )
    {
      if ( wff._Myres >= 8 )
        operator delete(wff._Bx._Ptr);
      goto LABEL_15;
    }
    if ( wff._Myres >= 8 )
    {
      operator delete(wff._Bx._Ptr);
      v9 = *(_DWORD *)data.gap0;
    }
    if ( (*((_BYTE *)&data._Chcount + *(_DWORD *)(v9 + 4) + 4) & 1) != 0 )
      goto LABEL_15;
  }
  std::istream::read(&data, &_Count);
  std::vector<int>::vector<int>(&buffer, _Count);
  *(_QWORD *)&v20._Mysize = 4 * _Count;
  LOBYTE(v39) = 8;
  std::istream::read(&data, buffer._Myfirst);
  v11 = 0;
  v12 = 0;
  v13 = 0;
  code._Myfirst = 0;
  code._Mylast = 0;
  code._Myend = 0;
  v14 = 0;
  LOBYTE(v39) = 9;
  for ( i = 0; v14 < (int)_Count; i = v14 )
  {
    v15 = &pswd;
    if ( pswd._Myres >= 8 )
      v15 = (std::wstring *)pswd._Bx._Ptr;
    v13 = code._Myend;
    v16 = LOBYTE(buffer._Myfirst[v14]) - v15->_Bx._Alias[2 * (v14 % pswd._Mysize)];
    HIBYTE(v21) = v16;
    BYTE2(v21) = v16;
    if ( (char *)&v21 + 2 >= v12 || v11 > (char *)&v21 + 2 )
    {
      if ( v12 == code._Myend )
      {
        std::vector<char>::_Reserve(&code, 1u);
        v13 = code._Myend;
        v12 = code._Mylast;
        v11 = code._Myfirst;
        v16 = HIBYTE(v21);
      }
      if ( v12 )
        *v12 = v16;
    }
    else
    {
      v17 = (char *)((char *)&v21 + 2 - v11);
      if ( v12 == code._Myend )
      {
        std::vector<char>::_Reserve(&code, 1u);
        v13 = code._Myend;
        v12 = code._Mylast;
        v11 = code._Myfirst;
      }
      if ( v12 )
        *v12 = v17[(_DWORD)v11];
      v14 = i;
    }
    ++v14;
    code._Mylast = ++v12;
  }
  v18 = v28;
  v19 = buffer._Myfirst;
  v24 = 1;
  v28->_Myfirst = v11;
  v18->_Mylast = v12;
  v18->_Myend = v13;
  if ( v19 )
    operator delete(v19);
  if ( wff._Myres >= 8 )
    operator delete(wff._Bx._Ptr);
  wff._Myres = 7;
  wff._Mysize = 0;
  wff._Bx._Buf[0] = 0;
  std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&data.gap64[12]);
  std::ios::~ios<char,std::char_traits<char>>(&data.gap64[12]);
  if ( pswd._Myres >= 8 )
    operator delete(pswd._Bx._Ptr);
  pswd._Myres = 7;
  pswd._Mysize = 0;
  pswd._Bx._Buf[0] = 0;
  LOBYTE(v39) = 1;
  ksSecurity::~ksSecurity(&sec);
  if ( cCurrentPath._Myres >= 8 )
    operator delete(cCurrentPath._Bx._Ptr);
  return v18;
}
char __userpurge FolderEncrypter::fileExists@<al>(FolderEncrypter *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *dataFile, const std::wstring *filename)
{
  int v5; // eax
  bool v6; // cf
  const std::wstring *v7; // eax
  int v8; // ecx
  int v9; // eax
  int v11; // [esp+18h] [ebp-4F8h]
  int ns; // [esp+28h] [ebp-4E8h] BYREF
  int bs; // [esp+2Ch] [ebp-4E4h] BYREF
  std::ifstream data; // [esp+30h] [ebp-4E0h] BYREF
  std::wstring wff; // [esp+E8h] [ebp-428h] BYREF
  char ff[1024]; // [esp+100h] [ebp-410h] BYREF
  int v17; // [esp+50Ch] [ebp-4h]

  std::ifstream::ifstream(&data, dataFile, 32, 64, 1);
  v17 = 0;
  if ( FolderEncrypter::checkKey(this, &data) )
  {
    v5 = *(_DWORD *)((char *)&data._Chcount + *(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 4);
    if ( (v5 & 1) == 0 )
    {
      while ( (v5 & 6) == 0 )
      {
        std::istream::read(&data, &ns);
        std::istream::read(&data, ff);
        if ( (unsigned int)ns >= 0x400 )
        {
          __report_rangecheckfailure(a2, (unsigned int)filename, (unsigned int)this);
          JUMPOUT(0x71E83D);
        }
        v11 = ns;
        ff[ns] = 0;
        ksDecodeUtf8(&wff, ff, v11);
        v6 = filename->_Myres < 8;
        LOBYTE(v17) = 1;
        if ( v6 )
          v7 = filename;
        else
          v7 = (const std::wstring *)filename->_Bx._Ptr;
        if ( !std::wstring::compare(&wff, 0, wff._Mysize, v7->_Bx._Buf, filename->_Mysize) )
        {
          if ( wff._Myres >= 8 )
            operator delete(wff._Bx._Ptr);
          wff._Myres = 7;
          wff._Mysize = 0;
          wff._Bx._Buf[0] = 0;
          v17 = -1;
          std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&data.gap64[12]);
          *(_DWORD *)&data.gap64[12] = std::ios_base::`vftable';
          std::ios_base::_Ios_base_dtor((struct std::ios_base *)&data.gap64[12]);
          return 1;
        }
        std::istream::read(&data, &bs);
        std::istream::seekg(&data, 4 * bs, 0, 1);
        v8 = *(_DWORD *)data.gap0;
        if ( (*((_BYTE *)&data._Chcount + *(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 4) & 6) != 0 )
        {
          if ( wff._Myres >= 8 )
            operator delete(wff._Bx._Ptr);
          wff._Myres = 7;
          wff._Mysize = 0;
          wff._Bx._Buf[0] = 0;
          break;
        }
        LOBYTE(v17) = 0;
        if ( wff._Myres >= 8 )
        {
          operator delete(wff._Bx._Ptr);
          v8 = *(_DWORD *)data.gap0;
        }
        wff._Myres = 7;
        wff._Bx._Buf[0] = 0;
        v9 = *(_DWORD *)(v8 + 4);
        wff._Mysize = 0;
        v5 = *(_DWORD *)((char *)&data._Chcount + v9 + 4);
        if ( (v5 & 1) != 0 )
          break;
      }
    }
  }
  v17 = -1;
  std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&data.gap64[12]);
  *(_DWORD *)&data.gap64[12] = std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor((struct std::ios_base *)&data.gap64[12]);
  return 0;
}
