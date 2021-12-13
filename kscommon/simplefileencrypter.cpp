#include "simplefileencrypter.h"
std::vector<char> *__usercall SimpleFileEncrypter::decryptFile@<eax>(unsigned int a1@<edi>, std::vector<char> *result, const std::wstring *filename, const std::wstring *password)
{
  int *v4; // ebp
  int v5; // edi
  const std::wstring *v6; // ecx
  char _Val; // [esp+31h] [ebp-525h] BYREF
  int bs; // [esp+32h] [ebp-524h] BYREF
  int ns; // [esp+36h] [ebp-520h] BYREF
  int v11; // [esp+3Ah] [ebp-51Ch]
  std::vector<char> code; // [esp+3Eh] [ebp-518h] BYREF
  std::vector<char> *v13; // [esp+4Ah] [ebp-50Ch]
  ksSecurity sec; // [esp+4Eh] [ebp-508h] BYREF
  std::ifstream data; // [esp+5Eh] [ebp-4F8h] BYREF
  std::vector<int> buffer; // [esp+116h] [ebp-440h] BYREF
  int v17; // [esp+126h] [ebp-430h]
  unsigned int v18; // [esp+12Ah] [ebp-42Ch]
  std::wstring cCurrentPath; // [esp+12Eh] [ebp-428h] BYREF
  char ff[1024]; // [esp+146h] [ebp-410h] BYREF
  int v21; // [esp+552h] [ebp-4h]

  v13 = result;
  v11 = 0;
  Path::getPath(&cCurrentPath, filename);
  v21 = 1;
  ksSecurity::ksSecurity(&sec);
  LOBYTE(v21) = 2;
  if ( Path::fileExists((unsigned int)result, filename, 0) )
  {
    std::ifstream::ifstream(&data, filename, 32, 64, 1);
    LOBYTE(v21) = 3;
    if ( (*((_BYTE *)&data._Chcount + *(_DWORD *)(*(_DWORD *)data.gap0 + 4) + 4) & 1) == 0 )
    {
      std::istream::read(&data, &ns);
      std::istream::read(&data, ff);
      if ( (unsigned int)ns < 0x400 )
      {
        ff[ns] = 0;
        std::istream::read(&data, &bs);
        std::vector<int>::vector<int>(&buffer, bs);
        v4 = buffer._Myfirst;
        LOBYTE(v21) = 4;
        std::istream::read(&data, buffer._Myfirst);
        code._Myfirst = 0;
        code._Mylast = 0;
        code._Myend = 0;
        v5 = 0;
        for ( LOBYTE(v21) = 5; v5 < bs; ++v5 )
        {
          if ( password->_Myres < 8 )
            v6 = password;
          else
            v6 = (const std::wstring *)password->_Bx._Ptr;
          _Val = LOBYTE(v4[v5]) - v6->_Bx._Alias[2 * (v5 % password->_Mysize)];
          std::vector<char>::push_back(&code, &_Val);
        }
        std::vector<char>::vector<char>(result, &code);
        v11 = 1;
        std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>((std::vector<SplineIndexBound> *)&code);
        std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&buffer);
        std::ifstream::`vbase destructor(&data);
        LOBYTE(v21) = 1;
        ksSecurity::~ksSecurity(&sec);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cCurrentPath);
        return result;
      }
      __report_rangecheckfailure((unsigned int)result, a1, (unsigned int)filename);
    }
    LOBYTE(v21) = 2;
    std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&data.gap64[12]);
    *(_DWORD *)&data.gap64[12] = std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor((struct std::ios_base *)&data.gap64[12]);
  }
  else
  {
    _printf("FILE NOT FOUND\n");
  }
  v18 = 7;
  v17 = 0;
  LOWORD(buffer._Myfirst) = 0;
  std::wstring::assign((std::wstring *)&buffer, L"NOT FOUND", 9u);
  LOBYTE(v21) = 6;
  ksEncodeUtf8(result, (const std::wstring *)&buffer);
  v11 = 1;
  if ( v18 >= 8 )
    operator delete(buffer._Myfirst);
  v18 = 7;
  v17 = 0;
  LOWORD(buffer._Myfirst) = 0;
  LOBYTE(v21) = 1;
  ksSecurity::~ksSecurity(&sec);
  if ( cCurrentPath._Myres >= 8 )
    operator delete(cCurrentPath._Bx._Ptr);
  return result;
}
