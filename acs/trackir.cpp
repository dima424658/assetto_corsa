#include "trackir.h"
void TrackIR::TrackIR(TrackIR *this, HWND__ *hwnd)
{
  bool v3; // bl
  std::string *v4; // eax
  std::wstring v5; // [esp-1Ch] [ebp-118h] BYREF
  const char *v6; // [esp-4h] [ebp-100h]
  unsigned __int16 wNPClientVer[4]; // [esp+10h] [ebp-ECh] BYREF
  std::string path; // [esp+18h] [ebp-E4h] BYREF
  std::wstring section; // [esp+30h] [ebp-CCh] BYREF
  INIReaderDocuments ini; // [esp+48h] [ebp-B4h] BYREF
  char csMinorVer[32]; // [esp+8Ch] [ebp-70h] BYREF
  char csMajorVer[64]; // [esp+ACh] [ebp-50h] BYREF
  int v13; // [esp+F8h] [ebp-4h]

  v6 = "Initializing TrackIR interface\n";
  this->divisionValue = 500.0;
  this->isValid = 0;
  _printf(v6);
  getDllLocation(&path);
  v13 = 0;
  if ( NPClient_Init(&path) )
  {
    v4 = &path;
    if ( path._Myres >= 0x10 )
      v4 = (std::string *)path._Bx._Ptr;
    _printf("TrackIR not found at %s\n", v4->_Bx._Buf);
  }
  else
  {
    _printf("TrackIR found\n");
    NP_RegisterWindowHandle(hwnd);
    if ( NP_QueryVersion(wNPClientVer) == NP_OK )
    {
      sprintf_s<64>((char (*)[64])csMajorVer, "%d", HIBYTE(wNPClientVer[0]));
      sprintf_s<32>((char (*)[32])csMinorVer, "%02d", LOBYTE(wNPClientVer[0]));
      _printf("NaturalPoint TrackIR software version is %d.%d\n", csMajorVer, csMinorVer);
      NP_RequestData(0x77u);
      NP_RegisterProgramProfileID(0x3EAu);
      if ( NP_StopCursor() )
        _printf("NPCient : Error stopping cursor\n");
      else
        _printf("Cursor stopped\n");
      if ( NP_StartDataTransmission() )
        _printf("NPCient : Error starting data transmission\n");
      else
        _printf("Data transmission started\n");
      v6 = 0;
      std::wstring::wstring(&v5, L"cfg/trackir.ini");
      INIReaderDocuments::INIReaderDocuments(&ini, (unsigned int)hwnd, v5, (bool)v6);
      LOBYTE(v13) = 1;
      if ( ini.ready )
      {
        std::wstring::wstring(&section, L"TRACK_IR");
        LOBYTE(v13) = 2;
        v3 = INIReader::hasSection(&ini, &section);
        LOBYTE(v13) = 1;
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        if ( v3 )
        {
          std::wstring::wstring((std::wstring *)csMinorVer, L"VALUE");
          LOBYTE(v13) = 3;
          std::wstring::wstring(&section, L"TRACK_IR");
          LOBYTE(v13) = 4;
          this->divisionValue = INIReader::getFloat(&ini, &section, (const std::wstring *)csMinorVer);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)csMinorVer);
        }
      }
      this->isValid = 1;
      LOBYTE(v13) = 0;
      INIReaderDocuments::~INIReaderDocuments(&ini);
    }
  }
  if ( path._Myres >= 0x10 )
    operator delete(path._Bx._Ptr);
}
void TrackIR::~TrackIR(TrackIR *this)
{
  if ( this->isValid )
  {
    _printf("Releasing TrackIR interface\n");
    NP_StopDataTransmission();
    NP_UnregisterWindowHandle();
  }
}
void TrackIR::getOffsets(TrackIR *this, vec3f *rot, vec3f *pos)
{
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  tagTrackIRData pTID; // [esp+Ch] [ebp-48h] BYREF

  if ( this->isValid )
  {
    if ( NP_GetData(&pTID) )
      _printf("TrackIR poll failed\n");
    if ( !pTID.wNPStatus )
    {
      v4 = pTID.fNPX;
      rot->y = pTID.fNPYaw / this->divisionValue;
      v5 = pTID.fNPY;
      LODWORD(rot->x) = COERCE_UNSIGNED_INT(pTID.fNPPitch / this->divisionValue) ^ _xmm;
      v6 = pTID.fNPZ;
      rot->z = pTID.fNPRoll / this->divisionValue;
      v7 = v4 * 0.0000099999997;
      v8 = v5 * 0.0000099999997;
      v9 = v6 * 0.0000099999997;
      v10 = FLOAT_0_1;
      if ( v7 <= 0.1 )
      {
        if ( v7 < -0.1 )
          v7 = FLOAT_N0_1;
      }
      else
      {
        v7 = FLOAT_0_1;
      }
      pos->x = v7;
      if ( v8 <= 0.1 )
      {
        if ( v8 < -0.1 )
          v8 = FLOAT_N0_1;
      }
      else
      {
        v8 = FLOAT_0_1;
      }
      pos->y = v8;
      if ( v9 <= 0.1 )
      {
        if ( v9 >= -0.1 )
          v10 = v9;
        else
          v10 = FLOAT_N0_1;
      }
      pos->z = v10;
    }
  }
}
