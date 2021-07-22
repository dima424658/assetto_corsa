#include "benchmarkmode.h"
void BenchmarkMode::BenchmarkMode(BenchmarkMode *this, Sim *sim)
{
  Game *v3; // eax
  std::wstring v4; // [esp-1Ch] [ebp-38h] BYREF
  Game *v5; // [esp-4h] [ebp-20h]
  BenchmarkMode *v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+18h] [ebp-4h]

  v6 = this;
  v5 = sim->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"BENCHMARK_MODE", 0xEu);
  GameObject::GameObject(this, v4, v5);
  this->__vftable = (BenchmarkMode_vtbl *)&BenchmarkMode::`vftable';
  this->sim = sim;
  this->frameCounter = 0;
  this->minFps = 100000;
  this->maxFps = 0;
  this->lastFps = -1;
  this->variance = 0;
  this->startTime = 0.0;
  this->avgFps = 0;
  this->isDone = 0;
  this->resultString._Myres = 7;
  this->resultString._Mysize = 0;
  v7 = 0;
  this->resultString._Bx._Buf[0] = 0;
  v5 = 0;
  LOBYTE(v7) = 1;
  this->initTime = 0.0;
  this->totCpu = 0;
  kglSetVSync((int)v5);
  v3 = this->game;
  v5 = 0;
  v4._Myres = 0;
  v3->gameTime.cappedFPS = 0.0;
  ACCameraManager::setMode(sim->cameraManager, eCockpit, v4._Myres, (bool)v5);
}
BenchmarkMode *BenchmarkMode::`scalar deleting destructor'(BenchmarkMode *this, unsigned int a2)
{
  this->__vftable = (BenchmarkMode_vtbl *)&BenchmarkMode::`vftable';
  if ( this->resultString._Myres >= 8 )
    operator delete(this->resultString._Bx._Ptr);
  this->resultString._Myres = 7;
  this->resultString._Mysize = 0;
  this->resultString._Bx._Buf[0] = 0;
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void BenchmarkMode::generateResultString(BenchmarkMode *this)
{
  std::wostream *v2; // eax
  std::wostream *v3; // eax
  std::wostream *v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  std::wostream *v8; // eax
  std::wostream *v9; // eax
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  std::wostream *v18; // eax
  int v19; // eax
  std::wostream *v20; // eax
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  Game *v23; // eax
  std::wostream *v24; // eax
  std::wostream *v25; // eax
  std::wostream *v26; // eax
  std::wostream *v27; // eax
  std::wostream *v28; // eax
  std::wostream *v29; // eax
  std::wostream *v30; // eax
  const std::wstring *v31; // eax
  std::wostream *v32; // eax
  std::wostream *v33; // eax
  int v34; // eax
  Game *v35; // eax
  std::wostream *v36; // eax
  GraphicsManager *v37; // eax
  std::wostream *v38; // eax
  std::wostream *v39; // eax
  std::wostream *v40; // eax
  std::wostream *v41; // eax
  std::wostream *v42; // eax
  std::wostream *v43; // eax
  int v44; // eax
  int v45; // eax
  Sim *v46; // ecx
  std::wostream *v47; // eax
  std::wostream *v48; // eax
  std::wostream *v49; // eax
  int v50; // eax
  GraphicsManager *v51; // ecx
  BOOL v52; // eax
  std::wostream *v53; // eax
  std::wostream *v54; // eax
  std::wostream *v55; // eax
  std::wostream *v56; // eax
  std::wostream *v57; // eax
  GraphicsManager *v58; // eax
  std::wostream *v59; // eax
  std::wostream *v60; // eax
  std::wostream *v61; // eax
  Game *v62; // eax
  GraphicsManager *v63; // ecx
  std::wostream *v64; // eax
  std::wostream *v65; // eax
  std::wostream *v66; // eax
  int v67; // eax
  int v68; // eax
  struct tm *v69; // eax
  struct tm *v70; // esi
  std::wostream *v71; // eax
  std::wostream *v72; // eax
  std::wostream *v73; // eax
  std::wostream *v74; // eax
  std::wostream *v75; // eax
  std::wostream *v76; // eax
  std::wostream *v77; // eax
  std::wostream *v78; // eax
  std::wostream *v79; // eax
  std::wostream *v80; // eax
  std::wstring *v81; // esi
  std::wstring *v82; // eax
  std::wstring *v83; // eax
  std::wstring *v84; // eax
  std::wstring *v85; // eax
  const std::wstring *v86; // eax
  std::wostream *v87; // eax
  std::wstring *v88; // eax
  std::wostream *v89; // eax
  std::wostream *v90; // eax
  BenchmarkMode *v91; // edi
  std::wstring *v92; // esi
  int v93; // [esp+60h] [ebp-778h]
  unsigned int v94; // [esp+7Ch] [ebp-75Ch]
  const char *v95; // [esp+7Ch] [ebp-75Ch]
  const char *v96; // [esp+80h] [ebp-758h]
  int v97; // [esp+80h] [ebp-758h]
  unsigned int v98; // [esp+84h] [ebp-754h]
  const char *v99; // [esp+84h] [ebp-754h]
  int v100; // [esp+84h] [ebp-754h]
  BOOL v101; // [esp+84h] [ebp-754h]
  const char *v102; // [esp+84h] [ebp-754h]
  const char *v103; // [esp+88h] [ebp-750h]
  int v104; // [esp+88h] [ebp-750h]
  const char *v105; // [esp+88h] [ebp-750h]
  int v106; // [esp+88h] [ebp-750h]
  int v107; // [esp+88h] [ebp-750h]
  const char *v108; // [esp+88h] [ebp-750h]
  char *_Val; // [esp+8Ch] [ebp-74Ch]
  char *_Vala; // [esp+8Ch] [ebp-74Ch]
  char *_Valb; // [esp+8Ch] [ebp-74Ch]
  BOOL _Valc; // [esp+8Ch] [ebp-74Ch]
  char *_Vald; // [esp+8Ch] [ebp-74Ch]
  char *_Vale; // [esp+8Ch] [ebp-74Ch]
  _BYTE v115[28]; // [esp+90h] [ebp-748h] BYREF
  int v116; // [esp+B4h] [ebp-724h]
  __int64 tt; // [esp+B8h] [ebp-720h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v118; // [esp+C0h] [ebp-718h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v119; // [esp+170h] [ebp-668h] BYREF
  std::wofstream out; // [esp+220h] [ebp-5B8h] BYREF
  KGLDeviceDesc result; // [esp+2D8h] [ebp-500h] BYREF
  int v122; // [esp+4E8h] [ebp-2F0h]
  unsigned int v123; // [esp+4ECh] [ebp-2ECh]
  std::wstring key; // [esp+4F0h] [ebp-2E8h] BYREF
  std::wstring v125; // [esp+508h] [ebp-2D0h] BYREF
  std::wstring v126; // [esp+520h] [ebp-2B8h] BYREF
  std::wstring filename; // [esp+538h] [ebp-2A0h] BYREF
  std::wstring v128; // [esp+550h] [ebp-288h] BYREF
  INIReaderDocuments ini; // [esp+568h] [ebp-270h] BYREF
  KGLDeviceDesc dd; // [esp+5B0h] [ebp-228h] BYREF
  int v131; // [esp+7C0h] [ebp-18h]
  int v132; // [esp+7D4h] [ebp-4h]

  v116 = 0;
  *(_DWORD *)v118.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v118.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v118.gap68);
  *(_DWORD *)&v118.gap0[4] = 1;
  std::wiostream::basic_iostream<wchar_t>(v118.gap10, &v118.gap10[24], 0);
  *(_DWORD *)&v118.gap10[*(_DWORD *)(*(_DWORD *)v118.gap10 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v118._Chcount + *(_DWORD *)(*(_DWORD *)v118.gap10 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v118.gap10
                                                                                               + 4)
                                                                                   - 104;
  std::wstreambuf::wstreambuf(&v118.gap10[24]);
  *(_DWORD *)&v118.gap10[24] = &std::wstringbuf::`vftable';
  *(_DWORD *)v118.gap60 = 0;
  *(_DWORD *)&v118.gap60[4] = 0;
  *(_QWORD *)&v115[20] = 7i64;
  *(_DWORD *)&v115[16] = 0;
  *(_WORD *)v115 = 0;
  std::wstring::assign((std::wstring *)v115, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(
    (INIReaderDocuments *)&ini.filename._Bx._Alias[8],
    (unsigned int)this,
    *(std::wstring *)v115,
    v115[24]);
  qmemcpy(&dd.name[8], kglGetDeviceDesc(&result), sizeof(KGLDeviceDesc));
  *(_DWORD *)&v115[24] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  *(_DWORD *)&v115[20] = &Sim::acVersionString;
  v2 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118.gap10[16], "AC VERSION: ");
  v3 = std::operator<<<wchar_t>(v2, *(const std::wstring **)&v115[20]);
  std::wostream::operator<<(v3);
  *(_DWORD *)&v115[24] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  *(_DWORD *)&v115[20] = this->frameCounter;
  v4 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118.gap10[16], "POINTS: ");
  v5 = std::wostream::operator<<(v4, *(_DWORD *)&v115[20]);
  std::wostream::operator<<(v5);
  v6 = this->totCpu / this->frameCounter;
  *(_DWORD *)&v115[24] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  *(_DWORD *)&v115[20] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  *(_DWORD *)&v115[16] = "%";
  *(_DWORD *)&v115[12] = v6;
  v7 = this->variance / this->frameCounter;
  *(_DWORD *)&v115[8] = " CPU=";
  *(_DWORD *)&v115[4] = v7;
  *(_DWORD *)v115 = " VARIANCE=";
  _Val = (char *)this->maxFps;
  v98 = this->minFps;
  v94 = this->avgFps;
  v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118.gap10[16], "FPS: AVG=");
  v9 = (std::wostream *)std::wostream::operator<<(v8, v94);
  v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v9, v95);
  v11 = (std::wostream *)std::wostream::operator<<(v10, " MIN=");
  v12 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v11, v96);
  v13 = (std::wostream *)std::wostream::operator<<(v12, v98);
  v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, v99);
  v15 = (std::wostream *)std::wostream::operator<<(v14, " MAX=");
  v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v15, v103);
  v17 = (std::wostream *)std::wostream::operator<<(v16, _Val);
  v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v17, _Vala);
  v19 = std::wostream::operator<<(v18);
  std::wostream::operator<<(v19);
  v100 = (int)(this->initTime * 0.001);
  v20 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118.gap0[4], "LOADING TIME: ");
  v21 = (std::wostream *)std::wostream::operator<<(v20, v100);
  v22 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v21, *(const char **)v115);
  std::wostream::operator<<(v22);
  v23 = this->game;
  *(_DWORD *)v115 = std::endl<wchar_t,std::char_traits<wchar_t>>;
  v97 = v23->graphics->videoSettings.width;
  v24 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118._Chcount, "GPU: ");
  v25 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v24, (const wchar_t *)&ini.code._Myres);
  v26 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v25, " (");
  v27 = (std::wostream *)std::wostream::operator<<(v26, v97);
  v28 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v27, *(const char **)&v115[4]);
  v29 = (std::wostream *)std::wostream::operator<<(v28, *(_DWORD *)&v115[8]);
  v30 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v29, *(const char **)&v115[8]);
  std::wostream::operator<<(v30);
  v31 = ksGetOSVersionString(&v126);
  *(_DWORD *)&v115[8] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  LOBYTE(v132) = 5;
  v32 = std::operator<<<wchar_t>((std::wostream *)v118.gap10, v31);
  std::wostream::operator<<(v32);
  LOBYTE(v132) = 4;
  if ( v126._Myres >= 8 )
    operator delete(v126._Bx._Ptr);
  *(_DWORD *)&v115[8] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  *(_DWORD *)&v115[4] = ksGetNumberOfProcessors();
  v33 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v118.gap10, "CPU CORES: ");
  v34 = std::wostream::operator<<(v33, *(_DWORD *)&v115[4]);
  std::wostream::operator<<(v34);
  v35 = this->game;
  *(_DWORD *)&v115[12] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  if ( v35->graphics->videoSettings.isFullscreen )
    *(_DWORD *)&v115[8] = "FULLSCREEN: ON";
  else
    *(_DWORD *)&v115[8] = "FULLSCREEN: OFF";
  v36 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118.gap10[4], *(const char **)&v115[8]);
  std::wostream::operator<<(v36);
  v37 = this->game->graphics;
  *(_DWORD *)&v115[20] = v37->videoSettings.shadowMapSize;
  *(_DWORD *)&v115[16] = "X SHDW:";
  *(_DWORD *)&v115[12] = v37->videoSettings.anisotropic;
  *(_DWORD *)&v115[8] = "X AF:";
  *(_DWORD *)&v115[4] = v37->videoSettings.aaSamples;
  v38 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118.gap10[12], "AA:");
  v39 = (std::wostream *)std::wostream::operator<<(v38, *(_DWORD *)&v115[4]);
  v40 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v39, *(const char **)&v115[4]);
  v41 = (std::wostream *)std::wostream::operator<<(v40, *(_DWORD *)&v115[8]);
  v42 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v41, *(const char **)&v115[8]);
  std::wostream::operator<<(v42, *(_DWORD *)&v115[12]);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"MOTION_BLUR", 0xBu);
  LOBYTE(v132) = 6;
  v123 = 7;
  v122 = 0;
  LOWORD(result.videoMemory) = 0;
  std::wstring::assign((std::wstring *)&result.videoMemory, L"EFFECTS", 7u);
  *(_DWORD *)&v115[8] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  LOBYTE(v132) = 7;
  *(_DWORD *)&v115[4] = INIReader::getInt(&ini, (const std::wstring *)&result.videoMemory, &key);
  v43 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v118.gap10, " BLUR:");
  v44 = std::wostream::operator<<(v43, *(_DWORD *)&v115[4]);
  std::wostream::operator<<(v44);
  if ( v123 >= 8 )
    operator delete(result.videoMemory);
  v123 = 7;
  v122 = 0;
  LOWORD(result.videoMemory) = 0;
  LOBYTE(v132) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SMOKE", 5u);
  LOBYTE(v132) = 8;
  v123 = 7;
  v122 = 0;
  LOWORD(result.videoMemory) = 0;
  std::wstring::assign((std::wstring *)&result.videoMemory, L"EFFECTS", 7u);
  *(_DWORD *)&v115[8] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  LOBYTE(v132) = 9;
  v45 = INIReader::getInt(&ini, (const std::wstring *)&result.videoMemory, &key);
  v46 = this->sim;
  *(_DWORD *)&v115[4] = v45;
  *(_DWORD *)v115 = " SMOKE:";
  _Valb = (char *)LODWORD(Sim::getSceneCamera(v46)->maxLayer);
  v47 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v118.gap10, "WORLD DETAIL: ");
  v48 = (std::wostream *)std::wostream::operator<<(v47);
  v49 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v48, _Valb);
  v50 = std::wostream::operator<<(v49, *(_DWORD *)v115);
  std::wostream::operator<<(v50);
  if ( v123 >= 8 )
    operator delete(result.videoMemory);
  v123 = 7;
  v122 = 0;
  LOWORD(result.videoMemory) = 0;
  LOBYTE(v132) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v51 = this->game->graphics;
  *(_DWORD *)&v115[8] = v51->videoSettings.ppFXAA;
  v52 = v51->videoSettings.ppHDREnabled;
  *(_DWORD *)&v115[4] = " FXAA:";
  *(_DWORD *)v115 = v52;
  v104 = v51->videoSettings.ppQuality;
  v53 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v118.gap10, "PP: QLT:");
  v54 = (std::wostream *)std::wostream::operator<<(v53, v104);
  v55 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v54, v105);
  v56 = (std::wostream *)std::wostream::operator<<(v55, " HDR:", *(_DWORD *)v115);
  v57 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v56, *(const char **)v115);
  std::wostream::operator<<(v57, *(_DWORD *)&v115[4], *(_DWORD *)&v115[8]);
  v58 = this->game->graphics;
  *(_DWORD *)v115 = v58->videoSettings.ppDof;
  v106 = v58->videoSettings.ppGlare;
  v59 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118._Chcount, " GLR:");
  v60 = (std::wostream *)std::wostream::operator<<(v59, v106);
  v61 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v60, *(const char **)&v115[4]);
  std::wostream::operator<<(v61, *(_DWORD *)&v115[8]);
  v62 = this->game;
  *(_DWORD *)&v115[4] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  *(_DWORD *)v115 = std::endl<wchar_t,std::char_traits<wchar_t>>;
  v63 = v62->graphics;
  _Valc = v63->videoSettings.ppHeatShimmer;
  v101 = v63->videoSettings.ppRaysOfGod;
  v64 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)((char *)&v118._Chcount + 4), " RAYS:");
  v65 = (std::wostream *)std::wostream::operator<<(v64, v101, " HEAT:");
  v66 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v65, v102);
  v67 = std::wostream::operator<<(v66, v107, _Valc);
  v68 = std::wostream::operator<<(v67);
  std::wostream::operator<<(v68);
  *(_QWORD *)&v115[20] = __time64(0);
  v69 = __localtime64((const __time64_t *)&v115[20]);
  *(_DWORD *)&v118.gap68[52] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)&v118.gap68[68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  v70 = v69;
  std::wios::wios(&v119.gap10[68]);
  LOBYTE(v131) = 10;
  *(_DWORD *)&v115[16] = 3;
  std::wiostream::basic_iostream<wchar_t>(&v118.gap68[52], &v119.gap0[4], 0);
  v131 = 11;
  *(_DWORD *)&v118.gap68[*(_DWORD *)(*(_DWORD *)&v118.gap68[52] + 4) + 52] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v118.gap68[*(_DWORD *)(*(_DWORD *)&v118.gap68[52] + 4) + 48] = *(_DWORD *)(*(_DWORD *)&v118.gap68[52] + 4)
                                                                           - 104;
  std::wstreambuf::wstreambuf(&v119.gap0[4]);
  *(_DWORD *)&v119.gap0[4] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v119.gap10[44] = 0;
  *(_DWORD *)&v119.gap10[48] = 0;
  LOBYTE(v131) = 13;
  v93 = v70->tm_year + 1900;
  v71 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v118.gap68[68], "acbench_");
  v72 = (std::wostream *)std::wostream::operator<<(v71, v93);
  v73 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v72, v108);
  v74 = (std::wostream *)std::wostream::operator<<(v73, _Vald);
  v75 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v74, _Vale);
  v76 = (std::wostream *)std::wostream::operator<<(v75, *(_DWORD *)v115);
  v77 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v76, *(const char **)v115);
  v78 = (std::wostream *)std::wostream::operator<<(v77, *(_DWORD *)&v115[4]);
  v79 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v78, *(const char **)&v115[4]);
  v80 = (std::wostream *)std::wostream::operator<<(v79, *(_DWORD *)&v115[8]);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v80, *(const char **)&v115[8]);
  v81 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v119, &v128);
  LOBYTE(v132) = 14;
  v82 = Path::getDocumentPath((std::wstring *)&result.videoMemory);
  LOBYTE(v132) = 15;
  v83 = std::operator+<wchar_t>(&key, v82, L"/Assetto Corsa/benchmarks/");
  LOBYTE(v132) = 16;
  std::operator+<wchar_t>(&filename, v83, v81);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( v123 >= 8 )
    operator delete(result.videoMemory);
  v123 = 7;
  v122 = 0;
  LOWORD(result.videoMemory) = 0;
  LOBYTE(v132) = 20;
  if ( v128._Myres >= 8 )
    operator delete(v128._Bx._Ptr);
  v128._Myres = 7;
  v128._Bx._Buf[0] = 0;
  v128._Mysize = 0;
  v84 = Path::getDocumentPath(&v125);
  LOBYTE(v132) = 21;
  v85 = std::operator+<wchar_t>(&v126, v84, L"/Assetto Corsa/benchmarks");
  if ( v85->_Myres >= 8 )
    v85 = (std::wstring *)v85->_Bx._Ptr;
  CreateDirectoryW(v85->_Bx._Buf, 0);
  if ( v126._Myres >= 8 )
    operator delete(v126._Bx._Ptr);
  v126._Myres = 7;
  v126._Mysize = 0;
  v126._Bx._Buf[0] = 0;
  LOBYTE(v132) = 20;
  if ( v125._Myres >= 8 )
    operator delete(v125._Bx._Ptr);
  std::wofstream::wofstream(&out, &filename, 2, 64, 1);
  LOBYTE(v132) = 22;
  v86 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v118, &v125);
  *(_DWORD *)&v115[8] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  LOBYTE(v132) = 23;
  v87 = std::operator<<<wchar_t>(&out, v86);
  std::wostream::operator<<(v87);
  LOBYTE(v132) = 22;
  if ( v125._Myres >= 8 )
    operator delete(v125._Bx._Ptr);
  v88 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v119, &v125);
  *(_DWORD *)&v115[8] = std::endl<wchar_t,std::char_traits<wchar_t>>;
  *(_DWORD *)&v115[4] = v88;
  LOBYTE(v132) = 24;
  v89 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v118.gap10, "FILENAME: ");
  v90 = std::operator<<<wchar_t>(v89, *(const std::wstring **)&v115[4]);
  std::wostream::operator<<(v90);
  LOBYTE(v132) = 22;
  if ( v125._Myres >= 8 )
    operator delete(v125._Bx._Ptr);
  v91 = (BenchmarkMode *)std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                           &v118,
                           &v125);
  v92 = &this->resultString;
  if ( &this->resultString != (std::wstring *)v91 )
  {
    if ( this->resultString._Myres >= 8 )
      operator delete(v92->_Bx._Ptr);
    this->resultString._Myres = 7;
    this->resultString._Mysize = 0;
    *(_DWORD *)&v115[8] = v91;
    v92->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->resultString, *(std::wstring **)&v115[8]);
  }
  if ( v125._Myres >= 8 )
    operator delete(v125._Bx._Ptr);
  std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&out.gap58[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&out.gap58[8]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Bx._Buf[0] = 0;
  filename._Mysize = 0;
  LOBYTE(v132) = 4;
  *(_DWORD *)&v119.gap0[*(_DWORD *)(*(_DWORD *)v119.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v118.gap68[*(_DWORD *)(*(_DWORD *)v119.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v119.gap0 + 4) - 104;
  *(_DWORD *)&v119.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v119.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v119.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v119.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v119.gap68);
  LOBYTE(v132) = 3;
  INIReaderDocuments::~INIReaderDocuments(&ini);
  v132 = -1;
  *(_DWORD *)&v118.gap0[*(_DWORD *)(*(_DWORD *)v118.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&tt + *(_DWORD *)(*(_DWORD *)v118.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v118.gap0 + 4) - 104;
  *(_DWORD *)&v118.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v118.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v118.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v118.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v118.gap68);
}
void BenchmarkMode::renderHUD(BenchmarkMode *this, float deltaT)
{
  BenchmarkMode *v2; // edi
  unsigned int *v3; // esi
  ACCameraManager *v4; // ecx
  float v5; // xmm1_4
  unsigned int v6; // eax
  std::wstring *v7; // esi
  std::wstring **v8; // ecx
  bool v9; // cf
  std::wstring **v10; // eax
  int v11; // eax
  double v12; // st7
  unsigned int v13; // esi
  int v14; // eax
  std::wstring *v15; // edi
  std::wstring *v16; // esi
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  const std::wstring *v30; // eax
  GraphicsManager *v31; // ecx
  GLRenderer *v32; // esi
  std::wstring *v33; // [esp+24h] [ebp-218h]
  std::wstring *v34; // [esp+28h] [ebp-214h]
  std::wstring *v35; // [esp+30h] [ebp-20Ch]
  int _Val; // [esp+34h] [ebp-208h]
  unsigned int *v37; // [esp+38h] [ebp-204h]
  int v38; // [esp+3Ch] [ebp-200h]
  float v40; // [esp+44h] [ebp-1F8h]
  std::wstring *_Right; // [esp+48h] [ebp-1F4h] BYREF
  std::wstring v42; // [esp+4Ch] [ebp-1F0h] BYREF
  std::wstring result; // [esp+64h] [ebp-1D8h] BYREF
  std::wstring v44; // [esp+7Ch] [ebp-1C0h] BYREF
  std::wstring v45; // [esp+94h] [ebp-1A8h] BYREF
  std::wstring v46; // [esp+ACh] [ebp-190h] BYREF
  std::wstring v47; // [esp+C4h] [ebp-178h] BYREF
  std::wstring v48; // [esp+DCh] [ebp-160h] BYREF
  std::wstring v49; // [esp+F4h] [ebp-148h] BYREF
  std::wstring v50; // [esp+10Ch] [ebp-130h] BYREF
  std::wstring v51; // [esp+124h] [ebp-118h] BYREF
  std::wstring v52; // [esp+13Ch] [ebp-100h] BYREF
  std::wstring v53; // [esp+154h] [ebp-E8h] BYREF
  std::wstring v54; // [esp+16Ch] [ebp-D0h] BYREF
  std::wstring v55; // [esp+184h] [ebp-B8h] BYREF
  std::wstring v56; // [esp+19Ch] [ebp-A0h] BYREF
  std::wstring v57; // [esp+1B4h] [ebp-88h] BYREF
  std::wstring v58; // [esp+1CCh] [ebp-70h] BYREF
  std::wstring v59; // [esp+1E4h] [ebp-58h] BYREF
  std::wstring v60; // [esp+1FCh] [ebp-40h] BYREF
  std::wstring v61; // [esp+214h] [ebp-28h] BYREF
  int v62; // [esp+238h] [ebp-4h]

  v2 = this;
  v3 = &this->frameCounter;
  v37 = &this->frameCounter;
  if ( !this->frameCounter )
    this->initTime = ksGetTime() - BenchmarkMode::loadingStartTime;
  v4 = v2->sim->cameraManager;
  if ( v2->isDone )
  {
    if ( v4->mode != eTrack )
      ACCameraManager::setMode(v4, eTrack, 0, 0);
    v31 = v2->game->graphics;
    v32 = v31->gl;
    GraphicsManager::setBlendMode(v31, eAlphaBlend);
    GLRenderer::color4f(v32, 0.0, 0.0, 0.0, 0.5);
    GLRenderer::quad(
      v32,
      0.0,
      0.0,
      (float)v2->game->graphics->videoSettings.width,
      (float)v2->game->graphics->videoSettings.height,
      0,
      0);
    Font::setColor(v2->game->gui->font._Ptr, 1.0, 1.0, 1.0, 1.0);
    Font::blitString(v2->game->gui->font._Ptr, 50.0, 100.0, &v2->resultString, 2.0, eAlignLeft);
  }
  else
  {
    if ( v4->mode )
      ACCameraManager::setMode(v4, eCockpit, 0, 0);
    if ( ++*v3 >= 0xA )
    {
      Font::setColor(v2->game->gui->font._Ptr, 1.0, 0.0, 1.0, 1.0);
      v40 = 1.0 / deltaT;
      v38 = ReplayManager::getCurrentFrame(v2->sim->replayManager);
      v5 = 1.0 / deltaT;
      _Val = ReplayManager::getRecordedFrames(v2->sim->replayManager);
      if ( (float)(1.0 / deltaT) >= 1.0 )
      {
        v6 = (unsigned int)v5;
        v5 = 1.0 / deltaT;
        v7 = (std::wstring *)v6;
        v8 = &_Right;
        v9 = v2->maxFps < v6;
        v10 = &_Right;
        _Right = v7;
        if ( !v9 )
          v8 = (std::wstring **)&v2->maxFps;
        v2->maxFps = (unsigned int)*v8;
        v9 = (unsigned int)v7 < v2->minFps;
        _Right = v7;
        v3 = v37;
        if ( !v9 )
          v10 = (std::wstring **)&v2->minFps;
        v2->minFps = (unsigned int)*v10;
      }
      v11 = v2->lastFps;
      if ( v11 != -1 )
        v2->variance = (unsigned int)(float)((float)v2->variance
                                           + COERCE_FLOAT(COERCE_UNSIGNED_INT(v5 - (float)v11) & _xmm));
      v12 = ksGetTime();
      v13 = *v3;
      v2->avgFps = (unsigned int)((double)v13 / ((v12 - v2->startTime) * 0.001));
      v2->totCpu += (int)(v2->game->stats.cpuTime / (deltaT * 1000.0) * 100.0);
      v35 = std::to_wstring(&result, v2->totCpu / v13);
      v62 = 0;
      v34 = std::to_wstring(&v57, _Val);
      LOBYTE(v62) = 1;
      v33 = std::to_wstring(&v42, v38);
      LOBYTE(v62) = 2;
      _Right = std::to_wstring(&v44, *v37);
      v14 = v2->variance / *v37;
      LOBYTE(v62) = 3;
      v15 = std::to_wstring(&v46, v14);
      LOBYTE(v62) = 4;
      v16 = std::to_wstring(&v48, this->avgFps);
      LOBYTE(v62) = 5;
      v17 = std::to_wstring(&v50, (int)v40);
      LOBYTE(v62) = 6;
      v18 = std::operator+<wchar_t>(&v52, L"FPS:", v17);
      LOBYTE(v62) = 7;
      v19 = std::operator+<wchar_t>(&v54, v18, L" AVG:");
      LOBYTE(v62) = 8;
      v20 = std::operator+<wchar_t>(&v56, v19, v16);
      LOBYTE(v62) = 9;
      v21 = std::operator+<wchar_t>(&v59, v20, L" VAR:");
      LOBYTE(v62) = 10;
      v22 = std::operator+<wchar_t>(&v60, v21, v15);
      LOBYTE(v62) = 11;
      v23 = std::operator+<wchar_t>(&v51, v22, L" PTS:");
      LOBYTE(v62) = 12;
      v24 = std::operator+<wchar_t>(&v47, v23, _Right);
      LOBYTE(v62) = 13;
      v25 = std::operator+<wchar_t>(&v61, v24, L" ");
      LOBYTE(v62) = 14;
      v26 = std::operator+<wchar_t>(&v53, v25, v33);
      LOBYTE(v62) = 15;
      v27 = std::operator+<wchar_t>(&v45, v26, L"/");
      LOBYTE(v62) = 16;
      v28 = std::operator+<wchar_t>(&v55, v27, v34);
      LOBYTE(v62) = 17;
      v29 = std::operator+<wchar_t>(&v49, v28, L" CPU:");
      LOBYTE(v62) = 18;
      v30 = std::operator+<wchar_t>(&v58, v29, v35);
      LOBYTE(v62) = 19;
      Font::blitString(this->game->gui->font._Ptr, 0.0, 0.0, v30, 1.0, eAlignLeft);
      if ( v58._Myres >= 8 )
        operator delete(v58._Bx._Ptr);
      v58._Myres = 7;
      v58._Mysize = 0;
      v58._Bx._Buf[0] = 0;
      if ( v49._Myres >= 8 )
        operator delete(v49._Bx._Ptr);
      v49._Myres = 7;
      v49._Mysize = 0;
      v49._Bx._Buf[0] = 0;
      if ( v55._Myres >= 8 )
        operator delete(v55._Bx._Ptr);
      v55._Myres = 7;
      v55._Mysize = 0;
      v55._Bx._Buf[0] = 0;
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
      v45._Myres = 7;
      v45._Mysize = 0;
      v45._Bx._Buf[0] = 0;
      if ( v53._Myres >= 8 )
        operator delete(v53._Bx._Ptr);
      v53._Myres = 7;
      v53._Mysize = 0;
      v53._Bx._Buf[0] = 0;
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      v61._Myres = 7;
      v61._Mysize = 0;
      v61._Bx._Buf[0] = 0;
      if ( v47._Myres >= 8 )
        operator delete(v47._Bx._Ptr);
      v47._Myres = 7;
      v47._Mysize = 0;
      v47._Bx._Buf[0] = 0;
      if ( v51._Myres >= 8 )
        operator delete(v51._Bx._Ptr);
      v51._Myres = 7;
      v51._Mysize = 0;
      v51._Bx._Buf[0] = 0;
      if ( v60._Myres >= 8 )
        operator delete(v60._Bx._Ptr);
      v60._Myres = 7;
      v60._Mysize = 0;
      v60._Bx._Buf[0] = 0;
      if ( v59._Myres >= 8 )
        operator delete(v59._Bx._Ptr);
      v59._Myres = 7;
      v59._Mysize = 0;
      v59._Bx._Buf[0] = 0;
      if ( v56._Myres >= 8 )
        operator delete(v56._Bx._Ptr);
      v56._Myres = 7;
      v56._Mysize = 0;
      v56._Bx._Buf[0] = 0;
      if ( v54._Myres >= 8 )
        operator delete(v54._Bx._Ptr);
      v54._Myres = 7;
      v54._Mysize = 0;
      v54._Bx._Buf[0] = 0;
      if ( v52._Myres >= 8 )
        operator delete(v52._Bx._Ptr);
      v52._Myres = 7;
      v52._Mysize = 0;
      v52._Bx._Buf[0] = 0;
      if ( v50._Myres >= 8 )
        operator delete(v50._Bx._Ptr);
      v50._Myres = 7;
      v50._Mysize = 0;
      v50._Bx._Buf[0] = 0;
      if ( v48._Myres >= 8 )
        operator delete(v48._Bx._Ptr);
      v48._Myres = 7;
      v48._Mysize = 0;
      v48._Bx._Buf[0] = 0;
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
      if ( v44._Myres >= 8 )
        operator delete(v44._Bx._Ptr);
      v44._Myres = 7;
      v44._Mysize = 0;
      v44._Bx._Buf[0] = 0;
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v42._Myres = 7;
      v42._Mysize = 0;
      v42._Bx._Buf[0] = 0;
      if ( v57._Myres >= 8 )
        operator delete(v57._Bx._Ptr);
      v57._Myres = 7;
      v57._Mysize = 0;
      v57._Bx._Buf[0] = 0;
      v62 = -1;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      this->lastFps = (int)v40;
      if ( v38 > _Val - 5 )
      {
        ReplayManager::pause(this->sim->replayManager);
        this->isDone = 1;
        BenchmarkMode::generateResultString(this);
      }
    }
    else
    {
      ReplayManager::setCurrentFrame(v2->sim->replayManager, 0);
      v2->startTime = ksGetTime();
    }
  }
}
