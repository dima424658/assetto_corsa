#include "filechangeobserver.h
void FileChangeObserver::FileChangeObserver(FileChangeObserver *this, const std::wstring *a_filename)
{
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  FileChangeObserver::observe(this, a_filename);
}
char FileChangeObserver::hasChanged(FileChangeObserver *this)
{
  unsigned int v2; // eax

  v2 = GetTickCount();
  if ( v2 - this->lastChanged <= 0x7D0 )
    return 0;
  this->lastChanged = v2;
  return 1;
}
void FileChangeObserver::observe(FileChangeObserver *this, const std::wstring *a_filename)
{
  std::wstring *v3; // esi
  int v4; // edi
  const wchar_t *v5; // eax
  HANDLE v6; // ebx
  _FILETIME LastWriteTime; // [esp+10h] [ebp-18h] BYREF
  _FILETIME LastAccessTime; // [esp+18h] [ebp-10h] BYREF
  _FILETIME CreationTime; // [esp+20h] [ebp-8h] BYREF

  v3 = &this->filename;
  if ( &this->filename != a_filename )
    std::wstring::assign(&this->filename, a_filename, 0, 0xFFFFFFFF);
  v4 = 0;
  while ( 1 )
  {
    v5 = (const wchar_t *)(v3->_Myres < 8 ? v3 : v3->_Bx._Ptr);
    v6 = CreateFileW(v5, 0x80000000, 0, 0, 3u, 0, 0);
    if ( v6 )
      break;
    Sleep(0xAu);
    if ( ++v4 > 1000 )
    {
      this->lastChanged = GetTickCount();
      return;
    }
  }
  GetFileTime(v6, &CreationTime, &LastAccessTime, &LastWriteTime);
  CloseHandle(v6);
  this->lastFileTime = LastWriteTime;
  this->lastChanged = GetTickCount();
}
void FileChangeObserver::reset(FileChangeObserver *this)
{
  int v1; // esi
  std::wstring *v2; // edi
  const wchar_t *v3; // eax
  HANDLE v4; // ebx
  _FILETIME LastWriteTime; // [esp+14h] [ebp-18h] BYREF
  _FILETIME LastAccessTime; // [esp+1Ch] [ebp-10h] BYREF
  _FILETIME CreationTime; // [esp+24h] [ebp-8h] BYREF

  v1 = 0;
  v2 = &this->filename;
  while ( 1 )
  {
    v3 = (const wchar_t *)(v2->_Myres < 8 ? v2 : v2->_Bx._Ptr);
    v4 = CreateFileW(v3, 0x80000000, 0, 0, 3u, 0, 0);
    if ( v4 )
      break;
    Sleep(0xAu);
    if ( ++v1 > 1000 )
      return;
  }
  GetFileTime(v4, &CreationTime, &LastAccessTime, &LastWriteTime);
  CloseHandle(v4);
  this->lastFileTime = LastWriteTime;
}
