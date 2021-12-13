#include "inireaderdocuments.h"
INIReaderDocuments *INIReaderDocuments::`vector deleting destructor'(INIReaderDocuments *this, unsigned int a2)
{
  INIReaderDocuments::~INIReaderDocuments(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge INIReaderDocuments::INIReaderDocuments(INIReaderDocuments *this@<ecx>, unsigned int a2@<ebx>, std::wstring iniName, bool createFile)
{
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // esi
  std::wstring *v10; // esi
  char v11; // al
  std::wstring *v12; // ecx
  const std::wstring *v13; // eax
  std::wofstream file; // [esp+14h] [ebp-1ECh] BYREF
  std::wstring section; // [esp+BCh] [ebp-144h] BYREF
  std::wstring key; // [esp+D4h] [ebp-12Ch] BYREF
  std::wstring docpath; // [esp+ECh] [ebp-114h] BYREF
  std::wstring result; // [esp+104h] [ebp-FCh] BYREF
  std::wstring ifilename; // [esp+11Ch] [ebp-E4h] BYREF
  std::wstring redirectPath; // [esp+134h] [ebp-CCh] BYREF
  std::wstring v21; // [esp+14Ch] [ebp-B4h] BYREF
  std::wstring v22; // [esp+164h] [ebp-9Ch] BYREF
  std::wstring v23; // [esp+17Ch] [ebp-84h] BYREF
  std::wstring v24; // [esp+194h] [ebp-6Ch] BYREF
  INIReader iniDocSettings; // [esp+1ACh] [ebp-54h] BYREF
  int v26; // [esp+1FCh] [ebp-4h]

  v26 = 0;
  INIReader::INIReader(this);
  this->__vftable = (INIReaderDocuments_vtbl *)&INIReaderDocuments::`vftable';
  LOBYTE(v26) = 1;
  if ( !INIReaderDocuments::initialized )
  {
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    std::wstring::assign(&ifilename, L"system/cfg/inireaderdocuments.ini", 0x21u);
    LOBYTE(v26) = 2;
    INIReader::INIReader(&iniDocSettings, &ifilename);
    LOBYTE(v26) = 4;
    if ( ifilename._Myres >= 8 )
      operator delete(ifilename._Bx._Ptr);
    ifilename._Myres = 7;
    ifilename._Mysize = 0;
    ifilename._Bx._Buf[0] = 0;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PROGRAM_NAME", 0xCu);
    LOBYTE(v26) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FOLDER", 6u);
    LOBYTE(v26) = 6;
    v5 = INIReader::getString(&iniDocSettings, &result, &section, &key);
    LOBYTE(v26) = 7;
    v6 = Path::getDocumentPath(&v24);
    LOBYTE(v26) = 8;
    v7 = std::operator+<wchar_t>(&v23, v6, L"/");
    LOBYTE(v26) = 9;
    v8 = std::operator+<wchar_t>(&v22, v7, v5);
    LOBYTE(v26) = 10;
    v9 = std::operator+<wchar_t>(&v21, v8, L"/");
    if ( v9 != &INIReaderDocuments::basePath )
    {
      if ( INIReaderDocuments::basePath._Myres >= 8 )
        operator delete(INIReaderDocuments::basePath._Bx._Ptr);
      INIReaderDocuments::basePath._Myres = 7;
      INIReaderDocuments::basePath._Mysize = 0;
      INIReaderDocuments::basePath._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&INIReaderDocuments::basePath, v9);
    }
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( v23._Myres >= 8 )
      operator delete(v23._Bx._Ptr);
    v23._Myres = 7;
    v23._Mysize = 0;
    v23._Bx._Buf[0] = 0;
    if ( v24._Myres >= 8 )
      operator delete(v24._Bx._Ptr);
    v24._Myres = 7;
    v24._Mysize = 0;
    v24._Bx._Buf[0] = 0;
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
    LOBYTE(v26) = 4;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BYPASS_DOCUMENT_FOLDER", 0x16u);
    LOBYTE(v26) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FOLDER", 6u);
    LOBYTE(v26) = 12;
    LOBYTE(a2) = INIReader::getInt(&iniDocSettings, &section, &key) == 1;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 4;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( (_BYTE)a2 )
      std::wstring::assign(&INIReaderDocuments::basePath, word_17BE9D8, 0);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CUSTOM_PATH", 0xBu);
    LOBYTE(v26) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FOLDER", 6u);
    LOBYTE(v26) = 14;
    INIReader::getString(&iniDocSettings, &redirectPath, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 17;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( std::wstring::compare(&redirectPath, 0, redirectPath._Mysize, word_17BE9D8, 0) )
    {
      v10 = std::operator+<wchar_t>(&result, &redirectPath, L"/");
      if ( v10 != &INIReaderDocuments::basePath )
      {
        if ( INIReaderDocuments::basePath._Myres >= 8 )
          operator delete(INIReaderDocuments::basePath._Bx._Ptr);
        INIReaderDocuments::basePath._Myres = 7;
        INIReaderDocuments::basePath._Mysize = 0;
        INIReaderDocuments::basePath._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&INIReaderDocuments::basePath, v10);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    INIReaderDocuments::initialized = 1;
    if ( redirectPath._Myres >= 8 )
      operator delete(redirectPath._Bx._Ptr);
    redirectPath._Myres = 7;
    redirectPath._Mysize = 0;
    redirectPath._Bx._Buf[0] = 0;
    LOBYTE(v26) = 1;
    INIReader::~INIReader(&iniDocSettings);
  }
  std::operator+<wchar_t>(&docpath, &INIReaderDocuments::basePath, &iniName);
  LOBYTE(v26) = 18;
  v11 = Path::fileExists(a2, &docpath, 0);
  if ( !createFile )
  {
    v12 = &this->filename;
    if ( v11 )
    {
      if ( v12 != &docpath )
        std::wstring::assign(v12, &docpath, 0, 0xFFFFFFFF);
LABEL_46:
      INIReader::load(this, &docpath);
      goto LABEL_59;
    }
    goto LABEL_53;
  }
  if ( v11 )
  {
    if ( &this->filename != &docpath )
      std::wstring::assign(&this->filename, &docpath, 0, 0xFFFFFFFF);
    goto LABEL_46;
  }
  if ( Path::fileExists(a2, &iniName, 0) )
  {
    v12 = &this->filename;
LABEL_53:
    if ( v12 != &iniName )
      std::wstring::assign(v12, &iniName, 0, 0xFFFFFFFF);
    INIReader::load(this, &iniName);
    goto LABEL_59;
  }
  v13 = Path::getPlatformSpecificPath(&result, &docpath);
  LOBYTE(v26) = 19;
  std::wofstream::wofstream(&file, v13, 2, 64, 1);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&file.gap58[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file.gap58[8]);
LABEL_59:
  if ( docpath._Myres >= 8 )
    operator delete(docpath._Bx._Ptr);
  if ( iniName._Myres >= 8 )
    operator delete(iniName._Bx._Ptr);
}
void INIReaderDocuments::~INIReaderDocuments(INIReaderDocuments *this)
{
  this->__vftable = (INIReaderDocuments_vtbl *)&INIReaderDocuments::`vftable';
  INIReader::~INIReader(this);
}
